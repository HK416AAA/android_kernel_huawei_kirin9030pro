#ifndef __DDR_REG_OP_QICE_APCR_H__
#define __DDR_REG_OP_QICE_APCR_H__ 
#include <ddr_reg_ops/ddr_reg_op_logic.h>
#include "ddr_reg_op_qice_common.h"
#include <soc_qice_apcr_interface.h>
#define GET_MEMBER_QICE_APCR(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, APCR, APCR)
#define SAVE_MEMBER_QICE_APCR(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, APCR, APCR)
#define GET_MEMBER_CACHE_QICE_APCR(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(QICE_APCR, reg_val, offset, member, result);
#define GET_MEMBER_QICE_APCR_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, APCR, APCR, x)
#define SAVE_MEMBER_QICE_APCR_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, APCR, APCR, x)
#define SET_MEMBER_CACHE_QICE_APCR(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(QICE_APCR, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_QICE_APCR(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(QICE_APCR, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_QICE_APCR(reg_val,offset) \
 SET_MEMBER_FLUSH_QICE(reg_val, offset, APCR, APCR)
#define SET_MEMBER_FLUSH_QICE_APCR_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_QICE_X(reg_val, offset, APCR, APCR, x)
#define WAIT_MEMBER_QICE_APCR_STAT(offset,member,expect_val) \
 WAIT_MEMBER_QICE_STAT(offset, member, expect_val, APCR, APCR)
#define CHECK_MEMBER_QICE_APCR_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_QICE_STAT(offset, member, expect_val, result, APCR, APCR)
#define WAIT_REGVAL_QICE_APCR_STAT(offset,expect_val) \
 WAIT_REGVAL_QICE_STAT(offset, expect_val, APCR, APCR)
#define WAIT_REGVAL_QICE_APCR_STAT_X(offset,expect_val,x) \
 WAIT_REGVAL_QICE_STAT_X(offset, expect_val, APCR, APCR, x)
#define CHECK_REGVAL_QICE_APCR_STAT(offset,expect_val,result) \
 CHECK_REGVAL_QICE_STAT(offset, expect_val, result, APCR, APCR)
#endif
