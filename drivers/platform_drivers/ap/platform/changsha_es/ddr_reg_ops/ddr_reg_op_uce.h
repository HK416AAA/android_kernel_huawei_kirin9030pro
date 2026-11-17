#ifndef __DDR_REG_OP_UCE_H__
#define __DDR_REG_OP_UCE_H__ 
#include "ddr_reg_op_ddrsys.h"
#include "ddr_reg_op_sys.h"
#include <soc_ddr_uce_sctrl_interface.h>
#include <soc_hi_timer_v510_interface.h>
#include <ddr/ddr_uce_interface_manager.h>
#include <soc_ddr_pte_interface.h>
#define GET_MEMBER_CACHE_PTE(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(DDR_PTE, reg_val, offset, member, result)
#define GET_MEMBER_PTE(reg_val,offset) \
 GET_MEMBER_FLUSH_DDRSYS(DDR_PTE, reg_val, offset, PTE)
#define SAVE_MEMBER_PTE(reg_val,offset) \
 GET_MEMBER_PTE(reg_val, offset)
#define GET_MEMBER_PTE_X(reg_val,offset,x) \
 GET_MEMBER_FLUSH_DDRSYS_X(DDR_PTE, reg_val, offset, PTE, x)
#define GET_MEMBER_PTE_X_Y(reg_val,offset,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_PTE, reg_val, offset, PTE, x, y)
#define GET_MEMBER_PTE_X_Y_Z(reg_val,offset,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_PTE, reg_val, offset, PTE, x, y, z)
#define GET_MEMBER_PTE_SINGLE(reg_val,offset,ch) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_PTE, reg_val, offset, PTE, ch)
#define GET_MEMBER_PTE_SINGLE_X(reg_val,offset,ch,x) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_PTE, reg_val, offset, PTE, ch, x)
#define GET_MEMBER_PTE_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_PTE, reg_val, offset, PTE, ch, x, y)
#define GET_MEMBER_PTE_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_PTE, reg_val, offset, PTE, ch, x, y, z)
#define SET_MEMBER_CACHE_PTE(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(DDR_PTE, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_PTE(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(DDR_PTE, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_PTE(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS(DDR_PTE, reg_val, offset, PTE)
#define SET_MEMBER_FLUSH_PTE_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_DDRSYS_X(DDR_PTE, reg_val, offset, PTE, x)
#define SET_MEMBER_FLUSH_PTE_X_Y(reg_val,offset,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_PTE, reg_val, offset, PTE, x, y)
#define SET_MEMBER_FLUSH_PTE_X_Y_Z(reg_val,offset,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_PTE, reg_val, offset, PTE, x, y, z)
#define SET_MEMBER_FLUSH_PTE_MASK(reg_val,offset,base_mask) \
 SET_MEMBER_FLUSH_DDRSYS_MASK(DDR_PTE, reg_val, offset, PTE, base_mask)
#define SET_MEMBER_FLUSH_PTE_MASK_X(reg_val,offset,base_mask,x) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X(DDR_PTE, reg_val, offset, PTE, base_mask, x)
#define SET_MEMBER_FLUSH_PTE_MASK_X_Y(reg_val,offset,base_mask,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y(DDR_PTE, reg_val, offset, PTE, base_mask, x, y)
#define SET_MEMBER_FLUSH_PTE_MASK_X_Y_Z(reg_val,offset,base_mask,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y_Z(DDR_PTE, reg_val, offset, PTE, base_mask, x, y, z)
#define SET_MEMBER_FLUSH_PTE_SINGLE(reg_val,offset,ch) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_PTE, reg_val, offset, PTE, ch)
#define SET_MEMBER_FLUSH_PTE_SINGLE_X(reg_val,offset,ch,x) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_PTE, reg_val, offset, PTE, ch, x)
#define SET_MEMBER_FLUSH_PTE_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_PTE, reg_val, offset, PTE, ch, x, y)
#define SET_MEMBER_FLUSH_PTE_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_PTE, reg_val, offset, PTE, ch, x, y, z)
#define SET_MEMBER_FLUSH_PTE_BROADCAST(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST(DDR_PTE, reg_val, offset, PTE);
#define SET_MEMBER_FLUSH_PTE_BROADCAST_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X(DDR_PTE, reg_val, offset, PTE, x);
#define SET_MEMBER_FLUSH_PTE_BROADCAST_X_Y(reg_val,offset,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y(DDR_PTE, reg_val, offset, PTE, x, y);
#define SET_MEMBER_FLUSH_PTE_BROADCAST_X_Y_Z(reg_val,offset,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y_Z(DDR_PTE, reg_val, offset, PTE, x, y, z);
#define WAIT_MEMBER_PTE_STAT(offset,member,expect_val) \
 WAIT_MEMBER_DDRSYS_STAT(DDR_PTE, offset, PTE, member, expect_val)
