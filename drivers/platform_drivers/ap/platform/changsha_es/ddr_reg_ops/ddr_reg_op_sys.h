#ifndef __DDR_REG_OP_SYS_H__
#define __DDR_REG_OP_SYS_H__ 
#include "ddr_reg_op_logic.h"
#include <soc_actrl_interface.h>
#include <soc_crgperiph_interface.h>
#include <soc_ao_crg_interface.h>
#ifndef DDR_EDA_IT
#include <soc_pmctrl_interface.h>
#include <soc_sctrl_interface.h>
#endif
#include <soc_tzpc_interface.h>
#include <soc_pctrl_interface.h>
#include <soc_lpm3_cfg_interface.h>
#include <soc_lpmcu_interface.h>
#include <soc_media2_ctrl_interface.h>
#include <soc_npu_ctrl_interface.h>
#include <soc_spmimst_interface.h>
#include <soc_ioc_ao_interface.h>
#include <soc_pad_ao_interface.h>
#include <soc_ipcns_interface.h>
#include <soc_ipc_interface.h>
#include <soc_pad_peri_interface.h>
#include <soc_ioc_peri_interface.h>
#include <soc_bisr_ctrl_interface.h>
#include <soc_qice_chi2qsp_interface.h>
#include <soc_core_crg_interface.h>
#include <soc_cpu_rtm_interface.h>
#define GET_MEMBER_CACHE_CPU_RTM(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(CPU_RTM, reg_val, offset, member, result)
#define GET_MEMBER_CPU_RTM(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(CPU_RTM, reg_val, offset, CPU_RTM)
#define SET_MEMBER_CACHE_CPU_RTM(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(CPU_RTM, reg_val, offset, member, cfg_val)
#define SET_MEMBER_FLUSH_CPU_RTM(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(CPU_RTM, reg_val, offset, CPU_RTM)
#define GET_MEMBER_CACHE_CORE_CRG(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(CORE_CRG, reg_val, offset, member, result)
#define GET_MEMBER_CORE_CRG(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(CORE_CRG, reg_val, offset, CORE_CRG)
#define SET_MEMBER_CACHE_CORE_CRG(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(CORE_CRG, reg_val, offset, member, cfg_val)
#define SET_MEMBER_FLUSH_CORE_CRG(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(CORE_CRG, reg_val, offset, CORE_CRG)
#define GET_MEMBER_CACHE_CRGPERIPH(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(CRGPERIPH, reg_val, offset, member, result)
#define GET_MEMBER_CRGPERIPH(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(CRGPERIPH, reg_val, offset, PERI_CRG)
#define SET_MEMBER_CACHE_CRGPERIPH(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(CRGPERIPH, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_CRGPERIPH(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(CRGPERIPH, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_CRGPERIPH(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(CRGPERIPH, reg_val, offset, PERI_CRG)
#define WAIT_MEMBER_CRGPERIPH_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(CRGPERIPH, offset, member, expect_val, PERI_CRG)
#define CHECK_MEMBER_CRGPERIPH_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(CRGPERIPH, offset, member, expect_val, result, PERI_CRG)
#define GET_MEMBER_CACHE_PCTRL(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(PCTRL, reg_val, offset, member, result)
#define GET_MEMBER_PCTRL(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(PCTRL, reg_val, offset, PCTRL)
#define SAVE_MEMBER_PCTRL(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(PCTRL, reg_val, offset, PCTRL)
#define SET_MEMBER_CACHE_PCTRL(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(PCTRL, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_PCTRL(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(PCTRL, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_PCTRL(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(PCTRL, reg_val, offset, PCTRL)
#define WAIT_MEMBER_PCTRL_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(PCTRL, offset, member, expect_val, PCTRL)
#define CHECK_MEMBER_PCTRL_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(PCTRL, offset, member, expect_val, result, PCTRL)
#define GET_MEMBER_CACHE_SCTRL(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(SCTRL, reg_val, offset, member, result)
#define GET_MEMBER_SCTRL(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(SCTRL, reg_val, offset, SCTRL)
#define SAVE_MEMBER_SCTRL(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(SCTRL, reg_val, offset, SCTRL)
#define SET_MEMBER_CACHE_SCTRL(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(SCTRL, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_SCTRL(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(SCTRL, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_SCTRL(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(SCTRL, reg_val, offset, SCTRL)
#define WAIT_MEMBER_SCTRL_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(SCTRL, offset, member, expect_val, SCTRL)
#define CHECK_MEMBER_SCTRL_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(SCTRL, offset, member, expect_val, result, SCTRL)
#define SET_MEMBER_CACHE_AOCRG(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(AO_CRG, reg_val, offset, member, cfg_val)
#define SET_MEMBER_FLUSH_AOCRG(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(AO_CRG, reg_val, offset, AO_CRG)
#define GET_MEMBER_CACHE_AOCRG(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(AO_CRG, reg_val, offset, member, result)
#define GET_MEMBER_AOCRG(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(AO_CRG, reg_val, offset, AO_CRG)
#define SET_MEMBER_CACHE_BITMASKEN_AOCRG(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(AO_CRG, reg_val, offset, member, bitmask, cfg_val)
#define GET_MEMBER_CACHE_ACTRL(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(ACTRL, reg_val, offset, member, result)
#define GET_MEMBER_ACTRL(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(ACTRL, reg_val, offset, ACTRL)
#define SAVE_MEMBER_ACTRL(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(ACTRL, reg_val, offset, ACTRL)
#define SET_MEMBER_CACHE_ACTRL(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(ACTRL, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_ACTRL(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(ACTRL, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_ACTRL(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(ACTRL, reg_val, offset, ACTRL)
#define WAIT_MEMBER_ACTRL_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(ACTRL, offset, member, expect_val, ACTRL)
#define CHECK_MEMBER_ACTRL_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(ACTRL, offset, member, expect_val, result, ACTRL)
#define GET_MEMBER_CACHE_PMCTRL(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(PMCTRL, reg_val, offset, member, result)
#define GET_MEMBER_PMCTRL(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(PMCTRL, reg_val, offset, PMCTRL)
#define SAVE_MEMBER_PMCTRL(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(PMCTRL, reg_val, offset, PMCTRL)
#define SET_MEMBER_CACHE_PMCTRL(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(PMCTRL, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_PMCTRL(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(PMCTRL, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_PMCTRL(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(PMCTRL, reg_val, offset, PMCTRL)
#define WAIT_MEMBER_PMCTRL_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(PMCTRL, offset, member, expect_val, PMCTRL)
#define CHECK_MEMBER_PMCTRL_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(PMCTRL, offset, member, expect_val, result, PMCTRL)
#define GET_MEMBER_CACHE_TZPC(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(TZPC, reg_val, offset, member, result)
#define GET_MEMBER_TZPC(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(TZPC, reg_val, offset, TZPC)
#define SAVE_MEMBER_TZPC(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(TZPC, reg_val, offset, TZPC)
#define SET_MEMBER_CACHE_TZPC(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(TZPC, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_TZPC(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(TZPC, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_TZPC(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(TZPC, reg_val, offset, TZPC)
#define WAIT_MEMBER_TZPC_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(PMCTRL, offset, member, expect_val, TZPC)
#define CHECK_MEMBER_TZPC_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(TZPC, offset, member, expect_val, result, TZPC)
#define GET_MEMBER_CACHE_LPM3_CFG(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(LPM3_CFG, reg_val, offset, member, result)
#define GET_MEMBER_LPM3_CFG(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(LPM3_CFG, reg_val, offset, LP_CONFIG)
#define SAVE_MEMBER_LPM3_CFG(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(LPM3_CFG, reg_val, offset, LP_CONFIG)
#define SET_MEMBER_CACHE_LPM3_CFG(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(LPM3_CFG, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_LPM3_CFG(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(LPM3_CFG, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_LPM3_CFG(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(LPM3_CFG, reg_val, offset, LP_CONFIG)
#define WAIT_MEMBER_LPM3_CFG_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(LPM3_CFG, offset, member, expect_val, LP_CONFIG)
#define CHECK_MEMBER_LPM3_CFG_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(LPM3_CFG, offset, member, expect_val, result, LP_CONFIG)
#define GET_MEMBER_CACHE_LPMCU(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(LPMCU, reg_val, offset, member, result)
#define GET_MEMBER_LPMCU(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(LPMCU, reg_val, offset, LP_CONFIG)
#define SAVE_MEMBER_LPMCU(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(LPMCU, reg_val, offset, LP_CONFIG)
#define SET_MEMBER_CACHE_LPMCU(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(LPMCU, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_LPMCU(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(LPMCU, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_LPMCU(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(LPMCU, reg_val, offset, LP_CONFIG)
#define WAIT_MEMBER_LPMCU_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(LPMCU, offset, member, expect_val, LP_CONFIG)
#define CHECK_MEMBER_LPMCU_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(LPMCU, offset, member, expect_val, result, LP_CONFIG)
#define GET_MEMBER_CACHE_ATG(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(ATG, reg_val, offset, member, result)
#define GET_MEMBER_ATG(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(ATG, reg_val, offset, ATG)
#define SAVE_MEMBER_ATG(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(ATG, reg_val, offset, ATG)
#define SET_MEMBER_CACHE_ATG(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(ATG, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_ATG(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(ATG, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_ATG(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(ATG, reg_val, offset, ATG)
#define WAIT_MEMBER_ATG_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(ATG, offset, member, expect_val, ATG)
#define CHECK_MEMBER_ATG_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(ATG, offset, member, expect_val, result, ATG)
#define GET_MEMBER_CACHE_MEDIA2_CTRL(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(Media2_CTRL, reg_val, offset, member, result)
#define GET_MEMBER_MEDIA2_CTRL(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(Media2_CTRL, reg_val, offset, MEDIA2_CTRL)
#define SAVE_MEMBER_MEDIA2_CTRL(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(Media2_CTRL, reg_val, offset, MEDIA2_CTRL)
#define SET_MEMBER_CACHE_MEDIA2_CTRL(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(Media2_CTRL, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_MEDIA2_CTRL(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(Media2_CTRL, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_MEDIA2_CTRL(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(Media2_CTRL, reg_val, offset, MEDIA2_CTRL)
#define WAIT_MEMBER_MEDIA2_CTRL_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(Media2_CTRL, offset, member, expect_val, MEDIA2_CTRL)
#define CHECK_MEMBER_MEDIA2_CTRL_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(Media2_CTRL, offset, member, expect_val, result, MEDIA2_CTRL)
#define GET_MEMBER_CACHE_NPU_CTRL(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(CTRL, reg_val, offset, member, result)
#define GET_MEMBER_NPU_CTRL(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(CTRL, reg_val, offset, NPU_CTRL)
#define SAVE_MEMBER_NPU_CTRL(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(CTRL, reg_val, offset, NPU_CTRL)
#define SET_MEMBER_CACHE_NPU_CTRL(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(CTRL, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_NPU_CTRL(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(CTRL, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_NPU_CTRL(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(CTRL, reg_val, offset, NPU_CTRL)
#define WAIT_MEMBER_NPU_CTRL_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(CTRL, offset, member, expect_val, NPU_CTRL)
#define CHECK_MEMBER_NPU_CTRL_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(CTRL, offset, member, expect_val, result, NPU_CTRL)
#define GET_MEMBER_CACHE_SPMIMST(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(SPMIMST, reg_val, offset, member, result)
#define GET_MEMBER_SPMIMST(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(SPMIMST, reg_val, offset, SPMIMST)
#define SET_MEMBER_CACHE_SPMIMST(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(SPMIMST, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_SPMIMST(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(SPMIMST, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_SPMIMST(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(SPMIMST, reg_val, offset, SPMIMST)
#define WAIT_MEMBER_SPMIMST_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(SPMIMST, offset, member, expect_val, SPMIMST)
#define CHECK_MEMBER_SPMIMST_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(SPMIMST, offset, member, expect_val, result, SPMIMST)
#define GET_MEMBER_CACHE_LATSTAT(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(LATSTAT, reg_val, offset, member, result)
#define GET_MEMBER_LATSTAT(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(LATSTAT, reg_val, offset, LATSTAT)
#define SAVE_MEMBER_LATSTAT(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(LATSTAT, reg_val, offset, LATSTAT)
#define SET_MEMBER_CACHE_LATSTAT(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(LATSTAT, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_LATSTAT(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(LATSTAT, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_LATSTAT(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(LATSTAT, reg_val, offset, LATSTAT)
#define WAIT_MEMBER_LATSTAT_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(LATSTAT, offset, member, expect_val, LATSTAT)
#define CHECK_MEMBER_LATSTAT_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(LATSTAT, offset, member, expect_val, result, LATSTAT)
#define GET_MEMBER_CACHE_PAD_PERI(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(PAD_PERI, reg_val, offset, member, result)
#define GET_MEMBER_PAD_PERI(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(PAD_PERI, reg_val, offset, PAD_PERI_IOMG_IOCG)
#define SAVE_MEMBER_PAD_PERI(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(PAD_PERI, reg_val, offset, PAD_PERI_IOMG_IOCG)
#define SET_MEMBER_CACHE_PAD_PERI(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(PAD_PERI, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_PAD_PERI(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(PAD_PERI, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_PAD_PERI(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(PAD_PERI, reg_val, offset, PAD_PERI_IOMG_IOCG)
#define WAIT_MEMBER_PAD_PERI_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(PAD_PERI, offset, member, expect_val, PAD_PERI_IOMG_IOCG)
#define CHECK_MEMBER_PAD_PERI_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(PAD_PERI, offset, member, expect_val, result, PAD_PERI_IOMG_IOCG)
#define GET_MEMBER_CACHE_IOC_PERI(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(IOC_PERI, reg_val, offset, member, result)
#define GET_MEMBER_IOC_PERI(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(IOC_PERI, reg_val, offset, PERI_IOC)
#define SAVE_MEMBER_IOC_PERI(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(IOC_PERI, reg_val, offset, PERI_IOC)
#define SET_MEMBER_CACHE_IOC_PERI(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(IOC_PERI, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_IOC_PERI(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(IOC_PERI, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_IOC_PERI(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(IOC_PERI, reg_val, offset, PERI_IOC)
#define WAIT_MEMBER_IOC_PERI_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(IOC_PERI, offset, member, expect_val, PERI_IOC)
#define CHECK_MEMBER_IOC_PERI_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(IOC_PERI, offset, member, expect_val, result, PERI_IOC)
#define GET_MEMBER_CACHE_IOC_AO(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(IOC_AO, reg_val, offset, member, result)
#define GET_MEMBER_IOC_AO(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(IOC_AO, reg_val, offset, IOC_AO)
#define SAVE_MEMBER_IOC_AO(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(IOC_AO, reg_val, offset, IOC_AO)
#define SET_MEMBER_CACHE_IOC_AO(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(IOC_AO, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_IOC_AO(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(IOC_AO, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_IOC_AO(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(IOC_AO, reg_val, offset, IOC_AO)
#define WAIT_MEMBER_IOC_AO_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(IOC_AO, offset, member, expect_val, IOC_AO)
#define CHECK_MEMBER_IOC_AO_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(IOC_AO, offset, member, expect_val, result, IOC_AO)
#define GET_MEMBER_CACHE_PAD_AO(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(PAD_AO, reg_val, offset, member, result)
#define GET_MEMBER_PAD_AO(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(PAD_AO, reg_val, offset, PAD_AO)
#define SAVE_MEMBER_PAD_AO(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(PAD_AO, reg_val, offset, PAD_AO)
#define SET_MEMBER_CACHE_PAD_AO(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(PAD_AO, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_PAD_AO(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(PAD_AO, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_PAD_AO(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(PAD_AO, reg_val, offset, PAD_AO)
#define WAIT_MEMBER_PAD_AO_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(PAD_AO, offset, member, expect_val, PAD_AO)
#define CHECK_MEMBER_PAD_AO_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(PAD_AO, offset, member, expect_val, result, PAD_AO)
#define GET_MEMBER_IOC_HSDT1(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(IOC_HSDT1, reg_val, offset, IOC_HSDT1)
#define SET_MEMBER_CACHE_IOC_HSDT1(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(IOC_HSDT1, reg_val, offset, member, cfg_val)
#define SET_MEMBER_FLUSH_IOC_HSDT1(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(IOC_HSDT1, reg_val, offset, IOC_HSDT1)
#define GET_MEMBER_CACHE_IPCNS(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(IPCNS, reg_val, offset, member, result)
#define GET_MEMBER_IPCNS(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(IPCNS, reg_val, offset, IPCNS)
#define GET_MEMBER_IPCNS_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_COMMON_X(IPCNS, reg_val, offset, IPCNS, x)
#define SAVE_MEMBER_IPCNS(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(IPCNS, reg_val, offset, IPCNS)
#define SET_MEMBER_CACHE_IPCNS(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(IPCNS, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_IPCNS(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(IPCNS, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_IPCNS(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(IPCNS, reg_val, offset, IPCNS)
#define SET_MEMBER_FLUSH_IPCNS_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_COMMON_X(IPCNS, reg_val, offset, IPCNS, x)
#define WAIT_MEMBER_IPCNS_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(IPCNS, offset, member, expect_val, IPCNS)
#define CHECK_MEMBER_IPCNS_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(IPCNS, offset, member, expect_val, result, IPCNS)
#define GET_MEMBER_CACHE_IPC(reg_val,offset,member,result) \
    GET_MEMBER_CACHE(IPC, reg_val, offset, member, result)
