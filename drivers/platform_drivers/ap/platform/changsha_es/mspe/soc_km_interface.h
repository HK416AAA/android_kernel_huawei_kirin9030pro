#ifndef __SOC_KM_INTERFACE_H__
#define __SOC_KM_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_KM_STR_ADDR(base) (base)
#define SOC_KM_MODE_ADDR(base) ((base) + 0x0004UL)
#define SOC_KM_DERIVE_KEY_CLR_ADDR(base) ((base) + 0x0008UL)
#define SOC_KM_KEY_DECRY_DONE_ADDR(base) ((base) + 0x000CUL)
#define SOC_KM_KEY_DERIVE_DONE_ADDR(base) ((base) + 0x0010UL)
#define SOC_KM_KEY_DERIVE_DONE_CLR_ADDR(base) ((base) + 0x0014UL)
#define SOC_KM_KEY_SEL_ADDR(base) ((base) + 0x0018UL)
#define SOC_KM_REG_LOCK_ADDR(base) ((base) + 0x001CUL)
#define SOC_KM_AES_KEY_ADDR(base,n) ((base) + 0x0020UL + (n) * 4)
#define SOC_KM_DES_KEY_ADDR(base,m) ((base) + 0x0040UL + (m) * 4)
#define SOC_KM_SM4_KEY_ADDR(base,k) ((base) + 0x0060UL + (k) * 4)
#define SOC_KM_RK_IN_ADDR(base,n) ((base) + 0x0080UL + (n) * 4)
#define SOC_KM_RK_OUT_ADDR(base,n) ((base) + 0x00A0UL + (n) * 4)
#define SOC_KM_CEK_IN_ADDR(base,k) ((base) + 0x00C0UL + (k) * 4)
#define SOC_KM_DERIVE_KEY_ADDR(base,k) ((base) + 0x0120UL + (k) * 4)
#define SOC_KM_KEY_INV_FLAG_ADDR(base) ((base) + 0x0140UL)
#define SOC_KM_RT_KEYWRITE_ONCE_ADDR(base) ((base) + 0x0144UL)
#define SOC_KM_ALARM_CLR_ADDR(base) ((base) + 0x0200UL)
#define SOC_KM_ALARM_MASK_EN_ADDR(base) ((base) + 0x0204UL)
#define SOC_KM_ALARM_ADDR(base) ((base) + 0x0208UL)
#define SOC_KM_ALARM_MASK_ADDR(base) ((base) + 0x020CUL)
#define SOC_KM_KEY_REG_LOCK_ADDR(base) ((base) + 0x0210UL)
#define SOC_KM_AESKEY_MASK_VALUE_ADDR(base) ((base) + 0x0214UL)
#define SOC_KM_DESKEY_MASK_VALUE_ADDR(base) ((base) + 0x0218UL)
#define SOC_KM_SM4KEY_MASK_VALUE_ADDR(base) ((base) + 0x021CUL)
#define SOC_KM_AES_KEY_PARITY_ADDR(base) ((base) + 0x0220UL)
#define SOC_KM_DES_KEY_PARITY_ADDR(base) ((base) + 0x0224UL)
#define SOC_KM_SM4_KEY_PARITY_ADDR(base) ((base) + 0x0228UL)
#define SOC_KM_RK_IN_PARITY_ADDR(base) ((base) + 0x022CUL)
#define SOC_KM_RK_OUT_PARITY_ADDR(base) ((base) + 0x0230UL)
#define SOC_KM_CEK_IN_PARITY_ADDR(base) ((base) + 0x0234UL)
#define SOC_KM_DERIVE_KEY_PARITY_ADDR(base) ((base) + 0x0238UL)
#define SOC_KM_CEK_MASK_VALUE_ADDR(base) ((base) + 0x0248UL)
#define SOC_KM_KEY_MASK_VALUE_ADDR(base) ((base) + 0x024CUL)
#define SOC_KM_DDRENC_KEY_ADDR(base,k) ((base) + 0x0260UL + (k) * 4)
#define SOC_KM_DEBUG_SD_ADDR(base) ((base) + 0x02A8UL)
#define SOC_KM_OEM_ID_ADDR(base,k) ((base) + 0x0300UL + (k) * 4)
#define SOC_KM_PRODUCT_ID_ADDR(base,k) ((base) + 0x0320UL + (k) * 4)
#define SOC_KM_ROTPK_ADDR(base,n) ((base) + 0x0340UL + (n) * 4)
#define SOC_KM_BUFFER_KEY_CLR_ADDR(base) ((base) + 0x0410UL)
#define SOC_KM_BUFFER_KEY_ADDR(base,k) ((base) + 0x0420UL + (k) * 4)
#define SOC_KM_BUFFER_KEY_PARITY_ADDR(base) ((base) + 0x0440UL)
#define SOC_KM_RK_MUXED_LOCK_ADDR(base) ((base) + 0x0460UL)
#define SOC_KM_RT_KEY_CHANGE_LOCK_ADDR(base) ((base) + 0x0464UL)
#define SOC_KM_WRAP_MODE_ADDR(base) ((base) + 0x04D4UL)
#define SOC_KM_WRAP_DIN_LEN_ADDR(base) ((base) + 0x04DCUL)
#define SOC_KM_WRAP_DONE_ADDR(base) ((base) + 0x04E0UL)
#define SOC_KM_WRAP_DONE_CLR_ADDR(base) ((base) + 0x04E4UL)
#define SOC_KM_WRAP_DATA_MASK_ADDR(base) ((base) + 0x04E8UL)
#define SOC_KM_WRAP_DIN_SEL_ADDR(base) ((base) + 0x04ECUL)
#define SOC_KM_WRAP_DATA_IN_ADDR(base,s) ((base) + 0x0500UL + (s) * 4)
#define SOC_KM_WRAP_DATA_OUT_ADDR(base,s) ((base) + 0x0540UL + (s) * 4)
#define SOC_KM_WRAP_DATA_IN_PARITY_ADDR(base) ((base) + 0x0590UL)
#define SOC_KM_WRAP_DATA_OUT_PARITY_ADDR(base) ((base) + 0x0594UL)
#define SOC_KM_MON_CNT_CONTROL_ADDR(base) ((base) + 0x0598UL)
#define SOC_KM_MON_CNT_ADDR(base) ((base) + 0x059CUL)
#define SOC_KM_MON_CNT_CFG_ADDR(base) ((base) + 0x05A0UL)
#define SOC_KM_HMAC_KEY1_ADDR(base,r) ((base) + 0x05C0UL + (r) * 4)
#define SOC_KM_HMAC_KEY2_ADDR(base,r) ((base) + 0x0600UL + (r) * 4)
#define SOC_KM_HMAC_KEY1_MASK_ADDR(base) ((base) + 0x0640UL)
#define SOC_KM_HMAC_KEY2_MASK_ADDR(base) ((base) + 0x0644UL)
#define SOC_KM_HMAC_KEY1_PARITY_ADDR(base) ((base) + 0x0648UL)
#define SOC_KM_HMAC_KEY2_PARITY_ADDR(base) ((base) + 0x064CUL)
#define SOC_KM_DFX0_ADDR(base) ((base) + 0x0650UL)
#define SOC_KM_DFX1_ADDR(base) ((base) + 0x0654UL)
#define SOC_KM_DFX2_ADDR(base) ((base) + 0x0658UL)
#define SOC_KM_DFX3_ADDR(base) ((base) + 0x065CUL)
#define SOC_KM_DRV_KEY_RAM_ADDR_ADDR(base) ((base) + 0x0670UL)
#define SOC_KM_KEY_BUFFER_WADDR_ADDR(base) ((base) + 0x0674UL)
#define SOC_KM_KEY_DRV_DATA_ADDR(base,k) ((base) + 0x0680UL + (k) * 4)
#define SOC_KM_KEY_DRV_DATA_MASK_ADDR(base) ((base) + 0x06A0UL)
#define SOC_KM_KEY_DRV_DATA_SEL_ADDR(base) ((base) + 0x06A4UL)
#define SOC_KM_KEY_RAM_DRV_DATA_SEL_ADDR(base) ((base) + 0x06A8UL)
#define SOC_KM_PKE_KEY_CLR_ADDR(base) ((base) + 0x06ACUL)
#define SOC_KM_WRAPPING_KEY_DIN_ADDR(base,n) ((base) + 0x06C0UL + (n) * 4)
#define SOC_KM_WRAPPING_KEY_MASK_ADDR(base) ((base) + 0x06E0UL)
#define SOC_KM_WRAPPING_KEY_PARITY_ADDR(base) ((base) + 0x06E4UL)
#define SOC_KM_IMG_DECRYKEY_UPDATE_FLAG_ADDR(base) ((base) + 0x06E8UL)
#define SOC_KM_IMG_DECRYKEY_CLEAR_ADDR(base) ((base) + 0x06ECUL)
#define SOC_KM_HSM_ID_ADDR(base) ((base) + 0x06F0UL)
#define SOC_KM_WRAP_KEY_START_ADDR(base) ((base) + 0x06F4UL)
#define SOC_KM_HSM_DES_SEL_ADDR(base) ((base) + 0x06F8UL)
#else
#define SOC_KM_STR_ADDR(base) (base)
#define SOC_KM_MODE_ADDR(base) ((base) + 0x0004)
#define SOC_KM_DERIVE_KEY_CLR_ADDR(base) ((base) + 0x0008)
#define SOC_KM_KEY_DECRY_DONE_ADDR(base) ((base) + 0x000C)
#define SOC_KM_KEY_DERIVE_DONE_ADDR(base) ((base) + 0x0010)
#define SOC_KM_KEY_DERIVE_DONE_CLR_ADDR(base) ((base) + 0x0014)
#define SOC_KM_KEY_SEL_ADDR(base) ((base) + 0x0018)
#define SOC_KM_REG_LOCK_ADDR(base) ((base) + 0x001C)
#define SOC_KM_AES_KEY_ADDR(base,n) ((base) + 0x0020 + (n) * 4)
#define SOC_KM_DES_KEY_ADDR(base,m) ((base) + 0x0040 + (m) * 4)
#define SOC_KM_SM4_KEY_ADDR(base,k) ((base) + 0x0060 + (k) * 4)
#define SOC_KM_RK_IN_ADDR(base,n) ((base) + 0x0080 + (n) * 4)
#define SOC_KM_RK_OUT_ADDR(base,n) ((base) + 0x00A0 + (n) * 4)
#define SOC_KM_CEK_IN_ADDR(base,k) ((base) + 0x00C0 + (k) * 4)
#define SOC_KM_DERIVE_KEY_ADDR(base,k) ((base) + 0x0120 + (k) * 4)
#define SOC_KM_KEY_INV_FLAG_ADDR(base) ((base) + 0x0140)
#define SOC_KM_RT_KEYWRITE_ONCE_ADDR(base) ((base) + 0x0144)
#define SOC_KM_ALARM_CLR_ADDR(base) ((base) + 0x0200)
#define SOC_KM_ALARM_MASK_EN_ADDR(base) ((base) + 0x0204)
#define SOC_KM_ALARM_ADDR(base) ((base) + 0x0208)
#define SOC_KM_ALARM_MASK_ADDR(base) ((base) + 0x020C)
#define SOC_KM_KEY_REG_LOCK_ADDR(base) ((base) + 0x0210)
#define SOC_KM_AESKEY_MASK_VALUE_ADDR(base) ((base) + 0x0214)
#define SOC_KM_DESKEY_MASK_VALUE_ADDR(base) ((base) + 0x0218)
#define SOC_KM_SM4KEY_MASK_VALUE_ADDR(base) ((base) + 0x021C)
#define SOC_KM_AES_KEY_PARITY_ADDR(base) ((base) + 0x0220)
#define SOC_KM_DES_KEY_PARITY_ADDR(base) ((base) + 0x0224)
#define SOC_KM_SM4_KEY_PARITY_ADDR(base) ((base) + 0x0228)
#define SOC_KM_RK_IN_PARITY_ADDR(base) ((base) + 0x022C)
#define SOC_KM_RK_OUT_PARITY_ADDR(base) ((base) + 0x0230)
#define SOC_KM_CEK_IN_PARITY_ADDR(base) ((base) + 0x0234)
#define SOC_KM_DERIVE_KEY_PARITY_ADDR(base) ((base) + 0x0238)
#define SOC_KM_CEK_MASK_VALUE_ADDR(base) ((base) + 0x0248)
#define SOC_KM_KEY_MASK_VALUE_ADDR(base) ((base) + 0x024C)
#define SOC_KM_DDRENC_KEY_ADDR(base,k) ((base) + 0x0260 + (k) * 4)
#define SOC_KM_DEBUG_SD_ADDR(base) ((base) + 0x02A8)
#define SOC_KM_OEM_ID_ADDR(base,k) ((base) + 0x0300 + (k) * 4)
#define SOC_KM_PRODUCT_ID_ADDR(base,k) ((base) + 0x0320 + (k) * 4)
#define SOC_KM_ROTPK_ADDR(base,n) ((base) + 0x0340 + (n) * 4)
#define SOC_KM_BUFFER_KEY_CLR_ADDR(base) ((base) + 0x0410)
#define SOC_KM_BUFFER_KEY_ADDR(base,k) ((base) + 0x0420 + (k) * 4)
#define SOC_KM_BUFFER_KEY_PARITY_ADDR(base) ((base) + 0x0440)
#define SOC_KM_RK_MUXED_LOCK_ADDR(base) ((base) + 0x0460)
#define SOC_KM_RT_KEY_CHANGE_LOCK_ADDR(base) ((base) + 0x0464)
#define SOC_KM_WRAP_MODE_ADDR(base) ((base) + 0x04D4)
#define SOC_KM_WRAP_DIN_LEN_ADDR(base) ((base) + 0x04DC)
#define SOC_KM_WRAP_DONE_ADDR(base) ((base) + 0x04E0)
#define SOC_KM_WRAP_DONE_CLR_ADDR(base) ((base) + 0x04E4)
#define SOC_KM_WRAP_DATA_MASK_ADDR(base) ((base) + 0x04E8)
#define SOC_KM_WRAP_DIN_SEL_ADDR(base) ((base) + 0x04EC)
#define SOC_KM_WRAP_DATA_IN_ADDR(base,s) ((base) + 0x0500 + (s) * 4)
#define SOC_KM_WRAP_DATA_OUT_ADDR(base,s) ((base) + 0x0540 + (s) * 4)
#define SOC_KM_WRAP_DATA_IN_PARITY_ADDR(base) ((base) + 0x0590)
#define SOC_KM_WRAP_DATA_OUT_PARITY_ADDR(base) ((base) + 0x0594)
#define SOC_KM_MON_CNT_CONTROL_ADDR(base) ((base) + 0x0598)
#define SOC_KM_MON_CNT_ADDR(base) ((base) + 0x059C)
#define SOC_KM_MON_CNT_CFG_ADDR(base) ((base) + 0x05A0)
#define SOC_KM_HMAC_KEY1_ADDR(base,r) ((base) + 0x05C0 + (r) * 4)
#define SOC_KM_HMAC_KEY2_ADDR(base,r) ((base) + 0x0600 + (r) * 4)
#define SOC_KM_HMAC_KEY1_MASK_ADDR(base) ((base) + 0x0640)
#define SOC_KM_HMAC_KEY2_MASK_ADDR(base) ((base) + 0x0644)
#define SOC_KM_HMAC_KEY1_PARITY_ADDR(base) ((base) + 0x0648)
#define SOC_KM_HMAC_KEY2_PARITY_ADDR(base) ((base) + 0x064C)
#define SOC_KM_DFX0_ADDR(base) ((base) + 0x0650)
#define SOC_KM_DFX1_ADDR(base) ((base) + 0x0654)
#define SOC_KM_DFX2_ADDR(base) ((base) + 0x0658)
#define SOC_KM_DFX3_ADDR(base) ((base) + 0x065C)
#define SOC_KM_DRV_KEY_RAM_ADDR_ADDR(base) ((base) + 0x0670)
#define SOC_KM_KEY_BUFFER_WADDR_ADDR(base) ((base) + 0x0674)
#define SOC_KM_KEY_DRV_DATA_ADDR(base,k) ((base) + 0x0680 + (k) * 4)
#define SOC_KM_KEY_DRV_DATA_MASK_ADDR(base) ((base) + 0x06A0)
#define SOC_KM_KEY_DRV_DATA_SEL_ADDR(base) ((base) + 0x06A4)
#define SOC_KM_KEY_RAM_DRV_DATA_SEL_ADDR(base) ((base) + 0x06A8)
#define SOC_KM_PKE_KEY_CLR_ADDR(base) ((base) + 0x06AC)
#define SOC_KM_WRAPPING_KEY_DIN_ADDR(base,n) ((base) + 0x06C0 + (n) * 4)
#define SOC_KM_WRAPPING_KEY_MASK_ADDR(base) ((base) + 0x06E0)
#define SOC_KM_WRAPPING_KEY_PARITY_ADDR(base) ((base) + 0x06E4)
#define SOC_KM_IMG_DECRYKEY_UPDATE_FLAG_ADDR(base) ((base) + 0x06E8)
#define SOC_KM_IMG_DECRYKEY_CLEAR_ADDR(base) ((base) + 0x06EC)
#define SOC_KM_HSM_ID_ADDR(base) ((base) + 0x06F0)
#define SOC_KM_WRAP_KEY_START_ADDR(base) ((base) + 0x06F4)
#define SOC_KM_HSM_DES_SEL_ADDR(base) ((base) + 0x06F8)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int km_str : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_STR_UNION;
#endif
#define SOC_KM_STR_km_str_START (0)
#define SOC_KM_STR_km_str_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int km_derive_mode : 8;
        unsigned int km_mode : 8;
        unsigned int ddrenc_key_derive : 4;
        unsigned int drv_key_inv : 4;
        unsigned int reserved : 8;
    } reg;
} SOC_KM_MODE_UNION;
#endif
#define SOC_KM_MODE_km_derive_mode_START (0)
#define SOC_KM_MODE_km_derive_mode_END (7)
#define SOC_KM_MODE_km_mode_START (8)
#define SOC_KM_MODE_km_mode_END (15)
#define SOC_KM_MODE_ddrenc_key_derive_START (16)
#define SOC_KM_MODE_ddrenc_key_derive_END (19)
#define SOC_KM_MODE_drv_key_inv_START (20)
#define SOC_KM_MODE_drv_key_inv_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derive_key_clr : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_DERIVE_KEY_CLR_UNION;
#endif
#define SOC_KM_DERIVE_KEY_CLR_derive_key_clr_START (0)
#define SOC_KM_DERIVE_KEY_CLR_derive_key_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int key_decry_done : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_KEY_DECRY_DONE_UNION;
#endif
#define SOC_KM_KEY_DECRY_DONE_key_decry_done_START (0)
#define SOC_KM_KEY_DECRY_DONE_key_decry_done_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int key_derive_done : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_KEY_DERIVE_DONE_UNION;
#endif
#define SOC_KM_KEY_DERIVE_DONE_key_derive_done_START (0)
#define SOC_KM_KEY_DERIVE_DONE_key_derive_done_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int key_derive_done_clr : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_KEY_DERIVE_DONE_CLR_UNION;
#endif
#define SOC_KM_KEY_DERIVE_DONE_CLR_key_derive_done_clr_START (0)
#define SOC_KM_KEY_DERIVE_DONE_CLR_key_derive_done_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
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
} SOC_KM_KEY_SEL_UNION;
#endif
#define SOC_KM_KEY_SEL_sce_key_sel_START (0)
#define SOC_KM_KEY_SEL_sce_key_sel_END (3)
#define SOC_KM_KEY_SEL_km_rootkey_sel_START (4)
#define SOC_KM_KEY_SEL_km_rootkey_sel_END (7)
#define SOC_KM_KEY_SEL_km_derive_key_sel_START (8)
#define SOC_KM_KEY_SEL_km_derive_key_sel_END (11)
#define SOC_KM_KEY_SEL_km_key_buff_sel_START (12)
#define SOC_KM_KEY_SEL_km_key_buff_sel_END (15)
#define SOC_KM_KEY_SEL_wrap_key_sel_START (16)
#define SOC_KM_KEY_SEL_wrap_key_sel_END (16)
#define SOC_KM_KEY_SEL_key_din_sel_START (17)
#define SOC_KM_KEY_SEL_key_din_sel_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prt_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_REG_LOCK_UNION;
#endif
#define SOC_KM_REG_LOCK_prt_lock_START (0)
#define SOC_KM_REG_LOCK_prt_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aes_key : 32;
    } reg;
} SOC_KM_AES_KEY_UNION;
#endif
#define SOC_KM_AES_KEY_aes_key_START (0)
#define SOC_KM_AES_KEY_aes_key_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int des_key : 32;
    } reg;
} SOC_KM_DES_KEY_UNION;
#endif
#define SOC_KM_DES_KEY_des_key_START (0)
#define SOC_KM_DES_KEY_des_key_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sm4_key : 32;
    } reg;
} SOC_KM_SM4_KEY_UNION;
#endif
#define SOC_KM_SM4_KEY_sm4_key_START (0)
#define SOC_KM_SM4_KEY_sm4_key_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rk_in : 32;
    } reg;
} SOC_KM_RK_IN_UNION;
#endif
#define SOC_KM_RK_IN_rk_in_START (0)
#define SOC_KM_RK_IN_rk_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rk_out : 32;
    } reg;
} SOC_KM_RK_OUT_UNION;
#endif
#define SOC_KM_RK_OUT_rk_out_START (0)
#define SOC_KM_RK_OUT_rk_out_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cek_in : 32;
    } reg;
} SOC_KM_CEK_IN_UNION;
#endif
#define SOC_KM_CEK_IN_cek_in_START (0)
#define SOC_KM_CEK_IN_cek_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derive_key : 32;
    } reg;
} SOC_KM_DERIVE_KEY_UNION;
#endif
#define SOC_KM_DERIVE_KEY_derive_key_START (0)
#define SOC_KM_DERIVE_KEY_derive_key_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int key_inv_flag : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_KEY_INV_FLAG_UNION;
#endif
#define SOC_KM_KEY_INV_FLAG_key_inv_flag_START (0)
#define SOC_KM_KEY_INV_FLAG_key_inv_flag_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rootkey_write_once : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_KM_RT_KEYWRITE_ONCE_UNION;
#endif
#define SOC_KM_RT_KEYWRITE_ONCE_rootkey_write_once_START (0)
#define SOC_KM_RT_KEYWRITE_ONCE_rootkey_write_once_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alarm_critical_clr : 4;
        unsigned int alarm_reg_check_clr : 4;
        unsigned int alarm_reg_access_clr : 4;
        unsigned int alarm_key_check_clr : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_KM_ALARM_CLR_UNION;
