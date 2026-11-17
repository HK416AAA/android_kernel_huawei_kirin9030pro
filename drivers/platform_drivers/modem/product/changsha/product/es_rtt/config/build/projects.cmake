
set(tsp_toolchain clang_tsp.cmake)
set(psp_toolchain clang_psa_itc_v1.0.cmake)
set(hids_toolchain clang_tsp_hids.cmake)
set(hcc7.3_toolchain hcc7.3_arm32.cmake)
set(ps_libs_dir ${GBB_BIN_DIR}/ps_libs/${GBB_PRODUCT_NAME}_es)
set(tsp_libs_dir ${GBB_BIN_DIR}/tsplibs/${GBB_PRODUCT_NAME}_es)
set(rfdsp_libs_dir ${GBB_BIN_DIR}/rfdsplibs/${GBB_PRODUCT_NAME}_es)
set(mdrv_libs_dir ${GBB_BIN_DIR}/mdrvlibs/${GBB_PRODUCT_NAME}_es)
set(vpp_libs_dir ${GBB_PLATFORM_DIR}/vpp_libs/${GBB_PRODUCT_NAME}_es)
set(release_libs_dir ${GBB_MODEM_RELEASE_DIR})

set(diag_tsp_drv.dir ${GBB_TOOLS_DIR}/modem/diag_msg_define/diag_tsp_drv)
set(diag_tsp_drv.stage STAGE_COMPILE)
set(diag_tsp_drv.toolchain ${hids_toolchain})
set(diag_tsp_drv.out diag_tsp_drv.bin)

set(diag_tsp_ps.dir ${GBB_TOOLS_DIR}/modem/diag_msg_define/diag_tsp_ps)
set(diag_tsp_ps.stage STAGE_COMPILE)
set(diag_tsp_ps.toolchain ${hids_toolchain})
set(diag_tsp_ps.out diag_tsp_ps.bin)

set(diag_tsp_phy_fs3.dir ${GBB_TOOLS_DIR}/modem/diag_msg_define/diag_tsp_phy_fs3)
set(diag_tsp_phy_fs3.stage STAGE_COMPILE)
set(diag_tsp_phy_fs3.toolchain ${psp_toolchain})
set(diag_tsp_phy_fs3.libs_file diag_phy.bin)

set(diag_rfdsp.dir ${GBB_TOOLS_DIR}/modem/diag_msg_define/diag_rfdsp)
set(diag_rfdsp.stage STAGE_COMPILE)
set(diag_rfdsp.toolchain clang_udsp_v200.cmake)
set(diag_rfdsp.out diag_rfdsp.bin rfdsp_bprint.a)

set(modem_tsp.dir ${GBB_MODEM_DIR}/key_modules/modem_tsp/build/full)
set(modem_tsp.stage STAGE_LINK)
set(modem_tsp.toolchain ${tsp_toolchain})
set(modem_tsp.sec default)
set(modem_tsp.out modem_tsp.bin modem_mtee.bin)
set(modem_tsp.depends_release_artifact "true")

set(vpp.dir ${GBB_PLATFORM_DIR}/vpp_src)
set(vpp.stage STAGE_COMPILE)
set(vpp.toolchain ${tsp_toolchain})
set(vpp.libs_dir ${vpp_libs_dir})
set(vpp.out vpp_libs/${CFG_CONFIG_CCPU_ARCH})
set(vpp.warning_allowed true)

set(ps_tls_crypt_drv.dir ${GBB_MODEM_DIR}/ps/infrastructure/tls/crypto_driver)
set(ps_tls_crypt_drv.stage STAGE_COMPILE)
set(ps_tls_crypt_drv.toolchain ${tsp_toolchain})
set(ps_tls_crypt_drv.libs_dir ${ps_libs_dir})
set(ps_tls_crypt_drv.libs_file ps_tls_crypt_drv.o)

set(ps_solution.dir ${GBB_MODEM_DIR}/ps/solution)
set(ps_solution.stage STAGE_COMPILE)
set(ps_solution.toolchain ${tsp_toolchain})
set(ps_solution.libs_dir ${ps_libs_dir})
set(ps_solution.out ps_solution.o)

