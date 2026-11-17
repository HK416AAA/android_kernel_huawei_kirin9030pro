# 向编译目标添加源文件路径
set(conn_plat_hcc_src
    ${CMAKE_CURRENT_SOURCE_DIR}/hcc_base.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hcc_master.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hcc_slave.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hcc_test.c
)

# 向编译目标添加头文件路径
target_include_directories(
    ${target_name}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_sources(${target_name} PRIVATE ${conn_plat_hcc_src})