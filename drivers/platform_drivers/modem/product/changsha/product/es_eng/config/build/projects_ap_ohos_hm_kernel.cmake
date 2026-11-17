set(ohos_vendor_modem_hm_kernel.dep
    diag_build_tool
    chr_build_tool
    tool_log_cfg
    sne
)

set(ohos_platform_vendor_modem_hm_kernel.dep
    diag_build_tool
    chr_build_tool
    tool_log_cfg
    sne
)

# set(ohos_system_hm_kernel.dep
#     ohos_vendor_ap_libs_hm_kernel
# )

# set(ohos_vendor_ap_hm_kernel.dep
#     ohos_vendor_ap_libs_hm_kernel
# )

set(ohos_vendor_modem_root.dep
    ohos_vendor_modem_hm_kernel
)

# set(ohos_system_hm_kernel_AP_sourece.dep
#     ohos_vendor_ap_libs_hm_kernel
# )

# set(ohos_vendor_ap_hm_kernel_AP_sourece.dep
#     ohos_vendor_ap_libs_hm_kernel
# )

set(ohos_ap_pkg_hm_kernel.build_frame COMMAND)
set(ohos_ap_pkg_hm_kernel.checkdir ${GBB_TOPDIR}/ap/build)
set(ohos_ap_pkg_hm_kernel.stage STAGE_PKG)
set(ohos_ap_pkg_hm_kernel.command_dir ${GBB_TOPDIR}/build)
set(ohos_ap_pkg_hm_kernel.command INTERMEDIATE_DELIVERY=${GBB_OUTPUT_DIR} HISI_INTERMEDIATE=${GBB_OUTPUT_DIR} ./HiBuild.sh product=${GBB_PRODUCT_NAME} chip_type=es ohos_pkg transfer=false verbose=true)

set(ohos_ap_pkg_hm_kernel_plat.build_frame COMMAND)
set(ohos_ap_pkg_hm_kernel_plat.checkdir ${GBB_TOPDIR}/ap/build)
set(ohos_ap_pkg_hm_kernel_plat.stage STAGE_PKG)
set(ohos_ap_pkg_hm_kernel_plat.command_dir ${GBB_TOPDIR}/build)
set(ohos_ap_pkg_hm_kernel_plat.command INTERMEDIATE_DELIVERY=${GBB_OUTPUT_DIR} HISI_INTERMEDIATE=${GBB_OUTPUT_DIR} ./HiBuild.sh product=${GBB_PRODUCT_NAME} chip_type=es ohos_pkg transfer=false verbose=true)

set(ohos_ap_pkg_hm_kernel_hitest.build_frame COMMAND)
set(ohos_ap_pkg_hm_kernel_hitest.checkdir ${GBB_TOPDIR}/ap/build)
set(ohos_ap_pkg_hm_kernel_hitest.stage STAGE_PKG)
set(ohos_ap_pkg_hm_kernel_hitest.command_dir ${GBB_TOPDIR}/build)
set(ohos_ap_pkg_hm_kernel_hitest.command INTERMEDIATE_DELIVERY=${GBB_OUTPUT_DIR} HISI_INTERMEDIATE=${GBB_OUTPUT_DIR} ./HiBuild.sh product=${GBB_PRODUCT_NAME} chip_type=es ohos_pkg transfer=false verbose=true)

set(ohos_modem_driver_hm_kernel_plat.build_frame COMMAND)
set(ohos_modem_driver_hm_kernel_plat.stage STAGE_COMPILE)
set(ohos_modem_driver_hm_kernel_plat.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_modem_driver_hm_kernel_plat.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_bootimage_hm_kernel no_clean=true)
set(ohos_modem_driver_hm_kernel_plat.alias modem_driver)
set(ohos_modem_driver_hm_kernel_plat.out ../image/modem_driver.img)
set(ohos_modem_driver_hm_kernel_plat.download_groups modem_driver ohos_vendor hmkernelkey hmkernel)


set(ohos_modem_driver_hm_kernel.build_frame COMMAND)
set(ohos_modem_driver_hm_kernel.stage STAGE_COMPILE)
set(ohos_modem_driver_hm_kernel.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_modem_driver_hm_kernel.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_bootimage_hm_kernel no_clean=true)
set(ohos_modem_driver_hm_kernel.alias modem_driver)
set(ohos_modem_driver_hm_kernel.out ../image/modem_driver.img)
set(ohos_modem_driver_hm_kernel.download_groups modem_driver ohos_vendor hmkernelkey hmkernel)

