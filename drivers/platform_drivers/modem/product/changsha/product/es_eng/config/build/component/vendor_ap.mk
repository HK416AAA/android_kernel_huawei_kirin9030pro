$(if $(output_dir),,$(error output_dir must set))
.PHONY: vendor_ap_post

# del unuse product
vendor_ap_post:
	rm -rfv $(output_dir)/image/modem_driver.img
	rm -rfv $(output_dir)/image/modem_driver.map.bin
	rm -rfv $(output_dir)/image/android_system
	rm -rfv $(output_dir)/image/data_hibench_slt
	rm -rfv $(output_dir)/image/boot_ramdisk_gsi.img
