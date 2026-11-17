#ifndef __DDR_REG_OP_QICE_QSP2TO1_WA_MDM_DDR_H__
#define __DDR_REG_OP_QICE_QSP2TO1_WA_MDM_DDR_H__ 
#include <ddr_reg_ops/ddr_reg_op_logic.h>
#include "ddr_reg_op_qice_common.h"
#include <soc_qice_qsp2to1_wa_top_wrap_interface.h>
#define GET_MEMBER_QICE_QSP2TO1_WA_MDM_DDR(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, QSP2TO1_WA_TOP_WRAP, QSP2TO1_WA_MDM_DDR)
#define SAVE_MEMBER_QICE_QSP2TO1_WA_MDM_DDR(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, QSP2TO1_WA_TOP_WRAP, QSP2TO1_WA_MDM_DDR)
#define GET_MEMBER_CACHE_QICE_QSP2TO1_WA_MDM_DDR(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(QICE_QSP2TO1_WA_TOP_WRAP, reg_val, offset, member, result);
#define GET_MEMBER_QICE_QSP2TO1_WA_MDM_DDR_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, QSP2TO1_WA_TOP_WRAP, QSP2TO1_WA_MDM_DDR, x)
#define SAVE_MEMBER_QICE_QSP2TO1_WA_MDM_DDR_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, QSP2TO1_WA_TOP_WRAP, QSP2TO1_WA_MDM_DDR, x)
#define SET_MEMBER_CACHE_QICE_QSP2TO1_WA_MDM_DDR(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(QICE_QSP2TO1_WA_TOP_WRAP, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_QICE_QSP2TO1_WA_MDM_DDR(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(QICE_QSP2TO1_WA_TOP_WRAP, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_QICE_QSP2TO1_WA_MDM_DDR(reg_val,offset) \
 SET_MEMBER_FLUSH_QICE(reg_val, offset, QSP2TO1_WA_TOP_WRAP, QSP2TO1_WA_MDM_DDR)
#define SET_MEMBER_FLUSH_QICE_QSP2TO1_WA_MDM_DDR_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_QICE_X(reg_val, offset, QSP2TO1_WA_TOP_WRAP, QSP2TO1_WA_MDM_DDR, x)
#define WAIT_MEMBER_QICE_QSP2TO1_WA_MDM_DDR_STAT(offset,member,expect_val) \
 WAIT_MEMBER_QICE_STAT(offset, member, expect_val, QSP2TO1_WA_TOP_WRAP, QSP2TO1_WA_MDM_DDR)
#define CHECK_MEMBER_QICE_QSP2TO1_WA_MDM_DDR_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_QICE_STAT(offset, member, expect_val, result, QSP2TO1_WA_TOP_WRAP, QSP2TO1_WA_MDM_DDR)
#define WAIT_REGVAL_QICE_QSP2TO1_WA_MDM_DDR_STAT(offset,expect_val) \
 WAIT_REGVAL_QICE_STAT(offset, expect_val, QSP2TO1_WA_TOP_WRAP, QSP2TO1_WA_MDM_DDR)
#define WAIT_REGVAL_QICE_QSP2TO1_WA_MDM_DDR_STAT_X(offset,expect_val,x) \
 WAIT_REGVAL_QICE_STAT_X(offset, expect_val, QSP2TO1_WA_TOP_WRAP, QSP2TO1_WA_MDM_DDR, x)
#define CHECK_REGVAL_QICE_QSP2TO1_WA_MDM_DDR_STAT(offset,expect_val,result) \
 CHECK_REGVAL_QICE_STAT(offset, expect_val, result, QSP2TO1_WA_TOP_WRAP, QSP2TO1_WA_MDM_DDR)
#endif
