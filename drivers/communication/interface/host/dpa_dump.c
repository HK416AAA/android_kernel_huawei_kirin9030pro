/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2025. All rights reserved.
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
#include "dpa_dump.h"
#include "dpa_version.h"

static const struct dpa_dump_ops *g_dpa_dump_ops;

int dpa_dump_api_register(const struct dpa_dump_ops *dump_ops)
{
    if (dump_ops == NULL) {
        return -1;
    }

    g_dpa_dump_ops = dump_ops;

    return 0;
}
EXPORT_SYMBOL(dpa_dump_api_register);

int dpa_dump_dpa_system_error_ops(unsigned int mod_id, unsigned int arg1, unsigned int arg2, char *arg3_virt_addr, unsigned int arg3_length)
{
    if (g_dpa_dump_ops == NULL) {
        dpa_err("Not Register dpa dump API!\n");
        return -ENOSYS;
    }

    if (g_dpa_dump_ops->dpa_system_error == NULL) {
        dpa_err("Not Support dpa_system_error API!\n");
        return -ENOSYS;
    }

    g_dpa_dump_ops->dpa_system_error(mod_id, arg1, arg2, arg3_virt_addr, arg3_length);
    return 0;
}
EXPORT_SYMBOL(dpa_dump_dpa_system_error_ops);

unsigned char *dpa_dump_register_field_ops(unsigned int field_id, const char *field_name, unsigned int length, unsigned short version)
{
    if (g_dpa_dump_ops == NULL) {
        dpa_err("Not Register dpa dump API!\n");
        return NULL;
    }

    if (g_dpa_dump_ops->bsp_dpa_dump_register_field == NULL) {
        dpa_err("Not Support bsp_dpa_dump_register_field API!\n");
        return NULL;
    }

    return g_dpa_dump_ops->bsp_dpa_dump_register_field(field_id, field_name, length, version);
}
EXPORT_SYMBOL(dpa_dump_register_field_ops);

int dpa_dump_register_hook_ops(const char *name, dump_hook p_func)
{
    if (g_dpa_dump_ops == NULL) {
        dpa_err("Not Register dpa dump API!\n");
        return -1;
    }

    if (g_dpa_dump_ops->bsp_dpa_dump_register_hook == NULL) {
        dpa_err("Not Support bsp_dpa_dump_register_hook API!\n");
        return -1;
    }

    return g_dpa_dump_ops->bsp_dpa_dump_register_hook(name, p_func);
}
EXPORT_SYMBOL(dpa_dump_register_hook_ops);