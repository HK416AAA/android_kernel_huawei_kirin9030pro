/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
 
#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/firmware.h>
#include <linux/mutex.h>
#include <securec.h>
#ifdef CONFIG_HISYSEVENT
#include <dfx/hiview_hisysevent.h>
#endif
#include "edp_drv/edp_panel_drv.h"
#include "edp_sysfs.h"
#include "edp_factory.h"
#include "tcon_i2c/tcon_i2c.h"
#include "tcon_i2c/tcon_i2c_upgrade.h"
#include "edp_log.h"
#include "edp_sysfs_fact.h"
 
#define PSR_ADDR 0xff400170
#define CHECKSUM_ADDR_1 0xff00569c
#define CHECKSUM_ADDR_2 0xff0046c0
#define ERR_RATE_1 0xff400210
#define ERR_RATE_2 0xff400214
#define ERR_RATE_VALID_1 0x8000
#define ERR_RATE_VALID_2 0x80000000
#define ERR_RATE_DATA_1 0x7fff
#define ERR_RATE_DATA_2 0x7fff0000
#define DDRT_START_ADDR 0x10d0000
#define DDRT_TEST_LEN 0x1030000
#define DDRT_ADDR_1 0xFF810020
#define DDRT_ADDR_2 0xFF810010
#define DDRT_ADDR_3 0xFF810018
#define DDRT_ADDR_4 0xFF810000
#define DDRT_TIME_OUT 0xFF810004
#define DDRT_CRACK_ADDR 0xF1010024
#define DDRT_CHECK_TIMES 10
#define CHECK_LOOP_CNT 30
#define TESTNUM 300
#define ERR_CNT_THD 10
#define EDP_MUTE_STATE 0xFF500EF0
#define UNSIGNED_INT_BIT_LENGTH 16
#define FIFTH_HEX_FLAG 0x10
#define CHECK_EXT_TCON_VENDOR_ENABLE  true
#define SHORT_BIT_LEN 16
#define VERSION_MAX_SIZE 31
#define CHANGE_MAIN 0XA
#define CHANGE_EXT 0XB
#define CRACK_1 0xff20028c
#define SN_ADDR_NUM 6
#define PANEL_SCREENSN_LEN 23
#define PANEL_SCREENSN_MOVE_BIT 8
#define PANEL_SCREENSN_MASK 0x000000FF
#define PANEL_SCREENSN_READ_DELAY_TIME 5
#define TCON_TE_ADDR 0xF8A2120C
#define TCON_SWITCH_FPS_ADDR 0xf1010040
#define TCON_MASK_SOC_FPS_ADDR 0xf1010044
#define TCON_VDF_ADDR 0xff01e000
#define CLOSE_TCON_TE_VAL 0x0
#define MASKED_SOC_FPS_VAL 0x4b
#define STR_TO_UINT_BASE16 16
#define CLOSE_VDF_FPS_VAL 0xa

enum EDP_EXT_UPDATE_TOOL {
    WAITING_DOING,
    UPDATE_TCON_EXT,
    CHANGE_EXT_BOOT,
    CHANGE_MAIN_BOOT,
    CHECK_NEXT_START,
    CHECK_NOW_BOOT,
    UPDATE_TCON_MAIN,
    READ_TCON_BIN_VENDOR,
    TOOL_MAX,
};

static unsigned char g_upate_tool = WAITING_DOING;
static struct mutex g_tcon_mutex = { 0 };

struct i2c_uint {
    uint32_t reg_addr;
    uint32_t val;
    uint32_t msdelay;
};

static const unsigned int g_sn_addr_list[SN_ADDR_NUM] = { 0xf8000080, 0xf8000084, 0xf8000088,
                                                          0xf800008c, 0xf8000090, 0xf8000094};

// output colorbar
static struct i2c_uint g_ddrt_step1[] = {
    {0xff00000c, 0x0, 100},
    {0xff3100f8, 0x0, 100},
    {0xff00c000, 0xC0001011, 2},
    {0xff00c028, 0x01141401, 2},
    {0xff01ac00, 0x84840B40, 20},
};