#define WAIT_MEMBER_PTE_STAT_MASK(offset,member,expect_val,base_mask) \
 WAIT_MEMBER_DDRSYS_STAT_MASK(DDR_PTE, offset, PTE, member, expect_val, base_mask)
#define WAIT_MEMBER_PTE_STAT_SINGLE(offset,member,expect_val,ch) \
 WAIT_MEMBER_DDRSYS_STAT_SINGLE(DDR_PTE, offset, PTE, member, expect_val, ch)
#define CHECK_MEMBER_PTE_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_DDRSYS_STAT(DDR_PTE, offset, PTE, member, expect_val, result)
#define CHECK_MEMBER_PTE_STAT_MASK(offset,member,expect_val,result,base_mask) \
 CHECK_MEMBER_DDRSYS_STAT_MASK(DDR_PTE, offset, PTE, member, expect_val, result, base_mask)
#define CHECK_MEMBER_PTE_STAT_SINGLE(offset,member,expect_val,result,ch) \
 CHECK_MEMBER_DDRSYS_STAT_SINGLE(DDR_PTE, offset, PTE, member, expect_val, result, ch)
#define GET_MEMBER_CACHE_UCE_SCTRL(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(DDR_UCE_SCTRL, reg_val, offset, member, result)
#define GET_MEMBER_UCE_SCTRL(reg_val,offset) \
 GET_MEMBER_FLUSH_DDRSYS(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL)
#define GET_MEMBER_UCE_SCTRL_X(reg_val,offset,x) \
 GET_MEMBER_FLUSH_DDRSYS_X(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, x)
#define GET_MEMBER_UCE_SCTRL_X_Y(reg_val,offset,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, x, y)
#define GET_MEMBER_UCE_SCTRL_X_Y_Z(reg_val,offset,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, x, y, z)
#define GET_MEMBER_UCE_SCTRL_SINGLE(reg_val,offset,ch) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, ch)
#define GET_MEMBER_UCE_SCTRL_SINGLE_X(reg_val,offset,ch,x) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, ch, x)
#define GET_MEMBER_UCE_SCTRL_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, ch, x, y)
#define GET_MEMBER_UCE_SCTRL_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, ch, x, y, z)
#define SET_MEMBER_CACHE_UCE_SCTRL(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(DDR_UCE_SCTRL, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_UCE_SCTRL(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(DDR_UCE_SCTRL, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_UCE_SCTRL(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL)
#define SET_MEMBER_RADIO_UCE_SCTRL(reg_val,offset) \
 SET_MEMBER_RADIO_DDRSYS(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL)
#define SET_MEMBER_FLUSH_UCE_SCTRL_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_DDRSYS_X(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, x)
#define SET_MEMBER_FLUSH_UCE_SCTRL_X_Y(reg_val,offset,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_X_Y(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, x, y)
#define SET_MEMBER_FLUSH_UCE_SCTRL_X_Y_Z(reg_val,offset,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_X_Y_Z(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, x, y, z)
#define SET_MEMBER_FLUSH_UCE_SCTRL_MASK(reg_val,offset,base_mask) \
 SET_MEMBER_FLUSH_DDRSYS_MASK(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, base_mask)
