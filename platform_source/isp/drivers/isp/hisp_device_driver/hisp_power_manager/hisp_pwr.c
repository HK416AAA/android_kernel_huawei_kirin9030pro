/*
 * driver, hisp_pwr.c
 *
 * Copyright (c) 2013 ISP Technologies CO., Ltd.
 *
 */

#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/err.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/clk.h>
#include <linux/regulator/consumer.h>
#ifdef CONFIG_LOAD_IMAGE
#include <platform_include/see/load_sec_image.h>
#endif
#include <platform_include/basicplatform/linux/partition/partition_ap_kernel.h>
#include <platform_include/isp/linux/hisp_remoteproc.h>
#include <platform_include/see/efuse_driver.h>
#include <teek_client_id.h>
#include <platform_include/basicplatform/linux/partition/partition_macro.h>
#include "hisp_internel.h"
#include <isp_ddr_map.h>
#include <securec.h>
#include "platform_include/basicplatform/linux/peri_volt_poll.h"

#if defined(CONFIG_SOC_PG_INFO)
#include <platform_include/basicplatform/linux/soc_spec.h>
#endif

#ifdef CONFIG_CAMERA_USE_HISP230
#include "soc_spec_info.h"
#endif

#ifdef DEBUG_HISP
#include <linux/iommu/mm_svm.h>
#include "hisp_pcie.h"
#endif

#include "aslr/ext_aslr.h"
#include "hisp_clock_manager.h"
#include "hisp_power_manager.h"

#define ISP_CFG_SIZE                        0x1000
#define ISP_LOAD_PARTITION                  "isp_firmware"
#define DEVICE_PATH                         "/dev/block/bootdevice/by-name/"

#define ISPCPU_REMAP_ENABLE                 (1 << 31)
#define ISP_SUB_CTRL_ISP_A7_CTRL_0          (0x40)
#define ISP_SUB_CTRL_CANARY_ADDR            (0x6FC)

#define QOS_MAX_NUM                         64
#define QOS_NSECREG                         0U
#define QOS_SECREG                          1U
#define QOS_NULLREG                         2U

#ifdef CONFIG_KERNEL_CAMERA_USE_HISP120
#define ISP_020010_MODULE_CGR_TOP           0x020010
#define ISP_BASE_ADDR_CVDR_SRT              0x2E000
#define ISP_BASE_ADDR_CVDR_RT               0x22000
#define ISP_SUB_CTRL_BASE_ADDR              0x183000
#define SMMU_CLK_ENABLE                     0x400000

#define CVDR_RT_CVDR_CFG_REG                0x0
#define CVDR_RT_CVDR_WR_QOS_CFG_REG         0xC
#define CVDR_RT_CVDR_RD_QOS_CFG_REG         0x10
#define CVDR_SRT_CVDR_CFG_REG               0x0
#define CVDR_SRT_CVDR_WR_QOS_CFG_REG        0xC
#define CVDR_SRT_CVDR_RD_QOS_CFG_REG        0x10
#define CVDR_SRT_VP_WR_IF_CFG_10_REG        0xC8
#define CVDR_SRT_VP_WR_IF_CFG_11_REG        0xD8
#define CVDR_SRT_VP_WR_IF_CFG_25_REG        0x1B8
#define CVDR_SRT_NR_RD_CFG_1_REG            0xA10
#define CVDR_SRT_LIMITER_NR_RD_1_REG        0xA18
#define CVDR_SRT_NR_RD_CFG_3_REG            0xA30

#define SUB_CTRL_ISP_FLUX_CTRL2_0_REG       0x190
#define SUB_CTRL_ISP_FLUX_CTRL2_1_REG       0x194
#define SUB_CTRL_ISP_FLUX_CTRL3_0_REG       0x198
#define SUB_CTRL_ISP_FLUX_CTRL3_1_REG       0x19C

#define CVDR_CLK_ENABLE                     (0x40020)
#endif

#define ALL_FE_EFUSE                            (0x7)
#define PG_FE_0_1_EFUSE                         (0x3)

struct hisp_qos {
	unsigned int secreg;
	unsigned int num;
	unsigned int *offset;
	unsigned int *value;
};

struct hisp_pwr {
	unsigned int refs_isp_power;
	unsigned int refs_isp_nsec_init;
	unsigned int refs_isp_sec_init;
	unsigned int refs_ispcpu_init;
	unsigned int refs_isp_nsec_dst;
	unsigned int refs_isp_sec_dst;
	unsigned int use_smmuv3_flag;
	unsigned int use_buck13_flag;
	unsigned int ispcpu_supply_flag;
	unsigned int isp_ecc;
	unsigned int csi_supply_flag;
	unsigned int ispsmmu_init_byap;
	unsigned int pwstat_num;
	struct mutex pwrlock;
	struct hisp_qos qos;
	struct device *device;
	struct regulator *clockdep_supply;
	struct regulator *ispcore_supply;
	struct regulator *ispcpu_supply;
	struct regulator *isptcu_supply;
	struct regulator *csi_supply;
	unsigned int pwstat_type[PWSTAT_MAX];
	unsigned int pwstat_offset[PWSTAT_MAX];
	unsigned int pwstat_bit[PWSTAT_MAX];
	unsigned int pwstat_wanted[PWSTAT_MAX];
};

struct hisp_pwr isp_pwr_dev;

int hisp_bsp_read_bin(const char *partion_name, unsigned int offset,
		unsigned int length, char *buffer)
{
	int ret = -1;
	char *pathname = NULL;
	size_t pathlen;
	struct file *fp = NULL;
	mm_segment_t fs;
	loff_t pos = 0;

	if ((partion_name == NULL) || (buffer == NULL))
		return -EINVAL;

	/* get resource */
	pathlen = sizeof(DEVICE_PATH) +
		strnlen(partion_name, (unsigned long)PART_NAMELEN);
	pathname = kmalloc(pathlen, GFP_KERNEL);
	if (pathname == NULL)
		return -EINVAL;

	ret = (int)flash_find_ptn_s((const char *)partion_name, pathname, (unsigned int)pathlen);
	if (ret < 0) {
		pr_err("partion_name.%s not in partion table!\n", partion_name);
		goto error;
	}

	fp = filp_open(pathname, O_RDONLY, 0600);
	if (IS_ERR(fp)) {
		pr_err("filp_open(%s) failed", pathname);
		ret = -1;
		goto error;
	}

	ret = (int)vfs_llseek(fp, offset, SEEK_SET);
	if (ret < 0) {
		pr_err("seek ops failed, ret %d", ret);
		goto err_close;
	}

	fs = get_fs();
	set_fs(KERNEL_DS);

	pos = fp->f_pos;
	ret = (int)vfs_read(fp, (char __user *)buffer, length, &pos);
	if (ret != (int)length) {
		pr_err("read ops failed, read ret=%d(length=%u)", ret, length);
		set_fs(fs);
		ret = -1;
		goto err_close;
	}
	set_fs(fs);

err_close:
	filp_close(fp, NULL);

error:
	/* free resource */
	if (pathname != NULL) {
		kfree(pathname);
		pathname = NULL;
	}

	return ret;
}

static int hisp_pwr_need_powerup(unsigned int refs)
{
	if (refs == ISP_MAX_NUM_MAGIC)
		pr_err("[%s] exc, refs == 0xffffffff\n", __func__);

	return ((refs == 0) ? 1 : 0);
}

static int hisp_pwr_need_powerdn(unsigned int refs)
{
	if (refs == ISP_MAX_NUM_MAGIC)
		pr_err("[%s] exc, refs == 0xffffffff\n", __func__);

	return ((refs == 1) ? 1 : 0);
}

int hisp_pwr_get_isppwr_state(unsigned int type)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	void __iomem *cfg_base = NULL;
	unsigned int media_pw_stat = 0;
	unsigned int pwsta_num = 0;

