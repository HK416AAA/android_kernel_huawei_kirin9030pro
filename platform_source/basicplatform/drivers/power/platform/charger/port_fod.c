/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: Device driver for schargerV800 waterdet
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

#include <linux/delay.h>
#include <linux/err.h>
#include <securec.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <huawei_platform/usb/hw_pd_dev.h>
#include <linux/platform_drivers/usb/hisi_typec.h>
#include "port_fod.h"

#define scharger_err(fmt, args...) pr_err("[port_fod]" fmt, ## args)
#define scharger_evt(fmt, args...) pr_warn("[port_fod]" fmt, ## args)
#define scharger_inf(fmt, args...) pr_info("[port_fod]" fmt, ## args)
#define scharger_dbg(fmt, args...) pr_debug("[port_fod]" fmt, ## args)

#define SCHARGER_10UA		10
#define POWER_BASE_DEC		10

enum port_check_source {
	PORT_CHECK_SBU1_SOURCE,
	PORT_CHECK_SBU2_SOURCE,
	PORT_CHECK_DP_SOURCE,
	PORT_CHECK_CC_RPRD,
	PORT_CHECK_CC_RDRP,
    PORT_CHECK_MAX_NUM
};

enum port_check_sorce_param {
	SORCE_NAME,
	SBU1_VOL_COL,
	SBU2_VOL_COL,
	DP_VOL_COL,
	DM_VOL_COL,
    SBU1_RES_COL,
	SBU2_RES_COL,
	DP_RES_COL,
	VUSB_COL,
	PORT_FOD_COL_MAX
};

#define CURRENT_SOURCE_NAME_LEN_MAX 32
struct scharger_fod_param {
	char source_name[CURRENT_SOURCE_NAME_LEN_MAX];
	int sbu1_vol;
	int sbu2_vol;
	int dp_vol;
	int dm_vol;
	int sbu1_res;
	int sbu2_res;
	int dp_res;
	int vusb;
};

struct scharger_fod {
	struct device *dev;
	struct scharger_fod_param fod_dts_th[PORT_CHECK_MAX_NUM];
};

static struct port_fod_ops *g_scharger_port_fod_ops = NULL;
struct scharger_fod *g_fod = NULL;

int port_fod_ops_register(struct port_fod_ops* ops)
{
	int ret = 0;

	if (g_scharger_port_fod_ops) {
		scharger_err("port_fod_ops register fail, g_scharger_port_fod_ops busy\n");
		return -EBUSY;
	}
 
	if (ops) {
		g_scharger_port_fod_ops = ops;
	} else {
		scharger_err("port_fod_ops register fail\n");
		ret = -EPERM;
	}
	return ret;
}

static int scharger_port_fod_ops_valid(void)
{
	if (g_scharger_port_fod_ops == NULL || g_scharger_port_fod_ops->ldo33_enable == NULL ||
			g_scharger_port_fod_ops->open_current_source_det == NULL ||
			g_scharger_port_fod_ops->close_current_source_det == NULL ||
			g_scharger_port_fod_ops->get_adc_value == NULL ||
			g_scharger_port_fod_ops->app_det_en == NULL) {
		scharger_err("scharger_port_fod_ops register fail\n");
		return -1;
	}
	return 0;
}

static int port_fod_open_app_en_get_dpdm_vol(struct scharger_fod_param *fod_adc)
{
	int ret = 0;

	g_scharger_port_fod_ops->app_det_en(1);
	ret = g_scharger_port_fod_ops->get_adc_value(&fod_adc->dp_vol, DP_CHL);
	ret += g_scharger_port_fod_ops->get_adc_value(&fod_adc->dm_vol, DM_CHL);
	g_scharger_port_fod_ops->app_det_en(0);
	return ret;
}

static int port_fod_open_current_source_det(
	struct scharger_fod_param *fod_adc, enum current_source_chsel source_chsel)
{
	int ret = 0;
	int vol = 0;

	if (scharger_port_fod_ops_valid())
		return -1;

	(void)memset_s(fod_adc, sizeof(fod_adc), 0, sizeof(fod_adc));

