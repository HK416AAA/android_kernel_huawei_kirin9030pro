/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: Hisilicon hardware crypto engine cipher alg.
 * Create : 2024/04/18
 */
#include <securec.h>
#include <asm/barrier.h>
#include <linux/iopoll.h>

#include "hicrypto_regs.h"
#include "hicrypto_register.h"
#include "hicrypto_dev_km.h"
#include "hicrypto_dev_symm.h"
#include "hicrypto_eng_ctrl.h"
#include "hicrypto_macro.h"

#define BSP_THIS_MODULE BSP_MODULE_KM

/* used for input key */
#define REE_KM_CFG_KEY_RANDOM_DELAY_CYCLES_MAX 8

#define REE_KM_REG_DONE 5
#define REE_KM_REG_STR_VALUE 5
#define REE_KM_REG_CLR 0x5

#define SOC_REE_KM_DERIVEKEY_REGNUM 4
#define SOC_REE_SCE_WRAPKEY_REGNUM 8
#define REE_KM_KEY_DRV_DATA_WORDNUM 4
#define REE_KM_WRAP_DATA_IN_WORDNUM 10
#define REE_KM_WRAP_DATA_OUT_WORDNUM 10

#define REE_KM_DERIVE_DONE_TIMEOUTUS 1000
#define REE_KM_RTLDEC_DONE_TIMEOUTUS 1000
#define REE_KM_WRAP_DONE_TIMEOUTUS 1000
#define REE_KM_IMGKEY_INIT_INDEX 0x5 /* cann't be less than 0x5 */
#define REE_KM_IMGKEY_MIN_INIT_INDEX 0x5

#define reekm_reg_get_wrap_din_len(dinlen) ((dinlen) / 8 - 1)

/* save lock status and change to unlock */
#define reekm_reglock_save(hdev, pflag)             \
    do {                                            \
        *(pflag) = reekm_reg_get_lock_status(hdev); \
        if (*(pflag) != SEC_UNLOCK) {               \
            reekm_reg_cfg_lock((hdev), SEC_UNLOCK); \
        }                                           \
    } while (0)

/* restore lock status */
#define reekm_reglock_restore(hdev, flag)     \
    do {                                      \
        if ((flag) != SEC_UNLOCK) {           \
            reekm_reg_cfg_lock((hdev), flag); \
        }                                     \
    } while (0)

enum reekm_reg_lock {
    REE_KM_REG_LOCK = 0x5,
    REE_KM_REG_UNLOCK = 0xA,
};

enum reekm_reg_keylock {
    REE_KM_REG_KEY_LOCK = 0x5,
    REE_KM_REG_KEY_UNLOCK = 0xA,
};

/* base km reg read */
unsigned int hisi_reg_km_read(struct hicrypto_device *hdev, unsigned int offset)
{
	return pal_read_u32(ptr_add(ptr_to_ulong(hdev->km_base), offset));
}

/* base km reg write */
void hisi_reg_km_write(struct hicrypto_device *hdev, unsigned int offset, unsigned int value)
{
	pal_write_u32(value, ptr_add(ptr_to_ulong(hdev->km_base) , offset));
}

void reekm_reg_cfg_kmmode(struct hicrypto_device *hdev, unsigned int kmmode)
{
    hisi_km_mode_union km_mode = {0};

    km_mode.value = hisi_reg_km_read(hdev, HISI_KM_OFF_KM_MODE);
    km_mode.reg.km_mode = kmmode;
    hisi_reg_km_write(hdev, HISI_KM_OFF_KM_MODE, km_mode.value); /* km_reg_cfg_kmmode */
}

static enum sec_status_e reekm_reg_get_lock_status(struct hicrypto_device *hdev)
{
    hisi_km_reg_lock_union lock;

    lock.value = hisi_reg_km_read(hdev, HISI_KM_OFF_REG_LOCK);
    if (lock.value == REE_KM_REG_UNLOCK)
        return SEC_UNLOCK;
    else
        return SEC_LOCK;
}

static void reekm_reg_cfg_lock(struct hicrypto_device *hdev, unsigned int lock)
{
    hisi_km_reg_lock_union kmlock = {.value = 0};

    if (lock == SEC_UNLOCK)
        kmlock.value = REE_KM_REG_UNLOCK;
    else
        kmlock.value = REE_KM_REG_LOCK;

    hisi_reg_km_write(hdev, HISI_KM_OFF_REG_LOCK, kmlock.value);
}

static void reekm_reg_cfg_keylock(struct hicrypto_device *hdev, unsigned int lock)
{
    hisi_km_reg_lock_union klock = {.value = 0};

    if (lock == SEC_UNLOCK)
        klock.value = REE_KM_REG_KEY_UNLOCK;
    else
        klock.value = REE_KM_REG_KEY_LOCK;

    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_REG_LOCK, klock.value);
}

static int reekm_reg_wait_derive_done(struct hicrypto_device *hdev, unsigned int timeoutus)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    unsigned int result;
    hisi_km_key_derive_done_union derive_done_value = {.value = 0};
    hisi_km_key_derive_done_union derive_done_mask = {.value = 0};

    derive_done_value.reg.key_derive_done = REE_KM_REG_DONE; /* done value */
    derive_done_mask.reg.key_derive_done = REE_KM_REG_DONE;  /* mask bitwidth */

    ret = readl_relaxed_poll_timeout_atomic(ptr_add(ptr_to_ulong(hdev->km_base), HISI_KM_OFF_KEY_DERIVE_DONE),
        result,
        ((result & derive_done_mask.value) == derive_done_value.value),
        HISI_REG_SLEEP_US,
        timeoutus);
    if (pal_check(ret != 0))
        return err_drv(ERRCODE_TIMEOUT);

    return BSP_RET_OK;
}

static void reekm_reg_clr_derive_done(struct hicrypto_device *hdev)
{
    hisi_km_key_dervice_done_clr_union done = {.value = 0};

    done.reg.key_derive_done_clr = REE_KM_REG_DONE;
    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_DERIVE_DONE_CLR, done.value);
}

static inline void reekm_reg_str(struct hicrypto_device *hdev)
{
    hisi_km_str_union str = {.value = 0};

    str.reg.km_str = REE_KM_REG_STR_VALUE;
    hisi_reg_km_write(hdev, HISI_KM_OFF_KM_STR, str.value);
}

