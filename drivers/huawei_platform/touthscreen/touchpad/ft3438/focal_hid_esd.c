/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2016-2025. All rights reserved.
 */

/*
 *
 * FocalTech TouchScreen driver.
 *
 * Copyright (c) 2012-2020, FocalTech Systems, Ltd., all rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

/*****************************************************************************
*
* File Name: focal_hid_esd.c
*
*    Author: Focaltech Driver Team
*
*   Created: 2016-08-03
*
*  Abstract: ESD check function
*
*   Version: v1.0
*
* Revision History:
*        v1.0:
*            First release. By luougojin 2016-08-03
*        v1.1: By luougojin 2017-02-15
*            1. Add LCD_ESD_PATCH to control idc_esdcheck_lcderror
*****************************************************************************/

/*****************************************************************************
* Included header files
*****************************************************************************/
#include "focal_hid_core.h"
#define FTS_ESDCHECK_EN                         0

/*****************************************************************************
* Private constant and macro definitions using #define
*****************************************************************************/
#define ESDCHECK_WAIT_TIME              1000    /* ms */
#define LCD_ESD_PATCH                   0
#define ESDCHECK_INTRCNT_MAX            2
#define ESD_INTR_INTERVALS              200    /* unit:ms */

/*****************************************************************************
* Private enumerations, structures and unions using typedef
*****************************************************************************/
struct fts_esdcheck_st {
    u8  mode                : 1;    /* 1- need check esd 0- no esd check */
    u8  suspend             : 1;
    u8  proc_debug          : 1;    /* apk or adb use */
    u8  intr                : 1;    /* 1- Interrupt trigger */
    u8  unused              : 4;
    u8  intr_cnt;
    u8  flow_work_hold_cnt;  /* Flow Work Cnt(reg0x91) keep a same value for x times. >=5 times is ESD, need reset */
    u8  flow_work_cnt_last;  /* Save Flow Work Cnt(reg0x91) value */
    u8  flow_work_cnt_cur;
    u8  flow_work_lcd_esd;
    u32 hardware_reset_cnt;
    u32 nack_cnt;
    u32 dataerror_cnt;
    struct mutex esd_mutex;
};

/*****************************************************************************
* Static variables
*****************************************************************************/
static struct fts_esdcheck_st fts_esdcheck_data;

/*****************************************************************************
* Global variable or extern global variabls/functions
*****************************************************************************/

/*****************************************************************************
* Static function prototypes
*****************************************************************************/

/*****************************************************************************
* functions body
*****************************************************************************/
#if LCD_ESD_PATCH
int lcd_need_reset = 0;
int idc_esdcheck_lcderror(void)
{
    mutex_lock(&fts_esdcheck_data.esd_mutex);
    if (fts_esdcheck_data.flow_work_lcd_esd == 0x55) {
    FTS_INFO("LCD ESD, need execute LCD reset");
        lcd_need_reset = 1;
        fts_esdcheck_data.flow_work_lcd_esd = 0;
    }
    mutex_unlock(&fts_esdcheck_data.esd_mutex);
    return 0;
}
#endif

int fts_update_esd_value(u8 tp_esd_value, u8 lcd_esd_value)
{
    mutex_lock(&fts_esdcheck_data.esd_mutex);
    fts_esdcheck_data.flow_work_cnt_cur = tp_esd_value;
    fts_esdcheck_data.flow_work_lcd_esd = lcd_esd_value;
    mutex_unlock(&fts_esdcheck_data.esd_mutex);
    return 0;
}


int fts_recovery_state(struct fts_hid_data *ts_data)

{
    FTS_FUNC_ENTER();
    /* wait tp stable */
    focal_wait_tp_to_valid();

    if (ts_data->esd_support && !ts_data->suspended) {
        FTS_DEBUG("esd recovery...");
        focal_esdcheck_switch(fts_hid_data, ENABLE);
    }
    FTS_FUNC_EXIT();
    return 0;
}


static int fts_esdcheck_tp_reset(struct fts_hid_data *ts_data)
{
    FTS_FUNC_ENTER();

    fts_esdcheck_data.flow_work_hold_cnt = 0;
    fts_esdcheck_data.hardware_reset_cnt++;

    fts_hw_reset(FTS_DELAY_MS_200);
    fts_recovery_state(fts_hid_data);
    FTS_FUNC_EXIT();
    return 0;
}

