/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_frsrpc
#define _PIDL_HEADER_frsrpc

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#include "librpc/gen_ndr/misc.h"
#ifndef _HEADER_frsrpc
#define _HEADER_frsrpc

#define FRSRPC_CO_IFLAG_NONE	( 0x0000000 )
struct frsrpc_CommPktChunkGuidName {
	struct GUID guid;/* [subcontext(4)] */
	const char * name;/* [subcontext(4),flag(LIBNDR_FLAG_STR_NULLTERM|LIBNDR_FLAG_ALIGN2)] */
};

struct frsrpc_CommPktGSVN {
	uint64_t vsn;
	struct GUID guid;
};

/* bitmap frsrpc_CommPktCoCmdFlags */
#define FRSRPC_CO_FLAG_ABORT_CO ( 0x00000001 )
#define FRSRPC_CO_FLAG_VV_ACTIVATED ( 0x00000002 )
#define FRSRPC_CO_FLAG_CONTENT_CMD ( 0x00000004 )
#define FRSRPC_CO_FLAG_LOCATION_CMD ( 0x00000008 )
#define FRSRPC_CO_FLAG_ONLIST ( 0x00000010 )
#define FRSRPC_CO_FLAG_LOCALCO ( 0x00000020 )
#define FRSRPC_CO_FLAG_RETRY ( 0x00000040 )
#define FRSRPC_CO_FLAG_OUT_OF_ORDER ( 0x00000200 )
#define FRSRPC_CO_FLAG_NEW_FILE ( 0x00000400 )
#define FRSRPC_CO_FLAG_CONTROL ( 0x00001000 )
#define FRSRPC_CO_FLAG_DIRECTED_CO ( 0x00002000 )
#define FRSRPC_CO_FLAG_VVJOIN_TO_ORIG ( 0x00040000 )
#define FRSRPC_CO_FLAG_SKIP_ORIG_REC_C ( 0x00100000 )
#define FRSRPC_CO_FLAG_MOVEIN_GEN ( 0x00200000 )
#define FRSRPC_CO_FLAG_MORPH_GEN_HEAD ( 0x00400000 )
#define FRSRPC_CO_FLAG_JUST_OID_RESET ( 0x00800000 )
#define FRSRPC_CO_FLAG_COMPRESSED_STAGE ( 0x01000000 )
#define FRSRPC_CO_FLAG_COMPRESSED_STAGE ( 0x01000000 )
#define FRSRPC_CO_FLAG_SKIP_VV_UPDATE ( 0x02000000 )

/* bitmap frsrpc_CommPktCoCmdIFlags */
#define FRSRPC_CO_IFLAG_VVRETIRE_EXEC ( 0x00000001 )
#define FRSRPC_CO_IFLAG_CO_ABORT ( 0x00000002 )
#define FRSRPC_CO_IFLAG_DIR_ENUM_PENDING ( 0x00000004 )

enum frsrpc_CommPktCoCmdStatus
#ifndef USE_UINT_ENUMS
 {
	FRSRPC_CO_STATUS_CO_ENTERED_LOG=(int)(0x00000000),
	FRSRPC_CO_STATUS_ALLOC_STAGING_LOCAL_CO=(int)(0x00000001),
	FRSRPC_CO_STATUS_LOCAL_CO_STAGING_STARTED=(int)(0x00000002),
	FRSRPC_CO_STATUS_LOCAL_CO_STAGING_COMPLETED=(int)(0x00000003),
	FRSRPC_CO_STATUS_WAIT_RETRY_LOCAL_CO_STAGING=(int)(0x00000004),
	FRSRPC_CO_STATUS_ALLOC_STAGING_REMOTE_CO=(int)(0x00000005),
	FRSRPC_CO_STATUS_REMOTE_CO_STAGING_STARTED=(int)(0x00000006),
	FRSRPC_CO_STATUS_REMOTE_CO_STAGING_COMPLETED=(int)(0x00000007),
	FRSRPC_CO_STATUS_WAIT_RETRY_REMOTE_CO_STAGING=(int)(0x00000008),
	FRSRPC_CO_STATUS_FILE_INSTALL_REQUESTED=(int)(0x00000009),
	FRSRPC_CO_STATUS_FILE_INSTALL_STARTED=(int)(0x0000000A),
	FRSRPC_CO_STATUS_FILE_INSTALL_COMPLETED=(int)(0x0000000B),
	FRSRPC_CO_STATUS_FILE_INSTALL_WAIT_RETRY=(int)(0x0000000C),
	FRSRPC_CO_STATUS_FILE_INSTALL_RETRYING=(int)(0x0000000D),
	FRSRPC_CO_STATUS_FILE_INSTALL_RENAME_RETRYING=(int)(0x0000000E),
	FRSRPC_CO_STATUS_FILE_INSTALL_DELETE_RETRYING=(int)(0x0000000F),
	FRSRPC_CO_STATUS_CO_RECYCLED_FOR_ENUM=(int)(0x00000013),
	FRSRPC_CO_STATUS_REQUEST_OUTBOUND_PROPAGATION=(int)(0x00000014),
	FRSRPC_CO_STATUS_REQUEST_ACCEPTED_OUTBOUND_LOG=(int)(0x00000015),
	FRSRPC_CO_STATUS_DB_STATE_UPDATE_STARTED=(int)(0x00000016),
	FRSRPC_CO_STATUS_DB_STATE_UPDATE_COMPLETED=(int)(0x00000017),
	FRSRPC_CO_STATUS_CO_ABORTED=(int)(0x00000018)
}
#else
 { __donnot_use_enum_frsrpc_CommPktCoCmdStatus=0x7FFFFFFF}
