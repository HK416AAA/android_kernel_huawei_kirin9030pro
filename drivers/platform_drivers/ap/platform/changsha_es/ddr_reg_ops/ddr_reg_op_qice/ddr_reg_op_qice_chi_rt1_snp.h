#ifndef __DDR_REG_OP_QICE_CHI_RT1_SNP_H__
#define __DDR_REG_OP_QICE_CHI_RT1_SNP_H__ 
#include <ddr_reg_ops/ddr_reg_op_logic.h>
#include "ddr_reg_op_qice_common.h"
#include <soc_qice_chi_rt_interface.h>
#define GET_MEMBER_QICE_CHI_RT1_SNP(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, CHI_RT, CHI_RT1_SNP)
#define SAVE_MEMBER_QICE_CHI_RT1_SNP(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, CHI_RT, CHI_RT1_SNP)
#define GET_MEMBER_CACHE_QICE_CHI_RT1_SNP(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(QICE_CHI_RT, reg_val, offset, member, result);
#define GET_MEMBER_QICE_CHI_RT1_SNP_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, CHI_RT, CHI_RT1_SNP, x)
#define SAVE_MEMBER_QICE_CHI_RT1_SNP_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, CHI_RT, CHI_RT1_SNP, x)
#define SET_MEMBER_CACHE_QICE_CHI_RT1_SNP(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(QICE_CHI_RT, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_QICE_CHI_RT1_SNP(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(QICE_CHI_RT, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_QICE_CHI_RT1_SNP(reg_val,offset) \
 SET_MEMBER_FLUSH_QICE(reg_val, offset, CHI_RT, CHI_RT1_SNP)
#define SET_MEMBER_FLUSH_QICE_CHI_RT1_SNP_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_QICE_X(reg_val, offset, CHI_RT, CHI_RT1_SNP, x)
#define WAIT_MEMBER_QICE_CHI_RT1_SNP_STAT(offset,member,expect_val) \
 WAIT_MEMBER_QICE_STAT(offset, member, expect_val, CHI_RT, CHI_RT1_SNP)
#define CHECK_MEMBER_QICE_CHI_RT1_SNP_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_QICE_STAT(offset, member, expect_val, result, CHI_RT, CHI_RT1_SNP)
#define WAIT_REGVAL_QICE_CHI_RT1_SNP_STAT(offset,expect_val) \
 WAIT_REGVAL_QICE_STAT(offset, expect_val, CHI_RT, CHI_RT1_SNP)
#define WAIT_REGVAL_QICE_CHI_RT1_SNP_STAT_X(offset,expect_val,x) \
 WAIT_REGVAL_QICE_STAT_X(offset, expect_val, CHI_RT, CHI_RT1_SNP, x)
#define CHECK_REGVAL_QICE_CHI_RT1_SNP_STAT(offset,expect_val,result) \
 CHECK_REGVAL_QICE_STAT(offset, expect_val, result, CHI_RT, CHI_RT1_SNP)
#endif
