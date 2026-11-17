GCOV_PROFILE := $(CONFIG_GCOV_KERNEL)
EXTRA_CFLAGS += -I$(srctree)/platform_source/audio/sound/soc/codecs/vendor/
EXTRA_CFLAGS += -I$(srctree)/include/linux/platform_drivers/
EXTRA_CFLAGS += -I$(srctree)/platform_source/audio/sound/soc/platforms/common_image/
EXTRA_CFLAGS += -I$(srctree)/platform_source/audio/include/

snd-soc-asp-codec-rda-proxy-objs := asp_codec_rda_proxy.o
obj-$(CONFIG_CHARPRO_IP_PLATFORM) += snd-soc-asp-codec-rda-proxy.o

snd-soc-asp-codec-gt-proxy-objs := \
    asp_codec_gt_proxy.o \
    asp_codec_gt_proxy_common.o

obj-$(CONFIG_SND_GT_PROXY_CODEC) += snd-soc-asp-codec-gt-proxy.o
