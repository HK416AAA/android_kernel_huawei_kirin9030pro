#ifndef __DDR_REG_OP_PACKPHY_H__
#define __DDR_REG_OP_PACKPHY_H__ 
#include "ddr_reg_op_ddrsys.h"
#include <soc_ddr_pack_interface.h>
#include <soc_ddr_phy_interface.h>
#include <soc_ddr_emu_phy_interface.h>
#define GET_MEMBER_CACHE_PACK(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(DDR_PACK, reg_val, offset, member, result)
#define GET_MEMBER_PACK(reg_val,offset) \
 GET_MEMBER_FLUSH_DDRSYS(DDR_PACK, reg_val, offset, PACK)
#define GET_MEMBER_MAX_VALUE_PACK(offset,member) \
        GET_MEMBER_MAX_VALUE(DDR_PACK, offset, member)
#define GET_MEMBER_PACK_X(reg_val,offset,x) \
 GET_MEMBER_FLUSH_DDRSYS_X(DDR_PACK, reg_val, offset, PACK, x)
#define GET_MEMBER_PACK_X_Y(reg_val,offset,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_PACK, reg_val, offset, PACK, x, y)
#define GET_MEMBER_PACK_X_Y_Z(reg_val,offset,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_PACK, reg_val, offset, PACK, x, y, z)
#define GET_MEMBER_PACK_SINGLE(reg_val,offset,ch) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_PACK, reg_val, offset, PACK, ch)
#define GET_MEMBER_PACK_SINGLE_X(reg_val,offset,ch,x) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_PACK, reg_val, offset, PACK, ch, x)
#define GET_MEMBER_PACK_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_PACK, reg_val, offset, PACK, ch, x, y)
#define GET_MEMBER_PACK_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_PACK, reg_val, offset, PACK, ch, x, y, z)
#define SAVE_MEMBER_PACK(reg_val,offset) \
 GET_MEMBER_FLUSH_DDRSYS(DDR_PACK, reg_val, offset, PACK)
#define SAVE_MEMBER_PACK_X(reg_val,offset,x) \
 GET_MEMBER_FLUSH_DDRSYS_X(DDR_PACK, reg_val, offset, PACK, x)
#define SAVE_MEMBER_PACK_X_Y(reg_val,offset,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_PACK, reg_val, offset, PACK, x, y)
#define SAVE_MEMBER_PACK_X_Y_Z(reg_val,offset,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_PACK, reg_val, offset, PACK, x, y, z)
#define SAVE_MEMBER_PACK_SINGLE(reg_val,offset,ch) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_PACK, reg_val, offset, PACK, ch)
#define SAVE_MEMBER_PACK_SINGLE_X(reg_val,offset,ch,x) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_PACK, reg_val, offset, PACK, ch, x)
#define SAVE_MEMBER_PACK_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_PACK, reg_val, offset, PACK, ch, x, y)
#define SAVE_MEMBER_PACK_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_PACK, reg_val, offset, PACK, ch, x, y, z)
#define SET_MEMBER_CACHE_PACK(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(DDR_PACK, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_PACK(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(DDR_PACK, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_PACK(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS(DDR_PACK, reg_val, offset, PACK)
#define SET_MEMBER_RADIO_PACK(reg_val,offset) \
 SET_MEMBER_RADIO_DDRSYS(DDR_PACK, reg_val, offset, PACK)
#define SET_MEMBER_FLUSH_PACK_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_DDRSYS_X(DDR_PACK, reg_val, offset, PACK, x)
#define SET_MEMBER_RADIO_PACK_X(reg_val,offset,x) \
 SET_MEMBER_RADIO_DDRSYS_X(DDR_PACK, reg_val, offset, PACK, x)
