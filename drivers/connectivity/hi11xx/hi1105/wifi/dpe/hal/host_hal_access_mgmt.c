/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : Host访问Device控制
 * 作    者 : wifi
 * 创建日期 : 2023年2月13日
 */

#include "host_hal_access_mgmt.h"
#include "host_hal_ext_if.h"
#include "dpe_wlan_resource.h"
#include "plat_pm_wlan.h"
#include "pcie_host.h"
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "pm_wlan.h"
#endif

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HOST_HAL_ACCESS_MGMT_C

OAL_PL1_DATA uint32_t g_forbid_sleep_bitmap = 0x0;
oal_spin_lock_stru g_access_dev_lock;
oal_atomic g_wifi_forbid_sleep;  // 部署ddr,业务是否禁止睡眠投票

#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#define FORBIDE_SLEEP_RECORD_CNT 100
uint8_t g_forbid_sleep_record = 0;
oal_bool_enum_uint8 g_check_forbid_sleep_enable = OAL_FALSE;

void hal_pm_set_check_forbid_sleep_enable(oal_bool_enum_uint8 enable)
{
    g_check_forbid_sleep_enable = enable;
}

// 在定时器中检查forbid_sleep的值，如果连续10s都是非0，输出error
void hal_pm_check_forbid_sleep_in_timer(void)
{
    if (g_check_forbid_sleep_enable == OAL_FALSE || oal_atomic_read(&g_wifi_forbid_sleep) == 0) {
        g_forbid_sleep_record = 0;
        return;
    }
    g_forbid_sleep_record++;
    if (g_forbid_sleep_record >= FORBIDE_SLEEP_RECORD_CNT) {
        oam_error_log2(0, OAM_SF_DPA, "hal_pm_check_forbid_sleep_in_timer: forbid_sleep[%d], bitmap is [%x] \n",
            oal_atomic_read(&g_wifi_forbid_sleep), g_forbid_sleep_bitmap);
        g_forbid_sleep_record = 0;
    }
}
#endif

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
typedef struct {
    uint8_t __rcu *access_dev_allowed;
} hal_host_access_device_mgmt_stru;

static DEFINE_PER_CPU(uint8_t, g_pcpu_access_dev_mem);
static DEFINE_PER_CPU(hal_host_access_device_mgmt_stru, g_pcpu_access_dev_mgmt) = { 0 };

/* need to be protected by rcu_read_lock! */
static inline uint8_t hal_host_pcpu_access_device_allowed(void)
{
    hal_host_access_device_mgmt_stru *pcpu_access_dev_mgmt = this_cpu_ptr(&g_pcpu_access_dev_mgmt);
    return *rcu_dereference(pcpu_access_dev_mgmt->access_dev_allowed);
}

static void hal_host_pcpu_update_access_device_status(uint8_t allowed)
{
    int32_t cpu;
    uint8_t *pcpu_access_dev_mem = NULL;

    oal_spin_lock_bh(&g_access_dev_lock);
    for_each_possible_cpu(cpu) {
        pcpu_access_dev_mem = per_cpu_ptr(&g_pcpu_access_dev_mem, cpu);
        *pcpu_access_dev_mem = allowed;
        rcu_assign_pointer(per_cpu_ptr(&g_pcpu_access_dev_mgmt, cpu)->access_dev_allowed, pcpu_access_dev_mem);
    }
    oal_spin_unlock_bh(&g_access_dev_lock);

    synchronize_rcu();
}

void hal_host_forbid_access_device(void)
{
    hal_host_pcpu_update_access_device_status(OAL_FALSE);
    oam_warning_log0(0, OAM_SF_DPA, "{hal_host_forbid_access_device::access forbid}");
}

void hal_host_approve_access_device(void)
{
    hal_host_pcpu_update_access_device_status(OAL_TRUE);
    oam_warning_log0(0, OAM_SF_DPA, "{hal_host_approve_access_device::access approve}");
}

uint32_t hal_host_readl(uint64_t addr)
{
    uint32_t val = HAL_HOST_READL_INVALID_VAL; /* invalid val */

    rcu_read_lock();
    if (hal_host_pcpu_access_device_allowed()) {
        val = oal_readl(addr);
    } else {
        oam_warning_log0(0, OAM_SF_DPA, "{hal_host_readl::illegal readl}");
    }
    rcu_read_unlock();

    return val;
}

