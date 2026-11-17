/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2016-2025. All rights reserved.
 */

/************************************************************************
* Copyright (c) 2012-2020, FocalTech Systems, Ltd., all rights reserved.
*
* File Name: focaltech_test_struct.h
*
* Author: Focaltech Driver Team
*
* Created: 2016-08-01
*
* Abstract: test entry for all IC
*
************************************************************************/
#ifndef _TEST_LIB_STRUCT_H
#define _TEST_LIB_STRUCT_H

/*****************************************************************************
* Included header files
*****************************************************************************/

#include "focaltech_test.h"

/*****************************************************************************
* enumerations, structures and unions
*****************************************************************************/
struct item_info {
    char name[TEST_ITEM_NAME_MAX];
    int code;
    int *data;
    int datalen;
    int result;
    int mc_sc;
    int key_support;
};

struct fts_test_data {
    int item_count;
    struct item_info info[TEST_ITEM_COUNT_MAX];
};

/* incell */
struct incell_testitem {
    u32 short_test                  : 1;
    u32 open_test                   : 1;
    u32 cb_test                     : 1;
    u32 rawdata_test                : 1;
    u32 lcdnoise_test               : 1;
    u32 keyshort_test               : 1;
    u32 mux_open_test               : 1;
};

struct incell_threshold_b {
    int short_res_min;
    int short_res_vk_min;
    int open_cb_min;
    int open_k1_check;
    int open_k1_value;
    int open_k2_check;
    int open_k2_value;
    int cb_min;
    int cb_max;
    int cb_vkey_check;
    int cb_min_vk;
    int cb_max_vk;
    int rawdata_min;
    int rawdata_max;
    int rawdata_vkey_check;
    int rawdata_min_vk;
    int rawdata_max_vk;
    int lcdnoise_frame;
    int lcdnoise_coefficient;
    int lcdnoise_coefficient_vkey;
    int open_diff_min;
    int open_diff_max;
    int open_nmos;
    int keyshort_k1;
    int keyshort_cb_max;
    int rawdata2_min;
    int rawdata2_max;
    int mux_open_cb_min;
    int open_delta_V;
};

struct incell_threshold {
    struct incell_threshold_b basic;
    int *rawdata_min;
    int *rawdata_max;
    int *rawdata2_min;
    int *rawdata2_max;
    int *cb_min;
    int *cb_max;
};

struct incell_test {
    struct incell_threshold thr;
    union {
        int tmp;
        struct incell_testitem item;
    } u;
};

/* mc_sc */
enum mapping_type {
    MAPPING = 0,
    NO_MAPPING = 1,
};

struct mc_sc_testitem {
    u32 rawdata_test                : 1;
    u32 rawdata_uniformity_test     : 1;
    u32 scap_cb_test                : 1;
    u32 scap_rawdata_test           : 1;
    u32 short_test                  : 1;
    u32 panel_differ_test           : 1;
    u32 noise_test                  : 1;
    u32 mcap_cmb_test               : 1;
    u32 fw_version_test             : 1;
};

struct mc_sc_threshold_b {
    int rawdata_h_min;
    int rawdata_h_max;
    int rawdata_set_hfreq;
    int rawdata_l_min;
    int rawdata_l_max;
    int rawdata_set_lfreq;
    int uniformity_check_tx;
    int uniformity_check_rx;
    int uniformity_check_min_max;
    int uniformity_tx_hole;
    int uniformity_rx_hole;
    int uniformity_min_max_hole;
    int scap_cb_off_min;
    int scap_cb_off_max;
    int scap_cb_wp_off_check;
    int scap_cb_on_min;
    int scap_cb_on_max;
    int scap_cb_wp_on_check;
    int scap_rawdata_off_min;
    int scap_rawdata_off_max;
    int scap_rawdata_wp_off_check;
    int scap_rawdata_on_min;
    int scap_rawdata_on_max;
    int scap_rawdata_wp_on_check;
    int short_cg;
    int short_cc;
    int panel_differ_min;
    int panel_differ_max;
    int scap_cb_hi_min;
    int scap_cb_hi_max;
    int scap_cb_hi_check;
    int scap_rawdata_hi_min;
    int scap_rawdata_hi_max;
    int scap_rawdata_hi_check;
    int scap_cb_hov_min;
    int scap_cb_hov_max;
    int scap_cb_hov_check;
    int scap_rawdata_hov_min;
    int scap_rawdata_hov_max;
    int scap_rawdata_hov_check;

