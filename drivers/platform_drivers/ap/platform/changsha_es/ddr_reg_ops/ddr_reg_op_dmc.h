#ifndef __DDR_REG_OP_DMC_H__
#define __DDR_REG_OP_DMC_H__ 
#include "ddr_reg_op_ddrsys.h"
#include <soc_ddr_dmc_top_interface.h>
#include <soc_ddr_dumreg_interface.h>
#include <soc_ddr_dmc_interface.h>
#include <soc_ddr_iecc_interface.h>
#include <soc_ddr_rasc_interface.h>
#include <soc_ddr_bpg_interface.h>
#define GET_MEMBER_CACHE_DMC(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(DDR_DMC, reg_val, offset, member, result)
#define GET_MEMBER_DMC(reg_val,offset) \
    GET_MEMBER_FLUSH_DDRSYS(DDR_DMC, reg_val, offset, DMC)
#define SAVE_MEMBER_DMC(reg_val,offset) \
    GET_MEMBER_FLUSH_DDRSYS(DDR_DMC, reg_val, offset, DMC)
#define GET_MEMBER_DMC_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DDRSYS_X(DDR_DMC, reg_val, offset, DMC, x)
#define SAVE_MEMBER_DMC_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DDRSYS_X(DDR_DMC, reg_val, offset, DMC, x)
#define GET_MEMBER_DMC_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_DMC, reg_val, offset, DMC, x, y)
#define SAVE_MEMBER_DMC_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_DMC, reg_val, offset, DMC, x, y)
#define GET_MEMBER_DMC_X_Y_Z(reg_val,offset,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_DMC, reg_val, offset, DMC, x, y, z)
#define SAVE_MEMBER_DMC_X_Y_Z(reg_val,offset,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_DMC, reg_val, offset, DMC, x, y, z)
#define GET_MEMBER_DMC_SINGLE(reg_val,offset,ch) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_DMC, reg_val, offset, DMC, ch)
#define SAVE_MEMBER_DMC_SINGLE(reg_val,offset,ch) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_DMC, reg_val, offset, DMC, ch)
#define GET_MEMBER_DMC_SINGLE_X(reg_val,offset,ch,x) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_DMC, reg_val, offset, DMC, ch, x)
#define SAVE_MEMBER_DMC_SINGLE_X(reg_val,offset,ch,x) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_DMC, reg_val, offset, DMC, ch, x)
#define GET_MEMBER_DMC_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_DMC, reg_val, offset, DMC, ch, x, y)
#define SAVE_MEMBER_DMC_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_DMC, reg_val, offset, DMC, ch, x, y)
#define GET_MEMBER_DMC_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_DMC, reg_val, offset, DMC, ch, x, y, z)
#define SAVE_MEMBER_DMC_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_DMC, reg_val, offset, DMC, ch, x, y, z)
#define SET_MEMBER_CACHE_DMC(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(DDR_DMC, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_DMC(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(DDR_DMC, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_DMC(reg_val,offset) \
    SET_MEMBER_FLUSH_DDRSYS(DDR_DMC, reg_val, offset, DMC)
#define SET_MEMBER_RADIO_DMC(reg_val,offset) \
    SET_MEMBER_RADIO_DDRSYS(DDR_DMC, reg_val, offset, DMC)
#define SET_MEMBER_FLUSH_DMC_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_DDRSYS_X(DDR_DMC, reg_val, offset, DMC, x)
#define SET_MEMBER_RADIO_DMC_X(reg_val,offset,x) \
    SET_MEMBER_RADIO_DDRSYS_X(DDR_DMC, reg_val, offset, DMC, x)
#define SET_MEMBER_FLUSH_DMC_X_Y(reg_val,offset,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_DMC, reg_val, offset, DMC, x, y)
#define SET_MEMBER_FLUSH_DMC_X_Y_Z(reg_val,offset,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_DMC, reg_val, offset, DMC, x, y, z)
#define SET_MEMBER_FLUSH_DMC_MASK(reg_val,offset,base_mask) \
    SET_MEMBER_FLUSH_DDRSYS_MASK(DDR_DMC, reg_val, offset, DMC, base_mask)
#define SET_MEMBER_FLUSH_DMC_MASK_X(reg_val,offset,base_mask,x) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X(DDR_DMC, reg_val, offset, DMC, base_mask, x)
#define SET_MEMBER_FLUSH_DMC_MASK_X_Y(reg_val,offset,base_mask,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y(DDR_DMC, reg_val, offset, DMC, base_mask, x, y)
#define SET_MEMBER_FLUSH_DMC_MASK_X_Y_Z(reg_val,offset,base_mask,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y_Z(DDR_DMC, reg_val, offset, DMC, base_mask, x, y, z)
#define SET_MEMBER_FLUSH_DMC_SINGLE(reg_val,offset,ch) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_DMC, reg_val, offset, DMC, ch)
#define SET_MEMBER_FLUSH_DMC_SINGLE_X(reg_val,offset,ch,x) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_DMC, reg_val, offset, DMC, ch, x)
#define SET_MEMBER_FLUSH_DMC_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_DMC, reg_val, offset, DMC, ch, x, y)
#define SET_MEMBER_FLUSH_DMC_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_DMC, reg_val, offset, DMC, ch, x, y, z)
#define SET_MEMBER_FLUSH_DMC_BROADCAST(reg_val,offset) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST(DDR_DMC, reg_val, offset, DMC);
#define SET_MEMBER_FLUSH_DMC_BROADCAST_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X(DDR_DMC, reg_val, offset, DMC, x);
#define SET_MEMBER_FLUSH_DMC_BROADCAST_X_Y(reg_val,offset,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y(DDR_DMC, reg_val, offset, DMC, x, y);
#define SET_MEMBER_FLUSH_DMC_BROADCAST_X_Y_Z(reg_val,offset,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y_Z(DDR_DMC, reg_val, offset, DMC, x, y, z);
#define WAIT_MEMBER_DMC_STAT(offset,member,expect_val) \
    WAIT_MEMBER_DDRSYS_STAT(DDR_DMC, offset, DMC, member, expect_val)
