/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description:pcie_chip.c
 * Author: dpa drivers
 */

#define MPXX_LOG_MODULE_NAME     "[PCIEC]"
#define MPXX_LOG_MODULE_NAME_VAR pciec_loglevel
#define HISI_LOG_TAG               "[PCIEC]"

#include "pcie_chip.h"
#include "mp17c/pcie_chip_mp17c.h"
#include "osl_irq.h"
#include "hcc_master.h"
#include "conn_dmi_flowctrl.h"
#include "dpa_exception_rst.h"
#include "oam_logger.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_PCIE_CHIP_C

#define PCIE_INTX_IRQ_NUM       117     // 暂时写死，需要修改为dpa提供的get_pcie0_irqnum

static hcc_bus_t g_pcie_bus;
oal_pcie_res *g_pcie_ete_res = NULL;

oal_pcie_res *get_pcie_res(void)
{
    return g_pcie_ete_res;
}

static pcie_chip_id_stru g_pcie_chipinfo_id[] = {
    {PCIE_HISI_DEVICE_ID_MP17C,    oal_pcie_chip_info_init_mp17c}
};

uint8_t oal_pcie_link_state_up(uint8_t dev_id)
{
    oal_pcie_res *pci_dpa_res = NULL;
    pcie_res *pcie_res = NULL;

    pci_dpa_res = get_pcie_res();
    if (pci_dpa_res == NULL) {
        return OAL_FALSE;
    }

    pcie_res = pci_dpa_res->pst_pci_res;
    if (pcie_res == NULL) {
        return OAL_FALSE;
    }

    return (pcie_res->link_state == PCI_WLAN_LINK_WORK_UP);
}

/* PCIE EP Master 口访问,主芯片CPU访问片内地址空间(注意不能访问片内PCIE Slave口空间) for WiFi TAE
 *    将devcpu看到的地址转换成host侧看到的物理地址和虚拟地址 */
int32_t oal_pcie_devca_to_hostva(uint32_t ul_chip_id, uint64_t dev_cpuaddr, uint64_t *host_va)
{
    return hcc_bus_master_address_switch(&g_pcie_bus, dev_cpuaddr, host_va, MASTER_WCPUADDR_TO_VA);
}

/* 虚拟地址转换成WCPU看到的地址 */
int32_t oal_pcie_get_dev_ca(uint32_t ul_chip_id, void *host_va, uint64_t* dev_cpuaddr)
{
    return hcc_bus_master_address_switch(&g_pcie_bus,
                                         (uint64_t)(uintptr_t)host_va, dev_cpuaddr, MASTER_VA_TO_WCPUADDR);
}

/* PCIE EP Slave 口看到的地址转换 --片内外设通过PCIE访问主芯片DDR空间 */
/* 地址转换主芯片的DDR设备地址转换成device的SLAVE口地址
 *  注意这里的DDR设备地址(iova)不是的直接物理地址，而是对应Kernel的DMA地址
 *  设备地址不能通过phys_to_virt/virt_to_phys直接转换
 */
int32_t pcie_if_hostca_to_devva(uint32_t chip_id, uint64_t host_iova, uint64_t *addr)
{
    return hcc_bus_slave_address_switch(&g_pcie_bus, host_iova, addr, SLAVE_IOVA_TO_PCI_SLV);
}

/* 地址转换主芯片的DDR设备地址转换成device的SLAVE口地址 */
int32_t pcie_if_devva_to_hostca(uint32_t chip_id, uint64_t devva, uint64_t *host_iova)
{
    return hcc_bus_slave_address_switch(&g_pcie_bus, devva, host_iova, SLAVE_PCI_SLV_TO_IOVA);
}

static int32_t oal_pcie_chip_info_res_init(pcie_res *pst_pci_res, int32_t device_id)
{
    int32_t i;
    int32_t chip_num = (int32_t)oal_array_size(g_pcie_chipinfo_id);
    for (i = 0; i < chip_num; i++) {
        if (g_pcie_chipinfo_id[i].device_id == device_id) {
            if (g_pcie_chipinfo_id[i].func != NULL) {
                return g_pcie_chipinfo_id[i].func(pst_pci_res, device_id);
            } else {
                oam_warning_log1(0, OAM_SF_DPA, "pcie chip init 0x%x init null func", device_id);
                return OAL_SUCC;
            }
        }
    }
    oam_error_log1(0, OAM_SF_DPA, "not implement chip info init device_id=0x%x", device_id);
    return -OAL_ENODEV;
}

