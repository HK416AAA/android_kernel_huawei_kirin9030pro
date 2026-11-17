obj-$(CONFIG_AKMD_AAE_RES_MGR) += aae_res_mgr.o
GCOV_PROFILE := $(CONFIG_GCOV_KERNEL)

aae_res_mgr-objs := \
	aae_res_mgr.o \
	config/aae_config_utils.o \
	config/aae_dvfs_config.o \
	config/v$(CONFIG_AKMD_AAE_VERSION)/aae_opr_config.o \
	config/v$(CONFIG_AKMD_AAE_VERSION)/aae_res_config.o \
	dvfs/aae_dvfs.o \
	dvfs/aae_ddr_dvfs.o \
	mapper/mapper.o \
	scene_id_mgr/scene_id_mgr.o \
	scene_mgr/scene_mgr.o \
	scene_mgr/aae_scene.o \
	task_binder/task_binder.o \
	tcu_power/tcu_power_mgr.o

EXTRA_CFLAGS += \
	-I$(srctree)/include/platform_include/display/ukmd/ \
	-I$(srctree)/include/platform_include/display/akmd \
	-I$(srctree)/include/platform_include/ffrt/uniform_id \
	-I$(srctree)/include/platform_include/ffrt/ffts \
	-I$(srctree)/drivers/video/fbdev/akmd/aksm \
	-I$(srctree)/drivers/video/fbdev/akmd/res_mgr \
	-I$(srctree)/drivers/video/fbdev/akmd/res_mgr/config \
	-I$(srctree)/drivers/video/fbdev/akmd/res_mgr/dvfs \
	-I$(srctree)/drivers/video/fbdev/akmd/res_mgr/mapper \
	-I$(srctree)/drivers/video/fbdev/akmd/res_mgr/scene_id_mgr \
	-I$(srctree)/drivers/video/fbdev/akmd/res_mgr/scene_mgr \
	-I$(srctree)/drivers/video/fbdev/akmd/res_mgr/task_binder \
	-I$(srctree)/drivers/video/fbdev/akmd/res_mgr/tcu_power \
	-I$(srctree)/drivers/video/fbdev/ukmd/uksm \
	-I$(srctree)/drivers/video/fbdev/ukmd/uksm/chrdev \
	-I$(srctree)/drivers/video/fbdev/ukmd/uksm/isr \
	-I$(srctree)/drivers/video/fbdev/ukmd/uksm/timeline \
	-I$(srctree)/drivers/video/fbdev/ukmd/cmdlist \
	-I$(srctree)/drivers/video/fbdev/ukmd/cmdlist/include \
	-I$(srctree)/arch/arm64/include/ \
	-I$(srctree)/include/

CFLAGS_MODULE += -Wdate-time -Wextra -Wfloat-equal -Wformat=2 -Wshadow
ifeq ($(CONFIG_AKMD_AAE_RES_MGR),m)
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

