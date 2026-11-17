/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: This file is the impl file of booster feature init.
 * Author: wangdingbang
 * Create: 2025-04-24
 */

#include "booster_dmi_client.h"
#ifdef CONFIG_HW_WIFIPRO
#include <hwnet/ipv4/wifipro_tcp_monitor_dmi_client.h>
#endif
#include "booster_bpf_client.h"
#ifdef CONFIG_HW_BOOSTER
#include "dpa_pkt_client.h"
#endif
#ifdef CONFIG_CHR_NETLINK_MODULE
#include "dpa_chr_client.h"
#include "dpa_chr_web_stat.h"
#endif
#ifdef CONFIG_HW_NETWORK_QOE
#include "qoe_client.h"
#endif

int booster_all_init(void)
{
    init_booster_dmi_client();
#ifdef CONFIG_HW_WIFIPRO
    wifipro_tcp_monitor_dmi_client_init();
#endif
    bpf_client_init();
#ifdef CONFIG_HW_BOOSTER
    dpa_pkt_num_dmi_client_init();
#endif
#ifdef CONFIG_CHR_NETLINK_MODULE
    dpa_chr_reg_tech_dmi_client_init();
    dpa_chr_rtt_dmi_client_init();
#endif
#ifdef CONFIG_HW_NETWORK_QOE
    qoe_client_init();
#endif
    return 0;
}

int booster_all_exit(void)
{
    return 0;
}