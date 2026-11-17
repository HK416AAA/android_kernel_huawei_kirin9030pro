/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2016-2025. All rights reserved.
 */

/************************************************************************
* Copyright (c) 2012-2020, FocalTech Systems, Ltd., all rights reserved.
*
* File Name: focaltech_test.h
*
* Author: Focaltech Driver Team
*
* Created: 2016-08-01
*
* Abstract: test entry for all IC
*
************************************************************************/
#ifndef _TEST_LIB_H
#define _TEST_LIB_H

/*****************************************************************************
* Included header files
*****************************************************************************/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/debugfs.h>
#include <asm/uaccess.h>
#include <linux/i2c.h> // iic
#include <linux/delay.h> // msleep
#include <linux/string.h>
#include <asm/unistd.h>
#include <linux/vmalloc.h>
#include <linux/time.h>
#include "../focal_hid_core.h"
#include "focaltech_test_ini.h"
#include "securec.h"

/*****************************************************************************
* Macro definitions using #define
*****************************************************************************/
#define FTS_INI_FILE_PATH                       "/chip_prod/etc/firmware/ts/"
#define FTS_SAVE_FILE_PATH                       "/data/"
#define FTS_CSV_FILE_NAME                       "testdata.csv"
#define FTS_TXT_FILE_NAME                       "testresult.txt"
#define TEST_CONFIG_FILE_NAME                   "FTS_TEST.ini"
#define false 0
#define true  1
#define TEST_ICSERIES_LEN                       (8)
#define TEST_ICSERIES(x)                        ((x) >> TEST_ICSERIES_LEN)

#define TEST_OPEN_MAX_VALUE                     (255)
#define BYTES_PER_TIME                          (32)  /* max:128 */
/* CSV & TXT */
#define CSV_LINE2_BUFFER_LEN                    (1024)
#define CSV_BUFFER_LEN                          (1024 * 80 * 5)
#define TXT_BUFFER_LEN                          (1024 * 80 * 5)

#define TEST_SAVE_FAIL_RESULT                   0

/*-----------------------------------------------------------
Test Status
-----------------------------------------------------------*/
#define RESULT_NULL                             0
#define RESULT_PASS                             1
#define RESULT_NG                               2

#define TX_NUM_MAX                              60
#define RX_NUM_MAX                              100
#define SC_NUM_MAX                  ((TX_NUM_MAX) + (RX_NUM_MAX))
#define NUM_MAX_SC                              (144)
#define KEY_NUM_MAX                             6
#define TEST_ITEM_COUNT_MAX                     32
#define TEST_ITEM_NAME_MAX                      32
#define TEST_SHORT_RES_MAX                      0xFFFF

/*
 * factory test registers
 */
#define ENTER_WORK_FACTORY_RETRIES              5

#define START_SCAN_RETRIES_INCELL               20
#define START_SCAN_RETRIES_DELAY_INCELL         16
#define FACTORY_TEST_RETRY                      50
#define FACTORY_TEST_DELAY                      18
#define FACTORY_TEST_RETRY_DELAY                100

#define DEVIDE_MODE_ADDR                        0x00
#define FTS_WORK_MODE                           0x00
#define FTS_FACTORY_MODE                        0x40


#define REG_FW_VERSION                          0xA6
#define REG_VA_TOUCH_THR                        0x80
#define REG_VKEY_TOUCH_THR                      0x82