/*****************************************************************************
*  Name: get_flow_cnt
*  Brief: Read flow cnt(0x91)
*  Input: NA
*  Output: NA
*  Return:  1(true) - Reg 0x91(flow cnt) abnormal: hold a value for 5 times
*           0(false) - Reg 0x91(flow cnt) normal
*****************************************************************************/
static bool get_flow_cnt(struct fts_hid_data *ts_data)
{
    mutex_lock(&fts_esdcheck_data.esd_mutex);
    if (fts_esdcheck_data.flow_work_cnt_cur == fts_esdcheck_data.flow_work_cnt_last) {
        FTS_DEBUG("reg0x91,val:%x,last:%x", fts_esdcheck_data.flow_work_cnt_cur,
                  fts_esdcheck_data.flow_work_cnt_last);
        fts_esdcheck_data.flow_work_hold_cnt++;
    } else {
        fts_esdcheck_data.flow_work_hold_cnt = 0;
    }

    fts_esdcheck_data.flow_work_cnt_last = fts_esdcheck_data.flow_work_cnt_cur;
    mutex_unlock(&fts_esdcheck_data.esd_mutex);
    /* Flow Work Cnt keep a value for 5 times, need execute TP reset */
    if (fts_esdcheck_data.flow_work_hold_cnt >= 5) {
        FTS_DEBUG("reg0x91 keep a value for 5 times, need execute TP reset");
        return true;
    }

    return false;
}

static int esdcheck_algorithm(struct fts_hid_data *ts_data)
{
    bool    hardware_reset = 0;
    unsigned long intr_timeout = msecs_to_jiffies(ESD_INTR_INTERVALS);

    /* 1. esdcheck is interrupt, then return */
    intr_timeout += ts_data->intr_jiffies;
    if (time_before(jiffies, intr_timeout)) {
        return 0;
    }

    /* 2. check power state, if suspend, no need check esd */
    if (fts_esdcheck_data.suspend == 1) {
        FTS_DEBUG("In suspend, not check esd");
        /* because in suspend state, adb can be used, when upgrade FW, will
         * active ESD check(active = 1); But in suspend, then will don't
         * queue_delayed_work, when resume, don't check ESD again
         */
        return 0;
    }

    /* 3. check fts_esdcheck_data.proc_debug state, if 1-proc busy, no need check esd */
    if (fts_esdcheck_data.proc_debug == 1) {
        FTS_INFO("In apk/adb command mode, not check esd");
        return 0;
    }

    /* 6. get Flow work cnt: 0x91 If no change for 5 times, then ESD and reset */
    hardware_reset = get_flow_cnt(ts_data);
    /* 7. If need hardware reset, then handle it here */
    if (hardware_reset == 1) {
        FTS_DEBUG("NoACK=%d, Error Data=%d, Hardware Reset=%d",
                  fts_esdcheck_data.nack_cnt,
                  fts_esdcheck_data.dataerror_cnt,
                  fts_esdcheck_data.hardware_reset_cnt);
        fts_esdcheck_tp_reset(ts_data);
    }

    return 0;
}

static void esdcheck_func(struct work_struct *work)
{
    struct fts_hid_data *ts_data = container_of(work,
                                  struct fts_hid_data, esdcheck_work.work);

    if (ts_data->esd_support && fts_esdcheck_data.mode) {
#if LCD_ESD_PATCH
        idc_esdcheck_lcderror();
#endif
        esdcheck_algorithm(ts_data);
        queue_delayed_work(ts_data->ts_workqueue, &ts_data->esdcheck_work,
                           msecs_to_jiffies(ESDCHECK_WAIT_TIME));
    }
}

/*****************************************************************************
*  Name: fts_esdcheck_proc_busy
*  Brief: When APK or ADB command access TP via driver, then need set proc_debug,
*         then will not check ESD.
*  Input: NA
*  Output: NA
*  Return: NA
*****************************************************************************/
void focal_esdcheck_proc_busy(struct fts_hid_data *ts_data, bool proc_debug)
{
    if (ts_data->esd_support) {
        fts_esdcheck_data.proc_debug = proc_debug;
    }
}

/*****************************************************************************
*  Name: fts_esdcheck_switch
*  Brief: FTS esd check function switch.
*  Input:   enable:  1 - Enable esd check
*                    0 - Disable esd check
*  Output: NA
*  Return: NA
*****************************************************************************/
void focal_esdcheck_switch(struct fts_hid_data *ts_data, bool enable)
{
    if (ts_data->esd_support) {
        FTS_FUNC_ENTER();
        if (fts_esdcheck_data.mode == ENABLE) {
            if (enable) {
                FTS_DEBUG("ESD check start");
                fts_esdcheck_data.flow_work_hold_cnt = 0;
                fts_esdcheck_data.flow_work_cnt_last = 0;
                fts_esdcheck_data.intr = 0;
                fts_esdcheck_data.intr_cnt = 0;
                fts_hid_write_reg(0x9B, 1);
                queue_delayed_work(ts_data->ts_workqueue,
                                   &ts_data->esdcheck_work,
                                   msecs_to_jiffies(ESDCHECK_WAIT_TIME));
            } else {
                FTS_DEBUG("ESD check stop");
                cancel_delayed_work_sync(&ts_data->esdcheck_work);
                fts_hid_write_reg(0x9B, 0);
            }
        }
        FTS_FUNC_EXIT();
    }
}

