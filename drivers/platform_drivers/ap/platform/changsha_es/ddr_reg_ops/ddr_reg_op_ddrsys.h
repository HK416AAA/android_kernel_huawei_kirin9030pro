#ifndef __DDR_REG_OP_DDRSYS_H__
#define __DDR_REG_OP_DDRSYS_H__ 
#include "ddr_reg_op_include.h"
#include "ddr_reg_op_logic.h"
#define GET_MEMBER_FLUSH_DDRSYS(type,reg_val,offset,base) \
    do { \
        (reg_val) = ddr_readl_reg(SOC_##type##_##offset##_ADDR(DDR_REG_##base(0))); \
    } while (0)
#define GET_MEMBER_FLUSH_DDRSYS_X(type,reg_val,offset,base,x) \
    do { \
        (reg_val) = ddr_readl_reg(SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), (x))); \
    } while (0)
#define GET_MEMBER_FLUSH_DDRSYS_X_Y(type,reg_val,offset,base,x,y) \
    do { \
        (reg_val) = ddr_readl_reg(SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), (x), (y))); \
    } while (0)
#define GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(type,reg_val,offset,base,x,y,z) \
    do { \
        (reg_val) = ddr_readl_reg(SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), (x), (y), (z))); \
    } while (0)
#define GET_MEMBER_FLUSH_DDRSYS_SINGLE(type,reg_val,offset,base,ch) \
    do { \
        (reg_val) = ddr_readl(SOC_##type##_##offset##_ADDR(DDR_REG_##base(ch))); \
 (void)ch; \
    } while (0)
#define GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(type,reg_val,offset,base,ch,x) \
    do { \
        (reg_val) = ddr_readl(SOC_##type##_##offset##_ADDR(DDR_REG_##base(ch), (x))); \
 (void)ch; \
    } while (0)
#define GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(type,reg_val,offset,base,ch,x,y) \
    do { \
        (reg_val) = ddr_readl(SOC_##type##_##offset##_ADDR(DDR_REG_##base(ch), (x), (y))); \
 (void)ch; \
    } while (0)
#define GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(type,reg_val,offset,base,ch,x,y,z) \
    do { \
        (reg_val) = ddr_readl(SOC_##type##_##offset##_ADDR(DDR_REG_##base(ch), (x), (y), (z))); \
 (void)ch; \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS(type,reg_val,offset,base) \
    do { \
        write_ddrsys_reg_all(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0))); \
    } while (0)
#define SET_MEMBER_RADIO_DDRSYS(type,reg_val,offset,base) \
    do { \
        ddr_writel(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_RADIO_##base)); \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS_X(type,reg_val,offset,base,x) \
    do { \
        write_ddrsys_reg_all(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), (x))); \
    } while (0)
#define SET_MEMBER_RADIO_DDRSYS_X(type,reg_val,offset,base,x) \
    do { \
        ddr_writel(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_RADIO_##base, (x))); \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS_X_Y(type,reg_val,offset,base,x,y) \
    do { \
        write_ddrsys_reg_all(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), (x), (y))); \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS_X_Y_Z(type,reg_val,offset,base,x,y,z) \
    do { \
        write_ddrsys_reg_all(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), (x), (y), (z))); \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS_MASK(type,reg_val,offset,base,base_mask) \
    do { \
        write_ddrsys_reg_base_mask(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0)), base_mask); \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS_MASK_X(type,reg_val,offset,base,base_mask,x) \
    do { \
        write_ddrsys_reg_base_mask(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), (x)), base_mask); \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y(type,reg_val,offset,base,base_mask,x,y) \
    do { \
        write_ddrsys_reg_base_mask(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), (x), (y)), base_mask); \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y_Z(type,reg_val,offset,base,base_mask,x,y,z) \
    do { \
        write_ddrsys_reg_base_mask(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), (x), (y), (z)), base_mask); \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS_SINGLE(type,reg_val,offset,base,ch) \
    do { \
        ddr_writel(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0)) + DDR_REG_CHANNEL_OFFSET(ch)); \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS_SINGLE_X(type,reg_val,offset,base,ch,x) \
    do { \
        write_ddrsys_reg_single(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), (x)), ch); \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(type,reg_val,offset,base,ch,x,y) \
    do { \
        write_ddrsys_reg_single(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), (x), (y)), ch); \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(type,reg_val,offset,base,ch,x,y,z) \
    do { \
        write_ddrsys_reg_single(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), (x), (y), (z)), ch); \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS_BROADCAST(type,reg_val,offset,base) \
    do { \
        write_ddrsys_reg_broadcast(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0))); \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X(type,reg_val,offset,base,x) \
    do { \
        write_ddrsys_reg_broadcast(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), x)); \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y(type,reg_val,offset,base,x,y) \
    do { \
        write_ddrsys_reg_broadcast(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), x, y)); \
    } while (0)