set(v2x_security.dir ${GBB_MODEM_DIR}/ps/solution/v2x/stub)
set(v2x_security.stage STAGE_COMPILE)
set(v2x_security.toolchain ${tsp_toolchain})
set(v2x_security.libs_dir ${ps_libs_dir})
set(v2x_security.out v2x_security.o)

set(gunas.dir ${GBB_MODEM_DIR}/ps/nas/gunas)
set(gunas.stage STAGE_COMPILE)
set(gunas.toolchain ${tsp_toolchain})
set(gunas.libs_dir ${ps_libs_dir})
set(gunas.out gunas.o)

set(ps_infrastructure.dir ${GBB_MODEM_DIR}/ps/infrastructure)
set(ps_infrastructure.stage STAGE_COMPILE)
set(ps_infrastructure.toolchain ${tsp_toolchain})
set(ps_infrastructure.libs_dir ${ps_libs_dir})
set(ps_infrastructure.out ps_infrastructure.o ps_log.o)

set(nrnas.dir ${GBB_MODEM_DIR}/ps/nas/nrnas)
set(nrnas.stage STAGE_COMPILE)
set(nrnas.toolchain ${tsp_toolchain})
set(nrnas.libs_dir ${ps_libs_dir})
set(nrnas.out nrnas.o)

set(imsa.dir ${GBB_MODEM_DIR}/ps/ims/imsa)
set(imsa.stage STAGE_COMPILE)
set(imsa.toolchain ${tsp_toolchain})
set(imsa.libs_dir ${ps_libs_dir})
set(imsa.out imsa.o)

set(ims.dir ${GBB_MODEM_DIR}/ps/ims)
set(ims.env_args -DUGP_OS=UGP_RTOSCK)
set(ims.stage STAGE_COMPILE)
set(ims.toolchain ${tsp_toolchain})
set(ims.libs_dir ${ps_libs_dir})
set(ims.release_libs_dir ${release_libs_dir})
set(ims.release_mode "libs")
set(ims.out ims.o)

set(sc1.dir ${GBB_MODEM_DIR}/ps/ims/sc1)
set(sc1.stage STAGE_COMPILE)
set(sc1.toolchain ${tsp_toolchain})
set(sc1.libs_dir ${ps_libs_dir})
set(sc1.release_libs_dir ${release_libs_dir})
set(sc1.release_mode "libs")
set(sc1.out sc1.o)

set(voice.dir ${GBB_MODEM_DIR}/ps/voice)
set(voice.stage STAGE_COMPILE)
set(voice.toolchain ${tsp_toolchain})
set(voice.libs_dir ${ps_libs_dir})
set(voice.release_libs_dir ${release_libs_dir})
set(voice.release_mode "libs")
set(voice.out voice.o evs.o)
set(voice.warning_allowed true)

set(diag_tsp_voice.dir ${GBB_TOOLS_DIR}/modem/diag_msg_define/diag_tsp_voice)
set(diag_tsp_voice.stage STAGE_COMPILE)
set(diag_tsp_voice.toolchain ${hids_toolchain})
set(diag_tsp_voice.out diag_tsp_voice.bin)
set(diag_tsp_voice.release_libs_dir ${release_libs_dir})
set(diag_tsp_voice.release_mode "libs")
set(diag_tsp_voice.warning_allowed true)

set(psbase.dir ${GBB_MODEM_DIR}/ps/base)
set(psbase.stage STAGE_COMPILE)
set(psbase.toolchain ${tsp_toolchain})
set(psbase.libs_dir ${ps_libs_dir})
set(psbase.out psbase.o perasn1.o)

set(nasbase.dir ${GBB_MODEM_DIR}/ps/nas/base)
set(nasbase.stage STAGE_COMPILE)
set(nasbase.toolchain ${tsp_toolchain})
set(nasbase.libs_dir ${ps_libs_dir})
set(nasbase.out nasbase.o)

set(lnas.dir ${GBB_MODEM_DIR}/ps/nas/lnas)
set(lnas.stage STAGE_COMPILE)
set(lnas.toolchain ${tsp_toolchain})
set(lnas.libs_dir ${ps_libs_dir})
set(lnas.out lnas.o)

