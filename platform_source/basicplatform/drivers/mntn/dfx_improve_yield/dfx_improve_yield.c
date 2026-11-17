/* dfx_improve_yield.c
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
#include "dfx_improve_yield.h"
#include "mntn_subtype_exception.h"
#include <vcodec_improve_yield.h>
#include <improve_yield_cpu_info.h>
#include <gpu_nv_data.h>
#include "improve_yield_info.h"
#include "improve_yield_internal.h"
#include "cpu_improve_yield.h"
#include "rdr_inner.h"
#include "../blackbox/diaginfo/bbox_diaginfo.h"
#include "../../mm_lb/v550/mm_lb_improve_yield.h"
#include <securec.h>
#include <platform_include/basicplatform/linux/rdr_platform.h>
#include <platform_include/basicplatform/linux/dfx_diaginfo_baseinfo.h>
#include <platform_include/basicplatform/linux/dfx_hw_diag.h>
#include <platform_include/basicplatform/linux/improve_yield.h>
#include <platform_include/basicplatform/linux/hw_cmdline_parse.h>
#include <platform_include/display/linux/dpu_improve_yield.h>
#include <linux/cpu.h>
#include <cpu_cluster_def.h>

/* check panic type whether is accord with sh panic conditions or not */
#if defined(CONFIG_DFX_IMPROVE_YIELD) && defined(CONFIG_FACTORY_MODE)
static bool is_sh_panic_type(void)
{
    int i;
    struct excep_type_and_subtype sh_panic_type[] = {
        {AP_S_PANIC, HI_APPANIC_RESERVED},
        {AP_S_PANIC, HI_APPANIC_DATA_ABORT},
        {AP_S_PANIC, HI_APPANIC_INSTRU_ABORT},
        {AP_S_PANIC, HI_APPANIC_SERROR},
        {HM_PANIC, HM_PANIC_KERNEL},
        {HM_PANIC, HM_PANIC_SYSMGR},
        {HM_PANIC, HM_PANIC_DEVHOST},
        {HM_PANIC, HM_PANIC_LOWDOG},
        {HM_PANIC, HM_PANIC_HARDDOG},
        {AP_S_AWDT, EXCEP_SUBTYPE_ANY},
        {LPM3_S_LPMCURST, EXCEP_SUBTYPE_ANY},
    };

    u32 rdr_subtype = rdr_get_exec_subtype_value();
    u32 reboot_type = rdr_get_reboot_type();

    PRINT_FUNC_AND_LINE;
    pr_err("reboot_type=%x,rdr_subtype=%x\n", reboot_type, rdr_subtype);
    for (i = 0; i < sizeof(sh_panic_type) / sizeof(struct excep_type_and_subtype); i++) {
        if (reboot_type != sh_panic_type[i].reboot_type) {
            continue;
        }
        if (sh_panic_type[i].exce_subtype == EXCEP_SUBTYPE_ANY || sh_panic_type[i].exce_subtype == rdr_subtype)
            return true;
    }

    if (reboot_type == AP_S_PANIC && IS_CPU_UE_SUBTYPE(rdr_subtype))
        return true;

    return false;
}

#ifdef IMPROVE_YIELD_CHS
static bool is_m1_exc_type(void)
{
#ifdef CONFIG_DFX_SEC_QIC_V300
	struct dfx_diag_qic_info *qic_info;
	qic_info = dfx_hw_diag_get_qic_info();
	if (IS_ERR_OR_NULL(qic_info))
		return false;

	pr_info("dfx_sh check dss exc, qic_buskey 0x%X, mid 0x%X, err_addr 0x%lX\n",
			qic_info->buskey, qic_info->mid, qic_info->err_address);
	if (qic_info->mid == QIC_DSS_EXC_MID &&
		qic_info->err_address == QIC_DSS_EXC_ADDR)
		return true;
#endif
	return false;
}
#endif