#define FACTORY_REG_LINE_ADDR                   0x01
#define FACTORY_REG_CHX_NUM                     0x02
#define FACTORY_REG_CHY_NUM                     0x03
#define FACTORY_REG_CLB                         0x04
#define FACTORY_REG_DATA_SELECT                 0x06
#define FACTORY_REG_RAWBUF_SELECT               0x09
#define FACTORY_REG_KEY_CBWIDTH                 0x0B
#define FACTORY_REG_PARAM_UPDATE_STATE          0x0E
#define FACTORY_REG_PARAM_UPDATE_STATE_TOUCH    0xB5
#define FACTORY_REG_SHORT_TEST_EN               0x0F
#define FACTORY_REG_SHORT_TEST_STATE            0x10
#define FACTORY_REG_LCD_NOISE_START             0x11
#define FACTORY_REG_LCD_NOISE_FRAME             0x12
#define FACTORY_REG_LCD_NOISE_TEST_STATE        0x13
#define FACTORY_REG_LCD_NOISE_TTHR              0x14
#define FACTORY_REG_OPEN_START                  0x15
#define FACTORY_REG_OPEN_STATE                  0x16
#define FACTORY_REG_OPEN_ADDR                   0xCF
#define FACTORY_REG_OPEN_IDLE                   0x03
#define FACTORY_REG_OPEN_BUSY                   0x01
#define FACTORY_REG_CB_ADDR_H                   0x18
#define FACTORY_REG_CB_ADDR_L                   0x19
#define FACTORY_REG_ORDER_ADDR_H                0x1A
#define FACTORY_REG_ORDER_ADDR_L                0x1B
#define FACTORY_REG_LCD_NOISE_STATE             0x1E
#define FACTORY_REG_KEYSHORT_EN                 0x2E
#define FACTORY_REG_KEYSHORT_STATE              0x2F

#define FACTORY_REG_LEFT_KEY                    0x1E
#define FACTORY_REG_RIGHT_KEY                   0x1F
#define FACTORY_REG_OPEN_REG20                  0x20
#define FACTORY_REG_OPEN_REG21                  0x21
#define FACTORY_REG_OPEN_REG22                  0x22
#define FACTORY_REG_OPEN_REG23                  0x23
#define FACTORY_REG_OPEN_REG2E                  0x2E
#define FACTORY_REG_OPEN_REG86                  0x86
#define FACTORY_REG_K1                          0x31
#define FACTORY_REG_K2                          0x32
#define FACTORY_REG_RAWDATA_ADDR                0x6A
#define FACTORY_REG_ORDER_ADDR                  0x6C
#define FACTORY_REG_CB_ADDR                     0x6E
#define FACTORY_REG_SHORT_ADDR                  0x89
#define FACTORY_REG_RAWDATA_TEST_EN             0x9E
#define FACTORY_REG_CB_TEST_EN                  0x9F
#define FACTORY_REG_OPEN_TEST_EN                0xA0
#define FACTORY_REG_RAWDATA_TARGET              0xCA


/* mc_sc */
#define FACTORY_REG_FRE_LIST                    0x0A
#define FACTORY_REG_DATA_TYPE                   0x5B
#define FACTORY_REG_NORMALIZE                   0x16
#define FACTORY_REG_RAWDATA_ADDR_MC_SC          0x36
#define FACTORY_REG_PATTERN                     0x53
#define FACTORY_REG_NOMAPPING                   0x54
#define FACTORY_REG_CHX_NUM_NOMAP               0x55
#define FACTORY_REG_CHY_NUM_NOMAP               0x56
#define FACTORY_REG_WC_SEL                      0x09
#define FACTORY_REG_HC_SEL                      0x0F
#define FACTORY_REG_MC_SC_MODE                  0x44
#define FACTORY_REG_MC_SC_CB_ADDR_OFF           0x45
#define FACTORY_REG_MC_SC_CB_H_ADDR_OFF         0x49
#define FACTORY_REG_MC_SC_CB_ADDR               0x4E
#define FACTROY_REG_SHORT_TEST_EN               0x07
#define FACTROY_REG_SHORT_CA                    0x01
#define FACTROY_REG_SHORT_CC                    0x02
#define FACTROY_REG_SHORT_CG                    0x03
#define FACTROY_REG_SHORT_OFFSET                0x04
#define FACTROY_REG_SHORT_AB_CH                 0x58
#define FACTROY_REG_SHORT_RES_LEVEL             0x5A
#define FACTORY_REG_GCB                         0xBD
#define FACTORY_REG_SHORT_ADDR_MC               0xF4
#define FACTORY_REG_FIR                         0xFB

#define FACTROY_REG_SCAP_CFG                    0x58
#define FACTROY_REG_SCAP_GCB_TX                 0xBC
#define FACTROY_REG_SCAP_GCB_RX                 0xBE
#define FACTROY_REG_CB_BUF_SEL                  0xBF