#endif
#define SOC_KM_ALARM_CLR_alarm_critical_clr_START (0)
#define SOC_KM_ALARM_CLR_alarm_critical_clr_END (3)
#define SOC_KM_ALARM_CLR_alarm_reg_check_clr_START (4)
#define SOC_KM_ALARM_CLR_alarm_reg_check_clr_END (7)
#define SOC_KM_ALARM_CLR_alarm_reg_access_clr_START (8)
#define SOC_KM_ALARM_CLR_alarm_reg_access_clr_END (11)
#define SOC_KM_ALARM_CLR_alarm_key_check_clr_START (12)
#define SOC_KM_ALARM_CLR_alarm_key_check_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alarm_critical_mask_en : 4;
        unsigned int alarm_reg_check_mask_en : 4;
        unsigned int alarm_reg_access_mask_en : 4;
        unsigned int alarm_key_check_mask_en : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_KM_ALARM_MASK_EN_UNION;
#endif
#define SOC_KM_ALARM_MASK_EN_alarm_critical_mask_en_START (0)
#define SOC_KM_ALARM_MASK_EN_alarm_critical_mask_en_END (3)
#define SOC_KM_ALARM_MASK_EN_alarm_reg_check_mask_en_START (4)
#define SOC_KM_ALARM_MASK_EN_alarm_reg_check_mask_en_END (7)
#define SOC_KM_ALARM_MASK_EN_alarm_reg_access_mask_en_START (8)
#define SOC_KM_ALARM_MASK_EN_alarm_reg_access_mask_en_END (11)
#define SOC_KM_ALARM_MASK_EN_alarm_key_check_mask_en_START (12)
#define SOC_KM_ALARM_MASK_EN_alarm_key_check_mask_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alarm_critical : 4;
        unsigned int alarm_reg_check : 4;
        unsigned int alarm_reg_access : 4;
        unsigned int alarm_key_check : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_KM_ALARM_UNION;