#ifdef DEBUG_HISP
	int status = hisp_check_pcie_stat();
	if (status != ISP_NORMAL_MODE)
		return 0;
#endif

	pwsta_num = dev->pwstat_num > PWSTAT_MAX ? PWSTAT_MAX : dev->pwstat_num;

	if (type >= pwsta_num) {
		pr_err("[%s] Failed: type.%u, pwstat_num.%u\n",
			__func__, type, pwsta_num);
		return 0;
	}

	if (dev->pwstat_offset[type] >= ISP_CFG_SIZE) {
		pr_err("[%s] Failed: pwstat_offset.0x%x, type.%u\n",
			__func__, dev->pwstat_offset[type], type);
		return 0;
	}

	cfg_base = hisp_dev_get_regaddr(dev->pwstat_type[type]);
	if (cfg_base == NULL) {
		pr_err("[%s] Failed: type.%u\n", __func__, type);
		return 0;
	}
	media_pw_stat = __raw_readl(cfg_base + dev->pwstat_offset[type]);
	media_pw_stat >>= dev->pwstat_bit[type];
	media_pw_stat &= 0x01;

	if (media_pw_stat == dev->pwstat_wanted[type])
		return 1;
	else
		return 0;
}

static int hisp_pwr_dst_ispcpu(u64 remap_addr, unsigned int canary)
{
#ifndef CONFIG_HISP_FFA_SUPPORT
	void __iomem *isp_subctrl_base;
#endif
	int ret = 0;
#ifdef DEBUG_HISP
	int status;
#endif

	pr_info("[%s] +\n", __func__);

#ifdef DEBUG_HISP
	status = hisp_check_pcie_stat();
	if (status == ISP_PCIE_NREADY) {
		return status;
	}
	else if (status == ISP_PCIE_MODE) {
		goto smc_disreset_cpu;
	}
#endif
	ret = hisp_pwr_get_isppwr_state(PWSTAT_MEDIA);
	if (ret == 0) {
		pr_err("[%s] Failed : get_media1_subsys_power_state. %d\n",
				__func__, ret);
		return -EINVAL;
	}

	ret = hisp_pwr_get_isppwr_state(PWSTAT_ISPSYS);
	if (ret == 0) {
		pr_err("[%s] Failed : get_isptop_power_state. %d\n",
				__func__, ret);
		return -EINVAL;
	}

#ifndef CONFIG_HISP_FFA_SUPPORT
	isp_subctrl_base = hisp_dev_get_regaddr(ISP_SUBCTRL);
	if (isp_subctrl_base == NULL) {
		pr_err("[%s] Failed : isp_subctrl_base\n", __func__);
		return -ENOMEM;
	}

	__raw_writel((unsigned int)(ISPCPU_REMAP_ENABLE | (remap_addr >> 16)),
		isp_subctrl_base + ISP_SUB_CTRL_ISP_A7_CTRL_0);

	__raw_writel(canary, isp_subctrl_base + ISP_SUB_CTRL_CANARY_ADDR);
#endif

#ifdef DEBUG_HISP
smc_disreset_cpu:
#endif
#ifdef CONFIG_HISP_FFA_SUPPORT
	(void)remap_addr;
	ret = hisp_ffa_disreset_ispcpu(canary, hisp_get_dyn_bootaddr());
#else
	ret = hisp_smc_disreset_ispcpu();
#endif
	if (ret < 0) {
		pr_err("[%s] Failed : hisp disreset ispcpu. %d\n", __func__, ret);
		return ret;
	}

	pr_info("[%s] -\n", __func__);
	return 0;
}

#if defined(CONFIG_SOC_PG_INFO) && defined(CONFIG_HISP_FE_PG)
static int hisp_get_fe_pg(void) {
	struct hisp_shared_para *param = NULL;
	struct soc_component_pg_info pg_info;
 
	get_soc_pg_info_by_index(SOC_COMPONENT_MEDIA2_ISP_FE_INFO, &pg_info);
	pr_info("efuse_value: 0x%08x, tailor_strategy: %d", pg_info.efuse_value, pg_info.tailor_strategy);

	if (pg_info.tailor_strategy == SOC_SPEC_EFUSE_INVALID_VALUE ||
		pg_info.tailor_strategy == SOC_COMPONENT_TAILOR_STRATEGY_2)
		return -EINVAL;

	param = hisp_share_get_para();
	if (param == NULL) {
		pr_err("[%s] share param is NULL!\n", __func__);
		return -EINVAL;
	}

	if (pg_info.tailor_strategy == SOC_COMPONENT_NOT_TAILOR ||
		pg_info.tailor_strategy == SOC_COMPONENT_NOT_TAILOR_EFUSE_NONE) {
		param->fe_pg_efuse = ALL_FE_EFUSE;
	} else if (pg_info.tailor_strategy == SOC_COMPONENT_TAILOR_STRATEGY_1 && pg_info.efuse_value == ALL_FE_EFUSE){
        pr_info("NOTICE:SOC_COMPONENT_TAILOR_STRATEGY_1, 3 FE Valiable, Only Use FE 0, FE 1");
		param->fe_pg_efuse = PG_FE_0_1_EFUSE;
	} else {
		param->fe_pg_efuse = pg_info.efuse_value;
	}

	pr_info("fe_pg_efuse %u\n", param->fe_pg_efuse);

    return 0;
}
#endif

#ifdef DEBUG_HISP
static int hisp_pwr_subsys_common_up_pcie(void)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	struct isp_pcie_cfg *cfg;
	int ret;

	cfg = hisp_get_pcie_cfg();
	if (cfg == NULL) {
		pr_err("Failed : isp pcie status abnormal\n");
		return -EINVAL;
	}

	pr_debug("[%s] media2 vcodec start power up", __func__);
#ifdef CONFIG_HISP_FFA_SUPPORT
	ret = hisp_ffa_media2_power_up();
#else
	ret = hisp_smc_media2_vcodec_power_up(cfg->isp_pci_inuse_flag, cfg->isp_pci_addr);
#endif
	if (ret != 0) {
		pr_err("[%s] Failed: hisp_smc_media2_vcodec_power_up.%d\n", __func__, ret);
		return ret;
	}
	pr_debug("[%s] smmu start power up", __func__);
	if (dev->use_smmuv3_flag) {
#if defined(CONFIG_ARM_SMMU_V3) || defined(CONFIG_MM_SMMU_V3)
		ret = mm_smmu_poweron(dev->device);
		if (ret != 0) {
			pr_err("[%s] Failed:isptcu enable.%d\n", __func__, ret);
#ifdef CONFIG_HISP_FFA_SUPPORT
			(void)hisp_ffa_media2_power_down();
#else
			(void)hisp_smc_media2_vcodec_power_down(cfg->isp_pci_inuse_flag, cfg->isp_pci_addr);
#endif
			return ret;
		}
#endif
	}

#ifndef CONFIG_HISP_FFA_SUPPORT
	pr_debug("[%s] ispnoc r8 start power up", __func__);
	ret = hisp_smc_ispnoc_r8_power_up(cfg->isp_pci_inuse_flag, cfg->isp_pci_addr);
	if (ret != 0) {
		pr_err("[%s] Failed: hisp_smc_ispnoc_r8_power_up.%d\n", __func__, ret);
		if (dev->use_smmuv3_flag)
#if defined(CONFIG_ARM_SMMU_V3) || defined(CONFIG_MM_SMMU_V3)
			(void)mm_smmu_poweroff(dev->device);
#endif
		(void)hisp_smc_media2_vcodec_power_down(cfg->isp_pci_inuse_flag, cfg->isp_pci_addr);
	}
#endif

	return ret;
}

