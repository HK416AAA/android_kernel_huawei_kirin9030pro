CHIP_VERSION := $(strip $(subst ", ,$(CONFIG_VENDOR_CHIP_PREFIX)))
CHIP_TYPE :=$(strip $(subst ", ,$(CONFIG_VENDOR_CHIP_SUFFIX)))

ifeq ($(CONFIG_HISP_DEBUG), y)
subdir-ccflags-y += -DDEBUG_HISP
ifeq ($(CONFIG_KCOV), y)
subdir-ccflags-y += -DHISP_KERNEL_FUZZ
endif
endif

ifeq ($(es_low_freq),true)
subdir-ccflags-y += -DCONFIG_ES_ISP_LOW_FREQ
endif

ifeq ($(CONFIG_ISP_BUF_PRIVATIZE), y)
subdir-ccflags-y += -DISP_BUF_PRIVATIZE
endif

ifeq ($(CONFIG_ISP_LINX_CPU_SUPPORT), y)
subdir-ccflags-y += -DISP_LINX_CPU_SUPPORT
# subdir-ccflags-y += -DISP_DMA_SPLITTED_SID
endif

ifeq ($(CONFIG_HISP_USE_FRIGATE), y)
subdir-ccflags-y += -DHISP_USE_FRIGATE
endif

obj-$(CONFIG_ISP) += hisp_device_driver/
obj-$(CONFIG_ISP_LINX_CPU_SUPPORT) += hisp_device_node/
obj-$(CONFIG_ISP) += hisp_driver_adapter/

ifdef CONFIG_HISP_SMARTISP_ENABLE
subdir-ccflags-y += -DHISP_SMARTISP_ENABLE
endif

ifdef CONFIG_ISP_SET_KTHREADD_VIP
subdir-ccflags-y += -DISP_SET_KTHREADD_VIP
endif

ifeq ($(CONFIG_ISP), y)
subdir-ccflags-y += -Wdate-time -Wextra -Wfloat-equal -Wformat=2 -Wshadow
subdir-ccflags-y += -I$(srctree)/drivers/platform_drivers/tzdriver \
                    -I$(srctree)/drivers/rpmsg \
                    -I$(srctree)/platform_source/see/drivers/load_image \
                    -I$(srctree)/platform_source/basicplatform/drivers/mntn/blackbox \
                    -I$(srctree)/platform_source/camera/drivers/media/native/camera \
                    -I$(srctree)/platform_source/camera/drivers/media/native/camera/sensor \
                    -I$(srctree)/platform_source/camera/drivers/media/native/camera/platform \
					-I$(srctree)/platform_source/isp/drivers/isp/hisp_include \
                    -I$(srctree)/../../vendor/huawei/chipset_common/plugins/kernel/include \
                    -I$(srctree)/drivers/platform_drivers/ap/platform/common
endif

ifneq ($(filter y,$(CONFIG_FFRT_UNIFORM_ID) $(CONFIG_FFRT_UNIFORM_ID_OHOS)),)
subdir-ccflags-y += -I$(srctree)/include/platform_include/ffrt/uniform_id
subdir-ccflags-y += -DCONFIG_FFRT_UNIFORM_ID
endif

ifeq ($(CONFIG_ISP_LINX_CPU_SUPPORT), y)
subdir-ccflags-y += -I$(srctree)/platform_include/isp/linux/hisp_msg
endif

ifeq ($(CONFIG_HISP_FUZZ), y)
subdir-ccflags-y += -DHISP_FUZZ
ifeq ($(CONFIG_HISP_KCOV_ENABLE_DUMP), y)
subdir-ccflags-y += -DHISP_KCOV_ENABLE_DUMP
endif
obj-$(CONFIG_ISP) += hisp_test/
endif