void focal_esdcheck_suspend(struct fts_hid_data *ts_data)
{
    FTS_FUNC_ENTER();
    focal_esdcheck_switch(ts_data, DISABLE);
    fts_esdcheck_data.suspend = 1;
    fts_esdcheck_data.intr = 0;
    fts_esdcheck_data.intr_cnt = 0;
    FTS_FUNC_EXIT();
}

void focal_esdcheck_resume(struct fts_hid_data *ts_data)
{
    FTS_FUNC_ENTER();
    focal_esdcheck_switch(ts_data, ENABLE);
    fts_esdcheck_data.suspend = 0;
    fts_esdcheck_data.intr = 0;
    fts_esdcheck_data.intr_cnt = 0;
    FTS_FUNC_EXIT();
}

static ssize_t fts_esdcheck_store(
    struct device *dev,
    struct device_attribute *attr, const char *buf, size_t count)
{
    mutex_lock(&fts_hid_data->debug_lock);
    if (FTS_SYSFS_ECHO_ON(buf)) {
        FTS_DEBUG("enable esdcheck");
        fts_hid_data->esd_support = ENABLE;
        focal_esdcheck_switch(fts_hid_data, ENABLE);
    } else if (FTS_SYSFS_ECHO_OFF(buf)) {
        FTS_DEBUG("disable esdcheck");
        focal_esdcheck_switch(fts_hid_data, DISABLE);
        fts_hid_data->esd_support = DISABLE;
    }
    mutex_unlock(&fts_hid_data->debug_lock);

    return count;
}

static ssize_t fts_esdcheck_show(
    struct device *dev, struct device_attribute *attr, char *buf)
{
    int count;

    mutex_lock(&fts_hid_data->debug_lock);
    count = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE, "Esd check: %s\n", \
                       fts_hid_data->esd_support ? "On" : "Off");
    mutex_unlock(&fts_hid_data->debug_lock);

    return count;
}

/* sysfs esd node
 *   read example: cat  fts_esd_mode        ---read esd mode
 *   write example:echo 01 > fts_esd_mode   ---make esdcheck enable
 *
 */
static DEVICE_ATTR(fts_esd_mode, S_IRUGO | S_IWUSR, fts_esdcheck_show, fts_esdcheck_store);

static struct attribute *fts_esd_mode_attrs[] = {

    &dev_attr_fts_esd_mode.attr,
    NULL,
};

static struct attribute_group fts_esd_group = {
    .attrs = fts_esd_mode_attrs,
};

static int fts_create_esd_sysfs(struct device *dev)
{
    int ret = 0;

    ret = sysfs_create_group(&dev->kobj, &fts_esd_group);
    if (ret != 0) {
        FTS_ERROR("fts_create_esd_sysfs(sysfs) create fail");
        sysfs_remove_group(&dev->kobj, &fts_esd_group);
        return ret;
    }
    return 0;
}

static void fts_esd_work(struct work_struct *work)
{
    FTS_FUNC_ENTER();
    if (!fts_hid_data->fw_loading) {
        FTS_INFO("focal_esdcheck_switch");
        focal_esdcheck_switch(fts_hid_data, ENABLE);
    }
    FTS_FUNC_EXIT();
}


int focal_esdcheck_init(struct fts_hid_data *ts_data)
{
    FTS_FUNC_ENTER();

    if (ts_data->ts_workqueue) {
        INIT_DELAYED_WORK(&ts_data->esdcheck_work, esdcheck_func);
    } else {
        FTS_ERROR("fts workqueue is NULL, can't run esd check function");
        return -EINVAL;
    }

    memset_s((u8 *)&fts_esdcheck_data, sizeof(struct fts_esdcheck_st), 0, sizeof(struct fts_esdcheck_st));

    mutex_init(&fts_esdcheck_data.esd_mutex);
    fts_esdcheck_data.mode = ENABLE;
    fts_esdcheck_data.intr = 0;
    fts_esdcheck_data.intr_cnt = 0;
    fts_create_esd_sysfs(&ts_data->hdev->dev);
    ts_data->esd_support = FTS_ESDCHECK_EN;
    INIT_WORK(&ts_data->esd_work, fts_esd_work);
    queue_work(ts_data->ts_workqueue, &ts_data->esd_work);
    FTS_FUNC_EXIT();
    return 0;
}

int focal_esdcheck_exit(struct fts_hid_data *ts_data)
{
    fts_esdcheck_data.mode = DISABLE;
    ts_data->esd_support = DISABLE;
    fts_hid_write_reg(0x9B, 0);
    cancel_delayed_work_sync(&ts_data->esdcheck_work);
    sysfs_remove_group(&ts_data->dev->kobj, &fts_esd_group);
    return 0;
}

