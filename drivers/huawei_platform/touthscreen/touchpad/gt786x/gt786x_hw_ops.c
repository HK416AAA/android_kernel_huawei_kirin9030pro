/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include "hm_os_sys.h"
#include "goodix_ts_core.h"
#include "goodix_ts_log.h"
#include "goodix_ts_utils.h"

#define I2C_MAX_TRANSFER_SIZE           255
#define TS_ADDR_LENGTH                  2

#define TS_WAIT_CFG_READY_RETRY_TIMES   30
#define TS_WAIT_CMD_FREE_RETRY_TIMES    10
#define TS_WAIT_CMD_READY_DELAY_MS      10

#define COMMAND_START_SEND_CFG          0x80
#define COMMAND_END_SEND_CFG            0x83
#define COMMAND_SEND_SMALL_CFG          0x81
#define COMMAND_SEND_CFG_PREPARE_OK     0x82
#define COMMAND_START_READ_CFG          0x86
#define COMMAND_READ_CFG_PREPARE_OK     0x85


#define	TS_CMD_REG_READY                0xFF
#define TS_CMD_CFG_ERR                  0x7E
#define TS_CMD_CFG_OK                   0x7F

enum TS_SEND_CFG_REPLY {
    TS_CFG_REPLY_PKGS_ERR   = 0x01,
    TS_CFG_REPLY_CHKSUM_ERR = 0x02,
    TS_CFG_REPLY_DATA_ERR   = 0x03,
    TS_CFG_REPLY_DATA_EQU   = 0x07,
};

#define CMD_LEN 3
void goodix_cmd_init(struct goodix_ts_cmd *ts_cmd, u8 cmds, u16 cmd_data, u32 reg_addr)
{
    ts_cmd->initialized = VALUE_FALSE;
    if (!reg_addr || !ts_cmd) {
        return;
    }

    ts_cmd->cmd_reg = reg_addr;
    ts_cmd->length = CMD_LEN;
    ts_cmd->cmds[0] = cmds;
    ts_cmd->cmds[1] = cmd_data & 0xFF;
    ts_cmd->cmds[INDEX_2] = 0 - cmds - cmd_data;
    ts_cmd->initialized = VALUE_TRUE;
}

/**
 * goodix_reg_read_trans - read device register through i2c bus
 * @addr: register address
 * @data: read buffer
 * @len: bytes to read
 * return: 0 - read ok, < 0 - i2c transter error
 */
int goodix_reg_read(unsigned int reg, u8 *data, unsigned int len)
{
    unsigned int transfer_length = 0;
    unsigned int pos = 0, address = reg;

    while (pos != len) {
        if (len - pos > I2C_MAX_TRANSFER_SIZE) {
            transfer_length = I2C_MAX_TRANSFER_SIZE;
        } else {
            transfer_length = len - pos;
        }

        if (sys_reg_read(address, &data[pos], transfer_length)) {
            ts_err("Read reg 0x%04x error", address);
            return -EINVAL;
        }
        pos += transfer_length;
        address += transfer_length;
    }
    return 0;
}

/**
 * goodix_reg_write - write device register through i2c bus
 * @addr: register address
 * @data: write buffer
 * @len: bytes to write
 * return: 0 - write ok; < 0 - i2c transter error.
 */
int goodix_reg_write(unsigned int reg, const u8 *data, unsigned int len)
{
    unsigned int transfer_length = 0;
    unsigned int pos = 0, address = reg;

    while (pos != len) {
        if (len - pos > I2C_MAX_TRANSFER_SIZE) {
            transfer_length = I2C_MAX_TRANSFER_SIZE;
        } else {
            transfer_length = len - pos;
        }

        if (sys_reg_write(address, &data[pos], transfer_length)) {
            ts_err("Write reg 0x%04x error\n", address);
            return -EINVAL;
        }
        pos += transfer_length;
        address += transfer_length;
    }

    return 0;
}

/**
 * goodix_send_command - seng cmd to firmware
 *
 * @cmd: pointer to command struct which cotain command data
 * Returns 0 - succeed,<0 - failed
 */
static int goodix_send_command(struct goodix_ts_cmd *cmd)
{
    if (!cmd || !cmd->initialized) {
        return -EINVAL;
    }

    return goodix_reg_write(cmd->cmd_reg, cmd->cmds, cmd->length);
}

