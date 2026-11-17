#ifndef PACKER_NETDEV_H
#define PACKER_NETDEV_H
#include "packer.h"
#include "client.h"

void pack_config_netdev(struct packer_buffer *packer, int idx, unsigned int mtu);
void unpack_config_netdev(struct packer_buffer *packer, int *idx, unsigned int *mtu);
void packer_netdev_add(struct packer_buffer *packer, struct eth_addr *mac, int is_no_arp);
void unpacker_netdev_add(struct packer_buffer *packer, struct eth_addr *mac, int *is_no_arp);
void packer_netdev_remove(struct packer_buffer *packer, int idx);
void unpacker_netdev_remove(struct packer_buffer *packer, int *idx);
void packer_netdev_update(struct packer_buffer *packer, int idx, int is_no_arp);
void unpacker_netdev_update(struct packer_buffer *packer, int *idx, int *is_no_arp);
void packer_netdev_cfg_ip4addr(struct packer_buffer *packer, int idx, unsigned int local, unsigned int mask);
void unpacker_netdev_cfg_ip4addr(struct packer_buffer *packer, int *idx, unsigned int *local, unsigned int *mask);

#endif