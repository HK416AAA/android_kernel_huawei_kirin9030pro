#ifndef __DDR_REG_OP_QICE_QTPE_WA_H0_RXDATA_H__
#define __DDR_REG_OP_QICE_QTPE_WA_H0_RXDATA_H__ 
#include <ddr_reg_ops/ddr_reg_op_logic.h>
#include "ddr_reg_op_qice_common.h"
#include <soc_qice_qtpe_wa_interface.h>
#define GET_MEMBER_QICE_QTPE_WA_H0_RXDATA(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, QTPE_WA, QTPE_WA_H0_RXDATA)
#define SAVE_MEMBER_QICE_QTPE_WA_H0_RXDATA(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, QTPE_WA, QTPE_WA_H0_RXDATA)
#define GET_MEMBER_CACHE_QICE_QTPE_WA_H0_RXDATA(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(QICE_QTPE_WA, reg_val, offset, member, result);
#define GET_MEMBER_QICE_QTPE_WA_H0_RXDATA_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, QTPE_WA, QTPE_WA_H0_RXDATA, x)
#define SAVE_MEMBER_QICE_QTPE_WA_H0_RXDATA_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, QTPE_WA, QTPE_WA_H0_RXDATA, x)
#define SET_MEMBER_CACHE_QICE_QTPE_WA_H0_RXDATA(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(QICE_QTPE_WA, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_QICE_QTPE_WA_H0_RXDATA(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(QICE_QTPE_WA, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_QICE_QTPE_WA_H0_RXDATA(reg_val,offset) \
 SET_MEMBER_FLUSH_QICE(reg_val, offset, QTPE_WA, QTPE_WA_H0_RXDATA)
#define SET_MEMBER_FLUSH_QICE_QTPE_WA_H0_RXDATA_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_QICE_X(reg_val, offset, QTPE_WA, QTPE_WA_H0_RXDATA, x)
#define WAIT_MEMBER_QICE_QTPE_WA_H0_RXDATA_STAT(offset,member,expect_val) \
 WAIT_MEMBER_QICE_STAT(offset, member, expect_val, QTPE_WA, QTPE_WA_H0_RXDATA)
#define CHECK_MEMBER_QICE_QTPE_WA_H0_RXDATA_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_QICE_STAT(offset, member, expect_val, result, QTPE_WA, QTPE_WA_H0_RXDATA)
#define WAIT_REGVAL_QICE_QTPE_WA_H0_RXDATA_STAT(offset,expect_val) \
 WAIT_REGVAL_QICE_STAT(offset, expect_val, QTPE_WA, QTPE_WA_H0_RXDATA)
#define WAIT_REGVAL_QICE_QTPE_WA_H0_RXDATA_STAT_X(offset,expect_val,x) \
 WAIT_REGVAL_QICE_STAT_X(offset, expect_val, QTPE_WA, QTPE_WA_H0_RXDATA, x)
#define CHECK_REGVAL_QICE_QTPE_WA_H0_RXDATA_STAT(offset,expect_val,result) \
 CHECK_REGVAL_QICE_STAT(offset, expect_val, result, QTPE_WA, QTPE_WA_H0_RXDATA)
#endif