set(ohos_kernel_modem_hm_kernel.build_frame COMMAND)
set(ohos_kernel_modem_hm_kernel.stage STAGE_COMPILE)
set(ohos_kernel_modem_hm_kernel.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_kernel_modem_hm_kernel.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_kernel_modem_hm_kernel no_clean=true)
set(ohos_kernel_modem_hm_kernel.checkdir ${GBB_TOPDIR}/modem/kernel/platform_drivers)
set(ohos_kernel_modem_hm_kernel.alias kernel_modem)
set(ohos_kernel_modem_hm_kernel.out ../image/modem_driver.img)
set(ohos_kernel_modem_hm_kernel.download_groups modem_driver hmkernelkey hmkernel)

set(ohos_kernel_modem_hm_kernel_with_eng.build_frame COMMAND)
set(ohos_kernel_modem_hm_kernel_with_eng.stage STAGE_COMPILE)
set(ohos_kernel_modem_hm_kernel_with_eng.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_kernel_modem_hm_kernel_with_eng.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_kernel_modem_hm_kernel no_clean=true)
set(ohos_kernel_modem_hm_kernel_with_eng.checkdir ${GBB_TOPDIR}/modem/kernel/platform_drivers)
set(ohos_kernel_modem_hm_kernel_with_eng.alias kernel_modem_eng)
set(ohos_kernel_modem_hm_kernel_with_eng.out ../image/modem_driver.img)
set(ohos_kernel_modem_hm_kernel_with_eng.download_groups modem_driver hmkernelkey hmkernel)

set(ohos_kernel_modem_hm_kernel_plat.build_frame COMMAND)
set(ohos_kernel_modem_hm_kernel_plat.stage STAGE_COMPILE)
set(ohos_kernel_modem_hm_kernel_plat.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_kernel_modem_hm_kernel_plat.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_kernel_modem_hm_kernel no_clean=true)
set(ohos_kernel_modem_hm_kernel_plat.alias kernel_modem)
set(ohos_kernel_modem_hm_kernel_plat.out ../image/modem_driver.img)
set(ohos_kernel_modem_hm_kernel_plat.download_groups modem_driver hmkernelkey hmkernel)

set(ohos_factory_modem_driver_hm_kernel.build_frame COMMAND)
set(ohos_factory_modem_driver_hm_kernel.stage STAGE_COMPILE)
set(ohos_factory_modem_driver_hm_kernel.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_factory_modem_driver_hm_kernel.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_hm_kernel_factory_bootimage no_clean=true)
set(ohos_factory_modem_driver_hm_kernel.alias modem_driver)
set(ohos_factory_modem_driver_hm_kernel.out ../image/modem_driver.img)
set(ohos_factory_modem_driver_hm_kernel.download_groups modem_driver ohos_vendor hmkernelkey hmkernel)

set(ohos_system_hm_kernel.build_frame COMMAND)
set(ohos_system_hm_kernel.stage STAGE_COMPILE)
set(ohos_system_hm_kernel.command_dir ${GBB_TOPDIR}/build/version_build)
set(ohos_system_hm_kernel.command python3 -B version_compile.py buildgroup:higeneric_ohos_system_componet_balong version:higeneric no_clean:true)
set(ohos_system_hm_kernel.release_type AP)
set(ohos_system_hm_kernel.download_groups ohos_system audioalgapkey npu_ndk_key vppkey hivrarhisialgokey hivrarkey kirinkey)
set(ohos_system_hm_kernel.release_required_os ubuntu_ap_release)
set(ohos_system_hm_kernel.release_required_cpu_num 44)
set(ohos_system_hm_kernel.alias kirin_system)
set(ohos_system_hm_kernel.out ../image/system.img)

set(ohos_sys_prod.build_frame COMMAND)
set(ohos_sys_prod.stage STAGE_COMPILE)
set(ohos_sys_prod.command_dir ${GBB_TOPDIR}/build/version_build)
set(ohos_sys_prod.command python3 -B version_compile.py buildgroup:${GBB_PRODUCT_NAME}_ohos_sys_prod version:${GBB_PRODUCT_NAME} no_clean:true)
set(ohos_sys_prod.release_type AP)
set(ohos_sys_prod.download_groups ohos_sys_prod)
set(ohos_sys_prod.release_required_os ubuntu_ap_release)
set(ohos_sys_prod.release_required_cpu_num 44)
set(ohos_sys_prod.alias sys_prod)
set(ohos_sys_prod.out ../image/sys_prod.img)

