ccflags-y += -Wdate-time -Wextra -Wfloat-equal -Wformat=2 -Wshadow

SOC_PLATFORM := $(strip $(subst ", ,$(CONFIG_VENDOR_CHIP_PREFIX)))
SOC_CHIP_TYPE := $(strip $(subst ", , $(CONFIG_VENDOR_CHIP_SUFFIX)))

ifneq ($(SOC_CHIP_TYPE),)
EXTRA_CFLAGS += -I$(srctree)/drivers/platform_drivers/ap/platform/$(SOC_PLATFORM)
else
EXTRA_CFLAGS += -I$(srctree)/drivers/platform_drivers/ap/platform/$(SOC_PLATFORM)_$(SOC_CHIP_TYPE)
endif

EXTRA_CFLAGS += -I$(srctree)/drivers/platform_drivers/ap/platform/common

ifneq ($(TARGET_BUILD_VARIANT),user)
obj-$(CONFIG_PERCHIP_VMIN) += perchip_vmin.o
endif