    int scap_cb_on_gcb_min;
    int scap_cb_on_gcb_max;
    int scap_cb_off_gcb_min;
    int scap_cb_off_gcb_max;
    int scap_cb_hi_gcb_min;
    int scap_cb_hi_gcb_max;
    int scap_cb_on_cf_min;
    int scap_cb_on_cf_max;
    int scap_cb_off_cf_min;
    int scap_cb_off_cf_max;
    int scap_cb_hi_cf_min;
    int scap_cb_hi_cf_max;

    int mcap_cmb_min;
    int mcap_cmb_max;

    int noise_max;
    int fw_version;
};

struct mc_sc_threshold {
    struct mc_sc_threshold_b basic;
    int *rawdata_h_min;
    int *rawdata_h_max;
    int *rawdata_l_min;
    int *rawdata_l_max;
    int *tx_linearity_max;
    int *tx_linearity_min;
    int *rx_linearity_max;
    int *rx_linearity_min;
    int *scap_cb_off_min;
    int *scap_cb_off_max;
    int *scap_cb_on_min;
    int *scap_cb_on_max;
    int *scap_cb_hi_min;
    int *scap_cb_hi_max;
    int *scap_cb_hov_min;
    int *scap_cb_hov_max;
    int *scap_rawdata_off_min;
    int *scap_rawdata_off_max;
    int *scap_rawdata_on_min;
    int *scap_rawdata_on_max;
    int *scap_rawdata_hi_min;
    int *scap_rawdata_hi_max;
    int *scap_rawdata_hov_min;
    int *scap_rawdata_hov_max;
    int *panel_differ_min;
    int *panel_differ_max;

    int *scap_cb_on_cf_min;
    int *scap_cb_on_cf_max;
    int *scap_cb_off_cf_min;
    int *scap_cb_off_cf_max;
    int *scap_cb_hi_cf_min;
    int *scap_cb_hi_cf_max;

    int *mcap_cmb_min;
    int *mcap_cmb_max;
};

struct mc_sc_test {
    struct mc_sc_threshold thr;
    union {
        u32 tmp;
        struct mc_sc_testitem item;
    } u;
};

/* sc */
struct sc_testitem {
    u32 rawdata_test                : 1;
    u32 cb_test                     : 1;
    u32 delta_cb_test               : 1;
    u32 short_test                  : 1;
};

struct sc_threshold_b {
    int rawdata_min;
    int rawdata_max;
    int cb_min;
    int cb_max;
    int dcb_base;
    int dcb_differ_max;
    int dcb_key_check;
    int dcb_key_differ_max;
    int dcb_ds1;
    int dcb_ds2;
    int dcb_ds3;
    int dcb_ds4;
    int dcb_ds5;
    int dcb_ds6;
    int dcb_critical_check;
    int dcb_cs1;
    int dcb_cs2;
    int dcb_cs3;
    int dcb_cs4;
    int dcb_cs5;
    int dcb_cs6;
    int short_min;
};

struct sc_threshold {
    struct sc_threshold_b basic;
    int *rawdata_min;
    int *rawdata_max;
    int *cb_min;
    int *cb_max;
    int *dcb_sort;
    int *dcb_base;
};

struct sc_test {
    struct sc_threshold thr;
    union {
        u32 tmp;
        struct sc_testitem item;
    } u;
};

enum test_hw_type {
    IC_HW_INCELL = 1,
    IC_HW_MC_SC,
    IC_HW_SC,
};

enum test_scan_mode {
    SCAN_NORMAL = 0,
    SCAN_SC,
};

struct fts_test_node {
    int channel_num;
    int tx_num;
    int rx_num;
    int node_num;
    int key_num;
};

struct fts_test {
    struct fts_hid_data *ts_data;
    struct fts_test_node node;
    struct fts_test_node sc_node;
    u8 fw_ver;
    u8 va_touch_thr;
    u8 vk_touch_thr;
    bool key_support;
    bool v3_pattern;
    u8 mapping;
    u8 normalize;
    int test_num;
    char *csv_buffer;
    int csv_result_len;
    int *item1_data;
    int *item2_data;
    int *item3_data;
    int *item4_data;
    int *item5_data;
    int *item6_data;
    int *buffer;
    int buffer_length;
    int *node_valid;
    int *node_valid_sc;
    int basic_thr_count;
    int csv_item_cnt;
    int csv_item_scb;
    int csv_item_sraw;
    int code1;
    int code2;
    int offset;
    union {
        struct incell_test incell;
        struct mc_sc_test mc_sc;
        struct sc_test sc;
    } ic;

    struct test_funcs *func;
    struct fts_test_data testdata;
    char *testresult;
    int testresult_len;
    int result;
#if defined(TEST_SAVE_FAIL_RESULT) && TEST_SAVE_FAIL_RESULT
    struct timeval tv;
#endif
    struct ini_data ini;
};

