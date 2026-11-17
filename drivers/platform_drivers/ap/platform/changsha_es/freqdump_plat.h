#ifndef FREQDUMP_PLAT_H
#define FREQDUMP_PLAT_H 
#include "cpu_cluster_def.h"
#include <stdbool.h>
#include <tsensor_interface.h>
#include <freqdump_plat_common.h>
#include <loadmonitor_plat.h>
#include <soc_cpu_pdc_interface.h>
#define CONFIG_FREQDUMP_NODE_DUMP 
#define CONFIG_SUPPORT_CLUSTER1 
#define CONFIG_SUPPORT_CLUSTER2 
#define MAX_NPU_MODULE_SHOW 5
#define MAX_NPU_NAME_LEN 16
#define MAX_AO_VOTE_NUM 3
#define NPU_SUPPORT_MEM_VOLT 
#define MAX_PERI_VOTE_TYPE_LEN 10
#define MAX_PERI_MEM_VOTE_TYPE_LEN 6
#define MAX_PERI_MEDIA_VOTE_TYPE_LEN 6
#define FREQDUMP_CLK4X_MASK 0x10
#define FREQDUMP_XDR_MASK 0xF
enum NPU_FREQ_VOLT {
 NPU_FREQ,
 NPU_LOGIC_VOLT,
 NPU_MEM_VOLT,
 NPU_INFO_MAX,
};
struct gpu_info {
 char pwr_status[POWER_STATE];
 char cluster_pwr_status[POWER_STATE];
 unsigned int voltage;
 unsigned int mem_voltage;
 unsigned int freq;
};
struct ddr_info {
 unsigned int ddr_freq_khz;
 float dmss_freq_khz;
 unsigned int clk_sel_ddr;
 unsigned int clk_sel_dmss;
 struct loadmonitor_ddr ddr_flux;
 unsigned int dmc_work_mode;
 unsigned int tmon_refi;
 unsigned int ddr_type;
 unsigned int voltage;
 unsigned int mem_voltage;
 unsigned int vdd2h_voltage;
 unsigned int vddhv_voltage;
 unsigned int l1bus_p0;
 unsigned int l1bus_p1;
 unsigned int l1bus_div;
};
#undef NPU_INFO_FROM_KERNEL
struct npu_info {
 unsigned int freq_volt[MAX_NPU_MODULE_SHOW][NPU_INFO_MAX];
 char name[MAX_NPU_MODULE_SHOW][MAX_NPU_NAME_LEN];
};
struct peri_info {
 unsigned int vote[MAX_PERI_VOTE_TYPE_LEN];
 unsigned int mem_vote[MAX_PERI_MEM_VOTE_TYPE_LEN];
 unsigned int m1_vote[MAX_PERI_MEDIA_VOTE_TYPE_LEN];
 unsigned int m2_vote[MAX_PERI_MEDIA_VOTE_TYPE_LEN];
 unsigned int freq;
 unsigned int voltage;
 unsigned int mem_voltage;
 unsigned int m1_voltage;
 unsigned int m2_voltage;
};
struct ao_info {
 unsigned int vote[MAX_AO_VOTE_NUM];
 unsigned int freq;
 unsigned int voltage;
 unsigned int mem_voltage;
};
struct cpu_info {
 unsigned int freq_khz[CPU_CLUSTER_CNT];
 unsigned int voltage[CPU_CLUSTER_CNT];
 unsigned int mem_voltage[CPU_CLUSTER_CNT];
 unsigned int temp_little;
 unsigned int temp_middle;
 unsigned int temp_big;
 char little_core_power_state[POWER_STATE];
 char middle_core_power_state[POWER_STATE];
 char big_core_power_state[POWER_STATE];
 char little_cluster_power_state[POWER_STATE];
 char middle_cluster_power_state[POWER_STATE];
 char big_cluster_power_state[POWER_STATE];
};
struct l3_info {
 unsigned int freq_khz;
 unsigned int voltage;
 unsigned int mem_voltage;
 char pwr_stat[POWER_STATE];
};
struct temp_info {
 long module_temp[MAX_MODULE_TEMP];
 long tsensor_temp[SENSOR_UNKNOWN_MAX];
};
struct freqdump_data {
 struct cpu_info cpu;
 struct ddr_info ddr;
 struct l3_info l3;
 struct peri_info peri;
 struct ao_info ao;
 struct npu_info npu;
 struct gpu_info gpu;
 struct gpu_info gpu_fcm;
 struct temp_info temp;
 unsigned int flags;
 bool is_fpga;
};
struct freqdump_and_monitor_data {
 struct loadmonitor_data monitor;
 struct freqdump_data freqdump;
};
#endif
