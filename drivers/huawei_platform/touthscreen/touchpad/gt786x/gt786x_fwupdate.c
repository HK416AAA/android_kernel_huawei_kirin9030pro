/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
/*
 * @Author: your name
 * @Date: 2022-06-28 14:13:48
 * @LastEditTime: 2022-06-28 14:28:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \app\goodix_ts_fwupdate.c
 */
#include <linux/firmware.h>

#include "hm_os_sys.h"
#include "goodix_ts_log.h"
#include "goodix_ts_core.h"
#include "goodix_ts_utils.h"

#define MODULE_WATCHDOG_ENABLE 0

#define FW_HEADER_SIZE				256
#define FW_SUBSYS_INFO_SIZE			8
#define FW_SUBSYS_INFO_OFFSET		32
#define FW_SUBSYS_MAX_NUM			28

#define FW_ISP_PKG_HEADER_SIZE      4
#define FW_ISP_PKG_CHECKSUM_SIZE    2
#define FW_ISP_PKG_METADATA_SIZE    (FW_ISP_PKG_HEADER_SIZE + FW_ISP_PKG_CHECKSUM_SIZE)

#define ISP_MAX_BUFFERSIZE			(1024 * 4)
#define FW_CHECKSUM_SIZE            4
#define FW_LEN_SIZE                 2

#define HW_REG_BANK_SELECT			0x2048
#define HW_REG_ACCESS_PATCH0		0x204D
#define HW_REG_ISP_ADDR				0xC000
#define HW_REG_ISP_RUN_FLAG			0x6006
#define HW_REG_CPU_RUN_FROM			0x4506 /* for nor_L is 0x4006 */
#define HW_REG_CPU_CTRL				0x2180
#define HW_REG_CLEAR_RAM            0x51E0

#define HW_REG_CPU_CTRL				0x2180
#define HW_REG_DSP_MCU_POWER		0x2010
#define HW_REG_CACHE				0x204B
#define HW_REG_ESD_KEY		        0x2318
#define HW_REG_WTD_TIMER			0x20B0
#define HW_REG_SCRAMBLE				0x2218
#define SORT_RESET_ADDR 			0x2184

#define HW_REG_ISP_BUFFER			0x6100
#define HW_REG_FLASH_FLAG			0x6022
#define HW_REG_SUBSYS_TYPE			0x6020

#define ISP_STAT_IDLE				0xFF
#define ISP_STAT_READY				0xAA
#define ISP_STAT_WRITING			0xAA
#define ISP_FLASH_SUCCESS			0xBB
#define ISP_FLASH_ERROR				0xCC
#define ISP_FLASH_CHECK_ERROR		0xDD
#define ISP_CMD_PREPARE				0x55
#define ISP_CMD_FLASH				0xAA


#define FLASH_ADDR_CONFIG_DATA			0x1E000
#define FLASH_SUBSYS_TYPE_CONFIG		0x03

#define ERROR_INVAL  (-1)

struct fw_subsys_info {
    u8 type;
    u32 size;
    u16 flash_addr;
    const u8 *data;
};

#pragma pack(1)
struct firmware_info {
    u32 size;
    u16 checksum;
    u8 hw_pid[6];
    u8 hw_vid[3];
    u8 fw_pid[8];
    u8 fw_vid[4];
    u8 subsys_num;
    u8 chip_type;
    u8 protocol_ver;
    u8 reserved[2];
    struct fw_subsys_info subsys[FW_SUBSYS_MAX_NUM];
};
#pragma pack()

struct firmware_data {
    struct firmware_info fw_info;
    const struct firmware *firmware;
    const struct firmware *config;
} g_fw_data;

static u8 g_buf[ISP_MAX_BUFFERSIZE];
static u8 g_buf1[ISP_MAX_BUFFERSIZE + FW_CHECKSUM_SIZE + FW_LEN_SIZE];
 
static u16 skip_flash_addr[] = {0x0000, 0x0010, 0x0020, 0x00c0, 0x00d0, 0x00e0, 0x0100};
 