void hal_host_writel(uint32_t val, uint64_t addr)
{
    rcu_read_lock();
    if (hal_host_pcpu_access_device_allowed()) {
        oal_writel(val, addr);
    } else {
        oam_warning_log0(0, OAM_SF_DPA, "{hal_host_writel::illegal writel}");
    }
    rcu_read_unlock();
}

uint32_t hal_host_readl_irq_handle(uint64_t addr)
{
    uint32_t val = HAL_HOST_READL_INVALID_VAL; /* invalid val */

    rcu_read_lock();
    if (!hal_host_pcpu_access_device_allowed()) {
        oam_warning_log0(0, OAM_SF_DPA, "{hal_host_readl_irq::illegal readl}");
    }
    val = oal_readl(addr);
    rcu_read_unlock();

    return val;
}

uint32_t hal_host_readl_irq(uint64_t addr)
{
    if (in_irq()) {
        return hal_host_readl_irq_handle(addr);
    } else {
        return hal_host_readl(addr);
    }
}

void hal_host_writel_irq_handle(uint32_t val, uint64_t addr)
{
    rcu_read_lock();
    if (!hal_host_pcpu_access_device_allowed()) {
        oam_warning_log0(0, OAM_SF_DPA, "{hal_host_writel_irq::illegal writel}");
    }
    oal_writel(val, addr);
    rcu_read_unlock();
}

void hal_host_writel_irq(uint32_t val, uint64_t addr)
{
    if (in_irq()) {
        hal_host_writel_irq_handle(val, addr);
    } else {
        hal_host_writel(val, addr);
    }
}

#else
OAL_PL1_DATA uint8_t g_wifi_access_dev_allowed[CORE_NUM] = { OAL_TRUE, OAL_TRUE };

void hal_host_forbid_access_device(void)
{
    uint8_t core;
    oal_uint flags;
    oal_spin_lock_irq_save(&g_access_dev_lock, &flags);
    for (core = 0; core < CORE_NUM; core++) {
        g_wifi_access_dev_allowed[core] = OAL_FALSE;
    }
    oam_warning_log0(0, OAM_SF_DPA, "{hal_host_forbid_access_device::access forbid}");
    oal_spin_unlock_irq_restore(&g_access_dev_lock, &flags);
}

void hal_host_approve_access_device(void)
{
    uint8_t core;
    oal_uint flags;
    oal_spin_lock_irq_save(&g_access_dev_lock, &flags);
    for (core = 0; core < CORE_NUM; core++) {
        g_wifi_access_dev_allowed[core] = OAL_TRUE;
    }
    oam_warning_log0(0, OAM_SF_DPA, "{hal_host_approve_access_device::access approve}");
    oal_spin_unlock_irq_restore(&g_access_dev_lock, &flags);
}
static inline uint8_t hal_host_pcpu_access_device_allowed(uint8_t core_id)
{
    return g_wifi_access_dev_allowed[core_id];
}
uint32_t hal_host_readl(uint64_t addr)
{
    uint32_t val = HAL_HOST_READL_INVALID_VAL; /* invalid val */
    if (hal_host_pcpu_access_device_allowed(DPE_CORE_0) == OAL_TRUE) {
        return oal_readl(addr);
    }
    oam_warning_log1(0, OAM_SF_DPA, "{hal_host_readl::illegal readl 0x%x}", addr);
    return val;
}

void hal_host_writel(uint32_t val, uint64_t addr)
{
    /* 非中断返回 */
    if (hal_host_pcpu_access_device_allowed(DPE_CORE_0) == OAL_TRUE) {
        oal_writel(val, addr);
        return;
    }
    oam_warning_log2(0, OAM_SF_DPA, "{hal_host_writel::illegal writel 0x%x 0x%x}", addr, val);
}

uint32_t hal_host_readl_irq(uint64_t addr)
{
    if (!hal_host_pcpu_access_device_allowed(DPE_CORE_0)) {
        oam_warning_log1(0, OAM_SF_DPA, "{hal_host_readl_irq::illegal readl 0x%x}", addr);
    }
    return oal_readl(addr);
}

