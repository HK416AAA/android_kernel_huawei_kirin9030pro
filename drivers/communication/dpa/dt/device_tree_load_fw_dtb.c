/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
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
#include "device_tree.h"
#include <bsp_dpa_loader.h>
#include <bsp_sec_call.h>

int bsp_dt_parse_image_by_secos(void)
{
    int ret = 0;
    dt_sec_call_s dt_info;

    dt_info.image_type = DPA_FW_DTB_IMG_TYPE;
    dt_printf("request secos to parse fw_dtb\n");
    ret = bsp_sec_call_ext(FUNC_DTS_LOAD_DT, 0, (void *)&dt_info, sizeof(dt_info));
    if (ret) {
        dt_printf("secos parse fw_dtb failed : %d\n", ret);
        return DTB_ERROR;
    }
    dt_printf("request secos to parse  fw_dtb success\n");

    return DTB_OK;
}

int bsp_dt_load_and_verify_fw_dtb_sec(void)
{
    int ret = 0;

    ret = bsp_dpa_loader_load_and_verify_image(DPA_IMG_FW_DTB);
    if (ret != 0) {
        dt_printf("load verify fw_dtb failed, ret = %d \n", ret);
        return ret;
    }

    ret = bsp_dt_parse_image_by_secos();
    if (ret != 0) {
        return DTB_ERROR;
    }

    dt_printf("load verify fw_dtb success\n");
    return DTB_OK;
}

int bsp_fw_dt_init(void)
{
    int ret = 0;

    ret = bsp_dt_load_and_verify_fw_dtb_sec();
    if (ret) {
        dt_printf("load fw_dtb fail, ret = %d\n", ret);
        return ret;
    }

    return DTB_OK;
}
