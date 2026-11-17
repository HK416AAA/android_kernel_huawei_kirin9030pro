#ifndef __CPU_TOPOLOGY_H__
#define __CPU_TOPOLOGY_H__ 
#include <cpu_cluster_def.h>
#define CORE_NUM_LIT 4
#define CORE_NUM_MID 8
#define CORE_NUM_BIG 2
#define ST_CORE_NUM_LIT 4
#define ST_CORE_NUM_MID 4
#define ST_CORE_NUM_BIG 1
#define CORE_NUM_ALL (CORE_NUM_LIT + CORE_NUM_MID + CORE_NUM_BIG)
#define ST_CORE_NUM_ALL (ST_CORE_NUM_LIT + ST_CORE_NUM_MID + ST_CORE_NUM_BIG)
#define CORE_FULL_BITMASK ((1U << CORE_NUM_ALL) - 1U)
#define LIT_CLUSTER_CORE_BASE 0
#define MID_CLUSTER_CORE_BASE CORE_NUM_LIT
#define BIG_CLUSTER_CORE_BASE (CORE_NUM_LIT + CORE_NUM_MID)
#define CLUSTER_CORE_BASE(clus) \
 (((clus) == CPU_LIT_CLUSTER) ? LIT_CLUSTER_CORE_BASE : \
  ((clus) == CPU_MID_CLUSTER) ? MID_CLUSTER_CORE_BASE : \
  BIG_CLUSTER_CORE_BASE)
#define CLUSTER_ID(cpu) \
 (((cpu) < MID_CLUSTER_CORE_BASE) ? CPU_LIT_CLUSTER : \
  ((cpu) < BIG_CLUSTER_CORE_BASE) ? CPU_MID_CLUSTER : \
  CPU_BIG_CLUSTER)
#define CORE_ID(clus,cpu) ((cpu) - CLUSTER_CORE_BASE(clus))
#define CPU_ID(clus,core) ((core) + CLUSTER_CORE_BASE(clus))
#define ST_CPU_ID(cluster,core) \
 (((cluster) == CPU_LIT_CLUSTER) ? core : \
 (((core) >> 1) + (((cluster) == CPU_MID_CLUSTER) ? (ST_CORE_NUM_LIT) : \
  (ST_CORE_NUM_LIT + ST_CORE_NUM_MID))))
#define IS_MT_CORE(cluster,core) ((cluster) != CPU_LIT_CLUSTER)
#if !(defined(__LINKER__) || defined(__ASSEMBLER__) || defined( __SOC_H_FOR_ASM__))
static const unsigned int g_cluster_core_cnt[CPU_CLUSTER_CNT] = {
 CORE_NUM_LIT, CORE_NUM_MID, CORE_NUM_BIG,
};
static const unsigned int g_cluster_core_mask[CPU_CLUSTER_CNT] = {
 (1U << CORE_NUM_LIT) - 1U,
 (1U << CORE_NUM_MID) - 1U,
 (1U << CORE_NUM_BIG) - 1U,
};
static const unsigned int g_cluster_core_base[CPU_CLUSTER_CNT] = {
 LIT_CLUSTER_CORE_BASE, MID_CLUSTER_CORE_BASE, BIG_CLUSTER_CORE_BASE,
};
static const unsigned int g_st_core_cnt[CPU_CLUSTER_CNT] = {
 ST_CORE_NUM_LIT, ST_CORE_NUM_MID, ST_CORE_NUM_BIG,
};
static const unsigned int g_st_core_base[CPU_CLUSTER_CNT] = {
 0, ST_CORE_NUM_LIT, ST_CORE_NUM_LIT + ST_CORE_NUM_MID,
};
#endif
#endif