#define FRSRPC_CO_STATUS_CO_ENTERED_LOG ( 0x00000000 )
#define FRSRPC_CO_STATUS_ALLOC_STAGING_LOCAL_CO ( 0x00000001 )
#define FRSRPC_CO_STATUS_LOCAL_CO_STAGING_STARTED ( 0x00000002 )
#define FRSRPC_CO_STATUS_LOCAL_CO_STAGING_COMPLETED ( 0x00000003 )
#define FRSRPC_CO_STATUS_WAIT_RETRY_LOCAL_CO_STAGING ( 0x00000004 )
#define FRSRPC_CO_STATUS_ALLOC_STAGING_REMOTE_CO ( 0x00000005 )
#define FRSRPC_CO_STATUS_REMOTE_CO_STAGING_STARTED ( 0x00000006 )
#define FRSRPC_CO_STATUS_REMOTE_CO_STAGING_COMPLETED ( 0x00000007 )
#define FRSRPC_CO_STATUS_WAIT_RETRY_REMOTE_CO_STAGING ( 0x00000008 )
#define FRSRPC_CO_STATUS_FILE_INSTALL_REQUESTED ( 0x00000009 )
#define FRSRPC_CO_STATUS_FILE_INSTALL_STARTED ( 0x0000000A )
#define FRSRPC_CO_STATUS_FILE_INSTALL_COMPLETED ( 0x0000000B )
#define FRSRPC_CO_STATUS_FILE_INSTALL_WAIT_RETRY ( 0x0000000C )
#define FRSRPC_CO_STATUS_FILE_INSTALL_RETRYING ( 0x0000000D )
#define FRSRPC_CO_STATUS_FILE_INSTALL_RENAME_RETRYING ( 0x0000000E )
#define FRSRPC_CO_STATUS_FILE_INSTALL_DELETE_RETRYING ( 0x0000000F )
#define FRSRPC_CO_STATUS_CO_RECYCLED_FOR_ENUM ( 0x00000013 )
#define FRSRPC_CO_STATUS_REQUEST_OUTBOUND_PROPAGATION ( 0x00000014 )
#define FRSRPC_CO_STATUS_REQUEST_ACCEPTED_OUTBOUND_LOG ( 0x00000015 )
#define FRSRPC_CO_STATUS_DB_STATE_UPDATE_STARTED ( 0x00000016 )
#define FRSRPC_CO_STATUS_DB_STATE_UPDATE_COMPLETED ( 0x00000017 )
#define FRSRPC_CO_STATUS_CO_ABORTED ( 0x00000018 )
#endif
;

/* bitmap frsrpc_CommPktCoCmdContentCmd */
#define FRSRPC_CONTENT_REASON_DATA_OVERWRITE ( 0x00000001 )
#define FRSRPC_CONTENT_REASON_DATA_EXTEND ( 0x00000002 )
#define FRSRPC_CONTENT_REASON_DATA_TRUNCATION ( 0x00000004 )
#define FRSRPC_CONTENT_REASON_NAMED_DATA_OVERWRITE ( 0x00000010 )
#define FRSRPC_CONTENT_REASON_NAMED_DATA_EXTEND ( 0x00000020 )
#define FRSRPC_CONTENT_REASON_NAMED_DATA_TRUNCATION ( 0x00000040 )
#define FRSRPC_CONTENT_REASON_FILE_CREATE ( 0x00000100 )
#define FRSRPC_CONTENT_REASON_FILE_DELETE ( 0x00000200 )
#define FRSRPC_CONTENT_REASON_EA_CHANGE ( 0x00000400 )
#define FRSRPC_CONTENT_REASON_SECURITY_CHANGE ( 0x00000800 )
#define FRSRPC_CONTENT_REASON_OLD_NAME ( 0x00001000 )
#define FRSRPC_CONTENT_REASON_NEW_NAME ( 0x00002000 )
#define FRSRPC_CONTENT_REASON_BASIC_INFO_CHANGE ( 0x00004000 )
#define FRSRPC_CONTENT_REASON_COMPRESSION_CHANGE ( 0x00020000 )