#define SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y_Z(type,reg_val,offset,base,x,y,z) \
    do { \
        write_ddrsys_reg_broadcast(reg_val, SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), x, y), (z)); \
    } while (0)
#define WAIT_MEMBER_DDRSYS_STAT(type,offset,base,member,expect_val) \
    do { \
        wait_member_status_ddrsys_reg(SOC_##type##_##offset##_ADDR(DDR_REG_##base(0)), GET_MEMBER_CACHE_MASK(type, offset, member), ((unsigned int)(expect_val) << (SOC_##type##_##offset##_##member##_START))); \
    } while (0)
#define WAIT_MEMBER_DDRSYS_STAT_X(type,offset,base,member,expect_val,x) \
    do { \
        wait_member_status_ddrsys_reg(SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), x), GET_MEMBER_CACHE_MASK(type, offset, member), ((unsigned int)(expect_val) << (SOC_##type##_##offset##_##member##_START))); \
    } while (0)
#define WAIT_MEMBER_DDRSYS_STAT_X_MASK(type,offset,base,member,expect_val,x,base_mask) \
    do { \
        wait_member_status_ddrsys_reg_base_mask(SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), x), GET_MEMBER_CACHE_MASK(type, offset, member), ((unsigned int)(expect_val) << (SOC_##type##_##offset##_##member##_START)), base_mask); \
    } while (0)
#define WAIT_MEMBER_DDRSYS_STAT_MASK(type,offset,base,member,expect_val,base_mask) \
    do { \
        wait_member_status_ddrsys_reg_base_mask(SOC_##type##_##offset##_ADDR(DDR_REG_##base(0)), GET_MEMBER_CACHE_MASK(type, offset, member), ((unsigned int)(expect_val) << (SOC_##type##_##offset##_##member##_START)), base_mask); \
    } while (0)
#define WAIT_MEMBER_DDRSYS_STAT_SINGLE(type,offset,base,member,expect_val,ch) \
    do { \
        wait_member_status_ddrsys_reg_single(SOC_##type##_##offset##_ADDR(DDR_REG_##base(0)), GET_MEMBER_CACHE_MASK(type, offset, member), ((unsigned int)(expect_val) << (SOC_##type##_##offset##_##member##_START)), ch); \
    } while (0)
#define WAIT_MEMBER_DDRSYS_STAT_SINGLE_X(type,offset,base,member,expect_val,ch,x) \
    do { \
        wait_member_status_ddrsys_reg_single(SOC_##type##_##offset##_ADDR(DDR_REG_##base(0), x), GET_MEMBER_CACHE_MASK(type, offset, member), ((unsigned int)(expect_val) << (SOC_##type##_##offset##_##member##_START)), ch); \
    } while (0)
#define CHECK_MEMBER_DDRSYS_STAT(type,offset,base,member,expect_val,result) \
    do { \
        (result) = check_member_status_ddrsys_reg(SOC_##type##_##offset##_ADDR(DDR_REG_##base(0)), GET_MEMBER_CACHE_MASK(type, offset, member), ((unsigned int)(expect_val) << (SOC_##type##_##offset##_##member##_START))); \
    } while (0)
#define CHECK_MEMBER_DDRSYS_STAT_MASK(type,offset,base,member,expect_val,result,base_mask) \
    do { \
        (result) = check_member_status_ddrsys_reg_base_mask(SOC_##type##_##offset##_ADDR(DDR_REG_##base(0)), GET_MEMBER_CACHE_MASK(type, offset, member), ((unsigned int)(expect_val) << (SOC_##type##_##offset##_##member##_START)), base_mask); \
    } while (0)
#define CHECK_MEMBER_DDRSYS_STAT_SINGLE(type,offset,base,member,expect_val,result,ch) \
    do { \
        (result) = check_member_status_ddrsys_reg_single(SOC_##type##_##offset##_ADDR(DDR_REG_##base(0)), GET_MEMBER_CACHE_MASK(type, offset, member), ((unsigned int)(expect_val) << (SOC_##type##_##offset##_##member##_START)), ch); \
    } while (0)
#endif