#define WAIT_MEMBER_DMC_STAT_MASK(offset,member,expect_val,base_mask) \
    WAIT_MEMBER_DDRSYS_STAT_MASK(DDR_DMC, offset, DMC, member, expect_val, base_mask)
#define WAIT_MEMBER_DMC_STAT_SINGLE(offset,member,expect_val,ch) \
    WAIT_MEMBER_DDRSYS_STAT_SINGLE(DDR_DMC, offset, DMC, member, expect_val, ch)
#define CHECK_MEMBER_DMC_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_DDRSYS_STAT(DDR_DMC, offset, DMC, member, expect_val, result)
#define CHECK_MEMBER_DMC_STAT_MASK(offset,member,expect_val,result,base_mask) \
    CHECK_MEMBER_DDRSYS_STAT_MASK(DDR_DMC, offset, DMC, member, expect_val, result, base_mask)
#define CHECK_MEMBER_DMC_STAT_SINGLE(offset,member,expect_val,result,ch) \
    CHECK_MEMBER_DDRSYS_STAT_SINGLE(DDR_DMC, offset, DMC, member, expect_val, result, ch)
#define GET_MEMBER_CACHE_DMC_TOP(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(DDR_DMC_TOP, reg_val, offset, member, result)
#define GET_MEMBER_DMC_TOP(reg_val,offset) \
    GET_MEMBER_FLUSH_DDRSYS(DDR_DMC_TOP, reg_val, offset, DMC_TOP)
#define GET_MEMBER_DMC_TOP_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DDRSYS_X(DDR_DMC_TOP, reg_val, offset, DMC_TOP, x)
#define GET_MEMBER_DMC_TOP_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_DMC_TOP, reg_val, offset, DMC_TOP, x, y)
#define GET_MEMBER_DMC_TOP_X_Y_Z(reg_val,offset,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_DMC_TOP, reg_val, offset, DMC_TOP, x, y, z)
#define GET_MEMBER_DMC_TOP_SINGLE(reg_val,offset,ch) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_DMC_TOP, reg_val, offset, DMC_TOP, ch)
#define GET_MEMBER_DMC_TOP_SINGLE_X(reg_val,offset,ch,x) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_DMC_TOP, reg_val, offset, DMC_TOP, ch, x)
#define GET_MEMBER_DMC_TOP_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_DMC_TOP, reg_val, offset, DMC_TOP, ch, x, y)
#define SAVE_MEMBER_DMC_TOP(reg_val,offset) \
    GET_MEMBER_FLUSH_DDRSYS(DDR_DMC_TOP, reg_val, offset, DMC_TOP)
#define SAVE_MEMBER_DMC_TOP_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DDRSYS_X(DDR_DMC_TOP, reg_val, offset, DMC_TOP, x)
#define SAVE_MEMBER_DMC_TOP_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_DMC_TOP, reg_val, offset, DMC_TOP, x, y)
#define SAVE_MEMBER_DMC_TOP_SINGLE(reg_val,offset,ch) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_DMC_TOP, reg_val, offset, DMC_TOP, ch)
#define SAVE_MEMBER_DMC_TOP_SINGLE_X(reg_val,offset,ch,x) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_DMC_TOP, reg_val, offset, DMC_TOP, ch, x)
#define SAVE_MEMBER_DMC_TOP_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_DMC_TOP, reg_val, offset, DMC_TOP, ch, x, y)
#define GET_MEMBER_DMC_TOP_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_DMC_TOP, reg_val, offset, DMC_TOP, ch, x, y, z)
#define SET_MEMBER_CACHE_DMC_TOP(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(DDR_DMC_TOP, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_DMC_TOP(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(DDR_DMC_TOP, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_DMC_TOP(reg_val,offset) \
    SET_MEMBER_FLUSH_DDRSYS(DDR_DMC_TOP, reg_val, offset, DMC_TOP)
#define SET_MEMBER_RADIO_DMC_TOP(reg_val,offset) \
    SET_MEMBER_RADIO_DDRSYS(DDR_DMC_TOP, reg_val, offset, DMC_TOP)
#define SET_MEMBER_FLUSH_DMC_TOP_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_DDRSYS_X(DDR_DMC_TOP, reg_val, offset, DMC_TOP, x)
#define SET_MEMBER_FLUSH_DMC_TOP_X_Y(reg_val,offset,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_DMC_TOP, reg_val, offset, DMC_TOP, x, y)
#define SET_MEMBER_FLUSH_DMC_TOP_X_Y_Z(reg_val,offset,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_DMC_TOP, reg_val, offset, DMC_TOP, x, y, z)
#define SET_MEMBER_FLUSH_DMC_TOP_MASK(reg_val,offset,base_mask) \
    SET_MEMBER_FLUSH_DDRSYS_MASK(DDR_DMC_TOP, reg_val, offset, DMC_TOP, base_mask)