static int goodix_wait_cfg_cmd_ready(u8 right_cmd, u8 send_cmd)
{
    int try_times = 0;
    u8 cmd_flag = 0;
    u8 cmd_buf[3] = {0};
    u16 command_reg = GT786X_CMD_REG;
    struct goodix_ts_cmd ts_cmd;

    goodix_cmd_init(&ts_cmd, send_cmd, 0, command_reg);

    for (try_times = 0; try_times < TS_WAIT_CFG_READY_RETRY_TIMES;
         try_times++) {
        if (goodix_reg_read(command_reg, cmd_buf, CMD_LEN)) {
            ts_err("Read cmd_reg error");
            return -EINVAL;
        }
        cmd_flag = cmd_buf[0];
        if (cmd_flag == right_cmd) {
            return 0;
        } else if (cmd_flag != send_cmd) {
            ts_err("failed cmd_reg:0x%X, 0x%X, 0x%X", cmd_buf[0], cmd_buf[1], cmd_buf[INDEX_2]);
            if (goodix_send_command(&ts_cmd)) {
                ts_err("Resend cmd 0x%02X FAILED", send_cmd);
                return -EINVAL;
            }
        }

        sys_delay_ms(GOODIX_DELAY_10MS);
    }

    return -EINVAL;
}

static int goodix_send_config(struct goodix_ts_config *config)
{
    int try_times = 0;
    u8 buf[3] = {0};
    u16 command_reg = GT786X_CMD_REG, cfg_reg = GT786X_CFG_REG;
    struct goodix_ts_cmd ts_cmd;

    /* 1. Inquire command_reg until it's free */
    for (try_times = 0; try_times < TS_WAIT_CMD_FREE_RETRY_TIMES; try_times++) {
        if (!goodix_reg_read(command_reg, buf, 1) && buf[0] == TS_CMD_REG_READY) {
            break;
        }

        sys_delay_ms(TS_WAIT_CMD_READY_DELAY_MS);
    }
    if (try_times >= TS_WAIT_CMD_FREE_RETRY_TIMES) {
        ts_err("failed send cfg, reg:0x%04x is not 0xff", command_reg);
        return -EINVAL;
    }

    /* 2. send "start write cfg" command */
    goodix_cmd_init(&ts_cmd, COMMAND_START_SEND_CFG, 0, GT786X_CMD_REG);
    if (goodix_send_command(&ts_cmd)) {
        ts_err("failed send cfg, COMMAND_START_SEND_CFG ERROR");
        return -EINVAL;
    }

    /* 3. wait ic set command_reg to 0x82 */
    if (goodix_wait_cfg_cmd_ready(COMMAND_SEND_CFG_PREPARE_OK, COMMAND_START_SEND_CFG)) {
        ts_err("failed send cfg, reg:0x%04x is not 0x82", command_reg);
        return -EINVAL;
    }

    /* 4. write cfg */
    if (goodix_reg_write(cfg_reg, config->data, config->length)) {
        ts_err("Send cfg FAILED, write cfg to fw ERROR");
        return -EINVAL;
    }

    /* 5. send "end send cfg" command */
    goodix_cmd_init(&ts_cmd, COMMAND_END_SEND_CFG, 0, GT786X_CMD_REG);
    if (goodix_send_command(&ts_cmd)) {
        ts_err("failed send cfg, COMMAND_END_SEND_CFG ERROR");
        return -EINVAL;
    }

    /* 6. wait ic set command_reg to 0xff */
    for (try_times = 0; try_times < TS_WAIT_CMD_FREE_RETRY_TIMES; try_times++) {
        if (!goodix_reg_read(command_reg, buf, 1) && buf[0] == TS_CMD_REG_READY) {
            break;
        }

        sys_delay_ms(TS_WAIT_CMD_READY_DELAY_MS);
    }
    if (try_times >= TS_WAIT_CMD_FREE_RETRY_TIMES) {
        ts_err("failed send cfg, reg:0x%04x is 0x%x not 0xff", command_reg, buf[0]);
        return -EINVAL;
    }

    ts_info("Send cfg SUCCESS\n");
    return 0;
}