struct test_funcs {
    u16 ctype[5];
    enum test_hw_type hwtype;
    int startscan_mode;
    int key_num_total;
    bool rawdata2_support;
    bool force_touch;
    bool mc_sc_short_v2;
    bool raw_u16;
    bool cb_high_support;
    bool param_update_support;
    int (*param_init)(void);
    int (*init)(void);
    int (*start_test)(void);
    void (*save_data_private)(char *buf, int *len);
};

enum byte_mode {
    DATA_ONE_BYTE,
    DATA_TWO_BYTE,
};
/* mc_sc */
enum normalize_type {
    NORMALIZE_OVERALL,
    NORMALIZE_AUTO,
};

enum wp_type {
    WATER_PROOF_OFF = 0,
    WATER_PROOF_ON = 1,
    HIGH_SENSITIVITY = 2,
    HOV = 3,
    WATER_PROOF_ON_TX = 100,
    WATER_PROOF_ON_RX,
    WATER_PROOF_OFF_TX,
    WATER_PROOF_OFF_RX,
};
/* mc end */

/* sc */
enum factory_mode {
    FACTORY_NORMAL,
    FACTORY_TESTMODE_1,
    FACTORY_TESTMODE_2,
};

enum dcb_sort_num {
    DCB_SORT_MIN = 1,
    DCB_SORT_MAX = 6,
};

struct dcb_sort_d {
    int ch_num;
    int deviation;
    int critical;
    int min;
    int max;
};
/* sc end */

enum csv_itemcode_incell {
    CODE_ENTER_FACTORY_MODE = 0,
    CODE_RAWDATA_TEST = 7,
    CODE_CB_TEST = 12,
    CODE_SHORT_TEST = 15,
    CODE_OPEN_TEST = 25,
    CODE_LCD_NOISE_TEST = 27,
    CODE_MUX_OPEN_TEST = 41,
};

enum csv_itemcode_mc_sc {
    CODE_M_RAWDATA_TEST = 7,
    CODE_M_SCAP_CB_TEST = 9,
    CODE_M_SCAP_RAWDATA_TEST = 10,
    CODE_M_WEAK_SHORT_CIRCUIT_TEST = 15,
    CODE_M_RAWDATA_UNIFORMITY_TEST = 16,
    CODE_M_PANELDIFFER_TEST = 20,
    CODE_M_CMB_TEST = 39,
};

enum csv_itemcode_sc {
    CODE_S_RAWDATA_TEST = 7,
    CODE_S_CB_TEST = 13,
    CODE_S_DCB_TEST = 14,
};

void sys_delay(int ms);
int fts_abs(int value);
void print_buffer(int *buffer, int length, int line_num);
int fts_test_read_reg(u8 addr, u8 *val);
int fts_test_write_reg(u8 addr, u8 val);
int fts_test_read(u8 addr, u8 *readbuf, int readlen);
int fts_test_read_one(u8 addr, u8 *readbuf, int readlen);
int fts_test_write(u8 addr, u8 *writebuf, int writelen);
int enter_work_mode(void);
int enter_factory_mode(void);
int read_mass_data(u8 addr, int byte_num, int *buf);
int chip_clb(void);
int wait_state_update(u8 retval);
int get_cb_incell(u16 saddr, int byte_num, int *cb_buf);
int short_get_adcdata_incell(u8 retval, u8 ch_num, int byte_num, int *adc_buf);
int start_scan(void);
int get_rawdata(int *data);
int get_cb_sc(int byte_num, int *cb_buf, enum byte_mode mode);
bool compare_data(int *data, int min, int max, int min_vk, int max_vk, bool key);
bool compare_array(int *data, int *min, int *max, bool key);
void show_data(int *data, bool key);
/* mc_sc */
int mapping_switch(u8 mapping);
bool get_fw_wp(u8 wp_channel_select, enum wp_type water_proof_type);
int get_cb_mc_sc(u8 wp, int byte_num, int *cb_buf, enum byte_mode mode);
int get_rawdata_mc_sc(enum wp_type wp, int *data);
int get_rawdata_mc(u8 fre, u8 fir, int *rawdata);
int short_get_adc_data_mc(u8 retval, int byte_num, int *adc_buf, u8 mode);
bool compare_mc_sc(bool, bool, int *, int *, int *);
void show_data_mc_sc(int *data);
void *fts_malloc(size_t size);
void fts_free_proc(void *p);
void fts_test_save_data(char *name, int code, int *data, int datacnt,
                        bool mc_sc, bool key, bool result);

#endif

