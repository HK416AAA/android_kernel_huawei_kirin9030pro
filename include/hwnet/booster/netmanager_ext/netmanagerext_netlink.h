

#ifndef _NETMANAGEREXT_NETLINK_H_
#define _NETMANAGEREXT_NETLINK_H_

#include <linux/netlink.h>

/* 4080 -> MEM PAGE 4K 4096 BYTE - NLMSG_HDRLEN 16 BYTE. */
#define MAX_REQ_DATA_LEN 4080

struct seg_tlv_head_ns {
	u8 type;
	u8 len;
};

/* Notification request issued by the upper layer is defined as: */
struct req_msg_head_ns {
	u16 type; // Event enumeration values
	u16 len; // The length behind this field, the limit lower 2048
};

/* Each module sends the message request is defined as: */
struct res_msg_head_ns {
	u16 type; // Event enumeration values
	u16 len; // The length behind this field, the limit lower 2048
};

/*
 * This enumeration type is the netlink command types issued by the JNI.
 * Mainly to maintain the channel with JNI.
 */
enum nl_cmd_type_ns {
	NL_MSG_REG_NS,
	NL_MSG_JNI_REQ_NS,

	NB_MSG_REQ_BUTT_NS
};

/*
 * This enumeration type is an enumeration of internal and external messages,
 * less than 0x8000 is an upper-level message,
 * and a kernel internal module message is greater than 0x8000.
 */
enum msg_rpt_type_ns {
	APP_QOE_RPT_NS = 0,
	SLICE_IP_PARA_RPT_NS = 4,
	INTER_MSG_BASE_NS = 0x8000,
	WIFI_RPT_TIMER_NS,
	NBMSG_RPT_BUTT_NS
};

/* Message type enumeration issued by the upper layer */
enum req_msg_type_ns {
	APP_QOE_SYNC_CMD_NS = 0,
	UPDATE_APP_INFO_CMD_NS = 1,
	SLICE_RPT_CTRL_CMD_NS = 9,
	BIND_PROCESS_TO_SLICE_CMD_NS = 15,
	DEL_SLICE_BIND_CMD_NS = 16,
	/* keep value with SteadySpeedChr in booster apk */
	UPDAT_INTERFACE_NAME_NS = 26,
	/* statistics traffic begin */
	ADD_TOP_UID_NS = 32,
	DEL_TOP_UID_NS = 33,
	UPDATE_CELLULAR_MODE_NS = 34,
	SYNC_TOP_UID_LIST_NS = 35,
	UPDATE_WIFI_STATE_NS = 36,
	UPDATE_VIRTUAL_SIM_STATE_NS = 37,
	// /* statistics traffic end */
	// /* iaware game flow qoe cmd */
	GAME_FLOW_QOE_CMD_NS = 40,
	FG_CHANGE_UID_NS = 44,
	UPDATE_TOP_APP_UID_LIST_NS = 48,
	TRIGGER_TOP_APP_ABN_REPORT_NS = 49,
	SMARTCURE_PARA_COLLEC_CMD_NS = 50,
	LABEL_HIGH_PRIORITY_CMD_NS = 51,
	INFER_MODEL_COLLECT_START_NS = 52,
	INFER_MODEL_COLLECT_STOP_NS = 53,
	TCP_RECOVERY_BASE_ON_APP_CMD_NS = 54,
	CMD_NUM_MAX_NS
};

/* network type IDs defined for each network type */
enum stats_network_type_ns {
	STATS_NETWORK_TYPE_SA_NS = 0,
	STATS_NETWORK_TYPE_NSA_NS = 1,
	STATS_NETWORK_TYPE_NSA_NO_ENDC_NS = 2,
	STATS_NETWORK_TYPE_LTE_NS = 3,
	STATS_NETWORK_TYPE_OTHER_NS = 4,
	STATS_NETWORK_TYPE_WIFI_NS = 5,
	RAT_NUM_MAX_NS
};

/* module IDs defined for each module */
enum install_model_ns {
	IP_PARA_COLLEC_NS = 0,
	TCP_PARA_COLLEC_NS,
	NETWORK_SLICE_MANAGEMENT_NS,
	SOCK_DESTROY_HANDLER_NS,
	BOOSTER_COMM_NS,
	MODEL_NUM_NS
};

/* mesage map entry index */
enum map_index_ns {
	MAP_KEY_INDEX_NS = 0,
	MAP_VALUE_INDEX_NS = 1,
	MAP_ENTITY_NUM_NS
};

typedef void notify_event_ns(struct res_msg_head_ns *msg);
typedef void msg_process_ns(struct req_msg_head_ns *req, u32 len);

#endif /* _NETMANAGEREXT_NETLINK_H_ */