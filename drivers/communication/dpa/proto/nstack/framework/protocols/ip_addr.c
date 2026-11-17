/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */

#include "stack_log.h"
#include "stack_mem.h"
#include "ip_addr.h"

#define IP_CLASS_A_LEADING_BIT 0U
#define IP_CLASS_B_LEADING_BIT 0b10000000U
#define IP_CLASS_C_LEADING_BIT 0b11000000U
/* Following masks are for the address in network byte order */
#define IP_CLASS_A_NETWORK_MASK 0xFFFFFF00U
#define IP_CLASS_B_NETWORK_MASK 0xFFFF0000U
#define IP_CLASS_C_NETWORK_MASK 0xFF000000U
#define IP_CLASS_A_LEADING_BIT_MASK 0b10000000U
#define IP_CLASS_B_LEADING_BIT_MASK 0b11000000U
#define IP_CLASS_C_LEADING_BIT_MASK 0b11100000U

#if SPL_IPV6
spl_ip6_addr_t g_ip6_prefix = SPL_IP6_ADDR_ANY_VAL;
#endif

bool is_broadcast_ip(u32 src, u32 dst, u32 net_mask)
{
    /* all ones (broad cast) or all zeroes (old skool broad cast) */
    if ((~dst == IP_ADDR_ANY) || (dst == IP_ADDR_ANY)) {
        return true;
    }

    /* address matches local address exactly, just as no broadcast */
    if (src == dst) {
        return false;
    }

    return (net_mask != IP_ADDR_NONE) && is_in_same_subnet(src, dst, net_mask) &&
            ((dst & ~net_mask) == (IP_ADDR_BROADCAST & ~net_mask));
}

s32 ip_addr_isbroadcast(u32 addr, u32 net_mask)
{
    if ((~addr == IP_ADDR_ANY) || (addr == IP_ADDR_ANY)) {
        return 1;
    }

    if ((net_mask != IP_ADDR_NONE) && ((addr & ~net_mask) == (IP_ADDR_BROADCAST & ~net_mask))) {
        return 1;
    }

    return 0;
}

u32 inet_addr(const char *cstr)
{
    spl_ip4_addr_t ip_val;

    if (inet_aton(cstr, &ip_val) != 0) {
        return spl_ip4_addr_get_u32(&ip_val);
    }

    return (IP_ADDR_NONE);
}

enum num_type {
    OCTAL = 1,
    DECIMAL,
    HEXADECIMAL,
};

static s32 convert_str_to_data_get_tmpval(u8 base, const char *pos, const char *end, u32 val_mask, u64 *tmp_val)
{
    char c_val;
    const char *tmp_pos = pos;
    if (base == HEXADECIMAL) {
        for (; tmp_pos < end; tmp_pos++) {
            c_val = stack_char_to_x(*tmp_pos);
            if ((s32)c_val < 0) {
                return -1;
            }
            *tmp_val <<= HEX_OFFSET_MASK;
            *tmp_val |= (u8)c_val;
            if (*tmp_val > val_mask) {
                return -1;
            }
        }
    } else if (base == OCTAL) {
        for (; tmp_pos < end; tmp_pos++) {
            if (((s32)(*tmp_pos) >= (s32)'0') && ((s32)(*tmp_pos) < (s32)'8')) {
                c_val = (char)((s32)(*tmp_pos) - (s32)'0');
            } else {
                return -1;
            }
            *tmp_val <<= OCT_OFFSET_MASK;
            *tmp_val |= (u8)c_val;
            if (*tmp_val > val_mask) {
                return -1;
            }
        }
    } else {
        for (; tmp_pos < end; tmp_pos++) {
            if (((s32)(*tmp_pos) >= (s32)'0') && ((s32)(*tmp_pos) <= (s32)'9')) {
                c_val = (char)((s32)(*tmp_pos) - (s32)'0');
            } else {
                return -1;
            }
            *tmp_val *= DEC_OFFSET_MASK;
            *tmp_val += (u8)c_val;
            if (*tmp_val > val_mask) {
                return -1;
            }
        }
    }

    return 0;
}

/* Convert IP str such as x.y.z.w which is seperated by '.' to u8.
 * Or convert IP str such as x which is not be seperated by '.' and may be represented by Octal,Hexadecimal, or Decimal
 * to u32 */
