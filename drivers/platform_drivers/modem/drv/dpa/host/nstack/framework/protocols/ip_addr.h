/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#ifndef IP_ADDR_H
#define IP_ADDR_H

#include "ip6_addr.h"
#include "stack_types.h"
#include "dmm_common.h"
#include "securec.h"
#include "stack_log.h"
#include "sockets.h"

#define IPV4_BIT_LEN 32
#define INET4_ADDR_DESC_BUFSIZE 32
#define INET6_ADDR_DESC_BUFSIZE 128

#define IP4_MAX_DESC_BUFSIZE 16
#define IP4_MAX_MASK_LEN 32U

#define IP6_U32_BUFSIZE 4
#define IP6_MAX_MASK_LEN 128

#define HEX_OFFSET_MASK 4U
#define OCT_OFFSET_MASK 3U
#define DEC_OFFSET_MASK 10U

#define SPL_IP_ADDR_TYPE_V4 0U  /* IPv4 */
#define SPL_IP_ADDR_TYPE_V6 6U  /* IPv6 */

typedef u32 spl_ip4_addr_t;

#define ip4_addr1(ipaddr) (((u8 *)(ipaddr))[0])
#define ip4_addr2(ipaddr) (((u8 *)(ipaddr))[1])
#define ip4_addr3(ipaddr) (((u8 *)(ipaddr))[2])
#define ip4_addr4(ipaddr) (((u8 *)(ipaddr))[3])

#define ipv4_addr1_u16(ipaddr) ((u16)ip4_addr1(ipaddr))
#define ipv4_addr2_u16(ipaddr) ((u16)ip4_addr2(ipaddr))
#define ipv4_addr3_u16(ipaddr) ((u16)ip4_addr3(ipaddr))
#define ipv4_addr4_u16(ipaddr) ((u16)ip4_addr4(ipaddr))

#define SAFETY_IP_VAR(ipaddr) ipv4_addr1_u16((ipaddr)), ipv4_addr2_u16((ipaddr))
#define FUZZY_IP_VAR(ipaddr) ipv4_addr3_u16((ipaddr)), ipv4_addr4_u16((ipaddr))

#define SPL_IP4_INIT0 0

#define spl_ip4_addr_get_u32(_spl_ip4_addr) (*(_spl_ip4_addr))

#define spl_ip4_addr_set_zero(_spl_ip4_addr) spl_ip4_addr_set_u32(_spl_ip4_addr, 0)

#define spl_ip4_addr_set_u32(_spl_ip4_addr, _u32_value) (*(_spl_ip4_addr) = (_u32_value))

#define spl_ip4_addr_set_any(_spl_ip4_addr) spl_ip4_addr_set_u32(_spl_ip4_addr, IP_ADDR_ANY)

#define spl_ip4_addr_set_loopback(_spl_ip4_addr) spl_ip4_addr_set_u32(_spl_ip4_addr, spl_htonl(IP_ADDR_LOOP))

#define spl_ip4_addr_is_any(_spl_ip4_addr) \
    (((_spl_ip4_addr) == NULL) || (spl_ip4_addr_get_u32(_spl_ip4_addr) == IP_ADDR_ANY))

#define spl_ipv4_addr_is_lbcast(_spl_ip4_addr) (spl_ip4_addr_get_u32(_spl_ip4_addr) == spl_htonl(0xffffffffUL))

#define spl_ip4_addr_is_multicast(_spl_ip4_addr) \
    ((spl_ip4_addr_get_u32(_spl_ip4_addr) & spl_htonl(0xf0000000UL)) == spl_htonl(0xe0000000UL))

#define spl_ip4_addr_is_link_local(_spl_ip4_addr) \
    ((spl_ip4_addr_get_u32(_spl_ip4_addr) & spl_htonl(0xffff0000UL)) == spl_htonl(0xa9fe0000UL))

#define spl_ip4_addr_is_loopback(_spl_ip4_addr) \
    ((spl_ip4_addr_get_u32(_spl_ip4_addr) & spl_htonl(0xff000000UL)) == spl_htonl(0x7f000000UL))

#define spl_ip4_addr_cmp(_spl_ip4_addr_1, _spl_ip4_addr_2) \
    (spl_ip4_addr_get_u32(_spl_ip4_addr_1) == spl_ip4_addr_get_u32(_spl_ip4_addr_2))