/* for sce */
struct hisi_km_reg_keytype g_ktype_map[HISI_SYMM_KEYTYPE_MAX] = {
    [HISI_SYMM_KEYTYPE_CEK] = {HISI_KM_REG_KEYTYPE_CEK, 0},
    [HISI_SYMM_KEYTYPE_KDR] = {HISI_KM_REG_KEYTYPE_ROOTKEY, HISI_KM_REG_ROOTKEY_KDR},
    [HISI_SYMM_KEYTYPE_GID] = {HISI_KM_REG_KEYTYPE_ROOTKEY, HISI_KM_REG_ROOTKEY_GID},
    [HISI_SYMM_KEYTYPE_RTL] = {HISI_KM_REG_KEYTYPE_RTL0, 0},
    [HISI_SYMM_KEYTYPE_USER] = {HISI_KM_REG_KEYTYPE_CPU, 0},
    [HISI_SYMM_KEYTYPE_POS] = {HISI_KM_REG_KEYTYPE_ROOTKEY, HISI_KM_REG_ROOTKEY_POS},
    [HISI_SYMM_KEYTYPE_DERIVE] = {HISI_KM_REG_KEYTYPE_DERIVEKEY, HISI_DERIVE_DATA_UNREAD_STR},
    [HISI_SYMM_KEYTYPE_RTL1] = {HISI_KM_REG_KEYTYPE_RTL1, 0},
    [HISI_SYMM_KEYTYPE_CEK1] = {HISI_KM_REG_KEYTYPE_KEYBUFF, HISI_KEY_BUFF_DATA_STR},
    [HISI_SYMM_KEYTYPE_TAKEY] = {HISI_KM_REG_KEYTYPE_KEYBUFF, HISI_KEY_BUFF_DATA_STR},
    [HISI_SYMM_KEYTYPE_BUFFKEY] = {HISI_KM_REG_KEYTYPE_KEYBUFF, HISI_KEY_BUFF_DATA_STR},
    [HISI_SYMM_KEYTYPE_AO_WRAPKEY] = {HISI_KM_REG_KEYTYPE_AO_WRAPKEY, 0},
    [HISI_SYMM_KEYTYPE_CPU_WRAPKEY] = {HISI_KM_REG_KEYTYPE_CPU_WRAPKEY, 0},
    [HISI_SYMM_KEYTYPE_IMGKEY] = {HISI_KM_REG_KEYTYPE_IMGKEY, 0},
};

static int reekm_reg_input_algkey(
    struct hicrypto_device *hdev, const struct hisi_km_key_reg *key, const struct hisi_dev_cipher_param *ctx)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    unsigned int keymask = 0;
    unsigned int klen;
    unsigned int key_wordnum;

    /* aes pkey is divided into two part for key1 and key2 */
    klen = ctx->keylen;
    if ((ctx->mode == HISI_CIPHER_MODE_XTS) && (ctx->algorithm == HISI_CIPHER_ALGORITHM_AES))
        klen = hisi_half_value(ctx->keylen);

    key_wordnum = byte2word(klen);

    hisi_reg_km_write(hdev, key->mask_addr, keymask);
    ret = hisi_reg_write(
        ptr_add(ptr_to_ulong(hdev->km_base), key->key_addr), SOC_SCE_AESKEY_REGNUM, ctx->pkey, key_wordnum);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    /* aes set xts key2 */
    if (ctx->mode == HISI_CIPHER_MODE_XTS && (ctx->algorithm == HISI_CIPHER_ALGORITHM_AES)) {
        hisi_reg_write(ptr_add(ptr_to_ulong(hdev->km_base), HISI_KM_OFF_WRAPPING_KEY_DIN),
            key_wordnum,
            ctx->pkey + klen,
            key_wordnum);
        return ret;
    }

    /* des
     * when 8/24, here return
     * when 16, need config A additional
     */
    if (ctx->keylen == HISI_SYMM_KEYLEN_16 && (ctx->algorithm == HISI_CIPHER_ALGORITHM_DES)) {
        ret = hisi_reg_write(ptr_add(ptr_to_ulong(hdev->km_base), key->key_addr + HISI_SYMM_KEYLEN_16),
            HISI_SCE_DESKEY_REGNUM - byte2word(HISI_SYMM_KEYLEN_16),
            ctx->pkey,
            byte2word(HISI_SYMM_KEYLEN_8));
        return ret;
    }
    return ret;
}

static int reekm_reg_input_userkey(struct hicrypto_device *hdev, const struct hisi_dev_cipher_param *ctx)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    struct hisi_km_key_reg key_reg_addr = {0};

    switch (ctx->algorithm) {
        case HISI_CIPHER_ALGORITHM_AES:
            key_reg_addr.key_addr = HISI_KM_OFF_AES_KEY;
            key_reg_addr.key_bak_addr = HISI_KM_OFF_AES_KEY_PARITY;
            key_reg_addr.mask_addr = HISI_KM_OFF_AESKEY_MASK;
            ret = reekm_reg_input_algkey(hdev, &key_reg_addr, ctx);
            if (pal_check(ret != BSP_RET_OK))
                return ret;
            break;
        case HISI_CIPHER_ALGORITHM_DES:
            key_reg_addr.key_addr = HISI_KM_OFF_DES_KEY;
            key_reg_addr.key_bak_addr = HISI_KM_OFF_DES_KEY_PARITY;
            key_reg_addr.mask_addr = HISI_KM_OFF_DESKEY_MASK;
            ret = reekm_reg_input_algkey(hdev, &key_reg_addr, ctx);
            if (pal_check(ret != BSP_RET_OK))
                return ret;
            break;
        case HISI_CIPHER_ALGORITHM_SM4:
            key_reg_addr.key_addr = HISI_KM_OFF_SM4_KEY;
            key_reg_addr.key_bak_addr = HISI_KM_OFF_SM4_KEY_PARITY;
            key_reg_addr.mask_addr = HISI_KM_OFF_SM4KEY_MASK;
            ret = reekm_reg_input_algkey(hdev, &key_reg_addr, ctx);
            if (pal_check(ret != BSP_RET_OK))
                return ret;
            break;
        default:
            pal_info("userkey OTHER\n");
            break;
    }

    return ret;
}

static int reekm_reg_cfg_keytype(struct hicrypto_device *hdev, unsigned int keytype, unsigned int sub_keytype)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    hisi_km_sel_union key_sel_union = {0};

    key_sel_union.value = hisi_reg_km_read(hdev, HISI_KM_OFF_KEY_SEL);
    key_sel_union.reg.sce_key_sel = keytype;
    switch (keytype) {
        case HISI_KM_REG_KEYTYPE_ROOTKEY:
            key_sel_union.reg.km_rootkey_sel = sub_keytype;
            break;
        case HISI_KM_REG_KEYTYPE_DERIVEKEY:
            key_sel_union.reg.km_derive_key_sel = sub_keytype;
            break;
        case HISI_KM_REG_KEYTYPE_KEYBUFF:
            key_sel_union.reg.km_key_buff_sel = sub_keytype;
            break;
        case HISI_KM_REG_KEYTYPE_CPU:
        case HISI_KM_REG_KEYTYPE_RTL0:
        case HISI_KM_REG_KEYTYPE_RTL1:
        case HISI_KM_REG_KEYTYPE_AO_WRAPKEY:
        case HISI_KM_REG_KEYTYPE_CPU_WRAPKEY:
        case HISI_KM_REG_KEYTYPE_CEK:
        case HISI_KM_REG_KEYTYPE_IMGKEY:
            break;
        default:
            return ret;
    }
    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_SEL, key_sel_union.value);

    return BSP_RET_OK;
}

