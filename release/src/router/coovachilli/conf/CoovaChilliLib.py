#!/usr/bin/python
"""
 CoovaChilli Python Library
 Copyright (C) 2009  David Bird <david@coova.com>

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
"""


import pygtk
pygtk.require('2.0')

import os
import gtk
import time
import string
import socket
import fcntl
import struct
import array
import gobject
import ConfigParser
import subprocess


class EntryDialog(gtk.Dialog):
    def __init__(self, message="", default_text='', modal=True):
        gtk.Dialog.__init__(self)
        self.connect("destroy", self.quit)
        self.connect("delete_event", self.quit)
        if modal:
            self.set_modal(gtk.TRUE)
        box = gtk.VBox(spacing=10)
        box.set_border_width(10)
        self.vbox.pack_start(box)
        box.show()
        if message:
            label = gtk.Label(message)
            box.pack_start(label)
            label.show()
        self.entry = gtk.Entry()
        self.entry.set_text(default_text)
        box.pack_start(self.entry)
        self.entry.show()
        self.entry.grab_focus()
        button = gtk.Button("OK")
        button.connect("clicked", self.click)
        button.set_flags(gtk.CAN_DEFAULT)
        self.action_area.pack_start(button)
        button.show()
        button.grab_default()
        button = gtk.Button("Cancel")
        button.connect("clicked", self.quit)
        button.set_flags(gtk.CAN_DEFAULT)
        self.action_area.pack_start(button)
        button.show()
        self.ret = None
    def quit(self, w=None, event=None):
        self.hide()
        self.destroy()
        gtk.main_quit()
    def click(self, button):
        self.ret = self.entry.get_text()
        self.quit()