static int hisp_pwr_subsys_common_dn_pcie(void)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	struct isp_pcie_cfg *cfg;
	int ret;

	cfg = hisp_get_pcie_cfg();
	if (cfg == NULL) {
		pr_err("Failed : isp pcie status abnormal\n");
		return -EINVAL;
	}

#ifndef CONFIG_HISP_FFA_SUPPORT
	pr_debug("[%s] ispnoc r8 start power down", __func__);
	ret = hisp_smc_ispnoc_r8_power_down(cfg->isp_pci_inuse_flag, cfg->isp_pci_addr);
	if (ret != 0) {
		pr_err("[%s] Failed: hisp_smc_ispnoc_r8_power_down.%d\n", __func__, ret);
		return ret;
	}
#endif

	pr_debug("[%s] smmuv3 start power down", __func__);
	if (dev->use_smmuv3_flag) {
#if defined(CONFIG_ARM_SMMU_V3) || defined(CONFIG_MM_SMMU_V3)
		ret = mm_smmu_poweroff(dev->device);
		if (ret != 0) {
			pr_err("[%s] Failed: isp tcu regulator_disable.%d\n",
					__func__, ret);
			return ret;
		}
#endif
	}

	pr_debug("[%s] media2 vcodec start power down", __func__);
#ifdef CONFIG_HISP_FFA_SUPPORT
	ret = hisp_ffa_media2_power_down();
#else
	ret = hisp_smc_media2_vcodec_power_down(cfg->isp_pci_inuse_flag, cfg->isp_pci_addr);
#endif
	if (ret != 0)
		pr_err("[%s] Failed: hisp_smc_media2_vcodec_power_down.%d\n", __func__, ret);

	return ret;
}
#endif

static int hisp_pwr_subsys_common_up(void)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int ret;

#ifdef CONFIG_PERI_DVFS
	if (dev->use_buck13_flag)
		peri_buck13_mem_volt_set(DVFS_ISP_CHANEL, DVFS_BUCK13_VOLT1);
#endif

	ret = regulator_enable(dev->clockdep_supply);
	if (ret != 0) {
		pr_err("[%s] Failed: clockdep enable.%d\n", __func__, ret);
		return ret;
	}

	if (dev->use_smmuv3_flag) {
		ret = regulator_enable(dev->isptcu_supply);
		if (ret != 0) {
			pr_err("[%s] Failed:isptcu enable.%d\n", __func__, ret);
			goto err_tcu_poweron;
		}
	}

	ret = hisp_clock_pwr_enable();
	if (ret < 0) {
		pr_err("[%s] Failed: hisp_clock_pwr_enable.%d\n",
				__func__, ret);
		goto err_ispclk;
	}

	ret = regulator_enable(dev->ispcore_supply);
	if (ret != 0) {
		pr_err("[%s] Failed: ispcore enable.%d\n", __func__, ret);
		goto err_ispclk;
	}

	if (dev->isp_ecc)
		hisp_ffa_isp_ecc();

	if (dev->ispcpu_supply_flag) {
		ret = regulator_enable(dev->ispcpu_supply);
		if (ret != 0) {
			pr_err("[%s] Failed:ispcpu enable.%d\n", __func__, ret);
			goto err_ispcpu_supply;
		}
	}

	if (dev->csi_supply_flag != 0) {
		ret = regulator_enable(dev->csi_supply);
		if (ret != 0) {
			pr_err("[%s] Failed:csi enable.%d\n", __func__, ret);
			goto err_csi_supply;
		}
	}

	return 0;

err_csi_supply:
	if (dev->ispcpu_supply_flag != 0)
		(void)regulator_disable(dev->ispcpu_supply);

err_ispcpu_supply:
	(void)regulator_disable(dev->ispcore_supply);

err_ispclk:
	if (dev->use_smmuv3_flag)
		(void)regulator_disable(dev->isptcu_supply);

err_tcu_poweron:
	(void)regulator_disable(dev->clockdep_supply);

	return ret;
}

static int hisp_pwr_subsys_common_dn(void)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int ret;

	if (dev->csi_supply_flag != 0) {
		ret = regulator_disable(dev->csi_supply);
		if (ret != 0)
			pr_err("[%s] Failed:csi disable.%d\n", __func__, ret);
	}

	if (dev->ispcpu_supply_flag) {
		ret = regulator_disable(dev->ispcpu_supply);
		if (ret != 0)
			pr_err("[%s] Failed: ispcpu regulator_disable.%d\n",
					__func__, ret);
	}

	ret = regulator_disable(dev->ispcore_supply);
	if (ret != 0)
		pr_err("[%s] Failed: ispcore regulator_disable.%d\n",
				__func__, ret);

	hisp_clock_pwr_disable();

	if (dev->use_smmuv3_flag) {
		ret = regulator_disable(dev->isptcu_supply);
		if (ret != 0)
			pr_err("[%s] Failed: isp tcu regulator_disable.%d\n",
					__func__, ret);
	}
	ret = regulator_disable(dev->clockdep_supply);
	if (ret != 0)
		pr_err("[%s] Failed: isp clockdep regulator_disable.%d\n",
				__func__, ret);

#ifdef CONFIG_PERI_DVFS
	if (dev->use_buck13_flag)
		peri_buck13_mem_volt_set(DVFS_ISP_CHANEL, DVFS_BUCK13_VOLT0);
#endif

	return 0;
}

unsigned int hisp_smmuv3_mode(void)
{
	struct hisp_pwr *dev = &isp_pwr_dev;

	return dev->use_smmuv3_flag;
}

int hisp_pwr_subsys_powerup(void)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int status = ISP_NORMAL_MODE;
	int ret = 0, err;

	mutex_lock(&dev->pwrlock);
	pr_info("[%s] + refs_isp_power.0x%x\n", __func__, dev->refs_isp_power);
	ret = hisp_pwr_need_powerup(dev->refs_isp_power);
	if (ret == 0) {
		dev->refs_isp_power++;
		pr_info("[%s]: refs_isp.0x%x\n", __func__, dev->refs_isp_power);
		mutex_unlock(&dev->pwrlock);
		return 0;
	}
#ifdef DEBUG_HISP
	status = hisp_check_pcie_stat();
#endif
	switch (status) {
	case ISP_NORMAL_MODE:
		ret = hisp_pwr_subsys_common_up();
		break;
#ifdef DEBUG_HISP
	case ISP_PCIE_MODE:
		ret = hisp_pwr_subsys_common_up_pcie();
		break;
#endif
	default:
		pr_err("unkown PLATFORM: 0x%x\n", status);
		mutex_unlock(&dev->pwrlock);
		return status;
	}
	if (ret < 0) {
		pr_err("[%s] Failed: hisp_pwr_subsys_common_up.%d\n",
			__func__, ret);
		goto err_common_powerup;
	}

	if (hisp_mntn_dumpregs() < 0)
		pr_err("Failed : get_ispcpu_cfg_info");

	if ((hisp_nsec_boot_mode() != 0) || (hisp_ca_boot_mode() == 0)) {
#ifdef CONFIG_HISP_FFA_SUPPORT
		ret = hisp_ffa_powerup_isptop();
#else
		ret = hisp_smc_isptop_power_up();
#endif
		if (ret != 0) {
			pr_err("[%s] Failed : hisp isptop power up.%d\n", __func__, ret);
			goto err_isptop;
		}
	}

	dev->refs_isp_power++;
	pr_info("[%s] - refs_isp_power.0x%x\n", __func__, dev->refs_isp_power);

#if defined(CONFIG_SOC_PG_INFO) && defined(CONFIG_HISP_FE_PG)
    ret = hisp_get_fe_pg();
	if (ret != 0) {
		pr_err("[%s] Failed : PG INFO Error\n", __func__);
		goto err_isptop;
	}
