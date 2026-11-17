
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/err.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/clk.h>
#include <linux/of.h>
#include <isp_ddr_map.h>
#include <securec.h>
#include "platform_include/basicplatform/linux/peri_volt_poll.h"
#include "hisp_internel.h"
#include <platform_include/see/efuse_driver.h>
#include "hisp_power_manager.h"

#if defined(CONFIG_SOC_PG_INFO)
#include <platform_include/basicplatform/linux/soc_spec.h>
#endif

#ifdef CONFIG_CAMERA_USE_HISP230
#include "soc_spec_info.h"
#endif

#ifdef CONFIG_LPMCU_INTERACT_THERMAL
#include "hisp_thermal_process.h"
#include "platform_include/cee/linux/thermal_interact_lpmcu.h"
#endif

#ifdef CONFIG_ES_ISP_LOW_FREQ
#define CLOCKVALUE                          "clock-value-low"
#else
#define CLOCKVALUE                          "clock-value"
#endif
#define CLOCKVALUELOW                       "clock-value-low"

#define HZ_TO_MHZ_DIV                       1000000

#define EFUSE_PARTIALGOOD_FLAG1_START_BIT		0
#define EFUSE_FT_START_BIT                      (121 - (EFUSE_PARTIALGOOD_FLAG1_START_BIT))
#define EFUSE_FT_BIT_SIZE	                    1
#define EFUSE_IMPROVE_VOL_FLAG_START_BIT        (148 - (EFUSE_PARTIALGOOD_FLAG1_START_BIT))
#define EFUSE_IMPROVE_VOL_FLAG_BIT_SIZE	        1

#define DLDO_EFUSE_MAX_VALUE 					(881)
#define DLDO_EFUSE_MIN_VALUE 					(1)
#define VALUE_NOT_SET 				            (0)
#define DLDO_NEED_IMPROVE_VOL                   (0)

enum hisp_clk_dvfs_type {
	HISP_CLK_TURBO      = 0,
	HISP_CLK_NORMINAL   = 1,
	HISP_CLK_LOWSVS     = 2,
	HISP_CLK_HIGHSVS    = 3,
	HISP_CLK_SVS        = 4,
	HISP_CLK_DISDVFS    = 5,
	HISP_CLK_DVFS_MAX
};

enum binded_clock_num_e {
	SOURCE_CLOCK_NUM     = 0,
	TARGET_CLOCK_NUM     = 1,
	MAX_BINED_CLOCK_TYPE = 2
};

#ifdef DEBUG_HISP
#define DUMP_ISPCPU_PC_TIMES    3

struct hisp_clk_dump_s {
	bool enable;
	unsigned int ispcpu_stat;
	unsigned int ispcpu_pc[DUMP_ISPCPU_PC_TIMES];
	unsigned long freq[ISP_CLK_MAX];
	unsigned int freqmask;
};
#endif

struct pll6_usage_item {
    unsigned int type;
    unsigned int pll6_freq;
    unsigned int stub_freq;
};

struct hisp_clk_manager_t {
	unsigned int dvfsmask;
	unsigned int usedvfs;
	unsigned int clock_num;
	unsigned int pll6_usage_num;
	unsigned int ispcpu_switch_volt_feq;
	unsigned int ispcpu_switch_low_volt_feq;
	unsigned int ispcpu_dldo_efuse_bit_start;
	unsigned int ispcpu_dldo_efuse_bit_cnt;
	struct clk *ispclk[ISP_CLK_MAX];
	const char *clk_name[ISP_CLK_MAX];
	unsigned int ispclk_value[ISP_CLK_MAX];
#ifdef CONFIG_KERNEL_CAMERA_USE_HISP120
	unsigned int ispclk_value_low[ISP_CLK_MAX];
#endif
	unsigned int clkdis_dvfs[ISP_CLK_MAX];
	unsigned int clkdis_need_div[ISP_CLK_MAX];
	unsigned int clkdn[HISP_CLK_DVFS_MAX][ISP_CLK_MAX];
	unsigned int binded_clock_num[MAX_BINED_CLOCK_TYPE];
	unsigned int binded_vote_level[ISP_CLK_MAX];
	unsigned int binded_source_clock[ISP_CLK_MAX];
	unsigned int binded_target_clock[ISP_CLK_MAX];
	struct pll6_usage_item pll6_usage_tbl[PLL6_USAGE_NUM];
	unsigned int binded_clock_flag;
	unsigned int efuse_dldo;
	unsigned int ft_dldo;
	unsigned int current_ispclk_rate[ISP_CLK_MAX];
	unsigned int low_temp_flag;
	unsigned int dldo_improve_volt_flag;
	unsigned int low_temp_enable;
#ifdef DEBUG_HISP
	struct hisp_clk_dump_s hisp_clk;
#endif
};

struct hisp_clk_manager_t hisp_clk_manager = {0};

#ifdef DEBUG_HISP
static unsigned long hisp_clock_get_ispclk_freq(unsigned int type);
#endif

static int hisp_clock_clk_valid_check(int clk)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;

	if (clk >= (int)clk_manager->clock_num) {
		pr_err("[%s] Failed : clk %d >= %d\n",
				__func__, clk, clk_manager->clock_num);
		return -EINVAL;
	}

	return 0;
}

int hisp_dvfs_enable(void)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;

	return (int)clk_manager->usedvfs;
}

static int hisp_clock_invalid_dvfsmask(int clk)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	int ret;

	ret = hisp_clock_clk_valid_check(clk);
	if (ret < 0)
		return ret;

	return (0x01 & (clk_manager->dvfsmask >> (unsigned int)clk));
}

static unsigned int pll6_usage_search(struct pll6_usage_item *arr, unsigned int max_item,
	unsigned int type, unsigned int rate)
{
	unsigned int i;

	for (i = 0; i < max_item; i++)
		if ((arr[i].type == type) && (arr[i].pll6_freq == rate))
			return i;

	return max_item;
}

static int pll6_clk_set(unsigned int type, unsigned int rate)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	struct pll6_usage_item *pll6_tbl;
	unsigned int item;
	unsigned int tbl_size;
	int ret;
	pll6_tbl = clk_manager->pll6_usage_tbl;

	if (clk_manager->pll6_usage_num == 0 || clk_manager->pll6_usage_num > PLL6_USAGE_NUM) {
		pr_info("[%s] Notice: pll6_usage_num is %u, no need ppll6 setting\n", __func__, clk_manager->pll6_usage_num);
		return 0;
	}

	tbl_size = clk_manager->pll6_usage_num;

	item = pll6_usage_search(pll6_tbl, tbl_size, type, rate);
	if (item >= tbl_size)
		return 0;

	pr_info("[%s]: clk.0x%x.%s switch to sub freq[%u]\n", __func__, type,
		clk_manager->clk_name[type], pll6_tbl[item].stub_freq);
	ret = clk_set_rate(clk_manager->ispclk[type], (unsigned long)pll6_tbl[item].stub_freq);
	if (ret < 0) {
		pr_err("[%s] Failed to switch to sub freq, clk.0x%x.%s freq.%u\n", __func__, type,
		clk_manager->clk_name[type], pll6_tbl[item].stub_freq);
		return ret;
	}

	return 0;
}

