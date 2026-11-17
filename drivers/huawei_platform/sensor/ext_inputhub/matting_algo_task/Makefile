ccflags-y += -I$(srctree)/drivers/huawei_platform/sensor/ext_inputhub/default/
ccflags-y += -I$(srctree)/drivers/huawei_platform/sensor/ext_inputhub/file_transfer/
ccflags-y += -I$(srctree)/drivers/huawei_platform/sensor/ext_inputhub/matting_algo_task/
ccflags-y += -I$(srctree)/../../vendor/huawei/chipset_common/devkit/lcdkit/lcdkit3.0/kernel/qcom/include/
ccflags-y += -I$(srctree)/../../vendor/huawei/chipset_common/devkit/lcdkit/lcdkit3.0/kernel/qcom/src/hybrid/
ccflags-y += -I$(srctree)/../../vendor/huawei/chipset_common/devkit/lcdkit/lcdkit3.0/kernel/qcom/common/include/
ccflags-y += -I$(srctree)/../../vendor/huawei/chipset_common/devkit/lcdkit/lcdkit3.0/kernel/qcom/adapt/
ccflags-y += -I$(srctree)/../../vendor/huawei/chipset_common/devkit/lcdkit/lcdkit3.0/kernel/common/include/
ccflags-y += -I$(srctree)/../../vendor/huawei/chipset_common/devkit/tpkit/3_0/hybrid/
ccflags-y += -I$(srctree)/../../vendor/huawei/chipset_common/devkit/tpkit/3_0/
ccflags-y += -I$(srctree)/techpack/display/msm/
ccflags-y += -I$(srctree)/techpack/display/msm/dsi/
ccflags-y += -I$(srctree)/techpack/display/include/
ccflags-y += -I$(srctree)/techpack/display/include/uapi/display/
ccflags-y += -I$(srctree)/techpack/display/include/uapi/display/drm/
ccflags-y += -I$(srctree)/include/
ccflags-y += -I$(srctree)/include/drm/
ccflags-y += -I$(srctree)/drivers/clk/qcom/
ifneq ($(CONFIG_EXT_INPUTHUB_MATTING_ALSC), y)
ccflags-y += -I$(srctree)/arch/arm/include/asm/
else
ccflags-y += -I$(srctree)/include/asm-generic
ccflags-y += -I$(srctree)/include/platform_include/display/dkmd
ccflags-y += -I$(srctree)/../../vendor/huawei/chipset_common/devkit/lcdkit/lcdkit3.0/kernel/dkmd/include
ccflags-y += -I$(srctree)/include/linux
endif

obj-$(CONFIG_EXT_INPUTHUB_MATTING) += image_compositing_algo.o
obj-$(CONFIG_EXT_INPUTHUB_MATTING) += matting_algo_task.o
obj-$(CONFIG_EXT_INPUTHUB_MATTING) += als_matting_algo.o
obj-$(CONFIG_EXT_INPUTHUB_MATTING) += math_calculation.o
obj-$(CONFIG_EXT_INPUTHUB_MATTING) += formula_als.o
ifneq ($(CONFIG_EXT_INPUTHUB_MATTING_ALSC), y)
obj-$(CONFIG_EXT_INPUTHUB_MATTING) += matting_algo_fs_interface.o
else
obj-$(CONFIG_EXT_INPUTHUB_MATTING_ALSC) += matting_algo_udev_device_interface.o
obj-$(CONFIG_EXT_INPUTHUB_MATTING_ALSC) += matting_algo_hisi_alsc_interface.o
endif
