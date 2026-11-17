/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: crypto engine aead hd interface
 * Create: 2024/04/11
 */
#include <linux/mm.h>
#include <linux/slab.h>
#include <securec.h>

#include "hicrypto_alg_hd_km.h"
#include "hicrypto_driver.h"
#include "hicrypto_dev_km.h"

#include "hicrypto_errno.h"
#include "hicrypto_log.h"
#include "hicrypto_utils.h"
#include "hicrypto_dft.h"
#include "hicrypto_macro.h"
#include "hicrypto_common.h"
#include "hicrypto_eng_ctrl.h"
#include "hicrypto_regs.h"
#include "hicrypto_io.h"

#define BSP_THIS_MODULE BSP_MODULE_KM

#define key_type_check(key_type) ((key_type) != HISI_SYMM_KEYTYPE_KDR && (key_type) != HISI_SYMM_KEYTYPE_GID)
#define wrap_key_check(key_type) ((key_type) != HISI_SYMM_KEYTYPE_AO_WRAPKEY)
#define wrap_mode_check(wrap_type) ((wrap_type) != HISI_KEY_WRAP && (wrap_type) != HISI_KEY_UNWRAP)
#define wrap_klen_check(klen) ((klen) != HISI_SYMM_KEYLEN_16 && (klen) != HISI_SYMM_KEYLEN_32)
#define export_klen_check(klen) ((klen) != HISI_SYMM_KEYLEN_16 && (klen) != HISI_SYMM_KEYLEN_32)

#define wrap_dlen_check(inlen, outlen)                                     \
    (((inlen) == HISI_SYMM_KEYLEN_8 && (outlen) == HISI_SYMM_KEYLEN_16) ||     \
        ((inlen) == HISI_SYMM_KEYLEN_16 && (outlen) == HISI_SYMM_KEYLEN_24) || \
        ((inlen) == HISI_SYMM_KEYLEN_24 && (outlen) == HISI_SYMM_KEYLEN_32) || \
        ((inlen) == HISI_SYMM_KEYLEN_32 && (outlen) == (HISI_SYMM_KEYLEN_32 + HISI_SYMM_KEYLEN_8)))
#define wrap_dout_check(klen)                                                                     \
    ((klen) != HISI_SYMM_KEYLEN_16 && (klen) != HISI_SYMM_KEYLEN_24 && (klen) != HISI_SYMM_KEYLEN_32 && \
        (klen) != (HISI_SYMM_KEYLEN_32 + HISI_SYMM_KEYLEN_8))


struct hicrypto_hd_derive {
    unsigned int keytype;      /* ::symm_ktype */
    unsigned int readable;     /* SEC_YES/SEC_NO */
    const unsigned char *pdin; /* pointer to derive vector */
    unsigned int dinlen;       /* byte length of pdin */
    unsigned char *pdout;      /* outbuf for derive key */
    unsigned int doutlen;      /* MUST be SYMM_KEYLEN_16 */
};

static int hicrypto_unwrap_data_check(struct hi_km_wrap_ctx_inner *wrap_ctx, struct hi_base_data *wrapping_key,
                                      struct hi_base_data *key_wrapped)
{
        if (pal_check(wrapping_key == NULL || wrapping_key->buffer == NULL ||
                      wrapping_key->type != ADDR_TYPE_KERNEL_VA || wrapping_key->size == 0))
            return err_api(ERRCODE_NULL);

        if (pal_check(key_wrapped == NULL || key_wrapped->type != ADDR_TYPE_KERNEL_VA || key_wrapped->size == 0))
            return err_api(ERRCODE_NULL);

        if (pal_check(wrap_dout_check(wrapping_key->size)))
            return err_api(ERRCODE_PARAMS);
        if (pal_check(wrap_dlen_check(key_wrapped->size, wrapping_key->size) == 0))
            return err_api(ERRCODE_PARAMS);
        if (pal_check(wrap_ctx->keybuff_waddr > 0xF))
            return err_api(ERRCODE_PARAMS);
        return BSP_RET_OK;
}

