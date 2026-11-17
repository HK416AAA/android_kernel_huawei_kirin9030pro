set(ap_modem.dep
    modem_driver
    vendor_modem
    modem_ps_user_libs
)

set(ap_modem_dpa.dep
    modem_driver_dpa
    vendor_modem
)
set(modem_driver.dep
    modem_extra_utils
)
set(modem_driver_plat.dep
    modem_extra_utils
)
set(ap_modem_plat.dep
    modem_driver_plat
    vendor_modem
)

set(ap_relese.dep
    vendor_ap
    kirin_system
)

set(ap_relese_AP_source.dep
    vendor_ap_AP_source
    kirin_system
)

set(vendor_modem_root.dep
    vendor_modem
)

set(vendor_modem.dep
    diag_build_tool
    chr_build_tool
    tool_log_cfg
    sne
)
set(release_libs_dir ${GBB_MODEM_RELEASE_DIR})

set(modem_extra_utils.build_frame COMMAND)
set(modem_extra_utils.stage STAGE_COMPILE)
set(modem_extra_utils.command_dir ${GBB_TOPDIR}/modem/build)
set(modem_extra_utils.command python3 -B modem_build.py product=${GBB_PRODUCT_NAME} modemextrautils transfer=false MODEMVENDOR_SEPARATE=true subproduct=F2FS sec_img=true dirty_check=true TARGET_CHIPSET_WORKAROUND=true use_hash_log=false use_klto=false keylibs_depchk=false uefi_enable=true)
set(modem_extra_utils.checkdir ${GBB_TOPDIR}/ap/build)
set(modem_extra_utils.download_groups modem_extra_utils)
set(modem_extra_utils.out modem_extra_utils/bin/avbtool)

set(kernel_modem.build_frame COMMAND)
set(kernel_modem.stage STAGE_COMPILE)
set(kernel_modem.command_dir ${GBB_TOPDIR}/modem/build)
set(kernel_modem.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_kernel_modem_pack no_clean=true)
set(kernel_modem.checkdir ${GBB_TOPDIR}/modem/kernel/platform_drivers)
set(kernel_modem.download_groups modem_driver)
set(kernel_modem.out ../image/modem_driver.img)


set(modem_driver.build_frame COMMAND)
set(modem_driver.stage STAGE_COMPILE)
set(modem_driver.command_dir ${GBB_TOPDIR}/modem/build)
set(modem_driver.checkdir ${GBB_TOPDIR}/modem/kernel/platform_drivers)
set(modem_driver.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_user_kernel_modem_pack no_clean=true)
set(modem_driver.out ../image/modem_driver.img)

set(modem_driver_dpa.build_frame COMMAND)
set(modem_driver_dpa.stage STAGE_COMPILE)
set(modem_driver_dpa.command_dir ${GBB_TOPDIR}/modem/build)
set(modem_driver_dpa.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_modem_driver)
set(modem_driver_dpa.out ../image/modem_driver.img)
set(modem_driver_dpa.alias modem_driver)
set(modem_driver_dpa.download_groups modem_driver)
set(vendor_modem.build_frame COMMAND)
set(vendor_modem.stage STAGE_COMPILE)
set(vendor_modem.command_dir ${GBB_TOPDIR}/modem/build)
set(vendor_modem.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_user_vendor_modem no_clean=true)
set(vendor_modem.checkdir ${GBB_TOPDIR}/modem/ap/phone/build)
set(vendor_modem.depends_release_artifact "true")
set(vendor_modem.release_libs_dir ${release_libs_dir})
set(vendor_modem.download_groups vendor_modem ps_user_private ps_user_private_key)
set(vendor_modem.out ../image/modem_vendor.img)

set(modem_ps_user_libs.dir ${GBB_MODEM_DIR}/product/${GBB_PRODUCT_NAME}/config/modem_ps_user_script/build)
set(modem_ps_user_libs.env_args -DINDEPENDENT_BUILD=true -DBUILD_GROUP=${GBB_PRODUCT_NAME}_es_user_modem_ps_user_libs -DNO_CLEAN=true -DCHIP_TYPE=es -DBOARD_TYPE=udp -DSOFTWARE_TYPE=user)
set(modem_ps_user_libs.checkdir ${GBB_MODEM_DIR}/ps/ap/user/private)
set(modem_ps_user_libs.stage STAGE_COMPILE)
set(modem_ps_user_libs.warning_allowed true)
set(modem_ps_user_libs.release_libs_dir ${release_libs_dir})
set(modem_ps_user_libs.release_mode "libs")
set(modem_ps_user_libs.download_groups vendor_modem ps_user_private ps_user_private_key)
set(modem_ps_user_libs.required_disk_num 512000)
set(modem_ps_user_libs.out
    ps_user/bin/hmi_service
    ps_user/lib64/libhmi_driver.so
    ps_user/lib64/libhmi_logcat.so
    ps_user/lib64/libhmi_chr.so
    ps_user/lib64/librtt.so
)