#endif

	mutex_unlock(&dev->pwrlock);

	return 0;

err_isptop:
#ifdef DEBUG_HISP
	if (status == ISP_PCIE_MODE)
		err = hisp_pwr_subsys_common_dn_pcie();
	else
#endif
	err = hisp_pwr_subsys_common_dn();
	if (err != 0)
		pr_err("[%s] Failed: hisp_pwr_subsys_common_dn.%d\n",
				__func__, err);

err_common_powerup:
	mutex_unlock(&dev->pwrlock);
	return ret;
}

int hisp_pwr_subsys_powerdn(void)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int status = ISP_NORMAL_MODE;
	int ret = 0;
	mutex_lock(&dev->pwrlock);
	pr_info("[%s] + refs_isp_power.0x%x\n", __func__, dev->refs_isp_power);
	ret = hisp_pwr_need_powerdn(dev->refs_isp_power);
	if (ret == 0) {
		if (dev->refs_isp_power > 0)
			dev->refs_isp_power--;
		pr_info("[%s] + refs_isp_power.0x%x\n",
			__func__, dev->refs_isp_power);
		mutex_unlock(&dev->pwrlock);
		return 0;
	}

	if ((hisp_nsec_boot_mode() != 0) || (hisp_ca_boot_mode() == 0)) {
#ifdef CONFIG_HISP_FFA_SUPPORT
		ret = hisp_ffa_powerdn_isptop();
#else
		ret = hisp_smc_isptop_power_down();
#endif
		if (ret != 0)
			pr_err("[%s] Failed : hisp isptop power down.%d\n", __func__, ret);
	}

#ifdef DEBUG_HISP
	status = hisp_check_pcie_stat();
#endif
	switch (status) {
	case ISP_NORMAL_MODE:
		ret = hisp_pwr_subsys_common_dn();
		break;
#ifdef DEBUG_HISP
	case ISP_PCIE_MODE:
		ret = hisp_pwr_subsys_common_dn_pcie();
		break;
#endif
	default:
		mutex_unlock(&dev->pwrlock);
		return status;
	}
	if (ret != 0)
		pr_err("[%s] Failed: hisp_pwr_subsys_common_dn.%d\n",
				__func__, ret);

	dev->refs_isp_power--;
	pr_info("[%s] + refs_isp_power.0x%x\n", __func__, dev->refs_isp_power);
	mutex_unlock(&dev->pwrlock);

	return 0;
}

#ifdef CONFIG_KERNEL_CAMERA_USE_HISP120
static int hisp_cvdr_init(void)
{
	void __iomem *isp_regs_base;
	void __iomem *isprt_base;
	void __iomem *ispsrt_base;
	void __iomem *ispsctrl_base;
	unsigned int value;

	pr_info("[%s] +\n", __func__);

	isp_regs_base = hisp_dev_get_regaddr(ISP_ISPCORE);
	if (unlikely(!isp_regs_base)) {
		pr_err("[%s] isp_regs_base failed!\n", __func__);
		return -ENOMEM;
	}

	isprt_base = isp_regs_base + ISP_BASE_ADDR_CVDR_RT;
	ispsrt_base = isp_regs_base + ISP_BASE_ADDR_CVDR_SRT;
	ispsctrl_base = isp_regs_base + ISP_SUB_CTRL_BASE_ADDR;

	value = readl(ISP_020010_MODULE_CGR_TOP + isp_regs_base);
	value |= CVDR_CLK_ENABLE;
	writel(value, ISP_020010_MODULE_CGR_TOP + isp_regs_base);

	/* CVDR RT */
	writel(0x0B0B4001, isprt_base + CVDR_RT_CVDR_CFG_REG);
	/* CVDR SRT */
	writel(0x0B132201, ispsrt_base + CVDR_SRT_CVDR_CFG_REG);
	// CVDR_RT QOS
	writel(0xF8765432, isprt_base + CVDR_RT_CVDR_WR_QOS_CFG_REG);
	writel(0xF8122334, isprt_base + CVDR_RT_CVDR_RD_QOS_CFG_REG);

	// CVDR_SRT QOS
	writel(0xD0765432, ispsrt_base + CVDR_SRT_CVDR_WR_QOS_CFG_REG);
	writel(0xD0122334, ispsrt_base + CVDR_SRT_CVDR_RD_QOS_CFG_REG);

	// CVDR SRT PORT STOP
	writel(0x00020000, ispsrt_base + CVDR_SRT_NR_RD_CFG_3_REG);
	writel(0x00020000, ispsrt_base + CVDR_SRT_VP_WR_IF_CFG_10_REG);
	writel(0x00020000, ispsrt_base + CVDR_SRT_VP_WR_IF_CFG_11_REG);

	// JPGENC limiter DU=8
	writel(0x00000000, ispsrt_base + CVDR_SRT_VP_WR_IF_CFG_25_REG);
	writel(0x80060100, ispsrt_base + CVDR_SRT_NR_RD_CFG_1_REG);
	writel(0x0F001111, ispsrt_base + CVDR_SRT_LIMITER_NR_RD_1_REG);

	// SRT READ
	writel(0x00026E10, ispsctrl_base + SUB_CTRL_ISP_FLUX_CTRL2_0_REG);
	writel(0x0000021F, ispsctrl_base + SUB_CTRL_ISP_FLUX_CTRL2_1_REG);
	// SRT WRITE
	writel(0x00027210, ispsctrl_base + SUB_CTRL_ISP_FLUX_CTRL3_0_REG);
	writel(0x0000024E, ispsctrl_base + SUB_CTRL_ISP_FLUX_CTRL3_1_REG);

	pr_info("[%s] -\n", __func__);

	return 0;
}
#endif

int hisp_pwr_core_nsec_init(u64 pgd_base)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int result;
#ifndef ISP_LINX_CPU_SUPPORT
	(void)pgd_base;
#endif
#ifdef CONFIG_KERNEL_CAMERA_USE_HISP120
		int ret;
		void __iomem *isp_regs_base = NULL;
#endif
	mutex_lock(&dev->pwrlock);
	pr_info("[%s] + refs_isp_nsec_init.0x%x\n",
		__func__, dev->refs_isp_nsec_init);
	result = hisp_pwr_need_powerup(dev->refs_isp_nsec_init);
	if (result == 0) {
		dev->refs_isp_nsec_init++;
		pr_info("[%s] + refs_isp_nsec_init.0x%x\n",
				__func__, dev->refs_isp_nsec_init);
		mutex_unlock(&dev->pwrlock);
		return 0;
	}
#ifdef ISP_LINX_CPU_SUPPORT
#ifdef CONFIG_HISP_FFA_SUPPORT
	u64 early_pa;
	early_pa = hisp_nsec_get_remap_pa();
	if (early_pa == 0ULL) {
		pr_err("%s: get early boot mem pa fail\n", __func__);
		mutex_unlock(&dev->pwrlock);
		return -EINVAL;
	}
	hisp_ffa_ispmmu_init(pgd_base, early_pa);
#else
	hisp_smc_ispsmmu_ns_init(pgd_base);
#endif
#endif

#ifdef CONFIG_KERNEL_CAMERA_USE_HISP120
	isp_regs_base = hisp_dev_get_regaddr(ISP_ISPCORE);
	writel(((unsigned int)readl(ISP_020010_MODULE_CGR_TOP +
		 isp_regs_base) | SMMU_CLK_ENABLE),
		 ISP_020010_MODULE_CGR_TOP + isp_regs_base);
	if (dev->ispsmmu_init_byap)
		hisp_smc_ispsmmu_ns_init(pgd_base);

	ret = hisp_cvdr_init();
	if (ret < 0) {
		pr_err("[%s] Failed: hisp_cvdr_init.%d\n", __func__, ret);
		mutex_unlock(&dev->pwrlock);
		return ret;
	}