static int hisp_clock_clk_dn(int clk, unsigned int clkdown)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	int ret = 0;
	unsigned long ispclk = 0;
	unsigned int stat_machine = clkdown;
	unsigned int type;

	ret = hisp_dvfs_enable();
	if (ret == 0) {
		pr_err("[%s] Failed : Do not Support DVFS\n", __func__);
		return -EINVAL;
	}

	if (clk >= (int)clk_manager->clock_num) {
		pr_err("[%s] Failed : clk.%d >= %d\n",
			__func__, clk, clk_manager->clock_num);
		return -EINVAL;
	}

	do {
		type = stat_machine;
		if (type >= HISP_CLK_DVFS_MAX) {
			pr_err("[%s] Failed: type. %d > %d or < 0\n",
					__func__, type, HISP_CLK_DVFS_MAX);
			return -EINVAL;
		}

		stat_machine++;
		ispclk = (unsigned long)clk_manager->clkdn[type][clk];
		pr_info("[%s] Clock Down %lu.%lu MHz\n", __func__,
			ispclk / HZ_TO_MHZ_DIV, ispclk % HZ_TO_MHZ_DIV);
		if (ispclk == 0)
			continue;

		ret = clk_set_rate(clk_manager->ispclk[clk], ispclk);
		if (ret < 0) {
			pr_err("[%s] Failed: clk_set_rate.%u > %u\n",
				__func__, type, stat_machine);
			goto try_clock_down;
		}

		ret = clk_prepare_enable(clk_manager->ispclk[clk]);
		if (ret < 0) {
			pr_err("[%s] Failed: clk_prepare_enable.%d, %u > %u\n",
				__func__, ret, type, stat_machine);
			goto try_clock_down;
		}
		clk_manager->current_ispclk_rate[clk] = ispclk;
		hisp_share_update_clk_value(clk, (unsigned int)ispclk);
try_clock_down:
		if (ret != 0 && stat_machine < HISP_CLK_DVFS_MAX)
			pr_info("[%s]Clk Dwn %lu.%luMHz > %u.%uMHz\n", __func__,
				ispclk / HZ_TO_MHZ_DIV, ispclk % HZ_TO_MHZ_DIV,
				clk_manager->clkdn[stat_machine][clk] / HZ_TO_MHZ_DIV,
				clk_manager->clkdn[stat_machine][clk] % HZ_TO_MHZ_DIV);
	} while (ret != 0);

	return ret;
}

static unsigned long hisp_clock_get_clk_value(int clk)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	unsigned long ispclock = 0;

#ifdef CONFIG_KERNEL_CAMERA_USE_HISP120
	int lowpower_flag = hisp120_get_lowpower();
	if (lowpower_flag)
		ispclock = (unsigned long)clk_manager->ispclk_value_low[clk];
	else
		ispclock = (unsigned long)clk_manager->ispclk_value[clk];
#else
	ispclock = (unsigned long)clk_manager->ispclk_value[clk];
#endif

	return ispclock;
}

static int hisp_clock_do_pwr_enable(unsigned int clk)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	unsigned long ispclock = 0;
	int ret;
#ifdef DEBUG_HISP
	unsigned long ispclock_debug;
#endif

	ret = strncmp(clk_manager->clk_name[clk], "isp_sys", strlen("isp_sys"));
	if (ret == 0) {
		ret = clk_prepare_enable(clk_manager->ispclk[clk]);
		if (ret < 0) {
			pr_err("[%s] Failed: %u.%s.clk_prepare_enable.%d\n",
				__func__, clk, clk_manager->clk_name[clk], ret);
			return -EINVAL;
		}
		pr_info("[%s] %u.%s.clk_prepare_enable\n",
				__func__, clk, clk_manager->clk_name[clk]);
		return 0;
	}

	ret = strncmp(clk_manager->clk_name[clk], "ap_ppll1", strlen("ap_ppll1"));
	if (ret == 0) {
		ret = clk_prepare_enable(clk_manager->ispclk[clk]);
		if (ret < 0) {
			pr_err("[%s] Failed: %u.%s.clk_prepare_enable.%d\n",
				__func__, clk, clk_manager->clk_name[clk], ret);
			return -EINVAL;
		}
		pr_info("[%s] %u.%s.clk_prepare_enable\n",
				__func__, clk, clk_manager->clk_name[clk]);
		return 0;
	}

	ispclock = hisp_clock_get_clk_value(clk);

#ifdef DEBUG_HISP
	ispclock_debug = hisp_clock_get_ispclk_freq((unsigned int)clk);
	if (ispclock_debug != 0)
		ispclock = ispclock_debug;
#endif

	if (pll6_clk_set(clk, (unsigned int)ispclock) < 0) {
		pr_err("[%s] Failed: pll6_clk_set.%u > %ul\n", __func__, clk, ispclock);
		goto try_clock_down;
	}

	ret = clk_set_rate(clk_manager->ispclk[clk], ispclock);
	if (ret < 0) {
		pr_err("[%s] Failed: %d.%d M, %u.%s.clk_set_rate.%d\n",
			__func__, (int)ispclock / HZ_TO_MHZ_DIV,
			(int)ispclock % HZ_TO_MHZ_DIV,
			clk, clk_manager->clk_name[clk], ret);
		goto try_clock_down;
	}

	ret = clk_prepare_enable(clk_manager->ispclk[clk]);
	if (ret < 0) {
		pr_err("[%s] Failed: %d.%d M, %u.%s.clk_prepare_enable.%d\n",
			__func__, (int)ispclock / HZ_TO_MHZ_DIV,
			(int)ispclock % HZ_TO_MHZ_DIV,
			clk, clk_manager->clk_name[clk], ret);
		goto try_clock_down;
	}
	clk_manager->current_ispclk_rate[clk] = ispclock;
	hisp_share_update_clk_value(clk, (unsigned int)ispclock);
	pr_info("[%s] %u.%s.clk_set_rate.%d.%d M\n", __func__,
		clk, clk_manager->clk_name[clk], (int)ispclock / HZ_TO_MHZ_DIV,
		(int)ispclock % HZ_TO_MHZ_DIV);

	return 0;

try_clock_down:
	return hisp_clock_clk_dn(clk, HISP_CLK_SVS);
}

static void hisp_clock_do_pwr_disable(int clk)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	unsigned long ispclock = 0;
	int ret = 0;

	if (hisp_clock_clk_valid_check(clk))
		return;

	ret = strncmp(clk_manager->clk_name[clk], "isp_sys", strlen("isp_sys"));
	if (ret == 0) {
		pr_info("[%s] %d.%s.clk_disable_unprepare\n",
				__func__, clk, clk_manager->clk_name[clk]);
		clk_disable_unprepare(clk_manager->ispclk[clk]);
		return;
	}

	ret = strncmp(clk_manager->clk_name[clk], "ap_ppll1", strlen("ap_ppll1"));
	if (ret == 0) {
		pr_info("[%s] %d.%s.clk_disable_unprepare\n",
				__func__, clk, clk_manager->clk_name[clk]);
		clk_disable_unprepare(clk_manager->ispclk[clk]);
		return;
	}

	ispclock = (unsigned long)clk_manager->clkdis_need_div[clk];
	if (ispclock != 0) {
		ret = clk_set_rate(clk_manager->ispclk[clk], ispclock);
		if (ret < 0) {
			pr_err("[%s] Failed: need_div %d.%d M, %d.%s.rate.%d\n",
				__func__, (int)ispclock / HZ_TO_MHZ_DIV,
				(int)ispclock % HZ_TO_MHZ_DIV,
				clk, clk_manager->clk_name[clk], ret);
			return;
		}
		pr_info("[%s] %d.%s.need_div clk_set_rate.%d.%d M\n", __func__,
			clk, clk_manager->clk_name[clk], (int)ispclock / HZ_TO_MHZ_DIV,
			(int)ispclock % HZ_TO_MHZ_DIV);
	}

	ispclock = (unsigned long)clk_manager->clkdis_dvfs[clk];
	ret = clk_set_rate(clk_manager->ispclk[clk], ispclock);
	if (ret < 0) {
		pr_err("[%s] Failed: %d.%d M, %d.%s.clk_set_rate.%d\n",
			__func__, (int)ispclock / HZ_TO_MHZ_DIV,
			(int)ispclock % HZ_TO_MHZ_DIV, clk,
			clk_manager->clk_name[clk], ret);
		return;
	}
	clk_manager->current_ispclk_rate[clk] = ispclock;
	hisp_share_update_clk_value(clk, (unsigned int)ispclock);
	pr_info("[%s] %d.%s.clk_set_rate.%d.%d M\n", __func__, clk,
			clk_manager->clk_name[clk], (int)ispclock / HZ_TO_MHZ_DIV,
			(int)ispclock % HZ_TO_MHZ_DIV);

	clk_disable_unprepare(clk_manager->ispclk[clk]);
}

