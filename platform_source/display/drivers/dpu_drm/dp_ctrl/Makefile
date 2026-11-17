obj-$(CONFIG_DPU_DP_CTRL) += hisi_dp_ctrl.o


hisi_dp_ctrl-objs := \
	controller/dp_avgen_base.o \
	controller/hidptx/hidptx_dp_aux.o \
	controller/hidptx/hidptx_dp_irq.o \
	controller/hidptx/hidptx_dp_avgen.o \
	controller/hidptx/hidptx_dp_core.o \
	controller/dsc/hidptx_dsc_config.o \
	controller/dsc/dsc_config_base.o \
	controller/psr/psr_config_base.o \
	link/dp_irq.o \
	link/dp_aux.o \
	link/dp_edid.o \
	link/dp_link_training.o \
	link/dp_mst_topology.o \
	link/dp_dsc_algorithm.o \
	link/drm_dp_helper.o \
	dp_ctrl_dev.o \
	dpu_dp_dbg.o
	

ifeq ($(CONFIG_DRM_DPU_VERSION),$(filter $(CONFIG_DRM_DPU_VERSION), 800))
hisi_dp_ctrl-objs += \
	config/v800/dp_ctrl_config.o \
	phy/hidptx_phy_config_v800.o
else
hisi_dp_ctrl-objs += \
	config/default/dp_ctrl_config.o \
	phy/hidptx_phy_config.o
endif

EXTRA_CFLAGS += \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm/peri \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dksm/isr \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp_dsc \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dpu_conn_mgr \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp_ctrl \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp_ctrl/controller \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp_ctrl/controller/hidptx \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp_ctrl/controller/psr \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp_ctrl/link \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp_ctrl/phy \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/hdcptx \
	-I$(srctree)/drivers/platform_drivers/ap/platform/common

ifeq ($(CONFIG_DRM_DPU_VERSION),$(filter $(CONFIG_DRM_DPU_VERSION), 800))
EXTRA_CFLAGS += \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp_ctrl/config/v800
else
EXTRA_CFLAGS += \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/dp_ctrl/config/default
endif

EXTRA_CFLAGS += \
	-I$(srctree)/platform_source/display/drivers/dpu_drm/composer/dacc \

EXTRA_CFLAGS += \
	-I$(srctree)/include/ \


clean:
	rm -rf *.o .*.cmd *.ko *.mod *.mod.c .tmp_versions *.symvers *.order *.symversions signed .*.d
	find . -name "*.o" | xargs rm -f
	find . -name ".*.cmd" | xargs rm -f
	find . -name ".*.d" | xargs rm -f
	find . -name "*.gcno" | xargs rm -f

	