/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: hardware crypto engine reg define
 * Create: 2023/03/07
 */
#ifndef __HICRYPTO_REGS_H__
#define __HICRYPTO_REGS_H__
#include "hicrypto_chip.h"
#include "hicrypto_regs_km.h"

#define HISI_REG_SLEEP_US 1

#define HISI_REG_CFG_BASE_OFF 0x000
#define HISI_REG_KM_BASE_OFF 0x1000
#define HISI_REG_SCE_BASE_OFF 0x2000

/* smc id */
#define OEM_BASE                 0xc3U
#define FID_CRYPTO_ENGINE_GROUP  0x31
#define make_fid(group, id)      ((((OEM_BASE << 16) + (group)) << 8) + (id))
#define FID_BL31_CRYPTO_ENGINE_REE_CLK_CTRL make_fid(FID_CRYPTO_ENGINE_GROUP, 0x03)

#define HISI_SCE_LIST_NODE_MAX (1U << HISI_SCE_SRAM_LIST_HADDR_STRBIT)
#define HISI_SCE_SRAM_LIST_LEN ((1U << HISI_SCE_SRAM_LIST_HADDR_STRBIT) - 1)
#define HISI_SCE_SCE_IVOUT_WORDNUM 4
#define HISI_SCE_SCE_IVIN_WORDNUM 4
#define HISI_SCE_SCE_MACIVIN_WORDNUM 16
#define HISI_SCE_MACIVOUT_WORDNUM 16
#define HISI_SCE_GCM_COUNTER0_REGNUM 4
#define HISI_SCE_TAG_IN_REGNUM 4
#define HISI_SCE_REG_TAG_LEN 16
#define HISI_SCE_REG_DOUT_NUM 8
#define HISI_SCE_DESKEY_REGNUM 6
#define HISI_SCE_LIST_MAX_NUM 128
// --------------------------------------
// BLOCK: CONFIG
// --------------------------------------
#define HISI_CFG_OFF_PEREN0 (0x100UL)
#define HISI_CFG_OFF_PERDIS0 (0x104UL)

#define HISI_CFG_VALUE_EN_SCE (0x2UL)
#define HISI_CFG_VALUE_DIS_SCE (0x2UL)

#define HISI_CFG_OFF_AW_SIDEBAND1 (0x400UL)
#define HISI_CFG_OFF_AR_SIDEBAND1 (0x404UL)

// --------------------------------------
// BLOCK: SCE
// --------------------------------------
#define HISI_SCE_OFF_REG_LOCK (0x0034UL)
#define HISI_SCE_OFF_SCE_STATE (0x000CUL)
#define HISI_SCE_OFF_SCE_MODE (0x0000UL)
#define HISI_SCE_OFF_SCE_CFG (0x0008UL)
#define HISI_SCE_OFF_PADDING_EN (0x01CCUL)
#define HISI_SCE_OFF_DATA_LENTH (0x0200UL)
#define HISI_SCE_OFF_SCE_IVIN2 (0x0080UL)
#define HISI_SCE_OFF_SCE_IVOUT2 (0x0100UL)
#define HISI_SCE_OFF_RX_DAT_LEN (0x0004UL)
#define HISI_SCE_OFF_TX_DAT_LEN (0x0030UL)
#define HISI_SCE_OFF_IV_BYPASS (0x02CCUL)
#define HISI_SCE_OFF_SRC_ADDR (0x02C0UL)
#define HISI_SCE_OFF_DES_ADDR (0x02C4UL)
#define HISI_SCE_OFF_CACHE_CTRL_ADDR (0x0300UL)
#define HISI_SCE_OFF_RAM_ADDR (0x0330UL)
#define HISI_SCE_OFF_RAM_DATA (0x0334UL)
#define HISI_SCE_OFF_RAM_READY (0x0338UL)
#define HISI_SCE_OFF_STR_RUN (0x0014UL)
#define HISI_SCE_OFF_ALARM_MASK (0x0024UL)
#define HISI_SCE_OFF_ALARM_MASK_EN (0x001CUL)
#define HISI_SCE_OFF_INT_SCE_CLR (0x02DCUL)
#define HISI_SCE_OFF_SCE_IVIN1 (0x01E0UL)
#define HISI_SCE_OFF_SCE_IVOUT1 (0x01F0UL)
#define HISI_SCE_OFF_SCE_DES (0x02C4UL)
#define HISI_SCE_OFF_INT_MASK_EN (0x02D0UL)
#define HISI_SCE_OFF_INT_MSK (0x02D4UL)
#define HISI_SCE_OFF_INT_SCE (0x02D8UL)
#define HISI_SCE_OFF_SCE_DOUT (0x00C0UL)
#define HISI_SCE_OFF_GCM_AAD_LEN (0x01D8UL)
#define HISI_SCE_OFF_SCE_DATA_LEN_ALL (0x0200UL)
#define HISI_SCE_OFF_GCM_COUNTER0 (0x0090UL)
#define HISI_SCE_OFF_SCE_TAG_IN (0x00A0UL)
#define HISI_SCE_OFF_AES_TAG_OUT (0x0230UL)
#define HISI_SCE_OFF_RAM_CLEAR (0x033CUL)

