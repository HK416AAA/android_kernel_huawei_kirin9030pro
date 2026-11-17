/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description:oal_util.c
 * Author: dpa drivers
 */

#include "oal_util.h"

OAL_STATIC int32_t oal_print_hex_dump_row(uint8_t *addr, int32_t row_size)
{
    int32_t i;
    for (i = 0; i < row_size; i++) {
        oal_io_print("%x ", addr[i]);
    }
    return i;
}

void oal_print_hex_dump(uint8_t *addr, int32_t len, int32_t groupsize, const char *pre_str)
{
    int32_t i, j, remain;
    j = 0;
    if (len == 0) {
        return;
    }
    if (!groupsize) {
        groupsize = 1;
    }
    remain = len;
    bsp_print("%s,dump addr 0x%x,len:%d"NEWLINE, pre_str, (uint32_t)addr, len);
    for (i = 0; i < len; i += groupsize, j++) {
        bsp_print("[%d] ", j);
        remain -= oal_print_hex_dump_row(addr + i, oal_min(remain, groupsize));
        bsp_print(""NEWLINE);
        if (remain <= 0) {
            break;
        }
    }
}

/*
 * 函 数 名  : oal_bit_find_first_bit_one_byte
 * 功能描述  : 找到1字节右数第一个是1的位数
 * 输入参数  : uc_byte: 要查找的字节
 * 返 回 值  : 右数第一个是1的位数
 */
uint8_t oal_bit_find_first_bit_four_byte(uint32_t byte)
{
    uint8_t ret = 0;

    if (byte == 0) {
        return ret;
    }

    if (!(byte & 0xffff)) {
        byte >>= 16; /* 说明32bit数据的低16bit全为0，所以可以直接从高16bit开始找为1的位数 */
        ret += 16;
    }

    if (!(byte & 0xff)) {
        byte >>= 8; /* 说明16bit数据的低8bit全为0，所以可以直接从高8bit开始找为1的位数 */
        ret += 8;
    }

    if (!(byte & 0xf)) {
        byte >>= 4; /* 说明8bit数据的低4bit全为0，所以可以直接从高4bit开始找为1的位数 */
        ret += 4;
    }

    if (!(byte & 0x3)) {
        byte >>= 2; /* 说明4bit数据的低2bit全为0，所以可以直接从高2bit开始找为1的位数 */
        ret += 2;
    }

    if (!(byte & 1)) {
        ret += 1;
    }

    return ret;
}

/*
 * 函 数 名  : oal_bit_find_first_zero_four_byte
 * 功能描述  : 找到1字节右数第一个是0的位数
 * 输入参数  : puc_byte: 要查找的字节
 * 返 回 值  : 右数第一个是0的位数
 */
uint8_t oal_bit_find_first_zero_four_byte(uint32_t byte)
{
    uint8_t uc_ret = 0;

    byte = ~byte;

    if (!(byte & 0xffff)) {
        byte >>= 16; /* 说明32bit数据的低16bit全为1，所以可以直接从高16bit开始找为0的位数 */
        uc_ret += 16;
    }

    if (!(byte & 0xff)) {
        byte >>= 8; /* 说明16bit数据的低8bit全为1，所以可以直接从高8bit开始找为0的位数 */
        uc_ret += 8;
    }

    if (!(byte & 0xf)) {
        byte >>= 4; /* 说明8bit数据的低4bit全为1，所以可以直接从高4bit开始找为0的位数 */
        uc_ret += 4;
    }

    if (!(byte & 0x3)) {
        byte >>= 2; /* 说明4bit数据的低2bit全为1，所以可以直接从高2bit开始找为0的位数 */
        uc_ret += 2;
    }

    if (!(byte & 1)) {
        uc_ret += 1;
    }

    return uc_ret;
}