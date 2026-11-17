subdir-ccflags-y += -Werror -Wformat=2 -Wfloat-equal -Wdate-time -Wno-declaration-after-statement -Wno-missing-prototypes
subdir-ccflags-y += -I$(srctree)/include/linux/mtd/
subdir-ccflags-y += -I$(srctree)/drivers/platform_drivers/tzdriver/
subdir-ccflags-y += -I$(srctree)/drivers/platform_drivers/tzdriver/libhwsecurec/
subdir-ccflags-y += -I$(srctree)/drivers/communication/interface/host/include/
subdir-ccflags-y += -Wno-frame-larger-than=
subdir-ccflags-y += -I$(srctree)/drivers/platform_drivers/tzdriver/
subdir-ccflags-y += -I$(srctree)/drivers/platform_drivers/tzdriver_hm/

# start dpa ko compile
ifeq ($(strip $(CONFIG_DPA_DRIVERS)),m)
DPA_MODULE := dpa
$(DPA_MODULE)-y :=
obj-m := $(DPA_MODULE).o

ifdef CONFIG_DPA_COMPILE_DEMO
$(DPA_MODULE)-y += compile_demo/demo.o
endif

subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/include/
subdir-ccflags-y += -I$(srctree)/drivers/communication/interface/host/include/
# rproc
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/remoteproc/rproc/
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/remoteproc/mem_layout/
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/remoteproc/load/
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/remoteproc/pm/
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/remoteproc/clk/
# boot
$(DPA_MODULE)-y += remoteproc/sysboot/sysboot.o
$(DPA_MODULE)-y += remoteproc/rproc/rproc.o
# clk
$(DPA_MODULE)-y += remoteproc/clk/clk.o
# mem layout
$(DPA_MODULE)-y += remoteproc/mem_layout/mem_layout.o
$(DPA_MODULE)-y += remoteproc/mem_layout/mem_pool.o
$(DPA_MODULE)-y += memory/memory_driver.o
$(DPA_MODULE)-y += memory/memory_layout.o
# ipc
$(DPA_MODULE)-y += remoteproc/dpa_ipc/dpa_ipc.o
$(DPA_MODULE)-y += remoteproc/dpa_ipc/dpa_ipc_dump.o

# nmi
$(DPA_MODULE)-y += remoteproc/nmi/nmi.o
# syscount
$(DPA_MODULE)-y += remoteproc/syscount/syscount.o

# dpa_rfile
ifdef CONFIG_DPA_RFILE
$(DPA_MODULE)-y += remoteproc/rfile/rfile_server.o
$(DPA_MODULE)-y += remoteproc/rfile/rfile_server_dump.o
$(DPA_MODULE)-y += remoteproc/rfile/rfile_server_fipc.o
$(DPA_MODULE)-y += remoteproc/rfile/rfile_server_load_mode.o
endif

# mntn-om-fileops
$(DPA_MODULE)-y           += mntn/file_ops/bsp_file_ops.o
subdir-ccflags-y+= -I$(srctree)/drivers/communication/dpa/mntn/file_ops
# mntn-om-dump
# modem工程构建传递该参数, 本地构建无此参数，为空字符串
subdir-ccflags-y+= -DDUMP_DPA_IMAGE_ID=\"$(GBB_MODEM_IMAGEID)\"
subdir-ccflags-y+= -DDUMP_DPA_PRODUCT_NAME=\"$(TARGET_BOARD_PLATFORM)\"
#dump frame
$(DPA_MODULE)-y           += mntn/dump/dump_exc_mgr.o
$(DPA_MODULE)-y           += mntn/dump/dump_frame.o
$(DPA_MODULE)-y           += mntn/dump/dump_subsys_mgr.o
$(DPA_MODULE)-y           += mntn/dump/dump_rdr_wrapper.o
subdir-ccflags-y+= -I$(srctree)/drivers/communication/dpa/mntn/dump \
                   -I$(srctree)/drivers/communication/dpa/mntn/dump/subsys_dpahost \
                   -I$(srctree)/drivers/communication/dpa/mntn/dump/infra \
                   -I$(srctree)/drivers/communication/dpa/mntn/dump/infra/log
