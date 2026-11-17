

#ifdef CONFIG_HW_NETWORK_QOE
#include <linux/namei.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include "qoe_client.h"
#include "booster_dmi_client.h"
#include "booster_features.h"
#include "bsp_print.h"
#include "securec.h"

#define MAX_VALID_APP_CNT 2
#define SYS_UID 10000
 
static char *g_data_ptr = NULL;
static spinlock_t g_data_lock;
static struct qoe_client_dfx dfx = {0};

static void merge_res_info(struct tcp_res *sum, struct dpa_tcp_res *add)
{
    for (int i = 0; i < DPA_CHANNEL_NUM; i++) {
        sum->info[i].in_rts_pkt += add->info[i].in_rts_pkt;
        sum->info[i].in_pkt += add->info[i].in_pkt;
        sum->info[i].in_len += add->info[i].in_len;
        sum->info[i].out_rts_pkt += add->info[i].out_rts_pkt;
        sum->info[i].out_pkt += add->info[i].out_pkt;
        sum->info[i].out_len += add->info[i].out_len;
        sum->info[i].rtt += add->info[i].rtt;
        sum->info[i].out_all_pkt += add->info[i].out_all_pkt;
        sum->info[i].in_udp_pkt += add->info[i].in_udp_pkt;
        sum->info[i].out_udp_pkt += add->info[i].out_udp_pkt;
        sum->info[i].in_udp_len += add->info[i].in_udp_len;
        sum->info[i].out_udp_len += add->info[i].out_udp_len;
        sum->info[i].tcp_sk_num += add->info[i].tcp_sk_num;
        sum->info[i].sk_rtt_sum += add->info[i].sk_rtt_sum;
        sum->info[i].tcp_syn_rts_pkt += add->info[i].tcp_syn_rts_pkt;
        if (sum->info[i].in_len > MAX_U32_VALUE)
            sum->info[i].in_len = MAX_U32_VALUE;
        if (sum->info[i].out_len > MAX_U32_VALUE)
            sum->info[i].out_len = MAX_U32_VALUE;
        if (sum->info[i].rtt > MAX_U32_VALUE)
            sum->info[i].rtt = MAX_U32_VALUE;
        if (sum->info[i].in_udp_len > MAX_U32_VALUE)
            sum->info[i].in_udp_len = MAX_U32_VALUE;
        if (sum->info[i].out_udp_len > MAX_U32_VALUE)
            sum->info[i].out_udp_len = MAX_U32_VALUE;
    }
}
 
static void merge_res_data(struct res_msg *res, struct dpa_res_msg *dpa_res)
{
    struct tcp_collect_res *tcp_res_ptr = &res->res.tcp;
    unsigned short ori_cnt = tcp_res_ptr->cnt;
 
    struct dpa_tcp_collect_res *dpa_res_ptr = &dpa_res->tcp;
    unsigned short dpa_cnt = dpa_res_ptr->cnt;
    
    if (ori_cnt > MAX_APP_LIST_LEN) {
        printk(KERN_ERR "[dpa_qoe] invalid ori_cnt: %hu \n", ori_cnt);
        return;
    }
    
    for (unsigned short i = 0; i < ori_cnt; i++) {
        if (tcp_res_ptr->res[i].uid < SYS_UID) {
            continue;
        }
        for (unsigned short j = 0; j < dpa_cnt; j++) {
            if (tcp_res_ptr->res[i].uid == dpa_res_ptr->res[j].uid) {
                merge_res_info(&tcp_res_ptr->res[i], &dpa_res_ptr->res[j]);
                printk(KERN_DEBUG "[dpa_qoe] merge_dpa_res success");
                break;
            }
        }
    }
}
 
void sync_config_cmd(struct req_msg_head *msg)
{
    if (unlikely(msg == NULL)) {
        return;
    }
    if (msg->type != UPDATE_APP_INFO_CMD) {
        return;
    }
    unsigned short cnt = ((struct req_msg *)msg)->req.tcp_req.cnt;
    unsigned short valid_cnt = cnt;
    unsigned int uid;
    for (int i = 0; i < cnt; i++) {
        uid = ((struct req_msg *)msg)->req.tcp_req.id[i].uid;
        if (uid < SYS_UID) {
            valid_cnt--;
        }
    }
    if (valid_cnt == 0 || valid_cnt > MAX_VALID_APP_CNT) {
        return;
    }
    if (valid_cnt == dfx.ori_app_cnt) {
        goto request_async;
    }
    printk(KERN_INFO "[dpa_qoe] sync_config_cmd, msg_len: %d, cnt: %d\n", msg->len, cnt);
    spin_lock_bh(&g_data_lock);
    dfx.ori_app_cnt = valid_cnt;
    if (g_data_ptr != NULL) {
        kfree(g_data_ptr);
        g_data_ptr = NULL;
    }
    dfx.malloc_len = sizeof(struct res_msg) + valid_cnt * sizeof(struct dpa_tcp_res);
    g_data_ptr = (char *)kmalloc(dfx.malloc_len, GFP_KERNEL);
    if (g_data_ptr == NULL) {
        spin_unlock_bh(&g_data_lock);
        printk(KERN_ERR "[dpa_qoe] kmalloc fail \n");
        return;
    }
    spin_unlock_bh(&g_data_lock);
request_async:
    booster_dpa_request_async(QOE_PARA_COLLECT_FEATURE, D_UPDATE_APP_INFO_CMD, (char *)msg, msg->len);
}
 
