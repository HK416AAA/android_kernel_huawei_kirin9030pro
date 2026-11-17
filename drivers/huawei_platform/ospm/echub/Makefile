#
# Makefile for kernel echub driver.
#

subdir-ccflags-y += -I$(srctree)/drivers/huawei_platform/ospm/echub/

obj-$(CONFIG_ARMPC_ECHUB_I2C)	+= echub_i2c.o
obj-y	+= keyboard/
obj-$(CONFIG_ARMPC_ECHUB_PMSYNC)	  += power/
obj-$(CONFIG_ARMPC_ECHUB_LID)         += lid/
obj-$(CONFIG_ARMPC_ECHUB_BATTERY)	  += battery/
obj-y	+= fnled/
obj-$(CONFIG_ARMPC_ECHUB_HMI)		  += hmi/
obj-$(CONFIG_PC_ECHUB_THERMAL)		  += thermal/
obj-$(CONFIG_ARMPC_ECHUB_LOG)		  += echub_log/
obj-$(CONFIG_ARMPC_ECHUB_UPDATE)	  += echub_update/
obj-$(CONFIG_ARMPC_ECHUB_RTC)		  += rtc/
obj-$(CONFIG_ARMPC_ECHUB_SWITCH)      += switch/
obj-$(CONFIG_ARMPC_ECHUB_POGOPIN)     += pogopin/
