#include <bsp_dpa_client.h>
#include "client.h"
#include "packer_helper.h"
#include "packer_netdev.h"
#include "id.h"

struct request_reply {
    struct semaphore *sema;
    unsigned char *data;
    unsigned int len;
};

static void dpa_sock_request_return_cb(void *priv, unsigned char *data, unsigned int len)
{
    struct request_reply *reply = (struct request_reply *)priv;
    PACKER_BUFFER(packer, data, len);
    packer_buffer_pop_s32(&packer, (int *)reply->data);
    reply->len = len;
    up(reply->sema);
}

int dpa_config_netdev(int idx, int mtu)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));

    int ret;
    DEFINE_SEMAPHORE(sema);
    struct request_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };
    sema_init(&sema, 0);

    packer_begin_callback(&packer, SERVICE_PROTO_NETDEV, NETDEV_CONFIG, dpa_sock_request_return_cb, &reply);
    pack_config_netdev(&packer, idx, mtu);
    packer_end(&packer);

    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);
    down(&sema);

    return ret;
}

int dpa_netdev_add(struct eth_addr *mac, int is_no_arp)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));

    int ret;
    DEFINE_SEMAPHORE(sema);
    struct request_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };
    sema_init(&sema, 0);

    packer_begin_callback(&packer, SERVICE_PROTO_NETDEV, NETDEV_ADD, dpa_sock_request_return_cb, &reply);
    packer_netdev_add(&packer, mac, is_no_arp);
    packer_end(&packer);

    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);
    down(&sema);

    return ret;
}

int dpa_netdev_remove(int idx)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));

    int ret;
    DEFINE_SEMAPHORE(sema);
    struct request_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };
    sema_init(&sema, 0);

    packer_begin_callback(&packer, SERVICE_PROTO_NETDEV, NETDEV_REMOVE, dpa_sock_request_return_cb, &reply);

    packer_netdev_remove(&packer, idx);

    packer_end(&packer);
    ret = bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);
    if (ret) {
        printk("dpa_client_request failed: %d\n", ret);
        return ret;
    }
    down(&sema);

    return ret;
}
int dpa_netdev_update(int idx, int is_no_arp)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));
    packer_begin(&packer, SERVICE_PROTO_NETDEV, NETDEV_UPDATE);

    packer_netdev_update(&packer, idx, is_no_arp);

    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);
    return 0;
}
int dpa_netdev_cfg_ip4addr(int idx, unsigned int local, unsigned int mask)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));
    packer_begin(&packer, SERVICE_PROTO_NETDEV, NETDEV_CFG_IP4ADDR);

    packer_netdev_cfg_ip4addr(&packer, idx, local, mask);

    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);
    return 0;
}