int reekm_reg_input_key(struct hicrypto_device *hdev, const struct hisi_dev_cipher_param *ctx)
{
    int ret = err_drv(ERRCODE_UNKNOWN);

    hisi_reg_km_write(hdev, HISI_KM_OFF_REG_LOCK, HISI_KM_VALUE_UNLOCK); /* km_reg_cfg_lock */

    /* kmmode/keytype */
    reekm_reg_cfg_kmmode(hdev, HISI_KM_REG_KMMODE_CRYPTO);
    ret =
        reekm_reg_cfg_keytype(hdev, g_ktype_map[ctx->keytype].km_reg_ktype, g_ktype_map[ctx->keytype].km_reg_sub_ktype);
    if (pal_check(ret != BSP_RET_OK))
        goto end_handle;

    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_REG_LOCK, HISI_KM_VALUE_UNLOCK); /* km_reg_cfg_keylock */
    switch (ctx->keytype) {
        case HISI_SYMM_KEYTYPE_USER:
            ret = reekm_reg_input_userkey(hdev, ctx);
            break;
            /* fall through, these keytype dont need config. */
        case HISI_SYMM_KEYTYPE_KDR:
        case HISI_SYMM_KEYTYPE_GID:
        case HISI_SYMM_KEYTYPE_RTL:
        case HISI_SYMM_KEYTYPE_POS:
        case HISI_SYMM_KEYTYPE_DERIVE:
        case HISI_SYMM_KEYTYPE_RTL1:
        case HISI_SYMM_KEYTYPE_CEK1:
        case HISI_SYMM_KEYTYPE_TAKEY:
        case HISI_SYMM_KEYTYPE_BUFFKEY:
        case HISI_SYMM_KEYTYPE_IMGKEY:
            ret = BSP_RET_OK;
            break;
        default:
            break;
    }
    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_REG_LOCK, HISI_KM_VALUE_LOCK); /* km_reg_cfg_keylock */
end_handle:
    hisi_reg_km_write(hdev, HISI_KM_OFF_REG_LOCK, HISI_KM_VALUE_LOCK); /* km_reg_cfg_lock */
    return ret;
}

static int reekm_reg_output_derivekey(struct hicrypto_device *hdev, unsigned char *pdout, unsigned int doutlen)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    unsigned int keymask = 0;

    if (!pdout)
        return BSP_RET_OK;

    /* 2. unlock key */
    reekm_reg_cfg_keylock(hdev, SEC_UNLOCK);

    /* 3. config keymask */
    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_MASK, keymask);

    /* 4. read from key reg */
    ret = hisi_reg_read_mask(ptr_add(ptr_to_ulong(hdev->km_base), HISI_KM_OFF_DERIVE_KEY_STR),
        SOC_REE_KM_DERIVEKEY_REGNUM,
        ptr_add(ptr_to_ulong(hdev->km_base), HISI_KM_OFF_DERIVE_KEY_PARITY),
        keymask,
        pdout,
        byte2word(doutlen),
        REE_KM_CFG_KEY_RANDOM_DELAY_CYCLES_MAX);
    if (pal_check(ret != BSP_RET_OK)) {
        goto out;
    }

out:
    /* 5. lock key */
    reekm_reg_cfg_keylock(hdev, SEC_LOCK);

    return ret;
}

int reekm_reg_chk_alarm(struct hicrypto_device *hdev)
{
    hisi_km_alarm_mask_union alarm;
    unsigned int regbak;

    reekm_reglock_save(hdev, &regbak);
    alarm.value = (unsigned int)hisi_reg_km_read(hdev, HISI_KM_OFF_ALARM_MASK);
    reekm_reglock_restore(hdev, regbak);
    if ((HISI_KM_REG_ALM_REGION & alarm.value) != HISI_KM_REG_ALM_EXPECT) {
        pal_error("kmalarm=%x\n", alarm.value);
        return err_drv(ERRCODE_ALARM);
    }
    return BSP_RET_OK;
}

static void reekm_reg_cfg_wrap_mode(struct hicrypto_device *hdev, unsigned int wrap_mode)
{
    hisi_km_wrap_mode_union wrap_mode_union;

    wrap_mode_union.value = hisi_reg_km_read(hdev, HISI_KM_OFF_WRAP_MODE);
    wrap_mode_union.reg.wrap_mode = wrap_mode;
    hisi_reg_km_write(hdev, HISI_KM_OFF_WRAP_MODE, wrap_mode_union.value);
}

static void reekm_reg_cfg_wrap_din_sel(struct hicrypto_device *hdev, unsigned int wrap_din_sel)
{
    hisi_km_wrap_din_sel_union wrap_din_sel_union;

    wrap_din_sel_union.value = hisi_reg_km_read(hdev, HISI_KM_OFF_WRAP_DIN_SEL);
    wrap_din_sel_union.reg.wrap_din_sel = wrap_din_sel;
    hisi_reg_km_write(hdev, HISI_KM_OFF_WRAP_DIN_SEL, wrap_din_sel_union.value);
}

static void reekm_reg_cfg_wrap_din_data_sel(struct hicrypto_device *hdev, unsigned int wrap_din_data_sel)
{
    hisi_km_sel_union key_sel_union;

    key_sel_union.value = hisi_reg_km_read(hdev, HISI_KM_OFF_KEY_SEL);
    key_sel_union.reg.km_derive_key_sel = wrap_din_data_sel;
    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_SEL, key_sel_union.value);
}

static void reekm_reg_cfg_wrap_key_sel(struct hicrypto_device *hdev, unsigned int wrap_key_sel)
{
    hisi_km_sel_union key_sel_union;

    key_sel_union.value = hisi_reg_km_read(hdev, HISI_KM_OFF_KEY_SEL);
    key_sel_union.reg.wrap_key_sel = wrap_key_sel;
    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_SEL, key_sel_union.value);
}

static void reekm_reg_cfg_key_buffer_waddr(struct hicrypto_device *hdev, unsigned int keybuff_waddr)
{
    hisi_km_key_buffer_waddr_union keybuff_waddr_union;

    keybuff_waddr_union.value = hisi_reg_km_read(hdev, HISI_KM_OFF_KEY_BUFFER_WADDR);
    keybuff_waddr_union.reg.key_buffer_waddr = keybuff_waddr;
    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_BUFFER_WADDR, keybuff_waddr_union.value);
}

static void reekm_reg_cfg_wrap_dinlen(struct hicrypto_device *hdev, unsigned int dinlen)
{
    hisi_km_wrap_din_len_union wrap_dinlen_union;

    wrap_dinlen_union.value = hisi_reg_km_read(hdev, HISI_KM_OFF_WRAP_DIN_LEN);
    wrap_dinlen_union.reg.wrap_din_len = reekm_reg_get_wrap_din_len(dinlen);
    hisi_reg_km_write(hdev, HISI_KM_OFF_WRAP_DIN_LEN, wrap_dinlen_union.value);
}

static void reekm_reg_cfg_drv_key_buff_data_sel(struct hicrypto_device *hdev, unsigned int keybuff_sel)
{
    hisi_km_key_ram_drv_data_sel_union data_sel_union;

    data_sel_union.value = hisi_reg_km_read(hdev, HISI_KM_OFF_KEY_RAM_DRV_DATA_SEL);
    data_sel_union.reg.drv_key_buff_data_sel = keybuff_sel;
    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_RAM_DRV_DATA_SEL, data_sel_union.value);
}

static void reekm_reg_cfg_key_drv_data_sel(struct hicrypto_device *hdev, unsigned int key_drv_sel)
{
    hisi_km_key_drv_data_sel_union drv_data_sel_union;

    drv_data_sel_union.value = hisi_reg_km_read(hdev, HISI_KM_OFF_KEY_DRV_DATA_SEL);
    drv_data_sel_union.reg.key_drv_data_sel = key_drv_sel;
    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_DRV_DATA_SEL, drv_data_sel_union.value);
}

static void reekm_reg_cfg_rootkey_lock(struct hicrypto_device *hdev)
{
    hisi_km_rt_key_change_lock_union change_lock_union;

    change_lock_union.value = hisi_reg_km_read(hdev, HISI_KM_OFF_RT_KEY_CHANGE_LOCK);
    change_lock_union.reg.km_rootkey_lock = SEC_LOCK;
    hisi_reg_km_write(hdev, HISI_KM_OFF_RT_KEY_CHANGE_LOCK, change_lock_union.value);
}