// disable the frame buffer and algorithm IP read/write memory.
static struct i2c_uint g_ddrt_step2[] = {
    {0xff004600, 0x0, 2},
    {0xff004800, 0x0, 2},
    {0xff004A00, 0x0, 2},
    {0xff004B00, 0x0, 2},
    {0xff004C00, 0x0, 2},
    {0xff004D00, 0x0, 2},
    {0xff004E00, 0x0, 2},
    {0xff005300, 0x0, 2},
    {0xff005600, 0x0, 2},
    {0xff005A00, 0x0, 2},
    {0xff005C00, 0x0, 2},
    {0xff00000C, 0x0, 20},
};

// bus mux switched to ddrt operation
static struct i2c_uint g_ddrt_step3[] = {
    {0xf8a20008, 0x1, 20},
};

// reset 1 time ddrt
static struct i2c_uint g_ddrt_step4[] = {
    {0xf8a221EC, 0xf, 2},
    {0xf8a221EC, 0x3, 20},
};

// common DDRT configuration
static struct i2c_uint g_ddrt_step5[] = {
    {0xFF810008, 0x4f, 2},
    {0xFF810024, 0x100, 20},
};

// prbs
static struct i2c_uint g_ddrt_step6[] = {
    {0xFF810040, 0xdeadbeef, 2},
    {0xFF810044, 0x6954ed71, 2},
    {0xFF810048, 0x11251986, 2},
    {0xFF81004c, 0xa9b7c5d3, 2},
    {0xFF810050, 0xf1e0d9c2, 2},
    {0xFF810054, 0xb8a39a94, 2},
    {0xFF810058, 0x39f67d3c, 2},
    {0xFF81005c, 0x20160917, 2},
    {0xFF810030, 0x00000000, 20},
};

static void send_i2c_seq(struct i2c_uint* seq, uint8_t len)
{
	int i;
    int ret;

    for (i = 0; i < len; i++) {
        ret = tcon_i2c_write_addr(seq[i].reg_addr, seq[i].val);
        if (ret < 0)
			edp_warn("write addr failed\n");
        mdelay(seq[i].msdelay);
    }
}

static bool checksum_result(void)
{
    int i = 0;
    unsigned int read_buff_w[3] = {0};
    unsigned int read_buff_r[3] = {0};

    for (i = 0; i < CHECK_LOOP_CNT; i++) {
		edp_debug("check cnt %d\n", i);
		read_buff_w[0] = tcon_i2c_read_addr(CHECKSUM_ADDR_1);
		read_buff_r[0] = tcon_i2c_read_addr(CHECKSUM_ADDR_2);
		edp_info("checksumw: %x checksumr: %x\n", read_buff_w[0], read_buff_r[0]);
        if (read_buff_w[0] != read_buff_r[0]) {
            edp_err("Result : PSR RAM check Failed!! check cnt %d read_buff_w %x read_buff_r %x\n",
                i, read_buff_w[0], read_buff_r[0]);
            return false;
        }
		mdelay(1); // delay 1 ms
		read_buff_w[1] = tcon_i2c_read_addr(CHECKSUM_ADDR_1);
		read_buff_r[1] = tcon_i2c_read_addr(CHECKSUM_ADDR_2);
		edp_info("checksumw: %x checksumr: %x\n", read_buff_w[1], read_buff_r[1]);
		mdelay(1); // delay 1 ms
		read_buff_w[2] = tcon_i2c_read_addr(CHECKSUM_ADDR_1);
		read_buff_r[2] = tcon_i2c_read_addr(CHECKSUM_ADDR_2);
		edp_info("checksumw: %x checksumr: %x\n", read_buff_w[2], read_buff_r[2]);
		if ((read_buff_w[0] == read_buff_w[1] && read_buff_w[1] == read_buff_w[2]) &&
			(read_buff_r[0] == read_buff_r[1] && read_buff_r[1] == read_buff_r[2])) {
            edp_info("Result : PSR RAM check Sucess!! check cnt %d read_buff_w %x read_buff_r %x\n",
                i, read_buff_w[0], read_buff_r[0]);
            return true;
		}
		mdelay(1); // delay 1 ms
	}

	edp_err("The number of times exceeds the limit!\n");
	return false;
}