int hisp_clock_pwr_enable(void)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	unsigned int index, err_index;
	int ret;

#ifdef DEBUG_HISP
	ret = hisp_check_pcie_stat();
	if (ret != ISP_NORMAL_MODE)
		return 0;
#endif

	for (index = 0; index < clk_manager->clock_num; index++) {
		ret = hisp_clock_do_pwr_enable(index);
		if (ret < 0) {
			pr_err("[%s] clk %u\n", __func__, index);
			goto err_ispclk;
		}
	}

	return 0;

err_ispclk:
	for (err_index = 0; err_index < index; err_index++)
		hisp_clock_do_pwr_disable(err_index);
	return ret;
}

void hisp_clock_pwr_disable(void)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	int index;

	for (index = 0; index < (int)clk_manager->clock_num; index++)
		hisp_clock_do_pwr_disable(index);
}

static unsigned long hisp_clock_getclkrate(unsigned int type)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;

	int ret = hisp_clock_invalid_dvfsmask((int)type);
	if (ret) {
		pr_err("[%s] Failed : DVFS Invalid type.0x%x, dvfsmask.0x%x\n",
				__func__, type, clk_manager->dvfsmask);
		return 0;
	}

	if (type >= ISP_CLK_MAX) {
		pr_err("%s:type error.%u\n", __func__, type);
		return 0;
	}

	return (unsigned long)clk_get_rate(clk_manager->ispclk[type]);
}

static unsigned int hisp_if_dldo_change_en(void) {
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	unsigned int pwr_dldo_efuse_h;
	unsigned int pwr_dldo_efuse_l;
	if (clk_manager->ispcpu_switch_volt_feq < clk_manager->clkdis_dvfs[ISPCPU_CLK] ||
		clk_manager->ispcpu_switch_volt_feq > clk_manager->ispclk_value[ISPCPU_CLK])
		return 0;

	if(clk_manager->ispcpu_switch_low_volt_feq != VALUE_NOT_SET) {
		pwr_dldo_efuse_h = (clk_manager->efuse_dldo >> 10) & 0x3ff;
		pwr_dldo_efuse_l = clk_manager->efuse_dldo & 0x3ff;
 
		if (pwr_dldo_efuse_h > DLDO_EFUSE_MAX_VALUE || pwr_dldo_efuse_h < DLDO_EFUSE_MIN_VALUE)
			return 0;
		
		if (pwr_dldo_efuse_l > DLDO_EFUSE_MAX_VALUE || pwr_dldo_efuse_l < DLDO_EFUSE_MIN_VALUE)
			return 0;
	} else {
		if (clk_manager->efuse_dldo > DLDO_EFUSE_MAX_VALUE || clk_manager->efuse_dldo < DLDO_EFUSE_MIN_VALUE)
			return 0;

		if (clk_manager->ft_dldo == 0)
			return 0;
	}
	return 1;
}

static unsigned int hisp_switch_rate_to_level(unsigned int type, unsigned int rate)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	unsigned int level = HISP_CLK_SVS;

	if (rate < clk_manager->clkdn[HISP_CLK_HIGHSVS][type]) {
		level = HISP_CLK_SVS;
	} else if (rate > clk_manager->clkdn[HISP_CLK_HIGHSVS][type] &&
		rate < clk_manager->clkdn[HISP_CLK_NORMINAL][type]) {
		level = HISP_CLK_HIGHSVS;
	} else if (rate > clk_manager->clkdn[HISP_CLK_NORMINAL][type] &&
		rate < clk_manager->clkdn[HISP_CLK_TURBO][type]) {
		level = HISP_CLK_NORMINAL;
	} else if (rate >= clk_manager->clkdn[HISP_CLK_TURBO][type]) {
		level = HISP_CLK_TURBO;
	}

	return level;
}

static unsigned int hisp_refresh_current_level(unsigned int type, unsigned int level)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	unsigned int target_level = HISP_CLK_SVS;
	unsigned int type_source;
	unsigned int num_source;
	unsigned int i;

	// Store current type clk level
	clk_manager->binded_vote_level[type] = level;

	num_source = min(clk_manager->clock_num, clk_manager->binded_clock_num[SOURCE_CLOCK_NUM]);

	// Check current max level for all source clks
	for (i = 0; i < num_source; i++) {
		type_source = clk_manager->binded_source_clock[i];
		if (type_source >= clk_manager->clock_num) {
			pr_err("[%s] source clock[%u].%u invalid", __func__, i, type_source);
			return HISP_CLK_DVFS_MAX;
		}

		if (clk_manager->binded_vote_level[type_source] < target_level) {
			target_level = clk_manager->binded_vote_level[type_source];
		}
	}

	return target_level;
}

static int hisp_set_binded_clock(unsigned int type, unsigned int rate)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	int ret;
	unsigned int level = HISP_CLK_SVS;
	unsigned int target_type;
	unsigned int i;

	level = hisp_switch_rate_to_level(type, rate);
	if (level >= HISP_CLK_DVFS_MAX) {
		pr_info("[%s] clk.0x%x.%s switch Rate.%u to level.%u Failed",
			__func__, type, clk_manager->clk_name[type], rate, level);
		return 0;
	}
	level = hisp_refresh_current_level(type, level);
	if (level >= HISP_CLK_DVFS_MAX) {
		pr_info("[%s] clk.0x%x.%s refresh Rate.%u to level.%u Failed",
			__func__, type, clk_manager->clk_name[type], rate, level);
		return 0;
	}

	// Fresh Target Clock Rate
	for (i = 0; i < clk_manager->binded_clock_num[TARGET_CLOCK_NUM]; i++) {
		target_type = clk_manager->binded_target_clock[i];
		if (target_type >= clk_manager->clock_num) {
			pr_err("[%s] target clock[%u].%u invalid", __func__, i, target_type);
			return -EINVAL;
		}

		pr_info("[%s] DVFS Set.0x%x.%s Rate.%d. %d.%08d M\n", __func__, target_type, clk_manager->clk_name[target_type],
			clk_manager->clkdn[level][target_type], clk_manager->clkdn[level][target_type] / HZ_TO_MHZ_DIV,
			clk_manager->clkdn[level][target_type] % HZ_TO_MHZ_DIV);
		ret = pll6_clk_set(target_type, clk_manager->clkdn[level][target_type]);
		if (ret < 0) {
			pr_err("[%s] Failed: pll6_clk_set.%u > %ul\n",
				__func__, target_type, clk_manager->clkdn[level][target_type]);
			return ret;
		}

		ret = clk_set_rate(clk_manager->ispclk[target_type], (unsigned long)clk_manager->clkdn[level][target_type]);
		if (ret < 0) {
			pr_err("[%s] Failed : DVFS Set.0x%x.%s Rate.%d. %d.%08d M\n",
					__func__, target_type, clk_manager->clk_name[target_type],
					clk_manager->clkdn[level][target_type],
					clk_manager->clkdn[level][target_type] / HZ_TO_MHZ_DIV,
					clk_manager->clkdn[level][target_type] % HZ_TO_MHZ_DIV);
			return ret;
		}
	}

	return 0;
}

