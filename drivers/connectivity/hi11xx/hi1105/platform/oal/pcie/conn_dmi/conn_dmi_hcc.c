/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: dmi消息驱动适配
 * Author: platform drivers
 */
#ifdef _PRE_PLAT_FEATURE_DPA
#define MPXX_LOG_MODULE_NAME "[PCIE_EICC_H]"
#define HISI_LOG_TAG           "[PCIE_EICC]"
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/err.h>
#include <linux/workqueue.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/pci.h>
#include <linux/list.h>
#include "board.h"
#include "plat_pm.h"
#endif
#include "oal_util.h"
#include "oal_net.h"
#include "oal_ext_if.h"
#include "oam_wdk.h"
#include "hisi_ini.h"
#include "oal_thread.h"
#include "plat_exception_rst.h"
#include "oam_ext_if.h"
#include "pcie_host.h"
#include "pcie_linux.h"
#include "mp16/pcie_ctrl_rb_regs.h"
#include "pcie_firmware_msg.h"
#include "pcie_rc_port.h"
#include "oal_hcc_host_if.h"
#include "oal_circ_queue.h"
#include "oal_schedule.h"
#include "oal_util.h"
#include "board_dpa.h"
#include "oal_mm.h"
#include "oal_hcc_comm.h"
#include "oal_circ_queue.h"
#include "conn_dmi_hal.h"
#include "conn_dmi_msg.h"
#include "conn_dmi_hcc.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_CONN_DMI_HCC_C

#define HCC_TRANS_QUEUE_DEPTH 128
#define DMI_RECV_THERAD_PRIORITY 10
#define WIFI_POWERUP_DONE_TIMEOUT 2000
#define HOST_WAIT_DEV_DELAY_TIMEOUT 5000
#define WIFI_WAKEUP_COMPLETE_TIMEOUT 6000 // 6ms

#pragma pack(1)
// hcc_trans 结构体: 用于AP<->DPA之间HCC数据交互
struct dmi_hcc_inter_data_stru {
    uint64_t payload_addr;          // 保存MAA首地址(不受offset影响, MAA地址块128字节位置)
    uint16_t payload_len;           // 保存MAA数据长度(申请长度 + offset偏移)
    uint8_t hcc_qtype;
    uint8_t resv;
    uint64_t head_addr;             // 保存headroom的地址(MAA地址块0字节位置)
    uint64_t head_len;              // 保存headroom的长度(128字节预留长度 + offset偏移)
    uint8_t hcc_hdr[HCC_HDR_TOTAL_LEN];
};
#pragma pack()

typedef struct {
    uint32_t state;
    hcc_bus *hcc_bus;
    struct task_struct *dmi_recv_thread;
    oal_wait_queue_head_stru dmi_recv_transfer_wq;
    oal_circ_queue_t hcc_process_queue;
    void *hcc_process_node;
    uint64_t hcc_rx_count;
    uint64_t hcc_tx_count;
} hcc_dmi_mng_str;

static hcc_dmi_mng_str g_hcc_dmi_mng;
oal_atomic g_dpa_sbuf_switch;
static oal_atomic g_dpa_dmi_state;

static oal_completion dpa_ete_rx_supply_done;
static oal_completion dpa_ete_powerdown_done;
static oal_completion dpa_ete_powerup_done;

void dmi_recv_sched_transfer(void);

int32_t dpa_sbuf_flowctrl_on(uint8_t* buf, uint8_t buf_len)
{
    oal_io_print("dpa_sbuf_flowctrl_on\n");
    oal_atomic_set(&g_dpa_sbuf_switch, 1);
    return 0;
}

int32_t dpa_sbuf_flowctrl_off(uint8_t* buf, uint8_t buf_len)
{
    oal_io_print("dpa_sbuf_flowctrl_off\n");
    oal_atomic_set(&g_dpa_sbuf_switch, 0);
    hcc_sched_transfer(hcc_get_handler(HCC_EP_WIFI_DEV));
    return 0;
}

int32_t dpa_sbuf_alloc_fail(uint8_t* buf, uint8_t buf_len)
{
    uint32_t alloc_cnt_fail = 0;
    if ((buf != NULL) && (buf_len >= sizeof(uint32_t))) {
        alloc_cnt_fail = *(uint32_t *)buf;
        oam_error_log1(0, OAM_SF_ANY, "dmi_rx alloc sbuf fail cnt %d\n", alloc_cnt_fail);
    }
    declare_dft_trace_key_info("dmi_rx alloc sbuf fail", OAL_DFT_TRACE_EXCEP);
    return 0;
}

/* wether the hcc flow ctrl queues have data. */
OAL_STATIC int32_t oal_dmi_tx_condition(hcc_bus *pst_bus, hcc_netbuf_queue_type qtype)
{
    oal_print_mpxx_log(MPXX_LOG_DBG, "g_dpa_sbuf_switch %d", g_dpa_sbuf_switch);
    if (oal_atomic_read(&g_dpa_sbuf_switch) == 1) {
        return OAL_FALSE;
    }
    return OAL_TRUE;
}

OAL_STATIC int32_t oal_get_dmi_state(void)
{
    oal_print_mpxx_log(MPXX_LOG_DBG, "g_dpa_dmi_state %d", g_dpa_dmi_state);
    if (oal_atomic_read(&g_dpa_dmi_state) == 0) {
        return OAL_FALSE;
    }
    return OAL_TRUE;
}

OAL_STATIC void oal_enable_dmi_state(hcc_bus *pst_bus, uint32_t mask)
{
    oal_atomic_set(&g_dpa_dmi_state, 1);
    oal_print_mpxx_log(MPXX_LOG_INFO, "oal_enable_dmi_state");
}

OAL_STATIC void oal_disable_dmi_state(hcc_bus *pst_bus, uint32_t mask)
{
    oal_atomic_set(&g_dpa_dmi_state, 0);
    oal_print_mpxx_log(MPXX_LOG_INFO, "oal_disable_dmi_state");
}

static int32_t dmi_send_para_check(oal_netbuf_stru *netbuf)
{
    uint16_t buf_len = 0;

    if (netbuf == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi_send_para_check param check fail\n");
        return -OAL_FAIL;
    }

    buf_len = oal_netbuf_len(netbuf);
    if (buf_len <= HCC_HDR_TOTAL_LEN || buf_len > NETBUF_MAXLEN) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "oal netbuf len %u invalid\n", buf_len);
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

uint64_t conn_dmi_hcc_get_rx_count(void)
{
    return g_hcc_dmi_mng.hcc_rx_count;
}

/*
 * 函 数 名  : conn_dmi_hcc_send
 * 功能描述  : conn dmi发送hcc消息接口
 */
