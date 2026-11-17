set(CONN_DRIVER_DIR ${DPA_FW_LOCAL_DIR}/service/connectivity/drivers)

set(target_name mp1x_wifi)
add_library(${target_name})
target_include_directories(
    ${target_name}
    PRIVATE
    ${dpa_fw_inc}
)

add_subdirectory(${CONN_DRIVER_DIR}/dpa/platform)
add_subdirectory(${CONN_DRIVER_DIR}/wifi)

get_target_property(SOURCES_LIST mp1x_wifi SOURCES)
get_target_property(INCLUDE mp1x_wifi INCLUDE_DIRECTORIES)
get_target_property(DEFINITIONS mp1x_wifi COMPILE_DEFINITIONS)

add_compile_definitions(${DEFINITIONS})

list(APPEND dpa_fw_ddr_inc
    ${INCLUDE}
)

list(APPEND dpa_fw_ddr_src
    "${SOURCES_LIST}"
)