static unsigned int hisp_select_dldo_efuse(unsigned int rate)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	unsigned int select_dldo_efuse = 0;
	if((clk_manager->ispcpu_switch_low_volt_feq != VALUE_NOT_SET) &&
		(rate > clk_manager->ispcpu_switch_low_volt_feq) &&
		(rate <= clk_manager->ispcpu_switch_volt_feq)) {
		select_dldo_efuse = (clk_manager->efuse_dldo >> 10) & 0x3ff;
	} else {
		select_dldo_efuse = clk_manager->efuse_dldo & 0x3ff;
	}
	pr_info("pwr_dldo_efuse = %u",select_dldo_efuse);
	return select_dldo_efuse;
}

static int hisp_ispcpu_set_volt(unsigned int rate)
{
#ifdef CONFIG_HISP_FFA_SUPPORT
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	int ret;
	unsigned int pwr_dldo_efuse = 0;
	unsigned int dldo_change_en = 0;
	
	dldo_change_en = hisp_if_dldo_change_en();
	pwr_dldo_efuse = hisp_select_dldo_efuse(rate);

	if (dldo_change_en > 0 && clk_manager->low_temp_flag == 1) {
		pr_info("[%s] enter low_temp_mode , low_temp_flag:%u\n" , __func__, clk_manager->low_temp_flag);
		ret = hisp_ffa_set_ispcpu_volt(ISPCPU_VOLT_CMOS, pwr_dldo_efuse);
		if (ret != 0) {
			pr_err("[%s] Failed : ISPCPU_CLK set DLOD fail low_temp_flag:%u , ret:0x%x\n",
				__func__, clk_manager->low_temp_flag , ret);
		}
		return ret;
	}
	if (dldo_change_en > 0 && rate > clk_manager->ispcpu_switch_volt_feq) {
		ret	= hisp_ffa_set_ispcpu_volt(ISPCPU_VOLT_CMOS, pwr_dldo_efuse);
		if (ret != 0) {
			pr_err("[%s] Failed : ISPCPU_CLK set DLOD fail ret:0x%x\n", __func__, ret);
		}
		return ret;
	}
	if (dldo_change_en > 0 && rate <= clk_manager->ispcpu_switch_volt_feq) {
		unsigned int set_dldo_volt_level = ISPCPU_VOLT_DLDO;
 
		if((clk_manager->ispcpu_switch_low_volt_feq != VALUE_NOT_SET) &&
			(rate > clk_manager->ispcpu_switch_low_volt_feq) &&
			(clk_manager->dldo_improve_volt_flag == DLDO_NEED_IMPROVE_VOL)) {
			set_dldo_volt_level = ISPCPU_VOLT_CMOS;
			pr_info("dldo_improve_volt_flag = %u,set_dldo_volt_level = %u",
				clk_manager->dldo_improve_volt_flag, set_dldo_volt_level);
		}
 
		ret	= hisp_ffa_set_ispcpu_volt(set_dldo_volt_level, pwr_dldo_efuse);
		if (ret != 0) {
			pr_err("[%s] Failed : ISPCPU_CLK set DLOD fail ret:0x%x\n", __func__, ret);
		}
		return ret;
	}
#else
	(void)rate;
#endif
	return 0;
}

static int hisp_ispcpu_set_clk_rate(unsigned int rate)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	int ret;
	unsigned int type = ISPCPU_CLK;
	if (rate > clk_manager->current_ispclk_rate[type]) {
		ret	= hisp_ispcpu_set_volt(rate);
		if (ret != 0) {
			pr_err("[%s] Failed0 : hisp_ispcpu_set_volt fail ret:0x%x\n", __func__, ret);
			return ret;
		}
		mdelay(1);
		ret = clk_set_rate(clk_manager->ispclk[type], (unsigned long)rate);
		if (ret < 0) {
			pr_err("[%s] Failed0 : DVFS Set.0x%x.%s Rate.%u. %d.%08d M\n",
					__func__, type, clk_manager->clk_name[type], rate,
					rate / HZ_TO_MHZ_DIV, rate % HZ_TO_MHZ_DIV);
			return ret;
		}
	} else {
		ret = clk_set_rate(clk_manager->ispclk[type], (unsigned long)rate);
		if (ret < 0) {
			pr_err("[%s] Failed1 : DVFS Set.0x%x.%s Rate.%u. %d.%08d M\n",
					__func__, type, clk_manager->clk_name[type], rate,
					rate / HZ_TO_MHZ_DIV, rate % HZ_TO_MHZ_DIV);
			return ret;
		}
		mdelay(1);
		ret	= hisp_ispcpu_set_volt(rate);
		if (ret != 0) {
			clk_manager->current_ispclk_rate[type] = rate;
			pr_err("[%s] Failed1 : hisp_ispcpu_set_volt fail ret:0x%x\n", __func__, ret);
			return ret;
		}
	}
	return 0;
}

static int hisp_clock_setclkrate(unsigned int type, unsigned int rate)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	int ret;

#ifdef DEBUG_HISP
	int status = hisp_check_pcie_stat();
	if (status != ISP_NORMAL_MODE)
		return 0;
#endif

	ret = hisp_clock_invalid_dvfsmask((int)type);
	if (ret != 0) {
		pr_err("[%s] Failed : DVFS type.0x%x, rate.%u, dvfsmask.0x%x\n",
				__func__, type, rate, clk_manager->dvfsmask);
		return -EINVAL;
	}

    if (type >= ISP_CLK_MAX) {
        pr_err("[%s] Failed : Invalid type.0x%x\n", __func__, type);
        return -EINVAL;
    }

	if ((rate > clk_manager->ispclk_value[type]) || (rate == 0)) {
		pr_err("[%s] Fail: type.0x%x.%s, %u. %d.%08dM > %d. %d.%08dM\n",
			__func__, type, clk_manager->clk_name[type],
			rate, rate / HZ_TO_MHZ_DIV,
			rate % HZ_TO_MHZ_DIV, clk_manager->ispclk_value[type],
			clk_manager->ispclk_value[type] / HZ_TO_MHZ_DIV,
			clk_manager->ispclk_value[type] % HZ_TO_MHZ_DIV);
		return -EINVAL;
	}

	ret = pll6_clk_set(type, rate);
	if (ret < 0) {
		pr_err("[%s] Failed : DVFS Set.0x%x.%s Rate.%u. %u.%08u M\n",
			__func__, type, clk_manager->clk_name[type], rate,
			rate / HZ_TO_MHZ_DIV, rate % HZ_TO_MHZ_DIV);
		return ret;
	}

	if (type != ISPCPU_CLK) {
		ret = clk_set_rate(clk_manager->ispclk[type], (unsigned long)rate);
		if (ret < 0) {
			pr_err("[%s] Failed : DVFS Set.0x%x.%s Rate.%u. %u.%08u M\n",
					__func__, type, clk_manager->clk_name[type], rate,
					rate / HZ_TO_MHZ_DIV, rate % HZ_TO_MHZ_DIV);
			return ret;
		}
	} else {
		ret = hisp_ispcpu_set_clk_rate(rate);
		if (ret != 0) {
			pr_err("[%s] Failed : hisp_ispcpu_set_clk_rate fail ret:0x%x\n", __func__, ret);
			return ret;
		}
	}

	clk_manager->current_ispclk_rate[type] = rate;
	hisp_share_update_clk_value((int)type, rate);
	pr_info("[%s] DVFS Set.0x%x.%s Rate.%u. %d.%08d M\n",
		__func__, type, clk_manager->clk_name[type], rate,
		rate / HZ_TO_MHZ_DIV, rate % HZ_TO_MHZ_DIV);

	if (clk_manager->binded_clock_flag != 1)
		return 0;

	ret = hisp_set_binded_clock(type, rate);
	if (ret < 0) {
		pr_err("[%s] Failed : hisp_set_binded_clock %d\n", __func__, ret);
		return ret;
	}

	return 0;
}