#define SET_MEMBER_FLUSH_UCE_SCTRL_MASK_X(reg_val,offset,base_mask,x) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, base_mask, x)
#define SET_MEMBER_FLUSH_UCE_SCTRL_MASK_X_Y(reg_val,offset,base_mask,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, base_mask, x, y)
#define SET_MEMBER_FLUSH_UCE_SCTRL_MASK_X_Y_Z(reg_val,offset,base_mask,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y_Z(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, base_mask, x, y, z)
#define SET_MEMBER_FLUSH_UCE_SCTRL_SINGLE(reg_val,offset,ch) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, ch)
#define SET_MEMBER_FLUSH_UCE_SCTRL_SINGLE_X(reg_val,offset,ch,x) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, ch, x)
#define SET_MEMBER_FLUSH_UCE_SCTRL_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, ch, x, y)
#define SET_MEMBER_FLUSH_UCE_SCTRL_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, ch, x, y, z)
#define SET_MEMBER_FLUSH_UCE_SCTRL_BROADCAST(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL);
#define SET_MEMBER_FLUSH_UCE_SCTRL_BROADCAST_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, x);
#define SET_MEMBER_FLUSH_UCE_SCTRL_BROADCAST_X_Y(reg_val,offset,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, x, y);
#define SET_MEMBER_FLUSH_UCE_SCTRL_BROADCAST_X_Y_Z(reg_val,offset,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y_Z(DDR_UCE_SCTRL, reg_val, offset, UCE_SCTRL, x, y, z);
#define WAIT_MEMBER_UCE_SCTRL_STAT(offset,member,expect_val) \
 WAIT_MEMBER_DDRSYS_STAT(DDR_UCE_SCTRL, offset, UCE_SCTRL, member, expect_val)
#define WAIT_MEMBER_UCE_SCTRL_STAT_MASK(offset,member,expect_val,base_mask) \
 WAIT_MEMBER_DDRSYS_STAT_MASK(DDR_UCE_SCTRL, offset, UCE_SCTRL, member, expect_val, base_mask)
#define WAIT_MEMBER_UCE_SCTRL_STAT_SINGLE(offset,member,expect_val,ch) \
 WAIT_MEMBER_DDRSYS_STAT_SINGLE(DDR_UCE_SCTRL, offset, UCE_SCTRL, member, expect_val, ch)
#define CHECK_MEMBER_UCE_SCTRL_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_DDRSYS_STAT(DDR_UCE_SCTRL, offset, UCE_SCTRL, member, expect_val, result)
#define CHECK_MEMBER_UCE_SCTRL_STAT_MASK(offset,member,expect_val,result,base_mask) \
 CHECK_MEMBER_DDRSYS_STAT_MASK(DDR_UCE_SCTRL, offset, UCE_SCTRL, member, expect_val, result, base_mask)
#define CHECK_MEMBER_UCE_SCTRL_STAT_SINGLE(offset,member,expect_val,result,ch) \
 CHECK_MEMBER_DDRSYS_STAT_SINGLE(DDR_UCE_SCTRL, offset, UCE_SCTRL, member, expect_val, result, ch)
#define GET_MEMBER_UCE_TIMER_SINGLE(reg_val,offset,num) \
 GET_MEMBER_FLUSH_COMMON_SINGLE(HI_TIMER_V510, reg_val, offset, UCE_TIMER, num)
#define GET_MEMBER_CACHE_UCE_TIMER(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(HI_TIMER_V510, reg_val, offset, member, result)
#define SET_MEMBER_CACHE_UCE_TIMER(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(HI_TIMER_V510, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_UCE_TIMER(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(HI_TIMER_V510, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_UCE_TIMER_SINGLE(reg_val,offset,num) \
 SET_MEMBER_FLUSH_COMMON_SINGLE(HI_TIMER_V510, reg_val, offset, UCE_TIMER, num)
#define GET_MEMBER_UCE_UART(reg_val,offset) \
 GET_MEMBER_FLUSH_DDRSYS(HI_UART_V500, reg_val, offset, UCE_UART)
#define GET_MEMBER_CACHE_UCE_UART(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(HI_UART_V500, reg_val, offset, member, result)
#define SET_MEMBER_CACHE_UCE_UART(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(HI_UART_V500, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_UCE_UART(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(HI_UART_V500, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_UCE_UART(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS(HI_UART_V500, reg_val, offset, UCE_UART)
#define GET_MEMBER_UCE_WDG(reg_val,offset) \
 GET_MEMBER_FLUSH_DDRSYS(HI_WatchDog_V500, reg_val, offset, UCE_WDG)
