#ifndef __SOC_CSI_WRAPPER_INTERFACE_H__
#define __SOC_CSI_WRAPPER_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CSI_WRAPPER_CSI_CGR_0_ADDR(base) ((base) + (0x000UL))
#define SOC_CSI_WRAPPER_CSI_CGR_0_SET_ADDR(base) ((base) + (0x004UL))
#define SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_ADDR(base) ((base) + (0x008UL))
#define SOC_CSI_WRAPPER_CSI_RESET_0_ADDR(base) ((base) + (0x00CUL))
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_ADDR(base) ((base) + (0x010UL))
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_ADDR(base) ((base) + (0x014UL))
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_ADDR(base) ((base) + (0x018UL))
#define SOC_CSI_WRAPPER_CSI_ABC_IDI_SEL_ADDR(base) ((base) + (0x01CUL))
#define SOC_CSI_WRAPPER_CSI_ABC_FORCE_PCLKON_ADDR(base) ((base) + (0x020UL))
#define SOC_CSI_WRAPPER_SECURE_ST_ADDR(base) ((base) + (0x300UL))
#define SOC_CSI_WRAPPER_CSI_MUDP_RS_CLKRST_ADDR(base) ((base) + (0x304UL))
#define SOC_CSI_WRAPPER_CSI_RESERVED_0_ADDR(base) ((base) + (0x310UL))
#define SOC_CSI_WRAPPER_CSI_RESERVED_1_ADDR(base) ((base) + (0x314UL))
#define SOC_CSI_WRAPPER_CSI_CGR_1_ADDR(base) ((base) + (0x400UL))
#define SOC_CSI_WRAPPER_CSI_CGR_1_SET_ADDR(base) ((base) + (0x404UL))
#define SOC_CSI_WRAPPER_CSI_CGR_1_CLEAR_ADDR(base) ((base) + (0x408UL))
#define SOC_CSI_WRAPPER_CSI_RESET_1_ADDR(base) ((base) + (0x40CUL))
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_ADDR(base) ((base) + (0x410UL))
#define SOC_CSI_WRAPPER_CSI_D_FORCE_PCLKON_ADDR(base) ((base) + (0x414UL))
#define SOC_CSI_WRAPPER_CSI_CGR_2_ADDR(base) ((base) + (0x500UL))
#define SOC_CSI_WRAPPER_CSI_CGR_2_SET_ADDR(base) ((base) + (0x504UL))
#define SOC_CSI_WRAPPER_CSI_CGR_2_CLEAR_ADDR(base) ((base) + (0x508UL))
#define SOC_CSI_WRAPPER_CSI_RESET_2_ADDR(base) ((base) + (0x50CUL))
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_ADDR(base) ((base) + (0x510UL))
#define SOC_CSI_WRAPPER_CSI_E_FORCE_PCLKON_ADDR(base) ((base) + (0x514UL))
#define SOC_CSI_WRAPPER_CSIA_CTRL_ADDR(base) ((base) + (0x600UL))
#define SOC_CSI_WRAPPER_CSIB_CTRL_ADDR(base) ((base) + (0x604UL))
#define SOC_CSI_WRAPPER_CSIC_CTRL_ADDR(base) ((base) + (0x608UL))
#define SOC_CSI_WRAPPER_CSID_CTRL_ADDR(base) ((base) + (0x60CUL))
#define SOC_CSI_WRAPPER_CSIE_CTRL_ADDR(base) ((base) + (0x610UL))
#define SOC_CSI_WRAPPER_CSIF_CTRL_ADDR(base) ((base) + (0x614UL))
#define SOC_CSI_WRAPPER_CSIG_CTRL_ADDR(base) ((base) + (0x618UL))
#define SOC_CSI_WRAPPER_CSIH_CTRL_ADDR(base) ((base) + (0x61CUL))
#define SOC_CSI_WRAPPER_CSI_DBG_ADDR(base) ((base) + (0x800UL))
#define SOC_CSI_WRAPPER_CSIA_DBG_ADDR(base) ((base) + (0x804UL))
#define SOC_CSI_WRAPPER_CSIB_DBG_ADDR(base) ((base) + (0x808UL))
#define SOC_CSI_WRAPPER_CSIC_DBG_ADDR(base) ((base) + (0x80CUL))
#define SOC_CSI_WRAPPER_CSID_DBG_ADDR(base) ((base) + (0x810UL))
#define SOC_CSI_WRAPPER_CSIE_DBG_ADDR(base) ((base) + (0x814UL))
#define SOC_CSI_WRAPPER_CSIF_DBG_ADDR(base) ((base) + (0x818UL))
#define SOC_CSI_WRAPPER_CSIG_DBG_ADDR(base) ((base) + (0x81CUL))
#define SOC_CSI_WRAPPER_PHY_DBG_TESTDOUT_SEL_ADDR(base) ((base) + (0x820UL))
#define SOC_CSI_WRAPPER_CSIH_DBG_ADDR(base) ((base) + (0x824UL))
#define SOC_CSI_WRAPPER_CSIF_CGR_ADDR(base) ((base) + (0x900UL))
#define SOC_CSI_WRAPPER_CSIF_CGR_SET_ADDR(base) ((base) + (0x904UL))
#define SOC_CSI_WRAPPER_CSIF_CGR_CLEAR_ADDR(base) ((base) + (0x908UL))
#define SOC_CSI_WRAPPER_CSIF_RESET_ADDR(base) ((base) + (0x90CUL))
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_ADDR(base) ((base) + (0x910UL))
#define SOC_CSI_WRAPPER_CSI_F_IDI_SEL_ADDR(base) ((base) + (0x914UL))
#define SOC_CSI_WRAPPER_CSI_F_FORCE_PCLKON_ADDR(base) ((base) + (0x918UL))
#define SOC_CSI_WRAPPER_CSIG_CGR_ADDR(base) ((base) + (0xA00UL))
#define SOC_CSI_WRAPPER_CSIG_CGR_SET_ADDR(base) ((base) + (0xA04UL))
#define SOC_CSI_WRAPPER_CSIG_CGR_CLEAR_ADDR(base) ((base) + (0xA08UL))
#define SOC_CSI_WRAPPER_CSIG_RESET_ADDR(base) ((base) + (0xA0CUL))
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_ADDR(base) ((base) + (0xA10UL))
#define SOC_CSI_WRAPPER_CSI_G_IDI_SEL_ADDR(base) ((base) + (0xA14UL))
#define SOC_CSI_WRAPPER_CSI_G_FORCE_PCLKON_ADDR(base) ((base) + (0xA18UL))
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_CTRL_ADDR(base) ((base) + (0xB00UL))
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_DOUT_ADDR(base) ((base) + (0xB04UL))
#define SOC_CSI_WRAPPER_CDPHY_A_SHUTDOWN_RST_CTRL_ADDR(base) ((base) + (0xB08UL))
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_ADDR(base) ((base) + (0xB0CUL))
#define SOC_CSI_WRAPPER_CDPHY_A_LOCK_CTRL_ADDR(base) ((base) + (0xB10UL))
#define SOC_CSI_WRAPPER_CDPHY_A_UNLOCK_CTRL_ADDR(base) ((base) + (0xB14UL))
#define SOC_CSI_WRAPPER_CDPHY_A_LOCK_STATE_ADDR(base) ((base) + (0xB18UL))
#define SOC_CSI_WRAPPER_CDPHY_A_DBG_ADDR(base) ((base) + (0xB1CUL))
#define SOC_CSI_WRAPPER_CDPHY_A_CLKRST_ADDR(base) ((base) + (0xB20UL))
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_CTRL_ADDR(base) ((base) + (0xB40UL))
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_DOUT_ADDR(base) ((base) + (0xB44UL))
#define SOC_CSI_WRAPPER_CDPHY_B_SHUTDOWN_RST_CTRL_ADDR(base) ((base) + (0xB48UL))
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_ADDR(base) ((base) + (0xB4CUL))
#define SOC_CSI_WRAPPER_CDPHY_B_LOCK_CTRL_ADDR(base) ((base) + (0xB50UL))
#define SOC_CSI_WRAPPER_CDPHY_B_UNLOCK_CTRL_ADDR(base) ((base) + (0xB54UL))
#define SOC_CSI_WRAPPER_CDPHY_B_LOCK_STATE_ADDR(base) ((base) + (0xB58UL))
#define SOC_CSI_WRAPPER_CDPHY_B_DBG_ADDR(base) ((base) + (0xB5CUL))
#define SOC_CSI_WRAPPER_CDPHY_B_CLKRST_ADDR(base) ((base) + (0xB60UL))
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_CTRL_ADDR(base) ((base) + (0xB80UL))
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_DOUT_ADDR(base) ((base) + (0xB84UL))
#define SOC_CSI_WRAPPER_CDPHY_C_SHUTDOWN_RST_CTRL_ADDR(base) ((base) + (0xB88UL))
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_ADDR(base) ((base) + (0xB8CUL))
#define SOC_CSI_WRAPPER_CDPHY_C_LOCK_CTRL_ADDR(base) ((base) + (0xB90UL))
#define SOC_CSI_WRAPPER_CDPHY_C_UNLOCK_CTRL_ADDR(base) ((base) + (0xB94UL))
#define SOC_CSI_WRAPPER_CDPHY_C_LOCK_STATE_ADDR(base) ((base) + (0xB98UL))
#define SOC_CSI_WRAPPER_CDPHY_C_DBG_ADDR(base) ((base) + (0xB9CUL))
#define SOC_CSI_WRAPPER_CDPHY_C_CLKRST_ADDR(base) ((base) + (0xBA0UL))
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_CTRL_ADDR(base) ((base) + (0xBC0UL))
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_DOUT_ADDR(base) ((base) + (0xBC4UL))
#define SOC_CSI_WRAPPER_CDPHY_D_SHUTDOWN_RST_CTRL_ADDR(base) ((base) + (0xBC8UL))
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_ADDR(base) ((base) + (0xBCCUL))
#define SOC_CSI_WRAPPER_CDPHY_D_LOCK_CTRL_ADDR(base) ((base) + (0xBD0UL))
#define SOC_CSI_WRAPPER_CDPHY_D_UNLOCK_CTRL_ADDR(base) ((base) + (0xBD4UL))
#define SOC_CSI_WRAPPER_CDPHY_D_LOCK_STATE_ADDR(base) ((base) + (0xBD8UL))
#define SOC_CSI_WRAPPER_CDPHY_D_DBG_ADDR(base) ((base) + (0xBDCUL))
#define SOC_CSI_WRAPPER_CDPHY_D_CLKRST_ADDR(base) ((base) + (0xBE0UL))
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_CTRL_ADDR(base) ((base) + (0xC00UL))
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_DOUT_ADDR(base) ((base) + (0xC04UL))
#define SOC_CSI_WRAPPER_CDPHY_E_SHUTDOWN_RST_CTRL_ADDR(base) ((base) + (0xC08UL))
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_ADDR(base) ((base) + (0xC0CUL))
#define SOC_CSI_WRAPPER_CDPHY_E_LOCK_CTRL_ADDR(base) ((base) + (0xC10UL))
#define SOC_CSI_WRAPPER_CDPHY_E_UNLOCK_CTRL_ADDR(base) ((base) + (0xC14UL))
#define SOC_CSI_WRAPPER_CDPHY_E_LOCK_STATE_ADDR(base) ((base) + (0xC18UL))
#define SOC_CSI_WRAPPER_CDPHY_E_DBG_ADDR(base) ((base) + (0xC1CUL))
#define SOC_CSI_WRAPPER_CDPHY_E_CLKRST_ADDR(base) ((base) + (0xC20UL))
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_CTRL_ADDR(base) ((base) + (0xC40UL))
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_DOUT_ADDR(base) ((base) + (0xC44UL))
#define SOC_CSI_WRAPPER_CDPHY_F_SHUTDOWN_RST_CTRL_ADDR(base) ((base) + (0xC48UL))
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_ADDR(base) ((base) + (0xC4CUL))
#define SOC_CSI_WRAPPER_CDPHY_F_LOCK_CTRL_ADDR(base) ((base) + (0xC50UL))
#define SOC_CSI_WRAPPER_CDPHY_F_UNLOCK_CTRL_ADDR(base) ((base) + (0xC54UL))
#define SOC_CSI_WRAPPER_CDPHY_F_LOCK_STATE_ADDR(base) ((base) + (0xC58UL))
#define SOC_CSI_WRAPPER_CDPHY_F_DBG_ADDR(base) ((base) + (0xC5CUL))
#define SOC_CSI_WRAPPER_CDPHY_F_CLKRST_ADDR(base) ((base) + (0xC60UL))
#define SOC_CSI_WRAPPER_CSIH_CGR_ADDR(base) ((base) + (0xD00UL))
#define SOC_CSI_WRAPPER_CSIH_CGR_SET_ADDR(base) ((base) + (0xD04UL))
#define SOC_CSI_WRAPPER_CSIH_CGR_CLEAR_ADDR(base) ((base) + (0xD08UL))
#define SOC_CSI_WRAPPER_CSIH_RESET_ADDR(base) ((base) + (0xD0CUL))
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_ADDR(base) ((base) + (0xD10UL))
#define SOC_CSI_WRAPPER_CSI_H_FORCE_PCLKON_ADDR(base) ((base) + (0xD14UL))
#define SOC_CSI_WRAPPER_S_ADDR(base) ((base) + (0xE00UL))
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_ADDR(base) ((base) + (0xE80UL))
#else
#define SOC_CSI_WRAPPER_CSI_CGR_0_ADDR(base) ((base) + (0x000))
#define SOC_CSI_WRAPPER_CSI_CGR_0_SET_ADDR(base) ((base) + (0x004))
#define SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_ADDR(base) ((base) + (0x008))
#define SOC_CSI_WRAPPER_CSI_RESET_0_ADDR(base) ((base) + (0x00C))
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_ADDR(base) ((base) + (0x010))
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_ADDR(base) ((base) + (0x014))
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_ADDR(base) ((base) + (0x018))
#define SOC_CSI_WRAPPER_CSI_ABC_IDI_SEL_ADDR(base) ((base) + (0x01C))
#define SOC_CSI_WRAPPER_CSI_ABC_FORCE_PCLKON_ADDR(base) ((base) + (0x020))
#define SOC_CSI_WRAPPER_SECURE_ST_ADDR(base) ((base) + (0x300))
#define SOC_CSI_WRAPPER_CSI_MUDP_RS_CLKRST_ADDR(base) ((base) + (0x304))
#define SOC_CSI_WRAPPER_CSI_RESERVED_0_ADDR(base) ((base) + (0x310))
#define SOC_CSI_WRAPPER_CSI_RESERVED_1_ADDR(base) ((base) + (0x314))
#define SOC_CSI_WRAPPER_CSI_CGR_1_ADDR(base) ((base) + (0x400))
#define SOC_CSI_WRAPPER_CSI_CGR_1_SET_ADDR(base) ((base) + (0x404))
#define SOC_CSI_WRAPPER_CSI_CGR_1_CLEAR_ADDR(base) ((base) + (0x408))
#define SOC_CSI_WRAPPER_CSI_RESET_1_ADDR(base) ((base) + (0x40C))
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_ADDR(base) ((base) + (0x410))
#define SOC_CSI_WRAPPER_CSI_D_FORCE_PCLKON_ADDR(base) ((base) + (0x414))
#define SOC_CSI_WRAPPER_CSI_CGR_2_ADDR(base) ((base) + (0x500))
#define SOC_CSI_WRAPPER_CSI_CGR_2_SET_ADDR(base) ((base) + (0x504))
#define SOC_CSI_WRAPPER_CSI_CGR_2_CLEAR_ADDR(base) ((base) + (0x508))
#define SOC_CSI_WRAPPER_CSI_RESET_2_ADDR(base) ((base) + (0x50C))
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_ADDR(base) ((base) + (0x510))
#define SOC_CSI_WRAPPER_CSI_E_FORCE_PCLKON_ADDR(base) ((base) + (0x514))
#define SOC_CSI_WRAPPER_CSIA_CTRL_ADDR(base) ((base) + (0x600))
#define SOC_CSI_WRAPPER_CSIB_CTRL_ADDR(base) ((base) + (0x604))
#define SOC_CSI_WRAPPER_CSIC_CTRL_ADDR(base) ((base) + (0x608))
#define SOC_CSI_WRAPPER_CSID_CTRL_ADDR(base) ((base) + (0x60C))
#define SOC_CSI_WRAPPER_CSIE_CTRL_ADDR(base) ((base) + (0x610))
#define SOC_CSI_WRAPPER_CSIF_CTRL_ADDR(base) ((base) + (0x614))
#define SOC_CSI_WRAPPER_CSIG_CTRL_ADDR(base) ((base) + (0x618))
#define SOC_CSI_WRAPPER_CSIH_CTRL_ADDR(base) ((base) + (0x61C))
#define SOC_CSI_WRAPPER_CSI_DBG_ADDR(base) ((base) + (0x800))
#define SOC_CSI_WRAPPER_CSIA_DBG_ADDR(base) ((base) + (0x804))
#define SOC_CSI_WRAPPER_CSIB_DBG_ADDR(base) ((base) + (0x808))
#define SOC_CSI_WRAPPER_CSIC_DBG_ADDR(base) ((base) + (0x80C))
#define SOC_CSI_WRAPPER_CSID_DBG_ADDR(base) ((base) + (0x810))
#define SOC_CSI_WRAPPER_CSIE_DBG_ADDR(base) ((base) + (0x814))
#define SOC_CSI_WRAPPER_CSIF_DBG_ADDR(base) ((base) + (0x818))
#define SOC_CSI_WRAPPER_CSIG_DBG_ADDR(base) ((base) + (0x81C))
#define SOC_CSI_WRAPPER_PHY_DBG_TESTDOUT_SEL_ADDR(base) ((base) + (0x820))
#define SOC_CSI_WRAPPER_CSIH_DBG_ADDR(base) ((base) + (0x824))
#define SOC_CSI_WRAPPER_CSIF_CGR_ADDR(base) ((base) + (0x900))
#define SOC_CSI_WRAPPER_CSIF_CGR_SET_ADDR(base) ((base) + (0x904))
#define SOC_CSI_WRAPPER_CSIF_CGR_CLEAR_ADDR(base) ((base) + (0x908))
#define SOC_CSI_WRAPPER_CSIF_RESET_ADDR(base) ((base) + (0x90C))
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_ADDR(base) ((base) + (0x910))
#define SOC_CSI_WRAPPER_CSI_F_IDI_SEL_ADDR(base) ((base) + (0x914))
#define SOC_CSI_WRAPPER_CSI_F_FORCE_PCLKON_ADDR(base) ((base) + (0x918))
#define SOC_CSI_WRAPPER_CSIG_CGR_ADDR(base) ((base) + (0xA00))
#define SOC_CSI_WRAPPER_CSIG_CGR_SET_ADDR(base) ((base) + (0xA04))
#define SOC_CSI_WRAPPER_CSIG_CGR_CLEAR_ADDR(base) ((base) + (0xA08))
#define SOC_CSI_WRAPPER_CSIG_RESET_ADDR(base) ((base) + (0xA0C))
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_ADDR(base) ((base) + (0xA10))
#define SOC_CSI_WRAPPER_CSI_G_IDI_SEL_ADDR(base) ((base) + (0xA14))
#define SOC_CSI_WRAPPER_CSI_G_FORCE_PCLKON_ADDR(base) ((base) + (0xA18))
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_CTRL_ADDR(base) ((base) + (0xB00))
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_DOUT_ADDR(base) ((base) + (0xB04))
#define SOC_CSI_WRAPPER_CDPHY_A_SHUTDOWN_RST_CTRL_ADDR(base) ((base) + (0xB08))
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_ADDR(base) ((base) + (0xB0C))
#define SOC_CSI_WRAPPER_CDPHY_A_LOCK_CTRL_ADDR(base) ((base) + (0xB10))
#define SOC_CSI_WRAPPER_CDPHY_A_UNLOCK_CTRL_ADDR(base) ((base) + (0xB14))
#define SOC_CSI_WRAPPER_CDPHY_A_LOCK_STATE_ADDR(base) ((base) + (0xB18))
#define SOC_CSI_WRAPPER_CDPHY_A_DBG_ADDR(base) ((base) + (0xB1C))
#define SOC_CSI_WRAPPER_CDPHY_A_CLKRST_ADDR(base) ((base) + (0xB20))
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_CTRL_ADDR(base) ((base) + (0xB40))
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_DOUT_ADDR(base) ((base) + (0xB44))
#define SOC_CSI_WRAPPER_CDPHY_B_SHUTDOWN_RST_CTRL_ADDR(base) ((base) + (0xB48))
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_ADDR(base) ((base) + (0xB4C))
#define SOC_CSI_WRAPPER_CDPHY_B_LOCK_CTRL_ADDR(base) ((base) + (0xB50))
#define SOC_CSI_WRAPPER_CDPHY_B_UNLOCK_CTRL_ADDR(base) ((base) + (0xB54))
#define SOC_CSI_WRAPPER_CDPHY_B_LOCK_STATE_ADDR(base) ((base) + (0xB58))
#define SOC_CSI_WRAPPER_CDPHY_B_DBG_ADDR(base) ((base) + (0xB5C))
#define SOC_CSI_WRAPPER_CDPHY_B_CLKRST_ADDR(base) ((base) + (0xB60))
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_CTRL_ADDR(base) ((base) + (0xB80))
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_DOUT_ADDR(base) ((base) + (0xB84))
#define SOC_CSI_WRAPPER_CDPHY_C_SHUTDOWN_RST_CTRL_ADDR(base) ((base) + (0xB88))
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_ADDR(base) ((base) + (0xB8C))
#define SOC_CSI_WRAPPER_CDPHY_C_LOCK_CTRL_ADDR(base) ((base) + (0xB90))
#define SOC_CSI_WRAPPER_CDPHY_C_UNLOCK_CTRL_ADDR(base) ((base) + (0xB94))
#define SOC_CSI_WRAPPER_CDPHY_C_LOCK_STATE_ADDR(base) ((base) + (0xB98))
#define SOC_CSI_WRAPPER_CDPHY_C_DBG_ADDR(base) ((base) + (0xB9C))
#define SOC_CSI_WRAPPER_CDPHY_C_CLKRST_ADDR(base) ((base) + (0xBA0))
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_CTRL_ADDR(base) ((base) + (0xBC0))
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_DOUT_ADDR(base) ((base) + (0xBC4))
#define SOC_CSI_WRAPPER_CDPHY_D_SHUTDOWN_RST_CTRL_ADDR(base) ((base) + (0xBC8))
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_ADDR(base) ((base) + (0xBCC))
#define SOC_CSI_WRAPPER_CDPHY_D_LOCK_CTRL_ADDR(base) ((base) + (0xBD0))
#define SOC_CSI_WRAPPER_CDPHY_D_UNLOCK_CTRL_ADDR(base) ((base) + (0xBD4))
#define SOC_CSI_WRAPPER_CDPHY_D_LOCK_STATE_ADDR(base) ((base) + (0xBD8))
#define SOC_CSI_WRAPPER_CDPHY_D_DBG_ADDR(base) ((base) + (0xBDC))
#define SOC_CSI_WRAPPER_CDPHY_D_CLKRST_ADDR(base) ((base) + (0xBE0))
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_CTRL_ADDR(base) ((base) + (0xC00))
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_DOUT_ADDR(base) ((base) + (0xC04))
#define SOC_CSI_WRAPPER_CDPHY_E_SHUTDOWN_RST_CTRL_ADDR(base) ((base) + (0xC08))
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_ADDR(base) ((base) + (0xC0C))
#define SOC_CSI_WRAPPER_CDPHY_E_LOCK_CTRL_ADDR(base) ((base) + (0xC10))
#define SOC_CSI_WRAPPER_CDPHY_E_UNLOCK_CTRL_ADDR(base) ((base) + (0xC14))
#define SOC_CSI_WRAPPER_CDPHY_E_LOCK_STATE_ADDR(base) ((base) + (0xC18))
#define SOC_CSI_WRAPPER_CDPHY_E_DBG_ADDR(base) ((base) + (0xC1C))
#define SOC_CSI_WRAPPER_CDPHY_E_CLKRST_ADDR(base) ((base) + (0xC20))
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_CTRL_ADDR(base) ((base) + (0xC40))
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_DOUT_ADDR(base) ((base) + (0xC44))
#define SOC_CSI_WRAPPER_CDPHY_F_SHUTDOWN_RST_CTRL_ADDR(base) ((base) + (0xC48))
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_ADDR(base) ((base) + (0xC4C))
#define SOC_CSI_WRAPPER_CDPHY_F_LOCK_CTRL_ADDR(base) ((base) + (0xC50))
#define SOC_CSI_WRAPPER_CDPHY_F_UNLOCK_CTRL_ADDR(base) ((base) + (0xC54))
#define SOC_CSI_WRAPPER_CDPHY_F_LOCK_STATE_ADDR(base) ((base) + (0xC58))
#define SOC_CSI_WRAPPER_CDPHY_F_DBG_ADDR(base) ((base) + (0xC5C))
#define SOC_CSI_WRAPPER_CDPHY_F_CLKRST_ADDR(base) ((base) + (0xC60))
#define SOC_CSI_WRAPPER_CSIH_CGR_ADDR(base) ((base) + (0xD00))
#define SOC_CSI_WRAPPER_CSIH_CGR_SET_ADDR(base) ((base) + (0xD04))
#define SOC_CSI_WRAPPER_CSIH_CGR_CLEAR_ADDR(base) ((base) + (0xD08))
#define SOC_CSI_WRAPPER_CSIH_RESET_ADDR(base) ((base) + (0xD0C))
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_ADDR(base) ((base) + (0xD10))
#define SOC_CSI_WRAPPER_CSI_H_FORCE_PCLKON_ADDR(base) ((base) + (0xD14))
#define SOC_CSI_WRAPPER_S_ADDR(base) ((base) + (0xE00))
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_ADDR(base) ((base) + (0xE80))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csia : 1;
        unsigned int cg_csib : 1;
        unsigned int cg_csic : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_0_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_0_cg_csia_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_0_cg_csia_END (0)
