/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/of_device.h>
#include <linux/remoteproc.h>
#include <linux/firmware.h>
#include <linux/jiffies.h>
#include <linux/printk.h>
#include <linux/jiffies.h>
#include <securec.h>
#include <bsp_print.h>
#include <bsp_slice.h>
#include <bsp_rproc.h>
#include <bsp_dpa_sysctrl.h>
#include <bsp_dpa_chr.h>
#include <bsp_dump.h>
#include <bsp_dra.h>
#include <bsp_memory.h>
#include "clk.h"
#include "mem_layout.h"
#include "rproc.h"
#include "nve_ap_kernel_interface.h"
#include <bsp_file_ops.h>
#include <bsp_dpa_loader.h>

#define RPROC_INIT_WAIT_TIMEOUT msecs_to_jiffies(10000)
static LIST_HEAD(dpa_wakeup_sources);
static DEFINE_SPINLOCK(dpa_events_lock);
#define WIFI_MO_FILE "/vendor/communication/dpa/firmware/mp1x_wifi.mo"

const struct firmware *g_dpa_fw;
struct rproc *g_dpa_rproc;
struct rproc_dpa g_rproc_dpa;

#ifdef CONFIG_DPA_PM
void bsp_rproc_reg_dpa_powerup_cb(dpa_powerup_cb cb)
{
    g_rproc_dpa.cb = cb;
}

void bsp_rproc_set_event(unsigned int event)
{
    set_bit(event, (void *)&g_rproc_dpa.event);
    wake_up(&g_rproc_dpa.wqueue);
}
int bsp_rproc_dpa_get_stat(void)
{
    if (g_dpa_rproc != NULL) {
        return g_dpa_rproc->state;
    }
    return RPROC_OFFLINE;
}
#endif

static int dpa_try_load_image(struct device *dev)
{
    int ret;
    const struct firmware *fw = NULL;
    unsigned int *mo_size = NULL;
    phy_addr_t addr;
    unsigned int size;

    mo_size = (unsigned int *)mdrv_mem_share_get("usshm_dpa_mo_size", &addr, &size, SHM_UNSEC);
    if (mo_size == NULL) {
        dpa_pr_err("get usshm_dpa_mo_size mem fail\n");
        return -1;
    }

    if (bsp_eaccess(WIFI_MO_FILE) != 0) {
        dpa_pr_err("mp1x_wifi.mo not existed\n");
        *mo_size = 0;
        return 0;
    }

    // 加载.mo进内核内存
    ret = request_firmware(&fw, "mp1x_wifi.mo", dev);
    if (ret) {
        dpa_pr_err("request_firmware add err %d\n", ret);
        return ret;
    }

    if (fw->size <= DPA_SECBOOT_VRL_SIZE) {
        dpa_pr_err("fw->size err:%u\n", (unsigned int)fw->size);
        release_firmware(fw);
        return -1;
    }

    ret = bsp_dpa_loader_copy_and_verify_image(DPA_IMG_WIFI_MO, (const char *)((fw)->data), (fw)->size);
    if (ret) {
        dpa_pr_err("fail to verify wifi.mo,ret=0x%x\n", ret);
        release_firmware(fw);
        return ret;
    }

    *mo_size = fw->size - DPA_SECBOOT_VRL_SIZE;

    release_firmware(fw);

    return ret;
}

int dpa_load_synamic_img(struct device *dev)
{
    int ret;

    dpa_pr_err("dpa_load_synamic_img start\n");
    ret = dpa_try_load_image(dev);
    if (ret != 0) {
        return ret;
    }
    dpa_pr_err("dpa_load_synamic_img ok\n");

    return 0;
}

static int dpa_verify_dpa_fw(const struct firmware *fw)
{
    int ret = bsp_dpa_loader_copy_and_verify_image(DPA_IMG_FIRMWARE, (const char *)fw->data,
        fw->size);
    if (ret) {
        dpa_pr_err("dpa verify dpa fw fail, ret=%d.\n", ret);
    }
    return ret;
}

