obj-$(CONFIG_HW_MIPI2HDMI_CONNECTOR) += mipi2hdmi_driver.o

mipi2hdmi_driver-objs := \
	mipi2hdmi_connector.o \
	mipi2hdmi_lt9611.o \
	mipi2hdmi_redriver.o \
	mipi2hdmi_utils.o \
	lt9611uxc_fw.o \
	lt9611uxd_fw.o \
	mipi2hdmi_lt9611_upgrade.o \

EXTRA_CFLAGS += \
	-I$(srctree)/include/ \
	-I$(srctree)/arch/arm64/include/ \
	-I$(srctree)/include/platform_include/display/dkmd/ \
	-I$(srctree)/drivers/video/fbdev/dkmd/dksm \
	-I$(srctree)/drivers/video/fbdev/ukmd/uksm \
	-I$(srctree)/drivers/video/fbdev/dkmd/backlight \
	-I$(srctree)/drivers/video/fbdev/dkmd/dksm/peri \
	-I$(srctree)/drivers/video/fbdev/ukmd/uksm/isr \
	-I$(srctree)/drivers/video/fbdev/dkmd/connector \
	-I$(srctree)/drivers/video/fbdev/dkmd/connector/mipi \
	-I$(srctree)/drivers/video/fbdev/dkmd/connector/dsc \
	-I$(srctree)/drivers/video/fbdev/dkmd/connector/spr \
	-I$(srctree)/drivers/video/fbdev/dkmd/connector/offline \
	-I$(srctree)/drivers/video/fbdev/dkmd/connector/dptx/dp_ctrl \
	-I$(srctree)/drivers/video/fbdev/dkmd/connector/dptx/dp_ctrl/dfr \
	-I$(srctree)/drivers/video/fbdev/dkmd/connector/panel \
	-I$(srctree)/drivers/video/fbdev/dkmd/connector/serdes/common \
	-I$(srctree)/drivers/video/fbdev/dkmd/connector/edid \

clean:
	rm -rf *.o .*.cmd *.ko *.mod.c .tmp_versions *.symvers *.order *.symversions signed .*.d
	find . -name "*.o" | xargs rm -f
	find . -name ".*.cmd" | xargs rm -f
	find . -name ".*.d" | xargs rm -f
	find . -name "*.gcno" | xargs rm -f