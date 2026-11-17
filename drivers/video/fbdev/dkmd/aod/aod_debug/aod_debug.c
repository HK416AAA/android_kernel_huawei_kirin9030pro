/* Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 and
* only version 2 as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
* GNU General Public License for more details.
*
*/
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/major.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/mman.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/kmod.h>
#include <linux/err.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/dma-buf.h>
#include <linux/pm_wakeup.h>
#include <asm/fb.h>
#include <platform_include/smart/linux/iomcu_ipc.h>
#include <platform_include/smart/linux/base/ap/protocol.h>
#include <securec.h>
#include "contexthub_route.h"
#include "dpu_sh_aod.h"
#include "aod_debug.h"

#define DIGITS_COUNT (10)

#define AOD_DEBUG_IOCTL_GET_PANEL_INFO		_IOW(0xDB, 0x01, struct current_resolution)
#define AOD_DEBUG_IOCTL_SET_LAYER_CONFIG 	_IOW(0xDB, 0x02, struct test_layer_config)
#define AOD_DEBUG_IOCTL_PREPARE_TASK 		_IOW(0xDB, 0x03, struct test_task_config)
#define AOD_DEBUG_IOCTL_EXCUTE_TASK_AUTO 	_IOW(0xDB, 0x04, struct test_task_config)
#define AOD_DEBUG_IOCTL_OPEN_DPU_DBG		_IO(0xDB, 0x05)
#define AOD_DEBUG_IOCTL_START_TEST 			_IO(0xDB, 0x06)
#define AOD_DEBUG_IOCTL_STOP_TEST 			_IO(0xDB, 0x07)

#define IOMCU_DBG_CMD_DPU_DBG (47)

enum dpu_test_op {
	OP_DPU_DBG_OPEN = 0,
    OP_DPU_DBG_CONFIG_LAYER,
    OP_DPU_DBG_PREPARE_TASK,
	OP_DPU_DBG_START,
    OP_DPU_DBG_STOP,
};

struct hdm_rect {
	int32_t left;
	int32_t top;
	int32_t right;
	int32_t bottom;
};

struct hdm_layer {
	int32_t type;
	int32_t format;
	uint32_t glb_alpha;
	uint32_t blending_mode;
	uint32_t smmu_enable;
	uint32_t need_arsr;

	uint32_t buffer;
	uint32_t stride;
	uint32_t u_offset;
	uint32_t v_offset;
	uint32_t u_stride;
	uint32_t v_stride;
	uint32_t src_color_mode;
	uint32_t dst_color_mode;
	struct hdm_rect src_rect;
	struct hdm_rect dst_rect;
};

uint32_t g_aod_debug_log_level = UKMD_LOG_LVL_INFO;
struct test_layer_config *g_layer_config = NULL;
struct aod_debug_data_t *g_aod_debug_data = NULL;
struct dma_buf *g_layer_dma_buf = NULL;
struct dma_buf *g_buffer_dma_buff = NULL;
struct dpu_dbg_para *g_dbg_para = NULL;

static int aod_debug_send_cmd_to_sensorhub(void *data, uint32_t data_len)
{
	int ret = 0;
	struct write_info pkg_ap;

	if(g_dbg_para == NULL || data_len == 0) {
		DPU_AOD_DEBUG_ERR("data is NULL or data_len is 0\n");
        return -1;
	}

	memset_s(&pkg_ap, sizeof(pkg_ap), 0, sizeof(pkg_ap));
	memcpy_s(g_dbg_para, data_len, data, data_len);

	DPU_AOD_DEBUG_INFO("data info:%d, %d, %d, %d, %d, %d\n", g_dbg_para->data[0], g_dbg_para->data[1],
		g_dbg_para->data[2], g_dbg_para->data[3], g_dbg_para->data[4], g_dbg_para->data[5]);

	pkg_ap.tag = TAG_DBG;
	pkg_ap.cmd = IOMCU_DBG_CMD_DPU_DBG;
	pkg_ap.wr_buf = (const void *)g_dbg_para;
	pkg_ap.wr_len = sizeof(struct dpu_dbg_para);

	DPU_AOD_DEBUG_DBG("aod_debug_send_cmd_to_sensorhub:%d,%d\n", pkg_ap.tag, pkg_ap.cmd);
	ret = write_customize_cmd(&pkg_ap, NULL, false);
	if (ret)
		DPU_AOD_DEBUG_ERR("ipc failed, cmd:tag is %d, cmd is %d\n",
			pkg_ap.tag, pkg_ap.cmd);

	return ret;
}

