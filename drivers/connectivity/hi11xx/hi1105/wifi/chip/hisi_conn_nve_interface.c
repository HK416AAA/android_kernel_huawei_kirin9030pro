/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明   : mp16产测pow\rssi\dpd校准NV接口实现
 * 作者       : wifi
 * 创建日期   : 2020年12月8日
 */
#ifdef HISI_CONN_NVE_SUPPORT
#include "hisi_conn_nve_interface.h"
#include "oal_util.h"
#include "securec.h"
#include "external/nve_info_interface.h"
#ifdef _PRE_CONFIG_READ_DYNCALI_E2PROM
#ifdef CONFIG_ARCH_PLATFORM
#define nve_direct_access_interface(...)  0
#else
#define hisi_nve_direct_access(...)  0
#endif /* end for CONFIG_ARCH_PLATFORM */
#endif /* end for _PRE_CONFIG_READ_DYNCALI_E2PROM */
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HISI_CONN_NVE_INTERFACE_C

#define POW_TYPE_2G_11B_FLAG         BIT0
#define POW_TYPE_2G_OFEM_20_FLAG     BIT1
#define POW_TYPE_2G_OFEM_40_FLAG     BIT2
#define POW_TYPE_5G_20_FLAG          BIT3
#define POW_TYPE_5G_40_FLAG          BIT4
#define POW_TYPE_5G_80_FLAG          BIT5
#define POW_TYPE_5G_160_FLAG         BIT6
#define POW_TYPE_5G_ALL_FLAG         (POW_TYPE_5G_20_FLAG | POW_TYPE_5G_40_FLAG | \
                                      POW_TYPE_5G_80_FLAG | POW_TYPE_5G_160_FLAG)
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
#define POW_TYPE_6G_20_FLAG          BIT7
#define POW_TYPE_6G_40_FLAG          BIT8
#define POW_TYPE_6G_80_FLAG          BIT9
#define POW_TYPE_6G_160_FLAG         BIT10
#endif
#define POW_TYPE_2G_ALL_NUM          3
#define POW_TYPE_5G_ALL_NUM          4
#define POW_TYPE_TOTAL_NUM           11

#define BAND_TYPE_2G_ALL_FLAG        0x1FFF
#define BAND_TYPE_5G_BAND0_FLAG      BIT0
#define BAND_TYPE_5G_BAND1_FLAG      BIT1
#define BAND_TYPE_5G_BAND2_FLAG      BIT2
#define BAND_TYPE_5G_BAND3_FLAG      BIT3
#define BAND_TYPE_5G_BAND4_FLAG      BIT4
#define BAND_TYPE_5G_BAND5_FLAG      BIT5
#define BAND_TYPE_5G_BAND6_FLAG      BIT6

#define WAL_TAS_VERSION_3_0          0xFFFF0300
#ifdef CONFIG_IODIE_HKADC
#define CONN_NVE_VALID_DATA_FLAG_OFFSET 0x18
#define CONN_NVE_VALID_DATA_ALL_MASK    3
#endif
typedef union {
    struct {
        uint32_t pow_type : 11;   /*  0:10 */
        uint32_t band_type : 15;  /* 11:25 */
        uint32_t reserved : 6;    /* 26:31 */
    } bits;
    uint32_t dword;
} powcal_map_flag;

typedef struct {
    powcal_map_flag flag;
    int8_t cali_data[WICAL_STREAM_NUM][WICAL_POW_CAL_LVL_NUM];
} powcal_nv_data;

typedef enum {
    CALI_DATA_NV_TYPE_NVBLOCK = 0,
    CALI_DATA_NV_TYPE_NVRAM,
    CALI_DATA_NV_TYPE_BUTT,
} cali_data_nv_type;

/* 全局变量定义 */
static struct semaphore g_nv_sem;
static conn_nve_ramdisk_stru g_conn_nve_struct;
static conn_nve_tas_particion_stru g_conn_tas_powcal_nvram;
static int g_hisi_sync_ramdisk_done = 0;
static uint8_t g_hisi_nve_available_page = 0;
static cali_data_nv_type g_cali_data_nv_type = CALI_DATA_NV_TYPE_NVBLOCK;

powcal_nv_data g_powcal_nv_data[] = {
    {.flag.dword = POW_TYPE_2G_11B_FLAG | oal_left_shift(BAND_TYPE_2G_ALL_FLAG, POW_TYPE_TOTAL_NUM)},
    {.flag.dword = POW_TYPE_2G_OFEM_20_FLAG | oal_left_shift(BAND_TYPE_2G_ALL_FLAG, POW_TYPE_TOTAL_NUM)},
    {.flag.dword = POW_TYPE_2G_OFEM_40_FLAG | oal_left_shift(BAND_TYPE_2G_ALL_FLAG, POW_TYPE_TOTAL_NUM)},
    {.flag.dword = POW_TYPE_5G_ALL_FLAG | oal_left_shift(BAND_TYPE_5G_BAND0_FLAG, POW_TYPE_TOTAL_NUM)},
    {.flag.dword = POW_TYPE_5G_ALL_FLAG |
                   oal_left_shift(BAND_TYPE_5G_BAND1_FLAG | BAND_TYPE_5G_BAND2_FLAG, POW_TYPE_TOTAL_NUM)},
    {.flag.dword = POW_TYPE_5G_ALL_FLAG |
                   oal_left_shift(BAND_TYPE_5G_BAND3_FLAG | BAND_TYPE_5G_BAND4_FLAG, POW_TYPE_TOTAL_NUM)},
    {.flag.dword = POW_TYPE_5G_ALL_FLAG | oal_left_shift(BAND_TYPE_5G_BAND5_FLAG, POW_TYPE_TOTAL_NUM)},
    {.flag.dword = POW_TYPE_5G_ALL_FLAG | oal_left_shift(BAND_TYPE_5G_BAND6_FLAG, POW_TYPE_TOTAL_NUM)},
};

void set_cali_data_nv_type(uint8_t type)
{
    if (type >= CALI_DATA_NV_TYPE_BUTT) {
        pr_warn("[CONN_NVE]:%s cali data nv type is wrong[%d]\n", __func__, type);
        return;
    }
    pr_info("[CONN_NVE]:%s set cali data nv type[%d]\n", __func__, type);
    g_cali_data_nv_type = type;
}

static int32_t conn_nve_read_from_nvblock(void)
{
    uint32_t tmp_crc;
    uint32_t age_max = 0;
    int up_to_date_idx = -1;
    int i;

    g_hisi_nve_available_page = 0;
    // read hisi_conn_nve from nvblock
    for (i = 0; i < CONN_NVE_IMG_NUM; i++) {
        if (hisi_conn_nve_read(HISI_CONN_WIFI_DATA, conn_nve_start_addr(i), sizeof(conn_nve_particion_stru),
            (u_char*)g_conn_nve_struct.conn_nve_ramdisk) != CONN_NVE_RET_OK) {
            continue;
        }
        // check data crc
        tmp_crc = crc32c_conn_nve(CRC32C_REV_SEED,
            (uint8_t*)g_conn_nve_struct.conn_nve_ramdisk, CONN_NVE_PARTICION_SIZE);
        if (tmp_crc != g_conn_nve_struct.conn_nve_ramdisk->crc) {
            pr_err("[CONN_NVE]:%s img[%d] crc check failure, new_crc is 0x%X, old_crc is 0x%X!\n", __func__, i,
                tmp_crc, g_conn_nve_struct.conn_nve_ramdisk->crc);
            continue;
        }
        g_hisi_nve_available_page |= (0x1 << i);
        // compare age, select newest img
        if (g_conn_nve_struct.conn_nve_ramdisk->age >= age_max) {
            age_max = g_conn_nve_struct.conn_nve_ramdisk->age;
            up_to_date_idx = i;
        }
    }
    // read newest data to ram
    if (up_to_date_idx == -1 || hisi_conn_nve_read(HISI_CONN_WIFI_DATA, conn_nve_start_addr(up_to_date_idx), \
        sizeof(conn_nve_particion_stru), (u_char*)g_conn_nve_struct.conn_nve_ramdisk) != CONN_NVE_RET_OK) {
        pr_err("[CONN_NVE]:%s faild due to read error!\n", __func__);
        return -CONN_NVE_ERROR_READ;
    }
    // check data crc
    tmp_crc = crc32c_conn_nve(CRC32C_REV_SEED, (uint8_t*)g_conn_nve_struct.conn_nve_ramdisk, CONN_NVE_PARTICION_SIZE);
    if (tmp_crc != g_conn_nve_struct.conn_nve_ramdisk->crc) {
        pr_err("[CONN_NVE]:%s faild due to crc check failure, new_crc is 0x%X, old_crc is 0x%X!\n", __func__,
            tmp_crc, g_conn_nve_struct.conn_nve_ramdisk->crc);
        return -CONN_NVE_ERROR_CRC;
    }

    g_conn_nve_struct.current_id = (uint32_t)up_to_date_idx;

    return CONN_NVE_RET_OK;
}

