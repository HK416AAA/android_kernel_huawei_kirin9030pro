/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2025. All rights reserved.
 */

/************************************************************************
* Copyright (c) 2012-2020, Focaltech Systems (R), All Rights Reserved.
*
* File Name: Focaltech_test_ft5452.c
*
* Author: Focaltech Driver Team
*
* Created: 2018-03-08
*
* Abstract:
*
************************************************************************/

/*****************************************************************************
* included header files
*****************************************************************************/
#include "../focaltech_test_struct.h"

#define FTS_SHORT_TEST_CODE_1      1437
#define FTS_SHORT_TEST_CONSTANT_1  395
#define FTS_SHORT_TEST_CONSTANT_2  111
#define FTS_SHORT_TEST_CONSTANT_3  3
#define FTS_REG_VALUE_ENABLE       0x01
#define FTS_RAWDATA_HI_FRE         0x81

#define FTS_BYTE_NUM               2
#define FTS_TEST_RETRY_NUM               3
#define FTS_TEST_DELAY_10_MS             10
#define FTS_DIV_100                      100
#define FTS_TEST_NUM               3
#define FTS_SHORT_OFFSET_CODE       1024
#define FTS_SHORT_CMD_NUM          3
#define FTS_PANEL_DIFF_DIV          10
/*****************************************************************************
* private constant and macro definitions using #define
*****************************************************************************/
static bool cal_short_data(struct fts_test *tdata, int *ca_short_resistance, int *adc_data, int offset)
{
    int i = 0;
    int code_1 = FTS_SHORT_TEST_CODE_1;
    int code = 0;
    int ch_num = 0;
    int tx_num = 0;
    int rx_num = 0;
    struct mc_sc_threshold *thr = &fts_ftest->ic.mc_sc.thr;
    int min_cc = thr->basic.short_cc;
    int numerator = 0;
    int denominator = 0;
    int err_ch_num = 0;

    FTS_FUNC_ENTER();
    tx_num = tdata->sc_node.tx_num;
    rx_num = tdata->sc_node.rx_num;
    ch_num = tx_num + rx_num;
    FTS_INFO("tx:%d,rx:%d,ch_num:%d\n", tx_num, rx_num, ch_num);
    
    for (i = 0; i < ch_num; i++) {
        code = adc_data[i];
        denominator = code_1 - code;
        if (denominator <= 0) {
            ca_short_resistance[i] = min_cc;
        } else {
            numerator = (code - offset + FTS_SHORT_TEST_CONSTANT_1) * FTS_SHORT_TEST_CONSTANT_2;
            ca_short_resistance[i] = fts_abs(numerator / denominator - FTS_SHORT_TEST_CONSTANT_3);
        }

        if (ca_short_resistance[i] < min_cc) {
            err_ch_num++;
        }
    }

    if (err_ch_num > 0) {
        /* print all Adc value */
        FTS_TEST_SAVE_INFO("Offset:%d, Code1:%d\n", offset, code_1);
        print_buffer(adc_data, ch_num, ch_num);
        return false;
    } else {
        return true;
    }
}

static int short_test_channel_to_all(struct fts_test *tdata, int *ca_short_resistance, int *adc_data,
                                     int offset, bool *result)
{
    int ret = 0;
    int tx_num = 0;
    int rx_num = 0;
    int ch_num = 0;

    FTS_TEST_FUNC_ENTER();
    *result = false;
    tx_num = tdata->sc_node.tx_num;
    rx_num = tdata->sc_node.rx_num;
    ch_num = tx_num + rx_num;

    /* get adc data for channel to all */
    ret = fts_test_write_reg(FACTROY_REG_SHORT_RES_LEVEL, FTS_REG_VALUE_ENABLE);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("write 5A fails,ret:%d\n", ret);
        goto TEST_END;
    }

    ret = short_get_adc_data_mc(TEST_RETVAL_00, (ch_num + 1) * FTS_BYTE_NUM, \
                                adc_data, FACTROY_REG_SHORT_CA);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("get adc data of ca fails,ret:%d\n", ret);
        goto TEST_END;
    }

    *result = cal_short_data(tdata, ca_short_resistance, adc_data, offset);

TEST_END:

    FTS_TEST_FUNC_EXIT();
    return ret;
}

static int rawdata_test_init(struct fts_test *tdata, u8 *normalize, u8 *fre, u8 *fir)
{
    int ret = 0;
    struct mc_sc_threshold *thr = &tdata->ic.mc_sc.thr;
    
    FTS_TEST_FUNC_ENTER();
    FTS_TEST_SAVE_INFO("\n============ Test Item: rawdata test\n");
    memset_s(tdata->buffer, tdata->buffer_length, 0, tdata->buffer_length);
    if (!thr->rawdata_h_min || !thr->rawdata_h_max) {
        FTS_TEST_SAVE_ERR("rawdata_h_min/max is null\n");
        ret = -EINVAL;
        return ret;
    }

    ret = enter_factory_mode();
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("failed to enter factory mode,ret=%d\n", ret);
        return ret;
    }

    /* rawdata test in mapping mode */
    ret = mapping_switch(MAPPING);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("switch mapping fail,ret=%d\n", ret);
        return ret;
    }

    /* save origin value */
    ret = fts_test_read_reg(FACTORY_REG_NORMALIZE, normalize);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("read normalize fail,ret=%d\n", ret);
        return ret;
    }

    ret = fts_test_read_reg(FACTORY_REG_FRE_LIST, fre);
    if (ret) {
        FTS_TEST_SAVE_ERR("read 0x0A fail,ret=%d\n", ret);
        return ret;
    }

    ret = fts_test_read_reg(FACTORY_REG_FIR, fir);
    if (ret) {
        FTS_TEST_SAVE_ERR("read 0xFB error,ret=%d\n", ret);
        return ret;
    }

    return 0;
}

