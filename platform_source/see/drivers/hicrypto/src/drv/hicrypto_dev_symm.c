/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: Hisilicon hardware crypto engine cipher alg.
 * Create : 2024/04/18
 */
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/iopoll.h>
#include <asm/barrier.h>

#include "hicrypto_common.h"
#include "hicrypto_regs.h"
#include "hicrypto_dev_km.h"
#include "hicrypto_dev_symm.h"
#include "hicrypto_macro.h"
#include "hicrypto_errno.h"
#include "hicrypto_io.h"
#include "hicrypto_log.h"
#include "hicrypto_register.h"
#include "hicrypto_chip.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE
#define HISI_4WORD_BYTES 4
#define HISI_8WORD_BYTES 8

enum hisi_sce_reg_algorithm hisi_symm_get_algorithm(unsigned int alg)
{
	switch (alg) {
		case HISI_CIPHER_ALGORITHM_AES:
			return HISI_SCE_REG_ALGORITHM_AES;
		case HISI_CIPHER_ALGORITHM_SM4:
			return HISI_SCE_REG_ALGORITHM_SM4;
		case HISI_CIPHER_ALGORITHM_DES:
			return HISI_SCE_REG_ALGORITHM_DES;
		case HISI_HASH_ALGORITHM_SHA1:
			return HISI_SCE_REG_ALGORITHM_SHA1;
		case HISI_HASH_ALGORITHM_MD5:
			return HISI_SCE_REG_ALGORITHM_MD5;
		/* fall through, SHA224/SH256 choose the same algorithm */
		case HISI_HASH_ALGORITHM_SHA224:
		case HISI_HASH_ALGORITHM_SHA256:
			return HISI_SCE_REG_ALGORITHM_SHA256;
		case HISI_HASH_ALGORITHM_SM3:
			return HISI_SCE_REG_ALGORITHM_SM3;
		/* fall through, SHA384/SH512 choose the same algorithm */
		case HISI_HASH_ALGORITHM_SHA384:
		case HISI_HASH_ALGORITHM_SHA512:
			return HISI_SCE_REG_ALGORITHM_SHA512;
		case HISI_SYMM_ALGORITHM_PLAINTCPY:
			return HISI_SCE_REG_ALGORITHM_PLAINTCPY;
		default:
			return HISI_SCE_REG_ALGORITHM_UNKNOWN;
	}
}

static inline unsigned int hisi_symm_process_algorithm(unsigned int alg, unsigned int mode)
{
	if (alg != HISI_SCE_REG_ALGORITHM_AES)
		return alg;

	if (mode == HISI_SCE_REG_MODE_CTR || mode == HISI_SCE_REG_MODE_GHASH || mode == HISI_SCE_REG_MODE_GCM_IV_INIT ||
	    mode == HISI_SCE_REG_MODE_GCM_GMAC || mode == HISI_SCE_REG_MODE_GCM_PAYLOAD_PROC)
		return HISI_SCE_REG_ALGORITHM_QUICK_AES;

	return alg;
}

static enum hisi_sce_reg_mode hisi_symm_get_mode(unsigned int mode)
{
	switch (mode) {
		case HISI_CIPHER_MODE_ECB:
			return HISI_SCE_REG_MODE_ECB;
		case HISI_CIPHER_MODE_CBC:
			return HISI_SCE_REG_MODE_CBC;
		case HISI_CIPHER_MODE_CBCMAC:
			return HISI_SCE_REG_MODE_CBCMAC;
		case HISI_CIPHER_MODE_CMAC:
			return HISI_SCE_REG_MODE_CMAC;
		case HISI_CIPHER_MODE_CTR:
			return HISI_SCE_REG_MODE_CTR;
		case HISI_CIPHER_MODE_XTS:
			return HISI_SCE_REG_MODE_XTS;
		case HISI_CIPHER_MODE_OFB:
			return HISI_SCE_REG_MODE_OFB;
		case HISI_CIPHER_MODE_XCBCMAC:
			return HISI_SCE_REG_MODE_XCBCMAC;
		case HISI_SYMM_MODE_CCM_ENC:
			return HISI_SCE_REG_MODE_CCM_PAYLOAD_PROC;
		case HISI_SYMM_MODE_GCM_IV_INIT:
			return HISI_SCE_REG_MODE_GCM_IV_INIT;
		case HISI_SYMM_MODE_GHASH:
			return HISI_SCE_REG_MODE_GHASH;
		case HISI_SYMM_MODE_GMAC:
			return HISI_SCE_REG_MODE_GCM_GMAC;
		case HISI_SYMM_MODE_GCM_ENC:
			return HISI_SCE_REG_MODE_GCM_PAYLOAD_PROC;
		default:
			return HISI_SCE_REG_MODE_UNKNOWN;
	}
}

static unsigned int hisi_symm_get_user_keywidth(unsigned int mode, unsigned int keylen)
{
	unsigned int klen;

	if (mode == HISI_CIPHER_MODE_XTS)
		klen = hisi_half_value(keylen);
	else
		klen = keylen;

	switch (klen) {
		case HISI_SYMM_KEYLEN_8:
		case HISI_SYMM_KEYLEN_16:
			return HISI_SCE_REG_KEY_WIDTH_128;
		case HISI_SYMM_KEYLEN_24:
			return HISI_SCE_REG_KEY_WIDTH_192;
		case HISI_SYMM_KEYLEN_32:
			return HISI_SCE_REG_KEY_WIDTH_256;
		default:
			return HISI_SCE_REG_KEY_WIDTH_UNKNOWN;
	}
}

static unsigned int hisi_symm_get_width(unsigned int keytype, unsigned int mode, unsigned int keylen)
{
	switch (keytype) {
		case HISI_SYMM_KEYTYPE_CEK:
			return HISI_SCE_REG_KEY_WIDTH_128;
		case HISI_SYMM_KEYTYPE_KDR:
		case HISI_SYMM_KEYTYPE_RTL1:
		case HISI_SYMM_KEYTYPE_GID:
		case HISI_SYMM_KEYTYPE_RTL:
		case HISI_SYMM_KEYTYPE_POS:
			return HISI_SCE_REG_KEY_WIDTH_256;
		case HISI_SYMM_KEYTYPE_USER:
		case HISI_SYMM_KEYTYPE_DERIVE:
		case HISI_SYMM_KEYTYPE_CEK1:
		case HISI_SYMM_KEYTYPE_TAKEY:
		case HISI_SYMM_KEYTYPE_BUFFKEY:
		case HISI_SYMM_KEYTYPE_IMGKEY:
		case HISI_SYMM_KEYTYPE_CPU_WRAPKEY:
		case HISI_SYMM_KEYTYPE_AO_WRAPKEY:
			return hisi_symm_get_user_keywidth(mode, keylen);
		default:
			return HISI_SCE_REG_KEY_WIDTH_UNKNOWN;
	}
}

