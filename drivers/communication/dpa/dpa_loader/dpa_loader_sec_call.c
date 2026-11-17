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

#include <teek_client_id.h>
#include <teek_client_api.h>

#include "bsp_dpa_loader.h"
#include "dpa_loader_load_image.h"
#include "dpa_loader_err.h"
#include "dpa_loader_sec_call.h"
#include <platform_include/see/sec_auth_ca.h> /* phone struct */

#define SEC_AUTH_TA_UUID TEE_SERVICE_SECAUTH
#define SEC_AUTH_TA_NAME "sec_auth"
#define SEC_BOOT_TA_UUID TEE_SERVICE_SECBOOT
#define SEC_BOOT_TA_NAME "sec_boot"

static struct teec_session g_dpa_loader_sec_auth_session; // 加载安全启动镜像使用
static struct teec_context g_dpa_loader_sec_auth_context; // 加载安全启动镜像使用
static struct teec_session g_dpa_loader_sec_boot_session; // 加载so镜像使用
static struct teec_context g_dpa_loader_sec_boot_context; // 加载so镜像使用

int dpa_loader_teek_init(struct teec_uuid uuid, const char *ta_name,
            struct teec_session *session, struct teec_context *context)
{
    uint32_t result;
    struct teec_uuid svc_uuid = uuid;
    struct teec_operation operation = { 0 };
    const char *package_name = ta_name;
    u32 root_id = 0;

    result = teek_initialize_context(NULL, context);
    if (result != TEEC_SUCCESS) {
        /* cov_verified_start */
        dpa_loader_print_err("fail to init teek context, result = 0x%x\n", result);
        goto error;
        /* cov_verified_stop */
    }

    operation.started = 1;
    operation.cancel_flag = 0;
    operation.paramtypes =
        (uint32_t)TEEC_PARAM_TYPES(TEEC_NONE, TEEC_NONE, TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT); /*lint !e845*/

    operation.params[2U].tmpref.buffer = (void *)&root_id;
    operation.params[2U].tmpref.size = sizeof(root_id);
    operation.params[3U].tmpref.buffer = (void *)package_name;
    operation.params[3U].tmpref.size = strlen(package_name) + 1;
    result = teek_open_session(context, session, &svc_uuid, TEEC_LOGIN_IDENTIFY, NULL, &operation,
        NULL);
    if (result != TEEC_SUCCESS) {
        /* cov_verified_start */
        dpa_loader_print_err("fail to open teek session, result = 0x%x\n", result);
        teek_finalize_context(context);
        /* cov_verified_stop */
    }

error:
    return (int)result;
}

int dpa_loader_verify_prepare(dpa_loader_img_id_e image)
{
    uint32_t result;
    uint32_t origin = 0;
    struct teec_operation operation = { 0 };
    struct image_id_t id = {
        .partition_name = DPA_PARTITION_NA,
    };

    if (dpa_loader_get_img_name(image, id.image_name, sizeof(id.image_name))) {
        return -1;
    }

    operation.started = 1;
    operation.cancel_flag = 0;
    operation.paramtypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
    operation.params[0].tmpref.buffer = (void *)&id;
    operation.params[0].tmpref.size = sizeof(id);

    dpa_loader_print_err("img_name:%s, partition_name:%s\n", id.image_name, id.partition_name);

    result = teek_invoke_command(&g_dpa_loader_sec_auth_session, SEC_AUTH_CMD_ID_INIT, &operation, &origin);
    if (result != TEEC_SUCCESS) {
        dpa_loader_print_err("fail to invoke teek command, result = 0x%x\n", result);
    }

    return (int)result;
}

int dpa_loader_trans_vrl_to_os(dpa_loader_img_id_e image, void *buf, const u32 len)
{
    uint32_t result;
    uint32_t origin = 0;
    struct teec_operation operation = { 0 };
    struct image_id_t id = {
        .partition_name = DPA_PARTITION_NA,
    };

    if (dpa_loader_get_img_name(image, id.image_name, sizeof(id.image_name))) {
        return -1;
    }

    operation.started = 1;
    operation.cancel_flag = 0;
    operation.paramtypes =
        (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE);
    operation.params[0].tmpref.buffer = (void *)&id;
    operation.params[0].tmpref.size = sizeof(id);
    operation.params[1].tmpref.buffer = buf;
    operation.params[1].tmpref.size = len;

    result = teek_invoke_command(&g_dpa_loader_sec_auth_session, SEC_AUTH_CMD_ID_READ_CERT, &operation, &origin);
    if (result != TEEC_SUCCESS) {
        dpa_loader_print_err("fail to invoke teek command, result = 0x%x\n", result);
    }

    return (int)result;
}

int dpa_loader_trans_data_to_os(dpa_loader_img_id_e image, void *buf, const u32 offset, const u32 len)
{
    uint32_t result;
    uint32_t origin = 0;
    struct teec_operation operation = { 0 };
    struct image_id_t id = {
        .partition_name = DPA_PARTITION_NA,
    };

    if (dpa_loader_get_img_name(image, id.image_name, sizeof(id.image_name))) {
        return -1;
    }

    operation.started = 1;
    operation.cancel_flag = 0;
    operation.paramtypes =
        (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_MEMREF_TEMP_INPUT, TEEC_VALUE_INPUT, TEEC_NONE);
    operation.params[0].tmpref.buffer = (void *)&id;
    operation.params[0].tmpref.size = sizeof(id);
    operation.params[1].tmpref.buffer = buf;
    operation.params[1].tmpref.size = len;
    operation.params[2U].value.a = offset;
    operation.params[2U].value.b = 0;

    result = teek_invoke_command(&g_dpa_loader_sec_auth_session, SEC_AUTH_CMD_ID_READ_DATA, &operation, &origin);
    if (result != TEEC_SUCCESS) {
        dpa_loader_print_err("fail to invoke teek command, result = 0x%x\n", result);
    }

    return (int)result;
}

