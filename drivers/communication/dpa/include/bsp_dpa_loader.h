/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2020. All rights reserved.
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

#ifndef _BSP_DPA_LOADER_H_
#define _BSP_DPA_LOADER_H_

#define DPA_SECBOOT_VRL_SIZE 0x2000

typedef enum {
    DPA_IMG_FIRMWARE = 0,
    DPA_IMG_LPMCU,
    DPA_IMG_FW_DTB,
    DPA_IMG_WIFI_MO,

    DPA_IMG_MAX,
} dpa_loader_img_id_e;

/* ****************************************************************************
 * Attention   END                        *
 * ****************************************************************************/

/**
 * @brief 从flash加载并校验镜像（包括VRL头+镜像内容）。
 *
 * @par 描述:
 * 从flash加载并校验镜像（包括VRL头+镜像内容），加载地址在内存布局中已确定，调用者不可见。
 *
 * @param[in]  image：镜像标识，每个镜像唯一，只能在dpa_host目录，
 * 
 * @retval <0，表示函数执行失败。
 * @retval =0，表示函数执行成功。
 *
 * @attention
 * <ul><li>镜像不支持压缩</li></ul>
 *
 * @see  image：取值范围见dpa_loader_img_id_e
 */
int bsp_dpa_loader_load_and_verify_image(dpa_loader_img_id_e image);

/**
 * @brief 校验镜像（包括VRL头+镜像内容）。
 *
 * @par 描述:
 * 调用者提前将镜像读取到buffer，buffer中数据包含vrl头+镜像内容，该接口不从flash中读取镜像。
 *
 * @param[in]  image：镜像标识，每个镜像唯一，只能在dpa_host目录；
 * img_data：存放镜像内容的内存空间；
 * img_size：buffer空间大小；
 *
 * @retval <0，表示函数执行失败。
 * @retval =0，表示函数执行成功。
 *
 * @attention
 * <ul><li>镜像不支持压缩</li></ul>
 *
 * @see  image：取值范围见dpa_loader_img_id_e
 */
int bsp_dpa_loader_copy_and_verify_image(dpa_loader_img_id_e image, const char *img_data,
    u32 img_size);

/**
 * @brief dpa loader状态复位。
 *
 * @par 描述:
 * dpa loader状态复位接口，在加载dpa子系统镜像加载控制流程入口处调用调用该接口
 *
 * 
 * @retval <0，表示函数执行失败。
 * @retval =0，表示函数执行成功。
 *
 * @attention
 * <ul><li>镜像不支持压缩</li></ul>
 *
 * @see  image：取值范围见dpa_loader_img_id_e
 */
int bsp_dpa_loader_reset(void);

#endif