enum frsrpc_CommPktCoCmdLocationCmd
#ifndef USE_UINT_ENUMS
 {
	FRSRPC_CO_LOCATION_FILE_CREATE=(int)(0x00000000),
	FRSRPC_CO_LOCATION_DIR_CREATE=(int)(0x00000000|0x00000001),
	FRSRPC_CO_LOCATION_FILE_DELETE=(int)(0x00000002),
	FRSRPC_CO_LOCATION_DIR_DELETE=(int)(0x00000002|0x00000001),
	FRSRPC_CO_LOCATION_FILE_MOVEIN=(int)(0x00000004),
	FRSRPC_CO_LOCATION_DIR_MOVEIN=(int)(0x00000004|0x00000001),
	FRSRPC_CO_LOCATION_FILE_MOVEIN2=(int)(0x00000006),
	FRSRPC_CO_LOCATION_DIR_MOVEIN2=(int)(0x00000006|0x00000001),
	FRSRPC_CO_LOCATION_FILE_MOVEOUT=(int)(0x00000008),
	FRSRPC_CO_LOCATION_DIR_MOVEOUT=(int)(0x00000008|0x00000001),
	FRSRPC_CO_LOCATION_FILE_MOVERS=(int)(0x0000000a),
	FRSRPC_CO_LOCATION_DIR_MOVERS=(int)(0x0000000a|0x00000001),
	FRSRPC_CO_LOCATION_FILE_MOVEDIR=(int)(0x0000000c),
	FRSRPC_CO_LOCATION_DIR_MOVEDIR=(int)(0x0000000c|0x00000001),
	FRSRPC_CO_LOCATION_FILE_NO_CMD=(int)(0x0000000e),
	FRSRPC_CO_LOCATION_DIR_NO_CMD=(int)(0x0000000e|0x00000001)
}
#else
 { __donnot_use_enum_frsrpc_CommPktCoCmdLocationCmd=0x7FFFFFFF}
#define FRSRPC_CO_LOCATION_FILE_CREATE ( 0x00000000 )
#define FRSRPC_CO_LOCATION_DIR_CREATE ( 0x00000000|0x00000001 )
#define FRSRPC_CO_LOCATION_FILE_DELETE ( 0x00000002 )
#define FRSRPC_CO_LOCATION_DIR_DELETE ( 0x00000002|0x00000001 )
#define FRSRPC_CO_LOCATION_FILE_MOVEIN ( 0x00000004 )
#define FRSRPC_CO_LOCATION_DIR_MOVEIN ( 0x00000004|0x00000001 )
#define FRSRPC_CO_LOCATION_FILE_MOVEIN2 ( 0x00000006 )
#define FRSRPC_CO_LOCATION_DIR_MOVEIN2 ( 0x00000006|0x00000001 )
#define FRSRPC_CO_LOCATION_FILE_MOVEOUT ( 0x00000008 )
#define FRSRPC_CO_LOCATION_DIR_MOVEOUT ( 0x00000008|0x00000001 )
#define FRSRPC_CO_LOCATION_FILE_MOVERS ( 0x0000000a )
#define FRSRPC_CO_LOCATION_DIR_MOVERS ( 0x0000000a|0x00000001 )
#define FRSRPC_CO_LOCATION_FILE_MOVEDIR ( 0x0000000c )
#define FRSRPC_CO_LOCATION_DIR_MOVEDIR ( 0x0000000c|0x00000001 )
#define FRSRPC_CO_LOCATION_FILE_NO_CMD ( 0x0000000e )
#define FRSRPC_CO_LOCATION_DIR_NO_CMD ( 0x0000000e|0x00000001 )
#endif
;