#endif
#define SOC_KM_ALARM_alarm_critical_START (0)
#define SOC_KM_ALARM_alarm_critical_END (3)
#define SOC_KM_ALARM_alarm_reg_check_START (4)
#define SOC_KM_ALARM_alarm_reg_check_END (7)
#define SOC_KM_ALARM_alarm_reg_access_START (8)
#define SOC_KM_ALARM_alarm_reg_access_END (11)
#define SOC_KM_ALARM_alarm_key_check_START (12)
#define SOC_KM_ALARM_alarm_key_check_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int alarm_critical_mask : 4;
        unsigned int alarm_reg_check_mask : 4;
        unsigned int alarm_reg_access_mask : 4;
        unsigned int alarm_key_check_mask : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_KM_ALARM_MASK_UNION;
#endif
#define SOC_KM_ALARM_MASK_alarm_critical_mask_START (0)
#define SOC_KM_ALARM_MASK_alarm_critical_mask_END (3)
#define SOC_KM_ALARM_MASK_alarm_reg_check_mask_START (4)
#define SOC_KM_ALARM_MASK_alarm_reg_check_mask_END (7)
#define SOC_KM_ALARM_MASK_alarm_reg_access_mask_START (8)
#define SOC_KM_ALARM_MASK_alarm_reg_access_mask_END (11)
#define SOC_KM_ALARM_MASK_alarm_key_check_mask_START (12)
#define SOC_KM_ALARM_MASK_alarm_key_check_mask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prt_key_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_KEY_REG_LOCK_UNION;
#endif
#define SOC_KM_KEY_REG_LOCK_prt_key_lock_START (0)
#define SOC_KM_KEY_REG_LOCK_prt_key_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aeskey_mask_value : 32;
    } reg;
} SOC_KM_AESKEY_MASK_VALUE_UNION;
#endif
#define SOC_KM_AESKEY_MASK_VALUE_aeskey_mask_value_START (0)
#define SOC_KM_AESKEY_MASK_VALUE_aeskey_mask_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int deskey_mask_value : 32;
    } reg;
} SOC_KM_DESKEY_MASK_VALUE_UNION;
#endif
#define SOC_KM_DESKEY_MASK_VALUE_deskey_mask_value_START (0)
#define SOC_KM_DESKEY_MASK_VALUE_deskey_mask_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sm4key_mask_value : 32;
    } reg;
} SOC_KM_SM4KEY_MASK_VALUE_UNION;
#endif
#define SOC_KM_SM4KEY_MASK_VALUE_sm4key_mask_value_START (0)
#define SOC_KM_SM4KEY_MASK_VALUE_sm4key_mask_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aes_key_parity : 32;
    } reg;
} SOC_KM_AES_KEY_PARITY_UNION;
#endif
#define SOC_KM_AES_KEY_PARITY_aes_key_parity_START (0)
#define SOC_KM_AES_KEY_PARITY_aes_key_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int des_key_parity : 32;
    } reg;
} SOC_KM_DES_KEY_PARITY_UNION;
#endif
#define SOC_KM_DES_KEY_PARITY_des_key_parity_START (0)
#define SOC_KM_DES_KEY_PARITY_des_key_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sm4_key_parity : 32;
    } reg;
} SOC_KM_SM4_KEY_PARITY_UNION;
#endif
#define SOC_KM_SM4_KEY_PARITY_sm4_key_parity_START (0)
#define SOC_KM_SM4_KEY_PARITY_sm4_key_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rk_in_parity : 32;
    } reg;
} SOC_KM_RK_IN_PARITY_UNION;
#endif
#define SOC_KM_RK_IN_PARITY_rk_in_parity_START (0)
#define SOC_KM_RK_IN_PARITY_rk_in_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rk_out_parity : 32;
    } reg;
} SOC_KM_RK_OUT_PARITY_UNION;
#endif
#define SOC_KM_RK_OUT_PARITY_rk_out_parity_START (0)
#define SOC_KM_RK_OUT_PARITY_rk_out_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cek_in_parity : 32;
    } reg;
} SOC_KM_CEK_IN_PARITY_UNION;
#endif
#define SOC_KM_CEK_IN_PARITY_cek_in_parity_START (0)
#define SOC_KM_CEK_IN_PARITY_cek_in_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int derive_key_parity : 32;
    } reg;
} SOC_KM_DERIVE_KEY_PARITY_UNION;
#endif
#define SOC_KM_DERIVE_KEY_PARITY_derive_key_parity_START (0)
#define SOC_KM_DERIVE_KEY_PARITY_derive_key_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cek_mask_value : 32;
    } reg;
} SOC_KM_CEK_MASK_VALUE_UNION;
#endif
#define SOC_KM_CEK_MASK_VALUE_cek_mask_value_START (0)
#define SOC_KM_CEK_MASK_VALUE_cek_mask_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int key_mask_value : 32;
    } reg;
} SOC_KM_KEY_MASK_VALUE_UNION;
#endif
#define SOC_KM_KEY_MASK_VALUE_key_mask_value_START (0)
#define SOC_KM_KEY_MASK_VALUE_key_mask_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddrenc_key : 32;
    } reg;
} SOC_KM_DDRENC_KEY_UNION;
#endif
#define SOC_KM_DDRENC_KEY_ddrenc_key_START (0)
#define SOC_KM_DDRENC_KEY_ddrenc_key_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int debug_sd : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_DEBUG_SD_UNION;
#endif
#define SOC_KM_DEBUG_SD_debug_sd_START (0)
#define SOC_KM_DEBUG_SD_debug_sd_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int oem_id : 32;
    } reg;
} SOC_KM_OEM_ID_UNION;
#endif
#define SOC_KM_OEM_ID_oem_id_START (0)
#define SOC_KM_OEM_ID_oem_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int product_id : 32;
    } reg;
} SOC_KM_PRODUCT_ID_UNION;
#endif
#define SOC_KM_PRODUCT_ID_product_id_START (0)
#define SOC_KM_PRODUCT_ID_product_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rotpk : 32;
    } reg;
} SOC_KM_ROTPK_UNION;
#endif
#define SOC_KM_ROTPK_rotpk_START (0)
#define SOC_KM_ROTPK_rotpk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buffer_key_clr : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_BUFFER_KEY_CLR_UNION;
#endif
#define SOC_KM_BUFFER_KEY_CLR_buffer_key_clr_START (0)
#define SOC_KM_BUFFER_KEY_CLR_buffer_key_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buffer_key : 32;
    } reg;
} SOC_KM_BUFFER_KEY_UNION;
#endif
#define SOC_KM_BUFFER_KEY_buffer_key_START (0)
#define SOC_KM_BUFFER_KEY_buffer_key_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buffer_key_parity : 32;
    } reg;
} SOC_KM_BUFFER_KEY_PARITY_UNION;
#endif
#define SOC_KM_BUFFER_KEY_PARITY_buffer_key_parity_START (0)
#define SOC_KM_BUFFER_KEY_PARITY_buffer_key_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rk_muxed_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_RK_MUXED_LOCK_UNION;
#endif
#define SOC_KM_RK_MUXED_LOCK_rk_muxed_lock_START (0)
#define SOC_KM_RK_MUXED_LOCK_rk_muxed_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int km_rootkey_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_RT_KEY_CHANGE_LOCK_UNION;
#endif
#define SOC_KM_RT_KEY_CHANGE_LOCK_km_rootkey_lock_START (0)
#define SOC_KM_RT_KEY_CHANGE_LOCK_km_rootkey_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrap_mode : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_WRAP_MODE_UNION;
#endif
#define SOC_KM_WRAP_MODE_wrap_mode_START (0)
#define SOC_KM_WRAP_MODE_wrap_mode_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrap_din_len : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_KM_WRAP_DIN_LEN_UNION;
#endif
#define SOC_KM_WRAP_DIN_LEN_wrap_din_len_START (0)
#define SOC_KM_WRAP_DIN_LEN_wrap_din_len_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrap_done : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_WRAP_DONE_UNION;
#endif
#define SOC_KM_WRAP_DONE_wrap_done_START (0)
#define SOC_KM_WRAP_DONE_wrap_done_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrap_done_clr : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_WRAP_DONE_CLR_UNION;
#endif
#define SOC_KM_WRAP_DONE_CLR_wrap_done_clr_START (0)
#define SOC_KM_WRAP_DONE_CLR_wrap_done_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrap_data_mask : 32;
    } reg;
} SOC_KM_WRAP_DATA_MASK_UNION;
#endif
#define SOC_KM_WRAP_DATA_MASK_wrap_data_mask_START (0)
#define SOC_KM_WRAP_DATA_MASK_wrap_data_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrap_din_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_WRAP_DIN_SEL_UNION;
#endif
#define SOC_KM_WRAP_DIN_SEL_wrap_din_sel_START (0)
#define SOC_KM_WRAP_DIN_SEL_wrap_din_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrap_data_in : 32;
    } reg;
} SOC_KM_WRAP_DATA_IN_UNION;
#endif
#define SOC_KM_WRAP_DATA_IN_wrap_data_in_START (0)
#define SOC_KM_WRAP_DATA_IN_wrap_data_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrap_data_out : 32;
    } reg;
} SOC_KM_WRAP_DATA_OUT_UNION;
#endif
#define SOC_KM_WRAP_DATA_OUT_wrap_data_out_START (0)
#define SOC_KM_WRAP_DATA_OUT_wrap_data_out_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrap_data_in_parity : 32;
    } reg;
} SOC_KM_WRAP_DATA_IN_PARITY_UNION;
#endif
#define SOC_KM_WRAP_DATA_IN_PARITY_wrap_data_in_parity_START (0)
#define SOC_KM_WRAP_DATA_IN_PARITY_wrap_data_in_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrap_data_out_parity : 32;
    } reg;
} SOC_KM_WRAP_DATA_OUT_PARITY_UNION;
#endif
#define SOC_KM_WRAP_DATA_OUT_PARITY_wrap_data_out_parity_START (0)
#define SOC_KM_WRAP_DATA_OUT_PARITY_wrap_data_out_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mon_cnt_lock : 4;
        unsigned int mon_cnt_adden : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_KM_MON_CNT_CONTROL_UNION;
