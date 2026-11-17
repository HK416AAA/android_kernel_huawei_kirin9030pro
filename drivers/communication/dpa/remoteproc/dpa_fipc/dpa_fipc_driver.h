/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#ifndef _DPA_FIPC_DRIVER_H
#define _DPA_FIPC_DRIVER_H
#include "dpa_fipc_device.h"
#include "dpa_fipc_plat.h"

#define DPA_FIPC_GLB_CTRL 0x0040         /* 全局控制寄存器 */
#define DPA_FIPC_OPIPE_STAT0 0x0050 /* FIPC状态寄存器 */
#define DPA_FIPC_OPIPE_STAT1 0x0054 /* FIPC状态寄存器 */
#define DPA_FIPC_IPIPE_STAT0 0x0058 /* FIPC状态寄存器 */
#define DPA_FIPC_IPIPE_STAT1 0x005C /* FIPC状态寄存器 */

#define DPA_FIPC_INT_OFFSET (0x400)

#define DPA_FIPC_CORE_OPIPE_INT_MASKSET0(cpu_id, regsoffset) (0x0000 + (regsoffset) + 0x40L * (cpu_id)) /* COREx OPIPE中断屏蔽设置寄存器 */
#define DPA_FIPC_CORE_OPIPE_INT_MASKSET1(cpu_id, regsoffset) (0x0004 + (regsoffset) + 0x40L * (cpu_id)) /* COREx OPIPE中断屏蔽设置寄存器 */
#define DPA_FIPC_CORE_IPIPE_INT_MASKSET0(cpu_id, regsoffset) (0x0008 + (regsoffset) + 0x40L * (cpu_id)) /* COREx IPIPE中断屏蔽设置寄存器 */
#define DPA_FIPC_CORE_IPIPE_INT_MASKSET1(cpu_id, regsoffset) (0x000C + (regsoffset) + 0x40L * (cpu_id)) /* COREx IPIPE中断屏蔽设置寄存器 */

#define DPA_FIPC_CORE_OPIPE_INT_MASKCLR0(cpu_id, regsoffset) (0x0010 + (regsoffset) + 0x40L * (cpu_id)) /* COREx OPIPE中断屏蔽清除寄存器 */
#define DPA_FIPC_CORE_OPIPE_INT_MASKCLR1(cpu_id, regsoffset) (0x0014 + (regsoffset) + 0x40L * (cpu_id)) /* COREx OPIPE中断屏蔽清除寄存器 */
#define DPA_FIPC_CORE_IPIPE_INT_MASKCLR0(cpu_id, regsoffset) (0x0018 + (regsoffset) + 0x40L * (cpu_id)) /* COREx IPIPE中断屏蔽清除寄存器 */
#define DPA_FIPC_CORE_IPIPE_INT_MASKCLR1(cpu_id, regsoffset) (0x001C + (regsoffset) + 0x40L * (cpu_id)) /* COREx IPIPE中断屏蔽清除寄存器 */

#define DPA_FIPC_CORE_OPIPE_INT_MASK0(cpu_id, regsoffset) (0x0020 + (regsoffset) + 0x40L * (cpu_id)) /* COREx OPIPE中断屏蔽寄存器 */
#define DPA_FIPC_CORE_OPIPE_INT_MASK1(cpu_id, regsoffset) (0x0024 + (regsoffset) + 0x40L * (cpu_id)) /* COREx OPIPE中断屏蔽寄存器 */
#define DPA_FIPC_CORE_IPIPE_INT_MASK0(cpu_id, regsoffset) (0x0028 + (regsoffset) + 0x40L * (cpu_id)) /* COREx IPIPE中断屏蔽寄存器 */
#define DPA_FIPC_CORE_IPIPE_INT_MASK1(cpu_id, regsoffset) (0x002C + (regsoffset) + 0x40L * (cpu_id)) /* COREx IPIPE中断屏蔽寄存器 */

