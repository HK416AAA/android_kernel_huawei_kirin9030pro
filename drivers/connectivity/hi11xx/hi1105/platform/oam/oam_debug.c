/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description:oam_rdr functional module
 * Author: platform drivers
 */
#include "oam_debug.h"
#ifndef _PRE_LINUX_TEST
#include "plat_debug.h"
#include "bfgx_core.h"
#include "bfgx_dev.h"
#include "plat_pm.h"
#include "oam_ext_if.h"
#include "bfgx_data_parse.h"
#include "oal_hcc_host_if.h"
#else
#include "plat_test_debug.h"
#endif

#ifdef PLATFORM_DEBUG_ENABLE
#define OAM_DBG_READ_ACK_TIMEOUT_MS     5000
#define OAM_DBG_WRITE_32BIT_MAX_VALUE   32
#define OAM_DBG_WRITE_16BIT_MAX_VALUE   16
#define HCC_OAM_DBG_INITIAL_VALUE       (-199)
#define OAM_DBG_FUNC_OPEN_VALUE_CMD     0xA5
#define OAM_DBG_FUNC_CLOSE_VALUE_CMD    0x5A
#define OAM_DBG_FUNC_OP_ADDR_CMD        0xFFFFFFFF /* 寄存器读写不会使用到这个地址。所以作为开关命令使用 */

enum oam_dbg_reg_width {
    OAM_DBG_REG_WIDTH_1 = 1,
    OAM_DBG_REG_WIDTH_2 = 2,
    OAM_DBG_REG_WIDTH_4 = 4,
};

enum oam_dbg_reg_mode {
    OAM_DBG_REG_MODE_WRITE = 0,
    OAM_DBG_REG_MODE_READ = 1,
};

typedef struct {
    uint8_t name[OAM_SUBSYS_NAME_SIZE];
    uint8_t subsys_index;
} oam_dbg_subsys_t;

typedef struct {
    uint32_t opt_type;
    uint32_t reg_addr;
    uint32_t reg_value;
    int32_t response_ret;
} hcc_oam_dbg_request_t;

oam_dbg_subsys_t g_oam_dbg_subsys_info[OAM_DBG_SUBSYS_BUTT] = {
    {"wifi",        OAM_DBG_SUBSYS_WIFI},
    {"bt",          OAM_DBG_SUBSYS_BT},
    {"sle",         OAM_DBG_SUBSYS_SLE},
    {"ir",          OAM_DBG_SUBSYS_IR},
    {"gnss",        OAM_DBG_SUBSYS_GNSS},
    {"glp",         OAM_DBG_SUBSYS_GLP},
};

oal_define_spinlock(g_oam_dbg_info_lock);
oal_oam_dbg_item_t g_oam_dbg_info;
oal_module_symbol(g_oam_dbg_info_lock);
oal_module_symbol(g_oam_dbg_info);

STATIC hcc_oam_dbg_request_t g_oam_dbg_request_ack;
STATIC bool g_oam_dbg_reg_func_en_flag = false;

/* 打印 */
ssize_t oam_debug_data_value_print_bits(char *buf, int32_t count, void *data, uint32_t size)
{
    int32_t ret = 0;
    uint32_t value;
    int32_t i;
    int32_t cnt_tmp = count;

    if (size == 1) { /* 1表示要打印长度为1字节 */
        value = (uint32_t)(*((uint8_t *)data));
    } else if (size == 2) { /* 2表示要打印长度为2字节 */
        value = (uint32_t)(*((uint16_t *)data));
    } else if (size == 4) { /* 4表示要打印长度为4字节 */
        value = (uint32_t)(*((uint32_t *)data));
    } else {
        /* 传入了错误的参数，不处理返回 */
        return -OAM_DEBUG_PRINT_BIT_ERROR;
    }

    /* 按比特打印 */
    for (i = (int32_t)size * 8 - 1; i >= 0; i--) { // 8 bits, 1 bit each time
        ret = snprintf_s(buf + cnt_tmp, PAGE_SIZE - cnt_tmp, PAGE_SIZE - cnt_tmp - 1, "%s",
                         (1u << (uint32_t)i) & value ? " 1 " : " 0 ");
        if (ret < 0) {
            ps_print_err("log str format err line[%d]\n", __LINE__);
            return ret;
        }
        cnt_tmp += ret;
    }
    ret = snprintf_s(buf + cnt_tmp, PAGE_SIZE - cnt_tmp, PAGE_SIZE - cnt_tmp - 1, "\n");
    if (ret < 0) {
        ps_print_err("log str format err line[%d]\n", __LINE__);
        return ret;
    }
    cnt_tmp += ret;

    return cnt_tmp;
}

