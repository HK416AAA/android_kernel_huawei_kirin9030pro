#ifndef __DDR_REG_OP_EXMBIST_H__
#define __DDR_REG_OP_EXMBIST_H__ 
#include "ddr_reg_op_logic.h"
#include <soc_ddr_dmc_top_interface.h>
#include <soc_ddr_exmbist_interface.h>
#define GET_MEMBER_FLUSH_EXMBIST(type,reg_val,offset,base) \
    do { \
        (reg_val) = ddr_readl(SOC_##type##_##offset##_ADDR(DDR_REG_##base)); \
    } while (0)
#define GET_MEMBER_EXMBIST_X(type,reg_val,offset,base,x) \
    do { \
        (reg_val) = ddr_readl(SOC_##type##_##offset##_ADDR(DDR_REG_##base, (x))); \
    } while (0)
#define SET_MEMBER_FLUSH_EXMBIST_ALL(type,reg_val,offset) \
    do { \
        ddr_writel(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_EXMBIST1)); \
        ddr_writel(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_EXMBIST0)); \
    } while (0)
#define SET_MEMBER_FLUSH_EXMBIST0(reg_val,offset) \
    do { \
        ddr_writel(reg_val, SOC_DDR_EXMBIST##_##offset##_ADDR(DDR_REG_EXMBIST0)); \
    } while (0)
#define SET_MEMBER_FLUSH_EXMBIST1(reg_val,offset) \
    do { \
        ddr_writel(reg_val, SOC_DDR_EXMBIST##_##offset##_ADDR(DDR_REG_EXMBIST1)); \
    } while (0)
#define SET_MEMBER_FLUSH_EXMBIST0_X(reg_val,offset,x) \
    do { \
        ddr_writel(reg_val, SOC_DDR_EXMBIST##_##offset##_ADDR(DDR_REG_EXMBIST0, (x))); \
    } while (0)
#define SET_MEMBER_FLUSH_EXMBIST1_X(reg_val,offset,x) \
    do { \
        ddr_writel(reg_val, SOC_DDR_EXMBIST##_##offset##_ADDR(DDR_REG_EXMBIST1, (x))); \
    } while (0)
#define SET_MEMBER_FLUSH_EXMBIST_X_ALL(type,reg_val,offset,x) \
    do { \
        ddr_writel(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_EXMBIST1, (x))); \
        ddr_writel(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_EXMBIST0, (x))); \
    } while (0)
#define WAIT_MEMBER_EXMBIST_STAT_ALL(type,offset,member,expect_val) \
    do { \
        volatile unsigned int __val0; \
        volatile unsigned int __val1; \
        unsigned int __result; \
        unsigned int __reg_val; \
        do { \
            GET_MEMBER_EXMBIST0(__reg_val, offset); \
            GET_MEMBER_CACHE(type, __reg_val, offset, member, __result); \
            __val0 = (unsigned int)(!!(__result != (expect_val))); \
            GET_MEMBER_EXMBIST1(__reg_val, offset); \
            GET_MEMBER_CACHE(type, __reg_val, offset, member, __result); \
            __val1 = (unsigned int)(!!(__result != (expect_val))); \
        } while (__val0 != 0 && __val1 != 0); \
    } while (0)
#define GET_MEMBER_EXMBIST(reg_val,offset) \
    GET_MEMBER_EXMBIST0(reg_val, offset)
#define GET_MEMBER_EXMBIST0(reg_val,offset) \
    GET_MEMBER_FLUSH_EXMBIST(DDR_EXMBIST, reg_val, offset, EXMBIST0)
#define GET_MEMBER_EXMBIST1(reg_val,offset) \
    GET_MEMBER_FLUSH_EXMBIST(DDR_EXMBIST, reg_val, offset, EXMBIST1)
#define GET_MEMBER_EXMBIST0_X(reg_val,offset,x) \
    GET_MEMBER_EXMBIST_X(DDR_EXMBIST, reg_val, offset, EXMBIST0, x)
#define GET_MEMBER_EXMBIST1_X(reg_val,offset,x) \
    GET_MEMBER_EXMBIST_X(DDR_EXMBIST, reg_val, offset, EXMBIST1, x)
#define GET_MEMBER_CACHE_EXMBIST(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(DDR_EXMBIST, reg_val, offset, member, result)
#define SET_MEMBER_FLUSH_EXMBIST(reg_val,offset) \
    SET_MEMBER_FLUSH_EXMBIST_ALL(DDR_EXMBIST, reg_val, offset)
#define SET_MEMBER_FLUSH_EXMBIST_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_EXMBIST_X_ALL(DDR_EXMBIST, reg_val, offset, x)
#define SET_MEMBER_CACHE_EXMBIST(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(DDR_EXMBIST, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_EXMBIST(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(DDR_EXMBIST, reg_val, offset, member, bitmask, cfg_val)
#define WAIT_MEMBER_EXMBIST_STAT(offset,member,expect_val) \
    WAIT_MEMBER_EXMBIST_STAT_ALL(DDR_EXMBIST, offset, member, expect_val)
#endif
