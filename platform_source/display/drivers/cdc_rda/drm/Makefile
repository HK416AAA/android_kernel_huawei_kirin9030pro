ccflags-y += -Wextra -Wshadow
EXTRA_CFLAGS += -fstack-protector-all

obj-$(CONFIG_DPU_OPR_MGR) += opr_mgr/
obj-$(CONFIG_DPU_MIPI_DSI) += mipi/
obj-$(CONFIG_DPU_PANEL) += panel/
obj-$(CONFIG_DPU_COMPOSER) += composer/
obj-$(CONFIG_DPU_CMDLIST) += cmdlist/

ifneq ($(CONFIG_RDA_DISPLAY_SELECT_CPRO),y)
obj-$(CONFIG_DPU_PANEL) += serdes/
endif

obj-$(CONFIG_DPU_DRM) += dpu_drm.o

EXTRA_CFLAGS += \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/cmdlist/pub \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/composer \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/opr_mgr \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/operators \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/dksm \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/plat

dpu_drm-objs := \
	dpu_drm_drv.o \
	dpu_kms.o

obj-$(CONFIG_DPU_DRM_GEM) += gem/dpu_drm_gem.o

EXTRA_CFLAGS += \
	-I$(srctree)/include \
	-I$(srctree)/include/platform_include

ifeq ($(CONFIG_DPU_DRM),m)

KERNEL_DIR = $(ANDROID_BUILD_TOP)/kernel/linux-5.10
KERNEL_OUT = $(ANDROID_PRODUCT_OUT)/obj/KERNEL_OBJ
PWD := $(shell pwd)
ARCH := arm64
CROSS_COMPILE := aarch64-linux-android-
CFLAGS_MODULE += -fno-pic

KBUILD_EXTRA_SYMBOLS += $(PWD)/cmdlist/Module.symvers
export KBUILD_EXTRA_SYMBOLS

default:
	$(MAKE) -C $(KERNEL_OUT) ARCH=$(ARCH) CFLAGS=$(EXTRA_CFLAGS) CROSS_COMPILE=$(CROSS_COMPILE) M=$(PWD) modules
	$(MAKE) -C $(KERNEL_OUT) M=$(PWD) INSTALL_MOD_PATH=$(PWD)/signed INSTALL_MOD_STRIP=1 modules_install
endif

clean:
	rm -rf *.o .*.cmd *.ko *.mod *.mod.c .tmp_versions *.symvers *.order *.symversions signed .*.d
	find . -name "*.mod" | xargs rm -f
	find . -name "*.mod.c" | xargs rm -f
	find . -name "*.o" | xargs rm -f
	find . -name ".*.cmd" | xargs rm -f
	find . -name ".*.d" | xargs rm -f
	find . -name "*.gcno" | xargs rm -f
	find . -name "*.ko" | xargs rm -f
	find . -name "*.symvers" | xargs rm -f
	find . -name "*.order" | xargs rm -f
	find . -name "*.symversions" | xargs rm -f
	find . -name "*.mod.c" | xargs rm -f
	find . -type d -name signed | xargs rm -r
