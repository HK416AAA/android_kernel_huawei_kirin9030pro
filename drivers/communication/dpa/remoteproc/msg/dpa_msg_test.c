#include <uapi/linux/sched/types.h> /* struct sched_param */
#include <linux/types.h>
#include <linux/dma-mapping.h>
#include <linux/slab.h>
#include "bsp_dpa_msg.h"
#include "dpa_msg_plat.h"

struct dpa_msg_chn_hdl *g_test_dpa_msg_hdl = NULL;

int dpa_msg_test_cbk(const struct dpa_msg_addr *src, void *msg, unsigned len)
{

    dpa_msg_err("src: [%d]%d\n", src->core, src->chnid);
    dpa_msg_err("recv msg len: %d\n", len);
    dpa_msg_err("recv content first word: 0x%x\n", *(u32 *)msg);
    return 0;
}

int dpa_msg_test_init(void)
{
    int ret = 0;
    struct dpa_msgchn_attr attr;
    bsp_dpa_msgchn_attr_init(&attr);

    attr.chnid = DPA_MSG_CHN_LOOP0;
    attr.coremask = DPA_MSG_CORE_MASK(DPA_MSG_CORE_DPA);
    attr.lite_notify = dpa_msg_test_cbk;

    ret = bsp_dpa_msg_lite_open(&g_test_dpa_msg_hdl, &attr);
    return ret;
}

int dpa_msg_test_send(u32 len)
{
    void *buf;
    int ret;
    struct dpa_msg_addr dst;

    buf = kmalloc(len, GFP_KERNEL);
    if (buf == NULL) {
        dpa_msg_err("dpa_msg_test_send malloc failed\n");
        return -1;
    }
    (void)memset_s(buf, len, 0xb, len);
    dst.core = DPA_MSG_CORE_DPA;
    dst.chnid = DPA_MSG_CHN_LOOP0;
    ret = bsp_dpa_msg_lite_sendto(g_test_dpa_msg_hdl, &dst, buf, len);
    dpa_msg_err("bsp_dpa_msg_lite_sendto ret: %d\n", ret);
    kfree(buf);
    return ret;
}