set(ohos_vendor_ap_hm_kernel.build_frame COMMAND)
set(ohos_vendor_ap_hm_kernel.stage STAGE_COMPILE)
set(ohos_vendor_ap_hm_kernel.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_vendor_ap_hm_kernel.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_vendor_ap_hm_kernel no_clean=true)
set(ohos_vendor_ap_hm_kernel.release_type AP)
set(ohos_vendor_ap_hm_kernel.download_groups ohos_vendor release_vendor hmkernelkey)
set(ohos_vendor_ap_hm_kernel.release_required_os ubuntu_ap_release)
set(ohos_vendor_ap_hm_kernel.release_required_cpu_num 44)
set(ohos_vendor_ap_hm_kernel.alias vendor_ap)
set(ohos_vendor_ap_hm_kernel.out ../image/vendor.img)

set(ohos_vendor_modem_hm_kernel.build_frame COMMAND)
set(ohos_vendor_modem_hm_kernel.stage STAGE_COMPILE)
set(ohos_vendor_modem_hm_kernel.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_vendor_modem_hm_kernel.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_vendor_modem no_clean=true)
set(ohos_vendor_modem_hm_kernel.checkdir ${GBB_TOPDIR}/modem/ap/phone/build/ohos)
set(ohos_vendor_modem_hm_kernel.alias vendor_modem)
set(ohos_vendor_modem_hm_kernel.out ../image/modem_vendor.img)
set(ohos_vendor_modem_hm_kernel.depends_release_artifact "true")
set(ohos_vendor_modem_hm_kernel.release_libs_dir ${release_libs_dir})
set(ohos_vendor_modem_hm_kernel.download_groups vendor_modem ps_user_private ps_user_private_key)

set(ohos_platform_vendor_modem_hm_kernel.build_frame COMMAND)
set(ohos_platform_vendor_modem_hm_kernel.stage STAGE_COMPILE)
set(ohos_platform_vendor_modem_hm_kernel.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_platform_vendor_modem_hm_kernel.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_vendor_modem_platform no_clean=true)
set(ohos_platform_vendor_modem_hm_kernel.checkdir ${GBB_TOPDIR}/modem/ap/phone/build/ohos)
set(ohos_platform_vendor_modem_hm_kernel.alias vendor_modem)
set(ohos_platform_vendor_modem_hm_kernel.out ../image/modem_vendor.img)
set(ohos_platform_vendor_modem_hm_kernel.depends_release_artifact "true")
set(ohos_platform_vendor_modem_hm_kernel.release_libs_dir ${release_libs_dir})
set(ohos_platform_vendor_modem_hm_kernel.download_groups vendor_modem ps_user_private ps_user_private_key)

set(ohos_modem_ps_user_libs.dir ${GBB_MODEM_DIR}/product/${GBB_PRODUCT_NAME}/config/modem_ps_user_script/build)
set(ohos_modem_ps_user_libs.env_args -DINDEPENDENT_BUILD=true -DBUILD_GROUP=${GBB_PRODUCT_NAME}_es_ohos_modem_ps_user_libs -DNO_CLEAN=true -DCHIP_TYPE=es -DBOARD_TYPE=udp -DSOFTWARE_TYPE=eng)
set(ohos_modem_ps_user_libs.checkdir ${GBB_MODEM_DIR}/ps/ap/user/private)
set(ohos_modem_ps_user_libs.stage STAGE_COMPILE)
set(ohos_modem_ps_user_libs.warning_allowed true)
set(ohos_modem_ps_user_libs.release_libs_dir ${release_libs_dir})
set(ohos_modem_ps_user_libs.release_mode "libs")
set(ohos_modem_ps_user_libs.download_groups vendor_modem ps_user_private ps_user_private_key)
set(ohos_modem_ps_user_libs.required_disk_num 512000)
set(ohos_modem_ps_user_libs.out
    ps_user_ohos/libs_file_list.yaml
    ps_user_ohos/bin/himodemapr
    ps_user_ohos/lib64/libhmi_driver_core.z.so
    ps_user_ohos/lib64/libhmi_logcat.z.so
    ps_user_ohos/lib64/libhmi_chr.z.so
    ps_user_ohos/lib64/libhmi_analysis.z.so
    ps_user_ohos/lib64/libhmi_qoe.z.so
)