static bool rawdata_test_set_reg(struct fts_test *tdata, int *rawdata, u8 normalize)
{
    int ret = 0;
    int i = 0;
    struct mc_sc_threshold *thr = &tdata->ic.mc_sc.thr;
        /* set to auto normalize */
    if (normalize != FTS_REG_VALUE_ENABLE) {
        ret = fts_test_write_reg(FACTORY_REG_NORMALIZE, FTS_REG_VALUE_ENABLE);
        if (ret < 0) {
            FTS_TEST_SAVE_ERR("write normalize fail,ret=%d\n", ret);
            return false;
        }
    }

    /* set frequecy high */
    ret = fts_test_write_reg(FACTORY_REG_FRE_LIST, FTS_RAWDATA_HI_FRE);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("set frequecy fail,ret=%d\n", ret);
        return false;
    }

    /* fir enable */
    ret = fts_test_write_reg(FACTORY_REG_FIR, FTS_REG_VALUE_ENABLE);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("set fir fail,ret=%d\n", ret);
        return false;
    }

    /*********************GET RAWDATA*********************/
    for (i = 0; i < FTS_TEST_RETRY_NUM; i++) {
        /* lost 3 frames, in order to obtain stable data */
        ret = get_rawdata(rawdata);
    }
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("get rawdata fail,ret=%d\n", ret);
        return ret;
    }

    /* show test data */
    show_data(rawdata, false);

    /* compare */
    return compare_array(rawdata, thr->rawdata_h_min, thr->rawdata_h_max, false);
}
static int ft5452_rawdata_test(struct fts_test *tdata, bool *test_result)
{
    int ret = 0;
    int *rawdata = NULL;
    u8 fre = 0;
    u8 fir = 0;
    u8 normalize = 0;
    bool result = false;

    ret = rawdata_test_init(tdata, &normalize, &fre, &fir);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("rawdata_test_init fail, ret = %d\n", ret);
        goto test_err;
    }
    rawdata = tdata->buffer;
    
    result = rawdata_test_set_reg(tdata, rawdata, normalize);

    /* set the origin value */
    ret = fts_test_write_reg(FACTORY_REG_NORMALIZE, normalize);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("restore normalize fail,ret=%d\n", ret);
    }

    ret = fts_test_write_reg(FACTORY_REG_FRE_LIST, fre);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("restore 0x0A fail,ret=%d\n", ret);
    }

    ret = fts_test_write_reg(FACTORY_REG_FIR, fir);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("restore 0xFB fail,ret=%d\n", ret);
    }

test_err:
    if (result) {
        *test_result = true;
        FTS_TEST_SAVE_INFO("------ rawdata test PASS\n");
    } else {
        *test_result = false;
        FTS_TEST_SAVE_INFO("------ rawdata test NG\n");
    }

    /* save test data */
    fts_test_save_data("Rawdata Test", CODE_M_RAWDATA_TEST,
                       rawdata, 0, false, false, *test_result);

    FTS_TEST_FUNC_EXIT();
    return ret;
}

static int uniformity_test_init(struct fts_test *tdata, u8 *normalize, u8 *fre, u8 *fir)
{
    int ret = 0;
    struct mc_sc_threshold *thr = &fts_ftest->ic.mc_sc.thr;
    
    FTS_TEST_FUNC_ENTER();
    FTS_TEST_SAVE_INFO("\n============ Test Item: rawdata unfiormity test\n");
    memset_s(tdata->buffer, tdata->buffer_length, 0, tdata->buffer_length);

    if (!thr->tx_linearity_max || !thr->rx_linearity_max || !tdata->node_valid) {
        FTS_TEST_SAVE_ERR("tx/rx_lmax/node_valid is null\n");
        ret = -EINVAL;
        return ret;
    }

    ret = enter_factory_mode();
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("failed to enter factory mode,ret=%d\n", ret);
        return ret;
    }
    /* rawdata unfiormity test in mapping mode */
    ret = mapping_switch(MAPPING);
    if (ret) {
        FTS_TEST_SAVE_ERR("failed to switch_to_mapping,ret=%d", ret);
        return ret;
    }

    ret = fts_test_read_reg(FACTORY_REG_NORMALIZE, normalize);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("read normalize fail,ret=%d\n", ret);
        return ret;
    }

    ret = fts_test_read_reg(FACTORY_REG_FRE_LIST, fre);
    if (ret) {
        FTS_TEST_SAVE_ERR("read 0x0A fail,ret=%d\n", ret);
        return ret;
    }

    ret = fts_test_read_reg(FACTORY_REG_FIR, fir);
    if (ret) {
        FTS_TEST_SAVE_ERR("read 0xFB error,ret=%d\n", ret);
        return ret;
    }

    return 0;
}