#endif
	dev->refs_isp_nsec_init++;
	pr_info("[%s] - refs_isp_nsec_init.0x%x\n",
		__func__, dev->refs_isp_nsec_init);
	mutex_unlock(&dev->pwrlock);

	return 0;
}

int hisp_pwr_core_nsec_exit(void)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int ret;

	mutex_lock(&dev->pwrlock);
	pr_info("[%s] + refs_isp_nsec_init.0x%x\n",
		__func__, dev->refs_isp_nsec_init);
	ret = hisp_pwr_need_powerdn(dev->refs_isp_nsec_init);
	if (ret == 0) {
		if (dev->refs_isp_nsec_init > 0)
			dev->refs_isp_nsec_init--;
		pr_info("[%s] + refs_isp_nsec_init.0x%x\n",
			__func__, dev->refs_isp_nsec_init);
		mutex_unlock(&dev->pwrlock);
		return 0;
	}

	dev->refs_isp_nsec_init--;
	pr_info("[%s] - refs_isp_nsec_init.0x%x\n",
		__func__, dev->refs_isp_nsec_init);
	mutex_unlock(&dev->pwrlock);

	return 0;
}

int hisp_pwr_core_sec_init(u64 phy_pgd_base)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int ret;

	mutex_lock(&dev->pwrlock);
	pr_info("[%s] + refs_isp_sec_init.0x%x\n",
		__func__, dev->refs_isp_sec_init);
	ret = hisp_pwr_need_powerup(dev->refs_isp_sec_init);
	if (ret == 0) {
		dev->refs_isp_sec_init++;
		pr_info("[%s] + refs_isp_sec_init.0x%x\n",
				__func__, dev->refs_isp_sec_init);
		mutex_unlock(&dev->pwrlock);
		return 0;
	}

	hisp_smc_isp_init(phy_pgd_base);
	dev->refs_isp_sec_init++;
	pr_info("[%s] + refs_isp_sec_init.0x%x\n",
		__func__, dev->refs_isp_sec_init);
	mutex_unlock(&dev->pwrlock);

	return 0;
}

int hisp_pwr_core_sec_exit(void)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int ret;

	mutex_lock(&dev->pwrlock);
	pr_info("[%s] + refs_isp_sec_init.0x%x\n",
		__func__, dev->refs_isp_sec_init);
	ret = hisp_pwr_need_powerdn(dev->refs_isp_sec_init);
	if (ret == 0) {
		if (dev->refs_isp_sec_init > 0)
			dev->refs_isp_sec_init--;
		pr_info("[%s] + refs_isp_sec_init.0x%x\n",
			__func__, dev->refs_isp_sec_init);
		mutex_unlock(&dev->pwrlock);
		return 0;
	}

	hisp_smc_isp_exit();
	dev->refs_isp_sec_init--;
	pr_info("[%s] + refs_isp_sec_init.0x%x\n",
		__func__, dev->refs_isp_sec_init);
	mutex_unlock(&dev->pwrlock);

	return 0;
}

int hisp_pwr_cpu_sec_init(void)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int ret;

	mutex_lock(&dev->pwrlock);
	pr_info("[%s] + refs_ispcpu_init.0x%x\n",
		__func__, dev->refs_ispcpu_init);
	ret = hisp_pwr_need_powerup(dev->refs_ispcpu_init);
	if (ret == 0) {
		dev->refs_ispcpu_init++;
		pr_info("[%s] + refs_ispcpu_init.0x%x\n",
				__func__, dev->refs_ispcpu_init);
		mutex_unlock(&dev->pwrlock);
		return 0;
	}

	ret = hisp_smc_ispcpu_init();
	if (ret < 0) {
		pr_info("[%s] hisp_smc_ispcpu_init fail.%d\n", __func__, ret);
		mutex_unlock(&dev->pwrlock);
		return ret;
	}

	dev->refs_ispcpu_init++;
	pr_info("[%s] + refs_ispcpu_init.0x%x\n",
		__func__, dev->refs_ispcpu_init);
	mutex_unlock(&dev->pwrlock);

	return 0;
}

int hisp_pwr_cpu_sec_exit(void)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int ret;

	mutex_lock(&dev->pwrlock);
	pr_info("[%s] + refs_ispcpu_init.0x%x\n",
		__func__, dev->refs_ispcpu_init);
	ret = hisp_pwr_need_powerdn(dev->refs_ispcpu_init);
	if (ret == 0) {
		if (dev->refs_ispcpu_init > 0)
			dev->refs_ispcpu_init--;
		pr_info("[%s] + refs_ispcpu_init.0x%x\n",
				__func__, dev->refs_ispcpu_init);
		mutex_unlock(&dev->pwrlock);
		return 0;
	}

	hisp_smc_ispcpu_exit();
	dev->refs_ispcpu_init--;
	pr_info("[%s] + refs_ispcpu_init.0x%x\n",
		__func__, dev->refs_ispcpu_init);
	mutex_unlock(&dev->pwrlock);

	return 0;
}

static inline bool in_range(uintptr_t addr, uintptr_t start, uintptr_t size)
{
    return (addr >= start) && (addr < (start + size));
}

uintptr_t OsAslrMemMap(uintptr_t addr)
{
	hisp_prog_info_t *pcb = hisp_prog_info_get();
    if (in_range(addr, (uintptr_t)pcb->text.iova, pcb->text.size)) {
        return (addr - (uintptr_t)pcb->text.iova) + (uintptr_t)pcb->text.mem;
    } else if (in_range(addr, (uintptr_t)pcb->data.iova, pcb->data.size)) {
        return (addr - (uintptr_t)pcb->data.iova) + (uintptr_t)pcb->data.mem;
    } else {
		return 0;
	}
}

static inline void hisp_flush_image_va(void)
{
	hisp_prog_info_t *pcb = hisp_prog_info_get();
	__flush_dcache_area(pcb->text.mem, pcb->text.size);
	__flush_dcache_area(pcb->data.mem, pcb->data.size);
}

#define HISP_FW_NAME_MAX_LEN 			31
#define HISP_FW_PATH_MAX_LEN			(HISP_FW_NAME_MAX_LEN + 32 + 1)
#define HISP_FW_ROOT_DIR_OHOS			"/chip_prod/etc/firmware"
#define HISP_FW_ROOT_DIR				"/odm/etc/firmware"

static bool hisp_firmware_name_ok(const char *firmware)
{
	if (strstr(firmware, "..")) {
		return false;
	}
	if ((strlen(firmware) == 0) || (strlen(firmware) > HISP_FW_NAME_MAX_LEN)) {
		return false;
	}
	return true;
}

static int hisp_get_firmware_fullpath(const char *firmware, char *buf, size_t max_len)
{
	size_t idx;
	int ret;
	struct file *filp = NULL;

	const char *dirs[] = {
		HISP_FW_ROOT_DIR,
		HISP_FW_ROOT_DIR_OHOS,
	};

	for (idx = 0; idx < ARRAY_SIZE(dirs); idx++) {
		ret = snprintf_s(buf, max_len, HISP_FW_PATH_MAX_LEN - 1, "%s/%s", dirs[idx], firmware);
		if (ret <= 0) {
			return ret;
		}
		filp = filp_open(buf, O_RDONLY, 0400);
		if (!IS_ERR_OR_NULL(filp)) {
			filp_close(filp, NULL);
			return 0;
		}
	}
	return -ENOENT;
}