#dump log interface
$(DPA_MODULE)-y           += mntn/dump/infra/dump_config.o
$(DPA_MODULE)-y           += mntn/dump/infra/dump_works.o
$(DPA_MODULE)-y           += mntn/dump/infra/log/dump_log_strategy.o
$(DPA_MODULE)-y           += mntn/dump/infra/log/dump_log_cut_strategy.o
$(DPA_MODULE)-y           += mntn/dump/infra/log/dump_logs.o
$(DPA_MODULE)-y           += mntn/dump/infra/log/dump_log_parser.o
$(DPA_MODULE)-y           += mntn/dump/infra/dump_teeos_service.o
#dump subsys dpahost
$(DPA_MODULE)-y           += mntn/dump/subsys_dpahost/dump_dpahost_agent.o
$(DPA_MODULE)-y           += mntn/dump/subsys_dpahost/dump_dpahost_exc_cfg.o
$(DPA_MODULE)-y           += mntn/dump/subsys_dpahost/dump_dpahost_log.o
$(DPA_MODULE)-y           += mntn/dump/subsys_dpahost/dump_area.o
$(DPA_MODULE)-y           += mntn/dump/subsys_dpahost/dump_baseinfo.o
#$(DPA_MODULE)-y           += mntn/dump/subsys_dpahost/dump_boot_check.o
$(DPA_MODULE)-y           += mntn/dump/subsys_dpahost/dump_ko.o
$(DPA_MODULE)-y           += mntn/dump/subsys_dpahost/dump_lastkmsg.o
$(DPA_MODULE)-y           += mntn/dump/subsys_dpahost/dump_area_phone.o
#dump subsys dpafw
$(DPA_MODULE)-y           += mntn/dump/subsys_dpafw/dump_dpafw_agent.o
$(DPA_MODULE)-y           += mntn/dump/subsys_dpafw/dump_dpafw_exc_cfg.o
$(DPA_MODULE)-y           += mntn/dump/subsys_dpafw/dump_dpafw_log.o
#dump subsys dpalpmcu
$(DPA_MODULE)-y           += mntn/dump/subsys_dpalpm/dump_lpm_agent.o
$(DPA_MODULE)-y           += mntn/dump/subsys_dpalpm/dump_lpm_exc_cfg.o
$(DPA_MODULE)-y           += mntn/dump/subsys_dpalpm/dump_lpm_log.o
#dump subsys comm
$(DPA_MODULE)-y           += mntn/dump/subsys_comm/dump_comm_agent.o
$(DPA_MODULE)-y           += mntn/dump/subsys_comm/dump_comm_log.o
$(DPA_MODULE)-y           += mntn/dump/subsys_comm/dump_reset_log.o
#dump subsys modem_agent
$(DPA_MODULE)-y           += mntn/dump/subsys_modem_agent/dump_modem_agent.o
$(DPA_MODULE)-y           += mntn/dump/subsys_modem_agent/dump_modem_agent_log.o
#end mntn-om-dump

#dpa_loader
$(DPA_MODULE)-y           += dpa_loader/dpa_loader_dump.o
$(DPA_MODULE)-y           += dpa_loader/dpa_loader_load_image.o
$(DPA_MODULE)-y           += dpa_loader/dpa_loader_load_modem_teeos.o
$(DPA_MODULE)-y           += dpa_loader/dpa_loader_sec_call.o
$(DPA_MODULE)-y           += dpa_loader/dpa_loader_sec_call.o
$(DPA_MODULE)-y           += dpa_loader/dpa_loader_util.o
#end dpa_loader

#dmi
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/remoteproc/dmi/
ifdef CONFIG_DPA_DMI
# dmi
$(DPA_MODULE)-y += remoteproc/dmi/dmi_client.o
$(DPA_MODULE)-y += remoteproc/dmi/dmi_recv.o
$(DPA_MODULE)-y += remoteproc/dmi/dmi_send.o

# fipc
$(DPA_MODULE)-y += remoteproc/dpa_fipc/dpa_fipc_device.o
$(DPA_MODULE)-y += remoteproc/dpa_fipc/dpa_fipc_driver.o
$(DPA_MODULE)-y += remoteproc/dpa_fipc/dpa_fipc_dts_parse.o
$(DPA_MODULE)-y += remoteproc/dpa_fipc/dpa_fipc_plat.o
$(DPA_MODULE)-y += remoteproc/dpa_fipc/dpa_fipc_core.o
$(DPA_MODULE)-y += remoteproc/dpa_fipc/dpa_fipc_pmsr.o
$(DPA_MODULE)-y += remoteproc/dpa_fipc/dpa_fipc_reset.o
$(DPA_MODULE)-y += remoteproc/dpa_fipc/dpa_fipc_mntn.o
$(DPA_MODULE)-y += remoteproc/dpa_fipc/dpa_fipc_dump.o

