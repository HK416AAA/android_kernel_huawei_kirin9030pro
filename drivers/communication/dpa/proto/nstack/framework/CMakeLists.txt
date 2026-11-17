#########################################################################
#Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
#########################################################################

add_subdirectory (log)
if (NOT BUILD_CP)
    add_subdirectory (json)
endif()

file (GLOB_RECURSE COMMON common/*.c)
file (GLOB INIT init/*.c)
file (GLOB_RECURSE IPC ipc/*.c)
file (GLOB LOG log/*.c log/custom/stack_log_base2.c)
file (GLOB SNAPSHOT snapshot/*.c)
file (GLOB MAINTAIN dfx/*.c)
file (GLOB EVENT event/epoll/*.c)
file (GLOB HAL hal/*.c)
file (GLOB RD  rd/*.c)
file (GLOB RES res/*.c)
file (GLOB_RECURSE MEM mem/*.c)
file (GLOB RING ring/*.c)
file (GLOB DFX dfx/*.c)
include_directories (
    nStackFw
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/nSocket/nstack
    ${CMAKE_SOURCE_DIR}/src/nSocket/include
    ${CMAKE_SOURCE_DIR}/src/framework/log
    ${CMAKE_CURRENT_LIST_DIR}/ipc/mgr_com
    ${CMAKE_CURRENT_LIST_DIR}/include/common/
    ${CMAKE_CURRENT_LIST_DIR}/include/common/generic
    ${CMAKE_CURRENT_LIST_DIR}/common/base/liblinuxapi
	${CMAKE_CURRENT_LIST_DIR}/dfx
	${CMAKE_SOURCE_DIR}/src/framework/event/epoll
)
add_library (nStackFw STATIC ${COMMON} ${INIT} ${IPC} ${LOG} ${SNAPSHOT} ${MAINTAIN} ${TRACEING} ${EVENT} ${RES} ${RD} ${HAL} ${MEM} ${RING} ${DFX})
if (NOT 5G_CORE)
target_link_libraries (
    nStackFw
    cap
)
endif ()
if (NOT BUILD_CP)
    add_dependencies (nStackFw nstack_json GLOG)
else()
    add_dependencies (nStackFw GLOG)
endif()

####################################################################
#make for mptcp
####################################################################
include_directories (
    nStackFw_mp
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/include
    ${CMAKE_SOURCE_DIR}/src/nSocket/nstack
    ${CMAKE_SOURCE_DIR}/src/nSocket/include
    ${CMAKE_CURRENT_LIST_DIR}/ipc/mgr_com
    ${CMAKE_CURRENT_LIST_DIR}/include/common/
    ${CMAKE_CURRENT_LIST_DIR}/include/common/generic
    ${CMAKE_CURRENT_LIST_DIR}/common/base/liblinuxapi
	${CMAKE_CURRENT_LIST_DIR}/dfx
    ${CMAKE_CURRENT_LIST_DIR}/mem/basic_mem
)
add_library (nStackFw_mp STATIC ${COMMON} ${INIT} ${IPC} ${LOG} ${SNAPSHOT} ${STARTUP} ${MAINTAIN} ${TRACEING} ${EVENT} ${RES} ${RD} ${HAL} ${MEM} ${RING})
if (NOT BUILD_CP)
    add_dependencies (nStackFw_mp nstack_json GLOG)
else()
    add_dependencies (nStackFw_mp GLOG)
endif()
set_target_properties (nStackFw_mp PROPERTIES COMPILE_FLAGS)