#define spl_ip4_addr_cast_from_inaddr(_spl_ip4_addr, _sin_addr) spl_ip4_addr_set_u32(_spl_ip4_addr, (_sin_addr)->s_addr)

#define spl_ip4_addr_cast_to_inaddr(_sin_addr, _spl_ip4_addr) (_sin_addr)->s_addr = spl_ip4_addr_get_u32(_spl_ip4_addr)

#define ipv4_addr_get_u32(ipaddr) spl_ip4_addr_get_u32(ipaddr)

#pragma pack(4)
typedef struct ip_addr {
    union {
        spl_ip4_addr_t addr; // Used for IPv4 address
        spl_ip6_addr_t ip6;
    };
    u8 type;
} ip_addr_t;
#pragma pack()

typedef struct ip_out_para {
    u8 ttl;
    u8 tos;
    u8 proto;
    void *options;
    u16 optlen;
} ip_out_para_t;

typedef struct {
    union {
        struct spl_in_addr addr4;
        struct spl_in6_addr addr6;
    };
} in_x_addr_t;

static inline void ip_out_para_set(ip_out_para_t *para, u8 ttl, u8 tos, u8 proto)
{
    para->ttl = ttl;
    para->tos = tos;
    para->proto = proto;
}

#define IP_OUT_PARA_INIT0 {                       \
        0, 0, 0, NULL, 0 \
    }

#define IP_ADDR_LOOP ((u32)0x7f000001UL) /* 127.0.0.1 */

#define IP_NET_MASK_LEN 8U /* 255.0.0.0 */

#define IP_ADDR_ANY ((u32)0x00000000UL) /* 0.0.0.0 */

#define IP_ADDR_BROADCAST ((u32)0xffffffffUL) /* 255.255.255.255 */

#define IP_ADDR_NONE ((u32)0xffffffffUL) /* 255.255.255.255 */

#define spl_ip_addr_get_type(_spl_ip_addr) ((_spl_ip_addr)->type)

#define spl_ip_addr_set_type(_spl_ip_addr, _type) ((_spl_ip_addr)->type = (_type))

#define spl_ip_addr_is_type(_spl_ip_addr, _type) ((_type) == spl_ip_addr_get_type(_spl_ip_addr))

#define spl_ip_isv4(_spl_ip_addr) spl_ip_addr_is_type(_spl_ip_addr, SPL_IP_ADDR_TYPE_V4)

#define spl_ip_isv6(_spl_ip_addr) spl_ip_addr_is_type(_spl_ip_addr, SPL_IP_ADDR_TYPE_V6)

#define spl_ip_addr_ipv4_value(_spl_ip_addr) (_spl_ip_addr)->addr

#define spl_ip_addr_get_ipv4_ptr(_spl_ip_addr) &(spl_ip_addr_ipv4_value(_spl_ip_addr))

#define ip_2_ip4(_spl_ip_addr) spl_ip_addr_get_ipv4_ptr(_spl_ip_addr)

#define spl_ip_addr_ipv6_value(_spl_ip_addr) (_spl_ip_addr)->ip6

#define spl_ip_addr_get_ipv6_ptr(_spl_ip_addr) (&(spl_ip_addr_ipv6_value(_spl_ip_addr)))

#define ip_2_ip6(_spl_ip_addr) spl_ip_addr_get_ipv6_ptr(_spl_ip_addr)

#define spl_ip_addr_get_u32(_spl_ip_addr) spl_ip4_addr_get_u32(ip_2_ip4(_spl_ip_addr))

#define spl_ip_addr_clear_nov4(_spl_ip_addr) do { \
    ip_2_ip6(_spl_ip_addr)->addr[1] = 0;             \
    ip_2_ip6(_spl_ip_addr)->addr[2] = 0;             \
    ip_2_ip6(_spl_ip_addr)->addr[3] = 0;             \
    spl_ip6_addr_clear_zone(ip_2_ip6(_spl_ip_addr)); \
} while (false)