static int uniformity_test_set_reg(struct fts_test *tdata, u8 normalize, int *rawdata)
{
    int ret = 0;
    int index = 0;
    
    if (normalize != 0x01) {
        ret = fts_test_write_reg(FACTORY_REG_NORMALIZE, FTS_REG_VALUE_ENABLE);
        if (ret < 0) {
            FTS_TEST_SAVE_ERR("write normalize fail,ret=%d\n", ret);
            return ret;
        }
    }

    /* set frequecy high */
    ret = fts_test_write_reg(FACTORY_REG_FRE_LIST, FTS_RAWDATA_HI_FRE);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("set frequecy fail,ret=%d\n", ret);
        return ret;
    }
    sys_delay(FTS_TEST_DELAY_10_MS);

    /* fir enable */
    ret = fts_test_write_reg(FACTORY_REG_FIR, FTS_REG_VALUE_ENABLE);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("set fir fail,ret=%d\n", ret);
        return ret;
    }
    sys_delay(FTS_TEST_DELAY_10_MS);

    /* change register value before,need to lose 3 frame data */
    for (index = 0; index < FTS_TEST_RETRY_NUM; ++index) {
        ret = get_rawdata(rawdata);
    }
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("get rawdata fail,ret=%d\n", ret);
        return ret;
    }
    print_buffer(rawdata, tdata->node.node_num, tdata->node.rx_num);

    return 0;
}

static bool uniformity_test_tx(struct fts_test *tdata, int *rl_tmp, int *rawdata)
{
    int row = 0;
    int col = 1;
    int offset = 0;
    int offset2 = 0;
    int deviation = 0;
    int max = 0;
    int tx_num = tdata->node.tx_num;
    int rx_num = tdata->node.rx_num;
    struct mc_sc_threshold *thr = &fts_ftest->ic.mc_sc.thr;
    
    for (row = 0; row < tx_num; row++) {
        for (col = 1; col <  rx_num; col++) {
            offset = row * rx_num + col;
            offset2 = row * rx_num + col - 1;
            deviation = abs(rawdata[offset] - rawdata[offset2]);
            max = max(rawdata[offset], rawdata[offset2]);
            max = max ? max : 1;
            rl_tmp[offset] = FTS_DIV_100 * deviation / max;
        }
    }
    /* show data in result.txt */
    FTS_TEST_SAVE_INFO(" Tx Linearity:\n");
    show_data(rl_tmp, false);
    FTS_TEST_SAVE_INFO("\n");

    /* compare */
    return compare_array(rl_tmp, thr->tx_linearity_min, thr->tx_linearity_max, false);
}

static bool uniformity_test_rx(struct fts_test *tdata, int *rl_tmp, int *rawdata)
{
    int row = 0;
    int col = 1;
    int offset = 0;
    int offset2 = 0;
    int deviation = 0;
    int max = 0;
    int tx_num = tdata->node.tx_num;
    int rx_num = tdata->node.rx_num;
    struct mc_sc_threshold *thr = &fts_ftest->ic.mc_sc.thr;

    for (row = 1; row < tx_num; row++) {
        for (col = 0; col < rx_num; col++) {
            offset = row * rx_num + col;
            offset2 = (row - 1) * rx_num + col;
            deviation = abs(rawdata[offset] - rawdata[offset2]);
            max = max(rawdata[offset], rawdata[offset2]);
            max = max ? max : 1;
            rl_tmp[offset] = FTS_DIV_100 * deviation / max;
        }
    }

    FTS_TEST_SAVE_INFO("Rx Linearity:\n");
    show_data(rl_tmp, false);
    FTS_TEST_SAVE_INFO("\n");

    /* compare */
    return compare_array(rl_tmp, thr->rx_linearity_min, thr->rx_linearity_max, false);
}

static bool uniformity_test_mini(struct fts_test *tdata, int *rawdata)
{
    int i = 0;
    int min = 100000;
    int max = -100000;
    int uniform = 0;
    bool result3 = true;
    struct mc_sc_threshold *thr = &fts_ftest->ic.mc_sc.thr;
    
    FTS_TEST_SAVE_INFO("Check Min/Max\n") ;
    for (i = 0; i < tdata->node.node_num; i++) {
        if (tdata->node_valid[i] == 0) {
            continue;
        }
        min = min(min, rawdata[i]);
        max = max(max, rawdata[i]);
    }
    max = !max ? 1 : max;
    uniform = FTS_DIV_100 * abs(min) / abs(max);

    FTS_TEST_SAVE_INFO("min:%d, max:%d, get value of min/max:%d\n",
                       min, max, uniform);
    if (uniform < thr->basic.uniformity_min_max_hole) {
        result3 = false;
        FTS_TEST_SAVE_ERR("min_max out of range, set value: %d\n",
                          thr->basic.uniformity_min_max_hole);
    }

    return result3;
}

static bool uniformity_test_body(struct fts_test *tdata, int *rawdata_linearity, int *rawdata)
{
    int *rl_tmp = NULL;
    int rl_cnt = 0;
    bool result, result2, result3;
    struct mc_sc_threshold *thr = &fts_ftest->ic.mc_sc.thr;
    
    result = true;
    if (thr->basic.uniformity_check_tx) {
        FTS_TEST_SAVE_INFO("Check Tx Linearity\n");
        rl_tmp = rawdata_linearity + rl_cnt;
        result = uniformity_test_tx(tdata, rl_tmp, rawdata);
        rl_cnt += tdata->node.node_num;
    }

    result2 = true;
    if (thr->basic.uniformity_check_rx) {
        FTS_TEST_SAVE_INFO("Check Rx Linearity\n");
        rl_tmp = rawdata_linearity + rl_cnt;
        result2 = uniformity_test_rx(tdata, rl_tmp, rawdata);
        rl_cnt += tdata->node.node_num;
    }

    result3 = true;
    if (thr->basic.uniformity_check_min_max) {
        result3 = uniformity_test_mini(tdata, rawdata);
    }

    if (result && result2 && result3) {
        return true;
    }

    return false;
}