static bool check_i2c_psr_ram(void)
{
	unsigned char cmd_write_buff[1] = {WRITE_CMD_HEAD};
	unsigned char read_buff[12] = {0};
	unsigned int psr_state = 0;
	int i2c_status = 0;
    int ret;

	ret = tcon_i2c_write_block(cmd_write_buff, ARRAY_SIZE(cmd_write_buff));
    if (ret < 0)
		edp_warn("write block failed\n");
	mdelay(5); // delay 5 ms
	i2c_status = tcon_i2c_read_block(read_buff, ARRAY_SIZE(read_buff));
	if (i2c_status) {
		edp_err("i2c_status=%d, the path of I2C is no nomal.\n", i2c_status);
		return false;
	}
	// check psr status
	psr_state = tcon_i2c_read_addr(PSR_ADDR);
	edp_info("psr_state: 0x%x\n", psr_state);
	return checksum_result();
}

static uint16_t query_error_count(void)
{
	unsigned int lane0 = 0;
	unsigned int lane1 = 0;
	unsigned int lane2 = 0;
	unsigned int lane3 = 0;
    int i;
    unsigned int read_buff[2] = { 0 };
    unsigned int mute_state = 0;

    for (i = 0; i < TESTNUM; i++) {
        read_buff[0] = tcon_i2c_read_addr(ERR_RATE_1);
        read_buff[1] = tcon_i2c_read_addr(ERR_RATE_2);
        mute_state = tcon_i2c_read_addr(EDP_MUTE_STATE);
        if ((mute_state & FIFTH_HEX_FLAG) == FIFTH_HEX_FLAG) {
            edp_err("err rate check result is failed\n");
            return 0;
        }
        if (!(read_buff[0] & ERR_RATE_VALID_1) || !(read_buff[0] & ERR_RATE_VALID_2)
            || !(read_buff[1] & ERR_RATE_VALID_1) || !(read_buff[1] & ERR_RATE_VALID_2)) {
                edp_err("lane data is invalid, try again!\n");
                return 2; // 2 is invalid data, try again
        }

        lane0 = lane0 + (read_buff[0] & ERR_RATE_DATA_1);
        if (lane0)
            edp_err("lane0 error:%u \n", lane0);
        lane1 = lane1 + ((read_buff[0] & ERR_RATE_DATA_2) >> UNSIGNED_INT_BIT_LENGTH);
        if (lane1)
            edp_err("lane1 error:%u \n", lane1);
        lane2 = lane2 + (read_buff[1] & ERR_RATE_DATA_1);
        if (lane2)
            edp_err("lane2 error:%u \n", lane2);
        lane3 = lane3 + ((read_buff[1] & ERR_RATE_DATA_2) >> UNSIGNED_INT_BIT_LENGTH);
        if (lane3)
            edp_err("lane3 error:%u \n", lane3);
    }

    if ((lane0 + lane1 + lane2 + lane3) > ERR_CNT_THD) {
        edp_err("err rate check result is failed\n");
        return 0; // failed
    }
    edp_info("err rate check result success!\n");
    return 1; //success
}

static ssize_t edp_panel_gram_check_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int ret = 0;
	bool checksum_result;

	if (edp_get_panel_on_state()) {
		checksum_result = check_i2c_psr_ram();
		ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n", checksum_result);
	}

	return ret;
}

static ssize_t edp_panel_gram_check_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	if (!buf) {
		edp_err("buf is null\n");
		return 0;
	}

	return count;
}

static ssize_t edp_panel_err_rate_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int ret = 0;
	int test_result = 0;

    if (!buf) {
		edp_err("buf is null\n");
		return 0;
	}
	if (edp_get_panel_on_state()) {
		test_result = query_error_count();
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n", test_result);
	}

	return ret;
}

