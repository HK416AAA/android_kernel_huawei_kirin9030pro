#include "hts_devinit.h"

#include <linux/fs.h>
#include <linux/device.h>
#include <linux/mutex.h>
#include <linux/list.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/irq.h>
#include <linux/irqchip/arm-gic-v3.h>
#include <linux/of_address.h>
#include <linux/platform_device.h>
#include <linux/io.h>
#include "hts_kernel_log.h"
#include "hts_common.h"
#include "hts_ioctl_services.h"
#include "hpd_interface.h"
#include "hts_pm.h"
#include "soc_hts_interface.h"
#include "hts_platform.h"
#include "hts_dmd_interface.h"
#include "hts_graph_manager.h"
#include "hts_graph_resource.h"

static struct class *g_hts_dev_class = NULL;
static unsigned int g_hts_major;

static void hts_dev_ctx_init(struct hts_dev_ctx *dev_ctx)
{
	int i;
	hts_drv_warn("start\n");
	struct hpd_registry *hpd = hts_get_hpd_registry();
	cond_return_void(hpd == NULL, "hpd is not registered\n");
	cond_return_void(hpd->hts_set_dev_ctx_events == NULL, "hts_set_dev_ctx_events is null\n");
	mutex_init(&dev_ctx->mtx);
	for (i = 0; i < SOC_IPMAX; i++) {
		atomic_set(&dev_ctx->dev_power_status[i], 1);
	}
	bitmap_zero(dev_ctx->res.event_bitmap, HTS_MAX_EVENT_NUM + 1);
	bitmap_zero(dev_ctx->res.rule_bitmap, HTS_MAX_RULE_NUM + 1);
	dev_ctx->res.rule_num = HTS_MAX_RULE_NUM;
	hpd->hts_set_dev_ctx_events();
	hts_drv_warn("end\n");
}

static void hts_dev_ctx_res_reset(struct hts_dev_ctx *dev_ctx)
{
	hts_drv_warn("start\n");
	struct hpd_registry *hpd = hts_get_hpd_registry();
	cond_return_void(hpd == NULL, "hpd is not registered\n");
	cond_return_void(hpd->hts_set_dev_ctx_events == NULL, "hts_set_dev_ctx_events is null\n");
	bitmap_zero(dev_ctx->res.event_bitmap, HTS_MAX_EVENT_NUM + 1);
	bitmap_zero(dev_ctx->res.rule_bitmap, HTS_MAX_RULE_NUM + 1);
	dev_ctx->res.rule_num = HTS_MAX_RULE_NUM;
	hpd->hts_set_dev_ctx_events();
	hts_drv_warn("end\n");
}

static int hts_dev_release(struct inode *inode, struct file *filep)
{
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	struct hpd_registry *hpd = hts_get_hpd_registry();
	unused(inode);
	unused(filep);
	hts_drv_warn("start\n");
	cond_return_error(hts_plat_get_info() == NULL, -EINVAL, "get platform info error\n");
	cond_return_error(hpd == NULL, -EINVAL, "hpd is not registered\n");
	cond_return_error(hpd->hts_resource_clear == NULL, -EINVAL, "hts_resource_clear is null\n");
    mutex_lock(&dev_ctx->mtx);
    hts_clear_graph_resource();
	hts_dev_ctx_res_reset(dev_ctx);
	hpd->hts_resource_clear();
	mutex_unlock(&dev_ctx->mtx);
	hts_drv_warn("success\n");
	return 0;
}

static int hts_dev_open(struct inode *inode, struct file *filep)
{
	unsigned int minor = iminor(inode);
	unused(filep);
	hts_drv_warn("hts start. minor = %u\n", minor);
	cond_return_error(minor >= HTS_DEV_NUM, -ENODEV,
					  "invalid hts minor num, minor = %u\n", minor);
	cond_return_error(hts_plat_get_info() == NULL, -ENODEV, "get platform info error\n");
	return 0;
}