static void reekm_reg_cfg_key_inv_flag(struct hicrypto_device *hdev, unsigned int key_inv_flag)
{
    hisi_km_key_inv_flag_union key_inv_flag_union;

    key_inv_flag_union.value = hisi_reg_km_read(hdev, HISI_KM_OFF_KEY_INV_FLAG);
    key_inv_flag_union.reg.key_inv_flag = key_inv_flag;
    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_INV_FLAG, key_inv_flag_union.value);
}

static void reekm_reg_cfg_drv_kram_ram_addr(
    struct hicrypto_device *hdev, unsigned int kram_waddr, unsigned int kram_raddr)
{
    hisi_km_drv_key_ram_addr_union kram_addr_union;

    kram_addr_union.value = hisi_reg_km_read(hdev, HISI_KM_OFF_DRV_KEY_RAM_ADDR);
    kram_addr_union.reg.drv_kram_ram_waddr = kram_waddr;
    kram_addr_union.reg.drv_kram_ram_raddr = kram_raddr;
    hisi_reg_km_write(hdev, HISI_KM_OFF_DRV_KEY_RAM_ADDR, kram_addr_union.value);
}

static int reekm_reg_wait_wrap_done(struct hicrypto_device *hdev, unsigned int timeoutus)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    hisi_km_wrap_done_union wrap_done_value = {.value = 0};
    hisi_km_wrap_done_union wrap_done_mask = {.value = 0};
    unsigned int result;

    wrap_done_value.reg.wrap_done = REE_KM_REG_DONE;
    wrap_done_mask.reg.wrap_done = REE_KM_REG_DONE;
    ret = readl_relaxed_poll_timeout_atomic(ptr_add(ptr_to_ulong(hdev->km_base), HISI_KM_OFF_WRAP_DONE),
        result,
        ((result & wrap_done_mask.value) == wrap_done_value.value),
        HISI_REG_SLEEP_US,
        timeoutus);
    if (pal_check(ret != 0))
        return err_drv(ERRCODE_TIMEOUT);

    return BSP_RET_OK;
}

static int reekm_reg_wait_decrypt_done(struct hicrypto_device *hdev, unsigned int timeoutus)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    hisi_km_key_decry_done_union dec_done_value = {.value = 0};
    hisi_km_key_decry_done_union dec_done_mask = {.value = 0};
    unsigned int result;

    dec_done_value.reg.key_decry_done = REE_KM_REG_DONE;
    dec_done_mask.reg.key_decry_done = REE_KM_REG_DONE;

    ret = readl_relaxed_poll_timeout_atomic(ptr_add(ptr_to_ulong(hdev->km_base), HISI_KM_OFF_KEY_DECRY_DONE),
        result,
        ((result & dec_done_mask.value) == dec_done_value.value),
        HISI_REG_SLEEP_US,
        timeoutus);
    if (pal_check(ret != 0))
        return err_drv(ERRCODE_TIMEOUT);

    return BSP_RET_OK;
}

static void reekm_reg_clr_wrap_done(struct hicrypto_device *hdev)
{
    hisi_km_wrap_done_clr_union done = {.value = 0};

    done.reg.wrap_done_clr = REE_KM_REG_CLR;
    hisi_reg_km_write(hdev, HISI_KM_OFF_WRAP_DONE_CLR, done.value);
}

static void reekm_reg_clr_derive_key(struct hicrypto_device *hdev, unsigned int clr_key_sub_sel)
{
    hisi_km_derive_key_clr_union key_clr = {0};
    hisi_km_sel_union key_sel_union;

    key_sel_union.value = hisi_reg_km_read(hdev, HISI_KM_OFF_KEY_SEL);
    key_sel_union.reg.km_derive_key_sel = clr_key_sub_sel;
    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_SEL, key_sel_union.value);

    key_clr.reg.derive_key_clr = REE_KM_REG_CLR;
    hisi_reg_km_write(hdev, HISI_KM_OFF_DERIVE_KEY_CLR, key_clr.value);
}

static void reekm_reg_clr_buffer_key(struct hicrypto_device *hdev, unsigned int clr_key_sub_sel)
{
    hisi_km_buffer_key_clr_union key_clr = {0};
    hisi_km_sel_union key_sel_union;

    key_sel_union.value = hisi_reg_km_read(hdev, HISI_KM_OFF_KEY_SEL);
    key_sel_union.reg.km_key_buff_sel = clr_key_sub_sel;
    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_SEL, key_sel_union.value);

    key_clr.reg.buffer_key_clr = REE_KM_REG_CLR;
    hisi_reg_km_write(hdev, HISI_KM_OFF_BUFFER_KEY_CLR, key_clr.value);
}

static int reekm_reg_input_wrapkey(struct hicrypto_device *hdev, const unsigned char *pkey, unsigned int keylen)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    void *key_addr = ptr_add(ptr_to_ulong(hdev->km_base), HISI_KM_OFF_WRAPPING_KEY_DIN);
    void *key_bak_addr = ptr_add(ptr_to_ulong(hdev->km_base), HISI_KM_OFF_WRAPPING_KEY_PARITY);
    void *mask_addr = ptr_add(ptr_to_ulong(hdev->km_base), HISI_KM_OFF_WRAPPING_KEY_MASK);
    unsigned int keymask = 0;
    unsigned int key_wordnum;

    key_wordnum = byte2word(keylen);
    pal_write_u32(keymask, mask_addr);

    ret = hisi_reg_write_mask(key_addr,
        SOC_REE_SCE_WRAPKEY_REGNUM,
        key_bak_addr,
        keymask,
        pkey,
        key_wordnum,
        REE_KM_CFG_KEY_RANDOM_DELAY_CYCLES_MAX);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    return ret;
}

static int reekm_reg_input_key_drv_data(
    struct hicrypto_device *hdev, const unsigned char *key_drv_data, unsigned int len)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    unsigned int keymask = 0;
    unsigned int offset;
    unsigned int key_wordnum;
    void *regaddr = ptr_add(ptr_to_ulong(hdev->km_base), HISI_KM_OFF_KEY_DRV_DATA_ADDR);

    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_DRV_DATA_MASK, keymask);

    key_wordnum = byte2word(len);
    if (pal_check(key_wordnum > REE_KM_KEY_DRV_DATA_WORDNUM))
        return err_drv(ERRCODE_PARAMS);
    offset = ((unsigned int)(REE_KM_KEY_DRV_DATA_WORDNUM) - key_wordnum) * sizeof(unsigned int);

    ret = hisi_reg_write_mask_no_bakaddr(
        ptr_add(ptr_to_ulong(regaddr), offset), key_wordnum, keymask, key_drv_data, key_wordnum);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    return ret;
}

static int reekm_reg_input_wrap_data(struct hicrypto_device *hdev, const unsigned char *pdin, unsigned int dinlen)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    unsigned int keymask = 0;
    unsigned int key_wordnum;
    void *regaddr = ptr_add(ptr_to_ulong(hdev->km_base), HISI_KM_OFF_WRAP_DATA_IN_ADDR);
    void *bakaddr = ptr_add(ptr_to_ulong(hdev->km_base), HISI_KM_OFF_WRAP_DATA_IN_PARITY);

    if (!pdin)
        return BSP_RET_OK;

    hisi_reg_km_write(hdev, HISI_KM_OFF_WRAP_DATA_MASK, keymask);
    key_wordnum = byte2word(dinlen);

    ret = hisi_reg_write_mask(regaddr,
        REE_KM_WRAP_DATA_IN_WORDNUM,
        bakaddr,
        keymask,
        pdin,
        key_wordnum,
        REE_KM_CFG_KEY_RANDOM_DELAY_CYCLES_MAX);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    return ret;
}

