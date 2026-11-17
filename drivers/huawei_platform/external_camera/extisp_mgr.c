/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.

 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#include <linux/kernel.h>
#include <linux/of.h>
#include <linux/module.h>
#include <linux/debugfs.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/gpio.h>
#include <linux/mutex.h>
#include <linux/of_platform.h>
#include <linux/platform_device.h>
#include <huawei_platform/camera/extisp_mgr.h>
#include <securec.h>

#define MIPI_ISP_TYPE_MAX 2

#ifndef PAGE_SIZE
#define PAGE_SIZE 4096
#endif

typedef struct extisp_mgr_cxt extisp_mgr_cxt_t;
typedef struct extisp_mgr_dev
{
    struct platform_device *pdev;
    extisp_type_t type;
    int isptype_gpiono;
    int forced_extisp_type;
    struct mutex ops_mutex;
    struct dentry *extisp_mgr_dir;
    extisp_mgr_cxt_t *mgr_cxt;
} extisp_mgr_dev_t;

typedef struct extisp_cb_ops
{
    int (*probe)(struct platform_device *);
    int (*remove)(struct platform_device *);
} extisp_cb_ops_t;

typedef struct extisp_dev
{
    struct platform_device *pdev;
    extisp_type_t type;
    bool extisp_inited;
    extisp_cb_ops_t cb;
} extisp_dev_t;

typedef struct extisp_mgr_cxt
{
    extisp_mgr_dev_t *mgr_dev;
    bool mgrdev_inited;
    extisp_dev_t usb;
    extisp_dev_t mipi[MIPI_ISP_TYPE_MAX];
} extisp_mgr_cxt_t;

