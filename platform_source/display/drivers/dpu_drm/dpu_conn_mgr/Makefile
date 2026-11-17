obj-$(CONFIG_DPU_CONN_MANAGER) += dpu_conn_manager.o

dpu_conn_manager-objs := \
	dpu_conn_mgr.o \
	dpu_connector.o

EXTRA_CFLAGS += \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm/peri \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm/isr \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp_ctrl \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp_dsc \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/composer \


EXTRA_CFLAGS += \
	-I$(srctree)/include/ \


clean:
	rm -rf *.o .*.cmd *.ko *.mod *.mod.c .tmp_versions *.symvers *.order *.symversions signed .*.d
	find . -name "*.o" | xargs rm -f
	find . -name ".*.cmd" | xargs rm -f
	find . -name ".*.d" | xargs rm -f
	find . -name "*.gcno" | xargs rm -f

	