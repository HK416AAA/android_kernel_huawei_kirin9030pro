ccflags-y += -Wextra -Wshadow

obj-$(CONFIG_DPU_COMPOSER) += hisi_dpu_composer.o

hisi_dpu_composer-objs := \
	composer_adaptor.o \
	composer_present.o \
	dacc/dpu_dacc.o \
	init/dpu_comp_init.o \
	ldi/dpu_ldi.o \
	irq/dpu_irq_sdp.o \
	vactive/dpu_comp_vactive.o \
	notifier/dpu_comp_notifier.o \
	osal/dpu_osal.o \
	smmu/dpu_comp_smmu.o \
	smmu/dpu_iommu.o \
	debug/dpu_debug.o \
	composer_debugfs.o \
	dbuf/dpu_dbuf.o \
	dpu_composer_sysfs.o \
	dvfs/dpu_dvfs.o \
	abnormal/dpu_comp_abnormal_handle.o

# v700
# hisi_dpu_composer-objs += \
# 	dpu_composer_drv.o \
# 	composer_power.o \
# 	plat/plat_get_dpu_index.o \
# 	config/dpu_comp_config_v700.o

# v740
# hisi_dpu_composer-objs += \
# 	dpu_composer_drv_v740.o \
# 	composer_power_v740.o \
# 	plat/plat_get_dpu_index_v740.o \
# 	config/dpu_comp_config_v741.o

#v741
hisi_dpu_composer-objs += \
	dpu_composer_drv_v741.o \
	composer_power_v741.o \
	plat/plat_get_dpu_index_v741.o \
	config/dpu_comp_config_v741.o \
	fusa/dpu_comp_priv_fusa_handler.o \
	fusa/dpu_drm_fusa_data.o

ifeq ($(CONFIG_DPU_TBU_ECC),y)
hisi_dpu_composer-objs += \
	irq/dpu_isr_ecc.o
endif

EXTRA_CFLAGS += \
	-I$(srctree)/include \
	-I$(srctree)/include/linux \
	-I$(srctree)/include/platform_include/linux

EXTRA_CFLAGS += \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/cmdlist/pub \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/composer \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/opr_mgr \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/opr_mgr/operators \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/composer/dksm \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/composer/plat \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/ \
	-I$(srctree)/platform_source/basicplatform/drivers/smmu \
	-I$(srctree)/platform_source/basicplatform/drivers/mntn/blackbox/diaginfo

EXTRA_CFLAGS += \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/composer \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/opr_mgr \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/opr_mgr/operators \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/composer/dksm \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/composer/plat

EXTRA_CFLAGS += \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/cmdlist/pub \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/composer \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/opr_mgr \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/opr_mgr/operators \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/composer/dksm \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/composer/plat

ifeq ($(chip_type),)
EXTRA_CFLAGS += \
	-I$(TOP_DIR)/kernel/linux-5.10/drivers/platform_drivers/ap/platform/$(TARGET_PRODUCT)
else
EXTRA_CFLAGS += \
	-I$(TOP_DIR)/kernel/linux-5.10/drivers/platform_drivers/ap/platform/$(TARGET_PRODUCT)_$(chip_type)
endif

ifeq ($(chip_type),)
EXTRA_CFLAGS += \
	-I$(srctree)/drivers/platform_drivers/ap/platform/$(TARGET_PRODUCT)
else
EXTRA_CFLAGS += \
	-I$(srctree)/drivers/platform_drivers/ap/platform/$(TARGET_PRODUCT)_$(chip_type)
endif

ifeq ($(CONFIG_DPU_COMPOSER),m)
KERNEL_DIR = $(ANDROID_BUILD_TOP)/kernel/linux-5.10
KERNEL_OUT = $(ANDROID_PRODUCT_OUT)/obj/KERNEL_OBJ
PWD := $(shell pwd)
ARCH := arm64
CROSS_COMPILE := aarch64-linux-android-
CFLAGS_MODULE += -fno-pic

KBUILD_EXTRA_SYMBOLS += $(PWD)/../cmdlist/Module.symvers
export KBUILD_EXTRA_SYMBOLS

default:
	$(MAKE) -C $(KERNEL_OUT) ARCH=$(ARCH) CFLAGS=$(EXTRA_CFLAGS) CROSS_COMPILE=$(CROSS_COMPILE) M=$(PWD) modules
	$(MAKE) -C $(KERNEL_OUT) M=$(PWD) INSTALL_MOD_PATH=$(PWD)/signed INSTALL_MOD_STRIP=1 modules_install
endif

clean:
	rm -rf *.o .*.cmd *.ko *.mod *.mod.c .tmp_versions *.symvers *.order *.symversions signed .*.d
	find . -name "*.o" | xargs rm -f
	find . -name ".*.cmd" | xargs rm -f
	find . -name ".*.d" | xargs rm -f
	find . -name "*.gcno" | xargs rm -f