int dpa_rproc_start(struct rproc *rproc)
{
    int ret;
    const struct firmware *fw = g_dpa_fw;
    struct device *dev = rproc->dev.parent;

    dpa_pr_err("dpa rproc start\n");
    ret = dpa_enable_clks();
    if (ret) {
        return ret;
    }

    dpa_mem_layout_config();

    ret = dpa_load_synamic_img(dev);
    if (ret) {
        return ret;
    }

    // 镜像校验，上电，加载，解复位
    ret = dpa_verify_dpa_fw(fw);
    if (ret) {
        return ret;
    }

    // DPA已完成上电解复位
    if (g_rproc_dpa.cb != NULL) {
        g_rproc_dpa.cb(RPROC_DPA_INIT_STEP2);
    }

    ret = wait_event_timeout(g_rproc_dpa.wqueue, test_bit(RPROC_EVENT_DPA_FW_MODULE_INIT_DONE, (void *)&g_rproc_dpa.event)
                                && test_bit(RPROC_EVENT_DPA_HOST_INIT_AFTER_FW_DRST_DONE, (void *)&g_rproc_dpa.event)
                                , RPROC_INIT_WAIT_TIMEOUT);
    if (ret == 0) {
        dpa_pr_err("dpa init timeout\n");
    }

    if (g_rproc_dpa.cb != NULL) {
        g_rproc_dpa.cb(RPROC_DPA_INIT_STEP3);
    }

    return 0;
}

// 单独复位使用,启动
int dpa_rproc_boot(struct rproc *rproc)
{
    dpa_pr_err("dpa rproc boot\n");
    return rproc_boot(rproc);
}

// 单独复位使用,复位
int dpa_rproc_stop(struct rproc *rproc)
{
    dpa_pr_err("dpa rproc stop\n");

    if (bsp_dpa_loader_reset()) {
        return -1;
    }
    dpa_disable_clks();

    return 0;
}

int dpa_rproc_attach(struct rproc *rproc)
{
    dpa_pr_err("dpa rproc attach\n");
    return 0;
}

void dpa_rproc_kick(struct rproc *rproc, int vqid)
{
    dpa_pr_err("dpa rproc kick\n");
}

int dpa_sanity_check(struct rproc *rproc, const struct firmware *fw)
{
    dpa_pr_err("dpa sanity check\n");
    return 0;
}

int dpa_load(struct rproc *rproc, const struct firmware *fw)
{
    g_dpa_fw = fw;
    dpa_pr_err("dpa load\n");
    return 0;
}

u64 dpa_get_boot_addr(struct rproc *rproc, const struct firmware *fw)
{
    dpa_pr_err("dpa get boot addr\n");
    return 0;
}

static const struct rproc_ops dpa_rproc_ops = {
    .start             = dpa_rproc_start,
    .stop              = dpa_rproc_stop,
    .attach            = dpa_rproc_attach,
    .kick              = dpa_rproc_kick,
    .sanity_check      = dpa_sanity_check,
    .load              = dpa_load,
    .get_boot_addr     = dpa_get_boot_addr,
};

void bsp_rproc_report_crash(void)
{
    rproc_report_crash(g_dpa_rproc, RPROC_FATAL_ERROR);
}

int bsp_rproc_boot(void)
{
    dpa_pr_err("dpa boot start\n");
    return rproc_boot(g_dpa_rproc);
}
 
int bsp_rproc_stop(void)
{
    rproc_shutdown(g_dpa_rproc);
    return 0;
}

