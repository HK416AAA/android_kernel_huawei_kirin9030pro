
#include <linux/kernel.h>
#include <linux/netdevice.h>
#include <linux/inetdevice.h>
#include <net/net_namespace.h>
#include <bsp_net_om.h>
#include <bsp_print.h>
#include "dpa_linux_sock.h"
#include "dpa_netdev_mng.h"
#include "dpa_resolve_neigh.h"
#include "client.h"

struct lwip_stats_s {
    void *stats;
    int len;
    struct net_om_info report_info;
};
struct lwip_stats_s g_lwip_stats;

#define NETIF_MAX_LDEV_NUM 256 /* max linux net dev num */
#define NETIF_IFIDX_MIN 2

static unsigned char g_dpa_ldev_map[NETIF_MAX_LDEV_NUM] = { 0 };

#define DPA_NETDEV_IDX_VALID(idx) ((idx) != 0xFF)

/* convert from linux ifindex to dpa netdev index */
int dpa_netdev_get_by_ifindex(int ifindex)
{
    unsigned char idx;

    if (ifindex < 0 || ifindex >= NETIF_MAX_LDEV_NUM) {
        return -1;
    }
    idx = g_dpa_ldev_map[ifindex];
    return (int)idx;
}

static inline int dpa_netdev_set_by_ifindex(int ifindex, unsigned char netdev_idx)
{
    if (ifindex < 0 || ifindex >= NETIF_MAX_LDEV_NUM) {
        return -1;
    }
    g_dpa_ldev_map[ifindex] = netdev_idx;
    return 0;
}

static inline void dpa_netdev_clear_by_ifindex(int ifindex)
{
    if (ifindex < 0 || ifindex >= NETIF_MAX_LDEV_NUM) {
        return;
    }
    g_dpa_ldev_map[ifindex] = 0xFF;
    return;
}

int dpa_netdev_add_dev_safely(struct net_device *ndev)
{
    int idx;
    int ret;
    int is_no_arp = 0;

    if (ndev->flags & IFF_NOARP) {
        is_no_arp = 1;
    }

    idx = dpa_netdev_get_by_ifindex(ndev->ifindex);
    if (DPA_NETDEV_IDX_VALID(idx)) {
        dpa_netdev_update(idx, is_no_arp);
        return idx;
    }

    idx = dpa_netdev_add((struct eth_addr *)ndev->dev_addr, is_no_arp);
    if (idx < 0) {
        printk("dpa_netdev_add for:%s fail\n", ndev->name);
        return -1;
    }

    ret = dpa_netdev_set_by_ifindex(ndev->ifindex, idx);
    if (ret < 0) {
        printk("dpa_netdev_add set_by_ifindex for:%s, idx:%d fail\n", ndev->name, idx);
        return -1;
    }

    return idx;
}

static int dpa_netdev_device_event_handler(struct notifier_block *this, unsigned long event, void *ptr)
{
    struct net_device *dev = netdev_notifier_info_to_dev(ptr);
    int ret;
    int idx;

    /* excludes netdev: lo and dummy0 */
    if (dev == NULL || dev->ifindex <= NETIF_IFIDX_MIN) {
        return NOTIFY_DONE;
    }

    if (event == NETDEV_UP) {
        ret = dpa_netdev_add_dev_safely(dev);
        if (ret < 0) {
            printk("dpa_netdev_add_dev_safely:%s, idx:%d fail\n", dev->name, ret);
        }
        printk("dpa_netdev add dev name:%s, ifindex:%d, idx:%d succ\n", dev->name, dev->ifindex, ret);
    }
    if (event == NETDEV_DOWN) {
        idx = dpa_netdev_get_by_ifindex(dev->ifindex);
        ret = dpa_netdev_remove(idx);
        if (ret < 0) {
            printk("dpa_netdev_remove for:%s fail\n", dev->name);
        }
        dpa_netdev_clear_by_ifindex(dev->ifindex);
        printk("dpa_netdev remove dev name:%s, ifindex:%d, idx:%d succ\n", dev->name, dev->ifindex, idx);
    }
    return NOTIFY_DONE;
}

static struct notifier_block dpa_netdev_notifier = {
    .notifier_call = dpa_netdev_device_event_handler,
};

