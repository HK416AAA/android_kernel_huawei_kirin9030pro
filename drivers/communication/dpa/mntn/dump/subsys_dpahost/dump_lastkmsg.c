/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2025. All rights reserved.
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

#include <linux/types.h>
#include <securec.h>
#include <linux/kmsg_dump.h>
#include <linux/vmalloc.h>
#include <bsp_dump.h>
#include <dump_errno.h>
#include <dump_infra.h>
#include <dump_subsys_mgr.h>
#include <dump_logs.h>
#include <dump_log_parser.h>

#define DUMP_CFG_LASTKMSG_SIZE_MAX 0x20000
#define DUMP_CFG_LASTKMSG_SIZE_MIN 0x10000

/* 不响应kmsg dump回调，只在dpa异常时自行保存kmsg */
static void dump_kmsg_stdout(struct kmsg_dumper *dumper, enum kmsg_dump_reason reason)
{
    UNUSED(dumper);
    UNUSED(reason);
    return;
}

static struct kmsg_dumper g_dump_kmsg_dumper = {
    .dump = dump_kmsg_stdout
};

void dump_save_lastkmsg(const char *dir_name)
{
    size_t text_len;
    size_t size = DUMP_CFG_LASTKMSG_SIZE_MAX;
    u8 *addr = vmalloc(size);
    struct parsefile_info_s outfile_info = { 0 };

    if (addr == NULL) {
        size = DUMP_CFG_LASTKMSG_SIZE_MIN;
        addr = vmalloc(size);
    }
    if (addr == NULL) {
        return;
    }
    g_dump_kmsg_dumper.active = true;
    kmsg_dump_rewind(&g_dump_kmsg_dumper);
    kmsg_dump_get_buffer(&g_dump_kmsg_dumper, false, addr, size, &text_len);
    g_dump_kmsg_dumper.active = false;
    text_len = (text_len >= size) ? size : text_len; // kernel接口理论上走不到这一步
    
    outfile_info.file_len = text_len + sizeof(outfile_info);
    outfile_info.parse_flag = 0;
    if (strncpy_s(outfile_info.file_name, DUMP_FILE_NAME_MAX_SIZE, "dpa_lastkmsg", strlen("dpa_lastkmsg")) != EOK) {
        dump_error("err\n");
    }
    dump_log_save(dir_name, "dpa_dump.txt", (const void *)&outfile_info, sizeof(outfile_info));
    dump_log_save(dir_name, "dpa_dump.txt", addr, text_len);
    vfree(addr);
}

__init int dump_lastkmsg_init(void)
{
    /* 看kernel kmsg_dump_rewind和kmsg_dump_get_buffer源码，自行dump kmsg时不需要kmsg_dump_register注册到kernel，
     * 但是这两个接口说明中，要求传入的dumper是注册了的，因此这里也注册一下，防止后续出现问题
     */
    kmsg_dump_register(&g_dump_kmsg_dumper);
    bsp_dpa_dump_register_log_notifier(DUMP_SAVE_HOST_KMSG, dump_save_lastkmsg);

    return DUMP_OK;
}