static int reekm_reg_output_wrap_data(struct hicrypto_device *hdev, unsigned char *pdout, unsigned int doutlen)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    unsigned int keymask = 0;

    if (!pdout)
        return BSP_RET_OK;

    keymask = hisi_reg_km_read(hdev, HISI_KM_OFF_WRAP_DATA_MASK);
    ret = hisi_reg_read_mask(ptr_add(ptr_to_ulong(hdev->km_base), HISI_KM_OFF_WRAP_DATA_OUT_ADDR),
        REE_KM_WRAP_DATA_OUT_WORDNUM,
        ptr_add(ptr_to_ulong(hdev->km_base), HISI_KM_OFF_WRAP_DATA_OUT_PARITY),
        keymask,
        pdout,
        byte2word(doutlen),
        REE_KM_CFG_KEY_RANDOM_DELAY_CYCLES_MAX);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    return ret;
}

static void reekm_reg_cfg_export_key_sel(
    struct hicrypto_device *hdev, unsigned int export_din_sel, unsigned int export_din_data_sel)
{
    hisi_km_sel_union key_sel_union;
    key_sel_union.value = hisi_reg_km_read(hdev, HISI_KM_OFF_KEY_SEL);
    if (export_din_sel != HISI_KM_REG_KEYTYPE_KEYBUFF)
        key_sel_union.reg.key_din_sel = 0x10;
    else
        key_sel_union.reg.key_din_sel = 0x0;

    export_din_data_sel = export_din_data_sel & 0xF;
    key_sel_union.reg.key_din_sel += export_din_data_sel;
    hisi_reg_km_write(hdev, HISI_KM_OFF_KEY_SEL, key_sel_union.value);
}

/* km function */
static int reedrv_km_cpu_proc_one_block(struct hicrypto_device *hdev, const unsigned char *pdin, unsigned int dinlen)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    hisi_sce_str_run_union start_run = {.value = 0};

    ret = reekm_reg_input_key_drv_data(hdev, pdin, dinlen);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    start_run.reg.sce_run = 1;
    hisi_reg_sce_write(hdev, HISI_SCE_OFF_STR_RUN, start_run.value); /* sce_reg_run */
    ret = hisi_reg_sce_wait_busy(hdev, HISI_SCE_REG_STATE_BUSY, HISI_SCE_VALUE_IDLE, HISI_SCE_IDLE_CPU_START_TIMEOUT);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    return ret;
}

static int reedrv_km_cpu_proc_data(struct hicrypto_device *hdev, const unsigned char *prdin, unsigned int rlen)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    errno_t libc_ret = EINVAL;
    const enum hisi_symm_blklen blklen = HISI_SYMM_BLKLEN_AES; /* only support AES/SM4 algs */
    unsigned char buf[HISI_SYMM_BLKLEN_AES] = {0};             /* only support AES/SM4 algs */

    while (rlen >= blklen) {
        ret = reedrv_km_cpu_proc_one_block(hdev, prdin, blklen);
        if (pal_check(ret != BSP_RET_OK))
            return ret;

        prdin += blklen;
        rlen -= blklen;
    }

    if (rlen > 0) {
        libc_ret = memcpy_s(buf, sizeof(buf), prdin, rlen);
        if (pal_check(libc_ret != EOK))
            return err_drv(ERRCODE_MEMORY);
        ret = reedrv_km_cpu_proc_one_block(hdev, buf, sizeof(buf));
        if (pal_check(ret != BSP_RET_OK))
            return ret;
    }

    return ret;
}

void hidev_km_derive_init(
    struct hidev_km *pdrv_km, struct hidev_km_derive *pdrv_derive, unsigned int readable, unsigned int keytype)
{
    (void)memset_s(pdrv_km, sizeof(struct hidev_km), 0, sizeof(struct hidev_km));

    pdrv_derive->key_drv_sel = HISI_KEY_DRV_CPU_CFG_DATA;
    pdrv_derive->key_drv_data_sel = HISI_DERIVE_DATA_UNREAD_STR;
    if (readable == SEC_YES)
        pdrv_derive->kram_waddr = HISI_DERIVE_DATA_READABLE_STR;
    else
        pdrv_derive->kram_waddr = HISI_DERIVE_DATA_UNREAD_STR;
    pdrv_derive->kram_raddr = pdrv_derive->kram_waddr;

    pdrv_km->ip_idx = 0;
    pdrv_km->algorithm = HISI_CIPHER_ALGORITHM_AES;
    pdrv_km->mode = HISI_CIPHER_MODE_CMAC;
    pdrv_km->direction = HISI_SYMM_DIRECTION_ENCRYPT;
    pdrv_km->pkey = NULL;
    pdrv_km->keylen = HISI_SYMM_KEYLEN_32;
    pdrv_km->km_mode = HISI_KM_REG_KMMODE_DERIVE;
    pdrv_km->keytype = HISI_KM_REG_KEYTYPE_ROOTKEY;
    if (keytype == HISI_SYMM_KEYTYPE_KDR)
        pdrv_km->sub_keytype = HISI_KM_REG_ROOTKEY_KDR;
    else if (keytype == HISI_SYMM_KEYTYPE_GID)
        pdrv_km->sub_keytype = HISI_KM_REG_ROOTKEY_GID;
    else
        pdrv_km->sub_keytype = HISI_KM_REG_ROOTKEY_POS;

    pdrv_km->pextend = pdrv_derive;
}

static int reedrv_km_proc_derive_data(struct hicrypto_device *hdev, const struct hidev_km *pkm)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    struct hidev_km_derive *pdrv_derive = (struct hidev_km_derive *)pkm->pextend;
    hisi_sce_str_run_union start_run = {.value = 0};

    reekm_reg_cfg_drv_kram_ram_addr(hdev, pdrv_derive->kram_waddr, pdrv_derive->kram_raddr);
    reekm_reg_cfg_key_drv_data_sel(hdev, pdrv_derive->key_drv_sel);
    if (pdrv_derive->key_drv_sel == HISI_KEY_DRV_DERIVE_DATA)
        reekm_reg_cfg_drv_key_buff_data_sel(hdev, pdrv_derive->key_drv_data_sel);
    mb();
    start_run.reg.sce_str = 1;
    hisi_reg_sce_write(hdev, HISI_SCE_OFF_STR_RUN, start_run.value); /* sce_reg_start */
    ret = hisi_reg_sce_wait_busy(hdev, HISI_SCE_REG_STATE_BUSY, HISI_SCE_VALUE_IDLE, HISI_SCE_IDLE_CPU_START_TIMEOUT);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    if (pdrv_derive->key_drv_sel == HISI_KEY_DRV_DERIVE_DATA) {
        start_run.value = 0;
        start_run.reg.sce_run = 1;
        hisi_reg_sce_write(hdev, HISI_SCE_OFF_STR_RUN, start_run.value); /* sce_reg_run */
        ret =
            hisi_reg_sce_wait_busy(hdev, HISI_SCE_REG_STATE_BUSY, HISI_SCE_VALUE_IDLE, HISI_SCE_IDLE_CPU_START_TIMEOUT);
        if (pal_check(ret != BSP_RET_OK))
            return ret;
    } else {
        ret = reedrv_km_cpu_proc_data(hdev, pkm->pdin, pkm->dinlen);
        if (pal_check(ret != BSP_RET_OK))
            return ret;
    }

    ret = reekm_reg_wait_derive_done(hdev, REE_KM_DERIVE_DONE_TIMEOUTUS);
    if (pal_check(ret != BSP_RET_OK))
        return ret;
    reekm_reg_clr_derive_done(hdev);

    ret = reekm_reg_output_derivekey(hdev, pkm->pdout, pkm->doutlen);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    return ret;
}