set(rrc_base.dir ${GBB_MODEM_DIR}/ps/rrc)
set(rrc_base.stage STAGE_COMPILE)
set(rrc_base.toolchain ${tsp_toolchain})
set(rrc_base.libs_dir ${ps_libs_dir})
set(rrc_base.out rrc_base.o ascomm.o)

set(gas.dir ${GBB_MODEM_DIR}/ps/rrc/gas)
set(gas.stage STAGE_COMPILE)
set(gas.toolchain ${tsp_toolchain})
set(gas.libs_dir ${ps_libs_dir})
set(gas.out gas.o)

set(was.dir ${GBB_MODEM_DIR}/ps/rrc/was)
set(was.stage STAGE_COMPILE)
set(was.toolchain ${tsp_toolchain})
set(was.libs_dir ${ps_libs_dir})
set(was.out was.o)

set(encodix.dir ${GBB_ROOT_DIR}/vendor/thirdparty/encodix_gsm/ver186)
set(encodix.stage STAGE_COMPILE)
set(encodix.toolchain ${tsp_toolchain})
set(encodix.libs_dir ${ps_libs_dir})
set(encodix.out encodix.o)

set(tlas.dir ${GBB_MODEM_DIR}/ps/rrc/lrrc)
set(tlas.stage STAGE_COMPILE)
set(tlas.toolchain ${tsp_toolchain})
set(tlas.libs_dir ${ps_libs_dir})
set(tlas.out tlas.o)

set(nrrc.dir ${GBB_MODEM_DIR}/ps/rrc/nrrcnew)
set(nrrc.stage STAGE_COMPILE)
set(nrrc.toolchain ${tsp_toolchain})
set(nrrc.libs_dir ${ps_libs_dir})
set(nrrc.out nrrc_base.o nrrc_conn.o nrrc_uecap.o nrrc_idle.o nrrc_entry.o)

set(asn1.dir ${GBB_MODEM_DIR}/ps/rrc/base/gucomm/asn1)
set(asn1.stage STAGE_COMPILE)
set(asn1.toolchain ${tsp_toolchain})
set(asn1.libs_dir ${ps_libs_dir})
set(asn1.out asn1.o)

set(gul2.dir ${GBB_MODEM_DIR}/ps/l2/gul2)
set(gul2.stage STAGE_COMPILE)
set(gul2.toolchain ${tsp_toolchain})
set(gul2.libs_dir ${ps_libs_dir})
set(gul2.out gl2.o wl2.o ttfcomm.o)

set(nlxwl2.dir ${GBB_MODEM_DIR}/ps/l2/nll2)
set(nlxwl2.stage STAGE_COMPILE)
set(nlxwl2.toolchain ${tsp_toolchain})
set(nlxwl2.libs_dir ${ps_libs_dir})
set(nlxwl2.out nlxwl2.o rohc.o)

set(l2base.dir ${GBB_MODEM_DIR}/ps/l2/base)
set(l2base.stage STAGE_COMPILE)
set(l2base.toolchain ${tsp_toolchain})
set(l2base.libs_dir ${ps_libs_dir})
set(l2base.out l2base.o)

set(nrps_om.dir ${GBB_MODEM_DIR}/ps/rrc/base/hashprint)
set(nrps_om.stage STAGE_COMPILE)
set(nrps_om.toolchain ${tsp_toolchain})
set(nrps_om.libs_dir ${ps_libs_dir})
set(nrps_om.out nrps_om.o)

set(ccpu_tsp_drv.dir ${GBB_MODEM_DIR}/drv/ccore)
set(ccpu_tsp_drv.stage STAGE_COMPILE)
set(ccpu_tsp_drv.toolchain ${tsp_toolchain})
set(ccpu_tsp_drv.out ccpu_tsp_boot.o libfdt_opensource.o ccpu_sysboot.o ccpu_main.o ccpu_main_minidle.o ccpu_sysboot_minidle.o ccpu_hal_minidle.o ccpu_hal.o ccpu_eng.o ccpu_mtee_boot.o ccpu_mtee_main.o)

set(ccpu_drv_mntn.dir ${GBB_MODEM_DIR}/drv/ccore/mree/om)
set(ccpu_drv_mntn.stage STAGE_COMPILE)
set(ccpu_drv_mntn.toolchain ${tsp_toolchain})
set(ccpu_drv_mntn.out ccpu_drv_om.o)