#define HISI_SCE_OFF_FIFO_LINE (0x0010UL)
#define HISI_SCE_OFF_RX_RES_BURST (0x240UL)
#define HISI_SCE_OFF_RX_RES_WORD (0x244UL)
#define HISI_SCE_OFF_RX_REQ_BURST (0x248UL)
#define HISI_SCE_OFF_RX_ROAD_WORD (0x24CUL)
#define HISI_SCE_OFF_TX_REQ_BURST (0x250UL)
#define HISI_SCE_OFF_TX_RES_BURST (0x254UL)
#define HISI_SCE_OFF_TX_REMAIN_BURST (0x258UL)
#define HISI_SCE_OFF_TX_REMAIN_WORD (0x25CUL)

#define HISI_SCE_OFF_FIFO_RX_WDATA0 (0x260UL)
#define HISI_SCE_OFF_FIFO_RX_WDATA1 (0x264UL)
#define HISI_SCE_OFF_FIFO_RX_WDATA2 (0x268UL)
#define HISI_SCE_OFF_FIFO_RX_WDATA3 (0x26cUL)

#define HISI_SCE_OFF_FIFO_RX_RDATA0 (0x270UL)
#define HISI_SCE_OFF_FIFO_RX_RDATA1 (0x274UL)
#define HISI_SCE_OFF_FIFO_RX_RDATA2 (0x278UL)
#define HISI_SCE_OFF_FIFO_RX_RDATA3 (0x27cUL)

#define HISI_SCE_OFF_FIFO_TX_WDATA0 (0x280UL)
#define HISI_SCE_OFF_FIFO_TX_WDATA1 (0x284UL)
#define HISI_SCE_OFF_FIFO_TX_WDATA2 (0x288UL)
#define HISI_SCE_OFF_FIFO_TX_WDATA3 (0x28cUL)

#define HISI_SCE_OFF_FIFO_TX_RDATA0 (0x290UL)
#define HISI_SCE_OFF_FIFO_TX_RDATA1 (0x294UL)
#define HISI_SCE_OFF_FIFO_TX_RDATA2 (0x298UL)
#define HISI_SCE_OFF_FIFO_TX_RDATA3 (0x29cUL)

#define HISI_SCE_OFF_DIN_STR        (0x0040UL)

