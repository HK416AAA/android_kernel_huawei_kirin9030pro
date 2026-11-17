#ifndef __DDR_REG_OP_DMSS_H__
#define __DDR_REG_OP_DMSS_H__ 
#include "ddr_reg_op_logic.h"
#define GET_MEMBER_FLUSH_DMSS_EXMBIST(type,reg_val,offset,base) \
    do { \
        (reg_val) = ddr_readl(SOC_##type##_##offset##_ADDR(DDR_REG_##base)); \
    } while (0)
#define GET_MEMBER_FLUSH_DMSS_EXMBIST_X(type,reg_val,offset,base,x) \
    do { \
        (reg_val) = ddr_readl(SOC_##type##_##offset##_ADDR(DDR_REG_##base, (x))); \
    } while (0)
#define GET_MEMBER_FLUSH_DMSS_EXMBIST_X_Y(type,reg_val,offset,base,x,y) \
    do { \
        (reg_val) = ddr_readl(SOC_##type##_##offset##_ADDR(DDR_REG_##base, (x), (y))); \
    } while (0)
#define GET_MEMBER_FLUSH_DMSS_EXMBIST_X_Y_Z(type,reg_val,offset,base,x,y,z) \
    do { \
        (reg_val) = ddr_readl(SOC_##type##_##offset##_ADDR(DDR_REG_##base, (x), (y), (z))); \
    } while (0)
#define SET_MEMBER_FLUSH_DMSS_EXMBIST(type,reg_val,offset,base) \
    do { \
        ddr_writel(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base)); \
    } while (0)
#define SET_MEMBER_FLUSH_DMSS_EXMBIST_X(type,reg_val,offset,base,x) \
    do { \
        ddr_writel(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base, (x))); \
    } while (0)
#define SET_MEMBER_FLUSH_DMSS_EXMBIST_X_Y(type,reg_val,offset,base,x,y) \
    do { \
        ddr_writel(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base, (x), (y))); \
    } while (0)
#define SET_MEMBER_FLUSH_DMSS_EXMBIST_X_Y_Z(type,reg_val,offset,base,x,y,z) \
    do { \
        ddr_writel(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base, (x), (y), (z))); \
    } while (0)
#define WAIT_MEMBER_DMSS_EXMBIST_STAT(type,offset,member,expect_val,base) \
    do { \
        volatile unsigned int __val; \
        unsigned int __result; \
        unsigned int __reg_val; \
        do { \
            GET_MEMBER_FLUSH_DMSS_EXMBIST(type, __reg_val, offset, base); \
            GET_MEMBER_CACHE(type, __reg_val, offset, member, __result); \
            __val = (unsigned int)(!!(__result != (expect_val))); \
        } while (__val); \
    } while (0)
#define CHECK_MEMBER_DMSS_EXMBIST_STAT(type,offset,member,expect_val,result,base) \
    do { \
        unsigned int __reg_val; \
        GET_MEMBER_FLUSH_DMSS_EXMBIST(type, __reg_val, offset, base); \
        GET_MEMBER_CACHE(type, __reg_val, offset, member, result); \
        (result) = (unsigned int)(!!((result) != (expect_val))); \
    } while (0)
#define GET_MEMBER_CACHE_DMSS(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(DMSS, reg_val, offset, member, result)
#define GET_MEMBER_DMSS(reg_val,offset) \
    GET_MEMBER_FLUSH_DMSS_EXMBIST(DMSS, reg_val, offset, DMSS)
#define SAVE_MEMBER_DMSS(reg_val,offset) \
    GET_MEMBER_FLUSH_DMSS_EXMBIST(DMSS, reg_val, offset, DMSS)
#define GET_MEMBER_DMSS_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DMSS_EXMBIST_X(DMSS, reg_val, offset, DMSS, x)
#define SAVE_MEMBER_DMSS_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_DMSS_EXMBIST_X(DMSS, reg_val, offset, DMSS, x)
#define GET_MEMBER_DMSS_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DMSS_EXMBIST_X_Y(DMSS, reg_val, offset, DMSS, x, y)
#define SAVE_MEMBER_DMSS_X_Y(reg_val,offset,x,y) \
    GET_MEMBER_FLUSH_DMSS_EXMBIST_X_Y(DMSS, reg_val, offset, DMSS, x, y)
#define GET_MEMBER_DMSS_X_Y_Z(reg_val,offset,x,y,z) \
    GET_MEMBER_FLUSH_DMSS_EXMBIST_X_Y_Z(DMSS, reg_val, offset, DMSS, x, y, z)
#define SET_MEMBER_CACHE_DMSS(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(DMSS, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_DMSS(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(DMSS, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_DMSS(reg_val,offset) \
    SET_MEMBER_FLUSH_DMSS_EXMBIST(DMSS, reg_val, offset, DMSS)
#define SET_MEMBER_FLUSH_DMSS_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_DMSS_EXMBIST_X(DMSS, reg_val, offset, DMSS, x)
#define SET_MEMBER_FLUSH_DMSS_X_Y(reg_val,offset,x,y) \
    SET_MEMBER_FLUSH_DMSS_EXMBIST_X_Y(DMSS, reg_val, offset, DMSS, x, y)
#define SET_MEMBER_FLUSH_DMSS_X_Y_Z(reg_val,offset,x,y,z) \
    SET_MEMBER_FLUSH_DMSS_EXMBIST_X_Y_Z(DMSS, reg_val, offset, DMSS, x, y, z)
#define WAIT_MEMBER_DMSS_STAT(offset,member,expect_val) \
    WAIT_MEMBER_DMSS_EXMBIST_STAT(DMSS, offset, member, expect_val, DMSS)
#define CHECK_MEMBER_DMSS_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_DMSS_EXMBIST_STAT(DMSS, offset, member, expect_val, result, DMSS)
#endif