static int32_t conn_nve_sync_from_nv(void)
{
    int32_t ret = CONN_NVE_RET_OK;
    if (hisi_conn_nve_setup_done() == 0) {
        pr_err("[CONN_NVE]:%s faild due to ini failure!\n", __func__);
        return -CONN_NVE_ERROR_INIT;
    }

    if (g_cali_data_nv_type == CALI_DATA_NV_TYPE_NVBLOCK) {
        ret = conn_nve_read_from_nvblock();
    } else if (g_cali_data_nv_type == CALI_DATA_NV_TYPE_NVRAM) {
        ret = conn_nve_read_powcal_from_nvram();
    }

    if (ret != CONN_NVE_RET_OK) {
        pr_err("[CONN_NVE]%s read nv failed!\n", __func__);
        return ret;
    }

#ifdef _PRE_WLAN_FEATURE_TAS_ANT_SWITCH
    ret = conn_nve_read_tas_powcal_from_nvram();
    if (ret != CONN_NVE_RET_OK) {
        pr_err("[CONN_NVE]%s read tas nv failed!\n", __func__);
        return ret;
    }
#endif

    g_hisi_sync_ramdisk_done = 1;
    return CONN_NVE_RET_OK;
}

static int32_t conn_nve_clear_nvblock(void)
{
    int32_t ret = CONN_NVE_RET_OK;
    unsigned int i;
    /* write init value of conn_nve */
    if (memset_s(g_conn_nve_struct.conn_nve_ramdisk, sizeof(conn_nve_particion_stru),
        0, sizeof(conn_nve_particion_stru)) != 0) {
        return -CONN_NVE_ERROR_CLEAR_ALL;
    }
    g_conn_nve_struct.conn_nve_ramdisk->age = 0;
    g_conn_nve_struct.conn_nve_ramdisk->crc = crc32c_conn_nve(CRC32C_REV_SEED,
        (const uint8_t*)g_conn_nve_struct.conn_nve_ramdisk, CONN_NVE_PARTICION_SIZE);
    for (i = 0; i < CONN_NVE_IMG_NUM; i++) {
        if (hisi_conn_nve_write(HISI_CONN_WIFI_DATA, conn_nve_start_addr(i), sizeof(conn_nve_particion_stru),
            (u_char*)g_conn_nve_struct.conn_nve_ramdisk)) {
            pr_err("[CONN_NVE]%s clear img[%d] failed!\n", __func__, i);
            ret = -CONN_NVE_ERROR_CLEAR_ALL;
        }
    }
    pr_info("[CONN_NVE]%s succ, now crc code is 0x%X\n", __func__, g_conn_nve_struct.conn_nve_ramdisk->crc);
    return ret;
}

/**
 * @brief  向nvram中写入数据。
 * @param  [in]            buff     向nvram中写入数据的存放地址。
 * @param  [in]            buff_len 要写入数据的长度。
 * @param  [in]            nv_name  nvram的名称。
 * @param  [in]            nv_num   nvram的编号。
 * @retval CONN_NVE_RET_OK Success。
 * @retval Other           参考 @ref hisi_conn_ret。
 */
static int32_t conn_nve_nvram_write(uint8_t *buff, uint8_t buff_len, char *nv_name, uint32_t nv_num)
{
    int32_t ret;
    struct external_nve_info_user nve;

    if (buff_len > sizeof(nve.nv_data)) {
        return CONN_NVE_ERROR_OVERSIZE;
    }

    memset_s(&nve, sizeof(nve), 0, sizeof(nve));
    if (strcpy_s(nve.nv_name, sizeof(nve.nv_name), nv_name) != EOK) {
        pr_err("[CONN_NVE]conn_nve_nvram_write:write nv_name failed, max size: %lu", sizeof(nve.nv_name));
        return CONN_NVE_ERROR_MEMCPY_FAIL;
    }
    nve.nv_name[sizeof(nve.nv_name) - 1] = '\0';
    nve.nv_number = nv_num;
    nve.valid_size = buff_len;
    nve.nv_operation = NV_WRITE;
    if (memcpy_s(nve.nv_data, sizeof(nve.nv_data), buff, buff_len) != EOK) {
        pr_err("[CONN_NVE]conn_nve_nvram_write:copy nv data failed");
        return CONN_NVE_ERROR_MEMCPY_FAIL;
    }

    ret = external_nve_direct_access_interface(&nve);
    if (ret) {
        pr_err("[CONN_NVE]conn_nve_nvram_write:write nv failed");
        return CONN_NVE_ERROR_WRITE;
    }
    return CONN_NVE_RET_OK;
}

/**
 * @brief  从nvram中读取数据。
 * @param  [out]           buff     从nvram中读取数据的存放地址。
 * @param  [in]            buff_len 要读取数据的长度。
 * @param  [in]            nv_name  nvram的名称。
 * @param  [in]            nv_num   nvram的编号。
 * @retval CONN_NVE_RET_OK Success。
 * @retval Other           参考 @ref hisi_conn_ret。
 */
static int32_t conn_nve_nvram_read(uint8_t *buff, uint8_t buff_len, char *nv_name, uint32_t nv_num)
{
    int32_t ret;
    struct external_nve_info_user nve;

    if (buff_len > NV_RAM_MAX_SIZE) {
        return CONN_NVE_ERROR_OVERSIZE;
    }

    memset_s(&nve, sizeof(nve), 0, sizeof(nve));
    if (strcpy_s(nve.nv_name, sizeof(nve.nv_name), nv_name) != EOK) {
        pr_err("[CONN_NVE]conn_nve_nvram_read:read nv_name failed, max size: %lu", sizeof(nve.nv_name));
        return CONN_NVE_ERROR_MEMCPY_FAIL;
    }
    nve.nv_name[sizeof(nve.nv_name) - 1] = '\0';
    nve.nv_number = nv_num;
    nve.valid_size = NV_RAM_MAX_SIZE;
    nve.nv_operation = NV_READ;

    ret = external_nve_direct_access_interface(&nve);
    if (ret) {
        pr_err("[CONN_NVE]conn_nve_nvram_read:read nv failed");
        return CONN_NVE_ERROR_WRITE;
    }

    if (memcpy_s(buff, buff_len, nve.nv_data, buff_len) != EOK) {
        pr_err("[CONN_NVE]conn_nve_nvram_read:copy nv data failed");
        return CONN_NVE_ERROR_MEMCPY_FAIL;
    }

    return CONN_NVE_RET_OK;
}

static int32_t conn_nve_clear_all(void)
{
    int32_t ret = CONN_NVE_RET_OK;
    if (g_cali_data_nv_type == CALI_DATA_NV_TYPE_NVBLOCK) {
        ret = conn_nve_clear_nvblock();
    } else if (g_cali_data_nv_type == CALI_DATA_NV_TYPE_NVRAM) {
        ret = conn_nve_clear_powcal_nvram();
    }
    if (ret != CONN_NVE_RET_OK) {
        return ret;
    }

#ifdef _PRE_WLAN_FEATURE_TAS_ANT_SWITCH
    ret = conn_nve_clear_tas_powcal_nvram();
#endif

    return ret;
}

/*
 * 写数据前检查ramdisk内容是否已与nv同步
 * 每次写数据，整个ramdisk内容会被重新写回nv
 * 如果ramdisk未同步nv就被直接写入，会导致nv数据被破坏
 */
static int32_t conn_nve_check_sync_before_write(void)
{
    int32_t ret = 0;
    /* ensure only one process can visit conn_nve at the same time in kernel */
    if (down_interruptible(&g_nv_sem)) {
        return -EBUSY;
    }
    if (g_hisi_sync_ramdisk_done == 0) {
        // 从nv同步数据到ram
        ret = conn_nve_sync_from_nv();
        // no nv data, try to set 0 all
        if (ret != CONN_NVE_RET_OK) {
            pr_err("[CONN_NVE]:%s no nv data, try to set 0 all!\n", __func__);
            ret = conn_nve_clear_all();
            up(&g_nv_sem);
            return ret;
        }

        pr_info("[CONN_NVE]:%s sync succ!\n", __func__);
    }
    up(&g_nv_sem);
    return ret;
}

static int32_t conn_nve_read_prepare_process(void)
{
    int32_t ret;

    /* ensure only one process can visit conn_nve at the same time in kernel */
    if (down_interruptible(&g_nv_sem)) {
        return -EBUSY;
    }
    if (g_hisi_sync_ramdisk_done == 0) {
        // 从nv同步数据到ram
        ret = conn_nve_sync_from_nv();
        if (ret) {
            pr_err("[CONN_NVE]:%s faild due to sync failure!\n", __func__);
            up(&g_nv_sem);
            return ret;
        }
        pr_info("[CONN_NVE]:%s sync succ!\n", __func__);
    }

    up(&g_nv_sem);
    return CONN_NVE_RET_OK;
}

static int32_t conn_nve_write_prepare_process(void)
{
    if (conn_nve_check_sync_before_write() != 0) {
        pr_err("[CONN_NVE]%s check sync failed!\n", __func__);
        return -CONN_NVE_ERROR_WRITE;
    }

    return CONN_NVE_RET_OK;
}

static int32_t conn_nve_write_to_nvblock(void)
{
    g_conn_nve_struct.conn_nve_ramdisk->age++;
    g_conn_nve_struct.conn_nve_ramdisk->crc = crc32c_conn_nve(CRC32C_REV_SEED,
        (uint8_t*)g_conn_nve_struct.conn_nve_ramdisk, CONN_NVE_PARTICION_SIZE);
    // 将数据同步到nvblock
    ++g_conn_nve_struct.current_id;
    if (hisi_conn_nve_write(HISI_CONN_WIFI_DATA, conn_nve_start_addr(g_conn_nve_struct.current_id), \
        sizeof(conn_nve_particion_stru), (uint8_t*)g_conn_nve_struct.conn_nve_ramdisk)) {
        pr_err("[CONN_NVE]hisi_conn_nve_write write data failed!\n");
        up(&g_nv_sem);
        return -CONN_NVE_ERROR_WRITE;
    }
    return CONN_NVE_RET_OK;
}

