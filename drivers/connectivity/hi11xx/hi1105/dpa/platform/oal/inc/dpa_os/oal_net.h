/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: oal_dpa_net.h
 * Author: dpa drivers
 */

#ifndef OAL_DPA_NET_H
#define OAL_DPA_NET_H

/* 其他头文件包含 */
#include "oal_types.h"
#include "oal_util.h"
#include "hcc_comm.h"
#include "sbuf_api.h"
#include "atomic.h"
#include "mdrv_sys.h"

#define OAL_SBUF_CB_MAX_LEN       SBUF_USER_DATA_MAX_LEN
#define OAL_SUB_HEADROOM_MAX_LEN  SBUF_DATA_HEADROOM_MAX_LEN
#define OAL_SBUF_DATA_MAX_LEN     SBUF_DATA_MAX_LEN

#define DPA_SBUF_FLOWCTRL_ON    400
#define DPA_SBUF_FLOWCTRL_OFF   50

typedef struct sbuf oal_netbuf_stru;
// netbuf使用的是maa地址， 为DDR上64位空间
typedef u64 netbuf_data_addr;

/*
 * 函 数 名  : oal_netbuf_alloc
 * 功能描述  : 申请netbuf以及 maa内存空间
 * 输入参数  : maa空间大小, dpa上约束最大位1536Byte
 */
static inline oal_netbuf_stru *oal_netbuf_alloc(uint32_t size)
{
    // DPA初始化流程对maa内存整体做smmu平映射，故后续maa内存流转无需感知smmu，直接使用即可
    return alloc_sbuf(size);
}

/*
 * 函 数 名  : oal_netbuf_alloc_data
 * 功能描述  : 申请netbuf 数据段 maa内存，返回起始地址
 *             起始地址前会预留128字节的头，通过地址偏移访问
 * 输入参数  : size: maa地址长度
 */
static inline netbuf_data_addr oal_netbuf_alloc_data(uint32_t size)
{
    return alloc_data(size);
}

/*
 * 函 数 名  : oal_netbuf_build
 * 功能描述  : 通过maa构建报文结构体内存空间
 * 输入参数  : addr: maa内存地址 size: maa内存大小
 */
static inline oal_netbuf_stru *oal_netbuf_build(uint64_t addr, unsigned int size)
{
    return build_sbuf(addr, size);
}

/*
 * 函 数 名  : oal_netbuf_free_data
 * 功能描述  : 释放maa 内存
 * 输入参数  : addr: maa地址
 */
static inline void oal_netbuf_free_data(netbuf_data_addr addr)
{
    return free_data(addr);
}

/*
 * 函 数 名  : oal_netbuf_free
 * 功能描述  : 释放报文结构体内存空间以及maa地址空间
 * 输入参数  : netbuf: 报文结构体指针
 */
static inline void oal_netbuf_free(oal_netbuf_stru *netbuf)
{
    return free_sbuf(netbuf);
}

/*
 * 函 数 名  : oal_netbuf_destory
 * 功能描述  : 仅释放报文本身结构体，返回maa地址空间
 * 输入参数  : netbuf: 报文结构体指针
 */
static inline netbuf_data_addr oal_netbuf_destory(oal_netbuf_stru *netbuf)
{
    return destroy_sbuf(netbuf);
}

/*
 * 函 数 名  : oal_netbuf_len
 * 功能描述  : 获取netbuf 数据段大小
 * 输入参数  : netbuf: 报文结构体指针
 */
static inline uint32_t oal_netbuf_len(oal_netbuf_stru *netbuf)
{
    return sbuf_len(netbuf);
}

/*
 * 函 数 名  : oal_netbuf_data
 * 功能描述  : 获取sbuf 数据地址
 * 输入参数  : netbuf: 报文结构体指针
 */
static inline netbuf_data_addr oal_netbuf_data(oal_netbuf_stru *netbuf)
{
    return (netbuf_data_addr)sbuf_data(netbuf);
}

/*
 * 函 数 名  : oal_netbuf_maa_data
 * 功能描述  : 获取sbuf 数据io 地址
 * 输入参数  : netbuf: 报文结构体指针
 */
static inline netbuf_data_addr oal_netbuf_data_iova(oal_netbuf_stru *netbuf)
{
    return (netbuf_data_addr)sbuf_data_iova(netbuf);
}

/*
 * 函 数 名  : oal_netbuf_header
 * 功能描述  : 获取sbuf header 地址
 * 输入参数  : netbuf: 报文结构体指针
 */
static inline netbuf_data_addr oal_netbuf_header(oal_netbuf_stru *netbuf)
{
    return (netbuf_data_addr)sbuf_headrroom_addr(netbuf);
}

/*
 * 函 数 名  : oal_sbuf_cb
 * 功能描述  : 获取CB 地址空间(dpa上固定位128字节)
 * 输入参数  : netbuf: 报文结构体指针
 */
static inline uint8_t *oal_sbuf_cb(oal_netbuf_stru *netbuf)
{
    return (uint8_t *)get_userdata(netbuf);
}

/*
 * 函 数 名  : oal_netbuf_pull
 * 功能描述  : 缓冲区data段开头减少数据， 返回修改后的data地址
 * 输入参数  : netbuf: 缓冲区结构体指针
 *             len: 减小的数据大小
 */
static inline netbuf_data_addr oal_netbuf_pull(oal_netbuf_stru *netbuf, uint32_t len)
{
    return sbuf_pull(netbuf, len);
}

/*
 * 函 数 名  : oal_netbuf_push
 * 功能描述  : 缓冲区data段开头增加数据， 返回修改后的data地址
 * 输入参数  : netbuf: 缓冲区结构体指针
 *             len: 增加的数据大小
 */
static inline netbuf_data_addr oal_netbuf_push(oal_netbuf_stru *netbuf, uint32_t len)
{
    return sbuf_push(netbuf, len);
}

/*
 * 函 数 名  : oal_netbuf_trim
 * 功能描述  : 缓冲区data段末尾减少数据
 * 输入参数  : netbuf: 缓冲区结构体指针
 *            len: 移除尾部后，剩余的长度
 */
static inline void oal_netbuf_trim(oal_netbuf_stru *netbuf, uint32_t len)
{
    sbuf_trim(netbuf, len);
}

/*
 * 函 数 名  : oal_netbuf_put
 * 功能描述  : 缓冲区data段末尾增加数据, 返回添加数据的第一个字节位置
 * 输入参数  : netbuf: 缓冲区结构体指针，以及增加的数据大小
 *            len: 增加的数据大小
 */
static inline netbuf_data_addr oal_netbuf_put(oal_netbuf_stru *netbuf, uint32_t len)
{
    return sbuf_put(netbuf, len);
}

/*
 * 函 数 名  : oal_netbuf_headroom
 * 功能描述  : 获取缓冲区头部空间的长度, sbuf初始化默认为128字节
 * 输入参数  : netbuf: 缓冲区结构体指针
 */
static inline uint32_t oal_netbuf_headroom(oal_netbuf_stru *netbuf)
{
    return (uint32_t)sbuf_headroom(netbuf);
}

#endif