static int aod_debug_get_panel_info(struct aod_debug_data_t *test_data, void __user *argp)
{
	struct current_resolution res = {0};

	res.xres = test_data->x_res;
    res.yres = test_data->y_res;
    res.bpp = test_data->bpp;
	if (copy_to_user(argp, &res, sizeof(struct current_resolution))){
		DPU_AOD_DEBUG_ERR("copy_to_user failed\n");
        return -1;
	}

	return 0;
}

static int aod_debug_map_layer_fd(struct device *dev)
{
	struct dma_buf_attachment *attach = NULL;
	struct sg_table *table = NULL;
	uint64_t lyr_addr;

	g_layer_dma_buf = dma_buf_get(g_layer_config->layer_addr);
	if (IS_ERR(g_layer_dma_buf)) {
		DPU_AOD_DEBUG_ERR("Invalid file handle %d\n", g_layer_config->layer_addr);
		return -EFAULT;
	}
	attach = dma_buf_attach(g_layer_dma_buf, dev);
	if (IS_ERR(attach)) {
		dma_buf_put(g_layer_dma_buf);
		return -EFAULT;
	}
	table = dma_buf_map_attachment(attach, DMA_BIDIRECTIONAL);
	if (IS_ERR(table)) {
		dma_buf_detach(g_layer_dma_buf, attach);
		dma_buf_put(g_layer_dma_buf);
		return -EFAULT;
	}
	lyr_addr = sg_phys(table->sgl); /* [false alarm] */
	uint64_t va_addr = sg_virt(table->sgl);
	dma_buf_unmap_attachment(attach, table, DMA_BIDIRECTIONAL);
	dma_buf_detach(g_layer_dma_buf, attach);
	dma_buf_put(g_layer_dma_buf);
	g_layer_config->layer_addr = lyr_addr;
	DPU_AOD_DEBUG_INFO("layer_addr pa = 0x%x, va = 0x%x", g_layer_config->layer_addr, va_addr);

	struct hdm_layer *layer = (struct hdm_layer *)(uintptr_t)va_addr;
	DPU_AOD_DEBUG_INFO("layer->type = %d, layer->format = %d, layer->glb_alpha = %d, layer->blending_mode = %d, "
						"layer->smmu_enable = %d, layer->need_arsr = %d\n"
						"layer->buffer = 0x%x, layer->stride = %d, layer->u_offset = %d, layer->v_offset = %d, "
						"layer->u_stride = %d, layer->v_stride = %d\n",
						layer->type, layer->format, layer->glb_alpha, layer->blending_mode,
						layer->smmu_enable, layer->need_arsr,
						layer->buffer, layer->stride, layer->u_offset, layer->v_offset,
						layer->u_stride, layer->v_stride);

	return 0;
}

