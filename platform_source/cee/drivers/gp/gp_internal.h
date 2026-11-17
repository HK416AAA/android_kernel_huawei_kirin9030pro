/*
 * gp_internal.h
 *
 * GP Internal Head File
 *
 * Copyright (c) 2023-2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef __GP_INTERNAL_H__
#define __GP_INTERNAL_H__
 
#include <linux/spinlock.h>
#include <linux/miscdevice.h>

#define HWP_GP_CTLR_EL1       sys_reg(3, 1, 15, 4, 3)
#define CPUPRFCTLR_EL1        sys_reg(3, 1, 15, 6, 4)
#define HWP_QOS_VALUE_CFG_EL1 sys_reg(3, 1, 15, 4, 6)
#define IFUACTLR1_EL1         sys_reg(3, 1, 15, 3, 6)
#define CPUPRFCTLR_GP_BIT     18
#define GP_MASK_EL1           (0x1 << CPUPRFCTLR_GP_BIT)
#define GP_EN_EL1             (0x0 << CPUPRFCTLR_GP_BIT)
#define GP_DIS_EL1            (0x1 << CPUPRFCTLR_GP_BIT)

#define GP_CFP_GASID          0x4010000
#define gp_cfp_asid(asid)     (((asid) & 0xff) | 0x4000000)

#define GP_CTLR_OPTYPE_MASK   0x7
#define GP_CTLR_FLUSH_MASK    0x1
#define GP_CTLR_WAY_MASK      0xff
#define GP_CTLR_VMID_MASK     0xff
#define GP_CTLR_ASID_MASK     0xffff
#define GP_CTLR_CKB_MASK      0xffff
#define GP_CTLR_PMUA_MASK     0x3f
#define GP_CTLR_PMUB_MASK     0x3f
#define gp_ctlr_optype(type)  (((type) & GP_CTLR_OPTYPE_MASK) << 0)
#define gp_ctlr_flush(flush)  (((flush) & GP_CTLR_FLUSH_MASK) << 4)
#define gp_ctlr_way(way)      (((way) & GP_CTLR_WAY_MASK) << 16)
#define gp_ctlr_vmid(vmid)    (((vmid) & GP_CTLR_VMID_MASK) << 40)
#define gp_ctlr_asid(asid)    (((asid) & GP_CTLR_ASID_MASK) << 48)
#define gp_ctlr_ckbcfg(ckb)   (((ckb) & GP_CTLR_CKB_MASK) << 48)
#define gp_ctlr_pmua(pmu)     (((pmu) & GP_CTLR_PMUA_MASK) << 48)
#define gp_ctlr_pmub(pmu)     (((pmu) & GP_CTLR_PMUB_MASK) << 54)

#define gp_ctlr_enable(asid, way)  \
	(gp_ctlr_optype(1) | gp_ctlr_asid(asid) | gp_ctlr_way(way))
#define GP_CTLR_DISABLE  (gp_ctlr_optype(0))
#define gp_ctlr_flush_way(way)  \
	(gp_ctlr_optype(2) | gp_ctlr_flush(1) | gp_ctlr_way(way))
#define gp_ctlr_flush_asid(asid)  \
	(gp_ctlr_optype(2) | gp_ctlr_flush(0) | gp_ctlr_asid(asid))
#define GP_CTLR_SLEEP  gp_ctlr_optype(3)
#define gp_ctlr_ckb(ckb)  \
	(gp_ctlr_optype(4) | gp_ctlr_ckbcfg(ckb))
#define gp_ctlr_pmu(p0, p1)  \
	(gp_ctlr_optype(5) | gp_ctlr_pmua(p0) | gp_ctlr_pmub(p1))

#define define_sysreg_read_func(_name, _reg_name)              \
static inline u64 read_ ## _name(void)				\
{								\
	return read_sysreg_s(_reg_name);				\
}

#define define_sysreg_write_func(_name, _reg_name)		\
static inline void write_ ## _name(u64 v)			\
{								\
	write_sysreg_s(v, _reg_name);				\
}

#define define_hw_sysreg_rw_funcs(_name, _reg_name)		\
	define_sysreg_read_func(_name, _reg_name)		\
	define_sysreg_write_func(_name, _reg_name)

define_hw_sysreg_rw_funcs(hwp_gp_ctlr_el1, HWP_GP_CTLR_EL1)
define_hw_sysreg_rw_funcs(cpuprfctlr_el1, CPUPRFCTLR_EL1)
define_hw_sysreg_rw_funcs(hwp_qos_value_cfg_el1, HWP_QOS_VALUE_CFG_EL1)
define_hw_sysreg_rw_funcs(ifuactlr1_el1, IFUACTLR1_EL1)

struct gp {
	struct list_head gp_info_list;
	struct miscdevice dev;
	struct proc_dir_entry *proc_gp;
	spinlock_t lock;
	u64 way_mask;
	int gp_info_count;
};

struct gp_info {
	struct list_head node;
	u64 asid;
	int tid;
	u64 way_mask;
	u64 reserved_way_mask;
	bool valid;
};

struct gp_thread_info {
	int tid;
	u64 way_num;
};

#endif