/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description:pcie_host.c
 * Author: dpa drivers
 */

#define MPXX_LOG_MODULE_NAME "[PCIE_H]"
#define HISI_LOG_TAG           "[PCIE]"
#include "pcie_host.h"
#include "pcie_chip.h"
#include "hcc_master.h"
#include "oam_logger.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_PCIE_HOST_C

char *g_pcie_link_state_str[PCI_WLAN_LINK_BUTT + 1] = {
    [PCI_WLAN_LINK_DOWN] = "linkdown",
    [PCI_WLAN_LINK_DEEPSLEEP] = "deepsleep",
    [PCI_WLAN_LINK_UP] = "linkup",
    [PCI_WLAN_LINK_MEM_UP] = "memup",
    [PCI_WLAN_LINK_RES_UP] = "resup",
    [PCI_WLAN_LINK_WORK_UP] = "workup",
    [PCI_WLAN_LINK_BUTT] = "butt"
};

/**
 * DPA无需访问iatu bar，因此仅需A核同步mem_bar信息即可
 * 该变量用于存储PCIe设备的BAR（基地址寄存器）信息
 */
static oal_pcie_bar_info g_en_bar_tab[] = {
    {
        .bar_idx = 0,
    },
};

int32_t oal_pcie_get_ca_by_pa(pcie_res *pci_res, uintptr_t paddr, uint64_t *cpuaddr)
{
    int32_t index;
    int32_t region_num;
    uint64_t offset;
    oal_pcie_region *region_base;
    uintptr_t end;

    region_num = pci_res->regions.region_nums;
    region_base = pci_res->regions.pst_regions;

    if (cpuaddr == NULL) {
        return -OAL_EINVAL;
    }

    *cpuaddr = 0;

    if (oal_warn_on(!pci_res->regions.inited)) {
        return -OAL_ENODEV;
    }

    for (index = 0; index < region_num; index++, region_base++) {
        if (region_base->vaddr == NULL) {
            continue;
        }

        end = (uintptr_t)region_base->paddr + region_base->size - 1;

        if ((paddr >= (uintptr_t)region_base->paddr) && (paddr <= end)) {
            /* 地址在范围内 */
            offset = paddr - (uintptr_t)region_base->paddr;
            *cpuaddr = region_base->cpu_start + offset;
            return OAL_SUCC;
        } else {
            continue;
        }
    }

    return -OAL_ENOMEM;
}

/*
 * 将Device Cpu看到的地址转换为 Host侧的虚拟地址,
 * 虚拟地址返回NULL为无效地址，Device Cpu地址有可能为0,
 * local ip inbound cpu address to host virtual address,
 * 函数返回非0为失败
 */
int32_t oal_pcie_inbound_ca_to_va(pcie_res *pci_res, uint64_t dev_cpuaddr, pci_addr_map *addr_map)
{
    int32_t index;
    int32_t region_num;
    uint64_t offset;
    oal_pcie_region *region_base;

    region_num = pci_res->regions.region_nums;
    region_base = pci_res->regions.pst_regions;

    if (addr_map != NULL) {
        addr_map->pa = 0;
        addr_map->va = 0;
    }

    if (oal_unlikely(pci_res->link_state < PCI_WLAN_LINK_MEM_UP)) {
        // dev_cpuaddr必为32位
        oam_warning_log2(0, OAM_SF_DPA, "addr request 0x%x failed, link_state:%d",
                         (uint32_t)dev_cpuaddr, pci_res->link_state);
        return -OAL_EBUSY;
    }

    if (oal_warn_on(!pci_res->regions.inited)) {
        return -OAL_ENODEV;
    }

    for (index = 0; index < region_num; index++, region_base++) {
        if (region_base->vaddr == NULL) {
            continue;
        }

        if ((dev_cpuaddr >= region_base->cpu_start) && (dev_cpuaddr <= region_base->cpu_end)) {
            /* 地址在范围内 */
            offset = dev_cpuaddr - region_base->cpu_start;
            if (addr_map != NULL) {
                /* 返回HOST虚拟地址 */
                addr_map->va = (uintptr_t)(region_base->vaddr + offset);
                /* 返回HOST物理地址 */
                addr_map->pa = (uintptr_t)(region_base->paddr + offset);
            }
            return OAL_SUCC;
        } else {
            continue;
        }
    }

    oam_warning_log1(0, OAM_SF_DPA, "addr request 0x%x failed", (uint32_t)dev_cpuaddr);
    return -OAL_ENOMEM;
}