static int hisp_nsec_image_aslr(void)
{
	int ret;
	uint32_t random;
	ElfFile *elf = NULL;
	void *aslr = NULL;
	const char *firmware = NULL;
	char fw_fullpath[HISP_FW_PATH_MAX_LEN];

	if (!hisp_ltar_enabled()) {
		return 0;
	}

	firmware = hisp_get_firmware();
	if (firmware == NULL || !hisp_firmware_name_ok(firmware)) {
		pr_info("[%s] get firmware failed\n", __func__);
		return -1;
	}

	ret = hisp_get_firmware_fullpath(firmware, fw_fullpath, sizeof(fw_fullpath));
	if (ret != 0) {
		pr_info("[%s] get firmware fullpath failed\n", __func__);
		return -1;
	}
	elf = elf_load(fw_fullpath);
	if (elf == NULL) {
		pr_info("[%s] elf_load failed\n", __func__);
		return -1;
	}

	aslr = aslr_cb_create(elf);
	if (aslr == NULL) {
		pr_info("[%s] aslr_cb_create failed\n", __func__);
		goto FREE_ELF;
	}

	random = hisp_get_dyn_bootaddr();

	ret = do_aslr_reloc(aslr, random);
	if (ret != 0) {
		pr_info("[%s] do_aslr_reloc failed\n", __func__);
		goto FREE_ASLR_CB;
	}

	/* do_aslr_reloc changed the content of loaded isp image, 
	 * make sure everything changed flush to memory */
	hisp_flush_image_va();

	aslr_cb_destroy(aslr);
	elf_destroy(elf);

	return 0;

FREE_ASLR_CB:
	aslr_cb_destroy(aslr);
FREE_ELF:
	elf_destroy(elf);
	return -1;
}

int hisp_pwr_cpu_nsec_dst(u64 remap_addr, unsigned int canary)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int ret;

	mutex_lock(&dev->pwrlock);
	pr_info("[%s] + refs_isp_nsec_dst.0x%x\n",
		__func__, dev->refs_isp_nsec_dst);
	ret = hisp_pwr_need_powerup(dev->refs_isp_nsec_dst);
	if (ret == 0) {
		dev->refs_isp_nsec_dst++;
		pr_info("[%s] + refs_isp_nsec_dst.0x%x\n",
		__func__, dev->refs_isp_nsec_dst);
		mutex_unlock(&dev->pwrlock);
		return 0;
	}

	ret = hisp_nsec_image_aslr();
	if (ret < 0) {
		pr_err("[%s] Failed : hisp_nsec_image_aslr.%d\n", __func__, ret);
		mutex_unlock(&dev->pwrlock);
		return ret;
	}

	/* need config by secure core */
	ret = hisp_pwr_dst_ispcpu(remap_addr, canary);
	if (ret < 0) {
		pr_err("[%s] Failed : disreset_ispcpu.%d\n", __func__, ret);
		mutex_unlock(&dev->pwrlock);
		return ret;
	}
	dev->refs_isp_nsec_dst++;
	pr_info("[%s] + refs_isp_nsec_dst.0x%x\n",
		__func__, dev->refs_isp_nsec_dst);
	mutex_unlock(&dev->pwrlock);

	return 0;
}

int hisp_pwr_cpu_nsec_rst(void)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int ret;

	mutex_lock(&dev->pwrlock);
	pr_info("[%s] + refs_isp_nsec_dst.0x%x\n",
		__func__, dev->refs_isp_nsec_dst);
	ret = hisp_pwr_need_powerdn(dev->refs_isp_nsec_dst);
	if (ret == 0) {
		if (dev->refs_isp_nsec_dst > 0)
			dev->refs_isp_nsec_dst--;
		pr_info("[%s] + refs_isp_nsec_dst.0x%x\n",
			__func__, dev->refs_isp_nsec_dst);
		mutex_unlock(&dev->pwrlock);
		return 0;
	}

	if ((hisp_nsec_boot_mode() != 0) || (hisp_ca_boot_mode() == 0)) {
#ifdef CONFIG_HISP_FFA_SUPPORT
		ret = hisp_ffa_reset_ispcpu();
		if (ret != 0)
			pr_err("[%s] Failed : hisp ispcpu power down.%d\n", __func__, ret);
#endif
	}

	dev->refs_isp_nsec_dst--;
	pr_info("[%s] + refs_isp_nsec_dst.0x%x\n",
		__func__, dev->refs_isp_nsec_dst);
	mutex_unlock(&dev->pwrlock);

	return 0;
}

int hisp_pwr_cpu_sec_dst(int ispmem_reserved, unsigned long image_addr)
{
#ifdef CONFIG_LOAD_IMAGE
	struct hisp_pwr *dev = &isp_pwr_dev;
	struct load_image_info loadinfo;
	int ret;

	loadinfo.ecoretype      = ISP;
	loadinfo.image_addr     = image_addr;
	loadinfo.image_size     = MEM_ISPFW_SIZE;
	loadinfo.partion_name   = ISP_LOAD_PARTITION;

	mutex_lock(&dev->pwrlock);
	pr_info("[%s] + %s.(0x%x), init.%x, ispmem_reserved.%x\n",
		__func__, loadinfo.partion_name, loadinfo.image_size,
		dev->refs_isp_sec_dst, ispmem_reserved);

	if (!hisp_pwr_need_powerup(dev->refs_isp_sec_dst)) {
		dev->refs_isp_sec_dst++;
		pr_info("[%s] + refs_isp_sec_dst.0x%x\n",
		__func__, dev->refs_isp_sec_dst);
		mutex_unlock(&dev->pwrlock);
		return 0;
	}

	if (!ispmem_reserved) {
		ret = bsp_load_and_verify_image(&loadinfo);
		if (ret < 0) {
			pr_err("[%s]Failed : bsp_load_and_verify.%d, %s.0x%x\n",
				__func__, ret, loadinfo.partion_name,
				loadinfo.image_size);
			mutex_unlock(&dev->pwrlock);
			return ret;
		}
	} else {
		ret = bsp_load_sec_img(&loadinfo);
		if (ret < 0) {
			pr_err("[%s] Failed : bsp_load_sec_image.%d, %s.0x%x\n",
				__func__, ret, loadinfo.partion_name,
				loadinfo.image_size);
			mutex_unlock(&dev->pwrlock);
			return ret;
		}
	}

	dev->refs_isp_sec_dst++;
	pr_info("[%s]: bsp_load_image.%d, %s.0x%x, init.%x, ispmem_resved.%x\n",
		__func__, ret, loadinfo.partion_name, loadinfo.image_size,
		dev->refs_isp_sec_dst, ispmem_reserved);
	mutex_unlock(&dev->pwrlock);
#else
	(void)ispmem_reserved;
	(void)image_addr;
#endif
	return 0;
}

int hisp_pwr_cpu_sec_rst(void)
{
#ifdef CONFIG_LOAD_IMAGE
	struct hisp_pwr *dev = &isp_pwr_dev;

	mutex_lock(&dev->pwrlock);
	pr_info("[%s] + refs_isp_sec_dst.0x%x\n",
		__func__, dev->refs_isp_sec_dst);
	if (!hisp_pwr_need_powerdn(dev->refs_isp_sec_dst)) {
		if (dev->refs_isp_sec_dst > 0)
			dev->refs_isp_sec_dst--;
		pr_info("[%s] + refs_isp_sec_dst.0x%x\n",
			__func__, dev->refs_isp_sec_dst);
		mutex_unlock(&dev->pwrlock);
		return 0;
	}

	dev->refs_isp_sec_dst--;
	pr_info("[%s] + refs_isp_sec_dst.0x%x\n",
		__func__, dev->refs_isp_sec_dst);
	mutex_unlock(&dev->pwrlock);
#endif
	return 0;
}