uint8_t oam_dbg_subsys_convert(uint8_t *subsys_str)
{
    uint8_t index = 0;
    for (index = 0; index < OAM_DBG_SUBSYS_BUTT; index++) {
        if (oal_strcmp(subsys_str, g_oam_dbg_subsys_info[index].name) == 0) {
            return g_oam_dbg_subsys_info[index].subsys_index;
        }
    }
    return OAM_DBG_SUBSYS_BUTT;
}

STATIC ssize_t store_oam_dbg_do_skb_send(struct ps_core_s *ps_core_d, const char *buf, size_t count)
{
    struct sk_buff *skb;
    int32_t ret, prepare_result;
    uint16_t total_len = (uint16_t)(count + PS_PKG_SIZE);

    ret = prepare_to_visit_node(ps_core_d, &prepare_result);
    if (ret < 0) {
        ps_print_err("[store_oam_dbg_do_skb_send]prepare work FAIL\n");
        return ret;
    }

    skb = ps_alloc_skb(total_len);
    if (skb == NULL) {
        post_to_visit_node(ps_core_d, prepare_result);
        ps_print_err("[store_oam_dbg_do_skb_send]alloc skb is err\n");
        return -EFAULT;
    }

    if (memcpy_s(&skb->data[PS_HEAD_SIZE], total_len - PS_HEAD_SIZE, buf, count) != EOK) {
        ps_print_err("[store_oam_dbg_do_skb_send]memcpy_s is err\n");
        kfree_skb(skb);
        post_to_visit_node(ps_core_d, prepare_result);
        return -EFAULT;
    }

    ps_print_info("[store_oam_dbg_do_skb_send]send %d byte data\n", total_len);
    if (ps_add_packet_head(skb->data, OML_MSG, total_len) != OAL_SUCC) {
        ps_print_err("[store_oam_dbg_do_skb_send]add packet head is err\n");
        kfree_skb(skb);
        post_to_visit_node(ps_core_d, prepare_result);
        return -EFAULT;
    }

    ps_skb_enqueue(ps_core_d, skb, TX_LOW_QUEUE);
    ps_core_tx_work_add(ps_core_d);

    post_to_visit_node(ps_core_d, prepare_result);
    return OAM_DEBUG_SUCCESS;
}

STATIC ssize_t store_oam_dbg_do_send_for_bgfx(const char *buf, size_t count, uint8_t *subsys)
{
    struct ps_core_s *ps_core_d = NULL;
    uint8_t uart_index = BUART;
    uint8_t subsys_index = oam_dbg_subsys_convert(subsys);
    if (subsys_index == OAM_DBG_SUBSYS_BUTT) {
        ps_print_err("[store_oam_dbg_do_send_for_bgfx]subsys name is error name:%s\n", subsys);
        return -EINVAL;
    }

    if (g_oam_dbg_info.uart_index_func != NULL) {
        uart_index = g_oam_dbg_info.uart_index_func((plat_oam_dbg_subsys_t)subsys_index);
    }

    ps_core_d = ps_get_core_reference(uart_index);
    if (unlikely((ps_core_d == NULL) || (buf == NULL))) {
        ps_print_err("[store_oam_dbg_do_send_for_bgfx]ps_core_d & buf is NULL\n");
        return -EINVAL;
    }

    if (!ps_core_chk_bfgx_active(ps_core_d)) {
        ps_print_err("[store_oam_dbg_do_send_for_bgfx][%s]no subsys is open!", index2name(ps_core_d->pm_data->index));
        return -EINVAL;
    }

    if (count > (DBG_TX_MAX_FRAME - PS_PKG_SIZE)) {
        ps_print_err("[store_oam_dbg_do_send_for_bgfx]err: dbg packet is too large!\n");
        return -EINVAL;
    }

    if (store_oam_dbg_do_skb_send(ps_core_d, buf, count) != OAM_DEBUG_SUCCESS) {
        return -EINVAL;
    }

    return count;
}

