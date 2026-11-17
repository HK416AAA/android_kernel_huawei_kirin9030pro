#ifndef __DDR_REG_OP_QICE_GS_DMIC_H__
#define __DDR_REG_OP_QICE_GS_DMIC_H__ 
#include <ddr_reg_ops/ddr_reg_op_logic.h>
#include "ddr_reg_op_qice_common.h"
#include <soc_qice_gs_dmi_interface.h>
#define GET_MEMBER_QICE_GS_DMIC(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, GS_DMI, GS_DMIC)
#define SAVE_MEMBER_QICE_GS_DMIC(reg_val,offset) \
 GET_MEMBER_QICE(reg_val, offset, GS_DMI, GS_DMIC)
#define GET_MEMBER_CACHE_QICE_GS_DMIC(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(QICE_GS_DMI, reg_val, offset, member, result);
#define GET_MEMBER_QICE_GS_DMIC_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, GS_DMI, GS_DMIC, x)
#define SAVE_MEMBER_QICE_GS_DMIC_X(reg_val,offset,x) \
 GET_MEMBER_QICE_X(reg_val, offset, GS_DMI, GS_DMIC, x)
#define SET_MEMBER_CACHE_QICE_GS_DMIC(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(QICE_GS_DMI, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_QICE_GS_DMIC(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(QICE_GS_DMI, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_QICE_GS_DMIC(reg_val,offset) \
 SET_MEMBER_FLUSH_QICE(reg_val, offset, GS_DMI, GS_DMIC)
#define SET_MEMBER_FLUSH_QICE_GS_DMIC_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_QICE_X(reg_val, offset, GS_DMI, GS_DMIC, x)
#define WAIT_MEMBER_QICE_GS_DMIC_STAT(offset,member,expect_val) \
 WAIT_MEMBER_QICE_STAT(offset, member, expect_val, GS_DMI, GS_DMIC)
#define CHECK_MEMBER_QICE_GS_DMIC_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_QICE_STAT(offset, member, expect_val, result, GS_DMI, GS_DMIC)
#define WAIT_REGVAL_QICE_GS_DMIC_STAT(offset,expect_val) \
 WAIT_REGVAL_QICE_STAT(offset, expect_val, GS_DMI, GS_DMIC)
#define WAIT_REGVAL_QICE_GS_DMIC_STAT_X(offset,expect_val,x) \
 WAIT_REGVAL_QICE_STAT_X(offset, expect_val, GS_DMI, GS_DMIC, x)
#define CHECK_REGVAL_QICE_GS_DMIC_STAT(offset,expect_val,result) \
 CHECK_REGVAL_QICE_STAT(offset, expect_val, result, GS_DMI, GS_DMIC)
#endif
