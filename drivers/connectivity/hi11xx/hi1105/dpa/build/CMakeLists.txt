cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0115 NEW)

#编译环境
set(DPA_TOOLS_PLATFORM_DIR ${COMPILER_DIR})
set(DPA_MO_DICT_NAME ${target_name})
set(DPA_MO_CHECK_SIZE_TOOL ${DPA_INTERFACE_DIR}/firmware/build/scripts/mo_check_size.py)

include(${DPA_INTERFACE_DIR}/firmware/build/frame/toolchain_option.cmake)
include(${DPA_INTERFACE_DIR}/firmware/build/frame/env.cmake)
project(mp1x_wifi)

#生成目标文件
add_executable(${target_name})

if(${choose_variant} STREQUAL "eng")
    set(CFLAG ${CFLAG} -DENG_VARIANT)
endif()

#增加除法指令优化
list(APPEND CFLAG "SHELL:-mllvm -hi-i64-division=true")

# 向编译目标添加dpa头文件路径
target_include_directories(
    ${target_name}
    PRIVATE
    ${LIBC_SEC_DIR}/include
    ${DPA_INTERFACE_DIR}/firmware/include
    ${DPA_INTERFACE_DIR}/firmware/include/rtosck_smp
    ${DPA_INTERFACE_DIR}/firmware/include/rtosck_smp/fusion
    ${DPA_INTERFACE_DIR}/firmware/include/rtosck_smp/fusion/hitspv300_lite_v200
    ${DPA_INTERFACE_DIR}/firmware/include/rtosck_smp/posix
    ${DPA_INTERFACE_DIR}/firmware/include/posix
)

#添加mo源文件目录
add_subdirectory(${CONN_DRIVER_DIR}/dpa/platform platform)
add_subdirectory(${CONN_DRIVER_DIR}/wifi wifi)

if("${CONFIG_COMPILER_OPT}" STREQUAL "y")
    # 采用如下函数配置编译优化参数，该函数会自动添加编译、链接以及目标指令
    # 如代码中已经target_xxx命令配置SOURCE INCLUDE DEFINE，则不需要再配置
    # LTO;FDO;AUTO_DEPLOY_TCM; 可配置为"y"或者"n"
    # LD_SCRIPT需要配置为编译优化使用的链接脚本（因无法知道MO组件开发者Cmakelist所在具体目录位置，所以需要此处配置）
    # CONFIG_DIR需要配置为包含上述编译优化所需的文件的目录。可参考demo_compiler_opt. 注意目录中的文件名保持不变
    # TOOLS_DIR需要配置为scirpts目录（因无法知道MO组件开发者Cmakelist所在具体目录位置，所以需要此处配置）
    # TARGET;SOURCE;INCLUDE;DEFINE;CC_OPTION;LINK_OPTION;LD_SCRIPT;LTO;FDO;AUTO_DEPLOY_TCM;CONFIG_DIR;TOOLS_DIR

    #避免过度无效内联
    list(APPEND CFLAG "SHELL:-mllvm -inline-threshold=0")
    #检查过大栈函数
    list(APPEND CFLAG -Wframe-larger-than=1000 )

    mo_add_compiler_opt_target(TARGET ${target_name}
        SOURCE ""
        INCLUDE ""
        DEFINE ""
        CC_OPTION ${LOCAL_CC_FLAGS} ${CFLAG}
        LINK_OPTION ${LOCAL_LD_FLAGS}
        LD_SCRIPT ${DPA_INTERFACE_DIR}/firmware/build/ld/compiler_opt_ld_script_file_mo.ld
        LTO "y"
        FDO "y"
        AUTO_DEPLOY_TCM "y"
        CONFIG_DIR  ${CONN_DRIVER_DIR}/dpa/build/config
        TOOLS_DIR ${DPA_INTERFACE_DIR}/firmware/build/scripts/
    )
else()
    target_compile_options(${target_name} PRIVATE ${LOCAL_CC_FLAGS} ${CFLAG})
    target_link_options(${target_name} PRIVATE ${LOCAL_LD_FLAGS} "-r" -T ${DPA_INTERFACE_DIR}/firmware/build/ld/default_ld_script_file_mo.ld)
    set_target_properties(${target_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endif()

add_custom_command(TARGET ${target_name} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} ${DPA_MO_DEFAULT_FLAG} ${CMAKE_CURRENT_BINARY_DIR}/${target_name} ${CMAKE_CURRENT_BINARY_DIR}/mp1x_wifi.mo
    COMMAND ${DPA_MO_CHECK_SIZE_TOOL} ${CMAKE_READELF} ${CMAKE_CURRENT_BINARY_DIR}/mp1x_wifi.mo "all" ${DPA_MO_MAX_SIZE}
    COMMAND ${DPA_MO_CHECK_SIZE_TOOL} ${CMAKE_READELF} ${CMAKE_CURRENT_BINARY_DIR}/mp1x_wifi.mo "itcm" ${DPA_MO_L1ITCM_MAX_SIZE}
    COMMAND ${DPA_MO_CHECK_SIZE_TOOL} ${CMAKE_READELF} ${CMAKE_CURRENT_BINARY_DIR}/mp1x_wifi.mo "dtcm" ${DPA_MO_L1DTCM_MAX_SIZE}
    COMMENT "post_build:gen mp1x_wifi.mo"
)

add_custom_command(TARGET ${target_name} POST_BUILD
    COMMAND ${CMAKE_OBJDUMP} -t ${CMAKE_CURRENT_BINARY_DIR}/${target_name} > ${CMAKE_CURRENT_BINARY_DIR}/symbols.txt
    COMMAND grep '*UND*' symbols.txt | sed 's/.* //' |sort > functions.txt
    COMMAND cat ${CONN_DRIVER_DIR}/dpa/build/functions |sort > ${CMAKE_CURRENT_BINARY_DIR}/functions_temp.txt
    COMMAND diff functions.txt functions_temp.txt
    COMMENT "post_build:compare functions.txt"
)
