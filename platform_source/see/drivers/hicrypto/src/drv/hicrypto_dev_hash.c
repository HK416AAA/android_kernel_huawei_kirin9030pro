/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine hash hd interface
 * Create: 2024/04/11
 */
#include <securec.h>
#include <asm/barrier.h>

#include "hicrypto_dev_hash.h"

#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_dft.h"
#include "hicrypto_utils.h"
#include "hicrypto_io.h"
#include "hicrypto_common.h"

#include "hicrypto_regs.h"
#include "hicrypto_dev_chip.h"
#include "hicrypto_dev_km.h"
#include "hicrypto_dev_symm.h"
#include "hicrypto_register.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

static int hisi_dev_hash_init(struct hicrypto_device *hdev)
{
	int ret;
	hisi_sce_state_union sce_state = { 0 };

	/* pre config */
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_REG_LOCK, HISI_SCE_VALUE_UNLOCK); /* sce_reg_cfg_lock */
	ret = hisi_reg_sce_wait_busy(hdev, HISI_SCE_REG_STATE_BUSY, HISI_SCE_VALUE_IDLE,
				     HISI_SCE_IDLE_ENTRY_TIMEOUT); /* sce_reg_wait_idle */
	if (pal_check(ret != BSP_RET_OK)) {
		pal_error("sce_reg_wait_idle failed\n");
		return ret;
	}

	/* alarm unmask */
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_ALARM_MASK_EN, HISI_SCE_VALUE_ALM_UNMSK);

	sce_state.value = 0;
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_STATE, sce_state.value); /* sce_reg_clr_busydone */

	return ret;
}

static int hisi_dev_hash_cfg_param(struct hicrypto_device *hdev, struct hi_hash_req_ctx_inner *rctx)
{
	hisi_km_mode_union km_mode = { 0 };
	hisi_sce_mode_union sce_mode = { 0 };
	hisi_sce_cfg_union sce_cfg = { 0 };
	int ret;

	hisi_reg_km_write(hdev, HISI_KM_OFF_REG_LOCK, HISI_KM_VALUE_UNLOCK); /* km_reg_cfg_lock */
	km_mode.value = hisi_reg_km_read(hdev, HISI_KM_OFF_KM_MODE);
	km_mode.reg.km_mode = HISI_KM_VALUE_MODE_CRYPTO;
	hisi_reg_km_write(hdev, HISI_KM_OFF_KM_MODE, km_mode.value);	   /* km_reg_cfg_kmmode */
	hisi_reg_km_write(hdev, HISI_KM_OFF_REG_LOCK, HISI_KM_VALUE_LOCK); /* km_reg_cfg_lock */

	sce_mode.value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_MODE);
	sce_mode.reg.sce_ip_sel = hisi_symm_get_algorithm(rctx->alg);
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_MODE, sce_mode.value);

	sce_cfg.value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_CFG);
	sce_cfg.reg.sce_mode = HISI_SCE_REG_MODE_CBC;
	sce_cfg.reg.sce_decrypt = HISI_SCE_REG_DIRECTION_ENCRYPT;
	sce_cfg.reg.sce_key_length = HISI_SCE_REG_KEY_WIDTH_128;
	sce_cfg.reg.tdes = 0;
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_CFG, sce_cfg.value); /* sce_reg_cfg_amdk */

	hisi_reg_sce_write(hdev, HISI_SCE_OFF_PADDING_EN, rctx->stage == HISI_SYMM_STAGE_DOFINAL ? 1 : 0);
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_DATA_LENTH, rctx->total_bytes); /* sce_reg_cfg_hashpadding */

	ret = hisi_reg_write(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_SCE_IVIN2),
			     HISI_SCE_SCE_MACIVIN_WORDNUM, rctx->digest, byte2word(rctx->iv_len));
	if (pal_check(ret != BSP_RET_OK)) {
		pal_info("hicrypto hash wr iv failed\n");
		return ret;
	}

	return ret;
}

static int hisi_dev_hash_cfg_din(struct hicrypto_device *hdev, struct hisi_dev_symm_data_proc *proc,
				 struct hisi_drv_symm_sg_list_info *plist_info)
{
	if (pal_check(proc == NULL || plist_info == NULL))
		return err_drv(ERRCODE_NULL);
	hisi_sce_mode_union sce_mode = { 0 };

	/* rx tx mode sce_reg_cfg_rxtxmode */
	sce_mode.value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_MODE);
	sce_mode.reg.sce_rx_dma_mode = proc->rxmode;
	sce_mode.reg.sce_tx_dma_mode = proc->txmode;
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_MODE, sce_mode.value);

	/* din len sce_reg_cfg_dinlen */
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_RX_DAT_LEN, plist_info->sg_cnt_in);

	/* rxaddr */
	hisi_reg_sce_master_rxaddr(hdev, 0);
	return BSP_RET_OK;
}