int hisp_pwr_cpu_ca_dst(void)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int ret;

	mutex_lock(&dev->pwrlock);
	ret = hisp_pwr_need_powerup(dev->refs_isp_sec_dst);
	if (ret == 0) {
		dev->refs_isp_sec_dst++;
		pr_info("[%s] + refs_isp_sec_dst.0x%x\n",
		__func__, dev->refs_isp_sec_dst);
		mutex_unlock(&dev->pwrlock);
		return 0;
	}

	ret = hisp_ca_ispcpu_disreset();
	if (ret < 0) {
		pr_err("[%s] Failed : hisp_ca_ispcpu_disreset.%d.\n",
			__func__, ret);
		mutex_unlock(&dev->pwrlock);
		return ret;
	}

	dev->refs_isp_sec_dst++;
	mutex_unlock(&dev->pwrlock);

	return 0;
}

int hisp_pwr_cpu_ca_rst(void)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int ret;

	mutex_lock(&dev->pwrlock);
	ret = hisp_pwr_need_powerdn(dev->refs_isp_sec_dst);
	if (ret == 0) {
		if (dev->refs_isp_sec_dst > 0)
			dev->refs_isp_sec_dst--;
		pr_info("[%s] + refs_isp_sec_dst.0x%x\n",
			__func__, dev->refs_isp_sec_dst);
		mutex_unlock(&dev->pwrlock);
		return 0;
	}

	ret = hisp_ca_ispcpu_reset();
	if (ret < 0)
		pr_err("[%s] Failed : hisp_ca_ispcpu_reset.%d.\n",
			__func__, ret);

	dev->refs_isp_sec_dst--;
	mutex_unlock(&dev->pwrlock);

	return ret;
}

static int hisp_qos_cfg_ap(void)
{
#ifndef ISP_LINX_CPU_SUPPORT
	struct hisp_pwr *dev = &isp_pwr_dev;
	void __iomem *vivobus_va;
	unsigned int i = 0;
#endif

#ifdef DEBUG_HISP
	int ret;
#endif

	pr_info("[%s] +\n", __func__);
#ifdef DEBUG_HISP
	ret = hisp_check_pcie_stat();
	if (ret != ISP_NORMAL_MODE)
		return 0;
#endif

#ifndef ISP_LINX_CPU_SUPPORT
	vivobus_va = hisp_dev_get_regaddr(ISP_VIVOBUS);
	if (vivobus_va == NULL) {
		pr_err("[%s] vivobus_base remap fail\n", __func__);
		return -ENOMEM;
	}
	pr_info("[%s] vivobus_base.%pK, qos_num.%d",
			__func__, vivobus_va, dev->qos.num);

	if ((dev->qos.num == 0) || (dev->qos.num > QOS_MAX_NUM) ||
		(dev->qos.offset == NULL) || (dev->qos.value == NULL)) {
		pr_err("[%s] Failed: QOS_MAX_NUM.%d, offset.%pK, value.%pK\n",
			__func__, QOS_MAX_NUM, dev->qos.offset, dev->qos.value);
		return -ENODEV;
	}

	for (i = 0; i < dev->qos.num; i++) {
		__raw_writel(dev->qos.value[i], vivobus_va + dev->qos.offset[i]);
#ifdef DEBUG_HISP
		pr_info("QOS : value.0x%x, offset.0x%x, actual.0x%x\n",
			dev->qos.value[i], dev->qos.offset[i],
			__raw_readl(vivobus_va + dev->qos.offset[i]));
#endif
	}
#endif

	return 0;
}

int hisp_ispcpu_qos_cfg(void)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int ret = 0;

#ifdef DEBUG_HISP
	ret = hisp_check_pcie_stat();
	if (ret != ISP_NORMAL_MODE)
		return 0;
#endif

	if (dev->qos.secreg == QOS_SECREG) {
#ifdef CONFIG_HISP_FFA_SUPPORT
		ret = hisp_ffa_cfg_qos();
#else
		ret = hisp_smc_qos_cfg();
#endif
	}
	else if (dev->qos.secreg == QOS_NSECREG) {
		ret = hisp_qos_cfg_ap();
	}
	else {
		pr_info("[%s] : isp qos no need\n", __func__);
	}

	return ret;
}

static int hisp_pwr_regulator_getdts(struct device *device,
			struct hisp_pwr *dev)
{
	struct device_node *np = device->of_node;
	int ret;

	dev->clockdep_supply = devm_regulator_get(device, "isp-clockdep");
	if (IS_ERR(dev->clockdep_supply)) {
		pr_err("[%s] Failed : isp-clockdep devm_regulator_get.%pK\n",
				__func__, dev->clockdep_supply);
		return -EINVAL;
	}

	dev->ispcore_supply = devm_regulator_get(device, "isp-core");
	if (IS_ERR(dev->ispcore_supply)) {
		pr_err("[%s] Failed : isp-core devm_regulator_get.%pK\n",
				__func__, dev->ispcore_supply);
		return -EINVAL;
	}

	ret = of_property_read_u32(np, "ispcpu-supply-flag",
			(unsigned int *)(&dev->ispcpu_supply_flag));
	if (ret < 0) {
		dev->ispcpu_supply_flag = 0;
		pr_err("[%s] Failed: ispcpu-supply-flag get from dtsi.%d\n",
			__func__, ret);
	}

	ret = of_property_read_u32(np, "qice-isp-ecc", (unsigned int *)(&dev->isp_ecc));
	if (ret < 0) {
		dev->isp_ecc = 0;
		pr_err("[%s]: qice-isp-ecc not support.%d\n", __func__, ret);
	}

	if (dev->ispcpu_supply_flag) {
		dev->ispcpu_supply = devm_regulator_get(device, "isp-cpu");
		if (IS_ERR(dev->ispcpu_supply))
			pr_err("[%s] Failed : isp-cpu devm_regulator_get.%pK\n",
				__func__, dev->ispcpu_supply);
	}

	ret = of_property_read_u32(np, "use-buck13-flag",
			(unsigned int *)(&dev->use_buck13_flag));
	if (ret < 0) {
		dev->use_buck13_flag = 0;
		pr_err("[%s]: use-buck13-flag no need.%d\n", __func__, ret);
	}

	ret = of_property_read_u32(np, "use-smmuv3-flag",
				(unsigned int *)(&dev->use_smmuv3_flag));
	if (ret < 0) {
		pr_err("[%s] Failed: use_smmuv3_flag get from dtsi.%d\n",
				__func__, ret);
		return -EINVAL;
	}
	pr_info("[%s] use_smmuv3_flag.0x%x\n", __func__, dev->use_smmuv3_flag);

	if (dev->use_smmuv3_flag) {
		dev->isptcu_supply = devm_regulator_get(device, "isp-smmu-tcu");
		if (IS_ERR(dev->isptcu_supply)) {
			pr_err("[%s] Failed : isp-tcu devm_regulator_get.%pK\n",
					__func__, dev->isptcu_supply);
			return -EINVAL;
		}
	}

	ret = of_property_read_u32(np, "csi-supply-flag", (unsigned int *)(&dev->csi_supply_flag));
	if (ret < 0) {
		dev->csi_supply_flag = 0;
		pr_err("[%s] : csi_supply_flag not support.%d\n", __func__, ret);
	}

	if (dev->csi_supply_flag != 0) {
		dev->csi_supply = devm_regulator_get(device, "isp-csi");
		if (IS_ERR(dev->csi_supply)) {
			pr_err("[%s] Failed : csi_supply\n", __func__);
			return -EINVAL;
		}
	}

	return 0;
}