set(mcu_uce.dir ${GBB_MODEM_DIR}/drv/mcore/ddr)
set(mcu_uce.stage STAGE_COMPILE)
set(mcu_uce.toolchain ${riscv_toolchain})
set(mcu_uce.out uce_boot.bin uce_runtime.bin)

# drv llt
set(root_llt_install.dir ${GBB_MODEM_DIR}/cmake/modules/install)
set(root_llt_install.stage STAGE_RELEASE)

set(plat_llt_install.dir ${GBB_MODEM_DIR}/cmake/modules/install)
set(plat_llt_install.stage STAGE_RELEASE)

set(modem_fw_llt.dir ${GBB_MODEM_DIR}/cmake/modules/modem_fw/build/full)
set(modem_fw_llt.stage STAGE_PKG)
set(modem_fw_llt.out modem_fw.img)

set(modem_fw_plat_llt.dir ${GBB_MODEM_DIR}/cmake/modules/modem_fw/build/plat)
set(modem_fw_plat_llt.stage STAGE_PKG)
set(modem_fw_plat_llt.out modem_fw.img)

set(modem_tsp_llt.dir ${GBB_MODEM_DIR}/key_modules/modem_tsp/build/llt)
set(modem_tsp_llt.stage STAGE_LINK)
set(modem_tsp_llt.toolchain ${tsp_toolchain})
set(modem_tsp_llt.sec default)
set(modem_tsp_llt.out modem_tsp.bin modem_mtee.bin)

set(modem_tsp_plat_llt.dir ${GBB_MODEM_DIR}/key_modules/modem_tsp/build/plat_llt)
set(modem_tsp_plat_llt.stage STAGE_LINK)
set(modem_tsp_plat_llt.toolchain ${tsp_toolchain})
set(modem_tsp_plat_llt.sec default)
set(modem_tsp_plat_llt.out modem_tsp.bin modem_mtee.bin)

set(ccpu_drv_llt.dir ${GBB_TOPDIR}/llt/mdrv/cmake/tspcore)
set(ccpu_drv_llt.stage STAGE_COMPILE)
set(ccpu_drv_llt.toolchain ${tsp_toolchain})
set(ccpu_drv_llt.out ccpu_drv_llt.o)

#plat
set(modem_tsp_plat.dir ${GBB_MODEM_DIR}/key_modules/modem_tsp/build/plat)
set(modem_tsp_plat.stage STAGE_LINK)
set(modem_tsp_plat.toolchain ${tsp_toolchain})
set(modem_tsp_plat.sec default)
set(modem_tsp_plat.out modem_tsp.bin modem_mtee.bin)

set(modem_fw_plat.dir ${GBB_MODEM_DIR}/cmake/modules/modem_fw/build/plat)
set(modem_fw_plat.stage STAGE_PKG)
set(modem_fw_plat.out modem_fw.img)

set(plat_install.dir ${GBB_MODEM_DIR}/cmake/modules/install/plat)
set(plat_install.stage STAGE_RELEASE)

# phy
set(uphy_tsp_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/uphy)
set(uphy_tsp_fs3.stage STAGE_COMPILE)
set(uphy_tsp_fs3.toolchain ${tsp_toolchain})
set(uphy_tsp_fs3.libs_file uphy.o)

set(uphy_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/uphy)
set(uphy_psa_fs3.stage STAGE_COMPILE)
set(uphy_psa_fs3.toolchain ${psp_toolchain})
set(uphy_psa_fs3.cpu_arch phy_psa)
set(uphy_psa_fs3.libs_file phy_psa/uphy_boot_psa.o phy_psa/uphy_psa.o)
set(uphy_psa_fs3.warning_allowed true)

set(ul1m_tsp_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/ul1m)
set(ul1m_tsp_fs3.stage STAGE_COMPILE)
set(ul1m_tsp_fs3.toolchain ${tsp_toolchain})
set(ul1m_tsp_fs3.libs_file ul1m.o)

set(ul1m_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/ul1m)
set(ul1m_psa_fs3.stage STAGE_COMPILE)
set(ul1m_psa_fs3.toolchain ${psp_toolchain})
set(ul1m_psa_fs3.cpu_arch phy_psa)
set(ul1m_psa_fs3.libs_file phy_psa/ul1m.o)
set(ul1m_psa_fs3.warning_allowed true)