// --------------------------------------
// BLOCK: sce
// --------------------------------------
unsigned int hisi_reg_sce_read(struct hicrypto_device *hdev, unsigned int offset)
{
	return pal_read_u32(ptr_add(ptr_to_ulong(hdev->sce_base), offset));
}

void hisi_reg_sce_write(struct hicrypto_device *hdev, unsigned int offset, unsigned int value)
{
	pal_write_u32(value, ptr_add(ptr_to_ulong(hdev->sce_base), offset));
}

int hisi_reg_sce_wait_busy(struct hicrypto_device *hdev, unsigned int mask, unsigned int value,
					unsigned int timeout_us)
{
	u32 status, ret;
	pal_debug("sce sce_wait_busy addr=0x%x, value=0x%x, msk=0x%x\n", ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_SCE_STATE),
		 value, mask);
	ret = readl_relaxed_poll_timeout_atomic(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_SCE_STATE), status,
					((status & mask) == value),HISI_REG_SLEEP_US, timeout_us);
	return ret != 0 ? err_drv(ERRCODE_BUSY) : BSP_RET_OK;
}

int hisi_reg_sce_wait_int(struct hicrypto_device *hdev, unsigned int mask, unsigned int value,
					unsigned int timeout_us)
{
	u32 status, ret;
	pal_debug("sce sce_wait_int addr=0x%x, value=0x%x, msk=0x%x\n", ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_INT_SCE),
		 value, mask);
	ret = readl_relaxed_poll_timeout_atomic(ptr_add(ptr_to_ulong(hdev->sce_base) ,HISI_SCE_OFF_INT_SCE), status,
					((status & mask) == value), HISI_REG_SLEEP_US, timeout_us);
	return ret != 0 ? err_drv(ERRCODE_BUSY) : BSP_RET_OK;
}

void hisi_reg_sce_clr_int(struct hicrypto_device *hdev)
{
	hisi_sce_int_clr_union int_clr = { .value = 0 };

	int_clr.reg.sce_master_int_clr = 0x05;
	int_clr.reg.dscrp_finish_int_clr = 0x05;
	int_clr.reg.dscrp_aempty_int_clr = 0x05;
	int_clr.reg.dscrp_overflow_int_clr = 0x05;
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_INT_SCE_CLR, int_clr.value);
}

/* mask interrupt (interrupt of done computing) */
void hisi_reg_sce_cfg_int(struct hicrypto_device *hdev, unsigned int mask)
{
	hisi_sce_int_mask_en_union int_mask = { .value = 0 };

	int_mask.reg.sce_master_int_mask_en = mask;
	int_mask.reg.dscrp_finish_int_mask_en = HISI_SCE_VALUE_MSK;
	int_mask.reg.dscrp_aempty_int_mask_en = HISI_SCE_VALUE_MSK;
	int_mask.reg.dscrp_overflow_int_mask_en = HISI_SCE_VALUE_MSK;

	hisi_reg_sce_write(hdev, HISI_SCE_OFF_INT_MASK_EN, int_mask.value);
}

void hisi_reg_sce_master_rxaddr(struct hicrypto_device *hdev, unsigned long long rxaddr)
{
	hisi_sce_iv_bypass_union iv_pass = { 0 };

	iv_pass.value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_IV_BYPASS);
	iv_pass.reg.sce_src_addr_high = u64_msb(rxaddr);

	hisi_reg_sce_write(hdev, HISI_SCE_OFF_IV_BYPASS, iv_pass.value);
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_SRC_ADDR, u64_lsb(rxaddr));
}

void hisi_reg_sce_master_txaddr(struct hicrypto_device *hdev, unsigned long long txaddr)
{
	hisi_sce_iv_bypass_union iv_pass = { 0 };

	iv_pass.value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_IV_BYPASS);
	/* high 32-bit */
	iv_pass.reg.sce_des_addr_high = u64_msb(txaddr);
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_IV_BYPASS, iv_pass.value);
	/* low 32-bit */
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_DES, u64_lsb(txaddr));

	return;
}

#define SOC_SCE_DIN_REGNUM       16
int hisi_reg_sce_input_din(struct hicrypto_device *hdev, const unsigned char *pdin, unsigned int dinlen)
{
	int ret = err_drv(ERRCODE_UNKNOWN);

	if (!pdin)
		return BSP_RET_OK;
	
	ret = hisi_reg_write(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_DIN_STR), SOC_SCE_DIN_REGNUM, pdin, byte2word(dinlen));
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	return ret;
}

#define SOC_SCE_IVIN_REGNUM         16
int hisi_reg_sce_input_ivin(struct hicrypto_device *hdev, const unsigned char *pivin, unsigned int ivinlen)
{
	int ret = err_drv(ERRCODE_UNKNOWN);

	if (!pivin)
		return BSP_RET_OK;
	
	ret = hisi_reg_write(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_SCE_IVIN1), SOC_SCE_IVIN_REGNUM, pivin, byte2word(ivinlen));
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	return ret;
}

enum hisi_symm_blklen hisi_reg_sce_get_blklen(struct hicrypto_device *hdev)
{
	hisi_sce_mode_union sce_mode = {0};
	unsigned int alg;

	sce_mode.value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_MODE);
	alg = sce_mode.reg.sce_ip_sel;
	switch (alg) {
	case HISI_SCE_REG_ALGORITHM_AES:
	case HISI_SCE_REG_ALGORITHM_SM4:
	case HISI_SCE_REG_ALGORITHM_QUICK_AES:
		return HISI_SYMM_BLKLEN_AES;
	case HISI_SCE_REG_ALGORITHM_DES:
		return HISI_SYMM_BLKLEN_DES;
	case HISI_SCE_REG_ALGORITHM_MD5:
	case HISI_SCE_REG_ALGORITHM_SHA1:
	case HISI_SCE_REG_ALGORITHM_SHA256:
	case HISI_SCE_REG_ALGORITHM_SM3:
		return HISI_SYMM_BLKLEN_HASH;
	case HISI_SCE_REG_ALGORITHM_SHA512:
		return HISI_SYMM_BLKLEN_HASH_SHA512;
	case HISI_SCE_REG_ALGORITHM_UNKNOWN:
	default:
		return HISI_SYMM_BLKLEN_UNKNOWN;
	}
}

void hisi_reg_sce_get_doutreg(struct hicrypto_device *hdev, unsigned int *regaddr, unsigned int *regnum)
{
	hisi_sce_mode_union sce_mode = {0};

	sce_mode.value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_MODE);
	if ((sce_mode.reg.sce_ip_sel >= HISI_SCE_REG_ALGORITHM_SHA1 &&
	     sce_mode.reg.sce_ip_sel <= HISI_SCE_REG_ALGORITHM_SM3) ||
	     sce_mode.reg.sce_ip_sel == HISI_SCE_REG_ALGORITHM_SHA512) {
		*regaddr = HISI_SCE_OFF_SCE_IVOUT2;
		*regnum = HISI_SCE_MACIVOUT_WORDNUM;
	} else {
		*regaddr = HISI_SCE_OFF_SCE_DOUT;
		*regnum = HISI_SCE_REG_DOUT_NUM;
	}
}