/* default auto-suspend delay (ms) */
#define DEFAULT_AUTOSUSPEND_DELAY 1000
static int dpa_rproc_probe(struct device *dev)
{
    struct rproc *rproc = NULL;
    struct rproc_dpa *rproc_dpa = &g_rproc_dpa;
    int ret;

    rproc = devm_rproc_alloc(dev, "dpa", &dpa_rproc_ops, "dpa_firmware.bin", 0);
    if (rproc == NULL) {
        dpa_pr_err("%s: devm_rproc_alloc fail\n", __func__);
        return -ENOMEM;
    }

    dev_set_name(&rproc->dev, "remoteproc%s", "_dpa");
    g_dpa_rproc = rproc;
    rproc->auto_boot = false;
    rproc->has_iommu = false;

    ret = devm_rproc_add(dev, rproc);
    if (ret != 0) {
        dpa_pr_err("%s: devm_rproc_add fail. ret %d\n", __func__, ret);
        return ret;
    }

    device_init_wakeup(rproc->dev.parent, true);
    dev_set_drvdata(dev, rproc);

    rproc_dpa->autosuspend_delay = DEFAULT_AUTOSUSPEND_DELAY;

    return 0;
}

int dpa_load_dtb(struct platform_device *pdev)
{
    int ret;
    const struct firmware *fw = NULL;
    int ovcs_id = 0;
    u32 val;
    struct device_node *parent_node = NULL;
    const char *dpa_name = "dpa,demo";

    dpa_pr_err("dpa_load_dtb\n");
    ret = request_firmware(&fw, "dpa_dto.bin", &pdev->dev);
    if (ret) {
        dpa_pr_err("request_firmware add err %d\n", ret);
        return ret;
    }

    dpa_pr_err("request_firmware %u\n", (unsigned int)fw->size);
    ret = of_overlay_fdt_apply((void *)fw->data, fw->size, &ovcs_id);
    release_firmware(fw);
    if (ret) {
        dpa_pr_err("of_overlay_fdt_apply err %d\n", ret);
        return ret;
    }

    parent_node = of_find_compatible_node(NULL, NULL, dpa_name);
    if (parent_node == NULL) {
        dpa_pr_err("%s of_find_compatible_node didn't find !\n", dpa_name);
        return -1;
    }
    ret = of_property_read_u32(parent_node, "dma_mask_bit", &val);
    if (ret) {
        dpa_pr_err("dma_mask_bit failed!\n");
        return -1;
    }
    pr_err("dma_mask_bit %d\n", val);

    return 0;
}

int dpa_clk_init(struct platform_device *pdev)
{
    struct device_node *np = NULL;

    np = of_find_compatible_node(NULL, NULL, "dpa,pm");
    if (np == NULL) {
        dpa_pr_err("dpa,pm dts read fail\n");
        return -1;
    }

    g_rproc_dpa.np = np;

    return dpa_init_clks(pdev, np);
}

static int dpa_probe(struct platform_device *pdev)
{
    int ret;
    struct rproc_dpa *rproc_dpa = &g_rproc_dpa;

    dpa_pr_err("rproc probe init begin \n");
    ret = dpa_load_dtb(pdev);
    if (ret) {
        return ret;
    }

    dpa_mem_layout_init();

    ret = dpa_clk_init(pdev);
    if (ret) {
        dpa_pr_err("clk init fail\n");
        return ret;
    }

    rproc_dpa->ws = wakeup_source_register(NULL, "dpa_awake");
    if (rproc_dpa->ws == NULL) {
        dpa_pr_err("rproc_dpa wakeup_source_register fail\n");
        return -1;
    }

    of_dma_configure(&pdev->dev, NULL, true);
    dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64));
    rproc_dpa->dev = &pdev->dev;
    init_waitqueue_head(&rproc_dpa->wqueue);
    dpa_pr_err("rproc probe init end \n");
    return 0;
}

int dpa_rproc_add(void)
{
    int ret;
    struct device *dev = g_rproc_dpa.dev;

    ret = dpa_rproc_probe(dev);
    if (ret) {
        dpa_pr_err("rproc creat fail\n");
    }
    return ret;
}

static int dpa_remove(struct platform_device *pdev)
{
    rproc_del(g_dpa_rproc);
    rproc_free(g_dpa_rproc);

    return 0;
}

