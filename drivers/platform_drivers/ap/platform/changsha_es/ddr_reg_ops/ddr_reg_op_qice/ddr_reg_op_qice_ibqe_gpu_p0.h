#ifndef __DDR_REG_OP_QICE_IBQE_GPU_P0_H__
#define __DDR_REG_OP_QICE_IBQE_GPU_P0_H__ 
#include <ddr_reg_ops/ddr_reg_op_logic.h>
#include "ddr_reg_op_qice_common.h"
#include <soc_qice_ibqe_interface.h>
#define GET_MEMBER_QICE_IBQE_GPU_P0(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, IBQE, IBQE_GPU_P0)
#define SAVE_MEMBER_QICE_IBQE_GPU_P0(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, IBQE, IBQE_GPU_P0)
#define GET_MEMBER_CACHE_QICE_IBQE_GPU_P0(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(QICE_IBQE, reg_val, offset, member, result);
#define GET_MEMBER_QICE_IBQE_GPU_P0_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, IBQE, IBQE_GPU_P0, x)
#define SAVE_MEMBER_QICE_IBQE_GPU_P0_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, IBQE, IBQE_GPU_P0, x)
#define SET_MEMBER_CACHE_QICE_IBQE_GPU_P0(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(QICE_IBQE, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_QICE_IBQE_GPU_P0(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(QICE_IBQE, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_QICE_IBQE_GPU_P0(reg_val,offset) \
 SET_MEMBER_FLUSH_QICE(reg_val, offset, IBQE, IBQE_GPU_P0)
#define SET_MEMBER_FLUSH_QICE_IBQE_GPU_P0_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_QICE_X(reg_val, offset, IBQE, IBQE_GPU_P0, x)
#define WAIT_MEMBER_QICE_IBQE_GPU_P0_STAT(offset,member,expect_val) \
 WAIT_MEMBER_QICE_STAT(offset, member, expect_val, IBQE, IBQE_GPU_P0)
#define CHECK_MEMBER_QICE_IBQE_GPU_P0_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_QICE_STAT(offset, member, expect_val, result, IBQE, IBQE_GPU_P0)
#define WAIT_REGVAL_QICE_IBQE_GPU_P0_STAT(offset,expect_val) \
 WAIT_REGVAL_QICE_STAT(offset, expect_val, IBQE, IBQE_GPU_P0)
#define WAIT_REGVAL_QICE_IBQE_GPU_P0_STAT_X(offset,expect_val,x) \
 WAIT_REGVAL_QICE_STAT_X(offset, expect_val, IBQE, IBQE_GPU_P0, x)
#define CHECK_REGVAL_QICE_IBQE_GPU_P0_STAT(offset,expect_val,result) \
 CHECK_REGVAL_QICE_STAT(offset, expect_val, result, IBQE, IBQE_GPU_P0)
#endif