static int hisi_dev_hash_wait_get_out(struct hicrypto_device *hdev, struct hi_hash_req_ctx_inner *rctx,
				      unsigned int dinlen)
{
	hisi_sce_str_run_union start_run = { .value = 0 };
	unsigned int value, timeoutus;
	int ret;

	/* start wait result */
	mb();
	start_run.reg.sce_str = 1;
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_STR_RUN, start_run.value); /* sce_reg_str */
	/* sce_reg_wait_idle */
	ret = hisi_reg_sce_wait_busy(hdev, HISI_SCE_REG_STATE_BUSY, HISI_SCE_VALUE_IDLE,
				     HISI_SCE_IDLE_CPU_START_TIMEOUT);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;

	start_run.value = 0;
	start_run.reg.sce_run = 1;
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_STR_RUN, start_run.value); /* sce_reg_run */

	/* sce_reg_wait_done */
	timeoutus = hisi_dev_symm_cal_timeoutus(dinlen);

	pal_hit_time();
	ret = hisi_reg_sce_wait_busy(hdev, HISI_SCE_REG_STATE_DONE, HISI_SCE_VALUE_DONE, timeoutus);
	if (pal_check(ret != BSP_RET_OK))
		goto end_handle;
	pal_hit_time();

	/* out result sce_reg_output_dout */
	ret = hisi_reg_read(ptr_add(ptr_to_ulong(hdev->sce_base), HISI_SCE_OFF_SCE_IVOUT2), HISI_SCE_MACIVOUT_WORDNUM,
			    rctx->digest, byte2word(rctx->iv_len));
	if (pal_check(ret != BSP_RET_OK)) {
		pal_info("hicrypto hash rd out failed\n");
		goto end_handle;
	}

end_handle:
	/* check alarm sce_reg_chk_alarm */
	value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_ALARM_MASK);
	if ((HISI_SCE_REG_ALARM_REGION & value) != 0)
		pal_info("alarm.value = 0x%x\n", value);

	/* km_reg_chk_alarm */
	hisi_reg_km_write(hdev, HISI_KM_OFF_REG_LOCK, HISI_KM_VALUE_UNLOCK);
	value = hisi_reg_km_read(hdev, HISI_KM_OFF_ALARM_MASK);
	hisi_reg_km_write(hdev, HISI_KM_OFF_REG_LOCK, HISI_KM_VALUE_LOCK);
	if (pal_check((HISI_KM_REG_ALM_REGION & value) != HISI_KM_REG_ALM_EXPECT)) {
		pal_info("kmalarm=%x\n", value);
		ret = err_drv(ERRCODE_ALARM);
		return ret;
	}

	return ret;
}

static void hisi_dev_hash_deinit(struct hicrypto_device *hdev)
{
	hisi_sce_state_union sce_state = { 0 };

	sce_state.value = 0;
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_STATE, sce_state.value);    /* sce_reg_clr_busydone */
	hisi_reg_sce_write(hdev, HISI_SCE_OFF_REG_LOCK, HISI_SCE_VALUE_LOCK); /* sce_reg_cfg_lock */
}

int hisi_dev_hash_run_cmd(struct hicrypto_device *hdev, struct hi_hash_req_ctx_inner *ctx,
			  struct hisi_dev_symm_data_proc *proc, struct hisi_drv_symm_sg_list_info *plist_sg_info)
{
	int ret;

	/* zero len process */
	if (ctx->stage == HISI_SYMM_STAGE_DOFINAL && ctx->total_bytes == 0)
		return BSP_RET_OK;
	/* plain cpy list info */
	if (proc->rxmode == HISI_SYMM_TRANSFER_LIST) {
		ret = hisi_dev_plain_cpy(hdev, plist_sg_info);
		if (pal_check(ret != BSP_RET_OK))
			return ret;
	}

	/* pre config */
	ret = hisi_dev_hash_init(hdev);
	if (pal_check(ret != BSP_RET_OK)) {
		pal_error("hisi_dev_hash_init failed\n");
		goto end_handle;
	}

	ret = hisi_dev_hash_cfg_param(hdev, ctx);
	if (pal_check(ret != BSP_RET_OK)) {
		pal_error("hisi_dev_hash_cfg_param failed\n");
		goto end_handle;
	}

	ret = hisi_dev_hash_cfg_din(hdev, proc, plist_sg_info);
	if (pal_check(ret != BSP_RET_OK)) {
		pal_error("hisi_dev_hash_cfg_din failed\n");
		goto end_handle;
	}

	ret = hisi_dev_hash_wait_get_out(hdev, ctx, ctx->cur_process_bytes);
	if (pal_check(ret != BSP_RET_OK)) {
		pal_error("hisi_dev_hash_wait_get_out failed\n");
		goto end_handle;
	}

end_handle:
	if (pal_check(ret != BSP_RET_OK))
		hisi_dev_symmm_mntn_dump(hdev, proc, plist_sg_info);

	hisi_dev_hash_deinit(hdev);
	return ret;
}