static int hicrypto_wrap_data_check(struct hi_km_wrap_ctx_inner *wrap_ctx, struct hi_base_data *wrapping_key,
                                    struct hi_base_data *key_wrapped)
{
    if (wrap_ctx->wrapmode == (unsigned int)HISI_KEY_WRAP) {
        if (pal_check(wrapping_key == NULL || wrapping_key->buffer == NULL ||
                      wrapping_key->type != ADDR_TYPE_KERNEL_VA || wrapping_key->size == 0))
            return err_api(ERRCODE_NULL);

        if (pal_check(key_wrapped == NULL || key_wrapped->buffer == NULL ||
                      key_wrapped->type != ADDR_TYPE_KERNEL_VA || key_wrapped->size == 0))
            return err_api(ERRCODE_NULL);

        if (pal_check(wrap_dlen_check(wrapping_key->size, key_wrapped->size) == 0))
            return err_api(ERRCODE_PARAMS);
    } else {
        int ret = hicrypto_unwrap_data_check(wrap_ctx, wrapping_key, key_wrapped);
        if (pal_check(ret != BSP_RET_OK))
            return ret;
    }

    return BSP_RET_OK;
}

/*
 * wrapmode:   WRAPMODE_WRAP/WRAPMODE_UNWRAP
 * key_type:	HISI_SYMM_KEYTYPE_AO_WRAPKEY
 * alg_type:    HISI_CIPHER_ALG_AES_CBC_NOPAD
 * wrapping_key: data to be wrapped/ unwrapped, only support from cpu
 * key: key to be wrapped/ unwrapped only for HISI_SYMM_KEYTYPE_AO_WRAPKEY
 * key_wrapped: wrapped data
 */
int hicrypto_ree_wrap_key(struct hi_km_wrap_ctx_inner *wrap_ctx, struct hi_base_data *wrapping_key,
    struct hi_base_data *key_in, struct hi_base_data *key_wrapped)
{
    struct hicrypto_device *hdev = NULL;
    int ret = err_api(ERRCODE_UNKNOWN);
    struct hidev_km_keywrap wrap_para = {0};
    struct hidev_km km = {0};
    unsigned char iv[HISI_SYMM_IVLEN_AES] = {0};

    hdev = hicrypto_find_dev(&hdev);
    if (pal_check(hdev == NULL))
        return err_api(ERRCODE_NULL);

    /* check alg param */
    if (pal_check(wrap_ctx == NULL))
        return err_api(ERRCODE_NULL);

    if (pal_check(wrap_mode_check(wrap_ctx->wrapmode)))
        return err_api(ERRCODE_PARAMS);

    if (pal_check(wrap_key_check(wrap_ctx->key_type)))
        return err_api(ERRCODE_PARAMS);

    if (pal_check(wrap_ctx->alg_type != HISI_CIPHER_ALG_AES_ECB_NOPAD))
        return err_api(ERRCODE_PARAMS);

    /* check key only for HISI_SYMM_KEYTYPE_AO_WRAPKEY */
    if (pal_check(key_in == NULL || wrap_klen_check(key_in->size)))
        return err_api(ERRCODE_PARAMS);

    /* check din */
    ret = hicrypto_wrap_data_check(wrap_ctx, wrapping_key, key_wrapped);
    if (pal_check(ret != BSP_RET_OK))
        return ret;
    hidev_km_wrap_init(&km, &wrap_para);
    wrap_para.keybuff_waddr = wrap_ctx->keybuff_waddr;
    wrap_para.wrap_mode = wrap_ctx->wrapmode;

    km.direction = (wrap_ctx->wrapmode == HISI_KEY_WRAP) ? HISI_SYMM_DIRECTION_ENCRYPT : HISI_SYMM_DIRECTION_DECRYPT;
    km.keylen = key_in->size;
    km.pdin = wrapping_key->buffer;
    km.dinlen = wrapping_key->size;
    km.doutlen = key_wrapped->size;
    km.pdout = key_wrapped->buffer;
    km.pivin = iv;

    seceng_ree_drv_run(hdev, &ret, 0, 0, hidev_km_function(hdev, &km));
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    return BSP_RET_OK;
}
/*
 * export_din_sel:   HISI_SYMM_KEYTYPE_DERIVE/HISI_SYMM_KEYTYPE_BUFFKEY
 * key_type:	HISI_SYMM_KEYTYPE_AO_WRAPKEY
 * alg_type:    HISI_CIPHER_ALG_AES_CBC_NOPAD
 * din_len:     export len
 * cipher_key: data to be export
 */