#define spl_ip_addr_copy(_spl_ip_addr_dest, _spl_ip_addr_src) do { \
    spl_ip_addr_set_type(_spl_ip_addr_dest, spl_ip_addr_get_type(_spl_ip_addr_src)); \
    if (spl_ip_isv6(_spl_ip_addr_src)) {                                             \
        spl_ip6_addr_copy(ip_2_ip6(_spl_ip_addr_dest), ip_2_ip6(_spl_ip_addr_src));  \
    } else {                                                                         \
        (void)memcpy_s(ip_2_ip4(_spl_ip_addr_dest), sizeof(spl_ip4_addr_t), ip_2_ip4(_spl_ip_addr_src), \
                       sizeof(spl_ip4_addr_t)); \
        spl_ip_addr_clear_nov4(_spl_ip_addr_dest);                                   \
    }                                                                                \
} while (false)

#define SPL_IP_ADDR_SET_ZERO(_spl_ip_addr) spl_ip6_addr_set_zero(_spl_ip_addr)

/* SPL_IP_ADDR_EXPORT */
#define spl_ip_addr_set_zero(_spl_ip_addr) SPL_IP_ADDR_SET_ZERO(_spl_ip_addr)

#define spl_ip_addr_set_zero_with_type(_spl_ip_addr, _type) do { \
    spl_ip6_addr_set_zero(ip_2_ip6(_spl_ip_addr));      \
    spl_ip_addr_set_type((_spl_ip_addr), (_type));      \
} while (false)

#define spl_ip_addr_set_u32(_spl_ip_addr, _u32_value) spl_ip4_addr_set_u32(ip_2_ip4(_spl_ip_addr), _u32_value)

#define SPL_IP4_BIT_NUM 32U
#define SPL_IP4_BYTE_NUM 4U
#define SPL_IP4_BIT_MASK(masklen) spl_htonl(((masklen) != 0U) ? ((~0U) << (SPL_IP4_BIT_NUM - (masklen))) : 0U)
#define SPL_IP4_MASK_V(ipaddr, masklen) ((ipaddr) & SPL_IP4_BIT_MASK(masklen))

#define is_in_same_subnet(src, dst, mask) (((src) & (mask)) == ((dst) & (mask)))

static __inline void ip_addr_set_any(bool is_ipv6, ip_addr_t *ipaddr)
{
    if (is_ipv6) {
        spl_ip6_addr_set_any(ip_2_ip6(ipaddr));
        spl_ip_addr_set_type(ipaddr, SPL_IP_ADDR_TYPE_V6);
    } else {
        spl_ip4_addr_set_any(ip_2_ip4(ipaddr));
        spl_ip_addr_set_type(ipaddr, SPL_IP_ADDR_TYPE_V4);
        spl_ip_addr_clear_nov4(ipaddr);
    }
}

static __inline void ip_addr_set_loopback(bool is_ipv6, ip_addr_t *ipaddr)
{
    if (is_ipv6) {
        spl_ip6_addr_set_loopback(ip_2_ip6(ipaddr));
        spl_ip_addr_set_type(ipaddr, SPL_IP_ADDR_TYPE_V6);
    } else {
        spl_ip4_addr_set_loopback(ip_2_ip4(ipaddr));
        spl_ip_addr_set_type(ipaddr, SPL_IP_ADDR_TYPE_V4);
        spl_ip_addr_clear_nov4(ipaddr);
    }
}

static inline char stack_char_to_x(char c)
{
    if (((s32)c >= (s32)'0') && ((s32)c <= (s32)'9')) {
        return (char)((s32)c - (s32)'0');
    } else if (((s32)c >= (s32)'A') && ((s32)c <= (s32)'F')) {
        return (char)((s32)c + 10 - (s32)'A');
    } else if (((s32)c >= (s32)'a') && ((s32)c <= (s32)'f')) {
        return (char)((s32)c + 10 - (s32)'a');
    } else {
        return (char)(-1);
    }
}


#define ip_addr_set_any_v4(_ipaddr) ip_addr_set_any(false, (_ipaddr))
#define ip_addr_set_any_v6(_ipaddr) ip_addr_set_any(true, (_ipaddr))

#define spl_ip_addr_init_ip4_with_value(_spl_ip_addr, _u32_value) do { \
    spl_ip_addr_set_zero_with_type((_spl_ip_addr), SPL_IP_ADDR_TYPE_V4); \
    spl_ip_addr_set_u32((_spl_ip_addr), (_u32_value));                   \
} while (false)