class CoovaChilli:
    About   = "<b>About:</b>\nCoovaChilli is an open-source access\ncontroller server. After assigning each\ndevice with an IP address using DHCP,\nchilli will redirect unauthenticated\nusers to a captive portal.\n\n<b>Created by:</b>\n(c) 2009 David Bird\nhttp://coova.org/\nReleased under GPL"
    Query   = '/usr/sbin/chilli_query'
    Socket  = '/var/run/chilli.sock'
    Init    = '/etc/init.d/chilli'
    DefIni  = '/etc/chilli/gui-config-default.ini'
    Ini     = '/etc/chilli/gui-config.ini'
    Conf    = '/etc/chilli/config'
    Section = '/tmp/hotspot-section'

    Settings = [ 'HS_SSID',
                 'HS_NETWORK',
                 'HS_NETMASK',
                 'HS_UAMPORT',
                 'HS_UAMLISTEN',
                 'HS_UAMSERVER', 
                 'HS_UAMFORMAT', 
                 'HS_UAMSERVICE', 
                 'HS_UAMSECRET',
                 'HS_RADIUS', 
                 'HS_RADIUS2', 
                 'HS_RADSECRET',
                 'HS_UAMALLOW',
                 'HS_UAMDOMAINS',
                 'HS_USELOCALUSERS',
                 'HS_ADMUSR',
                 'HS_ADMPWD',
                 'HS_LOC_NAME' ]

    Labels   = { 'HS_SSID' : gtk.Label( "Hotspot SSID:" ),
                 'HS_NETWORK' : gtk.Label( "Network:" ),
                 'HS_NETMASK' : gtk.Label( "Netmask:" ),
                 'HS_UAMLISTEN' : gtk.Label( "UAM IP Address:" ),
                 'HS_UAMSERVER' : gtk.Label( "UAM Server:" ),
                 'HS_UAMFORMAT' : gtk.Label( "UAM Redirect URL:" ),
                 'HS_UAMSERVICE' : gtk.Label( "UAM Service URL:" ),
                 'HS_UAMSECRET' : gtk.Label( "UAM Secret:" ),
                 'HS_RADIUS' : gtk.Label( "RADIUS Server 1:" ),
                 'HS_RADIUS2' : gtk.Label( "RADIUS Server 2:" ),
                 'HS_RADSECRET' : gtk.Label( "Shared Secret:" ),
                 'HS_UAMALLOW' : gtk.Label( "UAM Allowed:" ),
                 'HS_UAMDOMAINS' : gtk.Label( "UAM Domains:" ),
                 'HS_ADMUSR' : gtk.Label( "Admin-User:" ),
                 'HS_ADMPWD' : gtk.Label( "Admin-Password:" ) }
    
    Entries  = { 'HS_SSID' : gtk.Entry(),
                 'HS_NETWORK' : gtk.Entry(),
                 'HS_NETMASK' : gtk.Entry(),
                 'HS_UAMLISTEN' : gtk.Entry(),
                 'HS_UAMSERVER' : gtk.Entry(),
                 'HS_UAMFORMAT' : gtk.Entry(),
                 'HS_UAMSERVICE' : gtk.Entry(),
                 'HS_UAMSECRET' : gtk.Entry(),
                 'HS_RADIUS' : gtk.Entry(),
                 'HS_RADIUS2' : gtk.Entry(),
                 'HS_RADSECRET' : gtk.Entry(),
                 'HS_UAMALLOW' : gtk.Entry(),
                 'HS_UAMDOMAINS' : gtk.Entry(),
                 'HS_ADMUSR' : gtk.Entry(),
                 'HS_ADMPWD' : gtk.Entry() }
    
    def saveChilliConfig( self, data=None ):
        configfile = open(self.Conf, 'wb')
        for setting in self.Settings:
            configfile.write(setting+"="+self.conf(setting)+"\n")
        return True

    def clone(self, section):
        for setting in self.Settings:
            self.config.set(section, setting, self.conf(setting))
        return

    def saveConfig( self, data=None ):
        print "Storing configuration changes"

        for setting in self.Settings:
            if self.Entries.get(setting):
                self.config.set(self.section, setting, self.Entries.get(setting).get_text())

        configfile = open(self.Ini, 'wb')
        self.config.write(configfile)
        configfile.close()

        self.saveChilliConfig()
        return True

    def _chilliQuery( self, mac=None ):
        self.sessionsStore.clear()

        if mac != None:
            self.selectedMac = mac

        if self.selectedMac == None:
            self.selectedSession = 0
            self.sesAuth.set_sensitive( False )
            self.sesRelease.set_sensitive( False )
            self.sesBlock.set_sensitive( False )
            self.sessionView.set_markup( '' )

        p = subprocess.Popen([self.Query, self.Socket, "list"], stdout=subprocess.PIPE, close_fds=True)

        i=0
        macNotFound = True
        selectPath = -1

        for line in p.stdout.readlines():
            print line
            s = line.split()
            self.sessionsStore.append([ s[0], s[1] ])
            if self.selectedMac == s[0]:
                macNotFound = False
                selectPath = i
                self.selectedSessionId = s[3]

                color = 'orange'

                if s[2] == 'pass':
                    color = 'green'

                if s[2] == 'drop':
                    color = 'red'

                markUp = "<b>MAC:</b>: <span color='"+color+"'>"+s[0]+"</span> <b>IP</b>: <span color='"+color+"'>"+s[1]+"</span>\n"
                markUp = markUp + ( "<b>Session Id</b>: <span color='"+color+"'>"+s[3]+"</span> <b>State</b>: <span color='"+color+"'>"+s[2]+"</span>\n" )
                markUp = markUp + ( "<b>Username</b>: <span color='"+color+"'>%s</span>\n" % s[5] )
                markUp = markUp + ( "<b>Time: Duration/Max</b>: <span color='"+color+"'>"+self.formatTime(s[6])+"</span> <b>Idle/Max</b>: <span color='"+color+"'>"+self.formatTime(s[7])+"</span>\n" )
                markUp = markUp + ( "<b>Octets: Input/Max</b>: <span color='"+color+"'>"+self.formatOctets(s[8])+"</span> <b>Output/Max</b>:<span color='"+color+"'>"+self.formatOctets(s[9])+"</span> <b>Total-Max</b>: <span color='"+color+"'>"+self.formatOctets(s[10])+"</span>\n" )
                markUp = markUp + ( "<b>Bandwidth: %/Max-Up</b>: <span color='"+color+"'>"+self.formatBw(s[12])+"</span> <b>%/Max-Down</b>: <span color='"+color+"'>"+self.formatBw(s[13])+"</span>\n" )
                markUp = markUp + ( "<b>Original URL:</b>: <span color='"+color+"'>"+self.formatURL(s[14])+"</span>\n" )
                self.sessionView.set_markup(markUp)
            i = i + 1

        if macNotFound:
            self.selectedMac = None
            self.sesAuth.set_sensitive( False )
            self.sesRelease.set_sensitive( False )
            self.sesBlock.set_sensitive( False )
            self.sessionView.set_markup('')
        else:
            if selectPath > -1:
                self.sessionsView.get_selection().select_path(selectPath)

    def chilliQuery( self, widget=None ):
        self._chilliQuery()
        return True

    def sessionRelease( self, widget ):
        print 'Releasing '+self.selectedMac
        p = subprocess.Popen([self.Query, self.Socket, "dhcp-release", self.selectedMac]).communicate()
        self.chilliQuery()
        return

    def sessionBlock( self, widget ):
        print 'Blocking access from '+self.selectedMac
        p = subprocess.Popen([self.Query, self.Socket, "block", self.selectedMac]).communicate()
        self.chilliQuery()
        return

    def sessionAuthorize( self, widget ):
        if self.selectedSessionId:
            print 'Authorizing '+self.selectedSessionId
            p = subprocess.Popen([self.Query, self.Socket, "authorize", "sessionid", self.selectedSessionId]).communicate()
            self.chilliQuery()
        return

    def startCoovaChilli( self, widget, data = None ):
        self.saveConfig()
        p = subprocess.Popen(self.Init + ' start', shell=True)
        sts = os.waitpid(p.pid, 0)
        configfile = open(self.Section, 'wb')
        configfile.write(self.section)
        configfile.close()
        return True

    def stopCoovaChilli( self, widget, data = None ):
        p = subprocess.Popen(self.Init + ' stop', shell=True)
        sts = os.waitpid(p.pid, 0)
        configfile = open(self.Section, 'wb')
        configfile.write('')
        configfile.close()
        return True

    def conf( self, name ):
        try:
            result = self.config.get(self.section, name);
        except:
            result = ''
        return result

    def _newSection( self ):
        win = EntryDialog('New config name', '', modal=True)
        win.set_title('Clone config')
        win.show()
        gtk.main()
        return win.ret

    def deleteSection( self, data=None ):
        if self.section != 'default':
            self.config.remove_section(self.section)
            self.sectionStore.clear()
            for s in self.config.sections():
                self.sectionStore.append([ s ])
            self._changeSection('default')
        return

    def newSection( self, data=None ):
        section = self._newSection()
        if section != None:
            if section != '':
                self.config.add_section(section)
                self.clone(section)
                self.sectionStore.clear()
                for s in self.config.sections():
                    self.sectionStore.append([ s ])
                self._changeSection(section)
        return

    def _setComboxBox(self, box, val):
        model = box.get_model()
        index = box.get_active()
        i = 0
        for m in model:
            if m[0] == val:
                if i != index:
                    box.set_active(i)
                    return
            i = i + 1
        return

    def _changeSection(self, section):
        print 'change to '+section
        self.section = section
        
        for setting in self.Settings:
            if self.Entries.get(setting):
                self.Entries.get(setting).set_text( self.conf( setting ) )
            
        self._setComboxBox(self.sectionBox, section)
        self._setComboxBox(self.sectionBox2, section)
        return

    def changeSection(self, combobox):
        model = combobox.get_model()
        index = combobox.get_active()
        self._changeSection( model[index][0] )
        return

    def changeSection2(self, combobox):
        model = combobox.get_model()
        index = combobox.get_active()
        self._changeSection( model[index][0] )
        return

    def row3(self, treeview, iter, path, action):
        print action

    def row1(self, treeview, action):
        if action == 'cursor-changed':
            selection = self.sessionsView.get_selection()
            model, iter = selection.get_selected()
            if iter:
                mac = self.sessionsStore.get_value(iter, 0)
                print 'Selected: '+mac
                self.sesAuth.set_sensitive( True )
                self.sesRelease.set_sensitive( True )
                self.sesBlock.set_sensitive( True )
                self._chilliQuery( mac )
        print action

    def formatOctets(self, o):
        return o

    def formatTime(self, o):
        return o

    def formatBw(self, o):
        return o

    def formatURL(self, o):
        idx = string.find(o, "?")
        if idx > -1:
            o = o[:idx]
        return o

    def makeConfigTable( self ):
        self.configTable = gtk.Table(8, 2, True)
        self.lblSection  = gtk.Label( "Configuration:" )
        self.btnSave = gtk.Button( "Save" )
        self.btnNewCfg = gtk.Button( "Clone" )
        self.btnDelCfg = gtk.Button( "Delete" )

        row = 0
        self.configTable.attach(self.lblSection, 0, 1, row, row+1)
        self.configTable.attach(self.sectionBox2, 1, 2, row, row+1)

        for setting in self.Settings:
            if self.Entries.get(setting):
                row = row + 1
                self.configTable.attach(self.Labels.get(setting), 0, 1, row, row+1)
                self.configTable.attach(self.Entries.get(setting), 1, 2, row, row+1)

        row = row + 1
        configBtnBox = gtk.HBox()
        configBtnBox.pack_start( self.btnSave )
        configBtnBox.pack_start( self.btnNewCfg )
        configBtnBox.pack_start( self.btnDelCfg )
        self.configTable.attach(configBtnBox, 0, 2, row, row+1)

        self.btnSave.connect( "clicked", self.saveConfig )
        self.btnNewCfg.connect( "clicked", self.newSection )
        self.btnDelCfg.connect( "clicked", self.deleteSection )

        self.lblSection.show()
        self.sectionBox.show()
        self.sectionBox2.show()

        for setting in self.Settings:
            if self.Entries.get(setting):
                self.Labels.get(setting).show()
                self.Entries.get(setting).show()

        self.btnSave.show()
        self.btnNewCfg.show()
        self.btnDelCfg.show()

        configBtnBox.show()

    def __init__( self, data=None, more=None ):

        # Load configuration file
        try:
            configfile = open(self.Section, 'r')
            self.section = configfile.readline()
            configfile.close()
        except:
            self.section = ''

        if self.section == '':
            self.section = 'default'

        # Initialize parameters
        self.selectedMac = None
        self.selectedSessionId = None

        self.config = ConfigParser.RawConfigParser()

        if os.path.exists(self.Ini):
            self.config.read(self.Ini)
        else:
            self.config.read(self.DefIni)

        # Setup the sections store and selection boxes
        self.sectionStore = gtk.ListStore(gobject.TYPE_STRING)
        self.sectionBox = gtk.ComboBox(self.sectionStore)
        self.sectionBox2 = gtk.ComboBox(self.sectionStore)
        cell = gtk.CellRendererText()
        self.sectionBox.pack_start(cell, True)
        self.sectionBox.add_attribute(cell, 'text', 0)
        self.sectionBox2.pack_start(cell, True)
        self.sectionBox2.add_attribute(cell, 'text', 0)

        for section in self.config.sections():
            self.sectionStore.append([ section ])

        self.sessionsStore = gtk.ListStore(gobject.TYPE_STRING, gobject.TYPE_STRING)

        self.sessionsView = gtk.TreeView(self.sessionsStore)

        cell = gtk.CellRendererText()
        col = gtk.TreeViewColumn("MAC", cell, text=0)
        self.sessionsView.append_column(col)

        cell = gtk.CellRendererText()
        col = gtk.TreeViewColumn("IP", cell, text=1)
        self.sessionsView.append_column(col)

        self.sessionsView.connect( "cursor-changed", self.row1, "cursor-changed" )

        self.vboxSessions = gtk.VBox( )
        self.vboxSessionBtns = gtk.HBox( homogeneous = True )

        self.sesRefresh = gtk.Button( "Refresh" )
        self.sesAuth = gtk.Button( "Auth" )
        self.sesRelease = gtk.Button( "Release" )
        self.sesBlock = gtk.Button( "Block" )
        self.sesAuth.set_sensitive( False )
        self.sesRelease.set_sensitive( False )
        self.sesBlock.set_sensitive( False )

        self.sessionView = gtk.Label("");
        self.vboxSessions.pack_start( self.sessionsView )
        self.vboxSessions.pack_start( self.sessionView, False )

        self.vboxSessionBtns.pack_start( self.sesRefresh )
        self.vboxSessionBtns.pack_start( self.sesAuth )
        self.vboxSessionBtns.pack_start( self.sesRelease )
        self.vboxSessionBtns.pack_start( self.sesBlock )

        self.vboxSessions.pack_start( self.vboxSessionBtns, False )

        self.sesRefresh.connect( "clicked", self.chilliQuery )
        self.sesRelease.connect( "clicked", self.sessionRelease )
        self.sesBlock.connect( "clicked", self.sessionBlock )
        self.sesAuth.connect( "clicked", self.sessionAuthorize )

        self.vboxSessions.show()
        self.sesRefresh.show()
        self.sesAuth.show()
        self.sesRelease.show()
        self.sesBlock.show()
        self.sessionView.show()
        self.sessionsView.show()
        self.vboxSessionBtns.show()
        
        self.btnStart = gtk.Button( "Start" )
        self.btnStop = gtk.Button( "Stop" )

        self.btnStart.set_sensitive( False )
        self.btnStop.set_sensitive( False )
        
        self.btnStart.connect( "clicked", self.startCoovaChilli )
        self.btnStop.connect( "clicked", self.stopCoovaChilli )

    def main( self ):
        print 'hello'



if __name__ == "__main__":
    COOVACHILLI = CoovaChilli()
    COOVACHILLI.main()
