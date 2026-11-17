subdir-ccflags-y += -Wall -Werror

EXTRA_CFLAGS += -I$(srctree)/$(RDA_AUDIO_SRC_PATH)/include/
EXTRA_CFLAGS += -I$(srctree)/$(RDA_AUDIO_SRC_PATH)/hifi_mailbox/mailbox/
EXTRA_CFLAGS += -I$(srctree)/$(RDA_AUDIO_SRC_PATH)/hifi_mailbox/ipcm/
EXTRA_CFLAGS += -I$(srctree)/$(RDA_AUDIO_SRC_PATH)/common_image
ifneq ($(findstring platform_source,$(RDA_AUDIO_SRC_PATH)),)
EXTRA_CFLAGS += -I$(srctree)/include/platform_include/audio/ipc/
EXTRA_CFLAGS += -I$(srctree)/include/platform_include/
else
EXTRA_CFLAGS += -I$(srctree)/vendor/include/platform_include/audio/ipc/
EXTRA_CFLAGS += -I$(srctree)/vendor/include/
endif
EXTRA_CFLAGS += -I$(HMSDKSYSROOTPATH)/usr/include/plugins/

ifeq ($(CONFIG_AUDIO_RDA_HIVIEW),y)
ifneq ($(findstring platform_source,$(RDA_AUDIO_SRC_PATH)),)
EXTRA_CFLAGS += -I$(srctree)/drivers/rda_drivers/hiviewlite/
else
EXTRA_CFLAGS += -I$(srctree)/vendor/ics_drivers/hiviewlite/
endif
endif

ifeq ($(CONFIG_VM_PRESET),y)
obj-$(CONFIG_AUDIO_NRDA_RESET)  += nrda_reset.o
endif

obj-$(CONFIG_RDA_HIFI_DSP_DRV)	+= dsp_misc.o
obj-$(CONFIG_RDA_HIFI_DSP_DRV)	+= dsp_msg.o
obj-$(CONFIG_RDA_HIFI_DSP_DRV)	+= dsp_proc.o
obj-$(CONFIG_RDA_HIFI_DSP_DRV)	+= dsp_debug.o
