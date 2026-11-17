KERNEL_DIR := $(srctree)

SCHED_SOC_CHIP_NAME :=$(strip $(subst ", ,$(CONFIG_VENDOR_CHIP_PREFIX)))
EXTRA_CFLAGS += -I$(KERNEL_DIR)/drivers/platform_drivers/ap/platform/common/

obj-$(CONFIG_SCHED_CHIP_INFO) += sched_chip_info.o

ifneq ($(SCHED_SOC_CHIP_NAME), " ")
obj-$(CONFIG_SCHED_CHIP_INFO) += $(SCHED_SOC_CHIP_NAME)/sched_chip_info_plat.o
endif

