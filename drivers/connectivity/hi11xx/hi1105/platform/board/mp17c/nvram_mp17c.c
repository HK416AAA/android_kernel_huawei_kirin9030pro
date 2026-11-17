/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: manage the efuse information that needs to be saved to nv
 * Author: platform drivers
 */

#include "plat_debug.h"
#include "hisi_conn_nve.h"
#include "nve_info_interface.h"
#include "hisi_conn_nve.h"
#include "plat_nvram.h"
#include "nvram_mp17c.h"

#ifdef HISI_NVRAM_SUPPORT

#define EFUSE_FT_RPG_VER_BIT_START         143
#define EFUSE_FT_RPG_VER_BIT_LEN           6
#define EFUSE_PMU_VBG_SETUP_TIME_BIT_START 266
#define EFUSE_PMU_VBG_SETUP_TIME_BIT_LEN   12
#define EFUSE_DIEID1_START                 0
#define EFUSE_DIEID1_LEN                   32
#define EFUSE_DIEID2_START                 32
#define EFUSE_DIEID2_LEN                   32
#define EFUSE_DIEID3_START                 64
#define EFUSE_DIEID3_LEN                   32
#define EFUSE_DIEID4_START                 96
#define EFUSE_DIEID4_LEN                   32
#define EFUSE_DIEID5_START                 128
#define EFUSE_DIEID5_LEN                   16


typedef struct {
    mp17c_nv_efuse_enum type;
    uint16_t bit_start;
    uint16_t bit_len;
} mp17c_nv_efuse_info_stru;

static mp17c_nv_efuse_info_stru g_conn_nve_efuse_info_mp17c[MP17C_NVRAM_EFUSE_BUTT] = {
    {MP17C_NVRAM_EFUSE_VER,      EFUSE_FT_RPG_VER_BIT_START,         EFUSE_FT_RPG_VER_BIT_LEN},
    {MP17C_NVRAM_EFUSE_VBG_TIME, EFUSE_PMU_VBG_SETUP_TIME_BIT_START, EFUSE_PMU_VBG_SETUP_TIME_BIT_LEN},
    {MP17C_NVRAM_EFUSE_CRC,      0,                                  0},   // 非efuse信息
    {MP17C_NVRAM_EFUSE_DIEID1,   EFUSE_DIEID1_START,                 EFUSE_DIEID1_LEN},
    {MP17C_NVRAM_EFUSE_DIEID2,   EFUSE_DIEID2_START,                 EFUSE_DIEID2_LEN},
    {MP17C_NVRAM_EFUSE_DIEID3,   EFUSE_DIEID3_START,                 EFUSE_DIEID3_LEN},
    {MP17C_NVRAM_EFUSE_DIEID4,   EFUSE_DIEID4_START,                 EFUSE_DIEID4_LEN},
    {MP17C_NVRAM_EFUSE_DIEID5,   EFUSE_DIEID5_START,                 EFUSE_DIEID5_LEN},
};

static int32_t update_nv_efuse_item(uint16_t *efuse_buff, uint32_t *nv_buff,
                                    nvram_field_enum *efuse_item, uint8_t item_num)
{
    size_t loop;
    uint8_t item;
    uint32_t value;
    uint16_t bit_loop;
    uint16_t idx;
    uint16_t offset;
    uint32_t bit_value;

    for (loop = 0; loop < item_num; loop++) {
        value = 0;

        item = efuse_item[loop];
        if (item >= MP17C_NVRAM_EFUSE_BUTT) {
            ps_print_err("efuse item is overflow, type: %d, max_type: %d", item, MP17C_NVRAM_EFUSE_BUTT);
            return -CONN_NVE_ERROR_NO_PART;
        }

        if (g_conn_nve_efuse_info_mp17c[item].type == MP17C_NVRAM_EFUSE_CRC) {
            value = crc32c_conn_nve(CRC32C_REV_SEED, (uint8_t *)nv_buff, MP17C_NVRAM_EFUSE_CRC * sizeof(uint32_t));
        } else {
            for (bit_loop = 0; bit_loop < g_conn_nve_efuse_info_mp17c[item].bit_len; bit_loop++) {
                idx = (g_conn_nve_efuse_info_mp17c[item].bit_start + bit_loop) / (NUM_2_BYTES * OAL_BITS_PER_BYTE);
                offset = (g_conn_nve_efuse_info_mp17c[item].bit_start + bit_loop) % (NUM_2_BYTES * OAL_BITS_PER_BYTE);
                bit_value = oal_get_bits(*(efuse_buff + idx), 1, offset);
                value += (bit_value << bit_loop);
            }
            ps_print_info("save efuse bit begin[%u], len[%u], value[%#x]",
                g_conn_nve_efuse_info_mp17c[item].bit_start, g_conn_nve_efuse_info_mp17c[item].bit_len, value);
        }
        nv_buff[item] = value;
    }

    return CONN_NVE_RET_OK;
}