static int hisi_sce_reg_set_alg(struct hicrypto_device *hdev, unsigned int algorithm, unsigned int mode)
{
	hisi_sce_mode_union sce_mode = { 0 };
	unsigned int alg;

	alg = hisi_symm_get_algorithm(algorithm);
	if (pal_check(alg == HISI_SCE_REG_ALGORITHM_UNKNOWN))
		return err_drv(ERRCODE_UNSUPPORT);

	alg = hisi_symm_process_algorithm(alg, mode);
	if (pal_check(alg == HISI_SCE_REG_ALGORITHM_UNKNOWN))
		return err_drv(ERRCODE_UNSUPPORT);

	sce_mode.value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_MODE);
	sce_mode.reg.sce_ip_sel = alg;
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_MODE, sce_mode.value);
	return BSP_RET_OK;
}

/* algorithm/mode/direction/keylen
 * for XTS, config half keylen
 * for des, config tdes
 */
int hisi_reg_sce_cfg_amdk(struct hicrypto_device *hdev, unsigned int algorithm, unsigned int mode,
				 unsigned int direction, unsigned int keytype,
				 unsigned int keylen)
{
	int ret = err_drv(ERRCODE_UNKNOWN);
	hisi_sce_cfg_union sce_cfg = { 0 };
	unsigned int sce_mode;
	unsigned int width;

	/* algorithm */
	sce_mode = hisi_symm_get_mode(mode);
	if (pal_check(sce_mode == HISI_SCE_REG_MODE_UNKNOWN))
		return err_drv(ERRCODE_UNSUPPORT);
	ret = hisi_sce_reg_set_alg(hdev, algorithm, sce_mode);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	/* mode */
	sce_cfg.value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_CFG);
	sce_cfg.reg.sce_mode = sce_mode;
	if (sce_mode == HISI_SCE_REG_MODE_CBCMAC)
		sce_cfg.reg.sce_padding_sel = 1; /* kernel crypto CBCMAC just support PADDING_00 */
	else
		sce_cfg.reg.sce_padding_sel = 0;

	/* dir */
	if (direction == HISI_SYMM_DIRECTION_DECRYPT)
		sce_cfg.reg.sce_decrypt = HISI_SCE_REG_DIRECTION_DECRYPT;
	else
		sce_cfg.reg.sce_decrypt = HISI_SCE_REG_DIRECTION_ENCRYPT;

	if (algorithm != HISI_SYMM_ALGORITHM_PLAINTCPY) {
		/* width */
		width = hisi_symm_get_width(keytype, mode, keylen);
		if (pal_check(width == HISI_SCE_REG_KEY_WIDTH_UNKNOWN))
			return err_drv(ERRCODE_UNSUPPORT);
		sce_cfg.reg.sce_key_length = width;
	}

	/* tdes */
	if (algorithm == HISI_CIPHER_ALGORITHM_DES && keylen > HISI_SYMM_KEYLEN_8)
		sce_cfg.reg.tdes = 1;
	else
		sce_cfg.reg.tdes = 0;

	hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_CFG, sce_cfg.value); /* sce_reg_cfg_amdk */
	return BSP_RET_OK;
}

int hisi_reg_sce_write_sram(struct hicrypto_device *hdev, unsigned int addr, unsigned int value)
{
	hisi_sce_ram_addr_union ram_addr_union = { 0 };
	unsigned int dest_value, ready_value;

	ram_addr_union.reg.sce_ram_addr = addr;
	ram_addr_union.reg.sce_ram_wren = 1; /* 1 is write, 0 is read */
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_RAM_ADDR, ram_addr_union.value);
	word_set_inv(&dest_value, &value);
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_RAM_DATA, dest_value);
	ready_value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_RAM_READY);
	if (pal_check(ready_value != 1)) /* 1 is done, 0 is doing */
		return err_drv(ERRCODE_VERIFY);

	return BSP_RET_OK;
}

int hisi_dev_cipher_deinit(struct hicrypto_device *hdev)
{
	hisi_sce_state_union sce_state = { 0 };

	/* km_reg_rst_config none */
	sce_state.value = 0;
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_STATE, sce_state.value); /* sce_reg_clr_busydone */
	hisi_reg_sce_clr_int(hdev);					   /* sce_reg_clr_int */
	/* sce_reg_cfg_ipen and drv_sm4_multi_core_config none */
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_REG_LOCK, HISI_SCE_VALUE_LOCK); /* sce_reg_cfg_lock */

	return BSP_RET_OK;
}

int hisi_dev_cipher_init(struct hicrypto_device *hdev, struct hisi_dev_cipher_param *cipher_param)
{
	int ret;
	hisi_sce_state_union sce_state = { 0 };

	/* drv_cipher_entry */
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_REG_LOCK, HISI_SCE_VALUE_UNLOCK); /* sce_reg_cfg_lock */
	ret = hisi_reg_sce_wait_busy(hdev, HISI_SCE_REG_STATE_BUSY, HISI_SCE_VALUE_IDLE, HISI_SCE_IDLE_ENTRY_TIMEOUT);
	if (pal_check(ret != BSP_RET_OK)) {
		pal_error("sce_reg_wait_idle failed\n");
		return ret;
	}

	/* alarm unmask */
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_ALARM_MASK_EN, HISI_SCE_VALUE_ALM_UNMSK);

	/* sce_reg_cfg_ipen and drv_sm4_multi_core_config none */
	sce_state.reg.sce_busy_reg = 0;					   /* clear busy */
	sce_state.reg.sce_done_reg = 0;					   /* clear done */
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_STATE, sce_state.value); /* sce_reg_clr_busydone */
	hisi_reg_sce_clr_int(hdev);					   /* sce_reg_clr_int */

	/* drv_cipher_config_param */
	/* sce_reg_cfg_amdk */
	hisi_reg_sce_cfg_amdk(hdev, cipher_param->algorithm, cipher_param->mode, cipher_param->direction,
			      cipher_param->keytype, cipher_param->keylen);

	/* drv_cipher_config_key */
	ret = reekm_reg_input_key(hdev, cipher_param);
	if (ret != BSP_RET_OK)
		return ret;
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_PADDING_EN, cipher_param->padding_en);

	return BSP_RET_OK;
}
#if !defined(CONFIG_CRYPTO_HICRYPTO_V2_DEBUG) || !CONFIG_CRYPTO_HICRYPTO_V2_DEBUG
void hisi_dev_symmm_mntn_dump(struct hicrypto_device *hdev, const struct hisi_dev_symm_data_proc *proc,
			      struct hisi_drv_symm_sg_list_info *drv_list_info)
{
	unused(hdev);
	unused(proc);
	unused(drv_list_info);
}
#else