	g_scharger_port_fod_ops->ldo33_enable(1);
	ret = g_scharger_port_fod_ops->open_current_source_det(source_chsel);
	mdelay(4); /* delay 4ms */
	ret += g_scharger_port_fod_ops->get_adc_value(&vol, source_chsel);
	switch (source_chsel) {
	case SBU1_CHL:
		fod_adc->sbu1_vol = vol;
		fod_adc->sbu1_res = fod_adc->sbu1_vol / SCHARGER_10UA;
		ret += port_fod_open_app_en_get_dpdm_vol(fod_adc);
		break;
	case SBU2_CHL:
		fod_adc->sbu2_vol = vol;
		fod_adc->sbu2_res = fod_adc->sbu2_vol / SCHARGER_10UA;
		ret += port_fod_open_app_en_get_dpdm_vol(fod_adc);
		break;
	case DP_CHL:
		fod_adc->dp_vol = vol;
		fod_adc->dp_res = fod_adc->dp_vol / SCHARGER_10UA;
		break;
	default:
		scharger_err("[%s]source_chsel err:%d\n", __func__, source_chsel);
		ret = -1;
	}
	ret += g_scharger_port_fod_ops->close_current_source_det(source_chsel);
	g_scharger_port_fod_ops->ldo33_enable(0);
	if (ret != 0)
		scharger_err("[%s]fail, ret:%d\n", __func__, ret);
	return ret;
}

static int port_fod_set_cc_mode_det(struct scharger_fod_param *fod_adc, int mode)
{
	int ret = 0;

	if (scharger_port_fod_ops_valid())
		return -1;

	(void)memset_s(fod_adc, sizeof(fod_adc), 0, sizeof(fod_adc));
	hisi_usb_set_cc_diff_cfg(mode);
	g_scharger_port_fod_ops->ldo33_enable(1);
	ret = port_fod_open_app_en_get_dpdm_vol(fod_adc);
	g_scharger_port_fod_ops->ldo33_enable(0);
	hisi_usb_set_cc_mode(TYPEC_CC_DRP);
	return ret;
}

static void _port_fod_parse_dts(int col, int row,
	const char *tmp_string, struct scharger_fod *di)
{
	int idata = 0;
	errno_t err;

	switch (col) {
	case SORCE_NAME:
		err = strncpy_s(di->fod_dts_th[row].source_name, CURRENT_SOURCE_NAME_LEN_MAX,
			tmp_string, strlen(tmp_string));
		if (err != EOK) {
			pr_err("[%s]strncpy_s fail, err= %d\n", __func__, err);
			return;
		}
		break;
		case SBU1_VOL_COL:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				return;
			di->fod_dts_th[row].sbu1_vol = idata;
			break;
		case SBU2_VOL_COL:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				return;
			di->fod_dts_th[row].sbu2_vol = idata;
			break;
		case DP_VOL_COL:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				return;
			di->fod_dts_th[row].dp_vol = idata;
			break;
		case DM_VOL_COL:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				return;
			di->fod_dts_th[row].dm_vol = idata;
			break;
		case SBU1_RES_COL:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				return;
			di->fod_dts_th[row].sbu1_res = idata;
			break;
		case SBU2_RES_COL:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				return;
			di->fod_dts_th[row].sbu2_res = idata;
			break;
		case DP_RES_COL:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				return;
			di->fod_dts_th[row].dp_res = idata;
			break;
		case VUSB_COL:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				return;
			di->fod_dts_th[row].vusb = idata;
			break;
		default:
			break;
		}
}
static void port_fod_parse_dts(struct scharger_fod *di, const struct device_node *np)
{
	int i, row, col, len;
	const char *tmp_string = NULL;

	len = power_dts_read_count_strings(power_dts_tag(HWLOG_TAG), np,
 		"port_fod_th", PORT_CHECK_MAX_NUM, PORT_FOD_COL_MAX);
 	if (len < 0)
 		return;

	for (i = 0; i < len; i++) {
 		if (power_dts_read_string_index(power_dts_tag(HWLOG_TAG),
 			np, "port_fod_th", i, &tmp_string))
 			return;
 
 		row = i / PORT_FOD_COL_MAX;
 		col = i % PORT_FOD_COL_MAX;
		_port_fod_parse_dts(col, row, tmp_string, di);
		scharger_inf("source_name %s, sbu1_vol_th=%d sbu2_vol_th=%d dp_vol_th=%d dm_vol_th=%d\n",
			di->fod_dts_th[row].source_name,
			di->fod_dts_th[row].sbu1_vol, di->fod_dts_th[row].sbu2_vol,
			di->fod_dts_th[row].dp_vol, di->fod_dts_th[row].dm_vol);
        scharger_inf("sbu1_res_th=%d sbu2_res_th=%d dp_res_th=%d vusb_th=%d\n",
			di->fod_dts_th[row].sbu1_res, di->fod_dts_th[row].sbu2_res,
			di->fod_dts_th[row].dp_res, di->fod_dts_th[row].vusb);
	}
}