#ifdef CONFIG_LPMCU_INTERACT_THERMAL
void hisp_set_low_temp_flag(unsigned int low_temp_flag)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	clk_manager->low_temp_flag = low_temp_flag;
}
#endif

int hisp_clock_set_rate(unsigned int type, unsigned int rate)
{
	int ret = -EINVAL;

	if (hisp_dvfs_enable() == 0) {
		pr_err("[%s] Failed : hisp_dvfs_enable\n", __func__);
		return -EINVAL;
	}

	ret = hisp_clock_setclkrate(type, rate);
	if (ret < 0)
		pr_info("[%s]Failed : hisp_clock_setclkrate.%d\n", __func__, ret);

	return ret;
}

unsigned long hisp_get_clk_rate(unsigned int type)
{
	if (hisp_rproc_enable_status() == 0) {
		pr_err("[%s] ispcpu not start!\n", __func__);
		return 0;
	}

	return hisp_clock_getclkrate(type);
}

static void hisp_clock_ispclk_info_init(void)
{
#ifdef DEBUG_HISP
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	int ret;

	ret = memset_s(&clk_manager->hisp_clk, sizeof(struct hisp_clk_dump_s),
		0, sizeof(struct hisp_clk_dump_s));
	if (ret != 0)
		pr_err("[%s] Failed : memset_s dev->hisp_clk.%d\n",
				__func__, ret);

	clk_manager->hisp_clk.freqmask = (1 << ISPI2C_CLK);
	clk_manager->hisp_clk.freqmask |= (1 << ISPI3C_CLK);
	clk_manager->hisp_clk.enable = 0;
#else
	return;
#endif
}

static int hisp_soc_clock_getdts(struct device_node *np,
			struct hisp_clk_manager_t *clk_manager)
{
	int ret = 0;
	(void)np;
	(void)clk_manager;

#ifdef CONFIG_CAMERA_USE_HISP230
	unsigned int freq_level;

	freq_level = get_module_freq_level(kernel, peri);
	if (freq_level != FREQ_LEVEL2)
		return 0;

	ret = of_property_read_u32_array(np, CLOCKVALUELOW,
				clk_manager->ispclk_value, clk_manager->clock_num);
	if (ret < 0) {
		pr_err("[%s] Failed: clock-value-low get from dtsi.%d\n",
			 __func__, ret);
		return -EINVAL;
	}
#endif

#ifdef CONFIG_KERNEL_CAMERA_USE_HISP120
	ret = of_property_read_u32_array(np, CLOCKVALUELOW,
				clk_manager->ispclk_value_low, clk_manager->clock_num);
	if (ret < 0) {
		pr_err("[%s] Failed: clock-value-low get from dtsi.%d\n",
			 __func__, ret);
		return -EINVAL;
	}
#endif
	return ret;
}

static int hisp_clock_binded_getdts(struct device_node *np,
			struct hisp_clk_manager_t *clk_manager)
{
	int ret;
	unsigned int i;
	unsigned int source_clk;

	ret = of_property_read_u32_array(np, "binded-clock-num", clk_manager->binded_clock_num, MAX_BINED_CLOCK_TYPE);
	if (ret < 0) {
		pr_err("[%s] Failed: binded_clock_num get from dtsi.%d\n", __func__, ret);
		return ret;
	}

	ret = of_property_read_u32_array(np, "binded-source-clock",
			clk_manager->binded_source_clock, clk_manager->binded_clock_num[SOURCE_CLOCK_NUM]);
	if (ret < 0) {
		pr_err("[%s] Failed: binded_source_clock get from dtsi.%d\n", __func__, ret);
		return ret;
	}

	ret = of_property_read_u32_array(np, "binded-target-clock",
			clk_manager->binded_target_clock, clk_manager->binded_clock_num[TARGET_CLOCK_NUM]);
	if (ret < 0) {
		pr_err("[%s] Failed: binded_target_clock get from dtsi.%d\n", __func__, ret);
		return ret;
	}

	for (i = 0; i < clk_manager->binded_clock_num[SOURCE_CLOCK_NUM]; i++) {
		source_clk = clk_manager->binded_source_clock[i];
		if (source_clk >= clk_manager->clock_num) {
			pr_err("[%s] Failed: binded_target_clock[%u].%u invalid\n", __func__, i, source_clk);
			return -EINVAL;
		}
		clk_manager->binded_vote_level[source_clk] = HISP_CLK_SVS;
	}

	return 0;
}

static int hisp_clock_getdts(struct device_node *np,
			struct hisp_clk_manager_t *clk_manager)
{
	int ret;

	ret = of_property_read_u32(np, "clock-num",
				(unsigned int *)(&clk_manager->clock_num));
	if (ret < 0) {
		pr_err("[%s] Failed: clock-num get from dtsi.%d\n",
				__func__, ret);
		return -EINVAL;
	}
	if (clk_manager->clock_num > ISP_CLK_MAX) {
		pr_err("[%s] Failed: clock-num invalid.%d\n", __func__, clk_manager->clock_num);
		clk_manager->clock_num = 0;
	}

	ret = of_property_read_string_array(np, "clock-names",
				clk_manager->clk_name, clk_manager->clock_num);
	if (ret < 0) {
		pr_err("[%s] Failed : clock-names get from dtsi.%d\n",
				__func__, ret);
		return -EINVAL;
	}

	pr_info("[%s] CLOCKVALUE.%s\n", __func__, CLOCKVALUE);
	ret = of_property_read_u32_array(np, CLOCKVALUE,
				clk_manager->ispclk_value, clk_manager->clock_num);
	if (ret < 0) {
		pr_err("[%s] Failed: clock-value get from dtsi.%d\n",
				__func__, ret);
		return -EINVAL;
	}

	ret = hisp_soc_clock_getdts(np, clk_manager);
	if (ret < 0) {
		pr_err("[%s] Failed: hisp_soc_clock_getdts.%d\n",
				__func__, ret);
		return -EINVAL;
	}

	ret = of_property_read_u32_array(np, "clkdis-dvfs",
				clk_manager->clkdis_dvfs, clk_manager->clock_num);
	if (ret < 0) {
		pr_err("[%s] Failed: clkdis-dvfs get from dtsi.%d\n",
				__func__, ret);
		return -EINVAL;
	}

	ret = of_property_read_u32_array(np, "clkdis-need-div",
				clk_manager->clkdis_need_div, clk_manager->clock_num);
	if (ret < 0)
		pr_err("[%s] Failed: clkdis-need-div get from dtsi.%d\n",
				__func__, ret);