#define FACTROY_REG_SHORT2_TEST_EN              0xC0
#define FACTROY_REG_SHORT2_CA                   0x01
#define FACTROY_REG_SHORT2_CC                   0x02
#define FACTROY_REG_SHORT2_CG                   0x03
#define FACTROY_REG_SHORT2_OFFSET               0x04
#define FACTROY_REG_SHORT2_RES_LEVEL            0xC1
#define FACTROY_REG_SHORT2_DEALY                0xC2
#define FACTROY_REG_SHORT2_TEST_STATE           0xC3
#define FACTORY_REG_SHORT2_ADDR_MC              0xC4
#define FACTROY_REG_SHORT2_AB_CH                0xC6

/* sc */
#define FACTORY_REG_SCAN_ADDR2                  0x08
#define FACTORY_REG_CH_NUM_SC                   0x0A
#define FACTORY_REG_KEY_NUM_SC                  0x0B
#define FACTORY_REG_SC_CB_ADDR_OFF              0x33
#define FACTORY_REG_SC_CB_ADDR                  0x39
#define FACTORY_REG_RAWDATA_SADDR_SC            0x34
#define FACTORY_REG_RAWDATA_ADDR_SC             0x35
#define FACTORY_REG_CB_SEL                      0x41
#define FACTORY_REG_FMODE                       0xAE

#define TEST_RETVAL_00                          0x00
#define TEST_RETVAL_AA                          0xAA

#define FTS_MAX_SORT_SC                         32768
#define FTS_MIN_SORT_SC                         0

/*****************************************************************************
* Global variable or extern global variabls/functions
*****************************************************************************/
extern struct test_funcs test_func_ft5452;


extern struct fts_test *fts_ftest;

#define fts_malloc_r(p, size) do { \
    if (NULL == (p)) { \
        (p) = fts_malloc(size); \
        if (NULL == (p)) { \
            return -ENOMEM; \
        } \
    } \
} while (0)

#define fts_free(p) do { \
    if (p) { \
        fts_free_proc(p); \
        p = NULL; \
    } \
} while (0)

#define CSV_SUPPORT             1
#define TXT_SUPPORT             1

#define FTS_TEST_DBG(fmt, args...) do { \
printk("[FTS_TS][TEST]%s:"fmt"\n",  __func__, ##args); \
} while (0)

#define FTS_TEST_FUNC_ENTER() do { \
    printk("[FTS_TS][TEST]%s: Enter\n", __func__); \
} while (0)

#define FTS_TEST_FUNC_EXIT()  do { \
    printk("[FTS_TS][TEST]%s: Exit(%d)\n", __func__, __LINE__); \
} while (0)

#define FTS_TEST_INFO(fmt, args...) do { \
    printk(KERN_ERR "[FTS_TS/I][TEST]%s:"fmt"\n", __func__, ##args); \
} while (0)

#define FTS_TEST_ERROR(fmt, args...) do { \
    printk(KERN_ERR "[FTS_TS/E][TEST]%s:"fmt"\n", __func__, ##args); \
} while (0)

#define FTS_TEST_SAVE_INFO(fmt, args...) do { \
    if (fts_ftest->testresult) { \
        fts_ftest->testresult_len += snprintf_s( \
        fts_ftest->testresult + fts_ftest->testresult_len, \
        TXT_BUFFER_LEN - fts_ftest->testresult_len, \
        TXT_BUFFER_LEN - fts_ftest->testresult_len, \
        fmt, ##args); \
    } \
} while (0)

#define FTS_TEST_SAVE_ERR(fmt, args...)  do { \
    if (fts_ftest->testresult && (fts_ftest->testresult_len < TXT_BUFFER_LEN)) { \
        fts_ftest->testresult_len += snprintf_s( \
        fts_ftest->testresult + fts_ftest->testresult_len, \
        TXT_BUFFER_LEN - fts_ftest->testresult_len, \
        TXT_BUFFER_LEN - fts_ftest->testresult_len, \
        fmt, ##args); \
    } \
    printk(KERN_ERR "[FTS_TS/E][TEST]%s:"fmt"\n", __func__, ##args); \
} while (0)
#endif