static bool pd_port_check_value(int source)
{
    struct scharger_fod_param fod_adc = {0};
    int ret;

    switch (source) {
    case PORT_CHECK_SBU1_SOURCE:
        ret = port_fod_open_current_source_det(&fod_adc, SBU1_CHL);
		break;
    case PORT_CHECK_SBU2_SOURCE:
		ret = port_fod_open_current_source_det(&fod_adc, SBU2_CHL);
		break;
    case PORT_CHECK_DP_SOURCE:
		ret = port_fod_open_current_source_det(&fod_adc, DP_CHL);
		break;
    case PORT_CHECK_CC_RPRD:
		ret = port_fod_set_cc_mode_det(&fod_adc, TYPEC_CC1_RP_CC2_RD);
		break;
    case PORT_CHECK_CC_RDRP:
		ret = port_fod_set_cc_mode_det(&fod_adc, TYPEC_CC1_RD_CC2_RP);
		break;
    default:
        scharger_err("%s invalid source = %d\n", __func__, source);
        return false;
    };
    if (ret) {
        scharger_err("%s fail, source = %d\n", __func__, source);
        return false;
    }

	scharger_inf("fod_adc[%d] sbu1_vol=%d sbu2_vol=%d dp_vol=%d dm_vol=%d\n", source,
			fod_adc.sbu1_vol, fod_adc.sbu2_vol, fod_adc.dp_vol, fod_adc.dm_vol);
	scharger_inf("fod_adc[%d] sbu1_res=%d sbu2_res=%d dp_res=%d vusb=%d\n", source,
			fod_adc.sbu1_res, fod_adc.sbu2_res, fod_adc.dp_res, fod_adc.vusb);

	if (source == PORT_CHECK_DP_SOURCE) {
		if (fod_adc.dp_vol < g_fod->fod_dts_th[source].dp_vol ||
			fod_adc.dp_res < g_fod->fod_dts_th[source].dp_res)
			return true;
		return false;
	}
	if (fod_adc.sbu1_vol < g_fod->fod_dts_th[source].sbu1_vol ||
		fod_adc.sbu2_vol < g_fod->fod_dts_th[source].sbu2_vol ||
		fod_adc.dp_vol > g_fod->fod_dts_th[source].dp_vol ||
		fod_adc.dm_vol > g_fod->fod_dts_th[source].dm_vol ||
		fod_adc.sbu1_res < g_fod->fod_dts_th[source].sbu1_res ||
		fod_adc.sbu2_res < g_fod->fod_dts_th[source].sbu2_res ||
		fod_adc.dp_res < g_fod->fod_dts_th[source].dp_res)
		return true;
	return false;
}

/* true: fod; false: no fod */
static bool is_port_fod_state(void)
{
	int no_fod_count = 0;
	int i;

	for (i = 0; i < PORT_CHECK_MAX_NUM; i++) {
		if (!pd_port_check_value(i)) {
			scharger_inf("%s %s test is no foreign object\n", __func__,
				g_fod->fod_dts_th[i].source_name);
			no_fod_count++;
		} else {
			scharger_inf("%s %s test is foreign object\n", __func__,
				g_fod->fod_dts_th[i].source_name);
		}
	}
	if (no_fod_count == PORT_CHECK_MAX_NUM)
		return false;
	return true;
}

static struct fod_ops det_ops = {
	.is_fod_state = is_port_fod_state,
};

static int scharger_port_fod_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct scharger_fod *fod = NULL;
	int ret = 0;

	fod = devm_kzalloc(dev, sizeof(*fod), GFP_KERNEL);
	if (fod == NULL) {
		scharger_err("[%s]wdg is null.\n", __func__);
		return -ENOMEM;
	}

	fod->dev = dev;
    port_fod_parse_dts(fod, dev->of_node);
    g_fod = fod;

	ret = fod_ops_register(&det_ops);
	scharger_inf("[%s] ret %d\n", __func__, ret);

	return ret;
}

static void scharger_port_fod_shutdown(struct platform_device *pdev)
{
}

static const struct of_device_id scharger_port_fod_of_match[] = {
	{
		.compatible = "hisilicon,scharger-port-fod",
		.data = NULL
	},
	{},
};

static struct platform_driver scharger_port_fod_driver = {
	.probe = scharger_port_fod_probe,
	.shutdown = scharger_port_fod_shutdown,
	.driver = {
		.name = "scharger-port-fod",
		.owner = THIS_MODULE,
		.of_match_table = scharger_port_fod_of_match,
	},
};

static int __init scharger_port_fod_init(void)
{
	platform_driver_register(&scharger_port_fod_driver);
	return 0;
}

static void __exit scharger_port_fod_exit(void)
{
	platform_driver_unregister(&scharger_port_fod_driver);
}
module_init(scharger_port_fod_init);
module_exit(scharger_port_fod_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("scharger port fod driver");