#define SET_MEMBER_CACHE_UCE_WDG(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(HI_WatchDog_V500, reg_val, offset, member, cfg_val)
#define SET_MEMBER_FLUSH_UCE_WDG(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS(HI_WatchDog_V500, reg_val, offset, UCE_WDG)
#define GET_MEMBER_CACHE_UCEINPUT(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(UCEINPUT, reg_val, offset, member, result)
#define GET_MEMBER_UCEINPUT(reg_val,offset) \
 GET_MEMBER_FLUSH_DDRSYS(UCEINPUT, reg_val, offset, UCEINPUT)
#define SAVE_MEMBER_UCEINPUT(reg_val,offset) \
 GET_MEMBER_FLUSH_DDRSYS(UCEINPUT, reg_val, offset, UCEINPUT)
#define GET_MEMBER_UCEINPUT_X(reg_val,offset,x) \
 GET_MEMBER_FLUSH_DDRSYS_X(UCEINPUT, reg_val, offset, UCEINPUT, x)
#define SAVE_MEMBER_UCEINPUT_X(reg_val,offset,x) \
 GET_MEMBER_FLUSH_DDRSYS_X(UCEINPUT, reg_val, offset, UCEINPUT, x)
#define GET_MEMBER_UCEINPUT_X_Y(reg_val,offset,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y(UCEINPUT, reg_val, offset, UCEINPUT, x, y)
#define SAVE_MEMBER_UCEINPUT_X_Y(reg_val,offset,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y(UCEINPUT, reg_val, offset, UCEINPUT, x, y)
#define GET_MEMBER_UCEINPUT_X_Y_Z(reg_val,offset,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(UCEINPUT, reg_val, offset, UCEINPUT, x, y, z)
#define SAVE_MEMBER_UCEINPUT_X_Y_Z(reg_val,offset,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(UCEINPUT, reg_val, offset, UCEINPUT, x, y, z)
#define GET_MEMBER_UCEINPUT_SINGLE(reg_val,offset,ch) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE(UCEINPUT, reg_val, offset, UCEINPUT, ch)
#define SAVE_MEMBER_UCEINPUT_SINGLE(reg_val,offset,ch) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE(UCEINPUT, reg_val, offset, UCEINPUT, ch)
#define GET_MEMBER_UCEINPUT_SINGLE_X(reg_val,offset,ch,x) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(UCEINPUT, reg_val, offset, UCEINPUT, ch, x)
#define SAVE_MEMBER_UCEINPUT_SINGLE_X(reg_val,offset,ch,x) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(UCEINPUT, reg_val, offset, UCEINPUT, ch, x)
#define GET_MEMBER_UCEINPUT_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(UCEINPUT, reg_val, offset, UCEINPUT, ch, x, y)
#define SAVE_MEMBER_UCEINPUT_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(UCEINPUT, reg_val, offset, UCEINPUT, ch, x, y)
#define GET_MEMBER_UCEINPUT_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(UCEINPUT, reg_val, offset, UCEINPUT, ch, x, y, z)
#define SAVE_MEMBER_UCEINPUT_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(UCEINPUT, reg_val, offset, UCEINPUT, ch, x, y, z)
#define SET_MEMBER_CACHE_UCEINPUT(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(UCEINPUT, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_UCEINPUT(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(UCEINPUT, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_UCEINPUT(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS(UCEINPUT, reg_val, offset, UCEINPUT)
#define SET_MEMBER_RADIO_UCEINPUT(reg_val,offset) \
 SET_MEMBER_RADIO_DDRSYS(UCEINPUT, reg_val, offset, UCEINPUT)
#define SET_MEMBER_FLUSH_UCEINPUT_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_DDRSYS_X(UCEINPUT, reg_val, offset, UCEINPUT, x)
#define SET_MEMBER_RADIO_UCEINPUT_X(reg_val,offset,x) \
 SET_MEMBER_RADIO_DDRSYS_X(UCEINPUT, reg_val, offset, UCEINPUT, x)
#define SET_MEMBER_FLUSH_UCEINPUT_X_Y(reg_val,offset,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_X_Y(UCEINPUT, reg_val, offset, UCEINPUT, x, y)
#define SET_MEMBER_FLUSH_UCEINPUT_X_Y_Z(reg_val,offset,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_X_Y_Z(UCEINPUT, reg_val, offset, UCEINPUT, x, y, z)
#define SET_MEMBER_FLUSH_UCEINPUT_MASK(reg_val,offset,base_mask) \
 SET_MEMBER_FLUSH_DDRSYS_MASK(UCEINPUT, reg_val, offset, UCEINPUT, base_mask)