#define SET_MEMBER_FLUSH_DMC_TOP_MASK_X(reg_val,offset,base_mask,x) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X(DDR_DMC_TOP, reg_val, offset, DMC_TOP, base_mask, x)
#define SET_MEMBER_FLUSH_DMC_TOP_MASK_X_Y(reg_val,offset,base_mask,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y(DDR_DMC_TOP, reg_val, offset, DMC_TOP, base_mask, x, y)
#define SET_MEMBER_FLUSH_DMC_TOP_MASK_X_Y_Z(reg_val,offset,base_mask,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y_Z(DDR_DMC_TOP, reg_val, offset, DMC_TOP, base_mask, x, y, z)
#define SET_MEMBER_FLUSH_DMC_TOP_SINGLE(reg_val,offset,ch) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_DMC_TOP, reg_val, offset, DMC_TOP, ch)
#define SET_MEMBER_FLUSH_DMC_TOP_SINGLE_X(reg_val,offset,ch,x) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_DMC_TOP, reg_val, offset, DMC_TOP, ch, x)
#define SET_MEMBER_FLUSH_DMC_TOP_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_DMC_TOP, reg_val, offset, DMC_TOP, ch, x, y)
#define SET_MEMBER_FLUSH_DMC_TOP_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_DMC_TOP, reg_val, offset, DMC_TOP, ch, x, y, z)
#define SET_MEMBER_FLUSH_DMC_TOP_BROADCAST(reg_val,offset) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST(DDR_DMC_TOP, reg_val, offset, DMC_TOP);
#define SET_MEMBER_FLUSH_DMC_TOP_BROADCAST_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X(DDR_DMC_TOP, reg_val, offset, DMC_TOP, x);
#define SET_MEMBER_FLUSH_DMC_TOP_BROADCAST_X_Y(reg_val,offset,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y(DDR_DMC_TOP, reg_val, offset, DMC_TOP, x, y);
#define SET_MEMBER_FLUSH_DMC_TOP_BROADCAST_X_Y_Z(reg_val,offset,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y_Z(DDR_DMC_TOP, reg_val, offset, DMC_TOP, x, y, z);
#define WAIT_MEMBER_DMC_TOP_STAT(offset,member,expect_val) \
    WAIT_MEMBER_DDRSYS_STAT(DDR_DMC_TOP, offset, DMC_TOP, member, expect_val)
#define WAIT_MEMBER_DMC_TOP_STAT_X(offset,member,expect_val,x) \
    WAIT_MEMBER_DDRSYS_STAT_X(DDR_DMC_TOP, offset, DMC_TOP, member, expect_val, x)
#define WAIT_MEMBER_DMC_TOP_STAT_MASK(offset,member,expect_val,base_mask) \
    WAIT_MEMBER_DDRSYS_STAT_MASK(DDR_DMC_TOP, offset, DMC_TOP, member, expect_val, base_mask)
#define WAIT_MEMBER_DMC_TOP_STAT_SINGLE(offset,member,expect_val,ch) \
    WAIT_MEMBER_DDRSYS_STAT_SINGLE(DDR_DMC_TOP, offset, DMC_TOP, member, expect_val, ch)
#define CHECK_MEMBER_DMC_TOP_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_DDRSYS_STAT(DDR_DMC_TOP, offset, DMC_TOP, member, expect_val, result)
#define CHECK_MEMBER_DMC_TOP_STAT_MASK(offset,member,expect_val,result,base_mask) \
    CHECK_MEMBER_DDRSYS_STAT_MASK(DDR_DMC_TOP, offset, DMC_TOP, member, expect_val, result, base_mask)
#define CHECK_MEMBER_DMC_TOP_STAT_SINGLE(offset,member,expect_val,result,ch) \
    CHECK_MEMBER_DDRSYS_STAT_SINGLE(DDR_DMC_TOP, offset, DMC_TOP, member, expect_val, result, ch)
#define GET_MEMBER_CACHE_DUMREG(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(DDR_DUMREG, reg_val, offset, member, result)
#define GET_MEMBER_DUMREG(reg_val,offset) \
    GET_MEMBER_FLUSH_DDRSYS(DDR_DUMREG, reg_val, offset, DUMREG)
#define GET_MEMBER_DUMREG_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DDRSYS_X(DDR_DUMREG, reg_val, offset, DUMREG, x)
#define GET_MEMBER_DUMREG_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_DUMREG, reg_val, offset, DUMREG, x, y)
#define GET_MEMBER_DUMREG_X_Y_Z(reg_val,offset,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_DUMREG, reg_val, offset, DUMREG, x, y, z)
#define GET_MEMBER_DUMREG_SINGLE(reg_val,offset,ch) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_DUMREG, reg_val, offset, DUMREG, ch)
#define GET_MEMBER_DUMREG_SINGLE_X(reg_val,offset,ch,x) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_DUMREG, reg_val, offset, DUMREG, ch, x)
#define GET_MEMBER_DUMREG_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_DUMREG, reg_val, offset, DUMREG, ch, x, y)
#define GET_MEMBER_DUMREG_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_DUMREG, reg_val, offset, DUMREG, ch, x, y, z)
#define SAVE_MEMBER_DUMREG(reg_val,offset) \
    GET_MEMBER_FLUSH_DDRSYS(DDR_DUMREG, reg_val, offset, DUMREG)
#define SAVE_MEMBER_DUMREG_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DDRSYS_X(DDR_DUMREG, reg_val, offset, DUMREG, x)
#define SAVE_MEMBER_DUMREG_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_DUMREG, reg_val, offset, DUMREG, x, y)
#define SAVE_MEMBER_DUMREG_SINGLE(reg_val,offset,ch) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_DUMREG, reg_val, offset, DUMREG, ch)
#define SAVE_MEMBER_DUMREG_SINGLE_X(reg_val,offset,ch,x) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_DUMREG, reg_val, offset, DUMREG, ch, x)
#define SAVE_MEMBER_DUMREG_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_DUMREG, reg_val, offset, DUMREG, ch, x, y)
#define SET_MEMBER_CACHE_DUMREG(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(DDR_DUMREG, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_DUMREG(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(DDR_DUMREG, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_DUMREG(reg_val,offset) \
    SET_MEMBER_FLUSH_DDRSYS(DDR_DUMREG, reg_val, offset, DUMREG)
#define SET_MEMBER_RADIO_DUMREG(reg_val,offset) \
    SET_MEMBER_RADIO_DDRSYS(DDR_DUMREG, reg_val, offset, DUMREG)