set(ohos_dpa_hm.build_frame COMMAND)
set(ohos_dpa_hm.stage STAGE_COMPILE)
set(ohos_dpa_hm.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_dpa_hm.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_dpa_hm no_clean=true)
set(ohos_dpa_hm.alias dpa)
set(ohos_dpa_hm.out ../image/dpa.img)
set(ohos_dpa_hm.depends_release_artifact "true")
set(ohos_dpa_hm.download_groups hmkernelkey hmkernel dpa_mirror dpa_hmdep)
set(ohos_dpa_hm.dep dpa_firmware dpa_dtb)
set(ohos_dpa_hm.required_cpu_num  32)
set(ohos_dpa_hm.required_os ubuntu_ap_modem)

set(ohos_dpa_hm_root.build_frame COMMAND)
set(ohos_dpa_hm_root.stage STAGE_COMPILE)
set(ohos_dpa_hm_root.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_dpa_hm_root.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_dpa_hm no_clean=true)
set(ohos_dpa_hm_root.alias dpa_eng)
set(ohos_dpa_hm_root.out ../image/dpa_eng.img)
set(ohos_dpa_hm_root.depends_release_artifact "true")
set(ohos_dpa_hm_root.download_groups hmkernelkey hmkernel dpa_mirror dpa_hmdep)
set(ohos_dpa_hm_root.dep dpa_firmware dpa_dtb)
set(ohos_dpa_hm_root.required_cpu_num  32)
set(ohos_dpa_hm_root.required_os ubuntu_ap_modem)

set(ohos_dpa_singleap_hm.build_frame COMMAND)
set(ohos_dpa_singleap_hm.stage STAGE_COMPILE)
set(ohos_dpa_singleap_hm.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_dpa_singleap_hm.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_dpa_singleap_hm no_clean=true)
set(ohos_dpa_singleap_hm.alias dpa_singleap)
set(ohos_dpa_singleap_hm.out ../image/dpa.img)
set(ohos_dpa_singleap_hm.depends_release_artifact "true")
set(ohos_dpa_singleap_hm.download_groups hmkernelkey hmkernel dpa_mirror dpa_hmdep)
set(ohos_dpa_singleap_hm.dep dpa_firmware dpa_dtb)
set(ohos_dpa_singleap_hm.required_cpu_num  32)
set(ohos_dpa_singleap_hm.required_os ubuntu_ap_modem)

set(ohos_dpa_balong_hm.build_frame COMMAND)
set(ohos_dpa_balong_hm.stage STAGE_COMPILE)
set(ohos_dpa_balong_hm.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_dpa_balong_hm.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_dpa_hm_balong no_clean=true)
set(ohos_dpa_balong_hm.alias dpa_balong)
set(ohos_dpa_balong_hm.out ../image/dpa.img)
set(ohos_dpa_balong_hm.depends_release_artifact "true")
set(ohos_dpa_balong_hm.download_groups ohos_vendor hmkernelkey hmkernel dpa_mirror dpa_hmdep)
set(ohos_dpa_balong_hm.dep dpa_firmware dpa_dtb)
set(ohos_dpa_balong_hm.required_cpu_num  32)
set(ohos_dpa_balong_hm.required_os ubuntu_ap_modem)

set(ohos_hm_bootimage.build_frame COMMAND)
set(ohos_hm_bootimage.stage STAGE_COMPILE)
set(ohos_hm_bootimage.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_hm_bootimage.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_bootimage_hm_kernel no_clean=true)
set(ohos_hm_bootimage.download_groups ohos_vendor kernel kernel5.10lts kernel_aux ucekey uce_aux fwdtb hmkernelkey hmkernel modem_driver)
set(ohos_hm_bootimage.required_os ubuntu_ap_modem)
set(ohos_hm_bootimage.required_cpu_num 88)
set(ohos_hm_bootimage.out ../image)

set(ohos_ap_pkg_hm_kernel.dep
    ohos_kernel_modem_hm_kernel
    ohos_vendor_ap_hm_kernel
    ohos_system_hm_kernel
    ohos_sys_prod
    ohos_vendor_modem_hm_kernel
    ohos_modem_ps_user_libs
    ohos_dpa_hm
    ${root_modem.dep}
)

