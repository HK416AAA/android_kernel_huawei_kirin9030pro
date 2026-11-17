/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: hardware crypto engine km reg define
 * Create: 2024/09/26
 */
#ifndef __HICRYPTO_REG_KM_DEF_H__
#define __HICRYPTO_REG_KM_DEF_H__
// --------------------------------------
// BLOCK: KM
// --------------------------------------
#define HISI_KM_OFF_REG_LOCK (0x001CUL)
#define HISI_KM_OFF_KM_MODE (0x0004UL)
#define HISI_KM_OFF_ALARM_MASK (0x020CUL)
#define HISI_KM_OFF_AES_KEY (0x0020UL)
#define HISI_KM_OFF_DES_KEY (0x0040UL)
#define HISI_KM_OFF_SM4_KEY (0x0060UL)
#define HISI_KM_OFF_AES_KEY_PARITY (0x0220UL)
#define HISI_KM_OFF_DES_KEY_PARITY (0x0224UL)
#define HISI_KM_OFF_SM4_KEY_PARITY (0x0228UL)
#define HISI_KM_OFF_AESKEY_MASK (0x0214UL)
#define HISI_KM_OFF_DESKEY_MASK (0x0218UL)
#define HISI_KM_OFF_SM4KEY_MASK (0x021CUL)
#define HISI_KM_OFF_WRAPPING_KEY_DIN (0x06C0UL)
#define HISI_KM_OFF_KEY_REG_LOCK (0x0210UL)
#define HISI_KM_OFF_KEY_SEL (0x0018UL)

#define HISI_KM_OFF_KEY_DECRY_DONE                 (0x000CUL)
#define HISI_KM_OFF_KEY_DERIVE_DONE                (0x0010UL)
#define HISI_KM_OFF_KEY_DERIVE_DONE_CLR            (0x0014UL)
#define HISI_KM_OFF_KM_STR                         (0x0000UL)
#define HISI_KM_OFF_KEY_MASK                       (0x024CUL)
#define HISI_KM_OFF_DERIVE_KEY_STR                 (0x0120UL)
#define HISI_KM_OFF_DERIVE_KEY_PARITY              (0x0238UL)
#define HISI_KM_OFF_WRAP_MODE                      (0x04D4UL)
#define HISI_KM_OFF_WRAP_DIN_SEL                   (0x04ECUL)
#define HISI_KM_OFF_KEY_BUFFER_WADDR               (0x0674UL)
#define HISI_KM_OFF_WRAP_DIN_LEN                   (0x04DCUL)
#define HISI_KM_OFF_KEY_RAM_DRV_DATA_SEL           (0x06A8UL)
#define HISI_KM_OFF_KEY_DRV_DATA_SEL               (0x06A4UL)
#define HISI_KM_OFF_RT_KEY_CHANGE_LOCK             (0x0464UL)
#define HISI_KM_OFF_KEY_INV_FLAG                   (0x0140UL)
#define HISI_KM_OFF_DRV_KEY_RAM_ADDR               (0x0670UL)
#define HISI_KM_OFF_WRAP_DONE                      (0x04E0)
#define HISI_KM_OFF_KEY_DECRY_DONE                 (0x000CUL)
#define HISI_KM_OFF_WRAP_DONE_CLR                  (0x04E4UL)
#define HISI_KM_OFF_KEY_DERIVE_DONE_CLR            (0x0014UL)
#define HISI_KM_OFF_DERIVE_KEY_CLR                 (0x0008UL)
#define HISI_KM_OFF_BUFFER_KEY_CLR                 (0x0410UL)
#define HISI_KM_OFF_WRAPPING_KEY_PARITY            (0x06E4UL)
#define HISI_KM_OFF_WRAPPING_KEY_MASK              (0x06E0UL)
#define HISI_KM_OFF_KEY_DRV_DATA_MASK              (0x06A0UL)
#define HISI_KM_OFF_KEY_DRV_DATA_ADDR              (0x0680UL)
#define HISI_KM_OFF_WRAP_DATA_MASK                 (0x04E8UL)
#define HISI_KM_OFF_WRAP_DATA_IN_ADDR              (0x0500UL)
#define HISI_KM_OFF_WRAP_DATA_IN_PARITY            (0x0590UL)
#define HISI_KM_OFF_WRAP_DATA_OUT_ADDR             (0x0540UL)
#define HISI_KM_OFF_WRAP_DATA_OUT_PARITY           (0x0594UL)

#define HISI_KM_VALUE_UNLOCK (0xAL)
#define HISI_KM_VALUE_LOCK (0x5L)
#define HISI_KM_VALUE_MODE_CRYPTO (0x0L)