#define SET_MEMBER_FLUSH_PACK_X_Y(reg_val,offset,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_PACK, reg_val, offset, PACK, x, y)
#define SET_MEMBER_FLUSH_PACK_X_Y_Z(reg_val,offset,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_PACK, reg_val, offset, PACK, x, y, z)
#define SET_MEMBER_FLUSH_PACK_MASK(reg_val,offset,base_mask) \
 SET_MEMBER_FLUSH_DDRSYS_MASK(DDR_PACK, reg_val, offset, PACK, base_mask)
#define SET_MEMBER_FLUSH_PACK_MASK_X(reg_val,offset,base_mask,x) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X(DDR_PACK, reg_val, offset, PACK, base_mask, x)
#define SET_MEMBER_FLUSH_PACK_MASK_X_Y(reg_val,offset,base_mask,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y(DDR_PACK, reg_val, offset, PACK, base_mask, x, y)
#define SET_MEMBER_FLUSH_PACK_MASK_X_Y_Z(reg_val,offset,base_mask,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y_Z(DDR_PACK, reg_val, offset, PACK, base_mask, x, y, z)
#define SET_MEMBER_FLUSH_PACK_SINGLE(reg_val,offset,ch) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_PACK, reg_val, offset, PACK, ch)
#define SET_MEMBER_FLUSH_HIPACK_SINGLE(reg_val,offset,ch) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE(HIPACK, reg_val, offset, PACK, ch)
#define SET_MEMBER_FLUSH_PACK_SINGLE_X(reg_val,offset,ch,x) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_PACK, reg_val, offset, PACK, ch, x)
#define SET_MEMBER_FLUSH_PACK_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_PACK, reg_val, offset, PACK, ch, x, y)
#define SET_MEMBER_FLUSH_PACK_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_PACK, reg_val, offset, PACK, ch, x, y, z)
#define SET_MEMBER_FLUSH_PACK_BROADCAST(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST(DDR_PACK, reg_val, offset, PACK);
#define SET_MEMBER_FLUSH_PACK_BROADCAST_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X(DDR_PACK, reg_val, offset, PACK, x);
#define SET_MEMBER_FLUSH_PACK_BROADCAST_X_Y(reg_val,offset,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y(DDR_PACK, reg_val, offset, PACK, x, y);
#define SET_MEMBER_FLUSH_PACK_BROADCAST_X_Y_Z(reg_val,offset,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y_Z(DDR_PACK, reg_val, offset, PACK, x, y, z);
#define WAIT_MEMBER_PACK_STAT(offset,member,expect_val) \
 WAIT_MEMBER_DDRSYS_STAT(DDR_PACK, offset, PACK, member, expect_val)
#define WAIT_MEMBER_PACK_STAT_MASK(offset,member,expect_val,base_mask) \
 WAIT_MEMBER_DDRSYS_STAT_MASK(DDR_PACK, offset, PACK, member, expect_val, base_mask)
#define WAIT_MEMBER_PACK_STAT_SINGLE(offset,member,expect_val,ch) \
 WAIT_MEMBER_DDRSYS_STAT_SINGLE(DDR_PACK, offset, PACK, member, expect_val, ch)
#define CHECK_MEMBER_PACK_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_DDRSYS_STAT(DDR_PACK, offset, PACK, member, expect_val, result)
#define CHECK_MEMBER_PACK_STAT_MASK(offset,member,expect_val,result,base_mask) \
 CHECK_MEMBER_DDRSYS_STAT_MASK(DDR_PACK, offset, PACK, member, expect_val, result, base_mask)
#define CHECK_MEMBER_PACK_STAT_SINGLE(offset,member,expect_val,result,ch) \
 CHECK_MEMBER_DDRSYS_STAT_SINGLE(DDR_PACK, offset, PACK, member, expect_val, result, ch)
#define GET_MEMBER_CACHE_PHY(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(DDR_PHY, reg_val, offset, member, result)
#define GET_MEMBER_PHY(reg_val,offset) \
 GET_MEMBER_FLUSH_DDRSYS(DDR_PHY, reg_val, offset, PHY)
#define GET_MEMBER_MAX_VALUE_PHY(offset,member) \
        GET_MEMBER_MAX_VALUE(DDR_PHY, offset, member)