#define DPA_FIPC_CORE_OPIPE_INT_STAT0(cpu_id, regsoffset) (0x0030 + (regsoffset) + 0x40L * (cpu_id)) /* COREx OPIPE中断状态寄存器 */
#define DPA_FIPC_CORE_OPIPE_INT_STAT1(cpu_id, regsoffset) (0x0034 + (regsoffset) + 0x40L * (cpu_id)) /* COREx OPIPE中断状态寄存器 */
#define DPA_FIPC_CORE_IPIPE_INT_STAT0(cpu_id, regsoffset) (0x0038 + (regsoffset) + 0x40L * (cpu_id)) /* COREx IPIPE中断状态寄存器 */
#define DPA_FIPC_CORE_IPIPE_INT_STAT1(cpu_id, regsoffset) (0x003C + (regsoffset) + 0x40L * (cpu_id)) /* COREx IPIPE中断状态寄存器 */

#define DPA_FIPC_OPIPE_BASE_ADDR_L(opipe_id) (0x4000 + 0x80L * (opipe_id)) /* OPIPE起始地址寄存器低位 */
#define DPA_FIPC_OPIPE_BASE_ADDR_H(opipe_id) (0x4004 + 0x80L * (opipe_id)) /* OPIPE起始地址寄存器高位 */
#define DPA_FIPC_OPIPE_DEPTH(opipe_id) (0x4008 + 0x80L * (opipe_id))       /* OPIPE深度寄存器 */
#define DPA_FIPC_OPIPE_WPTR(opipe_id) (0x400C + 0x80L * (opipe_id))        /* OPIPE写指针寄存器 */
#define DPA_FIPC_OPIPE_RPTR(opipe_id) (0x4010 + 0x80L * (opipe_id))        /* OPIPE读指针寄存器 */
#define DPA_FIPC_OPIPE_PTR_ADDR_L(opipe_id) (0x4018 + 0x80L * (opipe_id))  /* OPIPE指针更新地址寄存器低位 */
#define DPA_FIPC_OPIPE_PTR_ADDR_H(opipe_id) (0x401C + 0x80L * (opipe_id))  /* OPIPE指针更新地址寄存器高位 */
#define DPA_FIPC_OPIPE_INT_MASK(opipe_id) (0x4040 + 0x80L * (opipe_id))    /* OPIPE中断屏蔽寄存器 */
#define DPA_FIPC_OPIPE_INT_STAT(opipe_id) (0x4044 + 0x80L * (opipe_id))    /* OPIPE中断状态寄存器 */
#define DPA_FIPC_OPIPE_INT_RAW(opipe_id) (0x4048 + 0x80L * (opipe_id))     /* OPIPE中断原始状态寄存器 */
#define DPA_FIPC_OPIPE_CTRL(opipe_id) (0x404C + 0x80L * (opipe_id))        /* OPIPE控制寄存器 */
#define DPA_FIPC_OPIPE_STAT(opipe_id) (0x4050 + 0x80L * (opipe_id))        /* OPIPE状态寄存器 */
#define DPA_FIPC_OPIPE_DBG0(opipe_id) (0x4054 + 0x80L * (opipe_id))        /* OPIPE debug寄存器0 */
#define DPA_FIPC_OPIPE_DBG1(opipe_id) (0x4058 + 0x80L * (opipe_id))        /* OPIPE debug寄存器1 */
#define DPA_FIPC_OPIPE_DBG2(opipe_id) (0x405C + 0x80L * (opipe_id))        /* OPIPE debug寄存器2 */
#define DPA_FIPC_OPIPE_DBG3(opipe_id) (0x4060 + 0x80L * (opipe_id))        /* OPIPE debug寄存器3 */


