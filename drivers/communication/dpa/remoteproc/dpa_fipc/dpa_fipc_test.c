#include <linux/version.h>
#include <linux/types.h>
#include <uapi/linux/sched/types.h> /* struct sched_param */
#include <linux/dma-mapping.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include "bsp_dpa_fipc.h"
#include "dpa_fipc_plat.h"

dpa_fipc_chn_t g_bd2_send_hdl_1;
dpa_fipc_chn_t g_bd2_recv_hdl_1;

int test_bd2_send_done_cbk(dpa_fipc_event event, void *arg, const dpa_fipc_eventinfo *event_info)
{
    char *input = (char *)arg;
    dpa_fipc_err("test_bd2_send_done_cbk: %s\n", input);
    return 0;
}

int test_bd2_send_init(void)
{
    dpa_fipc_chn_attr_t attr;
    dpa_fipc_chn_attr_t *pattr = &attr;
    int ret;
    ret = bsp_dpa_fipc_chn_attr_init(pattr);

    pattr->chnid = DPA_FIPC_TEST_PRIVATE_SEND_1;
    pattr->cbk = test_bd2_send_done_cbk;
    pattr->cbk_arg = "send done cbk: 1";
    pattr->type = DPA_FIPC_CHNL_SEND;
    pattr->size = 0x80;
    pattr->va = dpa_fipc_alloc_coherent(pattr->size, &pattr->ga, GFP_KERNEL);
    if (pattr->va == NULL || pattr->ga == 0) {
        dpa_fipc_err("test_bd2_send_init failed to alloc mem for ringbuf!\n");
        return -1;
    }
    pattr->ptr_vaddr = dpa_fipc_alloc_coherent(sizeof(u32), &pattr->ptr_gaddr, GFP_KERNEL);
    if (pattr->ptr_vaddr == NULL || pattr->ptr_gaddr == 0) {
        dpa_fipc_err("test_bd2_send_init failed to alloc mem for ptr!\n");\
        return -1;
    }

    ret = bsp_dpa_fipc_chn_open(&g_bd2_send_hdl_1, pattr);
    if (ret) {
        dpa_fipc_err("DPA_FIPC_TEST_PRIVATE_SEND_1 open failed: %d\n", ret);
        return -2;
    }
    return 0;
}

int test_bd2_recv_cbk(dpa_fipc_event event, void *arg, const dpa_fipc_eventinfo *event_info)
{
    int ret;
    char *input = (char *)arg;
    void *buf = NULL;
    u32 len = 0x60;
    dpa_fipc_err("test_bd2_recv_cbk: %s\n", input);
    buf = (void *)kmalloc(len, GFP_KERNEL);
    ret = bsp_dpa_fipc_chn_recv_raw(event_info->data_event.chn_hdl, buf, len);
    dpa_fipc_err("read len: %d\n", ret);
    dpa_fipc_err("content: 0x%x\n", *(u32 *)buf);
    kfree(buf);
    return 0;
}

int test_bd2_recv_init(void)
{
    dpa_fipc_chn_attr_t attr;
    dpa_fipc_chn_attr_t *pattr = &attr;
    int ret;
    ret = bsp_dpa_fipc_chn_attr_init(pattr);

    pattr->chnid = DPA_FIPC_TEST_PRIVATE_RECV_1;
    pattr->cbk = test_bd2_recv_cbk;
    pattr->cbk_arg = "bd2 recv cbk: 1";
    pattr->type = DPA_FIPC_CHNL_RECV;
    pattr->size = 0x200;
    pattr->va = dpa_fipc_alloc_coherent(pattr->size, &pattr->ga, GFP_KERNEL);
    if (pattr->va == NULL || pattr->ga == 0) {
        dpa_fipc_err("test_bd2_send_init failed to alloc mem for ringbuf!\n");
        return -1;
    }
    pattr->ptr_vaddr = dpa_fipc_alloc_coherent(sizeof(u32), &pattr->ptr_gaddr, GFP_KERNEL);
    if (pattr->ptr_vaddr == NULL || pattr->ptr_gaddr == 0) {
        dpa_fipc_err("test_bd2_send_init failed to alloc mem for ptr!\n");
        return -1;
    }

    ret = bsp_dpa_fipc_chn_open(&g_bd2_recv_hdl_1, pattr);
    if (ret) {
        dpa_fipc_err("DPA_FIPC_TEST_PRIVATE_SEND_1 open failed: %d\n", ret);
        return -2;
    }
    return 0;
}

int test_bd2_send_1(u32 len)
{
    int ret;
    void *msg = NULL;
    dpafipcsoc_ptr_t msg_pa = 0;
    msg = dpa_fipc_alloc_coherent(len, &msg_pa, GFP_KERNEL);
    if (msg == NULL || msg_pa == 0) {
        dpa_fipc_err("test_bd2_send_1 failed to alloc mem!\n");
        return -1;
    }

    (void)memset_s(msg, len, 0xc, len);
    ret = bsp_dpa_fipc_chn_blk2ring_send(g_bd2_send_hdl_1, msg_pa, len, 0);
    dpa_fipc_err("test_bd2_send_1 send: %d!\n", ret);
    return ret;
}