#define GET_MEMBER_PHY_X(reg_val,offset,x) \
 GET_MEMBER_FLUSH_DDRSYS_X(DDR_PHY, reg_val, offset, PHY, x)
#define GET_MEMBER_PHY_X_Y(reg_val,offset,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_PHY, reg_val, offset, PHY, x, y)
#define GET_MEMBER_PHY_X_Y_Z(reg_val,offset,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_PHY, reg_val, offset, PHY, x, y, z)
#define GET_MEMBER_PHY_SINGLE(reg_val,offset,ch) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_PHY, reg_val, offset, PHY, ch)
#define GET_MEMBER_PHY_SINGLE_X(reg_val,offset,ch,x) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_PHY, reg_val, offset, PHY, ch, x)
#define GET_MEMBER_PHY_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_PHY, reg_val, offset, PHY, ch, x, y)
#define SAVE_MEMBER_PHY(reg_val,offset) \
 GET_MEMBER_FLUSH_DDRSYS(DDR_PHY, reg_val, offset, PHY)
#define SAVE_MEMBER_PHY_X(reg_val,offset,x) \
 GET_MEMBER_FLUSH_DDRSYS_X(DDR_PHY, reg_val, offset, PHY, x)
#define SAVE_MEMBER_PHY_X_Y(reg_val,offset,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_PHY, reg_val, offset, PHY, x, y)
#define SAVE_MEMBER_PHY_SINGLE(reg_val,offset,ch) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_PHY, reg_val, offset, PHY, ch)
#define SAVE_MEMBER_PHY_SINGLE_X(reg_val,offset,ch,x) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_PHY, reg_val, offset, PHY, ch, x)
#define SAVE_MEMBER_PHY_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_PHY, reg_val, offset, PHY, ch, x, y)
#define GET_MEMBER_PHY_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_PHY, reg_val, offset, PHY, ch, x, y, z)
#define SET_MEMBER_CACHE_PHY(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(DDR_PHY, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_PHY(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(DDR_PHY, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_PHY(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS(DDR_PHY, reg_val, offset, PHY)
#define SET_MEMBER_RADIO_PHY(reg_val,offset) \
 SET_MEMBER_RADIO_DDRSYS(DDR_PHY, reg_val, offset, PHY)
#define SET_MEMBER_FLUSH_PHY_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_DDRSYS_X(DDR_PHY, reg_val, offset, PHY, x)
#define SET_MEMBER_RADIO_PHY_X(reg_val,offset,x) \
 SET_MEMBER_RADIO_DDRSYS_X(DDR_PHY, reg_val, offset, PHY, x)
#define SET_MEMBER_FLUSH_PHY_X_Y(reg_val,offset,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_PHY, reg_val, offset, PHY, x, y)
#define SET_MEMBER_FLUSH_PHY_X_Y_Z(reg_val,offset,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_PHY, reg_val, offset, PHY, x, y, z)
#define SET_MEMBER_FLUSH_PHY_MASK(reg_val,offset,base_mask) \
 SET_MEMBER_FLUSH_DDRSYS_MASK(DDR_PHY, reg_val, offset, PHY, base_mask)