#define SOC_CSI_WRAPPER_CSI_CGR_0_cg_csib_START (1)
#define SOC_CSI_WRAPPER_CSI_CGR_0_cg_csib_END (1)
#define SOC_CSI_WRAPPER_CSI_CGR_0_cg_csic_START (2)
#define SOC_CSI_WRAPPER_CSI_CGR_0_cg_csic_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csia : 1;
        unsigned int cg_csib : 1;
        unsigned int cg_csic : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_0_SET_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_0_SET_cg_csia_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_0_SET_cg_csia_END (0)
#define SOC_CSI_WRAPPER_CSI_CGR_0_SET_cg_csib_START (1)
#define SOC_CSI_WRAPPER_CSI_CGR_0_SET_cg_csib_END (1)
#define SOC_CSI_WRAPPER_CSI_CGR_0_SET_cg_csic_START (2)
#define SOC_CSI_WRAPPER_CSI_CGR_0_SET_cg_csic_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csia : 1;
        unsigned int cg_csib : 1;
        unsigned int cg_csic : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_cg_csia_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_cg_csia_END (0)
#define SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_cg_csib_START (1)
#define SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_cg_csib_END (1)
#define SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_cg_csic_START (2)
#define SOC_CSI_WRAPPER_CSI_CGR_0_CLEAR_cg_csic_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_rst_csia : 1;
        unsigned int soft_rst_csib : 1;
        unsigned int soft_rst_csic : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CSI_WRAPPER_CSI_RESET_0_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_RESET_0_soft_rst_csia_START (0)