static bool is_app_panic_type(void)
{
    int i;
    struct excep_type_and_subtype app_panic_type[] = {
        {AP_S_PANIC, HI_APPANIC_HUNGTASK},
        {HM_PANIC, HM_PANIC_INJECT},
        {HM_PANIC, HGUARD_DEADLOCK},
        {HM_PANIC, HGUARD_USER_CONFIG},
        {HM_PANIC, HM_PANIC_HIGHDOG},
    };

    u32 rdr_subtype = rdr_get_exec_subtype_value();
    u32 reboot_type = rdr_get_reboot_type();
    PRINT_FUNC_AND_LINE;
    pr_err("reboot_type=%x,rdr_subtype=%x\n", reboot_type, rdr_subtype);
    for (i = 0; i < sizeof(app_panic_type) / sizeof(struct excep_type_and_subtype); i++) {
        if (reboot_type != app_panic_type[i].reboot_type) {
            continue;
        }
        if (app_panic_type[i].exce_subtype == rdr_subtype)
            return true;
    }

    return false;
}

static void cpu_panic_improve_yield_set_pvflag(int cluster)
{
    int ret;
    improve_yield_cpu_panic_nv_t cpu_info;

    if (cluster < CPU_LIT_CLUSTER || cluster >= CPU_CLUSTER_CNT) {
        pr_err("panic cluster %d is invalid\n", cluster);
        return;
    }

    ret = get_improve_yield_nv_info(MODULE_ID_CPU_PANIC, (char *)&cpu_info, sizeof(improve_yield_cpu_panic_nv_t));
    if (ret != 0) {
        pr_err("[%s %d]: get improve yield cpu panic info fail, ret:%d\n", __func__, __LINE__, ret);
        return;
    }

    cpu_info.cluster_panic_info[cluster].bits.pv_flag = 1; /* panic hanpened on cluster, set flag */

    PRINT_FUNC_AND_LINE;
    ret = set_improve_yield_nv_info(MODULE_ID_CPU_PANIC, (char *)&cpu_info, sizeof(improve_yield_cpu_panic_nv_t));
    if (ret != 0)
        pr_err("[%s %d]: set improve yield cpu panic info fail, ret:%d\n", __func__, __LINE__, ret);

    PRINT_FUNC_AND_LINE;
    ret = get_improve_yield_nv_info(MODULE_ID_CPU_PANIC, (char *)&cpu_info, sizeof(improve_yield_cpu_panic_nv_t));
    if (ret != 0) {
        pr_err("[%s %d]: get improve yield cpu panic info1 fail, ret:%d\n", __func__, __LINE__, ret);
    }
    pr_err("[%s %d]: pv_flag:%d\n", __func__, __LINE__, cpu_info.cluster_panic_info[cluster].bits.pv_flag);
}

static u32 cpu_panic_improve_yield_read_pvflag(int cluster)
{
    int ret;
    improve_yield_cpu_panic_nv_t cpu_info;

    if (cluster < CPU_LIT_CLUSTER || cluster >= CPU_CLUSTER_CNT) {
        pr_err("panic cluster %d is invalid\n", cluster);
        return 0;
    }

    ret = get_improve_yield_nv_info(MODULE_ID_CPU_PANIC, (char *)&cpu_info, sizeof(improve_yield_cpu_panic_nv_t));
    if (ret != 0) {
        pr_err("[%s %d]: get improve yield cpu panic info fail, ret:%d\n", __func__, __LINE__, ret);
        return (u32)ret;
    }

    return cpu_info.cluster_panic_info[cluster].bits.pv_flag;
}

static void app_panic_improve_yield_set_cnt(void)
{
    int ret;
    static int flag = 0;
    improve_yield_app_nv_p app_info = {0};
    if (flag)
        return;

    ret = get_improve_yield_nv_info(MODULE_ID_APP_PANIC, (char *)&app_info, sizeof(improve_yield_app_nv_p));
    if (ret != 0) {
        pr_err("[%s %d]: get improve yield cpu panic info fail, ret:%d\n", __func__, __LINE__, ret);
        return;
    }

    if (app_info.app_panic_info.bits.count < 6) {
        app_info.app_panic_info.bits.count++;
    } else {
        app_info.app_panic_info.bits.count = 7;
    }

    ret = set_improve_yield_nv_info(MODULE_ID_APP_PANIC, (char *)&app_info, sizeof(improve_yield_app_nv_p));
    if (ret != 0)
        pr_err("[%s %d]: set improve yield cpu panic info fail, ret:%d\n", __func__, __LINE__, ret);

    flag = 1;
}
#endif

