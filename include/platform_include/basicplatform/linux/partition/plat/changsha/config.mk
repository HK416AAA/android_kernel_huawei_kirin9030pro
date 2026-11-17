set(EMULATORE_FLAG "true")

add_definitions(-DEMU_EMMC_USERDATA_BLKS=0xF00000)

if("${product_type}" STREQUAL "armpc")
add_definitions(-DEMU_UFS_USERDATA_BLKS=0xF00000)
else()
add_definitions(-DEMU_UFS_USERDATA_BLKS=0x780000)
endif()
