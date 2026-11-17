/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description:pcie_iatu_mp17c.c
 * Author: dpa drivers
 */
#include "oal_util.h"
#include "oal_types.h"
#include "pcie_host.h"
#include "chip/mp17c/pcie_soc_mp17c.h"
#include "oam_logger.h"
 
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_PCIE_IATU_MP17C_C

static oal_pcie_region g_pcie_dpa_regions[] = {
    {   .pci_start = 0x00200000,
        .pci_end   = 0x0031FFFF,
        .cpu_start = 0x00200000,
        .cpu_end   = 0x0031FFFF, /* 1152KB */
        .flag      = OAL_IORESOURCE_REG,
        .name      = "MP17C_ITCM"
    },
    {   .pci_start = 0x00400000,
        .pci_end   = 0x0048FFFF,
        .cpu_start = 0x00400000,
        .cpu_end   = 0x0048FFFF, /* 576KB */
        .flag      = OAL_IORESOURCE_REG,
        .name      = "MP17C_DTCM_S2"
    },
    {   .pci_start = 0x01200000,
        .pci_end   = 0x0132FFFF,
        .cpu_start = 0x01200000,
        .cpu_end   = 0x0132FFFF, /* 1216KB */
        .flag      = OAL_IORESOURCE_REG,
        .name      = "MP17C_BITCM"
    },
    {   .pci_start = 0x01400000,
        .pci_end   = 0x01451FFF,
        .cpu_start = 0x01400000,
        .cpu_end   = 0x01451FFF, /* 328KB */
        .flag      = OAL_IORESOURCE_REG,
        .name      = "MP17C_BDTCM"
    },
    {   .pci_start = 0x02200000,
        .pci_end   = 0x022BFFFF,
        .cpu_start = 0x02200000,
        .cpu_end   = 0x022BFFFF, /* 768KB */
        .flag      = OAL_IORESOURCE_REG,
        .name      = "MP17C_GFITCM"
    },
    {   .pci_start = 0x02400000,
        .pci_end   = 0x024C7FFF,
        .cpu_start = 0x02400000,
        .cpu_end   = 0x024C7FFF, /* 800KB */
        .flag      = OAL_IORESOURCE_REG,
        .name      = "MP17C_GFDTCM"
    },
    {   .pci_start = 0x03200000,
        .pci_end   = 0x03217FFF,
        .cpu_start = 0x03200000,
        .cpu_end   = 0x03217FFF, /* 96KB */
        .flag      = OAL_IORESOURCE_REG,
        .name      = "MP17C_COMRAM"
    },
    {   .pci_start = 0x04000000,
        .pci_end   = 0x041E3FFF,
        .cpu_start = 0x04000000,
        .cpu_end   = 0x041E3FFF, /* 1936KB */
        .flag      = OAL_IORESOURCE_REG,
        .name      = "MP17C_AON_WAPB"
    },
    {   .pci_start = 0x04900000,
        .pci_end   = 0x04985FFF,
        .cpu_start = 0x04900000,
        .cpu_end   = 0x04985FFF, /* 536KB */
        .flag      = OAL_IORESOURCE_REG,
        .name      = "MP17C_PCIE_WAPB"
    },
    {   .pci_start = 0x08000000,
        .pci_end   = 0x0808FFFF,
        .cpu_start = 0x08000000,
        .cpu_end   = 0x0808FFFF, /* 576KB */
        .flag      = OAL_IORESOURCE_REG,
        .name      = "MP17C_SHARE_MEM_S5"
    },
    {   .pci_start = 0x0061F000,
        .pci_end   = 0x00620FFF,
        .cpu_start = 0x0061F000,
        .cpu_end   = 0x00620FFF,
        .flag      = OAL_IORESOURCE_REG,
        .name      = "MP17C_DTCM_S1"
    },
};

int32_t oal_pcie_get_bar_region_info_mp17c(pcie_res *pst_pci_res, oal_pcie_region **region_base, uint32_t *region_num)
{
    oam_warning_log0(0, OAM_SF_DPA, "mp17c pcie dpa region init");

    *region_num = (uint32_t)oal_array_size(g_pcie_dpa_regions);
    *region_base = &g_pcie_dpa_regions[0];

    return OAL_SUCC;
}