int32_t conn_dmi_hcc_send(oal_netbuf_stru *netbuf, uint8_t qtype)
{
    struct dmi_hcc_inter_data_stru *hcc_data = NULL;
    uint64_t buf_maa = 0;
    void *buf_maa_phy = NULL;
    int32_t ret;

    /* 入参检查 */
    if (dmi_send_para_check(netbuf) != OAL_SUCC) {
        return -OAL_FAIL;
    }

    // A核按照最大的内存申请，不足往后使用最多24字节
    buf_maa = external_dpa_data_alloc_ops(MAA_ALLOC_MAXLEN);
    if ((void *)buf_maa == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "maa malloc fail\n");
        return -OAL_FAIL;
    }

    buf_maa_phy = external_dpa_data_phys_to_virt_ops(buf_maa);
    if (memcpy_s((buf_maa_phy - HCC_HDR_TOTAL_LEN), (HCC_HDR_TOTAL_LEN + MAA_ALLOC_MAXLEN + MAA_DATA_TAIL_RESV_LEN),
                 (void *)(oal_netbuf_data(netbuf)), oal_netbuf_len(netbuf)) != EOK) {
        external_dpa_data_free_ops(buf_maa); // maa内存释放
        oal_print_mpxx_log(MPXX_LOG_ERR, "tx maa buff write failed\n");
        return -OAL_FAIL;
    }

    hcc_data = (struct dmi_hcc_inter_data_stru *)conn_dmi_hal_alloc_buf(sizeof(struct dmi_hcc_inter_data_stru));
    if (hcc_data == NULL) {
        return -OAL_ENOMEM;
    }

    if (memcpy_s(hcc_data->hcc_hdr, HCC_HDR_TOTAL_LEN, oal_netbuf_data(netbuf), HCC_HDR_TOTAL_LEN) != EOK) {
        conn_dmi_hal_free_buf((uint8_t *)hcc_data);
        external_dpa_data_free_ops(buf_maa); // maa内存释放
        oal_print_mpxx_log(MPXX_LOG_ERR, "hcc_head memcopy fail\n");
        return -OAL_FAIL;
    }

    hcc_data->payload_addr = buf_maa;
    hcc_data->payload_len = oal_netbuf_len(netbuf) - HCC_HDR_TOTAL_LEN;
    hcc_data->head_addr = buf_maa - HCC_HDR_TOTAL_LEN;
    hcc_data->head_len = HCC_HDR_TOTAL_LEN;

    ret = conn_dmi_hal_send(DMI_HAL_TYPE_HCC, (uint8_t *)hcc_data, sizeof(struct dmi_hcc_inter_data_stru));
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi hcc send fail");
        conn_dmi_hal_free_buf((uint8_t *)hcc_data);
        external_dpa_data_free_ops(buf_maa);
        return ret;
    }

    conn_dmi_hal_free_buf((uint8_t *)hcc_data);
    return OAL_SUCC;
}

static inline void conn_hcc_dmi_rx_fail(struct dmi_hcc_inter_data_stru *hcc_data)
{
    struct hcc_header *hcc_hdr = NULL;
    oam_error_log1(0, OAM_SF_ANY, "hcc dmi rx para check fail, payload_len = %d", hcc_data->payload_len);
    if (hcc_data->head_addr != 0 && hcc_data->head_len >= sizeof(struct hcc_header)) {
        hcc_hdr = (struct hcc_header *)external_dpa_data_phys_to_virt_ops(hcc_data->head_addr);
        oam_error_log3(0, OAM_SF_ANY, "invaild hcc rx head, main_type[%d] sub_type[%d] pay_len[%d]", \
                       hcc_hdr->main_type, hcc_hdr->sub_type, hcc_hdr->pay_len);
    }
}

static inline int32_t conn_hcc_dmi_rx_check(struct dmi_hcc_inter_data_stru *hcc_data, uint16_t buf_len)
{
    if (buf_len != (uint16_t)(sizeof(struct dmi_hcc_inter_data_stru))) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "hcc dmi rx len %u invalid", buf_len);
        return -OAL_FAIL;
    }

    if (hcc_data->payload_addr == 0 || hcc_data->payload_len == 0 ||
        hcc_data->head_addr == 0 || hcc_data->head_len == 0) {
        conn_hcc_dmi_rx_fail(hcc_data);
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

static int32_t conn_dmi_hcc_rx(uint8_t *buf, uint16_t buf_len)
{
    struct dmi_hcc_inter_data_stru *dmi_ptr = NULL;
    if (buf == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "request_hcc_cb_process param check fail");
        return -OAL_FAIL;
    }
    g_hcc_dmi_mng.hcc_rx_count++;
    dmi_ptr = (struct dmi_hcc_inter_data_stru *)buf;

    if (conn_hcc_dmi_rx_check(dmi_ptr, buf_len) != OAL_SUCC) {
        external_dpa_data_free_ops(dmi_ptr->payload_addr);
        return -OAL_FAIL;
    }

    if (oal_circ_queue_enqueue(&g_hcc_dmi_mng.hcc_process_queue, (uintptr_t)dmi_ptr) != OAL_SUCC) {
        external_dpa_data_free_ops(dmi_ptr->payload_addr);
        oal_print_mpxx_log(MPXX_LOG_ERR, "request_hcc_cb_process oal_circ_queue_enqueue fail, size = %u", \
                           oal_circ_queue_size(&g_hcc_dmi_mng.hcc_process_queue));
    }

    dmi_recv_sched_transfer();
    return OAL_SUCC;
}

static int32_t conn_dmi_hcc_rx_err(uint8_t *buf, uint16_t buf_len)
{
    struct dmi_hcc_inter_data_stru *hcc_data = (struct dmi_hcc_inter_data_stru *)buf;

    if (conn_hcc_dmi_rx_check(hcc_data, buf_len) != OAL_SUCC) {
        return -OAL_FAIL;
    }

    oal_print_mpxx_log(MPXX_LOG_ERR, "hcc dmi rx err, buf_len = %d", buf_len);
    external_dpa_data_free_ops(hcc_data->payload_addr);
    return OAL_SUCC;
}

static void oal_dmi_dpa_ete_thread_sched(void)
{
    conn_dmi_single_msg_send(CONN_DMI_MSG_ETE_THREAD_SCHED);
}

#define MAX_RX_CHECK_CNT 500
int32_t oal_dmi_sleep_wait_ete_rx_trans_done(oal_pcie_res *pst_pci_res)
{
    int32_t curr_cnt;
    int32_t ret;

    for (curr_cnt = 0; curr_cnt < MAX_RX_CHECK_CNT; curr_cnt++) {
        mutex_lock(&pst_pci_res->st_rx_mem_lock);
        ret = oal_ete_sleep_request_rx_queue_check(pst_pci_res);
        mutex_unlock(&pst_pci_res->st_rx_mem_lock);
        if (oal_likely(ret == OAL_SUCC)) {
            return OAL_SUCC;
        } else if (ret == -OAL_EBUSY) {
            oal_dmi_dpa_ete_thread_sched();
            oal_msleep(5);  /* 若当前还未传输完成，则触发调度后等待5ms再做检查 */
            continue;
        } else {
            break;
        }
    }
    return -OAL_EFAIL;
}

