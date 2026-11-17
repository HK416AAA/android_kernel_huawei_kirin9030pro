/* Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * All rights reserved.
 * Description: Interface between the matting algo module and ALSC module for calculating noise
 * Author: yangxiaopeng@huawei.com
 * Create: 2024-9-1
 */

#include "als_matting_algo.h"
#include "dkmd_alsc_interface.h"
#include <huawei_platform/log/hw_log.h>
#include <linux/err.h>
#include "matting_algo_hisi_alsc_interface.h"
#include "matting_algo_task.h"
#include <securec.h>

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif

#define HWLOG_TAG matting_algo_task
HWLOG_REGIST();

#define MATTING_ALGO_DKMD_ALSC_DEF_SENSOR_CHANNEL	(1)
#define MATTING_ALGO_SCREEN_FOV_SHIFT_8BIT			(8)
#define MATTING_ALGO_SCREEN_FOV_SHIFT_13BIT			(13)
#define MATTING_ALGO_SCREEN_FOV_SHIFT_16BIT			(16)
#define MATTING_ALGO_SCREEN_FOV_PIXEL_ONE			(1)
#define MULTIPLES_65536								(65536)
#define MATTING_ALGO_SCREEN_FOV_COORDINATE_RTS		(0x15A019)
#define MATTING_ALGO_SCREEN_FOV_WIDTHHIGHT			(0x2C2C)

#ifndef MATTING_ALGO_ALSC_ENABLE
#define MATTING_ALGO_ALSC_ENABLE (1)
#endif

static struct dkmd_alsc matting_algo_hisi_dss_alsc_init = {
	.alsc_en = MATTING_ALGO_ALSC_ENABLE,
	.sensor_channel = MATTING_ALGO_DKMD_ALSC_DEF_SENSOR_CHANNEL,
	.addr = MATTING_ALGO_SCREEN_FOV_COORDINATE_RTS,
	.size = MATTING_ALGO_SCREEN_FOV_WIDTHHIGHT,
	.bl_param = { 0 },
	.addr_block = {
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	},
	.ave_block = {
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
    },
	.coef_block_r = {
		0xFFFFFFFF, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	},
	.coef_block_g = {
		0xFFFFFFFF, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	},

	.coef_block_b = {
		0xFFFFFFFF, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	},

	.coef_block_c = {
		0xFFFFFFFF, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	},
	.degamma_coef = { 0 }
};

static struct alsc_bl_param g_bl_param;
static struct alsc_bl_param g_bl_param_old;

static struct alsc_noise g_als_noise_old = {
	.status    = 0,
	.noise1    = 0,
	.noise2    = 0,
	.noise3    = 0,
	.noise4    = 0,
	.timestamp = 0,
};

void matting_algo_clear_bl_param_old(void)
{
	errno_t err;

	err = memset_s(&g_bl_param_old, sizeof(g_bl_param_old), 0, sizeof(g_bl_param_old));
	if (err != EOK) {
		hwlog_err("%s: memset_s return %d\n", __func__, err);
		return;
	}
}

void matting_algo_clear_als_noise_old(void)
{
	errno_t err;

	err = memset_s(&g_als_noise_old, sizeof(g_als_noise_old), 0, sizeof(g_als_noise_old));
	if (err != EOK) {
		hwlog_err("%s: memset_s return %d\n", __func__, err);
		return;
	}
}

static int matting_algo_update_alsc_bl_param(uint64_t max_noise[][RGB_CURVE], uint32_t panel_id)
{
	errno_t err;
	int ret = EC_FAILURE;

	err = memset_s(&g_bl_param, sizeof(g_bl_param), 0, sizeof(g_bl_param));
	if (err != EOK) {
		hwlog_err("%s: memset_s return %d\n", __func__, err);
		return ret;
	}

	// r picture 0 channel
	g_bl_param.coef_r2r = (uint32_t)max_noise[INDEX_ZERO][INDEX_ZERO];
	// g picture 0 channel
	g_bl_param.coef_g2r = (uint32_t)max_noise[INDEX_ZERO][INDEX_ONE];
	// b picture 0 channel
	g_bl_param.coef_b2r = (uint32_t)max_noise[INDEX_ZERO][INDEX_TWO];
	// r picture 1 channel
	g_bl_param.coef_r2g = (uint32_t)max_noise[INDEX_ONE][INDEX_ZERO];
	// g picture 1 channel
	g_bl_param.coef_g2g = (uint32_t)max_noise[INDEX_ONE][INDEX_ONE];
	// b picture 1 channel
	g_bl_param.coef_b2g = (uint32_t)max_noise[INDEX_ONE][INDEX_TWO];

	if (!memcmp(&g_bl_param_old, &g_bl_param, sizeof(g_bl_param))) {
		return EC_SUCCESS;
	}

	err = memcpy_s(&g_bl_param_old, sizeof(g_bl_param_old), &g_bl_param, sizeof(g_bl_param));
	if (err != EOK) {
		hwlog_err("%s: memcpy_s return %d\n", __func__, err);
		return ret;
	}

	ret = dkmd_alsc_update_bl_param(&g_bl_param, panel_id);
	if (ret != EC_SUCCESS) {
		hwlog_err("[%s] update bl param return %d\n", __func__, ret);
	}
	dkmd_alsc_refresh(panel_id);

	return ret;
}