static s32 convert_str_to_u8_or_u32(const char *start, const char *end, void *val, s32 is_u32)
{
    s32 len = (s32)(end - start);
    u8 base = DECIMAL;
    u64 tmp_val = 0;
    const char *pos = start;
    u32 val_mask = 0xffU;

    if (is_u32 != 0) {
        val_mask = IP_ADDR_NONE;
    }

    if (len <= 0) {
        return -1;
    }

    if (*start == (char)'0') {
        if ((len > 1) && ((*(start + 1) == (char)'x') || (*(start + 1) == (char)'X'))) {
            base = HEXADECIMAL;
            if (len == 2) { /* 0x should return error */
                return -1;
            }
            pos += 2;
        } else {
            base = OCTAL;
        }
    }

    if (convert_str_to_data_get_tmpval(base, pos, end, val_mask, &tmp_val) == -1) {
        return -1;
    }

    if (is_u32 != 0) {
        *(u32 *)val = (u32)(tmp_val & val_mask);
    } else {
        *(u8 *)val = (u8)(tmp_val & val_mask);
    }

    return 0;
}

s32 inet_aton(const char *str, spl_ip4_addr_t *ip4addr)
{
    u8 addr_u8[SPL_IP4_BYTE_NUM] = {0};
    u32 index = 0;
    const char *ptr = str;
    const char *start_ptr = str;
    const char *end_ptr = NULL;
    u32 i;
    u32 ip_val = 0;

    if ((ip4addr == NULL) || (str == NULL)) {
        return 0;
    }

    if (strlen(str) == 0U) {
        return 0;
    }

    end_ptr = str + strlen(str) - 1;
    if (*end_ptr == (char)'.') {
        return 0;
    }

    for (; ptr <= end_ptr; ptr++) {
        if (*ptr != (char)'.') {
            continue;
        }

        if ((start_ptr == ptr) || (convert_str_to_u8_or_u32(start_ptr, ptr, (void *)&addr_u8[index], 0) < 0)) {
            return 0;
        }

        ++index;

        if (index == SPL_IP4_BYTE_NUM) {
            return 0;
        }

        start_ptr = ptr + 1;
    }

    /* If no '.', the str will be regard as u32 IP */
    u32 tmp_val = 0;
    if (convert_str_to_u8_or_u32(start_ptr, end_ptr + 1, (void *)&tmp_val, 1) < 0) {
        return 0;
    }

    if (tmp_val > (u32)(NSTACK_MAX_U32_NUM >> (u8)((SPL_IP4_BIT_NUM / SPL_IP4_BYTE_NUM)  * index))) {
        return 0;
    }

    for (i = 0; i < index; i++) {
        ip_val |= (((u32)addr_u8[i]) << ((SPL_IP4_BIT_NUM / SPL_IP4_BYTE_NUM) * ((SPL_IP4_BYTE_NUM - 1U) - i)));
    }
    ip_val |= tmp_val;

    spl_ip4_addr_set_u32(ip4addr, spl_htonl(ip_val));

    return 1;
}

char *inet_ntoa(const spl_ip4_addr_t *addr)
{
    static char desc_str[IP4_MAX_DESC_BUFSIZE];

    return inet_ntoa_r(addr, desc_str, IP4_MAX_DESC_BUFSIZE);
}

char *inet_ntoa_r(const spl_ip4_addr_t *addr, char *buf, u32 buflen)
{
    const u8 *addr_u8 = (const u8 *)addr;
    char tmp_buf[IP4_MAX_DESC_BUFSIZE] = {0};
    u32 index = 0;
    u32 i;
    u8 tmp_val;
    u8 tmp_val1;

    for (i = 0U; i < SPL_IP4_BYTE_NUM; i++) {
        tmp_val = (u8)(addr_u8[i] / ((u8)100U));
        if (tmp_val != 0U) {
            tmp_buf[index] = (char)(tmp_val + '0');
            ++index;
        }

        tmp_val1 = (u8)(addr_u8[i] % ((u8)100U));
        tmp_val1 = (u8)(tmp_val1 / ((u8)10U));
        if ((tmp_val != 0U) || (tmp_val1 != 0U)) {
            tmp_buf[index] = (char)(tmp_val1 + '0');
            ++index;
        }

        tmp_val = (u8)(addr_u8[i] % ((u8)10U));
        tmp_buf[index] = (char)(tmp_val + '0');
        ++index;
        tmp_buf[index] = '.';
        ++index;
    }
    tmp_buf[index - 1U] = '\0';

    if ((buflen < index) || (strncpy_s(buf, buflen, tmp_buf, index) != EOK)) {
        return NULL;
    }

    return buf;
}

