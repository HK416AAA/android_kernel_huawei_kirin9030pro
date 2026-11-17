ifneq ($(KERNELRELEASE),)
include Kbuild

else
KDIR ?= /lib/modules/`uname -r`/build

default:
	CONFIG_TOF8801=m $(MAKE) -C $(KDIR) M=$$PWD
clean:
	CONFIG_TOF8801=m $(MAKE) -C $(KDIR) M=$$PWD clean

endif
