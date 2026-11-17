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
#include "dpa_version.h"
#include "dpa_dmi.h"

static struct dpa_dmi_ops *g_dpa_dmi_ops;

int dpa_dmi_api_register(struct dpa_dmi_ops *dmi_ops)
{
    if (dmi_ops == NULL) {
        return -1;
    }

    g_dpa_dmi_ops = dmi_ops;

    return 0;
}
EXPORT_SYMBOL(dpa_dmi_api_register);

int dpa_dmi_client_init_ops(struct dmi_client *client)
{
    if (g_dpa_dmi_ops == NULL) {
        dpa_err("Not Register dpa dmi API!\n");
        return -ENOSYS;
    }

    if (g_dpa_dmi_ops->dpa_dmi_client_init == NULL) {
        dpa_err("Not Support dpa_dmi_client_init API!\n");
        return -ENOSYS;
    }

    return g_dpa_dmi_ops->dpa_dmi_client_init(client);
}
EXPORT_SYMBOL(dpa_dmi_client_init_ops);

int dpa_dmi_client_register_ops(struct dmi_client *client)
{
    if (g_dpa_dmi_ops == NULL) {
        dpa_err("Not Register dpa dmi API!\n");
        return -ENOSYS;
    }

    if (g_dpa_dmi_ops->dpa_dmi_client_register == NULL) {
        dpa_err("Not Support dpa_dmi_client_register API!\n");
        return -ENOSYS;
    }

    return g_dpa_dmi_ops->dpa_dmi_client_register(client);
}
EXPORT_SYMBOL(dpa_dmi_client_register_ops);

int dpa_dmi_client_request_ops(struct dmi_msg *msg, unsigned int len)
{
    if (g_dpa_dmi_ops == NULL) {
        dpa_err("Not Register dpa dmi API!\n");
        return -ENOSYS;
    }

    if (g_dpa_dmi_ops->dpa_dmi_client_request == NULL) {
        dpa_err("Not Support dpa_dmi_client_request API!\n");
        return -ENOSYS;
    }

    return g_dpa_dmi_ops->dpa_dmi_client_request(msg, len);
}
EXPORT_SYMBOL(dpa_dmi_client_request_ops);

struct dmi_msg *dpa_dmi_msg_alloc_ops(unsigned int dmi_id, unsigned int len)
{
    if (g_dpa_dmi_ops == NULL) {
        dpa_err("Not Register dpa dmi API!\n");
        return NULL;
    }

    if (g_dpa_dmi_ops->dpa_dmi_msg_alloc == NULL) {
        dpa_err("Not Support dpa_dmi_msg_alloc API!\n");
        return NULL;
    }

    return g_dpa_dmi_ops->dpa_dmi_msg_alloc(dmi_id, len);
}
EXPORT_SYMBOL(dpa_dmi_msg_alloc_ops);

int dpa_dmi_msg_free_ops(struct dmi_msg_data *msg)
{
    if (g_dpa_dmi_ops == NULL) {
        dpa_err("Not Register dpa dmi API!\n");
        return -ENOSYS;
    }

    if (g_dpa_dmi_ops->dpa_dmi_msg_free == NULL) {
        dpa_err("Not Support dpa_dmi_msg_free API!\n");
        return -ENOSYS;
    }

    return g_dpa_dmi_ops->dpa_dmi_msg_free(msg);
}
EXPORT_SYMBOL(dpa_dmi_msg_free_ops);

int dpa_dmi_msg_maxsize_ops(void)
{
    if (g_dpa_dmi_ops == NULL) {
        dpa_err("Not Register dpa dmi API!\n");
        return -ENOSYS;
    }

    if (g_dpa_dmi_ops->dpa_dmi_msg_maxsize == NULL) {
        dpa_err("Not Support dpa_dmi_msg_maxsize_ops API!\n");
        return -ENOSYS;
    }

    return g_dpa_dmi_ops->dpa_dmi_msg_maxsize();
}
EXPORT_SYMBOL(dpa_dmi_msg_maxsize_ops);