set(neun_tsp_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/neun)
set(neun_tsp_fs3.stage STAGE_COMPILE)
set(neun_tsp_fs3.toolchain ${tsp_toolchain})
set(neun_tsp_fs3.libs_file neun.o)

set(neun_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/neun)
set(neun_psa_fs3.stage STAGE_COMPILE)
set(neun_psa_fs3.toolchain ${psp_toolchain})
set(neun_psa_fs3.cpu_arch phy_psa)
set(neun_psa_fs3.libs_file phy_psa/neun.o)
set(neun_psa_fs3.warning_allowed true)

set(ncun_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/ncun)
set(ncun_psa_fs3.stage STAGE_COMPILE)
set(ncun_psa_fs3.toolchain ${psp_toolchain})
set(ncun_psa_fs3.cpu_arch phy_psa)
set(ncun_psa_fs3.libs_file phy_psa/ncun.o)
set(ncun_psa_fs3.warning_allowed true)

set(ncun_tsp_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/ncun)
set(ncun_tsp_fs3.stage STAGE_COMPILE)
set(ncun_tsp_fs3.toolchain ${tsp_toolchain})
set(ncun_tsp_fs3.libs_file ncun.o)
set(ncun_tsp_fs3.warning_allowed true)

set(csxw1_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/csxw1)
set(csxw1_psa_fs3.stage STAGE_COMPILE)
set(csxw1_psa_fs3.toolchain ${psp_toolchain})
set(csxw1_psa_fs3.cpu_arch phy_psa)
set(csxw1_psa_fs3.libs_file phy_psa/csxw1_hl1c.o phy_psa/csxw1_ll1c.o phy_psa/csxw1_pub.o)
set(csxw1_psa_fs3.warning_allowed true)

set(csxw2_tsp_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/csxw2)
set(csxw2_tsp_fs3.stage STAGE_COMPILE)
set(csxw2_tsp_fs3.toolchain ${tsp_toolchain})
set(csxw2_tsp_fs3.libs_file csxw2.o)
set(csxw2_tsp_fs3.warning_allowed true)

set(csxw2_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/csxw2)
set(csxw2_psa_fs3.stage STAGE_COMPILE)
set(csxw2_psa_fs3.toolchain ${psp_toolchain})
set(csxw2_psa_fs3.cpu_arch phy_psa)
set(csxw2_psa_fs3.libs_file phy_psa/csxw2_comm.o phy_psa/csxw2_hl1c.o phy_psa/csxw2_ml1c.o phy_psa/csxw2_ll1d.o phy_psa/csxw2_ll1u.o)
set(csxw2_psa_fs3.warning_allowed true)

set(fess_bb_tsp_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/fess)
set(fess_bb_tsp_fs3.stage STAGE_COMPILE)
set(fess_bb_tsp_fs3.toolchain ${tsp_toolchain})
set(fess_bb_tsp_fs3.libs_file fess.o)

set(fess_bb_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/fess)
set(fess_bb_psa_fs3.stage STAGE_COMPILE)
set(fess_bb_psa_fs3.toolchain ${psp_toolchain})
set(fess_bb_psa_fs3.cpu_arch phy_psa)
set(fess_bb_psa_fs3.libs_file phy_psa/fess.o)
set(fess_bb_psa_fs3.warning_allowed true)

set(lphy_tsp_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/lphy)
set(lphy_tsp_fs3.stage STAGE_COMPILE)
set(lphy_tsp_fs3.toolchain ${tsp_toolchain})
set(lphy_tsp_fs3.libs_file lphy.o)

set(lphy_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/lphy)
set(lphy_psa_fs3.stage STAGE_COMPILE)
set(lphy_psa_fs3.toolchain ${psp_toolchain})
set(lphy_psa_fs3.cpu_arch phy_psa)
set(lphy_psa_fs3.libs_file phy_psa/lphy_comm.o phy_psa/lphy_hl1c.o phy_psa/lphy_ml1c.o phy_psa/lphy_ll1d.o phy_psa/lphy_ll1u.o)
set(lphy_psa_fs3.warning_allowed true)

