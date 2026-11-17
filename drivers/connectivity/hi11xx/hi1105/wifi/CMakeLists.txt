set(CONN_WIFI_DIR ${CONN_DRIVER_DIR}/wifi)
set(
    conn_wifi_macro
    _PRE_OS_VERSION_LINUX=0
    _PRE_OS_VERSION_WIN32=1
    _PRE_OS_VERSION_WINDOWS=2
    _PRE_OS_VERSION_RAW=3
    _PRE_OS_VERSION_HiRTOS=4
    _PRE_OS_VERSION_WIN32_RAW=5
    _PRE_OS_VERSION=_PRE_OS_VERSION_HiRTOS
    _PRE_PRODUCT_ID_HI110X_HOST
	_PRE_WLAN_FEATURE_11BE
	_PRE_WLAN_FEATURE_11AX
    _PRE_MULTI_CORE_DPE_OFFLOAD
	_PRE_MULTI_CORE_DPE_OFFLOAD_COMPILE
	_PRE_MULTI_CORE_DPE_DMA_SYNC
	_PRE_MULTI_CORE_DPE_DMA_ASYNC
	_PRE_MULTI_CORE_DPE_THREAD_FIBER
	#_PRE_MULTI_CORE_DPE_THREAD_STACK_MEM
	#_PRE_MULTI_CORE_DPE_DMA_DEBUG
	USE_TCM
	_DMA_USE_TCM
	_USE_CACHE_PRELOAD
	_PRE_WLAN_CHBA_MGMT
	_PRE_WLAN_FEATURE_MCAST_AMPDU
	_PRE_WLAN_FEATURE_ML
	_PRE_WLAN_FEATURE_EMLSR
	_PRE_WLAN_FEATURE_TX_STAT
	_PRE_WLAN_DPE_DEBUG
)

target_compile_definitions(
    ${target_name}
    PRIVATE
    ${conn_wifi_macro}
)

# .h文件目录
set(conn_wifi_ddr_inc
    ${conn_wifi_ddr_inc}
    ${CONN_WIFI_DIR}/inc
    ${CONN_WIFI_DIR}/inc/hd_common
    ${CONN_WIFI_DIR}/dpe
    ${CONN_WIFI_DIR}/dpe/dfx
    ${CONN_WIFI_DIR}/dpe/adapter
    ${CONN_WIFI_DIR}/dpe/frw
    ${CONN_WIFI_DIR}/dpe/features
    ${CONN_WIFI_DIR}/dpe/features/vsp
    ${CONN_WIFI_DIR}/dpe/frame
    ${CONN_WIFI_DIR}/dpe/hal
    ${CONN_WIFI_DIR}/dpe/hal/product/mp12
    ${CONN_WIFI_DIR}/dpe/hal/product/mp13
    ${CONN_WIFI_DIR}/dpe/hal/product/mp16
    ${CONN_WIFI_DIR}/dpe/hal/product/mp16c_gf61
    ${CONN_WIFI_DIR}/dpe/hal/product/mp17c
    ${CONN_WIFI_DIR}/dpe/hcc
    ${CONN_WIFI_DIR}/dpe/inc
    ${CONN_WIFI_DIR}/dpe/inc/oal
    ${CONN_WIFI_DIR}/dpe/main
    ${CONN_WIFI_DIR}/dpe/resource
    ${CONN_WIFI_DIR}/dpe/rx
    ${CONN_WIFI_DIR}/dpe/thread
    ${CONN_WIFI_DIR}/dpe/tx
)