#define SET_MEMBER_FLUSH_DUMREG_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_DDRSYS_X(DDR_DUMREG, reg_val, offset, DUMREG, x)
#define SET_MEMBER_FLUSH_DUMREG_X_Y(reg_val,offset,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_DUMREG, reg_val, offset, DUMREG, x, y)
#define SET_MEMBER_FLUSH_DUMREG_X_Y_Z(reg_val,offset,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_DUMREG, reg_val, offset, DUMREG, x, y, z)
#define SET_MEMBER_FLUSH_DUMREG_MASK(reg_val,offset,base_mask) \
    SET_MEMBER_FLUSH_DDRSYS_MASK(DDR_DUMREG, reg_val, offset, DUMREG, base_mask)
#define SET_MEMBER_FLUSH_DUMREG_MASK_X(reg_val,offset,base_mask,x) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X(DDR_DUMREG, reg_val, offset, DUMREG, base_mask, x)
#define SET_MEMBER_FLUSH_DUMREG_MASK_X_Y(reg_val,offset,base_mask,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y(DDR_DUMREG, reg_val, offset, DUMREG, base_mask, x, y)
#define SET_MEMBER_FLUSH_DUMREG_MASK_X_Y_Z(reg_val,offset,base_mask,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y_Z(DDR_DUMREG, reg_val, offset, DUMREG, base_mask, x, y, z)
#define SET_MEMBER_FLUSH_DUMREG_SINGLE(reg_val,offset,ch) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_DUMREG, reg_val, offset, DUMREG, ch)
#define SET_MEMBER_FLUSH_DUMREG_SINGLE_X(reg_val,offset,ch,x) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_DUMREG, reg_val, offset, DUMREG, ch, x)
#define SET_MEMBER_FLUSH_DUMREG_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_DUMREG, reg_val, offset, DUMREG, ch, x, y)
#define SET_MEMBER_FLUSH_DUMREG_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_DUMREG, reg_val, offset, DUMREG, ch, x, y, z)
#define SET_MEMBER_FLUSH_DUMREG_BROADCAST(reg_val,offset) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST(DDR_DUMREG, reg_val, offset, DUMREG);
#define SET_MEMBER_FLUSH_DUMREG_BROADCAST_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X(DDR_DUMREG, reg_val, offset, DUMREG, x);
#define SET_MEMBER_FLUSH_DUMREG_BROADCAST_X_Y(reg_val,offset,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y(DDR_DUMREG, reg_val, offset, DUMREG, x, y);
#define SET_MEMBER_FLUSH_DUMREG_BROADCAST_X_Y_Z(reg_val,offset,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y_Z(DDR_DUMREG, reg_val, offset, DUMREG, x, y, z);
#define WAIT_MEMBER_DUMREG_STAT(offset,member,expect_val) \
    WAIT_MEMBER_DDRSYS_STAT(DDR_DUMREG, offset, DUMREG, member, expect_val)
#define WAIT_MEMBER_DUMREG_STAT_MASK(offset,member,expect_val,base_mask) \
    WAIT_MEMBER_DDRSYS_STAT_MASK(DDR_DUMREG, offset, DUMREG, member, expect_val, base_mask)
#define WAIT_MEMBER_DUMREG_STAT_SINGLE(offset,member,expect_val,ch) \
    WAIT_MEMBER_DDRSYS_STAT_SINGLE(DDR_DUMREG, offset, DUMREG, member, expect_val, ch)
#define CHECK_MEMBER_DUMREG_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_DDRSYS_STAT(DDR_DUMREG, offset, DUMREG, member, expect_val, result)
#define CHECK_MEMBER_DUMREG_STAT_MASK(offset,member,expect_val,result,base_mask) \
    CHECK_MEMBER_DDRSYS_STAT_MASK(DDR_DUMREG, offset, DUMREG, member, expect_val, result, base_mask)
#define CHECK_MEMBER_DUMREG_STAT_SINGLE(offset,member,expect_val,result,ch) \
    CHECK_MEMBER_DDRSYS_STAT_SINGLE(DDR_DUMREG, offset, DUMREG, member, expect_val, result, ch)
#define GET_MEMBER_CACHE_GBUF(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(DDR_GRP_BUF, reg_val, offset, member, result)
#define GET_MEMBER_GBUF(reg_val,offset) \
    GET_MEMBER_FLUSH_DDRSYS(DDR_GRP_BUF, reg_val, offset, DMC_GBUF)
#define GET_MEMBER_GBUF_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DDRSYS_X(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, x)
#define GET_MEMBER_GBUF_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, x, y)
#define GET_MEMBER_GBUF_X_Y_Z(reg_val,offset,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, x, y, z)
#define GET_MEMBER_GBUF_SINGLE(reg_val,offset,ch) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, ch)
#define GET_MEMBER_GBUF_SINGLE_X(reg_val,offset,ch,x) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, ch, x)
#define GET_MEMBER_GBUF_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, ch, x, y)
#define GET_MEMBER_GBUF_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, ch, x, y, z)
#define SAVE_MEMBER_GBUF(reg_val,offset) \
    GET_MEMBER_FLUSH_DDRSYS(DDR_GRP_BUF, reg_val, offset, DMC_GBUF)
#define SAVE_MEMBER_GBUF_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DDRSYS_X(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, x)
#define SAVE_MEMBER_GBUF_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, x, y)
#define SAVE_MEMBER_GBUF_SINGLE(reg_val,offset,ch) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, ch)
#define SAVE_MEMBER_GBUF_SINGLE_X(reg_val,offset,ch,x) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, ch, x)
#define SAVE_MEMBER_GBUF_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, ch, x, y)
#define SET_MEMBER_CACHE_GBUF(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(DDR_GRP_BUF, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_GBUF(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(DDR_GRP_BUF, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_GBUF(reg_val,offset) \
    SET_MEMBER_FLUSH_DDRSYS(DDR_GRP_BUF, reg_val, offset, DMC_GBUF)