#define SOC_CSI_WRAPPER_CSI_RESET_0_soft_rst_csia_END (0)
#define SOC_CSI_WRAPPER_CSI_RESET_0_soft_rst_csib_START (1)
#define SOC_CSI_WRAPPER_CSI_RESET_0_soft_rst_csib_END (1)
#define SOC_CSI_WRAPPER_CSI_RESET_0_soft_rst_csic_START (2)
#define SOC_CSI_WRAPPER_CSI_RESET_0_soft_rst_csic_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phya_rxactivehs_0 : 1;
        unsigned int phya_rxactivehs_1 : 1;
        unsigned int phya_rxactivehs_2 : 1;
        unsigned int phya_rxactivehs_3 : 1;
        unsigned int phya_rxlpdtesc_0 : 1;
        unsigned int phya_rxlpdtesc_1 : 1;
        unsigned int phya_rxlpdtesc_2 : 1;
        unsigned int phya_rxlpdtesc_3 : 1;
        unsigned int phya_ulpsactivenot_0 : 1;
        unsigned int phya_ulpsactivenot_1 : 1;
        unsigned int phya_ulpsactivenot_2 : 1;
        unsigned int phya_ulpsactivenot_3 : 1;
        unsigned int phya_errsyncesc_0 : 1;
        unsigned int phya_errsyncesc_1 : 1;
        unsigned int phya_errsyncesc_2 : 1;
        unsigned int phya_errsyncesc_3 : 1;
        unsigned int phya_ulpsactivenotclk : 1;
        unsigned int reserved_0 : 3;
        unsigned int phya_rxinvalidcodehs_0 : 2;
        unsigned int phya_rxinvalidcodehs_1 : 2;
        unsigned int phya_rxinvalidcodehs_2 : 2;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_A_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxactivehs_0_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxactivehs_0_END (0)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxactivehs_1_START (1)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxactivehs_1_END (1)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxactivehs_2_START (2)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxactivehs_2_END (2)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxactivehs_3_START (3)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxactivehs_3_END (3)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxlpdtesc_0_START (4)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxlpdtesc_0_END (4)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxlpdtesc_1_START (5)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxlpdtesc_1_END (5)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxlpdtesc_2_START (6)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxlpdtesc_2_END (6)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxlpdtesc_3_START (7)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxlpdtesc_3_END (7)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_ulpsactivenot_0_START (8)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_ulpsactivenot_0_END (8)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_ulpsactivenot_1_START (9)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_ulpsactivenot_1_END (9)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_ulpsactivenot_2_START (10)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_ulpsactivenot_2_END (10)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_ulpsactivenot_3_START (11)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_ulpsactivenot_3_END (11)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_errsyncesc_0_START (12)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_errsyncesc_0_END (12)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_errsyncesc_1_START (13)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_errsyncesc_1_END (13)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_errsyncesc_2_START (14)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_errsyncesc_2_END (14)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_errsyncesc_3_START (15)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_errsyncesc_3_END (15)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_ulpsactivenotclk_START (16)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_ulpsactivenotclk_END (16)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxinvalidcodehs_0_START (20)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxinvalidcodehs_0_END (21)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxinvalidcodehs_1_START (22)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxinvalidcodehs_1_END (23)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxinvalidcodehs_2_START (24)
#define SOC_CSI_WRAPPER_PHY_CSI_A_DBG_phya_rxinvalidcodehs_2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyb_rxactivehs_0 : 1;
        unsigned int phyb_rxactivehs_1 : 1;
        unsigned int phyb_rxactivehs_2 : 1;
        unsigned int phyb_rxactivehs_3 : 1;
        unsigned int phyb_rxlpdtesc_0 : 1;
        unsigned int phyb_rxlpdtesc_1 : 1;
        unsigned int phyb_rxlpdtesc_2 : 1;
        unsigned int phyb_rxlpdtesc_3 : 1;
        unsigned int phyb_ulpsactivenot_0 : 1;
        unsigned int phyb_ulpsactivenot_1 : 1;
        unsigned int phyb_ulpsactivenot_2 : 1;
        unsigned int phyb_ulpsactivenot_3 : 1;
        unsigned int phyb_errsyncesc_0 : 1;
        unsigned int phyb_errsyncesc_1 : 1;
        unsigned int phyb_errsyncesc_2 : 1;
        unsigned int phyb_errsyncesc_3 : 1;
        unsigned int phyb_ulpsactivenotclk : 1;
        unsigned int reserved_0 : 3;
        unsigned int phyb_rxinvalidcodehs_0 : 2;
        unsigned int phyb_rxinvalidcodehs_1 : 2;
        unsigned int phyb_rxinvalidcodehs_2 : 2;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_B_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxactivehs_0_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxactivehs_0_END (0)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxactivehs_1_START (1)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxactivehs_1_END (1)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxactivehs_2_START (2)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxactivehs_2_END (2)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxactivehs_3_START (3)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxactivehs_3_END (3)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxlpdtesc_0_START (4)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxlpdtesc_0_END (4)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxlpdtesc_1_START (5)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxlpdtesc_1_END (5)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxlpdtesc_2_START (6)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxlpdtesc_2_END (6)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxlpdtesc_3_START (7)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxlpdtesc_3_END (7)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_ulpsactivenot_0_START (8)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_ulpsactivenot_0_END (8)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_ulpsactivenot_1_START (9)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_ulpsactivenot_1_END (9)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_ulpsactivenot_2_START (10)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_ulpsactivenot_2_END (10)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_ulpsactivenot_3_START (11)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_ulpsactivenot_3_END (11)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_errsyncesc_0_START (12)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_errsyncesc_0_END (12)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_errsyncesc_1_START (13)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_errsyncesc_1_END (13)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_errsyncesc_2_START (14)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_errsyncesc_2_END (14)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_errsyncesc_3_START (15)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_errsyncesc_3_END (15)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_ulpsactivenotclk_START (16)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_ulpsactivenotclk_END (16)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxinvalidcodehs_0_START (20)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxinvalidcodehs_0_END (21)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxinvalidcodehs_1_START (22)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxinvalidcodehs_1_END (23)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxinvalidcodehs_2_START (24)
#define SOC_CSI_WRAPPER_PHY_CSI_B_DBG_phyb_rxinvalidcodehs_2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyc_rxactivehs_0 : 1;
        unsigned int phyc_rxactivehs_1 : 1;
        unsigned int phyc_rxactivehs_2 : 1;
        unsigned int phyc_rxactivehs_3 : 1;
        unsigned int phyc_rxlpdtesc_0 : 1;
        unsigned int phyc_rxlpdtesc_1 : 1;
        unsigned int phyc_rxlpdtesc_2 : 1;
        unsigned int phyc_rxlpdtesc_3 : 1;
        unsigned int phyc_ulpsactivenot_0 : 1;
        unsigned int phyc_ulpsactivenot_1 : 1;
        unsigned int phyc_ulpsactivenot_2 : 1;
        unsigned int phyc_ulpsactivenot_3 : 1;
        unsigned int phyc_errsyncesc_0 : 1;
        unsigned int phyc_errsyncesc_1 : 1;
        unsigned int phyc_errsyncesc_2 : 1;
        unsigned int phyc_errsyncesc_3 : 1;
        unsigned int phyc_ulpsactivenotclk : 1;
        unsigned int reserved_0 : 3;
        unsigned int phyc_rxinvalidcodehs_0 : 2;
        unsigned int phyc_rxinvalidcodehs_1 : 2;
        unsigned int phyc_rxinvalidcodehs_2 : 2;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_C_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxactivehs_0_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxactivehs_0_END (0)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxactivehs_1_START (1)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxactivehs_1_END (1)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxactivehs_2_START (2)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxactivehs_2_END (2)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxactivehs_3_START (3)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxactivehs_3_END (3)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxlpdtesc_0_START (4)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxlpdtesc_0_END (4)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxlpdtesc_1_START (5)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxlpdtesc_1_END (5)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxlpdtesc_2_START (6)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxlpdtesc_2_END (6)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxlpdtesc_3_START (7)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxlpdtesc_3_END (7)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_ulpsactivenot_0_START (8)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_ulpsactivenot_0_END (8)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_ulpsactivenot_1_START (9)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_ulpsactivenot_1_END (9)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_ulpsactivenot_2_START (10)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_ulpsactivenot_2_END (10)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_ulpsactivenot_3_START (11)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_ulpsactivenot_3_END (11)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_errsyncesc_0_START (12)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_errsyncesc_0_END (12)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_errsyncesc_1_START (13)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_errsyncesc_1_END (13)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_errsyncesc_2_START (14)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_errsyncesc_2_END (14)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_errsyncesc_3_START (15)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_errsyncesc_3_END (15)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_ulpsactivenotclk_START (16)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_ulpsactivenotclk_END (16)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxinvalidcodehs_0_START (20)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxinvalidcodehs_0_END (21)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxinvalidcodehs_1_START (22)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxinvalidcodehs_1_END (23)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxinvalidcodehs_2_START (24)
#define SOC_CSI_WRAPPER_PHY_CSI_C_DBG_phyc_rxinvalidcodehs_2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idi_sel_a : 1;
        unsigned int idi_sel_b : 1;
        unsigned int idi_sel_c : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CSI_WRAPPER_CSI_ABC_IDI_SEL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_ABC_IDI_SEL_idi_sel_a_START (0)
#define SOC_CSI_WRAPPER_CSI_ABC_IDI_SEL_idi_sel_a_END (0)
#define SOC_CSI_WRAPPER_CSI_ABC_IDI_SEL_idi_sel_b_START (1)
#define SOC_CSI_WRAPPER_CSI_ABC_IDI_SEL_idi_sel_b_END (1)
#define SOC_CSI_WRAPPER_CSI_ABC_IDI_SEL_idi_sel_c_START (2)
#define SOC_CSI_WRAPPER_CSI_ABC_IDI_SEL_idi_sel_c_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csia_force_pclk_on : 1;
        unsigned int csib_force_pclk_on : 1;
        unsigned int csic_force_pclk_on : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CSI_WRAPPER_CSI_ABC_FORCE_PCLKON_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_ABC_FORCE_PCLKON_csia_force_pclk_on_START (0)
#define SOC_CSI_WRAPPER_CSI_ABC_FORCE_PCLKON_csia_force_pclk_on_END (0)
#define SOC_CSI_WRAPPER_CSI_ABC_FORCE_PCLKON_csib_force_pclk_on_START (1)
#define SOC_CSI_WRAPPER_CSI_ABC_FORCE_PCLKON_csib_force_pclk_on_END (1)
#define SOC_CSI_WRAPPER_CSI_ABC_FORCE_PCLKON_csic_force_pclk_on_START (2)
#define SOC_CSI_WRAPPER_CSI_ABC_FORCE_PCLKON_csic_force_pclk_on_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csi_wrapper_secure_st : 32;
    } reg;
} SOC_CSI_WRAPPER_SECURE_ST_UNION;
#endif
#define SOC_CSI_WRAPPER_SECURE_ST_csi_wrapper_secure_st_START (0)
#define SOC_CSI_WRAPPER_SECURE_ST_csi_wrapper_secure_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_rst_mudp : 1;
        unsigned int cg_en_mudp : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI_WRAPPER_CSI_MUDP_RS_CLKRST_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_MUDP_RS_CLKRST_soft_rst_mudp_START (0)
#define SOC_CSI_WRAPPER_CSI_MUDP_RS_CLKRST_soft_rst_mudp_END (0)
#define SOC_CSI_WRAPPER_CSI_MUDP_RS_CLKRST_cg_en_mudp_START (1)
#define SOC_CSI_WRAPPER_CSI_MUDP_RS_CLKRST_cg_en_mudp_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CSI_WRAPPER_CSI_RESERVED_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_CSI_WRAPPER_CSI_RESERVED_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_1_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_1_cg_csid_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_1_cg_csid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_1_SET_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_1_SET_cg_csid_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_1_SET_cg_csid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_1_CLEAR_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_1_CLEAR_cg_csid_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_1_CLEAR_cg_csid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_rst_csid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_RESET_1_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_RESET_1_soft_rst_csid_START (0)
#define SOC_CSI_WRAPPER_CSI_RESET_1_soft_rst_csid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyd_rxactivehs_0 : 1;
        unsigned int phyd_rxactivehs_1 : 1;
        unsigned int phyd_rxactivehs_2 : 1;
        unsigned int phyd_rxactivehs_3 : 1;
        unsigned int phyd_rxlpdtesc_0 : 1;
        unsigned int phyd_rxlpdtesc_1 : 1;
        unsigned int phyd_rxlpdtesc_2 : 1;
        unsigned int phyd_rxlpdtesc_3 : 1;
        unsigned int phyd_ulpsactivenot_0 : 1;
        unsigned int phyd_ulpsactivenot_1 : 1;
        unsigned int phyd_ulpsactivenot_2 : 1;
        unsigned int phyd_ulpsactivenot_3 : 1;
        unsigned int phyd_errsyncesc_0 : 1;
        unsigned int phyd_errsyncesc_1 : 1;
        unsigned int phyd_errsyncesc_2 : 1;
        unsigned int phyd_errsyncesc_3 : 1;
        unsigned int phyd_ulpsactivenotclk : 1;
        unsigned int reserved_0 : 3;
        unsigned int phyd_rxinvalidcodehs_0 : 2;
        unsigned int phyd_rxinvalidcodehs_1 : 2;
        unsigned int phyd_rxinvalidcodehs_2 : 2;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_D_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxactivehs_0_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxactivehs_0_END (0)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxactivehs_1_START (1)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxactivehs_1_END (1)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxactivehs_2_START (2)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxactivehs_2_END (2)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxactivehs_3_START (3)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxactivehs_3_END (3)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxlpdtesc_0_START (4)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxlpdtesc_0_END (4)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxlpdtesc_1_START (5)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxlpdtesc_1_END (5)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxlpdtesc_2_START (6)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxlpdtesc_2_END (6)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxlpdtesc_3_START (7)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxlpdtesc_3_END (7)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_ulpsactivenot_0_START (8)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_ulpsactivenot_0_END (8)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_ulpsactivenot_1_START (9)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_ulpsactivenot_1_END (9)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_ulpsactivenot_2_START (10)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_ulpsactivenot_2_END (10)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_ulpsactivenot_3_START (11)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_ulpsactivenot_3_END (11)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_errsyncesc_0_START (12)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_errsyncesc_0_END (12)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_errsyncesc_1_START (13)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_errsyncesc_1_END (13)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_errsyncesc_2_START (14)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_errsyncesc_2_END (14)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_errsyncesc_3_START (15)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_errsyncesc_3_END (15)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_ulpsactivenotclk_START (16)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_ulpsactivenotclk_END (16)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxinvalidcodehs_0_START (20)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxinvalidcodehs_0_END (21)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxinvalidcodehs_1_START (22)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxinvalidcodehs_1_END (23)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxinvalidcodehs_2_START (24)
