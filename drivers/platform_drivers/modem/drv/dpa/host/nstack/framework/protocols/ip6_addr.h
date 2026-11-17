/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#ifndef SPL_IP6_ADDR_H
#define SPL_IP6_ADDR_H

#include "stack_types.h"
#include "dmm_common.h"
#include "def.h"
#include "securec.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SPL_IPV6_U32_ARRAY_LENGTH 4

#pragma pack(4)
typedef struct spl_ip6_addr {
    u32 addr[SPL_IPV6_U32_ARRAY_LENGTH];
    u8 zone;  // scope zone index
} spl_ip6_addr_t;
#pragma pack()

struct spl_in6_addr {
    union {
        u8 u6_addr8[16];
        u16 u6_addr16[8];
        u32 u6_addr32[4];
    } in6_u;
#define s6_addr in6_u.u6_addr8
#define s6_addr16 in6_u.u6_addr16
#define s6_addr32 in6_u.u6_addr32
};

struct spl_in6_pktinfo {
    struct spl_in6_addr    ipi6_addr;
    int        ipi6_ifindex;
};

struct spl_sockaddr_in6 {
    unsigned short int sin6_family;
    u16 sin6_port;
    u32 sin6_flowinfo;
    struct spl_in6_addr sin6_addr;
    u32 sin6_scope_id;
};

#define SPL_IPV6_U32_BITS 32
#define SPL_IPV6_MAX_MASK_LEN 128
#define SPL_IPV6_DEFAULT_PREFIX_LENGTH 64
#define SPL_IP6_ADDRESS_STRING_LENGTH 128

#define SPL_IP6_ADDR6_INIT(a, b, c, d) \
    {                                  \
        { (a), (b), (c), (d) }, 0      \
    }

static inline void spl_ip6_addr_set_val(spl_ip6_addr_t *addr, const u32 *val)
{
    (void)memcpy_s(addr->addr, sizeof(addr->addr), val, sizeof(addr->addr));
    addr->zone = 0;
}

#define SPL_IP6_ADDR_ANY_VAL SPL_IP6_ADDR6_INIT(0UL, 0UL, 0UL, 0UL)

static const spl_ip6_addr_t g_spl_ip6_addr_any = SPL_IP6_ADDR_ANY_VAL;

#define SPL_IP6_ADDR_ANY (&g_spl_ip6_addr_any)

#define SPL_IP6_NO_ZONE 0

#define spl_ip6_addr_clear_zone(_spl_ip6_addr) ((_spl_ip6_addr)->zone = SPL_IP6_NO_ZONE)

#define spl_ip6_addr_copy_zone(_spl_ip6_addr_dest, _spl_ip6_addr_src) \
    ((_spl_ip6_addr_dest)->zone = (_spl_ip6_addr_src)->zone)

#define spl_ip6_addr_copy(_spl_ip6_addr_dest, _spl_ip6_addr_src) do { \
    (_spl_ip6_addr_dest)->addr[0] = (_spl_ip6_addr_src)->addr[0];      \
    (_spl_ip6_addr_dest)->addr[1] = (_spl_ip6_addr_src)->addr[1];      \
    (_spl_ip6_addr_dest)->addr[2] = (_spl_ip6_addr_src)->addr[2];      \
    (_spl_ip6_addr_dest)->addr[3] = (_spl_ip6_addr_src)->addr[3];      \
    spl_ip6_addr_copy_zone((_spl_ip6_addr_dest), (_spl_ip6_addr_src)); \
} while (false)

#define spl_ip6_addr_set_zero(_spl_ip6_addr) do { \
    (_spl_ip6_addr)->addr[0] = 0;           \
    (_spl_ip6_addr)->addr[1] = 0;           \
    (_spl_ip6_addr)->addr[2] = 0;           \
    (_spl_ip6_addr)->addr[3] = 0;           \
    spl_ip6_addr_clear_zone(_spl_ip6_addr); \
} while (false)
#define spl_ip6_addr_set_any(_spl_ip6_addr) spl_ip6_addr_set_zero(_spl_ip6_addr)

