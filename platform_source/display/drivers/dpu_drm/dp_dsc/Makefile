obj-$(CONFIG_DP_DSC) += hisi_dp_dsc.o


hisi_dp_dsc-objs := \
	dsc_debug.o \
	dsc_algorithm_manager.o \
	dsc_algorithm.o \
	dsc_output_calc.o \
	dsc_config.o


EXTRA_CFLAGS += \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp  \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm/peri \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm/isr \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp_ctrl \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dpu_conn_mgr \

EXTRA_CFLAGS += \
	-I$(srctree)/include/ \


clean:
	rm -rf *.o .*.cmd *.ko *.mod *.mod.c .tmp_versions *.symvers *.order *.symversions signed .*.d
	find . -name "*.o" | xargs rm -f
	find . -name ".*.cmd" | xargs rm -f
	find . -name ".*.d" | xargs rm -f
	find . -name "*.gcno" | xargs rm -f

	