/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: function for base hash operation
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include "auth_path_impl.h"
#include <linux/string.h>
#include <linux/types.h>
#include <linux/slab.h>
#if defined(CONFIG_SELINUX_AUTH_ENBALE) && defined(CONFIG_SECURITY_SELINUX)
#include <linux/security.h>
#endif
#include <securec.h>
#include "tc_ns_log.h"
#include "tc_current_info.h"
#include "tc_ns_client.h"
#include "tc_linux_def.h"

#if defined(CONFIG_SELINUX_AUTH_ENBALE) && defined(CONFIG_SECURITY_SELINUX)
static int check_proc_selinux_access(const char *s_ctx)
{
	if (s_ctx == NULL) {
		tloge("bad params\n");
		return CHECK_ACCESS_FAIL;
	}

	int rc;
	u32 sid;
	u32 tid;
	u32 s_ctx_len = strnlen(s_ctx, MAX_SCTX_LEN);
	if (s_ctx_len == 0 || s_ctx_len >= MAX_SCTX_LEN) {
		tloge("invalid selinux ctx\n");
		return CHECK_ACCESS_FAIL;
	}

	security_task_getsecid(current, &sid);
	rc = security_secctx_to_secid(s_ctx, s_ctx_len, &tid);
	if (rc != 0) {
		tloge("secctx to sid failed, rc %d", rc);
		return CHECK_ACCESS_FAIL;
	}
	if (sid != tid) {
		tloge("check selinux label failed\n");
		return CHECK_ACCESS_FAIL;
	}

	return CHECK_ACCESS_SUCC;
}
#endif

static int check_proc_uid_path(const char *auth_ctx)
{
	int ret = CHECK_ACCESS_SUCC;
	char str_path_uid[MAX_PATH_SIZE] = { 0 };
	char *pro_dpath = NULL;
	char *k_path = NULL;
	u32 auth_ctx_len;
	uid_t proc_uid;

	if (auth_ctx == NULL) {
		tloge("bad params\n");
		return CHECK_ACCESS_FAIL;
	}

	auth_ctx_len = (u32)strnlen(auth_ctx, MAX_PATH_SIZE);
	if (auth_ctx_len == 0 || auth_ctx_len >= MAX_PATH_SIZE) {
		tloge("invalid uid path\n");
		return CHECK_ACCESS_FAIL;
	}

	k_path = kmalloc(MAX_PATH_SIZE, GFP_KERNEL);
	if (ZERO_OR_NULL_PTR((unsigned long)(uintptr_t)k_path)) {
		tloge("path kmalloc fail\n");
		return CHECK_ACCESS_FAIL;
	}

	pro_dpath = get_proc_dpath(k_path, MAX_PATH_SIZE);
	if (IS_ERR_OR_NULL(pro_dpath)) {
		kfree(k_path);
		tloge("dpath is null\n");
		return CHECK_ACCESS_FAIL;
	}

	proc_uid = current_uid().val;
	if (snprintf_s(str_path_uid, MAX_PATH_SIZE, MAX_PATH_SIZE - 1, "%s:%u",
		pro_dpath, (unsigned int)proc_uid) < 0) {
		tloge("snprintf_s path uid failed, ret %d\n", ret);
		ret = CHECK_ACCESS_FAIL;
		goto clean;
	}

	if (strnlen(str_path_uid, MAX_PATH_SIZE) != auth_ctx_len || strncmp(str_path_uid, auth_ctx, auth_ctx_len) != 0)
		ret = ENTER_BYPASS_CHANNEL;
	else
		ret = CHECK_ACCESS_SUCC;

clean:
	kfree(k_path);
	return ret;
}

#if defined(CONFIG_CLIENT_HIDL) || defined(CONFIG_MDC_HAL_AUTH) || defined(CONFIG_CADAEMON_AUTH)
bool is_hidl_or_cadaemon(void)
{
	bool ret = false;
	if (CURRENT_MM == NULL)
		return false;
#if defined(CONFIG_CLIENT_HIDL) || defined(CONFIG_MDC_HAL_AUTH)
	ret |= (check_proc_uid_path(CA_HIDL_PATH_UID_AUTH_CTX) == CHECK_ACCESS_SUCC);
#endif
#ifdef CONFIG_CADAEMON_AUTH
	ret |= (check_proc_uid_path(CADAEMON_PATH_UID_AUTH_CTX) == CHECK_ACCESS_SUCC);
#endif
	return ret;
}
#endif