static int32_t conn_dmi_rx_queue_process(hcc_dmi_mng_str *dmi_mng)
{
    struct dmi_hcc_inter_data_stru *cur_dmi = NULL;
    oal_netbuf_stru *netbuf = NULL;
    uint8_t *hcc_head = NULL;
    uint16_t idx = 0;
    void *used_head_addr = NULL;
    uint16_t queue_size = oal_circ_queue_size(&dmi_mng->hcc_process_queue);
    for (idx = 0; idx < queue_size; idx++) {
        cur_dmi = (struct dmi_hcc_inter_data_stru *)oal_circ_queue_head(&dmi_mng->hcc_process_queue);
        if (cur_dmi == NULL) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "cur_dmi is empty");
            return -OAL_FAIL;
        }
        netbuf = hcc_netbuf_alloc((cur_dmi->payload_len + HCC_HDR_TOTAL_LEN));
        if (netbuf == NULL) {
            oal_print_mpxx_log(MPXX_LOG_ERR, "hcc_netbuf_alloc fail");
            return -OAL_ENOMEM;
        }
        hcc_head = (uint8_t *)oal_netbuf_data(netbuf);
        used_head_addr = external_dpa_data_phys_to_virt_ops(cur_dmi->head_addr);
        if (memcpy_s(hcc_head, (cur_dmi->payload_len + HCC_HDR_TOTAL_LEN),
                     (void *)(used_head_addr), (cur_dmi->payload_len + HCC_HDR_TOTAL_LEN)) != EOK) {
            oal_netbuf_free(netbuf);
            oal_print_mpxx_log(MPXX_LOG_ERR, "conn_dmi_rx_queue_process hcc hdr memcpy_s fail");
            return -OAL_FAIL;
        }
        oal_netbuf_put(netbuf, (cur_dmi->payload_len + HCC_HDR_TOTAL_LEN));
        hcc_rx_submit(hbus_to_hcc(dmi_mng->hcc_bus), netbuf);
        hcc_sched_transfer(hbus_to_hcc(dmi_mng->hcc_bus));
        oal_circ_queue_dequeue(&dmi_mng->hcc_process_queue);
        external_dpa_data_free_ops(cur_dmi->payload_addr);
    }
    return OAL_SUCC;
}

void dmi_recv_sched_transfer(void)
{
    oal_wait_queue_wake_up_interrupt(&g_hcc_dmi_mng.dmi_recv_transfer_wq);
}

OAL_STATIC int32_t dmi_recv_thread_wait_event_cond_check(hcc_dmi_mng_str *dmi_mng_str)
{
    if (dmi_mng_str == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "%s error: dmi_mng_str is null", __FUNCTION__);
        return OAL_FALSE;
    }

    if (oal_circ_queue_size(&dmi_mng_str->hcc_process_queue) == 0) {
        return OAL_FALSE;
    }

    return OAL_TRUE;
}

static int32_t dmi_recv_thread(void *data)
{
    hcc_dmi_mng_str *dmi_mng_str = (hcc_dmi_mng_str *)data;
    int32_t ret;

    if (dmi_mng_str == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "%s data is null", __FUNCTION__);
        return -OAL_FAIL;
    }

    allow_signal(SIGTERM);
    oal_print_mpxx_log(MPXX_LOG_DBG, "%s thread start", oal_get_current_task_name());
    forever_loop() {
        ret = oal_wait_event_interruptible_m(dmi_mng_str->dmi_recv_transfer_wq,
                                             (dmi_recv_thread_wait_event_cond_check(dmi_mng_str) == OAL_TRUE) ||
                                             oal_kthread_should_stop());
        if (oal_unlikely(ret == -ERESTARTSYS)) {
            oal_io_print("wifi task %s was interrupted by a signal\n", oal_get_current_task_name());
            break;
        }
        if (oal_unlikely(oal_kthread_should_stop())) {
            oal_io_print("dmi recv transfer thread leave\n");
            break;
        }
        conn_dmi_rx_queue_process(dmi_mng_str);
    }
    oal_print_mpxx_log(MPXX_LOG_DBG, "%s thread stop", oal_get_current_task_name());
    return 0;
}

static int32_t conn_dmi_hcc_tx_netbuf(hcc_bus *bus, oal_netbuf_head_stru *queue, hcc_netbuf_queue_type qtype)
{
    int32_t ret;
    oal_netbuf_stru *netbuf;
    uint32_t total = 0;
    if (bus == NULL || queue == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "conn_dmi_hcc_tx_netbuf param check fail");
        return -OAL_FAIL;
    }
    if (oal_netbuf_list_len(queue) == 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "conn_dmi_hcc_tx_netbuf netbuf queue is empty");
        return -OAL_FAIL;
    }

    if (oal_get_dmi_state() != OAL_TRUE) { // dmi_state 关闭状态下直接释放netbuf
        oal_print_mpxx_log(MPXX_LOG_DBG, "dmi_state is off");
        netbuf = oal_netbuf_delist(queue);
        hcc_tx_netbuf_free(netbuf);
        return total;
    }

    if (oal_dmi_tx_condition(bus, qtype) != OAL_TRUE) {
        oal_print_mpxx_log(MPXX_LOG_DBG, "conn_dmi_hcc_tx_netbuf flow ctrl on");
        return total;
    }

    /* 发送唤醒 */
    if (oal_unlikely(OAL_SUCC != hcc_bus_pm_wakeup_device(bus))) {
        oal_msleep(100); /* wakeup failed, wait 100ms block the send thread */
        return total;
    }

    g_hcc_dmi_mng.hcc_tx_count++;
    netbuf = oal_netbuf_delist(queue);
    ret = conn_dmi_hcc_send(netbuf, qtype);
    if (ret != OAL_SUCC) {
        oal_netbuf_addlist(queue, netbuf);
    } else {
        hcc_tx_netbuf_free(netbuf);
        total++;
    }
    hcc_sched_transfer(hbus_to_hcc(g_hcc_dmi_mng.hcc_bus));
    return total;
}

int32_t oal_dmi_host_init(oal_pcie_res *pst_pci_res)
{
    if (pst_pci_res->chip_info.dmi_support != OAL_TRUE) {
        return OAL_SUCC;
    }
    if (conn_dmi_drv_init() != OAL_SUCC) {
        return OAL_FAIL;
    }
    return OAL_SUCC;
}

static int32_t oal_dmi_ete_supply_ack(uint8_t type, void *priv)
{
    oal_complete(&dpa_ete_rx_supply_done);
    return 0;
}

static int32_t oal_dmi_notify_dpa_ete_supply(void)
{
    int32_t ret;
    oal_init_completion(&dpa_ete_rx_supply_done);
    conn_sync_dmi_single_ack_msg_send(CONN_DMI_MSG_ETE_RX_SUPPLY, oal_dmi_ete_supply_ack, NULL);
    ret = oal_wait_for_completion_timeout(&dpa_ete_rx_supply_done, (uint32_t)oal_msecs_to_jiffies(MSEC_PER_SEC));
    if (ret == 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "oal_dmi_notify_dpa_ete_supply wait completion fail !\n");
        return -OAL_EFAIL;
    }
    oal_print_mpxx_log(MPXX_LOG_INFO, "oal_dmi_notify_dpa_ete_supply done %d\n", ret);
    return OAL_SUCC;
}

