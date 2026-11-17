
obj-${CONFIG_DPU_OPR_SDMA} += hisi_dpu_opr_sdma.o

hisi_dpu_opr_sdma-objs := \
	sdma_cmd_data.o \
	../opr_format.o \
	../opr_hebce.o \
	../opr_compress_strategy.o \
	../opr_cmd_data.o \
	../../dksm/dpu_format.o

EXTRA_CFLAGS += \
	-I$(srctree)/include \
	-I$(srctree)/platform_source/display/drivers/dpu_drm \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/opr_mgr \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/opr_mgr/plat \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/opr_mgr/dksm \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/opr_mgr/operators

ifeq ($(chip_type),)
EXTRA_CFLAGS += \
	-I$(srctree)/drivers/platform_drivers/ap/platform/$(TARGET_PRODUCT)
else
EXTRA_CFLAGS += \
	-I$(srctree)/drivers/platform_drivers/ap/platform/$(TARGET_PRODUCT)_$(chip_type)
endif

ifeq ($(CONFIG_DPU_OPR_SDMA),m)
KERNEL_DIR = $(ANDROID_BUILD_TOP)/kernel/linux-5.10
KERNEL_OUT = $(ANDROID_PRODUCT_OUT)/obj/KERNEL_OBJ
PWD := $(shell pwd)
ARCH := arm64
CROSS_COMPILE := aarch64-linux-android-
CFLAGS_MODULE += -fno-pic

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