#define SOC_CSI_WRAPPER_PHY_CSI_D_DBG_phyd_rxinvalidcodehs_2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csid_force_pclk_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_D_FORCE_PCLKON_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_D_FORCE_PCLKON_csid_force_pclk_on_START (0)
#define SOC_CSI_WRAPPER_CSI_D_FORCE_PCLKON_csid_force_pclk_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csie : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_2_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_2_cg_csie_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_2_cg_csie_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csie : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_2_SET_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_2_SET_cg_csie_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_2_SET_cg_csie_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csie : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_CGR_2_CLEAR_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_CGR_2_CLEAR_cg_csie_START (0)
#define SOC_CSI_WRAPPER_CSI_CGR_2_CLEAR_cg_csie_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_rst_csie : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_RESET_2_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_RESET_2_soft_rst_csie_START (0)
#define SOC_CSI_WRAPPER_CSI_RESET_2_soft_rst_csie_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phye_rxactivehs_0 : 1;
        unsigned int phye_rxactivehs_1 : 1;
        unsigned int phye_rxactivehs_2 : 1;
        unsigned int phye_rxactivehs_3 : 1;
        unsigned int phye_rxlpdtesc_0 : 1;
        unsigned int phye_rxlpdtesc_1 : 1;
        unsigned int phye_rxlpdtesc_2 : 1;
        unsigned int phye_rxlpdtesc_3 : 1;
        unsigned int phye_ulpsactivenot_0 : 1;
        unsigned int phye_ulpsactivenot_1 : 1;
        unsigned int phye_ulpsactivenot_2 : 1;
        unsigned int phye_ulpsactivenot_3 : 1;
        unsigned int phye_errsyncesc_0 : 1;
        unsigned int phye_errsyncesc_1 : 1;
        unsigned int phye_errsyncesc_2 : 1;
        unsigned int phye_errsyncesc_3 : 1;
        unsigned int phye_ulpsactivenotclk : 1;
        unsigned int reserved_0 : 3;
        unsigned int phye_rxinvalidcodehs_0 : 2;
        unsigned int phye_rxinvalidcodehs_1 : 2;
        unsigned int phye_rxinvalidcodehs_2 : 2;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_E_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxactivehs_0_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxactivehs_0_END (0)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxactivehs_1_START (1)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxactivehs_1_END (1)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxactivehs_2_START (2)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxactivehs_2_END (2)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxactivehs_3_START (3)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxactivehs_3_END (3)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxlpdtesc_0_START (4)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxlpdtesc_0_END (4)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxlpdtesc_1_START (5)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxlpdtesc_1_END (5)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxlpdtesc_2_START (6)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxlpdtesc_2_END (6)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxlpdtesc_3_START (7)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxlpdtesc_3_END (7)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_ulpsactivenot_0_START (8)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_ulpsactivenot_0_END (8)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_ulpsactivenot_1_START (9)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_ulpsactivenot_1_END (9)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_ulpsactivenot_2_START (10)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_ulpsactivenot_2_END (10)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_ulpsactivenot_3_START (11)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_ulpsactivenot_3_END (11)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_errsyncesc_0_START (12)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_errsyncesc_0_END (12)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_errsyncesc_1_START (13)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_errsyncesc_1_END (13)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_errsyncesc_2_START (14)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_errsyncesc_2_END (14)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_errsyncesc_3_START (15)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_errsyncesc_3_END (15)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_ulpsactivenotclk_START (16)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_ulpsactivenotclk_END (16)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxinvalidcodehs_0_START (20)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxinvalidcodehs_0_END (21)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxinvalidcodehs_1_START (22)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxinvalidcodehs_1_END (23)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxinvalidcodehs_2_START (24)
#define SOC_CSI_WRAPPER_PHY_CSI_E_DBG_phye_rxinvalidcodehs_2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csie_force_pclk_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_E_FORCE_PCLKON_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_E_FORCE_PCLKON_csie_force_pclk_on_START (0)
#define SOC_CSI_WRAPPER_CSI_E_FORCE_PCLKON_csie_force_pclk_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 25;
        unsigned int csia_en : 1;
        unsigned int csia_sensor : 1;
        unsigned int csia_cdphy_sensor_connection : 1;
        unsigned int reserved_1 : 1;
        unsigned int csia_cdphy_source : 3;
    } reg;
} SOC_CSI_WRAPPER_CSIA_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_en_START (25)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_en_END (25)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_sensor_START (26)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_sensor_END (26)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_cdphy_sensor_connection_START (27)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_cdphy_sensor_connection_END (27)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_cdphy_source_START (29)
#define SOC_CSI_WRAPPER_CSIA_CTRL_csia_cdphy_source_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 25;
        unsigned int csib_en : 1;
        unsigned int csib_sensor : 1;
        unsigned int csib_cdphy_sensor_connection : 1;
        unsigned int reserved_1 : 1;
        unsigned int csib_cdphy_source : 3;
    } reg;
} SOC_CSI_WRAPPER_CSIB_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_en_START (25)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_en_END (25)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_sensor_START (26)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_sensor_END (26)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_cdphy_sensor_connection_START (27)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_cdphy_sensor_connection_END (27)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_cdphy_source_START (29)
#define SOC_CSI_WRAPPER_CSIB_CTRL_csib_cdphy_source_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 25;
        unsigned int csic_en : 1;
        unsigned int csic_sensor : 1;
        unsigned int csic_cdphy_sensor_connection : 1;
        unsigned int reserved_1 : 1;
        unsigned int csic_cdphy_source : 3;
    } reg;
} SOC_CSI_WRAPPER_CSIC_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_en_START (25)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_en_END (25)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_sensor_START (26)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_sensor_END (26)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_cdphy_sensor_connection_START (27)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_cdphy_sensor_connection_END (27)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_cdphy_source_START (29)
#define SOC_CSI_WRAPPER_CSIC_CTRL_csic_cdphy_source_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 23;
        unsigned int csid_reformat_type : 1;
        unsigned int csid_reformat_enable : 1;
        unsigned int csid_en : 1;
        unsigned int csid_sensor : 1;
        unsigned int csid_cdphy_sensor_connection : 1;
        unsigned int reserved_1 : 1;
        unsigned int csid_cdphy_source : 3;
    } reg;
} SOC_CSI_WRAPPER_CSID_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_reformat_type_START (23)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_reformat_type_END (23)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_reformat_enable_START (24)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_reformat_enable_END (24)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_en_START (25)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_en_END (25)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_sensor_START (26)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_sensor_END (26)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_cdphy_sensor_connection_START (27)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_cdphy_sensor_connection_END (27)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_cdphy_source_START (29)
#define SOC_CSI_WRAPPER_CSID_CTRL_csid_cdphy_source_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ipi_cfg_vc : 4;
        unsigned int in_pixel_type : 1;
        unsigned int round_type : 1;
        unsigned int reorder_err_en : 1;
        unsigned int reserved_0 : 10;
        unsigned int ipi_cfg_dt : 6;
        unsigned int reserved_1 : 2;
        unsigned int csie_en : 1;
        unsigned int csie_sensor : 1;
        unsigned int csie_cdphy_sensor_connection : 1;
        unsigned int reserved_2 : 1;
        unsigned int csie_cdphy_source : 3;
    } reg;
} SOC_CSI_WRAPPER_CSIE_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIE_CTRL_ipi_cfg_vc_START (0)
#define SOC_CSI_WRAPPER_CSIE_CTRL_ipi_cfg_vc_END (3)
#define SOC_CSI_WRAPPER_CSIE_CTRL_in_pixel_type_START (4)
#define SOC_CSI_WRAPPER_CSIE_CTRL_in_pixel_type_END (4)
#define SOC_CSI_WRAPPER_CSIE_CTRL_round_type_START (5)
#define SOC_CSI_WRAPPER_CSIE_CTRL_round_type_END (5)
#define SOC_CSI_WRAPPER_CSIE_CTRL_reorder_err_en_START (6)
#define SOC_CSI_WRAPPER_CSIE_CTRL_reorder_err_en_END (6)
#define SOC_CSI_WRAPPER_CSIE_CTRL_ipi_cfg_dt_START (17)
#define SOC_CSI_WRAPPER_CSIE_CTRL_ipi_cfg_dt_END (22)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_en_START (25)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_en_END (25)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_sensor_START (26)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_sensor_END (26)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_cdphy_sensor_connection_START (27)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_cdphy_sensor_connection_END (27)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_cdphy_source_START (29)
#define SOC_CSI_WRAPPER_CSIE_CTRL_csie_cdphy_source_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 25;
        unsigned int csif_en : 1;
        unsigned int csif_sensor : 1;
        unsigned int csif_cdphy_sensor_connection : 1;
        unsigned int reserved_1 : 1;
        unsigned int csif_cdphy_source : 3;
    } reg;
} SOC_CSI_WRAPPER_CSIF_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIF_CTRL_csif_en_START (25)
#define SOC_CSI_WRAPPER_CSIF_CTRL_csif_en_END (25)
#define SOC_CSI_WRAPPER_CSIF_CTRL_csif_sensor_START (26)
#define SOC_CSI_WRAPPER_CSIF_CTRL_csif_sensor_END (26)
#define SOC_CSI_WRAPPER_CSIF_CTRL_csif_cdphy_sensor_connection_START (27)
#define SOC_CSI_WRAPPER_CSIF_CTRL_csif_cdphy_sensor_connection_END (27)
#define SOC_CSI_WRAPPER_CSIF_CTRL_csif_cdphy_source_START (29)
#define SOC_CSI_WRAPPER_CSIF_CTRL_csif_cdphy_source_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 25;
        unsigned int csig_en : 1;
        unsigned int csig_sensor : 1;
        unsigned int csig_cdphy_sensor_connection : 1;
        unsigned int reserved_1 : 1;
        unsigned int csig_cdphy_source : 3;
    } reg;
} SOC_CSI_WRAPPER_CSIG_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIG_CTRL_csig_en_START (25)
#define SOC_CSI_WRAPPER_CSIG_CTRL_csig_en_END (25)
#define SOC_CSI_WRAPPER_CSIG_CTRL_csig_sensor_START (26)
#define SOC_CSI_WRAPPER_CSIG_CTRL_csig_sensor_END (26)
#define SOC_CSI_WRAPPER_CSIG_CTRL_csig_cdphy_sensor_connection_START (27)
#define SOC_CSI_WRAPPER_CSIG_CTRL_csig_cdphy_sensor_connection_END (27)
#define SOC_CSI_WRAPPER_CSIG_CTRL_csig_cdphy_source_START (29)
#define SOC_CSI_WRAPPER_CSIG_CTRL_csig_cdphy_source_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 25;
        unsigned int csih_en : 1;
        unsigned int csih_sensor : 1;
        unsigned int csih_cdphy_sensor_connection : 1;
        unsigned int reserved_1 : 1;
        unsigned int csih_cdphy_source : 3;
    } reg;
} SOC_CSI_WRAPPER_CSIH_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIH_CTRL_csih_en_START (25)
#define SOC_CSI_WRAPPER_CSIH_CTRL_csih_en_END (25)
#define SOC_CSI_WRAPPER_CSIH_CTRL_csih_sensor_START (26)
#define SOC_CSI_WRAPPER_CSIH_CTRL_csih_sensor_END (26)
#define SOC_CSI_WRAPPER_CSIH_CTRL_csih_cdphy_sensor_connection_START (27)
#define SOC_CSI_WRAPPER_CSIH_CTRL_csih_cdphy_sensor_connection_END (27)
#define SOC_CSI_WRAPPER_CSIH_CTRL_csih_cdphy_source_START (29)
#define SOC_CSI_WRAPPER_CSIH_CTRL_csih_cdphy_source_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csi_debug_en : 1;
        unsigned int csia_overflow : 1;
        unsigned int csib_overflow : 1;
        unsigned int csic_overflow : 1;
        unsigned int csid_overflow : 1;
        unsigned int csie_overflow : 1;
        unsigned int csif_overflow : 1;
        unsigned int csig_overflow : 1;
        unsigned int reorder_err : 1;
        unsigned int csih_overflow : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_CSI_WRAPPER_CSI_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_DBG_csi_debug_en_START (0)
#define SOC_CSI_WRAPPER_CSI_DBG_csi_debug_en_END (0)
#define SOC_CSI_WRAPPER_CSI_DBG_csia_overflow_START (1)
#define SOC_CSI_WRAPPER_CSI_DBG_csia_overflow_END (1)
#define SOC_CSI_WRAPPER_CSI_DBG_csib_overflow_START (2)
#define SOC_CSI_WRAPPER_CSI_DBG_csib_overflow_END (2)
#define SOC_CSI_WRAPPER_CSI_DBG_csic_overflow_START (3)
#define SOC_CSI_WRAPPER_CSI_DBG_csic_overflow_END (3)
#define SOC_CSI_WRAPPER_CSI_DBG_csid_overflow_START (4)
#define SOC_CSI_WRAPPER_CSI_DBG_csid_overflow_END (4)
#define SOC_CSI_WRAPPER_CSI_DBG_csie_overflow_START (5)
#define SOC_CSI_WRAPPER_CSI_DBG_csie_overflow_END (5)
#define SOC_CSI_WRAPPER_CSI_DBG_csif_overflow_START (6)
#define SOC_CSI_WRAPPER_CSI_DBG_csif_overflow_END (6)
#define SOC_CSI_WRAPPER_CSI_DBG_csig_overflow_START (7)
#define SOC_CSI_WRAPPER_CSI_DBG_csig_overflow_END (7)
#define SOC_CSI_WRAPPER_CSI_DBG_reorder_err_START (8)
#define SOC_CSI_WRAPPER_CSI_DBG_reorder_err_END (8)
#define SOC_CSI_WRAPPER_CSI_DBG_csih_overflow_START (9)
#define SOC_CSI_WRAPPER_CSI_DBG_csih_overflow_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csia_dbg_hcnt : 13;
        unsigned int csia_dbg_hcnt_max : 13;
        unsigned int csia_dbg_v_flag : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CSI_WRAPPER_CSIA_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIA_DBG_csia_dbg_hcnt_START (0)
#define SOC_CSI_WRAPPER_CSIA_DBG_csia_dbg_hcnt_END (12)
#define SOC_CSI_WRAPPER_CSIA_DBG_csia_dbg_hcnt_max_START (13)
#define SOC_CSI_WRAPPER_CSIA_DBG_csia_dbg_hcnt_max_END (25)
#define SOC_CSI_WRAPPER_CSIA_DBG_csia_dbg_v_flag_START (26)
#define SOC_CSI_WRAPPER_CSIA_DBG_csia_dbg_v_flag_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csib_dbg_hcnt : 13;
        unsigned int csib_dbg_hcnt_max : 13;
        unsigned int csib_dbg_v_flag : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CSI_WRAPPER_CSIB_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIB_DBG_csib_dbg_hcnt_START (0)