/* success return config length else return -1 */
static int goodix_read_config_nor(u8 *buf, int size)
{
    u32 cfg_addr = GT786X_CFG_REG;
    int sub_bags = 0, offset = 0, subbag_len, i, ret;
    u8 checksum;

    ret = goodix_reg_read(cfg_addr, buf, TS_CFG_HEADER_SIZE);
    if (ret) {
        return ret;
    }

    offset = TS_CFG_HEADER_SIZE;
    sub_bags = buf[TS_CFG_BAG_NUM_INDEX];
    checksum = checksum_u8(buf, TS_CFG_HEADER_SIZE);
    if (checksum) {
        ts_err("Config head checksum err\n");
        return -EINVAL;
    }

    ts_info("config_version:%u, vub_bags:%u\n", buf[0], sub_bags);
    for (i = 0; i < sub_bags; i++) {
        /* read sub head [0]: sub bag num, [1]: sub bag length */
        if (offset + GOODIX_CFG_BAG_HEADER_SIZE >= size) {
            ts_err("config size overflow, %d\n", offset + GOODIX_CFG_BAG_HEADER_SIZE);
            return -EINVAL;
        }
        ret = goodix_reg_read(cfg_addr + offset, buf + offset, GOODIX_CFG_BAG_HEADER_SIZE);
        if (ret) {
            return ret;
        }

        /* read sub bag data */
        subbag_len = buf[offset + GOODIX_CFG_BAG_LEN_SIZE];

        ts_debug("sub bag num:%u,sub bag length:%u\n", buf[offset], subbag_len);
        if (offset + GOODIX_CFG_BAG_SIZE(subbag_len) >= size) {
            ts_err("config size overflow, %d\n", offset + GOODIX_CFG_BAG_SIZE(subbag_len));
            return -EINVAL;
        }
        ret = goodix_reg_read(cfg_addr + offset + GOODIX_CFG_BAG_HEADER_SIZE,
                              buf + offset + GOODIX_CFG_BAG_HEADER_SIZE, subbag_len + GOODIX_CFG_BAG_CHECKSUM_SIZE);
        if (ret) {
            return ret;
        }
        checksum = checksum_u8(buf + offset, GOODIX_CFG_BAG_SIZE(subbag_len));
        if (checksum) {
            ts_err("sub bag checksum err:0x%x\n", checksum);
            return -EINVAL;
        }
        offset += GOODIX_CFG_BAG_SIZE(subbag_len);
    }
    return offset;
}

/* success return config_len, <= 0 failed */
static int goodix_read_config(u8 *config_data, int size)
{
    struct goodix_ts_cmd ts_cmd;
    u8 cmd_flag;
    u32 cmd_reg = GT786X_CMD_REG;
    int r = 0, i;

    if (!config_data) {
        ts_err("Illegal params");
        return -EINVAL;
    }
    if (!GT786X_CMD_REG) {
        ts_err("command register ERROR:0x%04x", GT786X_CMD_REG);
        return -EINVAL;
    }

    /* wait for IC in IDLE state */
    for (i = 0; i < TS_WAIT_CMD_FREE_RETRY_TIMES; i++) {
        cmd_flag = 0;
        r = goodix_reg_read(cmd_reg, &cmd_flag, 1);
        if (r < 0 || cmd_flag == TS_CMD_REG_READY) {
            break;
        }

        sys_delay_ms(GOODIX_DELAY_10MS);
    }
    if (cmd_flag != TS_CMD_REG_READY) {
        ts_err("Wait for IC ready IDEL state timeout:addr 0x%x\n", cmd_reg);
        return -EAGAIN;
    }
    /* 0x86 read config command */
    goodix_cmd_init(&ts_cmd, COMMAND_START_READ_CFG, 0, cmd_reg);
    r = goodix_send_command(&ts_cmd);
    if (r) {
        ts_err("Failed send read config command");
        return r;
    }
    /* wait for config data ready */
    if (goodix_wait_cfg_cmd_ready(COMMAND_READ_CFG_PREPARE_OK, COMMAND_START_READ_CFG)) {
        ts_err("Wait for config data ready timeout");
        return -EAGAIN;
    }

    r = goodix_read_config_nor(config_data, size);
    if (r <= 0) {
        ts_err("Failed read config data");
    }

    /* clear command */
    goodix_cmd_init(&ts_cmd, TS_CMD_REG_READY, 0, cmd_reg);
    goodix_send_command(&ts_cmd);

    return r;
}

#define HW_REG_CLEAR_RAM        0x51E0
#define GOODIX_SOFT_RESET_REG   0x2180
#define GOODIX_SOFT_RESET_DELAY 500
#define GOODIX_SW_RESET_CMD     0x01
static int goodix_reset(void)
{
    u8 reset_cmd = GOODIX_SW_RESET_CMD;
    u8 clear_ram_buf[8] = {0};

    /* clear ram */
    goodix_reg_write(HW_REG_CLEAR_RAM, clear_ram_buf, sizeof(clear_ram_buf));
    goodix_reg_write(HW_REG_CLEAR_RAM, clear_ram_buf, sizeof(clear_ram_buf));
    sys_delay_ms(GOODIX_DELAY_10MS);

    goodix_reg_write(GOODIX_SOFT_RESET_REG, &reset_cmd, 1);
    sys_delay_ms(GOODIX_DELAY_10MS);
    goodix_reg_write(GOODIX_SOFT_RESET_REG, &reset_cmd, 1);
    sys_delay_ms(GOODIX_DELAY_10MS);
    goodix_reg_write(GOODIX_SOFT_RESET_REG, &reset_cmd, 1);
    sys_delay_ms(GOODIX_SOFT_RESET_DELAY);
    return 0;
}