int hicrypto_ree_export_key(struct hi_km_export_ctx_inner *export_para, struct hi_base_data *cipher_key)
{
    struct hicrypto_device *hdev = NULL;
    int ret = err_api(ERRCODE_UNKNOWN);
    struct hidev_km_keyexport exp_extend = {0};
    struct hidev_km km = {0};
    unsigned char iv[HISI_SYMM_IVLEN_AES] = {0};

    hdev = hicrypto_find_dev(&hdev);
    if (pal_check(hdev == NULL))
        return err_api(ERRCODE_NULL);

    /* check alg param */
    if (pal_check(export_para == NULL))
        return err_api(ERRCODE_NULL);

    if (pal_check((export_para->export_din_sel != HISI_SYMM_KEYTYPE_DERIVE) &&
                  (export_para->export_din_sel != HISI_SYMM_KEYTYPE_BUFFKEY)))
        return err_api(ERRCODE_PARAMS);
    if (pal_check(export_para->key_type != HISI_SYMM_KEYTYPE_AO_WRAPKEY))
        return err_api(ERRCODE_PARAMS);
    if (pal_check(export_para->alg_type != HISI_CIPHER_ALG_AES_CBC_NOPAD))
        return err_api(ERRCODE_PARAMS);
    if (pal_check((export_para->dinlen % HISI_SYMM_BLKLEN_AES) != 0))
        return err_api(ERRCODE_PARAMS);

    if (pal_check(cipher_key == NULL || cipher_key->buffer == NULL || cipher_key->type != ADDR_TYPE_KERNEL_VA ||
                  cipher_key->size != export_para->dinlen))
        return err_api(ERRCODE_PARAMS);
    if (pal_check(export_klen_check(export_para->key_len)))
        return err_api(ERRCODE_PARAMS);

    hidev_km_export_init(&km, &exp_extend);
    exp_extend.keybuff_waddr = HISI_KEY_BUFF_DATA_STR;
    exp_extend.export_din_sel = export_para->export_din_sel == HISI_SYMM_KEYTYPE_DERIVE ? HISI_KM_REG_KEYTYPE_DERIVEKEY
                                                                                      : HISI_KM_REG_KEYTYPE_KEYBUFF;
    exp_extend.export_din_data_sel = HISI_DERIVE_DATA_UNREAD_STR;

    km.keylen = export_para->key_len;

    km.dinlen = export_para->dinlen;
    km.doutlen = cipher_key->size;
    km.pdout = cipher_key->buffer;
    km.pivin = iv;

    seceng_ree_drv_run(hdev, &ret, 0, 0, hidev_km_function(hdev, &km));
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    return BSP_RET_OK;
}

static int hicrypto_ree_derive_key(struct hicrypto_device *hdev, struct hicrypto_hd_derive *derive)
{
    int ret = err_api(ERRCODE_UNKNOWN);
    struct hidev_km km;
    struct hidev_km_derive derive_para;
    unsigned char iv[HISI_SYMM_IVLEN_AES] = {0};

    hidev_km_derive_init(&km, &derive_para, derive->readable, derive->keytype);

    if (derive->readable == SEC_YES) {
        km.pdout = derive->pdout;
        km.doutlen = derive->doutlen;
    }

    km.pdin = derive->pdin;
    km.dinlen = derive->dinlen;
    km.pivin = iv;
    km.ivinlen = sizeof(iv);
    ret = hidev_km_function(hdev, &km);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    return ret;
}

