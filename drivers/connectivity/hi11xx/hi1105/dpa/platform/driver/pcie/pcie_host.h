/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description:pcie_host.h
 * Author: dpa drivers
 */

#ifndef PCIE_HOST_H
#define PCIE_HOST_H

#include "oal_util.h"
#include "oal_mm.h"
#include "oal_net.h"
#include "oal_hardware.h"
#include "securec.h"
#include "ete_host.h"
#include "hcc_base.h"
#include "oam_logger.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_PCIE_HOST_H

#define PCIE_RX_TRANS_FLAG 0xbeafbeaf

#define PCIE_RX_RINGBUF_SUPPLY_ALL 0xFFFFFFFFUL

#define PCI_LOGLEVEL_FORMAT_LEN 4

#define OAL_PCIE_MIN_MPS 128

#define OAL_CONTINUOUS_LINK_UP_SUCC_TIMES 3

#define  PCIE_HISI_VENDOR_ID             (0x19e5)
#define  PCIE_HISI_VENDOR_ID_0           (0x19e7)
#define  PCIE_HISI_DEVICE_ID_MP17C       (0xa002)

#define hreg_set_val(regname, baseaddr) \
    oal_writel((regname).as_dword, ((void*)(uintptr_t)(baseaddr)))
#define hreg_get_val(regname, baseaddr) \
    (regname).as_dword = oal_readl(((void*)(uintptr_t)(baseaddr)))

/*
 * when deepsleep not S/R, pcie is PCI_WLAN_LINK_UP,
 * when deepsleep under S/R, pcie is PCI_WLAN_LINK_DOWN,
 * when down firmware , pcie is PCI_WLAN_LINK_MEM_UP,
 * after wcpu main func up device ready, pcie is PCI_WLAN_LINK_DMA_UP,
 * we can't access pcie ep's AXI interface when it's  power down,
 * cased host bus error
 */
typedef enum _pci_wlan_link_state_ {
    PCI_WLAN_LINK_DOWN = 0,  /* default state, PCIe not ready */
    PCI_WLAN_LINK_DEEPSLEEP, /* pcie linkdown, but soc sleep mode */
    PCI_WLAN_LINK_UP,        /* 物理链路已使能 */
    PCI_WLAN_LINK_MEM_UP,    /* IATU已经配置OK，可以访问AXI */
    PCI_WLAN_LINK_RES_UP,    /* RINGBUF OK */
    PCI_WLAN_LINK_WORK_UP,   /* 业务层可以访问PCIE */
    PCI_WLAN_LINK_BUTT
} pci_wlan_link_state;

typedef struct _pcie_callback_ {
    void (*pf_func)(void *para);
    void *para;
} pcie_callback_stru;

typedef struct _pcie_wlan_callback_group_ {
    pcie_callback_stru pcie_mac_2g_isr_callback;
    pcie_callback_stru pcie_mac_5g_isr_callback;
    pcie_callback_stru pcie_phy_2g_isr_callback;
    pcie_callback_stru pcie_phy_5g_isr_callback;
    pcie_callback_stru pcie_mac_common_isr_callback;
} pcie_wlan_callback_group_stru;

typedef struct _pcie_res__ pcie_res;

/* Ring Buff */
typedef union _dma_paddr_t_ {
    struct {
        uint32_t low_addr;
        uint32_t high_addr;
    } bits;
    uint64_t addr;
} dma_paddr_t;

typedef struct _pcie_cb_dma_res_ {
    dma_paddr_t paddr;
    uint32_t len;
    uint32_t tsf;
} pcie_cb_dma_res;

extern char *g_pcie_link_state_str[PCI_WLAN_LINK_BUTT + 1];

typedef struct _oal_pcie_region_ {
    void *vaddr;  /* virtual address after remap */
    uint64_t paddr; /* PCIe在Host侧分配到的物理地址 */

    uint64_t bus_addr; /* PCIe RC 发出的总线地址 */

    /* pci为PCI看到的地址和CPU看到的地址 每个SOC 大小和地址可能有差异 */
    /* device pci address */
    uint64_t pci_start;
    uint64_t pci_end;
    /* Device侧CPU看到的地址 */
    uint64_t cpu_start;
    uint64_t cpu_end;
    uint32_t size;

    uint32_t flag; /* I/O type,是否需要刷Cache */
    char *name; /* resource name */
} oal_pcie_region;

typedef struct _oal_pcie_bar_info_ {
    uint8_t bar_idx;
    uint64_t start; /* PCIe在Host分配空间的起始物理地址 */
    uint64_t end;
    uint32_t size;  /* PCIe在Host分配到的总物理地址大小 */
} oal_pcie_bar_info;

