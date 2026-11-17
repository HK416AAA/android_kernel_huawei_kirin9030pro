/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: hardware crypto engine common soft process
 * Create: 2024/03/01
 */
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/dma-mapping.h>
#include <linux/dma-direct.h>
#include <linux/scatterlist.h>

#include "hicrypto_errno.h"
#include "hicrypto_common.h"
#include "hicrypto_dev_symm.h"
#include "hicrypto_macro.h"
#include "hicrypto_io.h"
#include "hicrypto_log.h"
#include "hicrypto_dft.h"
#include "hicrypto_regs.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

 /* mspe-ree ddr total size: 1M.
 * ----------+---------------------+---------+ --> 0
 *           | PA_BUFF1            | 256KB   |
 *           | PA_BUFF2            | 256KB   |
 * sre_mmap  +---------------------+---------+ --> 0x80000
 *           | RESEREVED           | 512KB   |
 * ----------+---------------------+---------+ --> 0x100000
 */
#define HICRYPTO_PAGE_SIZE            4096
#define HICRYPTO_PA_BUFF_SIZE         (4096 << 6) /* 256k */
#define HICRYPTO_PA_BUFF1_OFFSET      0
#define HICRYPTO_PA_BUFF2_OFFSET      (HICRYPTO_PA_BUFF1_OFFSET + HICRYPTO_PA_BUFF_SIZE)

enum hicrypto_pa_type {
	HICRYPTO_PA_BUFF1_TYPE = 0x0,
	HICRYPTO_PA_BUFF2_TYPE = 0x1,
	HICRYPTO_PA_RESERVED_TYPE = 0xF,
};

static int hicrypto_reserve_copy_from_user(struct hicrypto_device *hdev, struct hi_data_addr *pva, unsigned long long pa_offset)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	void *reserve_buff = ptr_add(ptr_to_ulong(hdev->reserved_vir_basei), pa_offset);
	if (!reserve_buff) {
		pal_error("hicrypto reserved_vir_basei is null.\n");
		return err_api(ERRCODE_NULL);
	}
	if (pal_check(pva->len > HICRYPTO_PA_BUFF_SIZE))
		return err_api(ERRCODE_PARAMS);

	if (pva->type == ADDR_TYPE_KERNEL_VA) {
		ret = memcpy_s(reserve_buff, pva->len, pva->addr.cpu_addr, pva->len);
		if (pal_check(ret != EOK)) {
			pal_error("copy_from_user memcpy failed, ret=%d\n", ret);
			return err_api(ERRCODE_MEMORY);
		}
	}
	if (pva->type == ADDR_TYPE_USER_VA) {
		ret = copy_from_user(reserve_buff, pva->addr.cpu_addr, pva->len);
		if (pal_check(ret != 0)) {
			pal_error("copy_from_user failed, ret=%d\n", ret);
			return err_api(ERRCODE_MEMORY);
		}
	}
	hicrypto_data_flush_dcache(reserve_buff, pva->len, ADDR_TYPE_KERNEL_VA);
	return BSP_RET_OK;
}

static int hicrypto_reserve_copy_to_user(struct hicrypto_device *hdev, struct hi_data_addr *pva, unsigned long long pa_offset)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	void *reserve_buff = ptr_add(ptr_to_ulong(hdev->reserved_vir_basei), pa_offset);
	if (!reserve_buff) {
		pal_error("hicrypto reserved_phy_base is null.\n");
		return err_api(ERRCODE_NULL);
	}
	if (pal_check(pva->len > HICRYPTO_PA_BUFF_SIZE))
		return err_api(ERRCODE_PARAMS);

	hicrypto_data_invalidate_dcache(reserve_buff, pva->len, ADDR_TYPE_KERNEL_VA);
	if (pva->type == ADDR_TYPE_KERNEL_VA) {
		ret = memcpy_s(pva->addr.cpu_addr, pva->len, reserve_buff, pva->len);
		if (pal_check(ret != EOK)){
			pal_error("copy_to_user memcpy failed, ret=%d\n", ret);
			return err_api(ERRCODE_MEMORY);
		}
	}
	if (pva->type == ADDR_TYPE_USER_VA) {
		ret = copy_to_user(pva->addr.cpu_addr, reserve_buff, pva->len);
		if (pal_check(ret != 0)) {
			pal_error("copy_to_user failed, ret=%d\n", ret);
			return err_api(ERRCODE_MEMORY);
		}
	}
	ret = memset_s(reserve_buff, pva->len, 0, pva->len);
	if (pal_check(ret != EOK))
		pal_error("memset_s failed, ret=%d\n", ret);
	return BSP_RET_OK;
}

