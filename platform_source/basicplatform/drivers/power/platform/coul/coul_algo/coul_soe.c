/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: coul_soe.c
 *
 * smartstar coulometer functions
 *
 * This software is licensed under the terms of the GNU General Public
 * License, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <platform_include/basicplatform/linux/power/platform/coul/coul_merge_drv.h>
#include <platform_include/basicplatform/linux/power/platform/battery_data.h>
#include <platform_include/basicplatform/linux/power/platform/coul/coul_core.h>
#include "coul_soe.h"

#define coul_soe_info(fmt, args...) pr_info("[coul_soe]" fmt, ## args)
#define coul_soe_err(fmt, args...) pr_err("[coul_soe]" fmt, ## args)

static int coul_check_charge_status_change(struct soe_information *soe_info)
{
    if (soe_info->soe_para.current_ua <= 0)
        soe_info->curr_charge_status = SOE_CHARGE;
    else if (soe_info->soe_para.current_ua > 0 && soe_info->soe_para.charging_state == CHARGING_STATE_CHARGE_UNKNOW)
        soe_info->curr_charge_status = SOE_START;
    else
        soe_info->curr_charge_status = SOE_DISCHARGE;

    if (soe_info->curr_charge_status != soe_info->last_charge_status) {
        soe_info->last_charge_status = soe_info->curr_charge_status;
        return 1;
    }
    return 0;
}

/* calculate capcity when soe 2 soc */
static void coul_cal_soe_capacity_charging(struct soe_information *soe_info, int delta_cap)
{
    if (!soe_info->adjust_flag) {
        soe_info->soe_para.capacity_1000x = soe_info->soe_para.soc * PERMILLAGE;
        return;
    } else
        soe_info->soe_para.capacity_1000x += delta_cap;

    if (DIV_ROUND_CLOSEST(soe_info->soe_para.capacity_1000x, PERMILLAGE) >= soe_info->soe_para.soc) {
        soe_info->adjust_flag = 0;
        soe_info->soe_para.capacity_1000x = soe_info->soe_para.soc * PERMILLAGE;
    }
}

/* calculate capcity when soc 2 soe */
static void coul_calc_capacity_discharging(struct soe_information *soe_info, int delta_cap)
{
    if (!soe_info->adjust_flag) {
        soe_info->soe_para.capacity_1000x = soe_info->soe_para.soe * PERMILLAGE;
        return;
    } else
        soe_info->soe_para.capacity_1000x -= delta_cap;

    if (DIV_ROUND_CLOSEST(soe_info->soe_para.capacity_1000x, PERMILLAGE) <= soe_info->soe_para.soe) {
        soe_info->adjust_flag = 0;
        soe_info->soe_para.capacity_1000x = soe_info->soe_para.soe * PERMILLAGE;
    }
}

static int coul_calculate_delta_cap(struct soe_information *soe_info, int delta_time)
{
    int count, time_to_smooth, cap_to_smooth_real, delta_cap;
    int cap_to_smooth_est = soe_info->soe_para.fcc_uah * DELTA_SOE_SMOOTH / PERCENT;

    if ((soe_info->soe_para.current_ua == 0) || (soe_info->soe_para.fcc_uah - soe_info->soe_para.rm_uah < 0) ||
        (soe_info->soe_para.rm_uah - soe_info->soe_para.uuc_uah < 0))
        return DELTA_SOE_PC_DEFAULT;

    if (soe_info->curr_charge_status == SOE_CHARGE) {
        cap_to_smooth_real = (soe_info->soe_para.fcc_uah - soe_info->soe_para.rm_uah > cap_to_smooth_est)
                               ? cap_to_smooth_est : (soe_info->soe_para.fcc_uah - soe_info->soe_para.rm_uah);
        time_to_smooth = (int)((s64)cap_to_smooth_real * SEC_PER_HOUR /
                      (s64)abs(soe_info->soe_para.current_ua));
        count = time_to_smooth / (delta_time * CHARGE_COUNT_COE);
    } else {
        cap_to_smooth_real = (soe_info->soe_para.rm_uah - soe_info->soe_para.uuc_uah > cap_to_smooth_est)
                               ? cap_to_smooth_est : (soe_info->soe_para.rm_uah - soe_info->soe_para.uuc_uah);
        time_to_smooth = (int)((s64)cap_to_smooth_real * SEC_PER_HOUR /
                      (s64)abs(soe_info->soe_para.current_ua));
        count = time_to_smooth / (delta_time * DISCHARGE_COUNT_COE);
    }
    if (count == 0)
        return DELTA_SOE_PC_DEFAULT;

    delta_cap = abs(soe_info->soe_para.soc - soe_info->soe_para.soe) * DELTA_SOE_GAIN / count;
    delta_cap = (delta_cap > PERMILLAGE) ? PERMILLAGE : delta_cap;
    coul_core_info("%s, batt_index=%d, cap_to_smooth_real=%d , time_to_smooth=%d, count=%d, delta_cap=%d\n", __func__,
    soe_info->soe_para.index, cap_to_smooth_real, time_to_smooth, count, delta_cap);
    return delta_cap;
}