void oam_dbg_uart_get_index_callback_register(oam_dbg_uart_get_index_func_t func)
{
    g_oam_dbg_info.uart_index_func = func;
}

STATIC uint8_t store_oam_dbg_buf_init(ps_reg_data_info_t *reg_buf, uint32_t opt_type,
                                      uint32_t reg_addr, uint32_t value)
{
    uint8_t ret = 0;
    reg_buf->frame_start = PACKET_START_SIGNAL;
    reg_buf->frame_end = PACKET_END_SIGNAL;
    reg_buf->func_type = OAM_DATA_TYPE_REG_RW;
    reg_buf->prim_id = 0x51;  // 寄存器读写固定使用的prim_id
    reg_buf->frame_len = PS_REG_DATA_SIZE;
    reg_buf->mem_addr = reg_addr;

    switch (opt_type) {
        case OAM_DBG_REG_WRITE_32:
            reg_buf->mode = OAM_DBG_REG_MODE_WRITE;
            reg_buf->mem_bit_width = OAM_DBG_REG_WIDTH_4;
            reg_buf->data = value;
            break;
        case OAM_DBG_REG_READ_32:
            reg_buf->mode = OAM_DBG_REG_MODE_READ;
            reg_buf->mem_bit_width = OAM_DBG_REG_WIDTH_4;
            break;
        case OAM_DBG_REG_WRITE_16:
            reg_buf->mode = OAM_DBG_REG_MODE_WRITE;
            reg_buf->mem_bit_width = OAM_DBG_REG_WIDTH_2;
            reg_buf->data = value;
            break;
        case OAM_DBG_REG_READ_16:
            reg_buf->mode = OAM_DBG_REG_MODE_READ;
            reg_buf->mem_bit_width = OAM_DBG_REG_WIDTH_2;
            break;
        case OAM_DBG_REG_WRITE_BIT_MASK_32:
        case OAM_DBG_REG_WRITE_BIT_MASK_16:
        case OAM_DBG_REG_CLEAR_BIT_MASK_32:
        case OAM_DBG_REG_CLEAR_BIT_MASK_16:
            reg_buf->mode = OAM_DBG_REG_MODE_READ;
            reg_buf->mem_bit_width = OAM_DBG_REG_WIDTH_4;
            ret = 1;
            break;
        default:
            ps_print_err("[store_oam_dbg_buf_init]opt_type is invalid\n");
            break;
    }
    return ret;
}

STATIC bool store_oam_dbg_write_bit_buf_set(ps_reg_data_info_t *reg_buf, uint32_t opt_type, uint32_t value)
{
    if ((opt_type == OAM_DBG_REG_WRITE_BIT_MASK_32) || (opt_type == OAM_DBG_REG_CLEAR_BIT_MASK_32)) {
        if (value >= OAM_DBG_WRITE_32BIT_MAX_VALUE) {
            return false;
        }
    }

    if ((opt_type == OAM_DBG_REG_WRITE_BIT_MASK_16) || (opt_type == OAM_DBG_REG_CLEAR_BIT_MASK_16)) {
        if (value >= OAM_DBG_WRITE_16BIT_MAX_VALUE) {
            return false;
        }
    }
    reg_buf->mode = OAM_DBG_REG_MODE_WRITE;
    switch (opt_type) {
        case OAM_DBG_REG_WRITE_BIT_MASK_32:
            reg_buf->mem_bit_width = OAM_DBG_REG_WIDTH_4;
            reg_buf->data = g_oam_dbg_info.reg_value | (1 << value);
            break;
        case OAM_DBG_REG_WRITE_BIT_MASK_16:
            reg_buf->mem_bit_width = OAM_DBG_REG_WIDTH_2;
            reg_buf->data = (g_oam_dbg_info.reg_value | (1 << value)) & 0xFFFF;
            break;
        case OAM_DBG_REG_CLEAR_BIT_MASK_32:
            reg_buf->mem_bit_width = OAM_DBG_REG_WIDTH_4;
            reg_buf->data = g_oam_dbg_info.reg_value & (~(1 << value));
            break;
        case OAM_DBG_REG_CLEAR_BIT_MASK_16:
            reg_buf->mem_bit_width = OAM_DBG_REG_WIDTH_2;
            reg_buf->data = g_oam_dbg_info.reg_value & ((~(1 << value)) & 0xFFFF);
            break;
        default:
            ps_print_err("[store_oam_dbg_write_bit_buf_set]opt_type is invalid\n");
            return false;
    }
    return true;
}

