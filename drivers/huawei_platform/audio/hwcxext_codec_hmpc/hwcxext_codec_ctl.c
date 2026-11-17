
/*
 * hwcxext_codec_ctl.c
 *
 * hwcxext_codec ioctl src file
 *
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/ioctl.h>
#include <linux/platform_device.h>
#include <linux/i2c.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/of_gpio.h>
#include <linux/delay.h>
#include <linux/gpio.h>
#include <linux/of_device.h>
#include <linux/compat.h>
#include <sound/jack.h>

#include "hwcxext_codec_v1.h"
#include "hwcxext_log.h"
#include "hwcxext_mbhc.h"
#include "hwcxext_codec_ctl.h"

#define IN_FUNCTION hwlog_info("%s function comein\n", __func__)
#define OUT_FUNCTION hwlog_info("%s function comeout\n", __func__)
#define HP_ONLINE 0x80000000

static int hwcxext_codec_ctrl_release(struct inode *inode, struct file *filp);
static int hwcxext_codec_ctrl_open(struct inode *inode, struct file *filp);
static long hwcxext_codec_ctrl_ioctl(struct file *file, unsigned int command, unsigned long arg);
#ifdef CONFIG_COMPAT
static long hwcxext_codec_ctrl_ioctl_compat(struct file *file, unsigned int command, unsigned long arg);
#endif
static int hwcxext_codec_ctrl_do_ioctl(struct file *file, unsigned int cmd, void __user *arg, int compat_mode);

static int hwcxext_codec_ctrl_probe(struct platform_device *pdev);
static int hwcxext_codec_ctrl_remove(struct platform_device *pdev);

#define HWLOG_TAG hwcxext_codec_ctrl
HWLOG_REGIST();

struct hwcxext_codec_ctrl_priv *g_hwcxext_codec_ctrl_priv;

static const struct file_operations hwcxext_codec_ctrl_fops = {
    .owner = THIS_MODULE,
    .open = hwcxext_codec_ctrl_open,
    .release = hwcxext_codec_ctrl_release,
    .unlocked_ioctl = hwcxext_codec_ctrl_ioctl,
#ifdef CONFIG_COMPAT
    .compat_ioctl = hwcxext_codec_ctrl_ioctl_compat,
#endif
};

static struct miscdevice hwcxext_codec_ctrl_miscdev = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "hwcxext_codec_ctrl",
    .fops = &hwcxext_codec_ctrl_fops,
};

static int hwcxext_codec_ctrl_open(struct inode *inode, struct file *filp)
{
    if ((inode == NULL) || (filp == NULL)) {
        hwlog_err("%s: invalid argument\n", __func__);
        return -EINVAL;
    }

    int ret = nonseekable_open(inode, filp);
    if (ret < 0) {
        hwlog_err("%s: nonseekable_open failed\n", __func__);
        return ret;
    }

    filp->private_data = g_hwcxext_codec_ctrl_priv;
    return ret;
}

static int hwcxext_codec_ctrl_release(struct inode *inode, struct file *filp)
{
    if ((inode == NULL) || (filp == NULL)) {
        hwlog_err("%s: invalid argument\n", __func__);
        return -EINVAL;
    }

    filp->private_data = NULL;
    return 0;
}

static long hwcxext_codec_ctrl_ioctl(struct file *file, unsigned int command, unsigned long arg)
{
    return hwcxext_codec_ctrl_do_ioctl(file, command, (void __user *)(uintptr_t)arg, 0);
}

#ifdef CONFIG_COMPAT
static long hwcxext_codec_ctrl_ioctl_compat(struct file *file, unsigned int command, unsigned long arg)
{
    switch (command) {
        case CODEC_GET_HEADPHONE_STATUS_COMP:
            command = CODEC_GET_HEADPHONE_STATUS;
            break;
        case CODEC_SET_HEADPHONE_TYPE_COMP:
            command = CODEC_SET_HEADPHONE_TYPE;
            break;
        case CODEC_SET_USE_SPEAKER_COMP:
            command = CODEC_SET_USE_SPEAKER;
            break;
        case CODEC_SET_SPEAKER_DIR_COMP:
            command = CODEC_SET_SPEAKER_DIR;
            break;
        case CODEC_SET_USE_DMIC_COMP:
            command = CODEC_SET_USE_DMIC;
            break;
        default:
            break;
    }

    return hwcxext_codec_ctrl_do_ioctl(file, command, compat_ptr((unsigned int)arg), 1);
}
#else
#define hwcxext_codec_ctrl_ioctl_compat NULL /* function pointer */
#endif