int32_t conn_nve_sync_to_nv(void)
{
    int32_t ret = CONN_NVE_RET_OK;

    ret = conn_nve_check_sync_before_write();
    if (ret != CONN_NVE_RET_OK) {
        pr_err("[CONN_NVE]%s check sync failed!\n", __func__);
        return ret;
    }

    /* ensure only one process can visit conn_nve at the same time in kernel */
    if (down_interruptible(&g_nv_sem)) {
        pr_err("[CONN_NVE]%s visite forbid!\n", __func__);
        return -EBUSY;
    }

    if (g_cali_data_nv_type == CALI_DATA_NV_TYPE_NVBLOCK) {
        ret = conn_nve_write_to_nvblock();
    } else if (g_cali_data_nv_type == CALI_DATA_NV_TYPE_NVRAM) {
        ret = conn_nve_write_powcal_to_nvram();
    }
    if (ret != CONN_NVE_RET_OK) {
        pr_err("[CONN_NVE]%s sync nv failed!\n", __func__);
        up(&g_nv_sem);
        return ret;
    }

#ifdef _PRE_WLAN_FEATURE_TAS_ANT_SWITCH
    ret = conn_nve_write_tas_powcal_to_nvram();
    if (ret != CONN_NVE_RET_OK) {
        pr_err("[CONN_NVE]%s sync tas nv failed!\n", __func__);
        up(&g_nv_sem);
        return ret;
    }
#endif

    up(&g_nv_sem);

    return ret;
}

int conn_nve_read_powcal_data(nv_pow_stru *buf)
{
    int32_t ret;

    ret = conn_nve_read_prepare_process();
    if (ret != CONN_NVE_RET_OK) {
        return ret;
    }

    if (down_interruptible(&g_nv_sem)) {
        return -EBUSY;
    }

    // 从ram取数据
    if (memcpy_s(buf, sizeof(*buf), &(CONN_NVE_PREFIX->pow_cal_data), sizeof(CONN_NVE_PREFIX->pow_cal_data))) {
        up(&g_nv_sem);
        return -CONN_NVE_ERROR_READ;
    }

    up(&g_nv_sem);
    return 0;
}

static void conn_nve_copy_pow_data_from_user_2g(nv_pow_stru *pow_cali, const nv_pow_user_info_stru *info)
{
    switch (info->band_type) {
        case POW_CAL_BAND_2G_11B:
            pow_cali->delta_gain_2g_11b[info->stream][info->band_idx].delta_gain[info->gain_lvl] = info->buf;
            break;
        case POW_CAL_BAND_2G_OFDM_20:
            pow_cali->delta_gain_2g_ofdm_20[info->stream][info->band_idx].delta_gain[info->gain_lvl] = \
                info->buf;
            break;
        case POW_CAL_BAND_2G_OFDM_40:
            pow_cali->delta_gain_2g_ofdm_40[info->stream][info->band_idx].delta_gain[info->gain_lvl] = \
                info->buf;
            break;
        default:
            break;
    }
}

static void conn_nve_copy_pow_data_from_user_5g(nv_pow_stru *pow_cali, const nv_pow_user_info_stru *info)
{
    switch (info->band_type) {
        case POW_CAL_BAND_5G_20:
            pow_cali->delta_gain_5g_20[info->stream][info->band_idx].delta_gain[info->gain_lvl] = info->buf;
            break;
        case POW_CAL_BAND_5G_40:
            pow_cali->delta_gain_5g_40[info->stream][info->band_idx].delta_gain[info->gain_lvl] = info->buf;
            break;
        case POW_CAL_BAND_5G_80:
            pow_cali->delta_gain_5g_80[info->stream][info->band_idx].delta_gain[info->gain_lvl] = info->buf;
            break;
        case POW_CAL_BAND_5G_160:
            pow_cali->delta_gain_5g_160[info->stream][info->band_idx].delta_gain[info->gain_lvl] = info->buf;
            break;
        default:
            break;
    }
}
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
static void conn_nve_copy_pow_data_from_user_6g(nv_pow_stru *pow_cali, const nv_pow_user_info_stru *info)
{
    switch (info->band_type) {
        case POW_CAL_BAND_6G_20:
            pow_cali->delta_gain_6g_20[info->stream][info->band_idx].delta_gain[info->gain_lvl] = info->buf;
            break;
        case POW_CAL_BAND_6G_40:
            pow_cali->delta_gain_6g_40[info->stream][info->band_idx].delta_gain[info->gain_lvl] = info->buf;
            break;
        case POW_CAL_BAND_6G_80:
            pow_cali->delta_gain_6g_80[info->stream][info->band_idx].delta_gain[info->gain_lvl] = info->buf;
            break;
        case POW_CAL_BAND_6G_160:
            pow_cali->delta_gain_6g_160[info->stream][info->band_idx].delta_gain[info->gain_lvl] = info->buf;
            break;
        default:
            break;
    }
}
#endif

int32_t conn_nve_write_powcal_data(nv_pow_user_info_stru *info)
{
    int32_t ret;
    nv_pow_stru *pow_cali_mem = NULL;

    ret = conn_nve_write_prepare_process();
    if (ret != CONN_NVE_RET_OK) {
        pr_err("[CONN_NVE]%s conn_nve_write_prepare_process fail!\n", __func__);
        return ret;
    }

    /* ensure only one process can visit conn_nve at the same time in kernel */
    if (down_interruptible(&g_nv_sem)) {
        pr_err("[CONN_NVE]%s visite forbid!\n", __func__);
        return -EBUSY;
    }

    if (info->stream <= WLAN_RF_CHANNEL_THREE) {
        pow_cali_mem = &POW_DATA_PREFIX;
    } else {
        pow_cali_mem = &g_conn_tas_powcal_nvram.tas_pow_cal_data;
        info->stream -= WICAL_STREAM_NUM;
    }

    // 首先拷贝数据至ram
    if (info->band_type >= POW_CAL_BAND_2G_11B && info->band_type < POW_CAL_BAND_5G_20) {
        conn_nve_copy_pow_data_from_user_2g(pow_cali_mem, info);
    } else if (info->band_type >= POW_CAL_BAND_5G_20 && info->band_type <= POW_CAL_BAND_5G_160) {
        conn_nve_copy_pow_data_from_user_5g(pow_cali_mem, info);
    } else {
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
        conn_nve_copy_pow_data_from_user_6g(pow_cali_mem, info);
#endif
    }

    up(&g_nv_sem);
    return CONN_NVE_RET_OK;
}

static void conn_nve_copy_dpd_data_to_user_5g(const nv_dpd_user_info_stru *info)
{
    if (info->bw == WLAN_BANDWIDTH_20) {
        memcpy_s(info->buf, sizeof(mp1x_wlan_cali_dpd_lut_stru),
            conn_nve_dpd_unit(CONN_NVE_PREFIX, cali_data_5g_20, info), sizeof(mp1x_wlan_cali_dpd_lut_stru));
    } else if (info->lut_type == CONN_NVE_LUT_TYPE_NORMAL) {
        if (info->bw == WLAN_BANDWIDTH_80) {
            memcpy_s(info->buf, sizeof(mp1x_wlan_cali_dpd_lut_stru),
                conn_nve_dpd_unit(CONN_NVE_PREFIX, cali_data_5g_80, info), sizeof(mp1x_wlan_cali_dpd_lut_stru));
        } else if (info->bw == WLAN_BANDWIDTH_160) {
            memcpy_s(info->buf, sizeof(mp1x_wlan_cali_dpd_lut_stru),
                conn_nve_dpd_unit(CONN_NVE_PREFIX, cali_data_5g_160, info), sizeof(mp1x_wlan_cali_dpd_lut_stru));
        }
    }
}

#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
static void conn_nve_copy_dpd_data_to_user_6g(const nv_dpd_user_info_stru *info)
{
    if (info->bw == WLAN_BANDWIDTH_20) {
        memcpy_s(info->buf, sizeof(mp1x_wlan_cali_dpd_lut_stru), \
            conn_nve_dpd_unit(CONN_NVE_PREFIX, cali_data_6g_20, info), sizeof(mp1x_wlan_cali_dpd_lut_stru));
    } else if (info->lut_type == CONN_NVE_LUT_TYPE_NORMAL) {
        if (info->bw == WLAN_BANDWIDTH_80) {
            memcpy_s(info->buf, sizeof(mp1x_wlan_cali_dpd_lut_stru), \
                conn_nve_dpd_unit(CONN_NVE_PREFIX, cali_data_6g_80, info), sizeof(mp1x_wlan_cali_dpd_lut_stru));
        } else if (info->bw == WLAN_BANDWIDTH_160) {
            memcpy_s(info->buf, sizeof(mp1x_wlan_cali_dpd_lut_stru), \
                conn_nve_dpd_unit(CONN_NVE_PREFIX, cali_data_6g_160, info), sizeof(mp1x_wlan_cali_dpd_lut_stru));
        }
    }
}

