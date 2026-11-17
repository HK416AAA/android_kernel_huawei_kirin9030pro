#ifndef __DDR_REG_OP_LOGIC_H__
#define __DDR_REG_OP_LOGIC_H__ 
#include <ddr/ddr_nmanager_extend.h>
#include <soc_xpu_lp_ctrl_cfg_interface.h>
#include <soc_pctrl_interface.h>
#include <soc_pmctrl_interface.h>
#define BITS_START(type,offset,member) \
    (SOC_##type##_##offset##_##member##_START)
#ifndef BITS_MASK
#define BITS_MASK(start,end) \
    ((unsigned int)((((unsigned long long)0x1 << (unsigned int)(((end) - (start)) + 1)) - 1) << (start)))
#endif
#define BITS_MASK_NONCONST(start,end) \
    ((unsigned int)((((unsigned int)0x1 << (unsigned int)(((end) - (start)) + 1)) - 1) << (start)))
#define SET_CACHE_NONCONST(reg_val,start,end,cfg_val) \
    do { \
        (reg_val) &= ~(BITS_MASK_NONCONST(start, end)); \
        (reg_val) |= (unsigned int)((((unsigned int)(cfg_val)) << (start)) & BITS_MASK_NONCONST(start, end)); \
    } while (0)
#define GET_CACHE(reg_val,start,end) \
    (((reg_val) & BITS_MASK(start, end)) >> (start))
#define SET_CACHE(reg_val,start,end,cfg_val) \
    do { \
        (reg_val) &= ~(BITS_MASK(start, end)); \
        (reg_val) |= (unsigned int)((((unsigned int)(cfg_val)) << (start)) & BITS_MASK(start, end)); \
    } while (0)
#define GET_CACHE_RANGE(start,end) \
    ((BITS_MASK(start, end)) >> start)
#define GET_MEMBER_CACHE_RANGE(type,offset,member) \
    ((BITS_MASK(SOC_##type##_##offset##_##member##_START, SOC_##type##_##offset##_##member##_END)) \
        >> SOC_##type##_##offset##_##member##_START)
#define GET_MEMBER_CACHE_MASK(type,offset,member) \
    (BITS_MASK(SOC_##type##_##offset##_##member##_START, SOC_##type##_##offset##_##member##_END))
#define GET_MEMBER_CACHE(type,reg_val,offset,member,result) \
    do { \
        (result) = (((reg_val) & BITS_MASK(SOC_##type##_##offset##_##member##_START, SOC_##type##_##offset##_##member##_END)) \
                    >> SOC_##type##_##offset##_##member##_START); \
    } while (0)
#define GET_MEMBER_MAX_VALUE(type,offset,member) \
        ((BITS_MASK(SOC_##type##_##offset##_##member##_START, SOC_##type##_##offset##_##member##_END)) \
             >> SOC_##type##_##offset##_##member##_START)
#define SET_MEMBER_CACHE_BITMASKEN(type,reg_val,offset,member,bitmask,cfg_val) \
    do { \
        (reg_val) &= ~(BITS_MASK(SOC_##type##_##offset##_##member##_START, SOC_##type##_##offset##_##member##_END)); \
        (reg_val) |= (unsigned int)((((unsigned int)(cfg_val)) << SOC_##type##_##offset##_##member##_START) & BITS_MASK(SOC_##type##_##offset##_##member##_START, SOC_##type##_##offset##_##member##_END)); \
        (reg_val) |= (unsigned int)(((unsigned int)(BITS_MASK(SOC_##type##_##offset##_##member##_START, SOC_##type##_##offset##_##member##_END))) << SOC_##type##_##offset##_##bitmask##_START); \
    } while (0)
#define SET_MEMBER_CACHE(type,reg_val,offset,member,cfg_val) \
    do { \
        (reg_val) &= ~(BITS_MASK(SOC_##type##_##offset##_##member##_START, SOC_##type##_##offset##_##member##_END)); \
        (reg_val) |= (unsigned int)((((unsigned int)(cfg_val)) << SOC_##type##_##offset##_##member##_START) & (unsigned int)BITS_MASK(SOC_##type##_##offset##_##member##_START, SOC_##type##_##offset##_##member##_END)); \
    } while (0)
#define GET_MEMBER_FLUSH_COMMON(type,reg_val,offset,base) \
    do { \
        (reg_val) = ddr_readl(SOC_##type##_##offset##_ADDR(SOC_##base##_BASE_ADDR)); \
    } while (0)
#define GET_MEMBER_FLUSH_COMMON_X(type,reg_val,offset,base,x) \
    do { \
        (reg_val) = ddr_readl(SOC_##type##_##offset##_ADDR(SOC_##base##_BASE_ADDR, (x))); \
    } while (0)
#define SET_MEMBER_FLUSH_COMMON(type,reg_val,offset,base) \
    do { \
        ddr_writel(reg_val, SOC_##type##_##offset##_ADDR(SOC_##base##_BASE_ADDR)); \
    } while (0)
#define SET_MEMBER_FLUSH_COMMON_X(type,reg_val,offset,base,x) \
    do { \
        ddr_writel(reg_val, SOC_##type##_##offset##_ADDR(SOC_##base##_BASE_ADDR, (x))); \
    } while (0)
#define WAIT_MEMBER_COMMON_STAT(type,offset,member,expect_val,base) \
    do { \
        volatile unsigned int __val; \
        unsigned int __reg_val, __result; \
        do { \
            GET_MEMBER_FLUSH_COMMON(type, __reg_val, offset, base); \
            GET_MEMBER_CACHE(type, __reg_val, offset, member, __result); \
            __val = (unsigned int)(!!(__result != (expect_val))); \
        } while (__val); \
    } while (0)
#define WAIT_MEMBER_COMMON_STAT_DELAYUS(type,offset,member,expect_val,base,us) \
    do { \
        volatile unsigned int __val; \
        unsigned int __reg_val, __result; \
        do { \
            GET_MEMBER_FLUSH_COMMON(type, __reg_val, offset, base); \
            GET_MEMBER_CACHE(type, __reg_val, offset, member, __result); \
            __val = (unsigned int)(!!(__result != (expect_val))); \
            ddr_udelay(us); \
        } while (__val); \
    } while (0)
#define WAIT_MEMBER_COMMON_STAT_TIMEOUT(type,offset,member,expect_val,base,timeout) \
    do { \
        volatile unsigned int __val; \
        unsigned int __reg_val, __result; \
        do { \
            timeout--; \
            GET_MEMBER_FLUSH_COMMON(type, __reg_val, offset, base); \
            GET_MEMBER_CACHE(type, __reg_val, offset, member, __result); \
            __val = (unsigned int)(!!(__result != (expect_val))); \
        } while (__val && (timeout > 0)); \
    } while (0)
#define WAIT_MEMBER_COMMON_STAT_DELAYUS_OVERTIMEUS(type,offset,member,expect_val,base,dl,ot) \
    do { \
        volatile unsigned int __val; \
        unsigned int __reg_val, __result; \
        unsigned int __time = 0; \
        do { \
            GET_MEMBER_FLUSH_COMMON(type, __reg_val, offset, base); \
            GET_MEMBER_CACHE(type, __reg_val, offset, member, __result); \
            __val = (unsigned int)(!!(__result != (expect_val))); \
            ddr_udelay(dl); \
            __time += dl; \
        } while (__val && (__time < ot)); \
        if (__val) \
            ddr_system_error(DDR_PSCI_DDR_XPU_WFI_TIMEOUT, NULL, 0); \
    } while (0)
#define WAIT_REGVAL_COMMON_STAT_DELAYUS(type,offset,expect_val,base,us) \
    do { \
        unsigned int __reg_val; \
        do { \
            GET_MEMBER_FLUSH_COMMON(type, __reg_val, offset, base); \
            ddr_udelay(us); \
        } while (__reg_val != (unsigned int)(expect_val)); \
    } while (0)
#define WAIT_REGVAL_COMMON_STAT_TIMEOUT(type,offset,expect_val,base,timeout) \
    do { \
        unsigned int __reg_val; \
        unsigned int __timeout = timeout;\
        do { \
            timeout--; \
            GET_MEMBER_FLUSH_COMMON(type, __reg_val, offset, base); \
        } while (__reg_val != (unsigned int)(expect_val) && __timeout > 0); \
    } while (0)
#define WAIT_MEMBER_COMMON_STAT_X(type,offset,member,expect_val,base,x) \
    do { \
        volatile unsigned int __val; \
        unsigned int __reg_val, __result; \
        do { \
            GET_MEMBER_FLUSH_COMMON_X(type, __reg_val, offset, base, x); \
            GET_MEMBER_CACHE(type, __reg_val, offset, member, __result); \
            __val = (unsigned int)(!!(__result != (expect_val))); \
        } while (__val); \
    } while (0)
#define CHECK_MEMBER_COMMON_STAT(type,offset,member,expect_val,result,base) \
    do { \
        unsigned int __reg_val; \
        GET_MEMBER_FLUSH_COMMON(type, __reg_val, offset, base); \
        GET_MEMBER_CACHE(type, __reg_val, offset, member, result); \
        (result) = (unsigned int)(!!((result) != (expect_val))); \
    } while (0)
#define CHECK_MEMBER_COMMON_STAT_X(type,offset,member,expect_val,result,base,x) \
    do { \
        unsigned int __reg_val; \
        GET_MEMBER_FLUSH_COMMON_X(type, __reg_val, offset, base, x); \
        GET_MEMBER_CACHE(type, __reg_val, offset, member, result); \
        (result) = (unsigned int)(!!((result) != (expect_val))); \
    } while (0)
#define GET_MEMBER_FLUSH_COMMON_SINGLE(type,reg_val,offset,base,num) \
    do { \
        (reg_val) = ddr_readl(SOC_##type##_##offset##_ADDR(SOC_##base##_BASE_ADDR(num))); \
    } while (0)
#define SET_MEMBER_FLUSH_COMMON_SINGLE(type,reg_val,offset,base,num) \
    do { \
        ddr_writel(reg_val, SOC_##type##_##offset##_ADDR(SOC_##base##_BASE_ADDR(num))); \
    } while (0)
#endif
