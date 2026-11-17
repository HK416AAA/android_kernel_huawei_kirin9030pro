#include "packer_netdev.h"
#include "packer.h"

void pack_config_netdev(struct packer_buffer *packer, int idx, unsigned int mtu)
{
    packer_buffer_append_s32(packer, idx);
    packer_buffer_append_u32(packer, mtu);
}

void unpack_config_netdev(struct packer_buffer *packer, int *idx, unsigned int *mtu)
{
    packer_buffer_pop_s32(packer, idx);
    packer_buffer_pop_u32(packer, mtu);
}

void packer_netdev_add(struct packer_buffer *packer, struct eth_addr *mac, int is_no_arp)
{
    packer_buffer_append_array(packer, (unsigned char *)mac, sizeof(struct eth_addr));
    packer_buffer_append_s32(packer, is_no_arp);
}

void unpacker_netdev_add(struct packer_buffer *packer, struct eth_addr *mac, int *is_no_arp)
{
    packer_buffer_pop_array(packer, (unsigned char *)mac, sizeof(struct eth_addr));
    packer_buffer_pop_s32(packer, is_no_arp);
}

void packer_netdev_remove(struct packer_buffer *packer, int idx)
{
    packer_buffer_append_s32(packer, idx);
}

void unpacker_netdev_remove(struct packer_buffer *packer, int *idx)
{
    packer_buffer_pop_s32(packer, idx);
}

void packer_netdev_update(struct packer_buffer *packer, int idx, int is_no_arp)
{
    packer_buffer_append_s32(packer, idx);
    packer_buffer_append_s32(packer, is_no_arp);
}

void unpacker_netdev_update(struct packer_buffer *packer, int *idx, int *is_no_arp)
{
    packer_buffer_pop_s32(packer, idx);
    packer_buffer_pop_s32(packer, is_no_arp);
}

void packer_netdev_cfg_ip4addr(struct packer_buffer *packer, int idx, unsigned int local, unsigned int mask)
{
    packer_buffer_append_s32(packer, idx);
    packer_buffer_append_u32(packer, local);
    packer_buffer_append_u32(packer, mask);
}

void unpacker_netdev_cfg_ip4addr(struct packer_buffer *packer, int *idx, unsigned int *local, unsigned int *mask)
{
    packer_buffer_pop_s32(packer, idx);
    packer_buffer_pop_u32(packer, local);
    packer_buffer_pop_u32(packer, mask);
}