/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: hts protocol header file
 * Create: 2025/03/27
 */
#ifndef __HTS_LITE_COMM_H__
#define __HTS_LITE_COMM_H__

#define MAX_ATTR_PER_NODE 8

#define MAX_EVENT_PER_NODE 3

#define MAX_REAL_HTS_EVENT_ID 1024 // to be confirm

struct hts_lite_resp_t {
	unsigned int user_id;
	unsigned int ret_code;
	unsigned int session_id;
};

enum session_id {
	SESSION_TEST,
	SESSION_TYPE_ENV_SOUND_DETECTOR,
	SESSION_TYPE_PUSH_AOD,
	SESSION_CNT,
};

enum node_type {
	NODE_TYPE_FACE_DETECTION,
	NODE_TYPE_SWING_EMOTION_SOURCE = 1,
	NODE_TYPE_NN_TINY_MODEL = 4,
	NODE_TYPE_EMOTION_MERGE = 7,
	NODE_TYPE_IOMCU_DFA = 20,
};

enum attribute_type {
	ATTR_TYPE_DEFAULT,
	ATTR_TYPE_SWING_FPS = 3,
	ATTR_TYPE_MODEL_ID = 4,
	ATTR_TYPE_EMOTION_FUSION_MODE = 6,
	ATTR_TYPE_CNT,
};

struct node_attribute {
	unsigned int type;
	unsigned int value;
};

enum event_tag {
	EVENT_TAG_ZERO,
	EVENT_TAG_ONE,
	EVENT_TAG_TWO,
	EVENT_TAG_THREE,
	EVENT_TAG_CNT,
};

struct buffer_handle { // 结合内存方案更新
	unsigned int addr;
	unsigned int size;
};

struct event_config {
	unsigned int event_id;
	unsigned int event_tag;
	struct buffer_handle buf_handle;
};

struct node_config {
	unsigned int session_id;
	unsigned int node_type;
	unsigned int node_id;
	struct node_attribute node_attrs[MAX_ATTR_PER_NODE];
	int input_event_cnt;
	struct event_config input_events[MAX_EVENT_PER_NODE];
	int output_event_cnt;
	struct event_config output_events[MAX_EVENT_PER_NODE];
};

struct lpc_create_session_t {
	unsigned short uid;
	unsigned int session_id;
};

struct lpc_start_session_t {
	unsigned int session_id;
};

struct lpc_stop_session_t {
	unsigned int session_id;
};

struct lpc_destory_session_t {
	unsigned int session_id;
};

struct lpc_set_node_config_t {
	struct node_config node_config;
};

struct lpc_update_node_config_t {
	unsigned int session_id;
	unsigned int node_type;
	unsigned int node_id;
	struct node_attribute node_attrs[MAX_ATTR_PER_NODE];
};

enum hts_lite_cmd {
	SUB_CMD_HTS_LITE_CREATE_SESSION = 0x20,
	SUB_CMD_HTS_LITE_SET_NODE_CONFIG,
	SUB_CMD_HTS_LITE_START_SESSION,
	SUB_CMD_HTS_LITE_STOP_SESSION,
	SUB_CMD_HTS_LITE_DESTORY_SESSION,
	SUB_CMD_HTS_LITE_UPDATE_CONFIG,
	SUB_CMD_HTS_LITE_UPDATE_BASE_ADDR,
	SUB_CMD_LPC_SESSION_UPLOAD,
};

struct hts_lite_msg {
	unsigned int user_id;
	unsigned int session_id;
	union {
		struct lpc_create_session_t create_session_param;
		struct lpc_start_session_t start_session_param;
		struct lpc_stop_session_t stop_session_param;
		struct lpc_destory_session_t destory_session_param;
		struct lpc_set_node_config_t set_node_config_param;
		struct lpc_update_node_config_t update_node_config_param;
	};
};

struct hts_teeos_msg {
	unsigned int hts_cmd;
	unsigned int session_id;
	unsigned int base_addr;
	unsigned int base_addr_size;
};

#endif