#define SOC_CSI_WRAPPER_CSIB_DBG_csib_dbg_hcnt_END (12)
#define SOC_CSI_WRAPPER_CSIB_DBG_csib_dbg_hcnt_max_START (13)
#define SOC_CSI_WRAPPER_CSIB_DBG_csib_dbg_hcnt_max_END (25)
#define SOC_CSI_WRAPPER_CSIB_DBG_csib_dbg_v_flag_START (26)
#define SOC_CSI_WRAPPER_CSIB_DBG_csib_dbg_v_flag_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csic_dbg_hcnt : 13;
        unsigned int csic_dbg_hcnt_max : 13;
        unsigned int csic_dbg_v_flag : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CSI_WRAPPER_CSIC_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIC_DBG_csic_dbg_hcnt_START (0)
#define SOC_CSI_WRAPPER_CSIC_DBG_csic_dbg_hcnt_END (12)
#define SOC_CSI_WRAPPER_CSIC_DBG_csic_dbg_hcnt_max_START (13)
#define SOC_CSI_WRAPPER_CSIC_DBG_csic_dbg_hcnt_max_END (25)
#define SOC_CSI_WRAPPER_CSIC_DBG_csic_dbg_v_flag_START (26)
#define SOC_CSI_WRAPPER_CSIC_DBG_csic_dbg_v_flag_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csid_dbg_hcnt : 13;
        unsigned int csid_dbg_hcnt_max : 13;
        unsigned int csid_dbg_v_flag : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CSI_WRAPPER_CSID_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CSID_DBG_csid_dbg_hcnt_START (0)
#define SOC_CSI_WRAPPER_CSID_DBG_csid_dbg_hcnt_END (12)
#define SOC_CSI_WRAPPER_CSID_DBG_csid_dbg_hcnt_max_START (13)
#define SOC_CSI_WRAPPER_CSID_DBG_csid_dbg_hcnt_max_END (25)
#define SOC_CSI_WRAPPER_CSID_DBG_csid_dbg_v_flag_START (26)
#define SOC_CSI_WRAPPER_CSID_DBG_csid_dbg_v_flag_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csie_dbg_hcnt : 13;
        unsigned int csie_dbg_hcnt_max : 13;
        unsigned int csie_dbg_v_flag : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CSI_WRAPPER_CSIE_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIE_DBG_csie_dbg_hcnt_START (0)
#define SOC_CSI_WRAPPER_CSIE_DBG_csie_dbg_hcnt_END (12)
#define SOC_CSI_WRAPPER_CSIE_DBG_csie_dbg_hcnt_max_START (13)
#define SOC_CSI_WRAPPER_CSIE_DBG_csie_dbg_hcnt_max_END (25)
#define SOC_CSI_WRAPPER_CSIE_DBG_csie_dbg_v_flag_START (26)
#define SOC_CSI_WRAPPER_CSIE_DBG_csie_dbg_v_flag_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csif_dbg_hcnt : 13;
        unsigned int csif_dbg_hcnt_max : 13;
        unsigned int csif_dbg_v_flag : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CSI_WRAPPER_CSIF_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIF_DBG_csif_dbg_hcnt_START (0)
#define SOC_CSI_WRAPPER_CSIF_DBG_csif_dbg_hcnt_END (12)
#define SOC_CSI_WRAPPER_CSIF_DBG_csif_dbg_hcnt_max_START (13)
#define SOC_CSI_WRAPPER_CSIF_DBG_csif_dbg_hcnt_max_END (25)
#define SOC_CSI_WRAPPER_CSIF_DBG_csif_dbg_v_flag_START (26)
#define SOC_CSI_WRAPPER_CSIF_DBG_csif_dbg_v_flag_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csig_dbg_hcnt : 13;
        unsigned int csig_dbg_hcnt_max : 13;
        unsigned int csig_dbg_v_flag : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CSI_WRAPPER_CSIG_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIG_DBG_csig_dbg_hcnt_START (0)
#define SOC_CSI_WRAPPER_CSIG_DBG_csig_dbg_hcnt_END (12)
#define SOC_CSI_WRAPPER_CSIG_DBG_csig_dbg_hcnt_max_START (13)
#define SOC_CSI_WRAPPER_CSIG_DBG_csig_dbg_hcnt_max_END (25)
#define SOC_CSI_WRAPPER_CSIG_DBG_csig_dbg_v_flag_START (26)
#define SOC_CSI_WRAPPER_CSIG_DBG_csig_dbg_v_flag_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phy_dbg_testdout_sel : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_CSI_WRAPPER_PHY_DBG_TESTDOUT_SEL_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_DBG_TESTDOUT_SEL_phy_dbg_testdout_sel_START (0)
#define SOC_CSI_WRAPPER_PHY_DBG_TESTDOUT_SEL_phy_dbg_testdout_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csih_dbg_hcnt : 13;
        unsigned int csih_dbg_hcnt_max : 13;
        unsigned int csih_dbg_v_flag : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CSI_WRAPPER_CSIH_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIH_DBG_csih_dbg_hcnt_START (0)
#define SOC_CSI_WRAPPER_CSIH_DBG_csih_dbg_hcnt_END (12)
#define SOC_CSI_WRAPPER_CSIH_DBG_csih_dbg_hcnt_max_START (13)
#define SOC_CSI_WRAPPER_CSIH_DBG_csih_dbg_hcnt_max_END (25)
#define SOC_CSI_WRAPPER_CSIH_DBG_csih_dbg_v_flag_START (26)
#define SOC_CSI_WRAPPER_CSIH_DBG_csih_dbg_v_flag_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csif : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSIF_CGR_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIF_CGR_cg_csif_START (0)
#define SOC_CSI_WRAPPER_CSIF_CGR_cg_csif_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csif : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSIF_CGR_SET_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIF_CGR_SET_cg_csif_START (0)
#define SOC_CSI_WRAPPER_CSIF_CGR_SET_cg_csif_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csif : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSIF_CGR_CLEAR_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIF_CGR_CLEAR_cg_csif_START (0)
#define SOC_CSI_WRAPPER_CSIF_CGR_CLEAR_cg_csif_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_rst_csif : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSIF_RESET_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIF_RESET_soft_rst_csif_START (0)
#define SOC_CSI_WRAPPER_CSIF_RESET_soft_rst_csif_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyf_rxactivehs_0 : 1;
        unsigned int phyf_rxactivehs_1 : 1;
        unsigned int phyf_rxactivehs_2 : 1;
        unsigned int phyf_rxactivehs_3 : 1;
        unsigned int phyf_rxlpdtesc_0 : 1;
        unsigned int phyf_rxlpdtesc_1 : 1;
        unsigned int phyf_rxlpdtesc_2 : 1;
        unsigned int phyf_rxlpdtesc_3 : 1;
        unsigned int phyf_ulpsactivenot_0 : 1;
        unsigned int phyf_ulpsactivenot_1 : 1;
        unsigned int phyf_ulpsactivenot_2 : 1;
        unsigned int phyf_ulpsactivenot_3 : 1;
        unsigned int phyf_errsyncesc_0 : 1;
        unsigned int phyf_errsyncesc_1 : 1;
        unsigned int phyf_errsyncesc_2 : 1;
        unsigned int phyf_errsyncesc_3 : 1;
        unsigned int phyf_ulpsactivenotclk : 1;
        unsigned int reserved_0 : 3;
        unsigned int phyf_rxinvalidcodehs_0 : 2;
        unsigned int phyf_rxinvalidcodehs_1 : 2;
        unsigned int phyf_rxinvalidcodehs_2 : 2;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_F_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxactivehs_0_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxactivehs_0_END (0)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxactivehs_1_START (1)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxactivehs_1_END (1)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxactivehs_2_START (2)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxactivehs_2_END (2)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxactivehs_3_START (3)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxactivehs_3_END (3)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxlpdtesc_0_START (4)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxlpdtesc_0_END (4)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxlpdtesc_1_START (5)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxlpdtesc_1_END (5)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxlpdtesc_2_START (6)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxlpdtesc_2_END (6)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxlpdtesc_3_START (7)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxlpdtesc_3_END (7)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_ulpsactivenot_0_START (8)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_ulpsactivenot_0_END (8)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_ulpsactivenot_1_START (9)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_ulpsactivenot_1_END (9)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_ulpsactivenot_2_START (10)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_ulpsactivenot_2_END (10)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_ulpsactivenot_3_START (11)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_ulpsactivenot_3_END (11)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_errsyncesc_0_START (12)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_errsyncesc_0_END (12)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_errsyncesc_1_START (13)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_errsyncesc_1_END (13)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_errsyncesc_2_START (14)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_errsyncesc_2_END (14)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_errsyncesc_3_START (15)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_errsyncesc_3_END (15)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_ulpsactivenotclk_START (16)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_ulpsactivenotclk_END (16)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxinvalidcodehs_0_START (20)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxinvalidcodehs_0_END (21)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxinvalidcodehs_1_START (22)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxinvalidcodehs_1_END (23)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxinvalidcodehs_2_START (24)
#define SOC_CSI_WRAPPER_PHY_CSI_F_DBG_phyf_rxinvalidcodehs_2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idi_sel_f : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_F_IDI_SEL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_F_IDI_SEL_idi_sel_f_START (0)
#define SOC_CSI_WRAPPER_CSI_F_IDI_SEL_idi_sel_f_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csif_force_pclk_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_F_FORCE_PCLKON_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_F_FORCE_PCLKON_csif_force_pclk_on_START (0)
#define SOC_CSI_WRAPPER_CSI_F_FORCE_PCLKON_csif_force_pclk_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csig : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSIG_CGR_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIG_CGR_cg_csig_START (0)
#define SOC_CSI_WRAPPER_CSIG_CGR_cg_csig_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csig : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSIG_CGR_SET_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIG_CGR_SET_cg_csig_START (0)
#define SOC_CSI_WRAPPER_CSIG_CGR_SET_cg_csig_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csig : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSIG_CGR_CLEAR_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIG_CGR_CLEAR_cg_csig_START (0)
#define SOC_CSI_WRAPPER_CSIG_CGR_CLEAR_cg_csig_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_rst_csig : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSIG_RESET_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIG_RESET_soft_rst_csig_START (0)
#define SOC_CSI_WRAPPER_CSIG_RESET_soft_rst_csig_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyg_rxactivehs_0 : 1;
        unsigned int phyg_rxactivehs_1 : 1;
        unsigned int phyg_rxactivehs_2 : 1;
        unsigned int phyg_rxactivehs_3 : 1;
        unsigned int phyg_rxlpdtesc_0 : 1;
        unsigned int phyg_rxlpdtesc_1 : 1;
        unsigned int phyg_rxlpdtesc_2 : 1;
        unsigned int phyg_rxlpdtesc_3 : 1;
        unsigned int phyg_ulpsactivenot_0 : 1;
        unsigned int phyg_ulpsactivenot_1 : 1;
        unsigned int phyg_ulpsactivenot_2 : 1;
        unsigned int phyg_ulpsactivenot_3 : 1;
        unsigned int phyg_errsyncesc_0 : 1;
        unsigned int phyg_errsyncesc_1 : 1;
        unsigned int phyg_errsyncesc_2 : 1;
        unsigned int phyg_errsyncesc_3 : 1;
        unsigned int phyg_ulpsactivenotclk : 1;
        unsigned int reserved_0 : 3;
        unsigned int phyg_rxinvalidcodehs_0 : 2;
        unsigned int phyg_rxinvalidcodehs_1 : 2;
        unsigned int phyg_rxinvalidcodehs_2 : 2;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_G_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxactivehs_0_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxactivehs_0_END (0)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxactivehs_1_START (1)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxactivehs_1_END (1)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxactivehs_2_START (2)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxactivehs_2_END (2)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxactivehs_3_START (3)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxactivehs_3_END (3)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxlpdtesc_0_START (4)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxlpdtesc_0_END (4)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxlpdtesc_1_START (5)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxlpdtesc_1_END (5)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxlpdtesc_2_START (6)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxlpdtesc_2_END (6)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxlpdtesc_3_START (7)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxlpdtesc_3_END (7)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_ulpsactivenot_0_START (8)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_ulpsactivenot_0_END (8)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_ulpsactivenot_1_START (9)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_ulpsactivenot_1_END (9)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_ulpsactivenot_2_START (10)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_ulpsactivenot_2_END (10)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_ulpsactivenot_3_START (11)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_ulpsactivenot_3_END (11)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_errsyncesc_0_START (12)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_errsyncesc_0_END (12)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_errsyncesc_1_START (13)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_errsyncesc_1_END (13)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_errsyncesc_2_START (14)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_errsyncesc_2_END (14)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_errsyncesc_3_START (15)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_errsyncesc_3_END (15)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_ulpsactivenotclk_START (16)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_ulpsactivenotclk_END (16)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxinvalidcodehs_0_START (20)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxinvalidcodehs_0_END (21)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxinvalidcodehs_1_START (22)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxinvalidcodehs_1_END (23)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxinvalidcodehs_2_START (24)
#define SOC_CSI_WRAPPER_PHY_CSI_G_DBG_phyg_rxinvalidcodehs_2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idi_sel_g : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_G_IDI_SEL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_G_IDI_SEL_idi_sel_g_START (0)
#define SOC_CSI_WRAPPER_CSI_G_IDI_SEL_idi_sel_g_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csig_force_pclk_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_G_FORCE_PCLKON_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_G_FORCE_PCLKON_csig_force_pclk_on_START (0)
#define SOC_CSI_WRAPPER_CSI_G_FORCE_PCLKON_csig_force_pclk_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phya_testdin : 10;
        unsigned int phya_testen : 1;
        unsigned int phya_testclr : 1;
        unsigned int phya_testclk : 1;
        unsigned int reserved : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_A_TEST_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_CTRL_phya_testdin_START (0)
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_CTRL_phya_testdin_END (9)
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_CTRL_phya_testen_START (10)
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_CTRL_phya_testen_END (10)
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_CTRL_phya_testclr_START (11)
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_CTRL_phya_testclr_END (11)
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_CTRL_phya_testclk_START (12)
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_CTRL_phya_testclk_END (12)
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_CTRL_bitmasken_START (16)
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_CTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phya_testdout : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_A_TEST_DOUT_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_DOUT_phya_testdout_START (0)
#define SOC_CSI_WRAPPER_CDPHY_A_TEST_DOUT_phya_testdout_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phya_rstz : 1;
        unsigned int phya_shutdownz : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_A_SHUTDOWN_RST_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_A_SHUTDOWN_RST_CTRL_phya_rstz_START (0)