# msg
$(DPA_MODULE)-y += remoteproc/msg/dpa_fipc_ops.o
$(DPA_MODULE)-y += remoteproc/msg/dpa_msg_cmsg.o
$(DPA_MODULE)-y += remoteproc/msg/dpa_msg_core.o
$(DPA_MODULE)-y += remoteproc/msg/dpa_msg_dts.o
$(DPA_MODULE)-y += remoteproc/msg/dpa_msg_task.o
endif

#dra
ifdef CONFIG_DPA_DRA
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/remoteproc/dra/
$(DPA_MODULE)-y += remoteproc/dra/bsp_dra.o
$(DPA_MODULE)-y += remoteproc/dra/dra_plat.o
$(DPA_MODULE)-y += remoteproc/dra/dra_core.o
$(DPA_MODULE)-y += remoteproc/dra/dra_lv_sbuf.o
$(DPA_MODULE)-y += remoteproc/dra/dra_hal.o
$(DPA_MODULE)-y += remoteproc/dra/dra_debug.o
$(DPA_MODULE)-y += remoteproc/dra/dra_reset.o
ifdef CONFIG_DPA_DRA_SMMU
$(DPA_MODULE)-y += remoteproc/dra/dra_smmu.o
endif
endif

#gid_ctrl
ifdef CONFIG_DPA_SC_GID_CTRL
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/remoteproc/syscache/
$(DPA_MODULE)-y += remoteproc/syscache/sc_gid_ctrl_hal.o
$(DPA_MODULE)-y += remoteproc/syscache/sc_gid_ctrl.o
endif

# reset
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/remoteproc/reset/
ifdef CONFIG_DPA_RESET
$(DPA_MODULE)-y += remoteproc/reset/dpa_reset_frame.o
$(DPA_MODULE)-y += remoteproc/reset/dpa_reset_dump.o
$(DPA_MODULE)-y += remoteproc/reset/dpa_reset_dev.o
else
$(DPA_MODULE)-y += remoteproc/reset/dpa_reset_stub.o
endif
ifdef CONFIG_DPA_MDM_RESET_AGENT
$(DPA_MODULE)-y += remoteproc/reset/sys_reset.o
else
$(DPA_MODULE)-y += remoteproc/reset/sys_reset_stub.o
endif

#netom
ifdef CONFIG_DPA_NET_OM
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/remoteproc/netom/
$(DPA_MODULE)-y += remoteproc/netom/netom_agent.o
endif

#dfa
ifdef CONFIG_DPA_DFA
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/remoteproc/dfa/
$(DPA_MODULE)-y += remoteproc/dfa/dfa.o
endif

#dshell
ifdef CONFIG_DSHELL_HOST
$(DPA_MODULE)-y += remoteproc/console/dshell_console.o
$(DPA_MODULE)-y += remoteproc/console/dshell_logger.o
else
$(DPA_MODULE)-y += remoteproc/console/dshell_stub.o
endif

# syslog
ifdef CONFIG_DPA_SYSLOG
$(DPA_MODULE)-y += mntn/syslog/syslog_output.o
$(DPA_MODULE)-y += mntn/syslog/syslog_dmesg.o
$(DPA_MODULE)-y += mntn/syslog/syslog_dmi.o
$(DPA_MODULE)-y += mntn/syslog/syslog_user.o
$(DPA_MODULE)-y += mntn/syslog/syslog_logser.o
ifdef CONFIG_LIBLINUX
$(DPA_MODULE)-y += mntn/syslog/syslog_stub.o
else
$(DPA_MODULE)-y += mntn/syslog/syslog_file.o
$(DPA_MODULE)-y += mntn/syslog/syslog_task.o
$(DPA_MODULE)-y += mntn/syslog/syslog_user_info.o
endif
endif

# om
$(DPA_MODULE)-y += mntn/om/ocd_stub.o