static void uniformity_test_restore_reg(u8 normalize, u8 fre, u8 fir)
{
    int ret = 0;
    /* set the origin value */
    ret = fts_test_write_reg(FACTORY_REG_NORMALIZE, normalize);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("restore normalize fail,ret=%d\n", ret);
    }

    ret = fts_test_write_reg(FACTORY_REG_FRE_LIST, fre);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("restore 0x0A fail,ret=%d\n", ret);
    }

    ret = fts_test_write_reg(FACTORY_REG_FIR, fir);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("restore 0xFB fail,ret=%d\n", ret);
    }
}
static int ft5452_uniformity_test(struct fts_test *tdata, bool *test_result)
{
    int ret = 0;
    int *rawdata = NULL;
    int *rawdata_linearity = NULL;
    u8 fre = 0;
    u8 fir = 0;
    u8 normalize = 0;
    bool result = false;

    ret = uniformity_test_init(tdata, &normalize, &fre, &fir);
    if (ret < 0) {
        goto test_err;
    }
    rawdata = tdata->buffer;

    rawdata_linearity = fts_malloc(tdata->node.node_num * FTS_TEST_NUM * sizeof(int));
    if (!rawdata_linearity) {
        FTS_TEST_SAVE_ERR("rawdata_linearity buffer malloc fail");
        ret = -ENOMEM;
        goto test_err;
    }

    ret = uniformity_test_set_reg(tdata, normalize, rawdata);
    if (ret < 0) {
        goto restore_reg;
    }

    result = uniformity_test_body(tdata, rawdata_linearity, rawdata);

restore_reg:
    uniformity_test_restore_reg(normalize, fre, fir);
test_err:
    if (result) {
        *test_result = true;
        FTS_TEST_SAVE_INFO("uniformity test is OK\n");
    } else {
        *test_result = false;
        FTS_TEST_SAVE_ERR("uniformity test is NG\n");
    }

    fts_test_save_data("Rawdata Uniformity Test",
                       CODE_M_RAWDATA_UNIFORMITY_TEST, rawdata_linearity,
                       tdata->node.node_num * FTS_BYTE_NUM, false, false, *test_result);

    fts_free(rawdata_linearity);
    FTS_TEST_FUNC_EXIT();
    return ret;
}

static int cb_test_init(struct fts_test *tdata, u8 *wc_sel, u8 *sc_mode)
{
    int ret = 0;
    struct mc_sc_threshold *thr = &tdata->ic.mc_sc.thr;
    
    FTS_TEST_FUNC_ENTER();
    FTS_TEST_SAVE_INFO("\n============ Test Item: Scap CB Test\n");
    memset_s(tdata->buffer, tdata->buffer_length, 0, tdata->buffer_length);
    
    if ((tdata->sc_node.node_num * FTS_BYTE_NUM) > tdata->buffer_length) {
        FTS_TEST_SAVE_ERR("scap cb num(%d) > buffer length(%d)",
                          tdata->sc_node.node_num * FTS_BYTE_NUM,
                          tdata->buffer_length);
        ret = -EINVAL;
        return ret;
    }

    if (!thr->scap_cb_on_min || !thr->scap_cb_on_max || !thr->scap_cb_off_min || !thr->scap_cb_off_max) {
        FTS_TEST_SAVE_ERR("scap_cb_on/off_min/max is null\n");
        ret = -EINVAL;
        return ret;
    }

    ret = enter_factory_mode();
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("enter factory mode fail,ret=%d\n", ret);
        return ret;
    }

    /* SCAP CB is in no-mapping mode */
    ret = mapping_switch(NO_MAPPING);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("switch no-mapping fail,ret=%d\n", ret);
        return ret;
    }

    /* get waterproof channel select */
    ret = fts_test_read_reg(FACTORY_REG_WC_SEL, wc_sel);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("read water_channel_sel fail,ret=%d\n", ret);
        return ret;
    }

    ret = fts_test_read_reg(FACTORY_REG_MC_SC_MODE, sc_mode);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("read sc_mode fail,ret=%d\n", ret);
        return ret;
    }

    return 0;
}

static bool cb_check_wp_on_data(struct fts_test *tdata, int *scb_tmp, u8 wc_sel)
{
    int ret = 0;
    bool tx_check = false;
    bool rx_check = false;
    bool tmp_result = false;
    bool fw_wp_check = false;
    struct mc_sc_threshold *thr = &tdata->ic.mc_sc.thr;
    int byte_num = tdata->sc_node.node_num * 2;

    FTS_FUNC_ENTER();
    FTS_INFO("byte_num = %d\n", byte_num);
    fw_wp_check = get_fw_wp(wc_sel, WATER_PROOF_ON);
    if (thr->basic.scap_cb_wp_on_check && fw_wp_check) {
        /* 1:waterproof 0:non-waterproof */
        ret = get_cb_mc_sc(WATER_PROOF_ON, byte_num, scb_tmp, DATA_TWO_BYTE);
        if (ret < 0) {
            FTS_TEST_SAVE_ERR("read sc_cb fail,ret=%d\n", ret);
            return ret;
        }

        /* show Scap CB */
        FTS_TEST_SAVE_INFO("scap_cb in waterproof on mode:\n");
        show_data_mc_sc(scb_tmp);

        /* compare */
        tx_check = get_fw_wp(wc_sel, WATER_PROOF_ON_TX);
        rx_check = get_fw_wp(wc_sel, WATER_PROOF_ON_RX);
        tmp_result = compare_mc_sc(tx_check, rx_check, scb_tmp,
                                   thr->scap_cb_on_min,
                                   thr->scap_cb_on_max);
    } else {
        tmp_result = true;
    }
    
    return true;
}