#define SET_MEMBER_FLUSH_PHY_MASK_X(reg_val,offset,base_mask,x) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X(DDR_PHY, reg_val, offset, PHY, base_mask, x)
#define SET_MEMBER_FLUSH_PHY_MASK_X_Y(reg_val,offset,base_mask,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y(DDR_PHY, reg_val, offset, PHY, base_mask, x, y)
#define SET_MEMBER_FLUSH_PHY_MASK_X_Y_Z(reg_val,offset,base_mask,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y_Z(DDR_PHY, reg_val, offset, PHY, base_mask, x, y, z)
#define SET_MEMBER_FLUSH_PHY_SINGLE(reg_val,offset,ch) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_PHY, reg_val, offset, PHY, ch)
#define SET_MEMBER_FLUSH_PHY_SINGLE_X(reg_val,offset,ch,x) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_PHY, reg_val, offset, PHY, ch, x)
#define SET_MEMBER_FLUSH_PHY_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_PHY, reg_val, offset, PHY, ch, x, y)
#define SET_MEMBER_FLUSH_PHY_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_PHY, reg_val, offset, PHY, ch, x, y, z)
#define SET_MEMBER_FLUSH_PHY_BROADCAST(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST(DDR_PHY, reg_val, offset, PHY);
#define SET_MEMBER_FLUSH_PHY_BROADCAST_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X(DDR_PHY, reg_val, offset, PHY, x);
#define SET_MEMBER_FLUSH_PHY_BROADCAST_X_Y(reg_val,offset,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y(DDR_PHY, reg_val, offset, PHY, x, y);
#define SET_MEMBER_FLUSH_PHY_BROADCAST_X_Y_Z(reg_val,offset,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y_Z(DDR_PHY, reg_val, offset, PHY, x, y, z);
#define WAIT_MEMBER_PHY_STAT(offset,member,expect_val) \
 WAIT_MEMBER_DDRSYS_STAT(DDR_PHY, offset, PHY, member, expect_val)
#define WAIT_MEMBER_PHY_STAT_MASK(offset,member,expect_val,base_mask) \
 WAIT_MEMBER_DDRSYS_STAT_MASK(DDR_PHY, offset, PHY, member, expect_val, base_mask)
#define WAIT_MEMBER_PHY_STAT_SINGLE(offset,member,expect_val,ch) \
 WAIT_MEMBER_DDRSYS_STAT_SINGLE(DDR_PHY, offset, PHY, member, expect_val, ch)
#define WAIT_MEMBER_PHY_STAT_SINGLE_X(offset,member,expect_val,ch,x) \
 WAIT_MEMBER_DDRSYS_STAT_SINGLE_X(DDR_PHY, offset, PHY, member, expect_val, ch, x)
#define WAIT_MEMBER_PHY_STAT_X(offset,member,expect_val,x) \
 WAIT_MEMBER_DDRSYS_STAT_X(DDR_PHY, offset, PHY, member, expect_val, x)
#define WAIT_MEMBER_PHY_STAT_X_MASK(offset,member,expect_val,x,base_mask) \
 WAIT_MEMBER_DDRSYS_STAT_X_MASK(DDR_PHY, offset, PHY, member, expect_val, x, base_mask)
#define CHECK_MEMBER_PHY_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_DDRSYS_STAT(DDR_PHY, offset, PHY, member, expect_val, result)
#define CHECK_MEMBER_PHY_STAT_MASK(offset,member,expect_val,result,base_mask) \
 CHECK_MEMBER_DDRSYS_STAT_MASK(DDR_PHY, offset, PHY, member, expect_val, result, base_mask)
#define CHECK_MEMBER_PHY_STAT_SINGLE(offset,member,expect_val,result,ch) \
 CHECK_MEMBER_DDRSYS_STAT_SINGLE(DDR_PHY, offset, PHY, member, expect_val, result, ch)
#define GET_MEMBER_CACHE_EMU_PHY(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(DDR_EMU_PHY, reg_val, offset, member, result)
#define GET_MEMBER_EMU_PHY(reg_val,offset) \
 GET_MEMBER_FLUSH_DDRSYS(DDR_EMU_PHY, reg_val, offset, PHY)
#define GET_MEMBER_MAX_VALUE_EMU_PHY(offset,member) \
        GET_MEMBER_MAX_VALUE(DDR_EMU_PHY, offset, member)
#define GET_MEMBER_EMU_PHY_X(reg_val,offset,x) \
 GET_MEMBER_FLUSH_DDRSYS_X(DDR_EMU_PHY, reg_val, offset, PHY, x)
