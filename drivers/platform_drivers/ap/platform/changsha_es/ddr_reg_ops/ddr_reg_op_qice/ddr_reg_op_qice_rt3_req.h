#ifndef __DDR_REG_OP_QICE_RT3_REQ_H__
#define __DDR_REG_OP_QICE_RT3_REQ_H__ 
#include <ddr_reg_ops/ddr_reg_op_logic.h>
#include "ddr_reg_op_qice_common.h"
#include <soc_qice_rt_interface.h>
#define GET_MEMBER_QICE_RT3_REQ(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, RT, RT3_REQ)
#define SAVE_MEMBER_QICE_RT3_REQ(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, RT, RT3_REQ)
#define GET_MEMBER_CACHE_QICE_RT3_REQ(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(QICE_RT, reg_val, offset, member, result);
#define GET_MEMBER_QICE_RT3_REQ_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, RT, RT3_REQ, x)
#define SAVE_MEMBER_QICE_RT3_REQ_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, RT, RT3_REQ, x)
#define SET_MEMBER_CACHE_QICE_RT3_REQ(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(QICE_RT, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_QICE_RT3_REQ(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(QICE_RT, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_QICE_RT3_REQ(reg_val,offset) \
 SET_MEMBER_FLUSH_QICE(reg_val, offset, RT, RT3_REQ)
#define SET_MEMBER_FLUSH_QICE_RT3_REQ_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_QICE_X(reg_val, offset, RT, RT3_REQ, x)
#define WAIT_MEMBER_QICE_RT3_REQ_STAT(offset,member,expect_val) \
 WAIT_MEMBER_QICE_STAT(offset, member, expect_val, RT, RT3_REQ)
#define CHECK_MEMBER_QICE_RT3_REQ_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_QICE_STAT(offset, member, expect_val, result, RT, RT3_REQ)
#define WAIT_REGVAL_QICE_RT3_REQ_STAT(offset,expect_val) \
 WAIT_REGVAL_QICE_STAT(offset, expect_val, RT, RT3_REQ)
#define WAIT_REGVAL_QICE_RT3_REQ_STAT_X(offset,expect_val,x) \
 WAIT_REGVAL_QICE_STAT_X(offset, expect_val, RT, RT3_REQ, x)
#define CHECK_REGVAL_QICE_RT3_REQ_STAT(offset,expect_val,result) \
 CHECK_REGVAL_QICE_STAT(offset, expect_val, result, RT, RT3_REQ)
#endif