#define GET_MEMBER_IPC(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(IPC, reg_val, offset, IPC)
#define GET_MEMBER_IPC_X(reg_val,offset,x) \
    GET_MEMBER_FLUSH_COMMON_X(IPC, reg_val, offset, IPC, x)
#define SAVE_MEMBER_IPC(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(IPC, reg_val, offset, IPC)
#define SET_MEMBER_CACHE_IPC(reg_val,offset,member,cfg_val) \
    SET_MEMBER_CACHE(IPC, reg_val, offset, member, cfg_val)
#define SET_MEMBER_CACHE_BITMASKEN_IPC(reg_val,offset,member,bitmask,cfg_val) \
    SET_MEMBER_CACHE_BITMASKEN(IPC, reg_val, offset, member, bitmask, cfg_val)
#define SET_MEMBER_FLUSH_IPC(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(IPC, reg_val, offset, IPC)
#define SET_MEMBER_FLUSH_IPC_X(reg_val,offset,x) \
    SET_MEMBER_FLUSH_COMMON_X(IPC, reg_val, offset, IPC, x)
#define WAIT_MEMBER_IPC_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(IPC, offset, member, expect_val, IPC)
#define CHECK_MEMBER_IPC_STAT(offset,member,expect_val,result) \
    CHECK_MEMBER_COMMON_STAT(IPC, offset, member, expect_val, result, IPC)
#define WAIT_MEMBER_BISR_CTRL_STAT(offset,member,expect_val) \
    WAIT_MEMBER_COMMON_STAT(BISR_CTRL, offset, member, expect_val, BISR_CTRL)
#define GET_MEMBER_CHI2QSP(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(QICE_CHI2QSP, reg_val, offset, CHI2QSP)
#define SAVE_MEMBER_CHI2QSP(reg_val,offset) \
    GET_MEMBER_FLUSH_COMMON(QICE_CHI2QSP, reg_val, offset, CHI2QSP)
#define SET_MEMBER_FLUSH_CHI2QSP(reg_val,offset) \
    SET_MEMBER_FLUSH_COMMON(QICE_CHI2QSP, reg_val, offset, CHI2QSP)
#endif
