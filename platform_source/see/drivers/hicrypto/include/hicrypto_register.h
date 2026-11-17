

/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2021. All rights reserved.
 * Description: security engine control
 * Create     : 2017/12/30
 */
#ifndef __HICRYPTO_REGISTER_H__
#define __HICRYPTO_REGISTER_H__
#include <linux/mm.h>

#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_dft.h"
#include "hicrypto_utils.h"
#include "hicrypto_io.h"

#define hisi_reg_mskwr_one(regaddr, bakaddr, mask, value, rand_delay)                        \
	do {                                                                                 \
		pal_write_u32(((mask) ^ (value)), bakaddr);                                  \
		((void)(rand_delay));                                                        \
		pal_write_u32(((mask) ^ (value)), regaddr);                                  \
		(regaddr) = (void __iomem *)(uintptr_t)((uintptr_t)(regaddr) + sizeof(unsigned int)); \
	} while (0)

int hisi_reg_write_mask(void __iomem *regaddr, unsigned int reg32size, void __iomem *bakaddr,
			unsigned int mask, const void *src, unsigned int wordnum, unsigned int rand_delay);
int hisi_reg_write_mask_no_bakaddr(void __iomem *regaddr, unsigned int reg32size, unsigned int mask,
									const void *src, unsigned int wordnum);
int hisi_reg_read_mask(void __iomem * regaddr, unsigned int reg32size, void __iomem * bakaddr,
			unsigned int mask, void *dst, unsigned int wordnum, u32 rand_delay);
int hisi_reg_write(void __iomem *reg32addr, unsigned int reg32size, const void *memory, unsigned int wordnum);

int hisi_reg_read(void __iomem *reg32addr, unsigned int reg32size, void *memory, unsigned int wordnum);

#endif