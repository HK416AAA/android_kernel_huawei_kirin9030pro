#ifndef __DDR_REG_OP_QICE_QIC_COMMON_MISC_NPU_H__
#define __DDR_REG_OP_QICE_QIC_COMMON_MISC_NPU_H__ 
#include <ddr_reg_ops/ddr_reg_op_logic.h>
#include "ddr_reg_op_qice_common.h"
#include <soc_qice_common_misc_npu_interface.h>
#define GET_MEMBER_QICE_QIC_COMMON_MISC_NPU(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, COMMON_MISC_NPU, QIC_COMMON_MISC_NPU)
#define SAVE_MEMBER_QICE_QIC_COMMON_MISC_NPU(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, COMMON_MISC_NPU, QIC_COMMON_MISC_NPU)
#define GET_MEMBER_CACHE_QICE_QIC_COMMON_MISC_NPU(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(QICE_COMMON_MISC_NPU, reg_val, offset, member, result);
#define GET_MEMBER_QICE_QIC_COMMON_MISC_NPU_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, COMMON_MISC_NPU, QIC_COMMON_MISC_NPU, x)
#define SAVE_MEMBER_QICE_QIC_COMMON_MISC_NPU_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, COMMON_MISC_NPU, QIC_COMMON_MISC_NPU, x)
#define SET_MEMBER_CACHE_QICE_QIC_COMMON_MISC_NPU(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(QICE_COMMON_MISC_NPU, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_QICE_QIC_COMMON_MISC_NPU(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(QICE_COMMON_MISC_NPU, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_QICE_QIC_COMMON_MISC_NPU(reg_val,offset) \
 SET_MEMBER_FLUSH_QICE(reg_val, offset, COMMON_MISC_NPU, QIC_COMMON_MISC_NPU)
#define SET_MEMBER_FLUSH_QICE_QIC_COMMON_MISC_NPU_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_QICE_X(reg_val, offset, COMMON_MISC_NPU, QIC_COMMON_MISC_NPU, x)
#define WAIT_MEMBER_QICE_QIC_COMMON_MISC_NPU_STAT(offset,member,expect_val) \
 WAIT_MEMBER_QICE_STAT(offset, member, expect_val, COMMON_MISC_NPU, QIC_COMMON_MISC_NPU)
#define CHECK_MEMBER_QICE_QIC_COMMON_MISC_NPU_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_QICE_STAT(offset, member, expect_val, result, COMMON_MISC_NPU, QIC_COMMON_MISC_NPU)
#define WAIT_REGVAL_QICE_QIC_COMMON_MISC_NPU_STAT(offset,expect_val) \
 WAIT_REGVAL_QICE_STAT(offset, expect_val, COMMON_MISC_NPU, QIC_COMMON_MISC_NPU)
#define WAIT_REGVAL_QICE_QIC_COMMON_MISC_NPU_STAT_X(offset,expect_val,x) \
 WAIT_REGVAL_QICE_STAT_X(offset, expect_val, COMMON_MISC_NPU, QIC_COMMON_MISC_NPU, x)
#define CHECK_REGVAL_QICE_QIC_COMMON_MISC_NPU_STAT(offset,expect_val,result) \
 CHECK_REGVAL_QICE_STAT(offset, expect_val, result, COMMON_MISC_NPU, QIC_COMMON_MISC_NPU)
#endif
