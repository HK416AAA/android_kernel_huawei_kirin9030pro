/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: oal_util.h
 * Author: dpa drivers
 */

#ifndef OAL_UTIL_H
#define OAL_UTIL_H

#include "dpa_os/oal_util.h"
#include "bsp_print.h"
#include "bsp_record.h"
#include "oal_types.h"
#include "securec.h"
#include "oal_mm.h"

/* STRUCT定义 */
#define MPXX_LOG_ERR     0
#define MPXX_LOG_WARN    1
#define MPXX_LOG_INFO    2
#define MPXX_LOG_DBG     3
#define MPXX_LOG_VERBOSE 4

#ifndef MPXX_LOG_MODULE_NAME
#define MPXX_LOG_MODULE_NAME "[MPXX]"
extern int32_t g_mpxx_loglevel;
#endif

#ifndef MPXX_LOG_MODULE_NAME_VAR
#define MPXX_LOG_MODULE_NAME_VAR g_mpxx_loglevel
extern int32_t g_mpxx_loglevel;
#else
static int32_t MPXX_LOG_MODULE_NAME_VAR = MPXX_LOG_INFO;
#endif

#define MPXX_LOGLEVEL_FORMAT 5
extern char *g_mpxx_loglevel_format[MPXX_LOGLEVEL_FORMAT];

