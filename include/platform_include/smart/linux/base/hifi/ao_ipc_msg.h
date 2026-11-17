/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: soc_dsp ao ipc msg head file
 * Create: 2020-9-18
 */

#ifndef _AO_IPC_MSF_H_
#define _AO_IPC_MSF_H_

#include "typedef.h"

enum ao_ipc_msg_tag {
	TAG_PS = 0x5,
	TAG_ORIENTATION = 0x8,
	TAG_MOTION = 0x2E,
	TAG_HIFI = 0x97,
	TAG_LPC = 171,
	TAG_BT_OFFLOAD = 203,
	TAG_AI_NC = 204,
	TAG_AUDIO_FUSION = 210,
	TAG_ULTRA_MISTOUCH_ACC = 211,
	TAG_NOTIFICATION = 220, /* sensorhub<->dsp : AOD */
};

enum hifi2sensor_hub_msg {
	HIFI_SEND_TO_IOM3_CMD = 7,
	IPC_TO_SENSORHUB_CMD_SCENE_DENOISE_OPEN = 0x61,
	IPC_TO_SENSORHUB_CMD_SCENE_DENOISE_DATA_READY = 0x62,
	IPC_TO_SENSORHUB_CMD_SCENE_DENOISE_CLOSE = 0x63,
	IPC_TO_SENSORHUB_CMD_SCENE_DENOISE_CHECK_BUFFER = 0x65,

	IPC_TO_SENSORHUB_CMD_SED_OPEN = 0x81,
	IPC_TO_SENSORHUB_CMD_SED_DATA_READY = 0x82,
	IPC_TO_SENSORHUB_CMD_SED_CLOSE = 0x83,
	IPC_TO_SENSORHUB_CMD_SED_CHECK_BUFFER = 0x85,
	IPC_TO_SENSORHUB_CMD_SED_RESET_BUFFER = 0x87,

	IPC_TO_SENSORHUB_CMD_PICKUP_START = 0x88,
	IPC_TO_SENSORHUB_CMD_PICKUP_STOP = 0x89,

	/* ipc for ath_watch gt mode */
	IPC_TO_SENSORHUB_LOCAL_PLAYER_START_RESP_CMD = 0x90,
	IPC_TO_SENSORHUB_LOCAL_PLAYER_STOP_RESP_CMD,
	IPC_TO_SENSORHUB_LOCAL_PLAYER_PLAY_DONE,
	IPC_TO_SENSORHUB_LOCAL_PLAYER_POSITION_RESP_CMD,
	IPC_TO_SENSORHUB_LOCAL_RECORD_START_RESP_CMD,
	IPC_TO_SENSORHUB_LOCAL_RECORD_STOP_RESP_CMD,
	IPC_TO_SENSORHUB_LOCAL_RECORD_NOTIFY_CMD,
	IPC_TO_SENSORHUB_LOCAL_NOTIFICATION_START_RES_CMD,
	IPC_TO_SENSORHUB_LOCAL_NOTIFICATION_UPDATE_REQ_CMD,
	IPC_TO_SENSORHUB_LOCAL_NOTIFICATION_STOP_RES_CMD,
	IPC_TO_SENSORHUB_GET_EFFECT_PARAM_RES_CMD,
	IPC_TO_SENSORHUB_SAVE_LOG_CMD,
	IPC_TO_SENSORHUB_SAVE_HOOK_PCM_CMD,
	IPC_TO_SENSORHUB_BT_SLAVE_VOICE_START_RESP_CMD,
	IPC_TO_SENSORHUB_BT_SLAVE_VOICE_STOP_RESP_CMD,
	/* ipc for ath_watch wakeup */
	IPC_TO_SENSORHUB_WAKEUP_START_RECV_CMD,
	IPC_TO_SENSORHUB_WAKEUP_STOP_RECV_CMD,
	IPC_TO_SENSORHUB_VOICE_SLVM_INFO_NOTIFY_CMD,
	/* ipc for ath_glass wakeup */
	IPC_TO_SENSORHUB_WAKEUP_OPEN_3MIC_PATH_CMD,
	IPC_TO_SENSORHUB_WAKEUP_CLOSE_3MIC_PATH_CMD,
	IPC_TO_SENSORHUB_WAKEUP_CLOSE_MAD_PATH_CMD,
	IPC_TO_SENSORHUB_WAKEUP_SEND_FEATURE_DATA_CMD,
	IPC_TO_SENSORHUB_WAKEUP_TRIGGER_SUCCESS_CMD,
	IPC_TO_SENSORHUB_WAKEUP_SEND_ONESHOT_DATA_CMD,
	IPC_TO_SENSORHUB_WAKEUP_SEND_INTENT_DATA_CMD,
	IPC_TO_SENSORHUB_WAKEUP_SEND_AAC_ENCODED_CMD,
	/* ipc for  wakeup */
	IPC_TO_SENSORHUB_CMD_WAKEUP_OPEN = 0xb0,
	IPC_TO_SENSORHUB_CMD_WAKEUP_CLOSE = 0xb1,
	IPC_TO_SENSORHUB_CMD_WAKEUP_START_INFER = 0xb2,