OAL_STATIC int32_t oal_pcie_dmi_wakeup_complete(hcc_bus *pst_bus)
{
    ktime_t start_time, end_time, trans_time;
    unsigned long long total_time;
    oal_pcie_linux_res *pst_pci_lres;
    oal_pcie_res *pst_pci_res;
    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;

    if (oal_warn_on(pst_pci_lres == NULL)) {
        oal_io_print("pst_pci_lres is null\n");
        return -OAL_EINVAL;
    }
    start_time = ktime_get();
    pst_pci_res = pst_pci_lres->pst_pci_res;
    mutex_lock(&pst_pci_res->st_rx_mem_lock);
    oal_pcie_change_link_state(pst_pci_res, PCI_WLAN_LINK_WORK_UP);
    oal_pcie_device_sr_debug(pst_pci_res, OAL_FALSE);
    mutex_unlock(&pst_pci_res->st_rx_mem_lock);

    if (g_pcie_auto_disable_aspm != 0) {
        /* disable L1 after wakeup */
        oal_pcie_set_device_aspm_dync_disable(pst_pci_res, OAL_TRUE);
        oal_pcie_device_xfer_pending_sig_clr(pst_pci_res, OAL_FALSE);
    }

    oal_dmi_notify_dpa_ete_supply();

    end_time = ktime_get();
    trans_time = ktime_sub(end_time, start_time);
    total_time = (unsigned long long)ktime_to_us(trans_time);
    pci_print_log(PCI_LOG_WARN, "consume %llu us", total_time);
    if (total_time > WIFI_WAKEUP_COMPLETE_TIMEOUT) {
        pci_print_log(PCI_LOG_INFO, "oal_pcie_dmi_wakeup_complete long_time");
        declare_dft_trace_key_info("oal_pcie_dmi_wakeup_complete long_time", OAL_DFT_TRACE_OTHER);
        // device侧异常未切换auxclk时钟, 在此补救
        oal_pcie_device_auxclk_switch(pst_pci_res, AUXCLK_TCXO);
    }

    return OAL_SUCC;
}

// 函数未注册返错误, dmi不检测需返回成功
OAL_STATIC int32_t oal_dmi_sleep_request_host(hcc_bus *pst_bus)
{
    return OAL_SUCC;
}

OAL_STATIC int32_t oal_dmi_poweroff_pre(hcc_bus *pst_bus)
{
    int32_t ret;
    oal_pcie_linux_res *pst_pci_lres;
    oal_pcie_res *pst_pci_res = NULL;

    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_ENODEV;
    }
    pst_pci_res = pst_pci_lres->pst_pci_res;
    if (pst_pci_res->chip_info.cb.pcie_poweroff_pre == NULL) {
        return -OAL_ENODEV;
    }

    if (oal_unlikely(pst_pci_res->link_state < PCI_WLAN_LINK_MEM_UP)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "int link invaild, link_state:%s",
                           oal_pcie_get_link_state_str((pst_pci_res->link_state)));
        return -OAL_ENODEV;
    }

    /* device收到下电消息后会关闭clkpll, 此时若业务mac中断未处理完可能会导致dev总线挂死，故先屏蔽intx中的业务中断 */
    ret = pst_pci_res->chip_info.cb.pcie_poweroff_pre(pst_pci_res);
    if (ret != OAL_SUCC) {
        return ret;
    }

    return OAL_SUCC;
}

OAL_STATIC int32_t oal_pcie_dmi_poweroff_complete(hcc_bus *pst_bus)
{
    uint32_t i, timeout_cnt;
    int32_t ret;
    oal_pcie_linux_res *pst_pci_lres;
    oal_pcie_res *pst_pci_res = NULL;

    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_ENODEV;
    }
    pst_pci_res = pst_pci_lres->pst_pci_res;
    if (pst_pci_res->chip_info.cb.pcie_poweroff_complete == NULL) {
        return -OAL_ENODEV;
    }

    /* :device下电关闭pll, 异常上报的mac中断会导致pcie异常;因此, 首先屏蔽中断 */
    if (pst_pci_res->pst_pci_ctrl_base == NULL) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "pst_pci_ctrl_base is null");
        return -OAL_ENODEV;
    }
    if (oal_unlikely(pst_pci_res->link_state < PCI_WLAN_LINK_MEM_UP)) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "int link invaild, link_state:%s",
                           oal_pcie_get_link_state_str((pst_pci_res->link_state)));
        return -OAL_ENODEV;
    }

    /* :20dbm可能存在较长时间占用信号量，wifi等待时间增加 */
    timeout_cnt = hi110x_get_emu_timeout(ACK_CHECK_MAX_CNT);
    ret = -OAL_EFAIL;
    for (i = 0; i < timeout_cnt; i++) {
        msleep(ACK_CHECK_WAIT_TIME);
        ret = pst_pci_res->chip_info.cb.pcie_poweroff_complete(pst_pci_res);
        if (ret == OAL_SUCC || ret == -OAL_ENODEV) {
            break;
        }
    }

    return ret;
}

OAL_STATIC OAL_INLINE void oal_dmi_bus_power_down(oal_pcie_linux_res *pst_pci_lres, hcc_bus *pst_bus)
{
    pcie_bus_power_down_action(pst_bus);
}

OAL_STATIC OAL_INLINE int32_t oal_dmi_bus_power_up(oal_pcie_linux_res *pst_pci_lres, hcc_bus *pst_bus)
{
    int32_t ret = OAL_SUCC;
    /* 上电之前打开PCIE HOST 控制器 */

    declare_time_cost_stru(cost);
    oal_get_time_cost_start(cost);

    pst_pci_lres->l1_err_cnt = 0;
    ret = oal_pcie_pm_control(pst_pci_lres->pst_pcie_dev,
                              oal_pcie_get_pcie_rc_idx(pst_pci_lres->pst_pcie_dev), PCIE_POWER_ON);
    if (g_pcie_print_once) {
        g_pcie_print_once = 0;
        ssi_dump_device_regs(SSI_MODULE_MASK_COMM | SSI_MODULE_MASK_PCIE_CFG | SSI_MODULE_MASK_PCIE_DBI |
                             SSI_MODULE_MASK_WCTRL | SSI_MODULE_MASK_BCTRL);
    }

    oal_pcie_power_notifiy_register(pst_pci_lres->pst_pcie_dev,
                                    oal_pcie_get_pcie_rc_idx(pst_pci_lres->pst_pcie_dev), NULL, NULL, NULL);
    if (ret) {
        oal_io_print("pcie power on and link failed, ret=%d\n", ret);
        pcie_linkup_fail_fixup(0);
        (void)ssi_dump_err_regs(SSI_ERR_PCIE_POWER_UP_FAIL);
        return ret;
    } else {
        pcie_linkup_succ_fixup(0);
    }

    oal_atomic_set(&pst_pci_lres->refcnt, 0);
    pst_pci_lres->pci_cnt = 1; // 1 pcie ip

    oal_pcie_register_event(pst_pci_lres->pst_pcie_dev, pst_pci_lres);

    pst_pci_lres->power_status = PCIE_EP_IP_POWER_UP;
    if (pst_pci_lres->pst_pci_res) {
        mutex_lock(&pst_pci_lres->pst_pci_res->st_rx_mem_lock);
        oal_pcie_change_link_state(pst_pci_lres->pst_pci_res, PCI_WLAN_LINK_UP);
        mutex_unlock(&pst_pci_lres->pst_pci_res->st_rx_mem_lock);
    }

    oal_get_time_cost_end(cost);
    oal_calc_time_cost_sub(cost);
    pci_print_log(PCI_LOG_INFO, "pcie link cost %llu us", time_cost_var_sub(cost));

    return ret;
}