struct alsc_bl_param *matting_algo_get_alsc_bl_param(void)
{
	return &g_bl_param;
}

void matting_algo_send_alsc_bl_param(uint32_t brightness)
{
	int ret;

	uint64_t max_noise[DISPLAY_ALS_CHANNEL_MAX][RGB_CURVE];

	if (brightness > NORMAL_MAX_BRIGHTNESS) {
		brightness = NORMAL_MAX_BRIGHTNESS;
	}

	alg_mat_dbv_curve_calc(brightness, max_noise, false);

	ret = matting_algo_update_alsc_bl_param(max_noise, DPU_PANEL_ID_INNER);
	if (ret != EC_SUCCESS) {
		hwlog_err("[%s] update bl param return %d\n", __func__, ret);
	}
}

void matting_algo_get_noise_from_alsc(struct alsc_noise *als_noise, uint32_t panel_id)
{
	int32_t ret;

	if (als_noise == NULL) {
		hwlog_err("[%s] alsc_noise is NULL ptr.\n", __func__);
		return;
	}

	g_als_noise_old.status = als_noise->status;
	g_als_noise_old.noise1 = als_noise->noise1;
	g_als_noise_old.noise2 = als_noise->noise2;
	g_als_noise_old.noise3 = als_noise->noise3;
	g_als_noise_old.noise4 = als_noise->noise4;
	g_als_noise_old.timestamp = als_noise->timestamp;

	ret = matting_algo_send_als_noise_to_algo_module(&g_als_noise_old, panel_id);
	if (ret != EC_SUCCESS) {
		hwlog_debug("[%s] send noise to algo module return %d\n", __func__, ret);
	}
}

void matting_algo_als_gamma_set_alpha(uint32_t alpha, uint32_t panel_id)
{
}

static uint32_t matting_algo_get_fov_window_addr(void)
{
    uint32_t fov_addr = 0;
	// Indicates the address of a global or static variable. The pointer is not null, null judgment is not required.
	struct alg_matting_data_param_info_st *data_param_info = matting_algo_get_data_param_info();

    fov_addr = (data_param_info->offset_y << MATTING_ALGO_SCREEN_FOV_SHIFT_13BIT) | data_param_info->offset_x;
    return fov_addr;
}

static uint32_t matting_algo_get_fov_window_size(void)
{
	// Indicates the address of a global or static variable. The pointer is not null, null judgment is not required.
	struct alg_matting_data_param_info_st *data_param_info = matting_algo_get_data_param_info();
    uint32_t width = data_param_info->fov_width;
    uint32_t height = data_param_info->fov_height;
    uint32_t fov_size = 0;

    if (width < MATTING_ALGO_SCREEN_FOV_PIXEL_ONE) {
        width = MATTING_ALGO_SCREEN_FOV_PIXEL_ONE;
    }

    if (height < MATTING_ALGO_SCREEN_FOV_PIXEL_ONE) {
        height = MATTING_ALGO_SCREEN_FOV_PIXEL_ONE;
    }

    fov_size = ((height - MATTING_ALGO_SCREEN_FOV_PIXEL_ONE) << MATTING_ALGO_SCREEN_FOV_SHIFT_8BIT) | \
                (width - MATTING_ALGO_SCREEN_FOV_PIXEL_ONE);
    return fov_size;
}

static void matting_algo_alsc_bl_param_init(void)
{
    errno_t err;
    uint32_t brightness = 0;
	uint64_t max_noise[DISPLAY_ALS_CHANNEL_MAX][RGB_CURVE];

	brightness = matting_algo_get_current_brightness();
	if (brightness > NORMAL_MAX_BRIGHTNESS) {
		brightness = NORMAL_MAX_BRIGHTNESS;
	}

	alg_mat_dbv_curve_calc(brightness, max_noise, false);

    err = memset_s(&matting_algo_hisi_dss_alsc_init.bl_param, sizeof(struct alsc_bl_param), 0,
					sizeof(struct alsc_bl_param));
    if (err != EOK) {
		hwlog_err("[%s] memset_s bl_param return %d\r\n", __func__, err);
        return;
    }

    // r picture 0 channel
    matting_algo_hisi_dss_alsc_init.bl_param.coef_r2r = (uint32_t)max_noise[INDEX_ZERO][INDEX_ZERO];
    // g picture 0 channel
    matting_algo_hisi_dss_alsc_init.bl_param.coef_g2r = (uint32_t)max_noise[INDEX_ZERO][INDEX_ONE];
    // b picture 0 channel
    matting_algo_hisi_dss_alsc_init.bl_param.coef_b2r = (uint32_t)max_noise[INDEX_ZERO][INDEX_TWO];
    // r picture 1 channel
    matting_algo_hisi_dss_alsc_init.bl_param.coef_r2g = (uint32_t)max_noise[INDEX_ONE][INDEX_ZERO];
    // g picture 1 channel
    matting_algo_hisi_dss_alsc_init.bl_param.coef_g2g = (uint32_t)max_noise[INDEX_ONE][INDEX_ONE];
    // b picture 1 channel
    matting_algo_hisi_dss_alsc_init.bl_param.coef_b2g = (uint32_t)max_noise[INDEX_ONE][INDEX_TWO];
}