#define HISI_KM_REG_ALM_REGION 0xAAAA
#define HISI_KM_REG_ALM_EXPECT 0xAAAA


enum hisi_km_reg_rootkey_sel {
	HISI_KM_REG_ROOTKEY_KDR = 0,
	HISI_KM_REG_ROOTKEY_GID = 1,
	HISI_KM_REG_ROOTKEY_POS = 2,
	HISI_KM_REG_ROOTKEY_RESERVE1 = 3,
	HISI_KM_REG_ROOTKEY_RESERVE2 = 4,
	HISI_KM_REG_ROOTKEY_RESERVE3 = 5,
};

enum hisi_km_reg_keytype_sel {
	HISI_KM_REG_KEYTYPE_CPU = 0,
	HISI_KM_REG_KEYTYPE_RTL0 = 1,
	HISI_KM_REG_KEYTYPE_RTL1 = 2,
	HISI_KM_REG_KEYTYPE_ROOTKEY = 3,
	HISI_KM_REG_KEYTYPE_DERIVEKEY = 4,
	HISI_KM_REG_KEYTYPE_AO_WRAPKEY = 5,
	HISI_KM_REG_KEYTYPE_CPU_WRAPKEY = 6,
	HISI_KM_REG_KEYTYPE_CEK = 7,
	HISI_KM_REG_KEYTYPE_KEYBUFF = 8,
	HISI_KM_REG_KEYTYPE_IMGKEY = 9,
};
enum hisi_km_reg_kmmode {
	HISI_KM_REG_KMMODE_CRYPTO = 0x00,
	HISI_KM_REG_KMMODE_DERIVE = 0x11,
	HISI_KM_REG_KMMODE_RTLDEC = 0x22,
	HISI_KM_REG_KMMODE_RK_UPDATE = 0x33,
	HISI_KM_REG_KMMODE_RTLENC = 0x44,
	HISI_KM_REG_KMMODE_RTL1ENC = 0x55,
	HISI_KM_REG_KMMODE_SCEKEY_DEC = 0x66,
	HISI_KM_REG_KMMODE_PKEKEY_DEC = 0x77,
	HISI_KM_REG_KMMODE_IMGDECKEY_CREATE = 0x88,
	HISI_KM_REG_KMMODE_IMGKEYDEC = 0x99,
	HISI_KM_REG_KMMODE_KEYWRAP = 0xAA,
	HISI_KM_REG_KMMODE_KEYEXPORT = 0xBB,
};

enum hisi_km_reg_derive_pos {
	HISI_DERIVE_DATA_UNREAD_STR = 0x0,
	HISI_DERIVE_DATA_UNREAD_END = 0xB,
	HISI_DERIVE_DATA_READABLE_STR = 0xC,
	HISI_DERIVE_DATA_READABLE_END = 0xF,
};

enum hisi_km_reg_key_buff {
	HISI_KEY_BUFF_DATA_STR = 0x0,
	HISI_KEY_BUFF_DATA_END = 0xF,
};

enum hisi_km_reg_key_drv_data_sel {
	HISI_KEY_DRV_CPU_CFG_DATA       = 0,
	HISI_KEY_DRV_DERIVE_DATA        = 1,
};

struct hisi_km_reg_keytype {
	unsigned int km_reg_ktype;
	unsigned int km_reg_sub_ktype;
};

enum hisi_km_reg_ao_wrapkey_sel {
	HISI_KM_REG_AO_WRAPKEY_TEE      = 0,
	HISI_KM_REG_AO_WRAPKEY_REE      = 1,
};

enum hisi_km_reg_wrapmode {
	HISI_KM_REG_WRAPMODE_WRAP   = 0x5,
	HISI_KM_REG_WRAPMODE_UNWRAP = 0xA,
};

enum hisi_km_reg_wrapdin_sel {
	HISI_KM_REG_WRAPDIN_SEL_CPU  = 0xA,
	HISI_KM_REG_WRAPDIN_SEL_HARD = 0x5,
};

enum hisi_km_reg_clr_key {
	HISI_KM_CLR_DERIVE_KEY        = 0,
	HISI_KM_CLR_BUFFER_KEY        = 1,
	HISI_KM_CLR_IMGDEC_KEY        = 2,
};

typedef union {
	unsigned int value;
	struct {
		unsigned int km_derive_mode : 8;
		unsigned int km_mode : 8;
		unsigned int ddrenc_key_derive : 4;
		unsigned int drv_key_inv : 4;
		unsigned int reserved : 8;
	} reg;
} hisi_km_mode_union;

