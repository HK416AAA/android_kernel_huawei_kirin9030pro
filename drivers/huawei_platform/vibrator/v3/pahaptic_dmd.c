/*
 * pahaptic_dmd.c
 *
 * common logic for haptic dmd
 *
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <linux/slab.h>
#include <linux/module.h>
#include <linux/string.h>
#include <huawei_platform/log/hw_log.h>
#include <securec.h>

#include "pa_haptic.h"
#include "haptic_dsp.h"
#include "pahaptic_dmd.h"
#include <linux/jiffies.h>

#ifdef CONFIG_HUAWEI_DSM
#include <log/hiview_hievent.h>
#elif (defined CONFIG_HUAWEI_OHOS_DSM)
#include <dfx/hiview_hisysevent.h>
#endif

#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
#include <dsm/dsm_pub.h>
#endif

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif
#define HWLOG_TAG ap_haptic_dmd
HWLOG_REGIST();

#ifdef CONFIG_HUAWEI_DSM
#define BIGDATA_SET_INTEGER(event, key, data) \
	hiview_hievent_put_integral((struct hiview_hievent *)(event), (key), ((long)(data)))
#define BIGDATA_SET_STRING(event, key, data) \
	hiview_hievent_put_string((struct hiview_hievent *)(event), (key), (data))
#elif (defined CONFIG_HUAWEI_OHOS_DSM)
#define BIGDATA_SET_INTEGER(event, key, data) \
	hisysevent_put_integer((struct hiview_hisysevent *)(event), (key), ((long long)(data)))
#define BIGDATA_SET_STRING(event, key, data) \
	hisysevent_put_string((struct hiview_hisysevent *)(event), (key), (data))
#endif

#ifdef CONFIG_HISYSEVENT
struct error_no_map {
	int error_no;
	char *name;
	int running_test_switch;
};

static struct error_no_map pa_haptic_error_no_map[] = {
	{ 926012015, "HAPTIC_VIBRATOR_ABNORMAL_ERROR", 1 },
	{ 926012016, "HAPTIC_VIBRATOR_OCP_ERROR", 1 },
	{ 926012017, "HAPTIC_VIBRATOR_UVP_ERROR", 1 },
	{ 926012018, "HAPTIC_VIBRATOR_POWER_DOWN_ERROR", 1 },
	{ 926012019, "HAPTIC_VIBRATOR_OTP_ERROR", 1 },
	{ 926012020, "HAPTIC_VIBRATOR_F0_ERROR", 1 },
};

int pa_haptic_errorno_to_str(int error_no, char *str, int bufflen)
{
	size_t i;
	size_t error_no_map_len = ARRAY_SIZE(pa_haptic_error_no_map);

	if (!str)
		return -1;

	for (i = 0; i < error_no_map_len; i++) {
		if (pa_haptic_error_no_map[i].error_no == error_no) {
			if (strlen(pa_haptic_error_no_map[i].name) >= bufflen) {
				hwlog_err("%s pa_haptic_error_no_map name too long\n", __func__);
				return -1;
			}
			if (strncpy_s(str, bufflen, pa_haptic_error_no_map[i].name, strlen(pa_haptic_error_no_map[i].name)) != 0) {
				hwlog_err("%s pa_haptic_error_no_map strncpy fail\n", __func__);
				return -1;
			}
			str[bufflen - 1] = '\0';
			hwlog_info("%s pa_haptic_error_no_map:%s\n", __func__, str);
			return 0;
		}
	}
	return -1;
}

static int vib_errorno_get_running_test_switch(int error_no)
{
	size_t i;
	size_t pa_haptic_error_no_map_len = ARRAY_SIZE(pa_haptic_error_no_map);

	for (i = 0; i < pa_haptic_error_no_map_len; i++) {
		if (pa_haptic_error_no_map[i].error_no == error_no)
			return pa_haptic_error_no_map[i].running_test_switch;
	}
	return 0;
}
#endif

#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
struct dsm_client_ops pa_haptic_ops = {
	.poll_state = NULL,
	.dump_func = NULL,
#ifdef CONFIG_HISYSEVENT
	.errorno_to_str = pa_haptic_errorno_to_str,
	.errorno_get_running_test_switch = vib_errorno_get_running_test_switch,
#endif
};
#endif

#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
static struct dsm_dev dsm_vibrator = {
#ifdef CONFIG_HISYSEVENT
	.name = "VIBRATOR",
#else
	.name = "dsm_vibrator",
#endif
	.device_name = NULL,
	.ic_name = NULL,
	.module_name = NULL,
	.fops = &pa_haptic_ops,
	.buff_size = 1024, // vibrator dsm buf size
};
static struct dsm_client *vib_dclient;

struct dsm_error_info {
	uint8_t error_code;
	const char *error_message;
	int dsm_error_type;
};

static struct dsm_error_info dsm_error_map[] = {
	{ DSM_VIBRATOR_ABNORMAL_ERROR, "LRA driver i2c transfer fail", DSM_SHB_VIBRATOR_ABNORMAL_ERROR },
	{ DSM_VIBRATOR_OCP_ERROR, "LRA driver OCP", DSM_SHB_VIBRATOR_OCP_ERROR },
	{ DSM_VIBRATOR_UVP_ERROR, "LRA driver UVP", DSM_SHB_VIBRATOR_UVP_ERROR },
	{ DSM_VIBRATOR_POWER_DOWN, "LRA driver power down", DSM_SHB_VIBRATOR_OVP_ERROR },
	{ DSM_VIBRATOR_OTP_ERROR, "LRA driver OTP", DSM_SHB_VIBRATOR_OTP_ERROR },
	{ DSM_VIBRATOR_F0_ERROR, "LRA driver F0 error", DSM_SHB_VIBRATOR_F0_ERROR },
};
#endif

void pa_haptic_dmd_work(uint8_t num)
{
#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
	if (dsm_client_ocuppy(vib_dclient))
		return;

	for (size_t i = 0; i < ARRAY_SIZE(dsm_error_map); i++) {
		if (dsm_error_map[i].error_code == num) {
			dsm_client_record(vib_dclient, dsm_error_map[i].error_message);
			dsm_client_notify(vib_dclient, dsm_error_map[i].dsm_error_type);
			hwlog_err("%s %s\n", __func__, dsm_error_map[i].error_message);
			return;
		}
	}
#endif
}

void pa_haptic_dsm_register()
{
#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
	if (vib_dclient != NULL) {
		hwlog_info("pahaptic dsm already registered\n");
		return;
	}

	vib_dclient = dsm_register_client(&dsm_vibrator);
	if (vib_dclient == NULL) {
		hwlog_err("pahaptic dsm registration failed\n");
		return;
	}

	hwlog_info("pahaptic dsm register success\n");
#endif
}

void i2c_err_dmd(struct pa_paptic_t *haptic_dev)
{
#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
	if (!haptic_dev)
		return;

	if (!haptic_dev->probe_succ)
		return;

	haptic_dev->i2c_err_cnt++;
	if (haptic_dev->i2c_err_cnt > 1 && haptic_dev->i2c_err_cnt < I2C_ERR_CNT_MAX)
		return;
	if (haptic_dev->i2c_err_cnt == I2C_ERR_CNT_MAX)
		haptic_dev->i2c_err_cnt = 0;
	haptic_dev->i2c_dmd_report_cnt++;
	if (haptic_dev->i2c_dmd_report_cnt > DMD_REPORT_MAX_CNT) {
		haptic_dev->i2c_dmd_report_cnt = DMD_REPORT_MAX_CNT;
		return;
	}
	pa_haptic_dmd_work(DSM_VIBRATOR_ABNORMAL_ERROR);
#endif
}

#if defined(CONFIG_HUAWEI_OHOS_DSM) || defined(CONFIG_HUAWEI_DSM)
static struct error_info error_map[] = {
	{ HAPTIC_OVERHEAT, "haptic overheat,", LEVEL_WARNING },
	{ HAPTIC_V_EXCEED, "f0 voltage exceed,", LEVEL_WARNING },
	{ HAPTIC_BROKEN_CIRCUIT, "haptic broken circuit,", LEVEL_ERROR },
	{ HAPTIC_SHORT_CIRCUIT, "haptic short circuit,", LEVEL_ERROR },
	{ HAPTIC_DSP_SOFTWARE_ERR, "dsp software error,", LEVEL_FATAL },
};
 
static int haptic_bigdata_fill(void *event, haptic_bigdata *bigdata)
{
	int ret = 0;
	ret |= BIGDATA_SET_INTEGER(event, "PA_VENDOR_ID_1", bigdata->pa_vendor_id[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "MOTO_VENDOR_ID_1", bigdata->motor_vendor_id[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "PA_I_SCALE_1", bigdata->i_scale[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "PA_V_SCALE_1", bigdata->v_scale[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "PA_RE_SCALE_1", bigdata->re_scale[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "F0_CALI_1", bigdata->cali_f0[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "RE_CALI_1", bigdata->cali_r0[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "CURRENT_F0_1", bigdata->tracking_f0[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "OUTPUT_RMS_1", bigdata->output_rms[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "OUTPUT_VALID_1", bigdata->output_valid_cnt[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "OUTPUT_TOTAL_1", bigdata->output_total_cnt[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "I_RMS_1", bigdata->i_rms[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "I_VALID_1", bigdata->i_valid_cnt[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "I_TOTAL_1", bigdata->i_total_cnt[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "V_RMS_1", bigdata->v_rms[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "V_VALID_1", bigdata->v_valid_cnt[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "V_TOTAL_1", bigdata->v_total_cnt[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "V_EXCEED_CNT_1", bigdata->v_exceed_cnt[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "R_AVG_1", bigdata->r_avg[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "I_FOR_V_RMS_1", bigdata->i_rms_while_v_valid[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "OVERHEAT_CNT_1", bigdata->overheat_cnt[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "BROKEN_CIRCUIT_CNT_1", bigdata->broken_cnt[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "SHORT_CIRCUIT_CNT_1", bigdata->short_cnt[HAPTIC_0]);
	ret |= BIGDATA_SET_INTEGER(event, "PA_VENDOR_ID_2", bigdata->pa_vendor_id[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "MOTO_VENDOR_ID_2", bigdata->motor_vendor_id[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "PA_I_SCALE_2", bigdata->i_scale[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "PA_V_SCALE_2", bigdata->v_scale[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "PA_RE_SCALE_2", bigdata->re_scale[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "F0_CALI_2", bigdata->cali_f0[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "RE_CALI_2", bigdata->cali_r0[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "CURRENT_F0_2", bigdata->tracking_f0[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "OUTPUT_RMS_2", bigdata->output_rms[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "OUTPUT_VALID_2", bigdata->output_valid_cnt[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "OUTPUT_TOTAL_2", bigdata->output_total_cnt[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "I_RMS_2", bigdata->i_rms[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "I_VALID_2", bigdata->i_valid_cnt[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "I_TOTAL_2", bigdata->i_total_cnt[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "V_RMS_2", bigdata->v_rms[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "V_VALID_2", bigdata->v_valid_cnt[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "V_TOTAL_2", bigdata->v_total_cnt[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "V_EXCEED_CNT_2", bigdata->v_exceed_cnt[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "R_AVG_2", bigdata->r_avg[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "I_FOR_V_RMS_2", bigdata->i_rms_while_v_valid[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "OVERHEAT_CNT_2", bigdata->overheat_cnt[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "BROKEN_CIRCUIT_CNT_2", bigdata->broken_cnt[HAPTIC_1]);
	ret |= BIGDATA_SET_INTEGER(event, "SHORT_CIRCUIT_CNT_2", bigdata->short_cnt[HAPTIC_1]);
	return ret;
}
#endif
 
static void haptic_bigdata_process(haptic_bigdata *bigdata, int err_flag)
{
	int ret = 0, err_type = -1, i = 0;
	char desc[256] = "";
	for (i = 0; i < MAX_HAPTIC_NUM; ++i) {
		hwlog_info("%s haptic[%d] pa_vendor:%d, motor_vendor:%d",
			__func__, i, bigdata->pa_vendor_id[i], bigdata->motor_vendor_id[i]);
		hwlog_info("%s haptic[%d] cali_F0:%d, cali_R0:%d, tracking_F0:%d, R_avg(x10):%d",
			__func__, i, bigdata->cali_f0[i], bigdata->cali_r0[i], bigdata->tracking_f0[i], bigdata->r_avg[i]);
		hwlog_info("%s haptic[%d] output_rms:%d, i_rms:%d, v_rms:%d",
			__func__, i, bigdata->output_rms[i], bigdata->i_rms[i], bigdata->v_rms[i]);
		hwlog_info("%s haptic[%d] overheat:%d, V_exceed:%d, broken:%d, short:%d", __func__, i,
			bigdata->overheat_cnt[i], bigdata->v_exceed_cnt[i], bigdata->broken_cnt[i], bigdata->short_cnt[i]);
	}
	hwlog_info("%s dsp_err_code:0x%llx", __func__, bigdata->dsp_err_code);
#ifdef CONFIG_HUAWEI_DSM
	struct hiview_hievent *event = hiview_hievent_create(HAPTIC_EXCEPTION_EVENT_ID);
#elif (defined CONFIG_HUAWEI_OHOS_DSM)
	struct hiview_hisysevent *event = hisysevent_create("AUDIO", "HAPTIC_EXCEPTION", STATISTIC);
#endif
	if (!event) {
		hwlog_err("create event failed in %s", __func__);
		return;
	}

	ret = haptic_bigdata_fill((void *)event, bigdata);
	ret |= BIGDATA_SET_INTEGER(event, "DSP_ERR_CODE", bigdata->dsp_err_code);
	for (i = 0; i < ARRAY_SIZE(error_map); ++i) {
		if (err_flag & ((int)1 << i)) {
			err_type = i;
			if (snprintf_s(desc, sizeof(desc), (sizeof(desc) - 1), "%s%s", desc, error_map[i].error_message) < 0) {
				hwlog_err("%s snprintf_s fail", __func__);
				continue;
			}
		}
	}
	if (err_type != -1) {
		ret |= BIGDATA_SET_INTEGER(event, "ERROR_PHENOMENON", error_map[err_type].error_code);
		ret |= BIGDATA_SET_INTEGER(event, "ERROR_LEVEL", error_map[err_type].error_level);
		ret |= BIGDATA_SET_STRING(event, "FAULT_DESCRIPTION", desc);
	}

#ifdef CONFIG_HUAWEI_DSM
	ret |= hiview_hievent_report(event);
	hiview_hievent_destroy(event);
#elif (defined CONFIG_HUAWEI_OHOS_DSM)
	ret |= hisysevent_write(event);
	hisysevent_destroy(&event);
#endif
	hwlog_info("%s big data report, ret: %d", __func__, ret);
}
 
void haptic_bigdata_report(struct work_struct *work)
{
	struct haptic_bigdata_work_t *hw = container_of(work, struct haptic_bigdata_work_t, bigdata_work);
	if (!hw) {
		return;
	}
 
	unsigned long now = jiffies;
	int err_flag = 0;
	bool is_error_exist = false;
	if (hw->bigdata.dsp_err_code != 0) {
		is_error_exist = true;
		err_flag |= (int)1 << HAPTIC_DSP_SOFTWARE_ERR;
	}
	for (int i = 0; i < MAX_HAPTIC_NUM; ++i) {
		if (hw->bigdata.overheat_cnt[i] != 0) {
			is_error_exist = true;
			err_flag |= (int)1 << HAPTIC_OVERHEAT;
		}
		if (hw->bigdata.v_exceed_cnt[i] != 0) {
			is_error_exist = true;
			err_flag |= (int)1 << HAPTIC_V_EXCEED;
		}
		if (hw->bigdata.broken_cnt[i] != 0) {
			is_error_exist = true;
			err_flag |= (int)1 << HAPTIC_BROKEN_CIRCUIT;
		}
		if (hw->bigdata.short_cnt[i] != 0) {
			is_error_exist = true;
			err_flag |= (int)1 << HAPTIC_SHORT_CIRCUIT;
		}
	}
	// same error in 10mins not report
	if (is_error_exist && (time_after(now, hw->last_report + 10 * 60 * HZ) || (hw->err_flag != err_flag))) {
		haptic_bigdata_process(&hw->bigdata, err_flag);
		hw->last_report = now;
		hw->err_flag = err_flag;
	}
	(void)memset_s(&hw->bigdata, sizeof(haptic_bigdata), 0, sizeof(haptic_bigdata));
}
