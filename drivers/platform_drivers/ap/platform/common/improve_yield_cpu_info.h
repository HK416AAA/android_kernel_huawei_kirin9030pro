#ifndef __IMPROVE_YIELD_CPU_INFO_H__
#define __IMPROVE_YIELD_CPU_INFO_H__ 
#include <cpu_cluster_def.h>
typedef union {
 unsigned int value;
 struct {
  unsigned int reserved : 5;
  unsigned int all_freq_pv_flag : 1;
  unsigned int pv_flag : 1;
  unsigned int enable_flag : 1;
  unsigned int freq_ce_mask : 24;
 } bits;
} improve_yield_cluster_ecc_nv_t;
typedef struct {
 improve_yield_cluster_ecc_nv_t cluster_ecc_info[CPU_CLUSTER_CNT];
} improve_yield_cpu_ecc_nv_t;
typedef union {
 unsigned char value;
 struct {
  unsigned char reserved : 6;
  unsigned char pv_flag : 1;
  unsigned char reserved2 : 1;
 } bits;
} improve_yield_cluster_panic_nv_t;
typedef struct {
 improve_yield_cluster_panic_nv_t cluster_panic_info[CPU_CLUSTER_CNT];
} improve_yield_cpu_panic_nv_t;
#endif
