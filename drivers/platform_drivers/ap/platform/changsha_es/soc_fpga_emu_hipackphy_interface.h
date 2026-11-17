#ifndef __SOC_FPGA_EMU_HIPACK_INTERFACE_H__
#define __SOC_FPGA_EMU_HIPACK_INTERFACE_H__ 
#ifdef __cplusplus
 #if __cplusplus
 extern "C" {
 #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HIPACK_PHY_MODEL_WCK_TIMING_ADDR(base) ((base) + (0x1000UL))
#define SOC_HIPACK_PHY_MODEL_READ_TIMING_ADDR(base) ((base) + (0x1004UL))
#define SOC_HIPACK_PHY_MODEL_CMD_TIMING_ADDR(base) ((base) + (0x1008UL))
#define SOC_HIPACK_PHY_MODEL_WRITE_TIMING_ADDR(base) ((base) + (0x100CUL))
#define SOC_HIPACK_PHY_MODEL_MISC_CTRL_ADDR(base) ((base) + (0x1100UL))
#define SOC_HIPACK_PHY_MODEL_WDATA_CTRL_ADDR(base) ((base) + (0x1104UL))
#else
#define SOC_HIPACK_PHY_MODEL_WCK_TIMING_ADDR(base) ((base) + (0x1000))
#define SOC_HIPACK_PHY_MODEL_READ_TIMING_ADDR(base) ((base) + (0x1004))
#define SOC_HIPACK_PHY_MODEL_CMD_TIMING_ADDR(base) ((base) + (0x1008))
#define SOC_HIPACK_PHY_MODEL_WRITE_TIMING_ADDR(base) ((base) + (0x100C))
#define SOC_HIPACK_PHY_MODEL_MISC_CTRL_ADDR(base) ((base) + (0x1100))
#define SOC_HIPACK_PHY_MODEL_WDATA_CTRL_ADDR(base) ((base) + (0x1104))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HIPACK_CTL_GDQS_DLY_ADDR(base) ((base) + (0x500UL))
#define SOC_HIPACK_PS_CTRL_ADDR(base) ((base) + (0x600UL))
#define SOC_HIPACK_PS_STATUS_ADDR(base) ((base) + (0x610UL))
#define SOC_HIPACK_PS_CLR_ADDR(base) ((base) + (0x700UL))
#else
#define SOC_HIPACK_CTL_GDQS_DLY_ADDR(base) ((base) + (0x500))
#define SOC_HIPACK_PS_CTRL_ADDR(base) ((base) + (0x600))
#define SOC_HIPACK_PS_STATUS_ADDR(base) ((base) + (0x610))
#define SOC_HIPACK_PS_CLR_ADDR(base) ((base) + (0x700))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
 unsigned int value;
 struct
 {
 unsigned int twck_cs : 8;
 unsigned int twck_en : 8;
 unsigned int twck_tog : 8;
 unsigned int reserved : 8;
 } reg;
} SOC_HIPACK_PHY_MODEL_WCK_TIMING_UNION;
#endif
#define SOC_HIPACK_PHY_MODEL_WCK_TIMING_twck_cs_START (0)
#define SOC_HIPACK_PHY_MODEL_WCK_TIMING_twck_cs_END (7)
#define SOC_HIPACK_PHY_MODEL_WCK_TIMING_twck_en_START (8)
#define SOC_HIPACK_PHY_MODEL_WCK_TIMING_twck_en_END (15)
#define SOC_HIPACK_PHY_MODEL_WCK_TIMING_twck_tog_START (16)
#define SOC_HIPACK_PHY_MODEL_WCK_TIMING_twck_tog_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
 unsigned int value;
 struct
 {
 unsigned int tphy_gate_sel : 1;
 unsigned int trdvalid : 8;
 unsigned int reserved : 23;
 } reg;
} SOC_HIPACK_PHY_MODEL_READ_TIMING_UNION;
#endif
#define SOC_HIPACK_PHY_MODEL_READ_TIMING_tphy_gate_sel_START (0)
#define SOC_HIPACK_PHY_MODEL_READ_TIMING_tphy_gate_sel_END (0)
#define SOC_HIPACK_PHY_MODEL_READ_TIMING_trdvalid_START (1)
#define SOC_HIPACK_PHY_MODEL_READ_TIMING_trdvalid_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
 unsigned int value;
 struct
 {
 unsigned int taddr : 8;
 unsigned int tcs : 8;
 unsigned int tck_dis : 8;
 unsigned int taddr_tick : 8;
 } reg;
} SOC_HIPACK_PHY_MODEL_CMD_TIMING_UNION;
#endif
#define SOC_HIPACK_PHY_MODEL_CMD_TIMING_taddr_START (0)
#define SOC_HIPACK_PHY_MODEL_CMD_TIMING_taddr_END (7)
#define SOC_HIPACK_PHY_MODEL_CMD_TIMING_tcs_START (8)
#define SOC_HIPACK_PHY_MODEL_CMD_TIMING_tcs_END (15)
#define SOC_HIPACK_PHY_MODEL_CMD_TIMING_tck_dis_START (16)
#define SOC_HIPACK_PHY_MODEL_CMD_TIMING_tck_dis_END (23)
#define SOC_HIPACK_PHY_MODEL_CMD_TIMING_taddr_tick_START (24)
#define SOC_HIPACK_PHY_MODEL_CMD_TIMING_taddr_tick_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
 unsigned int value;
 struct
 {
 unsigned int twrdata : 8;
 unsigned int twrdmi : 8;
 unsigned int twren : 8;
 unsigned int reserved : 8;
 } reg;
} SOC_HIPACK_PHY_MODEL_WRITE_TIMING_UNION;
#endif
#define SOC_HIPACK_PHY_MODEL_WRITE_TIMING_twrdata_START (0)
#define SOC_HIPACK_PHY_MODEL_WRITE_TIMING_twrdata_END (7)
#define SOC_HIPACK_PHY_MODEL_WRITE_TIMING_twrdmi_START (8)
#define SOC_HIPACK_PHY_MODEL_WRITE_TIMING_twrdmi_END (15)
#define SOC_HIPACK_PHY_MODEL_WRITE_TIMING_twren_START (16)
#define SOC_HIPACK_PHY_MODEL_WRITE_TIMING_twren_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
 unsigned int value;
 struct
 {
 unsigned int wck_alwayson : 1;
 unsigned int wck2ck_disable : 1;
 unsigned int overclock_en : 1;
 unsigned int overclock_phase : 1;
 unsigned int reserved : 28;
 } reg;
} SOC_HIPACK_PHY_MODEL_MISC_CTRL_UNION;
#endif
#define SOC_HIPACK_PHY_MODEL_MISC_CTRL_wck_alwayson_START (0)
#define SOC_HIPACK_PHY_MODEL_MISC_CTRL_wck_alwayson_END (0)
#define SOC_HIPACK_PHY_MODEL_MISC_CTRL_wck2ck_disable_START (1)
#define SOC_HIPACK_PHY_MODEL_MISC_CTRL_wck2ck_disable_END (1)
#define SOC_HIPACK_PHY_MODEL_MISC_CTRL_overclock_en_START (2)
#define SOC_HIPACK_PHY_MODEL_MISC_CTRL_overclock_en_END (2)
#define SOC_HIPACK_PHY_MODEL_MISC_CTRL_overclock_phase_START (3)
#define SOC_HIPACK_PHY_MODEL_MISC_CTRL_overclock_phase_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
 unsigned int value;
 struct
 {
 unsigned int wdata_rpl : 32;
 } reg;
} SOC_HIPACK_PHY_MODEL_WDATA_CTRL_UNION;
#endif
#define SOC_HIPACK_PHY_MODEL_WDATA_CTRL_wdata_rpl_START (0)
#define SOC_HIPACK_PHY_MODEL_WDATA_CTRL_wdata_rpl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
 unsigned int value;
 struct
 {
 unsigned int tphy_gate_sel : 2;
 unsigned int ctl_qs_en_final : 4;
 unsigned int hdr_mode : 1;
 unsigned int wl_odd_sel : 1;
 unsigned int dbg_rvalid_bypass : 2;
 unsigned int reversed : 21;
 unsigned int dbg_rvalid_latch : 1;
 } reg;
} SOC_HIPACK_CTL_GDQS_DLY_UNION;
#endif
#define SOC_HIPACK_CTL_GDQS_DLY_tphy_gate_sel_START (0)
#define SOC_HIPACK_CTL_GDQS_DLY_tphy_gate_sel_END (1)
#define SOC_HIPACK_CTL_GDQS_DLY_ctl_qs_en_final_START (2)
#define SOC_HIPACK_CTL_GDQS_DLY_ctl_qs_en_final_END (5)
#define SOC_HIPACK_CTL_GDQS_DLY_hdr_mode_START (6)
#define SOC_HIPACK_CTL_GDQS_DLY_hdr_mode_END (6)
#define SOC_HIPACK_CTL_GDQS_DLY_wl_odd_sel_START (7)
#define SOC_HIPACK_CTL_GDQS_DLY_wl_odd_sel_END (7)
#define SOC_HIPACK_CTL_GDQS_DLY_dbg_rvalid_bypass_START (8)
#define SOC_HIPACK_CTL_GDQS_DLY_dbg_rvalid_bypass_END (9)
#define SOC_HIPACK_CTL_GDQS_DLY_reversed_START (10)
#define SOC_HIPACK_CTL_GDQS_DLY_reversed_END (30)
#define SOC_HIPACK_CTL_GDQS_DLY_dbg_rvalid_latch_START (31)
#define SOC_HIPACK_CTL_GDQS_DLY_dbg_rvalid_latch_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
 unsigned int value;
 struct
 {
 unsigned int ps_start : 1;
 unsigned int reserved_0 : 3;
 unsigned int psincdec : 1;
 unsigned int reserved_1 : 11;
 unsigned int phase_shift : 13;
 unsigned int reserved_2 : 2;
 unsigned int train_type : 1;
 } reg;
} SOC_HIPACK_PS_CTRL_UNION;
#endif
#define SOC_HIPACK_PS_CTRL_ps_start_START (0)
#define SOC_HIPACK_PS_CTRL_ps_start_END (0)
#define SOC_HIPACK_PS_CTRL_psincdec_START (4)
#define SOC_HIPACK_PS_CTRL_psincdec_END (4)
#define SOC_HIPACK_PS_CTRL_phase_shift_START (16)
#define SOC_HIPACK_PS_CTRL_phase_shift_END (28)
#define SOC_HIPACK_PS_CTRL_train_type_START (31)
#define SOC_HIPACK_PS_CTRL_train_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
 unsigned int value;
 struct
 {
 unsigned int ps_status : 1;
 unsigned int reserved : 31;
 } reg;
} SOC_HIPACK_PS_STATUS_UNION;
#endif
#define SOC_HIPACK_PS_STATUS_ps_status_START (0)
#define SOC_HIPACK_PS_STATUS_ps_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
 unsigned int value;
 struct
 {
 unsigned int ps_clr : 1;
 unsigned int reserved : 31;
 } reg;
} SOC_HIPACK_PS_CLR_UNION;
#endif
#define SOC_HIPACK_PS_CLR_ps_clr_START (0)
#define SOC_HIPACK_PS_CLR_ps_clr_END (0)
#ifdef __cplusplus
 #if __cplusplus
 #endif
#endif
#endif
