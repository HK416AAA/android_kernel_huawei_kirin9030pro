#ifndef LOADMONITOR_PLAT_H
#define LOADMONITOR_PLAT_H 
#include <soc_pmctrl_interface.h>
#include <freqdump_plat_common.h>
#define PERI_VOTE_8_PROFILE 
#define CONFIG_DUBAI_LOADMONITOR 
#define MONITOR0_IP_MASK 0xFFFFFFFF
#define MAX_PERI_MONITOR0_DEVICE bit_count(MONITOR0_IP_MASK)
#define MONITOR1_IP_MASK 0xFFFFFFFF
#define MAX_PERI_MONITOR1_DEVICE bit_count(MONITOR1_IP_MASK)
#define AO_MONITOR0_IP_MASK 0xFFFFFFFF
#define MAX_MONITOR_IP_DEVICE_AO bit_count(AO_MONITOR0_IP_MASK)
#define MAX_PERI_MONITOR_DEVICE (MAX_PERI_MONITOR0_DEVICE + MAX_PERI_MONITOR1_DEVICE)
#define MAX_MONITOR_IP_DEVICE (MAX_PERI_MONITOR_DEVICE + MAX_MONITOR_IP_DEVICE_AO)
#define LOADMONITOR_PERI_FREQ_CS 167120000
#define MONITOR_PERI_FREQ_CS 167120000
#define LOADMONITOR_PCLK 167
#define LOADMONITOR_AO_FREQ 52800000
#define MONITOR_AO_FREQ_CS 52800000
#define CHANNEL_SIZE 16
#define CHANNEL_SUM CHANNEL_SIZE
#define PERI_VOTE_DATA 32U
#define DPM_PERIOD_MAX (LOADMONITOR_PCLK * 1000 * 1000 * 25)
#define DPM_PERIOD_MIN (LOADMONITOR_PCLK * 100 * 1000)
enum EN_FLAGS {
 ENABLE_NONE = 0x0,
 ENABLE_PERI0 = 0x2,
 ENABLE_PERI1 = 0x4,
 ENABLE_PERI = ENABLE_PERI0 | ENABLE_PERI1,
 ENABLE_AO = 0x10,
 ENABLE_DDR = 0x10000,
 ENABLE_VOTE = 0x20000,
 ENABLE_ALL = ENABLE_PERI | ENABLE_AO | ENABLE_DDR | ENABLE_VOTE,
};
struct loadmonitor_ips {
 struct ips_info peri0;
 struct ips_info peri1;
 struct ips_info ao;
};
struct dubai_peri {
 SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_0_UNION vote0;
 SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_1_UNION vote1;
 SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_2_UNION vote2;
        SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_3_UNION vote3;
 SOC_PMCTRL_PERI_VOTE_VOL_VALID_UNION enable;
};
struct loadmonitor_data {
 struct loadmonitor_ips ips;
 struct loadmonitor_ddr ddr;
 struct dubai_peri peri;
};
#define MAX_NUM_LOGIC_IP_DEVICE (sizeof(struct loadmonitor_ips) / \
     sizeof(struct ips_info) * MAX_SENSOR_NUM)
struct delay_time_with_freq {
 unsigned int monitor_enable_flags;
 unsigned int peri0;
 unsigned int peri1;
 unsigned int ao;
};
#endif
