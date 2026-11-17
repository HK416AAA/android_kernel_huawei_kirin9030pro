FFTS_CHIP_VERSION := $(strip $(subst ", ,$(CONFIG_FFRT_FFTS_VERSION)))

ifneq ($(FFTS_CHIP_VERSION),)
	include $(srctree)/platform_source/ffrt/ffts/fpd/$(FFTS_CHIP_VERSION).mk
endif

EXTRA_CFLAGS += -I$(FPD_DIR)/
EXTRA_CFLAGS += -I$(FPD_DIR)/$(FFTS_ARCH_VERSION)/
EXTRA_CFLAGS += -I$(FKD_DIR)/
EXTRA_CFLAGS += -I$(FKD_DIR)/core
EXTRA_CFLAGS += -I$(FKD_DIR)/communication
EXTRA_CFLAGS += -I$(FKD_DIR)/inc
EXTRA_CFLAGS += -I$(FKD_DIR)/dfx
EXTRA_CFLAGS += -I$(FKD_DIR)/dfx/bbox
EXTRA_CFLAGS += -I$(UNIFORM_ID_DIR)/
EXTRA_CFLAGS += -I$(srctree)/drivers/platform_drivers/ap/platform/$(FFTS_CHIP_PLATFORM_DIR)
EXTRA_CFLAGS += $(FFTS_GLOBAL_CFLAGS)
EXTRA_CFLAGS += -I$(srctree)/include/platform_include/ffrt/ffts/
EXTRA_CFLAGS += -I$(srctree)/include/platform_include/see/ffa

obj-y += fpd.o

fpd-objs :=  fpd_main.o ffts_platform_pm.o

obj-y += $(FFTS_FILE_OBJECTS)