static bool timeout_check(const char* check_num)
{
    unsigned int res0 = 0;
    const unsigned int result_check = 0x3;

    res0 = tcon_i2c_read_addr(DDRT_TIME_OUT);
    if (res0 != result_check) {
        edp_err("all %s check failed.\n", check_num);
        return false;
    }
    edp_info("all %s check success.\n", check_num);
    return true;
}
 
static bool ddrt_check(unsigned int startAddr, unsigned int test_len)
{
	int i;
    unsigned int ddrt_data_1 = test_len / 0x100 - 1;
    const unsigned int ddrt_data_2 = 0x1;
    const unsigned int ddrt_data_3 = 0x5001;
    const unsigned int ddrt_data_4 = 0x6001;
    int ret;

    send_i2c_seq(g_ddrt_step1, ARRAY_SIZE(g_ddrt_step1));
    send_i2c_seq(g_ddrt_step2, ARRAY_SIZE(g_ddrt_step2));
    send_i2c_seq(g_ddrt_step3, ARRAY_SIZE(g_ddrt_step3));
    send_i2c_seq(g_ddrt_step4, ARRAY_SIZE(g_ddrt_step4));
    send_i2c_seq(g_ddrt_step5, ARRAY_SIZE(g_ddrt_step5));
    /* set startadd & test len & test range */
    ret = tcon_i2c_write_addr(DDRT_ADDR_1, startAddr);
    if (ret < 0)
			edp_warn("write addr failed\n");
    ret = tcon_i2c_write_addr(DDRT_ADDR_2, ddrt_data_1);
    if (ret < 0)
			edp_warn("write addr failed\n");
    ret = tcon_i2c_write_addr(DDRT_ADDR_3, ddrt_data_2);
    if (ret < 0)
			edp_warn("write addr failed\n");
    msleep(20); // timing requirement: delay 20 ms before i2c write
    send_i2c_seq(g_ddrt_step6, ARRAY_SIZE(g_ddrt_step6));

    for (i = 0; i < DDRT_CHECK_TIMES; i++) {
        edp_debug("test %dth\n", i + 1);
        ret = tcon_i2c_write_addr(DDRT_ADDR_4, ddrt_data_3);
        if (ret < 0) {
            edp_warn("write addr failed\n");
            continue;
        }
        msleep(50); // timing requirement: delay 50 ms before i2c write
        if (!timeout_check("0x00000000"))
            return false;
        ret = tcon_i2c_write_addr(DDRT_ADDR_4, ddrt_data_4);
        if (ret < 0) {
            edp_warn("write addr failed\n");
            continue;
        }
        msleep(50); // timing requirement: delay 50 ms before i2c write
        if (!timeout_check("0xFFFFFFFF"))
            return false;
    }
    return true;
}

static ssize_t edp_panel_ddrt_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int ret = 0;
	int test_result = 0;

    if (!buf) {
		edp_err("buf is null\n");
		return 0;
	}
	if (edp_get_panel_on_state()) {
        if (ddrt_check(DDRT_START_ADDR, DDRT_TEST_LEN)) {
		    edp_info("result:pass\n");
		    test_result = 1;
	    } else {
            edp_info("result:fail\n");
            test_result = 0;
        }
        return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n", test_result);
	}

	return 0;
}

static bool edp_crack_check(void)
{
    unsigned int crack_value;

    crack_value = tcon_i2c_read_addr(DDRT_CRACK_ADDR);
    if (crack_value & 0x1) {
	    edp_info("edp crack check fail errcode = %x", crack_value);
	    return false;
    }
	return true;
}

static ssize_t edp_panel_crack_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
    int test_result = 0;

    if (!buf) {
		edp_err("buf is null\n");
		return 0;
	}
    if (edp_get_panel_on_state()) {
        if (edp_crack_check()) {
            edp_info("result:pass\n");
            test_result = 1;
        } else {
            edp_info("result:fail\n");
            test_result = 0;
        }
        return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n", test_result);
	}
	return 0;
}

