set(packet root hids plat plat_llt root_llt root_slt plat_slt plat_phy root_modem root_chr_build_tool plat_smartboot ohos_root_hm_kernel ohos_root_hm_kernel_root_pkg)

#----------------------------------------------------------------------------------
# compile entrance
#----------------------------------------------------------------------------------
set(build_tree ${packet})

#----------------------------------------------------------------------------------
# Build Tree Common Definition
#----------------------------------------------------------------------------------
set(rfdsp_set rf_type4 rf_type6 rf_type7)
set(rf_type7.dep
    rf_type7_rfdsp
    rf_type7_rsip
)

set(common nv_modem_img modemconfig_cust_image)
set(tsp_phy_key_set
    uphy_tsp_fs3
    ul1m_tsp_fs3
    fess_bb_tsp_fs3
    neun_tsp_fs3
    lphy_tsp_fs3
    nphy_tsp_fs3
    uphy_lsp_fs3
    ncun_tsp_fs3
    csxw2_tsp_fs3
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
set(tsp_ps_open_set)

set(tsp_ps_key_set
    asn1
    nlxwl2
    encodix
    gas
    lvpsl3
    lvpsnas
    imsa
    ims
    sc1
    voice
    nrnas
    nrrc
    nrps_om
    ps_ltev_l2
    ps_infrastructure
    tlas
    gul2
    was
    guas_pidtrans
    rrc_base
    l2base
    psbase
    nasbase
    lnas
    gunas
    ps_solution
    v2x_security
    hid2d_l3
    ps_hid2d_l2
    srrc
    ps_tts_l2
    xw1rrc
)

set(tsp_os_key_set rtosck)
set(tsp_drv_open_set
    ccpu_sec_c
    ccpu_tsp_drv
    ccpu_pl2_libs
    ccpu_drv_mntn
)
set(ps_mfg_mo.dep ps_mfg)
set(nv_public.dep nv_private diag_build_tool)
#----------------------------------------------------------------------------------
# build_tree-packet: hids
#----------------------------------------------------------------------------------
set(hids.dep tools_modem_update_install)
set(tools_modem_update_install.dep tools_modem_update)
set(sub_log_cfg.dep tool_log_cfg)
set(tools_modem_update.dep diag_build_tool modem_tsp modem_psa nv_private diag_rfdsp diag_tsp_drv diag_tsp_ps diag_tsp_phy_fs3 diag_tools diag_tsp_voice ps_mfg_mo dpa_firmware)
set(tool_log_cfg.dep diag_build_tool diag_rfdsp diag_tsp_drv diag_tsp_ps diag_tsp_phy_fs3 diag_tools diag_tsp_voice)

#----------------------------------------------------------------------------------
# build_tree-packet: plat
#----------------------------------------------------------------------------------
set(plat_modem.dep plat_install)
set(plat_install.dep ${common} modem_fw_plat)
set(modem_fw_set_plat lpmcu modem_dt nv_public nv_private drv_build_tool l2dle)
set(modem_fw_plat.dep ${modem_fw_set_plat} modem_tsp_plat)
set(modem_tsp_plat.dep
    ${tsp_os_key_set}
    ${tsp_drv_open_set}
    vpp
    ps_tls_crypt_drv
    diag_build_tool
)

#----------------------------------------------------------------------------------
# build_tree-packet: plat_phy
#----------------------------------------------------------------------------------
set(plat_phy.dep plat_phy_install)
set(plat_phy_install.dep modem_tsp_plat_phy)

set(modem_tsp_plat_phy.dep
    ${tsp_os_key_set}
    ${tsp_drv_open_set}
    ${tsp_phy_key_set}
    vpp
    diag_build_tool
)

#----------------------------------------------------------------------------------
# build_tree-packet: root
#----------------------------------------------------------------------------------
set(root_modem.dep root_install)
set(root_install.dep ${common} modem_fw)

set(modem_fw_set lpmcu modem_dt nv_public nv_private l2dle pde simlock_cust ${rfdsp_set} modem_fw_buildinfo drv_build_tool ps_mfg_mo)
set(modem_fw.dep ${modem_fw_set} modem_tsp modem_psa)
set(modem_tsp.dep
    ${tsp_os_key_set}
    ${tsp_drv_open_set}
    ${tsp_phy_key_set}
    ${tsp_ps_open_set}
    ${tsp_ps_key_set}
    vpp
    ps_tls_crypt_drv
    visp
    diag_build_tool
)

set(modem_psa.dep
    ${phy_psp_key_set}
)

set(dpa_firmware.dep rtosck_dpa)

set(nv_private.dep diag_build_tool)
set(nv_modem_img.dep nv_private)
set(modemconfig_cust_image.dep nv_public nv_private modem_dtcust)
set(ccpu_pl2_libs.dep ccpu_sec_c)
set(lpmcu.dep diag_build_tool)

#----------------------------------------------------------------------------------
# build_tree-packet: root_llt
#----------------------------------------------------------------------------------
set(root_modem_llt.dep root_llt_install)
set(root_llt_install.dep ${common} modem_fw_llt)

set(modem_fw_llt.dep ${modem_fw_set} modem_tsp_llt modem_psa dpa_firmware dpa_dtb)
set(modem_tsp_llt.dep
    ${tsp_os_key_set}
    ${tsp_drv_open_set}
    ${tsp_phy_key_set}
    ${tsp_ps_open_set}
    ${tsp_ps_key_set}
    ccpu_drv_llt
    ccpu_drv_it
    vpp
    ps_tls_crypt_drv
    visp
    diag_build_tool
)

#----------------------------------------------------------------------------------
# build_tree-packet: plat_llt
#----------------------------------------------------------------------------------
set(plat_modem_llt.dep plat_llt_install)
set(plat_llt_install.dep ${common} modem_fw_plat_llt)

# build_tree-packet: plat_smartboot
#----------------------------------------------------------------------------------
set(plat_modem_llt_smartboot.dep plat_smartboot_install)
set(plat_smartboot_install.dep ${common} modem_fw_plat_llt bvp_kernel bvp_sec_os)
set(modem_fw_plat_llt.dep ${modem_fw_set_plat} modem_tsp_plat_llt)
set(modem_tsp_plat_llt.dep
    ${tsp_os_key_set}
    ${tsp_drv_open_set}
    ccpu_drv_llt
    ccpu_drv_it
    vpp
    ps_tls_crypt_drv
    diag_build_tool
)

#----------------------------------------------------------------------------------
# build_tree-packet: root_slt
#----------------------------------------------------------------------------------
set(root_slt.dep root_install_slt)
set(root_install_slt.dep modem_tsp_slt uefi_slt modem_dt)

set(modem_tsp_slt.dep
    ${tsp_os_key_set}
    ${tsp_drv_open_set}
    ccpu_drv_slt
    voice_slt
)

#---------------------------------------------------------------------------------
# build_tree-packet: plat_slt
#---------------------------------------------------------------------------------
set(plat_slt.dep plat_install_slt)
set(plat_install_slt.dep modem_tsp_plat_slt uefi_slt modem_dt dpa_fw_drv_it)

set(modem_tsp_plat_slt.dep
    ${tsp_os_key_set}
    ${tsp_drv_open_set}
    ccpu_drv_slt
)

#----------------------------------------------------------------------------------
# build_tree-packet: root_modem
#----------------------------------------------------------------------------------
set(root_chr_build_tool.dep chr_build_tool)
