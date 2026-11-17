#ifndef __CPU_IPC_H__
#define __CPU_IPC_H__ 
#include <soc_lpmcu_baseaddr_interface.h>
#include <soc_acpu_baseaddr_interface.h>
#include <soc_ipc_interface.h>
#define CPU_IPC_DATA_MAX 8
typedef enum {
 IPC_CMD_RESERVED = 0,
 IPC_CMD_FTY_SET_FREQ_VOLT,
 IPC_CMD_FTY_SET_FREQ,
 IPC_CMD_FTY_GET_FREQ,
 IPC_CMD_FTY_SET_VDDP,
 IPC_CMD_FTY_SET_VDDC,
 IPC_CMD_FTY_GET_VDDP,
 IPC_CMD_FTY_GET_VDDC,
 IPC_CMD_FTY_CLK_ONOFF,
 IPC_CMD_DBG_SET_VOLT,
 IPC_CMD_DBG_SET_FREQ,
 IPC_CMD_LOW_POWER_BOOT_LIMIT_FREQ,
 IPC_CMD_DBG_KERNEL_TEST,
 IPC_CMD_LOG_EXPORT,
 IPC_CMD_SET_STAGE,
 IPC_CMD_SVFD_TRIM,
 IPC_CMD_NV_FREQ_RANGE,
 IPC_CMD_NV_MEM_VOLT_BIAS,
 IPC_CMD_PMU_INIT,
 IPC_CMD_DDR_LINK_INIT,
 IPC_CMD_PA_MARGIN_INIT,
 IPC_CMD_XPU_RTM_TRACE,
 IPC_CMD_XPU_RTM_LATENCY,
 IPC_CMD_XPU_RTM_SET_QOS,
 IPC_CMD_VOLT_BOOST,
 IPC_CMD_BHS_TRIM,
 IPC_CMD_DFV_STATUS_INIT,
 IPC_CMD_PERCHIP_DFV_PARA_INIT,
 IPC_CMD_PIM_INIT,
 IPC_CMD_VDDC_CLASS_INIT,
 IPC_CMD_CPU_IDDQ_INIT,
 IPC_CMD_SUSPEND = 0x0100,
 IPC_CMD_CORE_PWRUP,
 IPC_CMD_CORE_PWR_DN,
 IPC_CMD_CORE_PWRUP_SOFT_FLOW,
 IPC_CMD_CORE_PWR_DN_SOFT_FLOW,
 IPC_CMD_RESUME,
 IPC_CMD_FCM_POWER_UP,
 IPC_CMD_32K_IDLE_DISABLED,
 IPC_CMD_DDR_FAST_WAKEUP,
 IPC_CMD_32K_IDLE = 0x0400,
 IPC_CMD_TSEL_INIT,
} IPC_CMD_TYPE;
union cxpu_dvfs_ipc {
 unsigned int data[CPU_IPC_DATA_MAX];
 struct {
  unsigned int cmd : 32;
  unsigned int cluster_id : 8;
  unsigned int reserved : 8;
  unsigned int volt_mv : 16;
  int result;
 } fty_volt;
 struct {
  unsigned int cmd : 32;
  unsigned int cluster_id : 8;
  unsigned int reserved : 24;
  unsigned int freq_khz : 32;
  int result;
 } fty_freq;
 struct {
  unsigned int cmd : 32;
  unsigned int cluster_id : 8;
  unsigned int volt_type : 8;
  unsigned int memvolt_mv : 16;
  unsigned int freq_mhz : 32;
  int result;
 } fty_freq_volt;
 struct {
  unsigned int cmd : 32;
  unsigned int cluster_id : 8;
  unsigned int profile_id : 8;
  unsigned int onoff : 8;
  unsigned int reserved : 8;
  int result;
 } fty_clk;
 struct {
  unsigned int cmd : 32;
  unsigned int cluster_id : 8;
  unsigned int profile_id : 8;
  unsigned int freq_mhz : 16;
 } dbg_freq;
 struct {
  unsigned int cmd : 32;
  unsigned int cluster_id : 8;
  unsigned int profile_id : 8;
  unsigned int volt_mv : 14;
  unsigned int bias_type : 2;
 } dbg_volt_bias;
 struct {
  unsigned int cmd : 32;
  unsigned int cluster_id : 8;
  unsigned int profile_id : 8;
  unsigned int volt_mv : 16;
 } dbg_volt;
};
union cxpu_dfv_ipc {
 unsigned int data[CPU_IPC_DATA_MAX];
 struct {
  unsigned int cmd : 32;
  unsigned int cluster_id : 8;
  unsigned int cmd_val : 8;
 } dbg_dfv_dc;
};
union cxpu_rtm_ipc {
 unsigned int data[CPU_IPC_DATA_MAX];
 struct {
  unsigned int cmd : 32;
  unsigned int para1 : 16;
  unsigned int para2 : 16;
 } cxpu_cmd;
};
#ifndef IPC_UNLOCK_VAL
#define IPC_UNLOCK_VAL 0x1ACCE551
#endif
#ifndef IPC_BASE
#ifdef CPU_PW_PLAT_M
#define IPC_BASE (SOC_LPMCU_IPC_BASE_ADDR)
#else
#define IPC_BASE (SOC_ACPU_IPC_BASE_ADDR)
#endif
#endif
#define IPC_CMD_CORE_INFO(cluster,cpumask) (((cluster) << 16) | (cpumask))
#define IPC_CMD_PARA(cluster,cpu) (((cluster) << 8) | (cpu))
#define IPC_STATE_IDLE 0x10
#define REG_IPC_ACK_BIT_SHIFT (1<<7)
#define IPC_IP_ACPU (1<<0)
#define IPC_IP_M3 (1<<2)
#define IPC_IP_CXPU (1<<11)
#define CXPU_MBX_ID 54
#define IPC_CPU_LPCTRL_MID 47
#endif