#define DPA_FIPC_IPIPE_BASE_ADDR_L(ipipe_id) (0x6000 + 0x80L * (ipipe_id)) /* IPIPE起始地址寄存器低位 */
#define DPA_FIPC_IPIPE_BASE_ADDR_H(ipipe_id) (0x6004 + 0x80L * (ipipe_id)) /* IPIPE起始地址寄存器高位 */
#define DPA_FIPC_IPIPE_DEPTH(ipipe_id) (0x6008 + 0x80L * (ipipe_id))       /* IPIPE深度寄存器 */
#define DPA_FIPC_IPIPE_WPTR(ipipe_id) (0x600C + 0x80L * (ipipe_id))        /* IPIPE写指针寄存器 */
#define DPA_FIPC_IPIPE_RPTR(ipipe_id) (0x6010 + 0x80L * (ipipe_id))        /* IPIPE读指针寄存器 */
#define DPA_FIPC_IPIPE_REMOTE_CTRL(ipipe_id) (0x6014 + 0x80L * (ipipe_id)) /* IPIPE remote控制寄存器	 */
#define DPA_FIPC_IPIPE_PTR_ADDR_L(ipipe_id) (0x6018 + 0x80L * (ipipe_id))  /* IPIPE指针更新地址寄存器低位 */
#define DPA_FIPC_IPIPE_PTR_ADDR_H(ipipe_id) (0x601C + 0x80L * (ipipe_id))  /* IPIPE指针更新地址寄存器高位 */
#define DPA_FIPC_IPIPE_CFG_ADDR_L(ipipe_id) (0x6020 + 0x80L * (ipipe_id))  /* IPIPE指针更新地址寄存器低位 */
#define DPA_FIPC_IPIPE_CFG_ADDR_H(ipipe_id) (0x6024 + 0x80L * (ipipe_id))  /* IPIPE指针更新地址寄存器高位 */
#define DPA_FIPC_IPIPE_INT_MASK(ipipe_id) (0x6040 + 0x80L * (ipipe_id))    /* IPIPE中断屏蔽寄存器 */
#define DPA_FIPC_IPIPE_INT_STAT(ipipe_id) (0x6044 + 0x80L * (ipipe_id))    /* IPIPE中断状态寄存器 */
#define DPA_FIPC_IPIPE_INT_RAW(ipipe_id) (0x6048 + 0x80L * (ipipe_id))     /* IPIPE中断原始状态寄存器 */
#define DPA_FIPC_IPIPE_CTRL(ipipe_id) (0x604C + 0x80L * (ipipe_id))        /* IPIPE控制寄存器 */
#define DPA_FIPC_IPIPE_STAT(ipipe_id) (0x6050 + 0x80L * (ipipe_id))        /* IPIPE状态寄存器 */
#define DPA_FIPC_IPIPE_DBG0(ipipe_id) (0x6054 + 0x80L * (ipipe_id))        /* IPIPE debug寄存器0 */
#define DPA_FIPC_IPIPE_DBG1(ipipe_id) (0x6058 + 0x80L * (ipipe_id))        /* IPIPE debug寄存器1 */
#define DPA_FIPC_IPIPE_DBG2(ipipe_id) (0x605C + 0x80L * (ipipe_id))        /* IPIPE debug寄存器2 */
#define DPA_FIPC_IPIPE_DBG3(ipipe_id) (0x6060 + 0x80L * (ipipe_id))        /* IPIPE debug寄存器3 */

/* -------------------STAT BITS FIELD----------------------------- */
#define DPA_FIPC_PIPE_STATUS_EMPTY (1 << 0)
#define DPA_FIPC_PIPE_STATUS_FULL (1 << 1)
#define DPA_FIPC_PIPE_STATUS_IDLE (1 << 2)
/* -------------------FICC全局安全控制----------------------------- */
#define GLB_SECCTRL_SECCTRL 0x10001
/* -------------------FICC自动门控----------------------------- */
#define CLOCK_AUTO_GATE 0x1FFB
/* -------------------FICC全局控制----------------------------- */
#define DPA_FIPC_GLB_CTRL_SR_PUSH (1 << 2)  /* 低功耗流程推送控制 */
#define DPA_FIPC_GLB_CTRL_CLK_AUTO (1 << 1) /* 自动门控使能控制 */

#define DPA_FIPC_PIPE_CNT_PER_REG 32