#define spl_ip6_addr_is_zero(addr) (((addr)[0] == 0U) && ((addr)[1] == 0U) && ((addr)[2] == 0U) && ((addr)[3] == 0U))

#define spl_ip6_addr_set_loopback(_spl_ip6_addr) do { \
    (_spl_ip6_addr)->addr[0] = 0;           \
    (_spl_ip6_addr)->addr[1] = 0;           \
    (_spl_ip6_addr)->addr[2] = 0;           \
    (_spl_ip6_addr)->addr[3] = spl_htonl(0x00000001UL); \
    spl_ip6_addr_clear_zone(_spl_ip6_addr); \
} while (false)

static inline bool spl_ip6_addr_is_any(const spl_ip6_addr_t *ip6addr)
{
    if (ip6addr == NULL) {
        return true;
    }

    return ((ip6addr->addr[0] == 0U) && (ip6addr->addr[1] == 0U) &&
        (ip6addr->addr[2] == 0U) && (ip6addr->addr[3] == 0U));
}

#define spl_ip6_addr_cmp_zoneless(_spl_ip6_addr1, _spl_ip6_addr2) \
    (((_spl_ip6_addr1)->addr[0] == (_spl_ip6_addr2)->addr[0]) &&  \
     ((_spl_ip6_addr1)->addr[1] == (_spl_ip6_addr2)->addr[1]) &&  \
     ((_spl_ip6_addr1)->addr[2] == (_spl_ip6_addr2)->addr[2]) &&  \
     ((_spl_ip6_addr1)->addr[3] == (_spl_ip6_addr2)->addr[3]))

#define spl_ip6_addr_cmp_zone(_spl_ip6_addr1, _spl_ip6_addr2) ((_spl_ip6_addr1)->zone == (_spl_ip6_addr2)->zone)

#define spl_ip6_addr_cmp(_spl_ip6_addr_1, _spl_ip6_addr_2)              \
    (spl_ip6_addr_cmp_zoneless((_spl_ip6_addr_1), (_spl_ip6_addr_2)) && \
     spl_ip6_addr_cmp_zone((_spl_ip6_addr_1), (_spl_ip6_addr_2)))

#define ip6_addr_cmp_packed(ip6addr, paddr, zone_idx)                                        \
    (((ip6addr)->addr[0] == (paddr)->addr[0]) && ((ip6addr)->addr[1] == (paddr)->addr[1]) && \
     ((ip6addr)->addr[2] == (paddr)->addr[2]) && ((ip6addr)->addr[3] == (paddr)->addr[3]) && \
     ip6_addr_equals_zone((ip6addr), (zone_idx)))

static inline void spl_ip6_addr_cast_from_in6addr(spl_ip6_addr_t *ip6_addr, const struct spl_in6_addr *sin6_addr)
{
    (void)memcpy_s(ip6_addr->addr, sizeof(ip6_addr->addr), sin6_addr->s6_addr32, sizeof(sin6_addr->s6_addr32));
    spl_ip6_addr_clear_zone(ip6_addr);
}

#define spl_ip6_addr_cast_from_sockaddr_in6(_spl_ip6_addr, _sockaddr_in6) \
    spl_ip6_addr_cast_from_in6addr(_spl_ip6_addr, &((_sockaddr_in6)->sin6_addr))

#define spl_ip6_addr_set_solicitednode(_spl_ip6_addr1, if_id) do { \
    (_spl_ip6_addr1)->addr[0] = spl_htonl(0xff020000UL);             \
    (_spl_ip6_addr1)->addr[1] = 0;                                  \
    (_spl_ip6_addr1)->addr[2] = spl_htonl(0x00000001UL);             \
    (_spl_ip6_addr1)->addr[3] = (spl_htonl(0xff000000UL) | (if_id)); \
    spl_ip6_addr_clear_zone(_spl_ip6_addr1);                        \
} while (false)

static inline bool ip6_addr_isloopback(const spl_ip6_addr_t *addr)
{
    return ((addr->addr[0] == 0UL) && (addr->addr[1] == 0UL) &&
        (addr->addr[2] == 0UL) && (addr->addr[3] == spl_htonl(0x00000001UL)));
}