static int coul_limit_capacity(struct soe_information *soe_info)
{
    soe_info->soe_para.capacity_1000x = max(soe_info->soe_para.soe * PERMILLAGE, soe_info->soe_para.capacity_1000x);
    soe_info->soe_para.capacity_1000x = min(soe_info->soe_para.soc * PERMILLAGE, soe_info->soe_para.capacity_1000x);
    soe_info->soe_para.capacity_1000x = max(0, soe_info->soe_para.capacity_1000x);
    soe_info->soe_para.capacity_1000x = min(SOC_FULL * PERMILLAGE, soe_info->soe_para.capacity_1000x);
    coul_soe_info("batt is %d, adjust_flag is %d, curr_charge_status is %d, last_charge_status is %d\n",
        soe_info->soe_para.index, soe_info->adjust_flag,
        soe_info->curr_charge_status, soe_info->last_charge_status);
    return soe_info->soe_para.capacity_1000x;
}

static int coul_get_batt_capacity(struct soe_information *soe_info)
{
    int delta_cap;
    u64 time_now = dfx_getcurtime() / NSEC_PER_SEC;
    int delta_time = (int)(time_now - soe_info->last_calc_time);

    soe_info->last_calc_time = time_now;
    if (soe_info->first_in)
        soe_info->soe_para.capacity_1000x = soe_info->soe_para.ui_soc * PERMILLAGE;

    soe_info->first_in = FALSE;

    if (delta_time <= 0)
        return soe_info->soe_para.capacity_1000x;

    if (coul_check_charge_status_change(soe_info))
        soe_info->adjust_flag = 1;

    delta_cap = coul_calculate_delta_cap(soe_info, delta_time);
    switch (soe_info->curr_charge_status) {
        case SOE_CHARGE:
            coul_cal_soe_capacity_charging(soe_info, delta_cap);
            break;
        case SOE_START:
        case SOE_DISCHARGE:
            coul_calc_capacity_discharging(soe_info, delta_cap);
            break;
        default:
            break;
    }
    return coul_limit_capacity(soe_info);
}

int coul_calc_soe_cap(struct soe_params *soe_params, struct soe_information *soe_info, int *soe_value)
{
    s64 soe_10x, soc_10x;
    soc_10x = (s64)soe_info->soe_para.soc_10x;
    /* soe = a * soc^3 + b * soc^2 + c * soc + d
           = a * (soc_10x / 10)^3 + b * (soc_10x / 10)^2 + c * (soc_10x / 10) + d
        soe / 1000 = a * soc_10x^3 + 10 * b * soc_10x^2 + 100 * c * soc_10x + 1000 * d
    */
    soe_10x = (s64)soe_params->a * soc_10x * soc_10x * soc_10x + (s64)soe_params->b * soc_10x * soc_10x * TENTH +
          (s64)soe_params->c * soc_10x * PERCENT + (s64)soe_params->d * PERMILLAGE;
    *soe_value = (int)(soe_10x / SOE_PARAMS_GAIN / PERMILLAGE);
    soe_info->soe_para.soe = *soe_value;
    coul_core_info("%s, soe=%d\n", __func__, *soe_value);
    return coul_get_batt_capacity(soe_info);
}

static void coul_soe_info_init(struct soe_information *soe_info)
{
    soe_info->first_in = TRUE;
    soe_info->adjust_flag = 1;
    soe_info->last_calc_time = dfx_getcurtime() / NSEC_PER_SEC;
    soe_info->curr_charge_status = SOE_UNKNOW;
    soe_info->last_charge_status = SOE_UNKNOW;
}