static bool cb_check_wp_off_data(struct fts_test *tdata, int *scb_tmp, u8 wc_sel)
{
    int ret = 0;
    bool tx_check = false;
    bool rx_check = false;
    bool tmp_result = false;
    bool fw_wp_check = false;
    struct mc_sc_threshold *thr = &tdata->ic.mc_sc.thr;
    int byte_num = tdata->sc_node.node_num * 2;

    FTS_FUNC_ENTER();
    FTS_INFO("byte_num = %d\n", byte_num);
    fw_wp_check = get_fw_wp(wc_sel, WATER_PROOF_OFF);
    if (thr->basic.scap_cb_wp_off_check && fw_wp_check) {
        /* 1:waterproof 0:non-waterproof */
        ret = get_cb_mc_sc(WATER_PROOF_OFF, byte_num, scb_tmp, DATA_TWO_BYTE);
        if (ret < 0) {
            FTS_TEST_SAVE_ERR("read sc_cb fail,ret=%d\n", ret);
            return ret;
        }

        /* show Scap CB */
        FTS_TEST_SAVE_INFO("scap_cb in waterproof off mode:\n");
        show_data_mc_sc(scb_tmp);

        /* compare */
        tx_check = get_fw_wp(wc_sel, WATER_PROOF_OFF_TX);
        rx_check = get_fw_wp(wc_sel, WATER_PROOF_OFF_RX);
        tmp_result = compare_mc_sc(tx_check, rx_check, scb_tmp, thr->scap_cb_off_min, thr->scap_cb_off_max);
    } else {
        tmp_result = true;
    }
    return true;
}


static int ft5452_scap_cb_test(struct fts_test *tdata, bool *test_result)
{
    int ret = 0;
    bool tmp_result = false;
    bool tmp2_result = false;
    u8 wc_sel = 0;
    u8 sc_mode = 0;
    int *scap_cb = NULL;
    int *scb_tmp = NULL;
    int scb_cnt = 0;

    ret = cb_test_init(tdata, &wc_sel, &sc_mode);
    if (ret < 0) {
        FTS_INFO("cb_test_init fial");
        goto test_err;
    }
    scap_cb = tdata->buffer;
    /* water proof on check */
    scb_tmp = scap_cb + scb_cnt;
    /* 1:waterproof 0:non-waterproof */
    tmp_result = cb_check_wp_on_data(tdata, scb_tmp, wc_sel);

    scb_cnt += tdata->sc_node.node_num;
    /* water proof off check */
    scb_tmp = scap_cb + scb_cnt;
    /* 1:waterproof 0:non-waterproof */
    tmp2_result = cb_check_wp_off_data(tdata, scb_tmp, wc_sel);

    scb_cnt += tdata->sc_node.node_num;

    ret = fts_test_write_reg(FACTORY_REG_MC_SC_MODE, sc_mode);  /* set the origin value */
    if (ret) {
        FTS_TEST_SAVE_ERR("write sc mode fail,ret=%d\n", ret);
    }
test_err:
    if (tmp_result && tmp2_result) {
        *test_result = true;
        FTS_TEST_SAVE_INFO("\n------ scap cb test PASS\n");
    } else {
        *test_result = false;
        FTS_TEST_SAVE_ERR("\n------ scap cb test NG\n");
    }

    /* save test data */
    fts_test_save_data("SCAP CB Test", CODE_M_SCAP_CB_TEST,
                       scap_cb, scb_cnt, true, false, *test_result);

    FTS_TEST_FUNC_EXIT();
    return ret;
}

static int scap_rawdata_test_init(struct fts_test *tdata, u8 *wc_sel)
{
    int ret = 0;
    struct mc_sc_threshold *thr = &tdata->ic.mc_sc.thr;
    
    FTS_TEST_FUNC_ENTER();
    FTS_TEST_SAVE_INFO("\n============ Test Item: Scap Rawdata Test\n");
    memset_s(tdata->buffer, tdata->buffer_length, 0, tdata->buffer_length);

    if ((tdata->sc_node.node_num * FTS_BYTE_NUM) > tdata->buffer_length) {
        FTS_TEST_SAVE_ERR("scap rawdata num(%d) > buffer length(%d)",
                          tdata->sc_node.node_num * FTS_BYTE_NUM,
                          tdata->buffer_length);
        ret = -EINVAL;
        return ret;
    }

    if (!thr->scap_rawdata_on_min || !thr->scap_rawdata_on_max ||
        !thr->scap_rawdata_off_min || !thr->scap_rawdata_off_max) {
        FTS_TEST_SAVE_ERR("scap_rawdata_on/off_min/max is null\n");
        ret = -EINVAL;
        return ret;
    }

    ret = enter_factory_mode();
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("enter factory mode fail,ret=%d\n", ret);
        return ret;
    }

    /* SCAP RAWDATA is in no-mapping mode */
    ret = mapping_switch(NO_MAPPING);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("switch no-mapping fail,ret=%d\n", ret);
        return ret;
    }

    /* get waterproof channel select */
    ret = fts_test_read_reg(FACTORY_REG_WC_SEL, wc_sel);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("read water_channel_sel fail,ret=%d\n", ret);
        return ret;
    }

    /* scan rawdata */
    ret = start_scan();
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("scan scap rawdata fail\n");
        return ret;
    }

    return 0;
}

