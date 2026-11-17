/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: Hisi fbex ca header files
 * Create : 2020/01/02
 */

#ifndef __HISI_FBEX_DERVER_H_
#define __HISI_FBEX_DERVER_H_

#include "fbex_dev.h"

#include <teek_client_type.h>
#include <linux/types.h>
#include <platform_include/see/fbe_ctrl.h>

#define FILE_DE        0
#define FILE_CE        1
#define FILE_ECE       2
#define FILE_SECE      3
#define FILE_GLOBAL_DE 4
#define FILE_UECE      6

#define FBEX_MAX_UFS_SLOT 32
#define FBEX_FILE_LEN     0x8
#define FBEX_FILE_MASK    0xff
#ifndef CONFIG_FBE_FPGA
#define FBEX_SECE_TIMEOUT 4000 /* ms */
#define FBEX_KEY_TIMEOUT  60000 /* ms */
#define FBEX_LOCK_TIMEOUT 1000 /* ms */
#else
/* These time are increased because of FPGA slow time */
#define FBEX_SECE_TIMEOUT 6000 /* ms */
#define FBEX_KEY_TIMEOUT  20000 /* ms */
#define FBEX_LOCK_TIMEOUT 2000 /* ms */
#endif
#define FBEX_DELAY_MSP    500  /* ms */
#define FBEX_DELAY_POWER  4000 /* ms */
#define MSP_ONLINE        0x78
#define MSP_OFFLINE       0x87
#define MSP_TIMER_CNT     10  /* Keep MSP power On 50s */

/* error ID 0xFBE302XX is error ID for kernel */
#define FBE3_ERROR_CMD_START          0xFBE30200
#define FBE3_ERROR_CMD_INVALID        0xFBE30201
#define FBE3_ERROR_CMD_UNSUPPORT      0xFBE30202
#define FBE3_ERROR_CMD_UNDEFINED      0xFBE30203
#define FBE3_ERROR_SECE_TIMEER_OUT    0xFBE30204
#define FBE3_ERROR_CKEY_TIMEER_OUT    0xFBE30205
#define FBE3_ERROR_DEBUG_TIMEER_OUT   0xFBE30206
#define FBE3_ERROR_BUFFER_NULL        0xFBE30207
#define FBE3_ERROR_COPY_FAIL          0xFBE30208
#define FBE3_ERROR_INIT_INFO          0xFBE30209
#define FBE3_ERROR_INIT_BUFFER        0xFBE3020A
#define FBE3_ERROR_IV_BUFFER          0xFBE3020B
#define FBE3_ERROR_SLOT_ID            0xFBE3020C
#define FBE3_ERROR_BUFFER_INVALID     0xFBE3020D
#define FBE3_ERROR_NULL_POINTER       0xFBE3020E
#define FBE3_ERROR_INVALID_IV         0xFBE3020F
#ifdef CONFIG_FBE3_1
#define FBE3_ERROR_MSPC_CHK_FROM_TA   0xFBE30210
#define FBE3_ERROR_GEN_SK             0xFBE30212
#endif
#define FBE3_ERROR_UFS_LOCK           0xFBE30211
#define FBE3_ERROR_AUTHLEN            0xFBE30213
#ifdef CONFIG_PRODUCT_ARMPC
#define FBE3_ERROR_KEYRING_FAIL       0xFBE30301
#define FBE3_ERROR_DESCRIPTION        0xFBE30302
#define FBE3_ERROR_NOT_ROOT           0xFBE30303
#define FBE3_ERROR_USER_NOT_MATCH     0xFBE30304
#endif
#define FILE_ENCRY_ERROR_UECE_ALREADY_CREATED 0xFBE30031

#define FBE4_ERROR_UECE_TIMER_OUT     0xFBE40001
#define FBE4_ERROR_UECE_ENHANCE_TIMER_OUT     0xFBE40002

