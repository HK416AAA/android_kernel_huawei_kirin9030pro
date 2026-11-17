/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/* *
 * @brief   PPP_NDIS模块对外头文件
 * @file    mdrv_bmi_ppp_ndis.h
 * @version v1.0
 * @date    2025.02.17
 * @note    该文件增删改需通过接口变更评审
 * <ul><li>v1.0|2025.02.17|创建文件</li></ul>
 * @since
 */

#ifndef __MDRV_BMI_PPP_NDIS_H__
#define __MDRV_BMI_PPP_NDIS_H__

/* *
 * @brief 描述定制网卡类型最大数量
 */ 
#define PPP_NDIS_CUST_NIC_TYPE_MAX_NUM 8

/* *
 * @brief 描述定制某网卡类型支持定制mac地址最大数量
 */ 
#define PPP_NDIS_MAC_ADDR_MAX_NUM 60

/* *
 * @brief 描述定制网卡mac地址长度
 */ 
#define PPP_NDIS_MAC_ADDR_LEN 6

/* *
 * @brief 描述定制网卡地址协议数据结构
 */
struct ppp_ndis_cust_mac_user_data {
    unsigned int nic_type;
    unsigned int cmd_id;
    unsigned int data_len;
    unsigned char data[0];
};

/* *
 * @brief 描述定制网卡类型枚举值
 */ 
enum ppp_ndis_nic_type {
    PPP_NDIS_NIC_TYPE_GMAC = 0,
    PPP_NDIS_NIC_TYPE_USB,
    PPP_NDIS_NIC_TYPE_WIFI,
    PPP_NDIS_NIC_TYPE_PCIE,
    PPP_NDIS_NIC_TYPE_LAST = PPP_NDIS_CUST_NIC_TYPE_MAX_NUM,
};

/* *
 * @brief 描述命令字枚举值
 */
enum ppp_ndis_cust_mac_cmd_id {
    PPP_NDIS_SET_MAC_ADDR = 0,
    PPP_NDIS_GET_MAC_ADDR,
    PPP_NDIS_RESTORE_DEFAULT_MAC_ADDR,
    PPP_NDIS_CMD_ID_LAST,
};

/* *
 * @brief 描述定制单张网卡mac地址数据结构
 */
struct ppp_ndis_set_single_mac_addr_info {
    unsigned char nic_id;
    unsigned char addr[PPP_NDIS_MAC_ADDR_LEN];
} __attribute__((packed));

/* *
 * @brief 描述设置指定网卡类型mac地址数据结构
 */
struct ppp_ndis_set_multi_mac_addr_info {
    unsigned char nic_num;
    struct ppp_ndis_set_single_mac_addr_info addr_infos[0]; // 实际数量为nic_num
} __attribute__((packed));

/* *
 * @brief 描述获取单张网卡mac地址数据结构，由ppp_ndis填充
 */
struct ppp_ndis_get_single_mac_addr_info {
    unsigned char state; // 0：未定制mac地址，1：已定制mac地址
    unsigned char addr[PPP_NDIS_MAC_ADDR_LEN];
} __attribute__((packed));

/* *
 * @brief 描述获取指定网卡类型mac地址数据结构，由ppp_ndis填充
 */
struct ppp_ndis_get_all_mac_addr_info {
    union {
        unsigned char nic_id; // 调用者填充,nic_id:0，返回该网卡类型下所有mac地址
        unsigned char nic_num; // ppp_ndis填充
    };
    struct ppp_ndis_get_single_mac_addr_info addr_infos[PPP_NDIS_MAC_ADDR_MAX_NUM]; // ppp_ndis填充
} __attribute__((packed));

/* *
 * @brief 描述取消定制mac地址数据结构
 */
struct ppp_ndis_restore_default_mac_addr_info {
    unsigned char nic_id; // 0：取消该网卡类型下所有定制mac地址
} __attribute__((packed));

#endif