set(modem_driver_plat.build_frame COMMAND)
set(modem_driver_plat.stage STAGE_COMPILE)
set(modem_driver_plat.command_dir ${GBB_TOPDIR}/modem/build)
set(modem_driver_plat.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_platform_kernel_modem_pack no_clean=true)
set(modem_driver_plat.out ../image/modem_driver.img)
set(modem_driver_plat.download_groups modem_driver)

set(linux_dpa_pack.build_frame COMMAND)
set(linux_dpa_pack.stage STAGE_COMPILE)
set(linux_dpa_pack.command_dir ${GBB_TOPDIR}/modem/build)
set(linux_dpa_pack.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_user_dpa_linux no_clean=true)
set(linux_dpa_pack.download_groups dpa_mirror modem_driver)
set(linux_dpa_pack.depends_release_artifact "true")
set(linux_dpa_pack.out ../image/dpa.img)

set(fastboot_xml.build_frame COMMAND)
set(fastboot_xml.stage STAGE_COMPILE)
set(fastboot_xml.command_dir ${GBB_TOPDIR}/modem/build)
set(fastboot_xml.command python3 -B build.py independent_build=true copy_fastboot_xml uefi_enable=true)
set(fastboot_xml.out ../image/update_sec_changsha_acpu.bat)

set(vendor_ap.build_frame COMMAND)
set(vendor_ap.stage STAGE_COMPILE)
set(vendor_ap.command_dir ${GBB_TOPDIR}/modem/build)
set(vendor_ap.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_vendor_user modem_ap_compile=true)
set(vendor_ap.checkdir ${GBB_ROOT_DIR}/vendor/hisi/lpm/common)
set(vendor_ap.libs_dir ${GBB_ROOT_DIR}/vendor/huaweiplatform/vendor_ap/${GBB_PRODUCT_NAME}_${GBB_CUST_NAME})
set(vendor_ap.release_type AP)
set(vendor_ap.download_groups release_vendor)
set(vendor_ap.release_required_os ubuntu_ap_release)
set(vendor_ap.release_required_cpu_num 44)
set(vendor_ap.out vendor.map)

set(kirin_system.build_frame COMMAND)
set(kirin_system.stage STAGE_COMPILE)
set(kirin_system.command_dir ${GBB_TOPDIR}/build/version_build)
set(kirin_system.command python -B version_compile.py buildgroup:kirin_system_arm64only_balong version:kirin)
set(kirin_system.checkdir ${GBB_ROOT_DIR}/device/common)
set(kirin_system.libs_dir ${GBB_ROOT_DIR}/vendor/huaweiplatform/kirin_system/eng)
set(kirin_system.release_type AP)
set(kirin_system.download_groups system)
set(kirin_system.release_required_os ubuntu_ap_release)
set(kirin_system.release_required_cpu_num 44)
set(kirin_system.out ../image/system.img)

set(ap_pkg.build_frame COMMAND)
set(ap_pkg.stage STAGE_PKG)
set(ap_pkg.checkdir ${GBB_TOPDIR}/build)
set(ap_pkg.command_dir ${GBB_TOPDIR}/build)
set(ap_pkg.command INTERMEDIATE_DELIVERY=${GBB_OUTPUT_DIR} HISI_INTERMEDIATE=${GBB_OUTPUT_DIR} ./HiBuild.sh product=${GBB_PRODUCT_NAME} choose_variant=user vb_superimage_repack transfer=false verbose=true use_buildinfo=false)

set(ap_plat_pkg.build_frame COMMAND)
set(ap_plat_pkg.stage STAGE_PKG)
set(ap_plat_pkg.checkdir ${GBB_TOPDIR}/build)
set(ap_plat_pkg.command_dir ${GBB_TOPDIR}/build)
set(ap_plat_pkg.command INTERMEDIATE_DELIVERY=${GBB_OUTPUT_DIR} HISI_INTERMEDIATE=${GBB_OUTPUT_DIR}  ./HiBuild.sh product=${GBB_PRODUCT_NAME} vb_superimage_repack transfer=false verbose=true use_buildinfo=false)

