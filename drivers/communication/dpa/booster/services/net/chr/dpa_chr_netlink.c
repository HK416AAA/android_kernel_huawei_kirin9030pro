/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: This module is to report dpa chr stat parameters.
 * Author: tianlei
 * Create: 2025-03-17
 */

#include <huawei_platform/log/hw_log.h>
#include <net/sock.h>
#include <uapi/linux/netlink.h>
#include <securec.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/mutex.h>
#include <linux/semaphore.h>
#include <linux/time.h>
#include <linux/skbuff.h>
#include <linux/netlink.h>
#include <linux/kthread.h>
#include <linux/version.h>
#include "dpa_chr_host_collec.h"
#ifdef CONFIG_CHR_NETLINK_MODULE
#include "dpa_chr_web_stat.h"
#endif
#include "dpa_chr_netlink.h"
#include "dpa_chr_info.h"

#undef HWLOG_TAG
#define HWLOG_TAG dpa_chr_netlink
#define DPA_CHR_STAT_RPT 25
#define DPA_CHR_EVENT_RPT 27
#define DPA_DUBAI_STAT_RPT 28
#define CHR_NETLINK_MAX_SIZE 4080
HWLOG_REGIST();

static unsigned int g_user_space_pid;
/* save user space progress pid when user space netlink socket registering */
static spinlock_t g_dpa_chr_send_lock;
/* dpa chr netlink socket fd */
static struct sock *g_dpa_chr_nlfd;
struct dpa_chr_nl_packet_msg g_dpa_chr_msg = {0};
struct dpa_dubai_nl_packet_msg g_dpa_dubai_msg = {0};
u32 g_report_uid[DPA_CHR_MAX_REPORT_APP_COUNT] = {0};

struct dpachr_msg_2_knl {
    struct nlmsghdr hdr;
    unsigned char data[0];
};

struct uid_msg {
    u32 type;
    u32 len;
    u32 uid_num;
};

static set_app_list g_dpa_chr_set_app_list_ops = NULL;
void register_chr_app_list_dmi_ops(set_app_list func)
{
	printk(KERN_INFO "register_chr_app_list_dmi_ops success\n");
	g_dpa_chr_set_app_list_ops = func;
}

static DEFINE_MUTEX(dpa_chr_nl_receive_sem);

static void process_uid_list(const struct dpachr_msg_2_knl *msg)
{
    if ((msg->hdr.nlmsg_len - sizeof(struct nlmsghdr)) < sizeof(struct uid_msg)) {
        printk(KERN_INFO "[dpa_chr] uid length error\n");
        return;
    }
    struct uid_msg *uid_msg_rcv = (struct uid_msg *)msg->data;
    u32 uidnum = uid_msg_rcv->uid_num;
    u32 *ptr = &uid_msg_rcv->uid_num;
    uidnum = uidnum > DPA_CHR_MAX_REPORT_APP_COUNT ? DPA_CHR_MAX_REPORT_APP_COUNT : uidnum;
    int i;
    for (i = 0; i < uidnum; i++) {
        g_report_uid[i] = *(ptr + i + 1);
        printk(KERN_INFO "%s: dpa chr uid = %d\n", __func__, g_report_uid[i]);
    }
    if (g_dpa_chr_set_app_list_ops) {
        g_dpa_chr_set_app_list_ops(&g_report_uid[0], uidnum);
    }
}

u32 *get_report_app_uid(void)
{
    return &g_report_uid[0];
}

int dpa_chr_notify_event(int pid, struct dpa_res_msg_head *msg)
{
    int ret;
    int size;
    struct sk_buff *skb = NULL;
    struct nlmsghdr *nlh = NULL;
    struct dpa_res_msg_head *packet = NULL;
 
    spin_lock_bh(&g_dpa_chr_send_lock);
    if (!pid || !g_dpa_chr_nlfd || !msg) {
        printk(KERN_ERR "%s: dpa cannot notify event, pid = %d\n", __func__, pid);
        ret = -1;
        goto end;
    }
    if (msg->len > CHR_NETLINK_MAX_SIZE) {
        printk(KERN_ERR "%s: dpa chr msg oversize.\n", __func__);
        ret = -1;
        goto end;
    }
    size = msg->len;
    skb = nlmsg_new(size, GFP_ATOMIC);
    if (skb == NULL) {
        printk(KERN_ERR "%s: dpa alloc skb fail\n", __func__);
        ret = -1;
        goto end;
    }
    nlh = nlmsg_put(skb, 0, 0, NETLINK_DPA_CHR_MSG_FROM_KERNEL, size, 0);
    if (nlh == NULL) {
        kfree_skb(skb);
        skb = NULL;
        ret = -1;
        goto end;
    }
 
    packet = nlmsg_data(nlh);
    if (memset_s(packet, size, 0, size) != EOK) {
        kfree_skb(skb);
        skb = NULL;
        ret = -1;
        goto end;
    }
    if (memcpy_s(packet, size, msg, size) != EOK) {
        kfree_skb(skb);
        skb = NULL;
        ret = -1;
        goto end;
    }
 
    /* skb will be freed in netlink_unicast */
    ret = netlink_unicast(g_dpa_chr_nlfd, skb, pid, MSG_DONTWAIT);
 
end:
    spin_unlock_bh(&g_dpa_chr_send_lock);
    return ret;
}