#define SET_MEMBER_RADIO_GBUF(reg_val,offset) \
    SET_MEMBER_RADIO_DDRSYS(DDR_GRP_BUF, reg_val, offset, DMC_GBUF)
#define SET_MEMBER_FLUSH_GBUF_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_DDRSYS_X(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, x)
#define SET_MEMBER_FLUSH_GBUF_X_Y(reg_val,offset,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, x, y)
#define SET_MEMBER_FLUSH_GBUF_X_Y_Z(reg_val,offset,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, x, y, z)
#define SET_MEMBER_FLUSH_GBUF_MASK(reg_val,offset,base_mask) \
    SET_MEMBER_FLUSH_DDRSYS_MASK(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, base_mask)
#define SET_MEMBER_FLUSH_GBUF_MASK_X(reg_val,offset,base_mask,x) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, base_mask, x)
#define SET_MEMBER_FLUSH_GBUF_MASK_X_Y(reg_val,offset,base_mask,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, base_mask, x, y)
#define SET_MEMBER_FLUSH_GBUF_MASK_X_Y_Z(reg_val,offset,base_mask,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y_Z(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, base_mask, x, y, z)
#define SET_MEMBER_FLUSH_GBUF_SINGLE(reg_val,offset,ch) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, ch)
#define SET_MEMBER_FLUSH_GBUF_SINGLE_X(reg_val,offset,ch,x) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, ch, x)
#define SET_MEMBER_FLUSH_GBUF_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, ch, x, y)
#define SET_MEMBER_FLUSH_GBUF_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, ch, x, y, z)
#define SET_MEMBER_FLUSH_GBUF_BROADCAST(reg_val,offset) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST(DDR_GRP_BUF, reg_val, offset, DMC_GBUF);
#define SET_MEMBER_FLUSH_GBUF_BROADCAST_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, x);
#define SET_MEMBER_FLUSH_GBUF_BROADCAST_X_Y(reg_val,offset,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, x, y);
#define SET_MEMBER_FLUSH_GBUF_BROADCAST_X_Y_Z(reg_val,offset,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y_Z(DDR_GRP_BUF, reg_val, offset, DMC_GBUF, x, y, z);
#define WAIT_MEMBER_GBUF_STAT(offset,member,expect_val) \
    WAIT_MEMBER_DDRSYS_STAT(DDR_GRP_BUF, offset, DMC_GBUF, member, expect_val)
#define WAIT_MEMBER_GBUF_STAT_MASK(offset,member,expect_val,base_mask) \
    WAIT_MEMBER_DDRSYS_STAT_MASK(DDR_GRP_BUF, offset, DMC_GBUF, member, expect_val, base_mask)
#define WAIT_MEMBER_GBUF_STAT_SINGLE(offset,member,expect_val,ch) \
    WAIT_MEMBER_DDRSYS_STAT_SINGLE(DDR_GRP_BUF, offset, DMC_GBUF, member, expect_val, ch)
#define CHECK_MEMBER_GBUF_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_DDRSYS_STAT(DDR_GRP_BUF, offset, DMC_GBUF, member, expect_val, result)
#define CHECK_MEMBER_GBUF_STAT_MASK(offset,member,expect_val,result,base_mask) \
    CHECK_MEMBER_DDRSYS_STAT_MASK(DDR_GRP_BUF, offset, DMC_GBUF, member, expect_val, result, base_mask)
#define CHECK_MEMBER_GBUF_STAT_SINGLE(offset,member,expect_val,result,ch) \
    CHECK_MEMBER_DDRSYS_STAT_SINGLE(DDR_GRP_BUF, offset, DMC_GBUF, member, expect_val, result, ch)
#define GET_MEMBER_CACHE_IECC(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(DDR_IECC, reg_val, offset, member, result)
#define GET_MEMBER_IECC(reg_val,offset) \
    GET_MEMBER_FLUSH_DDRSYS(DDR_IECC, reg_val, offset, DMC_IECC)
#define GET_MEMBER_IECC_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DDRSYS_X(DDR_IECC, reg_val, offset, DMC_IECC, x)
#define GET_MEMBER_IECC_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_IECC, reg_val, offset, DMC_IECC, x, y)
#define GET_MEMBER_IECC_X_Y_Z(reg_val,offset,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_IECC, reg_val, offset, DMC_IECC, x, y, z)
#define GET_MEMBER_IECC_SINGLE(reg_val,offset,ch) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_IECC, reg_val, offset, DMC_IECC, ch)
#define GET_MEMBER_IECC_SINGLE_X(reg_val,offset,ch,x) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_IECC, reg_val, offset, DMC_IECC, ch, x)
#define GET_MEMBER_IECC_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_IECC, reg_val, offset, DMC_IECC, ch, x, y)
#define GET_MEMBER_IECC_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_IECC, reg_val, offset, DMC_IECC, ch, x, y, z)
#define SAVE_MEMBER_IECC(reg_val,offset) \
    GET_MEMBER_FLUSH_DDRSYS(DDR_IECC, reg_val, offset, DMC_IECC)
#define SAVE_MEMBER_IECC_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DDRSYS_X(DDR_IECC, reg_val, offset, DMC_IECC, x)
#define SAVE_MEMBER_IECC_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_IECC, reg_val, offset, DMC_IECC, x, y)
#define SAVE_MEMBER_IECC_SINGLE(reg_val,offset,ch) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_IECC, reg_val, offset, DMC_IECC, ch)
#define SAVE_MEMBER_IECC_SINGLE_X(reg_val,offset,ch,x) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_IECC, reg_val, offset, DMC_IECC, ch, x)
#define SAVE_MEMBER_IECC_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_IECC, reg_val, offset, DMC_IECC, ch, x, y)
#define SET_MEMBER_CACHE_IECC(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(DDR_IECC, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_IECC(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(DDR_IECC, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_IECC(reg_val,offset) \
    SET_MEMBER_FLUSH_DDRSYS(DDR_IECC, reg_val, offset, DMC_IECC)