	ret = of_property_read_u32(np, "binded-clock-flag",
				(unsigned int *)(&clk_manager->binded_clock_flag));
	if (ret < 0) {
		pr_err("[%s] Failed: binded_clock_flag get from dtsi.%d\n", __func__, ret);
		clk_manager->binded_clock_flag = 0;
	}
	pr_info("[%s] binded_clock_flag.0x%x\n", __func__, clk_manager->binded_clock_flag);

	ret = of_property_read_u32(np, "ispcpu_switch_volt_feq",
		(unsigned int *)(&clk_manager->ispcpu_switch_volt_feq));
	if (ret < 0) {
		pr_info("[%s] Notice: ispcpu_switch_volt_feq,ret.%d, maybe not supported\n", __func__, ret);
		clk_manager->ispcpu_switch_volt_feq = 0;
	}
	if (clk_manager->ispcpu_switch_volt_feq < clk_manager->clkdis_dvfs[ISPCPU_CLK] ||
		clk_manager->ispcpu_switch_volt_feq > clk_manager->ispclk_value[ISPCPU_CLK]) {
		pr_info("[%s] Notice: ispcpu_switch_volt_feq get from dts invalid, set to 0 %u\n",
				__func__, clk_manager->ispcpu_switch_volt_feq);
		clk_manager->ispcpu_switch_volt_feq = 0;
	}
	pr_info("[%s] ispcpu_switch_volt_feq is.%u\n", __func__, clk_manager->ispcpu_switch_volt_feq);

	ret = of_property_read_u32(np, "pll6-usage-num", (unsigned int *)(&clk_manager->pll6_usage_num));
	if (ret < 0) {
		pr_info("[%s] Notice: pll6-usage-num,ret.%d, maybe not supported\n", __func__, ret);
		clk_manager->pll6_usage_num = 0;
	}
	clk_manager->pll6_usage_num = hisp_min(PLL6_USAGE_NUM, clk_manager->pll6_usage_num);

	ret = of_property_read_u32_array(np, "pll6-usage-tbl", (unsigned int *)(&clk_manager->pll6_usage_tbl),
		clk_manager->pll6_usage_num * (sizeof(struct pll6_usage_item) / sizeof(unsigned int)));
	if (ret < 0) {
		pr_info("[%s] Notice: pll6-usage-tbl, ret %d with pll6-usage-num %d.\n",
			__func__, ret, clk_manager->pll6_usage_num);
		memset_s(clk_manager->pll6_usage_tbl, sizeof(clk_manager->pll6_usage_tbl), 0, sizeof(clk_manager->pll6_usage_tbl));
		clk_manager->pll6_usage_num = 0;
	}

	pr_info("[%s]: dump pll6_usage_tbl[%u] info:\n", __func__, clk_manager->pll6_usage_num);

	if (clk_manager->binded_clock_flag == 0)
		return 0;

	ret = hisp_clock_binded_getdts(np, clk_manager);
	if (ret < 0) {
		pr_err("[%s] Failed: hisp_clock_binded_getdts.%d\n", __func__, ret);
		return ret;
	}

	return 0;
}

static int hisp_clock_dvfs_getdts(struct device_node *np)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	int ret;

	ret = of_property_read_u32(np, "usedvfs",
				(unsigned int *)(&clk_manager->usedvfs));
	if (ret < 0) {
		pr_err("[%s] Failed: usedvfs get from dtsi.%d\n",
				__func__, ret);
		return -EINVAL;
	}
	pr_info("[%s] usedvfs.0x%x\n", __func__, clk_manager->usedvfs);

	if (clk_manager->usedvfs == 0)
		return 0;

	ret = of_property_read_u32_array(np, "clock-value",
			clk_manager->clkdn[HISP_CLK_TURBO], clk_manager->clock_num);
	if (ret < 0) {
		pr_err("[%s] Failed: TURBO get from dtsi.%d\n",
				__func__, ret);
		return -EINVAL;
	}

	ret = of_property_read_u32_array(np, "clkdn-normal",
			clk_manager->clkdn[HISP_CLK_NORMINAL], clk_manager->clock_num);
	if (ret < 0) {
		pr_err("[%s] Failed: NORMINAL get from dtsi.%d\n",
				__func__, ret);
		return -EINVAL;
	}

	ret = of_property_read_u32_array(np, "clkdn-highsvs",
			clk_manager->clkdn[HISP_CLK_HIGHSVS], clk_manager->clock_num);
	if (ret < 0)
		pr_err("[%s]Failed: HIGHSVS get from dtsi.%d\n", __func__, ret);

	ret = of_property_read_u32_array(np, "clkdn-svs",
			clk_manager->clkdn[HISP_CLK_SVS], clk_manager->clock_num);
	if (ret < 0) {
		pr_err("[%s] Failed: SVS get from dtsi.%d\n", __func__, ret);
		return -EINVAL;
	}

	ret = of_property_read_u32_array(np, "clkdn-lowsvs",
			clk_manager->clkdn[HISP_CLK_LOWSVS], clk_manager->clock_num);
	if (ret < 0)
		pr_err("[%s] Failed: LOW SVS get from dtsi.%d\n",
				__func__, ret);

	ret = of_property_read_u32_array(np, "clkdis-dvfs",
			clk_manager->clkdn[HISP_CLK_DISDVFS], clk_manager->clock_num);
	if (ret < 0) {
		pr_err("[%s] Failed: SVS get from dtsi.%d\n", __func__, ret);
		return -EINVAL;
	}

	ret = of_property_read_u32(np, "ispcpu_switch_low_volt_feq",
		(unsigned int *)(&clk_manager->ispcpu_switch_low_volt_feq));
	if (ret < 0) {
		pr_info("[%s] Notice: ispcpu_switch_low_volt_feq,ret.%d, maybe not supported\n", __func__, ret);
		clk_manager->ispcpu_switch_low_volt_feq = VALUE_NOT_SET;
	}
	if (clk_manager->ispcpu_switch_low_volt_feq < clk_manager->clkdis_dvfs[ISPCPU_CLK] ||
		clk_manager->ispcpu_switch_low_volt_feq > clk_manager->ispclk_value[ISPCPU_CLK]) {
		pr_info("[%s] Notice: ispcpu_switch_low_volt_feq get from dts invalid, set to 0 %u\n",
				__func__, clk_manager->ispcpu_switch_low_volt_feq);
		clk_manager->ispcpu_switch_low_volt_feq = VALUE_NOT_SET;
	}
	pr_info("[%s] ispcpu_switch_low_volt_feq is.%u\n", __func__, clk_manager->ispcpu_switch_low_volt_feq);

	ret = of_property_read_u32(np, "ispcpu_dldo_efuse_bit_start",
		(unsigned int *)(&clk_manager->ispcpu_dldo_efuse_bit_start));
	if (ret < 0) {
		pr_info("[%s] Notice: ispcpu_dldo_efuse_bit_start,ret.%d, maybe not supported\n", __func__, ret);
		clk_manager->ispcpu_dldo_efuse_bit_start = VALUE_NOT_SET;
	}

	ret = of_property_read_u32(np, "ispcpu_dldo_efuse_bit_cnt",
		(unsigned int *)(&clk_manager->ispcpu_dldo_efuse_bit_cnt));
	if (ret < 0) {
		pr_info("[%s] Notice: ispcpu_dldo_efuse_bit_cnt,ret.%d, maybe not supported\n", __func__, ret);
		clk_manager->ispcpu_dldo_efuse_bit_cnt = VALUE_NOT_SET;
	}

	ret = of_property_read_u32(np, "ispcpu_switch_low_temp_enable",
		(unsigned int *)(&clk_manager->low_temp_enable));
	if (ret < 0) {
		pr_info("[%s] Notice: ispcpu_switch_low_temp_enable,ret.%d, maybe not supported\n", __func__, ret);
		clk_manager->low_temp_enable = VALUE_NOT_SET;
	}

	return 0;
}