/* 芯片上电初始化 */
int32_t oal_dmi_transfer_res_init(oal_pcie_res *pst_pci_res)
{
    int32_t ret;

    /* 下载完PATCH才需要执行下面的操作, 片验证阶段通过SSI下载代码 */
    ret = oal_pcie_share_mem_res_map(pst_pci_res);
    if (ret != OAL_SUCC) {
        (void)ssi_dump_err_regs(SSI_ERR_PCIE_WAIT_BOOT_TIMEOUT);
        return ret;
    }

    ret = oal_pcie_ringbuf_res_map(pst_pci_res);
    if (ret != OAL_SUCC) {
        return ret;
    }

    mutex_lock(&pst_pci_res->st_rx_mem_lock);
    oal_pcie_change_link_state(pst_pci_res, PCI_WLAN_LINK_RES_UP);
    mutex_unlock(&pst_pci_res->st_rx_mem_lock);
    return ret;
}

void oal_dmi_transfer_res_exit(oal_pcie_res *pst_pci_res)
{
    oal_pcie_change_link_state(pst_pci_res, PCI_WLAN_LINK_DOWN);

    oal_pcie_ringbuf_res_unmap(pst_pci_res);

    /* clean ring */
    oal_pcie_share_mem_res_unmap(pst_pci_res);
}

OAL_STATIC OAL_INLINE int32_t oal_dmi_bus_power_patch_lauch(oal_pcie_linux_res *pst_pci_lres, hcc_bus *pst_bus)
{
    int32_t ret;
    unsigned int timeout = hi110x_get_emu_timeout(HOST_WAIT_BOTTOM_INIT_TIMEOUT);
    oal_io_print("power patch lauch\n");

    /* Patch下载完后 初始化通道资源，然后等待业务初始化完成 */
    ret = oal_pcie_transfer_res_init(pst_pci_lres->pst_pci_res);
    if (ret) {
        oal_io_print("pcie_transfer_res_init failed, ret=%d\n", ret);
        return ret;
    }

    oal_pcie_host_ip_init(pst_pci_lres);

    oal_wlan_gpio_intr_enable(hbus_to_dev(pst_bus), OAL_TRUE);

    /* pcie相关资源发送, 等待dpa初始化 */
    ret = dpa_wlan_open();
    if (ret) {
        oal_io_print("dpa_wlan_open failed, ret=%d\n", ret);
        return ret;
    }
    ret = oal_pcie_enable_device_func(pst_pci_lres);
    if (ret != OAL_SUCC) {
        oal_io_print("enable pcie device func failed, ret=%d\n", ret);
        return ret;
    }

    if (oal_wait_for_completion_timeout(&pst_bus->st_device_ready,
                                        (uint32_t)oal_msecs_to_jiffies(timeout)) == 0) {
        oal_io_print("wait device ready timeout... %d ms \n", timeout);
        up(&pst_bus->rx_sema);
        if (oal_wait_for_completion_timeout(&pst_bus->st_device_ready,
                                            (uint32_t)oal_msecs_to_jiffies(HOST_WAIT_DEV_DELAY_TIMEOUT)) == 0) {
            oal_io_print("retry 5 second hold, still timeout");
            return -OAL_ETIMEDOUT;
        } else {
            /* 强制调度成功，说明有可能是GPIO中断未响应 */
            oal_io_print("[E]retry succ, maybe gpio interrupt issue");
            declare_dft_trace_key_info("pcie gpio int issue", OAL_DFT_TRACE_FAIL);
        }
    }

    mutex_lock(&pst_pci_lres->pst_pci_res->st_rx_mem_lock);
    oal_pcie_change_link_state(pst_pci_lres->pst_pci_res, PCI_WLAN_LINK_WORK_UP);
    mutex_unlock(&pst_pci_lres->pst_pci_res->st_rx_mem_lock);

    ret = wait_for_dap_ready();
    if (ret) {
        oal_io_print("wait_for_dap_ready failed, ret=%d\n", ret);
        return ret;
    }

    hcc_enable(hbus_to_hcc(pst_bus), OAL_TRUE);

    return OAL_SUCC;
}

OAL_STATIC OAL_INLINE void oal_dmi_bus_power_sleep(oal_pcie_linux_res *pst_pci_lres, hcc_bus *pst_bus)
{
    pcie_bus_power_sleep_action(pst_bus);
}

OAL_STATIC int32_t oal_pcie_dmi_power_action(hcc_bus *pst_bus, hcc_bus_power_action_type action)
{
    int32_t ret = OAL_SUCC;
    oal_pcie_linux_res *pst_pci_lres;

    pst_pci_lres = (oal_pcie_linux_res *)pst_bus->data;
    if (oal_warn_on(pst_pci_lres == NULL)) {
        return -OAL_ENODEV;
    }

    if (action == HCC_BUS_POWER_DOWN) {
        oal_dmi_bus_power_down(pst_pci_lres, pst_bus);
    }

    if (action == HCC_BUS_POWER_SLEEP) {
        oal_dmi_bus_power_sleep(pst_pci_lres, pst_bus);
    }

    if (action == HCC_BUS_POWER_UP) {
        ret = oal_dmi_bus_power_up(pst_pci_lres, pst_bus);
    }

    if (action == HCC_BUS_POWER_PATCH_LOAD_PREPARE) {
        /* close hcc */
        hcc_disable(hbus_to_hcc(pst_bus), OAL_TRUE);
        oal_init_completion(&pst_bus->st_device_ready);
        oal_wlan_gpio_intr_enable(hbus_to_dev(pst_bus), OAL_FALSE);
    }

    if (action == HCC_BUS_POWER_PATCH_LAUCH) {
        ret = oal_dmi_bus_power_patch_lauch(pst_pci_lres, pst_bus);
    }

    return ret;
}

static int32_t oal_dmi_deepsleep_clean_ack(uint8_t type, void *priv)
{
    oal_complete(&dpa_ete_powerdown_done);
    return OAL_SUCC;
}

static int32_t oal_dmi_deepwkup_restore_ack(uint8_t type, void *priv)
{
    oal_complete(&dpa_ete_powerup_done);
    return OAL_SUCC;
}

void oal_dmi_transfer_deepsleep_clean(oal_pcie_res *pst_pci_res)
{
    int32_t ret;
    oal_init_completion(&dpa_ete_powerdown_done);
    conn_sync_dmi_single_ack_msg_send(CONN_DMI_MSG_ETE_DEEPSLEEP_CLEAN, oal_dmi_deepsleep_clean_ack, NULL);
    ret = oal_wait_for_completion_timeout(&dpa_ete_powerdown_done, (uint32_t)oal_msecs_to_jiffies(MSEC_PER_SEC));
    if (ret == 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "oal_dmi_transfer_deepsleep_clean wait completion fail !\n");
    }
    oal_print_mpxx_log(MPXX_LOG_INFO, "oal_dmi_transfer_deepsleep_clean done %d\n", ret);
}

int32_t oal_dmi_transfer_deepwkup_restore(oal_pcie_res *pst_pci_res)
{
    int32_t ret;
    oal_init_completion(&dpa_ete_powerup_done);
    conn_sync_dmi_single_ack_msg_send(CONN_DMI_MSG_ETE_DEEPWKUP_RESTORE, oal_dmi_deepwkup_restore_ack, NULL);
    ret = oal_wait_for_completion_timeout(&dpa_ete_powerup_done, (uint32_t)oal_msecs_to_jiffies(MSEC_PER_SEC));
    if (ret == 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "oal_dmi_transfer_deepwkup_restore wait completion fail !\n");
        return -OAL_EFAIL;
    }
    oal_print_mpxx_log(MPXX_LOG_INFO, "oal_dmi_transfer_deepwkup_restore done %d\n", ret);
    return OAL_SUCC;
}