static bool scap_rawdata_wp_on_check(struct fts_test *tdata, int *srawdata_tmp, u8 wc_sel)
{
    int ret = 0;
    bool tx_check = false;
    bool rx_check = false;
    bool tmp_result = false;
    bool fw_wp_check = false;
    struct mc_sc_threshold *thr = &tdata->ic.mc_sc.thr;
    
    fw_wp_check = get_fw_wp(wc_sel, WATER_PROOF_ON);
    if (thr->basic.scap_rawdata_wp_on_check && fw_wp_check) {
        ret = get_rawdata_mc_sc(WATER_PROOF_ON, srawdata_tmp);
        if (ret < 0) {
            FTS_TEST_SAVE_ERR("get scap(WP_ON) rawdata fail\n");
            return false;
        }

        FTS_TEST_SAVE_INFO("scap_rawdata in waterproof on mode:\n");
        show_data_mc_sc(srawdata_tmp);

        /* compare */
        tx_check = get_fw_wp(wc_sel, WATER_PROOF_ON_TX);
        rx_check = get_fw_wp(wc_sel, WATER_PROOF_ON_RX);
        tmp_result = compare_mc_sc(tx_check, rx_check, srawdata_tmp,
                                   thr->scap_rawdata_on_min,
                                   thr->scap_rawdata_on_max);
    } else {
        tmp_result = true;
    }

    return tmp_result;
}

static bool scap_rawdata_wp_off_check(struct fts_test *tdata, int *srawdata_tmp, u8 wc_sel)
{
    int ret = 0;
    bool tx_check = false;
    bool rx_check = false;
    bool tmp_result = false;
    bool fw_wp_check = false;
    struct mc_sc_threshold *thr = &tdata->ic.mc_sc.thr;
    
    fw_wp_check = get_fw_wp(wc_sel, WATER_PROOF_OFF);
    if (thr->basic.scap_rawdata_wp_off_check && fw_wp_check) {
        ret = get_rawdata_mc_sc(WATER_PROOF_OFF, srawdata_tmp);
        if (ret < 0) {
            FTS_TEST_SAVE_ERR("get scap(WP_OFF) rawdata fail\n");
            return false;
        }

        FTS_TEST_SAVE_INFO("scap_rawdata in waterproof off mode:\n");
        show_data_mc_sc(srawdata_tmp);

        /* compare */
        tx_check = get_fw_wp(wc_sel, WATER_PROOF_OFF_TX);
        rx_check = get_fw_wp(wc_sel, WATER_PROOF_OFF_RX);
        tmp_result = compare_mc_sc(tx_check, rx_check, srawdata_tmp,
                                   thr->scap_rawdata_off_min,
                                   thr->scap_rawdata_off_max);
    } else {
        tmp_result = true;
    }

    return tmp_result;
}


static int ft5452_scap_rawdata_test(struct fts_test *tdata, bool *test_result)
{
    int ret = 0;
    bool tmp_result = false;
    bool tmp2_result = false;
    u8 wc_sel = 0;
    int *scap_rawdata = NULL;
    int *srawdata_tmp = NULL;
    int srawdata_cnt = 0;

    ret = scap_rawdata_test_init(tdata, &wc_sel);
    if (ret < 0) {
        goto test_err;
    }
    scap_rawdata = tdata->buffer;
    /* water proof on check */
 
    srawdata_tmp = scap_rawdata + srawdata_cnt;
    tmp_result = scap_rawdata_wp_on_check(tdata, srawdata_tmp, wc_sel);
    srawdata_cnt += tdata->sc_node.node_num;

    /* water proof off check */

    srawdata_tmp = scap_rawdata + srawdata_cnt;
    tmp2_result = scap_rawdata_wp_off_check(tdata, srawdata_tmp, wc_sel);
    srawdata_cnt += tdata->sc_node.node_num;

test_err:
    if (tmp_result && tmp2_result) {
        *test_result = true;
        FTS_TEST_SAVE_INFO("\n------ scap rawdata test PASS\n");
    } else {
        *test_result = false;
        FTS_TEST_SAVE_INFO("\n------ scap rawdata test NG\n");
    }

    /* save data */
    fts_test_save_data("SCAP Rawdata Test", CODE_M_SCAP_RAWDATA_TEST,
                       scap_rawdata, srawdata_cnt, true, false, *test_result);

    FTS_TEST_FUNC_EXIT();
    return ret;
}

static bool get_short_data(struct fts_test *tdata, int *adc_data, int *ca_short_resistance)
{
    int ret = 0;
    int offset = 0;
    bool weak_short_result = false;
    
    ret = short_get_adc_data_mc(TEST_RETVAL_00, 1 * FTS_BYTE_NUM, &offset, \
                                FACTROY_REG_SHORT_OFFSET);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("failed to get weak short data,ret=%d\n", ret);
        return ret;
    }

    offset -= FTS_SHORT_OFFSET_CODE;

    /* get short resistance and exceptional channel */
    ret = short_test_channel_to_all(tdata, ca_short_resistance, adc_data, offset, \
                                    &weak_short_result);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("short test of channel to all fails\n");
        return ret;
    }

    return weak_short_result;
}

static int short_test_init(struct fts_test *tdata, int **adc_data, int **ca_short_resistance)
{
    int ret = 0;
    int ch_num = 0;
    
    FTS_TEST_FUNC_ENTER();
    FTS_TEST_SAVE_INFO("\n============ Test Item: Short Test\n");
    ch_num = tdata->sc_node.tx_num + tdata->sc_node.rx_num;

    ret = enter_factory_mode();
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("enter factory mode fail,ret=%d\n", ret);
        return ret;
    }

    /* short is in no-mapping mode */
    ret = mapping_switch(NO_MAPPING);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("switch no-mapping fail,ret=%d\n", ret);
        return ret;
    }

    *adc_data = (int *)fts_malloc((ch_num + FTS_SHORT_CMD_NUM) * sizeof(int));
    if (NULL == *adc_data) {
        FTS_TEST_SAVE_ERR("adc_data buffer malloc fail\n");
        ret = -ENOMEM;
        return ret;
    }

    *ca_short_resistance = (int *)fts_malloc(ch_num * sizeof(int));
    if (NULL == *ca_short_resistance) {
        FTS_TEST_SAVE_ERR("short_resistance buffer malloc fail\n");
        ret = -ENOMEM;
        return ret;
    }

    return 0;
}