#define HISI_SCE_VALUE_MSK (0x5L)
#define HISI_SCE_VALUE_UNMSK (0xAL)
#define HISI_SCE_VALUE_UNLOCK (0xAL)
#define HISI_SCE_VALUE_LOCK (0x5L)
#define HISI_SCE_VALUE_BUSY (HISI_SCE_REG_STATE_BUSY)
#define HISI_SCE_VALUE_IDLE (HISI_SCE_REG_STATE_BUSY ^ HISI_SCE_REG_STATE_BUSY)
#define HISI_SCE_VALUE_DONE (HISI_SCE_REG_STATE_DONE)
#define HISI_SCE_VALUE_INT_VALID (0x5)
#define HISI_SCE_VALUE_ALM_UNMSK (0xAAAAAAAA)

#define HISI_SCE_REG_STATE_BUSY (1U << (4))
#define HISI_SCE_REG_STATE_DONE (1U << (8))
#define HISI_SCE_REG_ALARM_REGION 0x1FFFF
#define HISI_SCE_REG_SRAM_TX_OFFSET 256
#define HISI_SCE_REG_SRAM_STEP 2
#define HISI_SCE_REG_SRAM_LEN 1024
#define HISI_SCE_REG_INT_SCE_MASK 0xF

typedef union {
	unsigned int value;
	struct {
		unsigned int gcm_tag_compare_flag : 1;
		unsigned int reserved_0 : 3;
		unsigned int sce_busy_reg : 1;
		unsigned int reserved_1 : 3;
		unsigned int sce_done_reg : 1;
		unsigned int sce_hmac_done_reg : 1;
		unsigned int reserved_2 : 2;
		unsigned int ctrl_rx_busy : 1;
		unsigned int reserved_3 : 3;
		unsigned int ctrl_tx_busy : 1;
		unsigned int reserved_4 : 15;
	} reg;
} hisi_sce_state_union;

typedef union {
	unsigned int value;
	struct {
		unsigned int sce_rx_dma_mode : 3;
		unsigned int reserved_0 : 1;
		unsigned int sce_ip_sel : 4;
		unsigned int sce_tx_dma_mode : 3;
		unsigned int reserved_1 : 21;
	} reg;
} hisi_sce_mode_union;

typedef union {
	unsigned int value;
	struct {
		unsigned int xts_init_en : 1;
		unsigned int reserved_0 : 1;
		unsigned int reserved_1 : 2;
		unsigned int sce_decrypt : 1;
		unsigned int reserved_2 : 3;
		unsigned int sce_mode : 4;
		unsigned int sce_key_length : 2;
		unsigned int reserved_3 : 2;
		unsigned int reserved_4 : 1;
		unsigned int reserved_5 : 3;
		unsigned int reserved_6 : 1;
		unsigned int reserved_7 : 3;
		unsigned int tdes : 1;
		unsigned int reserved_8 : 3;
		unsigned int tx_big_little_end : 1;
		unsigned int rx_big_little_end : 1;
		unsigned int sce_padding_sel : 1;
		unsigned int reserved_9 : 1;
	} reg;
} hisi_sce_cfg_union;

typedef union {
	unsigned int value;
	struct {
		unsigned int iv_sel : 4;
		unsigned int sce_src_addr_high : 12;
		unsigned int sce_des_addr_high : 12;
		unsigned int reserved : 4;
	} reg;
} hisi_sce_iv_bypass_union;

typedef union {
	unsigned int value;
	struct {
		unsigned int sce_run : 1;
		unsigned int reserved_0 : 3;
		unsigned int sce_str : 1;
		unsigned int reserved_1 : 3;
		unsigned int reserved_2 : 24;
	} reg;
} hisi_sce_str_run_union;

typedef union {
	unsigned int value;
	struct {
		unsigned int sce_master_int_clr : 4;
		unsigned int dscrp_finish_int_clr : 4;
		unsigned int dscrp_aempty_int_clr : 4;
		unsigned int dscrp_overflow_int_clr : 4;
		unsigned int reserved : 16;
	} reg;
} hisi_sce_int_clr_union;

