GCOV_PROFILE := $(CONFIG_GCOV_KERNEL)
ccflags-y += -Wdate-time -Wfloat-equal -Wformat=2

ifeq ($(CONFIG_SYS_PM_STR),y)
EXTRA_CFLAGS += -I$(srctree)/platform_source/cee/drivers/pm
endif
EXTRA_CFLAGS += -I$(srctree)/platform_source/audio/include
EXTRA_CFLAGS += -I$(srctree)/include/platform_include/audio/ipc
EXTRA_CFLAGS += -I$(srctree)/platform_source/audio/drivers/hifi_mailbox/mailbox

obj-$(CONFIG_STR_NOTIFY_DSP) += str_mode_notifier.o