	/* ipc for AInc */
	IPC_TO_SENSORHUB_AI_NC_PROC_CMD = 0xB3,

	/* blow detection */
	IPC_TO_SENSORHUB_FACE_MSG_SUBSCRIPTION_CMD = 0xD0,
	IPC_TO_SENSORHUB_BLOW_DETECTION_RES_CMD = 0xD2,

	IPC_TO_SENSORHUB_AVLPP_START_RESP_CMD,
	IPC_TO_SENSORHUB_AVLPP_STOP_RESP_CMD,
	IPC_TO_SENSORHUB_AVLPP_PLAY_DONE,
	IPC_TO_SENSORHUB_AVLPP_POSITION_RESP_CMD,
	IPC_TO_SENSORHUB_AVLPP_LATENCY_RESP_CMD,
	IPC_TO_SENSORHUB_AVLPP_SPEED_RESP_CMD,
	/* audio_haptic_aod */
	IPC_TO_SENSORHUB_HAPTIC_START_RSP_CMD = 0xE0,
	IPC_TO_SENSORHUB_HAPTIC_REQ_DATA_CMD,
	IPC_TO_SENSORHUB_HAPTIC_PLAY_DONE_CMD,
	
	/* ipc for glass */
	IPC_TO_SENSORHUB_BT_PLAYER_START_RESP_CMD = 0xF0,
	IPC_TO_SENSORHUB_BT_PLAYER_STOP_RESP_CMD,

	/* ipc for glass_ai_chat */
	IPC_TO_SENSORHUB_VOICE_CHAT_START_RESP_CMD = 0xF3,
	IPC_TO_SENSORHUB_VOICE_CHAT_STOP_RESP_CMD,
	IPC_TO_SENSORHUB_VOICE_CHAT_NOTIFY_CMD,

	/* ipc for glass_audio_collect */
	IPC_TO_SENSORHUB_AUDIO_COLLECT_START_RESP_CMD = 0xF6,
	IPC_TO_SENSORHUB_AUDIO_COLLECT_STOP_RESP_CMD,
	IPC_TO_SENSORHUB_AUDIO_COLLECT_NOTIFY_CMD,

	/* ipc for glass_ai_nc */
	IPC_TO_SENSORHUB_VOICE_CHAT_NN_MODEL_PROC_CMD = 0xF9,
	IPC_TO_SENSORHUB_VOICE_CALL_NN_MODEL_PROC_CMD,

	IPC_TO_SENSORHUB_WAKEUP_RESULT_RESPONSE = 0xFB,

	/* ipc for glass state sync */
	IPC_TO_SENSORHUB_AUDIO_STATE_SYNC_RESPONSE = 0xFC,

	IPC_TO_SENSORHUB_WAKEUP_KWS1_SUCCESS = 0xFD,
};

enum sensor_hub2hifi_msg {
	AO_IPC_LIGHT_MSG_TYPE = 0,
	AO_IPC_SEND_TO_SENSERHUB_ULTRA_STATUS_TYPE,

	/* add for ultra mtp */
	AP_IPC_START_MTP,
	AP_IPC_UPDATE_MTP_CALIB_VAL,
	AP_IPC_SEND_MTP_STATUS,
	IPC_FROM_SENOSRHUB_CMD_PS_STATE_PNR = 5,
	IPC_FROM_SENSORHUB_CMD_SCENE_DENOISE_GET_ADDR = 0x60,
	IPC_FROM_SENSORHUB_CMD_SCENE_DENOISE_GET_PARAM = 0x64,
	IPC_FROM_SENSORHUB_CMD_SCENE_DENOISE_BUFFER_READY = 0x66,

	/* aod play */
	IPC_FROM_SENSORHUB_CMD_AOD_SET_DEVICE = 0x70,
	IPC_FROM_SENSORHUB_CMD_AOD_START = 0x71,
	IPC_FROM_SENSORHUB_CMD_AOD_SET_DATA = 0x74,
	IPC_FROM_SENSORHUB_CMD_AOD_STOP = 0x76,