static ssize_t edp_read_screen_sn(unsigned char *read_buff)
{
    int sn_index = 0;
    int i;
    int count = 0;
    unsigned int value[SN_ADDR_NUM] = { 0 };
    unsigned char num = 0;

    for (sn_index = 0; sn_index < SN_ADDR_NUM; sn_index++) {
        value[sn_index] = tcon_i2c_read_addr(g_sn_addr_list[sn_index]);
        edp_info("value[%d] is %x\n", sn_index, value[sn_index]);

        for (i = 0; i < PANEL_SCREENSN_LEN && value[sn_index] != 0; i++) {
            num = value[sn_index] & PANEL_SCREENSN_MASK;
            value[sn_index] = value[sn_index] >> PANEL_SCREENSN_MOVE_BIT;
            read_buff[count++] = (unsigned char)num;
        }
        mdelay(PANEL_SCREENSN_READ_DELAY_TIME);
    }
    read_buff[count] = '\0';
    return count;
}

static ssize_t edp_panel_screen_sn_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
    unsigned char read_buff[PANEL_SCREENSN_LEN] = { 0 };
    int ret;
    unsigned int read_len;
 
    if (!edp_get_panel_on_state()) {
        edp_err("panel not state on failed\n");
        return 0;
    }
 
    read_len = edp_read_screen_sn(read_buff);
    if (read_len == PANEL_SCREENSN_LEN) {
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%s\n", read_buff);
        if (ret < 0) {
            edp_err("snprintf_s failed\n");
            return 0;
        }
        return ret;
    } else {
        edp_err("edp read sn len err\n");
        return read_len;
    }
    return 0;
}

static ssize_t edp_panel_test_config_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int ret;
    int result = 0;

    if (!buf) {
		edp_err("buf is null\n");
		return 0;
	}
	ret = edp_get_test_config(buf);
	edp_info("buf is %s\n", buf);
	if (ret < 0) {
		edp_err("not find test item\n");
		return 0;
	}

    if (!strncmp(buf, "OVER_CURRENT_DETECTION", strlen("OVER_CURRENT_DETECTION"))) {
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n", result);
		if (ret < 0) {
            edp_err("snprintf_s failed\n");
            return 0;
        }
        return ret;
	}
	if (!strncmp(buf, "OVER_VOLTAGE_DETECTION", strlen("OVER_VOLTAGE_DETECTION"))) {
		ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n", result);
		if (ret < 0) {
            edp_err("snprintf_s failed\n");
            return 0;
        }
        return ret;
	}

	return ret;
}

static ssize_t edp_panel_test_config_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
    if (!buf) {
		edp_err("buf is null\n");
		return 0;
	}
	if (edp_set_test_config(buf) < 0) {
		edp_err("set_test_config failed\n");
        return -EINVAL;
    }

	return count;
}

#ifdef CONFIG_HISYSEVENT
static void tcon_hiview_hisysevent_upload(const char *buf, uint16_t vendor, uint16_t version)
{
    char version_str_temp[VERSION_MAX_SIZE] = { 0 };
    struct hiview_hisysevent *event = NULL;
    int ret = 0;

    if (!buf) {
        edp_err("buf is null\n");
        return;
    }
    if (vendor == 0 || version == 0) {
        edp_err("vendor or version is null");
        return;
    }
    ret = snprintf_s(version_str_temp, VERSION_MAX_SIZE, VERSION_MAX_SIZE - 1,
                    "vendor=0X%04X,version=0X%04X\n", vendor, version);
    if (ret < 0) {
        edp_err("snprintf_s fail %d", ret);
        return;
    }
	event = hisysevent_create("LCD", "TCON_UPDATE", STATISTIC);
	if (!event) {
		edp_err("failed to create event\n");
		return;
	}
	ret = hisysevent_put_string(event, "VERSION", version_str_temp);
	if (ret != 0) {
		edp_err("failed to put value to event, ret=%d\n", ret);
		goto hisysevent_end;
	}
    ret = hisysevent_put_string(event, "RESULT", buf);
	if (ret != 0) {
		edp_err("failed to put value to event, ret=%d\n", ret);
		goto hisysevent_end;
	}
	ret = hisysevent_write(event);
	if (ret < 0)
		edp_err("edp_tcon_hiview_hisysevent fail\n");

hisysevent_end:
	hisysevent_destroy(&event);
}
#endif

