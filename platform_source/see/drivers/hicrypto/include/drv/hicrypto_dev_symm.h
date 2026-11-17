/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: hardware crypto engine dev ops
 * Create: 2023/03/07
 */

#ifndef __HICRYPTO_DEV_SYMM_H__
#define __HICRYPTO_DEV_SYMM_H__

#include "hicrypto_driver.h"
#include "hicrypto_chip.h"
#include "hicrypto_dev_data.h"

/* from  api alg to reg alg */
enum hisi_sce_reg_algorithm hisi_symm_get_algorithm(unsigned int alg);

// --------------------------------------
// BLOCK: SCE
// --------------------------------------
/* get sce max list node len */
static inline unsigned int hisi_dev_symm_get_list_node_maxlen(void)
{
	return (1U << HISI_SCE_SRAM_LIST_HADDR_STRBIT);
}
/* get blk len by sce reg alg */
enum hisi_symm_blklen hisi_reg_sce_get_blklen(struct hicrypto_device *hdev);
/* sce reg read */
unsigned int hisi_reg_sce_read(struct hicrypto_device *hdev, unsigned int offset);
/* sce reg write */
void hisi_reg_sce_write(struct hicrypto_device *hdev, unsigned int offset, unsigned int value);
/* check sce state is idle */
int hisi_reg_sce_wait_busy(struct hicrypto_device *hdev, unsigned int mask, unsigned int value,
					unsigned int timeout_us);
/* check sce int is ok */
int hisi_reg_sce_wait_int(struct hicrypto_device *hdev, unsigned int mask, unsigned int value,
					unsigned int timeout_us);
/* clr sce int */
void hisi_reg_sce_clr_int(struct hicrypto_device *hdev);

/* mask interrupt (interrupt of done computing) */
void hisi_reg_sce_cfg_int(struct hicrypto_device *hdev, unsigned int mask);

/* cfg sce rx addr */
void hisi_reg_sce_master_rxaddr(struct hicrypto_device *hdev, unsigned long long rxaddr);
/* cfg sce tx addr */
void hisi_reg_sce_master_txaddr(struct hicrypto_device *hdev, unsigned long long txaddr);
/* cfg sce sram */
int hisi_reg_sce_write_sram(struct hicrypto_device *hdev, unsigned int addr, unsigned int value);
/* get sce out reg addr */
void hisi_reg_sce_get_doutreg(struct hicrypto_device *hdev, unsigned int *regaddr, unsigned int *regnum);
/* cfg sce din */
int hisi_reg_sce_input_din(struct hicrypto_device *hdev, const unsigned char *pdin, unsigned int dinlen);
/* cfg sce alg\mode\key */
int hisi_reg_sce_cfg_amdk(struct hicrypto_device *hdev, unsigned int algorithm, unsigned int mode,
				 unsigned int direction, unsigned int keytype, unsigned int keylen);
/* cfg sce iv in */
int hisi_reg_sce_input_ivin(struct hicrypto_device *hdev, const unsigned char *pivin, unsigned int ivinlen);

/* symm mntn info dump */
void hisi_dev_symmm_mntn_dump(struct hicrypto_device *hdev, const struct hisi_dev_symm_data_proc *proc,
			      struct hisi_drv_symm_sg_list_info *drv_list_info);
/* cipher sce reg config init */
int hisi_dev_cipher_init(struct hicrypto_device *hdev, struct hisi_dev_cipher_param *cipher_param);
/* cipher sce reg config core flow */
int hisi_dev_cipher_process(struct hicrypto_device *hdev, struct hisi_dev_symm_data_proc *drv_symm_data,
							struct hisi_drv_symm_sg_list_info *drv_sg_list_info);
/* cipher sce reg config deinit */
int hisi_dev_cipher_deinit(struct hicrypto_device *hdev);

/* cipher din is plain cpy, sce reg config core flow */
int hisi_dev_cipher_main(struct hicrypto_device *hdev, struct hisi_dev_symm_data_proc *drv_symm_data,
			 struct hisi_dev_cipher_param *cipher_param, struct hisi_drv_symm_sg_list_info *drv_list_info);
/* cipher sce reg config get iv/mac out flow */
int hisi_dev_cipher_post(struct hicrypto_device *hdev, struct hisi_dev_symm_data_proc *drv_symm_data,
			 struct hisi_drv_symm_sg_list_info *drv_list_info);
/* plain_cpy sce reg config core flow */
int hisi_dev_plain_cpy(struct hicrypto_device *hdev, struct hisi_drv_symm_sg_list_info *drv_sg_list_info);

/* read sce irq status */
int hisi_dev_irq_top(struct hicrypto_device *hdev, unsigned int *p_irq_status);

#endif