struct frsrpc_CommPktChangeOrderCommand {
	uint32_t sequence_number;
	uint32_t flags;
	uint32_t iflags;
	enum frsrpc_CommPktCoCmdStatus status;
	uint32_t content_cmd;
	enum frsrpc_CommPktCoCmdLocationCmd location_cmd;
	uint32_t file_attributes;
	uint32_t file_version_number;
	uint32_t partern_ack_sequence_number;
	uint32_t not_used;/* [value(0)] */
	uint64_t file_size;
	uint64_t file_offset;
	uint64_t frs_vsn;
	uint64_t file_usn;
	uint64_t jrnl_usn;
	uint64_t jrnl_first_usn;
	uint32_t original_replica_num;
	uint32_t new_replica_num;
	struct GUID change_order_guid;
	struct GUID originator_guid;
	struct GUID file_guid;
	struct GUID old_parent_guid;
	struct GUID new_parent_guid;
	struct GUID connection_guid;
	uint64_t ack_version;
	uint64_t spare2ul1;/* [value(0)] */
	uint64_t spare1guid_p1;/* [value(0)] */
	uint64_t spare1guid_p2;/* [value(0)] */
	uint64_t spare2guid_p1;/* [value(0)] */
	uint64_t spare3guid_p2;/* [value(0)] */
	uint32_t spare1wcs;/* [value(0)] */
	uint32_t spare2wcs;/* [value(0)] */
	uint32_t extension;/* [value(0)] */
	uint32_t spare2bin;/* [value(0)] */
	NTTIME event_time;
	uint16_t file_name_length;/* [value(2*strlen_m(file_name))] */
	const char *file_name;/* [charset(UTF16)] */
	uint8_t padding1;/* [value(0)] */
	uint8_t padding2;/* [value(0)] */
	uint8_t padding3;/* [value(0)] */
	uint8_t padding4;/* [value(0)] */
};

enum frsrpc_CommPktDataExtensionType
#ifndef USE_UINT_ENUMS
 {
	FRSRPC_DATA_EXTENSION_TERMINATOR=(int)(0x00000000),
	FRSRPC_DATA_EXTENSION_MD5_CHECKSUM=(int)(0x00000001),
	FRSRPC_DATA_EXTENSION_RETRY_TIMEOUT=(int)(0x00000002)
}
#else
 { __donnot_use_enum_frsrpc_CommPktDataExtensionType=0x7FFFFFFF}
#define FRSRPC_DATA_EXTENSION_TERMINATOR ( 0x00000000 )
#define FRSRPC_DATA_EXTENSION_MD5_CHECKSUM ( 0x00000001 )
#define FRSRPC_DATA_EXTENSION_RETRY_TIMEOUT ( 0x00000002 )
#endif
;

struct frsrpc_CommPktDataExtensionChecksum {
	uint32_t prefix_size;/* [value(0x00000018)] */
	enum frsrpc_CommPktDataExtensionType prefix_type;/* [value(FRSRPC_DATA_EXTENSION_MD5_CHECKSUM)] */
	uint8_t data[16];
}/* [flag(LIBNDR_PRINT_ARRAY_HEX)] */;

struct frsrpc_CommPktDataExtensionRetryTimeout {
	uint32_t prefix_size;/* [value(0x00000018)] */
	enum frsrpc_CommPktDataExtensionType prefix_type;/* [value(FRSRPC_DATA_EXTENSION_RETRY_TIMEOUT)] */
	uint32_t count;
	uint32_t not_used;/* [value(0)] */
	NTTIME first_try_time;
};

enum frsrpc_CommPktCoRecordExtensionMajor
#ifndef USE_UINT_ENUMS
 {
	FRSRPC_CO_RECORD_EXTENSION_VERSION_WIN2K=(int)(0x0000),
	FRSRPC_CO_RECORD_EXTENSION_VERSION_1=(int)(0x0001)
}
#else
 { __donnot_use_enum_frsrpc_CommPktCoRecordExtensionMajor=0x7FFFFFFF}
#define FRSRPC_CO_RECORD_EXTENSION_VERSION_WIN2K ( 0x0000 )
#define FRSRPC_CO_RECORD_EXTENSION_VERSION_1 ( 0x0001 )
#endif
;

struct frsrpc_CommPktCoRecordExtensionWin2k {
	uint32_t field_size;/* [value(0x00000028)] */
	enum frsrpc_CommPktCoRecordExtensionMajor major;/* [value(FRSRPC_CO_RECORD_EXTENSION_VERSION_WIN2K)] */
	uint16_t offset_count;/* [value(0x0001)] */
	uint32_t offset;/* [value(0x00000010)] */
	uint32_t offset_last;/* [value(0)] */
	struct frsrpc_CommPktDataExtensionChecksum data_checksum;
};

