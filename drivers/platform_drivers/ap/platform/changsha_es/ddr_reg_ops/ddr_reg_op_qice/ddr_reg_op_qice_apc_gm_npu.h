#ifndef __DDR_REG_OP_QICE_APC_GM_NPU_H__
#define __DDR_REG_OP_QICE_APC_GM_NPU_H__ 
#include <ddr_reg_ops/ddr_reg_op_logic.h>
#include "ddr_reg_op_qice_common.h"
#include <soc_qice_gm_apc_interface.h>
#define GET_MEMBER_QICE_APC_GM_NPU(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, GM_APC, APC_GM_NPU)
#define SAVE_MEMBER_QICE_APC_GM_NPU(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, GM_APC, APC_GM_NPU)
#define GET_MEMBER_CACHE_QICE_APC_GM_NPU(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(QICE_GM_APC, reg_val, offset, member, result);
#define GET_MEMBER_QICE_APC_GM_NPU_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, GM_APC, APC_GM_NPU, x)
#define SAVE_MEMBER_QICE_APC_GM_NPU_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, GM_APC, APC_GM_NPU, x)
#define SET_MEMBER_CACHE_QICE_APC_GM_NPU(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(QICE_GM_APC, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_QICE_APC_GM_NPU(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(QICE_GM_APC, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_QICE_APC_GM_NPU(reg_val,offset) \
 SET_MEMBER_FLUSH_QICE(reg_val, offset, GM_APC, APC_GM_NPU)
#define SET_MEMBER_FLUSH_QICE_APC_GM_NPU_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_QICE_X(reg_val, offset, GM_APC, APC_GM_NPU, x)
#define WAIT_MEMBER_QICE_APC_GM_NPU_STAT(offset,member,expect_val) \
 WAIT_MEMBER_QICE_STAT(offset, member, expect_val, GM_APC, APC_GM_NPU)
#define CHECK_MEMBER_QICE_APC_GM_NPU_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_QICE_STAT(offset, member, expect_val, result, GM_APC, APC_GM_NPU)
#define WAIT_REGVAL_QICE_APC_GM_NPU_STAT(offset,expect_val) \
 WAIT_REGVAL_QICE_STAT(offset, expect_val, GM_APC, APC_GM_NPU)
#define WAIT_REGVAL_QICE_APC_GM_NPU_STAT_X(offset,expect_val,x) \
 WAIT_REGVAL_QICE_STAT_X(offset, expect_val, GM_APC, APC_GM_NPU, x)
#define CHECK_REGVAL_QICE_APC_GM_NPU_STAT(offset,expect_val,result) \
 CHECK_REGVAL_QICE_STAT(offset, expect_val, result, GM_APC, APC_GM_NPU)
#endif