static void conn_nve_copy_dpd_data_from_user_6g(const nv_dpd_user_info_stru *info)
{
    if (info->bw == WLAN_BANDWIDTH_20) {
        memcpy_s(conn_nve_dpd_unit(CONN_NVE_PREFIX, cali_data_6g_20, info), sizeof(mp1x_wlan_cali_dpd_lut_stru), \
            info->buf, sizeof(mp1x_wlan_cali_dpd_lut_stru));
    } else if (info->lut_type == CONN_NVE_LUT_TYPE_NORMAL) {
        if (info->bw == WLAN_BANDWIDTH_80) {
            memcpy_s(conn_nve_dpd_unit(CONN_NVE_PREFIX, cali_data_6g_80, info), sizeof(mp1x_wlan_cali_dpd_lut_stru), \
                info->buf, sizeof(mp1x_wlan_cali_dpd_lut_stru));
        } else if (info->bw == WLAN_BANDWIDTH_160) {
            memcpy_s(conn_nve_dpd_unit(CONN_NVE_PREFIX, cali_data_6g_160, info), sizeof(mp1x_wlan_cali_dpd_lut_stru), \
                info->buf, sizeof(mp1x_wlan_cali_dpd_lut_stru));
        }
    }
}
#endif

static void conn_nve_do_copy_dpd_data_to_user(const nv_dpd_user_info_stru *info)
{
    switch (info->band_type) {
        case WLAN_CALI_BAND_2G:
            memcpy_s(info->buf, sizeof(mp1x_wlan_cali_dpd_lut_stru), \
                conn_nve_dpd_unit(CONN_NVE_PREFIX, cali_data_2g, info), sizeof(mp1x_wlan_cali_dpd_lut_stru));
            break;
        case WLAN_CALI_BAND_5G:
            conn_nve_copy_dpd_data_to_user_5g(info);
            break;
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
        case WLAN_CALI_BAND_6G:
            conn_nve_copy_dpd_data_to_user_6g(info);
            break;
#endif
        default:
            break;
    }
}

static void conn_nve_copy_dpd_data_from_user_5g(const nv_dpd_user_info_stru *info)
{
    if (info->bw == WLAN_BANDWIDTH_20) {
        memcpy_s(conn_nve_dpd_unit(CONN_NVE_PREFIX, cali_data_5g_20, info), info->dpd_lut_size, \
            info->buf, info->dpd_lut_size);
    } else if (info->lut_type == CONN_NVE_LUT_TYPE_NORMAL) {
        if (info->bw == WLAN_BANDWIDTH_80) {
            memcpy_s(conn_nve_dpd_unit(CONN_NVE_PREFIX, cali_data_5g_80, info), info->dpd_lut_size, \
                info->buf, info->dpd_lut_size);
        } else if (info->bw == WLAN_BANDWIDTH_160) {
            memcpy_s(conn_nve_dpd_unit(CONN_NVE_PREFIX, cali_data_5g_160, info), info->dpd_lut_size, \
                info->buf, info->dpd_lut_size);
        }
    }
}

static int32_t conn_nve_do_copy_dpd_data_from_user(const nv_dpd_user_info_stru *info)
{
    /* ensure only one process can visit conn_nve at the same time in kernel */
    if (down_interruptible(&g_nv_sem)) {
        pr_err("[CONN_NVE]%s visite forbid!\n", __func__);
        return -EBUSY;
    }

    switch (info->band_type) {
        case WLAN_CALI_BAND_2G:
            memcpy_s(conn_nve_dpd_unit(CONN_NVE_PREFIX, cali_data_2g, info), info->dpd_lut_size,
                info->buf, info->dpd_lut_size);
            break;
        case WLAN_CALI_BAND_5G:
            conn_nve_copy_dpd_data_from_user_5g(info);
            break;
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
        case WLAN_CALI_BAND_6G:
            conn_nve_copy_dpd_data_from_user_6g(info);
            break;
#endif
        default: break;
    }
    up(&g_nv_sem);
    
    return CONN_NVE_RET_OK;
}

int32_t conn_nve_read_dpd_data(const nv_dpd_user_info_stru *info)
{
    int32_t ret;

    ret = conn_nve_read_prepare_process();
    if (ret != CONN_NVE_RET_OK) {
        return ret;
    }

    if (down_interruptible(&g_nv_sem)) {
        return -EBUSY;
    }
    // 从ram取数据
    conn_nve_do_copy_dpd_data_to_user(info);
    up(&g_nv_sem);
    return 0;
}

int32_t conn_nve_write_dpd_data(const nv_dpd_user_info_stru *info)
{
    int32_t ret;

    ret = conn_nve_write_prepare_process();
    if (ret != CONN_NVE_RET_OK) {
        return ret;
    }

    // 首先拷贝数据至ram
    conn_nve_do_copy_dpd_data_from_user(info);

    return CONN_NVE_RET_OK;
}

int32_t conn_nve_write_rssi_data(const nv_rssi_user_info_stru *info)
{
    int32_t ret;

    ret = conn_nve_write_prepare_process();
    if (ret != CONN_NVE_RET_OK) {
        return ret;
    }

    /* ensure only one process can visit conn_nve at the same time in kernel */
    if (down_interruptible(&g_nv_sem)) {
        pr_err("[CONN_NVE]%s visite forbid!\n", __func__);
        return -EBUSY;
    }
    // 首先拷贝数据至ram
    if (info->band_type == WLAN_CALI_BAND_2G) {
        CONN_NVE_PREFIX->rssi_cal_data.delta_gain_2g[info->stream][info->band_idx][info->gain_lvl][info->fem_lvl] = \
            info->buf;
    } else if (info->band_type == WLAN_CALI_BAND_5G) {
        CONN_NVE_PREFIX->rssi_cal_data.delta_gain_5g[info->stream][info->band_idx][info->gain_lvl][info->fem_lvl] = \
            info->buf;
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    } else if (info->band_type == WLAN_CALI_BAND_6G) {
        CONN_NVE_PREFIX->rssi_cal_data.delta_gain_6g[info->stream][info->band_idx][info->gain_lvl][info->fem_lvl] = \
            info->buf;
#endif
    }
    up(&g_nv_sem);
    return CONN_NVE_RET_OK;
}

int32_t conn_nve_read_rssi_data(nv_rssi_user_info_stru *info)
{
    int32_t ret;

    ret = conn_nve_read_prepare_process();
    if (ret != CONN_NVE_RET_OK) {
        return ret;
    }

    if (down_interruptible(&g_nv_sem)) {
        return -EBUSY;
    }

    // 从ram取数据
    if (info->band_type == WLAN_CALI_BAND_2G) {
        info->buf = \
            CONN_NVE_PREFIX->rssi_cal_data.delta_gain_2g[info->stream][info->band_idx][info->gain_lvl][info->fem_lvl];
    } else if (info->band_type == WLAN_CALI_BAND_5G) {
        info->buf = \
            CONN_NVE_PREFIX->rssi_cal_data.delta_gain_5g[info->stream][info->band_idx][info->gain_lvl][info->fem_lvl];
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    } else if (info->band_type == WLAN_CALI_BAND_6G) {
        info->buf = \
            CONN_NVE_PREFIX->rssi_cal_data.delta_gain_6g[info->stream][info->band_idx][info->gain_lvl][info->fem_lvl];
#endif
    }

    up(&g_nv_sem);
    return CONN_NVE_RET_OK;
}

static void conn_nve_clear_pow_2g_by_cmd(nv_pow_stru *pow_cali, uint8_t core_idx)
{
    memset_s(pow_cali->delta_gain_2g_11b[core_idx], \
        sizeof(pow_cali->delta_gain_2g_11b[core_idx]),\
        0, sizeof(wlan_cali_pow_para_stru) * WICAL_2G_RF_BAND_NUM);
    memset_s(pow_cali->delta_gain_2g_ofdm_20[core_idx], \
        sizeof(pow_cali->delta_gain_2g_ofdm_20[core_idx]), \
        0, sizeof(wlan_cali_pow_para_stru) * WICAL_2G_RF_BAND_NUM);
    memset_s(pow_cali->delta_gain_2g_ofdm_40[core_idx], \
        sizeof(pow_cali->delta_gain_2g_ofdm_40[core_idx]), \
        0, sizeof(wlan_cali_pow_para_stru) * WICAL_2G_RF_BAND_NUM);
}

static void conn_nve_clear_pow_5g_by_cmd(nv_pow_stru *pow_cali, uint8_t core_idx)
{
    memset_s(pow_cali->delta_gain_5g_20[core_idx], \
        sizeof(pow_cali->delta_gain_5g_20[core_idx]), \
        0, sizeof(wlan_cali_pow_para_stru) * WICAL_5G_RF_BAND_NUM);
    memset_s(pow_cali->delta_gain_5g_40[core_idx], \
        sizeof(pow_cali->delta_gain_5g_40[core_idx]), \
        0, sizeof(wlan_cali_pow_para_stru) * WICAL_5G_RF_BAND_NUM);
    memset_s(pow_cali->delta_gain_5g_80[core_idx], \
        sizeof(pow_cali->delta_gain_5g_80[core_idx]), \
        0, sizeof(wlan_cali_pow_para_stru) * WICAL_5G_RF_BAND_NUM);
    memset_s(pow_cali->delta_gain_5g_160[core_idx], \
        sizeof(pow_cali->delta_gain_5g_160[core_idx]), \
        0, sizeof(wlan_cali_pow_para_stru) * WICAL_5G_RF_BAND_NUM);
}