struct frsrpc_CommPktChangeOrderRecordExtension {
	uint32_t field_size;/* [value(0x00000048)] */
	enum frsrpc_CommPktCoRecordExtensionMajor major;
	uint16_t offset_count;/* [value(0x0002)] */
	uint32_t offset0;/* [value(0x00000018)] */
	uint32_t offset1;/* [value(0x00000030)] */
	uint32_t offset_last;/* [value(0)] */
	uint32_t not_used;/* [value(0)] */
	struct frsrpc_CommPktDataExtensionChecksum data_checksum;
	struct frsrpc_CommPktDataExtensionRetryTimeout data_retry_timeout;
};

enum frsrpc_CommPktCommand
#ifndef USE_UINT_ENUMS
 {
	FRSRPC_COMMAND_REMOTE_CO=(int)(0x00000218),
	FRSRPC_COMMAND_RECEIVING_STATE=(int)(0x00000238),
	FRSRPC_COMMAND_REMOTE_CO_DONE=(int)(0x00000250),
	FRSRPC_COMMAND_ABORT_FETCH=(int)(0x00000246),
	FRSRPC_COMMAND_RETRY_FETCH=(int)(0x00000244),
	FRSRPC_COMMAND_NEED_JOIN=(int)(0x00000121),
	FRSRPC_COMMAND_START_JOIN=(int)(0x00000122),
	FRSRPC_COMMAND_JOINING=(int)(0x00000130),
	FRSRPC_COMMAND_JOINED=(int)(0x00000128),
	FRSRPC_COMMAND_UNJOIN_REMOTE=(int)(0x00000148),
	FRSRPC_COMMAND_WJOIN_DONE=(int)(0x00000136),
	FRSRPC_COMMAND_SEND_STAGE=(int)(0x00000228)
}
#else
 { __donnot_use_enum_frsrpc_CommPktCommand=0x7FFFFFFF}
#define FRSRPC_COMMAND_REMOTE_CO ( 0x00000218 )
#define FRSRPC_COMMAND_RECEIVING_STATE ( 0x00000238 )
#define FRSRPC_COMMAND_REMOTE_CO_DONE ( 0x00000250 )
#define FRSRPC_COMMAND_ABORT_FETCH ( 0x00000246 )
#define FRSRPC_COMMAND_RETRY_FETCH ( 0x00000244 )
#define FRSRPC_COMMAND_NEED_JOIN ( 0x00000121 )
#define FRSRPC_COMMAND_START_JOIN ( 0x00000122 )
#define FRSRPC_COMMAND_JOINING ( 0x00000130 )
#define FRSRPC_COMMAND_JOINED ( 0x00000128 )
#define FRSRPC_COMMAND_UNJOIN_REMOTE ( 0x00000148 )
#define FRSRPC_COMMAND_WJOIN_DONE ( 0x00000136 )
#define FRSRPC_COMMAND_SEND_STAGE ( 0x00000228 )
#endif
;

enum frsrpc_CommPktChunkType
#ifndef USE_UINT_ENUMS
 {
	FRSRPC_COMM_PKT_CHUNK_BOP=(int)(0x0001),
	FRSRPC_COMM_PKT_CHUNK_COMMAND=(int)(0x0002),
	FRSRPC_COMM_PKT_CHUNK_TO=(int)(0x0003),
	FRSRPC_COMM_PKT_CHUNK_FROM=(int)(0x0004),
	FRSRPC_COMM_PKT_CHUNK_REPLICA=(int)(0x0005),
	FRSRPC_COMM_PKT_CHUNK_CONNECTION=(int)(0x0008),
	FRSRPC_COMM_PKT_CHUNK_JOIN_GUID=(int)(0x0006),
	FRSRPC_COMM_PKT_CHUNK_LAST_JOIN_TIME=(int)(0x0012),
	FRSRPC_COMM_PKT_CHUNK_VVECTOR=(int)(0x0007),
	FRSRPC_COMM_PKT_CHUNK_JOIN_TIME=(int)(0x0011),
	FRSRPC_COMM_PKT_CHUNK_REPLICA_VERSION_GUID=(int)(0x0014),
	FRSRPC_COMM_PKT_CHUNK_COMPRESSION_GUID=(int)(0x0018),
	FRSRPC_COMM_PKT_CHUNK_BLOCK=(int)(0x0009),
	FRSRPC_COMM_PKT_CHUNK_BLOCK_SIZE=(int)(0x000A),
	FRSRPC_COMM_PKT_CHUNK_FILE_SIZE=(int)(0x000B),
	FRSRPC_COMM_PKT_CHUNK_FILE_OFFSET=(int)(0x000C),
	FRSRPC_COMM_PKT_CHUNK_GVSN=(int)(0x000E),
	FRSRPC_COMM_PKT_CHUNK_CO_GUID=(int)(0x000F),
	FRSRPC_COMM_PKT_CHUNK_CO_SEQUENCE_NUMBER=(int)(0x0010),
	FRSRPC_COMM_PKT_CHUNK_REMOTE_CO=(int)(0x000D),
	FRSRPC_COMM_PKT_CHUNK_CO_EXT_WIN2K=(int)(0x0016),
	FRSRPC_COMM_PKT_CHUNK_CO_EXTENTION_2=(int)(0x0017),
	FRSRPC_COMM_PKT_CHUNK_EOP=(int)(0x0013)
}
#else
 { __donnot_use_enum_frsrpc_CommPktChunkType=0x7FFFFFFF}
