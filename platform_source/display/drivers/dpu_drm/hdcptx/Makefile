obj-$(CONFIG_DPU_HDCPTX) += hisi_dpu_hdcptx.o


hisi_dpu_hdcptx-objs := \
	hdcp_common.o 

EXTRA_CFLAGS += \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm/peri \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm/isr \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp_dsc \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp_ctrl \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dpu_conn_mgr \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp_ctrl/config/default 



EXTRA_CFLAGS += \
	-I$(srctree)/include/ \


clean:
	rm -rf *.o .*.cmd *.ko *.mod *.mod.c .tmp_versions *.symvers *.order *.symversions signed .*.d
	find . -name "*.o" | xargs rm -f
	find . -name ".*.cmd" | xargs rm -f
	find . -name ".*.d" | xargs rm -f
	find . -name "*.gcno" | xargs rm -f

	