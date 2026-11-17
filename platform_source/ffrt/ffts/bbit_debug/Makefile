FFTS_CHIP_VERSION := $(strip $(subst ", ,$(CONFIG_FFRT_FFTS_VERSION)))

ifneq ($(FFTS_CHIP_VERSION),)
	include $(srctree)/platform_source/ffrt/ffts/fpd/$(FFTS_CHIP_VERSION).mk
endif

EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/ffts/fkd
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/ffts/fkd/inc
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/ffts/fkd/dfx
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/ffts/fkd/communication
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/ffts/fpd/$(FFTS_ARCH_VERSION)
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/ffts/bbit_debug
EXTRA_CFLAGS += -I$(srctree)/drivers/platform_drivers/ap/platform/$(FFTS_CHIP_PLATFORM_DIR)
EXTRA_CFLAGS += -I$(srctree)/include/platform_include/ffrt/ffts/

EXTRA_CFLAGS += $(FFTS_GLOBAL_CFLAGS)

obj-y += ffts_bbit_debug.o
ffts_bbit_debug-objs := ffts_bbit_debug.o ffts_bbit_abnormal.o