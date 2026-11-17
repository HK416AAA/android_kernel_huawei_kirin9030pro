/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 * Description: lpp channel source file
 * Author: DIVS_SENSORHUB
 * Create: 2024-08-14
 */

#ifndef __LPP_CHANNEL_H__
#define __LPP_CHANNEL_H__

#include <linux/types.h>
#include <platform_include/smart/linux/iomcu_config.h>
#include <platform_include/smart/linux/base/ap/protocol.h>

#define MAX_LPP_INSTANCE_NUM          (3)
#define MAX_LPP_SOURCE_NUM            (8)
#define MAX_VDEC_OUTPUT_BUFF_NUM      (30)
#define VDEC_IOVA_NUM                 (3)
#define MAX_SOURCE_URL_LENGTH         (8 * 1024)
#define MAX_LPP_IPC_DATA_LENGTH       (1500)
#define MAX_LPP_UPLOAD_MSG_LENGTH     (128)
#define MAX_PKG_HDI_LEN               (1500)

enum lpp_cmd_list {
	LPP_CMD_OPEN,
	LPP_CMD_CLOSE,
	LPP_CMD_CONFIG,
	LPP_CMD_UPLOAD,  // sensorhub -> ap
	LPP_CMD_RELEASE_BUFF,
	LPP_CMD_FLUSH_DONE,
	LPP_CMD_ACK,
};

enum lpp_app_type_t {
	APP_START = 0,
	APP_DEMUX,
	APP_DECODE,
	APP_DISPLAY,
	APP_MAX,
};

enum cma_buffer_num {
	LPP_VDEC_TO_MCU_RING_BUFF = 0,
	LPP_MCU_TO_VDEC_RING_BUFF = 1,
	LPP_CMA_BUFFER_MAX,
};

enum lpp_upload_event_type {
    ON_ERROR_EVENT = 1,
    ON_TARGET_ARRIVED = 2,
    ON_RENDER_STARTED = 3,
    ON_EOS = 4,
    ON_INFO = 5,
	ON_FIRST_FRAME_READY = 6,
	ON_PAUSED_FRAME = 7,
	ON_RELEASE = 8,
	BUFFER_DONE = 9,
    EVENT_TYPE_MAX = 10,
};

enum lpp_state {
    LPP_IDLE = 0,
    LPP_INITIALIZED = 1,
    LPP_PREPARED = 2,
    LPP_PLAYING = 3,
    LPP_PAUSED = 4,
	LPP_STOPPED = 5,
	LPP_TYPE_MAX = 6,
};

enum lpp_error_code {
    SHB_THREAD_CREATE_FAIL = 0x01FF01,
    SHB_MUTEX_INIT_FAIL = 0x01FF02,
    SHB_TIMER_INIT_FAIL = 0x01FF03,
    SHB_MSG_QUEUE_CREATE_FAIL = 0x01FF04,
    SHB_MEM_ALLOC_FAIL = 0x01FF05,
    SHB_DACC_INIT_FAIL = 0x01FF06,
    SHB_RS_RINGBUFF_INIT_FAIL = 0x01FF07,
    SHB_RS_UPLOAD_DATA_FAIL = 0x01FF08,
    SHB_VDEC_RINGBUFF_INIT_FAIL = 0x01FF09,
    SHB_SID_INVALID_ERR = 0x01FF0A,
    SHB_INVALID_BUFF_CNT = 0x01FF0B,
    LPPDRV_MMAP_FAIL = 0x02FF01,
    LPPDRV_SHB_CRASH = 0x02FF02,
    LPPDRV_INSTANCE_EXCEED_LIMIT = 0x02FF03,
	LPPDRV_FLUSH_TIMEOUT = 0X02FF04,
    DSS_RESORCE_PROBE_FAIL = 0x03FF01,
    DSS_AO_LOCK_FAIL = 0x03FF02,
    DSS_CHECK_VOTE_FAIL = 0x03FF03,
    DSS_START_VSYNC_FAIL = 0x03FF04,
    DSS_FSM_STATE_FAIL = 0x03FF05,
    SHB_TIME_ANCHOR_GIANT_GAP = 0x010001,
    SHB_SET_SPEED_ERR = 0x010002,
    SHB_OUTPUT_BUFF_FOUND_ERR = 0x010003,
    LPPDRV_STATE_MACH_ERR = 0x020001,
};