s32 ip_ext_cmp(bool isv6, const ip_addr_t *ip_x, const ip_addr_t *ip)
{
    (void)isv6;
    if (ip_x->addr != ip->addr) {
        return 0;
    } else if (ip_x->type == SPL_IP_ADDR_TYPE_V6) {
#if SPL_IPV6
        return ip6_addr_cmp_zoneless(&ip_x->ip6, &ip->ip6);
#else
        return 0;
#endif
    } else {
        return 1;
    }
}

char *ip_fmt_buf(void)
{
    static NSFW_THREAD u32 fmt_idx = 0;
    static NSFW_THREAD char fmt_buf[IP_FMT_NUM][IP_FMT_LEN] = {{0}};
    fmt_idx = (fmt_idx + 1) % IP_FMT_NUM;

    return fmt_buf[fmt_idx];
}

const char *hwaddr_fuzzy(const u8 *hwaddr)
{
    char *buf = ip_fmt_buf();
    if (snprintf_s(buf, IP_FMT_LEN, IP_FMT_LEN - 1, "%x:%x:***:%x:%x",
        hwaddr[0], hwaddr[1], hwaddr[4], hwaddr[5]) > 0) {
        return buf;
    }

    return "*";
}

const char *ip_fuzzy_v6(const spl_ip6_addr_t *addr)
{
    char *buf = ip_fmt_buf();
    if (snprintf_s(buf, IP_FMT_LEN, IP_FMT_LEN - 1, "%x:***:%x",
        SPL_IP6_ADDR_BLOCK1(addr), SPL_IP6_ADDR_BLOCK8(addr)) > 0) {
        return buf;
    }

    return "*";
}

const char *ip_fuzzy_x(bool isv6, const ip_addr_t *addr)
{
    s32 ret;
    char *buf = ip_fmt_buf();

    (void)isv6;
    if (addr->type == SPL_IP_ADDR_TYPE_V6) {
        ret = snprintf_s(buf, IP_FMT_LEN, IP_FMT_LEN - 1, "%x:***:%x", SPL_IP6_ADDR_BLOCK1(IP6OFX(addr)),
                         SPL_IP6_ADDR_BLOCK8(IP6OFX(addr)));
    } else {
        ret = snprintf_s(buf, IP_FMT_LEN, IP_FMT_LEN - 1, "*.*.%u.%u", FUZZY_IP_VAR(&addr->addr));
    }

    if (ret > 0) {
        return buf;
    }
    return "*";
}

const char *ip_safety_x(const ip_addr_t *addr)
{
    s32 ret;
    char *buf = ip_fmt_buf();

    if (addr->type == SPL_IP_ADDR_TYPE_V6) {
        ret = snprintf_s(buf, IP_FMT_LEN, IP_FMT_LEN - 1, "%x:%x:***", SAFETY_IPV6_VAR(&addr->ip6));
    } else {
        ret = snprintf_s(buf, IP_FMT_LEN, IP_FMT_LEN - 1, "%u.%u.*.*", SAFETY_IP_VAR(&addr->addr));
    }

    if (ret > 0) {
        return buf;
    }
    return "*";
}

const char *safety_in_x_addr(bool isv6, const in_x_addr_t *addr)
{
    s32 ret;
    char *buf = ip_fmt_buf();

    if (isv6) {
        const u16 *daddr = addr->addr6.s6_addr16;
        ret = snprintf_s(buf, IP_FMT_LEN, IP_FMT_LEN - 1, "%x:%x:***", spl_ntohs(daddr[0]), spl_ntohs(daddr[1]));
    } else {
        ret = snprintf_s(buf, IP_FMT_LEN, IP_FMT_LEN - 1, "%u.%u.*.*", SAFETY_IP_VAR(&addr->addr4.s_addr));
    }

    if (ret > 0) {
        return buf;
    }
    return "*";
}