static void hisi_reg_sce_print_master_addr(struct hicrypto_device *hdev)
{
	hisi_sce_iv_bypass_union ivbypass = { 0 };
	unsigned int rxhaddr, rxladdr, txhaddr, txladdr;

	unused(rxhaddr);
	unused(rxladdr);
	unused(txhaddr);
	unused(txladdr);
	/* rx addr high 32-bit */
	ivbypass.value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_IV_BYPASS);
	rxhaddr = ivbypass.reg.sce_src_addr_high;
	/* rx addr low 32-bit */
	rxladdr = hisi_reg_sce_read(hdev, HISI_SCE_OFF_SRC_ADDR);

	/* tx addr high 32-bit */
	txhaddr = ivbypass.reg.sce_des_addr_high;
	/* tx addr low 32-bit */
	txladdr = hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_DES);

	pal_error("rxaddr:0x%llx, txaddr:0x%llx\n", tou64(rxhaddr, rxladdr), tou64(txhaddr, txladdr));
}

static void hisi_reg_sce_pint_master_len(struct hicrypto_device *hdev)
{
	unsigned int dinlen = hisi_reg_sce_read(hdev, HISI_SCE_OFF_RX_DAT_LEN);
	unsigned int doutlen = hisi_reg_sce_read(hdev, HISI_SCE_OFF_TX_DAT_LEN);

	unused(dinlen);
	unused(doutlen);
	pal_error("dinlen:0x%x, doutlen:0x%x\n", dinlen, doutlen);
}

static int hisi_reg_sce_read_sram(struct hicrypto_device *hdev, unsigned int addr, unsigned int *value)
{
	hisi_sce_ram_addr_union ram_addr_union;
	unsigned int src_value, ready_value;

	ram_addr_union.reg.sce_ram_addr = addr;
	ram_addr_union.reg.sce_ram_wren = 0; /* 1 is write, 0 is read */
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_RAM_ADDR, ram_addr_union.value);
	ready_value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_RAM_READY);
	if (pal_check(ready_value != 1)) /* 1 is done, 0 is doing */
		return err_drv(ERRCODE_VERIFY);

	src_value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_RAM_DATA);
	word_set_inv(value, &src_value);

	return BSP_RET_OK;
}

static void hisi_reg_sce_sram_dump(struct hicrypto_device *hdev, unsigned int sce_ram_addr, unsigned int list_num)
{
	unsigned int i, laddr, haddr, len, haddr_and_len, total_len;

	unused(laddr);
	unused(haddr);
	unused(len);
	unused(haddr_and_len);
	unused(total_len);
	total_len = 0;
	haddr_and_len = 0;
	for (i = 0; i < list_num; i++) {
		hisi_reg_sce_read_sram(hdev, sce_ram_addr, &laddr);
		sce_ram_addr++;
		hisi_reg_sce_read_sram(hdev, sce_ram_addr, &haddr_and_len);
		sce_ram_addr++;
		len = haddr_and_len & HISI_SCE_SRAM_LIST_LEN_REGION;
		haddr = haddr_and_len >> HISI_SCE_SRAM_LIST_HADDR_STRBIT;
		total_len += len;
		pal_error("reg list[%d], addr:0x%llx, len:%d\n", i, tou64(haddr, laddr), len);
	}
	pal_error("reg list total num:%d, list total len:%d\n", list_num, total_len);
}

static void hisi_reg_sce_listin_dump(struct hicrypto_device *hdev, unsigned int list_num)
{
	hisi_reg_sce_sram_dump(hdev, 0, list_num);
}

static void hisi_reg_sce_listout_dump(struct hicrypto_device *hdev, unsigned int list_num, unsigned int in_num)
{
	hisi_reg_sce_sram_dump(hdev, HISI_SCE_REG_SRAM_STEP * in_num, list_num);
}

static void hisi_dev_master_proc_mntn(struct hicrypto_device *hdev, const struct hisi_dev_symm_data_proc *proc)
{
	pal_error("hicrypto master dump, rxmode 0x%x, txmode 0x%x.\n", proc->rxmode, proc->txmode);
	hisi_reg_sce_print_master_addr(hdev);
	hisi_reg_sce_pint_master_len(hdev);

	if (proc->txmode == HISI_SYMM_TRANSFER_CPU)
		pal_error("pdout:0x%x, doutlen:%d\n", (unsigned int)(uintptr_t)(proc->pb_out), proc->outlen);
}

static void hisi_dev_list_proc_mntn(struct hicrypto_device *hdev, const struct hisi_dev_symm_data_proc *proc,
				    struct hisi_drv_symm_sg_list_info *drv_list_info)
{
	pal_error("hicrypto list dump, rxmode 0x%x, txmode 0x%x.\n", proc->rxmode, proc->txmode);
	hisi_reg_sce_listin_dump(hdev, drv_list_info->sg_cnt_in);

	if (proc->txmode == HISI_SYMM_TRANSFER_LIST)
		hisi_reg_sce_listout_dump(hdev, drv_list_info->sg_cnt_out, drv_list_info->sg_cnt_in);

	if (proc->txmode == HISI_SYMM_TRANSFER_CPU)
		pal_error("pdout:0x%x, dout:0x%x\n", (unsigned int)(uintptr_t)(proc->pb_out), proc->outlen);
}

static void hisi_dev_dump_sce_reg(struct hicrypto_device *hdev)
{
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_MODE);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_RX_DAT_LEN);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_CFG);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_STATE);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_LINE);

	hisi_reg_sce_read(hdev, HISI_SCE_OFF_ALARM_MASK_EN);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_ALARM_MASK);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_TX_DAT_LEN);

	hisi_reg_sce_read(hdev, HISI_SCE_OFF_GCM_AAD_LEN);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_DATA_LEN_ALL);

	hisi_reg_sce_read(hdev, HISI_SCE_OFF_IV_BYPASS);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_SRC_ADDR);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_DES_ADDR);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_CACHE_CTRL_ADDR);

	hisi_reg_sce_read(hdev, HISI_SCE_OFF_RX_RES_BURST);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_RX_RES_WORD);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_RX_REQ_BURST);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_RX_ROAD_WORD);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_TX_REQ_BURST);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_TX_REMAIN_BURST);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_TX_REMAIN_WORD);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_RX_WDATA0);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_RX_WDATA1);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_RX_WDATA2);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_RX_WDATA3);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_RX_RDATA0);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_RX_RDATA1);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_RX_RDATA2);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_RX_RDATA3);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_TX_WDATA0);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_TX_WDATA1);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_TX_WDATA2);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_TX_WDATA3);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_TX_RDATA0);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_TX_RDATA1);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_TX_RDATA2);
	hisi_reg_sce_read(hdev, HISI_SCE_OFF_FIFO_TX_RDATA2);
}