int hicrypto_ree_derive_root_key(unsigned int derive_type, struct hi_base_data *in, struct hi_base_data *out)
{
    struct hicrypto_device *hdev = NULL;
    int ret = err_api(ERRCODE_UNKNOWN);
    struct hicrypto_hd_derive derive = {0};

    hdev = hicrypto_find_dev(&hdev);
    if (pal_check(hdev == NULL))
        return err_api(ERRCODE_NULL);

    if (pal_check(key_type_check(derive_type)))
        return err_api(ERRCODE_UNSUPPORT);

    if (pal_check(
            in == NULL || out == NULL || in->buffer == NULL || out->buffer == NULL || in->size == 0 || out->size == 0))
        return err_api(ERRCODE_NULL);

    if (pal_check(in->type != ADDR_TYPE_KERNEL_VA || out->type != ADDR_TYPE_KERNEL_VA))
        return err_api(ERRCODE_UNSUPPORT);

    if (pal_check(out->size < KEY_DERIVE_BASIC_OUTLEN))
        return err_api(ERRCODE_MEMORY);

    derive.keytype = derive_type;
    derive.pdin = in->buffer;
    derive.dinlen = in->size;
    derive.pdout = out->buffer;
    derive.doutlen = KEY_DERIVE_BASIC_OUTLEN;
    derive.readable = SEC_YES;

    seceng_ree_drv_run(hdev, &ret, 0, 0, hicrypto_ree_derive_key(hdev, &derive));
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    out->size = KEY_DERIVE_BASIC_OUTLEN;
    return BSP_RET_OK;
}

int hicrypto_ree_derive_unreadable_key(unsigned int derive_type, struct hi_base_data *in, unsigned int *pdoutlen)
{
    struct hicrypto_device *hdev = NULL;
    int ret = err_api(ERRCODE_UNKNOWN);
    struct hicrypto_hd_derive derive = {0};

    hdev = hicrypto_find_dev(&hdev);
    if (pal_check(hdev == NULL))
        return err_api(ERRCODE_NULL);

    if (pal_check(derive_type != HISI_SYMM_KEYTYPE_KDR && derive_type != HISI_SYMM_KEYTYPE_POS))
        return err_api(ERRCODE_UNSUPPORT);

    if (pal_check(in == NULL || pdoutlen == NULL || in->buffer == NULL || in->size == 0))
        return err_api(ERRCODE_NULL);
    if (pal_check(in->type != ADDR_TYPE_KERNEL_VA))
        return err_api(ERRCODE_NULL);

    derive.keytype = derive_type;
    derive.pdin = in->buffer;
    derive.dinlen = in->size;
    derive.pdout = NULL;
    derive.doutlen = KEY_DERIVE_BASIC_OUTLEN;
    derive.readable = SEC_NO;

    seceng_ree_drv_run(hdev, &ret, 0, 0, hicrypto_ree_derive_key(hdev, &derive));
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    *pdoutlen = KEY_DERIVE_BASIC_OUTLEN;
    return BSP_RET_OK;
}

int hicrypto_ree_derive_readable_key(unsigned int derive_type, struct hi_base_data *in, struct hi_base_data *out)
{
    struct hicrypto_device *hdev = NULL;
    int ret = err_api(ERRCODE_UNKNOWN);
    struct hicrypto_hd_derive derive = {0};

    hdev = hicrypto_find_dev(&hdev);
    if (pal_check(hdev == NULL))
        return err_api(ERRCODE_NULL);

    if (pal_check(derive_type != HISI_SYMM_KEYTYPE_GID && derive_type != HISI_SYMM_KEYTYPE_KDR))
        return err_api(ERRCODE_UNSUPPORT);

    if (pal_check(in == NULL || in->buffer == NULL || in->size == 0))
        return err_api(ERRCODE_NULL);

    if (pal_check(in->type != ADDR_TYPE_KERNEL_VA))
        return err_api(ERRCODE_NULL);

    if (pal_check(out == NULL || out->buffer == NULL || out->size == 0))
        return err_api(ERRCODE_NULL);

    if (pal_check(out->type != ADDR_TYPE_KERNEL_VA))
        return err_api(ERRCODE_NULL);

    derive.keytype = derive_type;
    derive.pdin = in->buffer;
    derive.dinlen = in->size;
    derive.pdout = out->buffer;
    derive.doutlen = out->size;
    derive.readable = SEC_YES;

    seceng_ree_drv_run(hdev, &ret, 0, 0, hicrypto_ree_derive_key(hdev, &derive));
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    return BSP_RET_OK;
}