#endif
#define SOC_KM_MON_CNT_CONTROL_mon_cnt_lock_START (0)
#define SOC_KM_MON_CNT_CONTROL_mon_cnt_lock_END (3)
#define SOC_KM_MON_CNT_CONTROL_mon_cnt_adden_START (4)
#define SOC_KM_MON_CNT_CONTROL_mon_cnt_adden_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mon_cnt : 32;
    } reg;
} SOC_KM_MON_CNT_UNION;
#endif
#define SOC_KM_MON_CNT_mon_cnt_START (0)
#define SOC_KM_MON_CNT_mon_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mon_cnt_cfg : 32;
    } reg;
} SOC_KM_MON_CNT_CFG_UNION;
#endif
#define SOC_KM_MON_CNT_CFG_mon_cnt_cfg_START (0)
#define SOC_KM_MON_CNT_CFG_mon_cnt_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hmac_key1 : 32;
    } reg;
} SOC_KM_HMAC_KEY1_UNION;
#endif
#define SOC_KM_HMAC_KEY1_hmac_key1_START (0)
#define SOC_KM_HMAC_KEY1_hmac_key1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hmac_key2 : 32;
    } reg;
} SOC_KM_HMAC_KEY2_UNION;
#endif
#define SOC_KM_HMAC_KEY2_hmac_key2_START (0)
#define SOC_KM_HMAC_KEY2_hmac_key2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hmac_key1_mask : 32;
    } reg;
} SOC_KM_HMAC_KEY1_MASK_UNION;
#endif
#define SOC_KM_HMAC_KEY1_MASK_hmac_key1_mask_START (0)
#define SOC_KM_HMAC_KEY1_MASK_hmac_key1_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hmac_key2_mask : 32;
    } reg;
} SOC_KM_HMAC_KEY2_MASK_UNION;
#endif
#define SOC_KM_HMAC_KEY2_MASK_hmac_key2_mask_START (0)
#define SOC_KM_HMAC_KEY2_MASK_hmac_key2_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hmac_key1_parity : 32;
    } reg;
} SOC_KM_HMAC_KEY1_PARITY_UNION;
#endif
#define SOC_KM_HMAC_KEY1_PARITY_hmac_key1_parity_START (0)
#define SOC_KM_HMAC_KEY1_PARITY_hmac_key1_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hmac_key2_parity : 32;
    } reg;
} SOC_KM_HMAC_KEY2_PARITY_UNION;
#endif
#define SOC_KM_HMAC_KEY2_PARITY_hmac_key2_parity_START (0)
#define SOC_KM_HMAC_KEY2_PARITY_hmac_key2_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int km_dfx0 : 32;
    } reg;
} SOC_KM_DFX0_UNION;
#endif
#define SOC_KM_DFX0_km_dfx0_START (0)
#define SOC_KM_DFX0_km_dfx0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int km_dfx1 : 32;
    } reg;
} SOC_KM_DFX1_UNION;
#endif
#define SOC_KM_DFX1_km_dfx1_START (0)
#define SOC_KM_DFX1_km_dfx1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int km_dfx2 : 32;
    } reg;
} SOC_KM_DFX2_UNION;
#endif
#define SOC_KM_DFX2_km_dfx2_START (0)
#define SOC_KM_DFX2_km_dfx2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int km_dfx3 : 32;
    } reg;
} SOC_KM_DFX3_UNION;
#endif
#define SOC_KM_DFX3_km_dfx3_START (0)
#define SOC_KM_DFX3_km_dfx3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int drv_kram_ram_waddr : 4;
        unsigned int drv_kram_ram_raddr : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_KM_DRV_KEY_RAM_ADDR_UNION;