typedef struct _oal_pcie_regions_ {
    oal_pcie_region *pst_regions;
    int32_t region_nums; /* region nums */
    oal_pcie_bar_info *pst_bars;
    int32_t inited; /* 非0表示初始化过 */
} oal_pcie_regions;

typedef uint32_t  dev_caddr; /* device cpu address */

typedef struct _pcie_address_info_ {
    dev_caddr edma_ctrl; /* edma ctrl base address */
    dev_caddr pcie_ctrl; /* pcie ctrl base address */
    dev_caddr dbi; /* pcie config base address */
    dev_caddr ete_ctrl; /* pcie host ctrl address */
    dev_caddr glb_ctrl;
    dev_caddr pmu_ctrl;
    dev_caddr pmu2_ctrl;
    dev_caddr ch_sel;  /* sdio/pcie sel reg  */
    dev_caddr sharemem_addr; /* device reg1 */
    dev_caddr boot_version;  /* bootloader version */
    dev_caddr boot_sharemem; /* bootloader pcie share memory存储地址 */
} pcie_address_info;

typedef int32_t (*pcie_chip_func)(pcie_res *, int32_t);
typedef struct _pcie_chip_id_stru_ {
    int32_t device_id;
    pcie_chip_func func;
} pcie_chip_id_stru;

typedef struct _pcie_chip_cb_ {
    int32_t (*pcie_host_slave_address_switch)(pcie_res *, uint64_t, uint64_t*, int32_t);
    int32_t (*pcie_get_bar_region_info)(pcie_res *, oal_pcie_region **, uint32_t *);
    void (*ete_address_init)(pcie_res *);
    int32_t (*ete_intr_init)(pcie_res *);
} pcie_chip_cb;

typedef struct _pci_addr_map__ {
    /* unsigned long 指针长度和CPU位宽等长 */
    uintptr_t va; /* 虚拟地址 */
    uintptr_t pa; /* 物理地址 */
} pci_addr_map;

typedef struct _pcie_chip_info_ {
    pcie_address_info addr_info;
    pcie_chip_cb  cb; // callback functions
} pcie_chip_info;

typedef struct _oal_pcie_trans_stat_ {
    uint32_t intx_total_count;
    uint32_t intx_tx_count;
    uint32_t intx_rx_count;
    uint32_t done_err_cnt;
    uint32_t h2d_doorbell_cnt;
    uint32_t d2h_doorbell_cnt;
} oal_pcie_trans_stat;

struct _pcie_res__ {
    uint32_t device;

    void *data;      /* callback pointer */
    uint32_t revision; /* ip version */

    pci_wlan_link_state link_state;

    oal_pcie_trans_stat stat;

    /* 根据Soc设计信息表刷新，不同的产品划分不一样, iATU必须对每个region分别映射 */
    oal_pcie_regions regions; /* Device地址划分, pa由A核同步，VA在dpa重新初始化 */
    oal_mutex_stru st_rx_mem_lock;

    /* PCIe Device 寄存器基地址,Host Virtual Address */
    void *pst_pci_ctrl_base;
    void *pst_ete_base;

    pcie_chip_info chip_info;
    pcie_ete_res ete_info;
};

typedef enum _pcie_ep_ip_status_ {
    PCIE_EP_IP_POWER_DOWN = 0,
    PCIE_EP_IP_POWER_UP
} pcie_ep_ip_status;

typedef struct _oal_pcie_res__ {
    uint32_t version;  /* pcie version */
    uint32_t revision; /* 1:4.7a  , 2:5.00a */
    uint32_t irq_stat; /* 0:enabled, 1:disabled */
    uint32_t irq_num;
    uint32_t l1_err_cnt;
    pcie_res *pst_pci_res;

    oal_atomic  refcnt; /* for dual interface */
    int32_t     pci_cnt; /* pcie ip count */

    pcie_ep_ip_status power_status;
} oal_pcie_res;

OAL_STATIC OAL_INLINE oal_netbuf_stru *oal_pcie_rx_netbuf_alloc(uint32_t ul_size)
{
    oal_netbuf_stru *netbuf = NULL;
    netbuf = hcc_netbuf_alloc(HCC_LONG_PACKAGE_SIZE);
    if (netbuf == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "pcie rx data alloc fail");
        return NULL;
    }

    if (oal_netbuf_len(netbuf) + HCC_HDR_TOTAL_LEN < ul_size) {
        oam_error_log0(0, OAM_SF_DPA, "pcie rx buf not enough");
        hcc_netbuf_free(netbuf);
        return NULL;
    }

    return netbuf;
}

OAL_STATIC OAL_INLINE char *oal_pcie_get_link_state_str(pci_wlan_link_state link_state)
{
    if (oal_warn_on(link_state > PCI_WLAN_LINK_BUTT)) {
        oam_warning_log1(0, OAM_SF_DPA, "invalid link_state:%d", link_state);
        return (char *)"overrun";
    }

    if (g_pcie_link_state_str[link_state] == NULL) {
        return (char *)"unkown";
    }

    return g_pcie_link_state_str[link_state];
}

