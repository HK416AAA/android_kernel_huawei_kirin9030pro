#
# Makefile for nfc devices
#
#EXTRA_CFLAGS += -Idrivers/huawei/device
obj-$(CONFIG_NFC_WATCH_COMMU)		+= nfc_watch_commu.o

ifdef CONFIG_EXT_INPUTHUB
ifeq ($(wildcard $(srctree)/drivers/huawei_platform/sensor/ext_inputhub/$(TARGET_BOARD_PLATFORM)),)
ccflags-y  += -I$(srctree)/drivers/huawei_platform/sensor/ext_inputhub/default/
else
ccflags-y  += -I$(srctree)/drivers/huawei_platform/sensor/ext_inputhub/$(TARGET_BOARD_PLATFORM)/
endif
endif