#define GET_MEMBER_EMU_PHY_X_Y(reg_val,offset,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_EMU_PHY, reg_val, offset, PHY, x, y)
#define GET_MEMBER_EMU_PHY_X_Y_Z(reg_val,offset,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_EMU_PHY, reg_val, offset, PHY, x, y, z)
#define GET_MEMBER_EMU_PHY_SINGLE(reg_val,offset,ch) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_EMU_PHY, reg_val, offset, PHY, ch)
#define GET_MEMBER_EMU_PHY_SINGLE_X(reg_val,offset,ch,x) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_EMU_PHY, reg_val, offset, PHY, ch, x)
#define GET_MEMBER_EMU_PHY_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_EMU_PHY, reg_val, offset, PHY, ch, x, y)
#define SAVE_MEMBER_EMU_PHY(reg_val,offset) \
 GET_MEMBER_FLUSH_DDRSYS(DDR_EMU_PHY, reg_val, offset, PACK)
#define SAVE_MEMBER_EMU_PHY_X(reg_val,offset,x) \
 GET_MEMBER_FLUSH_DDRSYS_X(DDR_EMU_PHY, reg_val, offset, PACK, x)
#define SAVE_MEMBER_EMU_PHY_X_Y(reg_val,offset,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_EMU_PHY, reg_val, offset, PACK, x, y)
#define SAVE_MEMBER_EMU_PHY_SINGLE(reg_val,offset,ch) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_EMU_PHY, reg_val, offset, PACK, ch)
#define SAVE_MEMBER_EMU_PHY_SINGLE_X(reg_val,offset,ch,x) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_EMU_PHY, reg_val, offset, PACK, ch, x)
#define SAVE_MEMBER_EMU_PHY_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_EMU_PHY, reg_val, offset, PACK, ch, x, y)
#define GET_MEMBER_EMU_PHY_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_EMU_PHY, reg_val, offset, PACK, ch, x, y, z)
#define SET_MEMBER_CACHE_EMU_PHY(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(DDR_EMU_PHY, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_EMU_PHY(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(DDR_EMU_PHY, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_EMU_PHY(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS(DDR_EMU_PHY, reg_val, offset, PACK)
#define SET_MEMBER_RADIO_EMU_PHY(reg_val,offset) \
 SET_MEMBER_RADIO_DDRSYS(DDR_EMU_PHY, reg_val, offset, PACK)
#define SET_MEMBER_FLUSH_EMU_PHY_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_DDRSYS_X(DDR_EMU_PHY, reg_val, offset, PACK, x)
#define SET_MEMBER_RADIO_EMU_PHY_X(reg_val,offset,x) \
 SET_MEMBER_RADIO_DDRSYS_X(DDR_EMU_PHY, reg_val, offset, PACK, x)
#define SET_MEMBER_FLUSH__EMU_PHY_X_Y(reg_val,offset,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_EMU_PHY, reg_val, offset, PACK, x, y)
#define SET_MEMBER_FLUSH_EMU_PHY_X_Y_Z(reg_val,offset,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_EMU_PHY, reg_val, offset, PACK, x, y, z)
#define SET_MEMBER_FLUSH_EMU_PHY_MASK(reg_val,offset,base_mask) \
 SET_MEMBER_FLUSH_DDRSYS_MASK(DDR_EMU_PHY, reg_val, offset, PACK, base_mask)