#define SET_MEMBER_FLUSH_UCEINPUT_MASK_X(reg_val,offset,base_mask,x) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X(UCEINPUT, reg_val, offset, UCEINPUT, base_mask, x)
#define SET_MEMBER_FLUSH_UCEINPUT_MASK_X_Y(reg_val,offset,base_mask,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y(UCEINPUT, reg_val, offset, UCEINPUT, base_mask, x, y)
#define SET_MEMBER_FLUSH_UCEINPUT_MASK_X_Y_Z(reg_val,offset,base_mask,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y_Z(UCEINPUT, reg_val, offset, UCEINPUT, base_mask, x, y, z)
#define SET_MEMBER_FLUSH_UCEINPUT_SINGLE(reg_val,offset,ch) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE(UCEINPUT, reg_val, offset, UCEINPUT, ch)
#define SET_MEMBER_FLUSH_UCEINPUT_SINGLE_X(reg_val,offset,ch,x) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X(UCEINPUT, reg_val, offset, UCEINPUT, ch, x)
#define SET_MEMBER_FLUSH_UCEINPUT_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(UCEINPUT, reg_val, offset, UCEINPUT, ch, x, y)
#define SET_MEMBER_FLUSH_UCEINPUT_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(UCEINPUT, reg_val, offset, UCEINPUT, ch, x, y, z)
#define SET_MEMBER_FLUSH_UCEINPUT_BROADCAST(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST(UCEINPUT, reg_val, offset, UCEINPUT);
#define SET_MEMBER_FLUSH_UCEINPUT_BROADCAST_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X(UCEINPUT, reg_val, offset, UCEINPUT, x);
#define SET_MEMBER_FLUSH_UCEINPUT_BROADCAST_X_Y(reg_val,offset,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y(UCEINPUT, reg_val, offset, UCEINPUT, x, y);
#define SET_MEMBER_FLUSH_UCEINPUT_BROADCAST_X_Y_Z(reg_val,offset,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y_Z(UCEINPUT, reg_val, offset, UCEINPUT, x, y, z);
#define WAIT_MEMBER_UCEINPUT_STAT(offset,member,expect_val) \
 WAIT_MEMBER_DDRSYS_STAT(UCEINPUT, offset, UCEINPUT, member, expect_val)
#define WAIT_MEMBER_UCEINPUT_STAT_MASK(offset,member,expect_val,base_mask) \
 WAIT_MEMBER_DDRSYS_STAT_MASK(UCEINPUT, offset, UCEINPUT, member, expect_val, base_mask)
#define WAIT_MEMBER_UCEINPUT_STAT_SINGLE(offset,member,expect_val,ch) \
 WAIT_MEMBER_DDRSYS_STAT_SINGLE(UCEINPUT, offset, UCEINPUT, member, expect_val, ch)
#define CHECK_MEMBER_UCEINPUT_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_DDRSYS_STAT(UCEINPUT, offset, UCEINPUT, member, expect_val, result)
#define CHECK_MEMBER_UCEINPUT_STAT_MASK(offset,member,expect_val,result,base_mask) \
 CHECK_MEMBER_DDRSYS_STAT_MASK(UCEINPUT, offset, UCEINPUT, member, expect_val, result, base_mask)
#define CHECK_MEMBER_UCEINPUT_STAT_SINGLE(offset,member,expect_val,result,ch) \
 CHECK_MEMBER_DDRSYS_STAT_SINGLE(UCEINPUT, offset, UCEINPUT, member, expect_val, result, ch)
#define GET_MEMBER_CACHE_UCEOUTPUT(reg_val,offset,member,result) \
 GET_MEMBER_CACHE(UCEOUTPUT, reg_val, offset, member, result)
#define GET_MEMBER_UCEOUTPUT(reg_val,offset) \
 GET_MEMBER_FLUSH_DDRSYS(UCEOUTPUT, reg_val, offset, UCEOUTPUT)
#define SAVE_MEMBER_UCEOUTPUT(reg_val,offset) \
 GET_MEMBER_FLUSH_DDRSYS(UCEOUTPUT, reg_val, offset, UCEOUTPUT)