typedef union {
	unsigned int value;
	struct {
		unsigned int sce_master_int_mask_en : 4;
		unsigned int dscrp_finish_int_mask_en : 4;
		unsigned int dscrp_aempty_int_mask_en : 4;
		unsigned int dscrp_overflow_int_mask_en : 4;
		unsigned int reserved : 16;
	} reg;
} hisi_sce_int_mask_en_union;

typedef union {
	unsigned int value;
	struct {
		unsigned int sce_ram_clear : 1;
		unsigned int reserved : 31;
	} reg;
} hisi_sce_ram_clear_union;

enum hisi_sce_reg_algorithm {
	HISI_SCE_REG_ALGORITHM_AES = 0,
	HISI_SCE_REG_ALGORITHM_SM4 = 1,
	HISI_SCE_REG_ALGORITHM_DES = 2,
	HISI_SCE_REG_ALGORITHM_PLAINTCPY = 3,
	HISI_SCE_REG_ALGORITHM_SHA1 = 4,
	HISI_SCE_REG_ALGORITHM_MD5 = 5,
	HISI_SCE_REG_ALGORITHM_SHA256 = 6,
	HISI_SCE_REG_ALGORITHM_SM3 = 7,
	HISI_SCE_REG_ALGORITHM_QUICK_AES = 0xa,
	HISI_SCE_REG_ALGORITHM_SHA512 = 0xc,
	HISI_SCE_REG_ALGORITHM_UNKNOWN,
};
enum hisi_sce_reg_mode {
	HISI_SCE_REG_MODE_ECB = 1,
	HISI_SCE_REG_MODE_CBC = 2,
	HISI_SCE_REG_MODE_CBCMAC = 3,
	HISI_SCE_REG_MODE_CMAC = 4,
	HISI_SCE_REG_MODE_CTR = 5,
	HISI_SCE_REG_MODE_OFB = 6,
	HISI_SCE_REG_MODE_GHASH = 7,
	HISI_SCE_REG_MODE_GCM_IV_INIT = 8,
	HISI_SCE_REG_MODE_GCM_GMAC = 9,
	HISI_SCE_REG_MODE_GCM_PAYLOAD_PROC = 10,
	HISI_SCE_REG_MODE_CCM_PAYLOAD_PROC = 11,
	HISI_SCE_REG_MODE_XTS = 12,
	HISI_SCE_REG_MODE_XCBCMAC = 13,

	HISI_SCE_REG_MODE_UNKNOWN,
};

enum hisi_sce_reg_dir {
	HISI_SCE_REG_DIRECTION_DECRYPT = 0x0,
	HISI_SCE_REG_DIRECTION_ENCRYPT = 0x1,
};

enum hisi_sce_reg_width {
	HISI_SCE_REG_KEY_WIDTH_128 = 0,
	HISI_SCE_REG_KEY_WIDTH_192 = 1,
	HISI_SCE_REG_KEY_WIDTH_256 = 2,

	HISI_SCE_REG_KEY_WIDTH_UNKNOWN,
};

enum hisi_sce_reg_pad_en {
	HISI_SCE_REG_PADDING_DISABLE = 0,
	HISI_SCE_REG_PADDING_ENABLE = 1,
};

enum hisi_sce_reg_padmode {
	HISI_SCE_REG_PADMODE_80 = 0x0,
	HISI_SCE_REG_PADMODE_00 = 0x1,
};

// --------------------------------------
// BLOCK: others
// --------------------------------------
#define HISI_CYCLES_PER_BLOCK_MAX 320
#define HISI_REDUNDANCE_COEF 15
#define HISI_TIMEOUT_BASE 100000
#define HISI_TIMEOUT_MAX 100000000
#define HISI_SCE_IDLE_ENTRY_TIMEOUT 10000
#define HISI_SCE_IDLE_CPU_START_TIMEOUT 10000
#define HISI_SYMM_RUN_RANDOM_DELAY_CYCLES_MAX 20
#define HISI_KM_CFG_KEY_RANDOM_DELAY_CYCLES_MAX 8

#endif /* __HICRYPTO_REGS_H__ */
