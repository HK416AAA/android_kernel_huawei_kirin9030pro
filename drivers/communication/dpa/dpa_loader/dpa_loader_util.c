/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
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
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/syscalls.h>
#include <linux/file.h>
#include <linux/uaccess.h>
#include "dpa_loader_util.h"
#include "dpa_loader_err.h"
#include <securec.h>

static const struct img_id_name_tbl g_match_tbl[] = {
    { DPA_IMG_FIRMWARE, DPA_FIRMWARE_IMG_NAME, "/vendor/communication/dpa/firmware/dpa_firmware.bin"},
    { DPA_IMG_LPMCU, DPA_LPMCU_IMG_NAME, "/vendor/communication/dpa/firmware/lpmcu_modem.bin"},
    { DPA_IMG_FW_DTB, DPA_FW_DTB_IMG_NAME, "/vendor/modem/modem_vendor/image/modem_fw_dtb.img"},
    { DPA_IMG_WIFI_MO, DPA_WIFI_MO_IMG_NAME, "/vendor/communication/dpa/firmware/mp1x_wifi.mo"},
};

int dpa_loader_get_img_name(dpa_loader_img_id_e image, char *buffer, unsigned int buffer_len)
{
    u32 i;
    for (i = 0; i < sizeof(g_match_tbl) / sizeof(g_match_tbl[0]); i++) {
        if (g_match_tbl[i].img_type == image) {
            return strcpy_s(buffer, buffer_len, g_match_tbl[i].img_name);
        }
    }

    return -1;
}

const char *dpa_loader_get_img_path(dpa_loader_img_id_e image)
{
    u32 i;
    for (i = 0; i < sizeof(g_match_tbl) / sizeof(g_match_tbl[0]); i++) {
        if (g_match_tbl[i].img_type == image) {
            return g_match_tbl[i].file_path;
        }
    }

    return NULL;
}