# .c文件
# frw层
set(conn_wifi_frw_ddr_src
    ${CONN_WIFI_DIR}/dpe/frw/dpe_frw_main.c
	${CONN_WIFI_DIR}/dpe/frw/dpe_frw_event.c
)
# rx层
set(conn_wifi_rx_ddr_src
    ${CONN_WIFI_DIR}/dpe/rx/hmac_rx_complete.c
	${CONN_WIFI_DIR}/dpe/rx/hmac_rx_dev.c
	${CONN_WIFI_DIR}/dpe/rx/hmac_rx_w2w.c
	${CONN_WIFI_DIR}/dpe/rx/hmac_rx_host.c
	${CONN_WIFI_DIR}/dpe/rx/hmac_rx.c
)
# resource层
set(conn_wifi_resource_ddr_src
    ${CONN_WIFI_DIR}/dpe/resource/dpe_wlan_tid.c
	${CONN_WIFI_DIR}/dpe/resource/dpe_wlan_vap.c
	${CONN_WIFI_DIR}/dpe/resource/dpe_wlan_device.c
	${CONN_WIFI_DIR}/dpe/resource/dpe_wlan_resource.c
	${CONN_WIFI_DIR}/dpe/resource/dpe_wlan_user.c
)
# oal层
set(conn_wifi_oal_ddr_src
)
# features层
set(conn_wifi_features_ddr_src
    ${CONN_WIFI_DIR}/dpe/features/hmac_rx_reorder_hw.c
	${CONN_WIFI_DIR}/dpe/features/hmac_rx_reorder_sw.c
	${CONN_WIFI_DIR}/dpe/features/hmac_rx_reorder.c
	${CONN_WIFI_DIR}/dpe/features/hmac_rx_pn_check.c
	${CONN_WIFI_DIR}/dpe/features/dpe_wlan_config.c
	${CONN_WIFI_DIR}/dpe/features/hmac_host_al_tx.c
	${CONN_WIFI_DIR}/dpe/features/dpe_wlan_debug.c
	${CONN_WIFI_DIR}/dpe/features/vsp/dpe_vsp.c
	${CONN_WIFI_DIR}/dpe/features/vsp/dpe_vsp_source.c
)
# frame层
set(conn_wifi_frame_ddr_src
    ${CONN_WIFI_DIR}/dpe/frame/mac_data.c
)
# hal层
set(conn_wifi_hal_ddr_src
    ${CONN_WIFI_DIR}/dpe/hal/host_hal_dscr.c
	${CONN_WIFI_DIR}/dpe/hal/host_hal_mac.c
	${CONN_WIFI_DIR}/dpe/hal/host_hal_dma_batch.c
	${CONN_WIFI_DIR}/dpe/hal/host_hal_irq.c
	${CONN_WIFI_DIR}/dpe/hal/host_hal_main.c
	${CONN_WIFI_DIR}/dpe/hal/host_hal_dma.c
	${CONN_WIFI_DIR}/dpe/hal/host_hal_device.c
	${CONN_WIFI_DIR}/dpe/hal/host_hal_ring.c
	${CONN_WIFI_DIR}/dpe/hal/host_hal_access_mgmt.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp12/host_sniffer_mp12.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp12/host_mac_mp12.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp12/host_csi_mp12.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp12/wlan_chip_spec12.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp12/host_irq_mp12.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp12/host_main_mp12.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp12/host_ftm_mp12.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp12/host_tx_mp12.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp12/host_dscr_mp12.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp17c/pilot/wlan_chip_spec17c.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp17c/pilot/host_mac_mp17c.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp17c/pilot/host_tx_mp17c.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp17c/pilot/host_irq_mp17c.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp17c/pilot/host_csi_mp17c.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp17c/pilot/host_sniffer_mp17c.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp17c/pilot/host_dscr_mp17c.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp17c/pilot/host_ftm_mp17c.c
	${CONN_WIFI_DIR}/dpe/hal/product/mp17c/pilot/host_main_mp17c.c
)
# dfx层
set(conn_wifi_dfx_ddr_src
	${CONN_WIFI_DIR}/dpe/dfx/hmac_tx_stat.c
	${CONN_WIFI_DIR}/dpe/dfx/dpe_wlan_stat.c
	${CONN_WIFI_DIR}/dpe/dfx/hmac_host_performance.c
)
# tx层
set(conn_wifi_tx_ddr_src
	${CONN_WIFI_DIR}/dpe/tx/hmac_tx_ring_alloc.c
	${CONN_WIFI_DIR}/dpe/tx/hmac_tid_ring_switch.c
	${CONN_WIFI_DIR}/dpe/tx/hmac_tx_msdu_dscr.c
	${CONN_WIFI_DIR}/dpe/tx/hmac_tid_sche.c
	${CONN_WIFI_DIR}/dpe/tx/hmac_tx_switch.c
	${CONN_WIFI_DIR}/dpe/tx/hmac_tx_sche_switch_fsm.c
	${CONN_WIFI_DIR}/dpe/tx/dpe_tx_data.c
	${CONN_WIFI_DIR}/dpe/tx/hmac_host_ring_tx.c
	${CONN_WIFI_DIR}/dpe/tx/hmac_tx_switch_fsm.c
	${CONN_WIFI_DIR}/dpe/tx/hmac_tid_update.c
	${CONN_WIFI_DIR}/dpe/tx/hmac_tx_complete.c
	${CONN_WIFI_DIR}/dpe/tx/hmac_pps_fsm.c
)
# main层
set(conn_wifi_main_ddr_src
	${CONN_WIFI_DIR}/dpe/main/dpe_main.c
)
# thread层
set(conn_wifi_thread_ddr_src
	${CONN_WIFI_DIR}/dpe/thread/dpe_thread.c
)
# hcc层
set(conn_wifi_hcc_ddr_src
	${CONN_WIFI_DIR}/dpe/hcc/dpe_hcc_master.c
	${CONN_WIFI_DIR}/dpe/hcc/dpe_hcc_slave.c
	${CONN_WIFI_DIR}/dpe/hcc/dpe_hcc.c
)
# adapter层
set(conn_wifi_adapter_ddr_src
	${CONN_WIFI_DIR}/dpe/adapter/dpe_wlan_rx.c
	${CONN_WIFI_DIR}/dpe/adapter/dpe_wlan_tx.c
	${CONN_WIFI_DIR}/dpe/adapter/dpe_dma.c
	${CONN_WIFI_DIR}/dpe/adapter/dpe_netdev_sync.c
	${CONN_WIFI_DIR}/dpe/adapter/dpe_filter_reg.c
	${CONN_WIFI_DIR}/dpe/adapter/dpe_pm.c
	${CONN_WIFI_DIR}/dpe/adapter/dpe_sync_hmac.c
)
set(conn_wifi_ddr_src
    ${conn_wifi_frw_ddr_src}
	${conn_wifi_rx_ddr_src}
	${conn_wifi_resource_ddr_src}
	${conn_wifi_oal_ddr_src}
	${conn_wifi_features_ddr_src}
	${conn_wifi_frame_ddr_src}
	${conn_wifi_hal_ddr_src}
	${conn_wifi_dfx_ddr_src}
	${conn_wifi_tx_ddr_src}
	${conn_wifi_main_ddr_src}
	${conn_wifi_thread_ddr_src}
	${conn_wifi_hcc_ddr_src}
	${conn_wifi_adapter_ddr_src}
)

# 向编译目标添加头文件路径
target_include_directories(
    ${target_name}
    PRIVATE
    ${conn_wifi_ddr_inc}
)

target_sources(${target_name} PRIVATE ${conn_wifi_ddr_src})