STATIC void oam_dbg_cmd_info_func(uint8_t *subsys, uint32_t opt_type,
                                  uint32_t reg_addr, uint32_t reg_value, int32_t ret)
{
    unsigned long flags__;
    oal_spin_lock_irq_save(&g_oam_dbg_info_lock, &flags__);
    if (memcpy_s(g_oam_dbg_info.subsys, OAM_SUBSYS_NAME_SIZE, subsys, OAM_SUBSYS_NAME_SIZE) != EOK) {
        ps_print_err("[oam_dbg_cmd_info_func]memcpy_s is err\n");
    }
    g_oam_dbg_info.opt_type = opt_type;
    g_oam_dbg_info.reg_addr = reg_addr;
    g_oam_dbg_info.reg_value = reg_value;
    g_oam_dbg_info.result = ret;
    oal_spin_unlock_irq_restore(&g_oam_dbg_info_lock, &flags__);
}

void oam_dbg_readback_info_func(uint32_t reg_addr, uint32_t reg_value)
{
    unsigned long flags__;
    oal_spin_lock_irq_save(&g_oam_dbg_info_lock, &flags__);

    if (reg_addr != g_oam_dbg_info.reg_addr) {
        printk("register address is not match reg=0x%x != 0x%x\n", reg_addr, g_oam_dbg_info.reg_addr);
        oal_spin_unlock_irq_restore(&g_oam_dbg_info_lock, &flags__);
        return;
    }

    if ((g_oam_dbg_info.opt_type != OAM_DBG_REG_READ_16) && (g_oam_dbg_info.opt_type != OAM_DBG_REG_READ_32)) {
        printk("register opt type is not match\n");
        oal_spin_unlock_irq_restore(&g_oam_dbg_info_lock, &flags__);
        return;
    }
    g_oam_dbg_info.reg_value = reg_value;
    g_oam_dbg_info.result = 0;
    oal_complete(&g_oam_dbg_info.readback_comp);
    oal_spin_unlock_irq_restore(&g_oam_dbg_info_lock, &flags__);
}

