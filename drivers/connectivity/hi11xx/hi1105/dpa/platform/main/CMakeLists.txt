# 向编译目标添加源文件路径
set(conn_plat_main_src
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)

target_sources(${target_name} PRIVATE ${conn_plat_main_src})