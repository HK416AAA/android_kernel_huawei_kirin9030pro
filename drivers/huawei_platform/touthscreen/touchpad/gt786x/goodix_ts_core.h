/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef GOODIX_TS_CORE_H
#define GOODIX_TS_CORE_H

#include <securec.h>

#define FIRMWARE_FILE_NAME           "gt7861_firmware.bin"
#define NORMAL_CONFIG_FILE_NAME      "gt7861_normal_cfg.bin"
#define TEST_CONFIG_FILE_NAME        "gt7861_test_cfg.bin"
#define TEST_LIMITS_FILE_NAME        "gt7861_test_limits.csv"

#define TS_RAWDATA_BUFF_MAX     2000
#define TS_RAWDATA_RESULT_MAX   100
#define GOODIX_CFG_MAX_SIZE     4096

#define GT786X_COOR_REG                 0x4100
#define GT786X_CMD_REG                  0x60cc
#define GT786X_CFG_REG                  0x60dc
#define FW_VERSION_SIZE                 4

#define GOODIX_MOVE_16BIT(val)   ((u8)((val) >> 16))
#define GOODIX_MOVE_8BIT(val)    ((u8)((val) >> 8))

#define GOODIX_VAL_H(val)       ((u8)((val) >> 8))
#define GOODIX_VAL_L(val)       ((u8)((val) & 0x00FF))

#define GOODIX_DELAY_10MS       10
#define GOODIX_DELAY_20MS       20
#define GOODIX_DELAY_50MS       50
#define GOODIX_DELAY_100MS      100
#define GOODIX_DELAY_200MS      200

#define TS_CFG_BAG_NUM_INDEX            2
#define TS_CFG_HEADER_SIZE              4

#define GOODIX_CFG_BAG_INDEX_SIZE    1
#define GOODIX_CFG_BAG_LEN_SIZE      1
#define GOODIX_CFG_BAG_CHECKSUM_SIZE 1
#define GOODIX_CFG_BAG_HEADER_SIZE  (GOODIX_CFG_BAG_LEN_SIZE + GOODIX_CFG_BAG_INDEX_SIZE)
#define GOODIX_CFG_BAG_SIZE(data_size)  ((GOODIX_CFG_BAG_HEADER_SIZE) + (data_size) + (GOODIX_CFG_BAG_CHECKSUM_SIZE))

#define INDEX_2 2
#define INDEX_3 3
#define INDEX_4 4
#define INDEX_5 5
#define INDEX_6 6

/*
 * struct goodix_ts_cmd - command package
 * @initialized: whether initialized
 * @cmd_reg: command register
 * @length: command length in bytes
 * @cmds: command data
 */
#pragma pack(4)
struct goodix_ts_cmd {
    u32 initialized;
    u32 cmd_reg;
    u32 length;
    u8 cmds[8];
};
#pragma pack()

enum IC_WORK_MODE {
    IC_WORK_MODE_IIC = 0,
    IC_WORK_MODE_HID = 1
};

struct goodix_ts_config {
    int initialized;
    char name[24];

    unsigned int reg_base;
    unsigned int length;
    unsigned int delay; /* ms */
    unsigned char data[GOODIX_CFG_MAX_SIZE];
};

#define GOODIX_PID_MAX_LEN		8
#define GOODIX_VID_MAX_LEN		8
#define GTX8_CONFIG_HEAD_LEN    4
#define FW_VERSION_VID_OFFSET      9
#define FW_VERSION_CID_OFFSET      17
#define FW_VERSION_SID_OFFSET      21

struct goodix_ts_version {
    u8 pid[GOODIX_PID_MAX_LEN];
    u8 vid[GOODIX_VID_MAX_LEN];
    u8 cid;
    u8 sensor_id;
    u8 config_id;
};

struct goodix_ts_hw_ops {
    int (*reset)(void);
    int (*read)(u32 addr, u8 *data, unsigned int len);
    int (*write)(u32 addr, const u8 *data, unsigned int len);
    int (*read_version)(struct goodix_ts_version *version);
    int (*send_cmd)(struct goodix_ts_cmd *cmd);
    int (*send_config)(struct goodix_ts_config *config);
    int (*read_config)(u8 *config_data, int size);
    int (*hid_mode_switch)(int mode);
};

extern struct goodix_ts_hw_ops gt786x_hw_ops;

const struct firmware *goodix_request_firmware(const char *name);
void goodix_cmd_init(struct goodix_ts_cmd *ts_cmd,
                     u8 cmds, u16 cmd_data, u32 reg_addr);

int goodix_fw_update_proc(void);
void dev_i2c_init(struct i2c_client *client);

#endif
