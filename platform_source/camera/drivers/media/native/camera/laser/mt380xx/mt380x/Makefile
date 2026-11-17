ifneq ($(KERNELRELEASE),)
include Kbuild

else
KDIR ?= /lib/modules/`uname -r`/build

default:
	CONFIG_MT380X=m $(MAKE) -C $(KDIR) M=$$PWD
clean:
	CONFIG_MT380X=m $(MAKE) -C $(KDIR) M=$$PWD clean

endif