static int ft5452_short_test(struct fts_test *tdata, bool *test_result)
{
    int ret = 0;
    int *adc_data = NULL;
    int *ca_short_resistance = NULL;
    u8 short_delay = 0;
    bool weak_short_result = false;

    ret = short_test_init(tdata, &adc_data, &ca_short_resistance);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("read 5A fails\n");
        goto test_err;
    }

    ret = fts_test_read_reg(FACTROY_REG_SHORT_RES_LEVEL, &short_delay);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("read 5A fails\n");
        goto test_err;
    }

    weak_short_result = get_short_data(tdata, adc_data, ca_short_resistance);
    
    ret = fts_test_write_reg(FACTROY_REG_SHORT_RES_LEVEL, short_delay);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("restore 5A fails");
    }

test_err:
    fts_free(adc_data);
    fts_free(ca_short_resistance);

    if (weak_short_result) {
        FTS_TEST_SAVE_INFO("------ short test PASS\n");
        *test_result = true;
    } else {
        FTS_TEST_SAVE_ERR("------ short test NG\n");
        *test_result = false;
    }

    FTS_TEST_FUNC_EXIT();
    return ret;
}

static int fts_get_panel_differ(struct fts_test *tdata, int *panel_differ, u8 normalize)
{
    int ret = 0;
    int i = 0;
    
    /* set to overall normalize */
    if (normalize != NORMALIZE_OVERALL) {
        ret = fts_test_write_reg(FACTORY_REG_NORMALIZE, NORMALIZE_OVERALL);
        if (ret < 0) {
            FTS_TEST_SAVE_ERR("write normalize fail,ret=%d\n", ret);
            return ret;
        }
    }

    /* set frequecy high */
    ret = fts_test_write_reg(FACTORY_REG_FRE_LIST, FTS_RAWDATA_HI_FRE);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("set frequecy fail,ret=%d\n", ret);
        return ret;
    }

    /* fir disable */
    ret = fts_test_write_reg(FACTORY_REG_FIR, 0);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("set fir fail,ret=%d\n", ret);
        return ret;
    }

    /* get rawdata */
    for (i = 0; i < FTS_TEST_RETRY_NUM; i++) {
        ret = get_rawdata(panel_differ);
        if (ret < 0) {
            FTS_TEST_SAVE_ERR("get rawdata fail\n");
            return ret;
        }
    }

    for (i = 0; i < tdata->node.node_num; i++) {
        panel_differ[i] = panel_differ[i] / FTS_PANEL_DIFF_DIV;
    }

    return 0;
}

static int panel_differ_test_read_reg(u8 *normalize, u8 *fre, u8 *fir)
{
    int ret = 0;
    /* save origin value */
    ret = fts_test_read_reg(FACTORY_REG_NORMALIZE, normalize);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("read normalize fail,ret=%d\n", ret);
        return ret;
    }

    ret = fts_test_read_reg(FACTORY_REG_FRE_LIST, fre);
    if (ret) {
        FTS_TEST_SAVE_ERR("read 0x0A fail,ret=%d\n", ret);
        return ret;
    }

    ret = fts_test_read_reg(FACTORY_REG_FIR, fir);
    if (ret) {
        FTS_TEST_SAVE_ERR("read 0xFB fail,ret=%d\n", ret);
        return ret;
    }

    return 0;
}

static int panel_differ_restore_reg(u8 normalize, u8 fre, u8 fir)
{
    int ret = 0;
    
    ret = fts_test_write_reg(FACTORY_REG_NORMALIZE, normalize);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("restore normalize fail,ret=%d\n", ret);
    }

    ret = fts_test_write_reg(FACTORY_REG_FRE_LIST, fre);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("restore 0x0A fail,ret=%d\n", ret);
    }

    ret = fts_test_write_reg(FACTORY_REG_FIR, fir);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("restore 0xFB fail,ret=%d\n", ret);
    }

    return 0;
}

static int panel_differ_test_init(struct fts_test *tdata)
{
    struct mc_sc_threshold *thr = &tdata->ic.mc_sc.thr;
    int ret = 0;
    
    FTS_TEST_FUNC_ENTER();
    FTS_TEST_SAVE_INFO("\n============ Test Item: Panel Differ Test\n");
    memset_s(tdata->buffer, tdata->buffer_length, 0, tdata->buffer_length);

    if (!thr->panel_differ_min || !thr->panel_differ_max) {
        FTS_TEST_SAVE_ERR("panel_differ_h_min/max is null\n");
        ret = -EINVAL;
        return ret;
    }

    ret = enter_factory_mode();
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("failed to enter factory mode,ret=%d\n", ret);
        return ret;
    }

    /* panel differ test in mapping mode */
    ret = mapping_switch(MAPPING);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("switch mapping fail,ret=%d\n", ret);
    }
    
    return ret;
}

