#include "dpa_resolve_neigh.h"

struct socket_dev_addr {
    unsigned char src_dev_addr[MAX_ADDR_LEN];
    unsigned char dst_dev_addr[MAX_ADDR_LEN];
    unsigned int ifdex;
    unsigned int socketidx;
    struct socket
        *sock; /*指向socket地址，可以构造一个数组，建立一个socket数组表，可以sne表项的userfield 带上socketidx*/
};

struct net_device *dpa_addr4_resolve(struct sockaddr_in *src_in, struct sockaddr_in *dst_in, u8 *dst_mac)
{
    __be32 src_ip = 0;
    __be32 dst_ip = dst_in->sin_addr.s_addr;
    struct neighbour *neigh = NULL;
    struct net_device *dev = NULL;
    struct rtable *rt = NULL;

    rt = ip_route_output(&init_net, dst_ip, src_ip, 0, 0);
    if (IS_ERR(rt)) {
        printk("ip_route_output returned error\n");
        return NULL;
    }

    neigh = dst_neigh_lookup(&rt->dst, &dst_ip);

    if (neigh) {
        rcu_read_lock();
        if (!(neigh->nud_state & NUD_VALID)) {
            neigh_event_send(neigh, NULL);
        }
        ether_addr_copy(dst_mac, neigh->ha);
        printk("mac_addr=[%pM]\n", dst_mac);
        rcu_read_unlock();
        neigh_release(neigh);
    }
    dev = rt->dst.dev;
    ip_rt_put(rt);
    return dev;
}

struct net_device *dpa_addr6_resolve(struct sockaddr_in6 *src_in, struct sockaddr_in6 *dst_in, u8 *dst_mac)
{
    struct neighbour *neigh = NULL;
    struct dst_entry *dst;
    struct net_device *dev;
    struct flowi6 fl6;

    memset(&fl6, 0, sizeof(fl6));
    fl6.daddr = dst_in->sin6_addr;

    dst = ip6_route_output(&init_net, NULL, &fl6);

    if ((!dst) || dst->error) {
        if (dst) {
            printk("ip6_route_output returned dst->error = %d\n", dst->error);
            dst_release(dst);
        }
        return NULL;
    }
    neigh = dst_neigh_lookup(dst, &fl6.daddr);
    if (neigh) {
        rcu_read_lock();
        if (!(neigh->nud_state & NUD_VALID)) {
            neigh_event_send(neigh, NULL);
        }
        ether_addr_copy(dst_mac, neigh->ha);
        printk("dpa_lwip neighbor mac_addr=[%pM]\n", dst_mac);
        rcu_read_unlock();
        neigh_release(neigh);
    }
    dev = dst->dev;

    dst_release(dst);

    return dev;
}

int dpa_test_neigh(void)
{
    int ret = 0;
    struct sockaddr_in ip4_src_sin;
    struct sockaddr_in ip4_dst_sin;
    struct sockaddr_in6 ip6_src_sin;
    struct sockaddr_in6 ip6_dst_sin;
    u8 dst_mac[16];
    struct net_device *dev;

    dev = dpa_addr4_resolve(&ip4_src_sin, &ip4_dst_sin, dst_mac);
    dev = dpa_addr6_resolve(&ip6_src_sin, &ip6_dst_sin, dst_mac);
    return ret;
}
