#ifndef __CPU_REGISTER_H__
#define __CPU_REGISTER_H__ 
#include <soc_lpmcu_baseaddr_interface.h>
#include <soc_acpu_baseaddr_interface.h>
#include <soc_sctrl_interface.h>
#include <cpu_pwplat.h>
#ifdef CPU_PW_PLAT_M
#define SCTRL_BASE_ADDR SOC_LPMCU_SCTRL_BASE_ADDR
#else
#define SCTRL_BASE_ADDR SOC_ACPU_SCTRL_BASE_ADDR
#endif
#if !(defined(__LINKER__) || defined(__ASSEMBLER__) || defined( __SOC_H_FOR_ASM__))
typedef union {
 unsigned int value;
 struct {
  unsigned int lit_mask : 4;
  unsigned int mid_mask : 8;
  unsigned int big_mask : 2;
  unsigned int reserved_mask: 6;
  unsigned int dts_type : 4;
  unsigned int reserved : 8;
 } reg;
 struct {
  unsigned int cpu_mask : 14;
  unsigned int reserved_0 : 6;
  unsigned int dts_type : 4;
  unsigned int reserved_1 : 8;
 } reg2;
} SELF_SCTRL_SCBAKDATA2_UNION;
#define SCTRL_SCBAKDATA2 (*(volatile SELF_SCTRL_SCBAKDATA2_UNION*)(SOC_SCTRL_SCBAKDATA2_ADDR(SCTRL_BASE_ADDR)))
typedef union {
 unsigned int value;
 struct {
  unsigned int main_core : 8;
  unsigned int main_cluster : 8;
  unsigned int reserved_0 : 8;
  unsigned int first_boot : 1;
  unsigned int reserved_1 : 6;
  unsigned int lpnv_enable : 1;
 } reg;
} SELF_SCTRL_SCBAKDATA3_UNION;
#define SCTRL_SCBAKDATA3 (*(volatile SELF_SCTRL_SCBAKDATA3_UNION*)(SOC_SCTRL_SCBAKDATA3_ADDR(SCTRL_BASE_ADDR)))
typedef union {
    unsigned int value;
    struct {
        unsigned int boot_cpu : 4;
        unsigned int reserved_0 : 4;
        unsigned int acpu_boot : 1;
        unsigned int reserved_1 : 7;
        unsigned int syssr_flag : 1;
        unsigned int reserved_2 : 15;
    } reg;
} SELF_SCTRL_SCBAKDATA8_UNION;
#define SCTRL_SCBAKDATA8 (*(volatile SELF_SCTRL_SCBAKDATA8_UNION*)(SOC_SCTRL_SCBAKDATA8_ADDR(SCTRL_BASE_ADDR)))
static const unsigned int g_core_pmau_intr[] = {
 CORE_PMAU_INTR(LITTLE, 0),
 CORE_PMAU_INTR(LITTLE, 1),
 CORE_PMAU_INTR(LITTLE, 2),
 CORE_PMAU_INTR(LITTLE, 3),
 CORE_PMAU_INTR(MIDDLE, 0),
 CORE_PMAU_INTR(MIDDLE, 1),
 CORE_PMAU_INTR(MIDDLE, 2),
 CORE_PMAU_INTR(MIDDLE, 3),
 CORE_PMAU_INTR(BIG, 0),
};
static const unsigned int g_core_pmau_req2pn[] = {
 CORE_PMAU_REQ2PN(LITTLE, 0),
 CORE_PMAU_REQ2PN(LITTLE, 1),
 CORE_PMAU_REQ2PN(LITTLE, 2),
 CORE_PMAU_REQ2PN(LITTLE, 3),
 CORE_PMAU_REQ2PN(MIDDLE, 0),
 CORE_PMAU_REQ2PN(MIDDLE, 1),
 CORE_PMAU_REQ2PN(MIDDLE, 2),
 CORE_PMAU_REQ2PN(MIDDLE, 3),
 CORE_PMAU_REQ2PN(BIG, 0),
};
static const unsigned int g_cluster_pmtu_standby_ctrl[] = {
 CLUSTER_PMTU_STANDBY_CTRL(LITTLE),
 CLUSTER_PMTU_STANDBY_CTRL(MIDDLE),
 CLUSTER_PMTU_STANDBY_CTRL(BIG),
};
#define LOCK_UNLOCK_OFFSET 0x4
#define LOCK_STAT_OFFSET 0x8
typedef enum {
 CPU_IDLE_LOCK = 0,
 CPU_CLUSTER_IDLE_LOCK,
 CPU_UP_LOCK,
 CPU_DOWN_LOCK,
} lpcpu_lock_type;
typedef struct {
 unsigned int addr;
 unsigned int lock_offset;
} lpcpu_lock;
static const lpcpu_lock g_cpu_lock[] = {
 { .addr = RES_LOCK_BASE(0), .lock_offset = 28 },
 { .addr = RES_LOCK_BASE(1), .lock_offset = 28 },
 { .addr = RES_LOCK_BASE(2), .lock_offset = 28 },
 { .addr = RES_LOCK_BASE(4), .lock_offset = 28 },
 { .addr = RES_LOCK_BASE(7), .lock_offset = 8 },
 { .addr = RES_LOCK_BASE(7), .lock_offset = 12 },
 { .addr = RES_LOCK_BASE(7), .lock_offset = 16 },
 { .addr = RES_LOCK_BASE(7), .lock_offset = 20 },
 { .addr = RES_LOCK_BASE(7), .lock_offset = 24 },
 { .addr = RES_LOCK_BASE(7), .lock_offset = 28 },
};
#define PCHANNEL_HANDSHAKE_DONE SOC_FCM_LOCAL_PERI_STAT7_core7_p_channel_handshake_done_START
static const unsigned int g_pchannel_handshake[] = {
 FCM_LOCAL_PERI_STAT(0),
 FCM_LOCAL_PERI_STAT(1),
 FCM_LOCAL_PERI_STAT(2),
 FCM_LOCAL_PERI_STAT(3),
 FCM_LOCAL_PERI_STAT(4),
 FCM_LOCAL_PERI_STAT(5),
 FCM_LOCAL_PERI_STAT(6),
 FCM_LOCAL_PERI_STAT(7),
 FCM_LOCAL_PERI_STAT(8),
};
#define SMT_CORE_INIT_CFG_MASK 0x7FU
#define SMT_CORE_INIT_CFG_COMMON BIT(3)
#define SMT_CORE_INIT_CFG_MT_MODE BIT(6)
#define SMT_CORE_INIT_CFG_SHIFT 4
static const unsigned int g_core_pchannel[] = {
 CORE_PCHANNEL(0),
 CORE_PCHANNEL(1),
 CORE_PCHANNEL(2),
 CORE_PCHANNEL(3),
 CORE_PCHANNEL(4),
 CORE_PCHANNEL(5),
 CORE_PCHANNEL(6),
 CORE_PCHANNEL(7),
 CORE_PCHANNEL(8),
};
static const unsigned int g_smt_config[] = {
 FCM_LOCAL_PERI_CTRL(38),
 FCM_LOCAL_PERI_CTRL(39),
};
static const unsigned int g_fcm_core_pchannel_debug_stat[] = {
 FCM_CORE_PCHANNEL_DEBUG_STAT(01),
 FCM_CORE_PCHANNEL_DEBUG_STAT(23),
 FCM_CORE_PCHANNEL_DEBUG_STAT(45),
 FCM_CORE_PCHANNEL_DEBUG_STAT(67),
 FCM_CORE_PCHANNEL_DEBUG_STAT(8),
};
#define PMAU_PWRMOD_MASK 0xFU
#define PMAU_PWRMOD_ON 0x1U
#define PMAU_PWRMOD_ENHANCE_IDLE 0x2U
#define PMAU_PWRMOD_MEM_RET 0x4U
#define PMAU_PWRMOD_OFF 0x8U
static const unsigned int g_pmau_pwrmod[] = {
 CORE_PMAU_PWRMOD_CFG(LITTLE, 0),
 CORE_PMAU_PWRMOD_CFG(LITTLE, 1),
 CORE_PMAU_PWRMOD_CFG(LITTLE, 2),
 CORE_PMAU_PWRMOD_CFG(LITTLE, 3),
 CORE_PMAU_PWRMOD_CFG(MIDDLE, 0),
 CORE_PMAU_PWRMOD_CFG(MIDDLE, 1),
 CORE_PMAU_PWRMOD_CFG(MIDDLE, 2),
 CORE_PMAU_PWRMOD_CFG(MIDDLE, 3),
 CORE_PMAU_PWRMOD_CFG(BIG, 0),
};
static const unsigned int g_cluster_pmau_pwrmod[] = {
 CLUSTER_PMAU_PWRMOD_CFG(LITTLE),
 CLUSTER_PMAU_PWRMOD_CFG(MIDDLE),
 CLUSTER_PMAU_PWRMOD_CFG(BIG),
};
#define CORE_PDC_FSM_STAT_MASK 0xFFU
#define CORE_PDC_OFF 0x04
#define CORE_PDC_MTCMOS_ON 0x40
#define CORE_PDC_ISO_DIS 0x20
#define CORE_PDC_RST_DIS 0x30
#define CORE_PDC_CLK_ON 0x10
#define CORE_PDC_ON 0x01
#define CORE_PDC_LP_HS_OFF 0x80
#define CORE_PDC_CLK_OFF 0x90
#define CORE_PDC_ISO_EN 0xA0
#define CORE_PDC_RST_EN 0xB0
#define CORE_PDC_MTCMOS_OFF 0xC0
static const unsigned int g_pdc_bypass_stat[] = {
 PDC_BYPASS_AND_STAT(LITTLE, 0),
 PDC_BYPASS_AND_STAT(LITTLE, 1),
 PDC_BYPASS_AND_STAT(LITTLE, 2),
 PDC_BYPASS_AND_STAT(LITTLE, 3),
 PDC_BYPASS_AND_STAT(MIDDLE, 0),
 PDC_BYPASS_AND_STAT(MIDDLE, 1),
 PDC_BYPASS_AND_STAT(MIDDLE, 2),
 PDC_BYPASS_AND_STAT(MIDDLE, 3),
 PDC_BYPASS_AND_STAT(BIG, 0),
};
static const unsigned int g_pdc_cfg_and_stat[] = {
 PDC_CFG_AND_STAT(LITTLE, 0),
 PDC_CFG_AND_STAT(LITTLE, 1),
 PDC_CFG_AND_STAT(LITTLE, 2),
 PDC_CFG_AND_STAT(LITTLE, 3),
 PDC_CFG_AND_STAT(MIDDLE, 0),
 PDC_CFG_AND_STAT(MIDDLE, 1),
 PDC_CFG_AND_STAT(MIDDLE, 2),
 PDC_CFG_AND_STAT(MIDDLE, 3),
 PDC_CFG_AND_STAT(BIG, 0),
};
static const unsigned int g_cluster_pmau_intr[] = {
 CLUSTER_PMAU_INTR(LITTLE),
 CLUSTER_PMAU_INTR(MIDDLE),
 CLUSTER_PMAU_INTR(BIG),
};
#define CLUSTER_DOWN_MODE_MASK 0x3
#define CLUSTER_DOWN_FLAG_OFFSET 26
typedef enum {
 CLUSTER_PWDN_IDLE = 0,
 CLUSTER_PWDN_HOTPLUG = 1,
 LPMCU_PM_SR = 2,
} cluster_down_mode;
#define ACPU_BOOT_VALID 0x41435055
#define ACPU_BOOT_INVALID 0x424F4F54
#define ACPU_BOOT_RUNNING 0x41434F54
#endif
#endif
