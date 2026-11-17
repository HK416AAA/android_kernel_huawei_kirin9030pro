/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: kernel config expot to dpa host.
 * Author: wangdingbang
 * Create: 2025-05-13
 */

#include <linux/export.h>
#include <securec.h>
#include <linux/kernel.h>

struct kernel_config_to_dpa {
    bool config_hw_booster;
    bool config_hw_wifipro;
    bool config_hw_network_aware;
    bool config_chr_netlink_module;
    bool config_huawei_smartcom;
    bool config_hw_network_qoe;
};

void fetch_kernel_config_to_dpa(struct kernel_config_to_dpa *config)
{
    printk(KERN_ERR "fetch_kernel_config_to_dpa success.\n");
    (void)memset_s(config, sizeof(struct kernel_config_to_dpa), 0, sizeof(struct kernel_config_to_dpa));

#ifdef CONFIG_HW_BOOSTER
    config->config_hw_booster = true;
#endif

#ifdef CONFIG_HW_WIFIPRO
    config->config_hw_wifipro = true;
#endif

#ifdef CONFIG_HW_NETWORK_AWARE
    config->config_hw_network_aware = true;
#endif

#ifdef CONFIG_CHR_NETLINK_MODULE
    config->config_chr_netlink_module = true;
#endif

#ifdef CONFIG_HUAWEI_SMARTCOM
    config->config_huawei_smartcom = true;
#endif

#ifdef CONFIG_HW_NETWORK_QOE
    config->config_hw_network_qoe = true;
#endif
}

EXPORT_SYMBOL(fetch_kernel_config_to_dpa);

#ifndef CONFIG_HW_WIFIPRO
#include "../ipv4/wifipro_tcp_monitor_dmi_client.h"
void register_wifipro_tcp_monitor_dmi_ops(struct wifipro_tcp_monitor_dmi_client_ops ops)
{
}
EXPORT_SYMBOL(register_wifipro_tcp_monitor_dmi_ops);
#endif

#ifndef CONFIG_HW_BOOSTER
typedef void (*get_pkt_num)(long *tcp_rx, long *tcp_tx, long *dns_rx, long *dns_tx);
void register_tcp_pkt_num_dmi_ops(get_pkt_num func)
{
}
EXPORT_SYMBOL(register_tcp_pkt_num_dmi_ops);
#endif

#ifndef CONFIG_CHR_NETLINK_MODULE
#include "../chr/wbc_hw_hook.h"
typedef void (*set_reg_tech)(int *data_reg);
void register_chr_reg_tech_dmi_ops(set_reg_tech func)
{
}
EXPORT_SYMBOL(register_chr_reg_tech_dmi_ops);

int get_data_reg_tech(void)
{
	return 0;
}
EXPORT_SYMBOL(get_data_reg_tech);

struct http_stream *get_stream_list(u8 hash_cnt)
{
	return NULL;
}
EXPORT_SYMBOL(get_stream_list);

void set_stream_list(u8 hash_cnt)
{
}
EXPORT_SYMBOL(set_stream_list);

void set_tcp_for_dpa(void)
{
}
EXPORT_SYMBOL(set_tcp_for_dpa);
#endif

#ifndef CONFIG_HW_NETWORK_QOE
#include "../booster/ip_para_collec.h"
#include "../booster/netlink_handle.h"
typedef void (*combine_ip_para)(struct res_msg *res);
typedef void (*sync_cmd)(struct req_msg_head *msg);
 
void dpa_combine_func_register(combine_ip_para func)
{
}
EXPORT_SYMBOL(dpa_combine_func_register);
 
void dpa_sync_config_register(sync_cmd func)
{
}
EXPORT_SYMBOL(dpa_sync_config_register);
#endif

#ifndef CONFIG_HUAWEI_SMARTCOM
#include <net/sock.h>
void smartcom_tcp_fallback(struct sock *sk, int reason, int state)
{
}
EXPORT_SYMBOL(smartcom_tcp_fallback);
#endif