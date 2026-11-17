set(files_install
    ${GBB_OUTPUT_LIB_DIR}/modem_fw.img
    ${GBB_OUTPUT_LIB_DIR}/changsha_udp_tsp_config.dtb
    ${GBB_OUTPUT_LIB_DIR}/nv_modem/nv_modem.img
)

message("GBB_TARGET_OS=$ENV{GBB_TARGET_OS}")
string(FIND "$$ENV{GBB_TARGET_OS}" "ohos" is_ohos)
message("is_ohos=${is_ohos}")
if("${is_ohos}" STREQUAL "-1")
set(files_install_execute
    ${GBB_MODEM_DIR}/drv/build/phone_update_bat/update_modem_common_sub.bat
    ${GBB_MODEM_DIR}/drv/build/phone_update_bat/changsha/update_sec_modem.bat
)
else()
set(files_install_execute
    ${GBB_MODEM_DIR}/drv/build/phone_update_bat/update_modem_common_sub_ohos.bat
    ${GBB_MODEM_DIR}/drv/build/phone_update_bat/changsha/update_sec_modem_ohos.bat
)
endif()
message("files_install_execute=${files_install_execute}")

install(
    FILES ${GBB_OUTPUT_LIB_DIR}/nv_modem/nv_modem.img
    DESTINATION image
    RENAME nv_modem.bin
)

install(
    FILES ${GBB_OUTPUT_LIB_DIR}/modemconfig_cust_image/modemconfig_cust.img
    DESTINATION image
)

execute_process(
    COMMAND make -C ${GBB_MODEM_DIR}/cmake/wrapper -f get_nv_cust_product_list.mk gbb_output_lib_dir=${GBB_OUTPUT_LIB_DIR} -s
    OUTPUT_VARIABLE cust_product_list
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
list(TRANSFORM cust_product_list REPLACE " " ";")
message("cust_product_list=${cust_product_list}")

foreach(cust_product_name ${cust_product_list})
    install(
        FILES ${GBB_OUTPUT_LIB_DIR}/modemconfig_cust_image/${cust_product_name}/modemconfig_cust.img
        DESTINATION image/${cust_product_name}
    )
endforeach()
