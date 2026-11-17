#include <linux/init.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/device.h>
#include <linux/bitops.h>
#include <linux/platform_device.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/delay.h>
#include <linux/suspend.h>
#include <linux/of.h>
#include <linux/mutex.h>
#include "audio_haptic.h"
#include "dsp_misc.h"
#include "audio_ddr_map.h"
#include "dsp_om.h"
#include "audio_hifi.h"

unsigned char *get_haptic_share_buf_virtaddr(void)
{
    unsigned char * sec_virt_addr = NULL;

    sec_virt_addr = get_dsp_viradr();
    if (sec_virt_addr == NULL) {
        loge("base virt is null\n");
        return NULL;
    }

    return sec_virt_addr + (DSP_HAPTIC_DATA_BUF_ADDR - DSP_UNSEC_BASE_ADDR);
}

#ifdef CONFIG_AUDIO_HAPTIC_UEVENT
struct audio_haptic_priv {
	struct device *dev;
    audio_haptic_switch_path_cb switch_path_cb;
    struct mutex source_mutex;
};

static struct audio_haptic_priv g_audio_haptic_data;

int audio_haptic_config_done(uintptr_t arg)
{
    mutex_lock(&g_audio_haptic_data.source_mutex);
    if (g_audio_haptic_data.switch_path_cb == NULL) {
        mutex_unlock(&g_audio_haptic_data.source_mutex);
        loge("no switch patch callback func\n");
        return ERROR;
    }

    g_audio_haptic_data.switch_path_cb(true);
    mutex_unlock(&g_audio_haptic_data.source_mutex);
    logi("haptic codec switch done\n");
    return 0;
}

int audio_haptic_switch_path(bool is_path_open)
{
	int ret;
	char *envp[2] = {"haptic=off", NULL};

    mutex_lock(&g_audio_haptic_data.source_mutex);
    if (g_audio_haptic_data.dev == NULL || g_audio_haptic_data.switch_path_cb == NULL) {
        mutex_unlock(&g_audio_haptic_data.source_mutex);
        loge("err: dev is null\n");
        return ERROR;
    }

    if (is_path_open)
        envp[0] = "haptic=on";

    ret = kobject_uevent_env(&g_audio_haptic_data.dev->kobj, KOBJ_CHANGE, envp);
    if (ret != 0)
        g_audio_haptic_data.switch_path_cb(false);

    mutex_unlock(&g_audio_haptic_data.source_mutex);
    logi("haptic path open/close %u, ret %d\n", is_path_open, ret);
    return ret;
}

int audio_haptic_switch_path_cb_register(audio_haptic_switch_path_cb callback)
{
    if (callback == NULL) {
        loge("err: haptic path cb is null\n");
        return ERROR;
    }
    mutex_lock(&g_audio_haptic_data.source_mutex);
    g_audio_haptic_data.switch_path_cb = callback;
    mutex_unlock(&g_audio_haptic_data.source_mutex);
    logi("regist ok\n");
    return 0;
}

static int audio_haptic_probe(struct platform_device *pdev)
{
    pr_info("enter\n");
    if (pdev == NULL) {
        pr_err("probe err\n");
        return ERROR;
    }

	g_audio_haptic_data.dev = &pdev->dev;
    return 0;
}

static int audio_haptic_remove(struct platform_device *pdev)
{
    pr_info("enter\n");
    mutex_lock(&g_audio_haptic_data.source_mutex);
    g_audio_haptic_data.dev = NULL;
    g_audio_haptic_data.switch_path_cb = NULL;
    mutex_unlock(&g_audio_haptic_data.source_mutex);
    return 0;
}

static const struct of_device_id audio_haptic_match[] = {
	{ .compatible = "hisilicon,audio-haptic", },
	{},
};
MODULE_DEVICE_TABLE(of, audio_haptic_match);

static struct platform_driver audio_haptic_driver = {
	.driver = {
		.name = "audio_haptic",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(audio_haptic_match),
	},
	.probe = audio_haptic_probe,
	.remove = audio_haptic_remove,
};

static int __init audio_haptic_drv_init(void)
{
    mutex_init(&g_audio_haptic_data.source_mutex);
	return platform_driver_register(&audio_haptic_driver);
}
module_init(audio_haptic_drv_init);

static void __exit audio_haptic_drv_exit(void)
{
	platform_driver_unregister(&audio_haptic_driver);
    mutex_destroy(&g_audio_haptic_data.source_mutex);
}
module_exit(audio_haptic_drv_exit);

MODULE_DESCRIPTION("Audio Haptic Driver");
MODULE_LICENSE("GPL v2");
#endif