static unsigned int app_panic_improve_yield_read_cnt(void)
{
    int ret;

    improve_yield_app_nv_p app_info = {0};

    ret = get_improve_yield_nv_info(MODULE_ID_APP_PANIC, (char *)&app_info, sizeof(improve_yield_app_nv_p));
    if (ret != 0) {
        pr_err("[%s %d]: get improve yield cpu panic info fail, ret:%d\n", __func__, __LINE__, ret);
        return ret;
    }

    return (unsigned int)app_info.app_panic_info.bits.count;
}

#if defined(CONFIG_DFX_IMPROVE_YIELD) && defined(CONFIG_FACTORY_MODE)

static int get_cpu_panic_on_cluster(void)
{
    int cluster;
    int cpunum;

    cpunum = dfx_hw_diag_get_panic_cpunum();
    pr_err("%s: panic on cpunum %d\n", __func__, cpunum);
    if (cpunum < 0 || cpunum >= nr_cpu_ids) {
        pr_err("cpu_improve_yield check cpu panic failed, invalid cpu num %d\n", cpunum);
        return -1;
    }
    cluster = topology_physical_package_id(cpunum);
    pr_err("%s: panic on cluster %d\n", __func__, cluster);
    return cluster;
}

static unsigned int get_last_cpu_cluster_pvflag(void)
{
    static unsigned int last_pv_flag = 0xFFFFFF;
    int cluster;

    cluster = get_cpu_panic_on_cluster();
    if (cluster < CPU_LIT_CLUSTER || cluster >= CPU_CLUSTER_CNT) {
        pr_err("panic cluster %d is invalid\n", cluster);
        return 0;
    }

    if (last_pv_flag != 0xFFFFFF)
        return last_pv_flag;

    last_pv_flag = cpu_panic_improve_yield_read_pvflag(cluster);

    return last_pv_flag;
}

static void _update_cpu_panic_nv_and_volt(int cluster)
{
    u32 freq_idx_mask = 0x00;
    u32 is_all_freq = 0x2;

    cpu_panic_improve_yield_set_pvflag(cluster);
    cpu_boost_volt(cluster, freq_idx_mask, is_all_freq);
}
static void update_cpu_panic_nv_and_volt()
{
    int cluster;
    u32 reboot_type = rdr_get_reboot_type();
    if (reboot_type == AP_S_AWDT || reboot_type == LPM3_S_LPMCURST) {
        for (cluster = CPU_LIT_CLUSTER; cluster < CPU_CLUSTER_CNT; cluster++) {
            _update_cpu_panic_nv_and_volt(cluster);
        }
        return;
    }

    cluster = get_cpu_panic_on_cluster();
    if (cluster < CPU_LIT_CLUSTER || cluster >= CPU_CLUSTER_CNT) {
        pr_err("panic cluster %d is invalid\n", cluster);
        return;
    }
    _update_cpu_panic_nv_and_volt(cluster);
}

/* The function is expected to return the value at the time of the first call. */
static bool is_m1_exc_need_improve_yield(void)
{
	static unsigned int judge = 0xFFFFFF;
#ifdef IMPROVE_YIELD_CHS
	int ret = 0;
#endif

	if (judge != 0xFFFFFF) {
		pr_info("[%s] judge = 0x%X\n", __func__, judge);
		return !!(judge);
	}

#ifdef IMPROVE_YIELD_CHS
	if (is_module_improve_yield_enable(MODULE_ID_VDEC) == YIELD_ENABLE &&
		is_m1_exc_type() && !dpu_is_pv_flag_true()) {
		ret = dpu_set_iy_nv_flag();
		if (ret) {
			judge = PVFLAG_DISABLE;
			pr_info("m1 exc, needing improve yield, but fail to set nve\n");
			return false;
		}
		judge = PVFLAG_ENABLE;
		pr_info("m1 exc, needing improve yield\n");
		return true;
	}
#endif

	judge = PVFLAG_DISABLE;
	return false;
}