#define SET_MEMBER_RADIO_IECC(reg_val,offset) \
    SET_MEMBER_RADIO_DDRSYS(DDR_IECC, reg_val, offset, DMC_IECC)
#define SET_MEMBER_FLUSH_IECC_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_DDRSYS_X(DDR_IECC, reg_val, offset, DMC_IECC, x)
#define SET_MEMBER_FLUSH_IECC_X_Y(reg_val,offset,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_IECC, reg_val, offset, DMC_IECC, x, y)
#define SET_MEMBER_FLUSH_IECC_X_Y_Z(reg_val,offset,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_IECC, reg_val, offset, DMC_IECC, x, y, z)
#define SET_MEMBER_FLUSH_IECC_MASK(reg_val,offset,base_mask) \
    SET_MEMBER_FLUSH_DDRSYS_MASK(DDR_IECC, reg_val, offset, DMC_IECC, base_mask)
#define SET_MEMBER_FLUSH_IECC_MASK_X(reg_val,offset,base_mask,x) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X(DDR_IECC, reg_val, offset, DMC_IECC, base_mask, x)
#define SET_MEMBER_FLUSH_IECC_MASK_X_Y(reg_val,offset,base_mask,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y(DDR_IECC, reg_val, offset, DMC_IECC, base_mask, x, y)
#define SET_MEMBER_FLUSH_IECC_MASK_X_Y_Z(reg_val,offset,base_mask,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y_Z(DDR_IECC, reg_val, offset, DMC_IECC, base_mask, x, y, z)
#define SET_MEMBER_FLUSH_IECC_SINGLE(reg_val,offset,ch) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_IECC, reg_val, offset, DMC_IECC, ch)
#define SET_MEMBER_FLUSH_IECC_SINGLE_X(reg_val,offset,ch,x) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_IECC, reg_val, offset, DMC_IECC, ch, x)
#define SET_MEMBER_FLUSH_IECC_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_IECC, reg_val, offset, DMC_IECC, ch, x, y)
#define SET_MEMBER_FLUSH_IECC_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_IECC, reg_val, offset, DMC_IECC, ch, x, y, z)
#define SET_MEMBER_FLUSH_IECC_BROADCAST(reg_val,offset) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST(DDR_IECC, reg_val, offset, DMC_IECC);
#define SET_MEMBER_FLUSH_IECC_BROADCAST_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X(DDR_IECC, reg_val, offset, DMC_IECC, x);
#define SET_MEMBER_FLUSH_IECC_BROADCAST_X_Y(reg_val,offset,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y(DDR_IECC, reg_val, offset, DMC_IECC, x, y);
#define SET_MEMBER_FLUSH_IECC_BROADCAST_X_Y_Z(reg_val,offset,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y_Z(DDR_IECC, reg_val, offset, DMC_IECC, x, y, z);
#define WAIT_MEMBER_IECC_STAT(offset,member,expect_val) \
    WAIT_MEMBER_DDRSYS_STAT(DDR_IECC, offset, DMC_IECC, member, expect_val)
#define WAIT_MEMBER_IECC_STAT_MASK(offset,member,expect_val,base_mask) \
    WAIT_MEMBER_DDRSYS_STAT_MASK(DDR_IECC, offset, DMC_IECC, member, expect_val, base_mask)
#define WAIT_MEMBER_IECC_STAT_SINGLE(offset,member,expect_val,ch) \
    WAIT_MEMBER_DDRSYS_STAT_SINGLE(DDR_IECC, offset, DMC_IECC, member, expect_val, ch)
#define CHECK_MEMBER_IECC_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_DDRSYS_STAT(DDR_IECC, offset, DMC_IECC, member, expect_val, result)
#define CHECK_MEMBER_IECC_STAT_MASK(offset,member,expect_val,result,base_mask) \
    CHECK_MEMBER_DDRSYS_STAT_MASK(DDR_IECC, offset, DMC_IECC, member, expect_val, result, base_mask)
#define CHECK_MEMBER_IECC_STAT_SINGLE(offset,member,expect_val,result,ch) \
    CHECK_MEMBER_DDRSYS_STAT_SINGLE(DDR_IECC, offset, DMC_IECC, member, expect_val, result, ch)
#define GET_MEMBER_CACHE_RASC(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(DDR_RASC, reg_val, offset, member, result)
#define GET_MEMBER_RASC(reg_val,offset) \
    GET_MEMBER_FLUSH_DDRSYS(DDR_RASC, reg_val, offset, DMC_RASC)
#define SAVE_MEMBER_RASC(reg_val,offset) \
    GET_MEMBER_FLUSH_DDRSYS(DDR_RASC, reg_val, offset, DMC_RASC)
#define GET_MEMBER_RASC_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DDRSYS_X(DDR_RASC, reg_val, offset, DMC_RASC, x)
#define SAVE_MEMBER_RASC_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DDRSYS_X(DDR_RASC, reg_val, offset, DMC_RASC, x)
#define GET_MEMBER_RASC_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_RASC, reg_val, offset, DMC_RASC, x, y)
#define SAVE_MEMBER_RASC_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_RASC, reg_val, offset, DMC_RASC, x, y)
#define GET_MEMBER_RASC_X_Y_Z(reg_val,offset,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_RASC, reg_val, offset, DMC_RASC, x, y, z)
#define SAVE_MEMBER_RASC_X_Y_Z(reg_val,offset,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_RASC, reg_val, offset, DMC_RASC, x, y, z)
#define GET_MEMBER_RASC_SINGLE(reg_val,offset,ch) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_RASC, reg_val, offset, DMC_RASC, ch)
#define SAVE_MEMBER_RASC_SINGLE(reg_val,offset,ch) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_RASC, reg_val, offset, DMC_RASC, ch)
#define GET_MEMBER_RASC_SINGLE_X(reg_val,offset,ch,x) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_RASC, reg_val, offset, DMC_RASC, ch, x)
#define SAVE_MEMBER_RASC_SINGLE_X(reg_val,offset,ch,x) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_RASC, reg_val, offset, DMC_RASC, ch, x)
#define GET_MEMBER_RASC_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_RASC, reg_val, offset, DMC_RASC, ch, x, y)
#define SAVE_MEMBER_RASC_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_RASC, reg_val, offset, DMC_RASC, ch, x, y)
#define GET_MEMBER_RASC_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_RASC, reg_val, offset, DMC_RASC, ch, x, y, z)
#define SAVE_MEMBER_RASC_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_RASC, reg_val, offset, DMC_RASC, ch, x, y, z)
#define SET_MEMBER_CACHE_RASC(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(DDR_RASC, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_RASC(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(DDR_RASC, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_RASC(reg_val,offset) \
    SET_MEMBER_FLUSH_DDRSYS(DDR_RASC, reg_val, offset, DMC_RASC)
