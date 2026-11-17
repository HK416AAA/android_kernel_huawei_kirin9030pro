
#include <linux/workqueue.h>
#include <linux/spinlock.h>
#include <linux/semaphore.h>
#include <linux/printk.h>
#include <securec.h>
#include <bsp_dpa_client.h>
#include "client.h"
#include "packer_helper.h"
#include "id.h"

struct mdm_cfg_info {
    unsigned int is_link;
    unsigned int m_id;
    unsigned int ps_id;
    unsigned int fc_head;
    unsigned int iface_id;
};

struct mdm_cfg_reply {
    struct semaphore *sema;
    unsigned char *data;
    unsigned int len;
};

static struct workqueue_struct* g_mdm_cfg_work_queue;
static struct delayed_work g_mdm_cfg_work;
static struct mdm_cfg_info g_cur_cfg;
static spinlock_t g_cfg_lock;

static void dpa_modem_cfg_request_cb(void *priv, unsigned char *data, unsigned int len)
{
    struct mdm_cfg_reply *reply = (struct mdm_cfg_reply *)priv;
    PACKER_BUFFER(packer, data, len);
    packer_buffer_pop_s32(&packer, (int *)reply->data);
    if (reply->len != len) {
        printk("dpa_modem_cfg reply len:%d err, local len:%d\n", len, reply->len);
    }
    up(reply->sema);
}

static void dpa_pack_modem_cfg(struct packer_buffer *packer, struct mdm_cfg_info* cfg)
{
    /* refer struct mdm_cfg_info */
    packer_buffer_append_u32(packer, cfg->is_link);
    packer_buffer_append_u32(packer, cfg->m_id);
    packer_buffer_append_u32(packer, cfg->ps_id);
    packer_buffer_append_u32(packer, cfg->fc_head);
    packer_buffer_append_u32(packer, cfg->iface_id);
}

int dpa_modem_cfg(struct mdm_cfg_info* cfg)
{
    int ret = 0;

    unsigned char data[sizeof(struct dpa_service_msg) + sizeof(struct mdm_cfg_info)] = { 0 };
    DEFINE_SEMAPHORE(sema);
    struct mdm_cfg_reply reply = {
        .sema = &sema,
        .data = (unsigned char *)&ret,
        .len = sizeof(ret),
    };

    sema_init(&sema, 0);
    PACKER_BUFFER(packer, data, sizeof(data));
    packer_begin_callback(&packer, SERVICE_PROTO_MDM_CFG, MODEM_CFG_LINK, dpa_modem_cfg_request_cb, &reply);
    dpa_pack_modem_cfg(&packer, cfg);
    packer_end(&packer);

    bsp_dpa_client_request((struct dpa_service_msg *)packer.base, packer.curr);
    down(&sema);

    return ret;
}

void mdrv_dpa_modem_cfg_link(unsigned int m_id, unsigned int ps_id, unsigned int fc_head, unsigned int iface_id)
{
    unsigned long flags;

    spin_lock_irqsave(&g_cfg_lock, flags);
    g_cur_cfg.is_link = 1;
    g_cur_cfg.m_id = m_id;
    g_cur_cfg.ps_id = ps_id;
    g_cur_cfg.fc_head = fc_head;
    g_cur_cfg.iface_id = iface_id;
    spin_unlock_irqrestore(&g_cfg_lock, flags);

    queue_delayed_work(g_mdm_cfg_work_queue, &g_mdm_cfg_work, 0);
}

void mdrv_dpa_modem_cfg_release(void)
{
    unsigned long flags;

    spin_lock_irqsave(&g_cfg_lock, flags);
    g_cur_cfg.is_link = 0;
    g_cur_cfg.m_id = 0;
    g_cur_cfg.ps_id = 0;
    g_cur_cfg.fc_head = 0;
    g_cur_cfg.iface_id = 0;
    spin_unlock_irqrestore(&g_cfg_lock, flags);

    queue_delayed_work(g_mdm_cfg_work_queue, &g_mdm_cfg_work, 0);
}

static void dpa_modem_cfg_work(struct work_struct *work)
{
    int ret;

    printk("dpa_modem_cfg_work is_link:%d, m_id:%d, ps_id:%d, fc_head:%d, iface_id:%d\n", 
        g_cur_cfg.is_link, g_cur_cfg.m_id, g_cur_cfg.ps_id, g_cur_cfg.fc_head, g_cur_cfg.iface_id);
    ret = dpa_modem_cfg(&g_cur_cfg);
    if (ret) {
        printk("dpa_modem_cfg fail:%d\n", ret);
    }
}

int dpa_modem_cfg_init(void)
{
    g_mdm_cfg_work_queue = create_singlethread_workqueue("dpa_mdm_cfg");
    if (!g_mdm_cfg_work_queue) {
        printk("dpa_modem_cfg_init fail\n");
        return -1;
    }
    INIT_DELAYED_WORK(&g_mdm_cfg_work, dpa_modem_cfg_work);
    spin_lock_init(&g_cfg_lock);
    return 0;
}

#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
module_init(dpa_modem_cfg_init);
#endif