static int aod_debug_map_buffer_fd(struct device *dev)
{
	struct dma_buf_attachment *attach = NULL;
	struct sg_table *table = NULL;
	uint64_t buf_addr;
	uint32_t buf_len;

	buf_len = g_layer_config->buff_len * g_layer_config->layer_count;
	DPU_AOD_DEBUG_INFO("Single buffer size %d, total %d\n", g_layer_config->buff_len, buf_len);

	if (g_layer_config->is_smmu_enable == 1) {
		DPU_AOD_DEBUG_INFO("smmu case\n");
		g_buffer_dma_buff = dma_buf_get(g_layer_config->buff_addr);
		if (IS_ERR(g_buffer_dma_buff)) {
			DPU_AOD_DEBUG_ERR("Invalid file handle %d\n", g_layer_config->buff_addr);
			return -EFAULT;
		}

		if (dpu_sh_dmabuf_map_iova(&buf_addr, g_buffer_dma_buff, buf_len)) {
			DPU_AOD_DEBUG_ERR("dpu_sh_dmabuf_map_iova fail\n");
			dma_buf_put(g_buffer_dma_buff);
			return -EFAULT;
		}

		DPU_AOD_DEBUG_INFO("map iova success, buf_addr = 0x%llx, size = %d\n", buf_addr, buf_len);
	} else {
		DPU_AOD_DEBUG_INFO("ion case\n");
		g_buffer_dma_buff = dma_buf_get(g_layer_config->buff_addr);
		if (IS_ERR(g_buffer_dma_buff)) {
			DPU_AOD_DEBUG_ERR("Invalid file handle %d\n", g_layer_config->buff_addr);
			return -EFAULT;
		}
		attach = dma_buf_attach(g_buffer_dma_buff, dev);
		if (IS_ERR(attach)) {
			DPU_AOD_DEBUG_ERR("dma_buf_attach fail\n");
			dma_buf_put(g_buffer_dma_buff);
			return -EFAULT;
		}
		table = dma_buf_map_attachment(attach, DMA_BIDIRECTIONAL);
		if (IS_ERR(table)) {
			DPU_AOD_DEBUG_ERR("dma_buf_map_attachment fail\n");
			dma_buf_detach(g_buffer_dma_buff, attach);
			dma_buf_put(g_buffer_dma_buff);
			return -EFAULT;
		}
		buf_addr = sg_phys(table->sgl);
		uint32_t* va_addr = (uint32_t *)(uintptr_t)sg_virt(table->sgl);
		dma_buf_unmap_attachment(attach, table, DMA_BIDIRECTIONAL);
		dma_buf_detach(g_buffer_dma_buff, attach);
		dma_buf_put(g_buffer_dma_buff);

		DPU_AOD_DEBUG_INFO("buffer read: 0x%x, 0x%x, 0x%x, 0x%x, 0x%x",
							*va_addr, *(va_addr++), *(va_addr++), *(va_addr++), *(va_addr++));
	}

	DPU_AOD_DEBUG_INFO("is_smmu_enable = %d, buffer_addr = 0x%llx", g_layer_config->is_smmu_enable, buf_addr);
	g_layer_config->buff_addr = buf_addr;
	return 0;
}

static int aod_debug_set_layer_config(struct aod_debug_data_t *test_data, void __user *argp)
{
	int ret;

	DPU_AOD_DEBUG_INFO("in\n");

	if ((g_layer_config == NULL) || (argp == NULL)) {
		DPU_AOD_DEBUG_ERR("g_layer_config or argp is NULL\n");
		return -1;
	}

	if (copy_from_user(g_layer_config, argp, sizeof(struct test_layer_config))) {
		DPU_AOD_DEBUG_ERR("copy_from_user failed\n");
		return -1;
	}
	g_layer_config->sub_cmd = OP_DPU_DBG_CONFIG_LAYER;

	// map layer fd
	ret = aod_debug_map_layer_fd(test_data->dev);
	if (ret) {
		DPU_AOD_DEBUG_ERR("map layer fd failed\n");
        return -1;
    }

	// map buffer fd
	ret = aod_debug_map_buffer_fd(test_data->dev);
	if (ret) {
		DPU_AOD_DEBUG_ERR("map buffer fd failed\n");
        return -1;
    }

	DPU_AOD_DEBUG_INFO("g_layer_config: %p, send to mcu config: sub_cmd %d, layer_count %d,"
						"smmu_enable %d, layer_addr 0x%x, buff_addr 0x%x, buff_len %d\n",
						g_layer_config, g_layer_config->sub_cmd, g_layer_config->layer_count,
						g_layer_config->is_smmu_enable, g_layer_config->layer_addr, g_layer_config->buff_addr,
						g_layer_config->buff_len);

	ret = aod_debug_send_cmd_to_sensorhub((void *)g_layer_config, sizeof(struct test_layer_config));
	if (ret) {
		DPU_AOD_DEBUG_ERR("send cmd to mcu failed\n");
        return -1;
	}
	g_aod_debug_data->is_layer_configed = true;

	return ret;
}