static bool is_cpu_panic_need_improve_yield(void)
{
    PRINT_FUNC_AND_LINE;

    if (is_module_improve_yield_enable(MODULE_ID_CPU_PANIC) == YIELD_ENABLE && is_sh_panic_type() == true &&
        get_last_cpu_cluster_pvflag() == PVFLAG_DISABLE) {
        update_cpu_panic_nv_and_volt();
        pr_info("cpu is_need_improve_yield panic is true\n");
        return true;
    }

    return false;
}

#ifdef CONFIG_MM_LB_IMPROVE_YIELD
static bool is_sc_ecc_ue_need_improve_yield(void)
{
    if (is_module_improve_yield_enable(MODULE_ID_TRA) == YIELD_ENABLE &&
        get_improve_yield_tra_nv_info(SH_FLAG) == YIELD_DISABLE &&
        get_improve_yield_tra_nv_info(NV_FLAG) == YIELD_ENABLE) {
        set_improve_yield_tra_nv_info(YIELD_ENABLE, SH_FLAG);
        pr_info("sc is_need_improve_yield panic is true\n");
        return true;
    }
    return false;
}
#endif

bool is_soc_exc_need_improve_yield(void)
{
	/* When serror, the judgement of m1 is more accurate, so it is better to judge m1 first and then cpu. */
	if (is_m1_exc_need_improve_yield())
		return true;
	if (is_cpu_panic_need_improve_yield())
		return true;
#ifdef CONFIG_MM_LB_IMPROVE_YIELD
	if (is_sc_ecc_ue_need_improve_yield())
		return true;
#endif
    return false;
}

bool is_app_panic_need_improve_yield(void)
{
    if (is_module_improve_yield_enable(MODULE_ID_APP_PANIC) == YIELD_ENABLE && is_app_panic_type() == true) {
        app_panic_improve_yield_set_cnt(); /* set improve yield app panic count */
        pr_info("is_need_improve_yield app panic is true, app panic happen\n");
        return true;
    }

    return false;
}

static char *soc_exc_category_name = "SOFTWARE_SH_ERROR";
static char *app_panic_category_name = "SOFTWARE_APP_ERROR";
char *get_iy_category_name(void)
{
	if (is_soc_exc_need_improve_yield() == true) {
		return soc_exc_category_name;
	} else if (is_app_panic_need_improve_yield() == true) {
		return app_panic_category_name;
	}
	return NULL;
}
#endif

static u32 get_improrve_yield_pv_flag(void)
{
    u32 cluster;
    u32 pv_flag = 0;
    improve_yield_cpu_ecc_nv_t cpu_info = {0};
    improve_yield_cpu_panic_nv_t cpu_panic_info = {0};
    improve_yield_vdec_info vdec_info = {0};
    struct hvgr_fac_gpu_nv_data gpu_info = {0};

    int ret;
    ret = get_improve_yield_nv_info(MODULE_ID_CPU, (char *)&cpu_info, sizeof(improve_yield_cpu_ecc_nv_t));
    if (ret != 0) {
        pr_err("%s:get improve yield info fail1\n", __func__);
        return 0;
    }
    ret = get_improve_yield_nv_info(MODULE_ID_CPU_PANIC, (char *)&cpu_panic_info, sizeof(improve_yield_cpu_panic_nv_t));
    if (ret != 0) {
        pr_err("%s:get improve yield info fail2\n", __func__);
        return 0;
    }
    ret = get_improve_yield_nv_info(MODULE_ID_VDEC, (char *)&vdec_info, sizeof(improve_yield_vdec_info));
    if (ret != 0) {
        pr_err("%s:get improve yield info fail3\n", __func__);
        return 0;
    }
    ret = get_improve_yield_nv_info(MODULE_ID_GPU, (char *)&gpu_info, sizeof(struct hvgr_fac_gpu_nv_data));
    if (ret != 0) {
        pr_err("%s:get improve yield info fail4\n", __func__);
        return 0;
    }

    for (cluster = CPU_LIT_CLUSTER; cluster < CPU_CLUSTER_CNT; cluster++) {
        pv_flag |=
            (cpu_info.cluster_ecc_info[cluster].bits.pv_flag == 1) ? BITS(RTB_PV_FLAG_CLUSTER0_ECC + cluster) : 0;
        pv_flag |= (cpu_panic_info.cluster_panic_info[cluster].bits.pv_flag == 1)
                       ? BITS(RTB_PV_FLAG_CLUSTER0_PANIC + cluster)
                       : 0;
    }

    pv_flag |= (vdec_info.nv_flag.bits.pv_flag == 1) ? BITS(RTB_PV_FLAG_VDEC) : 0;
    pv_flag |= (gpu_info.cfg.bit.pv_mark == 1) ? BITS(RTB_PV_FLAG_GPU) : 0;

    pr_info("%s: Pv_Flag = 0x%x\n", __func__, pv_flag);
    return pv_flag;
}

