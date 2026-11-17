subdir-ccflags-y              += -Wall -Werror

EXTRA_CFLAGS += -I$(srctree)/platform_source/see/drivers/safety_island
EXTRA_CFLAGS += -I$(srctree)/include/linux
EXTRA_CFLAGS += -DTARGET_ENV_ACPU

obj-$(CONFIG_SAFETY_ISLAND)  += safety_island.o
obj-$(CONFIG_SAFETY_ISLAND)  += sils_power.o
obj-$(CONFIG_SAFETY_ISLAND)  += sils_mntn.o
obj-$(CONFIG_SAFETY_ISLAND)  += sils_msg.o
obj-$(CONFIG_SAFETY_ISLAND)  += sils_dev.o
obj-$(CONFIG_SAFETY_ISLAND_RDA_HEARTBEAT)  += sils_heartbeat.o

# need define manually
# CONFIG_SAFETY_ISLAND_TEST := y
# EXTRA_CFLAGS += -DCONFIG_SAFETY_ISLAND_TEST
ifeq ($(CONFIG_SAFETY_ISLAND_ENG),y)
obj-$(CONFIG_SAFETY_ISLAND_TEST) += test/
endif