#define SOC_CSI_WRAPPER_CDPHY_A_SHUTDOWN_RST_CTRL_phya_rstz_END (0)
#define SOC_CSI_WRAPPER_CDPHY_A_SHUTDOWN_RST_CTRL_phya_shutdownz_START (1)
#define SOC_CSI_WRAPPER_CDPHY_A_SHUTDOWN_RST_CTRL_phya_shutdownz_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phya_enable_0 : 1;
        unsigned int phya_enable_1 : 1;
        unsigned int phya_enable_2 : 1;
        unsigned int phya_enable_3 : 1;
        unsigned int phya_enableclk_0 : 1;
        unsigned int phya_enableclk_1 : 1;
        unsigned int phya_cdphy_rx_sel : 1;
        unsigned int phya_lane1_clk_en : 1;
        unsigned int phya_rxdatawidthhs_0_cphy : 2;
        unsigned int phya_rxdatawidthhs_1_cphy : 2;
        unsigned int phya_rxdatawidthhs_2_cphy : 2;
        unsigned int phya_protocol_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int phya_rxdatawidthhs_0_dphy : 2;
        unsigned int phya_rxdatawidthhs_1_dphy : 2;
        unsigned int phya_vote_cnt : 2;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_A_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_enable_0_START (0)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_enable_0_END (0)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_enable_1_START (1)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_enable_1_END (1)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_enable_2_START (2)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_enable_2_END (2)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_enable_3_START (3)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_enable_3_END (3)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_enableclk_0_START (4)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_enableclk_0_END (4)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_enableclk_1_START (5)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_enableclk_1_END (5)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_cdphy_rx_sel_START (6)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_cdphy_rx_sel_END (6)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_lane1_clk_en_START (7)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_lane1_clk_en_END (7)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_rxdatawidthhs_0_cphy_START (8)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_rxdatawidthhs_0_cphy_END (9)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_rxdatawidthhs_1_cphy_START (10)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_rxdatawidthhs_1_cphy_END (11)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_rxdatawidthhs_2_cphy_START (12)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_rxdatawidthhs_2_cphy_END (13)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_protocol_sel_START (14)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_protocol_sel_END (14)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_rxdatawidthhs_0_dphy_START (16)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_rxdatawidthhs_0_dphy_END (17)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_rxdatawidthhs_1_dphy_START (18)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_rxdatawidthhs_1_dphy_END (19)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_vote_cnt_START (20)
#define SOC_CSI_WRAPPER_CDPHY_A_CTRL_phya_vote_cnt_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phya_lock_wr_vld : 1;
        unsigned int phya_lock_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_A_LOCK_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_A_LOCK_CTRL_phya_lock_wr_vld_START (0)
#define SOC_CSI_WRAPPER_CDPHY_A_LOCK_CTRL_phya_lock_wr_vld_END (0)
#define SOC_CSI_WRAPPER_CDPHY_A_LOCK_CTRL_phya_lock_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_A_LOCK_CTRL_phya_lock_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phya_unlock_wr_vld : 1;
        unsigned int phya_unlocked_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_A_UNLOCK_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_A_UNLOCK_CTRL_phya_unlock_wr_vld_START (0)
#define SOC_CSI_WRAPPER_CDPHY_A_UNLOCK_CTRL_phya_unlock_wr_vld_END (0)
#define SOC_CSI_WRAPPER_CDPHY_A_UNLOCK_CTRL_phya_unlocked_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_A_UNLOCK_CTRL_phya_unlocked_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phya_lock_status : 1;
        unsigned int phya_locked_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_A_LOCK_STATE_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_A_LOCK_STATE_phya_lock_status_START (0)
#define SOC_CSI_WRAPPER_CDPHY_A_LOCK_STATE_phya_lock_status_END (0)
#define SOC_CSI_WRAPPER_CDPHY_A_LOCK_STATE_phya_locked_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_A_LOCK_STATE_phya_locked_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phya_rx_dbg_out : 24;
        unsigned int phya_clk_dbg_cnt : 8;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_A_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_A_DBG_phya_rx_dbg_out_START (0)
#define SOC_CSI_WRAPPER_CDPHY_A_DBG_phya_rx_dbg_out_END (23)
#define SOC_CSI_WRAPPER_CDPHY_A_DBG_phya_clk_dbg_cnt_START (24)
#define SOC_CSI_WRAPPER_CDPHY_A_DBG_phya_clk_dbg_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_rst_phya : 1;
        unsigned int cg_phya : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_A_CLKRST_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_A_CLKRST_soft_rst_phya_START (0)
#define SOC_CSI_WRAPPER_CDPHY_A_CLKRST_soft_rst_phya_END (0)
#define SOC_CSI_WRAPPER_CDPHY_A_CLKRST_cg_phya_START (1)
#define SOC_CSI_WRAPPER_CDPHY_A_CLKRST_cg_phya_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyb_testdin : 10;
        unsigned int phyb_testen : 1;
        unsigned int phyb_testclr : 1;
        unsigned int phyb_testclk : 1;
        unsigned int reserved : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_B_TEST_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_CTRL_phyb_testdin_START (0)
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_CTRL_phyb_testdin_END (9)
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_CTRL_phyb_testen_START (10)
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_CTRL_phyb_testen_END (10)
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_CTRL_phyb_testclr_START (11)
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_CTRL_phyb_testclr_END (11)
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_CTRL_phyb_testclk_START (12)
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_CTRL_phyb_testclk_END (12)
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_CTRL_bitmasken_START (16)
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_CTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyb_testdout : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_B_TEST_DOUT_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_DOUT_phyb_testdout_START (0)
#define SOC_CSI_WRAPPER_CDPHY_B_TEST_DOUT_phyb_testdout_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyb_rstz : 1;
        unsigned int phyb_shutdownz : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_B_SHUTDOWN_RST_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_B_SHUTDOWN_RST_CTRL_phyb_rstz_START (0)
#define SOC_CSI_WRAPPER_CDPHY_B_SHUTDOWN_RST_CTRL_phyb_rstz_END (0)
#define SOC_CSI_WRAPPER_CDPHY_B_SHUTDOWN_RST_CTRL_phyb_shutdownz_START (1)
#define SOC_CSI_WRAPPER_CDPHY_B_SHUTDOWN_RST_CTRL_phyb_shutdownz_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyb_enable_0 : 1;
        unsigned int phyb_enable_1 : 1;
        unsigned int phyb_enable_2 : 1;
        unsigned int phyb_enable_3 : 1;
        unsigned int phyb_enableclk_0 : 1;
        unsigned int phyb_enableclk_1 : 1;
        unsigned int phyb_cdphy_rx_sel : 1;
        unsigned int phyb_lane1_clk_en : 1;
        unsigned int phyb_rxdatawidthhs_0_cphy : 2;
        unsigned int phyb_rxdatawidthhs_1_cphy : 2;
        unsigned int phyb_rxdatawidthhs_2_cphy : 2;
        unsigned int phyb_protocol_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int phyb_rxdatawidthhs_0_dphy : 2;
        unsigned int phyb_rxdatawidthhs_1_dphy : 2;
        unsigned int phyb_vote_cnt : 2;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_B_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_enable_0_START (0)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_enable_0_END (0)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_enable_1_START (1)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_enable_1_END (1)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_enable_2_START (2)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_enable_2_END (2)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_enable_3_START (3)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_enable_3_END (3)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_enableclk_0_START (4)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_enableclk_0_END (4)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_enableclk_1_START (5)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_enableclk_1_END (5)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_cdphy_rx_sel_START (6)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_cdphy_rx_sel_END (6)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_lane1_clk_en_START (7)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_lane1_clk_en_END (7)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_rxdatawidthhs_0_cphy_START (8)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_rxdatawidthhs_0_cphy_END (9)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_rxdatawidthhs_1_cphy_START (10)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_rxdatawidthhs_1_cphy_END (11)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_rxdatawidthhs_2_cphy_START (12)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_rxdatawidthhs_2_cphy_END (13)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_protocol_sel_START (14)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_protocol_sel_END (14)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_rxdatawidthhs_0_dphy_START (16)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_rxdatawidthhs_0_dphy_END (17)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_rxdatawidthhs_1_dphy_START (18)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_rxdatawidthhs_1_dphy_END (19)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_vote_cnt_START (20)
#define SOC_CSI_WRAPPER_CDPHY_B_CTRL_phyb_vote_cnt_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyb_lock_wr_vld : 1;
        unsigned int phyb_lock_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_B_LOCK_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_B_LOCK_CTRL_phyb_lock_wr_vld_START (0)
#define SOC_CSI_WRAPPER_CDPHY_B_LOCK_CTRL_phyb_lock_wr_vld_END (0)
#define SOC_CSI_WRAPPER_CDPHY_B_LOCK_CTRL_phyb_lock_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_B_LOCK_CTRL_phyb_lock_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyb_unlock_wr_vld : 1;
        unsigned int phyb_unlocked_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_B_UNLOCK_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_B_UNLOCK_CTRL_phyb_unlock_wr_vld_START (0)
#define SOC_CSI_WRAPPER_CDPHY_B_UNLOCK_CTRL_phyb_unlock_wr_vld_END (0)
#define SOC_CSI_WRAPPER_CDPHY_B_UNLOCK_CTRL_phyb_unlocked_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_B_UNLOCK_CTRL_phyb_unlocked_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyb_lock_status : 1;
        unsigned int phyb_locked_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_B_LOCK_STATE_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_B_LOCK_STATE_phyb_lock_status_START (0)
#define SOC_CSI_WRAPPER_CDPHY_B_LOCK_STATE_phyb_lock_status_END (0)
#define SOC_CSI_WRAPPER_CDPHY_B_LOCK_STATE_phyb_locked_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_B_LOCK_STATE_phyb_locked_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyb_rx_dbg_out : 24;
        unsigned int phyb_clk_dbg_cnt : 8;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_B_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_B_DBG_phyb_rx_dbg_out_START (0)
#define SOC_CSI_WRAPPER_CDPHY_B_DBG_phyb_rx_dbg_out_END (23)
#define SOC_CSI_WRAPPER_CDPHY_B_DBG_phyb_clk_dbg_cnt_START (24)
#define SOC_CSI_WRAPPER_CDPHY_B_DBG_phyb_clk_dbg_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_rst_phyb : 1;
        unsigned int cg_phyb : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_B_CLKRST_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_B_CLKRST_soft_rst_phyb_START (0)
#define SOC_CSI_WRAPPER_CDPHY_B_CLKRST_soft_rst_phyb_END (0)
#define SOC_CSI_WRAPPER_CDPHY_B_CLKRST_cg_phyb_START (1)
#define SOC_CSI_WRAPPER_CDPHY_B_CLKRST_cg_phyb_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyc_testdin : 10;
        unsigned int phyc_testen : 1;
        unsigned int phyc_testclr : 1;
        unsigned int phyc_testclk : 1;
        unsigned int reserved : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_C_TEST_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_CTRL_phyc_testdin_START (0)
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_CTRL_phyc_testdin_END (9)
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_CTRL_phyc_testen_START (10)
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_CTRL_phyc_testen_END (10)
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_CTRL_phyc_testclr_START (11)
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_CTRL_phyc_testclr_END (11)
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_CTRL_phyc_testclk_START (12)
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_CTRL_phyc_testclk_END (12)
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_CTRL_bitmasken_START (16)
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_CTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyc_testdout : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_C_TEST_DOUT_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_DOUT_phyc_testdout_START (0)
#define SOC_CSI_WRAPPER_CDPHY_C_TEST_DOUT_phyc_testdout_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyc_rstz : 1;
        unsigned int phyc_shutdownz : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_C_SHUTDOWN_RST_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_C_SHUTDOWN_RST_CTRL_phyc_rstz_START (0)
#define SOC_CSI_WRAPPER_CDPHY_C_SHUTDOWN_RST_CTRL_phyc_rstz_END (0)
#define SOC_CSI_WRAPPER_CDPHY_C_SHUTDOWN_RST_CTRL_phyc_shutdownz_START (1)
#define SOC_CSI_WRAPPER_CDPHY_C_SHUTDOWN_RST_CTRL_phyc_shutdownz_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyc_enable_0 : 1;
        unsigned int phyc_enable_1 : 1;
        unsigned int phyc_enable_2 : 1;
        unsigned int phyc_enable_3 : 1;
        unsigned int phyc_enableclk_0 : 1;
        unsigned int phyc_enableclk_1 : 1;
        unsigned int phyc_cdphy_rx_sel : 1;
        unsigned int phyc_lane1_clk_en : 1;
        unsigned int phyc_rxdatawidthhs_0_cphy : 2;
        unsigned int phyc_rxdatawidthhs_1_cphy : 2;
        unsigned int phyc_rxdatawidthhs_2_cphy : 2;
        unsigned int phyc_protocol_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int phyc_rxdatawidthhs_0_dphy : 2;
        unsigned int phyc_rxdatawidthhs_1_dphy : 2;
        unsigned int phyc_vote_cnt : 2;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_C_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_enable_0_START (0)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_enable_0_END (0)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_enable_1_START (1)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_enable_1_END (1)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_enable_2_START (2)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_enable_2_END (2)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_enable_3_START (3)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_enable_3_END (3)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_enableclk_0_START (4)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_enableclk_0_END (4)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_enableclk_1_START (5)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_enableclk_1_END (5)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_cdphy_rx_sel_START (6)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_cdphy_rx_sel_END (6)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_lane1_clk_en_START (7)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_lane1_clk_en_END (7)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_rxdatawidthhs_0_cphy_START (8)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_rxdatawidthhs_0_cphy_END (9)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_rxdatawidthhs_1_cphy_START (10)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_rxdatawidthhs_1_cphy_END (11)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_rxdatawidthhs_2_cphy_START (12)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_rxdatawidthhs_2_cphy_END (13)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_protocol_sel_START (14)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_protocol_sel_END (14)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_rxdatawidthhs_0_dphy_START (16)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_rxdatawidthhs_0_dphy_END (17)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_rxdatawidthhs_1_dphy_START (18)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_rxdatawidthhs_1_dphy_END (19)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_vote_cnt_START (20)
