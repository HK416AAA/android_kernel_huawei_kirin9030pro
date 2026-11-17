/*
 * echub_battery_diagnosis.c
 *
 * echub_battery_diagnosis driver for echub
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */

#include <linux/fs.h>
#include <securec.h>
#ifdef CONFIG_HISYSEVENT
#include <dfx/hiview_hisysevent.h>
#endif
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include "echub_battery.h"
#include "ospm_printf.h"

#define READ_BATT_FAULTDATA_CMD      0x02F4
#define SEND_BATT_THRESHOLD_CMD      0x02F5
#define BATT_FAULTDATA_COUNT         8
#define BATT_FAULTDATA_LEN           128

#define CVT_VERSION "1.01"

/* !!! this array must be same order as struct battery_fault_info !!! */
static char *g_batt_faultdata_hisys[] = {
    "TEMP_MAX_0",
    "TEMP_MIN_0",
    "TEMP_MAX_1",
    "TEMP_MIN_1",
    "VCELL1_0",
    "VCELL2_0",
    "VCELL3_0",
    "VCELL4_0",
    "VCELL1_1",
    "VCELL2_1",
    "VCELL3_1",
    "VCELL4_1",
    "VCELL_MIN_0",
    "VCELL_MAX_0",
    "VCELL_MIN_1",
    "LCDTIME",
    "CVT_0",
    "CVT1_1",
    "CVT2_1",
    "CVT3_1",
    "CVT4_1",
    "CVT1_2",
    "CVT2_2",
    "CVT3_2",
    "CVT4_2",
    "CVTMAX",
    "CVTMIN",
    "CVT_DELTA_MAX_1",
    "CVT_DELTA_MAX_2",
    "VCELL1_RANGE",
    "VCELL2_RANGE",
    "VCELL3_RANGE",
    "VCELL4_RANGE",
    "VCELL_RANGE_MAX",
    "VCELL_RANGE_DELTA_MAX",
    "VCELL_DELTA_MAX",
    "TEMP_DELTA_MAX",
    "CURRENT_MIN",
    "CYCLE",
    "SOH",
    "FCC",
    "DESIGN_CAPACITY",
    "CHARGE_NUMBER",
    "CELL_NUMBER_0",
    "CELL_NUMBER_1",
    "CELL_NUMBER_2",
    "CELL_NUMBER_3"
};

static int get_batt_fault_data(struct echub_batt_device_info *di, int data_index, u8 *databuf, int buflen)
{
    int ret;
    unsigned char wb;
    unsigned char rb[BATT_FAULTDATA_LEN] = {0};

    if (!di || !databuf)
        return -EINVAL;

    wb = data_index;
    ret = di->echub_dev->transfer_func(di->echub_dev, READ_BATT_FAULTDATA_CMD, &wb, 1, rb, BATT_FAULTDATA_LEN);
    if (ret) {
        echub_err("get batery fault data failed, ret=%d\n", ret);
        return -1;
    }

    ret = memcpy_s(databuf, buflen, rb, BATT_FAULTDATA_LEN);
    return ret;
}

