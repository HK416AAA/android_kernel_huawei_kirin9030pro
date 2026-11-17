

#include "bpf_dpa_netlink.h"

#include <linux/errno.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/netlink.h>
#include <linux/skbuff.h>
#include <linux/semaphore.h>
#include <linux/time.h>
#include <linux/types.h>
#include <linux/version.h>
#include <net/sock.h>
#include <net/netlink.h>
#include <securec.h>
#include <uapi/linux/netlink.h>

#include "booster_features.h"
#include "booster_dmi_client.h"

DEFINE_MUTEX(dpa_receive_sem);
typedef enum {
    NETLINK_BPF_REG = 0,
    NETLINK_BPF_TO_KER_MSG,
    NETLINK_BPF_TO_USR_MSG,
} bpf_netlink_msg_type;

#ifndef NETLINK_DPA_BPF
#define NETLINK_DPA_BPF 48
#endif

/* netlink socket fd */
static struct sock *g_dpa_nlfd;
/* save user space progress pid when user space netlink socket registering */
static unsigned int g_user_space_pid;
static int g_dpa_module_state = BPF_NETLINK_EXIT;

static spinlock_t g_dpa_send_lock;

#define HED_LEN (sizeof(struct nlmsghdr) + sizeof (bpf_op_code))

int send_resp_msg(bpf_op_code opcode, struct bpf_packet_msg *msg)
{
    int ret = -1;
    int size;
    struct sk_buff *skb = NULL;
    struct nlmsghdr *nlh = NULL;
    struct bpf_packet_msg *packet = NULL;

    spin_lock_bh(&g_dpa_send_lock);
    if (!g_user_space_pid || !g_dpa_nlfd || !msg) {
        printk(KERN_INFO "[dpa_netlink] wrong para, pid {%d}.\n", g_user_space_pid);
        goto end;
    }
    size = sizeof(struct bpf_packet_msg);
    skb = nlmsg_new(size, GFP_ATOMIC);
    if (skb == NULL) {
        printk(KERN_INFO "[dpa_netlink] unable to new msg head");
        goto end;
    }
    nlh = nlmsg_put(skb, 0, 0, NETLINK_BPF_TO_USR_MSG, size, 0);
    if (nlh == NULL) {
        printk(KERN_INFO "[dpa_netlink] unable to put msg head");
        skb = NULL;
        goto end;
    }
    packet = nlmsg_data(nlh);
    errno_t err = memset_s(packet, sizeof(struct bpf_packet_msg), 0, sizeof(struct bpf_packet_msg));
    if (err != EOK) {
        printk(KERN_INFO "[dpa_netlink] unable to set memory for bpf_packet_msg.\n");
        goto end;
    }

    err = memcpy_s(packet, size, msg, size);
    if (err != EOK) {
        printk(KERN_INFO "[dpa_netlink] unable to copy memory for bpf_packet_msg.\n");
        goto end;
    }
    /* skb will be freed in netlink_unicast */
    ret = netlink_unicast(g_dpa_nlfd, skb, g_user_space_pid, MSG_DONTWAIT);
    if (ret < 0) {
        printk(KERN_INFO "[dpa_netlink] send msg to user space failed! errno = %d.\n", ret);
        goto end;
    }
    printk(KERN_INFO "[dpa_netlink] send msg to user space success! \n");
    ret = 0;

end:
    if (skb != NULL) {
        kfree_skb(skb);
    }
    spin_unlock_bh(&g_dpa_send_lock);
    return ret;
}

static void process_bpf_msg(struct bpf_msg_2_knl *msg)
{
    if (msg->bpf_code > NETLINK_BPF_OPCODE_MAX) {
        printk(KERN_INFO "[dpa_netlink] wrong bpf kernel msg type: {%d}.\n", msg->bpf_code);
        return;
    }
    printk(KERN_INFO "[dpa_netlink] recv bpf msg, type: {%d}.\n", msg->bpf_code);
    int ret = 0;
    // 对收到的消息去头，只传输body
    char *send_msg = (char *)((void *)msg + HED_LEN);
    ret = booster_dpa_request_async(
            BPF_MAP_OP, msg->bpf_code, send_msg, sizeof(struct bpf_msg_2_knl) - HED_LEN);
    if (ret < 0) {
        printk(KERN_ERR "[dpa_netlink] fail to send dpa sync netlink msg: {%d}", msg->bpf_code);
        return;
    }
}

/*
 * Netlink socket's callback function,it will be called by system when
 * user space send a message to kernel.
 * this function will process message from user space.
 * @arg1: socket buffer
 * Return: no
 */
static void kernel_dpa_receive(struct sk_buff *skb_recv)
{
    struct nlmsghdr *nlh = NULL;
    struct sk_buff *skb = NULL;
    if (skb_recv == NULL) {
        printk(KERN_ERR "Invalid parameter: zero pointer reference(skb_recv)\n");
        return;
    }
    skb = skb_get(skb_recv);
    if (skb == NULL) {
        printk(KERN_ERR "%s: skb = NULL\n", __func__);
        return;
    }
    mutex_lock(&dpa_receive_sem);
    if (skb->len >= NLMSG_HDRLEN) {
        nlh = nlmsg_hdr(skb);
        if (nlh == NULL) {
            printk("%s: nlh = NULL\n", __func__);
            kfree_skb(skb);
            mutex_unlock(&dpa_receive_sem);
            return;
        }
        if ((nlh->nlmsg_len >= sizeof(struct nlmsghdr)) && (skb->len >= nlh->nlmsg_len)) {
            if (nlh->nlmsg_type == NETLINK_BPF_REG) {
                /*
                 * Save user space progress pid when register netlink socket.
                 */
                g_user_space_pid = nlh->nlmsg_pid;
                printk(KERN_INFO "[dpa_netlink] recv pid.\n");
            } else if (nlh->nlmsg_type == NETLINK_BPF_TO_KER_MSG && nlh->nlmsg_len >= sizeof(struct bpf_msg_2_knl)) {
                process_bpf_msg((struct bpf_msg_2_knl *)nlh);
            } else {
                printk(KERN_ERR "[dpa_netlink] wrong netlink msg format, parse fail!\n");
            }
        } else {
            printk(KERN_ERR "[dpa_netlink] recv msg is illegal, nlmsg len: {%d}, skb len: {%d}, expect msg len: {%d}",
                nlh->nlmsg_len,
                skb->len,
                (int)sizeof(struct nlmsghdr));
        }
    } else {
        printk(KERN_ERR "[dpa_netlink] wrong skb len: {%d}, expect len:{%d}", skb->len, NLMSG_HDRLEN);
    }
    kfree_skb(skb);
    mutex_unlock(&dpa_receive_sem);
}

static void bpf_netlink_init(void)
{
    struct netlink_kernel_cfg dpa_nl_cfg = {
        .input = kernel_dpa_receive,
    };

    g_dpa_nlfd = netlink_kernel_create(&init_net, NETLINK_DPA_BPF, &dpa_nl_cfg);
    if (!g_dpa_nlfd) {
        printk("%s: failed\n", __func__);
    } else {
        printk("%s: success\n", __func__);
    }
}

int  bpf_dpa_netlink_module_init(void)
{
    bpf_netlink_init();
    if (!g_dpa_nlfd) {
        return -1;
    }
    g_dpa_module_state = BPF_NETLINK_INIT;
    return 0;
}