typedef union {
	unsigned int value;
	struct {
		unsigned int sce_key_sel : 4;
		unsigned int km_rootkey_sel : 4;
		unsigned int km_derive_key_sel : 4;
		unsigned int km_key_buff_sel : 4;
		unsigned int wrap_key_sel : 1;
		unsigned int key_din_sel : 5;
		unsigned int reserved : 10;
	} reg;
} hisi_km_sel_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  prt_lock : 4; /* bit[0-3]  */
        unsigned int  reserved : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_reg_lock_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  prt_key_lock : 4;  /* bit[0-3] */
        unsigned int  reserved     : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_key_lock_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  key_derive_done : 4;  /* bit[0-3]  */
        unsigned int  reserved        : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_key_derive_done_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  key_decry_done : 4;  /* bit[0-3] : */
        unsigned int  reserved       : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_key_decry_done_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  key_derive_done_clr : 4;  /* bit[0-3]  */
        unsigned int  reserved            : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_key_dervice_done_clr_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  km_str   : 4;  /* bit[0-3] : */
        unsigned int  reserved : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_str_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  alarm_critical_mask   : 4;  /* bit[0-3]  : */
        unsigned int  alarm_reg_check_mask  : 4;  /* bit[4-7]  : */
        unsigned int  alarm_reg_access_mask : 4;  /* bit[8-11] :  */
        unsigned int  alarm_key_check_mask  : 4;  /* bit[12-15]:  */
        unsigned int  reserved              : 16; /* bit[16-31]:  */
    } reg;
} hisi_km_alarm_mask_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  sce_key_sel       : 4;  /* bit[0-3]  */
        unsigned int  km_rootkey_sel    : 4;  /* bit[4-7]  */
        unsigned int  km_derive_key_sel : 4;  /* bit[8-11]  */
        unsigned int  km_key_buff_sel   : 4;  /* bit[12-15] */
        unsigned int  wrap_key_sel      : 1;  /* bit[16]  */
        unsigned int  key_din_sel       : 5;  /* bit[17-21]: */
        unsigned int  reserved          : 10; /* bit[22-31]:  */
    } reg;
} hisi_km_key_sel_union;


typedef union {
    unsigned int      value;
    struct {
        unsigned int  wrap_mode : 4;  /* bit[0-3] : */
        unsigned int  reserved  : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_wrap_mode_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  wrap_din_sel : 4;  /* bit[0-3] :  */
        unsigned int  reserved     : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_wrap_din_sel_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  key_buffer_waddr : 4;  /* bit[0-3] :  */
        unsigned int  reserved         : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_key_buffer_waddr_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  wrap_din_len : 3;  /* bit[0-2] :  */
        unsigned int  reserved     : 29; /* bit[3-31]:  */
    } reg;
} hisi_km_wrap_din_len_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  drv_key_buff_data_sel : 4;  /* bit[0-3] : */
        unsigned int  reserved              : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_key_ram_drv_data_sel_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  key_drv_data_sel : 2;  /* bit[0-1] :  */
        unsigned int  reserved         : 30; /* bit[2-31]:  */
    } reg;
} hisi_km_key_drv_data_sel_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  km_rootkey_lock : 4;  /* bit[0-3] : */
        unsigned int  reserved        : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_rt_key_change_lock_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  key_inv_flag : 4;  /* bit[0-3] :  */
        unsigned int  reserved     : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_key_inv_flag_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  drv_kram_ram_waddr : 4;  /* bit[0-3] :  */
        unsigned int  drv_kram_ram_raddr : 4;  /* bit[4-7] :  */
        unsigned int  reserved           : 24; /* bit[8-31]:  */
    } reg;
} hisi_km_drv_key_ram_addr_union;


typedef union {
    unsigned int      value;
    struct {
        unsigned int  wrap_done : 4;  /* bit[0-3] :  */
        unsigned int  reserved  : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_wrap_done_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  wrap_done_clr : 4;  /* bit[0-3] :  */
        unsigned int  reserved      : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_wrap_done_clr_union;


typedef union {
    unsigned int      value;
    struct {
        unsigned int  key_derive_done_clr : 4;  /* bit[0-3] :  */
        unsigned int  reserved            : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_key_derive_done_clr_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  derive_key_clr : 4;  /* bit[0-3] :  */
        unsigned int  reserved       : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_derive_key_clr_union;

typedef union {
    unsigned int      value;
    struct {
        unsigned int  buffer_key_clr : 4;  /* bit[0-3] : */
        unsigned int  reserved       : 28; /* bit[4-31]:  */
    } reg;
} hisi_km_buffer_key_clr_union;

#endif