ccflags-y += -Wextra -Wshadow
obj-$(CONFIG_DPU_OPR_MGR) += hisi_dpu_opr_mgr.o

hisi_dpu_opr_mgr-objs := \
	operators/cmd_manager.o \
	operators/cmd_manager_impl.o \
	operators/opr_cmd_data_interface.o \
	operators/cmd_manager_adaptor.o \
	plat/dpu_addr.o \
	osal/dpu_osal.o \
	opr_mgr.o

# ifeq ($(CONFIG_DPU_CMDLIST))
# hisi_dpu_opr_mgr += operators/opr_cmd_util_cmdlist.o
# else
# hisi_dpu_opr_mgr += operators/opr_cmd_util_cpu.o
# endif

hisi_dpu_opr_mgr-objs += operators/opr_cmd_util_cmdlist.o

hisi_dpu_opr_mgr-objs += \
	operators/sdma/sdma_cmd_data.o \
	operators/opr_format.o \
	operators/opr_hebce.o \
	operators/opr_compress_strategy.o \
	operators/opr_cmd_data.o \
	dksm/dpu_format.o

hisi_dpu_opr_mgr-objs += \
	operators/ov/ov_cmd_data.o \
	operators/opr_csc.o

hisi_dpu_opr_mgr-objs += \
	operators/dpp/dpp_cmd_data.o

hisi_dpu_opr_mgr-objs += \
	operators/itfsw/itfsw_cmd_data.o

hisi_dpu_opr_mgr-objs += \
	network/network_generater.o \
	plat/dpu_network_cfg.o

hisi_dpu_opr_mgr-objs += \
	operators/fusa/dpuv74x/ffd/plat_opr_ffd.o \
	operators/fusa/dpuv74x/le/plat_opr_le.o

EXTRA_CFLAGS += \
	-I$(srctree)/include \
	-I$(srctree)/include/platform_include/linux \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/ \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/cmdlist/pub \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/opr_mgr \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/opr_mgr/plat \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/opr_mgr/dksm \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/opr_mgr/operators \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/gem \
	-I$(srctree)/platform_source/display/drivers/cdc_rda/drm/opr_mgr/operators/fusa

EXTRA_CFLAGS += \
	-I$(srctree)/include \
	-I$(srctree)/platform_source/display/drivers/dpu_drm \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/cmdlist/pub \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/opr_mgr \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/opr_mgr/plat \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/opr_mgr/dksm \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/opr_mgr/operators

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

ifeq ($(CONFIG_DPU_OPR_MGR),m)
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