static int reedrv_km_proc_keydec_data(struct hicrypto_device *hdev, const struct hidev_km *pkm)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    enum hisi_symm_blklen blklen;
    unsigned int rlen = pkm->dinlen;
    const unsigned char *prdin = pkm->pdin;
    struct hidev_km_deckey *pdrv_deckey = (struct hidev_km_deckey *)pkm->pextend;
    hisi_sce_str_run_union start_run = {.value = 0};

    if (pkm->km_mode == HISI_KM_REG_KMMODE_SCEKEY_DEC) {
        if (pal_check(pdrv_deckey == NULL))
            return err_drv(ERRCODE_NULL);
        reekm_reg_cfg_key_buffer_waddr(hdev, pdrv_deckey->keybuff_waddr);
    }
    mb();
    start_run.reg.sce_str = 1;
    hisi_reg_sce_write(hdev, HISI_SCE_OFF_STR_RUN, start_run.value); /* sce_reg_start */
    ret = hisi_reg_sce_wait_busy(
        hdev, HISI_SCE_REG_STATE_BUSY, HISI_SCE_VALUE_IDLE, HISI_SCE_IDLE_CPU_START_TIMEOUT); /* sce_reg_wait_idle */
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    blklen = hisi_reg_sce_get_blklen(hdev);
    if (pal_check(blklen == HISI_SYMM_BLKLEN_UNKNOWN))
        return err_drv(ERRCODE_READ);
    while (rlen >= blklen) {
        ret = hisi_reg_sce_input_din(hdev, prdin, blklen);
        if (pal_check(ret != BSP_RET_OK))
            return ret;

        start_run.value = 0;
        start_run.reg.sce_run = 1;
        hisi_reg_sce_write(hdev, HISI_SCE_OFF_STR_RUN, start_run.value); /* sce_reg_run */
        ret = hisi_reg_sce_wait_busy(hdev,
            HISI_SCE_REG_STATE_BUSY,
            HISI_SCE_VALUE_IDLE,
            HISI_SCE_IDLE_CPU_START_TIMEOUT); /* sce_reg_wait_idle */
        if (pal_check(ret != BSP_RET_OK))
            return ret;

        prdin += blklen;
        rlen -= blklen;
    }

    return ret;
}

void hidev_km_rtldec_init(struct hidev_km *pdrv_km)
{
    pdrv_km->ip_idx = 0;
    pdrv_km->algorithm = HISI_CIPHER_ALGORITHM_AES;
    pdrv_km->mode = HISI_CIPHER_MODE_CBC;
    pdrv_km->direction = HISI_SYMM_DIRECTION_DECRYPT;
    pdrv_km->pkey = NULL;
    pdrv_km->keylen = HISI_SYMM_KEYLEN_32;
    pdrv_km->km_mode = HISI_KM_REG_KMMODE_RTLDEC;
    pdrv_km->keytype = HISI_KM_REG_KEYTYPE_ROOTKEY;
    pdrv_km->sub_keytype = 0;
    pdrv_km->pdin = NULL; /* din is in efuse */
    pdrv_km->dinlen = HISI_SYMM_KEYLEN_32;
    pdrv_km->pdout = NULL; /* dout is in reg */
    pdrv_km->doutlen = HISI_SYMM_KEYLEN_32;
    pdrv_km->pivin = NULL;
    pdrv_km->ivinlen = 0;
    pdrv_km->pextend = NULL;
}

int hidev_km_rtldec_function(struct hicrypto_device *hdev)
{
    int ret;
    struct hidev_km km;

    hidev_km_rtldec_init(&km);

    km.sub_keytype = HISI_KM_REG_ROOTKEY_KDR;
    ret = hidev_km_function(hdev, &km);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    km.sub_keytype = HISI_KM_REG_ROOTKEY_GID;
    ret = hidev_km_function(hdev, &km);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    km.sub_keytype = HISI_KM_REG_ROOTKEY_POS;
    ret = hidev_km_function(hdev, &km);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    return ret;
}

static int reedrv_km_proc_rtldec_data(struct hicrypto_device *hdev, const struct hidev_km *pkm)
{
    int ret = err_drv(ERRCODE_UNKNOWN);

    unused(pkm);
    mb();
    reekm_reg_str(hdev);
    ret = reekm_reg_wait_decrypt_done(hdev, REE_KM_DERIVE_DONE_TIMEOUTUS);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    return ret;
}

#define REE_KEYWRAP_TAG_LEN 8
static int reedrv_km_proc_keywrap_data(struct hicrypto_device *hdev, const struct hidev_km *pkm)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    struct hidev_km_keywrap *pkeywrap = (struct hidev_km_keywrap *)pkm->pextend;

    /* bugfix for cpro mspe ree unwrap:
       dinlen/doutlen must be more than AES BLKLEN, even the data length is less than AES BLKLEN */
    hisi_reg_sce_write(hdev, HISI_SCE_OFF_RX_DAT_LEN, HISI_SYMM_BLKLEN_AES << 1); /* sce_reg_cfg_dinlen */
    hisi_reg_sce_write(hdev, HISI_SCE_OFF_TX_DAT_LEN, HISI_SYMM_BLKLEN_AES << 1); /* sce_reg_cfg_doutlen */

    if (pkm->keytype == HISI_KM_REG_KEYTYPE_CPU_WRAPKEY)
        reekm_reg_input_wrapkey(hdev, pkm->pkey, pkm->keylen);
    reekm_reg_cfg_wrap_mode(hdev, pkeywrap->wrap_mode);
    reekm_reg_cfg_wrap_din_sel(hdev, pkeywrap->wrap_din_sel);
    reekm_reg_cfg_wrap_key_sel(hdev, pkeywrap->wrap_key_sel);
    if (pkeywrap->wrap_mode == HISI_KM_REG_WRAPMODE_UNWRAP) {
        reekm_reg_cfg_key_buffer_waddr(hdev, pkeywrap->keybuff_waddr);
        reekm_reg_cfg_wrap_dinlen(hdev, pkm->dinlen - REE_KEYWRAP_TAG_LEN);
    } else {
        reekm_reg_cfg_wrap_dinlen(hdev, pkm->dinlen);
    }

    ret = reekm_reg_input_wrap_data(hdev, pkm->pdin, pkm->dinlen);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    if (pkeywrap->wrap_din_sel == HISI_KM_REG_WRAPDIN_SEL_HARD)
        reekm_reg_cfg_wrap_din_data_sel(hdev, pkeywrap->wrap_din_data_sel);
    mb();
    reekm_reg_str(hdev);
    reekm_reg_wait_wrap_done(hdev, REE_KM_WRAP_DONE_TIMEOUTUS);

    if (pkeywrap->wrap_mode == HISI_KM_REG_WRAPMODE_WRAP) {
        ret = reekm_reg_output_wrap_data(hdev, pkm->pdout, pkm->doutlen);
        if (pal_check(ret != BSP_RET_OK))
            return ret;
    }

    reekm_reg_clr_wrap_done(hdev);

    return ret;
}

