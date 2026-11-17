cmake_minimum_required(VERSION 3.15)

include(${GBB_MODEM_DIR}/cmake/frame/env.cmake)
include(${GBB_CUST_BUILD_DIR}/env.cmake)
# include(${GBB_CUST_BUILD_DIR}/cmd.cmake)

project(modem_ps_user_libs)

list(APPEND env_params independent_build=${INDEPENDENT_BUILD})
list(APPEND env_params buildgroup=${BUILD_GROUP})
list(APPEND env_params no_clean=${NO_CLEAN})
list(APPEND env_params chip=${GBB_PRODUCT_NAME})
list(APPEND env_params chip_type=${CHIP_TYPE})
list(APPEND env_params board_type=${BOARD_TYPE})
list(APPEND env_params software_type=${SOFTWARE_TYPE})

add_custom_target(
    modem_ps_user_libs ALL
    COMMAND python3 -B ${GBB_MODEM_DIR}/build/build.py ${env_params}
)

message("GBB_TARGET_OS=$ENV{GBB_TARGET_OS}")
string(FIND "$$ENV{GBB_TARGET_OS}" "ohos" is_ohos)
message("is_ohos=${is_ohos}")

if("${is_ohos}" STREQUAL "-1")
include(install.cmake)
else()
include(install_ohos.cmake)
endif()