#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
static void conn_nve_clear_pow_6g_by_cmd(nv_pow_stru *pow_cali, uint8_t core_idx)
{
    memset_s(pow_cali->delta_gain_6g_20[core_idx], \
        sizeof(pow_cali->delta_gain_6g_20[core_idx]), \
        0, sizeof(wlan_cali_pow_para_stru) * WICAL_6G_RF_BAND_NUM);
    memset_s(pow_cali->delta_gain_6g_40[core_idx], \
        sizeof(pow_cali->delta_gain_6g_40[core_idx]), \
        0, sizeof(wlan_cali_pow_para_stru) * WICAL_6G_RF_BAND_NUM);
    memset_s(pow_cali->delta_gain_6g_80[core_idx], \
        sizeof(pow_cali->delta_gain_6g_80[core_idx]), \
        0, sizeof(wlan_cali_pow_para_stru) * WICAL_6G_RF_BAND_NUM);
    memset_s(pow_cali->delta_gain_6g_160[core_idx], \
        sizeof(pow_cali->delta_gain_6g_160[core_idx]), \
        0, sizeof(wlan_cali_pow_para_stru) * WICAL_6G_RF_BAND_NUM);
}
#endif

static void conn_nve_clear_pow_by_channel(uint32_t cmd, uint8_t channel, nv_pow_stru *pow_cali)
{
    if (cmd & CONN_NVE_CLEAR_2G_MASK) {
        conn_nve_clear_pow_2g_by_cmd(pow_cali, channel);
    }
    if (cmd & CONN_NVE_CLEAR_5G_MASK) {
        conn_nve_clear_pow_5g_by_cmd(pow_cali, channel);
    }
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    if (cmd & CONN_NVE_CLEAR_6G_MASK) {
        conn_nve_clear_pow_6g_by_cmd(pow_cali, channel);
    }
#endif
}

static void conn_nve_clear_pow_all_channel(uint32_t cmd, nv_pow_stru *pow_cali)
{
    uint8_t channel;
    for (channel = 0; channel < WICAL_STREAM_NUM; ++channel) {
        if (cmd == CONN_NVE_CLEAR_POW_2G || cmd == CONN_NVE_CLEAR_TAS_POW_2G) {
            conn_nve_clear_pow_2g_by_cmd(pow_cali, channel);
        } else if (cmd == CONN_NVE_CLEAR_POW_5G || cmd == CONN_NVE_CLEAR_TAS_POW_5G) {
            conn_nve_clear_pow_5g_by_cmd(pow_cali, channel);
        } else {
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
            conn_nve_clear_pow_6g_by_cmd(pow_cali, channel);
#endif
        }
    }
}

static int conn_nve_clear_pow_by_cmd(uint32_t cmd, nv_pow_stru *pow_cali)
{
    uint8_t cmd_idx;
    uint8_t channel;
    cmd_idx = (cmd & CONN_NVE_CLEAR_MASK);

    /* write init value of conn_nve */
    if (cmd_idx == CONN_NVE_CLEAR_POW_ALL || cmd_idx == CONN_NVE_CLEAR_TAS_POW_ALL) {
        memset_s(pow_cali, sizeof(nv_pow_stru), 0, sizeof(nv_pow_stru));
    } else if ((cmd_idx >= CONN_NVE_CLEAR_POW_C0 && cmd_idx <= CONN_NVE_CLEAR_POW_C3) ||
               (cmd_idx >= CONN_NVE_CLEAR_TAS_POW_C0 && cmd_idx <= CONN_NVE_CLEAR_TAS_POW_C3)) {
        if (cmd_idx <= CONN_NVE_CLEAR_POW_C3) {
            channel = cmd_idx - CONN_NVE_CLEAR_POW_C0;
        } else {
            channel = cmd_idx - CONN_NVE_CLEAR_TAS_POW_C0;
        }
        conn_nve_clear_pow_by_channel(cmd, channel, pow_cali);
    } else if ((cmd_idx >= CONN_NVE_CLEAR_POW_2G && cmd_idx < CONN_NVE_CLEAR_POW_ALL) ||
               (cmd_idx >= CONN_NVE_CLEAR_TAS_POW_2G && cmd_idx < CONN_NVE_CLEAR_TAS_POW_ALL)) {
        conn_nve_clear_pow_all_channel(cmd, pow_cali);
    } else {
        pr_err("[CONN_NVE]:%s uknown clear cmd!\n", __func__);
    }

    return CONN_NVE_RET_OK;
}

static void conn_nve_clear_rssi_fullband_by_cmd(uint32_t cmd, uint8_t core_idx)
{
    if (cmd & CONN_NVE_CLEAR_2G_MASK) {
        memset_s(&CONN_NVE_PREFIX->rssi_cal_data.delta_gain_2g[core_idx], \
            sizeof(CONN_NVE_PREFIX->rssi_cal_data.delta_gain_2g[core_idx]), \
            0, RSSI_ONE_STREAM_SIZE_2G);
    }
    if (cmd & CONN_NVE_CLEAR_5G_MASK) {
        memset_s(&CONN_NVE_PREFIX->rssi_cal_data.delta_gain_5g[core_idx], \
            sizeof(CONN_NVE_PREFIX->rssi_cal_data.delta_gain_5g[core_idx]), \
            0, RSSI_ONE_STREAM_SIZE_5G);
    }
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    if (cmd & CONN_NVE_CLEAR_6G_MASK) {
        memset_s(&CONN_NVE_PREFIX->rssi_cal_data.delta_gain_6g[core_idx], \
            sizeof(CONN_NVE_PREFIX->rssi_cal_data.delta_gain_6g[core_idx]), \
            0, RSSI_ONE_STREAM_SIZE_6G);
    }
#endif
}

static int conn_nve_clear_rssi_by_cmd(uint32_t cmd)
{
    uint8_t core_idx;
    uint8_t cmd_idx = (cmd & CONN_NVE_CLEAR_MASK);

    /* write init value of conn_nve */
    if (cmd_idx == CONN_NVE_CLEAR_RSSI_ALL) {
        memset_s(&CONN_NVE_PREFIX->rssi_cal_data, sizeof(CONN_NVE_PREFIX->rssi_cal_data), 0, sizeof(nv_rssi_stru));
    } else if (cmd_idx >= CONN_NVE_CLEAR_RSSI_C0 && cmd_idx <= CONN_NVE_CLEAR_RSSI_C3) {
        core_idx = cmd_idx - CONN_NVE_CLEAR_RSSI_C0;
        conn_nve_clear_rssi_fullband_by_cmd(cmd, core_idx);
    } else if (cmd_idx == CONN_NVE_CLEAR_RSSI_2G) {
        memset_s(&CONN_NVE_PREFIX->rssi_cal_data.delta_gain_2g, \
            sizeof(CONN_NVE_PREFIX->rssi_cal_data.delta_gain_2g), \
            0, sizeof(CONN_NVE_PREFIX->rssi_cal_data.delta_gain_2g));
    } else if (cmd_idx == CONN_NVE_CLEAR_RSSI_5G) {
        memset_s(&CONN_NVE_PREFIX->rssi_cal_data.delta_gain_5g, \
            sizeof(CONN_NVE_PREFIX->rssi_cal_data.delta_gain_5g), \
            0, sizeof(CONN_NVE_PREFIX->rssi_cal_data.delta_gain_5g));
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    } else if (cmd_idx == CONN_NVE_CLEAR_RSSI_6G) {
        memset_s(&CONN_NVE_PREFIX->rssi_cal_data.delta_gain_6g, \
            sizeof(CONN_NVE_PREFIX->rssi_cal_data.delta_gain_6g), \
            0, sizeof(CONN_NVE_PREFIX->rssi_cal_data.delta_gain_6g));
    }
#else
    }
#endif

    return CONN_NVE_RET_OK;
}

static void conn_nve_clear_dpd_2g_5g_by_cmd(uint32_t cmd)
{
    uint8_t core_idx = (cmd & CONN_NVE_CLEAR_MASK) - CONN_NVE_CLEAR_DPD_C0;
    uint8_t radio_cap_mask;
    if (cmd & CONN_NVE_CLEAR_2G_MASK) {
        memset_s(&DPD_DATA_PREFIX.cali_data_2g[core_idx], sizeof(DPD_DATA_PREFIX.cali_data_2g[core_idx]), \
            0, dpd_size(WLAN_2G_CALI_BAND_NUM));
        radio_cap_mask = (uint8_t)(~(0x1 << core_idx));
        CONN_NVE_PREFIX->data_status &= radio_cap_mask;
    }
    if (cmd & CONN_NVE_CLEAR_5G_MASK) {
        memset_s(&DPD_DATA_PREFIX.cali_data_5g_20[core_idx], sizeof(DPD_DATA_PREFIX.cali_data_5g_20[core_idx]), \
            0, dpd_size(WLAN_5G_20M_CALI_BAND_NUM));
        memset_s(&DPD_DATA_PREFIX.cali_data_5g_80[core_idx], sizeof(DPD_DATA_PREFIX.cali_data_5g_80[core_idx]), \
            0, dpd_size(WLAN_5G_20M_CALI_BAND_NUM));
        memset_s(&DPD_DATA_PREFIX.cali_data_5g_160[core_idx], sizeof(DPD_DATA_PREFIX.cali_data_5g_160[core_idx]), \
            0, dpd_size(WLAN_5G_160M_CALI_BAND_NUM));
        radio_cap_mask = (uint8_t)(~(0x10 << core_idx));
        CONN_NVE_PREFIX->data_status &= radio_cap_mask;
    }
}