set(ohos_ap_pkg_hm_kernel_hitest.dep
    ohos_kernel_modem_hm_kernel
    ohos_vendor_ap_hm_kernel
    ohos_system_hm_kernel
    ohos_sys_prod
    ohos_vendor_modem_hm_kernel
    ohos_modem_ps_user_libs
    ohos_dpa_hm
    ${root_no_slt.dep}
)

if("${GBB_SKIP_AP_PKG}" STREQUAL "True")
message("!!!!!!!!!!!GBB_SKIP_AP_PKG=${GBB_SKIP_AP_PKG}")
set(ohos_root_hm_kernel.dep
    ohos_kernel_modem_hm_kernel
    ohos_vendor_modem_hm_kernel
    ohos_vendor_ap_libs_hm_kernel
    ohos_dpa_hm
    ${root_modem.dep})
else()
set(ohos_root_hm_kernel.dep  ohos_ap_pkg_hm_kernel)
endif()

if("${GBB_SKIP_AP_PKG}" STREQUAL "True")
message("!!!!!!!!!!!GBB_SKIP_AP_PKG=${GBB_SKIP_AP_PKG}")
set(ohos_root_hitest_hm_kernel.dep
    ohos_kernel_modem_hm_kernel
    ohos_vendor_modem_hm_kernel
    ohos_vendor_ap_libs_hm_kernel
    ohos_dpa_hm
    ${root_no_slt.dep})
else()
set(ohos_root_hitest_hm_kernel.dep  ohos_ap_pkg_hm_kernel_hitest)
endif()

set(ohos_ap_pkg_hm_kernel_plat.dep
    ohos_kernel_modem_hm_kernel_plat
    ohos_vendor_ap_hm_kernel
    ohos_system_hm_kernel
    ohos_sys_prod
    ohos_platform_vendor_modem_hm_kernel
    ohos_dpa_hm
    ${plat_modem_llt.dep})
set(ohos_hm_kernel_plat_llt.dep ohos_ap_pkg_hm_kernel_plat)

#-------------------------factory config---------------------------------

set(ohos_factory_vendor_modem_root.dep
    ohos_factory_vendor_modem_hm_kernel
)

set(ohos_factory_vendor_modem_hm_kernel.dep
    diag_build_tool
    chr_build_tool
    tool_log_cfg
    sne)

set(ohos_factory_vendor_modem_hm_kernel.build_frame COMMAND)
set(ohos_factory_vendor_modem_hm_kernel.stage STAGE_COMPILE)
set(ohos_factory_vendor_modem_hm_kernel.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_factory_vendor_modem_hm_kernel.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_factory_vendor_modem no_clean=true)
set(ohos_factory_vendor_modem_hm_kernel.alias vendor_modem)
set(ohos_factory_vendor_modem_hm_kernel.out ../image/modem_vendor.img)
set(ohos_factory_vendor_modem_hm_kernel.depends_release_artifact "true")
set(ohos_factory_vendor_modem_hm_kernel.release_libs_dir ${release_libs_dir})
set(ohos_factory_vendor_modem_hm_kernel.download_groups vendor_modem ps_user_private ps_user_private_key)

set(ohos_factory_system_hm_kernel.build_frame COMMAND)
set(ohos_factory_system_hm_kernel.stage STAGE_COMPILE)
set(ohos_factory_system_hm_kernel.command_dir ${GBB_TOPDIR}/build/version_build)
set(ohos_factory_system_hm_kernel.command python3 -B version_compile.py buildgroup:higeneric_ohos_system_componet_factory version:higeneric no_clean:true)
set(ohos_factory_system_hm_kernel.release_type AP)
set(ohos_factory_system_hm_kernel.download_groups ohos_system)
set(ohos_factory_system_hm_kernel.release_required_os ubuntu_ap_release)
set(ohos_factory_system_hm_kernel.release_required_cpu_num 44)
set(ohos_factory_system_hm_kernel.alias kirin_system)
set(ohos_factory_system_hm_kernel.out ../image/system.img)