/* ipv4 address setting notifer handler */
static int dpa_netdev_inetaddr_event_handler(struct notifier_block *this, unsigned long event, void *ptr)
{
    struct in_ifaddr *ifa = (struct in_ifaddr *)ptr;
    struct in_device *in_dev;
    struct net_device *net_dev;

    if (ifa == NULL) {
        return NOTIFY_DONE;
    }

    in_dev = ifa->ifa_dev;
    if (in_dev == NULL || in_dev->dev == NULL) {
        return NOTIFY_DONE;
    }
    net_dev = in_dev->dev;

    /* excludes netdev: lo and dummy0 */
    if (net_dev->ifindex <= NETIF_IFIDX_MIN) {
        return NOTIFY_DONE;
    }

    if (event == NETDEV_UP) {
        int ret;
        int idx;

        idx = dpa_netdev_add_dev_safely(net_dev);
        ret = dpa_netdev_cfg_ip4addr(idx, ifa->ifa_local, ifa->ifa_mask);
        if (ret) {
            printk("dpa_netdev_cfg_ip4addr for:%s fail\n", net_dev->name);
        }
        printk("dpa_netdev cfg ip4addr dev name:%s, ifindex:%d, idx:%d succ\n", net_dev->name, net_dev->ifindex, idx);
    }

    return NOTIFY_DONE;
}

static struct notifier_block dpa_inetaddr_notifier = {
    .notifier_call = dpa_netdev_inetaddr_event_handler,
};

void dpa_sock_arp_notifier(unsigned int ipv4)
{
    struct net_device *linux_netdev;
    struct sockaddr_in remote_addr4;
    char resolv_mac[ETH_ALEN];
    int ret;
    int idx;

    printk("dpa_sock_arp_notifier start\n");

    remote_addr4.sin_family = AF_INET;
    remote_addr4.sin_port = 0;
    remote_addr4.sin_addr.s_addr = ipv4;
    linux_netdev = dpa_addr4_resolve(NULL, &remote_addr4, resolv_mac);
    if (linux_netdev == NULL) {
        printk("dpa_sock_arp_notifier: dpa_addr4_resolve fail\n");
        return;
    }

    idx = dpa_netdev_get_by_ifindex(linux_netdev->ifindex);
    ret = dpa_add_static_arp_entry(idx, ipv4, (struct eth_addr *)resolv_mac, 1);
    if (ret) {
        printk("dpa_sock_arp_notifier: dpa_add_static_arp_entry error:%d\n", ret);
        return;
    }
    return;
}

void dpa_sock_nd6_notifier(ip6_addr_t *ip6addr)
{
    struct net_device *linux_netdev;
    struct sockaddr_in6 remote_addr6;
    char resolv_mac[ETH_ALEN];
    int ret;

    printk("dpa_sock_nd6_notifier start\n");

    remote_addr6.sin6_family = AF_INET;
    remote_addr6.sin6_port = 0;
    memcpy(&(remote_addr6.sin6_addr), ip6addr->addr, sizeof(remote_addr6.sin6_addr));
    linux_netdev = dpa_addr6_resolve(NULL, &remote_addr6, resolv_mac);
    if (linux_netdev == NULL) {
        printk("dpa_sock_nd6_notifier: dpa_addr4_resolve fail\n");
        return;
    }

    ret = dpa_add_static_nd6_entry(ip6addr, (struct eth_addr *)resolv_mac);
    if (ret) {
        printk("dpa_sock_nd6_notifier: dpa_add_static_nd6_entry error:%d\n", ret);
        return;
    }
    return;
}

void lwip_hds_transreport(void)
{
    // struct lwip_stats_s *om = &g_lwip_stats;
    // om->len = dpa_lwip_getstatslen();
    // dpa_lwip_getstats(&om->stats);
}

void dpa_trans_report_register(void)
{
    // struct lwip_stats_s *om = &g_lwip_stats;
    // struct net_om_info *info = &om->report_info;
    // int ret;

    // info->ul_msg_id = NET_OM_MSGID_DPA;
    // info->data = (void *)&om->stats;
    // info->size = dpa_lwip_getstatslen();
    // info->func_cb = lwip_hds_transreport;
    // INIT_LIST_HEAD(&info->list);

    // ret = bsp_net_report_register(info);
    // if (ret) {
    //     LWIP_PLATFORM_DIAG(("trans report register fail\n"));
    // }
}

int dpa_netdev_event_init(void)
{
    int ret;

    memset(g_dpa_ldev_map, 0xFF, sizeof(g_dpa_ldev_map));
    ret = register_netdevice_notifier(&dpa_netdev_notifier);
    if (ret) {
        printk("dpa_netdev register_netdevice_notifier error\n");
    }
    ret = register_inetaddr_notifier(&dpa_inetaddr_notifier);
    if (ret) {
        printk("dpa_netdev register_inetaddr_notifier error\n");
    }
    //dpa_trans_report_register();
    dpa_etharp_register_notifier((void *)dpa_sock_arp_notifier);
    dpa_nd6_register_notifier((void *)dpa_sock_nd6_notifier);

    printk("dpa_netdev_event_init ok\n");
    return ret;
}