#define spl_ip_addr_init_from_ip4(_spl_ip_addr, _spl_ip4_addr) \
    spl_ip_addr_init_ip4_with_value((_spl_ip_addr), spl_ip4_addr_get_u32((_spl_ip4_addr)))

#define spl_ip_addr_init_from_ip6(_spl_ip_addr, _spl_ip6_addr) do { \
    spl_ip_addr_set_zero_with_type((_spl_ip_addr), SPL_IP_ADDR_TYPE_V6); \
    spl_ip6_addr_copy(ip_2_ip6((_spl_ip_addr)), (_spl_ip6_addr));        \
} while (false)

#define spl_ip_addr_copy_from_ip4(_spl_ip_addr, _spl_ip4_addr) \
    spl_ip_addr_set_u32((_spl_ip_addr), spl_ip4_addr_get_u32((_spl_ip4_addr)))

#define spl_ip_addr_copy_from_ip6(_spl_ip_addr, _spl_ip6_addr) \
    spl_ip_addr_init_from_ip6((_spl_ip_addr), (_spl_ip6_addr))

/* Below are old IP inteface code, they are kept and adapted. 2019-02-16 */
#define ip_addr_set_zero(addr) spl_ip_addr_set_zero_with_type((addr), SPL_IP_ADDR_TYPE_V4)

u32 inet_addr(const char *cstr);
s32 inet_aton(const char *str, spl_ip4_addr_t *ip4addr);

char *inet_ntoa(const spl_ip4_addr_t *addr);
char *inet_ntoa_r(const spl_ip4_addr_t *addr, char *buf, u32 buflen);

#if SPL_IPV6
static inline void inet6_addr_to_ip6addr(spl_ip6_addr_t *dst_addr, const struct spl_in6_addr *src_addr)
{
    (void)memcpy_s(dst_addr->addr, sizeof(dst_addr->addr), src_addr->s6_addr32, sizeof(src_addr->s6_addr32));
}

static inline void inet6_addr_from_ip6addr(struct spl_in6_addr *dst_addr, const spl_ip6_addr_t *src_addr)
{
    (void)memcpy_s(dst_addr->s6_addr32, sizeof(dst_addr->s6_addr32), src_addr->addr, sizeof(src_addr->addr));
}

static inline u32 ip6_fold4(const spl_ip6_addr_t *ip6)
{
    u32 fold_num = ip6->addr[0];
    u32 i;
    for (i = 1; i < SPL_IPV6_U32_ARRAY_LENGTH; i++) {
        fold_num ^= ip6->addr[i];
    }
    return fold_num;
}
#endif

#define IP6OFX(ipx) ((const spl_ip6_addr_t *)&(ipx)->ip6)
#define IP6OFX_W(ipx) ((spl_ip6_addr_t *)&(ipx)->ip6)
#define IP4OFX(ipx) spl_ip_addr_get_ipv4_ptr(ipx)

static inline bool ip_addr_isany_x(bool isv6, const ip_addr_t *addr1)
{
    (void)isv6;
    if (addr1->type == SPL_IP_ADDR_TYPE_V6) {
        return spl_ip6_addr_is_any(IP6OFX(addr1));
    } else if (addr1->type == SPL_IP_ADDR_TYPE_V4) {
        return spl_ip4_addr_is_any(IP4OFX(addr1));
    } else {
        NS_ERR("invalid type %u", addr1->type);
        stack_dump_stack();
        return false;
    }
}

static inline bool ip_addr_cmp_x(bool isv6, const ip_addr_t *addr1, const ip_addr_t *addr2)
{
    (void)isv6;
    if (addr1->type != addr2->type) {
        NS_ERR("invalid type %u:%u", addr1->type, addr2->type);
        stack_dump_stack();
        return false;
    }
    if (addr1->type == SPL_IP_ADDR_TYPE_V6) {
        return spl_ip6_addr_cmp(IP6OFX(addr1), IP6OFX(addr2));
    }
    return spl_ip4_addr_cmp(IP4OFX(addr1), IP4OFX(addr2));
}

#define ip_addr_copy_x(isv6, dst, src) do { \
    dst = src; \
} while (false)