set(ohos_factory_vendor_ap_hm_kernel.build_frame COMMAND)
set(ohos_factory_vendor_ap_hm_kernel.stage STAGE_COMPILE)
set(ohos_factory_vendor_ap_hm_kernel.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_factory_vendor_ap_hm_kernel.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_factory_vendor_ap_hm_kernel no_clean=true)
set(ohos_factory_vendor_ap_hm_kernel.release_type AP)
set(ohos_factory_vendor_ap_hm_kernel.download_groups ohos_vendor release_vendor hmkernelkey)
set(ohos_factory_vendor_ap_hm_kernel.release_required_os ubuntu_ap_release)
set(ohos_factory_vendor_ap_hm_kernel.release_required_cpu_num 44)
set(ohos_factory_vendor_ap_hm_kernel.alias vendor_ap)
set(ohos_factory_vendor_ap_hm_kernel.out ../image/vendor.img)

set(ohos_factory_ap_pkg_hm_kernel.build_frame COMMAND)
set(ohos_factory_ap_pkg_hm_kernel.checkdir ${GBB_TOPDIR}/ap/build)
set(ohos_factory_ap_pkg_hm_kernel.stage STAGE_PKG)
set(ohos_factory_ap_pkg_hm_kernel.command_dir ${GBB_TOPDIR}/build)
set(ohos_factory_ap_pkg_hm_kernel.command INTERMEDIATE_DELIVERY=${GBB_OUTPUT_DIR} HISI_INTERMEDIATE=${GBB_OUTPUT_DIR} ./HiBuild.sh product=${GBB_PRODUCT_NAME} ohos_pkg transfer=false verbose=true)

set(ohos_factory_ap_pkg_hm_kernel.dep
    ohos_factory_modem_driver_hm_kernel
    ohos_factory_vendor_ap_hm_kernel
    ohos_factory_system_hm_kernel
    ohos_factory_vendor_modem_hm_kernel
    ohos_dpa_hm
    ${root_modem.dep})
set(ohos_factory_root_hm_kernel.dep ohos_factory_ap_pkg_hm_kernel)

#----------------------al_libs--------------------
set(ohos_vendor_ap_libs_hm_kernel.build_frame CALL_KIRIN)
set(ohos_vendor_ap_libs_hm_kernel.stage STAGE_COMPILE)
set(ohos_vendor_ap_libs_hm_kernel.alias vendor_ap_libs)
set(ohos_vendor_ap_libs_hm_kernel.download_groups ohos_vendor release_vendor hmkernelkey ohos_system)
set(ohos_vendor_ap_libs_hm_kernel.modem_img modem_fw.img nv_modem.bin modemconfig_cust.img modemconfig_cust_image/ modem_driver.img modem_vendor.img dpa.img)
set(ohos_vendor_ap_libs_hm_kernel.out ../image/vendor.img)

set(ohos_root_hm_kernel_ap_libs.dep
    ohos_modem_driver_hm_kernel
    ohos_vendor_ap_libs_hm_kernel
    ohos_vendor_modem
    ${root_modem.dep}
)
set(ohos_hm_kernel_plat_llt_ap_libs.dep
    ohos_modem_driver_hm_kernel_plat
    ohos_vendor_ap_libs_hm_kernel
    ohos_vendor_modem
    ${plat_modem_llt.dep}
)
set(ohos_factory_root_hm_kernel_ap_libs.dep
    ohos_vendor_ap_libs_hm_kernel
    ohos_modem_driver
    ohos_factory_vendor_modem
    ${root_modem.dep}
)

#----------------------al_source--------------------
set(ohos_system_hm_kernel_AP_sourece.build_frame COMMAND)
set(ohos_system_hm_kernel_AP_sourece.stage STAGE_COMPILE)
set(ohos_system_hm_kernel_AP_sourece.command_dir ${GBB_TOPDIR}/build/version_build)
set(ohos_system_hm_kernel_AP_sourece.command python3 -B version_compile.py buildgroup:higeneric_ohos_system_componet_balong version:higeneric no_clean:true)
set(ohos_system_hm_kernel_AP_sourece.release_type AP)
set(ohos_system_hm_kernel_AP_sourece.download_groups ohos_system audioalgapkey npu_ndk_key hivrarhisialgokey hivrarkey kirinkey)
set(ohos_system_hm_kernel_AP_sourece.release_required_os ubuntu_ap_release)
set(ohos_system_hm_kernel_AP_sourece.release_required_cpu_num 44)
set(ohos_system_hm_kernel_AP_sourece.alias kirin_system)
set(ohos_system_hm_kernel_AP_sourece.out ../image/system.img)