#define ip6_addr_isglobal(_spl_ip6_addr1) \
    (((_spl_ip6_addr1)->addr[0] & spl_htonl(0xe0000000UL)) == spl_htonl(0x20000000UL))

#define ip6_addr_islinklocal(_spl_ip6_addr1) \
    (((_spl_ip6_addr1)->addr[0] & spl_htonl(0xffc00000UL)) == spl_htonl(0xfe800000UL))

#define ip6_addr_issitelocal(_spl_ip6_addr1) \
    (((_spl_ip6_addr1)->addr[0] & spl_htonl(0xffc00000UL)) == spl_htonl(0xfec00000UL))

#define ip6_addr_isuniquelocal(_spl_ip6_addr1) \
    (((_spl_ip6_addr1)->addr[0] & spl_htonl(0xfe000000UL)) == spl_htonl(0xfc000000UL))

#define ip6_addr_isipv4mappedipv6(_spl_ip6_addr1)                                              \
    (((_spl_ip6_addr1)->addr[0] == 0) && ((_spl_ip6_addr1)->addr[1] == 0) && \
     (((_spl_ip6_addr1)->addr[2]) == spl_htonl(0x0000FFFFUL)))

#define spl_ip6_addr_ismulticast(_spl_ip6_addr1) \
    (((_spl_ip6_addr1)->addr[0] & spl_htonl(0xff000000UL)) == spl_htonl(0xff000000UL))
#define ip6_addr_multicast_transient_flag(_spl_ip6_addr1) ((_spl_ip6_addr1)->addr[0] & spl_htonl(0x00100000UL))
#define ip6_addr_multicast_prefix_flag(_spl_ip6_addr1) ((_spl_ip6_addr1)->addr[0] & spl_htonl(0x00200000UL))
#define ip6_addr_multicast_rendezvous_flag(_spl_ip6_addr1) ((_spl_ip6_addr1)->addr[0] & spl_htonl(0x00400000UL))
#define ip6_addr_multicast_scope(_spl_ip6_addr1) ((spl_htonl((_spl_ip6_addr1)->addr[0]) >> 16) & 0xf)

#define SPL_IP6_MULTICAST_SCOPE_RESERVED 0x0
#define SPL_IP6_MULTICAST_SCOPE_INTERFACE_LOCAL 0x1
#define SPL_IP6_MULTICAST_SCOPE_LINK_LOCAL 0x2
#define SPL_IP6_MULTICAST_SCOPE_ADMIN_LOCAL 0x4
#define SPL_IP6_MULTICAST_SCOPE_SITE_LOCAL 0x5
#define SPL_IP6_MULTICAST_SCOPE_ORGANIZATION_LOCAL 0x8
#define SPL_IP6_MULTICAST_SCOPE_GLOBAL 0xe
#define SPL_IP6_MULTICAST_SCOPE_F_RESERVED 0xf

#define ip6_addr_ismulticast_iflocal(_spl_ip6_addr1) \
    (((_spl_ip6_addr1)->addr[0] & spl_htonl(0xff8f0000UL)) == spl_htonl(0xff010000UL))
#define ip6_addr_ismulticast_linklocal(_spl_ip6_addr1) \
    (((_spl_ip6_addr1)->addr[0] & spl_htonl(0xff8f0000UL)) == spl_htonl(0xff020000UL))
#define ip6_addr_ismulticast_adminlocal(_spl_ip6_addr1) \
    (((_spl_ip6_addr1)->addr[0] & spl_htonl(0xff8f0000UL)) == spl_htonl(0xff040000UL))
#define ip6_addr_ismulticast_sitelocal(_spl_ip6_addr1) \
    (((_spl_ip6_addr1)->addr[0] & spl_htonl(0xff8f0000UL)) == spl_htonl(0xff050000UL))
#define ip6_addr_ismulticast_orglocal(_spl_ip6_addr1) \
    (((_spl_ip6_addr1)->addr[0] & spl_htonl(0xff8f0000UL)) == spl_htonl(0xff080000UL))
