ARCH_VERSION=v200
HTS_VERSION := $(strip $(subst ", ,$(CONFIG_FFRT_HTS_VERSION)))
ifneq ($(HTS_VERSION),)
	ARCH_VERSION := $(HTS_VERSION)
endif
export ARCH_VERSION

obj-$(CONFIG_FFRT_HTS) += hkd/
obj-$(CONFIG_FFRT_HTS) += hpd/