#define SET_MEMBER_RADIO_RASC(reg_val,offset) \
    SET_MEMBER_RADIO_DDRSYS(DDR_RASC, reg_val, offset, DMC_RASC)
#define SET_MEMBER_FLUSH_RASC_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_DDRSYS_X(DDR_RASC, reg_val, offset, DMC_RASC, x)
#define SET_MEMBER_RADIO_RASC_X(reg_val,offset,x) \
    SET_MEMBER_RADIO_DDRSYS_X(DDR_RASC, reg_val, offset, DMC_RASC, x)
#define SET_MEMBER_FLUSH_RASC_X_Y(reg_val,offset,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_RASC, reg_val, offset, DMC_RASC, x, y)
#define SET_MEMBER_FLUSH_RASC_X_Y_Z(reg_val,offset,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_RASC, reg_val, offset, DMC_RASC, x, y, z)
#define SET_MEMBER_FLUSH_RASC_MASK(reg_val,offset,base_mask) \
    SET_MEMBER_FLUSH_DDRSYS_MASK(DDR_RASC, reg_val, offset, DMC_RASC, base_mask)
#define SET_MEMBER_FLUSH_RASC_MASK_X(reg_val,offset,base_mask,x) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X(DDR_RASC, reg_val, offset, DMC_RASC, base_mask, x)
#define SET_MEMBER_FLUSH_RASC_MASK_X_Y(reg_val,offset,base_mask,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y(DDR_RASC, reg_val, offset, DMC_RASC, base_mask, x, y)
#define SET_MEMBER_FLUSH_RASC_MASK_X_Y_Z(reg_val,offset,base_mask,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y_Z(DDR_RASC, reg_val, offset, DMC_RASC, base_mask, x, y, z)
#define SET_MEMBER_FLUSH_RASC_SINGLE(reg_val,offset,ch) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_RASC, reg_val, offset, DMC_RASC, ch)
#define SET_MEMBER_FLUSH_RASC_SINGLE_X(reg_val,offset,ch,x) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_RASC, reg_val, offset, DMC_RASC, ch, x)
#define SET_MEMBER_FLUSH_RASC_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_RASC, reg_val, offset, DMC_RASC, ch, x, y)
#define SET_MEMBER_FLUSH_RASC_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_RASC, reg_val, offset, DMC_RASC, ch, x, y, z)
#define SET_MEMBER_FLUSH_RASC_BROADCAST(reg_val,offset) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST(DDR_RASC, reg_val, offset, DMC_RASC);
#define SET_MEMBER_FLUSH_RASC_BROADCAST_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X(DDR_RASC, reg_val, offset, DMC_RASC, x);
#define SET_MEMBER_FLUSH_RASC_BROADCAST_X_Y(reg_val,offset,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y(DDR_RASC, reg_val, offset, DMC_RASC, x, y);
#define SET_MEMBER_FLUSH_RASC_BROADCAST_X_Y_Z(reg_val,offset,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y_Z(DDR_RASC, reg_val, offset, DMC_RASC, x, y, z);
#define WAIT_MEMBER_RASC_STAT(offset,member,expect_val) \
    WAIT_MEMBER_DDRSYS_STAT(DDR_RASC, offset, DMC_RASC, member, expect_val)
#define WAIT_MEMBER_RASC_STAT_MASK(offset,member,expect_val,base_mask) \
    WAIT_MEMBER_DDRSYS_STAT_MASK(DDR_RASC, offset, DMC_RASC, member, expect_val, base_mask)
#define WAIT_MEMBER_RASC_STAT_SINGLE(offset,member,expect_val,ch) \
    WAIT_MEMBER_DDRSYS_STAT_SINGLE(DDR_RASC, offset, DMC_RASC, member, expect_val, ch)
#define CHECK_MEMBER_RASC_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_DDRSYS_STAT(DDR_RASC, offset, DMC_RASC, member, expect_val, result)
#define CHECK_MEMBER_RASC_STAT_MASK(offset,member,expect_val,result,base_mask) \
    CHECK_MEMBER_DDRSYS_STAT_MASK(DDR_RASC, offset, DMC_RASC, member, expect_val, result, base_mask)
#define CHECK_MEMBER_RASC_STAT_SINGLE(offset,member,expect_val,result,ch) \
    CHECK_MEMBER_DDRSYS_STAT_SINGLE(DDR_RASC, offset, DMC_RASC, member, expect_val, result, ch)
#define GET_MEMBER_CACHE_BPG(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(DDR_BPG, reg_val, offset, member, result)
#define GET_MEMBER_BPG(reg_val,offset) \
    GET_MEMBER_FLUSH_DDRSYS(DDR_BPG, reg_val, offset, BPG)