static int aod_debug_prepare_task(void __user *argp)
{
	struct test_task_config task_config = {0};

	if (!g_aod_debug_data->is_layer_configed) {
		DPU_AOD_DEBUG_ERR("layer is not configured\n");
        return -1;
	}

	if (argp == NULL) {
		DPU_AOD_DEBUG_ERR("argp is NULL\n");
        return -1;
    }

	if (copy_from_user(&task_config, argp, sizeof(struct test_task_config))) {
        DPU_AOD_DEBUG_ERR("copy_from_user failed\n");
        return -1;
	}
	task_config.sub_cmd = OP_DPU_DBG_PREPARE_TASK;

	DPU_AOD_DEBUG_INFO("prepare task, task_config 0x%x, frame_config 0x%x\n",
                        task_config.task_config, task_config.frame_config);
	return aod_debug_send_cmd_to_sensorhub(&task_config, sizeof(struct test_task_config));
}

static int aod_debug_open_dpu_dbg (void)
{
	uint32_t sub_cmd = OP_DPU_DBG_OPEN;

	if (!g_aod_debug_data->is_layer_configed) {
		DPU_AOD_DEBUG_ERR("layer is not configured\n");
        return -1;
	}

	DPU_AOD_DEBUG_INFO("open mcu dpu debug\n");
	return aod_debug_send_cmd_to_sensorhub(&sub_cmd, sizeof(uint32_t));
}

static int aod_debug_start_test(void)
{
	uint32_t sub_cmd = OP_DPU_DBG_START;

	if (!g_aod_debug_data->is_layer_configed) {
		DPU_AOD_DEBUG_ERR("layer is not configured\n");
        return -1;
	}

	DPU_AOD_DEBUG_INFO("start test\n");
	return aod_debug_send_cmd_to_sensorhub(&sub_cmd, sizeof(uint32_t));
}

static int aod_debug_stop_test(void)
{
	uint32_t sub_cmd = OP_DPU_DBG_STOP;

	if (!g_aod_debug_data->is_layer_configed) {
		DPU_AOD_DEBUG_ERR("layer is not configured\n");
        return -1;
	}

	DPU_AOD_DEBUG_INFO("stop test\n");
	return aod_debug_send_cmd_to_sensorhub(&sub_cmd, sizeof(uint32_t));
}

static long aod_debug_ioctl(struct file* file, unsigned int cmd, unsigned long arg)
{
	int ret = 0;
	void __user *argp = (void __user *)(uintptr_t)arg;

	if (g_aod_debug_data == NULL) {
		DPU_AOD_DEBUG_ERR("g_aod_debug_data is NULL\n");
        return -1;
    }
	mutex_lock(&g_aod_debug_data->ioctl_lock);
	DPU_AOD_DEBUG_INFO("cmd = 0x%x\n", cmd);
    switch(cmd) {
		case AOD_DEBUG_IOCTL_GET_PANEL_INFO:
			ret = aod_debug_get_panel_info(g_aod_debug_data, argp);
			break;
        case AOD_DEBUG_IOCTL_SET_LAYER_CONFIG:
			ret = aod_debug_set_layer_config(g_aod_debug_data, argp);
			break;
		case AOD_DEBUG_IOCTL_PREPARE_TASK:
			ret = aod_debug_prepare_task(argp);
			break;
		case AOD_DEBUG_IOCTL_OPEN_DPU_DBG:
			ret = aod_debug_open_dpu_dbg();
            break;
		case AOD_DEBUG_IOCTL_START_TEST:
			ret = aod_debug_start_test();
			break;
		case AOD_DEBUG_IOCTL_STOP_TEST:
			ret = aod_debug_stop_test();
			break;
		default:
			DPU_AOD_DEBUG_ERR("aod_debug_ioctl unknown cmd, 0x%x\n", cmd);
            ret = -ENOTTY;
            break;
	}
	mutex_unlock(&g_aod_debug_data->ioctl_lock);
    return 0;
}