#define ip6_addr_ismulticast_global(_spl_ip6_addr1) \
    (((_spl_ip6_addr1)->addr[0] & spl_htonl(0xff8f0000UL)) == spl_htonl(0xff0e0000UL))

#define IP6_NO_ZONE 0

#define ip6_addr_zone(ip6addr) ((ip6addr)->zone)

#define ip6_addr_has_zone(ip6addr) (ip6_addr_zone(ip6addr) != IP6_NO_ZONE)

#define ip6_addr_set_zone(ip6addr, zone_idx) ((ip6addr)->zone = (zone_idx))

#define ip6_addr_clear_zone(ip6addr) ((ip6addr)->zone = IP6_NO_ZONE)

#define ip6_addr_copy_zone(ip6addr1, ip6addr2) ((ip6addr1).zone = (ip6addr2).zone)

#define ip6_addr_equals_zone(ip6addr, zone_idx) ((ip6addr)->zone == (zone_idx))

#define ip6_addr_cmp_zone(ip6addr1, ip6addr2) ((ip6addr1)->zone == (ip6addr2)->zone)

#define SPL_IP6_ADDR(ip6addr, idx0, idx1, idx2, idx3) do { \
    (ip6addr)->addr[0] = idx0;                    \
    (ip6addr)->addr[1] = idx1;                    \
    (ip6addr)->addr[2] = idx2;                    \
    (ip6addr)->addr[3] = idx3;                    \
    ip6_addr_clear_zone(ip6addr);                 \
} while (0)

static __inline void ip6_addr_set_solicitednode(spl_ip6_addr_t *ip6addr, u32 if_id)
{
    SPL_IP6_ADDR(ip6addr, spl_htonl(0xff020000UL), 0, spl_htonl(0x00000001UL), (spl_htonl(0xff000000UL) | (if_id)));
}

static __inline void ip6_addr_set_mutlicast_v2(spl_ip6_addr_t *ip6addr)
{
    SPL_IP6_ADDR(ip6addr, spl_htonl(0xff020000UL), 0, 0, spl_htonl(0x00000016UL));
}

enum spl_ipv6_scope_type {
    IP6_UNKNOWN = 0,
    IP6_UNICAST = 1,
    IP6_MULTICAST = 2
};

#define ip6_addr_has_scope(_spl_ip6_addr, type)                                       \
    (ip6_addr_islinklocal(_spl_ip6_addr) ||                                           \
     (((type) != IP6_UNICAST) &&                                                      \
      (ip6_addr_ismulticast_iflocal(_spl_ip6_addr) || ip6_addr_ismulticast_linklocal(_spl_ip6_addr))))

#define ip6_addr_assign_zone(_spl_ip6_addr, type, zone_idx) \
    (ip6_addr_set_zone((_spl_ip6_addr), ip6_addr_has_scope((_spl_ip6_addr), (type)) ? (zone_idx) : 0))

#define ip6_addr_test_zone(_spl_ip6_addr, zone_idx) (ip6_addr_equals_zone((_spl_ip6_addr), zone_idx))

#define ip6_addr_lacks_zone(_spl_ip6_addr, type) \
    (!ip6_addr_has_zone(_spl_ip6_addr) && ip6_addr_has_scope((_spl_ip6_addr), (type)))

#define ip6_addr_isallnodes_iflocal(ip6addr)                                             \
    (((ip6addr)->addr[0] == spl_htonl(0xff010000UL)) && ((ip6addr)->addr[1] == 0UL) && \
     ((ip6addr)->addr[2] == 0UL) && ((ip6addr)->addr[3] == spl_htonl(0x00000001UL)))

/* the below part is for replacing scope and zone related macro in refactoring */
#define ip6_addr_is_link_local(ip6_addr) (((ip6_addr)->addr[0] & spl_htonl(0xffc00000UL)) == spl_htonl(0xfe800000UL))