static inline int hwcxext_codec_ctrl_hp_online(struct hwcxext_codec_ctrl_priv *priv)
{
    if ((priv == NULL) || (priv->hwcxext_codec == NULL) || (priv->hwcxext_codec->component == NULL)) {
        hwlog_err("%s:invalid argument\n", __func__);
        return -EINVAL;
    }

    unsigned int hs_type = snd_soc_component_read(priv->hwcxext_codec->component, HWCXEXT_CODEC_V1_PORTA_PIN_SENSE);
    return hs_type & HWCXEXT_CODEC_V1_BIT_31;
}

static int hwcxext_codec_ctrl_set_use_speaker(struct hwcxext_codec_ctrl_priv *priv, void __user *arg)
{
    IN_FUNCTION;
    if (arg == NULL) {
        hwlog_err("%s:arg is NULL\n", __func__);
        return -EINVAL;
    }
    if (!access_ok(arg, sizeof(bool))) {
        hwlog_err("%s:arg is not a valid ptr\n", __func__);
        return -EINVAL;
    }

    bool use_speaker = false;
    int ret = copy_from_user(&use_speaker, arg, sizeof(bool));
    if (ret != 0) {
        hwlog_err("%s: set use_speaker fail\n", __func__);
        return ret;
    }
    if (hwcxext_codec_ctrl_hp_online(priv) == HP_ONLINE) {
        struct hwcxext_mbhc_priv *mbhc_data = priv->hwcxext_codec->mbhc_data;
        if (mbhc_data == NULL) {
            hwlog_err("%s:mbhc_data is invalid\n", __func__);
            return -EINVAL;
        }
        if (use_speaker) {
            switch_set_state(&mbhc_data->sdev, AUDIO_JACK_NONE);
        } else {
            switch_set_state(&mbhc_data->sdev, mbhc_data->hs_status);
        }
    }
    OUT_FUNCTION;
    return 0;
}

static int hwcxext_codec_ctrl_set_use_dmic(struct hwcxext_codec_ctrl_priv *priv, void __user *arg)
{
    IN_FUNCTION;
    if (arg == NULL) {
        hwlog_err("%s:arg is NULL\n", __func__);
        return -EINVAL;
    }
    if (!access_ok(arg, sizeof(bool))) {
        hwlog_err("%s:arg is not a valid ptr\n", __func__);
        return -EINVAL;
    }

    bool use_dmic = false;
    int ret = copy_from_user(&use_dmic, arg, sizeof(bool));
    if (ret != 0) {
        hwlog_err("%s: set use_dmic fail\n", __func__);
        return ret;
    }

    if (hwcxext_codec_ctrl_hp_online(priv) == HP_ONLINE) {
        struct hwcxext_mbhc_priv *mbhc_data = priv->hwcxext_codec->mbhc_data;
        if (mbhc_data == NULL) {
            hwlog_err("%s:mbhc_data is invalid\n", __func__);
            return -EINVAL;
        }
        if (use_dmic) {
            switch_set_state(&mbhc_data->sdev, AUDIO_JACK_NONE);
        } else {
            switch_set_state(&mbhc_data->sdev, mbhc_data->hs_status);
        }
    }
    OUT_FUNCTION;
    return 0;
}

