/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: provide aae dacc start function interfaces.
 */
#include <linux/delay.h>
#include <aae/soc_aae_define.h>
#include <aae/soc_aae_dacc_interface.h>
#include "ukmd_utils.h"
#include "akmd_log.h"
#include "aae_dacc_ctrl.h"

int32_t start_dacc(char __iomem *aae_base)
{
    int32_t ret = -1;
    uint32_t times = 0;
    char __iomem *dacc_base = NULL;
    aae_check_and_return(!aae_base, -1, err, "aae_base is null!");
    dacc_base = aae_base + DACC_AAE_OFFSET;
    set_reg(SOC_DACC_AAE_POR_RESET_PC_REG_ADDR(dacc_base + DMC_OFFSET), 0, 32, 0);
    set_reg(SOC_DACC_AAE_CORE_CONFIG_REG_ADDR(dacc_base + DMC_OFFSET), 0, 1, 4);

    while (true) {
        uint32_t status = readl(SOC_DACC_AAE_RISCV_2_ACPU_REG_ADDR(dacc_base + DMC_OFFSET)); // 0xe2522050
        if (status) {
            aae_pr_info("wait riscv init finish for %u us, status = 0x%x", (times * 50), status);
            ret = 0;
            break;
        } else if (times >= 1000 * 1000) {
            aae_pr_err("wait riscv init finish timeout, failed!");
            ret = -1;
            break;
        } else {
            udelay(50);
            times++;
        }
    }

    return ret;
}