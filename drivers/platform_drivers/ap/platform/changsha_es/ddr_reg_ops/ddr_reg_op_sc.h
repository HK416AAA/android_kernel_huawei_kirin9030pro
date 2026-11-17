#ifndef __DDR_REG_OP_SC_H__
#define __DDR_REG_OP_SC_H__ 
#include <soc_acpu_baseaddr_interface.h>
#include <ddr_reg_ops/ddr_reg_op_logic.h>
#include <soc_sc_interface.h>
#define GET_MEMBER_SC_CFG(reg_val,offset) \
do { \
 reg_val = ddr_readl(SOC_SC_##offset##_ADDR(SOC_ACPU_SC_CFG_BASE_ADDR)); \
} while (0)
#define SET_MEMBER_CACHE_SC_CFG(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(SC, reg_val, offset, member, cfg_val)
#define SET_MEMBER_FLUSH_SC_CFG(reg_val,offset) \
do { \
 ddr_writel(reg_val, SOC_SC_##offset##_ADDR(SOC_ACPU_SC_CFG_BASE_ADDR)); \
} while (0)
#define GET_MEMBER_SC_CFGCMO_CFG(reg_val,offset) \
do { \
 reg_val = ddr_readl(SOC_CFG_##offset##_ADDR(SOC_ACPU_SC_CFG_BASE_ADDR)); \
} while (0)
#define SC_SILICE_INDEX_OFFSET 0X10000
#define GET_MEMBER_SC_CFG_SLICE(reg_val,offset,slice) \
do { \
 reg_val = ddr_readl(SOC_SC_##offset##_ADDR(SOC_ACPU_SC_CFG_BASE_ADDR + slice * SC_SILICE_INDEX_OFFSET)); \
} while (0)
#define SET_MEMBER_FLUSH_SC_CFG_SLICE(reg_val,offset,slice) \
do { \
 ddr_writel(reg_val, SOC_SC_##offset##_ADDR(SOC_ACPU_SC_CFG_BASE_ADDR + slice * SC_SILICE_INDEX_OFFSET)); \
} while (0)
#define GET_MEMBER_SC_CFG_SLICE_IDX(reg_val,offset,slice,idx) \
do { \
 reg_val = ddr_readl(SOC_SC_##offset##_ADDR(SOC_ACPU_SC_CFG_BASE_ADDR + slice * SC_SILICE_INDEX_OFFSET, idx)); \
} while (0)
#define SET_MEMBER_SC_CFG_SLICE_IDX(reg_val,offset,slice,idx) \
do { \
 ddr_writel(reg_val, SOC_SC_##offset##_ADDR(SOC_ACPU_SC_CFG_BASE_ADDR + slice * SC_SILICE_INDEX_OFFSET, idx)); \
} while (0)
#endif
