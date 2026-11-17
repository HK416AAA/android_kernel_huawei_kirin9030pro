/*
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include "../clk.h"
#include "../clk-fast-dvfs.h"
#include "../clk_sec.h"
#include "clock-es.h"
#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/of_device.h>
#include <linux/clk-provider.h>
#include <media_xpu/media_xpu_clock.h>
#include <media_xpu/media_xpu_reg_extend.h>

static const struct fixed_rate_clock fixed_clks[] = {
	{ CLKIN_SYS, "clkin_sys", NULL, 0, 38400000, "clkin_sys" },
	{ CLKIN_SYS_SERDES, "clkin_sys_serdes", NULL, 0, 38400000, "clkin_sys_serdes" },
	{ CLKIN_REF, "clkin_ref", NULL, 0, 32764, "clkin_ref" },
	{ CLK_FLL_SRC, "clk_fll_src", NULL, 0, 211200000, "clk_fll_src" },
	{ CLK_PPLL1, "clk_ppll1", NULL, 0, 1440000000, "clk_ppll1" },
	{ CLK_PPLL2, "clk_ppll2", NULL, 0, 964000000, "clk_ppll2" },
	{ CLK_PPLL2_B, "clk_ppll2_b", NULL, 0, 1280000000, "clk_ppll2_b" },
	{ CLK_PPLL6, "clk_ppll6", NULL, 0, 1200000000, "clk_ppll6" },
	{ CLK_PPLL7, "clk_ppll7", NULL, 0, 1290000000, "clk_ppll7" },
	{ CLK_SPLL, "clk_spll", NULL, 0, 1671168000, "clk_spll" },
	{ CLK_ULPPLL_1, "clk_ulppll_1", NULL, 0, 294913310, "clk_ulppll_1" },
	{ CLK_AUPLL, "clk_aupll", NULL, 0, 1572864000, "clk_aupll" },
	{ CLK_PPLL_PCIE, "clk_ppll_pcie", NULL, 0, 100000000, "clk_ppll_pcie" },
	{ CLK_SDPLL, "clk_sdpll", NULL, 0, 963000000, "clk_sdpll" },
	{ PCLK, "apb_pclk", NULL, 0, 20000000, "apb_pclk" },
	{ CLK_UART6, "uart6clk", NULL, 0, 19200000, "uart6clk" },
	{ OSC32K, "osc32khz", NULL, 0, 32764, "osc32khz" },
	{ OSC19M, "osc19mhz", NULL, 0, 19200000, "osc19mhz" },
	{ CLK_480M, "clk_480m", NULL, 0, 480000000, "clk_480m" },
	{ CLK_INVALID, "clk_invalid", NULL, 0, 10000000, "clk_invalid" },
	{ CLK_FPGA_1P92, "clk_fpga_1p92", NULL, 0, 1920000, "clk_fpga_1p92" },
	{ CLK_FPGA_2M, "clk_fpga_2m", NULL, 0, 2000000, "clk_fpga_2m" },
	{ CLK_FPGA_10M, "clk_fpga_10m", NULL, 0, 10000000, "clk_fpga_10m" },
	{ CLK_FPGA_19M, "clk_fpga_19m", NULL, 0, 19200000, "clk_fpga_19m" },
	{ CLK_FPGA_20M, "clk_fpga_20m", NULL, 0, 20000000, "clk_fpga_20m" },
	{ CLK_FPGA_24M, "clk_fpga_24m", NULL, 0, 24000000, "clk_fpga_24m" },
	{ CLK_FPGA_26M, "clk_fpga_26m", NULL, 0, 26000000, "clk_fpga_26m" },
	{ CLK_FPGA_27M, "clk_fpga_27m", NULL, 0, 27000000, "clk_fpga_27m" },
	{ CLK_FPGA_32M, "clk_fpga_32m", NULL, 0, 32000000, "clk_fpga_32m" },
	{ CLK_FPGA_40M, "clk_fpga_40m", NULL, 0, 40000000, "clk_fpga_40m" },
	{ CLK_FPGA_48M, "clk_fpga_48m", NULL, 0, 48000000, "clk_fpga_48m" },
	{ CLK_FPGA_50M, "clk_fpga_50m", NULL, 0, 50000000, "clk_fpga_50m" },
	{ CLK_FPGA_57M, "clk_fpga_57m", NULL, 0, 57000000, "clk_fpga_57m" },
	{ CLK_FPGA_60M, "clk_fpga_60m", NULL, 0, 60000000, "clk_fpga_60m" },
	{ CLK_FPGA_64M, "clk_fpga_64m", NULL, 0, 64000000, "clk_fpga_64m" },
	{ CLK_FPGA_80M, "clk_fpga_80m", NULL, 0, 80000000, "clk_fpga_80m" },
	{ CLK_FPGA_100M, "clk_fpga_100m", NULL, 0, 100000000, "clk_fpga_100m" },
	{ CLK_FPGA_160M, "clk_fpga_160m", NULL, 0, 160000000, "clk_fpga_160m" },
};

static const struct fixed_factor_clock fixed_factor_clks[] = {
	{ CLK_SYS_INI, "clk_sys_ini", "clkin_sys", 1, 2, 0, "clk_sys_ini" },
	{ CLK_DIV_SYSBUS, "div_sysbus_pll", "clk_spll", 1, 7, 0, "div_sysbus_pll" },
	{ CLK_DIV_AOBUS_334M, "div_aobus_334M", "clk_spll", 1, 5, 0, "div_aobus_334M" },
	{ CLK_DIV_AOBUS, "sc_div_aobus", "div_aobus_334M", 1, 6, 0, "sc_div_aobus" },
	{ CLK_GATE_TIMER5_B, "clk_timer5_b", "clk_spll", 1, 1, 0, "clk_timer5_b" },
	{ CLK_TIMER_DIV, "clk_div_timer", "clk_fll_src", 1, 17, 0, "clk_div_timer" },
	{ ATCLK, "clk_at", "clk_atdvfs", 1, 1, 0, "clk_at" },
	{ PCLK_DBG, "pclk_dbg", "pclkdiv_dbg", 1, 1, 0, "pclk_dbg" },
	{ CLK_DIV_CSSYSDBG, "clk_cssys_div", "autodiv_sysbus", 1, 1, 0, "clk_cssys_div" },
	{ CLK_GATE_CSSYSDBG, "clk_cssysdbg", "div_sysbus_pll", 1, 1, 0, "clk_cssysdbg" },
	{ ACLK_GATE_ISP, "aclk_isp", "clk_invalid", 1, 1, 0, "aclk_isp" },
	{ CLK_QIC_HSDT1BUS, "clk_qic_hsdt1bus", "clk_spll", 1, 7, 0, "clk_qic_hsdt1bus" },
	{ CLK_DIV_SD, "clk_div_sd", "gt_clk_sd_sys", 1, 12, 0, "clk_div_sd" },
	{ CLK_DIV_320M, "sc_div_320m", "gt_clk_320m_pll", 1, 5, 0, "sc_div_320m" },
	{ PCLK_GATE_UART0, "pclk_uart0", "clk_uart0", 1, 1, 0, "pclk_uart0" },
	{ CLK_FACTOR_UART0, "clk_uart0_fac", "clkmux_uart0", 1, 1, 0, "clk_uart0_fac" },
	{ CLK_GATE_UART3, "clk_uart3", "clk_gate_peri0", 1, 9, 0, "clk_uart3" },
	{ CLK_GATE_UART7, "clk_uart7", "clk_gate_peri0", 1, 9, 0, "clk_uart7" },
	{ CLK_GATE_I2C0, "clk_i2c0", "clk_fll_src", 1, 2, 0, "clk_i2c0" },
	{ CLK_GATE_I2C2, "clk_i2c2", "clk_fll_src", 1, 2, 0, "clk_i2c2" },
	{ CLK_GATE_IOMCU_PERI0, "clk_gate_peri0", "clk_spll", 1, 1, 0, "clk_gate_peri0" },
	{ CLK_USB2PHY_REF_DIV, "clkdiv_usb2phy_ref", "clkgt_usb2phy_ref", 1, 2, 0, "clkdiv_usb2phy_ref" },
	{ CLK_HSDT_SUBSYS_INI, "clk_hsdt_subsys_ini", "clk_spll", 1, 7, 0, "clk_hsdt_subsys_ini" },
	{ CLK_GATE_UFSIO_REF, "clk_ufsio_ref", "clkin_sys", 1, 1, 0, "clk_ufsio_ref" },
	{ CLK_DIV_PTP, "clk_ptp_div", "clk_ptp_gt", 1, 3, 0, "clk_ptp_div" },
	{ CLK_SYSCNT_DIV, "clk_syscnt_div", "clk_sys_ini", 1, 3, 0, "clk_syscnt_div" },
	{ CLK_GATE_GPS_REF, "clk_gps_ref", "clk_sys_ini", 1, 1, 0, "clk_gps_ref" },
	{ CLK_MUX_GPS_REF, "clkmux_gps_ref", "clk_sys_ini", 1, 1, 0, "clkmux_gps_ref" },
	{ CLK_GATE_MDM2GPS0, "clk_mdm2gps0", "clk_sys_ini", 1, 1, 0, "clk_mdm2gps0" },
	{ CLK_GATE_MDM2GPS1, "clk_mdm2gps1", "clk_sys_ini", 1, 1, 0, "clk_mdm2gps1" },
	{ CLK_GATE_MDM2GPS2, "clk_mdm2gps2", "clk_sys_ini", 1, 1, 0, "clk_mdm2gps2" },
	{ VENC_VOLT_HOLD, "venc_volt_hold", "peri_volt_hold", 1, 1, 0, "venc_volt_hold" },
	{ VDEC_VOLT_HOLD, "vdec_volt_hold", "peri_volt_hold", 1, 1, 0, "vdec_volt_hold" },
	{ EDC_VOLT_HOLD, "edc_volt_hold", "peri_volt_hold", 1, 1, 0, "edc_volt_hold" },
	{ EFUSE_VOLT_HOLD, "efuse_volt_hold", "peri_volt_middle", 1, 1, 0, "efuse_volt_hold" },
	{ LDI0_VOLT_HOLD, "ldi0_volt_hold", "peri_volt_hold", 1, 1, 0, "ldi0_volt_hold" },
	{ SEPLAT_VOLT_HOLD, "seplat_volt_hold", "peri_volt_hold", 1, 1, 0, "seplat_volt_hold" },
	{ CLK_GATE_VDEC, "clk_vdec", "clk_sys_ini", 1, 1, 0, "clk_vdec" },
	{ DIV_USB1_MCU, "div_usb1_mcu", "clk_gt_usb1_mcu", 1, 7, 0, "div_usb1_mcu" },
};

static const struct gate_clock crgctrl_gate_clks[] = {
	{ CLK_GATE_PPLL0_MEDIA, "clk_ppll0_media", "clk_spll", 0, 0x0, ALWAYS_ON,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ppll0_media" },
	{ CLK_GATE_PPLL1_MEDIA, "clk_ppll1_media", "clk_ap_ppll1", 0, 0x0, ALWAYS_ON,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ppll1_media" },
	{ CLK_GATE_PPLL2_MEDIA, "clk_ppll2_media", "clk_ap_ppll2", 0, 0x0, ALWAYS_ON,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ppll2_media" },
	{ CLK_GATE_PPLL2B_MEDIA, "clk_ppll2b_media", "clk_ap_ppll2_b", 0, 0x0, ALWAYS_ON,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ppll2b_media" },
	{ CLK_GATE_FLL_MEDIA, "clk_fll_media", "clk_fll_src", 0, 0x0, ALWAYS_ON,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_fll_media" },
	{ CLK_GATE_PPLL0_M2, "clk_ppll0_m2", "clk_spll", 0, 0x0, ALWAYS_ON,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ppll0_m2" },
	{ CLK_GATE_PPLL1_M2, "clk_ppll1_m2", "clk_ap_ppll1", 0, 0x0, ALWAYS_ON,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ppll1_m2" },
	{ CLK_GATE_PPLL2_M2, "clk_ppll2_m2", "clk_ap_ppll2", 0, 0x0, ALWAYS_ON,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ppll2_m2" },
	{ CLK_GATE_PPLL2B_M2, "clk_ppll2b_m2", "clk_ap_ppll2_b", 0, 0x0, ALWAYS_ON,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ppll2b_m2" },
	{ CLK_GATE_PPLL6_M2, "clk_ppll6_m2", "clk_ap_ppll6", 0, 0x0, ALWAYS_ON,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ppll6_m2" },
	{ CLK_GATE_FLL_M2, "clk_fll_m2", "clk_fll_src", 0, 0x0, ALWAYS_ON,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_fll_m2" },
	{ PCLK_GATE_WD0, "pclk_wd0", "clkin_ref", 0, 0x0, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_wd0" },
	{ CLK_GATE_CODECSSI, "clk_codecssi", "sel_codeccssi", 0x020, 0x4000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_codecssi" },
	{ PCLK_GATE_CODECSSI, "pclk_codecssi", "div_sysbus_pll", 0x020, 0x4000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_codecssi" },
	{ CLK_GATE_HSDT1_USBDP, "clk_hsdt1_usbdp", "div_hsdt1_usbdp", 0x040, 0x2, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_hsdt1_usbdp" },
	{ CLK_ATDVFS, "clk_atdvfs", "clk_cssys_div", 0, 0x0, 0,
		NULL, 1, { 0, 0, 0, 0}, { 0, 1, 2, 3, 4}, 4, 1, 0, "clk_atdvfs" },
	{ CLK_GATE_TIME_STAMP, "clk_time_stamp", "clk_timestp_div", 0x000, 0x200000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_time_stamp" },
	{ ACLK_GATE_PERF_STAT, "aclk_perf_stat", "div_sysbus_pll", 0x040, 0x400, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "aclk_perf_stat" },
	{ PCLK_GATE_PERF_STAT, "pclk_perf_stat", "div_sysbus_pll", 0x040, 0x200, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_perf_stat" },
	{ CLK_GATE_PERF_STAT, "clk_perf_stat", "clk_perf_div", 0x040, 0x100, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_perf_stat" },
	{ CLK_GATE_PERF_CTRL, "clk_perf_ctrl", "sc_div_320m", 0x040, 0x800, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_perf_ctrl" },
	{ CLK_GATE_DMAC, "clk_dmac", "div_sysbus_pll", 0x030, 0x2, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_dmac" },
	{ CLK_GATE_SD_PERI, "clk_sd_peri", "clk_div_sd_peri", 0x020, 0x200000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_sd_peri" },
	{ CLK_GATE_UART4, "clk_uart4", "clkmux_uarth", 0x020, 0x4000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_uart4" },
	{ PCLK_GATE_UART4, "pclk_uart4", "clkmux_uarth", 0x020, 0x4000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_uart4" },
	{ CLK_GATE_UART5, "clk_uart5", "clkmux_uartl", 0x020, 0x8000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_uart5" },
	{ PCLK_GATE_UART5, "pclk_uart5", "clkmux_uartl", 0x020, 0x8000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_uart5" },
	{ CLK_GATE_UART0, "clk_uart0", "clkmux_uart0", 0x020, 0x400, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_uart0" },
	{ CLK_GATE_UART8, "clk_uart8", "clkmux_uart8", 0x020, 0x800, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_uart8" },
	{ PCLK_GATE_UART8, "pclk_uart8", "clkmux_uart8", 0x020, 0x800, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_uart8" },
	{ CLK_GATE_I2C2_ACPU, "clk_i2c2_acpu", "clkmux_i2c", 0x020, 0x2, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_i2c2_acpu" },
	{ CLK_GATE_I2C3, "clk_i2c3", "clkmux_i2c", 0x020, 0x80, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_i2c3" },
	{ CLK_GATE_I2C4, "clk_i2c4", "clkmux_i2c", 0x020, 0x8000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_i2c4" },
	{ CLK_GATE_I2C6_ACPU, "clk_i2c6_acpu", "clkmux_i2c", 0x010, 0x40000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_i2c6_acpu" },
	{ CLK_GATE_I2C7, "clk_i2c7", "clkmux_i2c", 0x010, 0x80000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_i2c7" },
	{ PCLK_GATE_I2C2, "pclk_i2c2", "clkmux_i2c", 0x020, 0x2, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_i2c2" },
	{ PCLK_GATE_I2C3, "pclk_i2c3", "clkmux_i2c", 0x020, 0x80, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_i2c3" },
	{ PCLK_GATE_I2C4, "pclk_i2c4", "clkmux_i2c", 0x020, 0x8000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_i2c4" },
	{ PCLK_GATE_I2C6_ACPU, "pclk_i2c6_acpu", "clkmux_i2c", 0x010, 0x40000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_i2c6_acpu" },
	{ PCLK_GATE_I2C7, "pclk_i2c7", "clkmux_i2c", 0x010, 0x80000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_i2c7" },
	{ CLK_GATE_I3C4, "clk_i3c4", "clkdiv_i3c4", 0x470, 0x1, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_i3c4" },
	{ PCLK_GATE_I3C4, "pclk_i3c4", "clkdiv_i3c4", 0x470, 0x1, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_i3c4" },
	{ CLK_GATE_SPI1, "clk_spi1", "clkmux_spi1", 0x020, 0x200, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_spi1" },
	{ PCLK_GATE_SPI1, "pclk_spi1", "clkmux_spi1", 0x020, 0x200, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_spi1" },
	{ CLK_GATE_SPI6, "clk_spi6", "clkmux_spi6", 0xE10, 0x20000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_spi6" },
	{ PCLK_GATE_SPI6, "pclk_spi6", "clkmux_spi6", 0xE10, 0x20000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_spi6" },
	{ CLK_GATE_AO_ASP, "clk_ao_asp", "clk_ao_asp_div", 0x000, 0x4000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ao_asp" },
	{ PCLK_GATE_PCTRL, "pclk_pctrl", "div_sysbus_pll", 0x020, 0x80000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_pctrl" },
	{ CLK_GATE_BLPWM1, "clk_blpwm1", "clk_ptp_div", 0x020, 0x1, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_blpwm1" },
	{ PERI_VOLT_NO_AVS_L, "peri_volt_no_avs_l", "clk_sys_ini", 0, 0x0, 0,
		NULL, 1, {0}, {0}, 0, 2, 0, "peri_volt_no_avs_l" },
	{ PERI_VOLT_HOLD, "peri_volt_hold", "clk_sys_ini", 0, 0x0, 0,
		NULL, 1, { 0, 0, 0 }, { 0, 1, 2, 3 }, 3, 3, 0, "peri_volt_hold" },
	{ PERI_VOLT_MIDDLE, "peri_volt_middle", "clk_sys_ini", 0, 0x0, 0,
		NULL, 1, { 0, 0 }, { 0, 1, 2 }, 2, 4, 0, "peri_volt_middle" },
	{ PERI_VOLT_LOW, "peri_volt_low", "clk_sys_ini", 0, 0x0, 0,
		NULL, 1, {0}, { 0, 1 }, 1, 5, 0, "peri_volt_low" },
	{ CLK_GATE_DPCTRL_16M, "clk_dpctrl_16m", "div_dpctrl16m", 0x470, 0x200000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_dpctrl_16m" },
	{ CLK_GATE_DPCTRL_PIXEL, "dpctrl_pixel", "div_dpctr_pixel", 0x470, 0x400000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "dpctrl_pixel" },
	{ CLK_GATE_RXDPHY_CFG, "clk_rxdphy_cfg", "clk_rxdphy_mux", 0x050, 0x1, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_rxdphy_cfg" },
	{ CLK_GATE_RXDPHY0_CFG, "clk_rxdphy0_cfg", "clk_rxdphy_cfg", 0x050, 0x2, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_rxdphy0_cfg" },
	{ CLK_GATE_RXDPHY1_CFG, "clk_rxdphy1_cfg", "clk_rxdphy_cfg", 0x050, 0x4, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_rxdphy1_cfg" },
	{ CLK_GATE_RXDPHY2_CFG, "clk_rxdphy2_cfg", "clk_rxdphy_cfg", 0x050, 0x8, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_rxdphy2_cfg" },
	{ CLK_GATE_RXDPHY3_CFG, "clk_rxdphy3_cfg", "clk_rxdphy_cfg", 0x050, 0x10, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_rxdphy3_cfg" },
	{ CLK_GATE_RXDPHY4_CFG, "clk_rxdphy4_cfg", "clk_rxdphy_cfg", 0x050, 0x20, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_rxdphy4_cfg" },
	{ CLK_GATE_RXDPHY5_CFG, "clk_rxdphy5_cfg", "clk_rxdphy_cfg", 0x050, 0x40, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_rxdphy5_cfg" },
	{ CLK_GATE_TXDPHY0_CFG, "clk_txdphy0_cfg", "clk_sys_ini", 0x030, 0x10000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_txdphy0_cfg" },
	{ CLK_GATE_TXDPHY0_REF, "clk_txdphy0_ref", "clkin_sys", 0x030, 0x20000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_txdphy0_ref" },
	{ PCLK_GATE_LOADMONITOR, "pclk_loadmonitor", "div_sysbus_pll", 0x020, 0x40, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_loadmonitor" },
	{ CLK_GATE_LOADMONITOR, "clk_loadmonitor", "clk_loadmonitor_div", 0x020, 0x20, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_loadmonitor" },
	{ PCLK_GATE_LOADMONITOR_L, "pclk_loadmonitor_l", "div_sysbus_pll", 0x020, 0x20000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_loadmonitor_l" },
	{ CLK_GATE_LOADMONITOR_L, "clk_loadmonitor_l", "clk_loadmonitor_div", 0x020, 0x10000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_loadmonitor_l" },
	{ CLK_GATE_MEDIA2_TCXO, "clk_media2_tcxo", "clk_sys_ini", 0x050, 0x40000000, ALWAYS_ON,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_media2_tcxo" },
	{ CLK_GATE_MDM_100M, "clk_mdm_100m", "clk_div_mdm_100m", 0, 0x0, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_mdm_100m" },
	{ CLK_GATE_SDCU, "clk_sdcu", "clk_div_sdcu", 0, 0x0, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_sdcu" },
	{ CLK_GATE_ONEWIRE, "clk_onewire", "clk_div_onewire", 0x000, 0x1, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_onewire" },
	{ CLK_UFS_DFA_CPU, "clk_ufs_dfa_cpu", "div_ufs_dfa_cpu", 0x000, 0x800000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ufs_dfa_cpu" },
	{ CLK_UFS_DFA_SYS, "clk_ufs_dfa_sys", "div_ufs_dfa_sys", 0x000, 0x400000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ufs_dfa_sys" },
};

static const struct fsm_pll_clock fsm_pll_clks[] = {
	{ CLK_GATE_PPLL1, "clk_ap_ppll1", "clk_ppll1", 0x1,
		{ 0x950, 0 }, { 0x958, 0 }, "clk_ap_ppll1" },
	{ CLK_GATE_PPLL2, "clk_ap_ppll2", "clk_ppll2", 0x2,
		{ 0x950, 5 }, { 0x958, 1 }, "clk_ap_ppll2" },
	{ CLK_GATE_PPLL2_B, "clk_ap_ppll2_b", "clk_ppll2_b", 0x9,
		{ 0x954, 5 }, { 0x958, 2 }, "clk_ap_ppll2_b" },
	{ CLK_GATE_PPLL6, "clk_ap_ppll6", "clk_ppll6", 0x6,
		{ 0x954, 10 }, { 0x958, 5 }, "clk_ap_ppll6" },
	{ CLK_GATE_PPLL7, "clk_ap_ppll7", "clk_ppll7", 0x7,
		{ 0x954, 0 }, { 0x958, 4 }, "clk_ap_ppll7" },
};

static const struct fsm_pll_clock aocrg_fsm_pll_clks[] = {
	{ CLK_GATE_AUPLL, "clk_ap_aupll", "clk_aupll", 0xC,
		{ 0x2B4, 0 }, { 0x358, 10 }, "clk_ap_aupll" },
};

static const struct scgt_clock crgctrl_scgt_clks[] = {
	{ CLK_ANDGT_HSDT1_USBDP, "clk_hsdt1_usbdp_andgt", "clk_fll_src",
		0x70C, 12, CLK_GATE_HIWORD_MASK, "clk_hsdt1_usbdp_andgt" },
	{ ATCLK_TO_CPU, "clk_at_to_cpu", "clk_atdvfs",
		0xFF0, 9, CLK_GATE_HIWORD_MASK, "clk_at_to_cpu" },
	{ CLK_GATE_TIME_STAMP_GT, "clk_timestp_gt", "clk_sys_ini",
		0x0F0, 1, CLK_GATE_HIWORD_MASK | CLK_GATE_ALWAYS_ON_MASK, "clk_timestp_gt" },
	{ CLK_PERF_DIV_GT, "clk_perf_gt", "sc_div_320m",
		0x0F0, 3, CLK_GATE_HIWORD_MASK, "clk_perf_gt" },
	{ CLK_ANDGT_SD_PERI, "clkgt_sd_peri", "clk_ap_ppll2",
		0x70C, 10, CLK_GATE_HIWORD_MASK, "clkgt_sd_peri" },
	{ CLK_A53HPM_ANDGT, "clk_a53hpm_gt", "clk_a53hpm_mux",
		0x0F4, 7, CLK_GATE_HIWORD_MASK, "clk_a53hpm_gt" },
	{ CLK_320M_PLL_GT, "gt_clk_320m_pll", "clk_spll",
		0x0F8, 10, CLK_GATE_HIWORD_MASK | CLK_GATE_ALWAYS_ON_MASK, "gt_clk_320m_pll" },
	{ CLK_ANDGT_UARTH, "clkgt_uarth", "sc_div_320m",
		0x0F4, 11, CLK_GATE_HIWORD_MASK, "clkgt_uarth" },
	{ CLK_ANDGT_UARTL, "clkgt_uartl", "sc_div_320m",
		0x0F4, 10, CLK_GATE_HIWORD_MASK | CLK_GATE_ALWAYS_ON_MASK, "clkgt_uartl" },
	{ CLK_ANDGT_UART0, "clkgt_uart0", "sc_div_320m",
		0x0F4, 9, CLK_GATE_HIWORD_MASK | CLK_GATE_ALWAYS_ON_MASK, "clkgt_uart0" },
	{ CLK_ANDGT_UART8, "clkgt_uart8", "sc_div_320m",
		0x0F4, 8, CLK_GATE_HIWORD_MASK, "clkgt_uart8" },
	{ CLK_ANDGT_I3C4, "clkgt_i3c4", "sc_div_320m",
		0x70C, 5, CLK_GATE_HIWORD_MASK, "clkgt_i3c4" },
	{ CLK_ANDGT_SPI1, "clkgt_spi1", "sc_div_320m",
		0x0F4, 13, CLK_GATE_HIWORD_MASK, "clkgt_spi1" },
	{ CLK_ANDGT_SPI6, "clkgt_spi6", "sc_div_320m",
		0xB04, 11, CLK_GATE_HIWORD_MASK, "clkgt_spi6" },
	{ CLK_ANDGT_ULPLL_ARB, "clkgt_ulpll_arb", "clk_fll_src",
		0x0FC, 3, CLK_GATE_HIWORD_MASK, "clkgt_ulpll_arb" },
	{ CLK_ANDGT_SPLL_ARB, "clkgt_spll_arb", "sc_div_320m",
		0x0FC, 1, CLK_GATE_HIWORD_MASK, "clkgt_spll_arb" },
	{ CLK_DIV_AO_ASP_GT, "clk_ao_asp_gt", "clkmux_ao_asp",
		0x0F4, 4, CLK_GATE_HIWORD_MASK, "clk_ao_asp_gt" },
	{ CLK_ANDGT_PTP, "clk_ptp_gt", "sc_div_320m",
		0x0F8, 5, CLK_GATE_HIWORD_MASK | CLK_GATE_ALWAYS_ON_MASK, "clk_ptp_gt" },
	{ CLK_GT_DPCTRL_16M, "clk_gt_16m_dp", "clk_mux_16m_dp",
		0x0FC, 12, CLK_GATE_HIWORD_MASK, "clk_gt_16m_dp" },
	{ CLK_ANDGT_DPCTR_PIXEL, "gt_dpctr_pixel", "mux_dpctr_pixel",
		0x0F0, 0, CLK_GATE_HIWORD_MASK, "gt_dpctr_pixel" },
	{ CLKANDGT_RXDPHY_FLL, "clkgt_rxdphy_fll", "clk_fll_src",
		0x0FC, 10, CLK_GATE_HIWORD_MASK, "clkgt_rxdphy_fll" },
	{ CLK_GT_LOADMONITOR, "clk_loadmonitor_gt", "sc_div_320m",
		0x0F0, 5, CLK_GATE_HIWORD_MASK, "clk_loadmonitor_gt" },
	{ CLK_ANDGT_MDM_100M, "clk_gt_mdm_100m", "clk_spll",
		0x104, 2, CLK_GATE_HIWORD_MASK, "clk_gt_mdm_100m" },
	{ CLK_ANDGT_SDCU, "clk_gt_sdcu", "clk_sdcu_mux",
		0x718, 3, CLK_GATE_HIWORD_MASK, "clk_gt_sdcu" },
	{ CLK_ANDGT_ONEWIRE, "clk_gt_onewire", "sc_div_320m",
		0x0C4, 4, CLK_GATE_HIWORD_MASK, "clk_gt_onewire" },
	{ GT_CLK_UFS_DFA_CPU, "gt_clk_ufs_dfa_cpu", "sel_ufs_dfa_cpu",
		0x0F0, 14, CLK_GATE_HIWORD_MASK, "gt_clk_ufs_dfa_cpu" },
	{ GT_CLK_UFS_DFA_SYS, "gt_clk_ufs_dfa_sys", "sel_ufs_dfa_sys",
		0x0F0, 15, CLK_GATE_HIWORD_MASK, "gt_clk_ufs_dfa_sys" },
	{ CLK_ANDGT_USB1_MCU, "clk_gt_usb1_mcu", "clk_spll",
		0x0FC, 0, CLK_GATE_HIWORD_MASK, "clk_gt_usb1_mcu" },
	{ AUTODIV_SYSBUS, "autodiv_sysbus", "div_sysbus_pll",
		0xF90, 5, CLK_GATE_HIWORD_MASK, "autodiv_sysbus" },
	{ AUTODIV_HSDT1BUS, "autodiv_hsdt1bus", "autodiv_sysbus",
		0xF90, 1, CLK_GATE_HIWORD_MASK, "autodiv_hsdt1bus" },
	{ AUTODIV_CFGBUS, "autodiv_cfgbus", "autodiv_sysbus",
		0xF90, 4, CLK_GATE_HIWORD_MASK, "autodiv_cfgbus" },
};

static const struct div_clock crgctrl_div_clks[] = {
	{ CLK_DIV_HSDT1_USBDP, "div_hsdt1_usbdp", "clk_hsdt1_usbdp_andgt",
		0x710, 0x300, 4, 1, 0, "div_hsdt1_usbdp" },
	{ PCLK_DIV_DBG, "pclkdiv_dbg", "clk_cssys_div",
		0xFF4, 0x6000, 4, 1, 0, "pclkdiv_dbg" },
	{ CLK_DIV_TIME_STAMP, "clk_timestp_div", "clk_timestp_gt",
		0x0B8, 0x70, 8, 1, 0, "clk_timestp_div" },
	{ CLK_DIV_PERF_STAT, "clk_perf_div", "clk_perf_gt",
		0x0D0, 0xf000, 16, 1, 0, "clk_perf_div" },
	{ CLK_DIV_SD_PERI, "clk_div_sd_peri", "clkgt_sd_peri",
		0x700, 0x1e0, 16, 1, 0, "clk_div_sd_peri" },
	{ CLK_DIV_A53HPM, "clk_a53hpm_div", "clk_a53hpm_gt",
		0x0E0, 0xfc00, 64, 1, 0, "clk_a53hpm_div" },
	{ CLK_DIV_UARTH, "clkdiv_uarth", "clkgt_uarth",
		0x0B0, 0xf000, 16, 1, 0, "clkdiv_uarth" },
	{ CLK_DIV_UARTL, "clkdiv_uartl", "clkgt_uartl",
		0x0B0, 0xf00, 16, 1, 0, "clkdiv_uartl" },
	{ CLK_DIV_UART0, "clkdiv_uart0", "clkgt_uart0",
		0x0B0, 0xf0, 16, 1, 0, "clkdiv_uart0" },
	{ CLK_DIV_UART8, "clkdiv_uart8", "clkgt_uart8",
		0x0B0, 0xf, 16, 1, 0, "clkdiv_uart8" },
	{ CLK_DIV_I2C, "clkdiv_i2c", "sc_div_320m",
		0x0E8, 0xf0, 16, 1, 0, "clkdiv_i2c" },
	{ CLK_DIV_I3C4, "clkdiv_i3c4", "clkgt_i3c4",
		0x710, 0xc00, 4, 1, 0, "clkdiv_i3c4" },
	{ CLK_DIV_SPI1, "clkdiv_spi1", "clkgt_spi1",
		0x0C4, 0xf000, 16, 1, 0, "clkdiv_spi1" },
	{ CLK_DIV_SPI6, "clkdiv_spi6", "clkgt_spi6",
		0xB0C, 0xf0, 16, 1, 0, "clkdiv_spi6" },
	{ CLK_DIV_ULPLL_ARB, "clkdiv_ulpll_arb", "clkgt_ulpll_arb",
		0x0FC, 0x1f0, 32, 1, 0, "clkdiv_ulpll_arb" },
	{ CLK_DIV_SPLL_ARB, "clkdiv_spll_arb", "clkgt_spll_arb",
		0x100, 0xf800, 32, 1, 0, "clkdiv_spll_arb" },
	{ CLK_DIV_AO_ASP, "clk_ao_asp_div", "clk_ao_asp_gt",
		0x108, 0x3c0, 16, 1, 0, "clk_ao_asp_div" },
	{ CLK_DIV_DPCTRL_16M, "div_dpctrl16m", "clk_gt_16m_dp",
		0x0B4, 0xfc0, 64, 1, 0, "div_dpctrl16m" },
	{ CLK_DIV_DPCTR_PIXEL, "div_dpctr_pixel", "gt_dpctr_pixel",
		0x0C0, 0x3f00, 64, 1, 0, "div_dpctr_pixel" },
	{ CLK_RXDPHY_FLL_DIV, "div_rxdphy_fll", "clkgt_rxdphy_fll",
		0x0DC, 0x3, 4, 1, 0, "div_rxdphy_fll" },
	{ CLK_DIV_LOADMONITOR, "clk_loadmonitor_div", "clk_loadmonitor_gt",
		0x0B8, 0xc000, 4, 1, 0, "clk_loadmonitor_div" },
	{ CLK_DIV_MDM_100M, "clk_div_mdm_100m", "clk_gt_mdm_100m",
		0x104, 0x1f8, 64, 1, 0, "clk_div_mdm_100m" },
	{ CLK_DIV_SDCU, "clk_div_sdcu", "clk_gt_sdcu",
		0x718, 0x6, 4, 1, 0, "clk_div_sdcu" },
	{ CLK_DIV_ONEWIRE, "clk_div_onewire", "clk_gt_onewire",
		0x0C4, 0xf, 16, 1, 0, "clk_div_onewire" },
	{ DIV_UFS_DFA_CPU, "div_ufs_dfa_cpu", "gt_clk_ufs_dfa_cpu",
		0x0A8, 0x3f, 64, 1, 0, "div_ufs_dfa_cpu" },
	{ DIV_UFS_DFA_SYS, "div_ufs_dfa_sys", "gt_clk_ufs_dfa_sys",
		0x0A8, 0xfc0, 64, 1, 0, "div_ufs_dfa_sys" },
};

static const char * const codeccssi_mux_p [] = { "clk_sys_ini", "clk_sys_ini" };
static const char * const clk_mux_a53hpm_p [] = { "clk_spll", "clk_ap_ppll1" };
static const char * const clk_mux_uarth_p [] = { "clk_sys_ini", "clkdiv_uarth" };
static const char * const clk_mux_uartl_p [] = { "clk_sys_ini", "clkdiv_uartl" };
static const char * const clk_mux_uart0_p [] = { "clk_sys_ini", "clkdiv_uart0" };
static const char * const clk_mux_uart8_p [] = { "clk_sys_ini", "clkdiv_uart8" };
static const char * const clk_mux_i2c_p [] = { "clk_sys_ini", "clkdiv_i2c" };
static const char * const clk_mux_spi1_p [] = { "clk_sys_ini", "clkdiv_spi1" };
static const char * const clk_mux_spi6_p [] = { "clk_sys_ini", "clkdiv_spi6" };
static const char * const clk_mux_usb1_arb_p [] = { "clkdiv_ulpll_arb", "clkdiv_spll_arb" };
static const char * const clk_mux_ao_asp_p [] = { "clk_ap_ppll1", "clk_ap_ppll2_b", "clk_invalid", "clk_invalid" };
static const char * const clk_mux_dpctrl_16m_p [] = { "clk_fll_src", "clk_a53hpm_div" };
static const char * const clk_mux_dpctr_pixel_p [] = { "clk_spll", "clk_ap_ppll1", "clk_ap_ppll7", "clk_ap_ppll7" };
static const char * const clk_mux_rxdphy_cfg_p [] = { "clk_a53hpm_div", "clk_a53hpm_div", "clk_sys_ini", "div_rxdphy_fll" };
static const char * const clk_mux_sdcu_p [] = { "clk_ap_ppll2", "clk_spll" };
static const char * const sel_ufs_dfa_cpu_p [] = {
		"clk_invalid", "clk_ap_ppll7", "clk_spll", "clk_invalid",
		"clk_ap_ppll2_b", "clk_invalid", "clk_invalid", "clk_invalid",
		"clk_ap_ppll2", "clk_invalid", "clk_invalid", "clk_invalid",
		"clk_invalid", "clk_invalid", "clk_invalid", "clk_invalid"
};
static const char * const sel_ufs_dfa_sys_p [] = { "clk_ap_ppll1", "clk_spll", "clk_ap_ppll2", "clk_ap_ppll2" };
static const struct mux_clock crgctrl_mux_clks[] = {
	{ CODECCSSI_MUX, "sel_codeccssi", codeccssi_mux_p,
		ARRAY_SIZE(codeccssi_mux_p), 0x0AC, 0x80, CLK_MUX_HIWORD_MASK, "sel_codeccssi" },
	{ CLK_MUX_A53HPM, "clk_a53hpm_mux", clk_mux_a53hpm_p,
		ARRAY_SIZE(clk_mux_a53hpm_p), 0x0D4, 0x200, CLK_MUX_HIWORD_MASK, "clk_a53hpm_mux" },
	{ CLK_MUX_UARTH, "clkmux_uarth", clk_mux_uarth_p,
		ARRAY_SIZE(clk_mux_uarth_p), 0x0AC, 0x10, CLK_MUX_HIWORD_MASK, "clkmux_uarth" },
	{ CLK_MUX_UARTL, "clkmux_uartl", clk_mux_uartl_p,
		ARRAY_SIZE(clk_mux_uartl_p), 0x0AC, 0x8, CLK_MUX_HIWORD_MASK, "clkmux_uartl" },
	{ CLK_MUX_UART0, "clkmux_uart0", clk_mux_uart0_p,
		ARRAY_SIZE(clk_mux_uart0_p), 0x0AC, 0x4, CLK_MUX_HIWORD_MASK, "clkmux_uart0" },
	{ CLK_MUX_UART8, "clkmux_uart8", clk_mux_uart8_p,
		ARRAY_SIZE(clk_mux_uart8_p), 0x0AC, 0x20, CLK_MUX_HIWORD_MASK, "clkmux_uart8" },
	{ CLK_MUX_I2C, "clkmux_i2c", clk_mux_i2c_p,
		ARRAY_SIZE(clk_mux_i2c_p), 0x0AC, 0x2000, CLK_MUX_HIWORD_MASK, "clkmux_i2c" },
	{ CLK_MUX_SPI1, "clkmux_spi1", clk_mux_spi1_p,
		ARRAY_SIZE(clk_mux_spi1_p), 0x0AC, 0x100, CLK_MUX_HIWORD_MASK, "clkmux_spi1" },
	{ CLK_MUX_SPI6, "clkmux_spi6", clk_mux_spi6_p,
		ARRAY_SIZE(clk_mux_spi6_p), 0xB0C, 0x8000, CLK_MUX_HIWORD_MASK, "clkmux_spi6" },
	{ CLK_MUX_USB1_ARB, "clk_mux_usb1_arb", clk_mux_usb1_arb_p,
		ARRAY_SIZE(clk_mux_usb1_arb_p), 0x100, 0x400, CLK_MUX_HIWORD_MASK, "clk_mux_usb1_arb" },
	{ CLK_MUX_AO_ASP, "clkmux_ao_asp", clk_mux_ao_asp_p,
		ARRAY_SIZE(clk_mux_ao_asp_p), 0x100, 0x30, CLK_MUX_HIWORD_MASK, "clkmux_ao_asp" },
	{ CLK_MUX_DPCTRL_16M, "clk_mux_16m_dp", clk_mux_dpctrl_16m_p,
		ARRAY_SIZE(clk_mux_dpctrl_16m_p), 0x0B4, 0x1000, CLK_MUX_HIWORD_MASK, "clk_mux_16m_dp" },
	{ CLK_MUX_DPCTR_PIXEL, "mux_dpctr_pixel", clk_mux_dpctr_pixel_p,
		ARRAY_SIZE(clk_mux_dpctr_pixel_p), 0x0C0, 0xc000, CLK_MUX_HIWORD_MASK, "mux_dpctr_pixel" },
	{ CLK_MUX_RXDPHY_CFG, "clk_rxdphy_mux", clk_mux_rxdphy_cfg_p,
		ARRAY_SIZE(clk_mux_rxdphy_cfg_p), 0x0DC, 0xc, CLK_MUX_HIWORD_MASK, "clk_rxdphy_mux" },
	{ CLK_MUX_SDCU, "clk_sdcu_mux", clk_mux_sdcu_p,
		ARRAY_SIZE(clk_mux_sdcu_p), 0x718, 0x1, CLK_MUX_HIWORD_MASK, "clk_sdcu_mux" },
	{ SEL_UFS_DFA_CPU, "sel_ufs_dfa_cpu", sel_ufs_dfa_cpu_p,
		ARRAY_SIZE(sel_ufs_dfa_cpu_p), 0x0BC, 0xf000, CLK_MUX_HIWORD_MASK, "sel_ufs_dfa_cpu" },
	{ SEL_UFS_DFA_SYS, "sel_ufs_dfa_sys", sel_ufs_dfa_sys_p,
		ARRAY_SIZE(sel_ufs_dfa_sys_p), 0x0BC, 0xc00, CLK_MUX_HIWORD_MASK, "sel_ufs_dfa_sys" },
};

static const struct div_clock hsdtctrl_div_clks[] = {
	{ DIV_UFS_PHY_HSDT, "div_ufs_phy_hsdt", "clk_ufs_mphy",
		0x0A8, 0xf00, 16, 1, 0, "div_ufs_phy_hsdt" },
};

static const struct pll_clock hsdtcrg_pll_clks[] = {
	{ CLK_GATE_PCIE0PLL, "clk_ap_pcie0pll", "clk_ppll_pcie", 0xD,
		{ 0x190, 0 }, { 0, 0 }, { 0x190, 1 }, { 0x204, 4 }, 10, 1, "clk_ap_pcie0pll" },
};

static const struct gate_clock hsdtctrl_gate_clks[] = {
	{ CLK_GATE_PCIEPHY_REF, "clk_pciephy_ref", "clk_ap_pcie0pll", 0x010, 0x40, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_pciephy_ref" },
	{ CLK_GATE_PCIE1PHY_REF, "clk_pcie1phy_ref", "clk_ap_pcie0pll", 0x000, 0x10, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_pcie1phy_ref" },
	{ PCLK_GATE_PCIE_SYS, "pclk_pcie_sys", "clk_ptp_div", 0x010, 0x10, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_pcie_sys" },
	{ PCLK_GATE_PCIE1_SYS, "pclk_pcie1_sys", "clk_ptp_div", 0x000, 0x200, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_pcie1_sys" },
	{ PCLK_GATE_PCIE_PHY, "pclk_pcie_phy", "clk_ptp_div", 0x010, 0x8, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_pcie_phy" },
	{ PCLK_GATE_PCIE1_PHY, "pclk_pcie1_phy", "clk_ptp_div", 0x000, 0x100, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_pcie1_phy" },
	{ ACLK_GATE_PCIE, "aclk_pcie", "clk_hsdt_subsys_ini", 0x010, 0x20, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "aclk_pcie" },
	{ CLK_GATE_HSDT_TCU, "clk_hsdt_tcu", "clk_hsdt_subsys_ini", 0x010, 0x400, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_hsdt_tcu" },
	{ CLK_GATE_HSDT_TBU, "clk_hsdt_tbu", "clk_hsdt_subsys_ini", 0x010, 0x800, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_hsdt_tbu" },
	{ CLK_GATE_PCIE1_TBU, "clk_pcie1_tbu", "clk_hsdt_subsys_ini", 0x000, 0x2000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_pcie1_tbu" },
	{ ACLK_GATE_PCIE1, "aclk_pcie1", "clk_hsdt_subsys_ini", 0x000, 0x400, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "aclk_pcie1" },
	{ CLK_UFS_DFAHSDT, "clk_ufs_dfahsdt", "clk_ufs_dfa_sys", 0x000, 0x10000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ufs_dfahsdt" },
	{ CLK_UFS_PHY_HSDT, "clk_ufs_phy_hsdt", "div_ufs_phy_hsdt", 0x000, 0x2, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ufs_phy_hsdt" },
};

static const struct div_clock hsdt1ctrl_div_clks[] = {
	{ CLK_DIV_SDPLL, "clkdiv_sdpll", "clkgt_sdpll",
		0x0AC, 0x1e, 16, 1, 0, "clkdiv_sdpll" },
};

static const struct pll_clock hsdt1crg_pll_clks[] = {
	{ CLK_GATE_SDPLL, "clk_ap_sdpll", "clk_sdpll", 0xF,
		{ 0x200, 0 }, { 0x204, 26 }, { 0x200, 1 }, { 0x208, 4 }, 12, 1, "clk_ap_sdpll" },
};

static const char * const clk_mux_sd_sys_p [] = { "clk_div_sd", "clk_sd_peri", "clkdiv_sdpll", "clkdiv_sdpll" };
static const struct mux_clock hsdt1ctrl_mux_clks[] = {
	{ CLK_MUX_SD_SYS, "clk_sd_muxsys", clk_mux_sd_sys_p,
		ARRAY_SIZE(clk_mux_sd_sys_p), 0x0AC, 0x60, CLK_MUX_HIWORD_MASK, "clk_sd_muxsys" },
};

static const struct gate_clock hsdt1ctrl_gate_clks[] = {
	{ CLK_GATE_SD_32K, "clk_sd_32k", "clkin_ref", 0x010, 0x800000, 0,
		NULL, 0, {0}, {0}, 0, 0, 1, "clk_sd_32k" },
	{ CLK_GATE_SDPLL_TP, "clk_sdpll_tp", "clk_sd_muxsys", 0x010, 0x400000, 0,
		NULL, 0, {0}, {0}, 0, 0, 1, "clk_sdpll_tp" },
	{ CLK_GATE_SD, "clk_sd", "clk_sd_muxsys", 0x010, 0x200000, 0,
		NULL, 0, {0}, {0}, 0, 0, 1, "clk_sd" },
	{ HCLK_GATE_SD, "hclk_sd", "clk_qic_hsdt1bus", 0x000, 0x1, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "hclk_sd" },
	{ CLK_GATE_USB31PHY_APB, "usb31phy_apb", "clk_mux_usb1_arb", 0x000, 0x4000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "usb31phy_apb" },
	{ CLK_GATE_HI_USB3_SUSPEND, "hi_usb3_suspend", "clk_abb_192", 0x000, 0x4000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "hi_usb3_suspend" },
	{ CLK_GATE_HI_USB3_SYS, "clk_hi_usb3_sys", "clk_hsdt1_usbdp", 0x000, 0x8000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_hi_usb3_sys" },
	{ ACLK_GATE_HI_USB3, "aclk_hi_usb3", "clk_hsdt1_usbdp", 0x000, 0x1000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "aclk_hi_usb3" },
	{ PCLK_GATE_USB2PHY, "pclk_usb2phy", "clk_mux_usb1_arb", 0x000, 0x4, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_usb2phy" },
	{ CLK_GATE_HI_USB3CTRL_REF, "hi_usb3crtl", "clkdiv_usb2phy_ref", 0x000, 0x200, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "hi_usb3crtl" },
	{ PCLK_GATE_USB_SCTRL, "pclk_usb_sctrl", "clkdiv_usb2phy_ref", 0x000, 0x20000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_usb_sctrl" },
	{ CLK_GATE_USB2PHY_REF, "clk_usb2phy_ref", "clkdiv_usb2phy_ref", 0x000, 0x40000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_usb2phy_ref" },
	{ CLK_GATE_USBDP_AUX, "clk_usbdp_aux", "clk_abb_192", 0x000, 0x800000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_usbdp_aux" },
	{ CLK_GATE_QIC_USB3, "clk_qic_usb3", "clk_hsdt1_usbdp", 0x000, 0x800, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_qic_usb3" },
	{ CLK_GATE_QIC_H1_APB, "clk_qic_h1_apb", "clk_ptp_div", 0, 0x0, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_qic_h1_apb" },
	{ CLK_GATE_USB3PHY_REF, "clk_usb3phy_ref", "clk_abb_192", 0, 0x0, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_usb3phy_ref" },
	{ CLK_GATE_UFS1PHY_REF, "clk_ufs1phy_ref", "clk_abb_192", 0, 0x0, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ufs1phy_ref" },
	{ PCLK_GATE_DPCTRL, "pclk_dpctrl", "clkdiv_usb2phy_ref", 0x000, 0x8, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_dpctrl" },
	{ CLK_UCE_HSDT1BUS, "clk_uce_hsdt1bus", "clk_qic_hsdt1bus", 0x000, 0x10000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_uce_hsdt1bus" },
	{ CLK_HSDT1_UCE_BUS, "clk_hsdt1_uce_bus", "div_usb1_mcu", 0x010, 0x10000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_hsdt1_uce_bus" },
	{ CLK_HSDT1_UCE, "clk_hsdt1_uce", "div_usb1_mcu", 0x010, 0x80000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_hsdt1_uce" },
	{ HCLK_HSDT1_UCE, "hclk_hsdt1_uce", "clk_mux_usb1_arb", 0x010, 0x4000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "hclk_hsdt1_uce" },
	{ PCLK_HSDT1_UCE, "pclk_hsdt1_uce", "clk_mux_usb1_arb", 0x010, 0x1000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_hsdt1_uce" },
	{ CLK_HSDT1_UCE32K, "clk_hsdt1_uce32k", "clkin_ref", 0x010, 0x20000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_hsdt1_uce32k" },
	{ CLK_UCE_19P2, "clk_uce_19p2", "clkdiv_usb2phy_ref", 0x010, 0x40000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_uce_19p2" },
	{ PCLK_COMBO_UCE, "pclk_combo_uce", "clkdiv_usb2phy_ref", 0x010, 0x2000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_combo_uce" },
};

static const struct scgt_clock hsdt1ctrl_scgt_clks[] = {
	{ CLK_ANDGT_SDPLL, "clkgt_sdpll", "clk_ap_sdpll",
		0x0B0, 1, CLK_GATE_HIWORD_MASK, "clkgt_sdpll" },
	{ GT_CLK_SD_SYS, "gt_clk_sd_sys", "clkin_sys",
		0x0B0, 0, CLK_GATE_HIWORD_MASK, "gt_clk_sd_sys" },
	{ CLK_ANDGT_USB2PHY_REF, "clkgt_usb2phy_ref", "clk_abb_192",
		0x0A8, 2, CLK_GATE_HIWORD_MASK | CLK_GATE_ALWAYS_ON_MASK, "clkgt_usb2phy_ref" },
};

static const struct div_clock aocrg_div_clks[] = {
	{ CLK_DIV_SPI3_ULPPLL, "div_spi3_ulppll", "gt_spi3_ulppll",
		0x2AC, 0xf, 16, 1, 0, "div_spi3_ulppll" },
	{ CLK_DIV_SPI3, "clkdiv_spi3", "clkgt_spi3",
		0x2A8, 0x1f80, 64, 1, 0, "clkdiv_spi3" },
	{ CLK_DIV_SPI5_ULPPLL, "div_spi5_ulppll", "gt_spi5_ulppll",
		0x2A4, 0xf00, 16, 1, 0, "div_spi5_ulppll" },
	{ CLK_DIV_SPI5, "clkdiv_spi5", "clkgt_spi5",
		0x2A4, 0xfc, 64, 1, 0, "clkdiv_spi5" },
	{ CLK_DIV_SPI11_ULPPLL, "div_spi11_ulppll", "gt_spi11_ulppll",
		0x2C8, 0x3f, 16, 1, 0, "div_spi11_ulppll" },
	{ CLK_DIV_SPI11, "clkdiv_spi11", "clkgt_spi11",
		0x2C4, 0x7e0, 64, 1, 0, "clkdiv_spi11" },
	{ CLK_DIV_32KPLL_PCIEAUX, "div_32kpll_pcieaux", "clkgt_32kpll_pcieaux",
		0x298, 0x3f0, 64, 1, 0, "div_32kpll_pcieaux" },
	{ CLK_DIV_BLPWM2, "clkdiv_blpwm2", "clkgt_blpwm2",
		0x2A8, 0x60, 4, 1, 0, "clkdiv_blpwm2" },
	{ CLK_DIV_BLPWM0, "clkdiv_blpwm0", "clkgt_blpwm0",
		0x2AC, 0xc00, 4, 1, 0, "clkdiv_blpwm0" },
	{ CLKDIV_ASP_CODEC, "clkdiv_asp_codec", "clkgt_asp_codec",
		0x284, 0x3f, 64, 1, 0, "clkdiv_asp_codec" },
	{ CLKDIV_DP_AUDIO_PLL_AO, "clk_dp_audio_pll_ao_div", "clk_dp_audio_pll_ao_gt",
		0x2A8, 0xf, 16, 1, 0, "clk_dp_audio_pll_ao_div" },
	{ CLK_DIV_AO_CAMERA, "clkdiv_ao_camera", "clkgt_ao_camera",
		0x260, 0x3f, 64, 1, 0, "clkdiv_ao_camera" },
	{ CLK_DIV_AO_TOF, "clkdiv_ao_tof", "clkgt_ao_tof",
		0x25C, 0xfc00, 64, 1, 0, "clkdiv_ao_tof" },
	{ CLK_DIV_AO_CAMERA1, "clkdiv_ao_camera1", "clkgt_ao_camera1",
		0x260, 0xfc00, 64, 1, 0, "clkdiv_ao_camera1" },
	{ CLK_ISP_SNCLK_DIV0, "clk_div_ispsn0", "clk_fac_ispsn",
		0x2BC, 0x3, 4, 1, 0, "clk_div_ispsn0" },
	{ CLK_ISP_SNCLK_DIV1, "clk_div_ispsn1", "clk_fac_ispsn",
		0x2BC, 0xc, 4, 1, 0, "clk_div_ispsn1" },
	{ CLK_ISP_SNCLK_DIV2, "clk_div_ispsn2", "clk_fac_ispsn",
		0x2BC, 0x30, 4, 1, 0, "clk_div_ispsn2" },
	{ CLK_ISP_SNCLK_DIV3, "clk_div_ispsn3", "clk_fac_ispsn",
		0x2BC, 0xc0, 4, 1, 0, "clk_div_ispsn3" },
	{ CLK_ISP_SNCLK_FAC, "clk_fac_ispsn", "clk_ispsn_gt",
		0x2B8, 0x3f00, 32, 1, 0, "clk_fac_ispsn" },
	{ CLK_DIV_AO_LOADMONITOR, "clk_ao_loadmonitor_div", "clk_ao_loadmonitor_gt",
		0x26C, 0x3c00, 16, 1, 0, "clk_ao_loadmonitor_div" },
	{ DIV_UFS_MPHY, "div_ufs_mphy", "clk_gt_ufs_mphy",
		0x264, 0x1e, 16, 1, 0, "div_ufs_mphy" },
	{ CLK_DIV_OUT0, "clkdiv_out0", "clkgt_out0",
		0x284, 0x3c00, 16, 1, 0, "clkdiv_out0" },
};

static const char * const clk_mux_spi3_p [] = { "clkdiv_spi3", "div_spi3_ulppll" };
static const char * const clk_mux_spi5_p [] = { "clkdiv_spi5", "div_spi5_ulppll" };
static const char * const clk_mux_spi11_p [] = { "clkdiv_spi11", "div_spi11_ulppll" };
static const char * const clk_mux_pcieaux_p [] = { "clk_sys_ini", "div_32kpll_pcieaux" };
static const char * const clkmux_syscnt_p [] = { "clk_syscnt_div", "clkin_ref" };
static const char * const clk_mux_asp_pll_p [] = {
		"clk_invalid", "clk_spll", "sel_ao_asp_32kpll", "clk_invalid",
		"clk_ao_asp", "clk_invalid", "clk_invalid", "clk_invalid",
		"clk_sys_ini", "clk_invalid", "clk_invalid", "clk_invalid",
		"clk_invalid", "clk_invalid", "clk_invalid", "clk_invalid"
};
static const char * const clk_ao_asp_32kpll_mux_p [] = { "clk_fll_src", "clk_ulppll_1" };
static const char * const clk_mux_ao_camera_p [] = { "clkin_sys", "clk_fll_src", "div_aobus_334M", "clk_ulppll_1" };
static const char * const clk_mux_ao_tof_p [] = { "clkin_sys", "clk_fll_src", "div_aobus_334M", "clk_ulppll_1" };
static const char * const clk_mux_ao_camera1_p [] = { "clkin_sys", "clk_fll_src", "div_aobus_334M", "clk_ulppll_1" };
static const char * const clk_isp_snclk_mux0_p [] = { "clk_sys_ini", "clk_sys_ini", "clkin_sys", "clk_div_ispsn0" };
static const char * const clk_isp_snclk_mux1_p [] = { "clk_sys_ini", "clk_sys_ini", "clkin_sys", "clk_div_ispsn1" };
static const char * const clk_isp_snclk_mux2_p [] = { "clk_sys_ini", "clk_sys_ini", "clkin_sys", "clk_div_ispsn2" };
static const char * const clk_isp_snclk_mux3_p [] = { "clk_sys_ini", "clk_sys_ini", "clkin_sys", "clk_div_ispsn3" };
static const char * const clk_mux_out0_p [] = { "div_aobus_334M", "clk_fll_src", "clk_invalid", "clk_invalid" };
static const char * const sel_clk_out_ufs_p [] = { "clkin_sys", "clk_sys_ini" };
static const struct mux_clock aocrg_mux_clks[] = {
	{ CLK_MUX_SPI3, "clkmux_spi3", clk_mux_spi3_p,
		ARRAY_SIZE(clk_mux_spi3_p), 0x2A8, 0x8000, CLK_MUX_HIWORD_MASK, "clkmux_spi3" },
	{ CLK_MUX_SPI5, "clkmux_spi5", clk_mux_spi5_p,
		ARRAY_SIZE(clk_mux_spi5_p), 0x2A4, 0x1000, CLK_MUX_HIWORD_MASK, "clkmux_spi5" },
	{ CLK_MUX_SPI11, "clkmux_spi11", clk_mux_spi11_p,
		ARRAY_SIZE(clk_mux_spi11_p), 0x2C4, 0x2, CLK_MUX_HIWORD_MASK, "clkmux_spi11" },
	{ CLK_MUX_PCIEAUX, "clkmux_pcieaux", clk_mux_pcieaux_p,
		ARRAY_SIZE(clk_mux_pcieaux_p), 0x288, 0x4000, CLK_MUX_HIWORD_MASK, "clkmux_pcieaux" },
	{ CLKMUX_SYSCNT, "clkmux_syscnt", clkmux_syscnt_p,
		ARRAY_SIZE(clkmux_syscnt_p), 0x264, 0x2000, CLK_MUX_HIWORD_MASK, "clkmux_syscnt" },
	{ CLK_MUX_ASP_PLL, "clk_asp_pll_sel", clk_mux_asp_pll_p,
		ARRAY_SIZE(clk_mux_asp_pll_p), 0x280, 0xf, CLK_MUX_HIWORD_MASK, "clk_asp_pll_sel" },
	{ CLK_AO_ASP_32KPLL_MUX, "sel_ao_asp_32kpll", clk_ao_asp_32kpll_mux_p,
		ARRAY_SIZE(clk_ao_asp_32kpll_mux_p), 0x250, 0x2000, CLK_MUX_HIWORD_MASK, "sel_ao_asp_32kpll" },
	{ CLK_MUX_AO_CAMERA, "clkmux_ao_camera", clk_mux_ao_camera_p,
		ARRAY_SIZE(clk_mux_ao_camera_p), 0x290, 0x30, CLK_MUX_HIWORD_MASK, "clkmux_ao_camera" },
	{ CLK_MUX_AO_TOF, "clkmux_ao_tof", clk_mux_ao_tof_p,
		ARRAY_SIZE(clk_mux_ao_tof_p), 0x25C, 0x300, CLK_MUX_HIWORD_MASK, "clkmux_ao_tof" },
	{ CLK_MUX_AO_CAMERA1, "clkmux_ao_camera1", clk_mux_ao_camera1_p,
		ARRAY_SIZE(clk_mux_ao_camera1_p), 0x260, 0xc0, CLK_MUX_HIWORD_MASK, "clkmux_ao_camera1" },
	{ CLK_ISP_SNCLK_MUX0, "clk_mux_ispsn0", clk_isp_snclk_mux0_p,
		ARRAY_SIZE(clk_isp_snclk_mux0_p), 0x2B8, 0x3, CLK_MUX_HIWORD_MASK, "clk_mux_ispsn0" },
	{ CLK_ISP_SNCLK_MUX1, "clk_mux_ispsn1", clk_isp_snclk_mux1_p,
		ARRAY_SIZE(clk_isp_snclk_mux1_p), 0x2B8, 0xc, CLK_MUX_HIWORD_MASK, "clk_mux_ispsn1" },
	{ CLK_ISP_SNCLK_MUX2, "clk_mux_ispsn2", clk_isp_snclk_mux2_p,
		ARRAY_SIZE(clk_isp_snclk_mux2_p), 0x2B8, 0x30, CLK_MUX_HIWORD_MASK, "clk_mux_ispsn2" },
	{ CLK_ISP_SNCLK_MUX3, "clk_mux_ispsn3", clk_isp_snclk_mux3_p,
		ARRAY_SIZE(clk_isp_snclk_mux3_p), 0x2B8, 0xc0, CLK_MUX_HIWORD_MASK, "clk_mux_ispsn3" },
	{ CLK_MUX_OUT0, "clkmux_out0", clk_mux_out0_p,
		ARRAY_SIZE(clk_mux_out0_p), 0x284, 0xc0, CLK_MUX_HIWORD_MASK, "clkmux_out0" },
	{ SEL_CLK_OUT_UFS, "sel_clk_out_ufs", sel_clk_out_ufs_p,
		ARRAY_SIZE(sel_clk_out_ufs_p), 0x26C, 0x100, CLK_MUX_HIWORD_MASK, "sel_clk_out_ufs" },
};

static const struct gate_clock aocrg_gate_clks[] = {
	{ CLK_GATE_AUPLL_M2, "clk_aupll_m2", "clk_ap_aupll", 0, 0x0, ALWAYS_ON,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_aupll_m2" },
	{ CLK_GATE_TIMER5, "clk_timer5", "clk_div_timer", 0x170, 0x1000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_timer5" },
	{ CLK_GATE_SPI, "clk_spi3", "clkmux_spi3", 0x1B0, 0x400, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_spi3" },
	{ PCLK_GATE_SPI, "pclk_spi3", "clkmux_spi3", 0x1B0, 0x400, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_spi3" },
	{ CLK_GATE_SPI5, "clk_spi5", "clkmux_spi5", 0x1B0, 0x40, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_spi5" },
	{ PCLK_GATE_SPI5, "pclk_spi5", "clkmux_spi5", 0x1B0, 0x40, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_spi5" },
	{ CLK_GATE_HSDT0_PCIEAUX, "clk_hsdt0_pcie_aux", "clkmux_pcieaux", 0x170, 0x100, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_hsdt0_pcie_aux" },
	{ CLK_GATE_PCIEAUX, "clk_pcie0_aux", "clk_hsdt0_pcie_aux", 0x170, 0x80000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_pcie0_aux" },
	{ CLK_GATE_PCIE1AUX, "clk_pcie1_aux", "clk_hsdt0_pcie_aux", 0x170, 0x100000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_pcie1_aux" },
	{ CLK_GATE_BLPWM2, "clk_blpwm2", "clkdiv_blpwm2", 0x160, 0x10000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_blpwm2" },
	{ CLK_GATE_BLPWM, "clk_blpwm", "clkdiv_blpwm0", 0x160, 0x400, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_blpwm" },
	{ PCLK_GATE_SYSCNT, "pclk_syscnt", "sc_div_aobus", 0x160, 0x80000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_syscnt" },
	{ CLK_GATE_SYSCNT, "clk_syscnt", "clkmux_syscnt", 0x160, 0x100000, ALWAYS_ON,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_syscnt" },
	{ CLK_ASP_CODEC, "clk_asp_codec", "clkdiv_asp_codec", 0x170, 0x8000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_asp_codec" },
	{ CLK_GATE_ASP_SUBSYS, "clk_asp_subsys", "clk_asp_pll_sel", 0x170, 0x10, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_asp_subsys" },
	{ CLK_GATE_ASP_TCXO, "clk_asp_tcxo", "clk_sys_ini", 0x160, 0x8000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_asp_tcxo" },
	{ CLK_GATE_DP_AUDIO_PLL, "clk_dp_audio_pll", "clk_dp_audio_pll_ao_div", 0x1B0, 0x80, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_dp_audio_pll" },
	{ CLK_GATE_AO_CAMERA, "clk_ao_camera", "clkdiv_ao_camera", 0x170, 0x40, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ao_camera" },
	{ CLK_GATE_AO_TOF, "clk_ao_tof", "clkdiv_ao_tof", 0x190, 0x4000000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ao_tof" },
	{ CLK_GATE_AO_CAMERA1, "clk_ao_camera1", "clkdiv_ao_camera1", 0x1D0, 0x2, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ao_camera1" },
	{ CLK_GATE_ISP_SNCLK0, "clk_isp_snclk0", "clk_mux_ispsn0", 0x160, 0x4000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_isp_snclk0" },
	{ CLK_GATE_ISP_SNCLK1, "clk_isp_snclk1", "clk_mux_ispsn1", 0x160, 0x2000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_isp_snclk1" },
	{ CLK_GATE_ISP_SNCLK2, "clk_isp_snclk2", "clk_mux_ispsn2", 0x160, 0x1000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_isp_snclk2" },
	{ CLK_GATE_ISP_SNCLK3, "clk_isp_snclk3", "clk_mux_ispsn3", 0x160, 0x800, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_isp_snclk3" },
	{ PCLK_GATE_AO_LOADMONITOR, "pclk_ao_loadmonitor", "sc_div_aobus", 0x1B0, 0x10, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "pclk_ao_loadmonitor" },
	{ CLK_GATE_AO_LOADMONITOR, "clk_ao_loadmonitor", "clk_ao_loadmonitor_div", 0x1B0, 0x20, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ao_loadmonitor" },
	{ CLK_UFS_MPHY, "clk_ufs_mphy", "div_ufs_mphy", 0x1D0, 0x1, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ufs_mphy" },
	{ CLK_OUT_IO_DIE, "clk_out_io_die", "clk_sys_ini", 0x1D0, 0x80, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_out_io_die" },
	{ CLK_OUT_UFS, "clk_out_ufs", "sel_clk_out_ufs", 0x1D0, 0x40, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_out_ufs" },
};

static const struct scgt_clock aocrg_scgt_clks[] = {
	{ CLK_ANDGT_SPI3_ULPPLL, "gt_spi3_ulppll", "clk_fll_src",
		0x2A8, 13, CLK_GATE_HIWORD_MASK, "gt_spi3_ulppll" },
	{ CLK_ANDGT_SPI3, "clkgt_spi3", "clk_spll",
		0x2A8, 14, CLK_GATE_HIWORD_MASK, "clkgt_spi3" },
	{ CLK_ANDGT_SPI5_ULPPLL, "gt_spi5_ulppll", "clk_fll_src",
		0x2A4, 1, CLK_GATE_HIWORD_MASK, "gt_spi5_ulppll" },
	{ CLK_ANDGT_SPI5, "clkgt_spi5", "clk_spll",
		0x2A4, 0, CLK_GATE_HIWORD_MASK, "clkgt_spi5" },
	{ CLK_ANDGT_SPI11_ULPPLL, "gt_spi11_ulppll", "clk_fll_src",
		0x2C4, 3, CLK_GATE_HIWORD_MASK, "gt_spi11_ulppll" },
	{ CLK_ANDGT_SPI11, "clkgt_spi11", "clk_spll",
		0x2C4, 2, CLK_GATE_HIWORD_MASK, "clkgt_spi11" },
	{ CLK_ANDGT_32KPLL_PCIEAUX, "clkgt_32kpll_pcieaux", "clk_fll_src",
		0x298, 10, CLK_GATE_HIWORD_MASK, "clkgt_32kpll_pcieaux" },
	{ CLK_ANDGT_BLPWM2, "clkgt_blpwm2", "clk_fll_src",
		0x264, 14, CLK_GATE_HIWORD_MASK, "clkgt_blpwm2" },
	{ CLK_ANDGT_BLPWM0, "clkgt_blpwm0", "clk_fll_src",
		0x264, 12, CLK_GATE_HIWORD_MASK, "clkgt_blpwm0" },
	{ CLKGT_ASP_CODEC, "clkgt_asp_codec", "clk_spll",
		0x274, 14, CLK_GATE_HIWORD_MASK | CLK_GATE_ALWAYS_ON_MASK, "clkgt_asp_codec" },
	{ CLKGT_DP_AUDIO_PLL_AO, "clk_dp_audio_pll_ao_gt", "clk_ap_aupll",
		0x294, 14, CLK_GATE_HIWORD_MASK, "clk_dp_audio_pll_ao_gt" },
	{ CLK_ANDGT_AO_CAMERA, "clkgt_ao_camera", "clkmux_ao_camera",
		0x290, 14, CLK_GATE_HIWORD_MASK, "clkgt_ao_camera" },
	{ CLK_ANDGT_AO_TOF, "clkgt_ao_tof", "clkmux_ao_tof",
		0x274, 11, CLK_GATE_HIWORD_MASK, "clkgt_ao_tof" },
	{ CLK_ANDGT_AO_CAMERA1, "clkgt_ao_camera1", "clkmux_ao_camera1",
		0x274, 12, CLK_GATE_HIWORD_MASK, "clkgt_ao_camera1" },
	{ CLK_ISP_SNCLK_ANGT, "clk_ispsn_gt", "div_aobus_334M",
		0x2B8, 14, CLK_GATE_HIWORD_MASK | CLK_GATE_ALWAYS_ON_MASK, "clk_ispsn_gt" },
	{ CLK_GT_AO_LOADMONITOR, "clk_ao_loadmonitor_gt", "clk_fll_src",
		0x26C, 9, CLK_GATE_HIWORD_MASK, "clk_ao_loadmonitor_gt" },
	{ CLK_ANDGT_UFS_MPHY, "clk_gt_ufs_mphy", "clk_spll",
		0x264, 0, CLK_GATE_HIWORD_MASK, "clk_gt_ufs_mphy" },
	{ CLK_ANDGT_OUT0, "clkgt_out0", "clkmux_out0",
		0x284, 8, CLK_GATE_HIWORD_MASK, "clkgt_out0" },
};

static const struct sec_gate_clock aocrg_sec_gate_clks[] = {
	{ CLK_GATE_OUT0, "clk_out0", "clkdiv_out0", { 0x900, 5 }, 0, 0, "clk_out0" },
	{ CLK_GATE_QIC_SPI11, "clk_qic_spi11dma", "clkmux_spi11", { 0x9d0, 1 }, 0, 1, "clk_qic_spi11dma" },
	{ CLK_GATE_SPI11DMA, "clk_spi11dma", "clk_qic_spi11dma", { 0x9d0, 2 }, 0, 2, "clk_spi11dma" },
};

static const struct div_clock media1crg_div_clks[] = {
	{ CLK_DIV_VIVOBUS, "clk_vivobus_div", "clk_vivobus_gt",
		0x06C, 0x3f00, 64, 1, 0, "clk_vivobus_div" },
};

static const char * const clk_mux_vivobus_p [] = {
		"clk_invalid", "clk_ppll2b_media", "clk_ppll0_media", "clk_invalid",
		"clk_ppll1_media", "clk_invalid", "clk_invalid", "clk_invalid",
		"clk_ppll2_media", "clk_invalid", "clk_invalid", "clk_invalid",
		"clk_invalid", "clk_invalid", "clk_invalid", "clk_invalid"
};
static const struct mux_clock media1crg_mux_clks[] = {
	{ CLK_MUX_VIVOBUS, "clk_vivobus_mux", clk_mux_vivobus_p,
		ARRAY_SIZE(clk_mux_vivobus_p), 0x060, 0xf00, CLK_MUX_HIWORD_MASK, "clk_vivobus_mux" },
};

static const struct gate_clock media1crg_gate_clks[] = {
	{ CLK_GATE_VIVOBUS, "clk_vivobus", "clk_spll", 0, 0x0, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_vivobus" },
	{ CLK_GATE_ATDIV_VIVO, "clk_atdiv_vivo", "clk_vivobus_div", 0x010, 0x2, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_atdiv_vivo" },
	{ CLK_GATE_ATDIV_VDEC, "clk_atdiv_vdec", "clk_spll", 0x010, 0x4, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_atdiv_vdec" },
	{ CLK_GATE_ATDIV_VENC, "clk_atdiv_venc", "clk_spll", 0x010, 0x8, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_atdiv_venc" },
	{ CLK_GATE_ATDIV_AAE, "clk_atdiv_aae", "clk_spll", 0x010, 0x4000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_atdiv_aae" },
};

static const struct scgt_clock media1crg_scgt_clks[] = {
	{ CLK_GATE_VIVOBUS_ANDGT, "clk_vivobus_gt", "clk_vivobus_mux",
		0x084, 1, CLK_GATE_HIWORD_MASK | CLK_GATE_ALWAYS_ON_MASK, "clk_vivobus_gt" },
};

static const struct div_clock media2crg_div_clks[] = {
	{ CLK_DIV_VCODECBUS, "clk_vcodbus_div", "clk_vcodbus_gt",
		0x09C, 0x3f, 64, 1, 0, "clk_vcodbus_div" },
	{ CLK_DIV_ISPCPU_PERI_CORE, "clk_ispcpu_peri_core_div", "clk_ispcpu_peri_core_gt",
		0x0B8, 0x3f, 64, 1, 0, "clk_ispcpu_peri_core_div" },
	{ CLK_DIV_ISPCPU_DJTAG, "clk_ispcpu_djtag_div", "clk_ispcpu_djtag_gt",
		0x0B8, 0x3f00, 64, 1, 0, "clk_ispcpu_djtag_div" },
	{ CLK_DIV_ISPCPU_DLDO, "clk_ispcpu_dldo_div", "clk_ispcpu_dldo_gt",
		0x0BC, 0x3f, 64, 1, 0, "clk_ispcpu_dldo_div" },
	{ CLK_DIV_ISP_I3C, "clkdiv_isp_i3c", "clk_ppll0_m2",
		0x0A0, 0x3f00, 64, 1, 0, "clkdiv_isp_i3c" },
};

static const char * const clk_mux_vcodecbus_p [] = {
		"clk_invalid", "clk_ppll2b_m2", "clk_fll_m2", "clk_invalid",
		"clk_ppll0_m2", "clk_invalid", "clk_invalid", "clk_invalid",
		"clk_ppll1_m2", "clk_invalid", "clk_invalid", "clk_invalid",
		"clk_invalid", "clk_invalid", "clk_invalid", "clk_invalid"
};
static const char * const clk_mux_ispcpu_peri_core_p [] = {
		"clk_invalid", "clk_ppll2b_m2", "clk_ppll0_m2", "clk_invalid",
		"clk_ppll1_m2", "clk_invalid", "clk_invalid", "clk_invalid",
		"clk_ppll2_m2", "clk_invalid", "clk_invalid", "clk_invalid",
		"clk_invalid", "clk_invalid", "clk_invalid", "clk_invalid"
};
static const char * const clk_mux_ispcpu_dldo_p [] = {
		"clk_invalid", "clk_ppll2b_m2", "clk_ppll0_m2", "clk_invalid",
		"clk_ppll1_m2", "clk_invalid", "clk_invalid", "clk_invalid",
		"clk_ppll2_m2", "clk_invalid", "clk_invalid", "clk_invalid",
		"clk_invalid", "clk_invalid", "clk_invalid", "clk_invalid"
};
static const struct mux_clock media2crg_mux_clks[] = {
	{ CLK_MUX_VCODECBUS, "clk_vcodbus_mux", clk_mux_vcodecbus_p,
		ARRAY_SIZE(clk_mux_vcodecbus_p), 0x088, 0xf0, CLK_MUX_HIWORD_MASK, "clk_vcodbus_mux" },
	{ CLK_MUX_ISPCPU_PERI_CORE, "sel_ispcpu_peri_core", clk_mux_ispcpu_peri_core_p,
		ARRAY_SIZE(clk_mux_ispcpu_peri_core_p), 0x090, 0xf00, CLK_MUX_HIWORD_MASK, "sel_ispcpu_peri_core" },
	{ CLK_MUX_ISPCPU_DLDO, "sel_ispcpu_dldo", clk_mux_ispcpu_dldo_p,
		ARRAY_SIZE(clk_mux_ispcpu_dldo_p), 0x094, 0xf00, CLK_MUX_HIWORD_MASK, "sel_ispcpu_dldo" },
};

static const struct gate_clock media2crg_gate_clks[] = {
	{ CLK_GATE_VCODECBUS, "clk_vcodecbus", "clk_spll", 0, 0x0, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_vcodecbus" },
	{ CLK_GATE_VCODECBUS2DDR, "clk_vcodecbus2", "clk_vcodbus_div", 0x000, 0x1000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_vcodecbus2" },
	{ CLK_GATE_ISP_SYS, "clk_isp_sys", "clk_media2_tcxo", 0x000, 0x20, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_isp_sys" },
	{ CLK_GATE_ISPCPU_CORE, "clk_ispcpu_core", "clk_ispcpu_peri_core_div", 0x010, 0x4, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ispcpu_core" },
	{ CLK_GATE_ISPCPU_DJTAG, "clk_ispcpu_djtag", "clk_ispcpu_djtag_div", 0x010, 0x8, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ispcpu_djtag" },
	{ CLK_GATE_ISPCPU_DLDO, "clk_ispcpu_dldo", "clk_ispcpu_dldo_div", 0x010, 0x20, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_ispcpu_dldo" },
	{ CLK_GATE_ISP_I3C, "clk_isp_i3c", "clkdiv_isp_i3c", 0x000, 0x2000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_isp_i3c" },
	{ CLK_GATE_AUTODIV_VCODECBUS, "clk_atdiv_vcbus", "clk_vcodbus_div", 0x000, 0x400000, 0,
		NULL, 0, {0}, {0}, 0, 0, 0, "clk_atdiv_vcbus" },
};

static const struct scgt_clock media2crg_scgt_clks[] = {
	{ CLK_GATE_VCODECBUS_GT, "clk_vcodbus_gt", "clk_vcodbus_mux",
		0x0C0, 5, CLK_GATE_HIWORD_MASK | CLK_GATE_ALWAYS_ON_MASK, "clk_vcodbus_gt" },
	{ CLK_ANDGT_ISPCPU_PERI_CORE, "clk_ispcpu_peri_core_gt", "sel_ispcpu_peri_core",
		0x0C4, 4, CLK_GATE_HIWORD_MASK, "clk_ispcpu_peri_core_gt" },
	{ CLK_ANDGT_ISPCPU_DJTAG, "clk_ispcpu_djtag_gt", "clk_ppll0_m2",
		0x0C4, 5, CLK_GATE_HIWORD_MASK, "clk_ispcpu_djtag_gt" },
	{ CLK_ANDGT_ISPCPU_DLDO, "clk_ispcpu_dldo_gt", "sel_ispcpu_dldo",
		0x0C4, 6, CLK_GATE_HIWORD_MASK, "clk_ispcpu_dldo_gt" },
};

static const struct xfreq_clock xfreq_clks[] = {
	{ CLK_CLUSTER0, "cpu-cluster.0", 0, 0, 0, 0x41C, {0x0001030A, 0x0}, {0x0001020A, 0x0}, "cpu-cluster.0" },
	{ CLK_CLUSTER1, "cpu-cluster.1", 1, 0, 0, 0x41C, {0x0002030A, 0x0}, {0x0002020A, 0x0}, "cpu-cluster.1" },
	{ CLK_G3D0, "clk_g3d", 2, 0, 0, 0x41C, { 0x0003030A, 0x0 }, { 0x0003020A, 0x0 }, "clk_g3d" },
	{ CLK_DDRC_FREQ0, "clk_ddrc_freq", 3, 0, 0, 0x41C, { 0x00040309, 0x0 }, { 0x0004020A, 0x0 }, "clk_ddrc_freq" },
	{ CLK_DDRC_MAX0, "clk_ddrc_max", 5, 1, 0x8000, 0x230, { 0x00040308, 0x0 }, { 0x0004020A, 0x0 }, "clk_ddrc_max" },
	{ CLK_DDRC_MIN0, "clk_ddrc_min", 4, 1, 0x8000, 0x270, { 0x00040309, 0x0 }, { 0x0004020A, 0x0 }, "clk_ddrc_min" },
	{ CLK_L1BUS_MIN0, "clk_l1bus_min", 6, 1, 0x8000, 0x250, { 0x00040309, 0x0 }, { 0x0004020A, 0x0 }, "clk_l1bus_min" },
};

static const struct pmu_clock pmu_clks[] = {
	{ CLK_GATE_ABB_192, "clk_abb_192", "clkin_sys", 0x06B, 0, pmu_clk_flag(1, 9), 0, "clk_abb_192" },
	{ CLK_RF0, "clk_rf0", "clkin_sys", 0x06F, 0, INVALID_HWSPINLOCK_ID, 0, "clk_rf0" },
	{ CLK_RF1, "clk_rf1", "clkin_sys", 0x070, 0, INVALID_HWSPINLOCK_ID, 0, "clk_rf1" },
	{ CLK_IODIE, "clk_iodie", "clkin_sys", 0x071, 0, INVALID_HWSPINLOCK_ID, 0, "clk_iodie" },
	{ CLK_PMU32KA, "clk_pmu32ka", "clkin_ref", 0x073, 0, INVALID_HWSPINLOCK_ID, ALWAYS_ON, "clk_pmu32ka" },
	{ CLK_PMU32KB, "clk_pmu32kb", "clkin_ref", 0x074, 0, INVALID_HWSPINLOCK_ID, 0, "clk_pmu32kb" },
	{ CLK_UWB_32K, "clk_uwb_32k", "clkin_ref", 0x075, 0, INVALID_HWSPINLOCK_ID, 0, "clk_uwb_32k" },
	{ CLK_WIFI, "clk_wifi", "clkin_sys", 0x06D, 0, INVALID_HWSPINLOCK_ID, 0, "clk_wifi" },
	{ CLK_NFC, "clk_nfc", "clkin_sys", 0x06E, 0, INVALID_HWSPINLOCK_ID, 0, "clk_nfc" },
	{ CLK_UWB, "clk_uwb", "clkin_sys", 0x072, 0, INVALID_HWSPINLOCK_ID, 0, "clk_uwb" },
};

static const struct dvfs_clock dvfs_clks[] = {
	{ CLK_GATE_MDM_DPA, "clk_mdm_dpa", "clk_dpa_freq", 20, -1, 3, 1,
		{418000, 558000, 640000}, {0, 2, 3, 4}, 640000, 1, "clk_mdm_dpa" },
	{ CLK_GATE_PFA, "clk_pfa", "clk_pfa_freq", 21, -1, 4, 1,
		{239000, 360000, 480000, 558000}, {0, 1, 2, 3, 4}, 558000, 1, "clk_pfa" },
};

static struct media_pll_info ppll0_crgctrl_info = MEDIA_PLL_INFO("clk_spll", 1671168);
static struct media_pll_info ppll1_crgctrl_info = MEDIA_PLL_INFO("clk_ap_ppll1", 1440000);
static struct media_pll_info ppll2_crgctrl_info = MEDIA_PLL_INFO("clk_ap_ppll2", 964000);
static struct media_pll_info ppll2b_crgctrl_info = MEDIA_PLL_INFO("clk_ap_ppll2_b", 1280000);

static struct media_pll_info *dpa_plls[] = {
	&ppll0_crgctrl_info, &ppll1_crgctrl_info, &ppll2b_crgctrl_info, &ppll2_crgctrl_info,
};

static struct media_pll_info *pfa_plls[] = {
	&ppll0_crgctrl_info, &ppll1_crgctrl_info, &ppll2b_crgctrl_info, &ppll2_crgctrl_info,
};

static const struct fast_dvfs_clock fast_dvfs_clks_crgctrl[] = {
	{ CLK_GATE_DPA_FREQ, "clk_dpa_freq", { 0x108, 0x3C00, 10 }, { 0x104, 0x1E00, 9 },
		{ 0x104, 0 }, { 0x000,9 }, dpa_plls, ARRAY_SIZE(dpa_plls),
		{ 417000, 482000, 557000, 640000, 720000, 835000 }, 5, { 0, 3, 0, 2, 1, 0 },
		{ 0x3C000400, 0x3C002000, 0x3C000400, 0x3C001000, 0x3C000800, 0x3C000400 }, { 4, 2, 3, 2, 2, 2 },
		{ 0x1E000600, 0x1E000200, 0x1E000400, 0x1E000200, 0x1E000200, 0x1E000200 }, NO_ALWAYS_ON, "clk_dpa_freq" },
	{ CLK_GATE_PFA_FREQ, "clk_pfa_freq", { 0x10C, 0x3C0, 6 }, { 0x108, 0xF, 0 },
		{ 0x104,1 }, { 0x000,10 }, pfa_plls, ARRAY_SIZE(pfa_plls),
		{ 238000, 278000, 360000, 417000, 480000, 557000, 640000, 720000}, 7, { 0, 0, 1, 0, 1, 0, 2, 1 },
		{ 0x3C00040, 0x3C00040, 0x3C00080, 0x3C00040, 0x3C00080, 0x3C00040, 0x3C00100, 0x3C00080 }, { 7, 6, 4, 4, 3, 3, 2, 2 },
		{ 0xF0006, 0xF0005, 0xF0003, 0xF0003, 0xF0002, 0xF0002, 0xF0001, 0xF0001}, NO_ALWAYS_ON, "clk_pfa_freq" },
};

static struct media_pll_info ppll0_m2_info = MEDIA_PLL_INFO("clk_ppll0_m2", 1671168);
static struct media_pll_info ppll1_m2_info = MEDIA_PLL_INFO("clk_ppll1_m2", 1440000);
static struct media_pll_info ppll2b_m2_info = MEDIA_PLL_INFO("clk_ppll2b_m2", 1280000);

static struct media_pll_info *ispcpu_plls[] = {
	&ppll0_m2_info, &ppll1_m2_info, &ppll2b_m2_info,
};

static const struct fast_dvfs_clock fast_dvfs_clks_media2[] = {
	{ CLK_GATE_ISPCPU, "clk_ispcpu", { 0x088, 0xF00F, 0 }, { 0x0A8, 0x3F00, 8 },
		{ 0x0C0, 4 }, { 0x000, 15 }, ispcpu_plls, ARRAY_SIZE(ispcpu_plls),
		{ 104000, 720000, 1280000 }, 2, { 0, 1, 2 },
		{ 0xF00F2002, 0xF00F2001, 0xF00F2004 }, { 16, 2, 1 },
		{ 0x3F000F00, 0x3F000100, 0x3F000000 }, NO_ALWAYS_ON, "clk_ispcpu" },
};

static const struct fixed_factor_clock media1_stub_clks[] = {
	{ CLK_MUX_VIVOBUS, "clk_vivobus_mux", "clk_sys_ini", 1, 1, 0, "clk_vivobus_mux" },
	{ CLK_GATE_VIVOBUS_ANDGT, "clk_vivobus_gt", "clk_sys_ini", 1, 1, 0, "clk_vivobus_gt" },
	{ CLK_DIV_VIVOBUS, "clk_vivobus_div", "clk_sys_ini", 1, 1, 0, "clk_vivobus_div" },
	{ CLK_GATE_VIVOBUS, "clk_vivobus", "clk_sys_ini", 1, 1, 0, "clk_vivobus" },
	{ CLK_GATE_ATDIV_VIVO, "clk_atdiv_vivo", "clk_sys_ini", 1, 1, 0, "clk_atdiv_vivo" },
	{ CLK_GATE_ATDIV_VDEC, "clk_atdiv_vdec", "clk_sys_ini", 1, 1, 0, "clk_atdiv_vdec" },
	{ CLK_GATE_ATDIV_VENC, "clk_atdiv_venc", "clk_sys_ini", 1, 1, 0, "clk_atdiv_venc" },
	{ CLK_GATE_ATDIV_AAE, "clk_atdiv_aae", "clk_sys_ini", 1, 1, 0, "clk_atdiv_aae" },
};

static const struct fixed_factor_clock media2_stub_clks[] = {
	{ CLK_GATE_VCODECBUS, "clk_vcodecbus", "clk_sys_ini", 1, 1, 0, "clk_vcodecbus" },
	{ CLK_GATE_VCODECBUS2DDR, "clk_vcodecbus2", "clk_sys_ini", 1, 1, 0, "clk_vcodecbus2" },
	{ CLK_DIV_VCODECBUS, "clk_vcodbus_div", "clk_sys_ini", 1, 1, 0, "clk_vcodbus_div" },
	{ CLK_GATE_VCODECBUS_GT, "clk_vcodbus_gt", "clk_sys_ini", 1, 1, 0, "clk_vcodbus_gt" },
	{ CLK_MUX_VCODECBUS, "clk_vcodbus_mux", "clk_sys_ini", 1, 1, 0, "clk_vcodbus_mux" },
	{ CLK_GATE_ISP_SYS, "clk_isp_sys", "clk_sys_ini", 1, 1, 0, "clk_isp_sys" },
	{ CLK_MUX_ISPCPU_PERI_CORE, "sel_ispcpu_peri_core", "clk_sys_ini", 1, 1, 0, "sel_ispcpu_peri_core" },
	{ CLK_ANDGT_ISPCPU_PERI_CORE, "clk_ispcpu_peri_core_gt", "clk_sys_ini", 1, 1, 0, "clk_ispcpu_peri_core_gt" },
	{ CLK_DIV_ISPCPU_PERI_CORE, "clk_ispcpu_peri_core_div", "clk_sys_ini", 1, 1, 0, "clk_ispcpu_peri_core_div" },
	{ CLK_GATE_ISPCPU_CORE, "clk_ispcpu_core", "clk_sys_ini", 1, 1, 0, "clk_ispcpu_core" },
	{ CLK_ANDGT_ISPCPU_DJTAG, "clk_ispcpu_djtag_gt", "clk_sys_ini", 1, 1, 0, "clk_ispcpu_djtag_gt" },
	{ CLK_DIV_ISPCPU_DJTAG, "clk_ispcpu_djtag_div", "clk_sys_ini", 1, 1, 0, "clk_ispcpu_djtag_div" },
	{ CLK_GATE_ISPCPU_DJTAG, "clk_ispcpu_djtag", "clk_sys_ini", 1, 1, 0, "clk_ispcpu_djtag" },
	{ CLK_MUX_ISPCPU_DLDO, "sel_ispcpu_dldo", "clk_sys_ini", 1, 1, 0, "sel_ispcpu_dldo" },
	{ CLK_ANDGT_ISPCPU_DLDO, "clk_ispcpu_dldo_gt", "clk_sys_ini", 1, 1, 0, "clk_ispcpu_dldo_gt" },
	{ CLK_DIV_ISPCPU_DLDO, "clk_ispcpu_dldo_div", "clk_sys_ini", 1, 1, 0, "clk_ispcpu_dldo_div" },
	{ CLK_GATE_ISPCPU_DLDO, "clk_ispcpu_dldo", "clk_sys_ini", 1, 1, 0, "clk_ispcpu_dldo" },
	{ CLK_DIV_ISP_I3C, "clkdiv_isp_i3c", "clk_sys_ini", 1, 1, 0, "clkdiv_isp_i3c" },
	{ CLK_GATE_ISP_I3C, "clk_isp_i3c", "clk_sys_ini", 1, 1, 0, "clk_isp_i3c" },
	{ CLK_GATE_AUTODIV_VCODECBUS, "clk_atdiv_vcbus", "clk_sys_ini", 1, 1, 0, "clk_atdiv_vcbus" },
};

static const struct fixed_factor_clock fast_dvfs_clks_stub_media2[] = {
	{ CLK_GATE_ISPCPU, "clk_ispcpu", "clk_sys_ini", 1, 1, 0, "clk_ispcpu" },
};

static const struct vote_xpu_clock vote_xpu_clks[] = {
	{ CLK_GATE_EDC0, "clk_edc0", CLK_DSS_CORE_TO_XPU,
		{ 0x200, 0, 15, 15 }, { 0x340, 0, 12, 12, 4 }, 0x2DC, { 0x2D4, 0 }, 640000, true, false, "clk_edc0" },
	{ CLK_GATE_VENC, "clk_venc", CLK_VENC_TO_XPU,
		{ 0x208, 0, 15, 15 }, { 0x350, 16, 12, 28, 4 }, 0x2E0, { 0x2D4, 1 }, 640000, true, false, "clk_venc" },
	{ CLK_GATE_VDEC_PXPC, "clk_vdec_pxpc", CLK_VDEC_PXPC_TO_XPU,
		{ 0x230, 0, 15, 15 }, { 0x350, 0, 12, 12, 4 }, 0x2F0, { 0x2D4, 5 }, 640000, true, false, "clk_vdec_pxpc" },
	{ CLK_GATE_AAE, "clk_aae", CLK_AAE_CORE_TO_XPU,
		{ 0x240, 0, 15, 15 }, { 0x340, 16, 12, 28, 4 }, 0x2F4, { 0x2D4, 6 }, 558000, true, false, "clk_aae" },
	{ CLK_GATE_ISPFUNC, "clk_ispfunc", CLK_ISP_RT_TO_XPU,
		{ 0x800, 0, 15, 15 }, { 0x354, 0, 12, 12, 4 }, 0x8DC, { 0x8D4, 0 }, 480000, true, false, "clk_ispfunc" },
	{ CLK_GATE_ISPFUNC2, "clk_ispfunc2", CLK_ISP_NRT_TO_XPU,
		{ 0x808, 0, 15, 15 }, { 0x354, 16, 12, 28, 4 }, 0x8E0, { 0x8D4, 1 }, 482000, true, false, "clk_ispfunc2" },
	{ CLK_GATE_ISPFUNC3, "clk_ispfunc3", CLK_ISP_SRT_TO_XPU,
		{ 0x810, 0, 15, 15 }, { 0x35C, 0, 12, 12, 4 }, 0x8E4, { 0x8D4, 2 }, 482000, true, false, "clk_ispfunc3" },
	{ CLK_GATE_ISP_OISP, "clk_isp_oisp", CLK_OISP_TO_XPU,
		{ 0x818, 0, 15, 15 }, { 0x35C, 16, 12, 28, 4 }, 0x8E8, { 0x8D4, 3 }, 640000, true, false, "clk_isp_oisp" },
	{ CLK_GATE_IPP, "clk_ipp", CLK_IPP_TO_XPU,
		{ 0x820, 0, 15, 15 }, { 0x930, 0, 12, 12, 4 }, 0x8EC, { 0x8D4, 4 }, 640000, true, false, "clk_ipp" },
	{ CLK_GATE_ISP_SPI, "clk_isp_spi", CLK_ISPSPI_TO_XPU,
		{ 0x830, 0, 15, 15 }, { 0x930, 16, 12, 28, 4 }, 0x8F0, { 0x8D4, 5 }, 168000, true, false, "clk_isp_spi" },
	{ CLK_GATE_ISPCPU_GIC, "clk_ispcpu_gic", CLK_GIC_ISPCPU_TO_XPU,
		{ 0x840, 0, 15, 15 }, { 0x934, 0, 12, 12, 4 }, 0x8F4, { 0x8D4, 6 }, 335000, true, false, "clk_ispcpu_gic" },
	{ CLK_GATE_ISPCPU_PERI, "clk_ispcpu_peri", CLK_PERIPH_ISPCPU_TO_XPU,
		{ 0x850, 0, 15, 15 }, { 0x934, 16, 12, 28, 4 }, 0x8F8, { 0x8D4, 7 }, 335000, true, false, "clk_ispcpu_peri" },
	{ CLK_GATE_CSI_IDI, "clk_csi_idi", CLK_CSI_IDI_TO_XPU,
		{ 0x870, 0, 15, 15 }, { 0x938, 0, 12, 12, 4 }, 0x8FC, { 0x8D4, 8 }, 0, false, false, "clk_csi_idi" },
	{ CLK_GATE_DSS_VIVO, "clk_dss_vivo", CLK_DSS_VIVO_TO_XPU,
		{ 0x210, 0, 15, 15 }, { 0x938, 16, 12, 28, 4 }, 0x2E4, { 0x2D4, 2 }, 558000, true, false, "clk_dss_vivo" },
};

static void clk_crgctrl_init(struct device_node *np)
{
	struct clock_data *clk_crgctrl_data = NULL;
	unsigned int nr = ARRAY_SIZE(fixed_clks) +
		ARRAY_SIZE(fsm_pll_clks) +
		ARRAY_SIZE(crgctrl_scgt_clks) +
		ARRAY_SIZE(fixed_factor_clks) +
		ARRAY_SIZE(crgctrl_div_clks) +
		ARRAY_SIZE(crgctrl_mux_clks) +
		ARRAY_SIZE(crgctrl_gate_clks);

	clk_crgctrl_data = clk_init(np, nr);
	if (!clk_crgctrl_data)
		return;

	plat_clk_register_fixed_rate(fixed_clks,
		ARRAY_SIZE(fixed_clks), clk_crgctrl_data);

	plat_clk_register_fsm_pll(fsm_pll_clks,
		ARRAY_SIZE(fsm_pll_clks), clk_crgctrl_data);

	plat_clk_register_scgt(crgctrl_scgt_clks,
		ARRAY_SIZE(crgctrl_scgt_clks), clk_crgctrl_data);

	plat_clk_register_fixed_factor(fixed_factor_clks,
		ARRAY_SIZE(fixed_factor_clks), clk_crgctrl_data);

	plat_clk_register_divider(crgctrl_div_clks,
		ARRAY_SIZE(crgctrl_div_clks), clk_crgctrl_data);

	plat_clk_register_mux(crgctrl_mux_clks,
		ARRAY_SIZE(crgctrl_mux_clks), clk_crgctrl_data);

	plat_clk_register_gate(crgctrl_gate_clks,
		ARRAY_SIZE(crgctrl_gate_clks), clk_crgctrl_data);
}

CLK_OF_DECLARE_DRIVER(clk_peri_crgctrl,
	"hisilicon,clk-extreme-crgctrl", clk_crgctrl_init);

static void clk_hsdt_init(struct device_node *np)
{
	struct clock_data *clk_data = NULL;
	unsigned int nr = ARRAY_SIZE(hsdtcrg_pll_clks) +
		ARRAY_SIZE(hsdtctrl_gate_clks) +
		ARRAY_SIZE(hsdtctrl_div_clks);

	clk_data = clk_init(np, nr);
	if (!clk_data)
		return;

	plat_clk_register_pll(hsdtcrg_pll_clks,
		ARRAY_SIZE(hsdtcrg_pll_clks), clk_data);

	plat_clk_register_gate(hsdtctrl_gate_clks,
		ARRAY_SIZE(hsdtctrl_gate_clks), clk_data);

	plat_clk_register_divider(hsdtctrl_div_clks,
		ARRAY_SIZE(hsdtctrl_div_clks), clk_data);
}

CLK_OF_DECLARE_DRIVER(clk_hsdtcrg,
	"hisilicon,clk-extreme-hsdt-crg", clk_hsdt_init);

static void clk_hsdt1_init(struct device_node *np)
{
	struct clock_data *clk_data = NULL;
	unsigned int nr = ARRAY_SIZE(hsdt1crg_pll_clks) +
		ARRAY_SIZE(hsdt1ctrl_scgt_clks) +
		ARRAY_SIZE(hsdt1ctrl_div_clks) +
		ARRAY_SIZE(hsdt1ctrl_mux_clks) +
		ARRAY_SIZE(hsdt1ctrl_gate_clks);

	clk_data = clk_init(np, nr);
	if (!clk_data)
		return;

	plat_clk_register_pll(hsdt1crg_pll_clks,
		ARRAY_SIZE(hsdt1crg_pll_clks), clk_data);

	plat_clk_register_scgt(hsdt1ctrl_scgt_clks,
		ARRAY_SIZE(hsdt1ctrl_scgt_clks), clk_data);

	plat_clk_register_divider(hsdt1ctrl_div_clks,
		ARRAY_SIZE(hsdt1ctrl_div_clks), clk_data);

	plat_clk_register_mux(hsdt1ctrl_mux_clks,
		ARRAY_SIZE(hsdt1ctrl_mux_clks), clk_data);

	plat_clk_register_gate(hsdt1ctrl_gate_clks,
		ARRAY_SIZE(hsdt1ctrl_gate_clks), clk_data);
}

CLK_OF_DECLARE_DRIVER(clk_hsdt1crg,
	"hisilicon,clk-extreme-hsdt1-crg", clk_hsdt1_init);

static void clk_aocrg_init(struct device_node *np)
{
	struct clock_data *clk_data = NULL;
	unsigned int nr = ARRAY_SIZE(aocrg_fsm_pll_clks) +
		ARRAY_SIZE(aocrg_scgt_clks) +
		ARRAY_SIZE(aocrg_div_clks) +
		ARRAY_SIZE(aocrg_mux_clks) +
		ARRAY_SIZE(aocrg_gate_clks) +
		ARRAY_SIZE(aocrg_sec_gate_clks);

	clk_data = clk_init(np, nr);
	if (!clk_data)
		return;

	plat_clk_register_fsm_pll(aocrg_fsm_pll_clks,
		ARRAY_SIZE(aocrg_fsm_pll_clks), clk_data);

	plat_clk_register_scgt(aocrg_scgt_clks,
		ARRAY_SIZE(aocrg_scgt_clks), clk_data);

	plat_clk_register_divider(aocrg_div_clks,
		ARRAY_SIZE(aocrg_div_clks), clk_data);

	plat_clk_register_mux(aocrg_mux_clks,
		ARRAY_SIZE(aocrg_mux_clks), clk_data);

	plat_clk_register_gate(aocrg_gate_clks,
		ARRAY_SIZE(aocrg_gate_clks), clk_data);

	plat_clk_register_sec_gate(aocrg_sec_gate_clks,
		ARRAY_SIZE(aocrg_sec_gate_clks), clk_data);
}

CLK_OF_DECLARE_DRIVER(clk_aocrg,
	"hisilicon,clk-extreme-aocrg", clk_aocrg_init);

static void clk_media1_init(struct device_node *np)
{
	unsigned int nr;
	struct clock_data *clk_data = NULL;
	int no_media = media_check(MEDIA1);
	if (no_media)
		nr = ARRAY_SIZE(media1_stub_clks);
	else
		nr = ARRAY_SIZE(media1crg_scgt_clks) +
		ARRAY_SIZE(media1crg_div_clks) +
		ARRAY_SIZE(media1crg_mux_clks) +
		ARRAY_SIZE(media1crg_gate_clks);

	clk_data = clk_init(np, nr);
	if (!clk_data)
		return;

	if (no_media) {
		pr_err("[%s] media1 clock won't initialize!\n", __func__);
		plat_clk_register_fixed_factor(media1_stub_clks,
			ARRAY_SIZE(media1_stub_clks), clk_data);
	} else {
		plat_clk_register_divider(media1crg_div_clks,
			ARRAY_SIZE(media1crg_div_clks), clk_data);

		plat_clk_register_mux(media1crg_mux_clks,
			ARRAY_SIZE(media1crg_mux_clks), clk_data);

		plat_clk_register_scgt(media1crg_scgt_clks,
			ARRAY_SIZE(media1crg_scgt_clks), clk_data);

		plat_clk_register_gate(media1crg_gate_clks,
			ARRAY_SIZE(media1crg_gate_clks), clk_data);
	}
}
CLK_OF_DECLARE_DRIVER(clk_media1crg,
	"hisilicon,clk-extreme-media1-crg", clk_media1_init);

static void clk_media2_init(struct device_node *np)
{
	unsigned int nr;
	struct clock_data *clk_data = NULL;
	int no_media = media_check(MEDIA2);
	if (no_media)
		nr = ARRAY_SIZE(media2_stub_clks);
	else
		nr = ARRAY_SIZE(media2crg_scgt_clks) +
			ARRAY_SIZE(media2crg_div_clks) +
			ARRAY_SIZE(media2crg_mux_clks) +
			ARRAY_SIZE(media2crg_gate_clks);

	clk_data = clk_init(np, nr);
	if (!clk_data)
		return;

	if (no_media) {
		pr_err("[%s] media2 clock won't initialize!\n", __func__);
		plat_clk_register_fixed_factor(media2_stub_clks,
			ARRAY_SIZE(media2_stub_clks), clk_data);
	} else {
		plat_clk_register_divider(media2crg_div_clks,
			ARRAY_SIZE(media2crg_div_clks), clk_data);

		plat_clk_register_mux(media2crg_mux_clks,
			ARRAY_SIZE(media2crg_mux_clks), clk_data);

		plat_clk_register_scgt(media2crg_scgt_clks,
			ARRAY_SIZE(media2crg_scgt_clks), clk_data);

		plat_clk_register_gate(media2crg_gate_clks,
			ARRAY_SIZE(media2crg_gate_clks), clk_data);
	}
}
CLK_OF_DECLARE_DRIVER(clk_media2crg,
	"hisilicon,clk-extreme-media2-crg", clk_media2_init);

static void clk_xfreq_init(struct device_node *np)
{
	struct clock_data *clk_data = NULL;
	unsigned int nr = ARRAY_SIZE(xfreq_clks);

	clk_data = clk_init(np, nr);
	if (!clk_data)
		return;

	plat_clk_register_xfreq(xfreq_clks,
		ARRAY_SIZE(xfreq_clks), clk_data);
}
CLK_OF_DECLARE_DRIVER(clk_xfreq,
	"hisilicon,clk-extreme-xfreq", clk_xfreq_init);

static void clk_pmu_init(struct device_node *np)
{
	struct clock_data *clk_data = NULL;
	unsigned int nr = ARRAY_SIZE(pmu_clks);

	clk_data = clk_init(np, nr);
	if (!clk_data)
		return;

	plat_clk_register_clkpmu(pmu_clks,
		ARRAY_SIZE(pmu_clks), clk_data);
}
CLK_OF_DECLARE_DRIVER(clk_pmu,
	"hisilicon,clk-extreme-pmu", clk_pmu_init);

static void clk_fast_dvfs_peri_init(struct device_node *np)
{
	struct clock_data *clk_data = NULL;
	unsigned int nr;

	nr = ARRAY_SIZE(fast_dvfs_clks_crgctrl);

	clk_data = clk_init(np, nr);
	if (!clk_data)
		return;

	plat_clk_register_fast_dvfs_clk(fast_dvfs_clks_crgctrl,
		ARRAY_SIZE(fast_dvfs_clks_crgctrl), clk_data);
}
CLK_OF_DECLARE_DRIVER(clk_fast_dvfs_pericrg,
	"hisilicon,clk-extreme-fast-dvfs-peri", clk_fast_dvfs_peri_init);

static void clk_fast_dvfs_media2_init(struct device_node *np)
{
	struct clock_data *clk_data = NULL;
	int no_media = media_check(MEDIA2);
	unsigned int nr;

	if (no_media)
		nr = ARRAY_SIZE(fast_dvfs_clks_stub_media2);
	else
		nr = ARRAY_SIZE(fast_dvfs_clks_media2);

	clk_data = clk_init(np, nr);
	if (!clk_data)
		return;
	if (no_media)
		plat_clk_register_fixed_factor(fast_dvfs_clks_stub_media2,
			ARRAY_SIZE(fast_dvfs_clks_stub_media2), clk_data);
	else
		plat_clk_register_fast_dvfs_clk(fast_dvfs_clks_media2,
			ARRAY_SIZE(fast_dvfs_clks_media2), clk_data);
}
CLK_OF_DECLARE_DRIVER(clk_fast_dvfs_media2,
	"hisilicon,clk-extreme-fast-dvfs-media2", clk_fast_dvfs_media2_init);

static void clk_dvfs_init(struct device_node *np)
{
	struct clock_data *clk_dvfs_data = NULL;
	unsigned int nr = ARRAY_SIZE(dvfs_clks);

	clk_dvfs_data = clk_init(np, nr);
	if (!clk_dvfs_data)
		return;

	plat_clk_register_dvfs_clk(dvfs_clks,
		ARRAY_SIZE(dvfs_clks), clk_dvfs_data);
}
CLK_OF_DECLARE_DRIVER(clk_dvfs,
	"hisilicon,clk-extreme-dvfs", clk_dvfs_init);

static void clk_vote_xpu_init(struct device_node *np)
{
	struct clock_data *data = NULL;
	unsigned int nr = ARRAY_SIZE(vote_xpu_clks);
	int ret;
 
	ret = clk_vote_xpu_driver_init(np);
	if (ret)
		return;
 
	data = clk_init(np, nr);
	if (!data)
		return;
 
	plat_clk_register_vote_xpu_clk(vote_xpu_clks,
		ARRAY_SIZE(vote_xpu_clks), data);
}
CLK_OF_DECLARE_DRIVER(clk_vote_xpu,
	"hisilicon,clk-extreme-vote-xpu", clk_vote_xpu_init);