OAL_STATIC uint32_t oal_pcie_dmi_is_master_ip(oal_pci_dev_stru *pst_pci_dev)
{
    uint32_t is_master;
    is_master = oal_pcie_is_master_ip(pst_pci_dev);
    if (is_master == OAL_TRUE) {
        declare_dft_trace_key_info("pcie_resume_master_powerup", OAL_DFT_TRACE_SUCC);
    } else {
        declare_dft_trace_key_info("pcie_resume_dual_powerup", OAL_DFT_TRACE_SUCC);
    }
    return is_master;
}

int32_t oal_pcie_dmi_wake_powerup_handler(void *data)
{
    int32_t ret = 0;
    uint32_t is_master;
    uint32_t retry_cnt = 0;
    const uint32_t max_retry_cnt = 3;
    struct wlan_pm_s *pst_wlan_pm = wlan_pm_get_drv();
    oal_pci_dev_stru *pst_pci_dev = (oal_pci_dev_stru *)data;
    oal_pcie_linux_res *pst_pci_lres = (oal_pcie_linux_res *)oal_pci_get_drvdata(pst_pci_dev);

    is_master = oal_pcie_dmi_is_master_ip(pst_pci_dev);

    if (pst_wlan_pm == NULL) {
        pci_print_log(PCI_LOG_INFO, "pst_wlan_pm is null wakeup failed");
        return 0;
    }

    /* for dual pcie */
    mutex_lock(&pst_pci_lres->sr_lock);
    if (conn_get_gpio_level(HOST_WKUP_W) == GPIO_LEVEL_LOW) {
retry:
        pci_print_log(PCI_LOG_INFO, "pcie_resume_powerup pull up gpio,retry_cnt=%u", retry_cnt);

        oal_init_completion(&pst_wlan_pm->st_wifi_powerup_done);

        oal_atomic_set(&g_bus_powerup_dev_wait_ack, 1);
        /* 这里保证解复位EP控制器时efuse已经稳定 */
        board_host_wakeup_dev_set(1);

        ret = oal_pcie_wait_for_completion(&pst_wlan_pm->st_wifi_powerup_done, (uint32_t)(WIFI_POWERUP_DONE_TIMEOUT));
        if (oal_unlikely(ret == -OAL_ETIMEDOUT)) { // timeout
            declare_dft_trace_key_info("pcie_resume_powerup ack timeout", OAL_DFT_TRACE_FAIL);
            (void)ssi_dump_err_regs(SSI_ERR_PCIE_SR_WAKEUP_FAIL);
            /* 最多尝试的次数，超过则出错 */
            if (retry_cnt++ < max_retry_cnt) {
                pci_print_log(PCI_LOG_INFO, "pull down wakeup gpio and retry");
                board_host_wakeup_dev_set(0);
                oal_msleep(5); /* 等待5ms，待唤醒io拉低稳定后再次尝试唤醒 */
                goto retry;
            } else {
                declare_dft_trace_key_info("pcie_resume_powerup_ack_timeout_retry_failed", OAL_DFT_TRACE_FAIL);
                (void)ssi_dump_err_regs(SSI_ERR_PCIE_SR_WAKEUP_RETRY_FAIL);
            }
        } else if (ret == -OAL_EFAIL || ret == -OAL_EINVAL) {
            oal_atomic_set(&g_bus_powerup_dev_wait_ack, 0);
            mutex_unlock(&pst_pci_lres->sr_lock);
            return ret;
        } else {
            pci_print_log(PCI_LOG_INFO, "powerup done");
        }

        oal_atomic_set(&g_bus_powerup_dev_wait_ack, 0);
    } else {
        // WL_HOST_WAKEUP high, need't wakeup
        pci_print_log(PCI_LOG_INFO, "host wakeup gpio is high");
    }
    mutex_unlock(&pst_pci_lres->sr_lock);

    /* pull up pcie_rst pin
     * 拉高pcie_rst管脚,不需要等待pcie解复位完成,直接尝试建链 */
    board_set_pcie_reset(is_master, OAL_TRUE);

    return ret;
}

OAL_STATIC int32_t oal_pcie_dmi_suspend_handler(void *data)
{
    oal_pci_dev_stru *pst_pci_dev = (oal_pci_dev_stru *)data;
    oal_pcie_linux_res *pst_pci_lres = (oal_pcie_linux_res *)oal_pci_get_drvdata(pst_pci_dev);
    int32_t rc_idx = oal_pcie_get_pcie_rc_idx(pst_pci_dev);

    if (pst_pci_lres == NULL) {
        return -OAL_EINVAL;
    }
    pst_pci_lres->power_status = PCIE_EP_IP_POWER_DOWN;
    oal_pcie_change_link_state(pst_pci_lres->pst_pci_res, PCI_WLAN_LINK_DEEPSLEEP);

    pci_print_log(PCI_LOG_INFO, "pcie%d_suspend refcnt=%d pci_cnt=%d", rc_idx,
                  oal_atomic_read(&pst_pci_lres->refcnt), pst_pci_lres->pci_cnt);

    if (oal_pcie_is_master_ip(pst_pci_dev) == OAL_TRUE) {
        declare_dft_trace_key_info("pcie_suspend_master_powerdown", OAL_DFT_TRACE_SUCC);
        oal_dmi_transfer_deepsleep_clean(pst_pci_lres->pst_pci_res);
    } else {
        declare_dft_trace_key_info("pcie_suspend_dual_powerdown", OAL_DFT_TRACE_SUCC);
    }

    /* pull down pcie_rst pin */
    board_set_pcie_reset(oal_pcie_is_master_ip(pst_pci_dev), OAL_FALSE);
    oal_pcie_power_notifiy_register(pst_pci_dev, oal_pcie_get_pcie_rc_idx(pst_pci_dev),
                                    oal_pcie_dmi_wake_powerup_handler, NULL, (void *)pst_pci_dev);
    return 0;
}

/* 双PCIE suspend函数会并发，函数需要考虑可重入 */
int32_t oal_pcie_dmi_suspend(oal_pci_dev_stru *pst_pci_dev, oal_pm_message_t state)
{
    int32_t ret;
    int32_t down_flag = 0;
    hcc_bus *pst_bus = NULL;
    struct hcc_handler *pst_hcc = NULL;

    oal_pcie_linux_res *pst_pci_lres = (oal_pcie_linux_res *)oal_pci_get_drvdata(pst_pci_dev);

    if (pst_pci_lres == NULL) {
        return -OAL_EINVAL;
    }

    ret = oal_pcie_sr_para_check(pst_pci_lres, &pst_bus, &pst_hcc);
    if (ret != OAL_SUCC) {
        if (ret == -OAL_ENODEV) {
            return OAL_SUCC;
        } else {
            return ret;
        }
    }

    pci_print_log(PCI_LOG_INFO, "oal_pcie_suspend name=%s", dev_name(&pst_pci_dev->dev));

    if (atomic_inc_return(&pst_pci_lres->refcnt) == 1) {
        /* first pcie suspend */
        if (down_interruptible(&pst_bus->sr_wake_sema)) {
            oal_io_print("pcie_wake_sema down failed.");
            oal_atomic_dec(&pst_pci_lres->refcnt);
            return -OAL_EFAIL;
        }
        down_flag = 1;
    }

    if (oal_pcie_wakelock_active(pst_bus) == OAL_TRUE) {
        /* has wake lock so stop controller's suspend,
         * otherwise controller maybe error while sdio reinit */
        pci_print_log(PCI_LOG_INFO, "already wake up, break suspend");
        if (down_flag == 1) {
            up(&pst_bus->sr_wake_sema);
        }
        oal_atomic_dec(&pst_pci_lres->refcnt);
        return -OAL_EFAIL;
    }

    if (down_flag == 1) {
        wlan_pm_wkup_src_debug_set(OAL_TRUE);
    }

    declare_dft_trace_key_info("pcie_os_suspend", OAL_DFT_TRACE_SUCC);
    if (g_pcie_pm_linkdown_switch == OAL_TRUE) { // 睡眠断链开关打开后，pcie此时已经断链
        return OAL_SUCC;
    }

    oal_pcie_save_default_resource(pst_pci_lres);
    oal_pcie_power_notifiy_register(pst_pci_dev, oal_pcie_get_pcie_rc_idx(pst_pci_dev),
                                    NULL, oal_pcie_dmi_suspend_handler, (void *)pst_pci_dev);
    return 0;
}