#define ispmgr_err(fmt, args...) \
do { \
	pr_err("[extisp_mgr err] %s: %d " fmt, __func__, __LINE__, ## args); \
} while (0)

#define ispmgr_info(fmt, args...) \
do { \
	pr_info("[extisp_mgr info] %s: %d " fmt, __func__, __LINE__, ## args); \
} while (0)

#define ispmgr_warn(fmt, args...) \
do { \
	pr_warn("[extisp_mgr warn] %s: %d " fmt, __func__, __LINE__, ## args); \
} while (0)

extern void static_dma_pool_heap_destory(void);
static DEFINE_MUTEX(mgr_mutex);
static extisp_mgr_cxt_t g_extisp_mgr_cxt;
int register_extisp_mgr(extisp_mgr_dev_t *mgr_dev);
int unregister_extisp_mgr(extisp_mgr_dev_t *mgr_dev);
struct class *extisp_mgr_class = NULL;
struct device *extisp_type_dev = NULL;
static int g_isp_type;
static bool g_isp_static_cma_buff_check = false;
static dev_t dev_num;

static ssize_t extisp_type_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    ispmgr_info("enter.");
    char extisp_type[10] = {"0"};
    int ret = -EINVAL;
    unsigned int length = sizeof(extisp_type);

    if (g_isp_type == EXTISP_TYPE_USB) {
        if (!g_isp_static_cma_buff_check) {
            ispmgr_info("do static_dma_pool_heap_destory");
            static_dma_pool_heap_destory();
            g_isp_static_cma_buff_check = true;
        }
        ret = snprintf_s(extisp_type, length, length - 1, "USB");
        if (ret < 0) {
            ispmgr_info("snprintf_s USB failed\n");
            return ret;
        }
    } else if (g_isp_type == EXTISP_TYPE_MIPI) {
        ret = snprintf_s(extisp_type, length, length - 1, "MIPI");
        if (ret < 0) {
            ispmgr_info("snprintf_s MIPI failed\n");
            return ret;
        }
    }

    return snprintf_s(buf, length, length - 1, "%s", extisp_type);
}

static DEVICE_ATTR(extisp_type, 0644, extisp_type_show, NULL);


static int set_gpio_idle(struct platform_device *pdev)
{
    int ret = -EINVAL;
    struct pinctrl_state *gpio_idle_state = NULL;
    struct pinctrl *pin = devm_pinctrl_get(&pdev->dev);

    ispmgr_info("enter.");
    if (IS_ERR(pin)) {
        ret = PTR_ERR(pin);
        ispmgr_err("Failed to get pinctrl:%d", ret);
        return ret;
    }

    ispmgr_info("pinctrl_lookup_state.");
    gpio_idle_state = pinctrl_lookup_state(pin, "gpio_idle");
    if (IS_ERR(gpio_idle_state)) {
        ispmgr_err("Failed to lookup gpio_idle_state");
        return PTR_ERR(gpio_idle_state);
    }

    // select gpio_dp
    ispmgr_info("pinctrl_select_state.");
    ret = pinctrl_select_state(pin, gpio_idle_state);
    if (ret) {
        ispmgr_err("Failed to select gpio_idle_state");
        return ret;
    }

    ispmgr_info("exit.");
    return 0;
}

static int read_forced_extisp_type(
    struct device_node *of_node,
    extisp_mgr_dev_t *mgr_dev)
{
    int ret = -EINVAL;

    if (!of_node || !mgr_dev )
        return -EINVAL;

    ret = of_property_read_u32(of_node, "forced_extisp_type", &mgr_dev->forced_extisp_type);
    if (ret == 0) {
        ispmgr_info("get forced select:%d.", mgr_dev->forced_extisp_type);
        if (mgr_dev->forced_extisp_type == EXTISP_TYPE_USB ||
            mgr_dev->forced_extisp_type == EXTISP_TYPE_MIPI) {
            mgr_dev->type = mgr_dev->forced_extisp_type;
        } else {
            return -EINVAL;
        }
    }

    return ret;
}

static int read_isp_type_gpio(
    struct device_node *of_node,
    extisp_mgr_dev_t *mgr_dev,
    int *type_gpio_val,
    int *mipitype_gpiostatus)
{
    int ret = -EINVAL;
    if (!of_node || !mgr_dev || !type_gpio_val || !mipitype_gpiostatus)
        return -EINVAL;

    ret = of_property_read_u32(of_node, "isptype_gpiono", &mgr_dev->isptype_gpiono);
    if (ret < 0) {
        ispmgr_err("get isptype_gpiono fail");
        return ret;
    }
    ret = of_property_read_u32(of_node, "mipitype_gpiostatus", mipitype_gpiostatus);
    if (ret < 0 || (*mipitype_gpiostatus != 0 && *mipitype_gpiostatus != 1)) {
        ispmgr_err("get mipitype_gpiostatus fail");
        return ret;
    }

    ispmgr_info("isptype_gpiono:%d.", mgr_dev->isptype_gpiono);
    if (!gpio_is_valid(mgr_dev->isptype_gpiono)) {
        ispmgr_err("isp index gpiono:%d is invalid.", mgr_dev->isptype_gpiono);
        return -EINVAL;
    }
    ret = gpio_request(mgr_dev->isptype_gpiono, "isptype_index");
    if (ret) {
        ispmgr_err("request gpio%d name:isptype_index fail %d", mgr_dev->isptype_gpiono, ret);
        return ret;
    }
    ret = gpio_direction_input(mgr_dev->isptype_gpiono);
    if (ret) {
        ispmgr_err("get gpio%d fail %d", mgr_dev->isptype_gpiono, ret);
        gpio_free(mgr_dev->isptype_gpiono);
        return ret;
    } else {
        *type_gpio_val = gpio_get_value(mgr_dev->isptype_gpiono);
        ispmgr_info("gpio%d get idx_gpio_val:%d.", mgr_dev->isptype_gpiono, *type_gpio_val);
        gpio_free(mgr_dev->isptype_gpiono);
    }
    return 0;
}

static int select_extisp_type(
    struct platform_device *pdev,
    extisp_mgr_dev_t *mgr_dev)
{
    struct device_node *of_node = NULL;
    int ret = -EINVAL;
    int type_gpio_val= -EINVAL;
    int mipitype_gpiostatus = -EINVAL;

    ispmgr_info("enter.");

    if (!pdev || !mgr_dev)
        return -EINVAL;

    of_node = pdev->dev.of_node;

    ret = read_forced_extisp_type(of_node, mgr_dev);
    if (ret == 0) {
        goto forced_extisp_type;
    }

    ret = read_isp_type_gpio(of_node, mgr_dev, &type_gpio_val, &mipitype_gpiostatus);
    if (ret < 0) {
        return ret;
    }

    ispmgr_info("type_gpio_val %d, mgr_dev->type %d, mipitype_gpiostatus %d.",
                type_gpio_val, mgr_dev->type, mipitype_gpiostatus);

    if (type_gpio_val == EXTISP_TYPE_USB || type_gpio_val == EXTISP_TYPE_MIPI) {
        ispmgr_info("type_gpio_val in:%d", mgr_dev->type);
        if (type_gpio_val == mipitype_gpiostatus)
            mgr_dev->type = EXTISP_TYPE_MIPI;
        else
            mgr_dev->type = EXTISP_TYPE_USB;
    } else {
        ispmgr_err("type_gpio_val fail %d.", type_gpio_val);
        return -EINVAL;
    }

forced_extisp_type:
    g_isp_type = mgr_dev->type;
    ispmgr_info("return mgr_dev->type %d.",mgr_dev->type);
    set_gpio_idle(pdev);
    return 0;
}

static int create_sysfs_entries(void)
{
    int ret = -EINVAL;

    extisp_mgr_class = class_create(THIS_MODULE, "extisp_mgr");
    if (IS_ERR(extisp_mgr_class)) {
        ret = PTR_ERR(extisp_mgr_class);
        ispmgr_err("Unable to create extisp_mgr_class; errno = %d\n", ret);
        extisp_mgr_class = NULL;
        return ret;
    }

    ret = alloc_chrdev_region(&dev_num, 0, 1, "extisp_type_dev");
    if (ret) {
        ispmgr_err("Failed to allocate device number");
        goto fail_out_alloc_chrdev;
    }

    extisp_type_dev = device_create(extisp_mgr_class, NULL, dev_num, NULL, "extisp_type_dev");
    if (IS_ERR(extisp_type_dev)) {
        ispmgr_err("Failed to create device extisp_type");
        ret = PTR_ERR(extisp_type_dev);
        goto fail_out_mgr_dev;
    }

    ret = sysfs_create_file(&extisp_type_dev->kobj, &dev_attr_extisp_type.attr);
    if (ret) {
        dev_err(extisp_type_dev, "Failed to create sysfs file");
        goto fail_out_mgr_class;
    }

    return 0;

fail_out_mgr_class:
    device_destroy(extisp_mgr_class, dev_num);
fail_out_mgr_dev:
    unregister_chrdev_region(dev_num, 1);
fail_out_alloc_chrdev:
    class_destroy(extisp_mgr_class);
    extisp_mgr_class = NULL;
    extisp_type_dev = NULL;
    return ret;
}

static void remove_sysfs_entries(void)
{
    sysfs_remove_file(&extisp_type_dev->kobj, &dev_attr_extisp_type.attr);
    device_destroy(extisp_mgr_class, dev_num);
    unregister_chrdev_region(dev_num, 1);
    class_destroy(extisp_mgr_class);
    extisp_mgr_class = NULL;
    extisp_type_dev = NULL;
}

static int extisp_mgr_dev_platform_probe(struct platform_device* pdev)
{
    int ret = -EINVAL;
    extisp_mgr_dev_t *mgr_dev = NULL;
    ispmgr_info("enter.");

    if (pdev == NULL) {
        ispmgr_err("pdev is null.\n");
        return -EINVAL;
    }

    // kzalloc extisp mgr_dev.
    mgr_dev = devm_kzalloc(&pdev->dev, sizeof(extisp_mgr_dev_t), GFP_KERNEL);
    if (!mgr_dev) {
        ispmgr_err("kzalloc extisp mgr_dev fail.");
        return -EINVAL;
    }
    mutex_init(&mgr_dev->ops_mutex);

    // select extisp type.
    ret = select_extisp_type(pdev, mgr_dev);
    if (ret < 0) {
        ispmgr_err("select_extisp_type fail");
        return ret;
    }
    mgr_dev->pdev = pdev;
    platform_set_drvdata(pdev, mgr_dev);

    // Create sysfs entries.
    ret = create_sysfs_entries();
    if (ret < 0) {
        ispmgr_err("Failed to create sysfs entries");
        return ret;
    }

    ispmgr_info("mgr_dev->type:%d", mgr_dev->type);
    ret = register_extisp_mgr(mgr_dev);
    if (ret < 0) {
        ispmgr_err("Failed to register_extisp_mgr");
        remove_sysfs_entries();
        return ret;
    }

    return 0;
}

static int extisp_mgr_dev_platform_remove(struct platform_device* pdev)
{
    ispmgr_info("removing  ext isp device");
    extisp_mgr_dev_t *mgr_dev = platform_get_drvdata(pdev);

    unregister_extisp_mgr(mgr_dev);
    remove_sysfs_entries();

    return 0;
}

static const struct of_device_id extisp_mgr_dev_dt_match[] =
{
    {
        .compatible = "vendor,extisp_mgr_dev",
    },
    {
    },
};

MODULE_DEVICE_TABLE(of, extisp_mgr_dev_dt_match);

static struct platform_driver extisp_mgr_dev_platform_driver = {
    .driver = {
        .name           = "vendor,extisp_mgr_dev",
        .owner          = THIS_MODULE,
        .of_match_table = extisp_mgr_dev_dt_match,
    },

    .probe = extisp_mgr_dev_platform_probe,
    .remove = extisp_mgr_dev_platform_remove,
};

static int __init extisp_mgr_dev_init(void)
{
    ispmgr_info("enter ..");
    return platform_driver_register(&extisp_mgr_dev_platform_driver);
}

static void __exit extisp_mgr_dev_exit(void)
{
    platform_driver_unregister(&extisp_mgr_dev_platform_driver);
}


static int get_extisp_dev_from_mgr_cxt(
    struct platform_device *pdev,
    extisp_type_t isp_type,
    extisp_dev_t **extisp_dev)
{
    ispmgr_info("enter ..");
    int ret = -EINVAL;
    int is_ctrl= -EINVAL;
    int mipi_idx = -EINVAL;
    extisp_mgr_cxt_t *mgr_cxt = &g_extisp_mgr_cxt;

    if (!pdev) 
        return -EINVAL;

    // check need extisp mgr ctrl ?
    ret = of_property_read_u32(pdev->dev.of_node, "need_extisp_mgr_ctrl", &is_ctrl);
    if (ret < 0 || is_ctrl == 0) {
        ispmgr_info("no need extisp mgr ctrl.");
        return EXTISP_NO_NEED_MGR_CTRL;
    }

    // get extisp_dev from mgr_cxt.
    if (isp_type == EXTISP_TYPE_USB) {
        *extisp_dev = &mgr_cxt->usb;
    } else if (isp_type == EXTISP_TYPE_MIPI){
        ret = of_property_read_u32(pdev->dev.of_node, "huawei,isp_idx", &mipi_idx);
        if (ret < 0 || mipi_idx < 0 || mipi_idx >= MIPI_ISP_TYPE_MAX) {
            ispmgr_err("invalid mipi idx.");
            return -EINVAL;
        }
        *extisp_dev = &(mgr_cxt->mipi[mipi_idx]);
    } else {
        ispmgr_err("invalid isp type.");
        return -EINVAL;
    }

    ispmgr_info("exit..");
    return 0;
}

static int extisp_dev_init(extisp_dev_t *extisp_dev)
{
    ispmgr_info("enter ..");
    int ret = EOK;
    extisp_mgr_cxt_t *mgr_cxt = &g_extisp_mgr_cxt;
    extisp_mgr_dev_t *mgr_dev = mgr_cxt->mgr_dev;

    if (!extisp_dev || !extisp_dev->pdev)
        return -EINVAL;

    // check extisp mgr dev inited?
    if (!mgr_dev || !mgr_cxt->mgrdev_inited) {
        ispmgr_info("mgr_dev has not been registered yet. ");
        return 0;
    } else {
        if (mgr_dev->type != extisp_dev->type) {
            ispmgr_info("isp_type no match. ");
            return 0;
        }
    }

    // probe callback.
    if (!(extisp_dev->extisp_inited) && extisp_dev->cb.probe) {
            ispmgr_info("callback extisp dev probe.");
            ret = extisp_dev->cb.probe(extisp_dev->pdev);
            if (ret == 0){
                ispmgr_info("extisp dev probe succ.");
                extisp_dev->extisp_inited = true;
            } else {
                ispmgr_err("extisp dev probe fail.");
        }
    }

    ispmgr_info("exit..");
    return ret;
}

int register_extisp_dev(
    struct platform_device *pdev, extisp_type_t isp_type,
    int (* cb_probe)(struct platform_device *),
    int (* cb_remove)(struct platform_device *))
{
    ispmgr_info("enter ..");
    int ret = -EINVAL;
    extisp_mgr_cxt_t *mgr_cxt = &g_extisp_mgr_cxt;
    extisp_dev_t *extisp_dev = NULL;

    if (!pdev || !cb_probe || !cb_remove)
        return -EINVAL;

    // get extisp_dev from mgr_cxt.
    ret = get_extisp_dev_from_mgr_cxt(pdev, isp_type, &extisp_dev);
    if (ret != 0) {
        ispmgr_info("no need extisp mgr ctrl.");
        return ret;
    }

    mutex_lock(&mgr_mutex);
    // save extisp pdev
    extisp_dev->pdev = pdev;
    extisp_dev->type = isp_type;
    extisp_dev->extisp_inited = false;
    extisp_dev->cb.probe = cb_probe;
    extisp_dev->cb.remove = cb_remove;

    // init extisp dev.
    ret = extisp_dev_init(extisp_dev);

    mutex_unlock(&mgr_mutex);

    ispmgr_info("exit.");
    return ret;
}
EXPORT_SYMBOL(register_extisp_dev);

int unregister_extisp_dev(
    struct platform_device *pdev, extisp_type_t isp_type)
{
    ispmgr_info("enter ..");
    int ret = -EINVAL;
    extisp_mgr_cxt_t *mgr_cxt = &g_extisp_mgr_cxt;
    extisp_dev_t *extisp_dev = NULL;

    if (!pdev)
        return -EINVAL;

    // get extisp_dev from mgr_cxt.
    ret = get_extisp_dev_from_mgr_cxt(pdev, isp_type, &extisp_dev);
    if (ret != 0) {
        ispmgr_info("no need extisp mgr ctrl.");
        return ret;
    }
    if (!extisp_dev)
        return -EINVAL;

    // remove extisp pdev
    mutex_lock(&mgr_mutex);
    if (extisp_dev->extisp_inited && extisp_dev->cb.remove) {
        ret = extisp_dev->cb.remove(pdev);
        extisp_dev->extisp_inited = false;
        extisp_dev->pdev = NULL;
        extisp_dev->cb.probe = NULL;
        extisp_dev->cb.remove = NULL;
    }
    mutex_unlock(&mgr_mutex);

    ispmgr_info("exit.");
    return ret;
}
EXPORT_SYMBOL(unregister_extisp_dev);

int register_extisp_mgr(extisp_mgr_dev_t *mgr_dev)
{
    ispmgr_info("enter ..");
    int ret = -EINVAL;
    int i = -EINVAL;
    extisp_mgr_cxt_t *mgr_cxt = &g_extisp_mgr_cxt;
    extisp_dev_t *extisp_dev = NULL;

    if (!mgr_dev)
        return -EINVAL;

    ispmgr_info("isp type:%d.", mgr_dev->type);
    mutex_lock(&mgr_mutex);
    mgr_cxt->mgr_dev = mgr_dev;
    mgr_dev->mgr_cxt = mgr_cxt;
    mgr_cxt->mgrdev_inited = true;

    // get extisp_dev form mgr_cxt, and extisp_inited.
    if (mgr_dev->type == EXTISP_TYPE_USB) {
        extisp_dev = &mgr_cxt->usb;
        ret = extisp_dev_init(extisp_dev);
    } else if (mgr_dev->type == EXTISP_TYPE_MIPI) {
        for (i = 0; i < MIPI_ISP_TYPE_MAX; i++) {
            extisp_dev = &(mgr_cxt->mipi[i]);
            ret = extisp_dev_init(extisp_dev);
            if (ret == 0) {
                ispmgr_info("mipi extisp dev init succ.");
                break;
            }
        }
    }
    mutex_unlock(&mgr_mutex);

    ispmgr_info("exit");
    return 0;
}
EXPORT_SYMBOL(register_extisp_mgr);

int unregister_extisp_mgr(extisp_mgr_dev_t *mgr_dev)
{
    ispmgr_info("enter ..");
    extisp_mgr_cxt_t *mgr_cxt = &g_extisp_mgr_cxt;

    if (!mgr_dev)
        return -EINVAL;

    mutex_lock(&mgr_mutex);
    mgr_cxt->mgr_dev = NULL;
    mgr_cxt->mgrdev_inited = false;
    mgr_dev->mgr_cxt = NULL;
    mutex_unlock(&mgr_mutex);
    ispmgr_info("exit");
    return 0;
}
EXPORT_SYMBOL(unregister_extisp_mgr);

module_init(extisp_mgr_dev_init);
module_exit(extisp_mgr_dev_exit);
MODULE_DESCRIPTION("external isp manager");
MODULE_LICENSE("GPL v2");