static int aod_debug_open(struct inode* inode, struct file* file)
{
    int ret = 0;

    if (g_aod_debug_data == NULL) {
        DPU_AOD_DEBUG_ERR("g_aod_debug_data is NULL\n");
        return -1;
    }

    mutex_lock(&g_aod_debug_data->ioctl_lock);

    if (g_aod_debug_data->ref_cnt) {
        DPU_AOD_DEBUG_ERR("already open, ref_cnt = %d\n", g_aod_debug_data->ref_cnt);
        ret = -1;
        goto unlock_mutex;
    }

    if (g_layer_config == NULL) {
        g_layer_config = kzalloc(sizeof(struct test_layer_config), GFP_KERNEL);
        if (IS_ERR_OR_NULL(g_layer_config)) {
            DPU_AOD_DEBUG_ERR("alloc memory for g_layer_config failed\n");
            ret = -1;
            goto unlock_mutex;
        }
    }

    if (g_dbg_para == NULL) {
        g_dbg_para = kzalloc(sizeof(struct dpu_dbg_para), GFP_KERNEL);
        if (IS_ERR_OR_NULL(g_dbg_para)) {
            DPU_AOD_DEBUG_ERR("alloc memory for g_dbg_para failed\n");
            kfree(g_layer_config);
            g_layer_config = NULL;
            ret = -1;
            goto unlock_mutex;
        }
	}

    g_aod_debug_data->ref_cnt++;
    DPU_AOD_DEBUG_INFO("aod_debug_open ref_cnt = %d\n", g_aod_debug_data->ref_cnt);

unlock_mutex:
    mutex_unlock(&g_aod_debug_data->ioctl_lock);
    return ret;
}

static int aod_debug_release(struct inode* inode, struct file* file)
{
    if (g_aod_debug_data == NULL) {
		DPU_AOD_DEBUG_ERR("g_aod_debug_data is NULL\n");
        return -1;
	}

	mutex_lock(&g_aod_debug_data->ioctl_lock);

	if (g_aod_debug_data->ref_cnt == 0) {
        DPU_AOD_DEBUG_ERR("release called with zero ref_cnt\n");
        mutex_unlock(&g_aod_debug_data->ioctl_lock);
        return -1;
    }

	if (g_layer_config->is_smmu_enable && g_buffer_dma_buff != NULL) {
		dma_buf_put(g_buffer_dma_buff);
		g_buffer_dma_buff = NULL;
	}

	if (g_layer_config != NULL) {
		kfree(g_layer_config);
        g_layer_config = NULL;
		g_aod_debug_data->is_layer_configed = false;
	}

	if (g_dbg_para != NULL) {
		kfree(g_dbg_para);
        g_dbg_para = NULL;
    }

	g_aod_debug_data->ref_cnt--;
	DPU_AOD_DEBUG_INFO("aod_debug_open ref_cnt = %d\n", g_aod_debug_data->ref_cnt);
	mutex_unlock(&g_aod_debug_data->ioctl_lock);
    return 0;
}

static struct file_operations aod_debug_fops = {
	.owner = THIS_MODULE,
	.open = aod_debug_open,
	.release = aod_debug_release,
	.unlocked_ioctl = aod_debug_ioctl,
};