int dpa_loader_verify_soc_image(dpa_loader_img_id_e image)
{
    uint32_t result;
    struct teec_operation operation = { 0 };
    uint32_t origin = 0;
    struct authed_data out = { 0 };
    struct image_id_t id = {
        .partition_name = DPA_PARTITION_NA,
    };

    if (dpa_loader_get_img_name(image, id.image_name, sizeof(id.image_name))) {
        return -1;
    }

    operation.started = 1;
    operation.cancel_flag = 0;
    operation.paramtypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEE_PARAM_TYPE_MEMREF_INOUT, TEEC_NONE,
        TEEC_NONE);
    operation.params[0].tmpref.buffer = (void *)&id;
    operation.params[0].tmpref.size = sizeof(id);
    operation.params[1].tmpref.buffer = (void *)&out;
    operation.params[1].tmpref.size = sizeof(out);
    result = teek_invoke_command(&g_dpa_loader_sec_auth_session, SEC_AUTH_CMD_ID_VERIFY, &operation, &origin);

    if (result != TEEC_SUCCESS) {
        dpa_loader_print_err("fail to verify image %d, result = 0x%x\n", image, result);
        return (int)result;
    }
    dpa_loader_print_err("succeed to verify image %d\n", image);

    operation.paramtypes =
        (uint32_t)TEEC_PARAM_TYPES(TEEC_MEMREF_TEMP_INPUT, TEEC_NONE, TEEC_NONE, TEEC_NONE);
    result = teek_invoke_command(&g_dpa_loader_sec_auth_session, SEC_AUTH_CMD_ID_FINAL, &operation, &origin);
    if (result != TEEC_SUCCESS) {
        dpa_loader_print_err("auth final result = 0x%x\n", result);
    }
    return (int)result;
}

int dpa_loader_sec_prepare(dpa_loader_img_id_e image)
{
    return dpa_loader_verify_prepare(image);
}

int dpa_loader_sec_copy_vrl(dpa_loader_img_id_e image, void *buf, const u32 len)
{
    return dpa_loader_trans_vrl_to_os(image, buf, len);
}

int dpa_loader_sec_copy_data(dpa_loader_img_id_e image, void *buf, const u32 ddr_offset, const u32 len)
{
    return dpa_loader_trans_data_to_os(image, buf, ddr_offset, len);
}
int dpa_loader_sec_verify(dpa_loader_img_id_e image)
{
    return dpa_loader_verify_soc_image(image);
}

int dap_loader_trans_secfile_to_os(const char *file_buffer, unsigned int file_size)
{
    if (file_buffer == NULL) {
        dpa_pr_err("file buffer is NULL,please check\n");
        return -1;
    }

    return (int)teek_send_secfile(&g_dpa_loader_sec_boot_session, file_buffer, file_size);
}

int dpa_loader_load_teeos_img(void)
{
    struct teec_session *session = &g_dpa_loader_sec_boot_session;
    uint32_t result;
    struct teec_operation operation = { 0 };
    uint32_t origin = 0;

    operation.started = 1;
    operation.cancel_flag = 0;
    operation.paramtypes = (uint32_t)TEEC_PARAM_TYPES(TEEC_NONE, TEEC_NONE, TEEC_NONE, TEEC_NONE);
    result = teek_invoke_command(session, SECBOOT_CMD_ID_BSP_LOAD_MODEM_TEEOS, &operation, &origin);
    if (result != TEEC_SUCCESS) {
        dpa_pr_err("load modem teeos failed, ret = 0x%x\n", result);
        return (int)result;
    }
    return (int)result;
}

int dap_loader_boot_teek_init(void)
{
    int ret;
    struct teec_uuid sec_boot_uuid = SEC_BOOT_TA_UUID;

    ret = dpa_loader_teek_init(sec_boot_uuid, SEC_BOOT_TA_NAME,
            &g_dpa_loader_sec_boot_session, &g_dpa_loader_sec_boot_context);
    if (ret) {
        dpa_loader_print_err("fail to open sec auth session, ret = %d\n", ret);
        return ret;
    }

    dpa_loader_print_err("dpa_loader secboot verifier init ok\n");
    return ret;
}

void dpa_loader_boot_teek_uninit(void)
{
    teek_close_session(&g_dpa_loader_sec_boot_session);
    teek_finalize_context(&g_dpa_loader_sec_boot_context);
}

int dpa_loader_verifier_init(void)
{
    int ret;
    struct teec_uuid sec_auth_uuid = SEC_AUTH_TA_UUID;

    ret = dpa_loader_teek_init(sec_auth_uuid, SEC_AUTH_TA_NAME,
            &g_dpa_loader_sec_auth_session, &g_dpa_loader_sec_auth_context);
    if (ret) {
        dpa_loader_print_err("fail to open sec auth session, ret = %d\n", ret);
        return ret;
    }

    dpa_loader_print_err("dpa_loader verifier init ok\n");

    return ret;
}

