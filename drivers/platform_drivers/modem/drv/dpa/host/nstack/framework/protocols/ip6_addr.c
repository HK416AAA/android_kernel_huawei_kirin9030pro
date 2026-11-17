/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */

#include "ip6_addr.h"
#include "ip_addr.h"
#include "securec.h"

#define IPV6_U32_LEN (SPL_IPV6_U32_ARRAY_LENGTH)
#define IPV6_U16_LEN (IPV6_U32_LEN * 2)
#define IPV6_STR_MAX_LEN (sizeof("ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.255"))
#define WITHOUT_DOUBLE_COLON  2

static s32 stack_str_to_x(const char *start, const char *end, u16 *val)
{
    s32 len = (s32)(end - start);
    char x_val;
    s32 i;
    const char *pos = start;

    if (len > SPL_IPV6_U32_ARRAY_LENGTH) {
        while (*pos == '0' && pos < end) {
            pos++;
            len--;
        }
        if (len == 0) {
            *val = 0;
            return 0;
        }
    }

    *val = 0;
    if ((len > 0) && (len <= SPL_IPV6_U32_ARRAY_LENGTH)) {
        for (i = 0; i < len; i++) {
            x_val = stack_char_to_x(pos[i]);
            if (x_val < (char)0) {
                return -1;
            }
            *val <<= SPL_IPV6_U32_ARRAY_LENGTH;
            *val |= (u8)x_val;
        }
        *val = (u16)((*val << 8U) & 0xff00U) | ((*val >> 8U) & 0xffU);
        return 0;
    }

    return -1;
}

s32 spl_ip6_addr_aton(const char *ip_char, spl_ip6_addr_t *ip6addr)
{
    if (ip_char == NULL || ip6addr == NULL) {
        return 0;
    }

    const char *data_start = NULL;
    const char *curr_tok = NULL;
    const char *pos = ip_char;
    const char *src_end = ip_char + strlen(ip_char) - 1;
    u16 p_dst[IPV6_U16_LEN] = {0};
    s32 index = 0;
    s32 double_tok = 0;
    s32 has_ipv4 = 0;
    s32 record_index = -1;
    s32 i;

    if (*pos == (char)'\0') {
        return 0;
    }

    for (; *pos != (char)'\0'; pos++) {
        if (*pos == (char)'.') {  /* convert IPV4 addr */
            if (index > IPV6_U16_LEN - WITHOUT_DOUBLE_COLON || (curr_tok == NULL)) {
                return 0;
            }
            data_start = curr_tok + 1 + double_tok;
            if (inet_aton(data_start, (spl_ip4_addr_t *)&p_dst[IPV6_U16_LEN - WITHOUT_DOUBLE_COLON]) == 0) {
                return 0;
            }
            has_ipv4 = 1;
            curr_tok = src_end;
            break;
        }

        if (*pos != (char)':') {
            if (data_start == NULL) {
                data_start = pos;
            }
            continue;
        }

        /* current pos char is ':' */
        curr_tok = pos;
        double_tok = 0;
        if (pos + 1 <= src_end && *(pos + 1) == (char)':') {
            if (((pos + WITHOUT_DOUBLE_COLON) <= src_end) &&
                (*(pos + WITHOUT_DOUBLE_COLON) == (char)':')) { /* check ":::" */
                return 0;
            }
            if (record_index >= 0) { /* check whether "::" appear twice */
                return 0;
            }
            double_tok = 1;
            record_index = index;
        }

        /* check whether excess the max xstrs before ":", or IPV6 str started with ":" but not "::" */
        if ((index >= (IPV6_U16_LEN - 1)) || ((double_tok == 0) && (data_start == NULL))) {
            return 0;
        }

        if (data_start && stack_str_to_x(data_start, curr_tok, (u16 *)&p_dst[index]) < 0) {
            return 0;
        }
        index++;
        if (double_tok != 0) {
            if (data_start != NULL) {
                record_index = index;
            }
            pos++;  /* "::" checked, should be skiped */
            index++;    /* "::" should represent two zero at least, here remain one zero in p_dst */
        }

        data_start = pos + 1;
    }

    if (curr_tok != NULL) {
        curr_tok += double_tok;
    }

    if (curr_tok != NULL && pos > curr_tok + 1) {
        if (stack_str_to_x(curr_tok + 1, pos, (u16 *)&p_dst[index]) < 0) {
            return 0;
        }
        index++;
    } else {
        if (has_ipv4 == 0 && double_tok == 0) {
            return 0;
        }
    }

    /* without "::" */
    if (record_index == -1) {
        if ((has_ipv4 == 0 && (index != IPV6_U16_LEN)) ||
            (has_ipv4 != 0 && (index != IPV6_U16_LEN - WITHOUT_DOUBLE_COLON))) {
            return 0;
        }
        (void)memcpy_s(ip6addr, IPV6_U32_LEN * sizeof(u32), p_dst, IPV6_U32_LEN * sizeof(u32));
    } else {
        s32 j = 0;
        s32 end_index = IPV6_U16_LEN;
        u16 *tmp_dst = (u16 *)ip6addr;

        (void)memset_s(ip6addr, IPV6_U32_LEN * sizeof(u32), 0, IPV6_U32_LEN * sizeof(u32));
        for (i = 0; i < record_index; i++) {
            tmp_dst[i] = p_dst[i];
        }
        if (has_ipv4 != 0) {
            tmp_dst[IPV6_U16_LEN - WITHOUT_DOUBLE_COLON] = p_dst[IPV6_U16_LEN - WITHOUT_DOUBLE_COLON];
            tmp_dst[IPV6_U16_LEN - 1] = p_dst[IPV6_U16_LEN - 1];
            end_index = IPV6_U16_LEN - WITHOUT_DOUBLE_COLON;
        }
        for (i = index - 1; i >= record_index; i--) {
            tmp_dst[end_index - j - 1] = p_dst[i];
            j++;
        }
    }

    spl_ip6_addr_clear_zone(ip6addr);
    return 1;
}