ssize_t update_tconic_tool(char *buf, bool main_flag)
{
    const char *fw_name = NULL;
    const struct firmware *fw = NULL;
    uint16_t vendor = 0;
    uint16_t version = 0;
    int ret;

#ifdef EDP_FACTORY_MODE
    ret = check_tcon_firmware(&fw, &vendor, &version, true, EXT_PARTITION);
#else
    ret = check_tcon_firmware(&fw, &vendor, &version, true, main_flag);
#endif
    if (ret) {
        edp_err("check_tcon_firmware fail");
        goto err_firmware;
    }
    ret = update_tconic_fw_request(fw, vendor, version, main_flag);
    if (ret != 0) {
        edp_err("upgrade fail\n");
#ifdef CONFIG_HISYSEVENT
        tcon_hiview_hisysevent_upload("fail", vendor, version);
#endif
        goto err_firmware;
    }
    edp_info("edp tcon upgarde success!!!\n");
#ifdef CONFIG_HISYSEVENT
    tcon_hiview_hisysevent_upload("success", vendor, version);
#endif
    release_firmware(fw);
    ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "edp %s tcon upgarde success!\n",
                                                     main_flag ? "main" : "ext");
    if (ret < 0) {
        edp_err("snprintf_s fail %d", ret);
        return 0;
    }
    return ret;

err_firmware:
    if (fw)
        release_firmware(fw);
    if (ret == TCON_NOT_NEED_UPGRADE) {
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "tcon skip uprage!\n");
    } else {
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "edp %s tcon update fail!\n",
                                                    main_flag ? "main" : "ext");
    }
    if (ret < 0) {
        edp_err("snprintf_s fail %d", ret);
        return 0;
    }

    return ret;
}

ssize_t edp_change_boot(char *buf, unsigned char patition)
{
    int ret;

    if (!buf) {
        edp_err("edp_change_boot buf is null\n");
        return 0;
    }
    if (extra_upgrade_switch_boot(patition)) {
        edp_err("error: change start partitions to %x failed!\n", patition);
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1,
                         "change start partitions to %x failed\n", patition);
    } else {
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "change %x change start partitions success\n", patition);
    }
    if (ret < 0) {
        edp_err("snprintf_s fail %d", ret);
        return 0;
    }
    return ret;
}

static ssize_t edp_check_next_start(char *buf)
{
    uint32_t check_num;
    int ret;

    check_num = tcon_i2c_read_addr(CHECK_CHANGE_PARTITIONS_ADDR);
    if (check_num == CHANGE_MAIN) {
        edp_info("NEXT MAIN\n");
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "NEXT MAIN\n");
    } else if (check_num == CHANGE_EXT) {
        edp_info("NEXT EXT\n");
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "NEXT EXT\n");
    } else {
        edp_info("read fail checksum = %02x\n", check_num);
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "read fail checksum = %02x\n", check_num);
    }
    if (ret < 0) {
        edp_err("snprintf_s fail %d", ret);
        return 0;
    }
    return ret;
}

ssize_t edp_check_now_boot(char *buf)
{
    uint32_t run_type;
    uint32_t temp;
    int ret;

    if (!buf) {
        edp_err("edp_check_now_boot buf is null\n");
        return 0;
    }
    run_type = tcon_i2c_read_addr(PARTITIONS_START_ADDR);
    temp = run_type >> SHORT_BIT_LEN;
    if (temp == 1) {
        edp_info("NOW MAIN\n");
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "NOW MAIN\n");
    } else if (temp == 2) { // 2 is ext partitions
        edp_info("NOW EXT\n");
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "NOW EXT\n");
    } else {
        edp_info("read fail run_type = %02x\n", run_type);
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "read fail run_type = %02x\n", run_type);
    }
    if (ret < 0) {
        edp_err("snprintf_s fail %d", ret);
        return 0;
    }
    return ret;
}

