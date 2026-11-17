/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: provide aae init function interfaces.
 */
#include <aae/soc_aae_interface.h>
#include <aae/soc_aae_define.h>
#include <soc_smmuv3_tbu_interface.h>
#include "akmd_log.h"
#include "aae_smmu.h"
#include "aae_manager.h"
#include "dacc_aae.h"
#include "aae_dacc_ctrl.h"
#include "aae_cmdlist.h"
#include "aae_ffts_ctrl.h"
#include "ukmd_utils.h"
#include "aae_init.h"

#define TBU_SWID_M_NUM 1

static int32_t aae_glb_reg_init(char __iomem *aae_base)
{
    size_t i = 0;
    aae_pr_debug("+");
    set_reg(AAE_GLB_PART0_AAE_PM_CTRL_ADDR(aae_base + AAE_GLB0_OFFSET), 0x0401A00F, 32, 0);
    set_reg(SOC_SMMUv3_TBU_SMMU_TBU_CR_ADDR(aae_base + AAE_SMMU_OFFSET), 0x10100F03, 32, 0);

    for (i = 0; i < TBU_SWID_M_NUM; ++i) {
        set_reg(SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_ADDR(aae_base + AAE_SMMU_OFFSET, i), 0x1, 1, 31);
        set_reg(SOC_SMMUv3_TBU_SMMU_TBU_SWID_CFG_ADDR(aae_base + AAE_SMMU_OFFSET, i), 0x3, 2, 28);
    }
    set_reg(AAE_DBCU_SMARTDMA_2_AXI_SEL_ADDR(aae_base + AAE_DBCU_OFFSET), 0x1, 1, 0); // SmartDMA_2_AXI_SEL
    set_reg(AAE_DBCU_WCH_1_AXI_SEL_ADDR(aae_base + AAE_DBCU_OFFSET), 0x1, 1, 0); // WCH_1_AXI_SEL
    set_reg(AAE_DBCU_CMDLIST_AXI_SEL_ADDR(aae_base + AAE_DBCU_OFFSET), 0x1, 1, 0); // CMDLIST_AXI_SEL
    set_reg(AAE_SDMA_CTRL0_ADDR(aae_base + AAE_SDMA_OFFSET, 0), 0x3, 2, 12); // sdma performance
    set_reg(AAE_SDMA_DBG_CTRL0_ADDR(aae_base + AAE_SDMA_OFFSET, 0), 1, 1, 20); // sdma anti-hanging
    set_reg(AAE_GLB_PART0_DBG_CFG_CTRL_ADDR(aae_base + AAE_GLB0_OFFSET), 0x3, 2, 0); // software read anti-hanging
    aae_pr_debug("-");
    return 0;
}

int32_t aae_init(struct aae_manager *aae_mgr)
{
    int32_t ret = -1;
    aae_check_and_return(!aae_mgr, -1, err, "aae_mgr is null!");
	aae_check_and_return(!aae_mgr->aae_base, -1, err, "aae_base is null!");
    aae_pr_info("+");

    set_reg(AAE_GLB_PART0_AAE_JTAG_MODE_ADDR(aae_mgr->aae_base + AAE_GLB0_OFFSET), 0x0, 1, 0);

    ret = aae_tbu_connect(aae_mgr->aae_base);
    aae_check_and_return(ret < 0, -1, err, "tbu connect failed!");

    cmdlist_init(aae_mgr->aae_base);

    aae_pr_debug("aae cmdlist init success");
    ret = aae_glb_reg_init(aae_mgr->aae_base);
    aae_check_and_return(ret < 0, -1, err, "aae glb reg init failed!");

    dacc_aae_load();
    aae_pr_debug("aae dacc load done");

    ret = start_dacc(aae_mgr->aae_base);
    aae_check_and_return(ret < 0, -1, err, "aae dacc start failed!");
    aae_pr_info("aae dacc start success");

    ret = aae_ffts_connect(aae_mgr->aae_base);
    aae_check_and_return(ret < 0, -1, err, "aae connect ffts failed!");

    aae_pr_info("aae init success");
    aae_pr_info("-");
    return 0;
}