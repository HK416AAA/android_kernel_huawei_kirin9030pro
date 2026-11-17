#ifndef __DDR_REG_OP_XPU_H__
#define __DDR_REG_OP_XPU_H__ 
#include "ddr_reg_op_ddrsys.h"
#include "ddr_reg_op_sys.h"
#include <soc_ddr_xpu_baseaddr_interface.h>
#include <ddr/ddr_nmanager_extend.h>
#include "ddr_reg_ops/ddr_reg_op_logic.h"
#include <soc_pmctrl_xpu_interface.h>
#include <soc_pmctrl_unit_xpu_interface.h>
#include <soc_xpu_lp_ctrl_cfg_interface.h>
#include <soc_hi_watchdog_v500_interface.h>
#include <soc_hi_uart_v500_interface.h>
#include <soc_hi_timer_v510_interface.h>
#include <soc_ioc_ao_interface.h>
#include <ddr/ddr_xpu_interface_nmanager.h>
#include <ddr_xpu_sram_map.h>
#ifdef __riscv
#include <core.h>
#endif
#define GET_MEMBER_XPU_WDG(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(HI_WatchDog_V500, reg_val, offset, XPU_WDG)
#define SET_MEMBER_CACHE_XPU_WDG(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(HI_WatchDog_V500, reg_val, offset, member, cfg_val)
#define SET_MEMBER_FLUSH_XPU_WDG(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(HI_WatchDog_V500, reg_val, offset, XPU_WDG)
#define GET_MEMBER_XPU_UART(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(HI_UART_V500, reg_val, offset, XPU_UART)
#define GET_MEMBER_CACHE_XPU_UART(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(HI_UART_V500, reg_val, offset, member, result)
#define SET_MEMBER_CACHE_XPU_UART(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(HI_UART_V500, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_XPU_UART(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(HI_UART_V500, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_XPU_UART(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(HI_UART_V500, reg_val, offset, XPU_UART)
#define WAIT_MEMBER_XPU_UART_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(HI_UART_V500, offset, member, expect_val, XPU_UART)
#define GET_MEMBER_XPU_TIMER_SINGLE(reg_val,offset,num) \
    GET_MEMBER_FLUSH_COMMON_SINGLE(HI_TIMER_V510, reg_val, offset, XPU_TIMER, num)
#define GET_MEMBER_CACHE_XPU_TIMER(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(HI_TIMER_V510, reg_val, offset, member, result)
#define SET_MEMBER_CACHE_XPU_TIMER(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(HI_TIMER_V510, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_XPU_TIMER(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(HI_TIMER_V510, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_XPU_TIMER_SINGLE(reg_val,offset,num) \
    SET_MEMBER_FLUSH_COMMON_SINGLE(HI_TIMER_V510, reg_val, offset, XPU_TIMER, num)
#define GET_MEMBER_PMCTRL_XPU(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(XPU_LP_CTRL_CFG, reg_val, offset, XPU_PMCTRL)
#define GET_MEMBER_PMCTRL_XPU_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_COMMON_X(XPU_LP_CTRL_CFG, reg_val, offset, XPU_PMCTRL, x)
#define GET_MEMBER_CACHE_PMCTRL_XPU(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(XPU_LP_CTRL_CFG, reg_val, offset, member, result)
#define SET_MEMBER_CACHE_PMCTRL_XPU(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(XPU_LP_CTRL_CFG, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_PMCTRL_XPU(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(XPU_LP_CTRL_CFG, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_PMCTRL_XPU(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(XPU_LP_CTRL_CFG, reg_val, offset, XPU_PMCTRL)
#define SET_MEMBER_FLUSH_PMCTRL_XPU_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_COMMON_X(XPU_LP_CTRL_CFG, reg_val, offset, XPU_PMCTRL, x)
#define WAIT_MEMBER_PMCTRL_XPU_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(XPU_LP_CTRL_CFG, offset, member, expect_val, XPU_PMCTRL)
#define GET_MEMBER_XPUINPUT(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(XPUINPUT, reg_val, offset, XPUINPUT)
#define GET_MEMBER_CACHE_XPUINPUT(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(XPUINPUT, reg_val, offset, member, result)
#define GET_MEMBER_XPUINPUT_X(reg_val,offset,x) \
 GET_MEMBER_FLUSH_COMMON_X(XPUINPUT, reg_val, offset, XPUINPUT, x)
#define SET_MEMBER_CACHE_XPUINPUT(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(XPUINPUT, reg_val, offset, member, cfg_val)
#define SET_MEMBER_FLUSH_XPUINPUT(reg_val,offset) \
    do {SET_MEMBER_FLUSH_COMMON(XPUINPUT, reg_val, offset, XPUINPUT);dsb();} while(0)
#define SET_MEMBER_FLUSH_XPUINPUT_X(reg_val,offset,x) \
    do {SET_MEMBER_FLUSH_COMMON_X(XPUINPUT, reg_val, offset, XPUINPUT, x);dsb();} while(0)
#define WAIT_MEMBER_STAT_XPUINPUT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(XPUINPUT, offset, member, expect_val, XPUINPUT)
#define WAIT_REGVAL_STAT_XPUINPUT_DELAYUS(offset,expect_val,delay_us) \
    WAIT_REGVAL_COMMON_STAT_DELAYUS(XPUINPUT, offset, expect_val, XPUINPUT, us)