enum DPA_FIPC_INT_READ_LEV {
    DPA_FIPC_INT_RD_UNDERFLOW = 0x1,
    DPA_FIPC_INT_RD_OVERFLOW = 0x2,
    DPA_FIPC_INT_RD_DATA_ARV = 0x4,
    DPA_FIPC_INT_RD_ARV_TIMEOUT = 0x8,
    DPA_FIPC_INT_RD_PIPE_WAKEUP = 0x10
};

enum FIPC_INT_WRITE_LEV {
    DPA_FIPC_INT_WR_UNDERFLOW = 0x1,
    DPA_FIPC_INT_WR_OVERFLOW = 0x2,
    DPA_FIPC_INT_WR_DATA_DONE = 0x4,
    DPA_FIPC_INT_WR_PIPE_ERR = 0x8,
    DPA_FIPC_INT_WR_TRANSCNT_FLIP = 0x10,
    DPA_FIPC_INT_WR_ABORT = 0x20 /* 这个中断一定不要开，因为应用中强停通道可能停其他核的 */
};

int dpa_fipc_ipipe_status_check(const void *base_addr, u32 ipipe_id);
int dpa_fipc_opipe_status_check(const void *base_addr, u32 opipe_id);

void dpa_fipc_opipe_startup(void *base_addr, struct dpa_fipc_pipe_config *opipe);
void dpa_fipc_ipipe_startup(void *base_addr, struct dpa_fipc_pipe_config *ipipe);

/*lint -esym(528,dpa_fipc_opipe_is_en) */
static inline u32 dpa_fipc_opipe_is_en(const void *base_addr, u32 pipe_id)
{
    u32 status;
    status = readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_CTRL(pipe_id)));
    return (status & 1);
}

/*lint -esym(528,dpa_fipc_opipe_local_en) */
static inline void dpa_fipc_opipe_local_en(void *base_addr, u32 pipe_id)
{
    u32 status;

    status = readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_CTRL(pipe_id)));
    writel(status | 1, (void *)((char *)base_addr + DPA_FIPC_OPIPE_CTRL(pipe_id)));
}

/*lint -esym(528,dpa_fipc_opipe_local_dis) */
static inline void dpa_fipc_opipe_local_dis(void *base_addr, u32 pipe_id)
{
    u32 status;

    status = readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_CTRL(pipe_id)));
    writel(status & (~1), (void *)((char *)base_addr + DPA_FIPC_OPIPE_CTRL(pipe_id)));
}

/*lint -esym(528,dpa_fipc_opipe_abort_set) */
static inline void dpa_fipc_opipe_abort_set(void *base_addr, u32 pipe_id)
{
    u32 status;

    status = readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_CTRL(pipe_id)));
    writel(status | 0x100, (void *)((char *)base_addr + DPA_FIPC_OPIPE_CTRL(pipe_id)));
}

/*lint -esym(528,dpa_fipc_opipe_abort_clr) */
static inline void dpa_fipc_opipe_abort_clr(void *base_addr, u32 pipe_id)
{
    u32 status;

    status = readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_CTRL(pipe_id)));
    writel(status & (~0x100), (void *)((char *)base_addr + DPA_FIPC_OPIPE_CTRL(pipe_id)));
}

/*lint -esym(528,dpa_fipc_ipipe_is_en) */
static inline u32 dpa_fipc_ipipe_is_en(const void *base_addr, u32 pipe_id)
{
    u32 status;
    status = readl((void *)((char *)base_addr + DPA_FIPC_IPIPE_CTRL(pipe_id)));
    return (status & 1);
}

/*lint -esym(528,dpa_fipc_ipipe_local_en) */
static inline void dpa_fipc_ipipe_local_en(void *base_addr, u32 pipe_id)
{
    u32 status;

    status = readl((void *)((char *)base_addr + DPA_FIPC_IPIPE_CTRL(pipe_id)));
    writel(status | 1, (void *)((char *)base_addr + DPA_FIPC_IPIPE_CTRL(pipe_id)));
}

