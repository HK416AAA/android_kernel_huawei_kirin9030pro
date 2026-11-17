set(GBB_PACKHEAD_TOOL ${GBB_MODEM_DIR}/cmake/wrapper/packhead/packhead_phone.sh)

set(CFG_CONFIG_CCPU_ARCH $ENV{TSP_CCPU_ARCH})
set(CFG_RTOSCK_INCLUDE_PATH ${GBB_MODEM_DIR}/include/rtosck_smp)
set(CFG_RTOSCK_TSP_INCLUDE_PATH ${GBB_MODEM_DIR}/include/rtosck_smp/fusion/hitspv300)
set(CFG_RTOSCK_TSP_MTEE_INCLUDE_PATH ${GBB_MODEM_DIR}/include/rtosck_smp/security/fusion/hitspv300)
set(CFG_TSP_COMPILER_PREFIX ${GBB_TOOLS_PLATFORM_DIR}/tsp_compiler/tsp_release/llvm-binary/llvm-binary-Release/bin/)
set(TSP_LIB_PATH ${GBB_OUTPUT_DIR}/lib/rtosck_os/tspv300)
set(TSP_CONFIG_PATH ${GBB_MODEM_DIR}/system/rtosck_smp/tspv300)
set(GBB_OBSCURE_SYM_TOOL python3 -B ${GBB_MODEM_DIR}/build/scripts/mo/obscure_symbol.py ENG)
set(GBB_MO_SYMBOL_CHECK_TOOL python3 -B ${GBB_MODEM_DIR}/build/scripts/mo/modem_mo_symbol_check.py ENG)

set(GBB_PRODUCT_TYPE phone)
set(GBB_CHIP_TYPE es)

# GBB_SIGN_ENABLE value: {true, false}
set(GBB_SIGN_ENABLE false)

set(CFG_MODEM_ARCH CONVERGED)

set(GBB_SIGN_TOOL
    python3 -B ${GBB_MODEM_DIR}/cmake/wrapper/sign/phone_v002/sign.py
    SIGN_PRODUCT_NAME=${GBB_PRODUCT_NAME}
    SIGN_TOPDIR=${GBB_TOPDIR}
    SIGN_WORK_DIR=${GBB_BUILD_DIR}
    SIGN_PRODUCT_TYPE=${GBB_PRODUCT_TYPE}
    SIGN_PRODUCT_RANGE=
    SIGN_TARGET_BUILD_VARIANT=eng
    SIGN_CHIP_TYPE=${GBB_CHIP_TYPE}
)
