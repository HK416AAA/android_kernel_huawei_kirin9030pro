/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef GT786X_INSPECT_H
#define GT786X_INSPECT_H

#include "goodix_ts_core.h"

#define SAVE_IN_CSV 1

#define GOODIX_RESULT_SAVE_PATH				"/data/testdata.csv"

#define CSV_TP_TARGET_FW_VERSION            "target_fw_version"
#define CSV_TP_SPECIAL_RAW_MIN				"special_raw_min"
#define CSV_TP_SPECIAL_RAW_MAX				"special_raw_max"
#define CSV_TP_SPECIAL_RAW_DELTA			"special_raw_delta"
#define CSV_TP_SHORT_THRESHOLD				"shortciurt_threshold"
#define CSV_TP_SPECIAL_SELFRAW_MAX			"special_selfraw_max"
#define CSV_TP_SPECIAL_SELFRAW_MIN			"special_selfraw_min"
#define CSV_TP_NOISE_LIMIT					"noise_data_limit"
#define CSV_TP_SELFNOISE_LIMIT				"noise_selfdata_limit"

#define MAX_LINE_LEN                		(1024 * 3 * 7)

#define DIV_S64 div_s64
/* test switch */

#define RAWDATA_UNSTABLE 		1
#define MAX_FRAME_TEST_ROUND	3

#define TOTAL_FRAME_NUM					16
#define GTX8_RETRY_NUM_3				3
#define GTX8_CONFIG_REFRESH_DATA		0x01

#define MAX_STR_LEN						32

#define FLOAT_AMPLIFIER					1000
#define MAX_U16_VALUE					65535

#define STATISTICS_DATA_LEN				32
#define MAX_TEST_ITEMS					10 /* 0P-1P-2P-3P-5P total test items */
#define MAX_SHORT_NUM					15

#define GTP_CAP_TEST                    1
#define GTP_DELTA_TEST                  2
#define GTP_SHORT_TEST                  3
#define GTP_VERSION_TEST                4
#define GTP_CONFIG_TEST                 5

#define GTP_TEST_PASS					1
#define GTP_PANEL_REASON				2
#define SYS_SOFTWARE_REASON				3

/* error code */
#define NO_ERR							0
#define RESULT_ERR						(-1)
#define RAWDATA_SIZE_LIMIT				(-2)

/* GTX8 CMD */
#define GTX8_CMD_NORMAL					0x00
#define GTX8_CMD_RAWDATA				0x01

#define GTP_RAWDATA_ADDR_7861			0x7828

/* short  test */
#define RESISTER_MAGNIFY_TIMES   100
#define SHORT_TO_GND_RESISTER(sig)  (div_s64(5266285, (sig) & (~0x8000)) - 40 * 100)    /* (52662.85/code-40) * 100 */
#define SHORT_TO_VDD_RESISTER(sig, value) (div_s64(36864 * ((value) - 9) * 100, (((sig) & (~0x8000)) * 7)) - 40 * 100)

#define DRV_CHANNEL_FLAG			0x80
#define SHORT_FW_VER_REG			0x4535
#define SHORT_STATUS_REG			0x5095

#define TXRX_THRESHOLD_REG			0x7408
#define GNDVDD_THRESHOLD_REG		0x740A
#define ADC_DUMP_NUM_REG			0x740C
#define SHORT_TESTEND_REG			0x7400

#define DRVxDRV_SHORT_NUM_ADDR		0x7460
#define SENxSEN_SHORT_NUM_ADDR		0x7C1C
#define SENxDRV_SHORT_NUM_ADDR		0x82E4

#define CHN_VDD						0xFF
#define CHN_GND						0x7F
#define GNDAVDD_SHORT_VALUE			16
#define ADC_DUMP_NUM				200

#define SHORT_CAL_SIZE(a)			(4 + (a) * 2 + 2)


#define TEST_RESTLT_REG				0x7401
#define TX_SHORT_NUM				0x7402

#define DIFF_CODE_REG				0x8A92