static void matting_algo_alsc_param_addr_block_init(void)
{
	errno_t err;
    uint32_t max_dest_len = ALSC_BLOCK_LEN * sizeof(uint32_t);
	uint32_t fov_size = matting_algo_get_fov_window_size();

    err = memset_s(matting_algo_hisi_dss_alsc_init.addr_block, max_dest_len, 0, max_dest_len);
    if (err != EOK) {
		hwlog_err("[%s] memset_s addr_block return %d\n", __func__, err);
        return;
    }

    matting_algo_hisi_dss_alsc_init.addr_block[0] = fov_size << MATTING_ALGO_SCREEN_FOV_SHIFT_16BIT;
}

static void matting_algo_alsc_param_ave_block_init(void)
{
    errno_t err;
    // Indicates the address of a global or static variable. The pointer is not null, null judgment is not required.
	struct alg_matting_data_param_info_st *data_param_info = matting_algo_get_data_param_info();
    uint32_t width = data_param_info->fov_width;
    uint32_t height = data_param_info->fov_height;

    err = memset_s(matting_algo_hisi_dss_alsc_init.ave_block, sizeof(matting_algo_hisi_dss_alsc_init.ave_block), 0,
                   sizeof(matting_algo_hisi_dss_alsc_init.ave_block));
    if (err != EOK) {
		hwlog_err("[%s] memset_s ave_block return %d\r\n", __func__, err);
        return;
    }

    if ((width == 0) || (height == 0)) {
		hwlog_err("[%s] width=%u or height=%u is 0\r\n", __func__, width, height);
        return;
    }

    matting_algo_hisi_dss_alsc_init.ave_block[0] = MULTIPLES_65536 / height / width;
}

static void matting_algo_alsc_param_init(void)
{
	errno_t err;
	uint32_t dest_degamma_coef_len = ALSC_DEGAMMA_COEF_LEN * sizeof(uint32_t);
	uint32_t src_gamma_table_len = GAMMA_TABLE_SIZE * sizeof(uint32_t);
	uint32_t *gamma_table = matting_algo_get_gamma_table();

	matting_algo_hisi_dss_alsc_init.addr = matting_algo_get_fov_window_addr();
    matting_algo_hisi_dss_alsc_init.size = matting_algo_get_fov_window_size();

	matting_algo_alsc_bl_param_init();
    matting_algo_alsc_param_addr_block_init();
    matting_algo_alsc_param_ave_block_init();

	err = memcpy_s(matting_algo_hisi_dss_alsc_init.degamma_coef.r_coef,
					dest_degamma_coef_len, gamma_table, src_gamma_table_len);
	if (err != EOK) {
		hwlog_err("[%s] copy r_coef gamma table return %d\n", __func__, err);
		return;
	}

	err = memcpy_s(matting_algo_hisi_dss_alsc_init.degamma_coef.g_coef,
					dest_degamma_coef_len, gamma_table, src_gamma_table_len);
	if (err != EOK) {
		hwlog_err("[%s] copy g_coef gamma table return %d\n", __func__, err);
		return;
	}

	err = memcpy_s(matting_algo_hisi_dss_alsc_init.degamma_coef.b_coef,
					dest_degamma_coef_len, gamma_table, src_gamma_table_len);
	if (err != EOK) {
		hwlog_err("[%s] copy b_coef gamma table return %d\n", __func__, err);
		return;
	}
}

void matting_algo_als_alsc_expand_status_config(void)
{
	int32_t ret = 0;
	static bool als_alsc_expand_status_config = false;

	if (!get_alg_matting_data_param_valid()) {
		hwlog_info("[%s] not receive data param from mcu, so return.\n", __func__);
		return;
	}

	if (als_alsc_expand_status_config) {
		hwlog_info("[%s] no repeated initialization is required.\n", __func__);
		return;
	}
	als_alsc_expand_status_config = true;

	matting_algo_alsc_param_init();

	ret = dkmd_alsc_param_init(&matting_algo_hisi_dss_alsc_init, DPU_PANEL_ID_INNER);
	if (ret != EC_SUCCESS) {
		hwlog_err("[%s] copy b_coef gamma table return %d\n", __func__, ret);
		return;
	}

	ret = dkmd_alsc_register_cb_func((void *)matting_algo_get_noise_from_alsc,
									(void *)matting_algo_als_gamma_set_alpha);
	if (ret != EC_SUCCESS) {
		hwlog_err("dss_alsc_register_cb fail\n");
		return;
	}
}