#ifdef  CONFIG_CADAEMON_AUTH
int check_cadaemon_auth(void)
{
	int ret = check_proc_uid_path(CADAEMON_PATH_UID_AUTH_CTX);
	if (ret != CHECK_ACCESS_SUCC) {
		tloge("check cadaemon path failed, ret %d\n", ret);
		return ret;
	}
#if defined(CONFIG_SELINUX_AUTH_ENBALE) && defined(CONFIG_SECURITY_SELINUX)
	ret = check_proc_selinux_access(SELINUX_CADAEMON_LABEL);
	if (ret != CHECK_ACCESS_SUCC) {
		tloge("check cadaemon selinux label failed!, ret %d\n", ret);
		return -EACCES;
	}
#endif
	return 0;
}
#endif

#if ((defined CONFIG_CLIENT_AUTH) || (defined CONFIG_MDC_HAL_AUTH))
int check_hidl_auth(void)
{
	int ret = check_proc_uid_path(CA_HIDL_PATH_UID_AUTH_CTX);
#ifdef CA_HIDL_REC_PATH_UID_AUTH_CTX
	int ret_rec = check_proc_uid_path(CA_HIDL_REC_PATH_UID_AUTH_CTX);
	if (ret != CHECK_ACCESS_SUCC && ret_rec != CHECK_ACCESS_SUCC)
#else
	if (ret != CHECK_ACCESS_SUCC)
#endif
	return ret;

#if defined(CONFIG_SELINUX_AUTH_ENBALE) && defined(CONFIG_SECURITY_SELINUX)
	ret = check_proc_selinux_access(SELINUX_CA_HIDL_LABEL);
	if (ret != CHECK_ACCESS_SUCC) {
		tloge("check hidl selinux label failed, ret %d\n", ret);
		return CHECK_SECLABEL_FAIL;
	}
#endif

	return CHECK_ACCESS_SUCC;
}
#endif

#ifdef CONFIG_TEECD_AUTH
int check_teecd_auth(void)
{
	int ret = check_proc_uid_path(TEECD_PATH_UID_AUTH_CTX);
	if (ret != CHECK_ACCESS_SUCC) {
		tloge("check teecd path failed, ret %d\n", ret);
		return ret;
	}

#if defined(CONFIG_SELINUX_AUTH_ENBALE) && defined(CONFIG_SECURITY_SELINUX)
	ret = check_proc_selinux_access(SELINUX_TEECD_LABEL);
	if (ret != CHECK_ACCESS_SUCC) {
		tloge("check teecd selinux label failed!, ret %d\n", ret);
		return -EACCES;
	}
#endif

	return CHECK_ACCESS_SUCC;
}
#endif

#ifdef CONFIG_TEE_TELEPORT_AUTH
int check_tee_teleport_auth(void)
{
	int ret = check_proc_uid_path(TEE_TELEPORT_PATH_UID_AUTH_CTX);
	if (ret != CHECK_ACCESS_SUCC) {
		tloge("check teleport path failed, ret %d\n", ret);
		return ret;
	}

#if defined(CONFIG_SELINUX_AUTH_ENBALE) && defined(CONFIG_SECURITY_SELINUX)
	int ret = check_proc_selinux_access(SELINUX_TEE_TELEPORT_LABEL);
	if (ret != CHECK_ACCESS_SUCC) {
		tloge("check tee_teleport selinux label failed!, ret %d\n", ret);
		return -EACCES;
	}
#endif

	return CHECK_ACCESS_SUCC;
}
#endif

#ifdef CONFIG_TEE_AGENTD_AUTH
int check_tee_agentd_auth(void)
{
	int ret = check_proc_uid_path(TEE_AGENTD_PATH_UID_AUTH_CTX);
	if (ret != CHECK_ACCESS_SUCC) {
		tloge("check agentd path failed, ret %d\n", ret);
		return ret;
	}

#if defined(CONFIG_SELINUX_AUTH_ENBALE) && defined(CONFIG_SECURITY_SELINUX)
	ret = check_proc_selinux_access(SELINUX_TEE_AGENTD_LABEL);
	if (ret != CHECK_ACCESS_SUCC) {
		tloge("check agentd selinux label failed!, ret %d\n", ret);
		return -EACCES;
	}
#endif

	return CHECK_ACCESS_SUCC;
}
#endif