#define ip6_addr_is_loopback(ip6_addr)                                                               \
    (((ip6_addr)->addr[0] == 0UL) && ((ip6_addr)->addr[1] == 0UL) && ((ip6_addr)->addr[2] == 0UL) && \
     ((ip6_addr)->addr[3] == spl_htonl(0x00000001UL)))

#define ip6_addr_is_multicast(ip6_addr) (((ip6_addr)->addr[0] & spl_htonl(0xff000000UL)) == spl_htonl(0xff000000UL))

#define ip6_addr_is_multicast_if_local(ip6_addr) \
    (((ip6_addr)->addr[0] & spl_htonl(0xff0f0000UL)) == spl_htonl(0xff010000UL))
#define ip6_addr_is_multicast_link_local(ip6_addr) \
    (((ip6_addr)->addr[0] & spl_htonl(0xff0f0000UL)) == spl_htonl(0xff020000UL))
#define ip6_addr_is_multicast_admin_local(ip6_addr) \
    (((ip6_addr)->addr[0] & spl_htonl(0xff0f0000UL)) == spl_htonl(0xff040000UL))
#define ip6_addr_is_multicast_site_local(ip6_addr) \
    (((ip6_addr)->addr[0] & spl_htonl(0xff0f0000UL)) == spl_htonl(0xff050000UL))
#define ip6_addr_is_multicast_org_local(ip6_addr) \
    (((ip6_addr)->addr[0] & spl_htonl(0xff0f0000UL)) == spl_htonl(0xff080000UL))
#define ip6_addr_is_multicast_global(ip6_addr) \
    (((ip6_addr)->addr[0] & spl_htonl(0xff0f0000UL)) == spl_htonl(0xff0e0000UL))

/* check an IPv6 address has scope except global scope, if has, then we can set zone to it */
#define new_ip6_addr_has_scope(ip6_addr) \
    (ip6_addr_is_link_local(ip6_addr) || (ip6_addr_is_multicast(ip6_addr) && !ip6_addr_is_multicast_global(ip6_addr)))

#define new_ip6_addr_set_zone(ip6addr, zone_idx) ((ip6addr)->zone = (zone_idx))

#define ip6_addr_get_zone(ip6addr) ((ip6addr)->zone)

#define ip6_addr_zone_matches(ip6_addr, zone_idx) ((ip6_addr)->zone == (zone_idx))

/* new macro end */
static __inline bool ip6_addr_isallnodes_linklocal(const spl_ip6_addr_t *ip6addr)
{
    return (((ip6addr)->addr[0] == spl_htonl(0xff020000UL)) && ((ip6addr)->addr[1] == 0UL) &&
            ((ip6addr)->addr[2] == 0UL) && ((ip6addr)->addr[3] == spl_htonl(0x00000001UL)));
}

static __inline void ip6_addr_set_allnodes_linklocal(spl_ip6_addr_t *ip6addr)
{
    SPL_IP6_ADDR(ip6addr, spl_htonl(0xff020000UL), 0, 0, spl_htonl(0x00000001UL));
}

static __inline void ip6_addr_set_allrouters_linklocal(spl_ip6_addr_t *ip6addr)
{
    SPL_IP6_ADDR(ip6addr, spl_htonl(0xff020000UL), 0, 0, spl_htonl(0x00000002UL));
}

#define ip6_addr_issolicitednode(ip6addr)                                \
    (((ip6addr)->addr[0] == spl_htonl(0xff020000UL)) &&                   \
     ((ip6addr)->addr[2] == spl_htonl(0x00000001UL)) &&                   \
     (((ip6addr)->addr[3] & spl_htonl(0xff000000UL)) == spl_htonl(0xff000000UL)))

#define ip6_addr_cmp_solicitednode(ip6addr, sn_addr)                                    \
    (((ip6addr)->addr[0] == spl_htonl(0xff020000UL)) && ((ip6addr)->addr[1] == 0) && \
     ((ip6addr)->addr[2] == spl_htonl(0x00000001UL)) &&                                  \
     ((ip6addr)->addr[3] == (spl_htonl(0xff000000UL) | (sn_addr)->addr[3])))