	IPC_FROM_SENSORHUB_CMD_SED_GET_ADDR = 0x80,
	IPC_FROM_SENSORHUB_CMD_SED_GET_PARAM = 0x84,
	IPC_FROM_SENSORHUB_CMD_SED_BUFFER_READY = 0x86,
	/* TAG_ORIENTATION */
    IPC_FROM_SENSORHUB_ORIENTATION_CMD = 0x89,
	/* TAG motion */
	MOTION_TO_HIFI_CMD = 0x90,
	/* TAG_PS */
    IPC_FROM_SENSORHUB_PS_CMD = 0x91,
	/* ipc for ath_watch gt mode */
	IPC_FROM_SENSORHUB_LOCAL_PLAYER_START_CMD = 0x92,
	IPC_FROM_SENSORHUB_LOCAL_PLAYER_STOP_CMD,
	IPC_FROM_SENSORHUB_LOCAL_PLAYER_UPDATE_DATA_CMD,
	IPC_FROM_SENSORHUB_LOCAL_PLAYER_GET_POSITION_CMD,
	IPC_FROM_SENSORHUB_LOCAL_RECORDER_START_CMD,
	IPC_FROM_SENSORHUB_LOCAL_RECORDER_STOP_CMD,
	IPC_FROM_SENSORHUB_LOCAL_RECORDER_DONE_CMD,
	IPC_FROM_SENSORHUB_LOCAL_NOTIFICATION_START_CMD,
	IPC_FROM_SENSORHUB_LOCAL_NOTIFICATION_STOP_CMD,
	IPC_FROM_SENSORHUB_LOCAL_NOTIFICATION_UPDATE_DATA_CMD,
	IPC_FROM_SENSORHUB_AUDIO_SET_VOL_CMD,
	IPC_FROM_SENSORHUB_AUDIO_SET_DEVICE_CMD,
	IPC_FROM_SENSORHUB_AUDIO_SET_SOURCE_CMD,
	IPC_FROM_SENSORHUB_SET_EFFECT_PARAM_CMD,
	IPC_FROM_SENSORHUB_GET_EFFECT_PARAM_CMD,
	IPC_FROM_SENSORHUB_ULTRASONIC_MISTOUCH_OPEN_CMD,
	IPC_FROM_SENSORHUB_ULTRASONIC_MISTOUCH_CLOSE_CMD,
	IPC_FROM_SENSORHUB_HOOK_PCM_START_CMD,
	IPC_FROM_SENSORHUB_HOOK_PCM_STOP_CMD,
	IPC_FROM_SENSORHUB_BT_ENCODER_INFO_CMD,
	IPC_FROM_SENSORHUB_BT_SLAVE_VOICE_START_CMD,
	IPC_FROM_SENSORHUB_BT_SLAVE_VOICE_STOP_CMD,
	IPC_FROM_SENSORHUB_NOTIFY_GID_PARAM_CMD,
	IPC_FROM_SENSORHUB_SET_INPUT_MUTE_CMD,
	/* ipc for ath_watch wakeup */
	IPC_FROM_SENSORHUB_WAKEUP_START_CMD,
	IPC_FROM_SENSORHUB_WAKEUP_STOP_CMD,

	/* ipc for ath_glass wakeup */
	IPC_FROM_SENSORHUB_WAKEUP_SWITCH_ON_CMD,
	IPC_FROM_SENSORHUB_WAKEUP_SWITCH_OFF_CMD,
	IPC_FROM_SENSORHUB_WAKEUP_MODEL_SET_CMD,
	IPC_FROM_SENSORHUB_WAKEUP_END_INFER_GLASS_CMD,
	IPC_FROM_SENSORHUB_WAKEUP_STOP_STREAM_CMD,
	IPC_FROM_SENSORHUB_WAKEUP_NOTIFY_ONESHOT_RESULT_CMD,
	IPC_FROM_SENSORHUB_WAKEUP_OPEN_3MIC_PATH_RESP_CMD, /* 0xB2 */

	IPC_FROM_SENSORHUB_CMD_WAKEUP_END_INFER = 0xb3,
	IPC_FROM_SENSORHUB_CMD_WAKEUP_GET_ADDR = 0xb4,

	/* ipc for AInc */
	IPC_FROM_SENSORHUB_SET_AI_NC_MODEL_STATUS_CMD = 0xB5,
	IPC_FROM_SENSORHUB_SET_AI_NC_PROC_RESULT_CMD = 0xB6,

	/* ipc for ultrasonic_proximity */
	IPC_FROM_SENSORHUB_ULTRASONIC_PROXIMITY_OPEN_CMD = 0xC0,
	IPC_FROM_SENSORHUB_ULTRASONIC_PROXIMITY_CLOSE_CMD,

	/* blow detection */
	IPC_FROM_SENSORHUB_FACE_POS_CMD = 0xD1,
	IPC_FROM_SENSORHUB_BLOW_SUBSCRIPTION_CMD = 0xD3,

	IPC_FROM_SENSORHUB_AVLPP_START_CMD,
	IPC_FROM_SENSORHUB_AVLPP_UPDATE_DATA_CMD,
	IPC_FROM_SENSORHUB_AVLPP_STOP_CMD,
	IPC_FROM_SENSORHUB_AVLPP_GET_POSITION_CMD,
	IPC_FROM_SENSORHUB_AVLPP_GET_LATENCY_CMD,
	IPC_FROM_SENSORHUB_AVLPP_CHANGE_SPEED_CMD,

    /* audio_haptic_aod */
    IPC_FROM_SENSORHUB_HAPTIC_START_CMD = 0xE0,
    IPC_FROM_SENSORHUB_HAPTIC_STOP_CMD,
    IPC_FROM_SENSORHUB_HAPTIC_UPDATE_SHARE_BUF_CMD,
    IPC_FROM_SENSORHUB_HAPTIC_SET_PARAMS_CMD,

