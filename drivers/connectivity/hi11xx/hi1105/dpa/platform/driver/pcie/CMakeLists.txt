# 向编译目标添加源文件路径
set(conn_plat_pcie_src
    ${CMAKE_CURRENT_SOURCE_DIR}/pcie_host.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/pcie_chip.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/mp17c/pcie_chip_mp17c.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/mp17c/pcie_iatu_mp17c.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ete_comm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ete_dpa.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ete_host.c
)

# 向编译目标添加头文件路径
target_include_directories(
    ${target_name}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/chip
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/mp17c
)

target_sources(${target_name} PRIVATE ${conn_plat_pcie_src})