/*lint -esym(528,dpa_fipc_ipipe_local_dis) */
static inline void dpa_fipc_ipipe_local_dis(void *base_addr, u32 pipe_id)
{
    u32 status;

    status = readl((void *)((char *)base_addr + DPA_FIPC_IPIPE_CTRL(pipe_id)));
    writel(status & (~1), (void *)((char *)base_addr + DPA_FIPC_IPIPE_CTRL(pipe_id)));
}

static inline unsigned int dpa_fipc_opipe_ctrl(void *base_addr, unsigned int pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_CTRL(pipe_id)));
}

static inline void dpa_fipc_opipe_ctrl_set(void *base_addr, unsigned int pipe_id, unsigned val)
{
    writel(val, (void *)((char *)base_addr + DPA_FIPC_OPIPE_CTRL(pipe_id)));
}

static inline unsigned int dpa_fipc_ipipe_ctrl(void *base_addr, unsigned int pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_IPIPE_CTRL(pipe_id)));
}

/*lint -esym(528,dpa_fipc_ipipe_coreint_en) */
static inline void dpa_fipc_ipipe_coreint_en(void *base_addr, u32 pipe_id, u32 cpu_id, u32 regsoffset)
{
    if (pipe_id < DPA_FIPC_PIPE_CNT_PER_REG) {
        writel(1UL << pipe_id, (void *)((char *)base_addr + DPA_FIPC_CORE_IPIPE_INT_MASKSET0(cpu_id, regsoffset)));
    } else {
        writel(1UL << (pipe_id - DPA_FIPC_PIPE_CNT_PER_REG),
            (void *)((char *)base_addr + DPA_FIPC_CORE_IPIPE_INT_MASKSET1(cpu_id, regsoffset)));
    }
}

/*lint -esym(528,dpa_fipc_ipipe_coreint_dis) */
static inline void dpa_fipc_ipipe_coreint_dis(void *base_addr, u32 pipe_id, u32 cpu_id, u32 regsoffset)
{
    if (pipe_id < DPA_FIPC_PIPE_CNT_PER_REG) {
        writel(1UL << pipe_id, (void *)((char *)base_addr + DPA_FIPC_CORE_IPIPE_INT_MASKCLR0(cpu_id, regsoffset)));
    } else {
        writel(1UL << (pipe_id - DPA_FIPC_PIPE_CNT_PER_REG),
            (void *)((char *)base_addr + DPA_FIPC_CORE_IPIPE_INT_MASKCLR1(cpu_id, regsoffset)));
    }
}

/*lint -esym(528,fipc_opipe_coreint_dis) */
static inline void dpa_fipc_opipe_coreint_dis(void *base_addr, u32 pipe_id, u32 cpu_id, u32 regsoffset)
{
    if (pipe_id < DPA_FIPC_PIPE_CNT_PER_REG) {
        writel(1UL << pipe_id, (void *)((char *)base_addr + DPA_FIPC_CORE_OPIPE_INT_MASKCLR0(cpu_id, regsoffset)));
    } else {
        writel(1UL << (pipe_id - DPA_FIPC_PIPE_CNT_PER_REG),
            (void *)((char *)base_addr + DPA_FIPC_CORE_OPIPE_INT_MASKCLR1(cpu_id, regsoffset)));
    }
}

/*lint -esym(528,dpa_fipc_opipe_stat_isbusy) */
static inline int dpa_fipc_opipe_stat_isbusy(const void *base_addr, u32 pipe_id)
{
    u32 status;

    if (pipe_id < DPA_FIPC_PIPE_CNT_PER_REG) {
        status = readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_STAT0));
        status &= (1UL << pipe_id);
        if (!status) {
            return 1;
        }
    } else {
        status = readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_STAT1));
        status &= (1UL << (pipe_id - DPA_FIPC_PIPE_CNT_PER_REG));
        if (!status) {
            return 1;
        }
    }
    return 0;
}