#define GET_MEMBER_BPG_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DDRSYS_X(DDR_BPG, reg_val, offset, BPG, x)
#define GET_MEMBER_BPG_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_BPG, reg_val, offset, BPG, x, y)
#define GET_MEMBER_BPG_X_Y_Z(reg_val,offset,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_BPG, reg_val, offset, BPG, x, y, z)
#define GET_MEMBER_BPG_SINGLE(reg_val,offset,ch) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_BPG, reg_val, offset, BPG, ch)
#define GET_MEMBER_BPG_SINGLE_X(reg_val,offset,ch,x) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_BPG, reg_val, offset, BPG, ch, x)
#define GET_MEMBER_BPG_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_BPG, reg_val, offset, BPG, ch, x, y)
#define GET_MEMBER_BPG_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_BPG, reg_val, offset, BPG, ch, x, y, z)
#define SAVE_MEMBER_BPG(reg_val,offset) \
    GET_MEMBER_FLUSH_DDRSYS(DDR_BPG, reg_val, offset, BPG)
#define SAVE_MEMBER_BPG_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DDRSYS_X(DDR_BPG, reg_val, offset, BPG, x)
#define SAVE_MEMBER_BPG_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_BPG, reg_val, offset, BPG, x, y)
#define SAVE_MEMBER_BPG_SINGLE(reg_val,offset,ch) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_BPG, reg_val, offset, BPG, ch)
#define SAVE_MEMBER_BPG_SINGLE_X(reg_val,offset,ch,x) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_BPG, reg_val, offset, BPG, ch, x)
#define SAVE_MEMBER_BPG_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_BPG, reg_val, offset, BPG, ch, x, y)
#define SET_MEMBER_CACHE_BPG(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(DDR_BPG, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_BPG(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(DDR_BPG, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_BPG(reg_val,offset) \
    SET_MEMBER_FLUSH_DDRSYS(DDR_BPG, reg_val, offset, BPG)
#define SET_MEMBER_RADIO_BPG(reg_val,offset) \
    SET_MEMBER_RADIO_DDRSYS(DDR_BPG, reg_val, offset, BPG)
#define SET_MEMBER_FLUSH_BPG_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_DDRSYS_X(DDR_BPG, reg_val, offset, BPG, x)
#define SET_MEMBER_FLUSH_BPG_X_Y(reg_val,offset,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_BPG, reg_val, offset, BPG, x, y)
#define SET_MEMBER_FLUSH_BPG_X_Y_Z(reg_val,offset,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_BPG, reg_val, offset, BPG, x, y, z)
#define SET_MEMBER_FLUSH_BPG_MASK(reg_val,offset,base_mask) \
    SET_MEMBER_FLUSH_DDRSYS_MASK(DDR_BPG, reg_val, offset, BPG, base_mask)
#define SET_MEMBER_FLUSH_BPG_MASK_X(reg_val,offset,base_mask,x) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X(DDR_BPG, reg_val, offset, BPG, base_mask, x)
#define SET_MEMBER_FLUSH_BPG_MASK_X_Y(reg_val,offset,base_mask,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y(DDR_BPG, reg_val, offset, BPG, base_mask, x, y)
#define SET_MEMBER_FLUSH_BPG_MASK_X_Y_Z(reg_val,offset,base_mask,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y_Z(DDR_BPG, reg_val, offset, BPG, base_mask, x, y, z)
#define SET_MEMBER_FLUSH_BPG_SINGLE(reg_val,offset,ch) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_BPG, reg_val, offset, BPG, ch)
#define SET_MEMBER_FLUSH_BPG_SINGLE_X(reg_val,offset,ch,x) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_BPG, reg_val, offset, BPG, ch, x)
#define SET_MEMBER_FLUSH_BPG_SINGLE_X_Y(reg_val,offset,ch,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_BPG, reg_val, offset, BPG, ch, x, y)
#define SET_MEMBER_FLUSH_BPG_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_BPG, reg_val, offset, BPG, ch, x, y, z)
#define SET_MEMBER_FLUSH_BPG_BROADCAST(reg_val,offset) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST(DDR_BPG, reg_val, offset, BPG);
#define SET_MEMBER_FLUSH_BPG_BROADCAST_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X(DDR_BPG, reg_val, offset, BPG, x);
#define SET_MEMBER_FLUSH_BPG_BROADCAST_X_Y(reg_val,offset,x,y) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y(DDR_BPG, reg_val, offset, BPG, x, y);
#define SET_MEMBER_FLUSH_BPG_BROADCAST_X_Y_Z(reg_val,offset,x,y,z) \
    SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y_Z(DDR_BPG, reg_val, offset, BPG, x, y, z);
#define WAIT_MEMBER_BPG_STAT(offset,member,expect_val) \
    WAIT_MEMBER_DDRSYS_STAT(DDR_BPG, offset, BPG, member, expect_val)
#define WAIT_MEMBER_BPG_STAT_MASK(offset,member,expect_val,base_mask) \
    WAIT_MEMBER_DDRSYS_STAT_MASK(DDR_BPG, offset, BPG, member, expect_val, base_mask)
#define WAIT_MEMBER_BPG_STAT_SINGLE(offset,member,expect_val,ch) \
    WAIT_MEMBER_DDRSYS_STAT_SINGLE(DDR_BPG, offset, BPG, member, expect_val, ch)
#define CHECK_MEMBER_BPG_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_DDRSYS_STAT(DDR_BPG, offset, BPG, member, expect_val, result)
#define CHECK_MEMBER_BPG_STAT_MASK(offset,member,expect_val,result,base_mask) \
    CHECK_MEMBER_DDRSYS_STAT_MASK(DDR_BPG, offset, BPG, member, expect_val, result, base_mask)
#define CHECK_MEMBER_BPG_STAT_SINGLE(offset,member,expect_val,result,ch) \
    CHECK_MEMBER_DDRSYS_STAT_SINGLE(DDR_BPG, offset, BPG, member, expect_val, result, ch)
#endif
