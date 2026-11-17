# slimbus driver
GCOV_PROFILE := $(CONFIG_GCOV_KERNEL)
subdir-ccflags-y += -Wall -Werror
ifeq ($(USE_BISHENG_CLANG),true)
subdir-ccflags-y += -Wno-error=unused-but-set-variable
endif

ccflags-y += -I$(srctree)/drivers/devkit/audiokit/

ccflags-y += -I$(srctree)/platform_source/audio/drivers/codec_bus/slimbus/vendor/include
ccflags-y += -I$(srctree)/platform_source/audio/drivers/codec_bus/slimbus/vendor
ccflags-y += -I$(srctree)/include/platform_include/audio/platform_drivers/codec_bus/
ccflags-y += -I$(srctree)/platform_source/audio/drivers/codec_bus/slimbus/
ccflags-y += -I$(srctree)/platform_source/audio/drivers/codec_bus/
ccflags-y += -I$(srctree)/platform_source/audio/sound/soc/platforms
ccflags-y += -I$(srctree)/platform_source/audio/drivers/rdr/
ccflags-y += -I$(srctree)/platform_source/audio/sound/soc/platforms/common_image/
ccflags-y += -I$(srctree)/platform_source/audio/include/

slimbus-platform-objs := vendor/slimbus_drv_bm.o vendor/src/slimbus_drv_api.o slimbus_drv.o
slimbus-platform-objs += slimbus.o slimbus_utils.o slimbus_pm.o slimbus_da_combine.o slimbus_da_combine_v3.o

ifeq ($(CONFIG_SND_SOC_DA_COMBINE_V5),y)
slimbus-platform-objs += slimbus_da_combine_v5.o
endif

ifeq ($(CONFIG_AUDIO_DEBUG),y)
ifneq ($(CONFIG_KCOV),y)
slimbus-platform-objs += slimbus_debug.o
endif
endif

obj-$(CONFIG_PLATFORM_SLIMBUS) += slimbus-platform.o
