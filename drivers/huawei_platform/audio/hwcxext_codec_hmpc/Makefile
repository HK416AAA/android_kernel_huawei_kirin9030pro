# hwcxext codec module pc

ifdef CONFIG_HWCXEXT_CODEC_MODULE_HMPC
	ccflags-y += -Idrivers/huawei_platform/audio/hwcxext_codec_hmpc
	ccflags-y += -Idrivers/devkit/audiokit/
	ccflags-y += -I$(srctree)/drivers/devkit/audiokit/
	ccflags-y += -Idrivers/hisi/tzdriver
endif

ifneq ($(TARGET_BUILD_VARIANT),user)
	ccflags-y += -DHWCXEXT_CODEC_INFO_PERMISSION_ENABLE
endif

obj-$(CONFIG_HWCXEXT_CODEC_MODULE_HMPC) += hwcxext_log.o
obj-$(CONFIG_HWCXEXT_CODEC_INTERFACE_HMPC) += hwcxext_codec_interfacehm.o
obj-$(CONFIG_HWCXEXT_MBHC_HMPC) += hwcxext_mbhc.o
obj-$(CONFIG_HWCXEXT_I2C_OPS_HMPC) += hwcxext_i2c_ops.o
obj-$(CONFIG_HWCXEXT_CODEC_V1_HMPC) += hwcxext_codec_v1.o
obj-$(CONFIG_HWCXEXT_CODEC_MODULE_HMPC) += hwcxext_codec_ctl.o

ifneq ($(TARGET_BUILD_VARIANT),user)
	obj-$(CONFIG_HWCXEXT_CODEC_MODULE_HMPC) += hwcxext_codec_info.o
endif
