obj-$(CONFIG_AKMD_AAE_DEVICE) += aae_init.o
GCOV_PROFILE := $(CONFIG_GCOV_KERNEL)

aae_init-objs := \
	aae_dacc_ctrl.o \
	aae_ffts_ctrl.o \
	aae_init.o

EXTRA_CFLAGS += \
	-I$(srctree)/include/platform_include/display/ukmd/ \
	-I$(srctree)/drivers/video/fbdev/akmd/aksm \
	-I$(srctree)/drivers/video/fbdev/akmd/cmdlist \
	-I$(srctree)/drivers/video/fbdev/akmd/dacc_aae \
	-I$(srctree)/drivers/video/fbdev/akmd/device \
	-I$(srctree)/drivers/video/fbdev/ukmd/uksm \
	-I$(srctree)/drivers/video/fbdev/ukmd/uksm/isr \
	-I$(srctree)/drivers/video/fbdev/ukmd/uksm/timeline \
	-I$(srctree)/arch/arm64/include/ \
	-I$(srctree)/include/

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
