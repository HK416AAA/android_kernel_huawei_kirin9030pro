ccflags-y += -Wextra -Wdate-time -Wfloat-equal -Wformat=2 -Wshadow

ifeq ($(TARGET_VERSION_MODE),factory)
ccflags-y += -DFACTORY_MODE
endif

EXTRA_CFLAGS += \
	-I$(srctree)/drivers/huawei_platform/ospm/power/eth_power_mgmt \

obj-$(CONFIG_HW_MOTORCOMM_PHY) += phy_driver.o
