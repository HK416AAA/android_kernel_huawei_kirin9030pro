#ifndef __DDR_REG_OP_QICE_TBED_DMC_CD_H__
#define __DDR_REG_OP_QICE_TBED_DMC_CD_H__ 
#include <ddr_reg_ops/ddr_reg_op_logic.h>
#include "ddr_reg_op_qice_common.h"
#include <soc_qice_tbed_interface.h>
#define GET_MEMBER_QICE_TBED_DMC_CD(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, TBED, TBED_DMC_CD)
#define SAVE_MEMBER_QICE_TBED_DMC_CD(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, TBED, TBED_DMC_CD)
#define GET_MEMBER_CACHE_QICE_TBED_DMC_CD(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(QICE_TBED, reg_val, offset, member, result);
#define GET_MEMBER_QICE_TBED_DMC_CD_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, TBED, TBED_DMC_CD, x)
#define SAVE_MEMBER_QICE_TBED_DMC_CD_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, TBED, TBED_DMC_CD, x)
#define SET_MEMBER_CACHE_QICE_TBED_DMC_CD(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(QICE_TBED, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_QICE_TBED_DMC_CD(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(QICE_TBED, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_QICE_TBED_DMC_CD(reg_val,offset) \
 SET_MEMBER_FLUSH_QICE(reg_val, offset, TBED, TBED_DMC_CD)
#define SET_MEMBER_FLUSH_QICE_TBED_DMC_CD_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_QICE_X(reg_val, offset, TBED, TBED_DMC_CD, x)
#define WAIT_MEMBER_QICE_TBED_DMC_CD_STAT(offset,member,expect_val) \
 WAIT_MEMBER_QICE_STAT(offset, member, expect_val, TBED, TBED_DMC_CD)
#define CHECK_MEMBER_QICE_TBED_DMC_CD_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_QICE_STAT(offset, member, expect_val, result, TBED, TBED_DMC_CD)
#define WAIT_REGVAL_QICE_TBED_DMC_CD_STAT(offset,expect_val) \
 WAIT_REGVAL_QICE_STAT(offset, expect_val, TBED, TBED_DMC_CD)
#define WAIT_REGVAL_QICE_TBED_DMC_CD_STAT_X(offset,expect_val,x) \
 WAIT_REGVAL_QICE_STAT_X(offset, expect_val, TBED, TBED_DMC_CD, x)
#define CHECK_REGVAL_QICE_TBED_DMC_CD_STAT(offset,expect_val,result) \
 CHECK_REGVAL_QICE_STAT(offset, expect_val, result, TBED, TBED_DMC_CD)
#endif