    /* ipc for glass */
    IPC_FROM_SENSORHUB_BT_PLAYER_START_CMD = 0xF0,
    IPC_FROM_SENSORHUB_BT_PLAYER_STOP_CMD,
    IPC_FROM_SENSORHUB_BT_PLAYER_RECEIVE_ADUIO_DATA_CMD,

	/* ipc for glass ai chat */
	IPC_FROM_SENSORHUB_VOICE_CHAT_START_CMD = 0xF3,
	IPC_FROM_SENSORHUB_VOICE_CHAT_STOP_CMD,
	IPC_FROM_SENSORHUB_VOICE_CHAT_DONE_CMD,

	/* ipc for glass_ai_nc */
	IPC_FROM_SENSORHUB_VOICE_CHAT_NN_MODEL_PROC_REPLY_CMD = 0xF6,
	IPC_FROM_SENSORHUB_VOICE_CALL_NN_MODEL_PROC_REPLY_CMD,
};

enum ultrasonic_hifi_ctrl_msg {
	/* add for ultra proximity */
	IPC_TO_SENSORHUB_ULTRA_DATA_FLG = 0,
	IPC_TO_SENSORHUB_ULTRA_OPEN_FLG,
	IPC_TO_SENSORHUB_ULTRA_CLOSE_FLG,
	IPC_TO_SENSORHUB_ULTRA_CLOSE_LIGHT,
	IPC_TO_SENSORHUB_FLG_IDX,

	/* add for ultra mtp */
	IPC_TO_SENSORHUB_MTP_DATA = 0x20,
	IPC_TO_SENSORHUB_MTP_OPEN,
	IPC_TO_SENSORHUB_MTP_CLOSE,

	IPC_TO_SENSORHUB_MTP_ANALOG_OPEN,
	IPC_TO_SENSORHUB_MTP_ANALOG_CLOSE,
	IPC_TO_SENSORHUB_MTP_START_FAIL,
	IPC_TO_SENSORHUB_MTP_UPDATE_CALIB_VAL_FAIL,
	IPC_TO_SENSORHUB_MTP_NOTHING_FLG,

	/* add for ultrasonic mistouch */
	IPC_TO_SENSORHUB_ULTRASONIC_MISTOUCH_OPEN = 0x30,
	IPC_TO_SENSORHUB_ULTRASONIC_MISTOUCH_CLOSE,
	IPC_TO_SENSORHUB_ULTRASONIC_MISTOUCH_SEND_ALGO_DATA,
	IPC_TO_SENSORHUB_ULTRASONIC_MISTOUCH_CLOSE_FUSION,

	/* aod play */
	IPC_TO_SENSORHUB_CMD_AOD_START_CNF = 0x72,
	IPC_TO_SENSORHUB_CMD_AOD_NOTIFY_UPDATE_DATA = 0x73,
	IPC_TO_SENSORHUB_CMD_AOD_PLAY_DONE = 0x75,
	IPC_TO_SENSORHUB_CMD_AOD_STOP_CNF = 0x77,
};

enum hifi_glasses_wakeup_response {
	GLASSES_SWITCH_ON_SUCC = 0,
	GLASSES_SWITCH_ON_FAIL = 1,
	GLASSES_STOP_SUCC = 2,
	GLASSES_STOP_FAIL = 3,
};

/* msg header */
struct ao_ipc_msg_header {
	uint8_t tag;
	uint8_t cmd;
	uint8_t resp : 1;
	uint8_t rsv : 3;
	uint8_t core : 4;
	uint8_t partial_order;
	uint16_t tranid;
	uint16_t length; /* size of ao ipc para */
};

/* ultrasonic msg body */
struct ps_sound_para_t {
	uint32_t sh_ctrl;
	uint32_t hifi_ctrl;
	uint32_t sound_data_0_3;
	uint32_t sound_data_4_7;
	uint32_t sound_data_8_11;
	uint32_t sound_data_12_15;
};

/* ultrasonic msg */
struct pkt_ps_sound_req_t {
	struct ao_ipc_msg_header hd;
	struct ps_sound_para_t para;
};

/* scene_denoise msg body */
struct audio_scene_denoise_ao_ipc_param {
	uint32_t batch_num;
	uint32_t size;
};

/* scene_denoise msg */
struct audio_scene_denoise_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	struct audio_scene_denoise_ao_ipc_param para;
};

/* sound event detect msg body */
struct sound_event_detect_ao_ipc_param {
	uint32_t batch_num;
	uint32_t size;
};

/* sound event detect msg */
struct sound_event_detect_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	struct sound_event_detect_ao_ipc_param para;
};

/* ---local player--- */
struct update_share_buf {
    uint32_t buffer_addr;
    uint32_t buffer_size;
    uint8_t last_block;
    uint8_t reserved[3];
};