static int should_skip_package(u16 addr)
{
    int i;
 
    for (i = 0; i < ARRAY_SIZE(skip_flash_addr); i++) {
        if (addr == skip_flash_addr[i]) {
            return 1;
        }
    }
    return 0;
}

#define REG_WRITE_CONFIG_BUF_LEN    32
int goodix_reg_write_confirm(u32 addr, u8 *data, u32 len)
{
    u8 cfm_buf[REG_WRITE_CONFIG_BUF_LEN];
    int r;

    r = gt786x_hw_ops.write(addr, data, len);
    if (r < 0) {
        return r;
    }
        
    r = gt786x_hw_ops.read(addr, cfm_buf, len);
    if (r < 0) {
        return r;
    }

    if (memcmp(data, cfm_buf, len)) {
        return -1;
    }
        
    return 0;
}

static int goodix_parse_firmware(void)
{
    const struct firmware *firmware = g_fw_data.firmware;
    struct firmware_info *fw_info = &g_fw_data.fw_info;
    unsigned int i, fw_offset, info_offset;
    u16 checksum;

    if (firmware->size < FW_SUBSYS_INFO_OFFSET) {
        ts_err("Invalid firmware size:%d\n", firmware->size);
        return -1;
    }
    memcpy_s(fw_info, FW_SUBSYS_INFO_OFFSET, firmware->data, FW_SUBSYS_INFO_OFFSET);

    /* check firmware size */
    fw_info->size = be32_to_cpu(fw_info->size);
    if (firmware->size != fw_info->size + FW_CHECKSUM_SIZE + FW_LEN_SIZE) {
        ts_err("Bad firmware, size not match, %d != %d\n",
            firmware->size, fw_info->size + FW_CHECKSUM_SIZE + FW_LEN_SIZE);
        return ERROR_INVAL;
    }

    for (i = FW_CHECKSUM_SIZE + FW_LEN_SIZE, checksum = 0; i < firmware->size; i++) {
        checksum += firmware->data[i];
    }

    /* byte order change, and check */
    fw_info->checksum = be16_to_cpu(fw_info->checksum);
    if (checksum != fw_info->checksum) {
        ts_err("Bad firmware, cheksum error %x(file) != %x(cal)\n",
            fw_info->checksum, checksum);
        return ERROR_INVAL;
    }

    if (fw_info->subsys_num > FW_SUBSYS_MAX_NUM) {
        ts_err("Bad firmware, invalid subsys num: %d\n",
               fw_info->subsys_num);
        return ERROR_INVAL;
    }

    /* parse subsystem info */
    fw_offset = FW_HEADER_SIZE;
    for (i = 0; i < fw_info->subsys_num; i++) {
        info_offset = FW_SUBSYS_INFO_OFFSET + i * FW_SUBSYS_INFO_SIZE;
        fw_info->subsys[i].type = firmware->data[info_offset];
        fw_info->subsys[i].size = be32_to_cpup((const __be32 *)(&firmware->data[info_offset + 1]));
        fw_info->subsys[i].flash_addr = be16_to_cpup((const __be16 *)(&firmware->data[info_offset + 5]));

        if (fw_offset > firmware->size) {
            ts_err("Sybsys offset exceed Firmware size\n");
            return ERROR_INVAL;
        }

        fw_info->subsys[i].data = firmware->data + fw_offset;
        fw_offset += fw_info->subsys[i].size;
    }

    return 0;
}

/* return 0 if no need update
 * return 1 if version is not equal
 * return -1 failed read version
 */
enum FW_UPDATE_CHECK_RESULT {
    FW_UPDATE_CHECK_EQUAL = 0,
    FW_UPDATE_CHECK_NOT_EQUAL = 1,
    FW_UPDATE_CHECK_FAILED = -1,
};