/*lint -esym(528,dpa_fipc_ipipe_stat_isbusy) */
static inline int dpa_fipc_ipipe_stat_isbusy(const void *base_addr, u32 pipe_id)
{
    u32 status;

    if (pipe_id < DPA_FIPC_PIPE_CNT_PER_REG) {
        status = readl((void *)((char *)base_addr + DPA_FIPC_IPIPE_STAT0));
        status &= (1UL << pipe_id);
        if (!status) {
            return 1;
        }
    } else {
        status = readl((void *)((char *)base_addr + DPA_FIPC_IPIPE_STAT1));
        status &= (1UL << (pipe_id - DPA_FIPC_PIPE_CNT_PER_REG));
        if (!status) {
            return 1;
        }
    }
    return 0;
}

/*lint -esym(528,dpa_fipc_ipipe_devint_en) */
static inline u32 dpa_fipc_ipipe_devint_en(void *base_addr, u32 pipe_id, u32 level)
{
    u32 reg;

    reg = readl((void *)((char *)base_addr + DPA_FIPC_IPIPE_INT_MASK(pipe_id)));
    writel(reg | level, (void *)((char *)base_addr + DPA_FIPC_IPIPE_INT_MASK(pipe_id)));

    return (reg | level);
}

/*lint -esym(528,dpa_fipc_ipipe_devint_dis) */
static inline u32 dpa_fipc_ipipe_devint_dis(void *base_addr, u32 pipe_id, u32 level)
{
    u32 reg;

    reg = readl((void *)((char *)base_addr + DPA_FIPC_IPIPE_INT_MASK(pipe_id)));
    reg &= (~level);
    writel(reg, (void *)((char *)base_addr + DPA_FIPC_IPIPE_INT_MASK(pipe_id)));

    return reg;
}

static inline u32 dpa_fipc_ipipe_devint_mask(const void *base_addr, u32 pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_IPIPE_INT_MASK(pipe_id)));
}

/*lint -esym(528,dpa_fipc_ipipe_devint_stat) */
static inline u32 dpa_fipc_ipipe_devint_stat(const void *base_addr, u32 pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_IPIPE_INT_STAT(pipe_id)));
}

/*lint -esym(528,dpa_fipc_ipipe_devint_raw) */
static inline u32 dpa_fipc_ipipe_devint_raw(const void *base_addr, u32 pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_IPIPE_INT_RAW(pipe_id)));
}

/*lint -esym(528,dpa_fipc_opipe_devint_stat) */
static inline u32 dpa_fipc_opipe_devint_stat(const void *base_addr, u32 pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_INT_STAT(pipe_id)));
}

/*lint -esym(528,dpa_fipc_ipipe_devint_clr) */
static inline void dpa_fipc_ipipe_devint_clr(void *base_addr, u32 pipe_id, u32 level)
{
    writel(level, (void *)((char *)base_addr + DPA_FIPC_IPIPE_INT_RAW(pipe_id)));
}

/*lint -esym(528,dpa_fipc_opipe_devint_raw) */
static inline u32 dpa_fipc_opipe_devint_raw(const void *base_addr, u32 pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_INT_RAW(pipe_id)));
}

/*lint -esym(528,dpa_fipc_opipe_devint_clr) */
static inline void dpa_fipc_opipe_devint_clr(void *base_addr, u32 pipe_id, u32 level)
{
    writel(level, (void *)((char *)base_addr + DPA_FIPC_OPIPE_INT_RAW(pipe_id)));
}

/*lint -esym(528,fipc_opipe_devint_en) */
static inline u32 dpa_fipc_opipe_devint_en(void *base_addr, u32 pipe_id, u32 level)
{
    u32 reg;

    reg = readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_INT_MASK(pipe_id)));
    writel(reg | level, (void *)((char *)base_addr + DPA_FIPC_OPIPE_INT_MASK(pipe_id)));

    return (reg | level);
}

/*lint -esym(528,fipc_opipe_devint_dis) */
static inline u32 dpa_fipc_opipe_devint_dis(void *base_addr, u32 pipe_id, u32 level)
{
    u32 reg;

    reg = readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_INT_MASK(pipe_id)));
    reg &= (~level);
    writel(reg, (void *)((char *)base_addr + DPA_FIPC_OPIPE_INT_MASK(pipe_id)));

    return reg;
}