enum {
    IPC_AUDIO_CODECTYPE_SBC,
    IPC_AUDIO_CODECTYPE_AAC,
    IPC_AUDIO_CODECTYPE_MP3,
    IPC_AUDIO_CODECTYPE_MSBC,
    IPC_AUDIO_CODECTYPE_CVSD,
    IPC_AUDIO_CODECTYPE_PCM,
    IPC_AUDIO_CODECTYPE_WAV,
    IPC_AUDIO_CODECTYPE_WAV_FLOAT,
    IPC_AUDIO_CODECTYPE_ALAC,
    IPC_AUDIO_CODECTYPE_FLAC,
    IPC_AUDIO_CODECTYPE_OPUS,
    IPC_AUDIO_CODECTYPE_SILK,
    IPC_AUDIO_CODECTYPE_BUTT,
};

enum {
    RESULT_SUCCESS = 0,
    RESULT_FAIL,
    RESULT_BUTT,
};

enum {
    IPC_STOP_NOW,
    IPC_STOP_DELAY,
    IPC_STOP_BUTT,
};

typedef struct {
    uint32_t 						format;
    uint16_t 						bitdepth;
    uint16_t 						channel_num;
    uint16_t 						volume;
    uint16_t 						is_volume_alg_bypass; /* 0:need volume alg, 1:bypass volume alg */
    uint32_t 						sample_rate_in;
    uint32_t 						sample_rate_out;
    uint32_t 						total_size;
    uint32_t 						start_pos; /* Actual audio stream played time */
    uint32_t 						actual_time; /* Actual audio stream header time */
    struct update_share_buf 		update_buffer;
    uint32_t 						extra_size;  /* hiby Decoder private data size */
    uint8_t 						extra_data[0]; /* hiby Decoder private data */
} mcu_hifi_local_player_start_t;

typedef struct {
    uint16_t delay;
	uint16_t reserve;
} mcu_hifi_local_player_stop_t;

typedef struct {
    struct update_share_buf update_buf;
} mcu_hifi_local_player_update_buf_t;

typedef struct {
    uint32_t result;
    uint32_t played_size;
} hifi_mcu_local_player_stop_response_t;

typedef struct {
    uint32_t codetype;
    uint16_t bitdepth;
    uint16_t channel_num;
    uint16_t volume;
    uint16_t downmixerMode;
    uint32_t sample_rate_in;
    uint32_t sample_rate_out;
	uint32_t svm_flag;
} mcu_hifi_bt_player_start_t;

typedef struct {
	uint32_t svm_flag;
    uint16_t delay;
	uint16_t reserve;
} mcu_hifi_bt_player_stop_t;

typedef struct {
    uint32_t buffer_addr;
    uint32_t buffer_size;
    uint8_t cmd_id;
    uint8_t audio_scene; /* a2dp scene music:0, game:1, other:2 */
    uint16_t audio_delay; /* audio overflow or underflow buffer */
} mcu_hifi_bt_dsp_data_t;

enum {
    LOCAL_PLAYER_DONE_NORMAL = 0,
    LOCAL_PLAYER_DONE_COMPLETE,
    LOCAL_PLAYER_DONE_ABNORMAL,
    LOCAL_PLAYER_USER_STOP_DELAY,
    LOCAL_PLAYER_USER_STOP_NOW,
    LOCAL_PLAYER_DONE_BUTT
};

enum {
    AVLPP_DONE_NORMAL = 0,
    AVLPP_DONE_COMPLETE,
    AVLPP_DONE_ABNORMAL,
    AVLPP_USER_STOP_DELAY,
    AVLPP_USER_STOP_NOW,
    AVLPP_DONE_BUTT
};

typedef struct {
    uint32_t play_done;
} hifi_mcu_local_player_done_indication_t;

typedef struct {
    uint32_t played_size;
} hifi_mcu_local_player_progess_response_t;

/* ---local record--- */
typedef struct {
    uint16_t channel_num;
	uint16_t reserve;
    uint32_t bitdepth;
    uint32_t sample_rate;
    uint32_t codec_type;
} mcu_hifi_record_start_t;

typedef struct {
	uint16_t        record_done;
	uint16_t        reserve;
} mcu_hifi_record_data_done_t;

typedef struct {
    uint32_t result;
} hifi_mcu_comm_response_t;

typedef struct {
	uint32_t record_done;
	uint32_t len;
} hifi_mcu_record_notify_t;

typedef struct {
    uint16_t channel_num;
	uint16_t reserve;
    uint32_t bitdepth;
    uint32_t sample_rate;
    uint32_t codec_type;
} mcu_hifi_voice_chat_start_t;

typedef struct {
	uint16_t        chat_done;
	uint16_t        reserve;
} mcu_hifi_voice_chat_data_done_t;

typedef struct {
    uint32_t result;
} hifi_mcu_chat_response_t;

typedef struct {
	uint32_t chat_done;
	uint32_t len;
} hifi_mcu_chat_notify_t;

typedef struct {
    uint32_t result;
} hifi_mcu_collect_response_t;

typedef struct {
	uint32_t collect_done;
	uint32_t len;
} hifi_mcu_collect_notify_t;