int goodix_check_fw_version(void)
{
    struct goodix_ts_version fw_ver;
    struct firmware_info *fw_info = &g_fw_data.fw_info;
    int ret;
    
    ret = gt786x_hw_ops.read_version(&fw_ver);
    if (ret < 0) {
        ts_err("get version failed\n");
        return FW_UPDATE_CHECK_FAILED;
    }

    ret = memcmp(fw_ver.vid, fw_info->fw_vid, FW_VERSION_SIZE);
#ifdef TOUCHPAD_FACTORY_ENABLE
    if (ret) {
#else
    if (ret < 0) {
#endif
        ts_err("FW version if not equal to the IC's");
        ts_info("IC pid: %*ph\n", (int)sizeof(fw_ver.pid), fw_ver.pid);
        ts_info("IC vid: %*ph\n", FW_VERSION_SIZE, fw_ver.vid);
 
        ts_info("FW file pid: %*ph\n", (int)sizeof(fw_info->fw_pid), fw_info->fw_pid);
        ts_info("FW file vid: %*ph\n", FW_VERSION_SIZE, fw_info->fw_vid);
        return FW_UPDATE_CHECK_NOT_EQUAL;
    }
    return FW_UPDATE_CHECK_EQUAL;
}

int goodix_check_config(void)
{
    u8 *origin_cfg;
    int ret, origin_cfg_len = 0;

    origin_cfg = sys_malloc(GOODIX_CFG_MAX_SIZE);
    if (!origin_cfg) {
        ts_err("Failed to alloc memory for original config\n");
        return FW_UPDATE_CHECK_FAILED;
    }

    ret = gt786x_hw_ops.read_config(origin_cfg, GOODIX_CFG_MAX_SIZE);
    if (ret < 0) {
        ts_err("Failed to read original config data\n");
        goto err_out;
    }
    origin_cfg_len = ret;
    ts_info("read config len %d\n", ret);
    ret = FW_UPDATE_CHECK_NOT_EQUAL;
    if (origin_cfg_len != g_fw_data.config->size) {
        ts_err("flash cfg len %d != file cfg len %d!\n", ret, g_fw_data.config->size);
        goto err_out;
    }

    if (checksum_u8(origin_cfg, GTX8_CONFIG_HEAD_LEN)) {
        ts_err("cfg header checksum error");
        goto err_out;
    }

    if (origin_cfg[0] != g_fw_data.config->data[0]) {
        ts_err("cfg ver unequal %d!=%d", origin_cfg[0], g_fw_data.config->data[0]);
        goto err_out;
    }

    if (memcmp(origin_cfg + GTX8_CONFIG_HEAD_LEN, g_fw_data.config->data + GTX8_CONFIG_HEAD_LEN,
        origin_cfg_len - GTX8_CONFIG_HEAD_LEN)) {
        ts_err("Read out config data uneaqual with file config\n");
        goto err_out;
    }
    ret = FW_UPDATE_CHECK_EQUAL;
    ts_info("Config is equal to the IC's\n");
err_out:
    if (ret == FW_UPDATE_CHECK_NOT_EQUAL) {
        ts_info("read out config data:");
        ts_info_array(origin_cfg, origin_cfg_len);

        ts_info("file config dat:");
        ts_info_array((u8 *)g_fw_data.config->data, g_fw_data.config->size);
    }
    sys_free(origin_cfg);
    return ret;
}

int goodix_check_update(void)
{
    int ret;

    ret = goodix_check_fw_version();
    if (ret != FW_UPDATE_CHECK_EQUAL) {
        ts_info("FW version check not equal %d\n", ret);
        return ret;
    }

    ret = goodix_check_config();
    if (ret != FW_UPDATE_CHECK_EQUAL) {
        ts_info("FW config check not equal %d\n", ret);
    }

    return ret;
}

#define GOODIX_REG_VALUE_RESET  0
#define GOODIX_REG_VALUE_SET    1

#define GOODIX_CPU_RUN_REG_SIZE      8
#define GOODIX_CPU_RUN_FROM_ISP_FLAG 0x55
static int goodix_load_isp_prepare(void)
{
    int r;
    u8 reg_val;

    ts_info("Loading ISP start\n");
    reg_val = GOODIX_REG_VALUE_RESET;
    r = gt786x_hw_ops.write(HW_REG_BANK_SELECT, &reg_val, sizeof(reg_val));
    if (r < 0) {
        ts_err("Failed to select bank0\n");
        return r;
    }
    ts_info("Success select bank0, Set 0x%x -->0x00\n", HW_REG_BANK_SELECT);

    reg_val = GOODIX_REG_VALUE_SET;
    r = gt786x_hw_ops.write(HW_REG_ACCESS_PATCH0, &reg_val, sizeof(reg_val));
    if (r < 0) {
        ts_err("Failed to enable patch0 access\n");
        return r;
    }
    ts_info("Success select bank0, Set 0x%x -->0x01\n", HW_REG_ACCESS_PATCH0);
    return 0;
}

static int goodix_switch_to_isp(void)
{
    int r;
    u8 reg_val[GOODIX_CPU_RUN_REG_SIZE] = {0};

    r = goodix_reg_write_confirm(HW_REG_ACCESS_PATCH0, reg_val, sizeof(u8));
    if (r < 0) {
        ts_err("Failed to disable patch0 access\n");
        return r;
    }
    ts_info("Success forbit bank0 accedd, set 0x%x -->0x00\n", HW_REG_ACCESS_PATCH0);

    r = gt786x_hw_ops.write(HW_REG_ISP_RUN_FLAG, reg_val, sizeof(u16));
    if (r < 0) {
        ts_err("Failed to clear 0x%x\n", HW_REG_ISP_RUN_FLAG);
        return r;
    }
    ts_info("Success clear 0x%x\n", HW_REG_ISP_RUN_FLAG);

    memset_s(reg_val, GOODIX_CPU_RUN_FROM_ISP_FLAG, GOODIX_CPU_RUN_FROM_ISP_FLAG, sizeof(reg_val));
    r = gt786x_hw_ops.write(HW_REG_CPU_RUN_FROM, reg_val, sizeof(reg_val));
    if (r < 0) {
        ts_err("Failed set HW_REG_CPU_RUN_FROM flag\n");
        return r;
    }
    ts_info("Success write [8]0x55 to HW_REG_CPU_RUN_FROM\n");

    reg_val[0] = 0x00;
    r = gt786x_hw_ops.write(HW_REG_CPU_CTRL, reg_val, sizeof(u8));
    if (r < 0) {
        ts_err("Failed to run isp\n");
        return r;
    }
    ts_info("Success run isp, set 0x%x-->0x00\n", HW_REG_CPU_CTRL);
    return 0;
}

#define GOODIX_RETRY_200 200
#define GOODIX_IS_RUN_FLAG_AA 0xAA
#define GOODIX_IS_RUN_FLAG_BB 0xBB
static int goodix_load_isp(struct firmware_data *fw_data)
{
    struct fw_subsys_info *fw_isp = &fw_data->fw_info.subsys[0];
    u8 reg_val[GOODIX_CPU_RUN_REG_SIZE] = {0x00};
    int r, i;

    if ((r = goodix_load_isp_prepare()) != 0) {
        return r;
    }

    r = gt786x_hw_ops.write(HW_REG_ISP_ADDR, fw_isp->data, fw_isp->size);
    if (r < 0) {
        ts_err("Loading ISP error\n");
        return r;
    }

    ts_info("Success send ISP data to IC\n");

    if ((r = goodix_switch_to_isp()) != 0) {
        return r;
    }

    /* check isp work state */
    for (i = 0; i < GOODIX_RETRY_200; i++) {
        #if MODULE_WATCHDOG_ENABLE
        wd_clear_cnt();
        #endif
        sys_delay_ms(GOODIX_DELAY_10MS);
        r = gt786x_hw_ops.read(HW_REG_ISP_RUN_FLAG, reg_val, sizeof(u16));
        if (r < 0 || (reg_val[0] == GOODIX_IS_RUN_FLAG_AA && reg_val[1] == GOODIX_IS_RUN_FLAG_BB)) {
            break;
        }
    }
    if (reg_val[0] == GOODIX_IS_RUN_FLAG_AA && reg_val[1] == GOODIX_IS_RUN_FLAG_BB) {
        ts_info("ISP working OK\n");
        return 0;
    }
    ts_err("ISP not work,0x%x=0x%x, 0x%x=0x%x\n", HW_REG_ISP_RUN_FLAG, reg_val[0],
        HW_REG_ISP_RUN_FLAG + 1, reg_val[1]);
    return -1;
}

#define GOODIX_HOLD_SS51_RETRY 20
#define GOODIX_HOLD_SS51_DELAY 20
#define GOODIX_DELAY_2MS        2
#define GDODIX_HOLD_FLAG        0x24
static int goodix_hold_ss51(void)
{
    u8 temp_buf[GOODIX_CPU_RUN_REG_SIZE] = {0};
    int retry, r;

    gt786x_hw_ops.write(HW_REG_CPU_RUN_FROM, temp_buf, sizeof(temp_buf));

    /* soft reset IC */
    ts_info("firmware update, reset\n");
    temp_buf[0] = GOODIX_REG_VALUE_SET;
    gt786x_hw_ops.write(SORT_RESET_ADDR, temp_buf, 1);
    sys_delay_ms(GOODIX_DELAY_2MS);

    for (retry = 0; retry < GOODIX_HOLD_SS51_RETRY; retry++) {
        temp_buf[0] = GDODIX_HOLD_FLAG;
        r = goodix_reg_write_confirm(HW_REG_CPU_CTRL, temp_buf, 1);
        if (r < 0) {
            ts_err("Failed to hold ss51, retry\n");
            sys_delay_ms(GOODIX_HOLD_SS51_DELAY);
        } else {
            break;
        }
    }
    if (retry >= GOODIX_HOLD_SS51_RETRY) {
        ts_err("Failed hold ss51,return =%d\n", r);
        return -EINVAL;
    }
    ts_info("success hold ss51\n");

    return 0;
}

#define GOODIX_ESD_VAL1 0x95
#define GOODIX_ESD_VAL2 0x27
static int goodix_update_reg_init(void)
{
    u8 reg_val;
    int r;

    /* enable DSP & MCU power */
    reg_val = GOODIX_REG_VALUE_RESET;
    r = goodix_reg_write_confirm(HW_REG_DSP_MCU_POWER, &reg_val, sizeof(reg_val));
    if (r < 0) {
        ts_err("Failed enable DSP&MCU power\n");
        return r;
    }
    ts_info("Success enabled DSP&MCU power,set 0x%x-->0x00\n", HW_REG_DSP_MCU_POWER);

    /* disable watchdog timer */
    reg_val = GOODIX_REG_VALUE_RESET;
    r = gt786x_hw_ops.write(HW_REG_CACHE, &reg_val, sizeof(reg_val));
    if (r < 0) {
        ts_err("Failed to clear cache\n");
        return r;
    }
    ts_info("Success clear cache\n");

    reg_val = GOODIX_ESD_VAL1;
    r = gt786x_hw_ops.write(HW_REG_ESD_KEY, &reg_val, sizeof(reg_val));
    reg_val = GOODIX_REG_VALUE_RESET;
    r |= gt786x_hw_ops.write(HW_REG_WTD_TIMER, &reg_val, sizeof(reg_val));
    reg_val = GOODIX_ESD_VAL2;
    r |= gt786x_hw_ops.write(HW_REG_ESD_KEY, &reg_val, sizeof(reg_val));
    if (r < 0) {
        ts_err("Failed to disable watchdog\n");
        return r;
    }
    ts_info("Success disable watchdog\n");

    /* set scramble */
    reg_val = GOODIX_REG_VALUE_RESET;
    r = gt786x_hw_ops.write(HW_REG_SCRAMBLE, &reg_val, sizeof(reg_val));
    if (r < 0) {
        ts_err("Failed to set scramble\n");
        return r;
    }
    ts_info("Succcess set scramble\n");
    return 0;
}

static int goodix_update_prepare(void)
{
    int r;

    if ((r = goodix_hold_ss51()) != 0) {
        return r;
    }

    if ((r = goodix_update_reg_init()) != 0) {
        return r;
    }

    /* load ISP code and run form isp */
    r = goodix_load_isp(&g_fw_data);
    if (r < 0) {
        ts_err("Failed lode and run isp\n");
    }

    return r;
}

static int goodix_format_fw_packet(u8 *pkt, u32 flash_addr, u16 len, const u8 *data)
{
    u16 checksum;

    if (!pkt || !data) {
        return -EINVAL;
    }

    /*
     * checksum rule:sum of data in one format is equal to zero
     * data format: byte/le16/be16/le32/be32/le64/be64
     */
    pkt[0] = GOODIX_VAL_H(len);
    pkt[1] = GOODIX_VAL_L(len);
    /* u16 >> 16bit seems nosense but really important */
    pkt[INDEX_2] = GOODIX_MOVE_16BIT(flash_addr);
    pkt[INDEX_3] = GOODIX_MOVE_8BIT(flash_addr);
    memcpy_s(&pkt[FW_ISP_PKG_HEADER_SIZE], len, data, len);
    checksum = checksum_be16(pkt, len + FW_ISP_PKG_HEADER_SIZE);
    checksum = 0 - checksum;
    len += FW_ISP_PKG_HEADER_SIZE;
    pkt[len++] = GOODIX_VAL_H(checksum);
    pkt[len] = GOODIX_VAL_L(checksum);
    return 0;
}

#define GOODIX_WAIT_FLASH_END_DELAY     55
static int goodix_check_fw_packet_flash_end(void)
{
    u8 reg_val[4];
    int r, i;

    for (i = 0; i < GOODIX_RETRY_200; i++) {
        #if MODULE_WATCHDOG_ENABLE
            wd_clear_cnt();
        #endif
        r = gt786x_hw_ops.read(HW_REG_FLASH_FLAG, reg_val, sizeof(u16));
        if (r < 0) {
            ts_err("Failed read flash state\n");
            return r;
        }

        /* flash haven't end */
        if (reg_val[0] == ISP_STAT_WRITING && reg_val[1] == ISP_STAT_WRITING) {
            ts_info("Flash not ending...\n");
            sys_delay_ms(GOODIX_WAIT_FLASH_END_DELAY);
            continue;
        }
        if (reg_val[0] == ISP_FLASH_SUCCESS && reg_val[1] == ISP_FLASH_SUCCESS) {
            r = gt786x_hw_ops.read(HW_REG_FLASH_FLAG, reg_val, sizeof(u16));
            if (!r && reg_val[0] == ISP_FLASH_SUCCESS && reg_val[1] == ISP_FLASH_SUCCESS) {
                ts_info("Flash subsystem ok\n");
                return 0;
            }
        }
        if (reg_val[0] == ISP_FLASH_ERROR && reg_val[1] == ISP_FLASH_ERROR) {
            ts_err(" Flash subsystem failed\n");
            return ERROR_INVAL;
        }
        if (reg_val[0] == ISP_FLASH_CHECK_ERROR) {
            ts_err("Subsystem checksum err\n");
            return ERROR_INVAL;
        }

        sys_delay_ms(1);
    }
    ts_err("Wait for flash end timeout, 0x6022= %x %x\n", reg_val[0], reg_val[1]);
    return ERROR_INVAL;
}

static int goodix_send_fw_packet(u8 type, u8 *pkt, u32 len)
{
    u8 reg_val[4];
    int r;

    if (!pkt) {
        return -1;
    }

    ts_info("target fw subsys type:0x%x, len %d\n", type, len);
    r = gt786x_hw_ops.write(HW_REG_ISP_BUFFER, pkt, len);
    if (r < 0) {
        ts_err("Failed to write firmware packet\n");
        return r;
    }

    reg_val[0] = 0;
    reg_val[1] = 0;
    /* clear flash flag 0X6022 */
    r = goodix_reg_write_confirm(HW_REG_FLASH_FLAG, reg_val, sizeof(u16));
    if (r < 0) {
        ts_err("Faile to clear flash flag\n");
        return r;
    }

    reg_val[0] = type;
    reg_val[1] = type;
    r = goodix_reg_write_confirm(HW_REG_SUBSYS_TYPE, reg_val, sizeof(u16));
    if (r < 0) {
        ts_err("Failed write subsystem type to IC\n");
        return r;
    }

    return goodix_check_fw_packet_flash_end();
}

static int goodix_flash_config(void)
{
    int ret;
    u8 *fw_packet = g_buf1;
    u8 *temp_data = g_buf;

    memset_s(temp_data, ISP_MAX_BUFFERSIZE, 0xFF, ISP_MAX_BUFFERSIZE);
    ts_info("normal config length %d\n", g_fw_data.config->size);
    memcpy_s(temp_data, ISP_MAX_BUFFERSIZE, g_fw_data.config->data, g_fw_data.config->size);

    /* format one firmware packet */
    ret = goodix_format_fw_packet(fw_packet, FLASH_ADDR_CONFIG_DATA,
            ISP_MAX_BUFFERSIZE, temp_data);
    if (ret < 0) {
        ts_err("Invalid packet params\n");
        return ret;
    }
    ts_info("try flash config\n");
    ret = goodix_send_fw_packet(FLASH_SUBSYS_TYPE_CONFIG, fw_packet, ISP_MAX_BUFFERSIZE + FW_ISP_PKG_METADATA_SIZE);
    if (ret) {
        ts_err("failed flash config, ret %d\n", ret);
    } else {
        ts_info("success flash config with isp\n");
    }

    return ret;
}

#define GOODIX_FLASH_ISP_RETYR 3
static int goodix_flash_subsystem(struct fw_subsys_info *subsys)
{
    u16 data_size, offset;
    u32 total_size;
    u32 subsys_base_addr = subsys->flash_addr << 8;
    u8 *fw_packet = g_buf1;
    int r = 0, i;

    /*
     * if bus(i2c/spi) error occued, then exit, we will do
     * hardware reset and re-prepare ISP and then retry
     * flashing
     */
    total_size = subsys->size;

    offset = 0;
    while (total_size > 0) {
        data_size = total_size > ISP_MAX_BUFFERSIZE ? ISP_MAX_BUFFERSIZE : total_size;
        ts_info("Flash firmware to %08x,size:%u bytes\n",
            subsys_base_addr + offset, data_size);

        /* format one firmware packet */
        r = goodix_format_fw_packet(fw_packet, subsys_base_addr + offset,
                data_size, &subsys->data[offset]);
        if (r < 0) {
            ts_err("Invalid packet params\n");
            return r;
        }

        /* send one firmware packet, retry 3 time if send failed */
        for (i = 0; i < GOODIX_FLASH_ISP_RETYR; i++) {
            r = goodix_send_fw_packet(subsys->type, fw_packet, data_size + FW_ISP_PKG_METADATA_SIZE);
            if (!r) {
                break;
            }
        }
        if (r) {
            ts_err("Failed flash subsystem\n");
            return r;
        }
        offset += data_size;
        total_size -= data_size;
    } /* end while */

    return r;
}

static int goodix_flash_firmware(void)
{
    struct firmware_data *fw_data = &g_fw_data;
    struct firmware_info  *fw_info;
    struct fw_subsys_info *fw_x;
    int retry = 3, retry_max = 3;
    int i, r = 0, fw_num;

    /* start from subsystem 1,
     * subsystem 0 is the ISP program
     */
    fw_info = &fw_data->fw_info;
    fw_num = fw_info->subsys_num;

    for (i = 1; i < fw_num && retry;) {
        ts_info("--- Start to flash subsystem[%d] ---\n", i);
        fw_x = &fw_info->subsys[i];
        if (should_skip_package(fw_x->flash_addr)) {
            ts_info("Skip flash subsystem[%d], addr:0x%x\n", i, fw_x->flash_addr);
            i++;
            continue;
        }
        r = goodix_flash_subsystem(fw_x);
        if (r == 0) {
            ts_info("--- End flash subsystem[%d]: OK ---\n", i);
            i++;
        } else {
            retry--;
            ts_info("--- End flash subsystem%d: Fail, errno:%d, retry:%d ---\n", i, r, retry_max - retry);
        }
    }

    return r;
}

static int goodix_update_finish(void)
{
    u8 reg_val[8] = {0};
    int r = 0;
    u8 clear_ram_buf[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    /* hold ss51 */
    reg_val[0] = 0x24;
    gt786x_hw_ops.write(HW_REG_CPU_CTRL, reg_val, 1);

    /* clear recovery flag */
    memset_s(reg_val, sizeof(reg_val), 0, sizeof(reg_val));
    gt786x_hw_ops.write(HW_REG_CPU_RUN_FROM, reg_val, sizeof(reg_val));

    /* release ss51 */
    reg_val[0] = 0x00;
    gt786x_hw_ops.write(HW_REG_CPU_CTRL, reg_val, 1);

    /* clear ram */
    gt786x_hw_ops.write(HW_REG_CLEAR_RAM, clear_ram_buf, sizeof(clear_ram_buf));
    sys_delay_ms(GOODIX_DELAY_10MS);
    
    /* soft reset */
    reg_val[0] = 1;
    gt786x_hw_ops.write(SORT_RESET_ADDR, reg_val, 1);
    sys_delay_ms(GOODIX_DELAY_100MS);

    r = goodix_check_update();
    if (r) {
        ts_err("fw version check failed\n");
        return -1;
    }

    ts_info("fw version check pass\n");
    return 0;
}

static int goodix_get_firmware_data(void)
{
    memset_s(&g_fw_data, sizeof(g_fw_data), 0, sizeof(g_fw_data));

    g_fw_data.firmware = goodix_request_firmware(FIRMWARE_FILE_NAME);
    if (!g_fw_data.firmware) {
        ts_err("failed get fw %s, %d", FIRMWARE_FILE_NAME);
        return -EINVAL;
    }

    g_fw_data.config = goodix_request_firmware(NORMAL_CONFIG_FILE_NAME);
    if (!g_fw_data.config) {
        ts_err("failed get config data");
        release_firmware(g_fw_data.firmware);
        g_fw_data.firmware = NULL;
        return -EINVAL;
    }
    return 0;
}

static void goodix_free_firmware_data(void)
{
    if (g_fw_data.firmware) {
        release_firmware(g_fw_data.firmware);
        g_fw_data.firmware = NULL;
    }
    if (g_fw_data.config) {
        release_firmware(g_fw_data.config);
        g_fw_data.config = NULL;
    }
}

int goodix_fw_update_proc(void)
{
    int r = -EINVAL;

    if (goodix_get_firmware_data()) {
        ts_err("Failed get firmware data\n");
        return -EINVAL;
    }

    if ((r = goodix_parse_firmware()) < 0) {
        ts_err("parse firmware failed\n");
        goto err_fw;
    }

    if (!(r = goodix_check_update())) {
        /* version equal no need update */
        goto err_fw;
    }

    gt786x_hw_ops.hid_mode_switch(0);
    ts_info("update proc start\n");
    if ((r = goodix_update_prepare()) < 0) {
        ts_err("update prepare failed\n");
        goto exit;
    }
    ts_info("update prepare success\n");

    if ((r = goodix_flash_config()) < 0) {
        ts_err("flash config failed\n");
        goto exit;
    }

    if ((r = goodix_flash_firmware()) < 0) {
        ts_err("flash firmware failed\n");
        goto exit;
    }

exit:
    if (r || goodix_update_finish()) {
        r = -EINVAL;
    }

err_fw:
    goodix_free_firmware_data();
    return r;
}