static void conn_nve_clear_dpd_5g_all(void)
{
    memset_s(&DPD_DATA_PREFIX.cali_data_5g_20, sizeof(DPD_DATA_PREFIX.cali_data_5g_20), \
        0, sizeof(DPD_DATA_PREFIX.cali_data_5g_20));
    memset_s(&DPD_DATA_PREFIX.cali_data_5g_80, sizeof(DPD_DATA_PREFIX.cali_data_5g_80), \
        0, sizeof(DPD_DATA_PREFIX.cali_data_5g_80));
    memset_s(&DPD_DATA_PREFIX.cali_data_5g_160, sizeof(DPD_DATA_PREFIX.cali_data_5g_160), \
        0, sizeof(DPD_DATA_PREFIX.cali_data_5g_160));
    CONN_NVE_PREFIX->data_status &= (~(0xF0));
}

#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
static void conn_nve_clear_dpd_6g_by_cmd(uint32_t cmd)
{
    uint8_t core_idx = (cmd & CONN_NVE_CLEAR_MASK) - CONN_NVE_CLEAR_DPD_C0;
    uint8_t radio_cap_mask = (uint8_t)(~(0x100 << core_idx));
    if (cmd & CONN_NVE_CLEAR_6G_MASK) {
        memset_s(&DPD_DATA_PREFIX.cali_data_6g_20[core_idx], \
            sizeof(DPD_DATA_PREFIX.cali_data_6g_20[core_idx]), 0, dpd_size(WLAN_6G_20M_CALI_BAND_NUM));
        memset_s(&DPD_DATA_PREFIX.cali_data_6g_80[core_idx], \
            sizeof(DPD_DATA_PREFIX.cali_data_6g_80[core_idx]), 0, dpd_size(WLAN_6G_20M_CALI_BAND_NUM));
        memset_s(&DPD_DATA_PREFIX.cali_data_6g_160[core_idx], \
            sizeof(DPD_DATA_PREFIX.cali_data_6g_160[core_idx]), 0, dpd_size(WLAN_6G_160M_CALI_BAND_NUM));
    }
    CONN_NVE_PREFIX->data_status &= radio_cap_mask;
}

static void conn_nve_clear_dpd_6g_all(void)
{
    memset_s(&DPD_DATA_PREFIX.cali_data_6g_20, sizeof(DPD_DATA_PREFIX.cali_data_6g_20), \
        0, sizeof(DPD_DATA_PREFIX.cali_data_6g_20));
    memset_s(&DPD_DATA_PREFIX.cali_data_6g_80, sizeof(DPD_DATA_PREFIX.cali_data_6g_80), \
        0, sizeof(DPD_DATA_PREFIX.cali_data_6g_80));
    memset_s(&DPD_DATA_PREFIX.cali_data_6g_160, sizeof(DPD_DATA_PREFIX.cali_data_6g_160), \
        0, sizeof(DPD_DATA_PREFIX.cali_data_6g_160));
    CONN_NVE_PREFIX->data_status &= (~(0xF00));
}
#endif

static int conn_nve_clear_dpd_by_cmd(uint32_t cmd)
{
    uint8_t cmd_idx = (cmd & CONN_NVE_CLEAR_MASK);

    /* write init value of conn_nve */
    if (cmd_idx == CONN_NVE_CLEAR_DPD_ALL) {
        memset_s(&CONN_NVE_PREFIX->dpd_cal_data, sizeof(CONN_NVE_PREFIX->dpd_cal_data), 0, sizeof(nv_dpd_stru));
        CONN_NVE_PREFIX->data_status = 0;
    } else if (cmd_idx >= CONN_NVE_CLEAR_DPD_C0 && cmd_idx <= CONN_NVE_CLEAR_DPD_C3) {
        conn_nve_clear_dpd_2g_5g_by_cmd(cmd);
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
        conn_nve_clear_dpd_6g_by_cmd(cmd);
#endif
    } else if (cmd_idx == CONN_NVE_CLEAR_DPD_2G) {
        memset_s(&DPD_DATA_PREFIX.cali_data_2g, sizeof(DPD_DATA_PREFIX.cali_data_2g), \
            0, sizeof(DPD_DATA_PREFIX.cali_data_2g));
        CONN_NVE_PREFIX->data_status &= (~(0x0F));
    } else if (cmd_idx == CONN_NVE_CLEAR_DPD_5G) {
        conn_nve_clear_dpd_5g_all();
    }
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    if (cmd_idx == CONN_NVE_CLEAR_DPD_6G) {
        conn_nve_clear_dpd_6g_all();
    }
#endif

    return CONN_NVE_RET_OK;
}

int32_t conn_nve_clear_by_cmd(uint32_t cmd)
{
    int32_t ret = CONN_NVE_RET_OK;
    uint8_t cmd_idx = (cmd & CONN_NVE_CLEAR_MASK);

    // 从nv同步数据到ram,如未初始化先初始化NV分区
    ret = conn_nve_check_sync_before_write();
    if (ret != CONN_NVE_RET_OK) {
        pr_err("[CONN_NVE]:%s sync fail!\n", __func__);
        return ret;
    }

    /* ensure only one process can visit conn_nve at the same time in kernel */
    if (down_interruptible(&g_nv_sem)) {
        return -EBUSY;
    }
    if (cmd_idx == CONN_NVE_CLEAR_ALL) {
        ret = conn_nve_clear_all();
    } else if (cmd_idx >= CONN_NVE_CLEAR_POW_C0 && cmd_idx <= CONN_NVE_CLEAR_POW_ALL) {
        ret = conn_nve_clear_pow_by_cmd(cmd, &POW_DATA_PREFIX);
    } else if (cmd_idx >= CONN_NVE_CLEAR_TAS_POW_C0 && cmd_idx <= CONN_NVE_CLEAR_TAS_POW_ALL) {
        ret = conn_nve_clear_pow_by_cmd(cmd, &g_conn_tas_powcal_nvram.tas_pow_cal_data);
    } else if (cmd_idx >= CONN_NVE_CLEAR_RSSI_C0 && cmd_idx <= CONN_NVE_CLEAR_RSSI_ALL) {
        ret = conn_nve_clear_rssi_by_cmd(cmd);
    } else if (cmd_idx >= CONN_NVE_CLEAR_DPD_C0 && cmd_idx <= CONN_NVE_CLEAR_DPD_ALL) {
        ret = conn_nve_clear_dpd_by_cmd(cmd);
    }

    up(&g_nv_sem);
    return ret;
}

static int32_t conn_nve_get_wifi_cali_data_buf(void)
{
    /* get ram addr alloced in platform */
    g_conn_nve_struct.conn_nve_ramdisk = (conn_nve_particion_stru *)hisi_conn_nve_get_ramdisk(HISI_CONN_WIFI_DATA);
    if (g_conn_nve_struct.conn_nve_ramdisk == NULL) {
        pr_err("[CONN_NVE]%s line %d failed kzalloc.\n", __func__, __LINE__);
        return -CONN_NVE_ERROR_INIT;
    }
    return CONN_NVE_RET_OK;
}

int32_t conn_nve_init_wifi_nvdata(void)
{
    /* semaphore initial */
    sema_init(&g_nv_sem, 1);
    pr_info("[CONN_NVE]%s hisi_conn_nve init begin.\n", __func__);
    // send wifidata particion info first
    if (hisi_conn_nve_set_particion_size(HISI_CONN_WIFI_DATA, CONN_NVE_WIFIDATA_LEN) != CONN_NVE_RET_OK) {
        return -CONN_NVE_ERROR_INIT;
    }
    if (conn_nve_get_wifi_cali_data_buf() != CONN_NVE_RET_OK) {
        return -CONN_NVE_ERROR_INIT;
    }

    pr_info("[CONN_NVE]%s hisi_conn_nve init end.\n", __func__);
    return CONN_NVE_RET_OK;
}

int32_t conn_nve_fetch_wifi_nvdata(conn_nve_particion_stru *buf)
{
    int32_t ret = conn_nve_read_prepare_process();
    if (ret != CONN_NVE_RET_OK) {
        return ret;
    }

    if (down_interruptible(&g_nv_sem)) {
        return -EBUSY;
    }
    // 从ram取数据
    if (memcpy_s(buf, sizeof(conn_nve_particion_stru), CONN_NVE_PREFIX, sizeof(conn_nve_particion_stru))) {
        up(&g_nv_sem);
        return -CONN_NVE_ERROR_READ;
    }
    up(&g_nv_sem);
    return 0;
}

int32_t conn_nve_fetch_tas_powcal_nvdata(conn_nve_tas_particion_stru *buf)
{
    int32_t ret = conn_nve_read_prepare_process();
    if (ret != CONN_NVE_RET_OK) {
        return ret;
    }

    if (down_interruptible(&g_nv_sem)) {
        return -EBUSY;
    }
    // 从ram取数据
    if (memcpy_s(buf, sizeof(conn_nve_tas_particion_stru),
        &g_conn_tas_powcal_nvram, sizeof(conn_nve_tas_particion_stru))) {
        up(&g_nv_sem);
        return -CONN_NVE_ERROR_READ;
    }
    up(&g_nv_sem);
    return 0;
}

static void conn_nve_set_data_status_bit(uint8_t type, uint32_t status)
{
    if (type >= CONN_STATUS_BUTT) {
        return;
    } else if (type == CONN_STATUS_DPD) {
        CONN_NVE_PREFIX->data_status |= (0xFFF & status);
    } else if (type == CONN_STATUS_POW) {
        CONN_NVE_PREFIX->data_status |= ((0xF & status) << 0xC);
    } else {
        CONN_NVE_PREFIX->data_status |= ((0xF & status) << 0x10);
    }
}