void hicrypto_km_gid_derive_selftest(struct hicrypto_device *hdev)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    struct hi_base_data inner_in = {0};
    struct hi_base_data inner_out = {0};
    unsigned char *in = NULL;
    unsigned char *out = NULL;
    unsigned char except_ret[HISI_SYMM_KEYLEN_16] = KM_VERIFY_GID_REF_DERIVE_OUT;

    in = (unsigned char *)kzalloc(HISI_SYMM_KEYLEN_32, GFP_KERNEL);
    if (pal_check(in == NULL)) {
        pal_error("hicrypto km selftest malloc failed\n");
        return;
    }
    out = (unsigned char *)kzalloc(HISI_SYMM_KEYLEN_16, GFP_KERNEL);
    if (pal_check(out == NULL)){
        pal_error("hicrypto km selftest malloc failed\n");
        kfree(in);
        return;
    }

    hi_gen_base(inner_in, in, HISI_SYMM_KEYLEN_32, ADDR_TYPE_KERNEL_VA);
    hi_gen_base(inner_out, out, HISI_SYMM_KEYLEN_16, ADDR_TYPE_KERNEL_VA);
    ret = hicrypto_ree_derive_readable_key(HISI_SYMM_KEYTYPE_GID, &inner_in, &inner_out);
    if (pal_check(ret != BSP_RET_OK)) {
        pal_error("hicrypto derive gid key failed, ret=0x%x\n", ret);
        hdev->km_valid_flag = HISI_KM_VALID_DIS;
        goto end_handler;
    }

    if (memcmp(inner_out.buffer, except_ret, HISI_SYMM_KEYLEN_16) == 0) {
        hdev->km_valid_flag = HISI_KM_VALID_EN;
    } else {
        pal_error("hicrypto km not valid\n");
        hdev->km_valid_flag = HISI_KM_VALID_DIS;
    }

end_handler:
    kfree(in);
    kfree(out);
}

int hicrypto_ree_km_rtldec(void)
{
    struct hicrypto_device *hdev = NULL;
    int ret = err_api(ERRCODE_UNKNOWN);

    hdev = hicrypto_find_dev(&hdev);
    if (pal_check(hdev == NULL))
        return err_api(ERRCODE_NULL);

    seceng_ree_drv_run(hdev, &ret, 0, 0, hidev_km_rtldec_function(hdev));
    if (pal_check(ret != BSP_RET_OK)) {
        pal_error(" hicrypto rtl dec failed, ret = 0x%x\n", ret);
        return ret;
    }

    return BSP_RET_OK;
}

static int hicrypto_km_kdr_derive_selftest(struct hicrypto_device *hdev)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    struct hicrypto_hd_derive derive = {0};
    unsigned char in[HISI_SYMM_KEYLEN_32] = {0};
    unsigned char out[HISI_SYMM_KEYLEN_16] = {0};
    const unsigned char except_ret[HISI_SYMM_KEYLEN_16] = {
        0x9e, 0xd3, 0x9b, 0xed, 0x22, 0x69, 0x3b, 0x32,
        0xee, 0xfe, 0x9a, 0x2b, 0xbd, 0x39, 0xc9, 0x13
    };
    derive.keytype = HISI_SYMM_KEYTYPE_KDR;
    derive.pdin = in;
    derive.dinlen = sizeof(in);
    derive.pdout = out;
    derive.doutlen = sizeof(out);
    derive.readable = SEC_YES;
    ret = hicrypto_ree_derive_key(hdev, &derive);
    if (pal_check(ret != BSP_RET_OK)) {
        pal_error("hicrypto_ree_derive_key failed!, ret = 0x%x\n", ret);
        return err_drv(ERRCODE_NOREADY);
    }
    if (memcmp(out, except_ret, HISI_SYMM_KEYLEN_16) == 0) {
        pal_error("hicrypto km mac key not ready!\n");
        return err_drv(ERRCODE_NOREADY);
    } else {
        return BSP_RET_OK;
    }
}

int hicrypto_km_kdr_derive_check(struct hicrypto_device *hdev)
{
    int ret = hicrypto_km_kdr_derive_selftest(hdev);
    if (pal_check(ret != BSP_RET_OK)) {
        ret = hidev_km_rtldec_function(hdev);
        if (pal_check(ret != BSP_RET_OK)) {
            pal_error("hicrypto rtl key decrypt failed!\n");
        }
    }
    return ret;
}