#define SOC_CSI_WRAPPER_CDPHY_C_CTRL_phyc_vote_cnt_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyc_lock_wr_vld : 1;
        unsigned int phyc_lock_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_C_LOCK_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_C_LOCK_CTRL_phyc_lock_wr_vld_START (0)
#define SOC_CSI_WRAPPER_CDPHY_C_LOCK_CTRL_phyc_lock_wr_vld_END (0)
#define SOC_CSI_WRAPPER_CDPHY_C_LOCK_CTRL_phyc_lock_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_C_LOCK_CTRL_phyc_lock_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyc_unlock_wr_vld : 1;
        unsigned int phyc_unlocked_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_C_UNLOCK_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_C_UNLOCK_CTRL_phyc_unlock_wr_vld_START (0)
#define SOC_CSI_WRAPPER_CDPHY_C_UNLOCK_CTRL_phyc_unlock_wr_vld_END (0)
#define SOC_CSI_WRAPPER_CDPHY_C_UNLOCK_CTRL_phyc_unlocked_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_C_UNLOCK_CTRL_phyc_unlocked_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyc_lock_status : 1;
        unsigned int phyc_locked_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_C_LOCK_STATE_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_C_LOCK_STATE_phyc_lock_status_START (0)
#define SOC_CSI_WRAPPER_CDPHY_C_LOCK_STATE_phyc_lock_status_END (0)
#define SOC_CSI_WRAPPER_CDPHY_C_LOCK_STATE_phyc_locked_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_C_LOCK_STATE_phyc_locked_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyc_rx_dbg_out : 24;
        unsigned int phyc_clk_dbg_cnt : 8;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_C_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_C_DBG_phyc_rx_dbg_out_START (0)
#define SOC_CSI_WRAPPER_CDPHY_C_DBG_phyc_rx_dbg_out_END (23)
#define SOC_CSI_WRAPPER_CDPHY_C_DBG_phyc_clk_dbg_cnt_START (24)
#define SOC_CSI_WRAPPER_CDPHY_C_DBG_phyc_clk_dbg_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_rst_phyc : 1;
        unsigned int cg_phyc : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_C_CLKRST_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_C_CLKRST_soft_rst_phyc_START (0)
#define SOC_CSI_WRAPPER_CDPHY_C_CLKRST_soft_rst_phyc_END (0)
#define SOC_CSI_WRAPPER_CDPHY_C_CLKRST_cg_phyc_START (1)
#define SOC_CSI_WRAPPER_CDPHY_C_CLKRST_cg_phyc_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyd_testdin : 10;
        unsigned int phyd_testen : 1;
        unsigned int phyd_testclr : 1;
        unsigned int phyd_testclk : 1;
        unsigned int reserved : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_D_TEST_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_CTRL_phyd_testdin_START (0)
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_CTRL_phyd_testdin_END (9)
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_CTRL_phyd_testen_START (10)
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_CTRL_phyd_testen_END (10)
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_CTRL_phyd_testclr_START (11)
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_CTRL_phyd_testclr_END (11)
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_CTRL_phyd_testclk_START (12)
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_CTRL_phyd_testclk_END (12)
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_CTRL_bitmasken_START (16)
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_CTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyd_testdout : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_D_TEST_DOUT_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_DOUT_phyd_testdout_START (0)
#define SOC_CSI_WRAPPER_CDPHY_D_TEST_DOUT_phyd_testdout_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyd_rstz : 1;
        unsigned int phyd_shutdownz : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_D_SHUTDOWN_RST_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_D_SHUTDOWN_RST_CTRL_phyd_rstz_START (0)
#define SOC_CSI_WRAPPER_CDPHY_D_SHUTDOWN_RST_CTRL_phyd_rstz_END (0)
#define SOC_CSI_WRAPPER_CDPHY_D_SHUTDOWN_RST_CTRL_phyd_shutdownz_START (1)
#define SOC_CSI_WRAPPER_CDPHY_D_SHUTDOWN_RST_CTRL_phyd_shutdownz_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyd_enable_0 : 1;
        unsigned int phyd_enable_1 : 1;
        unsigned int phyd_enable_2 : 1;
        unsigned int phyd_enable_3 : 1;
        unsigned int phyd_enableclk_0 : 1;
        unsigned int phyd_enableclk_1 : 1;
        unsigned int phyd_cdphy_rx_sel : 1;
        unsigned int phyd_lane1_clk_en : 1;
        unsigned int phyd_rxdatawidthhs_0_cphy : 2;
        unsigned int phyd_rxdatawidthhs_1_cphy : 2;
        unsigned int phyd_rxdatawidthhs_2_cphy : 2;
        unsigned int phyd_protocol_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int phyd_rxdatawidthhs_0_dphy : 2;
        unsigned int phyd_rxdatawidthhs_1_dphy : 2;
        unsigned int phyd_vote_cnt : 2;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_D_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_enable_0_START (0)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_enable_0_END (0)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_enable_1_START (1)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_enable_1_END (1)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_enable_2_START (2)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_enable_2_END (2)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_enable_3_START (3)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_enable_3_END (3)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_enableclk_0_START (4)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_enableclk_0_END (4)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_enableclk_1_START (5)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_enableclk_1_END (5)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_cdphy_rx_sel_START (6)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_cdphy_rx_sel_END (6)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_lane1_clk_en_START (7)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_lane1_clk_en_END (7)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_rxdatawidthhs_0_cphy_START (8)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_rxdatawidthhs_0_cphy_END (9)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_rxdatawidthhs_1_cphy_START (10)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_rxdatawidthhs_1_cphy_END (11)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_rxdatawidthhs_2_cphy_START (12)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_rxdatawidthhs_2_cphy_END (13)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_protocol_sel_START (14)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_protocol_sel_END (14)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_rxdatawidthhs_0_dphy_START (16)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_rxdatawidthhs_0_dphy_END (17)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_rxdatawidthhs_1_dphy_START (18)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_rxdatawidthhs_1_dphy_END (19)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_vote_cnt_START (20)
#define SOC_CSI_WRAPPER_CDPHY_D_CTRL_phyd_vote_cnt_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyd_lock_wr_vld : 1;
        unsigned int phyd_lock_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_D_LOCK_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_D_LOCK_CTRL_phyd_lock_wr_vld_START (0)
#define SOC_CSI_WRAPPER_CDPHY_D_LOCK_CTRL_phyd_lock_wr_vld_END (0)
#define SOC_CSI_WRAPPER_CDPHY_D_LOCK_CTRL_phyd_lock_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_D_LOCK_CTRL_phyd_lock_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyd_unlock_wr_vld : 1;
        unsigned int phyd_unlocked_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_D_UNLOCK_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_D_UNLOCK_CTRL_phyd_unlock_wr_vld_START (0)
#define SOC_CSI_WRAPPER_CDPHY_D_UNLOCK_CTRL_phyd_unlock_wr_vld_END (0)
#define SOC_CSI_WRAPPER_CDPHY_D_UNLOCK_CTRL_phyd_unlocked_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_D_UNLOCK_CTRL_phyd_unlocked_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyd_lock_status : 1;
        unsigned int phyd_locked_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_D_LOCK_STATE_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_D_LOCK_STATE_phyd_lock_status_START (0)
#define SOC_CSI_WRAPPER_CDPHY_D_LOCK_STATE_phyd_lock_status_END (0)
#define SOC_CSI_WRAPPER_CDPHY_D_LOCK_STATE_phyd_locked_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_D_LOCK_STATE_phyd_locked_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyd_rx_dbg_out : 24;
        unsigned int phyd_clk_dbg_cnt : 8;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_D_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_D_DBG_phyd_rx_dbg_out_START (0)
#define SOC_CSI_WRAPPER_CDPHY_D_DBG_phyd_rx_dbg_out_END (23)
#define SOC_CSI_WRAPPER_CDPHY_D_DBG_phyd_clk_dbg_cnt_START (24)
#define SOC_CSI_WRAPPER_CDPHY_D_DBG_phyd_clk_dbg_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_rst_phyd : 1;
        unsigned int cg_phyd : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_D_CLKRST_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_D_CLKRST_soft_rst_phyd_START (0)
#define SOC_CSI_WRAPPER_CDPHY_D_CLKRST_soft_rst_phyd_END (0)
#define SOC_CSI_WRAPPER_CDPHY_D_CLKRST_cg_phyd_START (1)
#define SOC_CSI_WRAPPER_CDPHY_D_CLKRST_cg_phyd_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phye_testdin : 10;
        unsigned int phye_testen : 1;
        unsigned int phye_testclr : 1;
        unsigned int phye_testclk : 1;
        unsigned int reserved : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_E_TEST_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_CTRL_phye_testdin_START (0)
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_CTRL_phye_testdin_END (9)
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_CTRL_phye_testen_START (10)
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_CTRL_phye_testen_END (10)
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_CTRL_phye_testclr_START (11)
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_CTRL_phye_testclr_END (11)
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_CTRL_phye_testclk_START (12)
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_CTRL_phye_testclk_END (12)
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_CTRL_bitmasken_START (16)
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_CTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phye_testdout : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_E_TEST_DOUT_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_DOUT_phye_testdout_START (0)
#define SOC_CSI_WRAPPER_CDPHY_E_TEST_DOUT_phye_testdout_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phye_rstz : 1;
        unsigned int phye_shutdownz : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_E_SHUTDOWN_RST_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_E_SHUTDOWN_RST_CTRL_phye_rstz_START (0)
#define SOC_CSI_WRAPPER_CDPHY_E_SHUTDOWN_RST_CTRL_phye_rstz_END (0)
#define SOC_CSI_WRAPPER_CDPHY_E_SHUTDOWN_RST_CTRL_phye_shutdownz_START (1)
#define SOC_CSI_WRAPPER_CDPHY_E_SHUTDOWN_RST_CTRL_phye_shutdownz_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phye_enable_0 : 1;
        unsigned int phye_enable_1 : 1;
        unsigned int phye_enable_2 : 1;
        unsigned int phye_enable_3 : 1;
        unsigned int phye_enableclk_0 : 1;
        unsigned int phye_enableclk_1 : 1;
        unsigned int phye_cdphy_rx_sel : 1;
        unsigned int phye_lane1_clk_en : 1;
        unsigned int phye_rxdatawidthhs_0_cphy : 2;
        unsigned int phye_rxdatawidthhs_1_cphy : 2;
        unsigned int phye_rxdatawidthhs_2_cphy : 2;
        unsigned int phye_protocol_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int phye_rxdatawidthhs_0_dphy : 2;
        unsigned int phye_rxdatawidthhs_1_dphy : 2;
        unsigned int phye_vote_cnt : 2;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_E_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_enable_0_START (0)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_enable_0_END (0)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_enable_1_START (1)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_enable_1_END (1)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_enable_2_START (2)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_enable_2_END (2)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_enable_3_START (3)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_enable_3_END (3)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_enableclk_0_START (4)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_enableclk_0_END (4)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_enableclk_1_START (5)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_enableclk_1_END (5)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_cdphy_rx_sel_START (6)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_cdphy_rx_sel_END (6)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_lane1_clk_en_START (7)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_lane1_clk_en_END (7)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_rxdatawidthhs_0_cphy_START (8)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_rxdatawidthhs_0_cphy_END (9)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_rxdatawidthhs_1_cphy_START (10)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_rxdatawidthhs_1_cphy_END (11)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_rxdatawidthhs_2_cphy_START (12)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_rxdatawidthhs_2_cphy_END (13)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_protocol_sel_START (14)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_protocol_sel_END (14)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_rxdatawidthhs_0_dphy_START (16)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_rxdatawidthhs_0_dphy_END (17)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_rxdatawidthhs_1_dphy_START (18)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_rxdatawidthhs_1_dphy_END (19)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_vote_cnt_START (20)
#define SOC_CSI_WRAPPER_CDPHY_E_CTRL_phye_vote_cnt_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phye_lock_wr_vld : 1;
        unsigned int phye_lock_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_E_LOCK_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_E_LOCK_CTRL_phye_lock_wr_vld_START (0)
#define SOC_CSI_WRAPPER_CDPHY_E_LOCK_CTRL_phye_lock_wr_vld_END (0)
#define SOC_CSI_WRAPPER_CDPHY_E_LOCK_CTRL_phye_lock_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_E_LOCK_CTRL_phye_lock_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phye_unlock_wr_vld : 1;
        unsigned int phye_unlocked_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_E_UNLOCK_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_E_UNLOCK_CTRL_phye_unlock_wr_vld_START (0)
#define SOC_CSI_WRAPPER_CDPHY_E_UNLOCK_CTRL_phye_unlock_wr_vld_END (0)
#define SOC_CSI_WRAPPER_CDPHY_E_UNLOCK_CTRL_phye_unlocked_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_E_UNLOCK_CTRL_phye_unlocked_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phye_lock_status : 1;
        unsigned int phye_locked_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_E_LOCK_STATE_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_E_LOCK_STATE_phye_lock_status_START (0)
#define SOC_CSI_WRAPPER_CDPHY_E_LOCK_STATE_phye_lock_status_END (0)
#define SOC_CSI_WRAPPER_CDPHY_E_LOCK_STATE_phye_locked_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_E_LOCK_STATE_phye_locked_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phye_rx_dbg_out : 24;
        unsigned int phye_clk_dbg_cnt : 8;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_E_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_E_DBG_phye_rx_dbg_out_START (0)
#define SOC_CSI_WRAPPER_CDPHY_E_DBG_phye_rx_dbg_out_END (23)
#define SOC_CSI_WRAPPER_CDPHY_E_DBG_phye_clk_dbg_cnt_START (24)
#define SOC_CSI_WRAPPER_CDPHY_E_DBG_phye_clk_dbg_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_rst_phye : 1;
        unsigned int cg_phye : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_E_CLKRST_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_E_CLKRST_soft_rst_phye_START (0)