static int ft5452_panel_differ_test(struct fts_test *tdata, bool *test_result)
{
    int ret = 0;
    bool tmp_result = false;
    u8 fre = 0;
    u8 fir = 0;
    u8 normalize = 0;
    int *panel_differ = NULL;
    struct mc_sc_threshold *thr = &tdata->ic.mc_sc.thr;

    ret = panel_differ_test_init(tdata);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("fts_get_panel_differ fail,ret=%d\n", ret);
        goto test_err;
    }
    panel_differ = tdata->buffer;

    ret = panel_differ_test_read_reg(&normalize, &fre, &fir);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("fts_get_panel_differ fail,ret=%d\n", ret);
        goto test_err;
    }

    ret = fts_get_panel_differ(tdata, panel_differ, normalize);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("fts_get_panel_differ fail,ret=%d\n", ret);
        goto test_err;
    }

    /* show test data */
    show_data(panel_differ, false);

    /* compare */
    tmp_result = compare_array(panel_differ, thr->panel_differ_min, thr->panel_differ_max, false);

    /* set the origin value */
    panel_differ_restore_reg(normalize, fre, fir);
test_err:
    /* result */
    if (tmp_result) {
        *test_result = true;
        FTS_TEST_SAVE_INFO("------ panel differ test PASS\n");
    } else {
        *test_result = false;
        FTS_TEST_SAVE_ERR("------ panel differ test NG\n");
    }

    /* save test data */
    fts_test_save_data("Panel Differ Test", CODE_M_PANELDIFFER_TEST,
                       panel_differ, 0, false, false, *test_result);

    FTS_TEST_FUNC_EXIT();
    return ret;
}

static int ft5452_fw_version_test(struct fts_test *tdata, bool *test_result)
{
    int ret = 0;
    u8 tp_fw_ver = 0;
    struct mc_sc_threshold *thr = &fts_ftest->ic.mc_sc.thr;
    bool tmp_result = false;

    ret = enter_factory_mode();
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("failed to enter factory mode,ret=%d\n", ret);
        goto test_err;
    }

    ret = fts_test_write_reg(0x50, 0x40);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("restore normalize fail,ret=%d\n", ret);
        goto test_err;
    }
    
    ret = fts_test_read_reg(0x51, &tp_fw_ver);
    if (ret < 0) {
        FTS_TEST_SAVE_ERR("read 0xA6 fail,ret=%d\n", ret);
        goto test_err;
    }
    
    FTS_TEST_SAVE_ERR("FW version:%#x, thr version:%#x\n", tp_fw_ver, thr->basic.fw_version);
    if (tp_fw_ver == thr->basic.fw_version) {
        tmp_result = true;
    }

test_err:
    if (tmp_result) {
        *test_result = true;
        ret = 0;
        FTS_TEST_SAVE_INFO("------ FW version test PASS\n");
    } else {
        *test_result = false;
        ret = -EINVAL;
        FTS_TEST_SAVE_INFO("------ FW version test NG\n");
    }
    return ret;
}

static int fts_scap_test(void)
{
    int ret = 0;
    struct fts_test *tdata = fts_ftest;
    struct mc_sc_testitem *test_item = &tdata->ic.mc_sc.u.item;
    bool temp_result = false;
    bool test_result = true;

    /* scap_cb test */
    if (test_item->scap_cb_test == true) {
        ret = ft5452_scap_cb_test(tdata, &temp_result);
        if ((ret < 0) || (false == temp_result)) {
            test_result = false;
        }
    }

    /* scap_rawdata test */
    if (test_item->scap_rawdata_test == true) {
        ret = ft5452_scap_rawdata_test(tdata, &temp_result);
        if ((ret < 0) || (false == temp_result)) {
            test_result = false;
        }
    }

    /* short test */
    if (test_item->short_test == true) {
        ret = ft5452_short_test(tdata, &temp_result);
        if ((ret < 0) || (false == temp_result)) {
            test_result = false;
        }
    }
    /* panel differ test */
    if (test_item->panel_differ_test == true) {
        ret = ft5452_panel_differ_test(tdata, &temp_result);
        if ((ret < 0) || (false == temp_result)) {
            test_result = false;
        }
    }

    return test_result;
}

static int start_test_ft5452(void)
{
    int ret = 0;
    struct fts_test *tdata = fts_ftest;
    struct mc_sc_testitem *test_item = &tdata->ic.mc_sc.u.item;
    bool temp_result = false;
    bool test_result = true;

    FTS_TEST_FUNC_ENTER();
    FTS_TEST_INFO("test item:0x%x", fts_ftest->ic.mc_sc.u.tmp);

    /* rawdata test */
    if (test_item->fw_version_test == true) {
        ret = ft5452_fw_version_test(tdata, &temp_result);
        if ((ret < 0) || (false == temp_result)) {
            test_result = false;
        }
    }
    
    if (test_item->rawdata_test == true) {
        ret = ft5452_rawdata_test(tdata, &temp_result);
        if ((ret < 0) || (false == temp_result)) {
            test_result = false;
        }
    }

    if (test_item->rawdata_uniformity_test == true) {
        ret = ft5452_uniformity_test(tdata, &temp_result);
        if ((ret < 0) || (false == temp_result)) {
            test_result = false;
        }
    }

    temp_result = fts_scap_test();
    if ((ret < 0) || (false == temp_result)) {
        test_result = false;
    }

    /* restore mapping state */
    fts_test_write_reg(FACTORY_REG_NOMAPPING, tdata->mapping);

    FTS_TEST_FUNC_EXIT();
    return test_result;
}

static int param_init_ft5452(void)
{
    struct mc_sc_threshold *thr = &fts_ftest->ic.mc_sc.thr;

    get_value_basic("FW_VER_VALUE", &thr->basic.fw_version);
    return 0;
}


struct test_funcs test_func_ft5452 = {
    .ctype = {0x81, 0x89},
    .hwtype = IC_HW_MC_SC,
    .key_num_total = 0,
    .start_test = start_test_ft5452,
    .param_init = param_init_ft5452,
};
