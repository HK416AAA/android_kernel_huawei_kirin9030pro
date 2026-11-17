#ifndef MPAM_POLICY_CONFIG_H
#define MPAM_POLICY_CONFIG_H 
unsigned int sysctl_enable_mpam_speedup = 0;
struct mpam_policy g_policy[MPAM_POLICY_MAX] = {
 {
  .type = MPAM_CLASS_CACHE,
  .level = L3_CACHE,
  .comp_id = COMP_1,
  .user = BASE,
  .partid = MPAM_PARTID_BASE,
  .prio = 0,
  .cpbm = {[0 ... MAX_PARTID - 1] = 0xfff},
 },
 {
  .type = MPAM_CLASS_CACHE,
  .level = L3_CACHE,
  .comp_id = COMP_1,
  .user = VIP,
  .partid = MPAM_PARTID_VIPTASK,
  .prio = 1,
  .cpbm = {[0] = 0x7, [MPAM_PARTID_VIPTASK] = 0xfff, [MPAM_PARTID_VIPTASK + 1 ... MAX_PARTID - 1] = 0x7},
 },
 {
  .type = MPAM_CLASS_CACHE,
  .level = L3_CACHE,
  .comp_id = COMP_1,
  .user = VIP,
  .partid = MPAM_PARTID_VIPTASK,
  .prio = 2,
  .cpbm = {[0] = 0x7, [MPAM_PARTID_VIPTASK] = 0xff8, [MPAM_PARTID_VIPTASK + 1 ... MAX_PARTID - 1] = 0x7},
 },
 {
  .type = MPAM_CLASS_CACHE,
  .level = L3_CACHE,
  .comp_id = COMP_1,
  .user = AI,
  .partid = MPAM_PARTID_AIGAME,
  .prio = 3,
  .cpbm = {[0 ... MPAM_PARTID_AIGAME - 1] = 0x3, [MPAM_PARTID_AIGAME] = 0xffc, [MPAM_PARTID_AIGAME + 1 ... MAX_PARTID - 1] = 0x3},
 },
 {
  .type = MPAM_CLASS_CACHE,
  .level = L3_CACHE,
  .comp_id = COMP_1,
  .user = AI,
  .partid = MPAM_PARTID_AIGAME,
  .prio = 4,
  .cpbm = {[0 ... MPAM_PARTID_AIGAME - 1] = 0x3, [MPAM_PARTID_AIGAME] = 0xfff, [MPAM_PARTID_AIGAME + 1 ... MAX_PARTID - 1] = 0x3},
  .sc_cpbm = {[0 ... MAX_PARTID - 1] = 0xfff},
 },
};
#endif
