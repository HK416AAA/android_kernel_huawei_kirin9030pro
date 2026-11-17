obj-$(CONFIG_AKMD_AAE_DEVICE) += aae_device.o
GCOV_PROFILE := $(CONFIG_GCOV_KERNEL)

aae_device-objs := \
	aae_manager.o \
	aae_gfx.o \
	aae_pip_hw.o \
	aae_pip.o \
	aae_smmu.o \
	aae_xpu_proxy.o \
	aae_cmdlist_cfg_prepare.o \
	aae_exp_dump_v$(CONFIG_AKMD_AAE_VERSION).o \
	aae_exp.o \
	config/v$(CONFIG_AKMD_AAE_VERSION)/aae_dev_config.o

EXTRA_CFLAGS += \
	-I$(srctree)/include/platform_include/display/ukmd/ \
	-I$(srctree)/drivers/video/fbdev/akmd/dacc_aae \
	-I$(srctree)/drivers/video/fbdev/akmd/aksm \
	-I$(srctree)/drivers/video/fbdev/akmd/cmdlist \
	-I$(srctree)/drivers/video/fbdev/akmd/device/config \
	-I$(srctree)/drivers/video/fbdev/akmd/init \
	-I$(srctree)/drivers/video/fbdev/akmd/isr \
	-I$(srctree)/drivers/video/fbdev/akmd/power \
	-I$(srctree)/drivers/video/fbdev/akmd/res_mgr \
	-I$(srctree)/drivers/video/fbdev/akmd/res_mgr/config \
	-I$(srctree)/drivers/video/fbdev/akmd/res_mgr/dvfs \
	-I$(srctree)/drivers/video/fbdev/akmd/mntn/dacc_log_read \
	-I$(srctree)/drivers/video/fbdev/ukmd/cmdlist \
	-I$(srctree)/drivers/video/fbdev/ukmd/uksm \
	-I$(srctree)/drivers/video/fbdev/ukmd/uksm/chrdev \
	-I$(srctree)/drivers/video/fbdev/ukmd/uksm/fence \
	-I$(srctree)/drivers/video/fbdev/ukmd/uksm/isr \
	-I$(srctree)/drivers/video/fbdev/ukmd/uksm/timeline \
	-I$(srctree)/arch/arm64/include/ \
	-I$(srctree)/include/

ifeq ($(CONFIG_AKMD_AAE_OHOS),y)
EXTRA_CFLAGS += -I$(srctree)/samples/ldk/vendor
endif

CFLAGS_MODULE += -Wdate-time -Wextra -Wfloat-equal -Wformat=2 -Wshadow
ifeq ($(CONFIG_AKMD_AAE_DEVICE),m)
ifeq ($(chip_type),)
EXTRA_CFLAGS += \
	-I$(srctree)/drivers/platform_drivers/ap/platform/$(TARGET_PRODUCT)
else
EXTRA_CFLAGS += \
	-I$(srctree)/drivers/platform_drivers/ap/platform/$(TARGET_PRODUCT)_$(chip_type)
endif
endif

clean:
	rm -rf *.o .*.cmd *.ko *.mod *.mod.c .tmp_versions *.symvers *.order *.symversions signed .*.d
	find . -name "*.o" | xargs rm -f
	find . -name ".*.cmd" | xargs rm -f
	find . -name ".*.d" | xargs rm -f
	find . -name "*.gcno" | xargs rm -f
	$(MAKE) -C opr_mgr/operators clean