ifdef CONFIG_DPA_WDT
$(DPA_MODULE)-y += mntn/om/watchdog_dpa.o
endif
ifdef CONFIG_DPA_HOST_DIAG
$(DPA_MODULE)-y += mntn/om/diag_agent.o
endif

# busprobe
ifdef CONFIG_MDMPERI_QIC
$(DPA_MODULE)-y += mntn/busprobe/buserr_base.o
$(DPA_MODULE)-y += mntn/busprobe/buserr_probe.o
$(DPA_MODULE)-y += mntn/busprobe/buserr_qicprobe.o
$(DPA_MODULE)-y += mntn/busprobe/buserr_pdlock.o
endif

# nstack
ifdef CONFIG_DPA_NSTACK
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/remoteproc\
                       -I$(srctree)/drivers/communication/dpa/proto/nstack/bridge/\
                       -I$(srctree)/drivers/communication/dpa/proto/nstack/bridge/cooperation\
                       -I$(srctree)/drivers/communication/dpa/proto/nstack/bridge/init\
                       -I$(srctree)/drivers/communication/dpa/proto/nstack/bridge/msg\
                       -I$(srctree)/drivers/communication/dpa/proto/nstack/bridge/socket\
                       -I$(srctree)/drivers/communication/dpa/proto/nstack/bridge/sys/\
                       -I$(srctree)/drivers/communication/dpa/proto/nstack/bridge/sys/dpa\
                       -I$(srctree)/drivers/communication/dpa/proto/nstack/bridge/dfx/\
                       -I$(srctree)/drivers/communication/dpa/proto/nstack/framework\
                       -I$(srctree)/drivers/communication/dpa/proto/nstack/framework/data_struct\
                       -I$(srctree)/drivers/communication/dpa/proto/nstack/framework/log\
                       -I$(srctree)/drivers/communication/dpa/proto/nstack/framework/protocols\
                       -I$(srctree)/drivers/communication/dpa/proto/nstack/framework/dfx\

subdir-ccflags-y += -include $(srctree)/drivers/communication/dpa/proto/nstack/framework/compile_config.h

subdir-ccflags-y += -DRTP_FORCE_INTRINSICS=1
subdir-ccflags-y += -DUSE_48BIT_ADDR
subdir-ccflags-y += -DSPL_IGMP=0
subdir-ccflags-y += -DSPL_IPV6=1
subdir-ccflags-y += -DSPL_LINGER=1
subdir-ccflags-y += -DSPL_REUSEPORT=1
subdir-ccflags-y += -DSPL_VLAN_NETIF=1
subdir-ccflags-y += -DSPL_TCP_DEFER_ACCEPT=0
subdir-ccflags-y += -DSPL_PF_HOOK=0
subdir-ccflags-y += -DSPL_STATS=1
subdir-ccflags-y += -DSPL_NETIF_STATS=1
subdir-ccflags-y += -DSPL_NETIFIP_STATS=0
subdir-ccflags-y += -DSPL_IPFRAG_STATS=1
subdir-ccflags-y += -DSPL_ICMP_STATS=1
subdir-ccflags-y += -DSPL_IGMP_STATS=1
subdir-ccflags-y += -DSPL_TCP_STATS=1
subdir-ccflags-y += -DSPL_IP6_STATS=1
subdir-ccflags-y += -DSPL_ICMP6_STATS=1
subdir-ccflags-y += -DSPL_ND6_STATS=1
subdir-ccflags-y += -DSPL_MLD6_STATS=1
subdir-ccflags-y += -DLINUX_NSTACK
subdir-ccflags-y += -DBUILD_BRIDGE
#subdir-ccflags-y += -DOH_MODE
subdir-ccflags-y += -DDPA_MODE

$(DPA_MODULE)-y += proto/nstack/framework/data_struct/dynamic_queue.o
$(DPA_MODULE)-y += proto/nstack/framework/data_struct/list.o
$(DPA_MODULE)-y += proto/nstack/framework/data_struct/stack_rb_tree.o
$(DPA_MODULE)-y += proto/nstack/framework/data_struct/ring.o
$(DPA_MODULE)-y += proto/nstack/framework/protocols/ip6_addr.o
$(DPA_MODULE)-y += proto/nstack/framework/protocols/ip_addr.o
$(DPA_MODULE)-y += proto/nstack/framework/dfx/proto_conn_stats.o