static int hwcxext_codec_ctrl_get_hp_status(struct hwcxext_codec_ctrl_priv *priv, void __user *arg)
{
    IN_FUNCTION;
    int val = hwcxext_codec_ctrl_hp_online(priv);

    if (val == -EINVAL) {
        hwlog_err("%s:param is invalid\n", __func__);
        return -EINVAL;
    }

    if (arg == NULL) {
        hwlog_err("%s:arg is NULL\n", __func__);
        return -EINVAL;
    }
    if (!access_ok(arg, sizeof(val))) {
        hwlog_err("%s:arg is not a valid ptr\n", __func__);
        return -EINVAL;
    }
    if (copy_to_user((void *)arg, &val, sizeof(val))) {
        hwlog_err("%s: send reg value to user failed\n", __func__);
        return -EFAULT;
    }
    OUT_FUNCTION;
    return 0;
}

static int hwcxext_codec_ctrl_set_hp_type(struct hwcxext_codec_ctrl_priv *priv, void __user *arg)
{
    IN_FUNCTION;
    if (arg == NULL) {
        hwlog_err("%s:arg is NULL\n", __func__);
        return -EINVAL;
    }
    if (!access_ok(arg, sizeof(HP_TYPE))) {
        hwlog_err("%s:arg is not a valid ptr\n", __func__);
        return -EINVAL;
    }

    HP_TYPE hp_type = HP_TYPE_CTIA;
    int ret = copy_from_user(&hp_type, arg, sizeof(HP_TYPE));
    if (ret != 0) {
        hwlog_err("%s: get hp_type fail\n", __func__);
        return ret;
    }

    if (hwcxext_codec_ctrl_hp_online(priv) != HP_ONLINE) {
        hwlog_err("%s: headphone not online\n", __func__);
        return -ENOENT;
    }

    if (hp_type == HP_TYPE_CTIA) {
        priv->ops->set_hp_us(priv->hwcxext_codec->component, true);
    } else if (hp_type == HP_TYPE_OMTP) {
        priv->ops->set_hp_us(priv->hwcxext_codec->component, false);
    }

    unsigned hs_type = snd_soc_component_read(priv->hwcxext_codec->component, HWCXEXT_CODEC_V1_DIGITAL_TEST11);
    hwlog_info("%s: hs_type 0x%x\n", __func__, hs_type);
    hs_type = hs_type >> 8;
    if (hs_type & 0x8) {
        hwlog_info("%s: headphone is 4 pole\n", __func__);
    } else if (hs_type & 0x4) {
        hwlog_info("%s: headphone is invert 4 pole\n", __func__);
    }

    OUT_FUNCTION;
    return 0;
}

static int hwcxext_codec_ctrl_set_speaker_direction(struct hwcxext_codec_ctrl_priv *priv, void __user *arg)
{
    IN_FUNCTION;
    if (arg == NULL) {
        hwlog_err("%s:arg is NULL\n", __func__);
        return -EINVAL;
    }
    if (!access_ok(arg, sizeof(SPK_DIR))) {
        hwlog_err("%s:arg is not a valid ptr\n", __func__);
        return -EINVAL;
    }

    SPK_DIR spk_dir = SPK_DIR_BOTH;
    int ret = copy_from_user(&spk_dir, arg, sizeof(SPK_DIR));
    if (ret != 0) {
        hwlog_err("%s: get spk_dir fail\n", __func__);
        return ret;
    }

    struct snd_soc_component *component = priv->hwcxext_codec->component;
    if (component == NULL) {
        hwlog_err("%s:component is NULL\n", __func__);
        return -EINVAL;
    }
    if (spk_dir == SPK_DIR_LEFT) {
        priv->ops->snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_LEFT, 0x80, 0);
        priv->ops->snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_RIGHT, 0x80, 0x80);
    } else if (spk_dir == SPK_DIR_RIGHT) {
        priv->ops->snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_LEFT, 0x80, 0x80);
        priv->ops->snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_RIGHT, 0x80, 0);
    } else if (spk_dir == SPK_DIR_BOTH) {
        priv->ops->snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_LEFT, 0x80, 0);
        priv->ops->snd_soc_update_bits(component, HWCXEXT_CODEC_V1_DAC2_AMP_GAIN_RIGHT, 0x80, 0);
    }
    OUT_FUNCTION;
    return 0;
}

