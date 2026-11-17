ccflags-y += -Wdate-time -Wextra -Wfloat-equal -Wformat=2 -Wshadow

PLATFORM_PATH := $(strip $(subst ", , $(CONFIG_IP_REGULATOR_PLATFORM)))

EXTRA_CFLAGS += -I$(srctree)/platform_source/basicplatform/drivers/regulator/regulator_mdfx_mntn/$(PLATFORM_PATH)
EXTRA_CFLAGS += -I$(srctree)/platform_source/display/drivers/video/dkmd/mdfx/
obj-$(CONFIG_MDFX_KMD) += regulator_mdfx_mntn.o