STATIC ssize_t oam_dbg_send_data_to_bfgx(uint8_t *subsys, uint32_t opt_type, uint32_t reg_addr, uint32_t reg_value)
{
    uint8_t bit_set = 0;
    ps_reg_data_info_t reg_buf = { 0 };
    int32_t ret;

    if ((opt_type != OAM_DBG_REG_WRITE_32) && (opt_type != OAM_DBG_REG_WRITE_16)) {
        oal_reinit_completion(g_oam_dbg_info.readback_comp);
    }

    oam_dbg_cmd_info_func(subsys, opt_type, reg_addr, reg_value, -OAM_DEBUG_FAILED);
    bit_set = store_oam_dbg_buf_init(&reg_buf, opt_type, reg_addr, reg_value);
    if (store_oam_dbg_do_send_for_bgfx((char *)&reg_buf, PS_REG_DATA_SIZE, subsys) < 0) {
        oam_dbg_cmd_info_func(subsys, opt_type, reg_addr, reg_value, -OAM_DEBUG_DATA_SEND_FAILED);
        ps_print_err("[store_oam_dbg]data send is error"NEWLINE);
        return -OAM_DEBUG_DATA_SEND_FAILED;
    }

    if ((opt_type != OAM_DBG_REG_WRITE_32) && (opt_type != OAM_DBG_REG_WRITE_16)) {
        ret = wait_for_completion_interruptible_timeout(&g_oam_dbg_info.readback_comp,
                                                        msecs_to_jiffies(OAM_DBG_READ_ACK_TIMEOUT_MS));
        if (ret < 0) {
            oam_dbg_cmd_info_func(subsys, opt_type, reg_addr, reg_value, -OAM_DEBUG_DATA_SEND_TIMEOUT);
            ps_print_info("oam debug test Event terminated ret=%d\n", ret);
            return ret;
        } else if (ret == 0) {
            oam_dbg_cmd_info_func(subsys, opt_type, reg_addr, reg_value, -OAM_DEBUG_DATA_SEND_TIMEOUT);
            ps_print_err("oam debug test timeout");
            return -OAM_DEBUG_DATA_SEND_TIMEOUT;
        }
    } else {
        oam_dbg_cmd_info_func(subsys, opt_type, reg_addr, reg_value, OAM_DEBUG_SUCCESS);
    }

    if (bit_set != 0) {
        if (!store_oam_dbg_write_bit_buf_set(&reg_buf, opt_type, reg_value)) {
            ps_print_err("[store_oam_dbg]data bit[%d] is error"NEWLINE, -OAM_DEBUG_BIT_SET_ERROR);
            return -OAM_DEBUG_BIT_SET_ERROR;
        }
        if (store_oam_dbg_do_send_for_bgfx((char *)&reg_buf, PS_REG_DATA_SIZE, subsys) < 0) {
            oam_dbg_cmd_info_func(subsys, opt_type, reg_addr, reg_value, -OAM_DEBUG_DATA_SEND_FAILED);
            ps_print_err("[store_oam_dbg]data send is error"NEWLINE);
            return -OAM_DEBUG_DATA_SEND_FAILED;
        }
    }

    ps_print_info("[store_oam_dbg]subsys=%s, opt_type=%d, reg_addr=%x"NEWLINE, subsys, opt_type, reg_addr);
    return OAM_DEBUG_SUCCESS;
}

void oam_dbg_hcc_ack_handle(oal_netbuf_stru *pst_netbuf)
{
    int32_t ret = memcpy_s(&g_oam_dbg_request_ack, sizeof(g_oam_dbg_request_ack),
                           (void *)oal_netbuf_data(pst_netbuf), sizeof(g_oam_dbg_request_ack));
    if (ret != EOK) {
        ps_print_err("[oam_dbg_hcc_ack_handle]memcpy_s err!\n");
        oal_complete(&g_oam_dbg_info.readback_comp);
        return;
    }
    oal_complete(&g_oam_dbg_info.readback_comp);
    ps_print_info("oam debug done opt_type=0x%x, addr=0x%x, value=0x%x",
                  g_oam_dbg_request_ack.opt_type, g_oam_dbg_request_ack.reg_addr, g_oam_dbg_request_ack.reg_value);
}

STATIC int32_t oam_dbg_do_send_hcc_data(struct hcc_handler *hcc, oal_netbuf_stru *pst_netbuf)
{
    int32_t ret;
    struct hcc_transfer_param st_hcc_transfer_param = { 0 };

    memset_s(&g_oam_dbg_request_ack, sizeof(g_oam_dbg_request_ack), 0, sizeof(g_oam_dbg_request_ack));
    g_oam_dbg_request_ack.response_ret = HCC_OAM_DBG_INITIAL_VALUE;
    oal_reinit_completion(g_oam_dbg_info.readback_comp);
    hcc_hdr_param_init(&st_hcc_transfer_param,
                       HCC_ACTION_TYPE_OAM,
                       RW_SINGLE_REG,
                       0,
                       HCC_FC_WAIT,
                       DATA_HI_QUEUE);

    ret = hcc_tx(hcc, pst_netbuf, &st_hcc_transfer_param);
    if (ret) {
        ps_print_err("pcie test send failed ret=%d", ret);
        return OAM_DEBUG_HCC_TX_ERROR;
    }
    ret = wait_for_completion_interruptible_timeout(&g_oam_dbg_info.readback_comp,
                                                    oal_msecs_to_jiffies(OAM_DBG_READ_ACK_TIMEOUT_MS));
    if (ret < 0) {
        ps_print_info("oam debug test Event terminated ret=%d\n", ret);
        return ret;
    } else if (ret == 0) {
        ps_print_err("oam debug test timeout");
        return -OAM_DEBUG_DATA_SEND_TIMEOUT;
    }
    return OAM_DEBUG_SUCCESS;
}

