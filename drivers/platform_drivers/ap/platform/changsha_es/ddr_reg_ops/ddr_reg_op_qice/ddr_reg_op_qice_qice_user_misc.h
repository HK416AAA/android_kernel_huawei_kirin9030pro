#ifndef __DDR_REG_OP_QICE_USER_MISC_H__
#define __DDR_REG_OP_QICE_USER_MISC_H__ 
#include <ddr_reg_ops/ddr_reg_op_logic.h>
#include "ddr_reg_op_qice_common.h"
#include <soc_qice_main_misc_user_interface.h>
#define GET_MEMBER_QICE_USER_MISC(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, MAIN_MISC_USER, QICE_USER_MISC)
#define SAVE_MEMBER_QICE_USER_MISC(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, MAIN_MISC_USER, QICE_USER_MISC)
#define GET_MEMBER_CACHE_QICE_USER_MISC(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(QICE_MAIN_MISC_USER, reg_val, offset, member, result);
#define GET_MEMBER_QICE_USER_MISC_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, MAIN_MISC_USER, QICE_USER_MISC, x)
#define SAVE_MEMBER_QICE_USER_MISC_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, MAIN_MISC_USER, QICE_USER_MISC, x)
#define SET_MEMBER_CACHE_QICE_USER_MISC(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(QICE_MAIN_MISC_USER, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_QICE_USER_MISC(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(QICE_MAIN_MISC_USER, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_QICE_USER_MISC(reg_val,offset) \
 SET_MEMBER_FLUSH_QICE(reg_val, offset, MAIN_MISC_USER, QICE_USER_MISC)
#define SET_MEMBER_FLUSH_QICE_USER_MISC_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_QICE_X(reg_val, offset, MAIN_MISC_USER, QICE_USER_MISC, x)
#define WAIT_MEMBER_QICE_USER_MISC_STAT(offset,member,expect_val) \
 WAIT_MEMBER_QICE_STAT(offset, member, expect_val, MAIN_MISC_USER, QICE_USER_MISC)
#define CHECK_MEMBER_QICE_USER_MISC_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_QICE_STAT(offset, member, expect_val, result, MAIN_MISC_USER, QICE_USER_MISC)
#define WAIT_REGVAL_QICE_USER_MISC_STAT(offset,expect_val) \
 WAIT_REGVAL_QICE_STAT(offset, expect_val, MAIN_MISC_USER, QICE_USER_MISC)
#define WAIT_REGVAL_QICE_USER_MISC_STAT_X(offset,expect_val,x) \
 WAIT_REGVAL_QICE_STAT_X(offset, expect_val, MAIN_MISC_USER, QICE_USER_MISC, x)
#define CHECK_REGVAL_QICE_USER_MISC_STAT(offset,expect_val,result) \
 CHECK_REGVAL_QICE_STAT(offset, expect_val, result, MAIN_MISC_USER, QICE_USER_MISC)
#endif