#define SOC_CSI_WRAPPER_CDPHY_E_CLKRST_soft_rst_phye_END (0)
#define SOC_CSI_WRAPPER_CDPHY_E_CLKRST_cg_phye_START (1)
#define SOC_CSI_WRAPPER_CDPHY_E_CLKRST_cg_phye_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyf_testdin : 10;
        unsigned int phyf_testen : 1;
        unsigned int phyf_testclr : 1;
        unsigned int phyf_testclk : 1;
        unsigned int reserved : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_F_TEST_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_CTRL_phyf_testdin_START (0)
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_CTRL_phyf_testdin_END (9)
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_CTRL_phyf_testen_START (10)
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_CTRL_phyf_testen_END (10)
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_CTRL_phyf_testclr_START (11)
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_CTRL_phyf_testclr_END (11)
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_CTRL_phyf_testclk_START (12)
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_CTRL_phyf_testclk_END (12)
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_CTRL_bitmasken_START (16)
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_CTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyf_testdout : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_F_TEST_DOUT_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_DOUT_phyf_testdout_START (0)
#define SOC_CSI_WRAPPER_CDPHY_F_TEST_DOUT_phyf_testdout_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyf_rstz : 1;
        unsigned int phyf_shutdownz : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_F_SHUTDOWN_RST_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_F_SHUTDOWN_RST_CTRL_phyf_rstz_START (0)
#define SOC_CSI_WRAPPER_CDPHY_F_SHUTDOWN_RST_CTRL_phyf_rstz_END (0)
#define SOC_CSI_WRAPPER_CDPHY_F_SHUTDOWN_RST_CTRL_phyf_shutdownz_START (1)
#define SOC_CSI_WRAPPER_CDPHY_F_SHUTDOWN_RST_CTRL_phyf_shutdownz_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyf_enable_0 : 1;
        unsigned int phyf_enable_1 : 1;
        unsigned int phyf_enable_2 : 1;
        unsigned int phyf_enable_3 : 1;
        unsigned int phyf_enableclk_0 : 1;
        unsigned int phyf_enableclk_1 : 1;
        unsigned int phyf_cdphy_rx_sel : 1;
        unsigned int phyf_lane1_clk_en : 1;
        unsigned int phyf_rxdatawidthhs_0_cphy : 2;
        unsigned int phyf_rxdatawidthhs_1_cphy : 2;
        unsigned int phyf_rxdatawidthhs_2_cphy : 2;
        unsigned int phyf_protocol_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int phyf_rxdatawidthhs_0_dphy : 2;
        unsigned int phyf_rxdatawidthhs_1_dphy : 2;
        unsigned int phyf_vote_cnt : 2;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_F_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_enable_0_START (0)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_enable_0_END (0)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_enable_1_START (1)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_enable_1_END (1)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_enable_2_START (2)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_enable_2_END (2)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_enable_3_START (3)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_enable_3_END (3)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_enableclk_0_START (4)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_enableclk_0_END (4)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_enableclk_1_START (5)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_enableclk_1_END (5)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_cdphy_rx_sel_START (6)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_cdphy_rx_sel_END (6)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_lane1_clk_en_START (7)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_lane1_clk_en_END (7)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_rxdatawidthhs_0_cphy_START (8)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_rxdatawidthhs_0_cphy_END (9)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_rxdatawidthhs_1_cphy_START (10)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_rxdatawidthhs_1_cphy_END (11)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_rxdatawidthhs_2_cphy_START (12)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_rxdatawidthhs_2_cphy_END (13)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_protocol_sel_START (14)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_protocol_sel_END (14)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_rxdatawidthhs_0_dphy_START (16)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_rxdatawidthhs_0_dphy_END (17)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_rxdatawidthhs_1_dphy_START (18)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_rxdatawidthhs_1_dphy_END (19)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_vote_cnt_START (20)
#define SOC_CSI_WRAPPER_CDPHY_F_CTRL_phyf_vote_cnt_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyf_lock_wr_vld : 1;
        unsigned int phyf_lock_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_F_LOCK_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_F_LOCK_CTRL_phyf_lock_wr_vld_START (0)
#define SOC_CSI_WRAPPER_CDPHY_F_LOCK_CTRL_phyf_lock_wr_vld_END (0)
#define SOC_CSI_WRAPPER_CDPHY_F_LOCK_CTRL_phyf_lock_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_F_LOCK_CTRL_phyf_lock_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyf_unlock_wr_vld : 1;
        unsigned int phyf_unlocked_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_F_UNLOCK_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_F_UNLOCK_CTRL_phyf_unlock_wr_vld_START (0)
#define SOC_CSI_WRAPPER_CDPHY_F_UNLOCK_CTRL_phyf_unlock_wr_vld_END (0)
#define SOC_CSI_WRAPPER_CDPHY_F_UNLOCK_CTRL_phyf_unlocked_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_F_UNLOCK_CTRL_phyf_unlocked_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyf_lock_status : 1;
        unsigned int phyf_locked_mst_id : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_F_LOCK_STATE_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_F_LOCK_STATE_phyf_lock_status_START (0)
#define SOC_CSI_WRAPPER_CDPHY_F_LOCK_STATE_phyf_lock_status_END (0)
#define SOC_CSI_WRAPPER_CDPHY_F_LOCK_STATE_phyf_locked_mst_id_START (1)
#define SOC_CSI_WRAPPER_CDPHY_F_LOCK_STATE_phyf_locked_mst_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyf_rx_dbg_out : 24;
        unsigned int phyf_clk_dbg_cnt : 8;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_F_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_F_DBG_phyf_rx_dbg_out_START (0)
#define SOC_CSI_WRAPPER_CDPHY_F_DBG_phyf_rx_dbg_out_END (23)
#define SOC_CSI_WRAPPER_CDPHY_F_DBG_phyf_clk_dbg_cnt_START (24)
#define SOC_CSI_WRAPPER_CDPHY_F_DBG_phyf_clk_dbg_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_rst_phyf : 1;
        unsigned int cg_phyf : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CSI_WRAPPER_CDPHY_F_CLKRST_UNION;
#endif
#define SOC_CSI_WRAPPER_CDPHY_F_CLKRST_soft_rst_phyf_START (0)
#define SOC_CSI_WRAPPER_CDPHY_F_CLKRST_soft_rst_phyf_END (0)
#define SOC_CSI_WRAPPER_CDPHY_F_CLKRST_cg_phyf_START (1)
#define SOC_CSI_WRAPPER_CDPHY_F_CLKRST_cg_phyf_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csih : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSIH_CGR_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIH_CGR_cg_csih_START (0)
#define SOC_CSI_WRAPPER_CSIH_CGR_cg_csih_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csih : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSIH_CGR_SET_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIH_CGR_SET_cg_csih_START (0)
#define SOC_CSI_WRAPPER_CSIH_CGR_SET_cg_csih_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cg_csih : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSIH_CGR_CLEAR_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIH_CGR_CLEAR_cg_csih_START (0)
#define SOC_CSI_WRAPPER_CSIH_CGR_CLEAR_cg_csih_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soft_rst_csih : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSIH_RESET_UNION;
#endif
#define SOC_CSI_WRAPPER_CSIH_RESET_soft_rst_csih_START (0)
#define SOC_CSI_WRAPPER_CSIH_RESET_soft_rst_csih_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int phyh_rxactivehs_0 : 1;
        unsigned int phyh_rxactivehs_1 : 1;
        unsigned int phyh_rxactivehs_2 : 1;
        unsigned int phyh_rxactivehs_3 : 1;
        unsigned int phyh_rxlpdtesc_0 : 1;
        unsigned int phyh_rxlpdtesc_1 : 1;
        unsigned int phyh_rxlpdtesc_2 : 1;
        unsigned int phyh_rxlpdtesc_3 : 1;
        unsigned int phyh_ulpsactivenot_0 : 1;
        unsigned int phyh_ulpsactivenot_1 : 1;
        unsigned int phyh_ulpsactivenot_2 : 1;
        unsigned int phyh_ulpsactivenot_3 : 1;
        unsigned int phyh_errsyncesc_0 : 1;
        unsigned int phyh_errsyncesc_1 : 1;
        unsigned int phyh_errsyncesc_2 : 1;
        unsigned int phyh_errsyncesc_3 : 1;
        unsigned int phyh_ulpsactivenotclk : 1;
        unsigned int reserved_0 : 3;
        unsigned int phyh_rxinvalidcodehs_0 : 2;
        unsigned int phyh_rxinvalidcodehs_1 : 2;
        unsigned int phyh_rxinvalidcodehs_2 : 2;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_CSI_WRAPPER_PHY_CSI_H_DBG_UNION;
#endif
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxactivehs_0_START (0)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxactivehs_0_END (0)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxactivehs_1_START (1)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxactivehs_1_END (1)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxactivehs_2_START (2)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxactivehs_2_END (2)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxactivehs_3_START (3)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxactivehs_3_END (3)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxlpdtesc_0_START (4)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxlpdtesc_0_END (4)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxlpdtesc_1_START (5)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxlpdtesc_1_END (5)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxlpdtesc_2_START (6)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxlpdtesc_2_END (6)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxlpdtesc_3_START (7)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxlpdtesc_3_END (7)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_ulpsactivenot_0_START (8)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_ulpsactivenot_0_END (8)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_ulpsactivenot_1_START (9)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_ulpsactivenot_1_END (9)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_ulpsactivenot_2_START (10)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_ulpsactivenot_2_END (10)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_ulpsactivenot_3_START (11)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_ulpsactivenot_3_END (11)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_errsyncesc_0_START (12)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_errsyncesc_0_END (12)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_errsyncesc_1_START (13)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_errsyncesc_1_END (13)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_errsyncesc_2_START (14)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_errsyncesc_2_END (14)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_errsyncesc_3_START (15)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_errsyncesc_3_END (15)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_ulpsactivenotclk_START (16)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_ulpsactivenotclk_END (16)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxinvalidcodehs_0_START (20)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxinvalidcodehs_0_END (21)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxinvalidcodehs_1_START (22)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxinvalidcodehs_1_END (23)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxinvalidcodehs_2_START (24)
#define SOC_CSI_WRAPPER_PHY_CSI_H_DBG_phyh_rxinvalidcodehs_2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csih_force_pclk_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CSI_WRAPPER_CSI_H_FORCE_PCLKON_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_H_FORCE_PCLKON_csih_force_pclk_on_START (0)
#define SOC_CSI_WRAPPER_CSI_H_FORCE_PCLKON_csih_force_pclk_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csi_abc_secure : 1;
        unsigned int csi_d_secure : 1;
        unsigned int csi_e_secure : 1;
        unsigned int csi_dbg_secure : 1;
        unsigned int csi_h_secure : 1;
        unsigned int reserved_0 : 1;
        unsigned int csi_f_secure : 1;
        unsigned int csi_g_secure : 1;
        unsigned int phy_a_secure : 1;
        unsigned int phy_b_secure : 1;
        unsigned int phy_c_secure : 1;
        unsigned int phy_d_secure : 1;
        unsigned int phy_e_secure : 1;
        unsigned int phy_f_secure : 1;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_CSI_WRAPPER_S_UNION;
#endif
#define SOC_CSI_WRAPPER_S_csi_abc_secure_START (0)
#define SOC_CSI_WRAPPER_S_csi_abc_secure_END (0)
#define SOC_CSI_WRAPPER_S_csi_d_secure_START (1)
#define SOC_CSI_WRAPPER_S_csi_d_secure_END (1)
#define SOC_CSI_WRAPPER_S_csi_e_secure_START (2)
#define SOC_CSI_WRAPPER_S_csi_e_secure_END (2)
#define SOC_CSI_WRAPPER_S_csi_dbg_secure_START (3)
#define SOC_CSI_WRAPPER_S_csi_dbg_secure_END (3)
#define SOC_CSI_WRAPPER_S_csi_h_secure_START (4)
#define SOC_CSI_WRAPPER_S_csi_h_secure_END (4)
#define SOC_CSI_WRAPPER_S_csi_f_secure_START (6)
#define SOC_CSI_WRAPPER_S_csi_f_secure_END (6)
#define SOC_CSI_WRAPPER_S_csi_g_secure_START (7)
#define SOC_CSI_WRAPPER_S_csi_g_secure_END (7)
#define SOC_CSI_WRAPPER_S_phy_a_secure_START (8)
#define SOC_CSI_WRAPPER_S_phy_a_secure_END (8)
#define SOC_CSI_WRAPPER_S_phy_b_secure_START (9)
#define SOC_CSI_WRAPPER_S_phy_b_secure_END (9)
#define SOC_CSI_WRAPPER_S_phy_c_secure_START (10)
#define SOC_CSI_WRAPPER_S_phy_c_secure_END (10)
#define SOC_CSI_WRAPPER_S_phy_d_secure_START (11)
#define SOC_CSI_WRAPPER_S_phy_d_secure_END (11)
#define SOC_CSI_WRAPPER_S_phy_e_secure_START (12)
#define SOC_CSI_WRAPPER_S_phy_e_secure_END (12)
#define SOC_CSI_WRAPPER_S_phy_f_secure_START (13)
#define SOC_CSI_WRAPPER_S_phy_f_secure_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csia_idi_clk_sel : 1;
        unsigned int csib_idi_clk_sel : 1;
        unsigned int csic_idi_clk_sel : 1;
        unsigned int csid_idi_clk_sel : 1;
        unsigned int csie_idi_clk_sel : 1;
        unsigned int csif_idi_clk_sel : 1;
        unsigned int csig_idi_clk_sel : 1;
        unsigned int csih_idi_clk_sel : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_UNION;
#endif
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csia_idi_clk_sel_START (0)
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csia_idi_clk_sel_END (0)
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csib_idi_clk_sel_START (1)
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csib_idi_clk_sel_END (1)
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csic_idi_clk_sel_START (2)
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csic_idi_clk_sel_END (2)
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csid_idi_clk_sel_START (3)
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csid_idi_clk_sel_END (3)
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csie_idi_clk_sel_START (4)
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csie_idi_clk_sel_END (4)
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csif_idi_clk_sel_START (5)
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csif_idi_clk_sel_END (5)
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csig_idi_clk_sel_START (6)
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csig_idi_clk_sel_END (6)
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csih_idi_clk_sel_START (7)
#define SOC_CSI_WRAPPER_CSI_WRAP_CLK_CTRL_csih_idi_clk_sel_END (7)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