/* 地址转换均为线性映射，注意起始地址和大小 */
int32_t oal_pcie_inbound_va_to_ca(pcie_res *pci_res, uint64_t host_va, uint64_t *dev_cpuaddr)
{
    int32_t index;
    int32_t region_num;
    uint64_t offset;
    oal_pcie_region *region_base;
    uint64_t end;
    uint64_t vaddr = host_va;

    region_num = pci_res->regions.region_nums;
    region_base = pci_res->regions.pst_regions;

    if (oal_warn_on(dev_cpuaddr == NULL)) {
        return -OAL_EINVAL;
    }

    *dev_cpuaddr = 0;

    if (oal_warn_on(!pci_res->regions.inited)) {
        return -OAL_ENODEV;
    }

    for (index = 0; index < region_num; index++, region_base++) {
        if (region_base->vaddr == NULL) {
            continue;
        }

        end = (uintptr_t)region_base->vaddr + region_base->size - 1;

        if ((vaddr >= (uintptr_t)region_base->vaddr) && (vaddr <= end)) {
            /* 地址在范围内 */
            offset = vaddr - (uintptr_t)region_base->vaddr;
            *dev_cpuaddr = region_base->cpu_start + offset;
            return OAL_SUCC;
        } else {
            continue;
        }
    }

    return -OAL_ENOMEM;
}

/* 检查通过PCIE操作的HOST侧虚拟地址是否合法 ，是否映射过 */
int32_t oal_pcie_vaddr_isvalid(pcie_res *pci_res, const void *vaddr)
{
    int32_t index;
    int32_t region_num;
    oal_pcie_region *region_base = NULL;
    if (oal_warn_on(!pci_res->regions.inited)) {
        return OAL_FALSE;
    }

    region_num = pci_res->regions.region_nums;
    region_base = pci_res->regions.pst_regions;

    for (index = 0; index < region_num; index++, region_base++) {
        if (region_base->vaddr == NULL) {
            continue;
        }

        if (((uintptr_t)vaddr >= (uintptr_t)region_base->vaddr)
            && ((uintptr_t)vaddr < (uintptr_t)region_base->vaddr + region_base->size)) {
            return OAL_TRUE;
        }
    }

    return OAL_FALSE;
}

void oal_pcie_release_rx_netbuf(pcie_res *pci_res, oal_netbuf_stru *netbuf)
{
    if (oal_warn_on(netbuf == NULL)) {
        return;
    }

    if (oal_warn_on(pci_res == NULL)) {
        oal_netbuf_free(netbuf);
        return;
    }

    oal_netbuf_free(netbuf);
}

void oal_pcie_tx_netbuf_free(pcie_res *pci_res, oal_netbuf_stru *netbuf)
{
    if (oal_warn_on(netbuf == NULL)) {
        return;
    }

    if (oal_warn_on(pci_res == NULL)) {
        oal_netbuf_free(netbuf);
        return;
    }

    hcc_netbuf_free(netbuf);
}

void oal_pcie_regions_info_dump(pcie_res *pci_res)
{
    int32_t index;
    int32_t region_num;
    oal_pcie_region *region_base;

    region_num = pci_res->regions.region_nums;
    region_base = pci_res->regions.pst_regions;

    if (oal_warn_on(!pci_res->regions.inited)) {
        return;
    }

    oam_warning_log1(0, OAM_SF_DPA, "regions[%d] info dump", region_num);

    for (index = 0; index < region_num; index++, region_base++) {
        oam_info_log3(0, OAM_SF_DPA, "region_index[%d]va:0x%x, pa:0x%x", index,
                      (uint32_t)(uintptr_t)region_base->vaddr, (uint32_t)region_base->paddr);
        oam_info_log2(0, OAM_SF_DPA, "pci start:0x%x end:0x%x",
                      (uint32_t)region_base->pci_start, (uint32_t)region_base->pci_end);
        oam_info_log2(0, OAM_SF_DPA, "cpu start:0x%x end:0x%x",
                      (uint32_t)region_base->cpu_start, (uint32_t)region_base->cpu_end);
        oam_info_log2(0, OAM_SF_DPA, "size:%x, flag:0x%x", region_base->size, region_base->flag);
    }
}

