#ifndef __SOC_QICE_MDE_AUTH_INTERFACE_H__
#define __SOC_QICE_MDE_AUTH_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_MDE_AUTH_MDE_AES_EN_ADDR(base) (base)
#define SOC_QICE_MDE_AUTH_MDEAUTH_CTRL_ADDR(base) ((base) + 0x0010UL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT0_ADDR(base) ((base) + 0x0020UL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT1_ADDR(base) ((base) + 0x0024UL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT2_ADDR(base) ((base) + 0x0028UL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT3_ADDR(base) ((base) + 0x002CUL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT4_ADDR(base) ((base) + 0x0030UL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT5_ADDR(base) ((base) + 0x0034UL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT6_ADDR(base) ((base) + 0x0038UL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT7_ADDR(base) ((base) + 0x003CUL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_NTRUST_ADDR(base,mde_auth_mid_idx) (base) + 0x0040 + 0x4 * (mde_auth_mid_idx)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM0_ADDR(base) ((base) + 0x0060UL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM1_ADDR(base) ((base) + 0x0064UL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM2_ADDR(base) ((base) + 0x0068UL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM3_ADDR(base) ((base) + 0x006CUL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM4_ADDR(base) ((base) + 0x0070UL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM5_ADDR(base) ((base) + 0x0074UL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM6_ADDR(base) ((base) + 0x0078UL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM7_ADDR(base) ((base) + 0x007CUL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_ENCRYPT_ACC_NDRM_ADDR(base,mde_auth_mid_idx) (base) + 0x0080 + 0x4 * (mde_auth_mid_idx)
#define SOC_QICE_MDE_AUTH_MDE_AES_KEY_ADDR(base,mde_aes_key_idx) (base) + 0x0100 + 0x4 * (mde_aes_key_idx)
#define SOC_QICE_MDE_AUTH_MDE_TWEAK_INI_ADDR(base,mde_tweak_ini_idx) (base) + 0x0140 + 0x4 * (mde_tweak_ini_idx)
#define SOC_QICE_MDE_AUTH_MDEAUTH_RTL_INF_ADDR(base) ((base) + 0x0400UL)
#define SOC_QICE_MDE_AUTH_MDEAUTH_RSV_RW_ADDR(base) ((base) + 0x0408UL)
#else
#define SOC_QICE_MDE_AUTH_MDE_AES_EN_ADDR(base) (base)
#define SOC_QICE_MDE_AUTH_MDEAUTH_CTRL_ADDR(base) ((base) + 0x0010)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT0_ADDR(base) ((base) + 0x0020)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT1_ADDR(base) ((base) + 0x0024)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT2_ADDR(base) ((base) + 0x0028)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT3_ADDR(base) ((base) + 0x002C)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT4_ADDR(base) ((base) + 0x0030)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT5_ADDR(base) ((base) + 0x0034)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT6_ADDR(base) ((base) + 0x0038)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT7_ADDR(base) ((base) + 0x003C)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_NTRUST_ADDR(base,mde_auth_mid_idx) (base) + 0x0040 + 0x4 * (mde_auth_mid_idx)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM0_ADDR(base) ((base) + 0x0060)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM1_ADDR(base) ((base) + 0x0064)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM2_ADDR(base) ((base) + 0x0068)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM3_ADDR(base) ((base) + 0x006C)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM4_ADDR(base) ((base) + 0x0070)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM5_ADDR(base) ((base) + 0x0074)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM6_ADDR(base) ((base) + 0x0078)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM7_ADDR(base) ((base) + 0x007C)
#define SOC_QICE_MDE_AUTH_MDEAUTH_ENCRYPT_ACC_NDRM_ADDR(base,mde_auth_mid_idx) (base) + 0x0080 + 0x4 * (mde_auth_mid_idx)
#define SOC_QICE_MDE_AUTH_MDE_AES_KEY_ADDR(base,mde_aes_key_idx) (base) + 0x0100 + 0x4 * (mde_aes_key_idx)
#define SOC_QICE_MDE_AUTH_MDE_TWEAK_INI_ADDR(base,mde_tweak_ini_idx) (base) + 0x0140 + 0x4 * (mde_tweak_ini_idx)
#define SOC_QICE_MDE_AUTH_MDEAUTH_RTL_INF_ADDR(base) ((base) + 0x0400)
#define SOC_QICE_MDE_AUTH_MDEAUTH_RSV_RW_ADDR(base) ((base) + 0x0408)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_mde_aes_key_vld : 1;
        unsigned int icfg_mde_wchn_bypass : 1;
        unsigned int icfg_mde_rchn_bypass : 1;
        unsigned int icfg_mde_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_MDE_AUTH_MDE_AES_EN_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDE_AES_EN_icfg_mde_aes_key_vld_START (0)