void hal_host_writel_irq(uint32_t val, uint64_t addr)
{
    if (!hal_host_pcpu_access_device_allowed(DPE_CORE_0)) {
        oam_warning_log2(0, OAM_SF_DPA, "{hal_host_writel_irq::illegal writel 0x%x 0x%x}", addr, val);
    }
    oal_writel(val, addr);
}
#endif

void hal_host_access_device_init(void)
{
    oal_spin_lock_init(&g_access_dev_lock);
    hal_host_approve_access_device();
}
void hal_host_access_device_exit(void)
{
    OAL_SPIN_LOCK_EXIT(&g_access_dev_lock);
}

uint32_t hal_pm_try_wakeup_dev_lock(void)
{
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
    mdrv_thread_type_t thread_type = mdrv_cur_context();
    if (thread_type == SYS_TASK) {
        if (wlan_pm_try_wakeup_dev_lock() != OAL_SUCC) {
            return OAL_FAIL;
        }
    } else if (thread_type == SYS_FIBER) {
        // 由于fiber中不能被阻塞，无法调用唤醒接口（有mutex锁），只做状态判断
        // POWER_STATE_SHUTDOWN表示device不可访问(进深睡或下电)
        if (pm_wlan_dpa_get_acpu_state() == POWER_STATE_SHUTDOWN) {
            oam_warning_log0(0, OAM_SF_DPA, "{hal_pm_try_wakeup_dev_lock::device already pwr down");
            oal_dump_callstack();
            return OAL_FAIL;
        }
    } else {
        oam_error_log1(0, 0, "hal_pm_try_wakeup_dev_lock::context[%d]", thread_type);
        return OAL_FAIL;
    }
#else
    if (wlan_pm_try_wakeup_dev_lock() != OAL_SUCC) {
        return OAL_FAIL;
    }
#endif
    if (!oal_pcie_link_state_up(HCC_EP_WIFI_DEV)) {
        oam_warning_log0(0, OAM_SF_DPA, "{hal_pm_try_wakeup_dev_lock::dpe pcie is not work up");
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

void hal_pm_try_wakeup_forbid_sleep(hal_pm_forbid_sleep_bitmap_type_enum event)
{
    oal_atomic_inc(&g_wifi_forbid_sleep);
    g_forbid_sleep_bitmap |= BIT(event);
}
void hal_pm_try_wakeup_allow_sleep(hal_pm_forbid_sleep_bitmap_type_enum event)
{
    // 判断为0时，不再减，做保护
    if (oal_atomic_read(&g_wifi_forbid_sleep) == 0) {
        oam_error_log0(0, OAM_SF_DPA, "hal_pm_try_wakeup_allow_sleep: forbid_sleep is 0");
        return;
    }
    oal_atomic_dec(&g_wifi_forbid_sleep);
    g_forbid_sleep_bitmap &= ~BIT(event);
}

void hal_pm_try_wakeup_reset_forbid_sleep(void)
{
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
    struct wlan_pm_s *wlan_pm_info = wlan_pm_get_drv();
#else
    wlan_pm_ring_stat *wlan_pm_info = wlan_pm_get_ring_stat();
#endif
    if (wlan_pm_info == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "hal_pm_try_wakeup_reset_forbid_sleep: wlan_pm is null \n");
        return;
    }
    oal_atomic_set(&g_wifi_forbid_sleep, OAL_FALSE);
    g_forbid_sleep_bitmap = 0;
}

uint32_t hal_pm_try_wakeup_proc(uint8_t event_type)
{
    if (event_type >= HAL_PM_FORBIDE_SLEEP_STATE_BUTT) {
        oam_error_log1(0, OAM_SF_DPA, "hal_pm_try_wakeup_proc::event_type error[%d] \n", event_type);
        return OAL_FAIL;
    }
    hal_pm_try_wakeup_forbid_sleep(event_type);
    if (hal_pm_try_wakeup_dev_lock() != OAL_SUCC) {
        hal_pm_try_wakeup_allow_sleep(event_type);
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

void hal_host_2g_mac_intr_default_handle(void *para)
{
    host_mac_irq_default_handler(HAL_DEVICE_ID_MASTER);
}
void hal_host_5g_mac_intr_default_handle(void *para)
{
    host_mac_irq_default_handler(HAL_DEVICE_ID_SLAVE);
}