typedef struct {
    uint16_t result;
    uint16_t reserve;
} mcu_hifi_voice_ai_nc_reply_t;

/* --hook data and save hifi log-- */
typedef struct {
	uint32_t mode;
} hifi_mcu_save_param_t;

typedef struct {
    uint32_t point;
    uint32_t data_addr;
    uint32_t data_length;
} hifi_mcu_hook_data_param_t;

typedef struct {
    uint32_t point;
    uint32_t data_addr;
    uint32_t data_length;
} mcu_hifi_hook_data_param_t;

/* ---notification--- */
typedef struct {
    uint32_t 						codec_type;
    uint16_t 						bitdepth;
    uint16_t 						channel_num;
    uint16_t 						volume;
    uint16_t 						mute_delay_cnt; /* mute delay cnt */
    uint32_t 						sample_rate;
    uint32_t 						total_size;
} mcu_hifi_notification_start_t;

typedef struct {
    uint16_t len; // length of data
    uint16_t is_last; // 1 if is last frame, else is not last frame
} mcu_hifi_notification_send_data_t;

typedef struct {
    uint16_t    delay;
    uint16_t    reserve;
} mcu_hifi_notification_stop_t;

enum {
    NOTIFICATION_PLAY_COMPLETE = 0,
    NOTIFICATION_PLAY_ABNORMAL,
    NOTIFICATION_USER_STOP,
    NOTIFICATION_BUTT
};

typedef struct {
    uint32_t result;
} hifi_mcu_notification_stop_t;

typedef struct {
    uint32_t len; // length of data
} hifi_mcu_notification_req_data_t;

/* ---dynamic changes--- */
typedef struct {
    uint16_t vol_type;
	uint16_t reserve;
    uint32_t volume; /* 音量值 */
    uint32_t volume_step; /* 音量阶数 */
} mcu_hifi_set_volume_t;

enum {
    DEVICE_PA = 0x2,
	DEVICE_BLUETOOTH_SCO = 0x10,
	DEVICE_BLUETOOTH_SCO_AND_PA = 0x12,
    DEVICE_BT = 0x80,
};

typedef struct {
    uint32_t value;
} mcu_hifi_set_device_source_t;

enum {
    SOURCE_MIC = 1,
    SOURCE_BT = 40000,
};

typedef struct {
    uint32_t io_sample_rate;
    uint32_t is_bt_slave_voice; /* 0: bt_master, 1: bt_slave */
#ifdef GLASSES_SUPPORT
	uint32_t is_svm_scene; /* 0: normal, 1: svm_scene */
#endif 
} mcu_hifi_io_sample_rate_t;

typedef struct {
    uint16_t is_mute;
    uint16_t reserve;
    uint32_t stream_direction;
    uint32_t is_bt_slave_voice;
} mcu_hifi_set_stream_mute_t;

enum {
    USE_IPC,
    USE_SHAREMEM,
    TRANS_TYPE_BUTT
};  /* trans type */

typedef struct {
    uint32_t trans_type;
    uint16_t effect_id;
    uint16_t len;
    uint8_t param[0];
} mcu_hifi_effect_param_t;

typedef struct {
    uint16_t effect_id;
    uint16_t len;
    uint8_t param[0];
} hifi_mcu_effect_param_t;

typedef struct {
	uint32_t sample_rate;
	uint8_t channel_mode;
	uint8_t block_num;
	uint8_t subband_num;
	uint8_t alloc_method;
	uint8_t bit_pool;
	uint8_t reserve;
 } mcu_hifi_sbc_encode_config;

typedef struct {
	uint32_t sample_rate;
	uint32_t bit_rate;
	uint8_t channel;
	uint8_t vbr;
 } mcu_hifi_aac_encode_config;

typedef struct {
	uint16_t codec_type;
	union {
		mcu_hifi_sbc_encode_config sbc_config;
		mcu_hifi_aac_encode_config aac_config;
	};
} mcu_hifi_bt_encoder_info_param_t;

typedef struct {
    uint32_t module_id;
} mcu_hifi_wakeup_start_t;

typedef struct {
    uint32_t module_id;
} mcu_hifi_wakeup_stop_t;

typedef struct {
    uint32_t model_id;
    uint32_t model_size; 
} mcu_hifi_wakeup_model_set_t;

typedef struct {
    uint32_t reserve;
} mcu_hifi_wakeup_common_t;

typedef struct {
    uint32_t size;
    uint32_t reserve;
} mcu_hifi_wakeup_data_t;

typedef struct {
    uint32_t result;
} mcu_hifi_common_response_t;

typedef struct {
    uint32_t result;
} mcu_hifi_common_result_t;

typedef struct {
    uint16_t face_msg_subscribed;  // 0:unsubstribe; 1:subscribe
	uint16_t reserve;
} face_msg_subscription_param_t;

