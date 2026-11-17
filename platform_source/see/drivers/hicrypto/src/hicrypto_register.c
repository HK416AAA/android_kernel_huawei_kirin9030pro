/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: security register
 * Create     : 2024/4/13
 */
#include <asm/page.h>
#include <linux/crypto.h>
#include <linux/delay.h>
#include <linux/iopoll.h>
#include <linux/device.h>
#include <linux/dma-mapping.h>
#include <linux/timex.h>
#include <linux/dma-direct.h>

#include "hicrypto_register.h"

#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_utils.h"
#include "hicrypto_io.h"
#include "hicrypto_macro.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

// --------------------------------------
// BLOCK:  symm comm sft func
// --------------------------------------
int hisi_reg_write_mask(void __iomem *regaddr, unsigned int reg32size, void __iomem *bakaddr, unsigned int mask,
			const void *src, unsigned int wordnum, unsigned int rand_delay)
{
	unsigned int *pmem = (unsigned int *)src;

	if (pal_check(regaddr == 0 || bakaddr == 0 || !src || wordnum > reg32size))
		return err_drv(ERRCODE_PARAMS);

	/* write to register in word order */
	while (wordnum > 0) {
		hisi_reg_mskwr_one(regaddr, bakaddr, mask, *pmem, rand_delay);
		pmem++;
		wordnum--;
	}
	return BSP_RET_OK + (int)wordnum; /* flow control */
}

int hisi_reg_write_mask_no_bakaddr(void __iomem *regaddr, unsigned int reg32size, unsigned int mask,
				   const void *src, unsigned int wordnum)
{
	unsigned int value = 0;

	if (pal_check(regaddr == 0 || !src || wordnum > reg32size))
		return err_drv(ERRCODE_PARAMS);

	while (wordnum > 0) {
		word_set(&value, src);
		pal_write_u32(((mask) ^ (value)), regaddr);
		regaddr = ptr_add(ptr_to_ulong(regaddr), sizeof(unsigned int));
		src = ptr_add(ptr_to_ulong(src), sizeof(unsigned int));
		wordnum--;
	}

	return BSP_RET_OK + (int)wordnum; /* flow control */
}
	
static int hisi_reg_read_mask_one(unsigned int *pvalue, void __iomem * reg32addr,
				  void __iomem * bakaddr, unsigned int mask, unsigned int rand_delay)
{
	unsigned int value;
	unsigned int bak_val;

	value = pal_read_u32(reg32addr);
	unused(rand_delay);
	bak_val = pal_read_u32(bakaddr);
	if (value != bak_val) {
		pal_error("reg(" PAL_FMT_PTR ")=" PAL_FMT_HEX
			  " no match bak(" PAL_FMT_PTR ")=" PAL_FMT_HEX "\n",
			  reg32addr, value, bakaddr, bak_val);
		return err_drv(ERRCODE_VERIFY);
	}

	*pvalue = value ^ (mask);
	return BSP_RET_OK;
}

int hisi_reg_read_mask(void __iomem *regaddr, unsigned int reg32size, void __iomem *bakaddr,
			unsigned int mask, void *dst, unsigned int wordnum, u32 rand_delay)
{
	unsigned int value = 0;
	void __iomem *regaddr_end;
	int ret = err_drv(ERRCODE_UNKNOWN);

	if (pal_check(regaddr == 0 || bakaddr == 0 || !dst || wordnum > reg32size))
		return err_drv(ERRCODE_PARAMS);

	regaddr_end = ptr_add(regaddr, word2byte(wordnum));
	while (regaddr < regaddr_end) {
		ret = hisi_reg_read_mask_one(&value, regaddr, bakaddr, mask, rand_delay);
		if (pal_check(ret != BSP_RET_OK))
			return ret;
		word_set(dst, &value);
		dst = ptr_add(dst, sizeof(unsigned int));
		regaddr = ptr_add(regaddr, sizeof(unsigned int));
	}
	return BSP_RET_OK + (int)(ptr_to_ulong(regaddr_end) - ptr_to_ulong(regaddr)); /* flow control */
}

int hisi_reg_write(void __iomem *reg32addr, u32 reg32size, const void *memory, u32 wordnum)
{
	unsigned int *pmem = (unsigned int *)memory;
	unsigned int nr = 0;

	if (pal_check(reg32addr == 0 || !memory || wordnum > reg32size))
		return err_drv(ERRCODE_PARAMS);

	while (nr < wordnum) {
		pal_write_u32(pmem[nr], reg32addr);
		reg32addr += sizeof(u32);
		nr++;
	}

	return BSP_RET_OK + (int)(wordnum - nr); /* flow control */
}

int hisi_reg_read(void __iomem *reg32addr, u32 reg32size, void *memory, u32 wordnum)
{
	unsigned int *pmem = (unsigned int *)memory;
	unsigned int nr = 0;

	if (pal_check(!memory || wordnum > reg32size))
		return err_drv(ERRCODE_PARAMS);

	while (nr < wordnum) {
		pmem[nr] = pal_read_u32(reg32addr);
		reg32addr += sizeof(u32);
		nr++;
	}

	return BSP_RET_OK + (int)(wordnum - nr); /* flow control */
}