static void hisi_dev_dump_km_reg(struct hicrypto_device *hdev)
{
	hisi_reg_km_write(hdev, HISI_KM_OFF_REG_LOCK, HISI_KM_VALUE_UNLOCK);
	hisi_reg_km_read(hdev, HISI_KM_OFF_KM_MODE);
	hisi_reg_km_read(hdev, HISI_KM_OFF_ALARM_MASK);
	hisi_reg_km_read(hdev, HISI_KM_OFF_KEY_SEL);
	hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_REG_LOCK, HISI_KM_VALUE_UNLOCK);
	hisi_reg_km_read(hdev, HISI_KM_OFF_AESKEY_MASK);
	hisi_reg_km_read(hdev, HISI_KM_OFF_AES_KEY);
	hisi_reg_km_read(hdev, (HISI_KM_OFF_AES_KEY + 0x4));
	hisi_reg_km_read(hdev, (HISI_KM_OFF_AES_KEY + 0x8));
	hisi_reg_km_read(hdev, (HISI_KM_OFF_AES_KEY + 0xc));
	hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_REG_LOCK, HISI_KM_VALUE_LOCK);
	hisi_reg_km_write(hdev, HISI_KM_OFF_REG_LOCK, HISI_KM_VALUE_LOCK);
}

void hisi_dev_symmm_mntn_dump(struct hicrypto_device *hdev, const struct hisi_dev_symm_data_proc *proc,
			      struct hisi_drv_symm_sg_list_info *drv_list_info)
{
	if (proc->rxmode == HISI_SYMM_TRANSFER_MASTER) {
		hisi_dev_master_proc_mntn(hdev, proc);
	} else if (proc->rxmode == HISI_SYMM_TRANSFER_LIST) {
		hisi_dev_list_proc_mntn(hdev, proc, drv_list_info);
	} else {
		pal_error("hicrypto rxmode is cpu\n");
	}
	pal_error("hicrypto bg dump sce reg\n");
	hisi_dev_dump_sce_reg(hdev);
	pal_error("hicrypto end dump sce reg\n");
	pal_error("hicrypto bg dump km reg\n");
	hisi_dev_dump_km_reg(hdev);
	pal_error("hicrypto end dump km reg\n");
}
#endif

static int hisi_dev_symm_list_proc_data(struct hicrypto_device *hdev, struct hisi_dev_symm_data_proc *proc,
					struct hisi_drv_symm_sg_list_info *plist_info)
{
	int ret = err_drv(ERRCODE_UNKNOWN);
	hisi_sce_mode_union sce_mode = { 0 };
	hisi_sce_str_run_union start_run = { 0 };
	unsigned int timeoutus, regaddr, wordnum;

	/* rx tx mode sce_reg_cfg_rxtxmode */
	sce_mode.value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_MODE);
	sce_mode.reg.sce_rx_dma_mode = proc->rxmode;
	sce_mode.reg.sce_tx_dma_mode = proc->txmode;

	hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_MODE, sce_mode.value);

	hisi_reg_sce_write(hdev, HISI_SCE_OFF_RX_DAT_LEN, plist_info->sg_cnt_in);
	if (proc->txmode == HISI_SYMM_TRANSFER_LIST)
		hisi_reg_sce_write(hdev, HISI_SCE_OFF_TX_DAT_LEN, plist_info->sg_cnt_out);

	/* cfg input list */
	hisi_reg_sce_master_rxaddr(hdev, 0);
	if (proc->txmode == HISI_SYMM_TRANSFER_LIST)
		/* here, the second param is the offset of the addr, tx is right behind rx */
		hisi_reg_sce_master_txaddr(hdev, plist_info->sg_cnt_in * HISI_SCE_REG_SRAM_STEP);

	/* start wait result */
	mb();
	start_run.reg.sce_str = 1;
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_STR_RUN, start_run.value); /* sce_reg_str */

	/* sce_reg_wait_idle */
	ret = hisi_reg_sce_wait_busy(hdev, HISI_SCE_REG_STATE_BUSY, HISI_SCE_VALUE_IDLE,
				     HISI_SCE_IDLE_CPU_START_TIMEOUT);
	if (pal_check(ret != BSP_RET_OK))
		return ret;

	start_run.value = 0;
	start_run.reg.sce_run = 1;
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_STR_RUN, start_run.value); /* sce_reg_run */

	if (hdev->polled == 0 && hdev->en_intr) {
		pal_hit_time();
		return ret;
	}

	timeoutus = hisi_dev_symm_cal_timeoutus(proc->inlen);
	if (proc->txmode == HISI_SYMM_TRANSFER_LIST) {
		pal_hit_time();
		ret = hisi_reg_sce_wait_int(hdev, HISI_SCE_REG_INT_SCE_MASK, HISI_SCE_VALUE_INT_VALID, timeoutus);
		pal_hit_time();
		if (pal_check(ret != BSP_RET_OK)) {
			pal_error("wait_int error, chk INT_SCE=0x%x, SCE_STATE=0x%x, ret=0x%x, timeoutus=0x%x\n",
				  hisi_reg_sce_read(hdev, HISI_SCE_OFF_INT_SCE),
				  hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_STATE), ret, timeoutus);
			return ret;
		}
	} else {
		pal_hit_time();
		/* sce_reg_wait_done */
		ret = hisi_reg_sce_wait_busy(hdev, HISI_SCE_REG_STATE_DONE, HISI_SCE_VALUE_DONE, timeoutus);
		pal_hit_time();
		if (pal_check(ret != BSP_RET_OK)) {
			pal_error("sce_reg_wait_done error\n");
			return ret;
		}

		if (proc->pb_out != NULL) {
			hisi_reg_sce_get_doutreg(hdev, &regaddr, &wordnum);
			ret = hisi_reg_read(ptr_add(ptr_to_ulong(hdev->sce_base), regaddr), wordnum, proc->pb_out,
					    byte2word(proc->outlen));
			if (pal_check(ret != BSP_RET_OK)) {
				pal_error("hisi_reg_read dout error\n");
				return ret;
			}
		}
		return ret;
	}

	return ret;
}

static void hisi_dev_plain_cpy_hwaddr(struct hicrypto_device *hdev, struct hisi_drv_symm_sg_list_info *psg_list_info,
				      struct hisi_cpy_list *plist_info)
{
	unsigned int hw_len;
	int i, j;
	unsigned long long hw_address;

	unused(hdev);
	for (i = 0, j = 0; i < psg_list_info->sg_cnt_in; i++, j++) {
		hw_address = psg_list_info->psrc_list[i].hw_address;
		hw_len = psg_list_info->psrc_list[i].hw_len;
		plist_info[j].laddr = htobe32(u64_lsb(hw_address));
		plist_info[j].haddr_and_len = htobe32((u64_msb(hw_address) << HISI_SCE_SRAM_LIST_HADDR_STRBIT) |
						      (hw_len & HISI_SCE_SRAM_LIST_LEN));
	}