static int32_t oal_pcie_chip_info_init(pcie_res *pst_pci_res)
{
    int32_t ret;
    uint32_t device_id = pst_pci_res->device;
    size_t len = sizeof(pst_pci_res->chip_info.addr_info);

    (void)memset_s(&pst_pci_res->chip_info.addr_info, len, 0, len);

    ret = oal_pcie_chip_info_res_init(pst_pci_res, device_id);
    if (ret != OAL_SUCC) {
        return ret;
    }

    return ret;
}

int32_t oal_pcie_host_slave_address_switch(pcie_res *pst_pci_res, uint64_t src_addr,
                                           uint64_t* dst_addr, int32_t is_host_iova)
{
    if (oal_warn_on(pst_pci_res->chip_info.cb.pcie_host_slave_address_switch == NULL)) {
        *dst_addr = 0;
        return -OAL_ENODEV; // needn't address switch
    }
    return pst_pci_res->chip_info.cb.pcie_host_slave_address_switch(pst_pci_res,
                                                                    src_addr, dst_addr, is_host_iova);
}

void oal_pcie_trigger_dfr(void)
{
    dpa_exception_submit(EXCEPTION_TYPE_PLAT_PCIE, NULL, 0);
}

int32_t oal_enable_pcie_irq(oal_pcie_res *pst_pci_lres)
{
    uint32_t ret;
    ret = mdrv_hwi_enable(pst_pci_lres->irq_num);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "enable_pcie_irq fail, ret = %u", ret);
        return -OAL_EFAIL;
    }
    return OAL_SUCC;
}

int32_t oal_disable_pcie_irq(oal_pcie_res *pst_pci_lres)
{
    uint32_t ret;
    ret = mdrv_hwi_disable(pst_pci_lres->irq_num);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "disable_pcie_irq fail, ret = %u", ret);
        return -OAL_EFAIL;
    }
    return OAL_SUCC;
}

irqreturn_t oal_pcie_intx_ete_isr(void *arg)
{
    /*
     * 中断处理内容太多，目前无法下移，因为中断需要每次读空 ，而不在中断读的话，
     * 要先锁住中断，否则中断会狂报
     */
    oal_pcie_res *pst_pci_lres = get_pcie_res();
    if (oal_unlikely(oal_pcie_transfer_ete_done(pst_pci_lres->pst_pci_res) < 0)) {
        oam_error_log0(0, OAM_SF_DPA, "froce to disable pcie intx");
        oal_disable_pcie_irq(pst_pci_lres);

        oal_pcie_change_link_state(pst_pci_lres->pst_pci_res, PCI_WLAN_LINK_DOWN);
        oal_pcie_trigger_dfr();
    }
    return IRQ_HANDLED;
}

/* interrupt register */
static int32_t oal_pcie_register_int(oal_pcie_res *pst_pci_lres)
{
    osl_irq_attr_t irq_attr = {0};
    uint32_t ret = OAL_EFAIL;
    uint32_t irq_num = pst_pci_lres->irq_num;

    irq_attr.priority = OS_HWI_PRIORITY16;
    irq_attr.trigger_mode = OSL_HWI_LEVEL_TRIGGER;
    irq_attr.handler = oal_pcie_intx_ete_isr;
    irq_attr.arg = NULL;

    ret = osl_irq_request(irq_num, &irq_attr);
    if (oal_unlikely(ret)) {
        oam_error_log1(0, OAM_SF_DPA, "request intx failed, ret=%u", ret);
        return -OAL_EFAIL;
    }

    pst_pci_lres->irq_stat = 0;

    oam_warning_log1(0, OAM_SF_DPA, "request pcie intx irq %u succ", irq_num);
    return OAL_SUCC;
}

static int32_t pcie_res_sync_from_acore(oal_pcie_res *pst_pci_lres, powerup_res_sync_stru *powerup_res)
{
    int32_t ret;
    uint32_t bar_addr_high = (uint32_t)(powerup_res->cfg.bar_addr >> 32);    // 右移32位，取高位
    pst_pci_lres->irq_num = PCIE_INTX_IRQ_NUM;
    oam_info_log1(0, OAM_SF_DPA, "bar_addr: 0x%x", (uint32_t)powerup_res->cfg.bar_addr);
    if (bar_addr_high != 0) {
        oam_warning_log1(0, OAM_SF_DPA, "invalid bar_addr_high:0x%x", bar_addr_high);
        return -OAL_EFAIL;
    }
    // 同步A核资源并做dpa初始化
    ret = oal_pcie_dpa_bar_res_init(pst_pci_lres->pst_pci_res, powerup_res->cfg.bar_addr, powerup_res->cfg.bar_size);

    return ret;
}

static void oal_ete_dpa_res_exit(oal_pcie_res *pst_pci_lres)
{
    oal_mutex_free(&pst_pci_lres->pst_pci_res->st_rx_mem_lock);
    oal_ete_host_exit(pst_pci_lres->pst_pci_res);
}