void add_dpa_res(struct res_msg *res)
{
    if (unlikely(res == NULL)) {
        return;
    }
    spin_lock_bh(&g_data_lock);
    if (dfx.took_away) {
        spin_unlock_bh(&g_data_lock);
        return;
    }
    struct dpa_tcp_collect_res *tcp_res = &(((struct dpa_res_msg *)g_data_ptr)->tcp);
    if (tcp_res->cnt != dfx.ori_app_cnt) {
        printk(KERN_ERR "[dpa_qoe] tcp res cnt: %d not equal ori_app_cnt: %d \n", tcp_res->cnt, dfx.ori_app_cnt);
        spin_unlock_bh(&g_data_lock);
        return;
    }
    for (unsigned int i = 0; i < tcp_res->cnt; i++) {
        for (unsigned int j = 0; j < DPA_CHANNEL_NUM; j++) {
            struct tcp_res_info *channel_res = &tcp_res->res[i].info[j];
            if (channel_res->in_pkt == 0 && channel_res->out_pkt == 0 &&
                channel_res->in_udp_pkt == 0 && channel_res->out_udp_pkt == 0) {
                continue;
            }
            printk(KERN_INFO "[dpa_qoe] channel: %d uid: %d, in_pkt: %d in_len: %d out_pkt: %d out_len: %d "
            "rtt: %d in_udp_pkt: %d out_udp_pkt: %d in_udp_len: %d out_udp_len: %d ", j, tcp_res->res[i].uid, 
            channel_res->in_pkt, channel_res->in_len, channel_res->out_pkt, channel_res->out_len, channel_res->rtt,
            channel_res->in_udp_pkt, channel_res->out_udp_pkt, channel_res->in_udp_len, channel_res->out_udp_len);
        }
    }
    merge_res_data(res, (struct dpa_res_msg *)g_data_ptr);
    int ret = memset_s(g_data_ptr, dfx.malloc_len, 0, dfx.malloc_len);
    if (ret != EOK) {
        printk("[dpa_qoe] memset_s fail");
    }
    dfx.took_away = true;
    spin_unlock_bh(&g_data_lock);
}
 
static void dpa_qoe_handle_response(unsigned short cmd, unsigned char *data, unsigned int len)
{
    printk(KERN_DEBUG "[dpa_qoe] dpa_qoe_handle_response, len: %d", len);
    if (cmd == D_REPORT_IP_PARA_CMD) {
        spin_lock_bh(&g_data_lock);
        if (len != dfx.malloc_len) {
            spin_unlock_bh(&g_data_lock);
            printk(KERN_ERR "[dpa_qoe] response len not equel malloc_len \n");
            return;
        }
        if (g_data_ptr == NULL) {
            spin_unlock_bh(&g_data_lock);
            printk(KERN_ERR "[dpa_qoe] g_data_ptr is null \n");
            return;
        }
        int ret = memcpy_s(g_data_ptr, len, data, len);
        if (ret != EOK) {
            spin_unlock_bh(&g_data_lock);
            printk(KERN_ERR "[dpa_qoe] handle response memcpy_s fail\n");
            return;
        }
        dfx.took_away = false;
        spin_unlock_bh(&g_data_lock);
    }
}
 
void qoe_client_init(void)
{
    printk(KERN_INFO "[dpa_qoe] init, sizeof res_msg: %lu, req_msg: %lu, tcp_res: %lu\n",
        sizeof(struct res_msg), sizeof(struct req_msg), sizeof(struct tcp_res));
    spin_lock_init(&g_data_lock);
    dpa_combine_func_register(add_dpa_res);
    dpa_sync_config_register(sync_config_cmd);
    register_handle_response_func(QOE_PARA_COLLECT_FEATURE, dpa_qoe_handle_response);
}
#else

#include <linux/printk.h>
#include "qoe_client.h"
void qoe_client_init(void) {
    printk(KERN_ERR "[dpa_qoe] not define CONFIG_HW_NETWORK_QOE, not initial. \n");
}

#endif