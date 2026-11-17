 
 
#ifndef _QOE_CLIENT_H
#define _QOE_CLIENT_H

#ifdef CONFIG_HW_NETWORK_QOE
#include "hwnet/booster/netlink_handle.h"
#include "hwnet/booster/ip_para_collec.h"

#define DPA_CHANNEL_NUM 4

struct qoe_client_dfx {
    bool took_away;
    unsigned int malloc_len;
    unsigned int ori_app_cnt;
};

struct dpa_tcp_res {
    u32 pid;
    u32 uid;
    struct tcp_res_info info[DPA_CHANNEL_NUM];
};

struct dpa_tcp_collect_res {
    u16 cnt;
    u16 sync;
    struct dpa_tcp_res res[0];
};

struct dpa_res_msg {
    u16 type;
    u16 len;
    struct dpa_tcp_collect_res tcp;
};

typedef void (*combine_ip_para)(struct res_msg *res);
typedef void (*sync_cmd)(struct req_msg_head *msg);

extern void dpa_combine_func_register(combine_ip_para func);
extern void dpa_sync_config_register(sync_cmd func);
#endif

void qoe_client_init(void);
 
#endif // _QOE_CLIENT_H