#define DRV_SELF_CODE_REG			0x8A1C

#define MAX_DRV_NUM					30
#define MAX_SEN_NUM					28

#define MAX_DRV_NUM_7861			30
#define MAX_SEN_NUM_7861			28

#define PRINT_MSG_MAX_LEN  256

/**
 * struct ts_test_params - test parameters
 * drv_num: touch panel tx(driver) number
 * sen_num: touch panel tx(sensor) number
 * max_limits: max limits of rawdata
 * min_limits: min limits of rawdata
 * deviation_limits: channel deviation limits
 * short_threshold: short resistance threshold
 * r_drv_drv_threshold: resistance threshold between drv and drv
 * r_drv_sen_threshold: resistance threshold between drv and sen
 * r_sen_sen_threshold: resistance threshold between sen and sen
 * r_drv_gnd_threshold: resistance threshold between drv and gnd
 * r_sen_gnd_threshold: resistance threshold between sen and gnd
 * avdd_value: avdd voltage value
 */
struct ts_test_params {
    u16 rawdata_addr;
    u16 noisedata_addr;
    u16 self_rawdata_addr;
    u16 self_noisedata_addr;

    u16 basedata_addr;
    u32 max_drv_num;
    u32 max_sen_num;
    u32 drv_num; // Row
    u32 sen_num; // Col
    u8 *drv_map;
    u8 *sen_map;

    u16 max_limits[MAX_DRV_NUM * MAX_SEN_NUM];
    u16 min_limits[MAX_DRV_NUM * MAX_SEN_NUM];
    u16 deviation_limits[MAX_DRV_NUM * MAX_SEN_NUM];
    u8 fw_vid[FW_VERSION_SIZE];
    u32 short_threshold;
    u32 r_drv_drv_threshold;
    u32 r_drv_sen_threshold;
    u32 r_sen_sen_threshold;
    u32 r_drv_gnd_threshold;
    u32 r_sen_gnd_threshold;
    u32 avdd_value;
};

/**
 * struct ts_test_rawdata - rawdata structure
 * data: rawdata buffer
 * size: rawdata size
 */
struct ts_test_rawdata {
    u16 data[MAX_SEN_NUM * MAX_DRV_NUM];
    u32 size;
};

#define SHORT_MSG_SIZE 4
struct ts_short_res {
    u8 short_num;
    u16 short_msg[SHORT_MSG_SIZE * MAX_SHORT_NUM];
};

struct ts_open_res {
    u8 beyond_max_limit_cnt[MAX_DRV_NUM*MAX_SEN_NUM];
    u8 beyond_min_limit_cnt[MAX_DRV_NUM*MAX_SEN_NUM];
    u8 beyond_accord_limit_cnt[MAX_DRV_NUM*MAX_SEN_NUM];
};

/**
 * struct gtx8_ts_test - main data structrue
 * ts: gtx8 touch screen data
 * test_config: test mode config data
 * orig_config: original config data
 * test_param: test parameters
 * rawdata: raw data structure
 * test_result: test result string
 */
struct gtx8_ts_test {
    struct goodix_ts_version fw_ver;
    struct goodix_ts_config test_config; // test config
    struct goodix_ts_config orig_config; // config read from IC
    struct goodix_ts_config normal_config; // normal config

    struct goodix_ts_cmd rawdata_cmd;
    struct goodix_ts_cmd normal_cmd;

    struct ts_test_params test_params;
    struct ts_test_rawdata rawdata;
    struct ts_test_rawdata rawdata_arr[TOTAL_FRAME_NUM];
    struct ts_test_rawdata accord_arr[TOTAL_FRAME_NUM];

    struct ts_open_res open_res;
    struct ts_short_res short_res;

    /* [0][0][0][0][0]..  0 without test; 1 pass, 2 panel failed; 3 software failed */
    char test_result[MAX_TEST_ITEMS];
    char test_info[TS_RAWDATA_RESULT_MAX];
};

int gtx8_do_inspect(void);

#endif