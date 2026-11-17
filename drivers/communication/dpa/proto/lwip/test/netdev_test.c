#include <linux/module.h>
#include <linux/kernel.h>
#include "client.h"

int test_dpa_config_netdev() {
    int idx = 38;
    int mtu = 1500;
    int ret = dpa_config_netdev(idx, mtu);
    if (ret != 0) {
        printk("dpa_config_netdev failed with error %d\n", ret);
    }
    return ret;
}

int test_dpa_netdev_add() {
    struct eth_addr mac = {
        {192, 168, 1, 1, 1, 1}
    };
    int is_no_arp = 1;
    int ret = dpa_netdev_add(&mac, is_no_arp);
    if (ret != 0) {
        printk("dpa_netdev_add failed with error %d\n", ret);
    }
    return ret;
}

int test_dpa_netdev_remove() {
    int idx = 38;
    int ret = dpa_netdev_remove(idx);
    if (ret != 0) {
        printk("dpa_netdev_remove failed with error %d\n", ret);
    }
    return ret;
}

int test_netdev_update() {
    int idx = 38;
    int is_no_arp = 0;
    int ret = dpa_netdev_update(idx, is_no_arp);
    if (ret != 0) {
        printk("dpa_netdev_update failed with error %d\n", ret);
    }
    return ret;
}

int test_netdev_cfg_ip4addr() {
    int idx = 38;
    unsigned int local = 0x0a000101; // 192.168.1.1
    unsigned int mask = 0xffffff00; // 255.255.
    int ret = dpa_netdev_cfg_ip4addr(idx, local, mask);
    if (ret != 0) {
        printk("dpa_netdev_cfg_ip4addr failed with error %d\n", ret);
        return ret;
    }
    return ret;
}