static int reedrv_km_proc_keyexport_data(struct hicrypto_device *hdev, const struct hidev_km *pkm)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    unsigned int rlen = pkm->dinlen;
    struct hidev_km_keyexport *pkeyexport = (struct hidev_km_keyexport *)pkm->pextend;
    unsigned char *pdout = pkm->pdout;
    unsigned int offset = 0;
    hisi_sce_str_run_union start_run = {.value = 0};
    unsigned int regaddr, wordnum;

    while (rlen >= HISI_SYMM_BLKLEN_AES) {
        reekm_reg_cfg_export_key_sel(hdev, pkeyexport->export_din_sel, pkeyexport->export_din_data_sel + offset);
        if (offset == 0) {
            mb();
            start_run.reg.sce_str = 1;
            hisi_reg_sce_write(hdev, HISI_SCE_OFF_STR_RUN, start_run.value); /* sce_reg_start */
            ret = hisi_reg_sce_wait_busy(hdev,
                HISI_SCE_REG_STATE_BUSY,
                HISI_SCE_VALUE_IDLE,
                HISI_SCE_IDLE_CPU_START_TIMEOUT); /* sce_reg_wait_idle */
            if (pal_check(ret != BSP_RET_OK))
                return ret;
        }

        start_run.value = 0;
        start_run.reg.sce_run = 1;
        hisi_reg_sce_write(hdev, HISI_SCE_OFF_STR_RUN, start_run.value); /* sce_reg_run */
        ret = hisi_reg_sce_wait_busy(hdev,
            HISI_SCE_REG_STATE_BUSY,
            HISI_SCE_VALUE_IDLE,
            HISI_SCE_IDLE_CPU_START_TIMEOUT); /* sce_reg_wait_idle */
        if (pal_check(ret != BSP_RET_OK))
            return ret;

        hisi_reg_sce_get_doutreg(hdev, &regaddr, &wordnum);
        ret = hisi_reg_read(
            ptr_add(ptr_to_ulong(hdev->sce_base), regaddr), wordnum, pdout, byte2word(HISI_SYMM_BLKLEN_AES));
        if (pal_check(ret != BSP_RET_OK))
            return ret;

        rlen -= HISI_SYMM_BLKLEN_AES;
        pdout += HISI_SYMM_BLKLEN_AES;
        offset++;
    }

    return ret;
}

typedef int (*reedrv_km_proc_kmmode_data)(struct hicrypto_device *hdev, const struct hidev_km *pkm);
struct reedrv_km_proc_data_map {
    unsigned int km_mode;
    reedrv_km_proc_kmmode_data handler;
};

static struct reedrv_km_proc_data_map g_km_proc_data_map[] = {
    {HISI_KM_REG_KMMODE_DERIVE, reedrv_km_proc_derive_data},
    {HISI_KM_REG_KMMODE_RTLDEC, reedrv_km_proc_rtldec_data},
    {HISI_KM_REG_KMMODE_SCEKEY_DEC, reedrv_km_proc_keydec_data},
    {HISI_KM_REG_KMMODE_KEYWRAP, reedrv_km_proc_keywrap_data},
    {HISI_KM_REG_KMMODE_KEYEXPORT, reedrv_km_proc_keyexport_data},
};

static int reedrv_km_proc_data(struct hicrypto_device *hdev, const struct hidev_km *pkm)
{
    int i, map_num;

    map_num = ARRAY_SIZE(g_km_proc_data_map);
    for (i = 0; i < map_num; i++) {
        if (g_km_proc_data_map[i].km_mode == pkm->km_mode)
            return g_km_proc_data_map[i].handler(hdev, pkm);
    }

    return err_drv(ERRCODE_UNKNOWN);
}

static int reedrv_km_config_param(struct hicrypto_device *hdev, const struct hidev_km *pkm)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    hisi_sce_mode_union sce_mode = {0};
    hisi_sce_cfg_union sce_cfg = {0};

    reekm_reg_cfg_kmmode(hdev, pkm->km_mode);
    ret = reekm_reg_cfg_keytype(hdev, pkm->keytype, pkm->sub_keytype);
    if (pal_check(ret != BSP_RET_OK))
        return ret;
    /* sce_reg_cfg_amdk */
    ret = hisi_reg_sce_cfg_amdk(hdev, pkm->algorithm, pkm->mode, pkm->direction, HISI_SYMM_KEYTYPE_USER, pkm->keylen);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    /* rx tx mode sce_reg_cfg_rxtxmode */
    sce_mode.value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_MODE);
    sce_mode.reg.sce_rx_dma_mode = HISI_SYMM_TRANSFER_CPU;
    sce_mode.reg.sce_tx_dma_mode = HISI_SYMM_TRANSFER_CPU;
    hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_MODE, sce_mode.value);

    hisi_reg_sce_write(hdev, HISI_SCE_OFF_RX_DAT_LEN, pkm->dinlen);  /* sce_reg_cfg_dinlen */
    hisi_reg_sce_write(hdev, HISI_SCE_OFF_TX_DAT_LEN, pkm->doutlen); /* sce_reg_cfg_doutlen */
    ret = hisi_reg_sce_input_ivin(hdev, pkm->pivin, pkm->ivinlen);
    if (pal_check(ret != BSP_RET_OK))
        return ret;

    hisi_reg_sce_write(hdev, HISI_SCE_OFF_PADDING_EN, HISI_SCE_REG_PADDING_ENABLE);

    sce_cfg.value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_SCE_CFG);
    sce_cfg.reg.sce_padding_sel = HISI_SCE_REG_PADMODE_80;
    hisi_reg_sce_write(hdev, HISI_SCE_OFF_SCE_CFG, sce_cfg.value);
    return ret;
}

static int reedrv_km_entry(struct hicrypto_device *hdev, unsigned int alg)
{
    int ret = err_drv(ERRCODE_UNKNOWN);

    unused(alg);
    hisi_reg_sce_write(hdev, HISI_SCE_OFF_REG_LOCK, HISI_SCE_VALUE_UNLOCK); /* sce_reg_cfg_lock */
    ret = hisi_reg_sce_wait_busy(hdev, HISI_SCE_REG_STATE_BUSY, HISI_SCE_VALUE_IDLE, HISI_SCE_IDLE_ENTRY_TIMEOUT);
    if (pal_check(ret != BSP_RET_OK)) {
        pal_error("sce_reg_wait_idle failed\n");
        return ret;
    }

    reekm_reg_cfg_lock(hdev, SEC_UNLOCK);
    reekm_reg_cfg_keylock(hdev, SEC_UNLOCK);

    return ret;
}

static int reedrv_km_exit(struct hicrypto_device *hdev, unsigned int alg)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    unsigned int value;

    unused(alg);
    value = hisi_reg_sce_read(hdev, HISI_SCE_OFF_ALARM_MASK);
    if ((HISI_SCE_REG_ALARM_REGION & value) != 0)
        pal_error("alarm.value = %x\n", value);

    ret = reekm_reg_chk_alarm(hdev);
    if (pal_check(ret != BSP_RET_OK))
        goto out;

