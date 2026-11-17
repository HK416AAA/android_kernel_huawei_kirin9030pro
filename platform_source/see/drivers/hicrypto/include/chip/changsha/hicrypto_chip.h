/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: hardware crypto engine chip define
 * Create: 2024/01/27
 */
#ifndef __HICRYPTO_CHIP_H__
#define __HICRYPTO_CHIP_H__

#define HISI_SCE_SRAM_LIST_HADDR_STRBIT 28
#define HISI_SCE_SRAM_LIST_LEN_REGION ((1U << HISI_SCE_SRAM_LIST_HADDR_STRBIT) - 1)
#define HISI_SCE_ADDR_DMA_BITS 36

#define HISI_CFG_AWR_STRBIT 20
#define HISI_CFG_AWR_DOMAIN (0x2 << HISI_CFG_AWR_STRBIT)

/* aw/ar cache bit[25:22] */
#define HISI_CFG_AWR_CACHE_STRBIT 22
/* aw cache 4'b0111 write not allocate sc */
#define HISI_CFG_AW_CACHE (0x7 << HISI_CFG_AWR_CACHE_STRBIT)
/* ar cache 4'b1011 read not allocate sc */
#define HISI_CFG_AR_CACHE (0xB << HISI_CFG_AWR_CACHE_STRBIT)

#define HISI_CFG_SCE_MAX_LIST_LEN 511

#define HISI_INTR_TIMEOUT_MAX 5

#define KM_VERIFY_GID_REF_DERIVE_OUT { \
	0x7b, 0x21, 0x86, 0xc1, 0x4f, 0xf3, 0xe3, 0x9e, \
	0x0e, 0x00, 0xe0, 0x4f, 0x85, 0xd7, 0x8b, 0x4a }

typedef union {
	unsigned int value;
	struct {
		unsigned int sce_ram_addr : 11; /* bit[0-9] */
		unsigned int sce_ram_wren : 1;  /* bit[10] */
		unsigned int reserved : 20;     /* bit[11-31]:  */
	} reg;
} hisi_sce_ram_addr_union;
#endif /* __HICRYPTO_CHIP_H__ */