static ssize_t get_bin_vendor(char *buf)
{
    int ret = 0;
    struct bin_vendor_info* bin_vendor = NULL;

    bin_vendor = get_bin_vendor_info();
    if (!bin_vendor) {
        edp_err("bin_vendor is null\n");
        return 0;
    }
    ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1,
        "bin_vendor=%x bin_version=%x\n", bin_vendor->vendor, bin_vendor->version);
    if (ret < 0) {
        edp_err("snprintf_s fail\n");
        return 0;
    }
    return ret;
}

static ssize_t edp_panel_update_extra_tconic_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
    int ret;

    if (!buf) {
        edp_err("buf is null\n");
        return 0;
    }
    mutex_lock(&g_tcon_mutex);
    switch (g_upate_tool) {
        case WAITING_DOING:
            ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "waiting command!\n");
            break;
        case UPDATE_TCON_EXT:
            ret = update_tconic_tool(buf, EXT_PARTITION);
            break;
        case CHANGE_MAIN_BOOT:
            ret = edp_change_boot(buf, CHANGE_MAIN);
            break;
        case CHANGE_EXT_BOOT:
            ret = edp_change_boot(buf, CHANGE_EXT);
            break;
        case CHECK_NEXT_START:
            ret = edp_check_next_start(buf);
            break;
        case CHECK_NOW_BOOT:
            ret = edp_check_now_boot(buf);
            break;
        case UPDATE_TCON_MAIN:
            ret = update_tconic_tool(buf, MAIN_PARTITION);
            break;
        case READ_TCON_BIN_VENDOR:
            ret = get_bin_vendor(buf);
            break;
        default:
            ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "command err\n");
            break;
    }
    mutex_unlock(&g_tcon_mutex);
    if (ret < 0) {
        edp_err("snprintf_s fail %d", ret);
        return 0;
    }
    return ret;
}

static ssize_t edp_panel_update_extra_tconic_store(struct device *dev, struct device_attribute *attr,
                                                   const char *buf, size_t count)
{
    unsigned int tool_value = 0;
    int ret;

    if (!buf) {
        edp_err("buf is null\n");
        return 0;
    }
    edp_info("buf %s", buf);
    ret = kstrtouint(buf, 0, &tool_value);
    if (ret) {
        edp_err("kstrtouint fail!\n");
        return ret;
    }
    mutex_lock(&g_tcon_mutex);
    if (tool_value < TOOL_MAX)
        g_upate_tool = tool_value;
    else
        g_upate_tool = WAITING_DOING;
	mutex_unlock(&g_tcon_mutex);
    edp_info("g_upate_tool %d\n", g_upate_tool);
    return count;
}

static ssize_t edp_panel_ext_update_status_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
    int ret;

    if (!buf) {
        edp_err("ext update status show buf null\n");
        return 0;
    }

    switch (get_update_status()) {
        case UPDATE_WAITING:
            ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "update not start!\n");
            break;
        case UPDATE_SUCESS:
            ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "update success!\n");
            break;
        case UPDATE_FAIL:
            ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "update fail!\n");
            break;
        case UPDATE_DOING:
            ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "updating please wait\n");
            break;
        default:
            ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "INVALID\n");
            break;
    }
    if (ret < 0) {
        edp_err("snprintf_s fail %d", ret);
        return 0;
    }
    return ret;
}

static ssize_t edp_panel_close_tcon_te_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
    int ret = 0;
    unsigned int read_buff = 0;
 
    if (!buf) {
        edp_err("edp_close_tcon_te_show buf is null\n");
        return 0;
    }
 
    if (!edp_get_panel_on_state()) {
        edp_err("panel is not power on\n");
        return 0;
    }

    ret = tcon_i2c_write_addr(TCON_TE_ADDR, CLOSE_TCON_TE_VAL);
    if (ret < 0) {
		edp_err("close tcon TE write addr failed\n");
        return 0;
    }

    read_buff = tcon_i2c_read_addr(TCON_TE_ADDR);
    ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "close tcon te read_buff is %x\n", read_buff);
    if (ret < 0) {
        edp_err("snprintf_s fail\n");
        return 0;
    }
    return ret;
}
 