static inline u32 dpa_fipc_opipe_devint_mask(void *base_addr, u32 pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_INT_MASK(pipe_id)));
}


static inline u32 dpa_fipc_opipe_debug0(void *base_addr, u32 pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_DBG0(pipe_id)));
}

static inline u32 dpa_fipc_opipe_debug1(void *base_addr, u32 pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_DBG1(pipe_id)));
}

/*lint -esym(528,fipc_opipe_coreint_en) */
static inline void dpa_fipc_opipe_coreint_en(void *base_addr, u32 pipe_id, u32 cpu_id, u32 regsoffset)
{
    if (pipe_id < DPA_FIPC_PIPE_CNT_PER_REG) {
        writel(1UL << pipe_id, (void *)((char *)base_addr + DPA_FIPC_CORE_OPIPE_INT_MASKSET0(cpu_id, regsoffset)));
    } else {
        writel(1UL << (pipe_id - DPA_FIPC_PIPE_CNT_PER_REG),
            (void *)((char *)base_addr + DPA_FIPC_CORE_OPIPE_INT_MASKSET1(cpu_id, regsoffset)));
    }
}

/*lint -esym(528,dpa_fipc_opipe_wptr_update) */
static inline void dpa_fipc_opipe_wptr_update(void *base_addr, u32 pipe_id, u32 wptr)
{
    writel(wptr, (void *)((char *)base_addr + DPA_FIPC_OPIPE_WPTR(pipe_id)));
}

/*lint -esym(528,dpa_fipc_opipe_rptr_update) */
static inline void dpa_fipc_opipe_rptr_update(void *base_addr, u32 pipe_id, u32 rptr)
{
    writel(rptr, (void *)((char *)base_addr + DPA_FIPC_OPIPE_RPTR(pipe_id)));
}

/*lint -esym(528,dpa_fipc_opipe_wptr_get) */
static inline u32 dpa_fipc_opipe_wptr_get(const void *base_addr, u32 pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_WPTR(pipe_id)));
}

/*lint -esym(528,dpa_fipc_opipe_rptr_get) */
static inline u32 dpa_fipc_opipe_rptr_get(const void *base_addr, u32 pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_RPTR(pipe_id)));
}

/*lint -esym(528,dpa_fipc_ipipe_wptr_update) */
static inline void dpa_fipc_ipipe_wptr_update(void *base_addr, u32 pipe_id, u32 wptr)
{
    writel(wptr & 0xFFFF, (void *)((char *)base_addr + DPA_FIPC_IPIPE_WPTR(pipe_id)));
}

/*lint -esym(528,dpa_fipc_ipipe_rptr_update) */
static inline void dpa_fipc_ipipe_rptr_update(void *base_addr, u32 pipe_id, u32 rptr)
{
    writel(rptr, (void *)((char *)base_addr + DPA_FIPC_IPIPE_RPTR(pipe_id)));
}

/*lint -esym(528,dpa_fipc_ipipe_wptr_get) */
static inline u32 dpa_fipc_ipipe_wptr_get(const void *base_addr, u32 pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_IPIPE_WPTR(pipe_id))) & 0xFFFF;
}

static inline u32 dpa_fipc_ipipe_rptr_get(const void *base_addr, u32 pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_IPIPE_RPTR(pipe_id)));
}

/*lint -esym(528,dpa_fipc_opipe_local_status) */
static inline u32 dpa_fipc_opipe_local_status(const void *base_addr, u32 pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_OPIPE_STAT(pipe_id)));
}

/*lint -esym(528,dpa_fipc_ipipe_local_status) */
static inline u32 dpa_fipc_ipipe_local_status(const void *base_addr, u32 pipe_id)
{
    return readl((void *)((char *)base_addr + DPA_FIPC_IPIPE_STAT(pipe_id)));
}

static inline void dpa_msg_clock_set(const void *base_addr, u32 mask, u32 off)
{
    writel(mask, (void *)((char *)(base_addr) + off));
}
#endif