obj-$(CONFIG_HW_EDP_DRIVER) += edp_driver.o
 
edp_driver-objs := \
	edp_drv/edp_panel_drv.o \
	tcon_i2c/tcon_i2c.o \
	tcon_i2c/tcon_i2c_upgrade.o \
	edp_sysfs/edp_sysfs.o \
	edp_sysfs/edp_sysfs_common.o \
	edp_sysfs/edp_factory.o \
	edp_sysfs/edp_sysfs_fact.o \
	display_engine/edp_display_engine.o \
	edp_ts_kit/edp_ts_kit.o \
	display_engine/edp_safe_fm_rate.o \
	edp_msr/edp_comp_msr.o \
	tcon_uart/tcon_uart.o \

ifeq ($(TARGET_VERSION_MODE),factory)
EXTRA_CFLAGS += -DEDP_FACTORY_MODE
endif

EXTRA_CFLAGS += \
	-I$(srctree)/arch/arm64/include/ \
	-I$(srctree)/include/platform_include/display/dkmd

CFLAGS_MODULE += -Wdate-time -Wextra -Wfloat-equal -Wformat=2 -Wshadow

DS_CHIP_TYPE := $(strip $(subst ", , $(CONFIG_VENDOR_CHIP_SUFFIX)))
DS_SOC_CHIP_NAME := $(strip $(subst ", , $(CONFIG_VENDOR_CHIP_PREFIX)))
ifeq ($(DS_CHIP_TYPE),)
EXTRA_CFLAGS += \
	-I$(srctree)/drivers/platform_drivers/ap/platform/$(DS_SOC_CHIP_NAME)
else
EXTRA_CFLAGS += \
	-I$(srctree)/drivers/platform_drivers/ap/platform/$(DS_SOC_CHIP_NAME)_$(DS_CHIP_TYPE)
endif

clean:
	rm -rf *.o .*.cmd *.ko *.mod.c .tmp_versions *.symvers *.order *.symversions signed .*.d
	find . -name "*.o" | xargs rm -f
	find . -name ".*.cmd" | xargs rm -f
	find . -name ".*.d" | xargs rm -f
	find . -name "*.gcno" | xargs rm -f