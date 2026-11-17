/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright (c) 2025 Huawei Device Co., Ltd.
 */

#ifndef LITE_HCK_USB_H
#define LITE_HCK_USB_H

#include <linux/usb.h>
#include <platform_include/basicplatform/linux/lite_vendor_hooks.h>

#ifndef CONFIG_HCK
#define CALL_HCK_LITE_HOOK(name, args...)
#define REGISTER_HCK_LITE_HOOK(name, probe)
#define REGISTER_HCK_LITE_DATA_HOOK(name, probe, data)
#else
#ifdef CONFIG_USB_UEVENT_SUPPRESS
DECLARE_HCK_LITE_HOOK(set_uevent_suppress_hook,
		TP_PROTO(struct usb_device *udev),
		TP_ARGS(udev));
#endif

#endif /* CONFIG_HCK */

#endif /* LITE_HCK_USB_H */
