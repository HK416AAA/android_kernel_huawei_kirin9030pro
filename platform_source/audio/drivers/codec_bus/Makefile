# codec bus driver
GCOV_PROFILE := $(CONFIG_GCOV_KERNEL)
subdir-ccflags-y += -Werror -Wdate-time -Wfloat-equal -Wformat=2
ccflags-y += -I$(srctree)/platform_source/audio/drivers/codec_bus/
ccflags-y += -I$(srctree)/include/linux/platform_drivers/
ccflags-y += -I$(srctree)/include/platform_include/audio/platform_drivers/codec_bus/
ccflags-y += -I$(srctree)/platform_source/audio/drivers/rdr/
ccflags-y += -I$(srctree)/platform_source/audio/sound/soc/platforms/common_image/
ccflags-y += -I$(srctree)/platform_source/audio/include/

obj-$(CONFIG_PLATFORM_SLIMBUS) += slimbus/
obj-$(CONFIG_PLATFORM_SOUNDWIRE) += soundwire/

obj-$(CONFIG_CODEC_BUS) += codec_bus.o