static uint32_t g_is_resume_failed = OAL_FALSE;
OAL_STATIC int32_t oal_pcie_dmi_resume_linkup_check(oal_pcie_linux_res *pst_pci_lres,
                                                    oal_pci_dev_stru *pst_pci_dev)
{
    uint32_t version = 0x0;
    int32_t ret;
    if (g_pcie_pm_linkdown_switch == OAL_TRUE) {
        return OAL_SUCC; // 睡眠断链开关打开后, pcie此时未重新建链
    }

    ret = oal_pci_read_config_dword(pst_pci_dev, 0x0, &version);
    if (ret) {
        pci_print_log(PCI_LOG_ERR, "read pci version failed ret=%d, name=%s",
                      ret, dev_name(&pst_pci_dev->dev));
        oal_msleep(1000); /* 整机低功耗流程，可能此时唤醒流程还未走完等1000ms */
        ret = oal_pci_read_config_dword(pst_pci_dev, 0x0, &version);
        if (ret) {
            pci_print_log(PCI_LOG_ERR, "read pci version failed ret=%d", ret);
        } else {
            pci_print_log(PCI_LOG_WARN, "version:0x%x is not match with:0x%x", version, pst_pci_lres->version);
        }

        g_is_resume_failed = OAL_TRUE;
        if (oal_atomic_read(&pst_pci_lres->refcnt) == 0) {
            return -OAL_EFAIL; // exception handler
        }
        return -OAL_ENODEV; // wait dual pcie handler done, bypass err
    }

    //  master pcie
    if (pst_pci_dev == pst_pci_lres->pst_pcie_dev) {
        if (version != pst_pci_lres->version) {
            pci_print_log(PCI_LOG_WARN, "version:0x%x is not match with:0x%x", version, pst_pci_lres->version);
        }
    }

    return OAL_SUCC;
}

OAL_STATIC void oal_pcie_dmi_resume_hold_sleep(oal_pcie_linux_res *pst_pci_lres, hcc_bus *pst_bus)
{
    if (oal_atomic_read(&pst_pci_lres->refcnt) == 0) {
        // resume all done, allow device deepsleep
        board_host_wakeup_dev_set(0);
        oal_usleep(WLAN_WAKEUP_DEV_EVENT_DELAY_US);
        pci_print_log(PCI_LOG_INFO, "oal_pcie_ete_resume done");
        up(&pst_bus->sr_wake_sema);
    }
}

int32_t oal_pcie_dmi_resume(oal_pci_dev_stru *pst_pci_dev)
{
    int32_t ret;
    hcc_bus *pst_bus = NULL;
    struct hcc_handler *pst_hcc = NULL;
    oal_pcie_linux_res *pst_pci_lres = (oal_pcie_linux_res *)oal_pci_get_drvdata(pst_pci_dev);

    ret = oal_pcie_sr_para_check(pst_pci_lres, &pst_bus, &pst_hcc);
    if (ret != OAL_SUCC) {
        if (ret == -OAL_ENODEV) {
            return OAL_SUCC;
        } else {
            return ret;
        }
    }

    declare_dft_trace_key_info("pcie_os_resume", OAL_DFT_TRACE_SUCC);

    mutex_lock(&pst_pci_lres->sr_lock);
    // last pcie resume
    if (atomic_dec_return(&pst_pci_lres->refcnt) == 0) {
        if (g_is_resume_failed == OAL_TRUE) {
            goto resume_exception;
        }
    }

    if (pst_pci_lres->power_status != PCIE_EP_IP_POWER_DOWN) {
        pci_print_log(PCI_LOG_INFO, "oal_pcie_resume");
        if (oal_atomic_read(&pst_pci_lres->refcnt) == 0) {
            up(&pst_bus->sr_wake_sema);
        }
        mutex_unlock(&pst_pci_lres->sr_lock);
        return OAL_SUCC;
    }

    // linkup failed
    ret = oal_pcie_dmi_resume_linkup_check(pst_pci_lres, pst_pci_dev);
    if (ret != OAL_SUCC) {
        if (ret == -OAL_ENODEV) {
            mutex_unlock(&pst_pci_lres->sr_lock);
            return OAL_SUCC;
        } else {
            goto resume_exception;
        }
    }

    oal_pcie_dmi_resume_hold_sleep(pst_pci_lres, pst_bus);

    mutex_unlock(&pst_pci_lres->sr_lock);
    return OAL_SUCC;
resume_exception:
    pci_print_log(PCI_LOG_INFO, "resume exception");
    g_is_resume_failed = OAL_FALSE;
    up(&pst_bus->sr_wake_sema);
    mutex_unlock(&pst_pci_lres->sr_lock);
    hcc_bus_exception_submit(pst_pci_lres->pst_bus, HCC_BUS_TRANS_FAIL);
    chr_exception_report(CHR_PLATFORM_EXCEPTION_EVENTID, CHR_SYSTEM_PLAT, CHR_LAYER_DRV,
                         CHR_PLT_DRV_EVENT_PCIE, CHR_PLAT_DRV_ERROR_RESUME_FIRMWARE_DOWN);
    return OAL_SUCC;
}

OAL_STATIC int32_t oal_pcie_master_address_switch(hcc_bus *hi_bus, uint64_t src_addr,
                                                  uint64_t* dst_addr, int32_t is_host_va)
{
    int32_t ret;
    pci_addr_map addr_map;

    oal_pcie_res *pst_pci_res = NULL;
    oal_pcie_linux_res *pst_pci_lres = (oal_pcie_linux_res *)hi_bus->data;
    if (oal_unlikely(pst_pci_lres == NULL)) {
        pci_print_log(PCI_LOG_INFO, "pst_pci_lres is null");
        return -OAL_ENODEV;
    }

    pst_pci_res = pst_pci_lres->pst_pci_res;

    if (oal_unlikely(pst_pci_res == NULL)) {
        pci_print_log(PCI_LOG_INFO, "pst_pci_res is null");
        return -OAL_ENODEV;
    }

    if (oal_warn_on(dst_addr == NULL)) {
        return -OAL_EINVAL;
    }

    *dst_addr = 0x0;

    if (is_host_va == OAL_FALSE) {
        /* device cpu address -> host virtual address */
        ret = oal_pcie_inbound_ca_to_va(pst_pci_res, src_addr, &addr_map);
        if (ret == OAL_SUCC) {
            *dst_addr = (uint64_t)addr_map.va;
        }
        return ret;
    } else {
        /* host virtual address -> device cpu address */
        ret = oal_pcie_inbound_va_to_ca(pst_pci_res, src_addr, dst_addr);
        return ret;
    }
}