#define GOODIX_HID_FLAG_REG     0x0100
#define GOODIX_HID_MODE_FLAG    0x1E
#define GOODIX_HID_CMD_REG      0x0500
#define GOODIX_RETRY_3 3
static void goodix_coor_reg_write(void)
{
    u8 flag = 0;
    goodix_reg_write(GT786X_COOR_REG, &flag, 1);
    sys_delay_ms(GOODIX_DELAY_10MS);
    goodix_reg_write(GT786X_COOR_REG, &flag, 1);
    sys_delay_ms(GOODIX_DELAY_10MS);
    goodix_reg_write(GT786X_COOR_REG, &flag, 1);
}

static int goodix_hid_mode_switch(int mode)
{
    int ret, retry;
    u8 flag;
    // because the reg rw function must have address, so set the first byte as address parameter.
    u8 enter_iic_mode_cmd[] = {0x2e, 0x03, 0x06, 0x00, 0x08, 0x00, 0x0e, 0x0f, 0x00, 0x00, 0x01, 0x01};

    ret = goodix_reg_read(GOODIX_HID_FLAG_REG, &flag, 1);
    if (ret) {
        ts_err("Read HID mode flag failed");
        return ret;
    }

    if ((mode && flag == GOODIX_HID_MODE_FLAG) || (!mode && flag != GOODIX_HID_MODE_FLAG)) {
        ts_info("already in %s mode, no need switch", flag == GOODIX_HID_MODE_FLAG ? "HID" : "I2C");
        return 0;
    }

    if (mode) {
        // soft reset IC to enter HID mode
        if (goodix_reset()) {
            return -EINVAL;
        }
        ret = goodix_reg_read(GOODIX_HID_FLAG_REG, &flag, 1);
        if (ret) {
            return ret;
        }
        if (flag == GOODIX_HID_MODE_FLAG) {
            return 0;
        }
        ts_err("Failed enter HID mode ");
        return -EINVAL;
    }

    for (retry = 0; retry < GOODIX_RETRY_3; retry++) {
        ret = goodix_reg_write(GOODIX_HID_CMD_REG, enter_iic_mode_cmd, sizeof(enter_iic_mode_cmd));
        if (ret) {
            sys_delay_ms(GOODIX_DELAY_10MS);
            continue;
        }
        // check state
        sys_delay_ms(GOODIX_DELAY_100MS);
        ret = goodix_reg_read(GOODIX_HID_FLAG_REG, &flag, 1);
        if (ret) {
            sys_delay_ms(GOODIX_DELAY_10MS);
            continue;
        }
        if (flag != GOODIX_HID_MODE_FLAG) {
            /* clean coor flag */
            goodix_coor_reg_write();
            return 0;
        }
    }
    ts_info("Failed exit HID mode");
    return -EINVAL;
}

#define CFG_START_ADDR             0x60DC

#define VERSION_ADDR	           0x452C
#define VERSION_LEN                72
int goodix_read_version(struct goodix_ts_version *version)
{
    u8 temp_buf[VERSION_LEN];
    u8 cfg_ver;
    u16 checksum;
    int r;

    r = goodix_reg_read(VERSION_ADDR, temp_buf, VERSION_LEN);
    if (r < 0) {
        ts_err("Read version base failed, reg:0x%02x, len:%d\n", VERSION_ADDR, VERSION_LEN);
        return r;
    }

    checksum = checksum_u8(temp_buf, VERSION_LEN);
    if (checksum) {
        ts_err("Read version checksum error\n");
        return -EINVAL;
    }

    r = goodix_reg_read(CFG_START_ADDR, &cfg_ver, 1);
    if (r < 0) {
        ts_err("Read config version failed\n");
        return r;
    }

    memcpy_s(version->pid, GOODIX_PID_MAX_LEN, temp_buf + FW_VERSION_VID_OFFSET, sizeof(version->pid));
    version->cid = temp_buf[FW_VERSION_CID_OFFSET];
    memcpy_s(version->vid, GOODIX_VID_MAX_LEN, temp_buf + FW_VERSION_CID_OFFSET, FW_VERSION_SIZE);
    version->sensor_id = temp_buf[FW_VERSION_SID_OFFSET] & 0x0f;
    version->config_id = cfg_ver;

    ts_info("IC pid: %*ph\n", (int)sizeof(version->pid), version->pid);
    ts_info("IC vid: %*ph\n", FW_VERSION_SIZE, version->vid);
    ts_info("IC sensorid:%d\n", version->sensor_id);
    ts_info("Goodix_Config verion:%d\n", cfg_ver);

    return 0;
}

struct goodix_ts_hw_ops gt786x_hw_ops = {
    .reset = goodix_reset,
    .read = goodix_reg_read,
    .write = goodix_reg_write,
    .read_version = goodix_read_version,
    .send_cmd = goodix_send_command,
    .send_config = goodix_send_config,
    .read_config = goodix_read_config,
    .hid_mode_switch = goodix_hid_mode_switch,
};