static int hisp_pwstat_getdts(struct device_node *np, struct hisp_pwr *dev)
{
	int ret;
	unsigned int pwsta_num = 0;
	unsigned int i;

	ret = of_property_read_u32(np, "pwstat-num",
				(unsigned int *)(&dev->pwstat_num));
	if (ret < 0) {
		pr_err("[%s] Failed: pwstat-num get from dtsi.%d\n",
				__func__, ret);
		return -EINVAL;
	}

	pwsta_num = dev->pwstat_num > PWSTAT_MAX ? PWSTAT_MAX : dev->pwstat_num;
	pr_info("[%s] pwstat_num.0x%x\n", __func__,
			dev->pwstat_num);

	ret = of_property_read_u32_array(np, "pwstat-type",
				dev->pwstat_type, pwsta_num);
	if (ret < 0) {
		pr_err("[%s] Failed: pwstat-type get from dtsi.%d\n",
				__func__, ret);
		return -EINVAL;
	}

	ret = of_property_read_u32_array(np, "pwstat-offset",
				dev->pwstat_offset, pwsta_num);
	if (ret < 0) {
		pr_err("[%s] Failed: pwstat-offset get from dtsi.%d\n",
				__func__, ret);
		return -EINVAL;
	}

	ret = of_property_read_u32_array(np, "pwstat-bit",
				dev->pwstat_bit, pwsta_num);
	if (ret < 0) {
		pr_err("[%s] Failed: pwstat-bit get from dtsi.%d\n",
				__func__, ret);
		return -EINVAL;
	}

	ret = of_property_read_u32_array(np, "pwstat-wanted",
				dev->pwstat_wanted, pwsta_num);
	if (ret < 0) {
		pr_err("[%s] Failed: pwstat-wanted get from dtsi.%d\n",
				__func__, ret);
		return -EINVAL;
	}
	for (i = 0; i < pwsta_num; i++)
		pr_info("[%s] : type.%d, offset.0x%x, bit.%d, wanted[%d]\n",
			__func__, dev->pwstat_type[i], dev->pwstat_offset[i],
			dev->pwstat_bit[i], dev->pwstat_wanted[i]);

	return 0;
}

static void hisp_qos_init(struct hisp_pwr *dev, unsigned int secreg,
	unsigned int num, unsigned int *offset, unsigned int *value)
{
	dev->qos.secreg = secreg;
	dev->qos.num = num;
	dev->qos.offset = offset;
	dev->qos.value = value;
}

static int hisp_qos_getdts(struct device_node *np, struct hisp_pwr *dev)
{
	int ret;
	unsigned int secreg = 0;

	pr_info("[%s] +\n", __func__);

	ret = of_property_read_u32(np, "qos-sec-flag", &secreg);
	if (ret < 0)
		pr_info("[%s] : get qos-sec-flag.%u, ret.%d\n",
			__func__, secreg, ret);

	if (secreg != QOS_NSECREG) {
		hisp_qos_init(dev, secreg, 0, NULL, NULL);
		return 0;
	}

	ret = of_property_read_u32(np, "qos-num", &dev->qos.num);
	if (ret < 0) {
		pr_err("[%s] Failed: qos-num.0x%x get from dtsi.%d\n",
				__func__, dev->qos.num, ret);
		return -ENODEV;
	}
	pr_info("[%s] qos-num.%d\n", __func__, dev->qos.num);

	if ((dev->qos.num == 0) || (dev->qos.num > QOS_MAX_NUM)) {
		pr_err("[%s] Failed: QOS_MAX_NUM.%d\n", __func__, QOS_MAX_NUM);
		return -ENODEV;
	}

	dev->qos.offset = kmalloc_array(dev->qos.num,
			sizeof(unsigned int), GFP_KERNEL);
	if (dev->qos.offset == NULL)
		return -ENOMEM;

	dev->qos.value = kmalloc_array(dev->qos.num,
			sizeof(unsigned int), GFP_KERNEL);
	if (dev->qos.value == NULL)
		goto free_qos;

	ret = of_property_read_u32_array(np, "qos-offset",
			dev->qos.offset, dev->qos.num);
	if (ret < 0) {
		pr_err("[%s] Failed: qos-offset get from dtsi.%d\n",
				__func__, ret);
		goto free_qos;
	}

	ret = of_property_read_u32_array(np, "qos-value",
			dev->qos.value, dev->qos.num);
	if (ret < 0) {
		pr_err("[%s] Failed: qos-value get from dtsi.%d\n",
				__func__, ret);
		goto free_qos;
	}

	hisp_qos_init(dev, QOS_NSECREG, dev->qos.num,
		dev->qos.offset, dev->qos.value);

	return 0;

free_qos:
	if (dev->qos.offset != NULL)
		kfree(dev->qos.offset);
	if (dev->qos.value != NULL)
		kfree(dev->qos.value);
	return -ENOMEM;
}

static void hisp_qos_free(struct hisp_pwr *dev)
{
	if (dev->qos.offset != NULL) {
		kfree(dev->qos.offset);
		dev->qos.offset = NULL;
	}
	if (dev->qos.value != NULL) {
		kfree(dev->qos.value);
		dev->qos.value = NULL;
	}
	dev->qos.num = 0;
	dev->qos.secreg = QOS_NSECREG;
}

static int hisp_smmu_getdts(struct device_node *np, struct hisp_pwr *dev)
{
	int ret;
	ret = of_property_read_u32(np, "ispsmmu-init-byap",
			&dev->ispsmmu_init_byap);
	if (ret < 0) {
		pr_err("[%s] Failed: ispsmmu-init-byap of_property_read_u32.%d\n",
				__func__, ret);
		return -EINVAL;
	}
	pr_info("[%s] isp-smmu-flag.0x%x\n", __func__, dev->ispsmmu_init_byap);
	return 0;
}

static int hisp_pwr_getdts(struct platform_device *pdev,
		struct hisp_pwr *dev)
{
	struct device *device = &pdev->dev;
	struct device_node *np = device->of_node;
	int ret;

	if (np == NULL) {
		pr_err("[%s] Failed : np.%pK\n", __func__, np);
		return -ENODEV;
	}

	pr_info("[%s] +\n", __func__);
	ret = hisp_pwr_regulator_getdts(device, dev);
	if (ret < 0) {
		pr_err("[%s] Failed: regulator_getdts.%d\n", __func__, ret);
		return ret;
	}

	ret = hisp_pwstat_getdts(np, dev);
	if (ret != 0) {
		pr_err("[%s] Failed : hisp_pwstat_getdts.%d.\n", __func__, ret);
		return ret;
	}

	ret = hisp_qos_getdts(np, dev);
	if (ret != 0) {
		pr_err("[%s] Failed : hisp_qos_getdts.%d.\n", __func__, ret);
		return ret;
	}

	ret = hisp_smmu_getdts(np, dev);
	if (ret != 0) {
		pr_err("[%s] Failed : hisp_smmu_getdts.%d.\n", __func__, ret);
		return ret;
	}

	pr_info("[%s] -\n", __func__);

	return 0;
}

int hisp_pwr_probe(struct platform_device *pdev)
{
	struct hisp_pwr *dev = &isp_pwr_dev;
	int ret = 0;

	pr_alert("[%s] +\n", __func__);
	dev->device = &pdev->dev;
	dev->ispcpu_supply_flag = 0;
	dev->refs_isp_power = 0;
	dev->refs_isp_nsec_init = 0;
	dev->refs_isp_sec_init = 0;
	dev->refs_ispcpu_init = 0;
	dev->refs_isp_nsec_dst = 0;
	dev->refs_isp_sec_dst = 0;
	dev->isp_ecc = 0;

	ret = hisp_pwr_getdts(pdev, dev);
	if (ret != 0) {
		pr_err("[%s] Failed : hisp_nsec_getdts.%d.\n",
				__func__, ret);
		return ret;
	}

	mutex_init(&dev->pwrlock);

	pr_alert("[%s] -\n", __func__);

	return 0;
}

int hisp_pwr_remove(struct platform_device *pdev)
{
	struct hisp_pwr *dev = &isp_pwr_dev;

	(void)pdev;

	hisp_qos_free(dev);

	mutex_destroy(&dev->pwrlock);
	return 0;
}