set(nphy_tsp_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/nphy)
set(nphy_tsp_fs3.stage STAGE_COMPILE)
set(nphy_tsp_fs3.toolchain ${tsp_toolchain})
set(nphy_tsp_fs3.libs_file nphy.o)

set(nphy_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/nphy)
set(nphy_psa_fs3.stage STAGE_COMPILE)
set(nphy_psa_fs3.toolchain ${psp_toolchain})
set(nphy_psa_fs3.cpu_arch phy_psa)
set(nphy_psa_fs3.libs_file phy_psa/nphy_comm.o phy_psa/nphy_hl1c.o phy_psa/nphy_ml1c.o phy_psa/nphy_ll1d.o phy_psa/nphy_ll1u.o)
set(nphy_psa_fs3.warning_allowed true)

set(ps_agent_psa.dir ${GBB_MODEM_DIR}/phy/ps_agent)
set(ps_agent_psa.stage STAGE_COMPILE)
set(ps_agent_psa.toolchain ${psp_toolchain})
set(ps_agent_psa.cpu_arch phy_psa)
set(ps_agent_psa.libs_file phy_psa/ps_agent_nr.o phy_psa/ps_agent_lte.o phy_psa/ps_agent_comm.o)
set(ps_agent_psa.warning_allowed true)

set(ps_agent_tsp.dir ${GBB_MODEM_DIR}/phy/ps_agent)
set(ps_agent_tsp.stage STAGE_COMPILE)
set(ps_agent_tsp.toolchain ${tsp_toolchain})
set(ps_agent_tsp.libs_file ps_agent_nr.o ps_agent_lte.o ps_agent_comm.o)

set(gphy_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/gphy)
set(gphy_psa_fs3.stage STAGE_COMPILE)
set(gphy_psa_fs3.toolchain ${psp_toolchain})
set(gphy_psa_fs3.cpu_arch phy_psa)
set(gphy_psa_fs3.libs_file phy_psa/gphy.o)
set(gphy_psa_fs3.warning_allowed true)

set(wphy_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/wphy)
set(wphy_psa_fs3.stage STAGE_COMPILE)
set(wphy_psa_fs3.toolchain ${psp_toolchain})
set(wphy_psa_fs3.cpu_arch phy_psa)
set(wphy_psa_fs3.libs_file phy_psa/wphy.o)
set(wphy_psa_fs3.warning_allowed true)

set(sphy_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/sphy)
set(sphy_psa_fs3.stage STAGE_COMPILE)
set(sphy_psa_fs3.toolchain ${psp_toolchain})
set(sphy_psa_fs3.cpu_arch phy_psa)
set(sphy_psa_fs3.libs_file phy_psa/sphy.o)
set(sphy_psa_fs3.warning_allowed true)

set(slcomm_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/sidelink/comm)
set(slcomm_psa_fs3.stage STAGE_COMPILE)
set(slcomm_psa_fs3.toolchain ${psp_toolchain})
set(slcomm_psa_fs3.cpu_arch phy_psa)
set(slcomm_psa_fs3.libs_file phy_psa/slcomm.o)
set(slcomm_psa_fs3.warning_allowed true)

set(v2xl_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/sidelink/v2xl)
set(v2xl_psa_fs3.stage STAGE_COMPILE)
set(v2xl_psa_fs3.toolchain ${psp_toolchain})
set(v2xl_psa_fs3.cpu_arch phy_psa)
set(v2xl_psa_fs3.libs_file phy_psa/v2xl.o)
set(v2xl_psa_fs3.warning_allowed true)

set(d2dl_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/sidelink/d2dl)
set(d2dl_psa_fs3.stage STAGE_COMPILE)
set(d2dl_psa_fs3.toolchain ${psp_toolchain})
set(d2dl_psa_fs3.cpu_arch phy_psa)
set(d2dl_psa_fs3.libs_file phy_psa/d2dl.o)
set(d2dl_psa_fs3.warning_allowed true)

set(rtt_test_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/ul1m/rtm)
set(rtt_test_fs3.stage STAGE_COMPILE)
set(rtt_test_fs3.toolchain ${tsp_toolchain})
set(rtt_test_fs3.libs_file rtt_test.o)

