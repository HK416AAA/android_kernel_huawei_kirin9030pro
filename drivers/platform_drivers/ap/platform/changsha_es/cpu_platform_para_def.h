#ifndef __CPU_PLATFORM_PARA_DEF_H__
#define __CPU_PLATFORM_PARA_DEF_H__ 
#include <cpu_cluster_def.h>
#define CPU_MAX_AVS_TZONE 8
typedef struct {
 unsigned char avs_volt[CPU_MAX_AVS_TZONE];
 unsigned short ddr_freq_limit[2];
 unsigned int apll_ctrl0;
 unsigned int apll_ctrl1;
 unsigned char clkdiv;
 unsigned char volprofile;
 unsigned char memvoltprofile;
 unsigned char div_code;
 unsigned short freq;
 unsigned char idle_clkdiv;
 unsigned char func_switch;
 unsigned short svfd_code;
} cpu_profile;
#endif