out:
    hisi_reg_sce_write(hdev, HISI_SCE_OFF_REG_LOCK, HISI_SCE_VALUE_LOCK); /* sce_reg_cfg_unlock */
    reekm_reg_cfg_keylock(hdev, SEC_LOCK);
    reekm_reg_cfg_lock(hdev, SEC_LOCK);

    return ret;
}

int hidev_km_function(struct hicrypto_device *hdev, const struct hidev_km *pkm)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    int exit_ret = err_drv(ERRCODE_UNKNOWN);

    ret = reedrv_km_entry(hdev, pkm->algorithm);
    if (pal_check(ret != BSP_RET_OK))
        goto end_handle;

    ret = reedrv_km_config_param(hdev, pkm);
    if (pal_check(ret != BSP_RET_OK))
        goto end_handle;

    ret = reedrv_km_proc_data(hdev, pkm);
    if (pal_check(ret != BSP_RET_OK))
        goto end_handle;

end_handle:
    exit_ret = reedrv_km_exit(hdev, pkm->algorithm);
    return ret == BSP_RET_OK ? exit_ret : ret;
}

static int reedrv_km_do_clear_key(struct hicrypto_device *hdev, unsigned int clr_key_sel, unsigned int clr_key_sub_sel)
{
    unsigned int lockbak;
    /* save and reset to unlock */
    reekm_reglock_save(hdev, &lockbak);

    switch (clr_key_sel) {
        case HISI_KM_CLR_DERIVE_KEY:
            reekm_reg_clr_derive_key(hdev, clr_key_sub_sel);
            break;
        case HISI_KM_CLR_BUFFER_KEY:
            reekm_reg_clr_buffer_key(hdev, clr_key_sub_sel);
            break;
        default:
            break;
    }

    /* restore lock status */
    reekm_reglock_restore(hdev, lockbak);
    return BSP_RET_OK;
}

static int reedrv_km_clear_key(struct hicrypto_device *hdev, unsigned int clr_key_sel, unsigned int clr_key_sub_sel)
{
    int ret = err_drv(ERRCODE_UNKNOWN);

    ret = reedrv_km_do_clear_key(hdev, clr_key_sel, clr_key_sub_sel);
    return ret;
}

int hidev_km_clear_bufferkey_by_slot(struct hicrypto_device *hdev, unsigned int unread_str, unsigned int unread_end)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    unsigned int i;

    if (pal_check(unread_str > HISI_DERIVE_DATA_UNREAD_END))
        return err_drv(ERRCODE_PARAMS);

    if (pal_check(unread_end > HISI_DERIVE_DATA_UNREAD_END))
        return err_drv(ERRCODE_PARAMS);

    if (pal_check(unread_str > unread_end))
        return err_drv(ERRCODE_PARAMS);

    for (i = unread_str; i <= unread_end; i++) {
        ret = reedrv_km_clear_key(hdev, HISI_KM_CLR_BUFFER_KEY, i);
        if (pal_check(ret != BSP_RET_OK))
            return ret;
    }
    return ret;
}

int hidev_km_clear_derive_key(struct hicrypto_device *hdev)
{
    int ret = err_drv(ERRCODE_UNKNOWN);
    unsigned int i;

    for (i = HISI_DERIVE_DATA_UNREAD_STR; i <= HISI_DERIVE_DATA_UNREAD_END; i++) {
        ret = reedrv_km_clear_key(hdev, HISI_KM_CLR_DERIVE_KEY, i);
        if (pal_check(ret != BSP_RET_OK))
            return ret;
    }

    return ret;
}

int hidev_km_clear_derive_key_by_id(struct hicrypto_device *hdev, unsigned int key_sel)
{
	if (pal_check(key_sel > (HISI_DERIVE_DATA_UNREAD_END - HISI_DERIVE_DATA_UNREAD_STR)))
		return err_drv(ERRCODE_PARAMS);
	return reedrv_km_do_clear_key(hdev, HISI_KM_CLR_DERIVE_KEY, key_sel + HISI_DERIVE_DATA_UNREAD_STR);
}

void hidev_km_wrap_init(struct hidev_km *pdrv_km, struct hidev_km_keywrap *pdrv_wrap)
{
    (void)memset_s(pdrv_km, sizeof(struct hidev_km), 0, sizeof(struct hidev_km));

    pdrv_wrap->wrap_din_sel = HISI_KM_REG_WRAPDIN_SEL_CPU;
    pdrv_wrap->wrap_din_data_sel = HISI_DERIVE_DATA_UNREAD_STR;
    pdrv_wrap->wrap_key_sel = HISI_KM_REG_AO_WRAPKEY_REE;

    pdrv_km->ip_idx = 0;
    pdrv_km->algorithm = HISI_CIPHER_ALGORITHM_AES;
    pdrv_km->mode = HISI_CIPHER_MODE_ECB;
    pdrv_km->direction = HISI_SYMM_DIRECTION_ENCRYPT;

    pdrv_km->km_mode = HISI_KM_REG_KMMODE_KEYWRAP;

    pdrv_km->pkey = NULL;
    pdrv_km->keytype = HISI_KM_REG_KEYTYPE_AO_WRAPKEY;
    pdrv_km->sub_keytype = HISI_KM_REG_ROOTKEY_KDR;
    pdrv_km->ivinlen = HISI_SYMM_IVLEN_AES;

    pdrv_km->pextend = pdrv_wrap;
}

void hidev_km_export_init(struct hidev_km *pdrv_km, struct hidev_km_keyexport *pdrv_export)
{
    (void)memset_s(pdrv_km, sizeof(struct hidev_km), 0, sizeof(struct hidev_km));

    pdrv_km->ip_idx = 0;
    pdrv_km->algorithm = HISI_CIPHER_ALGORITHM_AES;
    pdrv_km->mode = HISI_CIPHER_MODE_CBC;
    pdrv_km->direction = HISI_SYMM_DIRECTION_ENCRYPT;

    pdrv_km->km_mode = HISI_KM_REG_KMMODE_KEYEXPORT;

    pdrv_km->pkey = NULL;
    pdrv_km->keytype = HISI_KM_REG_KEYTYPE_AO_WRAPKEY;
    pdrv_km->sub_keytype = HISI_KM_REG_ROOTKEY_KDR;
    pdrv_km->ivinlen = HISI_SYMM_IVLEN_AES;

    pdrv_km->pextend = pdrv_export;
}

int hidev_km_reg_set_derive_subkey(unsigned int subkey)
{
    if (pal_check(subkey > HISI_DERIVE_DATA_UNREAD_END))
        return err_drv(ERRCODE_UNSUPPORT);

    g_ktype_map[HISI_SYMM_KEYTYPE_DERIVE].km_reg_sub_ktype = subkey;
    return BSP_RET_OK;
}

int hidev_km_reg_set_buff_subkey(unsigned int subkey)
{
    if (pal_check(subkey > HISI_KEY_BUFF_DATA_END))
        return err_drv(ERRCODE_UNSUPPORT);

    g_ktype_map[HISI_SYMM_KEYTYPE_BUFFKEY].km_reg_sub_ktype = subkey;
    return BSP_RET_OK;
}

void hidev_km_reg_cfg_key_inv_flag(struct hicrypto_device *hdev, unsigned int key_inv_flag)
{
    unsigned int lockbak;

    reekm_reglock_save(hdev, &lockbak);
    reekm_reg_cfg_key_inv_flag(hdev, key_inv_flag);
    reekm_reglock_restore(hdev, lockbak);
}