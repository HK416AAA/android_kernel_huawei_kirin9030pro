/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: hardware crypto engine km dev
 * Create: 2024/08/19
 */

#ifndef __HICRYPTO_DEV_KM_H__
#define __HICRYPTO_DEV_KM_H__
#include "hicrypto_driver.h"
#include "hicrypto_dev_data.h"

/* for sce dev */
struct hisi_km_key_reg {
	unsigned int key_addr;
	unsigned int key_bak_addr;
	unsigned int mask_addr;
};
#define SOC_SCE_AESKEY_REGNUM  8
#define KM_REG_AESKEY_NUMS     1
#define hisi_half_value(value) ((value) / 2)

enum hidev_km_reg_clr_key {
	REE_KM_CLR_DERIVE_KEY        = 0,
	REE_KM_CLR_BUFFER_KEY        = 1,
	REE_KM_CLR_IMGDEC_KEY        = 2,
};

struct hidev_km_derive {
	unsigned int        key_drv_sel;
	unsigned int        key_drv_data_sel;
	unsigned int        kram_waddr;
	unsigned int        kram_raddr;
};

struct hidev_km_deckey {
	unsigned int        keybuff_waddr;
};

struct hidev_km_keywrap {
	unsigned int        keybuff_waddr;
	unsigned int        wrap_mode;
	unsigned int        wrap_din_sel;
	unsigned int        wrap_din_data_sel;
	unsigned int        wrap_key_sel;
};

struct hidev_km_keyexport {
	unsigned int        keybuff_waddr;
	unsigned int        export_din_sel;
	unsigned int        export_din_data_sel;
};

struct hidev_km {
	unsigned int        ip_idx;
	unsigned int        algorithm;
	unsigned int        mode;
	unsigned int        direction;
	const unsigned char *pkey;
	unsigned int        keylen;
	unsigned int        km_mode;
	unsigned int        keytype;
	unsigned int        sub_keytype;
	const unsigned char   *pdin;
	unsigned int        dinlen;
	unsigned char         *pdout;
	unsigned int        doutlen;
	const unsigned char   *pivin;
	unsigned int        ivinlen;
	const void *pextend;
};

/* read km reg */
unsigned int hisi_reg_km_read(struct hicrypto_device *hdev, unsigned int offset);

/* write km reg */
void hisi_reg_km_write(struct hicrypto_device *hdev, unsigned int offset, unsigned int value);

/* config km mode */
void reekm_reg_cfg_kmmode(struct hicrypto_device *hdev, unsigned int kmmode);

/* config km key */
int reekm_reg_input_key(struct hicrypto_device *hdev, const struct hisi_dev_cipher_param *ctx);

/* check km alarm */
int reekm_reg_chk_alarm(struct hicrypto_device *hdev);

/* core km config function */
int hidev_km_function(struct hicrypto_device *hdev, const struct hidev_km *pkm);

/* km rtl decrypt fuction */
int hidev_km_rtldec_function(struct hicrypto_device *hdev);

/* clr km derive key */
int hidev_km_clear_bufferkey_by_slot(struct hicrypto_device *hdev, unsigned int unread_str, unsigned int unread_end);
int hidev_km_clear_derive_key(struct hicrypto_device *hdev);
int hidev_km_clear_derive_key_by_id(struct hicrypto_device *hdev, unsigned int key_sel);
/* derive dev struct common init */
void hidev_km_derive_init(struct hidev_km *pdrv_km, struct hidev_km_derive *pdrv_derive, unsigned int readable, unsigned int keytype);

/* rtl decrypt dev struct common init */
void hidev_km_rtldec_init(struct hidev_km *pdrv_km);

/* export key dev struct common init */
void hidev_km_export_init(struct hidev_km *pdrv_km, struct hidev_km_keyexport *pdrv_export);

/* wrap key dev struct common init */
void hidev_km_wrap_init(struct hidev_km *pdrv_km, struct hidev_km_keywrap *pdrv_wrap);
/* set derive key pos */
int hidev_km_reg_set_derive_subkey(unsigned int subkey);
/* set buffer key pos */
int hidev_km_reg_set_buff_subkey(unsigned int subkey);
/* set key inv flag */
void hidev_km_reg_cfg_key_inv_flag(struct hicrypto_device *hdev, unsigned int key_inv_flag);
#endif