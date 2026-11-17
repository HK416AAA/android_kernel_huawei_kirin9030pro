#ifndef DPA_RESOLVE_NEIGH_H
#define DPA_RESOLVE_NEIGH_H

#include <net/ip.h>
#include <net/ipv6.h>
#include <net/addrconf.h>
#include <net/route.h>
#include <net/ip6_route.h>
#include <net/flow.h>
#include <linux/netdevice.h>

struct net_device *dpa_addr4_resolve(struct sockaddr_in *src_in, struct sockaddr_in *dst_in, u8 *dst_mac);
struct net_device *dpa_addr6_resolve(struct sockaddr_in6 *src_in, struct sockaddr_in6 *dst_in, u8 *dst_mac);
#endif