set(ap_pkg_dpa.build_frame COMMAND)
set(ap_pkg_dpa.stage STAGE_PKG)
set(ap_pkg_dpa.checkdir ${GBB_TOPDIR}/build)
set(ap_pkg_dpa.command_dir ${GBB_TOPDIR}/build)
set(ap_pkg_dpa.command INTERMEDIATE_DELIVERY=${GBB_OUTPUT_DIR} HISI_INTERMEDIATE=${GBB_OUTPUT_DIR} ./HiBuild.sh product=${GBB_PRODUCT_NAME} vb_superimage_repack transfer=false verbose=true use_buildinfo=false)
set(ap_pkg.dep ${ap_modem.dep} ${ap_relese.dep})
set(root_ap.dep ap_pkg)
set(linux_dpa_pack.dep dpa_firmware dpa_dtb)
set(root.dep ${root_modem.dep} ${root_ap.dep} linux_dpa_pack)
set(root_llt.dep ${root_modem_llt.dep} ${root_ap.dep} linux_dpa_pack)

set(ap_pkg_dpa.dep ${ap_modem_dpa.dep} ${ap_relese.dep})
set(root_boot_ap.dep ap_pkg_dpa)
set(root_boot.dep ${root_modem.dep} ${root_boot_ap.dep} linux_dpa_pack)
set(ap_plat_pkg.dep ${ap_modem_plat.dep} ${ap_relese.dep})
set(root_plat_ap.dep ap_plat_pkg)
set(plat_llt.dep ${plat_modem_llt.dep} ${root_plat_ap.dep} linux_dpa_pack)

# ------- ap_libs--------
set(vendor_ap_libs.build_frame CALL_KIRIN)
set(vendor_ap_libs.stage STAGE_COMPILE)
set(vendor_ap_libs.download_groups release_vendor system)
set(vendor_ap_libs.modem_img modem_fw.img nv_modem.bin modemconfig_cust.img modemconfig_cust_image/ modem_driver.img modem_vendor.img)
set(vendor_ap_libs.out ../image/super.img)

set(root_ap_libs.dep ${root_modem.dep} ${ap_modem.dep} vendor_ap_libs)
set(root_llt_ap_libs.dep ${root_modem_llt.dep} ${ap_modem.dep} vendor_ap_libs)
set(plat_llt_ap_libs.dep ${plat_modem_llt.dep} ${ap_modem.dep} vendor_ap_libs)

# ------- ap_source--------
set(vendor_ap_AP_source.build_frame COMMAND)
set(vendor_ap_AP_source.stage STAGE_COMPILE)
set(vendor_ap_AP_source.command_dir ${GBB_TOPDIR}/modem/build)
set(vendor_ap_AP_source.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_vendor_ap no_clean=true)
set(vendor_ap_AP_source.release_type AP)
set(vendor_ap_AP_source.download_groups release_vendor npu audiokey audioalgkey btaudiokey smartalgkey audiooskey hisekey cannkey npuomkey aikey cie_key halidecvkey gpukey color_algos_key cvdspkey uni_iomcukey kirinkey hihdrkey vcodeckey camerakey audioalgapkey aischedkey displayacckey ispcvkey ispdispkey ffrtkey cv_basic_algo_key dfakey ispcvxkey cv_basic_algo_x_key higpubinkey higpuddkkey higpucsikey hicvkey hicvalgokey isphw_fwkey ispkey ispsw_fwkey isphw_algokey ispsw_algokey camera_algo_a_key svekey lpkey atfkey bootloaderkey ucekey hheekey hiepskey contexthubkey iomcukey miniispkey divskey theekey lpgpukey lpcpukey lpmkey ddrpvskey ddrxpukey secbootkey hibenchkey cryptokey xloaderkey lsihubkey safetyislandkey uefikey tzspkey firewallkey kirin_ai_test uefi_test)
set(vendor_ap_AP_source.release_required_os ubuntu_ap_release)
set(vendor_ap_AP_source.release_required_cpu_num 88)
set(vendor_ap_AP_source.alias vendor_ap)
set(vendor_ap_AP_source.out ../image/vendor.img)

set(root_AP_source.dep ap_pkg_AP_source)
set(ap_pkg_AP_source.dep
    vendor_modem
    modem_ps_user_libs
    linux_dpa_pack
    ${ap_relese_AP_source.dep}
    ${ap_modem.dep}
    ${root_modem.dep}
)
set(ap_pkg_AP_source.build_frame COMMAND)
set(ap_pkg_AP_source.stage STAGE_PKG)
set(ap_pkg_AP_source.checkdir ${GBB_TOPDIR}/build)
set(ap_pkg_AP_source.command_dir ${GBB_TOPDIR}/build)
set(ap_pkg_AP_source.command INTERMEDIATE_DELIVERY=${GBB_OUTPUT_DIR} HISI_INTERMEDIATE=${GBB_OUTPUT_DIR} ./HiBuild.sh product=${GBB_PRODUCT_NAME} vb_superimage_repack transfer=false verbose=true use_buildinfo=false choose_variant=user)