static int32_t oal_ete_dpa_res_init(oal_pcie_res *pst_pci_lres)
{
    int32_t ret;
    ret = oal_ete_host_init(pst_pci_lres->pst_pci_res);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "ete host init fail");
        return -OAL_EFAIL;
    }

    ret = oal_mutex_init(&pst_pci_lres->pst_pci_res->st_rx_mem_lock);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "oal_mutex_init fail 0x%x", ret);
        goto err_mutex_init;
    }

    ret = ete_rx_thread_create();
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "ete_rx_thread_create fail");
        goto err_thread_creat_fail;
    }
    return OAL_SUCC;

err_thread_creat_fail:
    oal_mutex_free(&pst_pci_lres->pst_pci_res->st_rx_mem_lock);
err_mutex_init:
    oal_ete_host_exit(pst_pci_lres->pst_pci_res);
    return -OAL_EFAIL;
}

static void pcie_dpa_res_exit(void)
{
    oal_pcie_res *pst_pci_lres = get_pcie_res();
    ete_rx_thread_destory();

    oal_ete_dpa_res_exit(pst_pci_lres);

    oal_free(pst_pci_lres->pst_pci_res);
    pst_pci_lres->pst_pci_res = NULL;

    oal_free(pst_pci_lres);
    pst_pci_lres = NULL;
}

static void pcie_hcc_bus_init(void)
{
    hcc_master_select_bus(HCC_BUS_PCIE);
    memset_s(&g_pcie_bus, sizeof(g_pcie_bus), 0, sizeof(g_pcie_bus));
    g_pcie_bus.type = HCC_BUS_PCIE;
    oal_pcie_ete_bus_ops_init(&g_pcie_bus);
    hcc_master_add_bus(&g_pcie_bus);
}

static int32_t pcie_dpa_res_init(powerup_res_sync_stru *powerup_res)
{
    int32_t ret;
    oal_pcie_res *pst_pci_lres = NULL;

    pst_pci_lres = (oal_pcie_res *)oal_memalloc(sizeof(oal_pcie_res));
    if (pst_pci_lres == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "alloc res failed,size:%lu",
                       (unsigned long)sizeof(oal_pcie_res));
        return -OAL_ENOMEM;
    }
    memset_s((void *)pst_pci_lres, sizeof(oal_pcie_res), 0, sizeof(oal_pcie_res));

    pst_pci_lres->pst_pci_res = (pcie_res *)oal_memalloc(sizeof(pcie_res));
    if (pst_pci_lres->pst_pci_res == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "alloc pcie res failed, size:%u", (uint32_t)sizeof(pcie_res));
        goto pst_pci_res_init_fail;
    }
    memset_s((void *)pst_pci_lres->pst_pci_res, sizeof(pcie_res), 0, sizeof(pcie_res));

    pst_pci_lres->pst_pci_res->device = powerup_res->cfg.pcie_dev_id;

    ret = oal_pcie_chip_info_init(pst_pci_lres->pst_pci_res);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "pcie_chip_info_init fail");
        goto pcie_chip_info_init_fail;
    }

    ret = oal_ete_dpa_res_init(pst_pci_lres);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "ete res init fail");
        goto pcie_chip_info_init_fail;
    }

    ret = pcie_res_sync_from_acore(pst_pci_lres, powerup_res);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "pcie res sync from acore fail");
        goto ete_res_init_fail;
    }

    ret = oal_pcie_register_int(pst_pci_lres);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "pcie register intx fail");
        goto ete_res_init_fail;
    }

    g_pcie_ete_res = pst_pci_lres;

    oam_warning_log0(0, OAM_SF_DPA, "pci_dpa_res init succ");
    return OAL_SUCC;
ete_res_init_fail:
    oal_ete_dpa_res_exit(pst_pci_lres);
pcie_chip_info_init_fail:
    oal_free(pst_pci_lres->pst_pci_res);
    pst_pci_lres->pst_pci_res = NULL;
pst_pci_res_init_fail:
    oal_free(pst_pci_lres);
    pst_pci_lres = NULL;

    return -OAL_EFAIL;
}

int32_t oal_pcie_bus_init(powerup_res_sync_stru *powerup_res)
{
    int32_t ret;
    ret = pcie_dpa_res_init(powerup_res);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "pcie_dpa_res_init fail");
        return -OAL_FAIL;
    }

    pcie_hcc_bus_init();
    return OAL_SUCC;
}

void oal_pcie_bus_deinit(void)
{
    memset_s(&g_pcie_bus, sizeof(g_pcie_bus), 0, sizeof(g_pcie_bus));
    pcie_dpa_res_exit();
}