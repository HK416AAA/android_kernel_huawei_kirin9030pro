EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/hts/dfx
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/hts/hkd
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/hts/hkd/tzsp
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/hts/hkd/communication
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/hts/hkd/core
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/hts/hkd/dts
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/hts/hkd/inc
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/hts/hkd/dmd
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/hts/hkd/interfaces
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/hts/hkd/power_manager
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/hts/hkd/profiling
EXTRA_CFLAGS += -I$(srctree)/platform_source/ffrt/hts/hpd/$(ARCH_VERSION)/
EXTRA_CFLAGS += -I$(srctree)/include/platform_include/ffrt/uniform_id
EXTRA_CFLAGS += -I$(srctree)/include/platform_include/ffrt/$(ARCH_VERSION)/
EXTRA_CFLAGS += -I$(srctree)/drivers/platform_drivers/ap/platform/$(FFTS_CHIP_PLATFORM_DIR)
EXTRA_CFLAGS += -I$(srctree)/include/platform_include/see/ffa
EXTRA_CFLAGS += -I$(srctree)/platform_include/see/ffa

ifneq ($(TARGET_BUILD_VARIANT),user)
	EXTRA_CFLAGS += -DHTS_DEBUG_EN
endif
obj-y += hkd.o

hkd-objs := hts_devinit.o hts_graph.o core/hts_ioctl_services.o communication/hts_irq.o interfaces/hts_interface.o hts_platform.o dts/hts_reg.o tzsp/hts_tzsp.o power_manager/hts_pm.o hts_common.o core/hts_event.o profiling/hts_profiling.o dmd/hts_dmd_interface.o