#define SET_MEMBER_FLUSH_EMU_PHY_MASK_X(reg_val,offset,base_mask,x) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X(DDR_EMU_PHY, reg_val, offset, PACK, base_mask, x)
#define SET_MEMBER_FLUSH_EMU_PHY_MASK_X_Y(reg_val,offset,base_mask,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y(DDR_EMU_PHY, reg_val, offset, PACK, base_mask, x, y)
#define SET_MEMBER_FLUSH_EMU_PHY_MASK_X_Y_Z(reg_val,offset,base_mask,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y_Z(DDR_EMU_PHY, reg_val, offset, PACK, base_mask, x, y, z)
#define SET_MEMBER_FLUSH_EMU_PHY_SINGLE(reg_val,offset,ch) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_EMU_PHY, reg_val, offset, PACK, ch)
#define SET_MEMBER_FLUSH_EMU_PHY_SINGLE_X(reg_val,offset,ch,x) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_EMU_PHY, reg_val, offset, PACK, ch, x)
#define SET_MEMBER_FLUSH_EMU_PHY_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_EMU_PHY, reg_val, offset, PACK, ch, x, y)
#define SET_MEMBER_FLUSH_EMU_PHY_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_EMU_PHY, reg_val, offset, PACK, ch, x, y, z)
#define SET_MEMBER_FLUSH_EMU_PHY_BROADCAST(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST(DDR_EMU_PHY, reg_val, offset, PACK);
#define SET_MEMBER_FLUSH_EMU_PHY_BROADCAST_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X(DDR_EMU_PHY, reg_val, offset, PACK, x);
#define SET_MEMBER_FLUSH_EMU_PHY_BROADCAST_X_Y(reg_val,offset,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y(DDR_EMU_PHY, reg_val, offset, PACK, x, y);
#define SET_MEMBER_FLUSH_EMU_PHY_BROADCAST_X_Y_Z(reg_val,offset,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y_Z(DDR_EMU_PHY, reg_val, offset, PACK, x, y, z);
#define WAIT_MEMBER_EMU_PHY_STAT(offset,member,expect_val) \
 WAIT_MEMBER_DDRSYS_STAT(DDR_EMU_PHY, offset, PACK, member, expect_val)
#define WAIT_MEMBER_EMU_PHY_STAT_MASK(offset,member,expect_val,base_mask) \
 WAIT_MEMBER_DDRSYS_STAT_MASK(DDR_EMU_PHY, offset, PACK, member, expect_val, base_mask)
#define WAIT_MEMBER_EMU_PHY_STAT_SINGLE(offset,member,expect_val,ch) \
 WAIT_MEMBER_DDRSYS_STAT_SINGLE(DDR_EMU_PHY, offset, PACK, member, expect_val, ch)
#define CHECK_MEMBER_EMU_PHY_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_DDRSYS_STAT(DDR_EMU_PHY, offset, PACK, member, expect_val, result)
#define CHECK_MEMBER_EMU_PHY_STAT_MASK(offset,member,expect_val,result,base_mask) \
 CHECK_MEMBER_DDRSYS_STAT_MASK(DDR_EMU_PHY, offset, PACK, member, expect_val, result, base_mask)
#define CHECK_MEMBER_EMU_PHY_STAT_SINGLE(offset,member,expect_val,result,ch) \
 CHECK_MEMBER_DDRSYS_STAT_SINGLE(DDR_EMU_PHY, offset, PACK, member, expect_val, result, ch)
#define SET_MEMBER_CACHE_PHY_0TO5(reg_val,offset,member,val) \
 SET_MEMBER_CACHE_PHY(reg_val, offset, member##0, val); \
 SET_MEMBER_CACHE_PHY(reg_val, offset, member##1, val); \
 SET_MEMBER_CACHE_PHY(reg_val, offset, member##2, val); \
 SET_MEMBER_CACHE_PHY(reg_val, offset, member##3, val); \
 SET_MEMBER_CACHE_PHY(reg_val, offset, member##4, val); \
 SET_MEMBER_CACHE_PHY(reg_val, offset, member##5, val);
#define SET_MEMBER_CACHE_PHY_0TO7(reg_val,offset,member,val) \
 SET_MEMBER_CACHE_PHY_0TO5(reg_val, offset, member, val); \
 SET_MEMBER_CACHE_PHY(reg_val, offset, member##6, val); \
 SET_MEMBER_CACHE_PHY(reg_val, offset, member##7, val);
#define SET_MEMBER_CACHE_PHY_0TO8(reg_val,offset,member,val) \
 SET_MEMBER_CACHE_PHY_0TO7(reg_val, offset, member, val); \
 SET_MEMBER_CACHE_PHY(reg_val, offset, member##8, val);
#endif