#ifdef CONFIG_HISYSEVENT
static int send_faultdata_hiview(u8 *databuf, int buflen)
{
    struct hiview_hisysevent *event = NULL;
	int ret = 0;
	int write_len = 0;
    battery_fault_info *faultdata;
    u16 *tempbuf;

    if (!databuf)
        return -EINVAL;

    event = hisysevent_create("BATTERY", "PC_CHARGETIME_PARAMETER", STATISTIC);
    if (event == NULL) {
		echub_err("failed to create BATTERY PC_CHARGETIME_PARAMETER event\n");
		return -1;
	}

    faultdata = (battery_fault_info *)databuf;
    ret = hisysevent_put_integer(event, "POWER_0", faultdata->power_0);
    if (ret != 0) {
		echub_err("failed to put key POWER_0 to event, ret=%d\n", ret);
		goto hisysevent_end;
	}

    tempbuf = (u16 *)databuf + 3; // 3: u16 magic + u32 power_0
    for (int i = 0; i < sizeof(g_batt_faultdata_hisys) / sizeof(g_batt_faultdata_hisys[0]); i++) {
        ret = hisysevent_put_integer(event, g_batt_faultdata_hisys[i], tempbuf[i]);
        if (ret != 0) {
            echub_err("failed to put key %s to event, ret=%d\n", g_batt_faultdata_hisys[i], ret);
            goto hisysevent_end;
        }
    }

    ret = hisysevent_put_integer(event, "CHG_START_TIME", faultdata->chgStartTime);
    if (ret != 0) {
		echub_err("failed to put key CHG_START_TIME to event, ret=%d\n", ret);
		goto hisysevent_end;
	}

    ret = hisysevent_put_integer(event, "CHG_END_TIME", faultdata->chgEndTime);
    if (ret != 0) {
		echub_err("failed to put key CHG_END_TIME to event, ret=%d\n", ret);
		goto hisysevent_end;
	}

    ret = hisysevent_put_string(event, "CVT_VERSION", CVT_VERSION);
    if (ret != 0) {
		echub_err("failed to put key CVT_VERSION to event, ret=%d\n", ret);
		goto hisysevent_end;
	}

    write_len = hisysevent_write(event);
	if (write_len < 0)
		echub_err("failed to write to event, write_len=%d\n", write_len);

hisysevent_end:
	hisysevent_destroy(&event);
    return ret;
}
#endif

static int faultdata_to_event_buf(u8 *data, u8 *buf, int buflen)
{
    battery_fault_info *faultdata = NULL;

    faultdata = (battery_fault_info *)data;
    return snprintf_s(buf, buflen, buflen - 1,
		"BSOH_EVT=EVT_EC_CVT@cycle:%d,Vcell_delta_max:%d,Temp_delta_max:%d,SOH:%d,LcdTime:%d,CVT_delta_max_1:%d,"
        "CVT_delta_max_2:%d,Vcell_range_delta_max:%d,CVTmin:%d,CVTmax:%d,Cell_Number_0:%d,Cell_Number_1:%d,"
        "Cell_Number_2:%d,Cell_Number_3:%d,Current_min:%d,CVT_0:%d\n",
		faultdata->cycle, faultdata->vcell_delta_max, faultdata->temp_delta_max, faultdata->soh, faultdata->lcdTime,
        faultdata->cvt_delta_max_1, faultdata->cvt_delta_max_2, faultdata->vcell_rang_delta_max, faultdata->cvt_min,
        faultdata->cvt_max, faultdata->cell_number_x[0], faultdata->cell_number_x[1], faultdata->cell_number_x[2],
        faultdata->cell_number_x[3], faultdata->current_min, faultdata->cvt_0);
}

static int send_faultdata_batterycare(u8 *databuf, int datalen)
{
    struct power_event_notify_data notify_data;
    char buf[POWER_EVENT_NOTIFY_SIZE] = { 0 };
	int len;

    if (!databuf)
        return -EINVAL;

    echub_err("%s: \n", __func__);
    len = faultdata_to_event_buf(databuf, buf, POWER_EVENT_NOTIFY_SIZE);
    if (len < 0) {
        echub_err("dump uevent buf error\n");
        return -1;
    }

    echub_info("faultdata to batterycare: %s\n", buf);
	notify_data.event_len = len;
	notify_data.event = buf;
	power_event_report_uevent(&notify_data);
    return 0;
}

void echub_battery_diagnosis_entry(struct echub_batt_device_info *di)
{
    int ret;
    u8 databuf[BATT_FAULTDATA_LEN] = {0};
    if (!di) {
        echub_err("echub battery di is null\n");
        return;
    }

    for (int i = 0; i < BATT_FAULTDATA_COUNT; i++) {
        ret = get_batt_fault_data(di, i, databuf, BATT_FAULTDATA_LEN);
        if (ret) {
            echub_err("get batery fault data (block %d ) failed\n", i);
            return;
        }
#ifdef CONFIG_HISYSEVENT
        ret = send_faultdata_hiview(databuf, BATT_FAULTDATA_LEN);
        if (ret)
            echub_err("send hiview batery fault data (block %d ) failed\n", i);
#endif
        ret = send_faultdata_batterycare(databuf, BATT_FAULTDATA_LEN);
        if (ret)
            echub_err("send batterycare fault data (block %d ) failed\n", i);
    }
}
