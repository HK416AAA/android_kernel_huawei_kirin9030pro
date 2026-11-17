hisi_dpu_bridge-objs := \
	common/drm_adapter.o \
	common/bridge_base_operator.o \
	common/bridge_dts_parse.o \
	mipi2hdmi/mipi2hdmi_interface_manager.o \
	mipi2hdmi/mipi2hdmi_sequence_operator.o \
	mipi2hdmi/mipi2hdmi_bridge.o \
	mipi2hdmi/lt9611ux.o \
	mipi2hdmi/lt9611uxd.o \
	mipi2hdmi/mipi2hdmi_desktop.o

obj-$(CONFIG_DPU_DRM_BRIDGE) += hisi_dpu_bridge.o

EXTRA_CFLAGS += \
		-Iinclude/drm

EXTRA_CFLAGS += \
	-I$(srctree)/include \
	-I$(srctree)/vendor/drivers/dpu_drm/bridge \
	-I$(srctree)/vendor/drivers/dpu_drm

EXTRA_CFLAGS += \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/mipi \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/bridge \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/panel \
	-I$(srctree)/platform_source/audio/sound/soc/codecs/vendor/asp_codec_codecless/store

EXTRA_CFLAGS += \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm/peri \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm/isr 

clean:
	rm -rf *.o .*.cmd *.ko *.mod *.mod.c .tmp_versions *.symvers *.order *.symversions signed .*.d
	find . -name "*.o" | xargs rm -f
	find . -name ".*.cmd" | xargs rm -f
	find . -name ".*.d" | xargs rm -f
	find . -name "*.gcno" | xargs rm -f