#ifdef CONFIG_FACTORY_MODE
static int _get_iy_diaginfo_factory(char *out_buf, size_t buf_size)
{
    int ret;
    size_t len;
    char *category_name = NULL;
    char improve_yield_str[YIELD_MAX_RECORD] = {0};
    unsigned int iy_apppanic_cnt = 0;
    unsigned int iy_pv_flag = 0;
    PRINT_FUNC_AND_LINE;
    if (out_buf == NULL || buf_size == 0) {
        pr_err("get imporve yield diaginfo failed, out_buf is NULL\n");
        return -1;
    }

    category_name = get_iy_category_name();
    if (!category_name) {
        return 0;
    }
    iy_pv_flag = get_improrve_yield_pv_flag();
    iy_apppanic_cnt = app_panic_improve_yield_read_cnt();
    ret = sprintf_s(improve_yield_str,
        YIELD_MAX_RECORD,
        "Category:%s,IyPvFlag=0x%x,IyAppPanicCnt=%u;",
        category_name,
        iy_pv_flag,
        iy_apppanic_cnt);
    if (ret < 0) {
        pr_err("%s():%d sprintf_s ERROR\n", __func__, __LINE__);
        return -1;
    }
    len = strlen(improve_yield_str);
    if (buf_size < len + 1) {
        pr_err("%s, out_buf size %lu is too small for string len %lu\n", __func__, buf_size, len);
        return -1;
    }
    if (strcpy_s(out_buf, buf_size, improve_yield_str) != EOK) {
        pr_err("%s, strcpy failed\n", __func__);
        return -1;
    }
    return len;
}
#else
static int _get_iy_diaginfo(char *out_buf, size_t buf_size)
{
    int ret;
    size_t len;
    char iy_apppanic_flagcnt_str[YIELD_MAX_RECORD] = {0};
    unsigned int iy_apppanic_cnt = 0;
    unsigned int iy_pv_flag = 0;
    PRINT_FUNC_AND_LINE;

    iy_pv_flag = get_improrve_yield_pv_flag();
    iy_apppanic_cnt = app_panic_improve_yield_read_cnt();
    if (iy_pv_flag == 0x0 && iy_apppanic_cnt == 0) {
        return 0;
    }
    ret = sprintf_s(
        iy_apppanic_flagcnt_str, YIELD_MAX_RECORD, "IyPvFlag=0x%x,IyAppPanicCnt=%u;", iy_pv_flag, iy_apppanic_cnt);
    if (ret < 0) {
        pr_err("%s():%d sprintf_s ERROR\n", __func__, __LINE__);
        return -1;
    }
    len = strlen(iy_apppanic_flagcnt_str);
    if (buf_size < len + 1) {
        pr_err("%s, out_buf size %lu is too small for string len %lu\n", __func__, buf_size, len);
        return -1;
    }
    if (strcpy_s(out_buf, buf_size, iy_apppanic_flagcnt_str) != EOK) {
        pr_err("%s, strcpy failed\n", __func__);
        return -1;
    }
    return len;
}
#endif

int get_iy_diaginfo(char *out_buf, size_t buf_size)
{
    if (out_buf == NULL || buf_size == 0) {
        pr_err("get imporve yield diaginfo failed, out_buf is NULL\n");
        return -1;
    }

#ifdef CONFIG_FACTORY_MODE
    return _get_iy_diaginfo_factory(out_buf, buf_size);
#else
    return _get_iy_diaginfo(out_buf, buf_size);
#endif
}