static int hwcxext_codec_ctrl_do_ioctl(struct file *file, unsigned int cmd, void __user *arg, int compat_mode)
{
    IN_FUNCTION;
    if ((file == NULL) || (file->private_data == NULL)) {
        hwlog_err("%s: invalid argument\n", __func__);
        return -EINVAL;
    }

    struct hwcxext_codec_ctrl_priv *priv = NULL;
    int ret = 0;
    priv = file->private_data;

    if (priv->hwcxext_codec == NULL || priv->ops == NULL) {
        hwlog_err("%s: priv is invalid\n", __func__);
        return -EINVAL;     
    }
    mutex_lock(&priv->do_ioctl_lock);
    
    switch (cmd) {
        case CODEC_GET_HEADPHONE_STATUS:
            ret = hwcxext_codec_ctrl_get_hp_status(priv, arg);
            break;
        case CODEC_SET_HEADPHONE_TYPE:
            ret = hwcxext_codec_ctrl_set_hp_type(priv, arg);
            break;
        case CODEC_SET_USE_SPEAKER:
            ret = hwcxext_codec_ctrl_set_use_speaker(priv, arg);
            break;
        case CODEC_SET_SPEAKER_DIR:
            ret = hwcxext_codec_ctrl_set_speaker_direction(priv, arg);
            break;
        case CODEC_SET_USE_DMIC:
            ret = hwcxext_codec_ctrl_set_use_dmic(priv, arg);
            break;
        default:
            hwlog_err("%s: not support cmd = 0x%x\n", __func__, cmd);
            ret = -EIO;
            break;
    }

    mutex_unlock(&priv->do_ioctl_lock);
    OUT_FUNCTION;
    return ret;
}

int hwcxext_codec_ctrl_init(struct hwcxext_codec_v1_priv *hwcxext_codec, hwcxext_codec_ctrl_ops_t *codec_ctrl_ops)
{
    if ((hwcxext_codec == NULL) || (codec_ctrl_ops == NULL)) {
        hwlog_err("%s: invalid argument\n", __func__);
        return -EINVAL;
    }
    
    struct hwcxext_codec_ctrl_priv *codec_ctrl_priv = NULL;
    int ret = 0;
    hwlog_info("%s: enter\n", __func__);

    codec_ctrl_priv = kzalloc(sizeof(struct hwcxext_codec_ctrl_priv), GFP_KERNEL);
    if (codec_ctrl_priv == NULL)
        return -ENOMEM;

    /* init ops lock */
    mutex_init(&codec_ctrl_priv->do_ioctl_lock);

    ret = misc_register(&hwcxext_codec_ctrl_miscdev);
    if (ret != 0) {
        hwlog_err("%s: register miscdev failed, %d\n", __func__, ret);
        goto err_out;
    }

    g_hwcxext_codec_ctrl_priv = codec_ctrl_priv;
    codec_ctrl_priv->ops = codec_ctrl_ops;
    codec_ctrl_priv->hwcxext_codec = hwcxext_codec;
    hwlog_info("%s: end success\n", __func__);
    return 0;

err_out:
    kfree(codec_ctrl_priv);
    return ret;
}

int hwcxext_codec_ctrl_deinit(void)
{
    if (g_hwcxext_codec_ctrl_priv != NULL) {
        kfree(g_hwcxext_codec_ctrl_priv);
        g_hwcxext_codec_ctrl_priv = NULL;
    }
    misc_deregister(&hwcxext_codec_ctrl_miscdev);
    return 0;
}