STATIC int32_t oam_dbg_send_data_to_wifi(uint8_t *subsys, uint32_t opt_type, uint32_t reg_addr, uint32_t value)
{
    int32_t ret;
    oal_netbuf_stru *pst_netbuf = NULL;
    hcc_oam_dbg_request_t oam_dbg_rq = { 0 };
    struct hcc_handler *hcc = NULL;

    hcc = hcc_get_handler(HCC_EP_WIFI_DEV);
    if (hcc == NULL) {
        ps_print_err("[oam_dbg_send_data_to_wifi]get hcc err, index=0x%x", HCC_EP_WIFI_DEV);
        return -OAM_DEBUG_GET_HCC_ERROR;
    }

    pst_netbuf = hcc_netbuf_alloc(sizeof(oam_dbg_rq));
    if (pst_netbuf == NULL) {
        ps_print_err("[oam_dbg_send_data_to_wifi]alloc mem failed!");
        return -OAM_DEBUG_ALLOC_MEM_ERROR;
    }
    oal_netbuf_put(pst_netbuf, sizeof(oam_dbg_rq));

    oam_dbg_rq.opt_type = opt_type;
    oam_dbg_rq.reg_addr = reg_addr;
    oam_dbg_rq.reg_value = value;
    ret = memcpy_s((void *)oal_netbuf_data(pst_netbuf), sizeof(oam_dbg_rq), (void *)&oam_dbg_rq, sizeof(oam_dbg_rq));
    if (ret != EOK) {
        oal_netbuf_free(pst_netbuf);
        ps_print_err("memcpy_s error!");
        return -OAM_DEBUG_MEMCPY_ERROR;
    }

    if (oam_dbg_do_send_hcc_data(hcc, pst_netbuf) != OAM_DEBUG_SUCCESS) {
        oam_dbg_cmd_info_func(subsys, opt_type, reg_addr, value, -OAM_DEBUG_FAILED);
        oal_netbuf_free(pst_netbuf);
        return -OAM_DEBUG_FAILED;
    }
    oam_dbg_cmd_info_func(subsys, opt_type, reg_addr, g_oam_dbg_request_ack.reg_value,
                          g_oam_dbg_request_ack.response_ret);
    return OAM_DEBUG_SUCCESS;
}

STATIC bool oam_dbg_checkfunc_enable(uint32_t reg_addr, uint32_t reg_value)
{
    if (reg_addr != OAM_DBG_FUNC_OP_ADDR_CMD) {
        return g_oam_dbg_reg_func_en_flag;
    }

    if (reg_value == OAM_DBG_FUNC_OPEN_VALUE_CMD) {
        g_oam_dbg_reg_func_en_flag = true;
    } else if (reg_value == OAM_DBG_FUNC_CLOSE_VALUE_CMD) {
        g_oam_dbg_reg_func_en_flag = false;
    }
    return false;
}

ssize_t oam_dbg_send_data_to_device(uint8_t *subsys, uint32_t opt_type, uint32_t reg_addr, uint32_t reg_value)
{
    if (!oam_dbg_checkfunc_enable(reg_addr, reg_value)) {
        oam_dbg_cmd_info_func(subsys, opt_type, reg_addr, reg_value, -OAM_DEBUG_FAILED);
        return -OAM_DEBUG_FAILED;
    }
    if (oal_strcmp(subsys, "wifi") == 0) {
        return oam_dbg_send_data_to_wifi(subsys, opt_type, reg_addr, reg_value);
    }
    return oam_dbg_send_data_to_bfgx(subsys, opt_type, reg_addr, reg_value);
}

bool oam_dbg_get_reg_func_enable(void)
{
    return g_oam_dbg_reg_func_en_flag;
}
#endif