	for (i = 0; i < psg_list_info->sg_cnt_out; i++, j++) {
		hw_address = psg_list_info->pdst_list[i].hw_address;
		hw_len = psg_list_info->pdst_list[i].hw_len;
		plist_info[j].laddr = htobe32(u64_lsb(hw_address));
		plist_info[j].haddr_and_len = htobe32((u64_msb(hw_address) << HISI_SCE_SRAM_LIST_HADDR_STRBIT) |
						      (hw_len & HISI_SCE_SRAM_LIST_LEN));
	}
}

static int hisi_dev_plain_cpy_proc(struct hicrypto_device *hdev, struct hisi_drv_symm_sg_list_info *drv_sg_list_info)
{
	int ret = err_drv(ERRCODE_UNKNOWN);
	hisi_sce_str_run_union start_run = { 0 };
	unsigned long long tx_addr,rx_addr;
	unsigned int list_num = drv_sg_list_info->sg_cnt_in + drv_sg_list_info->sg_cnt_out;
	unsigned long mm_size = sizeof(struct hisi_cpy_list) * list_num;
	struct hisi_cpy_list *addr = (struct hisi_cpy_list *)kzalloc(mm_size, GFP_KERNEL);
	if (pal_check(addr == NULL))
		return err_drv(ERRCODE_MEMORY);
	rx_addr = virt_to_phys(addr);

	(void)memset_s(addr, mm_size, 0, mm_size);
	hisi_dev_plain_cpy_hwaddr(hdev, drv_sg_list_info, addr);

	hicrypto_data_flush_dcache(ptr_to_ulong(addr), mm_size, ADDR_TYPE_KERNEL_VA);

	tx_addr = 0;

	/* dinlen/doutlen */
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_RX_DAT_LEN, list_num * sizeof(struct hisi_cpy_list));
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_TX_DAT_LEN, list_num * sizeof(struct hisi_cpy_list));

	/* tx addr is sram 0  */
	hisi_reg_sce_master_rxaddr(hdev, rx_addr);
	hisi_reg_sce_master_txaddr(hdev, tx_addr);

	if (hdev->polled == 0 && hdev->en_intr) {
		hisi_reg_sce_clr_int(hdev);
		hisi_reg_sce_cfg_int(hdev, HISI_SCE_VALUE_MSK);
	}

	/* start wait result */
	start_run.reg.sce_str = 1;
	mb();
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_STR_RUN, start_run.value); /* sce_reg_str */

	/* sce_reg_wait_idle */
	ret = hisi_reg_sce_wait_busy(hdev, HISI_SCE_REG_STATE_BUSY, HISI_SCE_VALUE_IDLE,
						HISI_SCE_IDLE_CPU_START_TIMEOUT);
	if (pal_check(ret != BSP_RET_OK))
			goto end_dstdma;

	start_run.value = 0;
	start_run.reg.sce_run = 1;
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_STR_RUN, start_run.value); /* sce_reg_run */

	ret = hisi_reg_sce_wait_int(hdev, HISI_SCE_REG_INT_SCE_MASK, HISI_SCE_VALUE_INT_VALID, HISI_TIMEOUT_BASE);
	if (pal_check(ret != BSP_RET_OK)) {
		pal_error("hisi_reg_sce_wait_int timeout error\n");
		goto end_dstdma;
	}

end_dstdma:
	if (pal_check(ret != BSP_RET_OK)) {
		#if defined(CONFIG_CRYPTO_HICRYPTO_V2_DEBUG) && CONFIG_CRYPTO_HICRYPTO_V2_DEBUG
		pal_error("hd cpy bg dump sce reg\n");
		hisi_dev_dump_sce_reg(hdev);
		pal_error("hd cpy end dump sce reg\n");
		pal_error("hd cpy bg dump km reg\n");
		hisi_dev_dump_km_reg(hdev);
		pal_error("hd cpy end dump km reg\n");
		hisi_reg_sce_listin_dump(hdev, drv_sg_list_info->sg_cnt_in);
		hisi_reg_sce_listout_dump(hdev, drv_sg_list_info->sg_cnt_out, drv_sg_list_info->sg_cnt_in);
		#else
		pal_error("hd cpy ret=0x%x\n", ret);
		#endif
	}

	if (addr != NULL) {
		kfree(addr);
		addr = NULL;
	}
	return ret;
}

static int hisi_sce_reg_get_gcm_extend(struct hicrypto_device *hdev, const void *pextend)
{
	struct hisi_dev_eparam_gcm *pgcm = NULL;
	unsigned char tag[HISI_SCE_REG_TAG_LEN] = { 0 };
	errno_t libc_ret;

	pgcm = (struct hisi_dev_eparam_gcm *)pextend;
	hisi_reg_read(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_AES_TAG_OUT), byte2word(HISI_SCE_REG_TAG_LEN),
		      tag, byte2word(HISI_SCE_REG_TAG_LEN));

	libc_ret = memcpy_s(pgcm->ptag, pgcm->taglen, tag, pgcm->taglen);
	if (pal_check(libc_ret != EOK))
		return err_drv(ERRCODE_MEMORY);

	return BSP_RET_OK;
}

static int hisi_sce_reg_cfg_gcm_extend(struct hicrypto_device *hdev, const void *pextend)
{
	struct hisi_dev_eparam_gcm *pgcm = NULL;
	int ret;

	pgcm = (struct hisi_dev_eparam_gcm *)pextend;
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_PADDING_EN, HISI_SCE_REG_PADDING_ENABLE);
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_GCM_AAD_LEN, pgcm->aadlen);
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_DATA_LEN_ALL, pgcm->payload_len);

	ret = hisi_reg_write(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_GCM_COUNTER0),
			     HISI_SCE_GCM_COUNTER0_REGNUM, pgcm->pgctr_j0, byte2word(pgcm->gctr_j0len));
	if (pal_check(ret != BSP_RET_OK)) {
		pal_info("gcm wr ctr j0 failed\n");
		return ret;
	}

	return BSP_RET_OK;
}

#define ccm_formate_q_len(nonce_len) ((14 - (nonce_len)) & 0x7)