#define SOC_QICE_MDE_AUTH_MDE_AES_EN_icfg_mde_aes_key_vld_END (0)
#define SOC_QICE_MDE_AUTH_MDE_AES_EN_icfg_mde_wchn_bypass_START (1)
#define SOC_QICE_MDE_AUTH_MDE_AES_EN_icfg_mde_wchn_bypass_END (1)
#define SOC_QICE_MDE_AUTH_MDE_AES_EN_icfg_mde_rchn_bypass_START (2)
#define SOC_QICE_MDE_AUTH_MDE_AES_EN_icfg_mde_rchn_bypass_END (2)
#define SOC_QICE_MDE_AUTH_MDE_AES_EN_icfg_mde_bypass_START (3)
#define SOC_QICE_MDE_AUTH_MDE_AES_EN_icfg_mde_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_en : 1;
        unsigned int mde_auth_rsperr_dis : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_CTRL_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_CTRL_mde_auth_en_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_CTRL_mde_auth_en_END (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_CTRL_mde_auth_rsperr_dis_START (1)
#define SOC_QICE_MDE_AUTH_MDEAUTH_CTRL_mde_auth_rsperr_dis_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_trust_wr_encrypt0 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT0_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT0_mde_auth_mid_trust_wr_encrypt0_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT0_mde_auth_mid_trust_wr_encrypt0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_trust_wr_encrypt1 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT1_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT1_mde_auth_mid_trust_wr_encrypt1_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT1_mde_auth_mid_trust_wr_encrypt1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_trust_wr_encrypt2 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT2_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT2_mde_auth_mid_trust_wr_encrypt2_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT2_mde_auth_mid_trust_wr_encrypt2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_trust_wr_encrypt3 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT3_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT3_mde_auth_mid_trust_wr_encrypt3_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT3_mde_auth_mid_trust_wr_encrypt3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_trust_wr_encrypt4 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT4_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT4_mde_auth_mid_trust_wr_encrypt4_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT4_mde_auth_mid_trust_wr_encrypt4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_trust_wr_encrypt5 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT5_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT5_mde_auth_mid_trust_wr_encrypt5_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT5_mde_auth_mid_trust_wr_encrypt5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_trust_wr_encrypt6 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT6_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT6_mde_auth_mid_trust_wr_encrypt6_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT6_mde_auth_mid_trust_wr_encrypt6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_trust_wr_encrypt7 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT7_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT7_mde_auth_mid_trust_wr_encrypt7_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_ENCRYPT7_mde_auth_mid_trust_wr_encrypt7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_trust_wr_ntrust : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_NTRUST_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_NTRUST_mde_auth_mid_trust_wr_ntrust_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_TRUST_WR_NTRUST_mde_auth_mid_trust_wr_ntrust_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_ntrust_acc_drm0 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM0_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM0_mde_auth_mid_ntrust_acc_drm0_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM0_mde_auth_mid_ntrust_acc_drm0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_ntrust_acc_drm1 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM1_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM1_mde_auth_mid_ntrust_acc_drm1_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM1_mde_auth_mid_ntrust_acc_drm1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_ntrust_acc_drm2 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM2_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM2_mde_auth_mid_ntrust_acc_drm2_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM2_mde_auth_mid_ntrust_acc_drm2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_ntrust_acc_drm3 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM3_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM3_mde_auth_mid_ntrust_acc_drm3_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM3_mde_auth_mid_ntrust_acc_drm3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_ntrust_acc_drm4 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM4_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM4_mde_auth_mid_ntrust_acc_drm4_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM4_mde_auth_mid_ntrust_acc_drm4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_ntrust_acc_drm5 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM5_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM5_mde_auth_mid_ntrust_acc_drm5_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM5_mde_auth_mid_ntrust_acc_drm5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_ntrust_acc_drm6 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM6_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM6_mde_auth_mid_ntrust_acc_drm6_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM6_mde_auth_mid_ntrust_acc_drm6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_ntrust_acc_drm7 : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM7_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM7_mde_auth_mid_ntrust_acc_drm7_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_NTRUST_ACC_DRM7_mde_auth_mid_ntrust_acc_drm7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_auth_mid_encrypt_acc_ndrm : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_ENCRYPT_ACC_NDRM_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_ENCRYPT_ACC_NDRM_mde_auth_mid_encrypt_acc_ndrm_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_ENCRYPT_ACC_NDRM_mde_auth_mid_encrypt_acc_ndrm_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_aes_key : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDE_AES_KEY_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDE_AES_KEY_mde_aes_key_START (0)
#define SOC_QICE_MDE_AUTH_MDE_AES_KEY_mde_aes_key_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mde_tweak_ini : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDE_TWEAK_INI_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDE_TWEAK_INI_mde_tweak_ini_START (0)
#define SOC_QICE_MDE_AUTH_MDE_TWEAK_INI_mde_tweak_ini_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_RTL_INF_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_RTL_INF_rtl_info_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_RTL_INF_rtl_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_rw : 32;
    } reg;
} SOC_QICE_MDE_AUTH_MDEAUTH_RSV_RW_UNION;
#endif
#define SOC_QICE_MDE_AUTH_MDEAUTH_RSV_RW_rsv_rw_START (0)
#define SOC_QICE_MDE_AUTH_MDEAUTH_RSV_RW_rsv_rw_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