typedef struct {
	uint16_t face_x_coord_min;  // 0 ~ 480
	uint16_t face_x_coord_max;  // 0 ~ 480
	uint16_t face_y_coord_min;  // 0 ~ 640
	uint16_t face_y_coord_max;  // 0 ~ 640
	uint32_t time_stamp;  // time stamp when face positon recorded
} blow_detection_face_pos_t;

typedef struct {
    uint16_t blow_res_subscribed;  // 0:unsubstribe; 1:subscribe
	uint16_t reserve;
} blow_res_subscription_param_t;

typedef struct {
	uint16_t sound_intensity;  // 0 ~ 12; 0: no blow detected
	uint16_t sound_direction; // 0: no blow; 1: near bottom mic; 2: middle; 3: near top mic
	uint16_t face_x_coord_min;  // 0 ~ 480; (0,0,0,0) - invalid
	uint16_t face_x_coord_max;  // 0 ~ 480;
	uint16_t face_y_coord_min;  // 0 ~ 640;
	uint16_t face_y_coord_max;  // 0 ~ 640;
	uint32_t time_stamp_face_msg;  // time stamp when face positon recorded
	uint32_t time_stamp_blow_res;  // time stamp of blow detection result
} blow_detection_res_param_t;

typedef struct {
    uint16_t event_type;
    uint16_t event_param_len;  // max len 64
    uint8_t event_param[0];
} hifi_mcu_state_sync_response_t;

struct local_player_start_response_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_comm_response_t para;
};

struct local_player_stop_response_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_local_player_stop_response_t para;
};

struct local_player_done_indication_response_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_local_player_done_indication_t para;
};

struct local_player_progess_response_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_local_player_progess_response_t para;
};

struct bt_player_start_response_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_comm_response_t para;
};

struct bt_player_stop_response_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_comm_response_t para;
};

struct record_start_response_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_comm_response_t para;
};

struct record_stop_response_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_comm_response_t para;
};

struct record_notifty_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_record_notify_t para;
};

struct chat_start_response_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_chat_response_t para;
};

struct chat_stop_response_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_chat_response_t para;
};

struct chat_notifty_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_chat_notify_t para;
};

struct collect_start_response_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_collect_response_t para;
};

struct collect_stop_response_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_collect_response_t para;
};

struct collect_notifty_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_collect_notify_t para;
};

struct ai_nc_proc_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
};

struct notification_stop_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_notification_stop_t para;
};

struct notification_response_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_comm_response_t para;
};

struct notification_req_data_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_notification_req_data_t para;
};

struct get_param_response_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_effect_param_t para;
};

struct bt_slave_voice_response_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_comm_response_t para;
};

struct a2dp_offload_data_param {
	uint16_t count;
	uint16_t size;
};

struct a2dp_offload_data_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	struct a2dp_offload_data_param para;
};

struct notification_save_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_save_param_t para;
};

struct hook_pcm_save_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_hook_data_param_t para;
};

typedef struct {
    uint32_t value;
} mcu_hifi_set_syscache_param_t;

struct wakeup_start_recv_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_comm_response_t para;
};

struct wakeup_stop_recv_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	hifi_mcu_comm_response_t para;
};

struct audio_state_sync_response_ao_ipc_pkt {
    struct ao_ipc_msg_header hd;
    hifi_mcu_state_sync_response_t para;
};

typedef struct {
    uint32_t reserve;
} hifi_mcu_wakeup_common_t;

typedef struct {
	uint32_t result;
} hifi_glasses_wakeup_result;

typedef struct {
    struct ao_ipc_msg_header hd;
    hifi_mcu_wakeup_common_t para;
} hifi_mcu_wakeup_path_t;

typedef struct {
	struct ao_ipc_msg_header hd;
    hifi_glasses_wakeup_result para;
} hifi_glass_wakeup_status_response_t;

typedef struct {
    uint32_t module_id;
    uint32_t wakeup_frame_position;
	uint32_t voice_energy;
} hifi_mcu_wakeup_trigger_t;

typedef struct {
    struct ao_ipc_msg_header hd;
    hifi_mcu_wakeup_trigger_t para;
} hifi_mcu_wakeup_trigger_event_t;

typedef struct {
    uint32_t size;
    uint32_t reserve;
} hifi_mcu_wakeup_data_t;

typedef struct {
    struct ao_ipc_msg_header hd;
    hifi_mcu_wakeup_data_t para;
} hifi_mcu_wakeup_data_send_t;

typedef struct {
	uint16_t noise_level;
	int16_t nfl_result;
	uint16_t volume;
	uint16_t voice_type;
} mcu_hifi_voice_slvm_info_t;

struct notify_voice_slvm_info_pkg
{
	struct ao_ipc_msg_header hd;
	mcu_hifi_voice_slvm_info_t para;
};

struct notify_ai_nc_proc_pkg
{
	struct ao_ipc_msg_header hd;
};

struct face_msg_subscription_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	face_msg_subscription_param_t para;
};

struct blow_detection_res_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	blow_detection_res_param_t para;
};

struct wakeup_set_module_recv_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	mcu_hifi_wakeup_model_set_t para;
};

