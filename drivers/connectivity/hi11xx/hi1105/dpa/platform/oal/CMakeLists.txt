# 向编译目标添加源文件路径
set(conn_plat_oal_src
    ${CMAKE_CURRENT_SOURCE_DIR}/oal_dft.c
    ${CMAKE_CURRENT_SOURCE_DIR}/oal_util.c
)

# 向编译目标添加头文件路径
target_include_directories(
    ${target_name}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_sources(${target_name} PRIVATE ${conn_plat_oal_src})