#
# Makefile for the vl53L0 drivers.
#

# Each configuration option enables a list of files.

ccflags-y += -I$(src)/vi5300
ccflags-y += -I$(src)/vi5302
ccflags-y += -I$(srctree)/platform_source/camera/drivers/media/native/camera/laser
obj-y += vi5300.o

# module
vi5300-objs := laser_vi5300_module.o

# vi5300
vi5300-objs += vi5300/vi5300_module.o vi5300/vi5300_platform.o vi5300/vi5300_api.o vi5300/vi5300_firmware.o

# vi5302
vi5300-objs += vi5302/vi5302_module.o vi5302/vi5302_platform.o vi5302/vi5302_api.o vi5302/vi5302_firmware.o