typedef struct {
	struct pkt_header hd;
	unsigned int subcmd;
	unsigned char para[MAX_LPP_IPC_DATA_LENGTH];
} __packed pkt_parameter_req_lpp_t;

#pragma pack(8)
typedef struct {
	int32_t instance_id;
	uint32_t package_len; // whole pkg length, not only data
	char data[];
} hdi_ioctl_package;
#pragma pack()

typedef struct {
	uint32_t lpp_ioctl_app_cmd;
	enum obj_sub_cmd cmd;
} lpp_ioctl_cmd_map;

typedef struct {
	enum lpp_state state;
	enum obj_sub_cmd cmd;
} lpp_state_cmd_map;

typedef struct {
	uint32_t phy_buffer_size;
	uint32_t phy_buffer_addr;
} lpp_cma_buffer_phy_t;

typedef struct {
	uint32_t vdec_iova_size;
	uint32_t vdec_iova_addr;
} lpp_vdec_iova_t;

typedef struct {
	uint32_t fd;
	uint32_t sequence_id;
	uint32_t buffer_id;
} vdec_yuv_buffer_hal_t;

typedef struct {
	uint32_t fd;
	uint32_t sequence_id;
	uint32_t buffer_id;
	uint64_t iova_addr;
} vdec_yuv_buffer_t;

typedef struct {
	vdec_yuv_buffer_hal_t yuv_buffer_list[MAX_VDEC_OUTPUT_BUFF_NUM];
	uint32_t buf_count;
} lpp_vdec_output_buffer_hal;

typedef struct {
	vdec_yuv_buffer_t yuv_buffer_list[MAX_VDEC_OUTPUT_BUFF_NUM];
	uint32_t buf_count;
} lpp_vdec_output_buffer_to_sensorhub;

typedef struct {
	uint32_t fd;
	uint32_t sequence_id;
	uint64_t iova_addr;
	struct dma_buf *buf;
} lpp_dma_buf_fd_t;

typedef struct {
	lpp_dma_buf_fd_t lpp_dma_buf_fd;
	struct list_head entry;
} lpp_output_buffer_node;

typedef struct {
	int64_t anchor_pts;
	uint64_t anchor_clk;
} lpp_time_anchor;

typedef struct {
	int64_t target_pts;
	uint32_t timeout_ms;
} lpp_seek_target_info;

typedef struct {
	int32_t instance_num;
	struct dma_buf *buf;
	uint32_t phy_buffer_size;
	uint32_t phy_buffer_addr;
} lpp_rs_buf_info;

typedef struct {
	int32_t instance_id;
	int32_t channel_id;
	uint32_t stream_id;
	uint64_t tunnel_id;
	uint32_t playback_speed;
	uint32_t seek_seconds;
	int64_t current_pts;
	uint32_t duration_time;
	lpp_rs_buf_info rs_buf_info;
	lpp_vdec_iova_t lpp_vdec_iova[VDEC_IOVA_NUM];
	lpp_cma_buffer_phy_t lpp_buffer_info[LPP_CMA_BUFFER_MAX];
	lpp_vdec_output_buffer_to_sensorhub output_buffer_to_sensorhub;
} lpp_instance_info;

typedef struct  {
	int32_t instance_id;
    enum lpp_upload_event_type event_type;
    int32_t error_code;
    char err_msg[MAX_LPP_UPLOAD_MSG_LENGTH];
    int64_t target_pts;
    bool is_timeout;
    int32_t info_code;
    char info_msg[MAX_LPP_UPLOAD_MSG_LENGTH];
} lpp_upload_pkg;

#define MAX_PROTOCOL_SIZE 16
typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t color_format;
    uint32_t frame_rate;
	uint32_t dpb_size;
	uint32_t bit_depth;
    char code_type[MAX_PROTOCOL_SIZE];
} lpp_video_format_mcu;

typedef struct {
	uint32_t lpp_app_type;
	uint32_t app_len;
	uint32_t lpp_cmd;
	uint32_t cmd_len;
} lpp_mcu_data_head;

typedef struct {
	lpp_mcu_data_head head;
	char value[];
} pkt_lpp_mcu_data_t;

#endif