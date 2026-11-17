FFTS_CHIP_VERSION := $(strip $(subst ", ,$(CONFIG_FFRT_FFTS_VERSION)))

ifneq ($(FFTS_CHIP_VERSION),)
	include $(srctree)/platform_source/ffrt/ffts/fpd/$(FFTS_CHIP_VERSION).mk
endif

EXTRA_CFLAGS += -I$(FKD_DIR)/
EXTRA_CFLAGS += -I$(FKD_DIR)/tzsp
EXTRA_CFLAGS += -I$(FKD_DIR)/communication
EXTRA_CFLAGS += -I$(FKD_DIR)/core
EXTRA_CFLAGS += -I$(FKD_DIR)/dfx
EXTRA_CFLAGS += -I$(FKD_DIR)/dfx/bbox
EXTRA_CFLAGS += -I$(FKD_DIR)/dfx/debug
EXTRA_CFLAGS += -I$(FKD_DIR)/dts
EXTRA_CFLAGS += -I$(FKD_DIR)/inc
EXTRA_CFLAGS += -I$(FKD_DIR)/memory
EXTRA_CFLAGS += -I$(srctree)/drivers/platform_drivers/ap/platform/$(FFTS_CHIP_PLATFORM_DIR)
EXTRA_CFLAGS += -I$(UNIFORM_ID_DIR)/
EXTRA_CFLAGS += -I$(FPD_DIR)/
EXTRA_CFLAGS += -I$(FPD_DIR)/$(FFTS_ARCH_VERSION)/
EXTRA_CFLAGS += -I$(FFTS_BBIT_DIR)/
EXTRA_CFLAGS += -I$(srctree)/include/platform_include/ffrt/ffts/
EXTRA_CFLAGS += -I$(srctree)/include/platform_include/see/ffa

obj-y += fkd.o

fkd-objs := ffts_common.o ffts_devinit.o ffts_platform.o tzsp/ffts_tzsp.o communication/ffts_interrupt.o core/ffts_ioctl_services.o \
	core/ffts_tid.o core/ffts_proc_ctx.o dts/ffts_irq.o dts/ffts_reg.o dts/ffts_lpid.o memory/ffts_map.o dfx/bbox/ffts_dfx_black_box.o dfx/debug/ffts_dfx_debug.o

ifeq ($(CONFIG_FFRT_DEBUG),y)
	EXTRA_CFLAGS += -DCONFIG_FFRT_DEBUG
	EXTRA_CFLAGS += -I$(FKD_DIR)/dfx/profiling
	EXTRA_CFLAGS += -I$(FKD_DIR)/dfx/perf
	fkd-objs += dfx/profiling/ffts_pmu.o dfx/perf/ffts_perf.o
endif