int fbex_init_driver(void);
void file_encry_init_sece(void);
void file_encry_record_error(u32 cmd, u32 user, u32 file, u32 error);
u32 fbe_ca_invoke_command(u32 cmd, TEEC_Operation *op);
u32 file_encry_unsupported(u32 user, u32 file, u8 *iv, u32 iv_len);
u32 file_encry_undefined(u32 user, u32 file, u8 *iv, u32 iv_len);
u32 file_encry_add_iv(u32 user, u32 file, u8 *iv, u32 iv_len);
u32 file_encry_delete_iv(u32 user, u32 file, u8 *iv, u32 iv_len);
u32 file_encry_logout_iv(u32 user, u32 file, u8 *iv, u32 iv_len);
#ifdef CONFIG_PRODUCT_ARMPC
u32 file_encry_rewrap(u32 user, u32 file, u8 *iv, u32 iv_len);
u32 file_encry_set_masterkey(u32 user, u32 file, u8 *iv, u32 iv_len);
u32 file_encry_del_masterkey(u32 user, u32 file, u8 *iv, u32 iv_len);
#else
u32 file_encry_lock_screen(u32 user, u32 file, u8 *iv, u32 iv_len);
u32 file_encry_unlock_screen(u32 user, u32 file, u8 *iv, u32 iv_len);
u32 file_encry_status_report(u32 user, u32 file, u8 *iv, u32 iv_len);
#endif
u32 fbex_ca_lock_screen(u32 user, u32 file);
u32 fbex_ca_unlock_screen(u32 user, u32 file, u8 *iv, u32 iv_len);
bool fbex_is_msp_online(void);
void fbex_init_slot(u32 user, u32 file, u8 slot);
void fbex_deinit_slot(u32 user, u32 file);
void fbex_work_finish(u32 ret);
bool hisi_fbex_is_preload(void);
void fbex_try_preloading(u32 user, u32 file);
void hisi_fbex_preloading_msp(bool flag);
void hisi_fbex_set_preload(bool flag);

typedef u32 (*file_encry_cb)(u32 user, u32 file, u8 *iv, u32 iv_len);

#ifdef CONFIG_PRODUCT_ARMPC
#define FILE_ENCRY_LIST                  \
	[0x00] = file_encry_undefined,     \
	[0x01] = file_encry_add_iv,        \
	[0x02] = file_encry_delete_iv,     \
	[0x03] = file_encry_unsupported,   \
	[0x04] = file_encry_unsupported,   \
	[0x05] = file_encry_unsupported,   \
	[0x06] = file_encry_unsupported,   \
	[0x07] = file_encry_unsupported,   \
	[0x08] = file_encry_logout_iv,     \
	[0x09] = file_encry_unsupported,   \
	[0x0A] = file_encry_unsupported,   \
	[0x0B] = file_encry_unsupported,   \
	[0x0C] = file_encry_unsupported,   \
	[0x0D] = file_encry_undefined,     \
	[0x0E] = file_encry_undefined,     \
	[0x0F] = file_encry_undefined,     \
	[0x10] = file_encry_rewrap,        \
	[0x11] = file_encry_set_masterkey, \
	[0x12] = file_encry_del_masterkey,
#else
#define FILE_ENCRY_LIST                  \
	[0x00] = file_encry_undefined,     \
	[0x01] = file_encry_add_iv,        \
	[0x02] = file_encry_delete_iv,     \
	[0x03] = file_encry_lock_screen,   \
	[0x04] = file_encry_unlock_screen, \
	[0x05] = file_encry_unsupported,   \
	[0x06] = file_encry_unsupported,   \
	[0x07] = file_encry_unsupported,   \
	[0x08] = file_encry_logout_iv,     \
	[0x09] = file_encry_unsupported,   \
	[0x0A] = file_encry_unsupported,   \
	[0x0B] = file_encry_unsupported,   \
	[0x0C] = file_encry_status_report, \
	[0x0D] = file_encry_undefined,     \
	[0x0E] = file_encry_undefined,     \
	[0x0F] = file_encry_undefined,
#endif

#endif /* __HISI_FBEX_DERVER_H_ */
