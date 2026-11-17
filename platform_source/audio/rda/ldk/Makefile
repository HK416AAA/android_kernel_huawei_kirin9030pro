ifeq ($(CONFIG_RDA_AUDIO_DRIVERS),y)
ifneq ($(wildcard $(srctree)/platform_source/audio/rda/ldk),)
RDA_AUDIO_SRC_PATH := platform_source/audio/rda/ldk
else
RDA_AUDIO_SRC_PATH := vendor/drivers/audio
endif

export RDA_AUDIO_SRC_PATH
EXTRA_CFLAGS += -I$(srctree)/$(RDA_AUDIO_SRC_PATH)/include
obj-$(CONFIG_RDA_AUDIO_DRIVERS) += common_image/platform_base_addr_info.o
endif

obj-$(CONFIG_RDA_AUDIO_DRIVERS) += hifi_dsp/
obj-$(CONFIG_RDA_AUDIO_DRIVERS) += codecs/
obj-$(CONFIG_RDA_AUDIO_DRIVERS) += hifi_mailbox/
obj-$(CONFIG_RDA_AUDIO_DRIVERS) += rda_rdr/
obj-$(CONFIG_RDA_AUDIO_DRIVERS) += a2b/