static uint32_t conn_nve_get_data_status_bit(uint8_t type)
{
    if (type >= CONN_STATUS_BUTT) {
        return 0;
    } else if (type == CONN_STATUS_DPD) {
        return CONN_NVE_PREFIX->data_status & 0xFFF;
    } else if (type == CONN_STATUS_POW) {
        return (CONN_NVE_PREFIX->data_status & 0xF000) >> 0xC;
    } else {
        return (CONN_NVE_PREFIX->data_status & 0xF0000) >> 0x10;
    }
}

int32_t conn_nve_set_data_status(uint8_t type, uint32_t status)
{
    if (conn_nve_check_sync_before_write()) {
        pr_err("[CONN_NVE]%s check sync failed!\n", __func__);
        return -CONN_NVE_ERROR_WRITE;
    }

    if (down_interruptible(&g_nv_sem)) {
        return -EBUSY;
    }
    conn_nve_set_data_status_bit(type, status);
    up(&g_nv_sem);
    return CONN_NVE_RET_OK;
}

uint32_t conn_nve_get_data_status(uint8_t type, oal_bool_enum_uint8 resync_flag)
{
    uint32_t ret;
    /* ensure only one process can visit conn_nve at the same time in kernel */
    if (down_interruptible(&g_nv_sem)) {
        return -EBUSY;
    }
    if (resync_flag || g_hisi_sync_ramdisk_done == 0) {
        // 从nv同步数据到ram
        if (conn_nve_sync_from_nv()) {
            pr_err("[CONN_NVE]:%s faild due to sync failure!\n", __func__);
            up(&g_nv_sem);
            return -CONN_NVE_ERROR_READ;
        }
        pr_err("[CONN_NVE]:%s sync succ!\n", __func__);
    }
    // 从ram取数据
    ret = conn_nve_get_data_status_bit(type);
    // 添加有效nv块标记位
    if (resync_flag) {
        ret |= (g_hisi_nve_available_page << 0x18);
    }
    pr_info("[CONN_NVE]:nve data status[%d]!\n", ret);
    up(&g_nv_sem);
    return ret;
}

int32_t conn_nve_write_fbgain(int16_t* data)
{
    nv_fbgain_stru fb_info;

    if (data == NULL ||
        memcpy_s(fb_info.fb_gain, sizeof(fb_info.fb_gain), (uint8_t*)data, sizeof(fb_info.fb_gain)) != EOK) {
        pr_err("[CONN_NVE]conn_nve_write_fbgain:copy ori data failed");
        return CONN_NVE_ERROR_WRITE;
    }
    fb_info.crc = crc32c_conn_nve(CRC32C_REV_SEED, (uint8_t*)fb_info.fb_gain, sizeof(fb_info.fb_gain));
    pr_info("[CONN_NVE]conn_nve_write_fbgain:crc[%u]", fb_info.crc);

    return conn_nve_nvram_write((uint8_t*)&fb_info, sizeof(fb_info), CONN_NVE_FBGAIN_NAME, CONN_NVE_FBGAIN_NUM);
}

int32_t conn_nve_read_fbgain(int16_t *data)
{
    int32_t ret;
    uint32_t tmp_crc;
    nv_fbgain_stru fb_info;

    ret = conn_nve_nvram_read((uint8_t *)&fb_info, sizeof(fb_info), CONN_NVE_FBGAIN_NAME, CONN_NVE_FBGAIN_NUM);
    if (ret != CONN_NVE_RET_OK) {
        return ret;
    }

    tmp_crc = crc32c_conn_nve(CRC32C_REV_SEED, (uint8_t*)fb_info.fb_gain, sizeof(fb_info.fb_gain));
    pr_info("[CONN_NVE]conn_nve_read_fbgain:tmp crc[%u],read crc[%d]", tmp_crc, fb_info.crc);
    if (tmp_crc != fb_info.crc) {
        pr_err("[CONN_NVE]conn_nve_read_fbgain:crc faild, tmp crc[%u],read crc[%d]", tmp_crc, fb_info.crc);
        return CONN_NVE_ERROR_READ;
    }

    if (data == NULL ||
        memcpy_s((uint8_t *)data, sizeof(fb_info.fb_gain), fb_info.fb_gain, sizeof(fb_info.fb_gain)) != EOK) {
        pr_err("[CONN_NVE]conn_nve_read_fbgain:copy nv data failed");
        return CONN_NVE_ERROR_WRITE;
    }

    return CONN_NVE_RET_OK;
}

static wlan_cali_pow_para_stru *conn_nve_get_pow_cali_ram_addr(nv_pow_stru *src_pow_cali, uint8_t pow_type,
                                                               uint8_t channel, uint8_t band)
{
    uint32_t offset = 0;
    if (BIT(pow_type) <= POW_TYPE_2G_OFEM_40_FLAG) {
        offset = pow_type * WICAL_POWER_SIZE_2G;
        return &((wlan_cali_pow_para_stru (*)[WICAL_2G_RF_BAND_NUM])((uint8_t *)src_pow_cali + offset))[channel][band];
    } else if (BIT(pow_type) <= POW_TYPE_5G_160_FLAG) {
        offset = POW_TYPE_2G_ALL_NUM * WICAL_POWER_SIZE_2G +
            (pow_type - POW_TYPE_2G_ALL_NUM) * WICAL_POWER_SIZE_5G;
        return &((wlan_cali_pow_para_stru (*)[WICAL_5G_RF_BAND_NUM])((uint8_t *)src_pow_cali + offset))[channel][band];
    }
    return NULL;
}

static void conn_nve_set_pow_cali_nv_data(nv_pow_stru *src_pow_cali, powcal_nv_data *nv_data,
                                          uint8_t type, uint8_t band)
{
    uint8_t channel_loop;
    uint8_t pow_level_loop;
    wlan_cali_pow_para_stru *pow_cali_data;

    for (channel_loop = 0; channel_loop < WICAL_STREAM_NUM; ++channel_loop) {
        for (pow_level_loop = 0; pow_level_loop < WICAL_POW_CAL_LVL_NUM; ++pow_level_loop) {
            pow_cali_data = conn_nve_get_pow_cali_ram_addr(src_pow_cali, type, channel_loop, band);
            if (pow_cali_data == NULL) {
                return;
            }
            nv_data->cali_data[channel_loop][pow_level_loop] = pow_cali_data->delta_gain[pow_level_loop];
        }
    }
}

static void conn_nve_get_pow_cali_nv_data(nv_pow_stru *dst_pow_cali, powcal_nv_data *nv_data,
                                          uint8_t type, uint8_t band)
{
    uint8_t channel_loop;
    uint8_t pow_level_loop;
    wlan_cali_pow_para_stru *pow_cali_data;

    for (channel_loop = 0; channel_loop < WICAL_STREAM_NUM; ++channel_loop) {
        for (pow_level_loop = 0; pow_level_loop < WICAL_POW_CAL_LVL_NUM; ++pow_level_loop) {
            pow_cali_data = conn_nve_get_pow_cali_ram_addr(dst_pow_cali, type, channel_loop, band);
            if (pow_cali_data == NULL) {
                return;
            }
            pow_cali_data->delta_gain[pow_level_loop] = nv_data->cali_data[channel_loop][pow_level_loop];
        }
    }
}

static void conn_nve_sync_first_pow_cali_from_ram(nv_pow_stru *src_pow_cali)
{
    uint8_t type;
    uint8_t band;
    uint8_t loop;
    powcal_map_flag map_flag;

    for (loop = 0; loop < oal_array_size(g_powcal_nv_data); ++loop) {
        map_flag = g_powcal_nv_data[loop].flag;
        type = oal_bit_find_first_bit_four_byte(map_flag.bits.pow_type);
        band = oal_bit_find_first_bit_four_byte(map_flag.bits.band_type);
        conn_nve_set_pow_cali_nv_data(src_pow_cali, &g_powcal_nv_data[loop], type, band);
    }
}

static void conn_nve_set_pow_cali_to_ram(nv_pow_stru *dst_pow_cali)
{
    uint32_t type_flag;
    uint8_t type;
    uint32_t band_flag;
    uint8_t band;
    uint8_t loop;
    uint8_t type_loop;
    uint8_t band_loop;
    powcal_map_flag map_flag;

    for (loop = 0; loop < oal_array_size(g_powcal_nv_data); ++loop) {
        map_flag = g_powcal_nv_data[loop].flag;
        type_flag = map_flag.bits.pow_type;

        for (type_loop = 0; type_loop < oal_bit_get_num_four_byte(map_flag.bits.pow_type); ++type_loop) {
            type = oal_bit_find_first_bit_four_byte(type_flag);

            band_flag = map_flag.bits.band_type;
            for (band_loop = 0; band_loop < oal_bit_get_num_four_byte(map_flag.bits.band_type); ++band_loop) {
                band = oal_bit_find_first_bit_four_byte(band_flag);
                conn_nve_get_pow_cali_nv_data(dst_pow_cali, &g_powcal_nv_data[loop], type, band);
                oal_bit_clear_bit_four_byte(&band_flag, band);
            }

            oal_bit_clear_bit_four_byte(&type_flag, type);
        }
    }
}

int32_t conn_nve_write_powcal_to_nvram(void)
{
    uint8_t nv_data[NV_RAM_MAX_SIZE];
    uint32_t crc;

    memset_s(nv_data, NV_RAM_MAX_SIZE, 0, NV_RAM_MAX_SIZE);

    conn_nve_sync_first_pow_cali_from_ram(&POW_DATA_PREFIX);

    if (memcpy_s(nv_data + sizeof(crc), NV_RAM_MAX_SIZE - sizeof(crc),
                 (uint8_t *)g_powcal_nv_data, sizeof(g_powcal_nv_data)) != EOK) {
        return CONN_NVE_ERROR_MEMCPY_FAIL;
    }
    // save crc value about power cali data
    crc = crc32c_conn_nve(CRC32C_REV_SEED, nv_data + sizeof(crc), NV_RAM_MAX_SIZE - sizeof(crc));
    *(uint32_t *)nv_data = crc;

    return conn_nve_nvram_write(nv_data, NV_RAM_MAX_SIZE, CONN_NVE_POWCAL_NAME, CONN_NVE_POWCAL_NUM);
}