static int aod_debug_probe(struct platform_device *pdev)
{
	struct aod_debug_data_t *test_data = NULL;
	struct device *dev = &pdev->dev;
	struct device_node *np = NULL;
	uint32_t line_length = 0;
	uint32_t fb_max_len = 0;
	uint32_t bitmaps_max_len = 0;
	int ret = 0;

	DPU_AOD_DEBUG_INFO("%s\n", __func__);

	test_data = kzalloc(sizeof(struct aod_debug_data_t), GFP_KERNEL);
	if (test_data == NULL) {
		DPU_AOD_DEBUG_ERR("alloc memory for test_data failed\n");
		ret = -ENOMEM;
		goto alloc_test_data_fail;
	}

	test_data->dev = dev;
	mutex_init(&test_data->ioctl_lock);

	test_data->aod_debug_class = class_create(THIS_MODULE, "aod_debug");
	if (IS_ERR(test_data->aod_debug_class)) {
		DPU_AOD_DEBUG_ERR("Unable to create aod class; errno = %ld\n", PTR_ERR(test_data->aod_debug_class));
		test_data->aod_debug_class = NULL;
		ret = -ENOMEM;
		goto create_aod_debug_class_err;
	}

	ret = alloc_chrdev_region(&test_data->devno, 0, 1, "aod_debug");
	if (ret) {
		DPU_AOD_DEBUG_ERR("%s alloc_chrdev_region failed ret = %d\n", __func__, ret);
		goto alloc_chrdev_region_err;
	}

	test_data->aod_debug_cdevice = device_create(test_data->aod_debug_class, NULL, test_data->devno, NULL,
	                                            "%s", "aod_debug");
	if (test_data->aod_debug_cdevice == NULL) {
		DPU_AOD_DEBUG_ERR("%s Failed to create hall aod_debug_cdevice", __func__);
		ret = -ENOMEM;
		goto create_aod_debug_cdevice_err;
	}

	cdev_init(&test_data->cdev, &aod_debug_fops);
	test_data->cdev.owner = THIS_MODULE;

	ret = cdev_add(&test_data->cdev, test_data->devno, 1);
	if (ret) {
		DPU_AOD_DEBUG_ERR("cdev_add failed ret = %d.\n", ret);
		ret = -ENOMEM;
		goto add_cdev_err;
	}

	np = of_find_compatible_node(NULL, NULL, "huawei,aod");
	if (!np) {
		DPU_AOD_DEBUG_ERR("not found device node aod!\n");
		ret = -ENOMEM;
		goto alloc_fb_fail;
	}

	ret = of_property_read_u32(np, "x_res", &test_data->x_res);
	if (ret) {
		DPU_AOD_DEBUG_ERR("x_res get lcd_display_type failed!\n");
		ret = -ENOMEM;
		goto alloc_fb_fail;
	}
	ret = of_property_read_u32(np, "y_res", &test_data->y_res);
	if (ret) {
		DPU_AOD_DEBUG_ERR("y_res get lcd_display_type failed!\n");
		ret = -ENOMEM;
		goto alloc_fb_fail;
	}
	ret = of_property_read_u32(np, "bpp", &test_data->bpp);
	if (ret) {
		DPU_AOD_DEBUG_ERR("bpp get lcd_display_type failed!\n");
		ret = -ENOMEM;
		goto alloc_fb_fail;
	}

	DPU_AOD_DEBUG_INFO("x_res = %d, y_res = %d, bpp = %d!\n", test_data->x_res, test_data->y_res, test_data->bpp);
	
	/* fb memory size */
	line_length = ALIGN_UP(test_data->x_res * test_data->bpp, 16);
	fb_max_len = roundup(line_length * test_data->y_res, PAGE_SIZE);

	/* bitmap memory size */
	bitmaps_max_len = DIGITS_COUNT * fb_max_len;
	test_data->max_buf_size = fb_max_len + bitmaps_max_len + sizeof(uint32_t);

	dev_set_drvdata(dev, test_data);
	g_aod_debug_data = test_data;
	return 0;

alloc_fb_fail:
    cdev_del(&test_data->cdev);
add_cdev_err:
    device_destroy(test_data->aod_debug_class, test_data->devno);
create_aod_debug_cdevice_err:
    unregister_chrdev_region(test_data->devno, 1);
alloc_chrdev_region_err:
    class_destroy(test_data->aod_debug_class);
create_aod_debug_class_err:
    mutex_destroy(&test_data->ioctl_lock);
    kfree(test_data);
    test_data = NULL;
alloc_test_data_fail:
    return ret;
}

static int aod_debug_remove(struct platform_device *pdev)
{
    if (g_aod_debug_data) {
        cdev_del(&g_aod_debug_data->cdev);
    	device_destroy(g_aod_debug_data->aod_debug_class, g_aod_debug_data->devno);
        unregister_chrdev_region(g_aod_debug_data->devno, 1);
        class_destroy(g_aod_debug_data->aod_debug_class);
        mutex_destroy(&g_aod_debug_data->ioctl_lock);
        kfree(g_aod_debug_data);
        g_aod_debug_data = NULL;
    }
    return 0;
}

static struct of_device_id aod_device_supply_ids[] = {
	{.compatible = "dkmd,aod_debug"},
	{}
};

static struct platform_driver aod_debug_driver = {
	.probe		= aod_debug_probe,
	.remove		= aod_debug_remove,
	.shutdown = NULL,
	.driver = {
		.name = "aod_debug",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(aod_device_supply_ids),
	},
};

static int __init aod_debug_init(void)
{
	int ret = 0;

	DPU_AOD_DEBUG_INFO("%s\n", __func__);

	ret = platform_driver_register(&aod_debug_driver);
	if(ret)
		DPU_AOD_DEBUG_ERR("platform aod driver register failed\n");

	return ret;
}

late_initcall_sync(aod_debug_init);
MODULE_LICENSE("GPL");