/*
* Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
* Description: This file is the impl file of acpu communicate with pkt.
* Author: tianlei
* Create: 2025-05-10
*/
#include "dpa_chr_client.h"
#include <linux/kernel.h>
#include <linux/export.h>
#include <linux/spinlock.h>
#include <linux/slab.h>
#include <securec.h>
#include "interface/client/booster_dmi_client.h"
#include "hwnet/chr/wbc_hw_hook.h"
#include "dpa_chr_netlink.h"
 
void set_dpa_reg_tech(int *buf)
{
    if (buf == NULL) {
        return;
    }
    int ret = booster_dpa_request_async(DPA_CHR, SET_REG_TECH, (unsigned char *)buf, sizeof(int));
    if (ret != 0) {
        printk(KERN_INFO "[booster_dpa_chr_client] dpa set dpa reg tech fail !\n");
    }
}

void set_dpa_app_list(u32 *buf, int num)
{
    if (buf == NULL) {
        return;
    }
    int ret = booster_dpa_request_async(DPA_CHR, SET_APP_LIST, (unsigned char *)buf, num * sizeof(u32));
    if (ret != 0) {
        printk(KERN_INFO "[booster_dpa_chr_client] dpa set dpa app list fail !\n");
    }
}

void dpa_chr_reg_tech_dmi_client_init(void)
{
#ifdef CONFIG_CHR_NETLINK_MODULE
    register_chr_reg_tech_dmi_ops(set_dpa_reg_tech);
#endif
    register_chr_app_list_dmi_ops(set_dpa_app_list);
}