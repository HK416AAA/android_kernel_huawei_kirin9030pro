#ifndef _LINUX_HWCXEXTLOG_H
#define _LINUX_HWCXEXTLOG_H

#include <linux/printk.h>
#include <linux/types.h>

enum {
	HWLOG_ERR	= 1U << 0,
	HWLOG_WARNING	= 1U << 1,
	HWLOG_INFO	= 1U << 2,
	HWLOG_DEBUG	= 1U << 3,
};

int hwcxext_codec_v1_suspend(struct device *dev);
int hwcxext_codec_v1_resume(struct device *dev);
int hwcxext_codec_v1_restore(struct device *dev);
int hwcxext_codec_v1_freeze(struct device *dev);
int hwcxext_codec_v1_thaw(struct device *dev);
bool hwcxext_codec_v1_is_noin_dapm_widgets(unsigned int reg);

#define HWLOG_TAG_DEFALUT_LEVEL (HWLOG_ERR | HWLOG_WARNING | HWLOG_INFO | HWLOG_DEBUG)

struct huawei_log_tag {
	const char *name;
	int level;
};

#define TAG_STRUCT_NAME(name) _hwtag_##name

#define hw_fmt_tag(TAG, LEVEL) "(" #LEVEL "/" #TAG ") "

#define HWLOG_REGIST()							\
	HWLOG_REGIST_TAG_LEVEL(HWLOG_TAG, HWLOG_TAG_DEFALUT_LEVEL)

#define HWLOG_REGIST_LEVEL(level)					\
	HWLOG_REGIST_TAG_LEVEL(HWLOG_TAG, level)

#define HWLOG_REGIST_TAG_LEVEL(name, level)				\
	_HWLOG_REGIST_TAG_LEVEL(name, level)

#define _HWLOG_REGIST_TAG_LEVEL(name, level)				\
	static struct huawei_log_tag TAG_STRUCT_NAME(name)		\
	__used								\
	__attribute__((unused, __section__("__hwlog_tag")))		\
	= { #name, level }

#define __hwlog_err(TAG, fmt, ...)					\
	do {								\
		if (TAG_STRUCT_NAME(TAG).level & HWLOG_ERR)		\
			printk(KERN_ERR hw_fmt_tag(TAG, E) fmt, ##__VA_ARGS__);	\
	} while (0)

#define __hwlog_warn(TAG, fmt, ...)					\
	do {								\
		if (TAG_STRUCT_NAME(TAG).level & HWLOG_WARNING)		\
			printk(KERN_WARNING hw_fmt_tag(TAG, W) fmt, ##__VA_ARGS__);	\
	} while (0)

#define __hwlog_info(TAG, fmt, ...)					\
	do {								\
		if (TAG_STRUCT_NAME(TAG).level & HWLOG_INFO)		\
			printk(KERN_INFO hw_fmt_tag(TAG, I) fmt, ##__VA_ARGS__);	\
	} while (0)

#define __hwlog_debug(TAG, fmt, ...)					\
	do {								\
		if (TAG_STRUCT_NAME(TAG).level & HWLOG_DEBUG)		\
			printk(KERN_INFO hw_fmt_tag(TAG, D) fmt, ##__VA_ARGS__);	\
	} while (0)

#define _hwlog_err(TAG, x...)    __hwlog_err(TAG, ##x)
#define _hwlog_warn(TAG, x...)   __hwlog_warn(TAG, ##x)
#define _hwlog_info(TAG, x...)   __hwlog_info(TAG, ##x)
#define _hwlog_debug(TAG, x...)  __hwlog_debug(TAG, ##x)

#define hwlog_err(x...)          _hwlog_err(HWLOG_TAG, ##x)
#define hwlog_warn(x...)         _hwlog_warn(HWLOG_TAG, ##x)
#define hwlog_info(x...)         _hwlog_info(HWLOG_TAG, ##x)
#define hwlog_debug(x...)        _hwlog_debug(HWLOG_TAG, ##x)

#endif
