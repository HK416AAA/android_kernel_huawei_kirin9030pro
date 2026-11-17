#ifndef __DDR_XPU_PRODUCT_STATE_H__
#define __DDR_XPU_PRODUCT_STATE_H__ 
#include "ddr/ddr_remap_interface.h"
#include "soc_efuse_interface.h"
#include "ddr/ddrtest_global_sram_map.h"
#include "ddr_xpu_sram_map.h"
#include "xloader_partition.h"
#include "ddr/ddr_screen_data_stuct.h"
#include "ddr/ddr_xpu_open_product_sram_map.h"
#include "boardid.h"
#define READER_NEED_CLEAR 1
#define READER_NO_NEED_CLEAR 0
struct efuse_reader_item {
    unsigned int start_bit;
    unsigned int bit_cnt;
    unsigned int target_buf_addr;
    unsigned int buf_size;
    unsigned int item_id;
    unsigned int efuse_id;
};
struct storage_reader_item {
    char ptable_name[PTABLE_NAME_MAX];
    unsigned int offset;
    unsigned int dst;
    unsigned int len;
    unsigned int if_need_clear;
};
struct nve_reader_item {
    unsigned int nve_number;
    unsigned int dst;
    unsigned int len;
};
struct state_reader_item {
    unsigned int (*get)(void);
    unsigned int dst;
};
const struct efuse_reader_item g_ddr_product_efuse[] =
{
    {
        .target_buf_addr = DIED_ID_BASE,
        .buf_size = EFUSE_DIEID_GROUP_WIDTH,
        .start_bit = EFUSE_DIEID_VALUE_START,
        .bit_cnt = EFUSE_DIEID_VALUE_SIZE,
        .item_id = EFUSE_DIEID_VALUE,
        .efuse_id = SYS_EFUSE1,
    },
};
#ifndef DDR_TMP_STUB
const unsigned int g_ddr_product_efuse_len = ARRAY_SIZE(g_ddr_product_efuse);
#else
const unsigned int g_ddr_product_efuse_len = 0;
#endif
const struct storage_reader_item g_ddr_product_storage[] =
{
#if defined(FACTORY_VERSION)
    {
        .ptable_name = DDR_SCREEN_EXMBIST_TEST_PART,
        .offset = DDR_SCREEN_EXMBIST_CTRL_OFFSET,
        .dst = SCREEN_EXMBIST_CTRL_BASE,
        .len = SCREEN_EXMBIST_CTRL_SIZE,
        .if_need_clear = READER_NEED_CLEAR,
    },
    {
        .ptable_name = PART_DDR_TEST_LOG,
        .offset = STORAGE_FSM_LOG_OFFSET,
        .dst = DDRTEST_FSM_PROCESS_BASE,
        .len = DDRTEST_FSM_PROCESS_SIZE,
        .if_need_clear = READER_NO_NEED_CLEAR,
    },
    {
        .ptable_name = PART_DDR_FAC,
        .offset = RESTORE_DDR_DRAM_VOL_SCALING_CTRL_ADDR,
        .dst = DDRAVS_VOLTAGE_CTRL_BASE,
        .len = DDRAVS_VOLTAGE_CTRL_SIZE,
    },
    {
        .ptable_name = PART_DDR_FAC,
        .offset = RESTORE_DDR_DRAM_TREFI_SCALING_CTRL_ADDR,
        .dst = DDRAVS_TREFI_CTRL_BASE,
        .len = DDRAVS_TREFI_CTRL_SIZE,
    },
#endif
    {
        .ptable_name = PART_DDR_FAC,
        .offset = RESTORE_DDR_DRAM_VOL_SCALING_RESULT_ADDR,
        .dst = DDRAVS_VOLTAGE_RESULT_BASE,
        .len = DDRAVS_VOLTAGE_RESULT_SIZE,
    },
    {
        .ptable_name = PART_DDR_FAC,
        .offset = RESTORE_DDR_DRAM_TREFI_SCALING_RESULT_ADDR,
        .dst = DDRAVS_TREFI_RESULT_BASE,
        .len = DDRAVS_TREFI_RESULT_SIZE,
    },
    {
        .ptable_name = PART_MISC,
        .offset = 0,
        .dst = DDR_PENGLAI_BASE,
        .len = DDR_PENGLAI_SIZE,
    }
};
const unsigned int g_ddr_product_storage_len = ARRAY_SIZE(g_ddr_product_storage);
const struct nve_reader_item g_ddr_product_nve[] =
{
    {
        .nve_number = DDR_NV_NUM,
        .dst = PPR_NV_BASE,
        .len = PPR_NV_SIZE,
    },
};
const unsigned int g_ddr_product_nve_len = ARRAY_SIZE(g_ddr_product_nve);
static inline unsigned int product_get_boardid(void)
{
    return (unsigned int)get_boardid();
}
const struct state_reader_item g_ddr_product_state[] =
{
    {
        .get = product_get_boardid,
        .dst = BOARDID_BASE,
    },
};
const unsigned int g_ddr_product_state_len = ARRAY_SIZE(g_ddr_product_state);
#endif