struct sensorhub2hifi_avlpp_start_msg {
    uint8_t bitdepth;
    uint8_t channel_num;
    uint8_t last_block;
    uint8_t resv;
    uint32_t sample_rate;
    uint32_t buffer_addr;
    uint32_t data_size;
};

struct sensorhub2hifi_avlpp_update_msg {
    uint32_t buffer_addr;
    uint32_t data_size;
    uint8_t last_block;
    uint8_t resv[3];
};

struct sensorhub2hifi_avlpp_stop_msg {
    uint16_t delay; // IPC_AVLPP_STOP_NOW: no fade out, IPC_AVLPP_STOP_DELAY: need fade out
    uint16_t resv;
};

enum avlpp_speed_type {
    AVLPP_SPEED_0_25,
    AVLPP_SPEED_0_5,
    AVLPP_SPEED_0_75,
    AVLPP_SPEED_1_0,
    AVLPP_SPEED_1_5,
    AVLPP_SPEED_2_0,
    AVLPP_SPEED_3_0,
    AVLPP_SPEED_MAX,
};

enum avlpp_stop_type {
    IPC_AVLPP_STOP_NOW,
    IPC_AVLPP_STOP_DELAY,
};

struct sensorhub2hifi_avlpp_speed_msg {
    uint8_t speed_type;
    uint8_t resv[3];
};

struct avlpp_start_response_para {
    uint32_t result; // 0 success, 1 fail
};

struct hifi2sensorhub_avlpp_start_response {
    struct ao_ipc_msg_header hd;
    struct avlpp_start_response_para para;
};

struct avlpp_stop_response_para {
    uint32_t result; // 0 success, 1 fail
    uint64_t decoder_consume_size;
};

struct hifi2sensorhub_avlpp_stop_response {
    struct ao_ipc_msg_header hd;
    struct avlpp_stop_response_para para;
};

struct avlpp_speed_response_para {
    uint8_t result; // 0 success, 1 fail
	uint8_t resv[3];
};

struct hifi2sensorhub_avlpp_speed_response {
	struct ao_ipc_msg_header hd;
	struct avlpp_speed_response_para para;
};

struct avlpp_get_position_response_para {
	uint64_t played_size;
	uint64_t decoder_consume_size;
};

struct hifi2sensorhub_avlpp_get_position_response {
	struct ao_ipc_msg_header hd;
	struct avlpp_get_position_response_para para;
};

struct avlpp_get_latency_response_para {
	uint32_t latency;
};

typedef struct {
	struct ao_ipc_msg_header hd;
	struct avlpp_get_latency_response_para para;
} hifi2sensorhub_avlpp_get_latency_response;

struct avlpp_played_para {
	uint32_t played_status;
	uint32_t buffer_addr;
    uint32_t buffer_size;
} ;

struct hifi2sensorhub_avlpp_update_data_request {
	struct ao_ipc_msg_header hd;
	struct avlpp_played_para para;
};

typedef struct {
    uint32_t data_len;
    int32_t default_haptic0_re;
    bool is_auto_brake;
} audio_haptic_aod_start_req_parm;

typedef struct {
    int32_t result;
} audio_haptic_aod_start_rsp_para;

struct audio_haptic_aod_start_rsp_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
	audio_haptic_aod_start_rsp_para para;
};

typedef struct {
    uint32_t data_len;
} audio_haptic_aod_update_share_buf_para;

struct non_para_ao_ipc_pkt {
	struct ao_ipc_msg_header hd;
};

typedef struct {
    uint32_t pa_version;
} audio_haptic_aod_set_params_para;

typedef struct {
    uint32_t new_haptic0_re;
} audio_haptic_aod_play_done_para;

typedef struct {
	struct ao_ipc_msg_header hd;
	audio_haptic_aod_play_done_para para;
} audio_haptic_aod_play_done_ao_ipc_pkt;

struct audio_aod_start_msg {
    uint32_t sample_rate; // 48K
    uint32_t channel_mask; // 2 channel interlace(LRLRLRLR)
    uint32_t format; // 32bit
    uint32_t len; // first data
    uint32_t total_len;
};

struct audio_aod_set_data {
    uint32_t len;
};

struct audio_aod_set_device_msg {
    uint32_t device;
};

typedef struct {
    uint32_t module_id;
} mcu_hifi_wakeup_close_t;

typedef struct {
    uint32_t size;
} mcu_hifi_data_infer_reseult_t;

typedef struct {
	uint32_t intent_type;
	uint32_t op_type;
	uint32_t data_head;
	uint32_t data_length;
} hifi_mcu_wakeup_intent_data_t;
 
typedef struct {
	struct ao_ipc_msg_header hd;
	hifi_mcu_wakeup_intent_data_t para;
} hifi_mcu_wakeup_intent_data_send_t;

typedef struct {
	struct ao_ipc_msg_header hd;
	hifi_mcu_wakeup_common_t para;
} hifi_mcu_wakeup_kws1_success_t;

#endif