/**
 * @brief 读取nv保存的所有efuse字段。
 * @param  [out]           nv_buff 存储nv内容的buffer指针。
 * @param  [in]            buff_byte_len 存储nv内容的buffer字节长度。
 * @retval CONN_NVE_RET_OK Success。
 * @retval Other           参考 @ref hisi_conn_ret。
 */
int32_t conn_nve_read_efuse_mp17c(uint32_t *nv_buff, uint16_t buff_byte_len)
{
    int32_t ret;
    struct external_nve_info_user info;

    if (nv_buff == NULL) {
        ps_print_err("nv buff is null");
        return -CONN_NVE_ERROR_READ;
    }

    if (buff_byte_len > PLAT_NVRAM_SIZE) {
        ps_print_err("read length is more than %d", PLAT_NVRAM_SIZE);
        return -CONN_NVE_ERROR_OVERSIZE;
    }

    memset_s(&info, sizeof(struct external_nve_info_user), 0, sizeof(struct external_nve_info_user));
    info.nv_operation = NV_READ;
    info.valid_size = (uint32_t)buff_byte_len;
    info.nv_number = PLAT_NVRAM_ID;
    ret = external_nve_direct_access_interface(&info);
    if (ret != CONN_NVE_RET_OK) {
        ps_print_err("read efuse nv failed, ret: %d", ret);
        return -CONN_NVE_ERROR_READ;
    }

    if (memcpy_s(nv_buff, buff_byte_len, info.nv_data, buff_byte_len) != EOK) {
        ps_print_err("copy data failed");
        return -CONN_NVE_ERROR_READ;
    }

    return CONN_NVE_RET_OK;
}

/**
 * @brief 保存特定的efuse字段到nv里。
 * @param [in]             efuse_buff 存储efuse内容的buffer指针。
 * @param [in]             efuse_item 要保存的efuse字段数组，从 @ref mp17c_nv_efuse_enum中选择。
 * @param [in]             item_num 要保存的efuse字段数量。
 * @retval CONN_NVE_RET_OK Success。
 * @retval Other           参考 @ref hisi_conn_ret。
 */
int32_t conn_nve_write_efuse_mp17c(uint16_t *efuse_buff, nvram_field_enum *efuse_item, uint8_t item_num)
{
    struct external_nve_info_user info;
    int32_t ret;
    uint32_t *nv_buff = (uint32_t *)info.nv_data;
    uint32_t crc;

    if (efuse_buff == NULL || efuse_item == NULL) {
        ps_print_err("efuse buff or efuse item is null");
        return -CONN_NVE_ERROR_WRITE;
    }

    memset_s(&info, sizeof(struct external_nve_info_user), 0, sizeof(struct external_nve_info_user));
    ret = conn_nve_read_efuse_mp17c(nv_buff, PLAT_NVRAM_SIZE);
    if (ret != CONN_NVE_RET_OK) {
        return ret;
    }

    ret = update_nv_efuse_item(efuse_buff, nv_buff, efuse_item, item_num);
    if (ret != CONN_NVE_RET_OK) {
        return ret;
    }

    crc = crc32c_conn_nve(CRC32C_REV_SEED, (uint8_t *)nv_buff, PLAT_NVRAM_SIZE - (uint16_t)sizeof(uint32_t));
    nv_buff[MP17C_NVRAM_EFUSE_TOTAL_CRC] = crc;

    if (strcpy_s(info.nv_name, sizeof(info.nv_name), PLAT_NVRAM_NAME) != EOK) {
        ps_print_err("strcpy nv name fail");
        return -CONN_NVE_ERROR_WRITE;
    }
    info.nv_name[sizeof(info.nv_name) - 1] = '\0';
    info.nv_number = PLAT_NVRAM_ID;
    info.valid_size = PLAT_NVRAM_SIZE;
    info.nv_operation = NV_WRITE;

    ret = external_nve_direct_access_interface(&info);
    if (ret != CONN_NVE_RET_OK) {
        ps_print_err("write efuse nv failed, ret: %d", ret);
        return -CONN_NVE_ERROR_WRITE;
    }
    return CONN_NVE_RET_OK;
}

