SENSORHUB_SOC_CHIP_NAME := $(strip $(subst ", ,$(CONFIG_VENDOR_CHIP_PREFIX)))
 
ifeq ($(wildcard $(srctree)/drivers/huawei_platform/inputhub/$(SENSORHUB_SOC_CHIP_NAME)),)
ccflags-y  += -I$(srctree)/drivers/huawei_platform/inputhub/default/
else
ccflags-y  += -I$(srctree)/drivers/huawei_platform/inputhub/$(SENSORHUB_SOC_CHIP_NAME)/
endif
EXTRA_CFLAGS += -Idrivers/platform_drivers/tzdriver
 
ccflags-y  += -I$(srctree)/platform_source/smart/drivers/channels/
 
obj-$(CONFIG_CONTEXTHUB_LPC) += smart_lpc_dev.o


ifeq ($(CONFIG_FFRT_UNIFORM_ID),y)
	EXTRA_CFLAGS += -I$(srctree)/include/platform_include/ffrt/uniform_id
endif
ifeq ($(CONFIG_FFRT_UNIFORM_ID_OHOS),y)
	EXTRA_CFLAGS += -I$(srctree)/include/platform_include/ffrt/uniform_id
	EXTRA_CFLAGS += -DCONFIG_FFRT_UNIFORM_ID
endif