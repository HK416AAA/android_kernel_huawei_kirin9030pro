/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/kernel.h>
#include "fltp_coord.h"
#include "fltp_utils.h"

static DEFINE_MUTEX(trans_mutex);
static fltp_vsp_callback fltp_callback;

bool __attribute__((weak)) wifi_tx_venc_pkg(struct tx_layer_ctrl *ctrl)
{
	return true;
}

void __attribute__((weak)) sx_set_callback(fltp_vsp_callback *callback)
{
}

// 处理wifi反馈回调
void wifi_tx_send_done(struct send_result_sx* send_result) {
    rcu_read_lock();
    if (!send_result || !send_result->layer_list) {
        rcu_read_unlock();
        return;
    }
    htp_info("wifi_tx_send_done end batchid : %u \n", send_result->layer_list->batch_id);
    fltp_coord_process_hmac_message(send_result);
    rcu_read_unlock();
}

static int fltp_loopback_skb(struct sk_buff *skb)
{
	int ret = 0;
#ifdef LOOPBACK_DEV
	/* do not fool net_timestamp_check() with various clock bases */
	skb->tstamp = 0;
	skb_orphan(skb);
	local_bh_disable();
	ret = netif_rx(skb);
	local_bh_enable();
#endif
	return ret;
}

// 需要加一个以太头 （12字节）
int32_t fltp_trans_send_data_to_wifi(struct sk_buff * skb, uint16_t batch_id) {
    struct fltphdr fdr = fltp_htp_hdr(skb);  // 获取HTP头部
#ifndef LOOPBACK_DEV
    struct ethhdr *eth = (struct ethhdr *)skb_mac_header(skb);
    
    struct tx_layer_ctrl *ctrl = kmalloc(sizeof(*ctrl), GFP_ATOMIC);
    if (!ctrl) {
        htp_err("ctrl kmalloc fail\n");
        return FLTP_NO_MEMORY;
    }
    ctrl->version = FLTP_CTRL_VERSION;
    (void)memcpy_s(ctrl->mac_ra_address, sizeof(uint8_t) * MAX_HARDWARE_MAC_ADDR_LEN, 
            eth->h_dest, 
            sizeof(uint8_t) * MAX_HARDWARE_MAC_ADDR_LEN);
    (void)memcpy_s(ctrl->mac_sa_address, sizeof(uint8_t) * MAX_HARDWARE_MAC_ADDR_LEN, 
            eth->h_source, 
            sizeof(uint8_t) * MAX_HARDWARE_MAC_ADDR_LEN);
    ctrl->netbuf = (struct oal_netbuf_stru *)skb;
    ctrl->batch_id = batch_id;
    htp_info("seq : %u batchid : %u\n", fdr.seq, batch_id);
    if (wifi_tx_venc_pkg(ctrl) != true) {
        kfree(ctrl);
        // skb的释放由调用者完成
        return FLTP_WIFI_SEND_FAIL;
    }
#endif
#ifdef LOOPBACK_DEV
    int iRet = fltp_loopback_skb(skb);
    if (iRet) {
        htp_err("loopback send error\n");
        return FLTP_WIFI_SEND_FAIL;
    }
    htp_debug("loopback send success seq : %u\n", fdr.seq);
#endif
    return FLTP_SUCCESS;
}

void fltp_trans_recv_packet(struct sk_buff *skb) {
	struct sk_buff *cur_skb = skb;
    fltp_hskb_flag_t flag;
    rcu_read_lock();
    fltp_htp_recv_packet_process(skb, &flag);
    if (flag == FLTP_HSKB_ADD_BACKLOG || flag == FLTP_HSKB_DROP) {
        htp_info("fltp_trans_recv_packet,back log or drop packet no process\n");
        rcu_read_unlock();
        return;
    }

    /* 判断是否为数据包 */
    struct fltp_htp_skb_cb cb = fltp_htp_skb_cb(cur_skb);
    if (cb.packet_type == FLTP_PKT_TYPE_DATA) {
        struct fltphdr fdr = fltp_htp_hdr(skb);  // 获取HTP头部
        struct sock *sk = fltp_htp_get_sk_by_skb(skb, fdr.dst, fdr.src);
        htp_info("fltp_trans_recv_packet rcv seq:%u time:%lu , skb len:%u\n", fdr.seq, getcurtime(), skb->len);
	    fltp_coord_recv_packet(sk, cur_skb);
    }
    rcu_read_unlock();
}

void fltp_trans_setvsp_callback(void) {
    mutex_lock(&trans_mutex);
    fltp_callback.wifi_tx_send_done = wifi_tx_send_done;
    fltp_callback.wifi_rx_msdu = fltp_trans_recv_packet;
	sx_set_callback(&fltp_callback);
    mutex_unlock(&trans_mutex);
}