/**
 * @brief 保存efuse字段中的dieid内容到nv里，dieid起始位置及长度在本函数内定义。
 * @param [in]             efuse_buff 存储efuse内容的buffer指针，其中包含dieid。
 * @retval CONN_NVE_RET_OK Success。
 * @retval Other           参考 @ref hisi_conn_ret。
 */
int32_t conn_nve_write_dieid_mp17c(uint16_t *efuse_buff)
{
    int32_t ret;
    uint32_t efuse_save_item[] = {MP17C_NVRAM_EFUSE_DIEID1, MP17C_NVRAM_EFUSE_DIEID2, MP17C_NVRAM_EFUSE_DIEID3,
                                  MP17C_NVRAM_EFUSE_DIEID4, MP17C_NVRAM_EFUSE_DIEID5};
    
    ret = conn_nve_write_efuse_mp17c(efuse_buff, efuse_save_item, sizeof(efuse_save_item) / sizeof(uint32_t));
    if (ret != CONN_NVE_RET_OK) {
        ps_print_err("write dieid to nv failed, ret: %d", ret);
        return ret;
    }

    return CONN_NVE_RET_OK;
}

/**
 * @brief 读取nv保存的所有dieid字段，dieid起始位置及长度在本函数内定义。
 * @param  [out]           dieid_buff 存储dieid内容的buffer指针。
 * @param  [in]            buff_byte_len 存储dieid内容的buffer字节长度。
 * @retval CONN_NVE_RET_OK Success。
 * @retval Other           参考 @ref hisi_conn_ret。
 */
int32_t conn_nve_read_dieid_mp17c(uint16_t *dieid_buff, uint16_t buff_byte_len)
{
    int32_t ret;
    uint32_t crc;
    uint32_t nv_data[NVRAM_FIELD_BUTT] = {0};
    uint8_t dieid_len = (uint8_t)((MP17C_NVRAM_EFUSE_DIEID5 - MP17C_NVRAM_EFUSE_DIEID1 + 1) * sizeof(uint32_t));

    ret = conn_nve_read_efuse_mp17c(nv_data, sizeof(nv_data));
    if (ret != CONN_NVE_RET_OK) {
        ps_print_err("read efuse from nv failed, ret: %d", ret);
        return ret;
    }

    crc = crc32c_conn_nve(CRC32C_REV_SEED, (uint8_t *)nv_data, (NVRAM_FIELD_BUTT - 1) * sizeof(uint32_t));
    if (crc != nv_data[MP17C_NVRAM_EFUSE_TOTAL_CRC]) {
        ps_print_err("efuse total crc check fail");
        return CONN_NVE_ERROR_READ;
    }

    if (memcpy_s(dieid_buff, buff_byte_len, nv_data + MP17C_NVRAM_EFUSE_DIEID1, dieid_len) != EOK) {
        ps_print_err("memcpy dieid fail");
        return CONN_NVE_ERROR_READ;
    }

    return CONN_NVE_RET_OK;
}

void nvram_ops_init_mp17c(void)
{
    plat_nvram_ops_stru *nvram_ops = get_plat_nvram_ops();
    if (nvram_ops == NULL) {
        return;
    }

    nvram_ops->read_nvram = conn_nve_read_efuse_mp17c;
    nvram_ops->write_nvram = NULL;
    nvram_ops->write_efuse_to_nvram = conn_nve_write_efuse_mp17c;
    nvram_ops->read_dieid_from_nvram = conn_nve_read_dieid_mp17c;
    nvram_ops->write_dieid_to_nvram = conn_nve_write_dieid_mp17c;
}

#endif