static void oal_pcie_ctrl_base_address_exit(pcie_res *pci_res)
{
    pci_res->pst_pci_ctrl_base = NULL;
    pci_res->pst_ete_base = NULL;
}

int32_t oal_pcie_ctrl_base_address_init(pcie_res *pci_res)
{
    int32_t ret;
    pci_addr_map st_map;

    ret = oal_pcie_inbound_ca_to_va(pci_res, pci_res->chip_info.addr_info.pcie_ctrl, &st_map);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "get dev address 0x%x failed", pci_res->chip_info.addr_info.pcie_ctrl);
        oal_pcie_regions_info_dump(pci_res);
        return -OAL_EFAIL;
    }
    pci_res->pst_pci_ctrl_base = (void *)st_map.va;

    /* ete base */
    ret = oal_pcie_inbound_ca_to_va(pci_res, pci_res->chip_info.addr_info.ete_ctrl, &st_map);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "get dev address 0x%x failed", pci_res->chip_info.addr_info.ete_ctrl);
        oal_pcie_regions_info_dump(pci_res);
        oal_pcie_ctrl_base_address_exit(pci_res);
        return -OAL_EFAIL;
    }
    pci_res->pst_ete_base = (void *)st_map.va;
    pci_res->chip_info.cb.ete_address_init(pci_res);

    oam_info_log2(0, OAM_SF_DPA, "pcie reg base init succ, pci va:0x%x, ete va:0x%x",
                  (uint32_t)(uintptr_t)pci_res->pst_pci_ctrl_base,
                  (uint32_t)(uintptr_t)pci_res->pst_ete_base);
    return OAL_SUCC;
}

/* 函数定义 */
int32_t oal_pcie_disable_regions(pcie_res *pci_res)
{
    if (oal_warn_on(pci_res == NULL)) {
        return -OAL_ENODEV;
    }

    pci_res->regions.inited = 0;
    oam_warning_log0(0, OAM_SF_DPA, "disable_regions");
    return OAL_SUCC;
}

int32_t oal_pcie_enable_regions(pcie_res *pci_res)
{
    if (oal_warn_on(pci_res == NULL)) {
        return -OAL_ENODEV;
    }

    pci_res->regions.inited = 1;

    oam_warning_log0(0, OAM_SF_DPA, "enable_regions");
    return OAL_SUCC;
}

static void oal_pcie_dpa_regions_exit(pcie_res *pci_res)
{
    int32_t index;
    int32_t region_num;
    oal_pcie_region *region_base = NULL;
    oam_warning_log0(0, OAM_SF_DPA, "oal_pcie_dpa_regions_exit");
    pci_res->regions.inited = 0;

    region_num = pci_res->regions.region_nums;
    region_base = pci_res->regions.pst_regions;

    /* 释放申请的地址空间 */
    for (index = 0; index < region_num; index++, region_base++) {
        if (region_base->vaddr != NULL) {
            region_base->vaddr = NULL;
            region_base->paddr = 0;
        }
    }
}