void coul_soe_initial(int batt_index, struct soe_params *soe_param, struct soe_information *soe_info)
{
    if ((soe_info->force_enable == 0) && (soe_info->dynamic_enable == 0))
        return;
    
    coul_soe_info_init(soe_info);
    if (soe_param == NULL) {
        coul_soe_err("%s soe_param is NULL!\n", __func__);
        return;
    }
    if (batt_index < 0 || batt_index >= BATT_MAX)
        goto default_params;
    if (soe_param->a < 0 || soe_param->a >= SOE_PARAMS_GAIN)
        goto default_params;
    if (soe_param->b <= -SOE_PARAMS_GAIN || soe_param->b >= SOE_PARAMS_GAIN)
        goto default_params;
    if (soe_param->c <= -SOE_PARAMS_GAIN || soe_param->c >= SOE_PARAMS_GAIN)
        goto default_params;
    if (soe_param->d <= -SOE_PARAMS_GAIN || soe_param->d >= SOE_PARAMS_GAIN)
        goto default_params;

    coul_soe_info("%s a:%d, b:%d, c:%d, d:%d\n",
        __func__, soe_param->a, soe_param->b, soe_param->c, soe_param->d);
    return;
default_params:
    soe_param->a = 0;
    soe_param->b = 0;
    soe_param->c = SOE_PARAMS_GAIN;
    soe_param->d = 0;
    coul_soe_info("%s use default params!\n", __func__);
}
static bool charge_profile_fifo_add(struct smartstar_coul_device *di, char value)
{
	if (di->soe_info.dynamic_soe_charge_profile_index >= SOE_STATUS_FIFO_DEPTH) {
		coul_core_err("%s, dynamic_soe_charge_profile_index error\n", __func__);
		return false;
	}

	di->soe_info.dynamic_soe_charge_profile_fifo[di->soe_info.dynamic_soe_charge_profile_index++] = value;
	di->soe_info.dynamic_soe_charge_profile_index = (int)di->soe_info.dynamic_soe_charge_profile_index % SOE_STATUS_FIFO_DEPTH;

	return true;
}

static bool check_low_capacity_charge_for_soe(struct smartstar_coul_device *di)
{
	int ret, delta_soc;
	char vaule;

    delta_soc = di->batt_soc_real - di->charging_begin_soc;
    delta_soc /= TENTH;
	if (delta_soc < di->soe_info.min_delta_cap)
		return false;

	vaule = ((di->charging_begin_soc / TENTH) < di->soe_info.start_cap) ? SOE_USING_VAILD_NUMBER : SOE_USING_INVAILD_NUMBER;

	return charge_profile_fifo_add(di, vaule);
}

static bool check_charge_profile_fifo_valid_for_soe(struct smartstar_coul_device *di)
{
	int i;
	int cnt = 0;

	for (i = 0; i < SOE_STATUS_FIFO_DEPTH; i++) {
		if (di->soe_info.dynamic_soe_charge_profile_fifo[i] == SOE_USING_VAILD_NUMBER)
			cnt++;
	}

	return (cnt >= SOE_STATUS_VAILD_MIN_COUNT);
}

void coul_check_dynamic_soe_enable_status(struct smartstar_coul_device *di)
{
	if (di == NULL) {
		coul_core_err("NULL point in [%s]\n", __func__);
		return;
	}

	if (di->soe_info.force_enable || di->soe_info.dynamic_soe_status || !check_low_capacity_charge_for_soe(di))
		return;

	if (check_charge_profile_fifo_valid_for_soe(di)) {
		di->soe_info.dynamic_soe_status = COUL_SOE_USING_ENABLE;
		di->soe_info.first_in = TRUE;
 		di->soe_info.adjust_flag = 1;
		di->soe_info.curr_charge_status = SOE_DISCHARGE;
		di->soe_info.last_charge_status = SOE_CHARGE;
		di->soe_info.last_calc_time = dfx_getcurtime() / NSEC_PER_SEC;
	}

	coul_core_info("%s, charging_begin_soc=%d, charging_stop_soc=%d, index=%d\n",
		__func__, di->charging_begin_soc / TENTH, di->batt_soc,
		di->soe_info.dynamic_soe_charge_profile_index);
}

bool coul_is_soe_used(struct smartstar_coul_device *di)
{
	return di->soe_info.force_enable ||
		((di->soe_info.dynamic_enable) && (di->soe_info.dynamic_soe_status == COUL_SOE_USING_ENABLE));
}