set(uphy_lsp_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/platform/build_lsp)
set(uphy_lsp_fs3.stage STAGE_COMPILE)
set(uphy_lsp_fs3.toolchain ${tsp_toolchain})
set(uphy_lsp_fs3.libs_file
    seg_head_config_phy.xml
    uphy_check.ld
    uphy_ddr_bss.ld
    uphy_ddr_data.ld
    uphy_ddr_rodata.ld
    uphy_ddr_text.ld
    uphy_virt.ld
    uphy_pl1_data.ld
    uphy_pl2_bss.ld
    uphy_pl2_data.ld
    uphy_pl2_rodata.ld
    uphy_pl2_text.ld
    uphy_pl2_rsv.ld
    uphy_ddr_wbna_data.ld
)

set(satellite_lib_psa_fs3.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/satellite_lib)
set(satellite_lib_psa_fs3.stage STAGE_COMPILE)
set(satellite_lib_psa_fs3.toolchain ${psp_toolchain})
set(satellite_lib_psa_fs3.cpu_arch phy_psa)
set(satellite_lib_psa_fs3.release_libs_dir ${release_libs_dir}/phy_psa)
set(satellite_lib_psa_fs3.release_mode "libs")
set(satellite_lib_psa_fs3.libs_file phy_psa/satellite_lib.o)


set(psa_sec_c.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/build/psa_sec_c)
set(psa_sec_c.stage STAGE_COMPILE)
set(psa_sec_c.toolchain ${psp_toolchain})
set(psa_sec_c.cpu_arch phy_psa)
set(psa_sec_c.out phy_psa/psa_sec_c.o)
set(psa_sec_c.warning_allowed true)

set(modem_psa.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/build/eng_cmake/build/phy_psp)
set(modem_psa.stage STAGE_LINK)
set(modem_psa.toolchain ${psp_toolchain})
set(modem_psa.out modem_psa.elf modem_psa.bin)

set(bbp_age.dir ${GBB_MODEM_DIR}/platform/tsp/${GBB_PRODUCT_NAME}/age)
set(bbp_age.stage STAGE_COMPILE)
set(bbp_age.toolchain ${tsp_toolchain})
set(bbp_age.libs_file bbp_aging.o)

set(phy_trace_cfg.dir ${GBB_MODEM_DIR}/phy/hing_phy_fs3/build/trace_cfg)
set(phy_trace_cfg.stage STAGE_COMPILE)
set(phy_trace_cfg.toolchain ${psp_toolchain})
set(phy_trace_cfg.out phy_trace_cfg.elf)
set(phy_trace_cfg.warning_allowed true)
#end phy

set(ccpu_pl2_libs.dir ${GBB_MODEM_DIR}/key_modules/pl2_libs)
set(ccpu_pl2_libs.stage STAGE_COMPILE)
set(ccpu_pl2_libs.toolchain ${tsp_toolchain})
set(ccpu_pl2_libs.out pl2_libs/libc_drv.a pl2_libs/libHITSP_sec_c_drv.a)

set(ccpu_sec_c.dir ${GBB_MODEM_DIR}/key_modules/secure_c)
set(ccpu_sec_c.stage STAGE_COMPILE)
set(ccpu_sec_c.toolchain ${tsp_toolchain})
set(ccpu_sec_c.out libHITSP_sec_c.a)

set(rtosck.dir ${GBB_MODEM_DIR}/key_modules/rtosck)
set(rtosck.checkdir ${GBB_PLATFORM_DIR}/rtosck_os)
set(rtosck.stage STAGE_COMPILE)
set(rtosck.toolchain ${tsp_toolchain})
set(rtosck.libs_dir ${GBB_BIN_DIR}/rtosck_libs/${GBB_PRODUCT_NAME})
set(rtosck.out
    rtosck_os/tspv300
)

set(rfdsp_entry.dir ${GBB_MODEM_DIR}/phy/fess_rf/multi_rf/build)
set(rfdsp_entry.stage STAGE_COMPILE)
set(rfdsp_entry.sec default)
set(rfdsp_entry.sec_file rf_type6.bin)
set(rfdsp_entry.libs_dir ${rfdsp_libs_dir})
set(rfdsp_entry.out rf_type6.bin rf_type6.elf rf_type6.map)

