/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __MPAM_SCHED_H
#define __MPAM_SCHED_H

#include <linux/types.h>
#include <linux/sched.h>
#include <linux/jump_label.h>

/**
 * struct mpam_pqr_state - State cache for the PQR MSR
 * @cur_partid:	        The cached curent partid
 * @default_partid:	The user assigned cached default partid
 *
 * The cache also helps to avoid pointless updates if the value does
 * not change.
 */
struct mpam_pqr_state {
	u32			cur_partid;
	u32			default_partid;
};

enum mpam_speedup_cmd {
	MPAM_SPEEDUP_STOP,
	MPAM_SPEEDUP_START,
	MPAM_SPEEDUP_KEEP
};

enum mpam_policy_type {
	MPAM_POLICY_BASE,
	MPAM_POLICY_VIPTASK,
	MPAM_POLICY_VIPTASK0,
	MPAM_POLICY_AIGAME,
	MPAM_POLICY_AIGAME_SC,
	MPAM_POLICY_MAX
};

enum mpam_partid_type {
	MPAM_PARTID_BASE,
	MPAM_PARTID_VIPTASK,
	MPAM_PARTID_AIGAME,
	MPAM_PARTID_MAX
};

#ifdef CONFIG_MPAM
void mpam_sched_in(void);

int mpam_cpus_write(u32 partid, u32 cpus_mask);

int mpam_partid_task_set(u32 partid, pid_t pid);
#else
static inline void mpam_sched_in(void) {}

static inline int mpam_cpus_write(u32 partid, u32 cpus_mask)
{
	return 0;
}

static inline int mpam_partid_task_set(u32 partid, pid_t pid)
{
	return 0;
}

#endif

#ifdef CONFIG_MPAM_POLICY
void update_mpam_speedup(enum mpam_speedup_cmd cmd);
int perf_ctrl_set_task_l3c_part(void __user *uarg);
#else
static inline void update_mpam_speedup(enum mpam_speedup_cmd cmd) {}
static inline int perf_ctrl_set_task_l3c_part(void __user *uarg)
{
	return -EFAULT;
}
#endif

#endif /* __MPAM_SCHED_H */
