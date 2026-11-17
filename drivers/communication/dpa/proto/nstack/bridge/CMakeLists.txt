#########################################################################
#Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
#########################################################################
cmake_minimum_required (VERSION 3.14.1)

set(MODULE_FILE ${BRIDGE_KO_NAME}.ko)

if(NOT (DEFINED ENV{KERNELDIR}))
    execute_process(COMMAND uname -r
        OUTPUT_VARIABLE KERNEL_VERSION
        OUTPUT_STRIP_TRAILING_WHITESPACE)
    set(ENV{KERNELDIR} "/lib/modules/${KERNEL_VERSION}/build")
endif()

set (TOP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)

add_compile_definitions (RTP_FORCE_INTRINSICS=1)
add_compile_definitions (USE_48BIT_ADDR)
add_compile_definitions (SPL_IPV6=1)
add_compile_definitions (SPL_LINGER=1)
add_compile_definitions (SPL_REUSEPORT=1)
add_compile_definitions (SPL_TCP_DEFER_ACCEPT=0)

add_compile_definitions (SPL_STATS=1)
add_compile_definitions (SPL_NETIF_STATS=1)
add_compile_definitions (SPL_NETIFIP_STATS=0)
add_compile_definitions (SPL_TCP_STATS=1)
add_compile_definitions (SPL_IP6_STATS=1)
add_compile_definitions (SPL_ND6_STATS=1)
add_compile_definitions (SPL_MLD6_STATS=1)

add_compile_definitions (LINUX_NSTACK)
add_compile_definitions (BUILD_BRIDGE)

#add_compile_definitions (_GNU_SOURCE)
set (COMPLE_CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/../framework/compile_config.h)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -include ${COMPLE_CONFIG}")

include_directories (
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/../framework
    ${CMAKE_CURRENT_SOURCE_DIR}/../framework/data_struct
    ${CMAKE_CURRENT_SOURCE_DIR}/../framework/log
    ${CMAKE_CURRENT_SOURCE_DIR}/../framework/protocols
    ${CMAKE_CURRENT_SOURCE_DIR}/socket
    ${CMAKE_CURRENT_SOURCE_DIR}/sys
    ${CMAKE_CURRENT_SOURCE_DIR}/sys/acpu
    ${CMAKE_CURRENT_SOURCE_DIR}/../../platform/HuaweiSecureC/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/dfx
    ${KERNELHEADERS_INCLUDE_DIRS}
)

file (GLOB COOPERATION ${CMAKE_CURRENT_SOURCE_DIR}/cooperation/*.c)
file (GLOB BRIDGE_SYS ${CMAKE_CURRENT_SOURCE_DIR}/sys/*.c)
file (GLOB BRIDGE_SYS_RUNTIME ${CMAKE_CURRENT_SOURCE_DIR}/sys/acpu/*.c)
file (GLOB BRIDGE_MSG ${CMAKE_CURRENT_SOURCE_DIR}/msg/*.c)
file (GLOB_RECURSE SOCKET ${CMAKE_CURRENT_SOURCE_DIR}/socket/*.c)
file (GLOB BRIDGE_INIT ${CMAKE_CURRENT_SOURCE_DIR}/init/*.c)
file (GLOB_RECURSE FRAMEWORK ${CMAKE_CURRENT_SOURCE_DIR}/../framework/*.c)
file (GLOB DFX ${CMAKE_CURRENT_SOURCE_DIR}/dfx/*.c)

set(src_file_list ${FRAMEWORK} ${SOCKET} ${COOPERATION} ${BRIDGE_SYS} ${BRIDGE_SYS_RUNTIME} ${BRIDGE_MSG} ${BRIDGE_INIT} ${DFX})

#generate Kbuild and build ko
execute_process(COMMAND uname -r OUTPUT_VARIABLE KERNEL_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)
set(KERNEL_VERSION "5.10.84")
set(KBUILD_FILE "obj-m := ${BRIDGE_KO_NAME}.o")
if (COVERAGE_BUILD)
    set(KBUILD_FILE "${KBUILD_FILE}\nCC:=hitestwrapper $(CC)")
    set(KBUILD_FILE "${KBUILD_FILE}\nLD:=hitestwrapper $(LD)")
endif()

foreach(file ${src_file_list})
    file(RELATIVE_PATH file "${CMAKE_CURRENT_SOURCE_DIR}" "${file}")
    get_filename_component(file_dir "${file}" DIRECTORY)
    get_filename_component(file_name_we "${file}" NAME_WE)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${file_dir})
    set(KBUILD_FILE "${KBUILD_FILE}\n${BRIDGE_KO_NAME}-y += ${file_dir}/${file_name_we}.o")
    list(APPEND source_relative "${file_dir}/${file_name_we}.c")
endforeach()

set(KBUILD_FILE "${KBUILD_FILE}\nccflags-y := -DMODULE_NAME=\\\"${BRIDGE_KO_NAME}\\\"")
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message(">>> include_dirs=${dirs}")
foreach(dir ${dirs})
    set(KBUILD_FILE "${KBUILD_FILE}\nccflags-y += -I${dir}")
endforeach()
get_directory_property(compile_macros DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} COMPILE_DEFINITIONS)
message(">>> macros=${compile_macros}")
foreach(self_macro ${compile_macros})
    set(KBUILD_FILE "${KBUILD_FILE}\nccflags-y += -D${self_macro}")
endforeach()
set(KBUILD_FILE "${KBUILD_FILE}\nccflags-y += ${CMAKE_C_FLAGS}")
set(KBUILD_FILE "${KBUILD_FILE}\nKBUILD_EXTRA_SYMBOLS += ${CMAKE_CURRENT_SOURCE_DIR}/../stack/Module.symvers")

#string(REGEX REPLACE "\n$" "" ${source_relative} "${source_relative}")
message(WARNING ${source_relative})

file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Kbuild ${KBUILD_FILE})

if (CMAKE_TOOLCHAIN_FILE)
    set (CROSS_COMPILE_OPTION CROSS_COMPILE=${COMPILEER_PATH_PREFIX})
endif()
if (ARCH_32)
    set (ARCH_TYPE ARCH=arm)
endif()

set(KBUILD_CMD $(MAKE) ${ARCH_TYPE} ${CROSS_COMPILE_OPTION} -C $ENV{KERNELDIR} M=${CMAKE_CURRENT_SOURCE_DIR} src=${CMAKE_CURRENT_SOURCE_DIR} modules)
add_custom_command(OUTPUT ${MODULE_FILE}
    COMMAND ${KBUILD_CMD}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${source_relative} VERBATIM)

add_custom_target(${BRIDGE_KO_NAME} ALL DEPENDS ${MODULE_FILE})
add_dependencies(${BRIDGE_KO_NAME} ${STACK_KO_NAME})