static struct platform_driver g_dpa_pltfm_driver = {
    .probe = dpa_probe,
    .remove = dpa_remove,
    .driver = {
        .name = "dpa_host",
        .owner = THIS_MODULE,
        .probe_type = PROBE_FORCE_SYNCHRONOUS,
    },
};

static struct platform_device g_dpa_device = {
    .name = "dpa_host",
    .id = -1,
    .num_resources = 0,
};

struct dpa_wakeup_source *dpa_wakeup_source_register(const char *name);
int dpa_wakeup_source_unregister(struct dpa_wakeup_source *ws);
int dpa_pm_stay_awake(struct dpa_wakeup_source *ws);
int dpa_pm_stay_awake_with_autosuspend(struct dpa_wakeup_source *ws, unsigned int msec);
int dpa_pm_relax(struct dpa_wakeup_source *ws);

static struct dpa_rproc_ops g_rproc_ops = {
    .dpa_get_status = bsp_rproc_dpa_get_stat,
    .dpa_wakeup_source_register = dpa_wakeup_source_register,
    .dpa_wakeup_source_unregister = dpa_wakeup_source_unregister,
    .dpa_pm_stay_awake = dpa_pm_stay_awake,
    .dpa_pm_stay_awake_with_autosuspend = dpa_pm_stay_awake_with_autosuspend,
    .dpa_pm_relax = dpa_pm_relax,
};

int dpa_rproc_init(void)
{
    if (platform_device_register(&g_dpa_device)) {
        dpa_pr_err("dpa dev register fail.\n");
        return -1;
    }

    if (platform_driver_register(&g_dpa_pltfm_driver)) {
        dpa_pr_err("dpa drv register fail.\n");
        return -1;
    }

    if (bsp_dpa_register(&g_rproc_ops)) {
        dpa_pr_err("dpa rproc api register fail.\n");
        return -1;
    }

    return 0;
}

struct dpa_wakeup_source *dpa_wakeup_source_register(const char *name)
{
    unsigned long flags;
    struct dpa_wakeup_source *ws;
    const char *ws_name;

    ws = kzalloc(sizeof(*ws), GFP_KERNEL);
    if (!ws) {
        return NULL;
    }

    ws_name = kstrdup_const(name, GFP_KERNEL);
    if (!ws_name) {
        return NULL;
    }
    ws->name = ws_name;

    spin_lock_init(&ws->lock);
    spin_lock_irqsave(&dpa_events_lock, flags);
    list_add_tail(&ws->entry, &dpa_wakeup_sources);
    spin_unlock_irqrestore(&dpa_events_lock, flags);
    ws->valid = true;
    return ws;
}
EXPORT_SYMBOL(dpa_wakeup_source_register);

int dpa_wakeup_source_unregister(struct dpa_wakeup_source *ws)
{
    unsigned long flags;

    if (!ws || !ws->valid) {
        return -ENOMEM;
    }

    spin_lock_irqsave(&dpa_events_lock, flags);
    list_del(&ws->entry);
    spin_unlock_irqrestore(&dpa_events_lock, flags);
    kfree_const(ws->name);
    kfree(ws);

    return 0;
}
EXPORT_SYMBOL(dpa_wakeup_source_unregister);

/*
    整体实现使用runtime进制来控制是否配置正常，不在接口里面额外再冗余重新封装设备状态
*/
int dpa_pm_stay_awake(struct dpa_wakeup_source *ws)
{
    return 0;
}
EXPORT_SYMBOL(dpa_pm_stay_awake);

int dpa_pm_stay_awake_with_autosuspend(struct dpa_wakeup_source *ws, unsigned int msec)
{
    return 0;
}
EXPORT_SYMBOL(dpa_pm_stay_awake_with_autosuspend);

int dpa_pm_relax(struct dpa_wakeup_source *ws)
{
    return 0;
}
EXPORT_SYMBOL(dpa_pm_relax);
