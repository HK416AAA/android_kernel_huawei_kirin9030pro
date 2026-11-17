#include <bsp_dpa_client.h>
#include "client.h"
#include "packer_helper.h"
#include "id.h"

int dpa_add_static_arp_entry(int idx, unsigned int ip_addr, struct eth_addr *mac_addr, int is_notif)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));
    packer_begin(&packer, SERVICE_PROTO_ENTRY, ADD_STATIC_ARP_ENTRY);

    packer_buffer_append_s32(&packer, idx);
    packer_buffer_append_u32(&packer, ip_addr);
    packer_buffer_append_array(&packer, (u8 *)mac_addr, sizeof(struct eth_addr));
    packer_buffer_append_s32(&packer, is_notif);

    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);
    return 0;
}
int dpa_del_static_arp_entry(unsigned int addr)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));
    packer_begin(&packer, SERVICE_PROTO_ENTRY, DEL_STATIC_ARP_ENTRY);

    packer_buffer_append_u32(&packer, addr);

    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);
    return 0;
}
int dpa_add_static_nd6_entry(const ip6_addr_t *ip_addr, struct eth_addr *mac_addr)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));
    packer_begin(&packer, SERVICE_PROTO_ENTRY, ADD_STATIC_ND6_ENTRY);

    packer_buffer_append_array(&packer, (u8 *)ip_addr, sizeof(const ip6_addr_t));
    packer_buffer_append_array(&packer, (u8 *)mac_addr, sizeof(struct eth_addr));

    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);
    return 0;
}
int dpa_del_static_nd6_entry(const ip6_addr_t *ip_addr)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));
    packer_begin(&packer, SERVICE_PROTO_ENTRY, DEL_STATIC_ND6_ENTRY);

    packer_buffer_append_array(&packer, (u8 *)ip_addr, sizeof(const ip6_addr_t));

    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);
    return 0;
}

void dpa_etharp_register_notifier(void *notif_cb)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));
    packer_begin(&packer, SERVICE_PROTO_ENTRY, ETHARP_REGISTER_NOTIFIER);

    packer_buffer_append_ptr(&packer, notif_cb);

    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);
    return;
}

void dpa_nd6_register_notifier(void *notif_cb)
{
    unsigned char data[64];
    PACKER_BUFFER(packer, data, sizeof(data));
    packer_begin(&packer, SERVICE_PROTO_ENTRY, ND6_REGISTER_NOTIFIER);

    packer_buffer_append_ptr(&packer, notif_cb);

    packer_end(&packer);
    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);
    return;
}