#define FRSRPC_COMM_PKT_CHUNK_BOP ( 0x0001 )
#define FRSRPC_COMM_PKT_CHUNK_COMMAND ( 0x0002 )
#define FRSRPC_COMM_PKT_CHUNK_TO ( 0x0003 )
#define FRSRPC_COMM_PKT_CHUNK_FROM ( 0x0004 )
#define FRSRPC_COMM_PKT_CHUNK_REPLICA ( 0x0005 )
#define FRSRPC_COMM_PKT_CHUNK_CONNECTION ( 0x0008 )
#define FRSRPC_COMM_PKT_CHUNK_JOIN_GUID ( 0x0006 )
#define FRSRPC_COMM_PKT_CHUNK_LAST_JOIN_TIME ( 0x0012 )
#define FRSRPC_COMM_PKT_CHUNK_VVECTOR ( 0x0007 )
#define FRSRPC_COMM_PKT_CHUNK_JOIN_TIME ( 0x0011 )
#define FRSRPC_COMM_PKT_CHUNK_REPLICA_VERSION_GUID ( 0x0014 )
#define FRSRPC_COMM_PKT_CHUNK_COMPRESSION_GUID ( 0x0018 )
#define FRSRPC_COMM_PKT_CHUNK_BLOCK ( 0x0009 )
#define FRSRPC_COMM_PKT_CHUNK_BLOCK_SIZE ( 0x000A )
#define FRSRPC_COMM_PKT_CHUNK_FILE_SIZE ( 0x000B )
#define FRSRPC_COMM_PKT_CHUNK_FILE_OFFSET ( 0x000C )
#define FRSRPC_COMM_PKT_CHUNK_GVSN ( 0x000E )
#define FRSRPC_COMM_PKT_CHUNK_CO_GUID ( 0x000F )
#define FRSRPC_COMM_PKT_CHUNK_CO_SEQUENCE_NUMBER ( 0x0010 )
#define FRSRPC_COMM_PKT_CHUNK_REMOTE_CO ( 0x000D )
#define FRSRPC_COMM_PKT_CHUNK_CO_EXT_WIN2K ( 0x0016 )
#define FRSRPC_COMM_PKT_CHUNK_CO_EXTENTION_2 ( 0x0017 )
#define FRSRPC_COMM_PKT_CHUNK_EOP ( 0x0013 )
#endif
;