#define WAIT_MEMBER_STAT_XPUINPUT_DELAYUS(offset,member,expect_val,delay_us) \
    WAIT_MEMBER_COMMON_STAT_DELAYUS(XPUINPUT, offset, member, expect_val, XPUINPUT, delay_us)
#define GET_MEMBER_XPUOUTPUT(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(XPUOUTPUT, reg_val, offset, XPUOUTPUT)
#define GET_MEMBER_XPUOUTPUT_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_COMMON_X(XPUOUTPUT, reg_val, offset, XPUOUTPUT, x)
#define GET_MEMBER_CACHE_XPUOUTPUT(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(XPUOUTPUT, reg_val, offset, member, result)
#define SET_MEMBER_CACHE_XPUOUTPUT(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(XPUOUTPUT, reg_val, offset, member, cfg_val)
#define SET_MEMBER_FLUSH_XPUOUTPUT(reg_val,offset) \
    do {SET_MEMBER_FLUSH_COMMON(XPUOUTPUT, reg_val, offset, XPUOUTPUT);dsb();} while(0)
#define SET_MEMBER_FLUSH_XPUOUTPUT_X(reg_val,offset,x) \
    do {SET_MEMBER_FLUSH_COMMON_X(XPUOUTPUT, reg_val, offset, XPUOUTPUT, x);dsb();} while(0)
#define WAIT_MEMBER_STAT_XPUOUTPUT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(XPUOUTPUT, offset, member, expect_val, XPUOUTPUT)
#define WAIT_REGVAL_STAT_XPUOUTPUT_DELAYUS(offset,expect_val,delay_us) \
    WAIT_REGVAL_COMMON_STAT_DELAYUS(XPUOUTPUT, offset, expect_val, XPUOUTPUT, delay_us)
#define WAIT_MEMBER_STAT_XPUOUTPUT_DELAYUS(offset,member,expect_val,delay_us) \
    WAIT_MEMBER_COMMON_STAT_DELAYUS(XPUOUTPUT, offset, member, expect_val, XPUOUTPUT, delay_us)
#define WAIT_MEMBER_STAT_XPUOUTPUT_DELAYUS_OVERTIMEUS(offset,member,expect_val,delay_us,overtime_us) \
    WAIT_MEMBER_COMMON_STAT_DELAYUS_OVERTIMEUS(XPUOUTPUT, offset, member, expect_val, XPUOUTPUT, delay_us, overtime_us)
#define GET_MEMBER_XPUREQUEST(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(XPUREQUEST, reg_val, offset, XPUREQUEST)
#define GET_MEMBER_CACHE_XPUREQUEST(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(XPUREQUEST, reg_val, offset, member, result)
#define SET_MEMBER_CACHE_XPUREQUEST(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(XPUREQUEST, reg_val, offset, member, cfg_val)
#define SET_MEMBER_FLUSH_XPUREQUEST(reg_val,offset) \
    do {SET_MEMBER_FLUSH_COMMON(XPUREQUEST, reg_val, offset, XPUREQUEST);dsb();} while(0)
#define WAIT_MEMBER_STAT_XPUREQUEST(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(XPUREQUEST, offset, member, expect_val, XPUREQUEST)
#define WAIT_REGVAL_STAT_XPUREQUEST_DELAYUS(offset,expect_val,delay_us) \
    WAIT_REGVAL_COMMON_STAT_DELAYUS(XPUREQUEST, offset, expect_val, XPUREQUEST, us)
#define WAIT_MEMBER_STAT_XPUREQUEST_DELAYUS(offset,member,expect_val,delay_us) \
    WAIT_MEMBER_COMMON_STAT_DELAYUS(XPUREQUEST, offset, member, expect_val, XPUREQUEST, delay_us)
#define WAIT_MEMBER_STAT_XPUREQUEST_TIMEOUT(offset,member,expect_val,timeout) \
    WAIT_MEMBER_COMMON_STAT_TIMEOUT(XPUREQUEST, offset, member, expect_val, XPUREQUEST, timeout)
#define GET_MEMBER_XPU_LP_CTRL_CFG(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(XPU_LP_CTRL_CFG, reg_val, offset, XPU_PMCTRL)
#define GET_MEMBER_XPU_LP_CTRL_CFG_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_COMMON_X(XPU_LP_CTRL_CFG, reg_val, offset, XPU_PMCTRL, x)
#define GET_MEMBER_CACHE_XPU_LP_CTRL_CFG(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(XPU_LP_CTRL_CFG, reg_val, offset, member, result)
#define SET_MEMBER_CACHE_XPU_LP_CTRL_CFG(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(XPU_LP_CTRL_CFG, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_XPU_LP_CTRL_CFG(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(XPU_LP_CTRL_CFG, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_XPU_LP_CTRL_CFG(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(XPU_LP_CTRL_CFG, reg_val, offset, XPU_PMCTRL)
#define WAIT_MEMBER_XPU_LP_CTRL_CFG_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(XPU_LP_CTRL_CFG, offset, member, expect_val, XPU_PMCTRL)
#endif
