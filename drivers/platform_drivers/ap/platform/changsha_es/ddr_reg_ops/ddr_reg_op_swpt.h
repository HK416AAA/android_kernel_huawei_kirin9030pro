#ifndef __DDR_REG_OP_SWPT_H__
#define __DDR_REG_OP_SWPT_H__ 
#include "ddr_reg_op_logic.h"
#include <soc_ddr_pack_interface.h>
#define GET_MEMBER_CACHE_SWPT(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(DDR_PACK, reg_val, offset, member, result)
#define GET_MEMBER_SWPT(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(DDR_PACK, reg_val, offset, UCE_UCE_PACK_SWPT)
#define GET_MEMBER_SWPT_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_COMMON_X(DDR_PACK, reg_val, offset, UCE_UCE_PACK_SWPT, x)
#define SET_MEMBER_CACHE_SWPT(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(DDR_PACK, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_SWPT(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(DDR_PACK, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_SWPT(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(DDR_PACK, reg_val, offset, UCE_UCE_PACK_SWPT)
#define SET_MEMBER_FLUSH_SWPT_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_COMMON_X(DDR_PACK, reg_val, offset, UCE_UCE_PACK_SWPT, x)
#define WAIT_MEMBER_SWPT_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(DDR_PACK, offset, member, expect_val, UCE_UCE_PACK_SWPT)
#define WAIT_MEMBER_SWPT_STAT_X(offset,member,expect_val,x) \
    WAIT_MEMBER_COMMON_STAT_X(DDR_PACK, offset, member, expect_val, UCE_UCE_PACK_SWPT, x)
#define CHECK_MEMBER_SWPT_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(DDR_PACK, offset, member, expect_val, result, UCE_UCE_PACK_SWPT)
#define CHECK_MEMBER_SWPT_STAT_X(offset,member,expect_val,result,x) \
    CHECK_MEMBER_COMMON_STAT_X(DDR_PACK, offset, member, expect_val, result, UCE_UCE_PACK_SWPT, x)
#endif