set(ohos_vendor_ap_hm_kernel_AP_sourece.build_frame COMMAND)
set(ohos_vendor_ap_hm_kernel_AP_sourece.stage STAGE_COMPILE)
set(ohos_vendor_ap_hm_kernel_AP_sourece.command_dir ${GBB_TOPDIR}/modem/build)
set(ohos_vendor_ap_hm_kernel_AP_sourece.command python3 -B build.py independent_build=true buildgroup=${GBB_PRODUCT_NAME}_es_ohos_chipset_hm_kernel_componet no_clean=true modem_ap_compile=true)
set(ohos_vendor_ap_hm_kernel_AP_sourece.release_type AP)
set(ohos_vendor_ap_hm_kernel_AP_sourece.download_groups release_vendor ohos_vendor audiokey audioalgkey btaudiokey smartalgkey audiooskey hisekey cannkey npu_ndk_key npuomkey aikey cie_key halidecvkey cvdspkey hihdrkey vcodeckey kirinkey camerakey audioalgapkey aischedkey displayacckey ispcvkey ispdispkey ffrtkey cv_basic_algo_key dfakey ispcvxkey cv_basic_algo_x_key gpukey higpuddkkey higpucsikey hicvkey hicvalgokey isphw_fwkey ispkey ispsw_fwkey isphw_algokey ispsw_algokey camera_algo_a_key svekey lpkey atfkey bootloaderkey ucekey hheekey contexthubkey iomcukey miniispkey divskey theekey lpgpukey lpcpukey lpmkey ddrxpukey hibenchkey cryptokey xloaderkey lsihubkey secbootkey uefikey tzspkey firewallkey microkernelkey safetyislandkey npu hmkernelkey kirin_ai_test ispnn_hlt)
set(ohos_vendor_ap_hm_kernel_AP_sourece.release_required_os ubuntu_ap_release)
set(ohos_vendor_ap_hm_kernel_AP_sourece.release_required_cpu_num 88)
set(ohos_vendor_ap_hm_kernel_AP_sourece.alias vendor_ap)
set(ohos_vendor_ap_hm_kernel_AP_sourece.out ../image/vendor.img)

set(ohos_ap_pkg_hm_kernel_AP_sourece.build_frame COMMAND)
set(ohos_ap_pkg_hm_kernel_AP_sourece.checkdir ${GBB_TOPDIR}/ap/build)
set(ohos_ap_pkg_hm_kernel_AP_sourece.stage STAGE_PKG)
set(ohos_ap_pkg_hm_kernel_AP_sourece.command_dir ${GBB_TOPDIR}/build)
set(ohos_ap_pkg_hm_kernel_AP_sourece.command INTERMEDIATE_DELIVERY=${GBB_OUTPUT_DIR} HISI_INTERMEDIATE=${GBB_OUTPUT_DIR} ./HiBuild.sh product=${GBB_PRODUCT_NAME} chip_type=es ohos_pkg transfer=false verbose=true)

set(ohos_ap_pkg_hm_kernel_AP_sourece.dep
    ohos_kernel_modem_hm_kernel
    ohos_vendor_ap_hm_kernel_AP_sourece
    ohos_system_hm_kernel_AP_sourece
    ohos_sys_prod
    ohos_vendor_modem_hm_kernel
    ohos_modem_ps_user_libs
    ohos_dpa_hm
    ${root_modem.dep}
)

set(ohos_root_hm_kernel_root_pkg.dep
    ohos_kernel_modem_hm_kernel_with_eng
    ohos_dpa_hm_root)

if("${GBB_SKIP_AP_PKG}" STREQUAL "True")
message("!!!!!!!!!!!GBB_SKIP_AP_PKG=${GBB_SKIP_AP_PKG}")
set(ohos_root_hm_kernel_AP_source.dep
    ohos_vendor_ap_libs_hm_kernel
    ohos_kernel_modem_hm_kernel
    ohos_sys_prod
    ohos_vendor_modem_hm_kernel
    ohos_modem_ps_user_libs
    ohos_dpa_hm
    ${root_modem.dep})
else()
set(ohos_root_hm_kernel_AP_source.dep  ohos_ap_pkg_hm_kernel_AP_sourece)
endif()
