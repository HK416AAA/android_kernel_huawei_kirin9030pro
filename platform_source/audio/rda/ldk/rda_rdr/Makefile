obj-y += rdr_audio_adapter.o
obj-y += rdr_audio_dump_socdsp.o

ifeq ($(CONFIG_HIFI_DSP_ONE_TRACK),y)
obj-y += rdr_audio_soc.o
EXTRA_CFLAGS += -DRDR_SOCDSP
endif

ifneq ($(findstring platform_source,$(RDA_AUDIO_SRC_PATH)),)
EXTRA_CFLAGS += -I$(srctree)/platform_source/basicplatform/drivers/mntn/blackbox
else
EXTRA_CFLAGS += -I$(srctree)/vendor/drivers/platform_drivers/mntn/blackbox
endif
EXTRA_CFLAGS += -I$(srctree)/$(RDA_AUDIO_SRC_PATH)/include
EXTRA_CFLAGS += -I$(srctree)/$(RDA_AUDIO_SRC_PATH)/common_image
EXTRA_CFLAGS += -I$(srctree)/$(RDA_AUDIO_SRC_PATH)/hifi_dsp
EXTRA_CFLAGS += -I$(srctree)/$(RDA_AUDIO_SRC_PATH)/codecs