#define ip6_addr_netcmp_zoneless(addr1, addr2) \
    (((addr1)->addr[0] == (addr2)->addr[0]) && ((addr1)->addr[1] == (addr2)->addr[1]))

#define ip6_addr_nethostcmp(addr1, addr2) \
    (((addr1)->addr[2] == (addr2)->addr[2]) && ((addr1)->addr[3] == (addr2)->addr[3]))

#define ip6_addr_cmp_zoneless(addr1, addr2)                                              \
    (((addr1)->addr[0] == (addr2)->addr[0]) && ((addr1)->addr[1] == (addr2)->addr[1]) && \
     ((addr1)->addr[2] == (addr2)->addr[2]) && ((addr1)->addr[3] == (addr2)->addr[3]))

s32 spl_ip6_addr_aton(const char *ip_char, spl_ip6_addr_t *ip6addr);
char *spl_ip6_addr_ntoa_r(const spl_ip6_addr_t *ip6addr, char *buf, u32 buflen);
const char *ip6_fuzzy(const spl_ip6_addr_t *addr);
bool ip6_mask_matches(const spl_ip6_addr_t *ip6addr1, const spl_ip6_addr_t *ip6addr2, u8 masklen);

#define IP6_ADDR_LIFE_STATIC    0
#define IP6_ADDR_LIFE_INFINITE  0xffffffffUL
#define ip6_addr_life_isstatic(addr_life) ((addr_life) == IP6_ADDR_LIFE_STATIC)
#define ip6_addr_life_isinfinite(addr_life) ((addr_life) == IP6_ADDR_LIFE_INFINITE)

#define SPL_IP6_ADDR_BLOCK1(_spl_ip6_addr) ((u16)((spl_htonl((_spl_ip6_addr)->addr[0]) >> 16) & 0xffffU))
#define SPL_IP6_ADDR_BLOCK2(_spl_ip6_addr) ((u16)((spl_htonl((_spl_ip6_addr)->addr[0])) & 0xffffU))
#define SPL_IP6_ADDR_BLOCK3(_spl_ip6_addr) ((u16)((spl_htonl((_spl_ip6_addr)->addr[1]) >> 16) & 0xffffU))
#define SPL_IP6_ADDR_BLOCK4(_spl_ip6_addr) ((u16)((spl_htonl((_spl_ip6_addr)->addr[1])) & 0xffffU))
#define SPL_IP6_ADDR_BLOCK5(_spl_ip6_addr) ((u16)((spl_htonl((_spl_ip6_addr)->addr[2]) >> 16) & 0xffffU))
#define SPL_IP6_ADDR_BLOCK6(_spl_ip6_addr) ((u16)((spl_htonl((_spl_ip6_addr)->addr[2])) & 0xffffU))
#define SPL_IP6_ADDR_BLOCK7(_spl_ip6_addr) ((u16)((spl_htonl((_spl_ip6_addr)->addr[3]) >> 16) & 0xffffU))
#define SPL_IP6_ADDR_BLOCK8(_spl_ip6_addr) ((u16)((spl_htonl((_spl_ip6_addr)->addr[3])) & 0xffffU))

#define SAFETY_IPV6_VAR(_spl_ip6_addr) SPL_IP6_ADDR_BLOCK1((_spl_ip6_addr)), SPL_IP6_ADDR_BLOCK2((_spl_ip6_addr))
#define FUZZY_IPV6_VAR(_spl_ip6_addr) SPL_IP6_ADDR_BLOCK1((_spl_ip6_addr)), SPL_IP6_ADDR_BLOCK8((_spl_ip6_addr))

static __inline u32 ip6_addr_u16_sum(const spl_ip6_addr_t *ip6addr)
{
#define IP6_ADDR_U16_LENTH 8
    const u16 *addr_16 = (const u16 *)((ip6addr)->addr);
    u32 sum = 0;
    s32 ii;
    for (ii = 0; ii < IP6_ADDR_U16_LENTH; ii++) {
        sum += addr_16[ii];
    }
    return sum;
}

#ifdef __cplusplus
}
#endif

#endif /* __SPL_IP6_ADDR_H__ */