int32_t oal_pcie_dpa_regions_init(pcie_res *pci_res)
{
    /* 初始化DEVICE 每个段分配的HOST物理地址，然后做remap */
    int32_t region_idx;
    int32_t region_num = pci_res->regions.region_nums;
    uint32_t bar_used_size = 0;
    oal_pcie_bar_info *bar_base = pci_res->regions.pst_bars;
    oal_pcie_region *region_base = pci_res->regions.pst_regions;

    if (oal_warn_on(pci_res->regions.inited)) {
        /* 不能重复初始化 */
        oam_error_log0(0, OAM_SF_DPA, "pcie dpa region already init");
        return -OAL_EBUSY;
    }

    /* 清空regions的特定字段 */
    for (region_idx = 0; region_idx < region_num; region_idx++, region_base++) {
        region_base->vaddr = NULL;  /* remap 后的虚拟地址 */
        region_base->paddr = 0x0;   /* DPA CPU看到的物理地址 */
        region_base->bus_addr = 0x0;
        region_base->size = region_base->pci_end - region_base->pci_start + 1;
    }

    region_base = pci_res->regions.pst_regions;

    for (region_idx = 0; region_idx < region_num; region_idx++, region_base++) {
        /* BAR可用的起始地址 */
        if (bar_base->start + bar_used_size + region_base->size - 1 > bar_base->end) {
            /* 这个BAR地址空间不足 */
            oam_error_log2(0, OAM_SF_DPA, "region_idx:%d, region_size:%u", region_idx, region_base->size);
            oam_error_log3(0, OAM_SF_DPA, "start:0x%x ,end:0x%x, used_size:0x%x",
                               (uint32_t)bar_base->start, (uint32_t)bar_base->end, bar_used_size);
            break;
        }

        region_base->paddr = bar_base->start + bar_used_size;
        /* remap */
        region_base->vaddr = oal_dpa_ioremap(region_base->paddr, region_base->size, region_base->flag);
        if (region_base->vaddr == NULL) {
            oam_error_log3(0, OAM_SF_DPA, "request mem region failed, addr:0x%x, size:%u, region_idx:%d",
                               (uint32_t)region_base->paddr, region_base->size, region_idx);
            return -OAL_EIO;
        }
        bar_used_size += region_base->size;
        oam_info_log3(0, OAM_SF_DPA, "region_idx:%d, region_paddr:0x%x, region_size:%u",
                      region_idx, (uint32_t)region_base->paddr, region_base->size);
    }

    if (region_idx < region_num) {
        /* 地址不够用 */
        oam_error_log2(0, OAM_SF_DPA, "bar space not enough, region: idx %d < num %d", region_idx, region_num);
        return -OAL_ENOMEM;
    }

    oam_info_log2(0, OAM_SF_DPA, "Total region num:%d, size:%u", region_num, bar_used_size);

    oal_pcie_enable_regions(pci_res);

    return OAL_SUCC;
}

/* 配置BAR,IATU等设备资源 */
int32_t oal_pcie_dpa_bar_res_init(pcie_res *pci_res, uint64_t bar_addr, uint32_t bar_size)
{
    int32_t ret;
    uint32_t region_num = 0;
    oal_pcie_region *region_base = NULL;

    pci_res->regions.pst_bars = &g_en_bar_tab[0];
    ret = pci_res->chip_info.cb.pcie_get_bar_region_info(pci_res, &region_base, &region_num);
    if (ret != OAL_SUCC) {
        return ret;
    }
    oam_info_log1(0, OAM_SF_DPA, "region_num:%d", region_num);

    pci_res->regions.pst_regions = region_base;
    pci_res->regions.region_nums = (int32_t)region_num;

    pci_res->regions.pst_bars->start = bar_addr;
    pci_res->regions.pst_bars->end = bar_addr + bar_size;
    pci_res->regions.pst_bars->size = bar_size;

    ret = oal_pcie_dpa_regions_init(pci_res);
    if (ret != OAL_SUCC) {
        return ret;
    }

    oal_pcie_change_link_state(pci_res, PCI_WLAN_LINK_MEM_UP);
    ret = oal_pcie_ctrl_base_address_init(pci_res);
    if (ret != OAL_SUCC) {
        oal_pcie_dpa_regions_exit(pci_res);
        return ret;
    }

    return OAL_SUCC;
}

int32_t oal_pcie_check_link_state(pcie_res *pst_pci_res)
{
    int32_t ret;
    pci_addr_map addr_map;
    uint32_t share_mem_address; /* Device cpu地址 */
    oal_pcie_res *pci_dpa_res = get_pcie_res();
    if (pci_dpa_res == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "pci_dpa_res is NULL");
        return OAL_FALSE;
    }

    ret = oal_pcie_inbound_ca_to_va(pst_pci_res, pst_pci_res->chip_info.addr_info.sharemem_addr, &addr_map);
    if (oal_unlikely(ret != OAL_SUCC)) {
        /* share mem 地址未映射! */
        oam_error_log1(0, OAM_SF_DPA, "can not found mem map for dev cpu address 0x%x\n",
                           pst_pci_res->chip_info.addr_info.sharemem_addr);
        return OAL_FALSE;
    }

    /* Get sharemem's dev_cpu address */
    share_mem_address = oal_readl(addr_map.va);
    if (share_mem_address == 0xFFFFFFFF) {
        oam_error_log0(0, OAM_SF_DPA, "pcie check_link_state fail");
        oal_pcie_change_link_state(pst_pci_res, PCI_WLAN_LINK_DOWN);
        oal_disable_pcie_irq(pci_dpa_res);
        return OAL_FALSE;
    }

    return OAL_TRUE;
}