static s32 convert_u16_to_xstr(u16 val, char *buf)
{
    s32 index = 0;
    s32 non_zero = 0;
    u8 tmp_val;
    u32 i;

    for (i = 0; i < 4U; i++) {
        tmp_val = (val >> (4U * (3U - i))) & 0xfU;
        if (non_zero != 0 || tmp_val != 0 || i == 3U) {
            non_zero = 1;
            buf[index] = (tmp_val >= 10) ? (char)(tmp_val - 10 + 'a') : (char)(tmp_val + '0');
            ++index;
        }
    }
    return index;
}

char *spl_ip6_addr_ntoa_r(const spl_ip6_addr_t *ip6addr, char *buf, u32 buflen)
{
    char addr_str[IPV6_STR_MAX_LEN] = "";
    u16 tmp_addr[IPV6_U16_LEN] = {0};
    s32 con_zero_index = -1;
    s32 con_zero_cnt = 0;
    s32 zero_cnt = 0;
    s32 i;
    const u16 *pos = (const u16 *)ip6addr;
    char *str_pos = addr_str;

    if (buf == NULL) {
        return NULL;
    }

    for (i = 0; i < IPV6_U16_LEN; i++) {
        tmp_addr[i] = (u16)((*pos << 8U) & 0xff00U) | ((*pos >> 8U) & 0xffU);

        if (*pos == 0) {
            zero_cnt++;
            if (i < IPV6_U16_LEN - 1) {
                ++pos;
                continue;
            }
        }

        if ((zero_cnt > 1) && (zero_cnt > con_zero_cnt)) {
            con_zero_index = i - zero_cnt + ((*pos == 0) ? 1 : 0); /* record the start index of continue zero */
            con_zero_cnt = zero_cnt;
            zero_cnt = 0;
        }

        ++pos;
    }

    for (i = 0; i < IPV6_U16_LEN; i++) {
        if (i == con_zero_index) {
            *str_pos = ':';
            ++str_pos;
            *str_pos = ':';
            ++str_pos;
            i += con_zero_cnt - 1;
            continue;
        }

        /* if only the last two u16 of addr is nonzero, the addr should convert to IPV4 */
        if ((i == (IPV6_U16_LEN - WITHOUT_DOUBLE_COLON)) && (con_zero_index == 0) &&
            (con_zero_cnt == (IPV6_U16_LEN - WITHOUT_DOUBLE_COLON))) {
            if (inet_ntoa_r(&ip6addr->addr[SPL_IPV6_U32_ARRAY_LENGTH - 1], str_pos,
                               (u32)(IPV6_STR_MAX_LEN - strlen("::"))) == NULL) {
                return NULL;
            }
            str_pos = addr_str + strlen(addr_str);
            break;
        }

        str_pos += convert_u16_to_xstr(tmp_addr[i], str_pos);
        if ((i != (IPV6_U16_LEN - 1)) && ((i + 1) != con_zero_index)) {
            *str_pos = ':';
            ++str_pos;
        }
    }

    *str_pos = '\0';
    ++str_pos;

    if (buflen < (u32)(str_pos - addr_str) || (strncpy_s(
        buf, buflen, addr_str, (size_t)(str_pos - addr_str)) != EOK)) {
        return NULL;
    }

    return buf;
}

/* Note: this function has known multi-thread issue, which can only be tolerated
 * when the function is used for log purpose. */
const char *ip6_fuzzy(const spl_ip6_addr_t *addr)
{
    s32 ret;
    static NSFW_THREAD char g_ip6_fuzzy_buffer[SPL_IP6_ADDRESS_STRING_LENGTH];
    char *buf = g_ip6_fuzzy_buffer;

    ret = snprintf_s(buf, SPL_IP6_ADDRESS_STRING_LENGTH, SPL_IP6_ADDRESS_STRING_LENGTH - 1, "%x:%x:***",
                     SPL_IP6_ADDR_BLOCK1(addr), SPL_IP6_ADDR_BLOCK2(addr));
    if (ret > 0) {
        return buf;
    }

    return "*";
}

bool ip6_mask_matches(const spl_ip6_addr_t *ip6addr1, const spl_ip6_addr_t *ip6addr2, u8 masklen)
{
    s32 idx;
    u32 mask;
    u8 tmp_masklen = masklen;

    for (idx = 0; (idx < SPL_IPV6_U32_ARRAY_LENGTH) && (tmp_masklen >= SPL_IPV6_U32_BITS); idx++) {
        if (ip6addr1->addr[idx] != ip6addr2->addr[idx]) {
            return false;
        }

        tmp_masklen -= SPL_IPV6_U32_BITS;
    }

    /* masklen is 128 */
    if (idx == SPL_IPV6_U32_ARRAY_LENGTH) {
        return true;
    }

    /* compare in network order byte */
    mask = spl_htonl((tmp_masklen != 0) ? ((~0U) << (SPL_IPV6_U32_BITS - tmp_masklen)) : 0);

    return (ip6addr1->addr[idx] & mask) == (ip6addr2->addr[idx] & mask);
}