#define GET_MEMBER_UCEOUTPUT_X(reg_val,offset,x) \
 GET_MEMBER_FLUSH_DDRSYS_X(UCEOUTPUT, reg_val, offset, UCEOUTPUT, x)
#define SAVE_MEMBER_UCEOUTPUT_X(reg_val,offset,x) \
 GET_MEMBER_FLUSH_DDRSYS_X(UCEOUTPUT, reg_val, offset, UCEOUTPUT, x)
#define GET_MEMBER_UCEOUTPUT_X_Y(reg_val,offset,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y(UCEOUTPUT, reg_val, offset, UCEOUTPUT, x, y)
#define SAVE_MEMBER_UCEOUTPUT_X_Y(reg_val,offset,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y(UCEOUTPUT, reg_val, offset, UCEOUTPUT, x, y)
#define GET_MEMBER_UCEOUTPUT_X_Y_Z(reg_val,offset,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(UCEOUTPUT, reg_val, offset, UCEOUTPUT, x, y, z)
#define SAVE_MEMBER_UCEOUTPUT_X_Y_Z(reg_val,offset,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_X_Y_Z(UCEOUTPUT, reg_val, offset, UCEOUTPUT, x, y, z)
#define GET_MEMBER_UCEOUTPUT_SINGLE(reg_val,offset,ch) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE(UCEOUTPUT, reg_val, offset, UCEOUTPUT, ch)
#define SAVE_MEMBER_UCEOUTPUT_SINGLE(reg_val,offset,ch) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE(UCEOUTPUT, reg_val, offset, UCEOUTPUT, ch)
#define GET_MEMBER_UCEOUTPUT_SINGLE_X(reg_val,offset,ch,x) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(UCEOUTPUT, reg_val, offset, UCEOUTPUT, ch, x)
#define SAVE_MEMBER_UCEOUTPUT_SINGLE_X(reg_val,offset,ch,x) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X(UCEOUTPUT, reg_val, offset, UCEOUTPUT, ch, x)
#define GET_MEMBER_UCEOUTPUT_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(UCEOUTPUT, reg_val, offset, UCEOUTPUT, ch, x, y)
#define SAVE_MEMBER_UCEOUTPUT_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(UCEOUTPUT, reg_val, offset, UCEOUTPUT, ch, x, y)
#define GET_MEMBER_UCEOUTPUT_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(UCEOUTPUT, reg_val, offset, UCEOUTPUT, ch, x, y, z)
#define SAVE_MEMBER_UCEOUTPUT_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 GET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(UCEOUTPUT, reg_val, offset, UCEOUTPUT, ch, x, y, z)
#define SET_MEMBER_CACHE_UCEOUTPUT(reg_val,offset,member,cfg_val) \
 SET_MEMBER_CACHE(UCEOUTPUT, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_UCEOUTPUT(reg_val,offset,member,bitmask,cfg_val) \
 SET_MEMBER_CACHE_BITMASKEN(UCEOUTPUT, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_UCEOUTPUT(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS(UCEOUTPUT, reg_val, offset, UCEOUTPUT)
#define SET_MEMBER_RADIO_UCEOUTPUT(reg_val,offset) \
 SET_MEMBER_RADIO_DDRSYS(UCEOUTPUT, reg_val, offset, UCEOUTPUT)
#define SET_MEMBER_FLUSH_UCEOUTPUT_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_DDRSYS_X(UCEOUTPUT, reg_val, offset, UCEOUTPUT, x)
#define SET_MEMBER_RADIO_UCEOUTPUT_X(reg_val,offset,x) \
 SET_MEMBER_RADIO_DDRSYS_X(UCEOUTPUT, reg_val, offset, UCEOUTPUT, x)
#define SET_MEMBER_FLUSH_UCEOUTPUT_X_Y(reg_val,offset,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_X_Y(UCEOUTPUT, reg_val, offset, UCEOUTPUT, x, y)
#define SET_MEMBER_FLUSH_UCEOUTPUT_X_Y_Z(reg_val,offset,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_X_Y_Z(UCEOUTPUT, reg_val, offset, UCEOUTPUT, x, y, z)
#define SET_MEMBER_FLUSH_UCEOUTPUT_MASK(reg_val,offset,base_mask) \
 SET_MEMBER_FLUSH_DDRSYS_MASK(UCEOUTPUT, reg_val, offset, UCEOUTPUT, base_mask)
#define SET_MEMBER_FLUSH_UCEOUTPUT_MASK_X(reg_val,offset,base_mask,x) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X(UCEOUTPUT, reg_val, offset, UCEOUTPUT, base_mask, x)
#define SET_MEMBER_FLUSH_UCEOUTPUT_MASK_X_Y(reg_val,offset,base_mask,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y(UCEOUTPUT, reg_val, offset, UCEOUTPUT, base_mask, x, y)
#define SET_MEMBER_FLUSH_UCEOUTPUT_MASK_X_Y_Z(reg_val,offset,base_mask,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_MASK_X_Y_Z(UCEOUTPUT, reg_val, offset, UCEOUTPUT, base_mask, x, y, z)
#define SET_MEMBER_FLUSH_UCEOUTPUT_SINGLE(reg_val,offset,ch) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE(UCEOUTPUT, reg_val, offset, UCEOUTPUT, ch)
#define SET_MEMBER_FLUSH_UCEOUTPUT_SINGLE_X(reg_val,offset,ch,x) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X(UCEOUTPUT, reg_val, offset, UCEOUTPUT, ch, x)
#define SET_MEMBER_FLUSH_UCEOUTPUT_SINGLE_X_Y(reg_val,offset,ch,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y(UCEOUTPUT, reg_val, offset, UCEOUTPUT, ch, x, y)
#define SET_MEMBER_FLUSH_UCEOUTPUT_SINGLE_X_Y_Z(reg_val,offset,ch,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_SINGLE_X_Y_Z(UCEOUTPUT, reg_val, offset, UCEOUTPUT, ch, x, y, z)
#define SET_MEMBER_FLUSH_UCEOUTPUT_BROADCAST(reg_val,offset) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST(UCEOUTPUT, reg_val, offset, UCEOUTPUT);
#define SET_MEMBER_FLUSH_UCEOUTPUT_BROADCAST_X(reg_val,offset,x) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X(UCEOUTPUT, reg_val, offset, UCEOUTPUT, x);
#define SET_MEMBER_FLUSH_UCEOUTPUT_BROADCAST_X_Y(reg_val,offset,x,y) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y(UCEOUTPUT, reg_val, offset, UCEOUTPUT, x, y);
#define SET_MEMBER_FLUSH_UCEOUTPUT_BROADCAST_X_Y_Z(reg_val,offset,x,y,z) \
 SET_MEMBER_FLUSH_DDRSYS_BROADCAST_X_Y_Z(UCEOUTPUT, reg_val, offset, UCEOUTPUT, x, y, z);
#define WAIT_MEMBER_UCEOUTPUT_STAT(offset,member,expect_val) \
 WAIT_MEMBER_DDRSYS_STAT(UCEOUTPUT, offset, UCEOUTPUT, member, expect_val)
#define WAIT_MEMBER_UCEOUTPUT_STAT_MASK(offset,member,expect_val,base_mask) \
 WAIT_MEMBER_DDRSYS_STAT_MASK(UCEOUTPUT, offset, UCEOUTPUT, member, expect_val, base_mask)
#define WAIT_MEMBER_UCEOUTPUT_STAT_SINGLE(offset,member,expect_val,ch) \
 WAIT_MEMBER_DDRSYS_STAT_SINGLE(UCEOUTPUT, offset, UCEOUTPUT, member, expect_val, ch)
#define CHECK_MEMBER_UCEOUTPUT_STAT(offset,member,expect_val,result) \
 CHECK_MEMBER_DDRSYS_STAT(UCEOUTPUT, offset, UCEOUTPUT, member, expect_val, result)
#define CHECK_MEMBER_UCEOUTPUT_STAT_MASK(offset,member,expect_val,result,base_mask) \
 CHECK_MEMBER_DDRSYS_STAT_MASK(UCEOUTPUT, offset, UCEOUTPUT, member, expect_val, result, base_mask)
#define CHECK_MEMBER_UCEOUTPUT_STAT_SINGLE(offset,member,expect_val,result,ch) \
 CHECK_MEMBER_DDRSYS_STAT_SINGLE(UCEOUTPUT, offset, UCEOUTPUT, member, expect_val, result, ch)
#endif