static int hicrypto_copy_virt_to_phy(struct hicrypto_device *hdev, unsigned int num, struct hi_data_addr *pva, struct hisi_sg_phy_list *ppa)
{
	int ret = err_api(ERRCODE_UNKNOWN);

	if (num == HICRYPTO_PA_BUFF1_TYPE) {
		ret = hicrypto_reserve_copy_from_user(hdev, pva, HICRYPTO_PA_BUFF1_OFFSET);
		if (pal_check(ret != BSP_RET_OK))
			return ret;
		ppa->hw_address = ptr_to_ulong(hdev->reserved_phy_base) + HICRYPTO_PA_BUFF1_OFFSET;
		ppa->hw_len = pva->len;
	}
	if (num == HICRYPTO_PA_BUFF2_TYPE) {
		ret = hicrypto_reserve_copy_from_user(hdev, pva, HICRYPTO_PA_BUFF2_OFFSET);
		if (pal_check(ret != BSP_RET_OK))
			return ret;
		ppa->hw_address = ptr_to_ulong(hdev->reserved_phy_base) + HICRYPTO_PA_BUFF2_OFFSET;
		ppa->hw_len = pva->len;
	}
	return BSP_RET_OK;
}

static int hicrypto_copy_phy_to_virt(struct hicrypto_device *hdev, unsigned int num, struct hi_data_addr *pva)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	if (num == HICRYPTO_PA_BUFF1_TYPE) {
		ret = hicrypto_reserve_copy_to_user(hdev, pva, HICRYPTO_PA_BUFF1_OFFSET);
		if (pal_check(ret != BSP_RET_OK))
			return ret;
	}
	if (num == HICRYPTO_PA_BUFF2_TYPE) {
		ret = hicrypto_reserve_copy_to_user(hdev, pva, HICRYPTO_PA_BUFF2_OFFSET);
		if (pal_check(ret != BSP_RET_OK))
			return ret;
	}
	return BSP_RET_OK;
}

int hisi_dev_symm_build_rxaddr(struct hicrypto_device *hdev, struct hisi_dev_symm_data_proc *proc,
	struct hisi_drv_symm_sg_list_info *plist_sg_info)
{
	unsigned int i;
	int ret = err_api(ERRCODE_UNKNOWN);
	struct hisi_sg_phy_list *pplist = NULL;
	unsigned int list_alloc_size = sizeof(struct hisi_sg_phy_list) * HISI_CTX_DATA_SIZE;

	/* 申请链表信息内存 */
	plist_sg_info->psrc_list = (struct hisi_sg_phy_list *)kmalloc(list_alloc_size, GFP_KERNEL);
	if (pal_check(!plist_sg_info->psrc_list))
		return err_api(ERRCODE_MEMORY);
	(void)memset_s(plist_sg_info->pdst_list, list_alloc_size, 0, list_alloc_size);

	/* get pa addr list and  flush */
	plist_sg_info->sg_cnt_in = 0;
	for (i = 0; i < proc->din_num; i++) {
		if (pal_check(plist_sg_info->sg_cnt_in > HISI_CTX_DATA_SIZE)) {
			pal_error("listin_num greater than upper limit \n");
			ret = err_api(ERRCODE_PARAMS);
			goto end_handle;
		}
		pplist = &(plist_sg_info->psrc_list[i]);
		ret = hicrypto_copy_virt_to_phy(hdev, i, &(proc->pdin[i]), pplist);
		plist_sg_info->sg_cnt_in++;
		plist_sg_info->doutlen += pplist->hw_len;
		if (pal_check(ret != BSP_RET_OK))
			goto end_handle;
	}
	return ret;
end_handle:
	if (plist_sg_info->psrc_list != NULL) {
		kfree(plist_sg_info->psrc_list);
		plist_sg_info->psrc_list = NULL;
	}
	return ret;
}