union frsrpc_CommPktChunkData {
	DATA_BLOB blob;/* [default,flag(LIBNDR_FLAG_REMAINING)] */
	uint32_t bop;/* [value(0),case(FRSRPC_COMM_PKT_CHUNK_BOP)] */
	enum frsrpc_CommPktCommand command;/* [case(FRSRPC_COMM_PKT_CHUNK_COMMAND)] */
	struct frsrpc_CommPktChunkGuidName to;/* [case(FRSRPC_COMM_PKT_CHUNK_TO)] */
	struct frsrpc_CommPktChunkGuidName from;/* [case(FRSRPC_COMM_PKT_CHUNK_FROM)] */
	struct frsrpc_CommPktChunkGuidName replica;/* [case(FRSRPC_COMM_PKT_CHUNK_REPLICA)] */
	struct frsrpc_CommPktChunkGuidName connection;/* [case(FRSRPC_COMM_PKT_CHUNK_CONNECTION)] */
	struct GUID join_guid;/* [subcontext(4),case(FRSRPC_COMM_PKT_CHUNK_JOIN_GUID)] */
	NTTIME last_join_time;/* [case(FRSRPC_COMM_PKT_CHUNK_LAST_JOIN_TIME)] */
	struct frsrpc_CommPktGSVN vvector;/* [case(FRSRPC_COMM_PKT_CHUNK_VVECTOR),subcontext(4)] */
	NTTIME join_time;/* [case(FRSRPC_COMM_PKT_CHUNK_JOIN_TIME),subcontext(4)] */
	struct GUID replica_version_guid;/* [case(FRSRPC_COMM_PKT_CHUNK_REPLICA_VERSION_GUID),subcontext(4)] */
	struct GUID compression_guid;/* [case(FRSRPC_COMM_PKT_CHUNK_COMPRESSION_GUID)] */
	DATA_BLOB block;/* [case(FRSRPC_COMM_PKT_CHUNK_BLOCK),flag(LIBNDR_FLAG_REMAINING)] */
	uint64_t block_size;/* [case(FRSRPC_COMM_PKT_CHUNK_BLOCK_SIZE)] */
	uint64_t file_size;/* [case(FRSRPC_COMM_PKT_CHUNK_FILE_SIZE)] */
	uint64_t file_offset;/* [case(FRSRPC_COMM_PKT_CHUNK_FILE_OFFSET)] */
	struct frsrpc_CommPktGSVN gvsn;/* [case(FRSRPC_COMM_PKT_CHUNK_GVSN),subcontext(4)] */
	struct GUID co_guid;/* [subcontext(4),case(FRSRPC_COMM_PKT_CHUNK_CO_GUID)] */
	uint32_t co_sequnence_number;/* [case(FRSRPC_COMM_PKT_CHUNK_CO_SEQUENCE_NUMBER)] */
	struct frsrpc_CommPktChangeOrderCommand remote_co;/* [subcontext(4),case(FRSRPC_COMM_PKT_CHUNK_REMOTE_CO)] */
	struct frsrpc_CommPktCoRecordExtensionWin2k co_ext_win2k;/* [subcontext(4),case(FRSRPC_COMM_PKT_CHUNK_CO_EXT_WIN2K)] */
	struct frsrpc_CommPktChangeOrderRecordExtension co_extension2;/* [subcontext(4),case(FRSRPC_COMM_PKT_CHUNK_CO_EXTENTION_2)] */
}/* [nodiscriminant] */;

struct frsrpc_CommPktChunk {
	enum frsrpc_CommPktChunkType type;
	union frsrpc_CommPktChunkData data;/* [switch_is(type),subcontext(4)] */
}/* [public,flag(LIBNDR_FLAG_NOALIGN)] */;

struct frsrpc_CommPktChunkCtr {
	uint32_t num_chunks;
	struct frsrpc_CommPktChunk *chunks;
}/* [flag(LIBNDR_FLAG_NOALIGN),nopull,nopush] */;

enum frsrpc_CommPktMajor
#ifndef USE_UINT_ENUMS
 {
	FRSRPC_COMM_PKT_MAJOR_0=(int)(0x00000000)
}
#else
 { __donnot_use_enum_frsrpc_CommPktMajor=0x7FFFFFFF}
#define FRSRPC_COMM_PKT_MAJOR_0 ( 0x00000000 )
#endif
;

enum frsrpc_CommPktMinor
#ifndef USE_UINT_ENUMS
 {
	FRSRPC_COMM_PKT_MINOR_0=(int)(0x00000000),
	FRSRPC_COMM_PKT_MINOR_1=(int)(0x00000001),
	FRSRPC_COMM_PKT_MINOR_2=(int)(0x00000002),
	FRSRPC_COMM_PKT_MINOR_3=(int)(0x00000003),
	FRSRPC_COMM_PKT_MINOR_4=(int)(0x00000004),
	FRSRPC_COMM_PKT_MINOR_5=(int)(0x00000005),
	FRSRPC_COMM_PKT_MINOR_6=(int)(0x00000006),
	FRSRPC_COMM_PKT_MINOR_7=(int)(0x00000007),
	FRSRPC_COMM_PKT_MINOR_8=(int)(0x00000008),
	FRSRPC_COMM_PKT_MINOR_9=(int)(0x00000009)
}
#else
 { __donnot_use_enum_frsrpc_CommPktMinor=0x7FFFFFFF}
#define FRSRPC_COMM_PKT_MINOR_0 ( 0x00000000 )
#define FRSRPC_COMM_PKT_MINOR_1 ( 0x00000001 )
#define FRSRPC_COMM_PKT_MINOR_2 ( 0x00000002 )
#define FRSRPC_COMM_PKT_MINOR_3 ( 0x00000003 )
#define FRSRPC_COMM_PKT_MINOR_4 ( 0x00000004 )
#define FRSRPC_COMM_PKT_MINOR_5 ( 0x00000005 )
#define FRSRPC_COMM_PKT_MINOR_6 ( 0x00000006 )
#define FRSRPC_COMM_PKT_MINOR_7 ( 0x00000007 )
#define FRSRPC_COMM_PKT_MINOR_8 ( 0x00000008 )
#define FRSRPC_COMM_PKT_MINOR_9 ( 0x00000009 )
#endif
;