static ssize_t edp_panel_switch_tcon_fps_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
    int ret = 0;
    unsigned int read_buff = 0;
 
    if (!buf) {
        edp_err("edp_switch_tcon_fram_rate_show buf is null\n");
        return 0;
    }
 
    if (!edp_get_panel_on_state()) {
        edp_err("panel is not power on\n");
        return 0;
    }

    read_buff = tcon_i2c_read_addr(TCON_SWITCH_FPS_ADDR);
    ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "FPS:%d\n", read_buff);
    if (ret < 0) {
        edp_err("snprintf_s fail\n");
        return 0;
    }
    return ret;
}
 
static ssize_t edp_panel_switch_tcon_fps_store(struct device *dev,
    struct device_attribute *attr, const char *buf, size_t count)
{
    int ret = 0;
    unsigned int read_buff = 0;
    unsigned int write_buff = 0;

    if (!buf) {
        edp_err("edp_switch_tcon_fps_stroe buf is null\n");
        return 0;
    }

    if (!edp_get_panel_on_state()) {
        edp_err("panel is not power on\n");
        return 0;
    }

    ret = kstrtouint(buf, STR_TO_UINT_BASE16, &write_buff);
    if (ret) {
        edp_err("kstrtouint fail!ret=%d\n", ret);
        return ret;
    }
    edp_info("write_buff=0x%x\n", write_buff);

    if (write_buff < CLOSE_VDF_FPS_VAL) {
        read_buff = tcon_i2c_read_addr(TCON_VDF_ADDR);
        read_buff &= ~(1 << 0);
        ret = tcon_i2c_write_addr(TCON_VDF_ADDR, read_buff);
        if (ret < 0) {
			edp_warn("write addr failed,close VDF failed\n");
            return 0;
        }
        edp_info("close VDF success!\n");
    }

    ret = tcon_i2c_write_addr(TCON_SWITCH_FPS_ADDR, write_buff);
    if (ret < 0)
		edp_warn("write addr failed,switch fps failed\n");

    ret = tcon_i2c_write_addr(TCON_MASK_SOC_FPS_ADDR, MASKED_SOC_FPS_VAL);
    if (ret < 0)
		edp_warn("write addr failed,masked soc fps failed\n");
 
    return count;
}

static struct edp_fact_ops g_edp_sysfs_fact_ops = {
	.gram_check_show = edp_panel_gram_check_show,
	.gram_check_store = edp_panel_gram_check_store,
	.err_rate_show = edp_panel_err_rate_show,
	.ddrt_show = edp_panel_ddrt_show,
    .crack_show = edp_panel_crack_show,
    .close_tcon_te_show = edp_panel_close_tcon_te_show,
    .switch_tcon_fps_show = edp_panel_switch_tcon_fps_show,
    .switch_tcon_fps_store = edp_panel_switch_tcon_fps_store,
    .screen_sn_show = edp_panel_screen_sn_show,
    .test_config_show = edp_panel_test_config_show,
	.test_config_store = edp_panel_test_config_store,
    .panel_update_extra_tconic_fw_show = edp_panel_update_extra_tconic_show,
    .panel_update_extra_tconic_store = edp_panel_update_extra_tconic_store,
    .panel_ext_update_status_show = edp_panel_ext_update_status_show,
};

int32_t edp_sysfs_fact_init(struct device *dev)
{
	int ret;

    mutex_init(&g_tcon_mutex);
	edp_fact_ops_register(&g_edp_sysfs_fact_ops);
	ret = edp_create_fact_sysfs(&dev->kobj);
	if (ret) {
		edp_err("create sysfs node fail\n");
		return ret;
	}

	return 0;
}

MODULE_AUTHOR("huawei");
MODULE_DESCRIPTION("huawei driver");
MODULE_LICENSE("GPL");