static int hisp_clk_init(struct device *dev)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	unsigned int i;

	for (i = 0; i < clk_manager->clock_num; i++) {
		clk_manager->ispclk[i] = devm_clk_get(dev, clk_manager->clk_name[i]);
		if (IS_ERR_OR_NULL(clk_manager->ispclk[i])) {
			pr_err("[%s] Failed : ispclk.%s.%d.%li\n", __func__,
				clk_manager->clk_name[i], i, PTR_ERR(clk_manager->ispclk[i]));
			return -EINVAL;
		}
		pr_info("[%s] ISP clock.%u.%s: %d.%d M\n", __func__, i,
			clk_manager->clk_name[i], clk_manager->ispclk_value[i] / HZ_TO_MHZ_DIV,
			clk_manager->ispclk_value[i] % HZ_TO_MHZ_DIV);

		pr_info("[%s] clkdis.%u.%s: %d.%d M\n", __func__, i,
			clk_manager->clk_name[i], clk_manager->clkdis_dvfs[i] / HZ_TO_MHZ_DIV,
			clk_manager->clkdis_dvfs[i] % HZ_TO_MHZ_DIV);
	}

	return 0;
}

static unsigned int hisp_get_efuse(struct efuse_desc desc)
{
	unsigned int efuse = 0;
	size_t e_size = 0;

	desc.buf = &efuse;
	e_size = sizeof(efuse) / sizeof(unsigned int);
	desc.buf_size = (unsigned int) e_size;
	if (efuse_read_value_t(&desc) != EFUSE_OK) {
		pr_err("dldo efuse read failed");
		return 0;
	}

	return efuse;
}

static void hisp_clock_get_dldo_efuse(void) {
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	struct efuse_desc desc = {0};

	if (clk_manager->ispcpu_switch_low_volt_feq == VALUE_NOT_SET) {
		desc.start_bit = clk_manager->ispcpu_dldo_efuse_bit_start;
		desc.bit_cnt = clk_manager->ispcpu_dldo_efuse_bit_cnt;
		desc.item_vid = EFUSE_KERNEL_PARTIALGOOD_FLAG8;

		clk_manager->efuse_dldo = hisp_get_efuse(desc);
		if (clk_manager->efuse_dldo > DLDO_EFUSE_MAX_VALUE || clk_manager->efuse_dldo < DLDO_EFUSE_MIN_VALUE) {
			pr_info("Do not support dldo efuse, val = %u", clk_manager->efuse_dldo);
		} else {
			pr_info("dldo efuse val = %u", clk_manager->efuse_dldo);
		}
		// FT version dldo en bit
		desc.start_bit = EFUSE_FT_START_BIT;
		desc.bit_cnt = EFUSE_FT_BIT_SIZE;
		desc.item_vid = EFUSE_KERNEL_PARTIALGOOD_FLAG1;

		clk_manager->ft_dldo = hisp_get_efuse(desc);
		if (clk_manager->ft_dldo == 0) {
			pr_info("FT version do not support dldo volt change, val = %u", clk_manager->ft_dldo);
		} else {
			pr_info("FT version support dldo volt change, val = %u", clk_manager->ft_dldo);
		}
	} else {
		desc.start_bit = clk_manager->ispcpu_dldo_efuse_bit_start;
		desc.bit_cnt = clk_manager->ispcpu_dldo_efuse_bit_cnt;
		desc.item_vid = EFUSE_KERNEL_DLDO_CTRL;

		clk_manager->efuse_dldo = hisp_get_efuse(desc);
		pr_info("hisp_get_efuse:dldo efuse(20bit) val = %u", clk_manager->efuse_dldo);

		// dldo_improve_volt_flag
		desc.start_bit = EFUSE_IMPROVE_VOL_FLAG_START_BIT;
		desc.bit_cnt = EFUSE_IMPROVE_VOL_FLAG_BIT_SIZE;
		desc.item_vid = EFUSE_KERNEL_PARTIALGOOD_FLAG1;
 
		clk_manager->dldo_improve_volt_flag = hisp_get_efuse(desc);
		pr_info("dldo_improve_volt_flag = %u", clk_manager->dldo_improve_volt_flag);
	}
}

int hisp_clock_manager_init(struct device *dev)
{
	struct device_node *np = dev->of_node;
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	int ret = 0;

	clk_manager->binded_clock_flag = 0;
	clk_manager->low_temp_flag = 0;
	
#ifdef CONFIG_LPMCU_INTERACT_THERMAL
	if (get_lowtemp_status() == 1) {
		clk_manager->low_temp_flag = 1;
	} 
#endif

	ret = hisp_clock_getdts(np, clk_manager);
	if (ret < 0) {
		pr_err("[%s] Failed: clock_getdts.%d\n", __func__, ret);
		return ret;
	}

	ret = hisp_clock_dvfs_getdts(np);
	if (ret < 0) {
		pr_err("[%s] Failed: hisp_clock_dvfs_getdts.%d\n", __func__, ret);
		return ret;
	}

	ret = hisp_clk_init(dev);
	if (ret != 0) {
		pr_err("[%s] Failed : hisp_clk_init.%d.\n", __func__, ret);
		return ret;
	}

	hisp_clock_get_dldo_efuse();

#ifdef CONFIG_LPMCU_INTERACT_THERMAL
	if (clk_manager->low_temp_enable != VALUE_NOT_SET) {
		hisp_thermal_init();
	}
#endif

	clk_manager->dvfsmask = (1 << ISPI2C_CLK);
	clk_manager->dvfsmask |= (1 << ISPI3C_CLK);

	hisp_clock_ispclk_info_init();

	return 0;
}

int hisp_clock_manager_deinit(struct device *dev)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
#ifdef DEBUG_HISP
	int ret;
#endif

	(void)dev;

#ifdef CONFIG_LPMCU_INTERACT_THERMAL
	if (clk_manager->low_temp_enable != VALUE_NOT_SET) {
		hisp_thermal_deinit();
	}
#endif

#ifdef DEBUG_HISP
	ret = memset_s(&clk_manager->hisp_clk, sizeof(struct hisp_clk_dump_s),
		0, sizeof(struct hisp_clk_dump_s));
	if (ret != 0)
		pr_err("[%s] Failed : memset_s clk_manager->hisp_clk.%d\n",
			__func__, ret);
#endif

	return 0;
}

#ifdef DEBUG_HISP
#define ISPCPU_CLK_DEBUG  "ispcpu"
#define ISPFUNC_CLK_DEBUG "ispfunc"
#define TMP_SIZE 0x1000

static unsigned int hisp_clock_get_ispclk_enable(void)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;

	return clk_manager->hisp_clk.enable;
}

static int hisp_set_ispclk_enable(int state)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;

	if (state != 0 && state != 1) {
		pr_err("[%s] Failed : state.%x\n", __func__, state);
		return -EINVAL;
	}

	clk_manager->hisp_clk.enable = state;

	return 0;
}