#define oal_print_mpxx_serial_log(loglevel, fmt, arg...)   \
    do {                                                                    \
        if (oal_unlikely(MPXX_LOG_MODULE_NAME_VAR >= loglevel)) {         \
            bsp_print("%s%s" fmt "[%s:%d]\n",                                  \
                g_mpxx_loglevel_format[loglevel], MPXX_LOG_MODULE_NAME, \
                ##arg, __FUNCTION__, __LINE__);                             \
        }                                                                   \
    } while (0)

#define oal_print_mpxx_log(loglevel, fmt, arg...)                         \
    do {                                                                    \
        if (oal_unlikely(MPXX_LOG_MODULE_NAME_VAR >= loglevel)) {         \
            if (loglevel == MPXX_LOG_ERR) bsp_dpa_record("[E]" fmt, ##arg); \
            else if (loglevel == MPXX_LOG_WARN) bsp_dpa_record("[W]" fmt, ##arg); \
            else if (loglevel == MPXX_LOG_INFO) bsp_dpa_record("[I]" fmt, ##arg); \
            else bsp_dpa_record("[D]" fmt, ##arg); \
        }                                                                   \
    } while (0)

#define oal_array_size(_ast_array) (sizeof(_ast_array) / sizeof((_ast_array)[0]))

// dead loop
#define forever_loop()  for (;;)

#define ADDR_HIGH(addr) (uint32_t)((addr) >> 32)    /* 右移32位取高位，注意入参需为64位 */
#define ADDR_LOW(addr) (uint32_t)(addr)             /* 取64位地址低位 */

/* 用作oal_print_hex_dump()的第三个参数，因为函数并没有用到该参数，所以定义成固定值 */
#define HEX_DUMP_GROUP_SIZE 32
#define OAL_MAC_ADDRESS_LEN 6
#define NUM_32_BYTES 32
#define NUM_16_BITS  16

#ifndef BIT
#define BIT(nr) (1UL << (nr))
#endif

#define oal_make_word64(lsw, msw)           ((((uint64_t)(msw) << 32) & 0xFFFFFFFF00000000) | (lsw))

#define oal_any_null_ptr1(_ptr1)                      (((_ptr1) == NULL))
#define oal_any_null_ptr2(_ptr1, _ptr2)               (((_ptr1) == NULL) || ((_ptr2) == NULL))
#define oal_any_null_ptr3(_ptr1, _ptr2, _ptr3)        (((_ptr1) == NULL) || ((_ptr2) == NULL) || ((_ptr3) == NULL))

#define oal_container_of(_member_ptr, _stru_type, _stru_member_name) \
    ((_stru_type *)((uintptr_t)(_member_ptr) - (uintptr_t)(&((_stru_type *)0)->_stru_member_name)))

OAL_STATIC OAL_INLINE void oal_bit_set_bit_four_byte(uint32_t *pul_byte, oal_bitops nr)
{
    *pul_byte |= ((uint32_t)(1 << nr));
}
OAL_STATIC OAL_INLINE void oal_bit_clear_bit_four_byte(uint32_t *pul_byte, oal_bitops nr)
{
    *pul_byte &= ~((uint32_t)(1 << nr));
}

static inline void oal_addr32_to_addr64(uint32_t addr_32, uint64_t *addr_64)
{
    uint32_t addr_l = addr_32;
    uint64_t addr_h = 0;
    *addr_64 = ((addr_h << 32) | addr_l);   // 高位左移32位
}

OAL_STATIC OAL_INLINE int oal_memcmp(const void *p_buf1, const void *p_buf2, uint32_t ul_count)
{
    if (p_buf1 == NULL || p_buf2 == NULL) {
        return -OAL_EINVAL;
    }
    return memcmp(p_buf1, p_buf2, ul_count);
}

OAL_STATIC OAL_INLINE void oal_set_mac_addr(unsigned char *puc_mac_addr1, const unsigned char *puc_mac_addr2)
{
    if (memcpy_s(puc_mac_addr1, OAL_MAC_ADDRESS_LEN, puc_mac_addr2, OAL_MAC_ADDRESS_LEN) != EOK) {
    }
}
OAL_STATIC OAL_INLINE uint32_t oal_compare_mac_addr(const unsigned char *puc_mac_addr1,
                                                    const unsigned char *puc_mac_addr2)
{
    return (uint32_t)oal_memcmp((void *)puc_mac_addr1, (void *)puc_mac_addr2, OAL_MAC_ADDRESS_LEN);
}
OAL_STATIC OAL_INLINE void oal_set_mac_addr_zero(unsigned char *puc_mac_addr)
{
    memset_s(puc_mac_addr, OAL_MAC_ADDRESS_LEN, 0, OAL_MAC_ADDRESS_LEN);
}
OAL_STATIC OAL_INLINE uint16_t oal_byteorder_host_to_net_uint16(uint16_t us_byte)
{
    us_byte = ((us_byte & 0x00FF) << 8) + ((us_byte & 0xFF00) >> 8);

    return us_byte;
}
/*
 * 函 数 名  : oal_get_lut_index
 * 功能描述  : 从LUT index bitmap表中，获取一个没有被使用的索引，没有找到的话，
 *             返回不可用的索引标识(非关键路径，未进行优化，有时间可以优化)
 */
OAL_STATIC OAL_INLINE uint8_t oal_get_lut_index(uint8_t *puc_lut_index_table,
                                                uint8_t uc_bmap_len,
                                                uint16_t us_max_lut_size,
                                                uint16_t us_start,
                                                uint16_t us_stop)
{
    uint8_t uc_byte = 0;
    uint8_t uc_bit = 0;
    uint8_t uc_temp = 0;
    uint16_t us_index = 0;

    if (oal_unlikely(puc_lut_index_table == NULL)) {
        return 0;
    }

    for (uc_byte = 0; uc_byte < uc_bmap_len; uc_byte++) {
        uc_temp = puc_lut_index_table[uc_byte];

        for (uc_bit = 0; uc_bit < 8; uc_bit++) { /* 以一个bit为单位遍历某一位为0 */
            if ((uc_temp & (1 << uc_bit)) == 0x0) {
                us_index = (uc_byte * 8 + uc_bit); /* 算出为0的bit位的位数 */
                if ((us_index < us_start) || (us_index >= us_stop)) {
                    continue;
                }
                if (us_index < us_max_lut_size) {
                    puc_lut_index_table[uc_byte] |= (uint8_t)(1 << uc_bit);

                    return (uint8_t)us_index;
                } else {
                    return (uint8_t)us_max_lut_size;
                }
            }
        }
    }

    return (uint8_t)us_max_lut_size;
}

/*
 * 函 数 名  : oal_del_lut_index
 * 功能描述  : 在LUT index bitmap表中，删除一个LUT index (注:%可以作为优化项)
 */
OAL_STATIC OAL_INLINE void oal_del_lut_index(uint8_t *puc_lut_index_table, uint8_t uc_idx)
{
    uint8_t uc_byte = uc_idx >> 3;
    uint8_t uc_bit = uc_idx & 0x07;

    if (oal_unlikely(puc_lut_index_table == NULL)) {
        return;
    }

    puc_lut_index_table[uc_byte] &= (uint8_t)(~(uint8_t)(1 << uc_bit));
}

void oal_print_hex_dump(uint8_t *addr, int32_t len, int32_t groupsize, const char *pre_str);
uint8_t oal_bit_find_first_bit_four_byte(uint32_t byte);
uint8_t oal_bit_find_first_zero_four_byte(uint32_t byte);
#endif