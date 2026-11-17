set(HITSP_PHY_KEY_TARGET
)

set(HITSP_PHY_OPEN_TARGET)

set(HITSP_PS_KEY_TARGET)

set(HITSP_PLATFORM_TARGET
    vpp_libs/${CFG_CONFIG_CCPU_ARCH}/libhitls_crypto.a
    vpp_libs/${CFG_CONFIG_CCPU_ARCH}/libhitls_bsl.a
)

set(HITSP_PS_OPEN_TARGET)
# set(CFG_TSP_CCORE_COMPONENTS)
set(CFG_TSP_CCORE_OS_DRV ccpu_os_drv.o)
set(CFG_TSP_CCORE_PHY rtt_test.o)
set(CFG_TSP_CCORE_DRV
    ccpu_hal.o
    ccpu_main.o
    ccpu_main_minidle.o
    ccpu_hal_minidle.o
    ccpu_eng.o
    ccpu_drv_om.o
)