static int hisi_sce_reg_cfg_ccm_extend(struct hicrypto_device *hdev, const void *pextend)
{
	struct hisi_dev_eparam_ccm *pccm = NULL;
	unsigned char aes_ctr_iv[HISI_SYMM_BLKLEN_AES] = { 0 };
	unsigned char aes_tag_in[HISI_SYMM_BLKLEN_AES] = { 0 };
	errno_t libc_ret;
	int ret;

	hisi_reg_sce_write(hdev, HISI_SCE_OFF_PADDING_EN, HISI_SCE_REG_PADDING_ENABLE);

	pccm = (struct hisi_dev_eparam_ccm *)pextend;
	(void)memset_s(aes_ctr_iv, sizeof(aes_ctr_iv), 0, sizeof(aes_ctr_iv));
	aes_ctr_iv[0] = ccm_formate_q_len(pccm->nonce_len);
	libc_ret = memcpy_s(&aes_ctr_iv[1], sizeof(aes_ctr_iv) - 1, pccm->pnonce, pccm->nonce_len);
	if (pal_check(libc_ret != EOK))
		return err_api(ERRCODE_MEMORY);

	ret = hisi_reg_write(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_GCM_COUNTER0),
			     HISI_SCE_GCM_COUNTER0_REGNUM, aes_ctr_iv, byte2word(sizeof(aes_ctr_iv)));
	if (pal_check(ret != BSP_RET_OK)) {
		pal_error("ccm wr aes_ctr_iv failed\n");
		return ret;
	}

	ret = hisi_reg_write(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_SCE_TAG_IN), HISI_SCE_TAG_IN_REGNUM,
			     aes_tag_in, byte2word(sizeof(aes_tag_in)));
	if (pal_check(ret != BSP_RET_OK)) {
		pal_error("ccm wr aes_tag_in failed\n");
		return ret;
	}

	return BSP_RET_OK;
}

static int hisi_sce_reg_get_ccm_extend(struct hicrypto_device *hdev, const void *pextend)
{
	struct hisi_dev_eparam_ccm *pccm = NULL;
	unsigned char macivout[HISI_SYMM_IVLEN_AES] = { 0 };
	unsigned int i;
	hisi_sce_cfg_union sce_cfg = { 0 };
	unsigned char tag[HISI_SCE_REG_TAG_LEN] = { 0 };
	errno_t libc_ret;

	pccm = (struct hisi_dev_eparam_ccm *)pextend;
	if (pal_check(pccm->taglen > sizeof(macivout)))
		return err_drv(ERRCODE_PARAMS);

	sce_cfg.value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_CFG);
	if (sce_cfg.reg.sce_decrypt == HISI_SCE_REG_DIRECTION_DECRYPT)
		hisi_reg_read(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_SCE_IVOUT2), HISI_SCE_MACIVOUT_WORDNUM,
			      macivout, byte2word(sizeof(macivout)));

	hisi_reg_read(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_AES_TAG_OUT), byte2word(HISI_SCE_REG_TAG_LEN),
		      tag, byte2word(HISI_SCE_REG_TAG_LEN));
	libc_ret = memcpy_s(pccm->ptag, pccm->taglen, tag, pccm->taglen);
	if (pal_check(libc_ret != EOK))
		return err_drv(ERRCODE_MEMORY);

	for (i = 0; i < pccm->taglen; i++)
		pccm->ptag[i] ^= macivout[i];

	return BSP_RET_OK;
}

static int hisi_dev_cipher_preprocess(struct hicrypto_device *hdev, struct hisi_dev_symm_data_proc *drv_symm_data)
{
	int ret = err_drv(ERRCODE_UNKNOWN);
	unsigned int eparam_id;

	if (drv_symm_data->pextend != NULL) {
		eparam_id = *(unsigned int *)(drv_symm_data->pextend);
		if (eparam_id == HISI_EPARAM_ID_GCM)
			ret = hisi_sce_reg_cfg_gcm_extend(hdev, drv_symm_data->pextend);
		if (eparam_id == HISI_EPARAM_ID_CCM)
			ret = hisi_sce_reg_cfg_ccm_extend(hdev, drv_symm_data->pextend);
		if (pal_check(ret != BSP_RET_OK))
			return ret;
	}

	if (drv_symm_data->pmacivin != NULL &&
	    drv_symm_data->macivinlen <= HISI_SCE_SCE_MACIVIN_WORDNUM * sizeof(unsigned int)) {
		hisi_reg_write(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_SCE_IVIN2),
			       HISI_SCE_SCE_MACIVIN_WORDNUM, drv_symm_data->pmacivin,
			       byte2word(drv_symm_data->macivinlen));
	}

	if (drv_symm_data->pivin != NULL && drv_symm_data->ivinlen <= HISI_SCE_SCE_IVIN_WORDNUM * sizeof(unsigned int)) {
		hisi_reg_write(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_SCE_IVIN1), HISI_SCE_SCE_IVIN_WORDNUM,
			       drv_symm_data->pivin, byte2word(drv_symm_data->ivinlen));
	}

	return BSP_RET_OK;
}

static int hisi_dev_cipher_postprocess(struct hicrypto_device *hdev, struct hisi_dev_symm_data_proc *drv_symm_data)
{
	int ret = err_drv(ERRCODE_UNKNOWN);
	unsigned int eparam_id;

	if (drv_symm_data->pivout != NULL &&
	    drv_symm_data->ivoutlen <= HISI_SCE_SCE_IVOUT_WORDNUM * sizeof(unsigned int)) {
		hisi_reg_read(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_SCE_IVOUT1),
			      HISI_SCE_SCE_IVOUT_WORDNUM, drv_symm_data->pivout, byte2word(drv_symm_data->ivoutlen));
	}

	if (drv_symm_data->pmacivout != NULL &&
	    drv_symm_data->macivoutlen <= HISI_SCE_MACIVOUT_WORDNUM * sizeof(unsigned int)) {
		hisi_reg_read(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_SCE_IVOUT2), HISI_SCE_MACIVOUT_WORDNUM,
			      drv_symm_data->pmacivout, byte2word(drv_symm_data->macivoutlen));
	}

	if (drv_symm_data->pextend != NULL) {
		eparam_id = *(unsigned int *)(drv_symm_data->pextend);
		if (eparam_id == HISI_EPARAM_ID_GCM)
			ret = hisi_sce_reg_get_gcm_extend(hdev, drv_symm_data->pextend);
		if (eparam_id == HISI_EPARAM_ID_CCM)
			ret = hisi_sce_reg_get_ccm_extend(hdev, drv_symm_data->pextend);
		if (pal_check(ret != BSP_RET_OK))
			return ret;
	}

	return BSP_RET_OK;
}

int hisi_dev_cipher_process(struct hicrypto_device *hdev, struct hisi_dev_symm_data_proc *drv_symm_data,
			    struct hisi_drv_symm_sg_list_info *drv_sg_list_info)
{
	int ret = err_drv(ERRCODE_UNKNOWN);
	unsigned int value;

	ret = hisi_dev_cipher_preprocess(hdev, drv_symm_data);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	ret = hisi_dev_symm_list_proc_data(hdev, drv_symm_data, drv_sg_list_info);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	if (hdev->polled == 0 && hdev->en_intr)
		return ret;

	ret = hisi_dev_cipher_postprocess(hdev, drv_symm_data);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;
end_handle:

	/* check alarm sce_reg_chk_alarm */
	value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_ALARM_MASK);
	if ((HISI_SCE_REG_ALARM_REGION & value) != 0)
		pal_error("alarm.value = %x\n", value);

	/* km_reg_chk_alarm */
	hisi_reg_km_write(hdev, HISI_KM_OFF_REG_LOCK, HISI_KM_VALUE_UNLOCK);
	value = hisi_reg_km_read(hdev, HISI_KM_OFF_ALARM_MASK);
	hisi_reg_km_write(hdev, HISI_KM_OFF_REG_LOCK, HISI_KM_VALUE_LOCK);
	if ((HISI_KM_REG_ALM_REGION & value) != HISI_KM_REG_ALM_EXPECT) {
		pal_error("kmalarm=%x\n", value);
		ret = err_drv(ERRCODE_ALARM);
	}

	return ret;
}

