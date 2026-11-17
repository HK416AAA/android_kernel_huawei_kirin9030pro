set(HITSP_PHY_KEY_TARGET
)

set(HITSP_PHY_OPEN_TARGET
)

set(HITSP_PS_KEY_TARGET
    ascomm.o
    perasn1.o
    nrps_om.o
    tlas.o
    rohc.o
    nlxwl2.o
    ps_infrastructure.o
    ps_tls_crypt_drv.o
    ps_log.o
    asn1.o
    gas.o
    encodix.o
    was.o
    guas_pidtrans.o
    gl2.o
    wl2.o
    ttfcomm.o
    nrrc_base.o
    nrrc_conn.o
    nrrc_uecap.o
    nrrc_idle.o
    nrrc_entry.o
    imsa.o
    ims.o
    sc1.o
    voice.o
    evs.o
    nrnas.o
    lvpsl3.o
    ps_ltev_l2.o
    lvpsnas.o
    rrc_base.o
    l2base.o
    BASTET1.o
    psbase.o
    nasbase.o
    lnas.o
    gunas.o
    ps_solution.o
    v2x_security.o
    hid2d_l3.o
    ps_hid2d_l2.o
    srrc.o
    ps_tts_l2.o
    cds.o
    xw1rrc.o
    push.o
)

set(HITSP_PS_OPEN_TARGET

)

set(HITSP_PLATFORM_TARGET
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/ipbir_common.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/ipbir_ipv6basic_host.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/ipbir_sh_ipv6basic_host.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_acl6_cbb.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_acl6_sh.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_acl_cbb.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_acl_sh.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_addition.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_arithip_cbb.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_common.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_dopra_cbb_expand.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_dopra_cbb_list.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_ipsec_ctrl.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_ipsec_ctrl6.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_ipsec_pkt.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_ipsec_pkt6.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_ipv4.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_ipv6.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_minitailor.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_pub_comp.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_pub_entry.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_pub_vrpvos.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_tcp4.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_udp4.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpipipsafe_pub.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/ipbir_ipsec_algorithm.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpipipsafe_shell.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/tcpip_os_adp.lib
    visp_libs/${CFG_CONFIG_CCPU_ARCH}/sec_crypto_hitls.lib
    vpp_libs/${CFG_CONFIG_CCPU_ARCH}/libhitls_tls.a
    vpp_libs/${CFG_CONFIG_CCPU_ARCH}/libipsi_pse.a
    vpp_libs/${CFG_CONFIG_CCPU_ARCH}/libhitls_crypto.a
    vpp_libs/${CFG_CONFIG_CCPU_ARCH}/libhitls_bsl.a
)

# set(CFG_TSP_CCORE_COMPONENTS)
set(CFG_TSP_CCORE_OS_DRV ccpu_os_drv.o)
set(CFG_TSP_CCORE_PHY )
set(CFG_TSP_CCORE_DRV
    ccpu_hal.o
    ccpu_main.o
    ccpu_main_minidle.o
    ccpu_hal_minidle.o
)

if("$ENV{modem_build_with_log}" STREQUAL "true")
message(INFO "modem_build_with_log:$ENV{modem_build_with_log}")
list(APPEND CFG_TSP_CCORE_DRV
    ccpu_drv_om.o
)
endif()