static int hisp_clock_set_ispclk_freq(unsigned int type, unsigned long value)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	unsigned int freq_mask = (1 << type) & clk_manager->hisp_clk.freqmask;

	if ((type >= ISP_CLK_MAX) || (freq_mask != 0)) {
		pr_err("[%s] Failed : type.%u, freqmask.0x%x\n",
			__func__, type, clk_manager->hisp_clk.freqmask);
		return -EINVAL;
	}

	clk_manager->hisp_clk.freq[type] = value;
	pr_info("[%s] freq.%lu -> type.%u\n", __func__, value, type);

	return 0;
}

static unsigned long hisp_clock_get_ispclk_freq(unsigned int type)
{
	struct hisp_clk_manager_t *clk_manager = &hisp_clk_manager;
	unsigned long freq = 0;
	unsigned int freq_mask;

	if (hisp_clock_get_ispclk_enable() == 0)
		return 0;

	freq_mask = (1 << type) & clk_manager->hisp_clk.freqmask;
	if ((type >= ISP_CLK_MAX) || (freq_mask != 0)) {
		pr_err("[%s] Failed : type.%u, freqmask.0x%x\n",
			__func__, type, clk_manager->hisp_clk.freqmask);
		return 0;
	}
	freq = clk_manager->hisp_clk.freq[type];
	pr_info("[%s] type.%u freq.%lu\n", __func__, type, freq);
	return freq;
}

static int hisp_clk_show_status(char *tmp, ssize_t *size)
{
	int ret = 0;
	unsigned int ret1;
	const char *p;

	ret1 = hisp_clock_get_ispclk_enable();
	if (ret1 == 0) {
		pr_err("[%s] debug isp clk not enable!\n", __func__);
		return -EINVAL;
	}

	ret = hisp_rproc_enable_status();
	if (ret == 0) {
		pr_err("[%s] ispcpu not boot!\n", __func__);
		return -EINVAL;
	}

	ret = hisp_pwr_get_isppwr_state(PWSTAT_MEDIA);
	if (ret == 0) {
		pr_err("[%s] failed: hisp_pwr_get_isppwr_state\n", __func__);
		return -EINVAL;
	}

	ret1 = hisp_clock_get_ispclk_enable();
	if (ret1 == 0)
		p = "disable";
	else
		p = "enable";

	ret = snprintf_s(tmp, NONSEC_MAX_SIZE, NONSEC_MAX_SIZE - 1,
			   "\n Isp Clk Enable: %s\n", p);
	if (ret < 0) {
		pr_err("[%s] failed: isp clk!\n", __func__);
		return -EINVAL;
	}

	*size += ret;

	ret = snprintf_s(*size + tmp, NONSEC_MAX_SIZE,
			   NONSEC_MAX_SIZE - 1, "%s\n", "NOW THE CLOK SET:");
	if (ret < 0) {
		pr_err("[%s] failed: NOW THE CLOCK!\n", __func__);
		return -EINVAL;
	}
	*size += ret;

	return 0;
}

static int hisp_clk_show_ispcore(char *tmp, ssize_t *size)
{
	int ret = 0;
	unsigned char index = 0;

	for (index = ISPCPU_CLK; index < ISP_CLK_MAX; index++) {
		ret = snprintf_s(tmp + *size, NONSEC_MAX_SIZE,
			NONSEC_MAX_SIZE - 1,
			"%x: %lu  Real CLK:%lu\n",
			index, hisp_clock_get_ispclk_freq(index),
			hisp_clock_getclkrate(index));
		if (ret < 0) {
			pr_err("[%s]failed:%x!\n", __func__, index);
			return -EINVAL;
		}
		*size += ret;
	}

	return 0;
}

ssize_t hisp_clk_show(struct device *pdev,
		struct device_attribute *attr, char *buf)
{
	ssize_t size = 0;
	int ret = 0;
	char *tmp = NULL;

	(void)pdev;
	(void)attr;

	pr_info("[%s] +\n", __func__);

	tmp = kzalloc(TMP_SIZE, GFP_KERNEL);
	if (tmp == NULL)
		return 0;

	ret = hisp_clk_show_status(tmp, &size);
	if (ret < 0) {
		pr_err("[%s] failed: hisp_clk_show_status!\n", __func__);
		goto show_err;
	}

	ret = hisp_clk_show_ispcore(tmp, &size);
	if (ret < 0) {
		pr_err("[%s] failed: hisp_clk_show_ispcore!\n", __func__);
		goto show_err;
	}

show_err:
	ret = memcpy_s((void *)buf, TMP_SIZE, (void *)tmp, TMP_SIZE);
	if (ret != 0)
		pr_err("[%s] Failed : memcpy_s buf from tmp fail\n", __func__);

	kfree((void *)tmp);

	pr_info("[%s] -\n", __func__);
	return size;
}

static int hisp_clk_store_freq(const char *buf, size_t count)
{
	char *p = NULL;
	size_t len = 0;
	unsigned long freq_value = 0;
	int ret;

	p = memchr(buf, ':', count);
	if (p == NULL) {
		pr_err("[%s] Failed buf cmd!\n", __func__);
		return -EINVAL;
	}
	len = (size_t)(p - buf);
	if (len == 0)
		return -EINVAL;
	p += 1;

	ret = kstrtoul(p, 10, &freq_value);
	pr_info("[%s] freq_value.%lu,ret.%d\n", __func__, freq_value, ret);
	if (ret < 0)
		return -EINVAL;
	if (strncmp(buf, ISPCPU_CLK_DEBUG, len) == 0) {
		hisp_clock_set_ispclk_freq(ISPCPU_CLK, freq_value);
		pr_info("[%s] Ispcpu Clk: %lu\n", __func__, freq_value);
	} else if (strncmp(buf, ISPFUNC_CLK_DEBUG, len) == 0) {
		hisp_clock_set_ispclk_freq(ISPFUNC_CLK, freq_value);
		pr_info("[%s] Ispfunc Clk:%lu\n", __func__, freq_value);
	} else {
		p = strstr(buf, ISPFUNC_CLK_DEBUG);
		if (p != NULL) {
			p += strlen(ISPFUNC_CLK_DEBUG);
			pr_info("[%s] len.%lu buf.%s\n",
				__func__, strlen(ISPFUNC_CLK_DEBUG), p);
			hisp_clock_set_ispclk_freq((unsigned int)(*p - (char)'2' + (char)ISPFUNC2_CLK),
					freq_value);
			pr_info("[%s] Ispfunc%c Clk.%lu\n",
				__func__, *p, freq_value);
		}
	}

	return 0;
}

ssize_t hisp_clk_store(struct device *pdev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	char *p = NULL;
	size_t len = 0;
	char index = 0;
	int ret;

	(void)pdev;
	(void)attr;

	p = memchr(buf, '\n', count);
	if (p == NULL) {
		pr_err("[%s] Failed p.%pK\n", __func__, p);
		return -EINVAL;
	}

	len = (size_t)(p - buf);
	if (len == 0)
		return -EINVAL;

	if (strncmp(buf, "enable", len) == 0) {
		hisp_set_ispclk_enable(1);
	} else if (strncmp(buf, "disable", len) == 0) {
		hisp_set_ispclk_enable(0);
		for (index = ISPCPU_CLK; index < ISP_CLK_MAX; index++)
			hisp_clock_set_ispclk_freq(ISPCPU_CLK, 0);
	} else {
		ret = hisp_clk_store_freq(buf, count);
		if (ret < 0) {
			pr_err("[%s] Failed buf cmd!\n", __func__);
			return -EINVAL;
		}
	}

	return (ssize_t)count;
}
#endif