/* for sce list info cfg to sram */
int hisi_dev_plain_cpy(struct hicrypto_device *hdev, struct hisi_drv_symm_sg_list_info *drv_sg_list_info)
{
	int ret;
	hisi_sce_mode_union sce_mode = { 0 };

	if (pal_check((drv_sg_list_info == NULL || (drv_sg_list_info->sg_cnt_in + drv_sg_list_info->sg_cnt_out) <= 0)))
		return err_drv(ERRCODE_PARAMS);

	/* init */
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_REG_LOCK, HISI_SCE_VALUE_UNLOCK);

	/* sce mode */
	sce_mode.reg.sce_ip_sel = HISI_SCE_REG_ALGORITHM_PLAINTCPY;
	sce_mode.reg.sce_rx_dma_mode = HISI_SYMM_TRANSFER_MASTER;
	sce_mode.reg.sce_tx_dma_mode = HISI_SYMM_TRANSFER_SRAM;
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_MODE, sce_mode.value);

	hisi_reg_km_write(hdev, HISI_KM_OFF_REG_LOCK, HISI_KM_VALUE_UNLOCK); /* km_reg_cfg_lock */
	/* kmmode/keytype */
	reekm_reg_cfg_kmmode(hdev, HISI_KM_REG_KMMODE_CRYPTO);
	hisi_reg_km_write(hdev, HISI_KM_OFF_REG_LOCK, HISI_KM_VALUE_LOCK); /* km_reg_cfg_lock */

	/* process */
	ret = hisi_dev_plain_cpy_proc(hdev, drv_sg_list_info);

	/* deinit */
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_STATE, 0);		      /* sce_reg_clr_busydone */
	hisi_reg_sce_clr_int(hdev);					      /* sce_reg_clr_int */
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_REG_LOCK, HISI_SCE_VALUE_LOCK); /* sce_reg_cfg_lock */

	return ret;
}

int hisi_dev_cipher_post(struct hicrypto_device *hdev, struct hisi_dev_symm_data_proc *drv_symm_data,
			 struct hisi_drv_symm_sg_list_info *drv_list_info)
{
	unsigned int value, eparam_id;
	int ret;

	if (drv_symm_data->pivout != NULL && drv_symm_data->ivoutlen <= HISI_SCE_SCE_IVOUT_WORDNUM * sizeof(unsigned int))
		hisi_reg_read(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_SCE_IVOUT1),
			      HISI_SCE_SCE_IVOUT_WORDNUM, drv_symm_data->pivout, byte2word(drv_symm_data->ivoutlen));

	if (drv_symm_data->pmacivout != NULL && drv_symm_data->macivoutlen <= HISI_SCE_MACIVOUT_WORDNUM * sizeof(unsigned int))
		hisi_reg_read(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_SCE_IVOUT2), HISI_SCE_MACIVOUT_WORDNUM,
			      drv_symm_data->pmacivout, byte2word(drv_symm_data->macivoutlen));

	ret = BSP_RET_OK;
	if (drv_symm_data->pextend != NULL) {
		eparam_id = *(unsigned int *)(drv_symm_data->pextend);
		if (eparam_id == HISI_EPARAM_ID_GCM)
			ret = hisi_sce_reg_get_gcm_extend(hdev, drv_symm_data->pextend);
		if (eparam_id == HISI_EPARAM_ID_CCM)
			ret = hisi_sce_reg_get_ccm_extend(hdev, drv_symm_data->pextend);
		if (pal_check(ret != BSP_RET_OK))
			goto end_handle;
	}

end_handle:
	/* check alarm sce_reg_chk_alarm */
	value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_ALARM_MASK);
	if ((HISI_SCE_REG_ALARM_REGION & value) != 0)
		pal_error("alarm.value = %x\n", value);

	/* km_reg_chk_alarm */
	hisi_reg_km_write(hdev, HISI_KM_OFF_REG_LOCK, HISI_KM_VALUE_UNLOCK);
	value = hisi_reg_km_read(hdev, HISI_KM_OFF_ALARM_MASK);
	hisi_reg_km_write(hdev, HISI_KM_OFF_REG_LOCK, HISI_KM_VALUE_LOCK);
	if ((HISI_KM_REG_ALM_REGION & value) != HISI_KM_REG_ALM_EXPECT) {
		pal_error("kmalarm=%x\n", value);
		ret = err_drv(ERRCODE_ALARM);
	}
	if (pal_check(ret != BSP_RET_OK))
		hisi_dev_symmm_mntn_dump(hdev, drv_symm_data, drv_list_info);
	/* cipher dev deinit */
	(void)hisi_dev_cipher_deinit(hdev);
	return ret;
}

int hisi_dev_cipher_main(struct hicrypto_device *hdev, struct hisi_dev_symm_data_proc *drv_symm_data,
			 struct hisi_dev_cipher_param *cipher_param, struct hisi_drv_symm_sg_list_info *drv_list_info)
{
	int ret = err_drv(ERRCODE_UNKNOWN);

	/* list mode plain cpy to sram */
	if (drv_symm_data->rxmode == HISI_SYMM_TRANSFER_LIST) {
		ret = hisi_dev_plain_cpy(hdev, drv_list_info);
		if (pal_check(ret != BSP_RET_OK))
			return ret;
	}

	/* cipher dev init */
	ret = hisi_dev_cipher_init(hdev, cipher_param);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	/* en intr default: mask intr */
	if (hdev->polled == 0 && hdev->en_intr)
		hisi_reg_sce_cfg_int(hdev, HISI_SCE_VALUE_UNMSK);

	/* cipher dev process */
	ret = hisi_dev_cipher_process(hdev, drv_symm_data, drv_list_info);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	if (hdev->polled == 0 && hdev->en_intr)
		return ret;

end_handle:
	if (pal_check(ret != BSP_RET_OK))
		hisi_dev_symmm_mntn_dump(hdev, drv_symm_data, drv_list_info);
	/* cipher dev deinit */
	(void)hisi_dev_cipher_deinit(hdev);

	return ret;
}

int hisi_dev_irq_top(struct hicrypto_device *hdev, unsigned int *p_irq_status)
{
	*p_irq_status = hisi_reg_sce_read(hdev, HISI_SCE_OFF_INT_MSK);
	if ((*p_irq_status & HISI_SCE_REG_INT_SCE_MASK) == HISI_SCE_VALUE_INT_VALID)
		hisi_reg_sce_cfg_int(hdev, HISI_SCE_VALUE_MSK);
	return BSP_RET_OK;
}
