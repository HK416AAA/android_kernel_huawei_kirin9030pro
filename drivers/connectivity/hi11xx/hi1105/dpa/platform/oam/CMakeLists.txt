# 向编译目标添加源文件路径
set(conn_plat_oam_src
    ${CMAKE_CURRENT_SOURCE_DIR}/oam_log.c
    ${CMAKE_CURRENT_SOURCE_DIR}/oam_main.c
)

# 向编译目标添加头文件路径
target_include_directories(
    ${target_name}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_sources(${target_name} PRIVATE ${conn_plat_oam_src})