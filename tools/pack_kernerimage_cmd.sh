#!/bin/bash
./mkbootimg --cmdline "loglevel=4 page_tracker=on printktimer=0xfdb23000,0x534,0x538 fw_devlink=permissive rcupdate.rcu_expedited=1 loop.max_part=7 androidboot.selinux=enforcing buildvariant=user" --tags_offset 0x65400000 --kernel_offset 0x00080000 --ramdisk_offset 0x66800000 --header_version 2 --base 0x0 --os_version 12 --os_patch_level 2021-10-05  --output kernel.img
