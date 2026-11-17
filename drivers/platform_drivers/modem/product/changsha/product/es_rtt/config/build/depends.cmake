set(packet root plat)

#----------------------------------------------------------------------------------
# compile entrance
#----------------------------------------------------------------------------------
set(build_tree ${packet})

#----------------------------------------------------------------------------------
# Build Tree Common Definition
#----------------------------------------------------------------------------------
set(config_set nv_public nv_private modem_dt rf_type6)
set(rfdsp_set rfdsp_entry)
set(tsp_phy_key_set
    uphy_tsp_fs3
    ul1m_tsp_fs3
    fess_bb_tsp_fs3
    neun_tsp_fs3
    lphy_tsp_fs3
    nphy_tsp_fs3
    rtt_test_fs3
    uphy_lsp_fs3
    ncun_tsp_fs3
    csxw2_tsp_fs3
    bbp_age
)

set(nphy_tsp_fs3.dep
    ps_agent_tsp
)
set(lphy_tsp_fs3.dep
    ps_agent_tsp
)
set(neun_tsp_fs3.dep
    ps_agent_tsp
)

set(phy_psp_key_set
    uphy_psa_fs3
    ul1m_psa_fs3
    fess_bb_psa_fs3
    neun_psa_fs3
    gphy_psa_fs3
    wphy_psa_fs3
    lphy_psa_fs3
    nphy_psa_fs3
    sphy_psa_fs3
    slcomm_psa_fs3
    v2xl_psa_fs3
    d2dl_psa_fs3
    psa_sec_c
    ncun_psa_fs3
    csxw1_psa_fs3
    csxw2_psa_fs3
    satellite_lib_psa_fs3
)

set(nphy_psa_fs3.dep
    ps_agent_psa
)

set(lphy_psa_fs3.dep
    ps_agent_psa
)
set(neun_psa_fs3.dep
    ps_agent_psa
)
set(tsp_os_key_set
    rtosck
)

set(tsp_drv_open_set
    ccpu_sec_c
    ccpu_tsp_drv
    ccpu_pl2_libs
    ccpu_drv_mntn
)
set(nv_public.dep nv_private diag_build_tool)
set(nv_private.dep diag_build_tool)
#----------------------------------------------------------------------------------
# build_tree-packet: plat
#----------------------------------------------------------------------------------
set(plat.dep plat_install)
set(plat_install.dep modem_tsp_plat ${config_set})
set(modem_tsp_plat.dep
    ${tsp_os_key_set}
    ${tsp_drv_open_set}
    diag_build_tool
    vpp
    ps_tls_crypt_drv
)

#----------------------------------------------------------------------------------
# build_tree-packet: root
#----------------------------------------------------------------------------------
set(root.dep root_install)
set(root_install.dep modem_tsp ${config_set} modem_psa phy_trace_cfg)
set(modem_tsp.dep
    ${tsp_os_key_set}
    ${tsp_drv_open_set}
    ${tsp_phy_key_set}
    diag_build_tool
    vpp
    ps_tls_crypt_drv
)

set(modem_psa.dep
    ${phy_psp_key_set}
)

set(ccpu_pl2_libs.dep ccpu_sec_c)

