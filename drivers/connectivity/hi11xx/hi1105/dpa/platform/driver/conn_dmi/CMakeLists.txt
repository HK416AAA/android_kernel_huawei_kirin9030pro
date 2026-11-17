# 向编译目标添加源文件路径
set(conn_plat_conn_dmi_src
    ${CMAKE_CURRENT_SOURCE_DIR}/conn_dmi_drv.c
    ${CMAKE_CURRENT_SOURCE_DIR}/conn_dmi_hal.c
    ${CMAKE_CURRENT_SOURCE_DIR}/conn_dmi_hcc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/conn_dmi_msg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/conn_dmi_oam.c
    ${CMAKE_CURRENT_SOURCE_DIR}/conn_dmi_flowctrl.c
)

# 向编译目标添加头文件路径
target_include_directories(
    ${target_name}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(${target_name} PRIVATE ${conn_plat_conn_dmi_src})