static const struct file_operations hts_dev_fops = {
	.owner = THIS_MODULE,
	.open = hts_dev_open,
	.release = hts_dev_release,
	.unlocked_ioctl = hts_ioctl,
};

static char *hts_dev_node(struct device *dev, umode_t *mode)
{
	unused(dev);
	if (mode != NULL)
		*mode = 660;
	return NULL;
}

static int hts_dev_register(struct module *owner, uint8_t dev_id)
{	
	struct device *i_device = NULL;
	dev_t devno;
	int ret;
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	unused(dev_id);

	hts_drv_warn("start\n");

	dev_ctx->hts_cdev.owner = owner;
	devno = MKDEV(g_hts_major, 0);

	cdev_init(&dev_ctx->hts_cdev, &hts_dev_fops);

	ret = cdev_add(&dev_ctx->hts_cdev, devno, HTS_DEV_NUM);
	cond_return_error(ret != 0, -1, "hts cdev_add error\n");

	i_device = device_create(g_hts_dev_class, NULL, devno, NULL, "hts");
	cond_goto_error(i_device == NULL, device_create_fail, ret, -ENOMEM,
					"hts device_create error\n");

	dev_ctx->hts_dev = i_device;
	hts_drv_warn("success\n");

	return ret;

device_create_fail:
	cdev_del(&dev_ctx->hts_cdev);
	return ret;
}

static void hts_dev_unregister(void)
{
	dev_t devno = MKDEV(g_hts_major, 0);
	device_destroy(g_hts_dev_class, devno);
	class_destroy(g_hts_dev_class);
	g_hts_dev_class = NULL;
	unregister_chrdev_region(MKDEV(g_hts_major, 0), HTS_DEV_NUM);
}

int hts_dev_init(struct module *owner, uint8_t dev_id)
{
	int ret = 0;
	dev_t hts_dev = 0;
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
#ifdef HTS_DEBUG_EN
	struct hpd_registry *hpd = NULL;
#endif
	hts_drv_warn("hts dev %hhu init start\n", dev_id);

	ret = alloc_chrdev_region(&hts_dev, 0, HTS_DEV_NUM, "hts-cdev");
	cond_return_error(ret != 0, ret, "alloc hts chr dev region error\n");

	g_hts_major = MAJOR(hts_dev);
	g_hts_dev_class = class_create(owner, "hts-class");
	if (IS_ERR(g_hts_dev_class)) {
		hts_drv_err("class_create error\n");
		ret = -EINVAL;
		goto class_fail;
	}
	g_hts_dev_class->devnode = hts_dev_node;

	ret = hts_dev_register(owner, dev_id);
	cond_goto_error(ret != 0, hts_drv_register_fail, ret, -ENOMEM, "hts_drv_register failed\n");
	hts_dev_ctx_init(dev_ctx);

	ret = hts_powerup();
	cond_goto_error(ret != 0, hts_drv_register_fail, ret, -ENOMEM, "hts poweron failed\n");
	if(hts_dmd_init() != 0)
		hts_drv_err("hts_dmd_init failed\n");

#ifdef HTS_DEBUG_EN
	hpd = hts_get_hpd_registry();
	cond_goto_error(hpd == NULL, hts_drv_register_fail, ret, -1, "hpd is not registered\n");
	if (hpd->hts_dbg_en_open_cfg != NULL)
		hpd->hts_dbg_en_open_cfg();
#endif

	return ret;
hts_drv_register_fail:
	class_destroy(g_hts_dev_class);
	g_hts_dev_class = NULL;
class_fail:
	unregister_chrdev_region(hts_dev, HTS_DEV_NUM);
	return ret;
}

void hts_dev_exit(void)
{
	struct hts_dev_ctx *dev_ctx = hts_get_dev_ctx();
	mutex_destroy(&dev_ctx->mtx);
	cdev_del(&dev_ctx->hts_cdev);
	hts_dev_unregister();
	hts_dmd_exit();
}