$(DPA_MODULE)-y += proto/nstack/bridge/socket/dpa_inet_socket.o
$(DPA_MODULE)-y += proto/nstack/bridge/socket/sbr_prot_com.o
$(DPA_MODULE)-y += proto/nstack/bridge/socket/sbr_protocol_api.o
$(DPA_MODULE)-y += proto/nstack/bridge/socket/sbr_res_mgr.o
$(DPA_MODULE)-y += proto/nstack/bridge/socket/sbr_socket.o
$(DPA_MODULE)-y += proto/nstack/bridge/socket/sbr_tcp.o
$(DPA_MODULE)-y += proto/nstack/bridge/socket/sbr_udp.o
$(DPA_MODULE)-y += proto/nstack/bridge/msg/bridge_msg_consumer.o
$(DPA_MODULE)-y += proto/nstack/bridge/msg/bridge_msg_producer.o
$(DPA_MODULE)-y += proto/nstack/bridge/msg/bridge_msg_wait_queue.o
$(DPA_MODULE)-y += proto/nstack/bridge/sys/dpa/runtime.o
$(DPA_MODULE)-y += proto/nstack/bridge/sys/dpa/sys_msg.o
$(DPA_MODULE)-y += proto/nstack/bridge/sys/dpa/tc_interface.o
$(DPA_MODULE)-y += proto/nstack/bridge/sys/dpa/sys_rx_filter.o
$(DPA_MODULE)-y += proto/nstack/bridge/sys/dpa/sys_ifidx_convert.o
$(DPA_MODULE)-y += proto/nstack/bridge/sys/sys_log.o
$(DPA_MODULE)-y += proto/nstack/bridge/sys/stack_thread.o
$(DPA_MODULE)-y += proto/nstack/bridge/init/init.o
$(DPA_MODULE)-y += proto/nstack/bridge/cooperation/cooperation.o
$(DPA_MODULE)-y += proto/nstack/bridge/dfx/chr_stats.o
$(DPA_MODULE)-y += proto/nstack/bridge/dfx/global_res_stats.o
$(DPA_MODULE)-y += proto/nstack/bridge/dfx/conn_stats.o
$(DPA_MODULE)-y += proto/nstack/bridge/dfx/dfx_display.o
#$(DPA_MODULE)-y += proto/nstack/server_udp.o
#$(DPA_MODULE)-y += proto/nstack/client_udp.o
endif

# white list
ifdef CONFIG_DPA_WHITE_LIST
$(DPA_MODULE)-y += sms/whitelist/white_list.o
endif

# sms
ifdef CONFIG_DPA_SMS
#subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/sms/netdev/
$(DPA_MODULE)-y += sms/sms_core.o
$(DPA_MODULE)-y += sms/netdev/nic_sync.o
$(DPA_MODULE)-y += sms/tx/sms_gso.o
$(DPA_MODULE)-y += sms/rx/sms_gro.o
endif

ifdef CONFIG_DPA_SMS_FILTER
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/proto/nstack/bridge/
$(DPA_MODULE)-y += sms/filter/sms_filter.o
endif

# traffic-control
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/traffic_control
ifdef CONFIG_DPA_TC
$(DPA_MODULE)-y += traffic_control/dpa_tc_interface.o
$(DPA_MODULE)-y += traffic_control/dpa_tc_statistics.o
$(DPA_MODULE)-y += traffic_control/dpa_tc_netfilter.o
$(DPA_MODULE)-y += traffic_control/dpa_tc_bpf.o
$(DPA_MODULE)-y += traffic_control/dpa_tc_util.o
$(DPA_MODULE)-y += traffic_control/dpa_tc_hidis.o
endif

# proto_om
ifdef CONFIG_DPA_PROTO_OM
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/proto_om/
$(DPA_MODULE)-y += proto_om/dpa_om.o
$(DPA_MODULE)-y += proto_om/dpa_om_msg.o
$(DPA_MODULE)-y += proto_om/dpa_om_hids.o
$(DPA_MODULE)-y += proto_om/dpa_om_tcpdump.o
endif

# udx server
ifdef CONFIG_UDX_SERVER
$(DPA_MODULE)-y += udx/server/udx_channel.o
$(DPA_MODULE)-y += udx/server/udx_dev.o
$(DPA_MODULE)-y += udx/server/udx_main.o
$(DPA_MODULE)-y += udx/server/udx_service_dev.o
$(DPA_MODULE)-y += udx/server/udx_service.o
$(DPA_MODULE)-y += udx/server/udx_test.o
endif