void pcie_ete_rx_sched_transfer(uint32_t event);
uint32_t pcie_ete_get_rx_event(void);
int32_t oal_pcie_check_link_state(pcie_res *pst_pci_res);
int32_t oal_pcie_dpa_bar_res_init(pcie_res *pci_res, uint64_t bar_addr, uint32_t bar_size);
int32_t oal_pcie_enable_regions(pcie_res *pci_res);
int32_t oal_pcie_disable_regions(pcie_res *pci_res);
void oal_pcie_release_rx_netbuf(pcie_res *pci_res, oal_netbuf_stru *netbuf);
void oal_pcie_tx_netbuf_free(pcie_res *pci_res, oal_netbuf_stru *netbuf);
int32_t oal_pcie_host_slave_address_switch(pcie_res *pst_pci_res, uint64_t src_addr,
                                           uint64_t* dst_addr, int32_t is_host_iova);
int32_t oal_ete_host_init(pcie_res *pst_pci_res);
void oal_ete_host_exit(pcie_res *pst_pci_res);
void oal_ete_ip_exit(pcie_res *pst_pci_res);
int32_t oal_ete_ip_init(pcie_res *pst_pci_res);
int32_t oal_pcie_transfer_ete_done(pcie_res *pst_pci_res);

int32_t oal_ete_transfer_res_init(pcie_res *pst_pci_res);
void oal_ete_transfer_res_exit(pcie_res *pst_pci_res);

int32_t oal_ete_send_netbuf_list(pcie_res *pst_pci_res, oal_netbuf_head_stru *pst_head,
                                 hcc_netbuf_queue_type_t qtype);
int32_t oal_ete_rx_ringbuf_build(pcie_res *pst_pci_res);
int32_t oal_pcie_ete_tx_is_idle(pcie_res *pst_pci_res, hcc_netbuf_queue_type_t qtype);
int32_t ete_rx_thread_create(void);
void ete_rx_thread_destory(void);

int32_t oal_ete_sleep_request_host_check(pcie_res *pci_res);
int32_t oal_ete_host_pending_signal_check(pcie_res *pci_res);
int32_t oal_ete_host_pending_signal_process(pcie_res *pci_res);

/* PCIE EP Slave 口看到的地址转换 --片内外设通过PCIE访问主芯片DDR空间
 * PCIE EP Slave 口访问, 片内IP 访问HOST DDR
 * 地址转换主芯片的DDR设备地址转换成device的SLAVE口地址
 *  注意这里的DDR设备地址(iova)不是直接的物理地址，而是对应Kernel的DMA地址
 *  设备地址不能通过phys_to_virt/virt_to_phys直接转换
 */
int32_t pcie_if_hostca_to_devva(uint32_t ul_chip_id, uint64_t host_iova, uint64_t* addr);
int32_t pcie_if_devva_to_hostca(uint32_t ul_chip_id, uint64_t devva, uint64_t* addr);
uint8_t oal_pcie_link_state_up(uint8_t dev_id);
/* PCIE EP Master口看到的地址转换 --主芯片外设(CPU)通过PCIE访问片内IP(RAM+寄存器) */
int32_t oal_pcie_devca_to_hostva(uint32_t ul_chip_id, uint64_t dev_cpuaddr, uint64_t *host_va);
int32_t oal_pcie_get_dev_ca(uint32_t ul_chip_id, void *host_va, uint64_t* dev_cpuaddr);
int32_t oal_pcie_inbound_ca_to_va(pcie_res *pci_res, uint64_t dev_cpuaddr, pci_addr_map *addr_map);
int32_t oal_pcie_inbound_va_to_ca(pcie_res *pci_res, uint64_t host_va, uint64_t *dev_cpuaddr);

int32_t pcie_wlan_func_register(pcie_wlan_callback_group_stru *p_func);
// for hcc bus ops
int32_t oal_pcie_rx_netbuf(hcc_bus_t *pst_bus, oal_netbuf_head_stru *pst_head);
void oal_pcie_ete_bus_ops_init(hcc_bus_t *pst_bus);
oal_pcie_res *get_pcie_res(void);

OAL_STATIC OAL_INLINE void oal_pcie_change_link_state(pcie_res *pst_pci_res, pci_wlan_link_state link_state_new)
{
    if (pst_pci_res->link_state != link_state_new) {
        oam_warning_log2(0, OAM_SF_DPA, "link_state change from %d to %d",
                         pst_pci_res->link_state, link_state_new);
    } else {
        oam_warning_log1(0, OAM_SF_DPA, "link_state still %d", link_state_new);
    }

    pst_pci_res->link_state = link_state_new;
}
#endif
