GCOV_PROFILE := $(CONFIG_GCOV_KERNEL)
subdir-ccflags-y += -Wall -Werror

EXTRA_CFLAGS += -I$(srctree)/platform_source/audio/drivers/hifi_dsp/
EXTRA_CFLAGS += -I$(srctree)/platform_source/audio/drivers/comm/
EXTRA_CFLAGS += -I$(srctree)/include/platform_include/audio/ipc
EXTRA_CFLAGS += -I$(srctree)/platform_source/audio/include
EXTRA_CFLAGS += -I$(srctree)/platform_source/audio/drivers/hifi_dsp/om/
EXTRA_CFLAGS += -I$(srctree)/platform_source/cee/drivers/thermal_platform/active_cooling_thermal/interface/

obj-$(CONFIG_AUDIO_BLOW_COGNITION) += blow_cognition.o
obj-$(CONFIG_AUDIO_COGNITION) += audio_cognition.o
obj-$(CONFIG_AUDIO_ENV_SOUND_COGNITION) += env_sound_cognition.o
obj-$(CONFIG_AUDIO_EMOTION_COGNITION) += emotion_cognition.o
obj-$(CONFIG_AUDIO_NOISE_SOUND_COGNITION) += noise_sound_cognition.o
obj-$(CONFIG_AUDIO_ENV_NOISE_COGNITION) += env_noise_cognition.o

ifeq ($(CONFIG_AUDIO_ENV_SOUND_COGNITION),y)
ifeq ($(CONFIG_AUDIO_DEBUG),y)
EXTRA_CFLAGS += -DOM_UPLOAD_COGNITION_DATA
endif
endif