# chr
ifdef CONFIG_DPA_CHR
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/chr/
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/booster/services/net/chr
ifdef CONFIG_CHR_NETLINK_MODULE
$(DPA_MODULE)-y += booster/services/net/chr/dpa_chr_web_stat.o
endif
$(DPA_MODULE)-y += booster/services/net/chr/dpa_chr_info.o
$(DPA_MODULE)-y += booster/services/net/chr/dpa_chr_host_collec.o
$(DPA_MODULE)-y += booster/services/net/chr/dpa_chr_netlink.o
$(DPA_MODULE)-y += chr/host_chr.o
endif

ifdef CONFIG_DPA_BOOSTER
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/booster
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/booster/interface
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/booster/interface/client
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/booster/services/bpf
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/booster/services/network_qoe
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/booster/services/wifi/multilink
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/booster/services/wifi/wiripro_tcp_monitor
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/booster/services/net/chr
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/booster/services/net/tcp_collec
subdir-ccflags-y += -I$(srctree)/drivers/communication/dpa/booster/init

ifdef CONFIG_DPA_BOOSTER
$(DPA_MODULE)-y += booster/interface/client/booster_dmi_client.o
$(DPA_MODULE)-y += booster/services/network_qoe/qoe_client.o
$(DPA_MODULE)-y += booster/services/wifi/multilink/multilink_client.o

ifdef CONFIG_HW_WIFIPRO
$(DPA_MODULE)-y += booster/services/wifi/wiripro_tcp_monitor/wifipro_tcp_monitor_dmi_client.o
endif
$(DPA_MODULE)-y += booster/services/bpf/bpf_dpa_netlink.o
$(DPA_MODULE)-y += booster/services/bpf/booster_bpf_client.o
ifdef CONFIG_HW_BOOSTER
$(DPA_MODULE)-y += booster/services/net/tcp_collec/dpa_pkt_client.o
endif
ifdef CONFIG_CHR_NETLINK_MODULE
$(DPA_MODULE)-y += booster/services/net/chr/dpa_chr_client.o
endif
$(DPA_MODULE)-y += booster/init/booster_init.o
endif
endif

# udx http
ifdef CONFIG_UDX_HTTP
$(DPA_MODULE)-y += udx/agent/udx_agent.o
endif

#udx buffer
ifdef CONFIG_UDX_BUFFER
ifndef CONFIG_LIBLINUX
$(DPA_MODULE)-y += udx/buffer/dma_heap.o
endif
$(DPA_MODULE)-y += udx/buffer/udx_heap.o
$(DPA_MODULE)-y += udx/buffer/udx_heap_helpers.o
$(DPA_MODULE)-y += udx/buffer/udx_buffer.o
$(DPA_MODULE)-y += udx/buffer/udx_buffer_queue.o
endif

ifdef CONFIG_UDX_DFS
$(DPA_MODULE)-y += udx/dfs/dfs_dev.o
endif

ifdef CONFIG_UDX_DFS
$(DPA_MODULE)-y += udx/dss/dss_dev.o
endif

# pm_agent
ifdef CONFIG_DPA_PM_MNTN
$(DPA_MODULE)-y += pm_agent/pm_mntn.o
endif
$(DPA_MODULE)-y += pm_agent/pm_wakeup.o

# sec_call
# 手机平台上，该宏只有定义为y，才在host编译，否则去modem_drvier侧编译
ifeq ($(strip $(CONFIG_DPA_SEC_CALL)),y)
$(DPA_MODULE)-y += remoteproc/sec_call/sec_call.o
endif

# dpa_sampler
ifdef CONFIG_DPA_SAMPLER
$(DPA_MODULE)-y += remoteproc/dpa_sampler/dpa_sampler_buffer.o
$(DPA_MODULE)-y += remoteproc/dpa_sampler/dpa_sampler.o
endif


# end dpa ko compile
else
# start dpa integration compile
obj-$(CONFIG_DPA_DRIVERS) += compile_demo/

# end dpa integration compile
endif

# dt
$(DPA_MODULE)-y += dt/device_tree_load_fw_dtb.o