struct frsrpc_FrsSendCommPktReq {
	enum frsrpc_CommPktMajor major;
	enum frsrpc_CommPktMinor minor;
	uint32_t cs_id;/* [value] */
	uint32_t memory_len;/* [value(pkt_len+12)] */
	uint32_t pkt_len;/* [range(0,262144),value(ndr_size_frsrpc_CommPktChunkCtr(r->ctr,ndr->flags))] */
	uint32_t upk_len;/* [value(0)] */
	struct frsrpc_CommPktChunkCtr *ctr;/* [unique,subcontext_size(pkt_len),subcontext(4)] */
	uint32_t data_name;/* [value(0)] */
	uint32_t data_handle;/* [value(0)] */
};

enum frsrpc_PartnerAuthLevel
#ifndef USE_UINT_ENUMS
 {
	FRSRPC_PARENT_AUTH_LEVEL_ENCRYPTED_KERBEROS=(int)(0x00000000),
	FRSRPC_PARENT_AUTH_LEVEL_NO_AUTHENTICATION=(int)(0x00000001)
}
#else
 { __donnot_use_enum_frsrpc_PartnerAuthLevel=0x7FFFFFFF}
#define FRSRPC_PARENT_AUTH_LEVEL_ENCRYPTED_KERBEROS ( 0x00000000 )
#define FRSRPC_PARENT_AUTH_LEVEL_NO_AUTHENTICATION ( 0x00000001 )
#endif
;


struct frsrpc_FrsSendCommPkt {
	struct {
		struct frsrpc_FrsSendCommPktReq req;
	} in;

	struct {
		WERROR result;
	} out;

};


struct frsrpc_FrsVerifyPromotionParent {
	struct {
		const char *parent_account;/* [charset(UTF16),unique] */
		const char *parent_password;/* [charset(UTF16),unique] */
		const char *replica_set_name;/* [unique,charset(UTF16)] */
		const char *replica_set_type;/* [unique,charset(UTF16)] */
		enum frsrpc_PartnerAuthLevel partner_auth_level;
		uint32_t __ndr_guid_size;
	} in;

	struct {
		WERROR result;
	} out;

};


struct frsrpc_FrsStartPromotionParent {
	struct {
		const char *parent_account;/* [unique,charset(UTF16)] */
		const char *parent_password;/* [unique,charset(UTF16)] */
		const char *replica_set_name;/* [charset(UTF16),unique] */
		const char *replica_set_type;/* [unique,charset(UTF16)] */
		const char *connection_name;/* [charset(UTF16),unique] */
		const char *partner_name;/* [unique,charset(UTF16)] */
		const char *partner_princ_name;/* [unique,charset(UTF16)] */
		enum frsrpc_PartnerAuthLevel partner_auth_level;
		uint32_t __ndr_guid_size;/* [range(16,16),value(16)] */
		struct GUID *connection_guid;/* [unique,subcontext_size(16),subcontext(4)] */
		struct GUID *partner_guid;/* [subcontext_size(16),unique,subcontext(4)] */
		struct GUID *parent_guid;/* [subcontext_size(16),unique,subcontext(4)] */
	} in;

	struct {
		struct GUID *parent_guid;/* [subcontext_size(16),unique,subcontext(4)] */
		WERROR result;
	} out;

};


struct frsrpc_FrsNOP {
	struct {
		WERROR result;
	} out;

};


struct FRSRPC_BACKUP_COMPLETE {
	int _dummy_element;
};


struct FRSRPC_BACKUP_COMPLETE_5 {
	int _dummy_element;
};


struct FRSRPC_BACKUP_COMPLETE_6 {
	int _dummy_element;
};


struct FRSRPC_BACKUP_COMPLETE_7 {
	int _dummy_element;
};


struct FRSRPC_BACKUP_COMPLETE_8 {
	int _dummy_element;
};


struct FRSRPC_BACKUP_COMPLETE_9 {
	int _dummy_element;
};


struct FRSRPC_VERIFY_PROMOTION_PARENT_EX {
	int _dummy_element;
};

#endif /* _HEADER_frsrpc */
#endif /* _PIDL_HEADER_frsrpc */