int32_t conn_nve_read_powcal_from_nvram(void)
{
    int32_t ret;
    uint8_t nv_data[NV_RAM_MAX_SIZE];
    uint32_t crc;

    ret = conn_nve_nvram_read(nv_data, NV_RAM_MAX_SIZE, CONN_NVE_POWCAL_NAME, CONN_NVE_POWCAL_NUM);
    if (ret != CONN_NVE_RET_OK) {
        return ret;
    }

    crc = crc32c_conn_nve(CRC32C_REV_SEED, nv_data + sizeof(crc), NV_RAM_MAX_SIZE - sizeof(crc));
    if (crc != *(uint32_t *)(nv_data)) {
        pr_err("[CONN_NVE]conn_nve_read_powcal_from_nvram:read data crc check fail");
        return CONN_NVE_ERROR_CRC_FAIL;
    }

    if (memcpy_s((uint8_t *)g_powcal_nv_data, sizeof(g_powcal_nv_data),
                 nv_data + sizeof(uint32_t), sizeof(g_powcal_nv_data)) != EOK) {
        return CONN_NVE_ERROR_MEMCPY_FAIL;
    }

    conn_nve_set_pow_cali_to_ram(&POW_DATA_PREFIX);

    return CONN_NVE_RET_OK;
}

int32_t conn_nve_clear_powcal_nvram(void)
{
    // 此处不能直接把NV写0，应该先把ram里的power cali data清0，再从ram同步到NV
    memset_s(&POW_DATA_PREFIX, sizeof(POW_DATA_PREFIX), 0, sizeof(POW_DATA_PREFIX));
    return conn_nve_write_powcal_to_nvram();
}

int32_t conn_nve_write_tas_powcal_to_nvram(void)
{
    uint8_t nv_data[NV_RAM_MAX_SIZE];
    uint32_t crc;
    uint32_t version = WAL_TAS_VERSION_3_0;

    memset_s(nv_data, NV_RAM_MAX_SIZE, 0, NV_RAM_MAX_SIZE);

    conn_nve_sync_first_pow_cali_from_ram(&g_conn_tas_powcal_nvram.tas_pow_cal_data);
    *(uint32_t *)(nv_data + sizeof(crc)) = version;
    if (memcpy_s(nv_data + sizeof(crc) + sizeof(version), NV_RAM_MAX_SIZE - sizeof(crc) - sizeof(version),
                 (uint8_t *)g_powcal_nv_data, sizeof(g_powcal_nv_data)) != EOK) {
        return CONN_NVE_ERROR_MEMCPY_FAIL;
    }
    // save crc value about tas power cali data
    crc = crc32c_conn_nve(CRC32C_REV_SEED, nv_data + sizeof(crc), NV_RAM_MAX_SIZE - sizeof(crc));
    *(uint32_t *)(nv_data) = crc;

    return conn_nve_nvram_write(nv_data, NV_RAM_MAX_SIZE, CONN_NVE_TAS_NAME, CONN_NVE_TAS_NUM);
}

static int32_t conn_nve_set_tas_nv_to_ram(int8_t* nv_data, uint8_t nv_data_len)
{
    int32_t type_loop;
    uint32_t data_len = sizeof(g_conn_tas_powcal_nvram.tas_pow_cal_data.delta_gain_5g_20[0]);
    for (type_loop = 0; type_loop < POW_TYPE_5G_ALL_NUM; ++type_loop) {
        if (memcpy_s((uint8_t *)(g_conn_tas_powcal_nvram.tas_pow_cal_data.delta_gain_5g_20[0]) +
            data_len * type_loop * WICAL_STREAM_NUM, data_len, nv_data, data_len)) {
            pr_err("[CONN_NVE]conn_nve_set_tas_nv_to_ram:copy data failed, idx=%d", type_loop);
            return CONN_NVE_ERROR_MEMCPY_FAIL;
        }
    }
    return CONN_NVE_RET_OK;
}

int32_t conn_nve_read_tas_powcal_from_nvram(void)
{
    int32_t ret;
    uint8_t nv_data[NV_RAM_MAX_SIZE];
    uint32_t crc;
    uint32_t version;

    ret = conn_nve_nvram_read(nv_data, NV_RAM_MAX_SIZE, CONN_NVE_TAS_NAME, CONN_NVE_TAS_NUM);
    if (ret != CONN_NVE_RET_OK) {
        return ret;
    }

    version = *(uint32_t *)(nv_data + sizeof(crc));
    if (version == WAL_TAS_VERSION_3_0) {
        crc = crc32c_conn_nve(CRC32C_REV_SEED, nv_data + sizeof(crc), NV_RAM_MAX_SIZE - sizeof(crc));
        if (crc != *(uint32_t *)(nv_data)) {
            pr_err("[CONN_NVE]conn_nve_read_tas_powcal_from_nvram:read data crc check fail");
            return CONN_NVE_ERROR_CRC_FAIL;
        }
        if (memcpy_s((uint8_t *)g_powcal_nv_data, sizeof(g_powcal_nv_data),
                     nv_data + sizeof(version) + sizeof(crc), sizeof(g_powcal_nv_data)) != EOK) {
            return CONN_NVE_ERROR_MEMCPY_FAIL;
        }
        conn_nve_set_pow_cali_to_ram(&g_conn_tas_powcal_nvram.tas_pow_cal_data);
        ret = CONN_NVE_RET_OK;
    } else {
        /* tas 1.0 and 2.0 have no crc code and version field */
        ret = conn_nve_set_tas_nv_to_ram(nv_data, NV_RAM_MAX_SIZE);
    }

    return ret;
}

int32_t conn_nve_clear_tas_powcal_nvram(void)
{
    // 此处不能直接把NV写0，应该先把ram里的power cali data清0，再从ram同步到NV
    memset_s(&g_conn_tas_powcal_nvram, sizeof(conn_nve_tas_particion_stru), 0, sizeof(conn_nve_tas_particion_stru));
    return conn_nve_write_tas_powcal_to_nvram();
}

#ifdef CONFIG_IODIE_HKADC
int32_t hisi_conn_nve_update_calidata_file(int8_t *src_path)
{
    int32_t ret;
    uint32_t status;
    uint8_t *buffer = hisi_conn_nve_get_ramdisk(HISI_CONN_WIFI_DATA);
    uint32_t tmp_crc;
    loff_t pos = 0;
    struct file *src_file, *dst_file;
    int i;

    // 打开文件
    src_file = oal_sys_open(src_path, O_RDONLY, (int)S_IRWXU | S_IRWXG | S_IRWXO);
    if (IS_ERR(src_file)) {
        pr_err("[CONN_NVE]:%s Failed to open src file:%ld\n", __func__, PTR_ERR(src_file));
        return -OAL_EFAIL;
    }
    // 读取源文件并写入目标文件
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0))
    ret = oal_sys_read(src_file, buffer, CONN_NVE_SIZE, &pos);
#else
    ret = oal_sys_read(src_file, pos, buffer, CONN_NVE_SIZE);
#endif
    oal_sys_close(src_file);
    if (ret < CONN_NVE_SIZE) {
        pr_err("[CONN_NVE]:%s Failed to read from source file, ret = %d\n", __func__, ret);
        return -OAL_EFAIL;
    }
    pos = 0;

    // crc
    for (i = 0; i < CONN_NVE_IMG_NUM; i++) {
        // check data crc
        tmp_crc = crc32c_conn_nve(CRC32C_REV_SEED, buffer + conn_nve_start_addr(i), CONN_NVE_PARTICION_SIZE);
        if (tmp_crc != ((conn_nve_particion_stru *)(buffer + conn_nve_start_addr(i)))->crc) {
            pr_err("[CONN_NVE]:%s img[%d] crc check failure, new_crc is 0x%X, old_crc is 0x%X!\n", __func__, i,
                tmp_crc, ((conn_nve_particion_stru *)(buffer + conn_nve_start_addr(i)))->crc);
            return -OAL_EFAIL;
        }
    }

    // 写入目标文件
    dst_file = oal_sys_open(CONN_NVE_DEVICE_NAME, O_WRONLY, (int)S_IRWXU | S_IRWXG | S_IRWXO);
    if (IS_ERR(dst_file)) {
        pr_err("[CONN_NVE]:%s Failed to open dst file:%ld\n", __func__, PTR_ERR(dst_file));
        return -OAL_EFAIL;
    }
    ret = oal_sys_write(dst_file, buffer, ret, &pos);
    oal_sys_close(dst_file);
    if (ret < 0) {
        pr_err("[CONN_NVE]:%s Failed to write to destination file: %zd\n", __func__, ret);
        return -OAL_EFAIL;
    }
    status = conn_nve_get_data_status(CONN_STATUS_DPD, OAL_TRUE);
    if ((status >> CONN_NVE_VALID_DATA_FLAG_OFFSET) != CONN_NVE_VALID_DATA_ALL_MASK) {
        return -OAL_EFAIL;
    }
    return OAL_SUCC;
}
#endif
#endif