int hisi_dev_symm_tx_out_process(struct hicrypto_device *hdev, struct hisi_dev_symm_data_proc *proc,
				 struct hisi_drv_symm_sg_list_info *plist_sg_info)
{
	unsigned int i;
	int ret = err_drv(ERRCODE_UNKNOWN);

	/* tx out process: flush worksapce and memcpy workspace to usrspace */
	if (proc->txmode == HISI_SYMM_TRANSFER_LIST) {
		for (i = 0; i < proc->dout_num; i++) {
			ret = hicrypto_copy_phy_to_virt(hdev, i, &proc->pdout[i]);
			if (pal_check(ret != BSP_RET_OK))
				return ret;
		}
	}
	return BSP_RET_OK;
}

int hisi_dev_symm_build_hwaddr(struct hicrypto_device *hdev, struct hisi_dev_symm_data_proc *proc,
			       struct hisi_drv_symm_sg_list_info *plist_sg_info)
{
	int ret = err_drv(ERRCODE_UNKNOWN);
	/* list mode not support zero len */
	if (proc->inlen == 0 && proc->outlen == 0) {
		proc->rxmode = HISI_SYMM_TRANSFER_MASTER;
		proc->txmode = HISI_SYMM_TRANSFER_MASTER;
		return BSP_RET_OK;
	}

	/* rx process: malloc list \get hdaddr\flush */
	if (proc->rxmode == HISI_SYMM_TRANSFER_LIST) {
		ret = hisi_dev_symm_build_rxaddr(hdev, proc, plist_sg_info);
		if (pal_check(ret != BSP_RET_OK))
			return ret;
	}

	/* all in reserverd memory  in/out in one place */
	if (proc->txmode == HISI_SYMM_TRANSFER_LIST) {
		/* get dst hw addr */
		plist_sg_info->sg_cnt_out = plist_sg_info->sg_cnt_in;
		plist_sg_info->pdst_list = plist_sg_info->psrc_list;
	}
	return BSP_RET_OK;
}

int hisi_dev_symm_clean_workspace(struct hisi_dev_symm_data_proc *proc, struct hisi_drv_symm_sg_list_info *plist_sg_info)
{
	int list_len = sizeof(struct hisi_sg_phy_list) * HISI_CTX_DATA_SIZE;
	unsigned int i;

	/* tx out process: flush worksapce and memcpy workspace to usrspace */
	if (proc->rxmode == HISI_SYMM_TRANSFER_LIST) {
		/* clear rx */
		if (plist_sg_info->psrc_list != NULL) {
			(void)memset_s((unsigned char *)(uintptr_t)plist_sg_info->psrc_list, list_len, 0, list_len);
			kfree(plist_sg_info->psrc_list);
			plist_sg_info->psrc_list = NULL;
		}
	}
	return BSP_RET_OK;
}

unsigned int hisi_dev_symm_cal_timeoutus(unsigned int dinlen)
{
	unsigned int timeoutus;
	unsigned int blknum;
	unsigned int freq = 240;
	unsigned int timecost_per_block;

	/*
	 * get blknum accroding to dinlen,
	 * when compute, we use the mini blklen to get the max blknum
	 */
	blknum = dinlen / HISI_SYMM_BLKLEN_DES + 1;

	timecost_per_block = HISI_CYCLES_PER_BLOCK_MAX / freq + 1;
	timeoutus = timecost_per_block * blknum;

	/* multiple of 4 for redundance when cal timeout */
	if (timeoutus < (U32_MAX / HISI_REDUNDANCE_COEF - HISI_TIMEOUT_BASE)) {
		timeoutus = HISI_REDUNDANCE_COEF * (timeoutus + HISI_TIMEOUT_BASE);
	} else {
		/* overflow */
		timeoutus = U32_MAX;
	}

	return timeoutus;
}