OAL_STATIC int32_t oal_pcie_slave_address_switch(hcc_bus *hi_bus, uint64_t src_addr,
                                                 uint64_t* dst_addr, int32_t is_host_iova)
{
    oal_pcie_res *pst_pci_res = NULL;
    oal_pcie_linux_res *pst_pci_lres = (oal_pcie_linux_res *)hi_bus->data;
    if (oal_unlikely(pst_pci_lres == NULL)) {
        pci_print_log(PCI_LOG_INFO, "pst_pci_lres is null");
        return -OAL_ENODEV;
    }

    pst_pci_res = pst_pci_lres->pst_pci_res;

    if (oal_unlikely(pst_pci_res == NULL)) {
        pci_print_log(PCI_LOG_INFO, "pst_pci_res is null");
        return -OAL_ENODEV;
    }

    if (oal_warn_on(dst_addr == NULL)) {
        return -OAL_EINVAL;
    }

    return oal_pcie_host_slave_address_switch(pst_pci_res, src_addr, dst_addr, is_host_iova);
}

OAL_STATIC hcc_bus_opt_ops g_dmi_opt_ops = {
    .disable_bus_state = oal_disable_dmi_state,
    .enable_bus_state = oal_enable_dmi_state,
    .tx_netbuf_list = conn_dmi_hcc_tx_netbuf,
    .send_msg = oal_pcie_send_msg,
    .lock = oal_pcie_host_lock,
    .unlock = oal_pcie_host_unlock,
    .sleep_request = oal_pcie_sleep_request,
    .sleep_request_host = oal_dmi_sleep_request_host,
    .wakeup_request = oal_pcie_wakeup_request,
    .get_sleep_state = oal_pcie_get_sleep_state,
    .wakeup_complete = oal_pcie_dmi_wakeup_complete,
    .poweroff_pre = oal_dmi_poweroff_pre,
    .poweroff_complete =  oal_pcie_dmi_poweroff_complete,
    .power_action = oal_pcie_dmi_power_action,
    .power_ctrl = oal_pcie_power_ctrl,
    .wlan_gpio_handler = oal_pcie_gpio_irq,
    .wlan_gpio_rxdata_proc = oal_pcie_gpio_rx_data,
    .reinit = oal_pcie_reinit,
    .deinit = oal_pcie_deinit,
    .patch_read = oal_pcie_patch_read,
    .patch_write = oal_pcie_patch_write,
    .tx_condition = oal_dmi_tx_condition,

    .master_address_switch = oal_pcie_master_address_switch,
    .slave_address_switch = oal_pcie_slave_address_switch,
};

void dmi_hcc_excep_handle(void)
{
    struct dmi_hcc_inter_data_stru *cur_dmi = NULL;
    uint16_t idx;
    uint16_t queue_size = oal_circ_queue_size(&g_hcc_dmi_mng.hcc_process_queue);
    for (idx = 0; idx < queue_size; idx++) {
        cur_dmi = (struct dmi_hcc_inter_data_stru *)oal_circ_queue_dequeue(&g_hcc_dmi_mng.hcc_process_queue);
        external_dpa_data_free_ops(cur_dmi->payload_addr);
    }
}

int32_t dmi_hcc_transfer_init(hcc_bus *bus)
{
    int32_t ret;
    bus->opt_ops = &g_dmi_opt_ops;
    g_hcc_dmi_mng.hcc_bus = bus;

    oal_atomic_set(&g_dpa_sbuf_switch, 0);

    g_hcc_dmi_mng.hcc_process_node = oal_memalloc(HCC_TRANS_QUEUE_DEPTH * sizeof(struct dmi_hcc_inter_data_stru));
    if (g_hcc_dmi_mng.hcc_process_node == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "hcc_process_node mem alloc fail");
        goto err_queue_mem_alloc;
    }

    ret = oal_circ_queue_init(&g_hcc_dmi_mng.hcc_process_queue, HCC_TRANS_QUEUE_DEPTH,
                              sizeof(struct dmi_hcc_inter_data_stru), (uintptr_t)g_hcc_dmi_mng.hcc_process_node);
    if (ret != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "circ_queue_init fail");
        goto err_circ_queue_init;
    }

    oal_wait_queue_init_head(&g_hcc_dmi_mng.dmi_recv_transfer_wq);
    g_hcc_dmi_mng.dmi_recv_thread = oal_thread_create(dmi_recv_thread,
                                                      &g_hcc_dmi_mng,
                                                      NULL,
                                                      "conn_dmi_recv",
                                                      SCHED_FIFO,
                                                      DMI_RECV_THERAD_PRIORITY,
                                                      -1);
    if (g_hcc_dmi_mng.dmi_recv_thread == NULL) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "dmi recv thread create failed!");
        goto failed_create_dmi_recv_thread;
    }

    if (conn_dmi_hal_rx_register(DMI_HAL_TYPE_HCC, conn_dmi_hcc_rx, conn_dmi_hcc_rx_err) != OAL_SUCC) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "request_hcc_cb_process register fail");
        goto failed_hal_hcc_register;
    }

    conn_dmi_msg_regiser(CONN_DMI_MSG_SBUF_FLOWCTRL_ON, dpa_sbuf_flowctrl_on);
    conn_dmi_msg_regiser(CONN_DMI_MSG_SBUF_FLOWCTRL_OFF, dpa_sbuf_flowctrl_off);
    conn_dmi_msg_regiser(CONN_DMI_MSG_SBUF_ALLOC_FAIL, dpa_sbuf_alloc_fail);
    return OAL_SUCC;

failed_hal_hcc_register:
    oal_kthread_stop(g_hcc_dmi_mng.dmi_recv_thread);
    g_hcc_dmi_mng.dmi_recv_thread = NULL;
failed_create_dmi_recv_thread:
    oal_circ_queue_deinit(&g_hcc_dmi_mng.hcc_process_queue);
err_circ_queue_init:
    oal_free(g_hcc_dmi_mng.hcc_process_node);
err_queue_mem_alloc:
    return -OAL_FAIL;
}

void dmi_hcc_transfer_deinit(void)
{
    conn_dmi_msg_regiser(CONN_DMI_MSG_SBUF_FLOWCTRL_OFF, NULL);
    conn_dmi_msg_regiser(CONN_DMI_MSG_SBUF_FLOWCTRL_ON, NULL);
    conn_dmi_hal_rx_register(DMI_HAL_TYPE_HCC, NULL, NULL);
    oal_kthread_stop(g_hcc_dmi_mng.dmi_recv_thread);
    g_hcc_dmi_mng.dmi_recv_thread = NULL;
    oal_circ_queue_deinit(&g_hcc_dmi_mng.hcc_process_queue);
    oal_free(g_hcc_dmi_mng.hcc_process_node);
    memset_s(&g_hcc_dmi_mng, sizeof(g_hcc_dmi_mng), 0, sizeof(hcc_dmi_mng_str));
}
#endif