#endif
#define SOC_KM_DRV_KEY_RAM_ADDR_drv_kram_ram_waddr_START (0)
#define SOC_KM_DRV_KEY_RAM_ADDR_drv_kram_ram_waddr_END (3)
#define SOC_KM_DRV_KEY_RAM_ADDR_drv_kram_ram_raddr_START (4)
#define SOC_KM_DRV_KEY_RAM_ADDR_drv_kram_ram_raddr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int key_buffer_waddr : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_KEY_BUFFER_WADDR_UNION;
#endif
#define SOC_KM_KEY_BUFFER_WADDR_key_buffer_waddr_START (0)
#define SOC_KM_KEY_BUFFER_WADDR_key_buffer_waddr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int key_drv_data : 32;
    } reg;
} SOC_KM_KEY_DRV_DATA_UNION;
#endif
#define SOC_KM_KEY_DRV_DATA_key_drv_data_START (0)
#define SOC_KM_KEY_DRV_DATA_key_drv_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int key_drv_data_mask : 32;
    } reg;
} SOC_KM_KEY_DRV_DATA_MASK_UNION;
#endif
#define SOC_KM_KEY_DRV_DATA_MASK_key_drv_data_mask_START (0)
#define SOC_KM_KEY_DRV_DATA_MASK_key_drv_data_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int key_drv_data_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_KM_KEY_DRV_DATA_SEL_UNION;
#endif
#define SOC_KM_KEY_DRV_DATA_SEL_key_drv_data_sel_START (0)
#define SOC_KM_KEY_DRV_DATA_SEL_key_drv_data_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int drv_key_buff_data_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_KEY_RAM_DRV_DATA_SEL_UNION;
#endif
#define SOC_KM_KEY_RAM_DRV_DATA_SEL_drv_key_buff_data_sel_START (0)
#define SOC_KM_KEY_RAM_DRV_DATA_SEL_drv_key_buff_data_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pke_key_clr : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_PKE_KEY_CLR_UNION;
#endif
#define SOC_KM_PKE_KEY_CLR_pke_key_clr_START (0)
#define SOC_KM_PKE_KEY_CLR_pke_key_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrapping_key_din : 32;
    } reg;
} SOC_KM_WRAPPING_KEY_DIN_UNION;
#endif
#define SOC_KM_WRAPPING_KEY_DIN_wrapping_key_din_START (0)
#define SOC_KM_WRAPPING_KEY_DIN_wrapping_key_din_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrapping_key_mask : 32;
    } reg;
} SOC_KM_WRAPPING_KEY_MASK_UNION;
#endif
#define SOC_KM_WRAPPING_KEY_MASK_wrapping_key_mask_START (0)
#define SOC_KM_WRAPPING_KEY_MASK_wrapping_key_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrapping_key_parity : 32;
    } reg;
} SOC_KM_WRAPPING_KEY_PARITY_UNION;
#endif
#define SOC_KM_WRAPPING_KEY_PARITY_wrapping_key_parity_START (0)
#define SOC_KM_WRAPPING_KEY_PARITY_wrapping_key_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int img_decrykey_update_flag : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_IMG_DECRYKEY_UPDATE_FLAG_UNION;
#endif
#define SOC_KM_IMG_DECRYKEY_UPDATE_FLAG_img_decrykey_update_flag_START (0)
#define SOC_KM_IMG_DECRYKEY_UPDATE_FLAG_img_decrykey_update_flag_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int img_decrykey_clear : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_IMG_DECRYKEY_CLEAR_UNION;
#endif
#define SOC_KM_IMG_DECRYKEY_CLEAR_img_decrykey_clear_START (0)
#define SOC_KM_IMG_DECRYKEY_CLEAR_img_decrykey_clear_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsm_id : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_HSM_ID_UNION;
#endif
#define SOC_KM_HSM_ID_hsm_id_START (0)
#define SOC_KM_HSM_ID_hsm_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wrap_key_start : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_WRAP_KEY_START_UNION;
#endif
#define SOC_KM_WRAP_KEY_START_wrap_key_start_START (0)
#define SOC_KM_WRAP_KEY_START_wrap_key_start_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsm_des_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_HSM_DES_SEL_UNION;
#endif
#define SOC_KM_HSM_DES_SEL_hsm_des_sel_START (0)
#define SOC_KM_HSM_DES_SEL_hsm_des_sel_END (3)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