set(rf_type6.dir ${GBB_MODEM_DIR}/phy/fess_rf/multi_rf/build/hi6356v200)
set(rf_type6.stage STAGE_COMPILE)
set(rf_type6.release_mode "libs")
set(rf_type6.release_libs_dir ${release_libs_dir})
set(rf_type6.libs_dir ${rfdsp_libs_dir})
set(rf_type6.out rf_type6.bin rf_type6.elf rf_type6.map rf_type6.dump)
set(rf_type6.toolchain clang_udsp_v200.cmake)
set(rf_type6.warning_allowed true)

#------------------------------------------------------------------------------
# 以下工程是非cmake框架的封装，不需要指定toolchain
#------------------------------------------------------------------------------

set(modem_fw.dir ${GBB_MODEM_DIR}/cmake/modules/modem_fw/build/full)
set(modem_fw.stage STAGE_PKG)
set(modem_fw.out modem_fw.img)

set(pde.dir ${GBB_MODEM_DIR}/pde/build)
set(pde.stage STAGE_COMPILE)
set(pde.sec default)
set(pde.sec_file pde_pdf.bin)
set(pde.out pde_pdf.bin)

set(modem_dt.dir ${GBB_MODEM_DIR}/config/dts/cp/build_script)
set(modem_dt.stage STAGE_COMPILE)
set(modem_dt.sec default)
set(modem_dt.sec_file modem_dt.img)
set(modem_dt.out changsha_udp_tsp_config.dtb modem_dt.img)

set(modem_dtcust.dir ${GBB_MODEM_DIR}/config/dts/overlay/build_script)
set(modem_dtcust.stage STAGE_COMPILE)
set(modem_dtcust.sec default)
set(modem_dtcust.out modem_dtcust.img)
set(modem_dtcust.warning_allowed true)

set(diag_tools.dir ${GBB_TOOLS_DIR}/modem/diag_msg_define/diag_tools)
set(diag_tools.stage STAGE_COMPILE)
set(diag_tools.toolchain ${hids_toolchain})
set(diag_tools.out diag_tools.bin)

set(tool_log_cfg.dir ${GBB_TOPDIR}/tools/modem/diag_tools_common/build/tool_log_cfg)
set(tool_log_cfg.stage STAGE_COMPILE)
set(tool_log_cfg.out tool_logcfg/)
set(diag_build_tool_lib_dir ${GBB_ROOT_DIR}/tools/modem/diag_tools_libs/${GBB_PRODUCT_NAME})
set(diag_build_tool.dir ${GBB_TOOLS_DIR}/modem/diag_tools_common/build/)
set(diag_build_tool.stage STAGE_COMPILE)
set(diag_build_tool.warning_allowed true)
set(diag_build_tool.libs_dir ${diag_build_tool_lib_dir})
set(diag_build_tool.out
    diag_build_tool/cdbmconverter/CdbmConverter
    diag_build_tool/cfgmaker/CfgMaker_New
    diag_build_tool/newbnt/bnt
    diag_build_tool/newbnt/cliem.cfg
    diag_build_tool/newbnt/klist.bin
    diag_build_tool/bootImage/bootImage
    diag_build_tool/NvColdPatchBnt/NvColdPatchBnt
)
set(diag_build_tool.warning_allowed true)

set(diag_hifi.dir ${GBB_TOOLS_DIR}/modem/diag_msg_define/diag_hifi)
set(diag_hifi.stage STAGE_COMPILE)
set(diag_hifi.out diag_hifi.bin)

include(${GBB_PRODUCT_PROJECT_DIR}/nv_private.cmake)
include(${GBB_PRODUCT_PROJECT_DIR}/nv_public.cmake)

set(modemconfig_cust_image.dir ${GBB_MODEM_DIR}/cmake/modules/modemconfig_cust_img)
set(modemconfig_cust_image.stage STAGE_PKG)

set(nv_modem_img.dir ${GBB_MODEM_DIR}/cmake/modules/nv_modem_img)
set(nv_modem_img.stage STAGE_PKG)

set(root_install.dir ${GBB_MODEM_DIR}/cmake/modules/install)
set(root_install.stage STAGE_RELEASE)