static void kernel_dpa_chr_receive(struct sk_buff *__skb)
{
    struct nlmsghdr *nlh = NULL;
    struct sk_buff *skb = NULL;
 
    if (__skb == NULL) {
        hwlog_err("Invalid parameter in dpa: zero pointer reference(__skb)\n");
        return;
    }
    skb = skb_get(__skb);
    if (skb == NULL) {
        hwlog_err("kernel_dpa_chr_receive: skb = NULL\n");
        return;
    }
    mutex_lock(&dpa_chr_nl_receive_sem);
    if (skb->len >= (unsigned int)NLMSG_HDRLEN) {
        nlh = nlmsg_hdr(skb);
        if (nlh == NULL) {
            hwlog_err("kernel_dpa_chr_receive: nlh = NULL\n");
            kfree_skb(skb);
            mutex_unlock(&dpa_chr_nl_receive_sem);
            return;
        }
        if ((nlh->nlmsg_len >= sizeof(struct nlmsghdr)) &&
            (skb->len >= nlh->nlmsg_len)) {
            if (nlh->nlmsg_type == NETLINK_DPA_CHR_REG) {
                /*
                * Save user space progress pid when
                * register netlink socket.
                */
                g_user_space_pid = nlh->nlmsg_pid;
            } else if (nlh->nlmsg_type == NETLINK_DPA_CHR_SET_APP_UID &&
                skb->len >= sizeof(struct dpachr_msg_2_knl) &&
                nlh->nlmsg_len >= sizeof(struct dpachr_msg_2_knl)) {
                process_uid_list((struct dpachr_msg_2_knl *)nlh);
            } else if (nlh->nlmsg_type == NETLINK_DPA_CHR_DUBAI_QUARY) {
                dpa_chr_dubai_request(1);
            } else {
                hwlog_err("dpachr_netlink::wrong netlink msg format");
            }
        }
    }
    kfree_skb(skb);
    mutex_unlock(&dpa_chr_nl_receive_sem);
}

void dpa_chr_report_send(void)
{
    memcpy_s(&g_dpa_chr_msg.chr_report, sizeof(struct dpa_chr_report), &g_dpa_chr_report, sizeof(struct dpa_chr_report));
    g_dpa_chr_msg.chr_event = DPA_CHR_STAT_RPT;
    g_dpa_chr_msg.len = sizeof(struct dpa_chr_report) + sizeof(u32) + sizeof(u32);
    dpa_chr_notify_event(g_user_space_pid, (struct dpa_res_msg_head *)&g_dpa_chr_msg);
    memset_s(&g_dpa_chr_report, sizeof(g_dpa_chr_report), 0, sizeof(g_dpa_chr_report));
    memset_s(&g_dpa_chr_msg, sizeof(struct dpa_chr_nl_packet_msg), 0, sizeof(struct dpa_chr_nl_packet_msg));
}

int dpa_chr_event_report_send(dpa_chr_event_msg *data, u32 len)
{
    struct dpa_chr_nl_event_msg *msg = NULL;
    int size = len + sizeof(u32) * 2;
    if (data == NULL || size > CHR_NETLINK_MAX_SIZE) {
        return -1;
    } 

    msg = (struct dpa_chr_nl_event_msg *)kmalloc(size, GFP_KERNEL);
    if (msg == NULL) {
        printk(KERN_INFO "%s: dpa mem kmalloc failed\n", __func__);
        return -1;
    }
    msg->chr_event = DPA_CHR_EVENT_RPT;
    msg->len = len + sizeof(u32) + sizeof(u32);
    memcpy_s(&msg->chr_event_report, len, data, len);
    dpa_chr_notify_event(g_user_space_pid, (struct dpa_res_msg_head *)msg);
    kfree(msg);

    return 0;
}

void dpa_dubai_report_send(void *data, u32 len)
{
    if (data == NULL || len != sizeof(dpa_chr_dubai_info_s)) {
        printk(KERN_ERR "%s: dpa dubai notify event, msg data err!\n", __func__);
    }
    memcpy_s(&g_dpa_dubai_msg.dubai_report, sizeof(dpa_chr_dubai_info_s), data, len);
    g_dpa_dubai_msg.dubai_event = DPA_DUBAI_STAT_RPT;
    g_dpa_dubai_msg.len = sizeof(dpa_chr_dubai_info_s) + sizeof(u32) + sizeof(u32);
    dpa_chr_notify_event(g_user_space_pid, (struct dpa_res_msg_head *)&g_dpa_dubai_msg);
    memset_s(&g_dpa_dubai_msg, sizeof(struct dpa_dubai_nl_packet_msg), 0, sizeof(struct dpa_dubai_nl_packet_msg));
}

unsigned int get_user_space_pid(void)
{
    return g_user_space_pid;
}

void dpa_chr_netlink_init(void)
{
    struct netlink_kernel_cfg dpa_chr_nl_cfg = {
        .input = kernel_dpa_chr_receive,
    };
    g_dpa_chr_nlfd = netlink_kernel_create(&init_net, NETLINK_DPA_CHR, &dpa_chr_nl_cfg);
    if (!g_dpa_chr_nlfd)
        printk(KERN_INFO "%s: dpa create netlink failed\n", __func__);
    else
        printk(KERN_INFO "%s: dpa create netlink success\n", __func__);
    spin_lock_init(&g_dpa_chr_send_lock);
    memset_s(&g_dpa_chr_msg, sizeof(struct dpa_chr_nl_packet_msg), 0, sizeof(struct dpa_chr_nl_packet_msg));
    memset_s(g_report_uid, sizeof(u32) * DPA_CHR_MAX_REPORT_APP_COUNT, 0xFFFFFFFF, sizeof(u32) * DPA_CHR_MAX_REPORT_APP_COUNT);
}

int dpa_chr_show_uid_list(void)
{
    int i;
    for (i = 0; i < DPA_CHR_MAX_REPORT_APP_COUNT; i++) {
        printk(KERN_INFO "%s: [dpa_chr] uid list %d = %d\n", __func__, i, g_report_uid[i]);
    }
    return 0;
}
