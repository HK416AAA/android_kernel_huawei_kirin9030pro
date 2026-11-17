#ifndef __DDR_REG_OP_QICE_CHI_RT1_SRSP_H__
#define __DDR_REG_OP_QICE_CHI_RT1_SRSP_H__ 
#include <ddr_reg_ops/ddr_reg_op_logic.h>
#include "ddr_reg_op_qice_common.h"
#include <soc_qice_chi_rt_interface.h>
#define GET_MEMBER_QICE_CHI_RT1_SRSP(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, CHI_RT, CHI_RT1_SRSP)
#define SAVE_MEMBER_QICE_CHI_RT1_SRSP(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, CHI_RT, CHI_RT1_SRSP)
#define GET_MEMBER_CACHE_QICE_CHI_RT1_SRSP(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(QICE_CHI_RT, reg_val, offset, member, result);
#define GET_MEMBER_QICE_CHI_RT1_SRSP_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, CHI_RT, CHI_RT1_SRSP, x)
#define SAVE_MEMBER_QICE_CHI_RT1_SRSP_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, CHI_RT, CHI_RT1_SRSP, x)
#define SET_MEMBER_CACHE_QICE_CHI_RT1_SRSP(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(QICE_CHI_RT, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_QICE_CHI_RT1_SRSP(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(QICE_CHI_RT, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_QICE_CHI_RT1_SRSP(reg_val,offset) \
 SET_MEMBER_FLUSH_QICE(reg_val, offset, CHI_RT, CHI_RT1_SRSP)
#define SET_MEMBER_FLUSH_QICE_CHI_RT1_SRSP_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_QICE_X(reg_val, offset, CHI_RT, CHI_RT1_SRSP, x)
#define WAIT_MEMBER_QICE_CHI_RT1_SRSP_STAT(offset,member,expect_val) \
 WAIT_MEMBER_QICE_STAT(offset, member, expect_val, CHI_RT, CHI_RT1_SRSP)
#define CHECK_MEMBER_QICE_CHI_RT1_SRSP_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_QICE_STAT(offset, member, expect_val, result, CHI_RT, CHI_RT1_SRSP)
#define WAIT_REGVAL_QICE_CHI_RT1_SRSP_STAT(offset,expect_val) \
 WAIT_REGVAL_QICE_STAT(offset, expect_val, CHI_RT, CHI_RT1_SRSP)
#define WAIT_REGVAL_QICE_CHI_RT1_SRSP_STAT_X(offset,expect_val,x) \
 WAIT_REGVAL_QICE_STAT_X(offset, expect_val, CHI_RT, CHI_RT1_SRSP, x)
#define CHECK_REGVAL_QICE_CHI_RT1_SRSP_STAT(offset,expect_val,result) \
 CHECK_REGVAL_QICE_STAT(offset, expect_val, result, CHI_RT, CHI_RT1_SRSP)
#endif