s32 ip_ext_cmp(bool isv6, const ip_addr_t *ip_x, const ip_addr_t *ip);

#define IP_FMT_NUM 3
#define IP_FMT_LEN 52 /* XXXX:XXXX:XXXX:XXXX:XXXX:XXXX:XXX.XXX.XXX.XXX.65535\0 */
char *ip_fmt_buf(void);
s32 ip_addr_isbroadcast(u32 addr, u32 net_mask);
const char *ip_fuzzy_x(bool isv6, const ip_addr_t *addr);
const char *ip_safety_x(const ip_addr_t *addr);
const char *safety_in_x_addr(bool isv6, const in_x_addr_t *addr);
const char *ip_fuzzy_v6(const spl_ip6_addr_t *addr);
const char *hwaddr_fuzzy(const u8 *hwaddr);

bool is_broadcast_ip(u32 src, u32 dst, u32 net_mask);

#if SPL_IPV6
static inline char *inet_ntop(int family, const void *addr, char *buf, u32 buflen)
{
    return ((family == AF_INET) ? inet_ntoa_r(addr, buf, buflen) :
                         ((family == AF_INET6) ? spl_ip6_addr_ntoa_r(addr, buf, buflen) : NULL));
}
#else
#define inet_ntop(af, addr, buf, buflen)
static inline char *inet_ntop(int family, const void *addr, char *buf, u32 buflen)
{
    return ((family == AF_INET) ? inet_ntoa_r(addr, buf, buflen) : NULL);
}
#endif

struct ip4_addr {
    u32 addr;
};

typedef struct ip4_addr ip4_addr_t;

/* Note: this function has known multi-thread issue, which can only be tolerated
 * when the function is used for log purpose. */
static inline const char *inet4_ntoa(const struct spl_sockaddr *addr)
{
    static char buf[INET4_ADDR_DESC_BUFSIZE];
    const uint8_t *p = (const uint8_t *)&((const struct spl_sockaddr_in *)addr)->sin_addr.s_addr;
    s32 ret = snprintf_s(buf, sizeof(buf), sizeof(buf) - 1UL, "%u.%u.*.*", p[0], p[1]);
    if (ret == -1) {
        return "NULL";
    }
    return buf;
}

/* Note: this function has known multi-thread issue, which can only be tolerated
 * when the function is used for log purpose. */
#if SPL_IPV6
static inline const char *inet6_ntoa(const struct spl_in6_addr *addr)
{
    static char buf[INET6_ADDR_DESC_BUFSIZE];

    if (snprintf_s(buf, sizeof(buf), sizeof(buf) - 1UL, "%x:%x:*:*:*:*",
        spl_htons(addr->s6_addr16[0]), spl_htons(addr->s6_addr16[1])) == -1) {
        return "NULL";
    }
    return buf;
}
#endif

/* Note: this function has known multi-thread issue, which can only be tolerated
 * when the function is used for log purpose. */
static inline const char *inet_ntoa_x(const struct spl_sockaddr *addr)
{
    static char buf[INET4_ADDR_DESC_BUFSIZE];

    if (addr->sa_family == AF_INET) {
        return inet4_ntoa(addr);
    }

#if SPL_IPV6
    if (addr->sa_family == AF_INET6) {
        return inet6_ntoa(&((const struct spl_sockaddr_in6 *)(void *)addr)->sin6_addr);
    }
#endif
    s32 ret = snprintf_s(buf, sizeof(buf), sizeof(buf) - 1UL, "family:%u", addr->sa_family);
    if (ret == -1) {
        return "NULL";
    }

    return buf;
}

/*
 * return ip mask in host byte order
 */
static inline u32 get_mask_from_len(u32 mask_len)
{
    if (mask_len == 0U) {
        return 0U;
    }

    u32 mask = ~0U;
    mask = (mask << ((u32)IPV4_BIT_LEN - mask_len));
    return mask;
}

/*
 * Get the prefix length of a netmask,
 * assume mask is valid and host byte ordered
 */
static inline s32 get_len_from_mask(u32 mask)
{
    if (mask == 0) {
        return 0;
    }
    return (IPV4_BIT_LEN - (ffs((s32)mask) - 1));
}

#endif /* __IP_ADDR_H__ */
