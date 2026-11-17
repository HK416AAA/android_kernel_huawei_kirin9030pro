#ifndef __SOC_SCHARGERV800_INTERFACE_H__
#define __SOC_SCHARGERV800_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define REG_PD_BASE 0x0000
#define REG_FCP_BASE 0x0100
#define REG_ADC_BASE 0x0200
#define REG_GLB_BASE 0x0300
#define REG_COUL_PWR_BASE 0x0400
#define REG_COUL_NOPWR0_BASE 0x0500
#define REG_COUL_NOPWR1_BASE 0x0600
#define REG_IRQ_BASE 0x0800
#define REG_ANA_BASE 0x0900
#define REG_FER_BASE 0x0B00
#define REG_FLASH_BASE 0x1000
#define REG_UFCS_PAGE0_BASE 0x2000
#define REG_UFCS_PAGE1_BASE 0x2100
#define REG_UFCS_PAGE2_BASE 0x2200
#define REG_UFCS_PAGE3_BASE 0x2300
#define REG_UFCS_PAGE4_BASE 0x2400
#define REG_UFCS_PAGE5_BASE 0x2500
#ifndef __SOC_H_FOR_ASM__
#define REG_VENDIDL_ADDR(base) ((base) + (0x00UL))
#define REG_VENDIDH_ADDR(base) ((base) + (0x01UL))
#define REG_PRODIDL_ADDR(base) ((base) + (0x02UL))
#define REG_PRODIDH_ADDR(base) ((base) + (0x03UL))
#define REG_DEVIDL_ADDR(base) ((base) + (0x04UL))
#define REG_DEVIDH_ADDR(base) ((base) + (0x05UL))
#define REG_TYPECREVL_ADDR(base) ((base) + (0x06UL))
#define REG_TYPECREVH_ADDR(base) ((base) + (0x07UL))
#define REG_USBPDVER_ADDR(base) ((base) + (0x08UL))
#define REG_USBPDREV_ADDR(base) ((base) + (0x09UL))
#define REG_PDIFREVL_ADDR(base) ((base) + (0x0AUL))
#define REG_PDIFREVH_ADDR(base) ((base) + (0x0BUL))
#define REG_PD_ALERT_L_ADDR(base) ((base) + (0x10UL))
#define REG_PD_ALERT_H_ADDR(base) ((base) + (0x11UL))
#define REG_PD_ALERT_MSK_L_ADDR(base) ((base) + (0x12UL))
#define REG_PD_ALERT_MSK_H_ADDR(base) ((base) + (0x13UL))
#define REG_PD_PWRSTAT_MSK_ADDR(base) ((base) + (0x14UL))
#define REG_PD_FAULTSTAT_MSK_ADDR(base) ((base) + (0x15UL))
#define REG_EXTENDED_STATUS_MASK_ADDR(base) ((base) + (0x16UL))
#define REG_ALERT_EXTENDED_MASK_ADDR(base) ((base) + (0x17UL))
#define REG_PD_TCPC_CTRL_ADDR(base) ((base) + (0x19UL))
#define REG_PD_ROLE_CTRL_ADDR(base) ((base) + (0x1AUL))
#define REG_PD_FAULT_CTRL_ADDR(base) ((base) + (0x1BUL))
#define REG_PD_PWR_CTRL_ADDR(base) ((base) + (0x1CUL))
#define REG_PD_CC_STATUS_ADDR(base) ((base) + (0x1DUL))
#define REG_PD_PWR_STATUS_ADDR(base) ((base) + (0x1EUL))
#define REG_PD_FAULT_STATUS_ADDR(base) ((base) + (0x1FUL))
#define REG_EXTENDED_STATUS_ADDR(base) ((base) + (0x20UL))
#define REG_ALERT_EXTENDED_ADDR(base) ((base) + (0x21UL))
#define REG_PD_COMMAND_ADDR(base) ((base) + (0x23UL))
#define REG_PD_DEVCAP1L_ADDR(base) ((base) + (0x24UL))
#define REG_PD_DEVCAP1H_ADDR(base) ((base) + (0x25UL))
#define REG_PD_DEVCAP2L_ADDR(base) ((base) + (0x26UL))
#define REG_PD_DEVCAP2H_ADDR(base) ((base) + (0x27UL))
#define REG_PD_STDIN_CAP_ADDR(base) ((base) + (0x28UL))
#define REG_PD_STDOUT_CAP_ADDR(base) ((base) + (0x29UL))
#define REG_PD_MSG_HEADR_ADDR(base) ((base) + (0x2EUL))
#define REG_PD_RXDETECT_ADDR(base) ((base) + (0x2FUL))
#define REG_PD_RXBYTECNT_ADDR(base) ((base) + (0x30UL))
#define REG_PD_RXTYPE_ADDR(base) ((base) + (0x31UL))
#define REG_PD_RXHEADL_ADDR(base) ((base) + (0x32UL))
#define REG_PD_RXHEADH_ADDR(base) ((base) + (0x33UL))
#define REG_PD_RXDATA_0_ADDR(base,k) ((base) + ((k)*1+0x34UL))
#define REG_PD_TRANSMIT_ADDR(base) ((base) + (0x50UL))
#define REG_PD_TXBYTECNT_ADDR(base) ((base) + (0x51UL))
#define REG_PD_TXHEADL_ADDR(base) ((base) + (0x52UL))
#define REG_PD_TXHEADH_ADDR(base) ((base) + (0x53UL))
#define REG_PD_TXDATA_ADDR(base,k) ((base) + ((k)*1+0x54UL))
#define REG_PD_VBUS_VOL_L_ADDR(base) ((base) + (0x70UL))
#define REG_PD_VBUS_VOL_H_ADDR(base) ((base) + (0x71UL))
#define REG_PD_VBUS_SNK_DISCL_ADDR(base) ((base) + (0x72UL))
#define REG_PD_VBUS_SNK_DISCH_ADDR(base) ((base) + (0x73UL))
#define REG_PD_VBUS_STOP_DISCL_ADDR(base) ((base) + (0x74UL))
#define REG_PD_VBUS_STOP_DISCH_ADDR(base) ((base) + (0x75UL))
#define REG_PD_VALARMH_CFGL_ADDR(base) ((base) + (0x76UL))
#define REG_PD_VALARMH_CFGH_ADDR(base) ((base) + (0x77UL))
#define REG_PD_VALARML_CFGL_ADDR(base) ((base) + (0x78UL))
#define REG_PD_VALARML_CFGH_ADDR(base) ((base) + (0x79UL))
#define REG_PD_VDM_CFG_0_ADDR(base) ((base) + (0x7AUL))
#define REG_PD_VDM_ENABLE_ADDR(base) ((base) + (0x7BUL))
#define REG_PD_VDM_CFG_1_ADDR(base) ((base) + (0x7CUL))
#define REG_PD_DBG_RDATA_CFG_ADDR(base) ((base) + (0x7DUL))
#define REG_PD_DBG_RDATA_ADDR(base) ((base) + (0x7EUL))
#else
#define REG_VENDIDL_ADDR(base) ((base) + (0x00))
#define REG_VENDIDH_ADDR(base) ((base) + (0x01))
#define REG_PRODIDL_ADDR(base) ((base) + (0x02))
#define REG_PRODIDH_ADDR(base) ((base) + (0x03))
#define REG_DEVIDL_ADDR(base) ((base) + (0x04))
#define REG_DEVIDH_ADDR(base) ((base) + (0x05))
#define REG_TYPECREVL_ADDR(base) ((base) + (0x06))
#define REG_TYPECREVH_ADDR(base) ((base) + (0x07))
#define REG_USBPDVER_ADDR(base) ((base) + (0x08))
#define REG_USBPDREV_ADDR(base) ((base) + (0x09))
#define REG_PDIFREVL_ADDR(base) ((base) + (0x0A))
#define REG_PDIFREVH_ADDR(base) ((base) + (0x0B))
#define REG_PD_ALERT_L_ADDR(base) ((base) + (0x10))
#define REG_PD_ALERT_H_ADDR(base) ((base) + (0x11))
#define REG_PD_ALERT_MSK_L_ADDR(base) ((base) + (0x12))
#define REG_PD_ALERT_MSK_H_ADDR(base) ((base) + (0x13))
#define REG_PD_PWRSTAT_MSK_ADDR(base) ((base) + (0x14))
#define REG_PD_FAULTSTAT_MSK_ADDR(base) ((base) + (0x15))
#define REG_EXTENDED_STATUS_MASK_ADDR(base) ((base) + (0x16))
#define REG_ALERT_EXTENDED_MASK_ADDR(base) ((base) + (0x17))
#define REG_PD_TCPC_CTRL_ADDR(base) ((base) + (0x19))
#define REG_PD_ROLE_CTRL_ADDR(base) ((base) + (0x1A))
#define REG_PD_FAULT_CTRL_ADDR(base) ((base) + (0x1B))
#define REG_PD_PWR_CTRL_ADDR(base) ((base) + (0x1C))
#define REG_PD_CC_STATUS_ADDR(base) ((base) + (0x1D))
#define REG_PD_PWR_STATUS_ADDR(base) ((base) + (0x1E))
#define REG_PD_FAULT_STATUS_ADDR(base) ((base) + (0x1F))
#define REG_EXTENDED_STATUS_ADDR(base) ((base) + (0x20))
#define REG_ALERT_EXTENDED_ADDR(base) ((base) + (0x21))
#define REG_PD_COMMAND_ADDR(base) ((base) + (0x23))
#define REG_PD_DEVCAP1L_ADDR(base) ((base) + (0x24))
#define REG_PD_DEVCAP1H_ADDR(base) ((base) + (0x25))
#define REG_PD_DEVCAP2L_ADDR(base) ((base) + (0x26))
#define REG_PD_DEVCAP2H_ADDR(base) ((base) + (0x27))
#define REG_PD_STDIN_CAP_ADDR(base) ((base) + (0x28))
#define REG_PD_STDOUT_CAP_ADDR(base) ((base) + (0x29))
#define REG_PD_MSG_HEADR_ADDR(base) ((base) + (0x2E))
#define REG_PD_RXDETECT_ADDR(base) ((base) + (0x2F))
#define REG_PD_RXBYTECNT_ADDR(base) ((base) + (0x30))
#define REG_PD_RXTYPE_ADDR(base) ((base) + (0x31))
#define REG_PD_RXHEADL_ADDR(base) ((base) + (0x32))
#define REG_PD_RXHEADH_ADDR(base) ((base) + (0x33))
#define REG_PD_RXDATA_0_ADDR(base,k) ((base) + ((k)*1+0x34))
#define REG_PD_TRANSMIT_ADDR(base) ((base) + (0x50))
#define REG_PD_TXBYTECNT_ADDR(base) ((base) + (0x51))
#define REG_PD_TXHEADL_ADDR(base) ((base) + (0x52))
#define REG_PD_TXHEADH_ADDR(base) ((base) + (0x53))
#define REG_PD_TXDATA_ADDR(base,k) ((base) + ((k)*1+0x54))
#define REG_PD_VBUS_VOL_L_ADDR(base) ((base) + (0x70))
#define REG_PD_VBUS_VOL_H_ADDR(base) ((base) + (0x71))
#define REG_PD_VBUS_SNK_DISCL_ADDR(base) ((base) + (0x72))
#define REG_PD_VBUS_SNK_DISCH_ADDR(base) ((base) + (0x73))
#define REG_PD_VBUS_STOP_DISCL_ADDR(base) ((base) + (0x74))
#define REG_PD_VBUS_STOP_DISCH_ADDR(base) ((base) + (0x75))
#define REG_PD_VALARMH_CFGL_ADDR(base) ((base) + (0x76))
#define REG_PD_VALARMH_CFGH_ADDR(base) ((base) + (0x77))
#define REG_PD_VALARML_CFGL_ADDR(base) ((base) + (0x78))
#define REG_PD_VALARML_CFGH_ADDR(base) ((base) + (0x79))
#define REG_PD_VDM_CFG_0_ADDR(base) ((base) + (0x7A))
#define REG_PD_VDM_ENABLE_ADDR(base) ((base) + (0x7B))
#define REG_PD_VDM_CFG_1_ADDR(base) ((base) + (0x7C))
#define REG_PD_DBG_RDATA_CFG_ADDR(base) ((base) + (0x7D))
#define REG_PD_DBG_RDATA_ADDR(base) ((base) + (0x7E))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_STATUIS_ADDR(base) ((base) + (0x00UL))
#define REG_CNTL_ADDR(base) ((base) + (0x01UL))
#define REG_CMD_ADDR(base) ((base) + (0x04UL))
#define REG_FCP_LENGTH_ADDR(base) ((base) + (0x05UL))
#define REG_ADDR_ADDR(base) ((base) + (0x07UL))
#define REG_DATA0_ADDR(base) ((base) + (0x08UL))
#define REG_DATA1_ADDR(base) ((base) + (0x09UL))
#define REG_DATA2_ADDR(base) ((base) + (0x0AUL))
#define REG_DATA3_ADDR(base) ((base) + (0x0BUL))
#define REG_DATA4_ADDR(base) ((base) + (0x0CUL))
#define REG_DATA5_ADDR(base) ((base) + (0x0DUL))
#define REG_DATA6_ADDR(base) ((base) + (0x0EUL))
#define REG_DATA7_ADDR(base) ((base) + (0x0FUL))
#define REG_FCP_RDATA0_ADDR(base) ((base) + (0x10UL))
#define REG_FCP_RDATA1_ADDR(base) ((base) + (0x11UL))
#define REG_FCP_RDATA2_ADDR(base) ((base) + (0x12UL))
#define REG_FCP_RDATA3_ADDR(base) ((base) + (0x13UL))
#define REG_FCP_RDATA4_ADDR(base) ((base) + (0x14UL))
#define REG_FCP_RDATA5_ADDR(base) ((base) + (0x15UL))
#define REG_FCP_RDATA6_ADDR(base) ((base) + (0x16UL))
#define REG_FCP_RDATA7_ADDR(base) ((base) + (0x17UL))
#define REG_ISR1_ADDR(base) ((base) + (0x19UL))
#define REG_ISR2_ADDR(base) ((base) + (0x1AUL))
#define REG_IMR1_ADDR(base) ((base) + (0x1BUL))
#define REG_IMR2_ADDR(base) ((base) + (0x1CUL))
#define REG_FCP_IRQ5_ADDR(base) ((base) + (0x1DUL))
#define REG_FCP_IRQ5_MASK_ADDR(base) ((base) + (0x1EUL))
#define REG_FCP_CTRL_ADDR(base) ((base) + (0x1FUL))
#define REG_FCP_MODE2_SET_ADDR(base) ((base) + (0x20UL))
#define REG_FCP_ADAP_CTRL_ADDR(base) ((base) + (0x21UL))
#define REG_RDATA_READY_ADDR(base) ((base) + (0x22UL))
#define REG_FCP_SOFT_RST_CTRL_ADDR(base) ((base) + (0x23UL))
#define REG_FCP_RDATA_PARITY_ERR_ADDR(base) ((base) + (0x25UL))
#define REG_FCP_INIT_RETRY_CFG_ADDR(base) ((base) + (0x26UL))
#define REG_FCP_IRQ3_ADDR(base) ((base) + (0x30UL))
#define REG_FCP_IRQ4_ADDR(base) ((base) + (0x31UL))
#define REG_FCP_IRQ3_MASK_ADDR(base) ((base) + (0x32UL))
#define REG_FCP_IRQ4_MASK_ADDR(base) ((base) + (0x33UL))
#define REG_MSTATE_ADDR(base) ((base) + (0x34UL))
#define REG_CRC_ENABLE_ADDR(base) ((base) + (0x35UL))
#define REG_CRC_START_VALUE_ADDR(base) ((base) + (0x36UL))
#define REG_SAMPLE_CNT_ADJ_ADDR(base) ((base) + (0x37UL))
#define REG_RX_PING_WIDTH_MIN_H_ADDR(base) ((base) + (0x38UL))
#define REG_RX_PING_WIDTH_MIN_L_ADDR(base) ((base) + (0x39UL))
#define REG_RX_PING_WIDTH_MAX_H_ADDR(base) ((base) + (0x3AUL))
#define REG_RX_PING_WIDTH_MAX_L_ADDR(base) ((base) + (0x3BUL))
#define REG_DATA_WAIT_TIME_ADDR(base) ((base) + (0x3CUL))
#define REG_RETRY_CNT_ADDR(base) ((base) + (0x3DUL))
#define REG_FCP_RO_RESERVE_ADDR(base) ((base) + (0x3EUL))
#define REG_FCP_DEBUG_REG0_ADDR(base) ((base) + (0x3FUL))
#define REG_FCP_DEBUG_REG1_ADDR(base) ((base) + (0x40UL))
#define REG_FCP_DEBUG_REG2_ADDR(base) ((base) + (0x41UL))
#define REG_FCP_DEBUG_REG3_ADDR(base) ((base) + (0x42UL))
#define REG_FCP_DEBUG_REG4_ADDR(base) ((base) + (0x43UL))
#define REG_RX_PACKET_WAIT_ADJUST_ADDR(base) ((base) + (0x44UL))
#define REG_SAMPLE_CNT_TINYJUST_ADDR(base) ((base) + (0x45UL))
#define REG_RX_PING_CNT_TINYJUST_ADDR(base) ((base) + (0x46UL))
#define REG_SHIFT_CNT_CFG_MAX_ADDR(base) ((base) + (0x47UL))
#define REG_PD_CDR_CFG_0_ADDR(base) ((base) + (0x50UL))
#define REG_PD_CDR_CFG_1_ADDR(base) ((base) + (0x51UL))
#define REG_PD_DBG_CFG_0_ADDR(base) ((base) + (0x52UL))
#define REG_PD_DBG_CFG_1_ADDR(base) ((base) + (0x53UL))
#define REG_PD_DBG_CFG_2_ADDR(base) ((base) + (0x54UL))
#define REG_PD_DBG_CFG_3_ADDR(base) ((base) + (0x55UL))
#define REG_PD_DBG_RO_0_ADDR(base) ((base) + (0x56UL))
#define REG_PD_DBG_RO_1_ADDR(base) ((base) + (0x57UL))
#define REG_PD_DBG_RO_2_ADDR(base) ((base) + (0x58UL))
#define REG_PD_DBG_RO_3_ADDR(base) ((base) + (0x59UL))
#define REG_PD_EXT_OTG_SEL_ADDR(base) ((base) + (0x5AUL))
#define REG_PD_EXT_OTG_EN_ADDR(base) ((base) + (0x5BUL))
#define REG_PD_EXT_OVP_SEL_ADDR(base) ((base) + (0x5CUL))
#define REG_PD_EXT_OVP_EN_ADDR(base) ((base) + (0x5DUL))
#else
#define REG_STATUIS_ADDR(base) ((base) + (0x00))
#define REG_CNTL_ADDR(base) ((base) + (0x01))
#define REG_CMD_ADDR(base) ((base) + (0x04))
#define REG_FCP_LENGTH_ADDR(base) ((base) + (0x05))
#define REG_ADDR_ADDR(base) ((base) + (0x07))
#define REG_DATA0_ADDR(base) ((base) + (0x08))
#define REG_DATA1_ADDR(base) ((base) + (0x09))
#define REG_DATA2_ADDR(base) ((base) + (0x0A))
#define REG_DATA3_ADDR(base) ((base) + (0x0B))
#define REG_DATA4_ADDR(base) ((base) + (0x0C))
#define REG_DATA5_ADDR(base) ((base) + (0x0D))
#define REG_DATA6_ADDR(base) ((base) + (0x0E))
#define REG_DATA7_ADDR(base) ((base) + (0x0F))
#define REG_FCP_RDATA0_ADDR(base) ((base) + (0x10))
#define REG_FCP_RDATA1_ADDR(base) ((base) + (0x11))
#define REG_FCP_RDATA2_ADDR(base) ((base) + (0x12))
#define REG_FCP_RDATA3_ADDR(base) ((base) + (0x13))
#define REG_FCP_RDATA4_ADDR(base) ((base) + (0x14))
#define REG_FCP_RDATA5_ADDR(base) ((base) + (0x15))
#define REG_FCP_RDATA6_ADDR(base) ((base) + (0x16))
#define REG_FCP_RDATA7_ADDR(base) ((base) + (0x17))
#define REG_ISR1_ADDR(base) ((base) + (0x19))
#define REG_ISR2_ADDR(base) ((base) + (0x1A))
#define REG_IMR1_ADDR(base) ((base) + (0x1B))
#define REG_IMR2_ADDR(base) ((base) + (0x1C))
#define REG_FCP_IRQ5_ADDR(base) ((base) + (0x1D))
#define REG_FCP_IRQ5_MASK_ADDR(base) ((base) + (0x1E))
#define REG_FCP_CTRL_ADDR(base) ((base) + (0x1F))
#define REG_FCP_MODE2_SET_ADDR(base) ((base) + (0x20))
#define REG_FCP_ADAP_CTRL_ADDR(base) ((base) + (0x21))
#define REG_RDATA_READY_ADDR(base) ((base) + (0x22))
#define REG_FCP_SOFT_RST_CTRL_ADDR(base) ((base) + (0x23))
#define REG_FCP_RDATA_PARITY_ERR_ADDR(base) ((base) + (0x25))
#define REG_FCP_INIT_RETRY_CFG_ADDR(base) ((base) + (0x26))
#define REG_FCP_IRQ3_ADDR(base) ((base) + (0x30))
#define REG_FCP_IRQ4_ADDR(base) ((base) + (0x31))
#define REG_FCP_IRQ3_MASK_ADDR(base) ((base) + (0x32))
#define REG_FCP_IRQ4_MASK_ADDR(base) ((base) + (0x33))
#define REG_MSTATE_ADDR(base) ((base) + (0x34))
#define REG_CRC_ENABLE_ADDR(base) ((base) + (0x35))
#define REG_CRC_START_VALUE_ADDR(base) ((base) + (0x36))
#define REG_SAMPLE_CNT_ADJ_ADDR(base) ((base) + (0x37))
#define REG_RX_PING_WIDTH_MIN_H_ADDR(base) ((base) + (0x38))
#define REG_RX_PING_WIDTH_MIN_L_ADDR(base) ((base) + (0x39))
#define REG_RX_PING_WIDTH_MAX_H_ADDR(base) ((base) + (0x3A))
#define REG_RX_PING_WIDTH_MAX_L_ADDR(base) ((base) + (0x3B))
#define REG_DATA_WAIT_TIME_ADDR(base) ((base) + (0x3C))
#define REG_RETRY_CNT_ADDR(base) ((base) + (0x3D))
#define REG_FCP_RO_RESERVE_ADDR(base) ((base) + (0x3E))
#define REG_FCP_DEBUG_REG0_ADDR(base) ((base) + (0x3F))
#define REG_FCP_DEBUG_REG1_ADDR(base) ((base) + (0x40))
#define REG_FCP_DEBUG_REG2_ADDR(base) ((base) + (0x41))
#define REG_FCP_DEBUG_REG3_ADDR(base) ((base) + (0x42))
#define REG_FCP_DEBUG_REG4_ADDR(base) ((base) + (0x43))
#define REG_RX_PACKET_WAIT_ADJUST_ADDR(base) ((base) + (0x44))
#define REG_SAMPLE_CNT_TINYJUST_ADDR(base) ((base) + (0x45))
#define REG_RX_PING_CNT_TINYJUST_ADDR(base) ((base) + (0x46))
#define REG_SHIFT_CNT_CFG_MAX_ADDR(base) ((base) + (0x47))
#define REG_PD_CDR_CFG_0_ADDR(base) ((base) + (0x50))
#define REG_PD_CDR_CFG_1_ADDR(base) ((base) + (0x51))
#define REG_PD_DBG_CFG_0_ADDR(base) ((base) + (0x52))
#define REG_PD_DBG_CFG_1_ADDR(base) ((base) + (0x53))
#define REG_PD_DBG_CFG_2_ADDR(base) ((base) + (0x54))
#define REG_PD_DBG_CFG_3_ADDR(base) ((base) + (0x55))
#define REG_PD_DBG_RO_0_ADDR(base) ((base) + (0x56))
#define REG_PD_DBG_RO_1_ADDR(base) ((base) + (0x57))
#define REG_PD_DBG_RO_2_ADDR(base) ((base) + (0x58))
#define REG_PD_DBG_RO_3_ADDR(base) ((base) + (0x59))
#define REG_PD_EXT_OTG_SEL_ADDR(base) ((base) + (0x5A))
#define REG_PD_EXT_OTG_EN_ADDR(base) ((base) + (0x5B))
#define REG_PD_EXT_OVP_SEL_ADDR(base) ((base) + (0x5C))
#define REG_PD_EXT_OVP_EN_ADDR(base) ((base) + (0x5D))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_HKADC_EN_ADDR(base) ((base) + (0x00UL))
#define REG_HKADC_START_ADDR(base) ((base) + (0x01UL))
#define REG_HKADC_CTRL1_ADDR(base) ((base) + (0x02UL))
#define REG_HKADC_SEQ_CH_H_ADDR(base) ((base) + (0x03UL))
#define REG_HKADC_SEQ_CH_L_ADDR(base) ((base) + (0x04UL))
#define REG_HKADC_RD_SEQ_ADDR(base) ((base) + (0x05UL))
#define REG_HKADC_DATA_VALID_ADDR(base) ((base) + (0x06UL))
#define REG_CH0_ADC_L_ADDR(base) ((base) + (0x07UL))
#define REG_CH0_ADC_H_ADDR(base) ((base) + (0x08UL))
#define REG_CH1_ADC_L_ADDR(base) ((base) + (0x09UL))
#define REG_CH1_ADC_H_ADDR(base) ((base) + (0x0AUL))
#define REG_CH2_ADC_L_ADDR(base) ((base) + (0x0BUL))
#define REG_CH2_ADC_H_ADDR(base) ((base) + (0x0CUL))
#define REG_CH3_ADC_L_ADDR(base) ((base) + (0x0DUL))
#define REG_CH3_ADC_H_ADDR(base) ((base) + (0x0EUL))
#define REG_CH4_ADC_L_ADDR(base) ((base) + (0x0FUL))
#define REG_CH4_ADC_H_ADDR(base) ((base) + (0x10UL))
#define REG_CH5_ADC_L_ADDR(base) ((base) + (0x11UL))
#define REG_CH5_ADC_H_ADDR(base) ((base) + (0x12UL))
#define REG_CH6_ADC_L_ADDR(base) ((base) + (0x13UL))
#define REG_CH6_ADC_H_ADDR(base) ((base) + (0x14UL))
#define REG_CH7_ADC_L_ADDR(base) ((base) + (0x15UL))
#define REG_CH7_ADC_H_ADDR(base) ((base) + (0x16UL))
#define REG_CH8_ADC_L_ADDR(base) ((base) + (0x17UL))
#define REG_CH8_ADC_H_ADDR(base) ((base) + (0x18UL))
#define REG_CH9_ADC_L_ADDR(base) ((base) + (0x19UL))
#define REG_CH9_ADC_H_ADDR(base) ((base) + (0x1AUL))
#define REG_CH10_ADC_L_ADDR(base) ((base) + (0x1BUL))
#define REG_CH10_ADC_H_ADDR(base) ((base) + (0x1CUL))
#define REG_CH11_ADC_L_ADDR(base) ((base) + (0x1DUL))
#define REG_CH11_ADC_H_ADDR(base) ((base) + (0x1EUL))
#define REG_CH12_ADC_L_ADDR(base) ((base) + (0x1FUL))
#define REG_CH12_ADC_H_ADDR(base) ((base) + (0x20UL))
#define REG_CH13_ADC_L_ADDR(base) ((base) + (0x21UL))
#define REG_CH13_ADC_H_ADDR(base) ((base) + (0x22UL))
#define REG_CH14_ADC_L_ADDR(base) ((base) + (0x23UL))
#define REG_CH14_ADC_H_ADDR(base) ((base) + (0x24UL))
#define REG_CH15_ADC_L_ADDR(base) ((base) + (0x25UL))
#define REG_CH15_ADC_H_ADDR(base) ((base) + (0x26UL))
#define REG_HKADC_CLK_EN_ADDR(base) ((base) + (0x2CUL))
#define REG_HKADC_TB_EN_SEL_ADDR(base) ((base) + (0x2DUL))
#define REG_HKADC_TB_DATA0_ADDR(base) ((base) + (0x2EUL))
#define REG_HKADC_TB_DATA1_ADDR(base) ((base) + (0x2FUL))
#define REG_OTP_EN_ADDR(base) ((base) + (0x41UL))
#define REG_TH_TBAT_OTP_ADDR(base) ((base) + (0x42UL))
#define REG_TH_TBAT_OTP_HYS_ADDR(base) ((base) + (0x43UL))
#else
#define REG_HKADC_EN_ADDR(base) ((base) + (0x00))
#define REG_HKADC_START_ADDR(base) ((base) + (0x01))
#define REG_HKADC_CTRL1_ADDR(base) ((base) + (0x02))
#define REG_HKADC_SEQ_CH_H_ADDR(base) ((base) + (0x03))
#define REG_HKADC_SEQ_CH_L_ADDR(base) ((base) + (0x04))
#define REG_HKADC_RD_SEQ_ADDR(base) ((base) + (0x05))
#define REG_HKADC_DATA_VALID_ADDR(base) ((base) + (0x06))
#define REG_CH0_ADC_L_ADDR(base) ((base) + (0x07))
#define REG_CH0_ADC_H_ADDR(base) ((base) + (0x08))
#define REG_CH1_ADC_L_ADDR(base) ((base) + (0x09))
#define REG_CH1_ADC_H_ADDR(base) ((base) + (0x0A))
#define REG_CH2_ADC_L_ADDR(base) ((base) + (0x0B))
#define REG_CH2_ADC_H_ADDR(base) ((base) + (0x0C))
#define REG_CH3_ADC_L_ADDR(base) ((base) + (0x0D))
#define REG_CH3_ADC_H_ADDR(base) ((base) + (0x0E))
#define REG_CH4_ADC_L_ADDR(base) ((base) + (0x0F))
#define REG_CH4_ADC_H_ADDR(base) ((base) + (0x10))
#define REG_CH5_ADC_L_ADDR(base) ((base) + (0x11))
#define REG_CH5_ADC_H_ADDR(base) ((base) + (0x12))
#define REG_CH6_ADC_L_ADDR(base) ((base) + (0x13))
#define REG_CH6_ADC_H_ADDR(base) ((base) + (0x14))
#define REG_CH7_ADC_L_ADDR(base) ((base) + (0x15))
#define REG_CH7_ADC_H_ADDR(base) ((base) + (0x16))
#define REG_CH8_ADC_L_ADDR(base) ((base) + (0x17))
#define REG_CH8_ADC_H_ADDR(base) ((base) + (0x18))
#define REG_CH9_ADC_L_ADDR(base) ((base) + (0x19))
#define REG_CH9_ADC_H_ADDR(base) ((base) + (0x1A))
#define REG_CH10_ADC_L_ADDR(base) ((base) + (0x1B))
#define REG_CH10_ADC_H_ADDR(base) ((base) + (0x1C))
#define REG_CH11_ADC_L_ADDR(base) ((base) + (0x1D))
#define REG_CH11_ADC_H_ADDR(base) ((base) + (0x1E))
#define REG_CH12_ADC_L_ADDR(base) ((base) + (0x1F))
#define REG_CH12_ADC_H_ADDR(base) ((base) + (0x20))
#define REG_CH13_ADC_L_ADDR(base) ((base) + (0x21))
#define REG_CH13_ADC_H_ADDR(base) ((base) + (0x22))
#define REG_CH14_ADC_L_ADDR(base) ((base) + (0x23))
#define REG_CH14_ADC_H_ADDR(base) ((base) + (0x24))
#define REG_CH15_ADC_L_ADDR(base) ((base) + (0x25))
#define REG_CH15_ADC_H_ADDR(base) ((base) + (0x26))
#define REG_HKADC_CLK_EN_ADDR(base) ((base) + (0x2C))
#define REG_HKADC_TB_EN_SEL_ADDR(base) ((base) + (0x2D))
#define REG_HKADC_TB_DATA0_ADDR(base) ((base) + (0x2E))
#define REG_HKADC_TB_DATA1_ADDR(base) ((base) + (0x2F))
#define REG_OTP_EN_ADDR(base) ((base) + (0x41))
#define REG_TH_TBAT_OTP_ADDR(base) ((base) + (0x42))
#define REG_TH_TBAT_OTP_HYS_ADDR(base) ((base) + (0x43))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_VERSION0_RO_REG_0_ADDR(base) ((base) + (0x00UL))
#define REG_VERSION1_RO_REG_0_ADDR(base) ((base) + (0x01UL))
#define REG_VERSION2_RO_REG_0_ADDR(base) ((base) + (0x02UL))
#define REG_VERSION3_RO_REG_0_ADDR(base) ((base) + (0x03UL))
#define REG_VERSION4_RO_REG_0_ADDR(base) ((base) + (0x04UL))
#define REG_VERSION5_RO_REG_0_ADDR(base) ((base) + (0x05UL))
#define REG_SC_TESTBUS_CFG_ADDR(base) ((base) + (0x10UL))
#define REG_SC_TESTBUS_RDATA_ADDR(base) ((base) + (0x11UL))
#define REG_GLB_SOFT_RST_CTRL_ADDR(base) ((base) + (0x12UL))
#define REG_EFUSE_SOFT_RST_CTRL_ADDR(base) ((base) + (0x13UL))
#define REG_HKADC_SOFT_RST_CTRL_ADDR(base) ((base) + (0x14UL))
#define REG_COUL_SOFT_RST_CTRL_ADDR(base) ((base) + (0x15UL))
#define REG_COUL_PD_RST_CTRL_ADDR(base) ((base) + (0x16UL))
#define REG_FLASH_SOFT_RST_CTRL_ADDR(base) ((base) + (0x17UL))
#define REG_SC_CRG_CLK_EN_CTRL_ADDR(base) ((base) + (0x18UL))
#define REG_SC_CRG_CLK_EN_CTRL_1_ADDR(base) ((base) + (0x19UL))
#define REG_SC_CRG_CLK_EN_CTRL_2_ADDR(base) ((base) + (0x1AUL))
#define REG_SC_TESTSIG_CFG_ADDR(base) ((base) + (0x1BUL))
#define REG_SC_WDT_EN_ADDR(base) ((base) + (0x20UL))
#define REG_WDT_SOFT_RST_ADDR(base) ((base) + (0x21UL))
#define REG_WDT_CTRL_ADDR(base) ((base) + (0x22UL))
#define REG_WDT_TIMEOUT_ADDR(base) ((base) + (0x23UL))
#define REG_BAT_CNCT_SEL_ADDR(base) ((base) + (0x2FUL))
#define REG_DA_SC_MODE_ADDR(base) ((base) + (0x30UL))
#define REG_OTG_MODE_CFG_ADDR(base) ((base) + (0x31UL))
#define REG_DA_SC_EN_ADDR(base) ((base) + (0x32UL))
#define REG_DA_SCBUCK_EN_ADDR(base) ((base) + (0x33UL))
#define REG_SC_BUCK_ENB_ADDR(base) ((base) + (0x34UL))
#define REG_DA_BOOST_EN_ADDR(base) ((base) + (0x35UL))
#define REG_USBOVP_CTRL_ADDR(base) ((base) + (0x36UL))
#define REG_PSWOVP_CTRL_ADDR(base) ((base) + (0x37UL))
#define REG_OVP_EN_ADDR(base) ((base) + (0x38UL))
#define REG_AUX_SBU_EN_ADDR(base) ((base) + (0x39UL))
#define REG_VBUS_BKVSET_ADDR(base) ((base) + (0x3AUL))
#define REG_DA_SC_PHASE1_EN_ADDR(base) ((base) + (0x3BUL))
#define REG_DA_SC_PHASE2_EN_ADDR(base) ((base) + (0x3CUL))
#define REG_EFUSE_PDOB_SEL_ADDR(base) ((base) + (0x60UL))
#define REG_EFUSE_MODE_ADDR(base) ((base) + (0x61UL))
#define REG_EFUSE_RD_CTRL_ADDR(base) ((base) + (0x62UL))
#define REG_EFUSE_AEN_ADDR(base) ((base) + (0x63UL))
#define REG_EFUSE_PGMEN_ADDR(base) ((base) + (0x64UL))
#define REG_EFUSE_RDEN_ADDR(base) ((base) + (0x65UL))
#define REG_EFUSE_ADDR_ADDR(base) ((base) + (0x66UL))
#define REG_EFUSE_ADDR_H_ADDR(base) ((base) + (0x67UL))
#define REG_EFUSE_PDOB_PRE_ADDR_WE_ADDR(base) ((base) + (0x68UL))
#define REG_EFUSE_PDOB_PRE_WDATA_ADDR(base) ((base) + (0x69UL))
#define REG_EFUSE_STATUS_ADDR(base) ((base) + (0x6AUL))
#define REG_EFUSE_FSM_RESET_ADDR(base) ((base) + (0x6BUL))
#define REG_EFUSE_TESTBUS_CFG_ADDR(base) ((base) + (0x6CUL))
#define REG_EFUSE_TESTBUS_RDATA_ADDR(base) ((base) + (0x6DUL))
#define REG_EFUSE_ADDR_CAL_SEL_ADDR(base) ((base) + (0x6EUL))
#define REG_OTG_DMD_CFG_ADDR(base) ((base) + (0x71UL))
#define REG_BUCK_CFG_REG_0_ADDR(base) ((base) + (0x72UL))
#define REG_BUCK_CFG_REG_1_ADDR(base) ((base) + (0x73UL))
#define REG_BUCK_CFG_REG_2_ADDR(base) ((base) + (0x74UL))
#define REG_BUCK_CFG_REG_3_ADDR(base) ((base) + (0x75UL))
#define REG_BUCK_CFG_REG_4_ADDR(base) ((base) + (0x76UL))
#define REG_BUCK_CFG_REG_5_ADDR(base) ((base) + (0x77UL))
#define REG_BUCK_CFG_REG_6_ADDR(base) ((base) + (0x78UL))
#define REG_BUCK_CFG_REG_7_ADDR(base) ((base) + (0x79UL))
#define REG_BUCK_CFG_REG_8_ADDR(base) ((base) + (0x7AUL))
#define REG_OTG_CFG_REG_0_ADDR(base) ((base) + (0x7BUL))
#define REG_OTG_CFG_REG_1_ADDR(base) ((base) + (0x7CUL))
#define REG_OTG_CFG_REG_2_ADDR(base) ((base) + (0x7DUL))
#define REG_OTG_CFG_REG_3_ADDR(base) ((base) + (0x7EUL))
#define REG_OTG_CFG_REG_4_ADDR(base) ((base) + (0x7FUL))
#define REG_OTG_CFG_REG_5_ADDR(base) ((base) + (0x80UL))
#define REG_OTG_CFG_REG_6_ADDR(base) ((base) + (0x81UL))
#define REG_OTG_CFG_REG_7_ADDR(base) ((base) + (0x82UL))
#define REG_OTG_CFG_REG_8_ADDR(base) ((base) + (0x83UL))
#define REG_STATUS_ADDR(base) ((base) + (0x8EUL))
#define REG_TB_CFG_ADDR(base) ((base) + (0x8FUL))
#define REG_TB_BUS_ADDR(base) ((base) + (0x90UL))
#define REG_TB_SIG_ADDR(base) ((base) + (0x91UL))
#define REG_EFS_DIG_TRIM_1_ADDR(base) ((base) + (0x9EUL))
#define REG_EFS_DIG_TRIM_0_ADDR(base) ((base) + (0x9FUL))
#define REG_DCP_CFG_ADDR(base) ((base) + (0xB0UL))
#define REG_BC12_CFG_0_ADDR(base) ((base) + (0xB1UL))
#define REG_BC12_CFG_1_ADDR(base) ((base) + (0xB2UL))
#define REG_BC12_CFG_2_ADDR(base) ((base) + (0xB3UL))
#define REG_BC12_STATUS_ADDR(base) ((base) + (0xB4UL))
#define REG_BC12_RESERVE0_ADDR(base) ((base) + (0xB5UL))
#define REG_BC12_RESERVE_DA_ADDR(base) ((base) + (0xB6UL))
#define REG_BC12_RESERVE1_ADDR(base) ((base) + (0xB7UL))
#else
#define REG_VERSION0_RO_REG_0_ADDR(base) ((base) + (0x00))
#define REG_VERSION1_RO_REG_0_ADDR(base) ((base) + (0x01))
#define REG_VERSION2_RO_REG_0_ADDR(base) ((base) + (0x02))
#define REG_VERSION3_RO_REG_0_ADDR(base) ((base) + (0x03))
#define REG_VERSION4_RO_REG_0_ADDR(base) ((base) + (0x04))
#define REG_VERSION5_RO_REG_0_ADDR(base) ((base) + (0x05))
#define REG_SC_TESTBUS_CFG_ADDR(base) ((base) + (0x10))
#define REG_SC_TESTBUS_RDATA_ADDR(base) ((base) + (0x11))
#define REG_GLB_SOFT_RST_CTRL_ADDR(base) ((base) + (0x12))
#define REG_EFUSE_SOFT_RST_CTRL_ADDR(base) ((base) + (0x13))
#define REG_HKADC_SOFT_RST_CTRL_ADDR(base) ((base) + (0x14))
#define REG_COUL_SOFT_RST_CTRL_ADDR(base) ((base) + (0x15))
#define REG_COUL_PD_RST_CTRL_ADDR(base) ((base) + (0x16))
#define REG_FLASH_SOFT_RST_CTRL_ADDR(base) ((base) + (0x17))
#define REG_SC_CRG_CLK_EN_CTRL_ADDR(base) ((base) + (0x18))
#define REG_SC_CRG_CLK_EN_CTRL_1_ADDR(base) ((base) + (0x19))
#define REG_SC_CRG_CLK_EN_CTRL_2_ADDR(base) ((base) + (0x1A))
#define REG_SC_TESTSIG_CFG_ADDR(base) ((base) + (0x1B))
#define REG_SC_WDT_EN_ADDR(base) ((base) + (0x20))
#define REG_WDT_SOFT_RST_ADDR(base) ((base) + (0x21))
#define REG_WDT_CTRL_ADDR(base) ((base) + (0x22))
#define REG_WDT_TIMEOUT_ADDR(base) ((base) + (0x23))
#define REG_BAT_CNCT_SEL_ADDR(base) ((base) + (0x2F))
#define REG_DA_SC_MODE_ADDR(base) ((base) + (0x30))
#define REG_OTG_MODE_CFG_ADDR(base) ((base) + (0x31))
#define REG_DA_SC_EN_ADDR(base) ((base) + (0x32))
#define REG_DA_SCBUCK_EN_ADDR(base) ((base) + (0x33))
#define REG_SC_BUCK_ENB_ADDR(base) ((base) + (0x34))
#define REG_DA_BOOST_EN_ADDR(base) ((base) + (0x35))
#define REG_USBOVP_CTRL_ADDR(base) ((base) + (0x36))
#define REG_PSWOVP_CTRL_ADDR(base) ((base) + (0x37))
#define REG_OVP_EN_ADDR(base) ((base) + (0x38))
#define REG_AUX_SBU_EN_ADDR(base) ((base) + (0x39))
#define REG_VBUS_BKVSET_ADDR(base) ((base) + (0x3A))
#define REG_DA_SC_PHASE1_EN_ADDR(base) ((base) + (0x3B))
#define REG_DA_SC_PHASE2_EN_ADDR(base) ((base) + (0x3C))
#define REG_EFUSE_PDOB_SEL_ADDR(base) ((base) + (0x60))
#define REG_EFUSE_MODE_ADDR(base) ((base) + (0x61))
#define REG_EFUSE_RD_CTRL_ADDR(base) ((base) + (0x62))
#define REG_EFUSE_AEN_ADDR(base) ((base) + (0x63))
#define REG_EFUSE_PGMEN_ADDR(base) ((base) + (0x64))
#define REG_EFUSE_RDEN_ADDR(base) ((base) + (0x65))
#define REG_EFUSE_ADDR_ADDR(base) ((base) + (0x66))
#define REG_EFUSE_ADDR_H_ADDR(base) ((base) + (0x67))
#define REG_EFUSE_PDOB_PRE_ADDR_WE_ADDR(base) ((base) + (0x68))
#define REG_EFUSE_PDOB_PRE_WDATA_ADDR(base) ((base) + (0x69))
#define REG_EFUSE_STATUS_ADDR(base) ((base) + (0x6A))
#define REG_EFUSE_FSM_RESET_ADDR(base) ((base) + (0x6B))
#define REG_EFUSE_TESTBUS_CFG_ADDR(base) ((base) + (0x6C))
#define REG_EFUSE_TESTBUS_RDATA_ADDR(base) ((base) + (0x6D))
#define REG_EFUSE_ADDR_CAL_SEL_ADDR(base) ((base) + (0x6E))
#define REG_OTG_DMD_CFG_ADDR(base) ((base) + (0x71))
#define REG_BUCK_CFG_REG_0_ADDR(base) ((base) + (0x72))
#define REG_BUCK_CFG_REG_1_ADDR(base) ((base) + (0x73))
#define REG_BUCK_CFG_REG_2_ADDR(base) ((base) + (0x74))
#define REG_BUCK_CFG_REG_3_ADDR(base) ((base) + (0x75))
#define REG_BUCK_CFG_REG_4_ADDR(base) ((base) + (0x76))
#define REG_BUCK_CFG_REG_5_ADDR(base) ((base) + (0x77))
#define REG_BUCK_CFG_REG_6_ADDR(base) ((base) + (0x78))
#define REG_BUCK_CFG_REG_7_ADDR(base) ((base) + (0x79))
#define REG_BUCK_CFG_REG_8_ADDR(base) ((base) + (0x7A))
#define REG_OTG_CFG_REG_0_ADDR(base) ((base) + (0x7B))
#define REG_OTG_CFG_REG_1_ADDR(base) ((base) + (0x7C))
#define REG_OTG_CFG_REG_2_ADDR(base) ((base) + (0x7D))
#define REG_OTG_CFG_REG_3_ADDR(base) ((base) + (0x7E))
#define REG_OTG_CFG_REG_4_ADDR(base) ((base) + (0x7F))
#define REG_OTG_CFG_REG_5_ADDR(base) ((base) + (0x80))
#define REG_OTG_CFG_REG_6_ADDR(base) ((base) + (0x81))
#define REG_OTG_CFG_REG_7_ADDR(base) ((base) + (0x82))
#define REG_OTG_CFG_REG_8_ADDR(base) ((base) + (0x83))
#define REG_STATUS_ADDR(base) ((base) + (0x8E))
#define REG_TB_CFG_ADDR(base) ((base) + (0x8F))
#define REG_TB_BUS_ADDR(base) ((base) + (0x90))
#define REG_TB_SIG_ADDR(base) ((base) + (0x91))
#define REG_EFS_DIG_TRIM_1_ADDR(base) ((base) + (0x9E))
#define REG_EFS_DIG_TRIM_0_ADDR(base) ((base) + (0x9F))
#define REG_DCP_CFG_ADDR(base) ((base) + (0xB0))
#define REG_BC12_CFG_0_ADDR(base) ((base) + (0xB1))
#define REG_BC12_CFG_1_ADDR(base) ((base) + (0xB2))
#define REG_BC12_CFG_2_ADDR(base) ((base) + (0xB3))
#define REG_BC12_STATUS_ADDR(base) ((base) + (0xB4))
#define REG_BC12_RESERVE0_ADDR(base) ((base) + (0xB5))
#define REG_BC12_RESERVE_DA_ADDR(base) ((base) + (0xB6))
#define REG_BC12_RESERVE1_ADDR(base) ((base) + (0xB7))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_CLJ_CTRL_REG0_ADDR(base) ((base) + (0x00UL))
#define REG_CLJ_CTRL_REG1_ADDR(base) ((base) + (0x01UL))
#define REG_CLJ_CTRL_REG2_ADDR(base) ((base) + (0x02UL))
#define REG_CLJ_CTRL_REG3_ADDR(base) ((base) + (0x03UL))
#define REG_SLIDE_CNT_DATA_OUT0_ADDR(base) ((base) + (0x04UL))
#define REG_SLIDE_CNT_DATA_OUT1_ADDR(base) ((base) + (0x05UL))
#define REG_SLIDE_CNT_DATA_OUT2_ADDR(base) ((base) + (0x06UL))
#define REG_SLIDE_IH_DATA0_OUT0_ADDR(base) ((base) + (0x07UL))
#define REG_SLIDE_IH_DATA0_OUT1_ADDR(base) ((base) + (0x08UL))
#define REG_SLIDE_IH_DATA0_OUT2_ADDR(base) ((base) + (0x09UL))
#define REG_SLIDE_IH_DATA1_OUT0_ADDR(base) ((base) + (0x0AUL))
#define REG_SLIDE_IH_DATA1_OUT1_ADDR(base) ((base) + (0x0BUL))
#define REG_SLIDE_IH_DATA1_OUT2_ADDR(base) ((base) + (0x0CUL))
#define REG_SLIDE_IH_DATA2_OUT0_ADDR(base) ((base) + (0x0DUL))
#define REG_SLIDE_IH_DATA2_OUT1_ADDR(base) ((base) + (0x0EUL))
#define REG_SLIDE_IH_DATA2_OUT2_ADDR(base) ((base) + (0x0FUL))
#define REG_SLIDE_IH_DATA3_OUT0_ADDR(base) ((base) + (0x10UL))
#define REG_SLIDE_IH_DATA3_OUT1_ADDR(base) ((base) + (0x11UL))
#define REG_SLIDE_IH_DATA3_OUT2_ADDR(base) ((base) + (0x12UL))
#define REG_SLIDE_VH_DATA0_OUT0_ADDR(base) ((base) + (0x13UL))
#define REG_SLIDE_VH_DATA0_OUT1_ADDR(base) ((base) + (0x14UL))
#define REG_SLIDE_VH_DATA0_OUT2_ADDR(base) ((base) + (0x15UL))
#define REG_SLIDE_VH_DATA1_OUT0_ADDR(base) ((base) + (0x16UL))
#define REG_SLIDE_VH_DATA1_OUT1_ADDR(base) ((base) + (0x17UL))
#define REG_SLIDE_VH_DATA1_OUT2_ADDR(base) ((base) + (0x18UL))
#define REG_SLIDE_VH_DATA2_OUT0_ADDR(base) ((base) + (0x19UL))
#define REG_SLIDE_VH_DATA2_OUT1_ADDR(base) ((base) + (0x1AUL))
#define REG_SLIDE_VH_DATA2_OUT2_ADDR(base) ((base) + (0x1BUL))
#define REG_SLIDE_VH_DATA3_OUT0_ADDR(base) ((base) + (0x1CUL))
#define REG_SLIDE_VH_DATA3_OUT1_ADDR(base) ((base) + (0x1DUL))
#define REG_SLIDE_VH_DATA3_OUT2_ADDR(base) ((base) + (0x1EUL))
#define REG_SLIDE_IL_DATA0_OUT0_ADDR(base) ((base) + (0x1FUL))
#define REG_SLIDE_IL_DATA0_OUT1_ADDR(base) ((base) + (0x20UL))
#define REG_SLIDE_IL_DATA0_OUT2_ADDR(base) ((base) + (0x21UL))
#define REG_SLIDE_IL_DATA1_OUT0_ADDR(base) ((base) + (0x22UL))
#define REG_SLIDE_IL_DATA1_OUT1_ADDR(base) ((base) + (0x23UL))
#define REG_SLIDE_IL_DATA1_OUT2_ADDR(base) ((base) + (0x24UL))
#define REG_SLIDE_IL_DATA2_OUT0_ADDR(base) ((base) + (0x25UL))
#define REG_SLIDE_IL_DATA2_OUT1_ADDR(base) ((base) + (0x26UL))
#define REG_SLIDE_IL_DATA2_OUT2_ADDR(base) ((base) + (0x27UL))
#define REG_SLIDE_IL_DATA3_OUT0_ADDR(base) ((base) + (0x28UL))
#define REG_SLIDE_IL_DATA3_OUT1_ADDR(base) ((base) + (0x29UL))
#define REG_SLIDE_IL_DATA3_OUT2_ADDR(base) ((base) + (0x2AUL))
#define REG_SLIDE_VL_DATA0_OUT0_ADDR(base) ((base) + (0x2BUL))
#define REG_SLIDE_VL_DATA0_OUT1_ADDR(base) ((base) + (0x2CUL))
#define REG_SLIDE_VL_DATA0_OUT2_ADDR(base) ((base) + (0x2DUL))
#define REG_SLIDE_VL_DATA1_OUT0_ADDR(base) ((base) + (0x2EUL))
#define REG_SLIDE_VL_DATA1_OUT1_ADDR(base) ((base) + (0x2FUL))
#define REG_SLIDE_VL_DATA1_OUT2_ADDR(base) ((base) + (0x30UL))
#define REG_SLIDE_VL_DATA2_OUT0_ADDR(base) ((base) + (0x31UL))
#define REG_SLIDE_VL_DATA2_OUT1_ADDR(base) ((base) + (0x32UL))
#define REG_SLIDE_VL_DATA2_OUT2_ADDR(base) ((base) + (0x33UL))
#define REG_SLIDE_VL_DATA3_OUT0_ADDR(base) ((base) + (0x34UL))
#define REG_SLIDE_VL_DATA3_OUT1_ADDR(base) ((base) + (0x35UL))
#define REG_SLIDE_VL_DATA3_OUT2_ADDR(base) ((base) + (0x36UL))
#else
#define REG_CLJ_CTRL_REG0_ADDR(base) ((base) + (0x00))
#define REG_CLJ_CTRL_REG1_ADDR(base) ((base) + (0x01))
#define REG_CLJ_CTRL_REG2_ADDR(base) ((base) + (0x02))
#define REG_CLJ_CTRL_REG3_ADDR(base) ((base) + (0x03))
#define REG_SLIDE_CNT_DATA_OUT0_ADDR(base) ((base) + (0x04))
#define REG_SLIDE_CNT_DATA_OUT1_ADDR(base) ((base) + (0x05))
#define REG_SLIDE_CNT_DATA_OUT2_ADDR(base) ((base) + (0x06))
#define REG_SLIDE_IH_DATA0_OUT0_ADDR(base) ((base) + (0x07))
#define REG_SLIDE_IH_DATA0_OUT1_ADDR(base) ((base) + (0x08))
#define REG_SLIDE_IH_DATA0_OUT2_ADDR(base) ((base) + (0x09))
#define REG_SLIDE_IH_DATA1_OUT0_ADDR(base) ((base) + (0x0A))
#define REG_SLIDE_IH_DATA1_OUT1_ADDR(base) ((base) + (0x0B))
#define REG_SLIDE_IH_DATA1_OUT2_ADDR(base) ((base) + (0x0C))
#define REG_SLIDE_IH_DATA2_OUT0_ADDR(base) ((base) + (0x0D))
#define REG_SLIDE_IH_DATA2_OUT1_ADDR(base) ((base) + (0x0E))
#define REG_SLIDE_IH_DATA2_OUT2_ADDR(base) ((base) + (0x0F))
#define REG_SLIDE_IH_DATA3_OUT0_ADDR(base) ((base) + (0x10))
#define REG_SLIDE_IH_DATA3_OUT1_ADDR(base) ((base) + (0x11))
#define REG_SLIDE_IH_DATA3_OUT2_ADDR(base) ((base) + (0x12))
#define REG_SLIDE_VH_DATA0_OUT0_ADDR(base) ((base) + (0x13))
#define REG_SLIDE_VH_DATA0_OUT1_ADDR(base) ((base) + (0x14))
#define REG_SLIDE_VH_DATA0_OUT2_ADDR(base) ((base) + (0x15))
#define REG_SLIDE_VH_DATA1_OUT0_ADDR(base) ((base) + (0x16))
#define REG_SLIDE_VH_DATA1_OUT1_ADDR(base) ((base) + (0x17))
#define REG_SLIDE_VH_DATA1_OUT2_ADDR(base) ((base) + (0x18))
#define REG_SLIDE_VH_DATA2_OUT0_ADDR(base) ((base) + (0x19))
#define REG_SLIDE_VH_DATA2_OUT1_ADDR(base) ((base) + (0x1A))
#define REG_SLIDE_VH_DATA2_OUT2_ADDR(base) ((base) + (0x1B))
#define REG_SLIDE_VH_DATA3_OUT0_ADDR(base) ((base) + (0x1C))
#define REG_SLIDE_VH_DATA3_OUT1_ADDR(base) ((base) + (0x1D))
#define REG_SLIDE_VH_DATA3_OUT2_ADDR(base) ((base) + (0x1E))
#define REG_SLIDE_IL_DATA0_OUT0_ADDR(base) ((base) + (0x1F))
#define REG_SLIDE_IL_DATA0_OUT1_ADDR(base) ((base) + (0x20))
#define REG_SLIDE_IL_DATA0_OUT2_ADDR(base) ((base) + (0x21))
#define REG_SLIDE_IL_DATA1_OUT0_ADDR(base) ((base) + (0x22))
#define REG_SLIDE_IL_DATA1_OUT1_ADDR(base) ((base) + (0x23))
#define REG_SLIDE_IL_DATA1_OUT2_ADDR(base) ((base) + (0x24))
#define REG_SLIDE_IL_DATA2_OUT0_ADDR(base) ((base) + (0x25))
#define REG_SLIDE_IL_DATA2_OUT1_ADDR(base) ((base) + (0x26))
#define REG_SLIDE_IL_DATA2_OUT2_ADDR(base) ((base) + (0x27))
#define REG_SLIDE_IL_DATA3_OUT0_ADDR(base) ((base) + (0x28))
#define REG_SLIDE_IL_DATA3_OUT1_ADDR(base) ((base) + (0x29))
#define REG_SLIDE_IL_DATA3_OUT2_ADDR(base) ((base) + (0x2A))
#define REG_SLIDE_VL_DATA0_OUT0_ADDR(base) ((base) + (0x2B))
#define REG_SLIDE_VL_DATA0_OUT1_ADDR(base) ((base) + (0x2C))
#define REG_SLIDE_VL_DATA0_OUT2_ADDR(base) ((base) + (0x2D))
#define REG_SLIDE_VL_DATA1_OUT0_ADDR(base) ((base) + (0x2E))
#define REG_SLIDE_VL_DATA1_OUT1_ADDR(base) ((base) + (0x2F))
#define REG_SLIDE_VL_DATA1_OUT2_ADDR(base) ((base) + (0x30))
#define REG_SLIDE_VL_DATA2_OUT0_ADDR(base) ((base) + (0x31))
#define REG_SLIDE_VL_DATA2_OUT1_ADDR(base) ((base) + (0x32))
#define REG_SLIDE_VL_DATA2_OUT2_ADDR(base) ((base) + (0x33))
#define REG_SLIDE_VL_DATA3_OUT0_ADDR(base) ((base) + (0x34))
#define REG_SLIDE_VL_DATA3_OUT1_ADDR(base) ((base) + (0x35))
#define REG_SLIDE_VL_DATA3_OUT2_ADDR(base) ((base) + (0x36))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_COUL_IRQ_FLAG_ADDR(base) ((base) + (0x00UL))
#define REG_COUL_H_IRQ_FLAG_ADDR(base) ((base) + (0x01UL))
#define REG_COUL_L_IRQ_FLAG_ADDR(base) ((base) + (0x02UL))
#define REG_COUL_IRQ_MASK_ADDR(base) ((base) + (0x03UL))
#define REG_COUL_H_IRQ_MASK_ADDR(base) ((base) + (0x04UL))
#define REG_COUL_L_IRQ_MASK_ADDR(base) ((base) + (0x05UL))
#define REG_COUL_H_IRQ_STATUS_ADDR(base) ((base) + (0x06UL))
#define REG_COUL_L_IRQ_STATUS_ADDR(base) ((base) + (0x07UL))
#define REG_COUL_RD_REQ_ADDR(base) ((base) + (0x08UL))
#define REG_CLJ_CTRL_REG4_ADDR(base) ((base) + (0x09UL))
#define REG_CLJ_CTRL_REG5_ADDR(base) ((base) + (0x0AUL))
#define REG_CIC_CTRL_ADDR(base) ((base) + (0x0BUL))
#define REG_STATE_TEST_ADDR(base) ((base) + (0x0CUL))
#define REG_CLJ_DEBUG0_ADDR(base) ((base) + (0x0DUL))
#define REG_CLJ_DEBUG1_ADDR(base) ((base) + (0x0EUL))
#define REG_DEBUG_WRITE_PRO_ADDR(base) ((base) + (0x10UL))
#define REG_COUL_CLK_CALI_EN_ADDR(base) ((base) + (0x11UL))
#define REG_DEBUG_CIC_DATA_SEL_ADDR(base) ((base) + (0x12UL))
#define REG_COUL_TB_CFG_ADDR(base) ((base) + (0x13UL))
#define REG_COUL_I_TB_BUS0_ADDR(base) ((base) + (0x14UL))
#define REG_COUL_I_TB_BUS1_ADDR(base) ((base) + (0x15UL))
#define REG_COUL_I_TB_BUS2_ADDR(base) ((base) + (0x16UL))
#define REG_COUL_V_TB_BUS0_ADDR(base) ((base) + (0x17UL))
#define REG_COUL_V_TB_BUS1_ADDR(base) ((base) + (0x18UL))
#define REG_COUL_V_TB_BUS2_ADDR(base) ((base) + (0x19UL))
#define REG_V_INT0_ADDR(base) ((base) + (0x1AUL))
#define REG_V_INT1_ADDR(base) ((base) + (0x1BUL))
#define REG_V_INT2_ADDR(base) ((base) + (0x1CUL))
#define REG_I_OUT_GATE0_ADDR(base) ((base) + (0x1DUL))
#define REG_I_OUT_GATE1_ADDR(base) ((base) + (0x1EUL))
#define REG_I_OUT_GATE2_ADDR(base) ((base) + (0x1FUL))
#define REG_I_IN_GATE0_ADDR(base) ((base) + (0x20UL))
#define REG_I_IN_GATE1_ADDR(base) ((base) + (0x21UL))
#define REG_I_IN_GATE2_ADDR(base) ((base) + (0x22UL))
#define REG_CL_INT0_ADDR(base) ((base) + (0x23UL))
#define REG_CL_INT1_ADDR(base) ((base) + (0x24UL))
#define REG_CL_INT2_ADDR(base) ((base) + (0x25UL))
#define REG_CL_INT3_ADDR(base) ((base) + (0x26UL))
#define REG_CL_INT4_ADDR(base) ((base) + (0x27UL))
#define REG_RTC_OCV_OUT_ADDR(base) ((base) + (0x28UL))
#define REG_RD_SYNC_PRO_ADDR(base) ((base) + (0x29UL))
#define REG_RD_SYNC_SEL_ADDR(base) ((base) + (0x2AUL))
#define REG_CIC_EN_DEBUG_ADDR(base) ((base) + (0x2BUL))
#define REG_SC_NICE_TB_SEL_ADDR(base) ((base) + (0x2CUL))
#define REG_SC_NICE_TB_TRIG_ADDR(base) ((base) + (0x2DUL))
#define REG_ECO_PWROFF_VLD_ADDR(base) ((base) + (0x2EUL))
#define REG_CLJ_DBG_CFG_ADDR(base) ((base) + (0x2FUL))
#define REG_CLJ_DBG_STATUS_ADDR(base) ((base) + (0x30UL))
#define REG_H_CL_OUT_RO0_ADDR(base) ((base) + (0x40UL))
#define REG_H_CL_OUT_RO1_ADDR(base) ((base) + (0x41UL))
#define REG_H_CL_OUT_RO2_ADDR(base) ((base) + (0x42UL))
#define REG_H_CL_OUT_RO3_ADDR(base) ((base) + (0x43UL))
#define REG_H_CL_OUT_RO4_ADDR(base) ((base) + (0x44UL))
#define REG_H_CL_IN_RO0_ADDR(base) ((base) + (0x45UL))
#define REG_H_CL_IN_RO1_ADDR(base) ((base) + (0x46UL))
#define REG_H_CL_IN_RO2_ADDR(base) ((base) + (0x47UL))
#define REG_H_CL_IN_RO3_ADDR(base) ((base) + (0x48UL))
#define REG_H_CL_IN_RO4_ADDR(base) ((base) + (0x49UL))
#define REG_H_CHG_TIMER_RO0_ADDR(base) ((base) + (0x4AUL))
#define REG_H_CHG_TIMER_RO1_ADDR(base) ((base) + (0x4BUL))
#define REG_H_CHG_TIMER_RO2_ADDR(base) ((base) + (0x4CUL))
#define REG_H_CHG_TIMER_RO3_ADDR(base) ((base) + (0x4DUL))
#define REG_H_LOAD_TIMER_RO0_ADDR(base) ((base) + (0x4EUL))
#define REG_H_LOAD_TIMER_RO1_ADDR(base) ((base) + (0x4FUL))
#define REG_H_LOAD_TIMER_RO2_ADDR(base) ((base) + (0x50UL))
#define REG_H_LOAD_TIMER_RO3_ADDR(base) ((base) + (0x51UL))
#define REG_L_CL_OUT_RO0_ADDR(base) ((base) + (0x52UL))
#define REG_L_CL_OUT_RO1_ADDR(base) ((base) + (0x53UL))
#define REG_L_CL_OUT_RO2_ADDR(base) ((base) + (0x54UL))
#define REG_L_CL_OUT_RO3_ADDR(base) ((base) + (0x55UL))
#define REG_L_CL_OUT_RO4_ADDR(base) ((base) + (0x56UL))
#define REG_L_CL_IN_RO0_ADDR(base) ((base) + (0x57UL))
#define REG_L_CL_IN_RO1_ADDR(base) ((base) + (0x58UL))
#define REG_L_CL_IN_RO2_ADDR(base) ((base) + (0x59UL))
#define REG_L_CL_IN_RO3_ADDR(base) ((base) + (0x5AUL))
#define REG_L_CL_IN_RO4_ADDR(base) ((base) + (0x5BUL))
#define REG_L_CHG_TIMER_RO0_ADDR(base) ((base) + (0x5CUL))
#define REG_L_CHG_TIMER_RO1_ADDR(base) ((base) + (0x5DUL))
#define REG_L_CHG_TIMER_RO2_ADDR(base) ((base) + (0x5EUL))
#define REG_L_CHG_TIMER_RO3_ADDR(base) ((base) + (0x5FUL))
#define REG_L_LOAD_TIMER_RO0_ADDR(base) ((base) + (0x60UL))
#define REG_L_LOAD_TIMER_RO1_ADDR(base) ((base) + (0x61UL))
#define REG_L_LOAD_TIMER_RO2_ADDR(base) ((base) + (0x62UL))
#define REG_L_LOAD_TIMER_RO3_ADDR(base) ((base) + (0x63UL))
#define REG_ECO_CNT1_OUT0_ADDR(base) ((base) + (0x64UL))
#define REG_ECO_CNT1_OUT1_ADDR(base) ((base) + (0x65UL))
#define REG_ECO_CNT2_OUT0_ADDR(base) ((base) + (0x66UL))
#define REG_ECO_CNT2_OUT1_ADDR(base) ((base) + (0x67UL))
#define REG_ECO_CNT3_OUT0_ADDR(base) ((base) + (0x68UL))
#define REG_ECO_CNT3_OUT1_ADDR(base) ((base) + (0x69UL))
#define REG_ECO_CNT4_OUT0_ADDR(base) ((base) + (0x6AUL))
#define REG_ECO_CNT4_OUT1_ADDR(base) ((base) + (0x6BUL))
#define REG_COUL_TOP_CFG_REG_0_ADDR(base) ((base) + (0x80UL))
#define REG_COUL_TOP_CFG_REG_1_ADDR(base) ((base) + (0x81UL))
#define REG_COUL_TOP_CFG_REG_2_ADDR(base) ((base) + (0x82UL))
#define REG_COUL_TOP_CFG_REG_3_ADDR(base) ((base) + (0x83UL))
#define REG_COUL_TOP_CFG_REG_4_ADDR(base) ((base) + (0x84UL))
#define REG_COUL_TOP_CFG_REG_5_ADDR(base) ((base) + (0x85UL))
#define REG_COUL_TOP_CFG_REG_6_ADDR(base) ((base) + (0x86UL))
#define REG_COUL_TOP_CFG_REG_7_ADDR(base) ((base) + (0x87UL))
#define REG_COUL_TOP_CFG_REG_8_ADDR(base) ((base) + (0x88UL))
#define REG_COUL_TOP_CFG_REG_9_ADDR(base) ((base) + (0x89UL))
#define REG_COUL_TOP_CFG_REG_10_ADDR(base) ((base) + (0x8AUL))
#define REG_COUL_TOP_CFG_REG_11_ADDR(base) ((base) + (0x8BUL))
#define REG_V_DROP_CTRL0_ADDR(base) ((base) + (0xA0UL))
#define REG_H_V_DROP_PRE0_OUT0_ADDR(base) ((base) + (0xB0UL))
#define REG_H_V_DROP_PRE0_OUT1_ADDR(base) ((base) + (0xB1UL))
#define REG_H_V_DROP_PRE0_OUT2_ADDR(base) ((base) + (0xB2UL))
#define REG_H_V_DROP_PRE1_OUT0_ADDR(base) ((base) + (0xB3UL))
#define REG_H_V_DROP_PRE1_OUT1_ADDR(base) ((base) + (0xB4UL))
#define REG_H_V_DROP_PRE1_OUT2_ADDR(base) ((base) + (0xB5UL))
#define REG_H_V_DROP_PRE2_OUT0_ADDR(base) ((base) + (0xB6UL))
#define REG_H_V_DROP_PRE2_OUT1_ADDR(base) ((base) + (0xB7UL))
#define REG_H_V_DROP_PRE2_OUT2_ADDR(base) ((base) + (0xB8UL))
#define REG_L_V_DROP_PRE0_OUT0_ADDR(base) ((base) + (0xB9UL))
#define REG_L_V_DROP_PRE0_OUT1_ADDR(base) ((base) + (0xBAUL))
#define REG_L_V_DROP_PRE0_OUT2_ADDR(base) ((base) + (0xBBUL))
#define REG_L_V_DROP_PRE1_OUT0_ADDR(base) ((base) + (0xBCUL))
#define REG_L_V_DROP_PRE1_OUT1_ADDR(base) ((base) + (0xBDUL))
#define REG_L_V_DROP_PRE1_OUT2_ADDR(base) ((base) + (0xBEUL))
#define REG_L_V_DROP_PRE2_OUT0_ADDR(base) ((base) + (0xBFUL))
#define REG_L_V_DROP_PRE2_OUT1_ADDR(base) ((base) + (0xC0UL))
#define REG_L_V_DROP_PRE2_OUT2_ADDR(base) ((base) + (0xC1UL))
#else
#define REG_COUL_IRQ_FLAG_ADDR(base) ((base) + (0x00))
#define REG_COUL_H_IRQ_FLAG_ADDR(base) ((base) + (0x01))
#define REG_COUL_L_IRQ_FLAG_ADDR(base) ((base) + (0x02))
#define REG_COUL_IRQ_MASK_ADDR(base) ((base) + (0x03))
#define REG_COUL_H_IRQ_MASK_ADDR(base) ((base) + (0x04))
#define REG_COUL_L_IRQ_MASK_ADDR(base) ((base) + (0x05))
#define REG_COUL_H_IRQ_STATUS_ADDR(base) ((base) + (0x06))
#define REG_COUL_L_IRQ_STATUS_ADDR(base) ((base) + (0x07))
#define REG_COUL_RD_REQ_ADDR(base) ((base) + (0x08))
#define REG_CLJ_CTRL_REG4_ADDR(base) ((base) + (0x09))
#define REG_CLJ_CTRL_REG5_ADDR(base) ((base) + (0x0A))
#define REG_CIC_CTRL_ADDR(base) ((base) + (0x0B))
#define REG_STATE_TEST_ADDR(base) ((base) + (0x0C))
#define REG_CLJ_DEBUG0_ADDR(base) ((base) + (0x0D))
#define REG_CLJ_DEBUG1_ADDR(base) ((base) + (0x0E))
#define REG_DEBUG_WRITE_PRO_ADDR(base) ((base) + (0x10))
#define REG_COUL_CLK_CALI_EN_ADDR(base) ((base) + (0x11))
#define REG_DEBUG_CIC_DATA_SEL_ADDR(base) ((base) + (0x12))
#define REG_COUL_TB_CFG_ADDR(base) ((base) + (0x13))
#define REG_COUL_I_TB_BUS0_ADDR(base) ((base) + (0x14))
#define REG_COUL_I_TB_BUS1_ADDR(base) ((base) + (0x15))
#define REG_COUL_I_TB_BUS2_ADDR(base) ((base) + (0x16))
#define REG_COUL_V_TB_BUS0_ADDR(base) ((base) + (0x17))
#define REG_COUL_V_TB_BUS1_ADDR(base) ((base) + (0x18))
#define REG_COUL_V_TB_BUS2_ADDR(base) ((base) + (0x19))
#define REG_V_INT0_ADDR(base) ((base) + (0x1A))
#define REG_V_INT1_ADDR(base) ((base) + (0x1B))
#define REG_V_INT2_ADDR(base) ((base) + (0x1C))
#define REG_I_OUT_GATE0_ADDR(base) ((base) + (0x1D))
#define REG_I_OUT_GATE1_ADDR(base) ((base) + (0x1E))
#define REG_I_OUT_GATE2_ADDR(base) ((base) + (0x1F))
#define REG_I_IN_GATE0_ADDR(base) ((base) + (0x20))
#define REG_I_IN_GATE1_ADDR(base) ((base) + (0x21))
#define REG_I_IN_GATE2_ADDR(base) ((base) + (0x22))
#define REG_CL_INT0_ADDR(base) ((base) + (0x23))
#define REG_CL_INT1_ADDR(base) ((base) + (0x24))
#define REG_CL_INT2_ADDR(base) ((base) + (0x25))
#define REG_CL_INT3_ADDR(base) ((base) + (0x26))
#define REG_CL_INT4_ADDR(base) ((base) + (0x27))
#define REG_RTC_OCV_OUT_ADDR(base) ((base) + (0x28))
#define REG_RD_SYNC_PRO_ADDR(base) ((base) + (0x29))
#define REG_RD_SYNC_SEL_ADDR(base) ((base) + (0x2A))
#define REG_CIC_EN_DEBUG_ADDR(base) ((base) + (0x2B))
#define REG_SC_NICE_TB_SEL_ADDR(base) ((base) + (0x2C))
#define REG_SC_NICE_TB_TRIG_ADDR(base) ((base) + (0x2D))
#define REG_ECO_PWROFF_VLD_ADDR(base) ((base) + (0x2E))
#define REG_CLJ_DBG_CFG_ADDR(base) ((base) + (0x2F))
#define REG_CLJ_DBG_STATUS_ADDR(base) ((base) + (0x30))
#define REG_H_CL_OUT_RO0_ADDR(base) ((base) + (0x40))
#define REG_H_CL_OUT_RO1_ADDR(base) ((base) + (0x41))
#define REG_H_CL_OUT_RO2_ADDR(base) ((base) + (0x42))
#define REG_H_CL_OUT_RO3_ADDR(base) ((base) + (0x43))
#define REG_H_CL_OUT_RO4_ADDR(base) ((base) + (0x44))
#define REG_H_CL_IN_RO0_ADDR(base) ((base) + (0x45))
#define REG_H_CL_IN_RO1_ADDR(base) ((base) + (0x46))
#define REG_H_CL_IN_RO2_ADDR(base) ((base) + (0x47))
#define REG_H_CL_IN_RO3_ADDR(base) ((base) + (0x48))
#define REG_H_CL_IN_RO4_ADDR(base) ((base) + (0x49))
#define REG_H_CHG_TIMER_RO0_ADDR(base) ((base) + (0x4A))
#define REG_H_CHG_TIMER_RO1_ADDR(base) ((base) + (0x4B))
#define REG_H_CHG_TIMER_RO2_ADDR(base) ((base) + (0x4C))
#define REG_H_CHG_TIMER_RO3_ADDR(base) ((base) + (0x4D))
#define REG_H_LOAD_TIMER_RO0_ADDR(base) ((base) + (0x4E))
#define REG_H_LOAD_TIMER_RO1_ADDR(base) ((base) + (0x4F))
#define REG_H_LOAD_TIMER_RO2_ADDR(base) ((base) + (0x50))
#define REG_H_LOAD_TIMER_RO3_ADDR(base) ((base) + (0x51))
#define REG_L_CL_OUT_RO0_ADDR(base) ((base) + (0x52))
#define REG_L_CL_OUT_RO1_ADDR(base) ((base) + (0x53))
#define REG_L_CL_OUT_RO2_ADDR(base) ((base) + (0x54))
#define REG_L_CL_OUT_RO3_ADDR(base) ((base) + (0x55))
#define REG_L_CL_OUT_RO4_ADDR(base) ((base) + (0x56))
#define REG_L_CL_IN_RO0_ADDR(base) ((base) + (0x57))
#define REG_L_CL_IN_RO1_ADDR(base) ((base) + (0x58))
#define REG_L_CL_IN_RO2_ADDR(base) ((base) + (0x59))
#define REG_L_CL_IN_RO3_ADDR(base) ((base) + (0x5A))
#define REG_L_CL_IN_RO4_ADDR(base) ((base) + (0x5B))
#define REG_L_CHG_TIMER_RO0_ADDR(base) ((base) + (0x5C))
#define REG_L_CHG_TIMER_RO1_ADDR(base) ((base) + (0x5D))
#define REG_L_CHG_TIMER_RO2_ADDR(base) ((base) + (0x5E))
#define REG_L_CHG_TIMER_RO3_ADDR(base) ((base) + (0x5F))
#define REG_L_LOAD_TIMER_RO0_ADDR(base) ((base) + (0x60))
#define REG_L_LOAD_TIMER_RO1_ADDR(base) ((base) + (0x61))
#define REG_L_LOAD_TIMER_RO2_ADDR(base) ((base) + (0x62))
#define REG_L_LOAD_TIMER_RO3_ADDR(base) ((base) + (0x63))
#define REG_ECO_CNT1_OUT0_ADDR(base) ((base) + (0x64))
#define REG_ECO_CNT1_OUT1_ADDR(base) ((base) + (0x65))
#define REG_ECO_CNT2_OUT0_ADDR(base) ((base) + (0x66))
#define REG_ECO_CNT2_OUT1_ADDR(base) ((base) + (0x67))
#define REG_ECO_CNT3_OUT0_ADDR(base) ((base) + (0x68))
#define REG_ECO_CNT3_OUT1_ADDR(base) ((base) + (0x69))
#define REG_ECO_CNT4_OUT0_ADDR(base) ((base) + (0x6A))
#define REG_ECO_CNT4_OUT1_ADDR(base) ((base) + (0x6B))
#define REG_COUL_TOP_CFG_REG_0_ADDR(base) ((base) + (0x80))
#define REG_COUL_TOP_CFG_REG_1_ADDR(base) ((base) + (0x81))
#define REG_COUL_TOP_CFG_REG_2_ADDR(base) ((base) + (0x82))
#define REG_COUL_TOP_CFG_REG_3_ADDR(base) ((base) + (0x83))
#define REG_COUL_TOP_CFG_REG_4_ADDR(base) ((base) + (0x84))
#define REG_COUL_TOP_CFG_REG_5_ADDR(base) ((base) + (0x85))
#define REG_COUL_TOP_CFG_REG_6_ADDR(base) ((base) + (0x86))
#define REG_COUL_TOP_CFG_REG_7_ADDR(base) ((base) + (0x87))
#define REG_COUL_TOP_CFG_REG_8_ADDR(base) ((base) + (0x88))
#define REG_COUL_TOP_CFG_REG_9_ADDR(base) ((base) + (0x89))
#define REG_COUL_TOP_CFG_REG_10_ADDR(base) ((base) + (0x8A))
#define REG_COUL_TOP_CFG_REG_11_ADDR(base) ((base) + (0x8B))
#define REG_V_DROP_CTRL0_ADDR(base) ((base) + (0xA0))
#define REG_H_V_DROP_PRE0_OUT0_ADDR(base) ((base) + (0xB0))
#define REG_H_V_DROP_PRE0_OUT1_ADDR(base) ((base) + (0xB1))
#define REG_H_V_DROP_PRE0_OUT2_ADDR(base) ((base) + (0xB2))
#define REG_H_V_DROP_PRE1_OUT0_ADDR(base) ((base) + (0xB3))
#define REG_H_V_DROP_PRE1_OUT1_ADDR(base) ((base) + (0xB4))
#define REG_H_V_DROP_PRE1_OUT2_ADDR(base) ((base) + (0xB5))
#define REG_H_V_DROP_PRE2_OUT0_ADDR(base) ((base) + (0xB6))
#define REG_H_V_DROP_PRE2_OUT1_ADDR(base) ((base) + (0xB7))
#define REG_H_V_DROP_PRE2_OUT2_ADDR(base) ((base) + (0xB8))
#define REG_L_V_DROP_PRE0_OUT0_ADDR(base) ((base) + (0xB9))
#define REG_L_V_DROP_PRE0_OUT1_ADDR(base) ((base) + (0xBA))
#define REG_L_V_DROP_PRE0_OUT2_ADDR(base) ((base) + (0xBB))
#define REG_L_V_DROP_PRE1_OUT0_ADDR(base) ((base) + (0xBC))
#define REG_L_V_DROP_PRE1_OUT1_ADDR(base) ((base) + (0xBD))
#define REG_L_V_DROP_PRE1_OUT2_ADDR(base) ((base) + (0xBE))
#define REG_L_V_DROP_PRE2_OUT0_ADDR(base) ((base) + (0xBF))
#define REG_L_V_DROP_PRE2_OUT1_ADDR(base) ((base) + (0xC0))
#define REG_L_V_DROP_PRE2_OUT2_ADDR(base) ((base) + (0xC1))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_H_CL_OUT0_ADDR(base) ((base) + (0x00UL))
#define REG_H_CL_OUT1_ADDR(base) ((base) + (0x01UL))
#define REG_H_CL_OUT2_ADDR(base) ((base) + (0x02UL))
#define REG_H_CL_OUT3_ADDR(base) ((base) + (0x03UL))
#define REG_H_CL_OUT4_ADDR(base) ((base) + (0x04UL))
#define REG_H_CL_IN0_ADDR(base) ((base) + (0x05UL))
#define REG_H_CL_IN1_ADDR(base) ((base) + (0x06UL))
#define REG_H_CL_IN2_ADDR(base) ((base) + (0x07UL))
#define REG_H_CL_IN3_ADDR(base) ((base) + (0x08UL))
#define REG_H_CL_IN4_ADDR(base) ((base) + (0x09UL))
#define REG_H_CHG_TIMER0_ADDR(base) ((base) + (0x0AUL))
#define REG_H_CHG_TIMER1_ADDR(base) ((base) + (0x0BUL))
#define REG_H_CHG_TIMER2_ADDR(base) ((base) + (0x0CUL))
#define REG_H_CHG_TIMER3_ADDR(base) ((base) + (0x0DUL))
#define REG_H_LOAD_TIMER0_ADDR(base) ((base) + (0x0EUL))
#define REG_H_LOAD_TIMER1_ADDR(base) ((base) + (0x0FUL))
#define REG_H_LOAD_TIMER2_ADDR(base) ((base) + (0x10UL))
#define REG_H_LOAD_TIMER3_ADDR(base) ((base) + (0x11UL))
#define REG_H0_OFFSET_CURRENT_MOD_0_ADDR(base) ((base) + (0x12UL))
#define REG_H0_OFFSET_CURRENT_MOD_1_ADDR(base) ((base) + (0x13UL))
#define REG_H0_OFFSET_CURRENT_MOD_2_ADDR(base) ((base) + (0x14UL))
#define REG_H1_OFFSET_CURRENT_MOD_0_ADDR(base) ((base) + (0x15UL))
#define REG_H1_OFFSET_CURRENT_MOD_1_ADDR(base) ((base) + (0x16UL))
#define REG_H1_OFFSET_CURRENT_MOD_2_ADDR(base) ((base) + (0x17UL))
#define REG_H_OFFSET_VOLTAGE_MOD_0_ADDR(base) ((base) + (0x18UL))
#define REG_H_OFFSET_VOLTAGE_MOD_1_ADDR(base) ((base) + (0x19UL))
#define REG_H_OFFSET_VOLTAGE_MOD_2_ADDR(base) ((base) + (0x1AUL))
#define REG_H_CURRENT_0_ADDR(base) ((base) + (0x1BUL))
#define REG_H_CURRENT_1_ADDR(base) ((base) + (0x1CUL))
#define REG_H_CURRENT_2_ADDR(base) ((base) + (0x1DUL))
#define REG_H_V_OUT_0_ADDR(base) ((base) + (0x1EUL))
#define REG_H_V_OUT_1_ADDR(base) ((base) + (0x1FUL))
#define REG_H_V_OUT_2_ADDR(base) ((base) + (0x20UL))
#define REG_H0_OFFSET_CURRENT0_ADDR(base) ((base) + (0x21UL))
#define REG_H0_OFFSET_CURRENT1_ADDR(base) ((base) + (0x22UL))
#define REG_H0_OFFSET_CURRENT2_ADDR(base) ((base) + (0x23UL))
#define REG_H1_OFFSET_CURRENT0_ADDR(base) ((base) + (0x24UL))
#define REG_H1_OFFSET_CURRENT1_ADDR(base) ((base) + (0x25UL))
#define REG_H1_OFFSET_CURRENT2_ADDR(base) ((base) + (0x26UL))
#define REG_H_OFFSET_VOLTAGE0_ADDR(base) ((base) + (0x27UL))
#define REG_H_OFFSET_VOLTAGE1_ADDR(base) ((base) + (0x28UL))
#define REG_H_OFFSET_VOLTAGE2_ADDR(base) ((base) + (0x29UL))
#define REG_H_OCV_VOLTAGE0_ADDR(base) ((base) + (0x2AUL))
#define REG_H_OCV_VOLTAGE1_ADDR(base) ((base) + (0x2BUL))
#define REG_H_OCV_VOLTAGE2_ADDR(base) ((base) + (0x2CUL))
#define REG_H_OCV_CURRENT0_ADDR(base) ((base) + (0x2DUL))
#define REG_H_OCV_CURRENT1_ADDR(base) ((base) + (0x2EUL))
#define REG_H_OCV_CURRENT2_ADDR(base) ((base) + (0x2FUL))
#define REG_H_ECO_OUT_CLIN_0_ADDR(base) ((base) + (0x30UL))
#define REG_H_ECO_OUT_CLIN_1_ADDR(base) ((base) + (0x31UL))
#define REG_H_ECO_OUT_CLIN_2_ADDR(base) ((base) + (0x32UL))
#define REG_H_ECO_OUT_CLIN_3_ADDR(base) ((base) + (0x33UL))
#define REG_H_ECO_OUT_CLIN_4_ADDR(base) ((base) + (0x34UL))
#define REG_H_ECO_OUT_CLOUT_0_ADDR(base) ((base) + (0x35UL))
#define REG_H_ECO_OUT_CLOUT_1_ADDR(base) ((base) + (0x36UL))
#define REG_H_ECO_OUT_CLOUT_2_ADDR(base) ((base) + (0x37UL))
#define REG_H_ECO_OUT_CLOUT_3_ADDR(base) ((base) + (0x38UL))
#define REG_H_ECO_OUT_CLOUT_4_ADDR(base) ((base) + (0x39UL))
#define REG_H_V_PRE0_OUT0_ADDR(base) ((base) + (0x3AUL))
#define REG_H_V_PRE0_OUT1_ADDR(base) ((base) + (0x3BUL))
#define REG_H_V_PRE0_OUT2_ADDR(base) ((base) + (0x3CUL))
#define REG_H_V_PRE1_OUT0_ADDR(base) ((base) + (0x3DUL))
#define REG_H_V_PRE1_OUT1_ADDR(base) ((base) + (0x3EUL))
#define REG_H_V_PRE1_OUT2_ADDR(base) ((base) + (0x3FUL))
#define REG_H_V_PRE2_OUT0_ADDR(base) ((base) + (0x40UL))
#define REG_H_V_PRE2_OUT1_ADDR(base) ((base) + (0x41UL))
#define REG_H_V_PRE2_OUT2_ADDR(base) ((base) + (0x42UL))
#define REG_H_V_PRE3_OUT0_ADDR(base) ((base) + (0x43UL))
#define REG_H_V_PRE3_OUT1_ADDR(base) ((base) + (0x44UL))
#define REG_H_V_PRE3_OUT2_ADDR(base) ((base) + (0x45UL))
#define REG_H_V_PRE4_OUT0_ADDR(base) ((base) + (0x46UL))
#define REG_H_V_PRE4_OUT1_ADDR(base) ((base) + (0x47UL))
#define REG_H_V_PRE4_OUT2_ADDR(base) ((base) + (0x48UL))
#define REG_H_V_PRE5_OUT0_ADDR(base) ((base) + (0x49UL))
#define REG_H_V_PRE5_OUT1_ADDR(base) ((base) + (0x4AUL))
#define REG_H_V_PRE5_OUT2_ADDR(base) ((base) + (0x4BUL))
#define REG_H_V_PRE6_OUT0_ADDR(base) ((base) + (0x4CUL))
#define REG_H_V_PRE6_OUT1_ADDR(base) ((base) + (0x4DUL))
#define REG_H_V_PRE6_OUT2_ADDR(base) ((base) + (0x4EUL))
#define REG_H_V_PRE7_OUT0_ADDR(base) ((base) + (0x4FUL))
#define REG_H_V_PRE7_OUT1_ADDR(base) ((base) + (0x50UL))
#define REG_H_V_PRE7_OUT2_ADDR(base) ((base) + (0x51UL))
#define REG_H_CURRENT_PRE0_OUT0_ADDR(base) ((base) + (0x52UL))
#define REG_H_CURRENT_PRE0_OUT1_ADDR(base) ((base) + (0x53UL))
#define REG_H_CURRENT_PRE0_OUT2_ADDR(base) ((base) + (0x54UL))
#define REG_H_CURRENT_PRE1_OUT0_ADDR(base) ((base) + (0x55UL))
#define REG_H_CURRENT_PRE1_OUT1_ADDR(base) ((base) + (0x56UL))
#define REG_H_CURRENT_PRE1_OUT2_ADDR(base) ((base) + (0x57UL))
#define REG_H_CURRENT_PRE2_OUT0_ADDR(base) ((base) + (0x58UL))
#define REG_H_CURRENT_PRE2_OUT1_ADDR(base) ((base) + (0x59UL))
#define REG_H_CURRENT_PRE2_OUT2_ADDR(base) ((base) + (0x5AUL))
#define REG_H_CURRENT_PRE3_OUT0_ADDR(base) ((base) + (0x5BUL))
#define REG_H_CURRENT_PRE3_OUT1_ADDR(base) ((base) + (0x5CUL))
#define REG_H_CURRENT_PRE3_OUT2_ADDR(base) ((base) + (0x5DUL))
#define REG_H_CURRENT_PRE4_OUT0_ADDR(base) ((base) + (0x5EUL))
#define REG_H_CURRENT_PRE4_OUT1_ADDR(base) ((base) + (0x5FUL))
#define REG_H_CURRENT_PRE4_OUT2_ADDR(base) ((base) + (0x60UL))
#define REG_H_CURRENT_PRE5_OUT0_ADDR(base) ((base) + (0x61UL))
#define REG_H_CURRENT_PRE5_OUT1_ADDR(base) ((base) + (0x62UL))
#define REG_H_CURRENT_PRE5_OUT2_ADDR(base) ((base) + (0x63UL))
#define REG_H_CURRENT_PRE6_OUT0_ADDR(base) ((base) + (0x64UL))
#define REG_H_CURRENT_PRE6_OUT1_ADDR(base) ((base) + (0x65UL))
#define REG_H_CURRENT_PRE6_OUT2_ADDR(base) ((base) + (0x66UL))
#define REG_H_CURRENT_PRE7_OUT0_ADDR(base) ((base) + (0x67UL))
#define REG_H_CURRENT_PRE7_OUT1_ADDR(base) ((base) + (0x68UL))
#define REG_H_CURRENT_PRE7_OUT2_ADDR(base) ((base) + (0x69UL))
#define REG_H_V_OCV_PRE1_OUT0_ADDR(base) ((base) + (0x6AUL))
#define REG_H_V_OCV_PRE1_OUT1_ADDR(base) ((base) + (0x6BUL))
#define REG_H_V_OCV_PRE1_OUT2_ADDR(base) ((base) + (0x6CUL))
#define REG_H_V_OCV_PRE2_OUT0_ADDR(base) ((base) + (0x6DUL))
#define REG_H_V_OCV_PRE2_OUT1_ADDR(base) ((base) + (0x6EUL))
#define REG_H_V_OCV_PRE2_OUT2_ADDR(base) ((base) + (0x6FUL))
#define REG_H_V_OCV_PRE3_OUT0_ADDR(base) ((base) + (0x70UL))
#define REG_H_V_OCV_PRE3_OUT1_ADDR(base) ((base) + (0x71UL))
#define REG_H_V_OCV_PRE3_OUT2_ADDR(base) ((base) + (0x72UL))
#define REG_H_V_OCV_PRE4_OUT0_ADDR(base) ((base) + (0x73UL))
#define REG_H_V_OCV_PRE4_OUT1_ADDR(base) ((base) + (0x74UL))
#define REG_H_V_OCV_PRE4_OUT2_ADDR(base) ((base) + (0x75UL))
#define REG_H_I_OCV_PRE1_OUT0_ADDR(base) ((base) + (0x76UL))
#define REG_H_I_OCV_PRE1_OUT1_ADDR(base) ((base) + (0x77UL))
#define REG_H_I_OCV_PRE1_OUT2_ADDR(base) ((base) + (0x78UL))
#define REG_H_I_OCV_PRE2_OUT0_ADDR(base) ((base) + (0x79UL))
#define REG_H_I_OCV_PRE2_OUT1_ADDR(base) ((base) + (0x7AUL))
#define REG_H_I_OCV_PRE2_OUT2_ADDR(base) ((base) + (0x7BUL))
#define REG_H_I_OCV_PRE3_OUT0_ADDR(base) ((base) + (0x7CUL))
#define REG_H_I_OCV_PRE3_OUT1_ADDR(base) ((base) + (0x7DUL))
#define REG_H_I_OCV_PRE3_OUT2_ADDR(base) ((base) + (0x7EUL))
#define REG_H_I_OCV_PRE4_OUT0_ADDR(base) ((base) + (0x7FUL))
#define REG_H_I_OCV_PRE4_OUT1_ADDR(base) ((base) + (0x80UL))
#define REG_H_I_OCV_PRE4_OUT2_ADDR(base) ((base) + (0x81UL))
#define REG_L_CL_OUT0_ADDR(base) ((base) + (0x82UL))
#define REG_L_CL_OUT1_ADDR(base) ((base) + (0x83UL))
#define REG_L_CL_OUT2_ADDR(base) ((base) + (0x84UL))
#define REG_L_CL_OUT3_ADDR(base) ((base) + (0x85UL))
#define REG_L_CL_OUT4_ADDR(base) ((base) + (0x86UL))
#define REG_L_CL_IN0_ADDR(base) ((base) + (0x87UL))
#define REG_L_CL_IN1_ADDR(base) ((base) + (0x88UL))
#define REG_L_CL_IN2_ADDR(base) ((base) + (0x89UL))
#define REG_L_CL_IN3_ADDR(base) ((base) + (0x8AUL))
#define REG_L_CL_IN4_ADDR(base) ((base) + (0x8BUL))
#define REG_L_CHG_TIMER0_ADDR(base) ((base) + (0x8CUL))
#define REG_L_CHG_TIMER1_ADDR(base) ((base) + (0x8DUL))
#define REG_L_CHG_TIMER2_ADDR(base) ((base) + (0x8EUL))
#define REG_L_CHG_TIMER3_ADDR(base) ((base) + (0x8FUL))
#define REG_L_LOAD_TIMER0_ADDR(base) ((base) + (0x90UL))
#define REG_L_LOAD_TIMER1_ADDR(base) ((base) + (0x91UL))
#define REG_L_LOAD_TIMER2_ADDR(base) ((base) + (0x92UL))
#define REG_L_LOAD_TIMER3_ADDR(base) ((base) + (0x93UL))
#define REG_L_OFFSET_CURRENT_MOD_0_ADDR(base) ((base) + (0x94UL))
#define REG_L_OFFSET_CURRENT_MOD_1_ADDR(base) ((base) + (0x95UL))
#define REG_L_OFFSET_CURRENT_MOD_2_ADDR(base) ((base) + (0x96UL))
#define REG_L_OFFSET_VOLTAGE_MOD_0_ADDR(base) ((base) + (0x97UL))
#define REG_L_OFFSET_VOLTAGE_MOD_1_ADDR(base) ((base) + (0x98UL))
#define REG_L_OFFSET_VOLTAGE_MOD_2_ADDR(base) ((base) + (0x99UL))
#define REG_L_CURRENT_0_ADDR(base) ((base) + (0x9AUL))
#define REG_L_CURRENT_1_ADDR(base) ((base) + (0x9BUL))
#define REG_L_CURRENT_2_ADDR(base) ((base) + (0x9CUL))
#define REG_L_V_OUT_0_ADDR(base) ((base) + (0x9DUL))
#define REG_L_V_OUT_1_ADDR(base) ((base) + (0x9EUL))
#define REG_L_V_OUT_2_ADDR(base) ((base) + (0x9FUL))
#define REG_L_OFFSET_CURRENT0_ADDR(base) ((base) + (0xA0UL))
#define REG_L_OFFSET_CURRENT1_ADDR(base) ((base) + (0xA1UL))
#define REG_L_OFFSET_CURRENT2_ADDR(base) ((base) + (0xA2UL))
#define REG_L_OFFSET_VOLTAGE0_ADDR(base) ((base) + (0xA3UL))
#define REG_L_OFFSET_VOLTAGE1_ADDR(base) ((base) + (0xA4UL))
#define REG_L_OFFSET_VOLTAGE2_ADDR(base) ((base) + (0xA5UL))
#define REG_L_OCV_VOLTAGE0_ADDR(base) ((base) + (0xA6UL))
#define REG_L_OCV_VOLTAGE1_ADDR(base) ((base) + (0xA7UL))
#define REG_L_OCV_VOLTAGE2_ADDR(base) ((base) + (0xA8UL))
#define REG_L_OCV_CURRENT0_ADDR(base) ((base) + (0xA9UL))
#define REG_L_OCV_CURRENT1_ADDR(base) ((base) + (0xAAUL))
#define REG_L_OCV_CURRENT2_ADDR(base) ((base) + (0xABUL))
#define REG_L_ECO_OUT_CLIN_0_ADDR(base) ((base) + (0xACUL))
#define REG_L_ECO_OUT_CLIN_1_ADDR(base) ((base) + (0xADUL))
#define REG_L_ECO_OUT_CLIN_2_ADDR(base) ((base) + (0xAEUL))
#define REG_L_ECO_OUT_CLIN_3_ADDR(base) ((base) + (0xAFUL))
#define REG_L_ECO_OUT_CLIN_4_ADDR(base) ((base) + (0xB0UL))
#define REG_L_ECO_OUT_CLOUT_0_ADDR(base) ((base) + (0xB1UL))
#define REG_L_ECO_OUT_CLOUT_1_ADDR(base) ((base) + (0xB2UL))
#define REG_L_ECO_OUT_CLOUT_2_ADDR(base) ((base) + (0xB3UL))
#define REG_L_ECO_OUT_CLOUT_3_ADDR(base) ((base) + (0xB4UL))
#define REG_L_ECO_OUT_CLOUT_4_ADDR(base) ((base) + (0xB5UL))
#define REG_L_V_PRE0_OUT0_ADDR(base) ((base) + (0xB6UL))
#define REG_L_V_PRE0_OUT1_ADDR(base) ((base) + (0xB7UL))
#define REG_L_V_PRE0_OUT2_ADDR(base) ((base) + (0xB8UL))
#define REG_L_V_PRE1_OUT0_ADDR(base) ((base) + (0xB9UL))
#define REG_L_V_PRE1_OUT1_ADDR(base) ((base) + (0xBAUL))
#define REG_L_V_PRE1_OUT2_ADDR(base) ((base) + (0xBBUL))
#define REG_L_V_PRE2_OUT0_ADDR(base) ((base) + (0xBCUL))
#define REG_L_V_PRE2_OUT1_ADDR(base) ((base) + (0xBDUL))
#define REG_L_V_PRE2_OUT2_ADDR(base) ((base) + (0xBEUL))
#define REG_L_V_PRE3_OUT0_ADDR(base) ((base) + (0xBFUL))
#define REG_L_V_PRE3_OUT1_ADDR(base) ((base) + (0xC0UL))
#define REG_L_V_PRE3_OUT2_ADDR(base) ((base) + (0xC1UL))
#define REG_L_V_PRE4_OUT0_ADDR(base) ((base) + (0xC2UL))
#define REG_L_V_PRE4_OUT1_ADDR(base) ((base) + (0xC3UL))
#define REG_L_V_PRE4_OUT2_ADDR(base) ((base) + (0xC4UL))
#define REG_L_V_PRE5_OUT0_ADDR(base) ((base) + (0xC5UL))
#define REG_L_V_PRE5_OUT1_ADDR(base) ((base) + (0xC6UL))
#define REG_L_V_PRE5_OUT2_ADDR(base) ((base) + (0xC7UL))
#define REG_L_V_PRE6_OUT0_ADDR(base) ((base) + (0xC8UL))
#define REG_L_V_PRE6_OUT1_ADDR(base) ((base) + (0xC9UL))
#define REG_L_V_PRE6_OUT2_ADDR(base) ((base) + (0xCAUL))
#define REG_L_V_PRE7_OUT0_ADDR(base) ((base) + (0xCBUL))
#define REG_L_V_PRE7_OUT1_ADDR(base) ((base) + (0xCCUL))
#define REG_L_V_PRE7_OUT2_ADDR(base) ((base) + (0xCDUL))
#define REG_L_CURRENT_PRE0_OUT0_ADDR(base) ((base) + (0xCEUL))
#define REG_L_CURRENT_PRE0_OUT1_ADDR(base) ((base) + (0xCFUL))
#define REG_L_CURRENT_PRE0_OUT2_ADDR(base) ((base) + (0xD0UL))
#define REG_L_CURRENT_PRE1_OUT0_ADDR(base) ((base) + (0xD1UL))
#define REG_L_CURRENT_PRE1_OUT1_ADDR(base) ((base) + (0xD2UL))
#define REG_L_CURRENT_PRE1_OUT2_ADDR(base) ((base) + (0xD3UL))
#define REG_L_CURRENT_PRE2_OUT0_ADDR(base) ((base) + (0xD4UL))
#define REG_L_CURRENT_PRE2_OUT1_ADDR(base) ((base) + (0xD5UL))
#define REG_L_CURRENT_PRE2_OUT2_ADDR(base) ((base) + (0xD6UL))
#define REG_L_CURRENT_PRE3_OUT0_ADDR(base) ((base) + (0xD7UL))
#define REG_L_CURRENT_PRE3_OUT1_ADDR(base) ((base) + (0xD8UL))
#define REG_L_CURRENT_PRE3_OUT2_ADDR(base) ((base) + (0xD9UL))
#define REG_L_CURRENT_PRE4_OUT0_ADDR(base) ((base) + (0xDAUL))
#define REG_L_CURRENT_PRE4_OUT1_ADDR(base) ((base) + (0xDBUL))
#define REG_L_CURRENT_PRE4_OUT2_ADDR(base) ((base) + (0xDCUL))
#define REG_L_CURRENT_PRE5_OUT0_ADDR(base) ((base) + (0xDDUL))
#define REG_L_CURRENT_PRE5_OUT1_ADDR(base) ((base) + (0xDEUL))
#define REG_L_CURRENT_PRE5_OUT2_ADDR(base) ((base) + (0xDFUL))
#define REG_L_CURRENT_PRE6_OUT0_ADDR(base) ((base) + (0xE0UL))
#define REG_L_CURRENT_PRE6_OUT1_ADDR(base) ((base) + (0xE1UL))
#define REG_L_CURRENT_PRE6_OUT2_ADDR(base) ((base) + (0xE2UL))
#define REG_L_CURRENT_PRE7_OUT0_ADDR(base) ((base) + (0xE3UL))
#define REG_L_CURRENT_PRE7_OUT1_ADDR(base) ((base) + (0xE4UL))
#define REG_L_CURRENT_PRE7_OUT2_ADDR(base) ((base) + (0xE5UL))
#define REG_L_V_OCV_PRE1_OUT0_ADDR(base) ((base) + (0xE6UL))
#define REG_L_V_OCV_PRE1_OUT1_ADDR(base) ((base) + (0xE7UL))
#define REG_L_V_OCV_PRE1_OUT2_ADDR(base) ((base) + (0xE8UL))
#define REG_L_V_OCV_PRE2_OUT0_ADDR(base) ((base) + (0xE9UL))
#define REG_L_V_OCV_PRE2_OUT1_ADDR(base) ((base) + (0xEAUL))
#define REG_L_V_OCV_PRE2_OUT2_ADDR(base) ((base) + (0xEBUL))
#define REG_L_V_OCV_PRE3_OUT0_ADDR(base) ((base) + (0xECUL))
#define REG_L_V_OCV_PRE3_OUT1_ADDR(base) ((base) + (0xEDUL))
#define REG_L_V_OCV_PRE3_OUT2_ADDR(base) ((base) + (0xEEUL))
#define REG_L_V_OCV_PRE4_OUT0_ADDR(base) ((base) + (0xEFUL))
#define REG_L_V_OCV_PRE4_OUT1_ADDR(base) ((base) + (0xF0UL))
#define REG_L_V_OCV_PRE4_OUT2_ADDR(base) ((base) + (0xF1UL))
#define REG_L_I_OCV_PRE1_OUT0_ADDR(base) ((base) + (0xF2UL))
#define REG_L_I_OCV_PRE1_OUT1_ADDR(base) ((base) + (0xF3UL))
#define REG_L_I_OCV_PRE1_OUT2_ADDR(base) ((base) + (0xF4UL))
#define REG_L_I_OCV_PRE2_OUT0_ADDR(base) ((base) + (0xF5UL))
#define REG_L_I_OCV_PRE2_OUT1_ADDR(base) ((base) + (0xF6UL))
#define REG_L_I_OCV_PRE2_OUT2_ADDR(base) ((base) + (0xF7UL))
#define REG_L_I_OCV_PRE3_OUT0_ADDR(base) ((base) + (0xF8UL))
#define REG_L_I_OCV_PRE3_OUT1_ADDR(base) ((base) + (0xF9UL))
#define REG_L_I_OCV_PRE3_OUT2_ADDR(base) ((base) + (0xFAUL))
#define REG_L_I_OCV_PRE4_OUT0_ADDR(base) ((base) + (0xFBUL))
#define REG_L_I_OCV_PRE4_OUT1_ADDR(base) ((base) + (0xFCUL))
#define REG_L_I_OCV_PRE4_OUT2_ADDR(base) ((base) + (0xFDUL))
#else
#define REG_H_CL_OUT0_ADDR(base) ((base) + (0x00))
#define REG_H_CL_OUT1_ADDR(base) ((base) + (0x01))
#define REG_H_CL_OUT2_ADDR(base) ((base) + (0x02))
#define REG_H_CL_OUT3_ADDR(base) ((base) + (0x03))
#define REG_H_CL_OUT4_ADDR(base) ((base) + (0x04))
#define REG_H_CL_IN0_ADDR(base) ((base) + (0x05))
#define REG_H_CL_IN1_ADDR(base) ((base) + (0x06))
#define REG_H_CL_IN2_ADDR(base) ((base) + (0x07))
#define REG_H_CL_IN3_ADDR(base) ((base) + (0x08))
#define REG_H_CL_IN4_ADDR(base) ((base) + (0x09))
#define REG_H_CHG_TIMER0_ADDR(base) ((base) + (0x0A))
#define REG_H_CHG_TIMER1_ADDR(base) ((base) + (0x0B))
#define REG_H_CHG_TIMER2_ADDR(base) ((base) + (0x0C))
#define REG_H_CHG_TIMER3_ADDR(base) ((base) + (0x0D))
#define REG_H_LOAD_TIMER0_ADDR(base) ((base) + (0x0E))
#define REG_H_LOAD_TIMER1_ADDR(base) ((base) + (0x0F))
#define REG_H_LOAD_TIMER2_ADDR(base) ((base) + (0x10))
#define REG_H_LOAD_TIMER3_ADDR(base) ((base) + (0x11))
#define REG_H0_OFFSET_CURRENT_MOD_0_ADDR(base) ((base) + (0x12))
#define REG_H0_OFFSET_CURRENT_MOD_1_ADDR(base) ((base) + (0x13))
#define REG_H0_OFFSET_CURRENT_MOD_2_ADDR(base) ((base) + (0x14))
#define REG_H1_OFFSET_CURRENT_MOD_0_ADDR(base) ((base) + (0x15))
#define REG_H1_OFFSET_CURRENT_MOD_1_ADDR(base) ((base) + (0x16))
#define REG_H1_OFFSET_CURRENT_MOD_2_ADDR(base) ((base) + (0x17))
#define REG_H_OFFSET_VOLTAGE_MOD_0_ADDR(base) ((base) + (0x18))
#define REG_H_OFFSET_VOLTAGE_MOD_1_ADDR(base) ((base) + (0x19))
#define REG_H_OFFSET_VOLTAGE_MOD_2_ADDR(base) ((base) + (0x1A))
#define REG_H_CURRENT_0_ADDR(base) ((base) + (0x1B))
#define REG_H_CURRENT_1_ADDR(base) ((base) + (0x1C))
#define REG_H_CURRENT_2_ADDR(base) ((base) + (0x1D))
#define REG_H_V_OUT_0_ADDR(base) ((base) + (0x1E))
#define REG_H_V_OUT_1_ADDR(base) ((base) + (0x1F))
#define REG_H_V_OUT_2_ADDR(base) ((base) + (0x20))
#define REG_H0_OFFSET_CURRENT0_ADDR(base) ((base) + (0x21))
#define REG_H0_OFFSET_CURRENT1_ADDR(base) ((base) + (0x22))
#define REG_H0_OFFSET_CURRENT2_ADDR(base) ((base) + (0x23))
#define REG_H1_OFFSET_CURRENT0_ADDR(base) ((base) + (0x24))
#define REG_H1_OFFSET_CURRENT1_ADDR(base) ((base) + (0x25))
#define REG_H1_OFFSET_CURRENT2_ADDR(base) ((base) + (0x26))
#define REG_H_OFFSET_VOLTAGE0_ADDR(base) ((base) + (0x27))
#define REG_H_OFFSET_VOLTAGE1_ADDR(base) ((base) + (0x28))
#define REG_H_OFFSET_VOLTAGE2_ADDR(base) ((base) + (0x29))
#define REG_H_OCV_VOLTAGE0_ADDR(base) ((base) + (0x2A))
#define REG_H_OCV_VOLTAGE1_ADDR(base) ((base) + (0x2B))
#define REG_H_OCV_VOLTAGE2_ADDR(base) ((base) + (0x2C))
#define REG_H_OCV_CURRENT0_ADDR(base) ((base) + (0x2D))
#define REG_H_OCV_CURRENT1_ADDR(base) ((base) + (0x2E))
#define REG_H_OCV_CURRENT2_ADDR(base) ((base) + (0x2F))
#define REG_H_ECO_OUT_CLIN_0_ADDR(base) ((base) + (0x30))
#define REG_H_ECO_OUT_CLIN_1_ADDR(base) ((base) + (0x31))
#define REG_H_ECO_OUT_CLIN_2_ADDR(base) ((base) + (0x32))
#define REG_H_ECO_OUT_CLIN_3_ADDR(base) ((base) + (0x33))
#define REG_H_ECO_OUT_CLIN_4_ADDR(base) ((base) + (0x34))
#define REG_H_ECO_OUT_CLOUT_0_ADDR(base) ((base) + (0x35))
#define REG_H_ECO_OUT_CLOUT_1_ADDR(base) ((base) + (0x36))
#define REG_H_ECO_OUT_CLOUT_2_ADDR(base) ((base) + (0x37))
#define REG_H_ECO_OUT_CLOUT_3_ADDR(base) ((base) + (0x38))
#define REG_H_ECO_OUT_CLOUT_4_ADDR(base) ((base) + (0x39))
#define REG_H_V_PRE0_OUT0_ADDR(base) ((base) + (0x3A))
#define REG_H_V_PRE0_OUT1_ADDR(base) ((base) + (0x3B))
#define REG_H_V_PRE0_OUT2_ADDR(base) ((base) + (0x3C))
#define REG_H_V_PRE1_OUT0_ADDR(base) ((base) + (0x3D))
#define REG_H_V_PRE1_OUT1_ADDR(base) ((base) + (0x3E))
#define REG_H_V_PRE1_OUT2_ADDR(base) ((base) + (0x3F))
#define REG_H_V_PRE2_OUT0_ADDR(base) ((base) + (0x40))
#define REG_H_V_PRE2_OUT1_ADDR(base) ((base) + (0x41))
#define REG_H_V_PRE2_OUT2_ADDR(base) ((base) + (0x42))
#define REG_H_V_PRE3_OUT0_ADDR(base) ((base) + (0x43))
#define REG_H_V_PRE3_OUT1_ADDR(base) ((base) + (0x44))
#define REG_H_V_PRE3_OUT2_ADDR(base) ((base) + (0x45))
#define REG_H_V_PRE4_OUT0_ADDR(base) ((base) + (0x46))
#define REG_H_V_PRE4_OUT1_ADDR(base) ((base) + (0x47))
#define REG_H_V_PRE4_OUT2_ADDR(base) ((base) + (0x48))
#define REG_H_V_PRE5_OUT0_ADDR(base) ((base) + (0x49))
#define REG_H_V_PRE5_OUT1_ADDR(base) ((base) + (0x4A))
#define REG_H_V_PRE5_OUT2_ADDR(base) ((base) + (0x4B))
#define REG_H_V_PRE6_OUT0_ADDR(base) ((base) + (0x4C))
#define REG_H_V_PRE6_OUT1_ADDR(base) ((base) + (0x4D))
#define REG_H_V_PRE6_OUT2_ADDR(base) ((base) + (0x4E))
#define REG_H_V_PRE7_OUT0_ADDR(base) ((base) + (0x4F))
#define REG_H_V_PRE7_OUT1_ADDR(base) ((base) + (0x50))
#define REG_H_V_PRE7_OUT2_ADDR(base) ((base) + (0x51))
#define REG_H_CURRENT_PRE0_OUT0_ADDR(base) ((base) + (0x52))
#define REG_H_CURRENT_PRE0_OUT1_ADDR(base) ((base) + (0x53))
#define REG_H_CURRENT_PRE0_OUT2_ADDR(base) ((base) + (0x54))
#define REG_H_CURRENT_PRE1_OUT0_ADDR(base) ((base) + (0x55))
#define REG_H_CURRENT_PRE1_OUT1_ADDR(base) ((base) + (0x56))
#define REG_H_CURRENT_PRE1_OUT2_ADDR(base) ((base) + (0x57))
#define REG_H_CURRENT_PRE2_OUT0_ADDR(base) ((base) + (0x58))
#define REG_H_CURRENT_PRE2_OUT1_ADDR(base) ((base) + (0x59))
#define REG_H_CURRENT_PRE2_OUT2_ADDR(base) ((base) + (0x5A))
#define REG_H_CURRENT_PRE3_OUT0_ADDR(base) ((base) + (0x5B))
#define REG_H_CURRENT_PRE3_OUT1_ADDR(base) ((base) + (0x5C))
#define REG_H_CURRENT_PRE3_OUT2_ADDR(base) ((base) + (0x5D))
#define REG_H_CURRENT_PRE4_OUT0_ADDR(base) ((base) + (0x5E))
#define REG_H_CURRENT_PRE4_OUT1_ADDR(base) ((base) + (0x5F))
#define REG_H_CURRENT_PRE4_OUT2_ADDR(base) ((base) + (0x60))
#define REG_H_CURRENT_PRE5_OUT0_ADDR(base) ((base) + (0x61))
#define REG_H_CURRENT_PRE5_OUT1_ADDR(base) ((base) + (0x62))
#define REG_H_CURRENT_PRE5_OUT2_ADDR(base) ((base) + (0x63))
#define REG_H_CURRENT_PRE6_OUT0_ADDR(base) ((base) + (0x64))
#define REG_H_CURRENT_PRE6_OUT1_ADDR(base) ((base) + (0x65))
#define REG_H_CURRENT_PRE6_OUT2_ADDR(base) ((base) + (0x66))
#define REG_H_CURRENT_PRE7_OUT0_ADDR(base) ((base) + (0x67))
#define REG_H_CURRENT_PRE7_OUT1_ADDR(base) ((base) + (0x68))
#define REG_H_CURRENT_PRE7_OUT2_ADDR(base) ((base) + (0x69))
#define REG_H_V_OCV_PRE1_OUT0_ADDR(base) ((base) + (0x6A))
#define REG_H_V_OCV_PRE1_OUT1_ADDR(base) ((base) + (0x6B))
#define REG_H_V_OCV_PRE1_OUT2_ADDR(base) ((base) + (0x6C))
#define REG_H_V_OCV_PRE2_OUT0_ADDR(base) ((base) + (0x6D))
#define REG_H_V_OCV_PRE2_OUT1_ADDR(base) ((base) + (0x6E))
#define REG_H_V_OCV_PRE2_OUT2_ADDR(base) ((base) + (0x6F))
#define REG_H_V_OCV_PRE3_OUT0_ADDR(base) ((base) + (0x70))
#define REG_H_V_OCV_PRE3_OUT1_ADDR(base) ((base) + (0x71))
#define REG_H_V_OCV_PRE3_OUT2_ADDR(base) ((base) + (0x72))
#define REG_H_V_OCV_PRE4_OUT0_ADDR(base) ((base) + (0x73))
#define REG_H_V_OCV_PRE4_OUT1_ADDR(base) ((base) + (0x74))
#define REG_H_V_OCV_PRE4_OUT2_ADDR(base) ((base) + (0x75))
#define REG_H_I_OCV_PRE1_OUT0_ADDR(base) ((base) + (0x76))
#define REG_H_I_OCV_PRE1_OUT1_ADDR(base) ((base) + (0x77))
#define REG_H_I_OCV_PRE1_OUT2_ADDR(base) ((base) + (0x78))
#define REG_H_I_OCV_PRE2_OUT0_ADDR(base) ((base) + (0x79))
#define REG_H_I_OCV_PRE2_OUT1_ADDR(base) ((base) + (0x7A))
#define REG_H_I_OCV_PRE2_OUT2_ADDR(base) ((base) + (0x7B))
#define REG_H_I_OCV_PRE3_OUT0_ADDR(base) ((base) + (0x7C))
#define REG_H_I_OCV_PRE3_OUT1_ADDR(base) ((base) + (0x7D))
#define REG_H_I_OCV_PRE3_OUT2_ADDR(base) ((base) + (0x7E))
#define REG_H_I_OCV_PRE4_OUT0_ADDR(base) ((base) + (0x7F))
#define REG_H_I_OCV_PRE4_OUT1_ADDR(base) ((base) + (0x80))
#define REG_H_I_OCV_PRE4_OUT2_ADDR(base) ((base) + (0x81))
#define REG_L_CL_OUT0_ADDR(base) ((base) + (0x82))
#define REG_L_CL_OUT1_ADDR(base) ((base) + (0x83))
#define REG_L_CL_OUT2_ADDR(base) ((base) + (0x84))
#define REG_L_CL_OUT3_ADDR(base) ((base) + (0x85))
#define REG_L_CL_OUT4_ADDR(base) ((base) + (0x86))
#define REG_L_CL_IN0_ADDR(base) ((base) + (0x87))
#define REG_L_CL_IN1_ADDR(base) ((base) + (0x88))
#define REG_L_CL_IN2_ADDR(base) ((base) + (0x89))
#define REG_L_CL_IN3_ADDR(base) ((base) + (0x8A))
#define REG_L_CL_IN4_ADDR(base) ((base) + (0x8B))
#define REG_L_CHG_TIMER0_ADDR(base) ((base) + (0x8C))
#define REG_L_CHG_TIMER1_ADDR(base) ((base) + (0x8D))
#define REG_L_CHG_TIMER2_ADDR(base) ((base) + (0x8E))
#define REG_L_CHG_TIMER3_ADDR(base) ((base) + (0x8F))
#define REG_L_LOAD_TIMER0_ADDR(base) ((base) + (0x90))
#define REG_L_LOAD_TIMER1_ADDR(base) ((base) + (0x91))
#define REG_L_LOAD_TIMER2_ADDR(base) ((base) + (0x92))
#define REG_L_LOAD_TIMER3_ADDR(base) ((base) + (0x93))
#define REG_L_OFFSET_CURRENT_MOD_0_ADDR(base) ((base) + (0x94))
#define REG_L_OFFSET_CURRENT_MOD_1_ADDR(base) ((base) + (0x95))
#define REG_L_OFFSET_CURRENT_MOD_2_ADDR(base) ((base) + (0x96))
#define REG_L_OFFSET_VOLTAGE_MOD_0_ADDR(base) ((base) + (0x97))
#define REG_L_OFFSET_VOLTAGE_MOD_1_ADDR(base) ((base) + (0x98))
#define REG_L_OFFSET_VOLTAGE_MOD_2_ADDR(base) ((base) + (0x99))
#define REG_L_CURRENT_0_ADDR(base) ((base) + (0x9A))
#define REG_L_CURRENT_1_ADDR(base) ((base) + (0x9B))
#define REG_L_CURRENT_2_ADDR(base) ((base) + (0x9C))
#define REG_L_V_OUT_0_ADDR(base) ((base) + (0x9D))
#define REG_L_V_OUT_1_ADDR(base) ((base) + (0x9E))
#define REG_L_V_OUT_2_ADDR(base) ((base) + (0x9F))
#define REG_L_OFFSET_CURRENT0_ADDR(base) ((base) + (0xA0))
#define REG_L_OFFSET_CURRENT1_ADDR(base) ((base) + (0xA1))
#define REG_L_OFFSET_CURRENT2_ADDR(base) ((base) + (0xA2))
#define REG_L_OFFSET_VOLTAGE0_ADDR(base) ((base) + (0xA3))
#define REG_L_OFFSET_VOLTAGE1_ADDR(base) ((base) + (0xA4))
#define REG_L_OFFSET_VOLTAGE2_ADDR(base) ((base) + (0xA5))
#define REG_L_OCV_VOLTAGE0_ADDR(base) ((base) + (0xA6))
#define REG_L_OCV_VOLTAGE1_ADDR(base) ((base) + (0xA7))
#define REG_L_OCV_VOLTAGE2_ADDR(base) ((base) + (0xA8))
#define REG_L_OCV_CURRENT0_ADDR(base) ((base) + (0xA9))
#define REG_L_OCV_CURRENT1_ADDR(base) ((base) + (0xAA))
#define REG_L_OCV_CURRENT2_ADDR(base) ((base) + (0xAB))
#define REG_L_ECO_OUT_CLIN_0_ADDR(base) ((base) + (0xAC))
#define REG_L_ECO_OUT_CLIN_1_ADDR(base) ((base) + (0xAD))
#define REG_L_ECO_OUT_CLIN_2_ADDR(base) ((base) + (0xAE))
#define REG_L_ECO_OUT_CLIN_3_ADDR(base) ((base) + (0xAF))
#define REG_L_ECO_OUT_CLIN_4_ADDR(base) ((base) + (0xB0))
#define REG_L_ECO_OUT_CLOUT_0_ADDR(base) ((base) + (0xB1))
#define REG_L_ECO_OUT_CLOUT_1_ADDR(base) ((base) + (0xB2))
#define REG_L_ECO_OUT_CLOUT_2_ADDR(base) ((base) + (0xB3))
#define REG_L_ECO_OUT_CLOUT_3_ADDR(base) ((base) + (0xB4))
#define REG_L_ECO_OUT_CLOUT_4_ADDR(base) ((base) + (0xB5))
#define REG_L_V_PRE0_OUT0_ADDR(base) ((base) + (0xB6))
#define REG_L_V_PRE0_OUT1_ADDR(base) ((base) + (0xB7))
#define REG_L_V_PRE0_OUT2_ADDR(base) ((base) + (0xB8))
#define REG_L_V_PRE1_OUT0_ADDR(base) ((base) + (0xB9))
#define REG_L_V_PRE1_OUT1_ADDR(base) ((base) + (0xBA))
#define REG_L_V_PRE1_OUT2_ADDR(base) ((base) + (0xBB))
#define REG_L_V_PRE2_OUT0_ADDR(base) ((base) + (0xBC))
#define REG_L_V_PRE2_OUT1_ADDR(base) ((base) + (0xBD))
#define REG_L_V_PRE2_OUT2_ADDR(base) ((base) + (0xBE))
#define REG_L_V_PRE3_OUT0_ADDR(base) ((base) + (0xBF))
#define REG_L_V_PRE3_OUT1_ADDR(base) ((base) + (0xC0))
#define REG_L_V_PRE3_OUT2_ADDR(base) ((base) + (0xC1))
#define REG_L_V_PRE4_OUT0_ADDR(base) ((base) + (0xC2))
#define REG_L_V_PRE4_OUT1_ADDR(base) ((base) + (0xC3))
#define REG_L_V_PRE4_OUT2_ADDR(base) ((base) + (0xC4))
#define REG_L_V_PRE5_OUT0_ADDR(base) ((base) + (0xC5))
#define REG_L_V_PRE5_OUT1_ADDR(base) ((base) + (0xC6))
#define REG_L_V_PRE5_OUT2_ADDR(base) ((base) + (0xC7))
#define REG_L_V_PRE6_OUT0_ADDR(base) ((base) + (0xC8))
#define REG_L_V_PRE6_OUT1_ADDR(base) ((base) + (0xC9))
#define REG_L_V_PRE6_OUT2_ADDR(base) ((base) + (0xCA))
#define REG_L_V_PRE7_OUT0_ADDR(base) ((base) + (0xCB))
#define REG_L_V_PRE7_OUT1_ADDR(base) ((base) + (0xCC))
#define REG_L_V_PRE7_OUT2_ADDR(base) ((base) + (0xCD))
#define REG_L_CURRENT_PRE0_OUT0_ADDR(base) ((base) + (0xCE))
#define REG_L_CURRENT_PRE0_OUT1_ADDR(base) ((base) + (0xCF))
#define REG_L_CURRENT_PRE0_OUT2_ADDR(base) ((base) + (0xD0))
#define REG_L_CURRENT_PRE1_OUT0_ADDR(base) ((base) + (0xD1))
#define REG_L_CURRENT_PRE1_OUT1_ADDR(base) ((base) + (0xD2))
#define REG_L_CURRENT_PRE1_OUT2_ADDR(base) ((base) + (0xD3))
#define REG_L_CURRENT_PRE2_OUT0_ADDR(base) ((base) + (0xD4))
#define REG_L_CURRENT_PRE2_OUT1_ADDR(base) ((base) + (0xD5))
#define REG_L_CURRENT_PRE2_OUT2_ADDR(base) ((base) + (0xD6))
#define REG_L_CURRENT_PRE3_OUT0_ADDR(base) ((base) + (0xD7))
#define REG_L_CURRENT_PRE3_OUT1_ADDR(base) ((base) + (0xD8))
#define REG_L_CURRENT_PRE3_OUT2_ADDR(base) ((base) + (0xD9))
#define REG_L_CURRENT_PRE4_OUT0_ADDR(base) ((base) + (0xDA))
#define REG_L_CURRENT_PRE4_OUT1_ADDR(base) ((base) + (0xDB))
#define REG_L_CURRENT_PRE4_OUT2_ADDR(base) ((base) + (0xDC))
#define REG_L_CURRENT_PRE5_OUT0_ADDR(base) ((base) + (0xDD))
#define REG_L_CURRENT_PRE5_OUT1_ADDR(base) ((base) + (0xDE))
#define REG_L_CURRENT_PRE5_OUT2_ADDR(base) ((base) + (0xDF))
#define REG_L_CURRENT_PRE6_OUT0_ADDR(base) ((base) + (0xE0))
#define REG_L_CURRENT_PRE6_OUT1_ADDR(base) ((base) + (0xE1))
#define REG_L_CURRENT_PRE6_OUT2_ADDR(base) ((base) + (0xE2))
#define REG_L_CURRENT_PRE7_OUT0_ADDR(base) ((base) + (0xE3))
#define REG_L_CURRENT_PRE7_OUT1_ADDR(base) ((base) + (0xE4))
#define REG_L_CURRENT_PRE7_OUT2_ADDR(base) ((base) + (0xE5))
#define REG_L_V_OCV_PRE1_OUT0_ADDR(base) ((base) + (0xE6))
#define REG_L_V_OCV_PRE1_OUT1_ADDR(base) ((base) + (0xE7))
#define REG_L_V_OCV_PRE1_OUT2_ADDR(base) ((base) + (0xE8))
#define REG_L_V_OCV_PRE2_OUT0_ADDR(base) ((base) + (0xE9))
#define REG_L_V_OCV_PRE2_OUT1_ADDR(base) ((base) + (0xEA))
#define REG_L_V_OCV_PRE2_OUT2_ADDR(base) ((base) + (0xEB))
#define REG_L_V_OCV_PRE3_OUT0_ADDR(base) ((base) + (0xEC))
#define REG_L_V_OCV_PRE3_OUT1_ADDR(base) ((base) + (0xED))
#define REG_L_V_OCV_PRE3_OUT2_ADDR(base) ((base) + (0xEE))
#define REG_L_V_OCV_PRE4_OUT0_ADDR(base) ((base) + (0xEF))
#define REG_L_V_OCV_PRE4_OUT1_ADDR(base) ((base) + (0xF0))
#define REG_L_V_OCV_PRE4_OUT2_ADDR(base) ((base) + (0xF1))
#define REG_L_I_OCV_PRE1_OUT0_ADDR(base) ((base) + (0xF2))
#define REG_L_I_OCV_PRE1_OUT1_ADDR(base) ((base) + (0xF3))
#define REG_L_I_OCV_PRE1_OUT2_ADDR(base) ((base) + (0xF4))
#define REG_L_I_OCV_PRE2_OUT0_ADDR(base) ((base) + (0xF5))
#define REG_L_I_OCV_PRE2_OUT1_ADDR(base) ((base) + (0xF6))
#define REG_L_I_OCV_PRE2_OUT2_ADDR(base) ((base) + (0xF7))
#define REG_L_I_OCV_PRE3_OUT0_ADDR(base) ((base) + (0xF8))
#define REG_L_I_OCV_PRE3_OUT1_ADDR(base) ((base) + (0xF9))
#define REG_L_I_OCV_PRE3_OUT2_ADDR(base) ((base) + (0xFA))
#define REG_L_I_OCV_PRE4_OUT0_ADDR(base) ((base) + (0xFB))
#define REG_L_I_OCV_PRE4_OUT1_ADDR(base) ((base) + (0xFC))
#define REG_L_I_OCV_PRE4_OUT2_ADDR(base) ((base) + (0xFD))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_IRQ_FLAG_ADDR(base) ((base) + (0x00UL))
#define REG_IRQ_FLAG_RSV_ADDR(base) ((base) + (0x01UL))
#define REG_IRQ_FLAG_0_ADDR(base) ((base) + (0x02UL))
#define REG_IRQ_FLAG_1_ADDR(base) ((base) + (0x03UL))
#define REG_IRQ_FLAG_2_ADDR(base) ((base) + (0x04UL))
#define REG_IRQ_FLAG_3_ADDR(base) ((base) + (0x05UL))
#define REG_IRQ_FLAG_4_ADDR(base) ((base) + (0x06UL))
#define REG_IRQ_FLAG_5_ADDR(base) ((base) + (0x07UL))
#define REG_IRQ_FLAG_6_ADDR(base) ((base) + (0x08UL))
#define REG_IRQ_FLAG_7_ADDR(base) ((base) + (0x09UL))
#define REG_IRQ_FLAG_8_ADDR(base) ((base) + (0x0AUL))
#define REG_IRQ_FLAG_9_ADDR(base) ((base) + (0x0BUL))
#define REG_IRQ_FLAG_10_ADDR(base) ((base) + (0x0CUL))
#define REG_IRQ_FLAG_11_ADDR(base) ((base) + (0x0DUL))
#define REG_IRQ_FLAG_12_ADDR(base) ((base) + (0x0EUL))
#define REG_IRQ_FLAG_13_ADDR(base) ((base) + (0x0FUL))
#define REG_IRQ_MASK_ADDR(base) ((base) + (0x20UL))
#define REG_IRQ_MASK_RSV_ADDR(base) ((base) + (0x21UL))
#define REG_IRQ_MASK_0_ADDR(base) ((base) + (0x22UL))
#define REG_IRQ_MASK_1_ADDR(base) ((base) + (0x23UL))
#define REG_IRQ_MASK_2_ADDR(base) ((base) + (0x24UL))
#define REG_IRQ_MASK_3_ADDR(base) ((base) + (0x25UL))
#define REG_IRQ_MASK_4_ADDR(base) ((base) + (0x26UL))
#define REG_IRQ_MASK_5_ADDR(base) ((base) + (0x27UL))
#define REG_IRQ_MASK_6_ADDR(base) ((base) + (0x28UL))
#define REG_IRQ_MASK_7_ADDR(base) ((base) + (0x29UL))
#define REG_IRQ_MASK_8_ADDR(base) ((base) + (0x2AUL))
#define REG_IRQ_MASK_9_ADDR(base) ((base) + (0x2BUL))
#define REG_IRQ_MASK_10_ADDR(base) ((base) + (0x2CUL))
#define REG_IRQ_MASK_11_ADDR(base) ((base) + (0x2DUL))
#define REG_IRQ_MASK_12_ADDR(base) ((base) + (0x2EUL))
#define REG_IRQ_MASK_13_ADDR(base) ((base) + (0x2FUL))
#define REG_IRQ_STATUS_RSV_ADDR(base) ((base) + (0x40UL))
#define REG_IRQ_STATUS_0_ADDR(base) ((base) + (0x41UL))
#define REG_IRQ_STATUS_1_ADDR(base) ((base) + (0x42UL))
#define REG_IRQ_STATUS_2_ADDR(base) ((base) + (0x43UL))
#define REG_IRQ_STATUS_3_ADDR(base) ((base) + (0x44UL))
#define REG_IRQ_STATUS_4_ADDR(base) ((base) + (0x45UL))
#define REG_IRQ_STATUS_5_ADDR(base) ((base) + (0x46UL))
#define REG_IRQ_STATUS_6_ADDR(base) ((base) + (0x47UL))
#define REG_IRQ_STATUS_7_ADDR(base) ((base) + (0x48UL))
#define REG_IRQ_STATUS_8_ADDR(base) ((base) + (0x49UL))
#define REG_IRQ_STATUS_9_ADDR(base) ((base) + (0x4AUL))
#define REG_IRQ_STATUS_10_ADDR(base) ((base) + (0x4BUL))
#define REG_IRQ_STATUS_11_ADDR(base) ((base) + (0x4CUL))
#define REG_IRQ_STATUS_12_ADDR(base) ((base) + (0x4DUL))
#define REG_IRQ_STATUS_13_ADDR(base) ((base) + (0x4EUL))
#define REG_FAKE_IRQ_ADDR(base) ((base) + (0x60UL))
#define REG_IRQ_SEL_ADDR(base) ((base) + (0x61UL))
#else
#define REG_IRQ_FLAG_ADDR(base) ((base) + (0x00))
#define REG_IRQ_FLAG_RSV_ADDR(base) ((base) + (0x01))
#define REG_IRQ_FLAG_0_ADDR(base) ((base) + (0x02))
#define REG_IRQ_FLAG_1_ADDR(base) ((base) + (0x03))
#define REG_IRQ_FLAG_2_ADDR(base) ((base) + (0x04))
#define REG_IRQ_FLAG_3_ADDR(base) ((base) + (0x05))
#define REG_IRQ_FLAG_4_ADDR(base) ((base) + (0x06))
#define REG_IRQ_FLAG_5_ADDR(base) ((base) + (0x07))
#define REG_IRQ_FLAG_6_ADDR(base) ((base) + (0x08))
#define REG_IRQ_FLAG_7_ADDR(base) ((base) + (0x09))
#define REG_IRQ_FLAG_8_ADDR(base) ((base) + (0x0A))
#define REG_IRQ_FLAG_9_ADDR(base) ((base) + (0x0B))
#define REG_IRQ_FLAG_10_ADDR(base) ((base) + (0x0C))
#define REG_IRQ_FLAG_11_ADDR(base) ((base) + (0x0D))
#define REG_IRQ_FLAG_12_ADDR(base) ((base) + (0x0E))
#define REG_IRQ_FLAG_13_ADDR(base) ((base) + (0x0F))
#define REG_IRQ_MASK_ADDR(base) ((base) + (0x20))
#define REG_IRQ_MASK_RSV_ADDR(base) ((base) + (0x21))
#define REG_IRQ_MASK_0_ADDR(base) ((base) + (0x22))
#define REG_IRQ_MASK_1_ADDR(base) ((base) + (0x23))
#define REG_IRQ_MASK_2_ADDR(base) ((base) + (0x24))
#define REG_IRQ_MASK_3_ADDR(base) ((base) + (0x25))
#define REG_IRQ_MASK_4_ADDR(base) ((base) + (0x26))
#define REG_IRQ_MASK_5_ADDR(base) ((base) + (0x27))
#define REG_IRQ_MASK_6_ADDR(base) ((base) + (0x28))
#define REG_IRQ_MASK_7_ADDR(base) ((base) + (0x29))
#define REG_IRQ_MASK_8_ADDR(base) ((base) + (0x2A))
#define REG_IRQ_MASK_9_ADDR(base) ((base) + (0x2B))
#define REG_IRQ_MASK_10_ADDR(base) ((base) + (0x2C))
#define REG_IRQ_MASK_11_ADDR(base) ((base) + (0x2D))
#define REG_IRQ_MASK_12_ADDR(base) ((base) + (0x2E))
#define REG_IRQ_MASK_13_ADDR(base) ((base) + (0x2F))
#define REG_IRQ_STATUS_RSV_ADDR(base) ((base) + (0x40))
#define REG_IRQ_STATUS_0_ADDR(base) ((base) + (0x41))
#define REG_IRQ_STATUS_1_ADDR(base) ((base) + (0x42))
#define REG_IRQ_STATUS_2_ADDR(base) ((base) + (0x43))
#define REG_IRQ_STATUS_3_ADDR(base) ((base) + (0x44))
#define REG_IRQ_STATUS_4_ADDR(base) ((base) + (0x45))
#define REG_IRQ_STATUS_5_ADDR(base) ((base) + (0x46))
#define REG_IRQ_STATUS_6_ADDR(base) ((base) + (0x47))
#define REG_IRQ_STATUS_7_ADDR(base) ((base) + (0x48))
#define REG_IRQ_STATUS_8_ADDR(base) ((base) + (0x49))
#define REG_IRQ_STATUS_9_ADDR(base) ((base) + (0x4A))
#define REG_IRQ_STATUS_10_ADDR(base) ((base) + (0x4B))
#define REG_IRQ_STATUS_11_ADDR(base) ((base) + (0x4C))
#define REG_IRQ_STATUS_12_ADDR(base) ((base) + (0x4D))
#define REG_IRQ_STATUS_13_ADDR(base) ((base) + (0x4E))
#define REG_FAKE_IRQ_ADDR(base) ((base) + (0x60))
#define REG_IRQ_SEL_ADDR(base) ((base) + (0x61))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_CHARGER_BATFET_H_CTRL_ADDR(base) ((base) + (0x00UL))
#define REG_CHARGER_BATFET_L_CTRL_ADDR(base) ((base) + (0x01UL))
#define REG_SHIP_MODE_ENB_ADDR(base) ((base) + (0x02UL))
#define REG_AUTO_SHIP_MODE_ADDR(base) ((base) + (0x03UL))
#define REG_VBAT_LV_REG_ADDR(base) ((base) + (0x04UL))
#define REG_BAT_RES_MODE_ADDR(base) ((base) + (0x05UL))
#define REG_VDM_CFG_REG_0_ADDR(base) ((base) + (0x07UL))
#define REG_VDM_CFG_REG_1_ADDR(base) ((base) + (0x08UL))
#define REG_VDM_CFG_REG_2_ADDR(base) ((base) + (0x09UL))
#define REG_VDM_CFG_REG_3_ADDR(base) ((base) + (0x0AUL))
#define REG_VDM_CFG_REG_4_ADDR(base) ((base) + (0x0BUL))
#define REG_VDM_CFG_REG_5_ADDR(base) ((base) + (0x0CUL))
#define REG_VDM_CFG_RSV_0_ADDR(base) ((base) + (0x0DUL))
#define REG_VDM_CFG_RSV_1_ADDR(base) ((base) + (0x0EUL))
#define REG_VDM5_CFG_EN_ADDR(base) ((base) + (0x0FUL))
#define REG_BATFET_OCP_FLAG_ADDR(base) ((base) + (0x10UL))
#define REG_DA_BUCK_REVERSBST_MODE_ADDR(base) ((base) + (0x11UL))
#define REG_SC_BUCK_REVERSBST_CLEAR_ADDR(base) ((base) + (0x12UL))
#define REG_JTAG_CFG_REG_0_ADDR(base) ((base) + (0x13UL))
#define REG_COUL_CHANNEL_SEL_ADDR(base) ((base) + (0x14UL))
#define REG_IBAT_RES_SEL_ADDR(base) ((base) + (0x15UL))
#define REG_COUL_PD_TIME_ADDR(base) ((base) + (0x16UL))
#define REG_FCP_TOP_CFG_REG_ADDR(base) ((base) + (0x20UL))
#define REG_BOOST_CFG_REG_0_ADDR(base) ((base) + (0x30UL))
#define REG_BOOST_CFG_REG_1_ADDR(base) ((base) + (0x31UL))
#define REG_BOOST_CFG_REG_2_ADDR(base) ((base) + (0x32UL))
#define REG_BOOST_CFG_REG_3_ADDR(base) ((base) + (0x33UL))
#define REG_BOOST_CFG_REG_4_ADDR(base) ((base) + (0x34UL))
#define REG_BOOST_CFG_REG_5_ADDR(base) ((base) + (0x35UL))
#define REG_BOOST_CFG_REG_6_ADDR(base) ((base) + (0x36UL))
#define REG_BOOST_CFG_REG_7_ADDR(base) ((base) + (0x37UL))
#define REG_BOOST_CFG_REG_8_ADDR(base) ((base) + (0x38UL))
#define REG_BOOST_CFG_REG_9_ADDR(base) ((base) + (0x39UL))
#define REG_BOOST_CFG_REG_10_ADDR(base) ((base) + (0x3AUL))
#define REG_BOOST_RO_REG_11_ADDR(base) ((base) + (0x3BUL))
#define REG_CHARGER_RO_REG_0_ADDR(base) ((base) + (0x3FUL))
#define REG_CHARGER_RO_REG_1_ADDR(base) ((base) + (0x40UL))
#define REG_CHARGER_CFG_REG_0_ADDR(base) ((base) + (0x41UL))
#define REG_CHARGER_CFG_REG_1_ADDR(base) ((base) + (0x42UL))
#define REG_BUCK_ILIMIT_ADDR(base) ((base) + (0x43UL))
#define REG_CHARGER_CFG_REG_2_ADDR(base) ((base) + (0x44UL))
#define REG_CHARGER_CFG_REG_3_ADDR(base) ((base) + (0x45UL))
#define REG_CHARGER_CFG_REG_4_ADDR(base) ((base) + (0x46UL))
#define REG_CHARGER_CFG_REG_5_ADDR(base) ((base) + (0x47UL))
#define REG_CHARGER_CFG_REG_6_ADDR(base) ((base) + (0x48UL))
#define REG_CHARGER_CFG_REG_7_ADDR(base) ((base) + (0x49UL))
#define REG_CHARGER_CFG_REG_8_ADDR(base) ((base) + (0x4AUL))
#define REG_CHARGER_CFG_REG_9_ADDR(base) ((base) + (0x4BUL))
#define REG_CHARGER_CFG_REG_10_ADDR(base) ((base) + (0x4CUL))
#define REG_CHARGER_CFG_REG_11_ADDR(base) ((base) + (0x4DUL))
#define REG_CHARGER_CFG_REG_12_ADDR(base) ((base) + (0x4EUL))
#define REG_CHARGER_CFG_REG_13_ADDR(base) ((base) + (0x4FUL))
#define REG_CHARGER_CFG_REG_14_ADDR(base) ((base) + (0x50UL))
#define REG_BUCK_OTG_TOP_CFG_REG_0_ADDR(base) ((base) + (0x56UL))
#define REG_BUCK_OTG_TOP_CFG_REG_1_ADDR(base) ((base) + (0x57UL))
#define REG_BUCK_OTG_TOP_CFG_REG_2_ADDR(base) ((base) + (0x58UL))
#define REG_BUCK_OTG_TOP_CFG_REG_3_ADDR(base) ((base) + (0x59UL))
#define REG_BUCK_OTG_TOP_CFG_REG_4_ADDR(base) ((base) + (0x5AUL))
#define REG_BUCK_OTG_TOP_CFG_REG_5_ADDR(base) ((base) + (0x5BUL))
#define REG_BUCK_OTG_TOP_CFG_REG_6_ADDR(base) ((base) + (0x5CUL))
#define REG_BUCK_OTG_TOP_CFG_REG_7_ADDR(base) ((base) + (0x5DUL))
#define REG_BUCK_OTG_TOP_CFG_REG_8_ADDR(base) ((base) + (0x5EUL))
#define REG_BUCK_OTG_TOP_CFG_REG_9_ADDR(base) ((base) + (0x5FUL))
#define REG_BUCK_OTG_TOP_CFG_REG_10_ADDR(base) ((base) + (0x60UL))
#define REG_BUCK_OTG_TOP_CFG_REG_11_ADDR(base) ((base) + (0x61UL))
#define REG_BUCK_OTG_TOP_CFG_REG_12_ADDR(base) ((base) + (0x62UL))
#define REG_BUCK_OTG_TOP_CFG_REG_13_ADDR(base) ((base) + (0x63UL))
#define REG_BUCK_OTG_TOP_CFG_REG_14_ADDR(base) ((base) + (0x64UL))
#define REG_BUCK_OTG_TOP_CFG_REG_15_ADDR(base) ((base) + (0x65UL))
#define REG_BUCK_OTG_TOP_CFG_REG_16_ADDR(base) ((base) + (0x66UL))
#define REG_BUCK_OTG_TOP_CFG_REG_17_ADDR(base) ((base) + (0x67UL))
#define REG_BUCK_OTG_TOP_CFG_REG_18_ADDR(base) ((base) + (0x68UL))
#define REG_BUCK_OTG_TOP_CFG_REG_19_ADDR(base) ((base) + (0x69UL))
#define REG_BUCK_OTG_TOP_CFG_REG_20_ADDR(base) ((base) + (0x6AUL))
#define REG_BUCK_OTG_TOP_CFG_REG_21_ADDR(base) ((base) + (0x6BUL))
#define REG_BUCK_OTG_TOP_CFG_REG_22_ADDR(base) ((base) + (0x6CUL))
#define REG_BUCK_OTG_TOP_CFG_REG_31_ADDR(base) ((base) + (0x6DUL))
#define REG_BUCK_OTG_TOP_CFG_REG_32_ADDR(base) ((base) + (0x6EUL))
#define REG_BUCK_OTG_TOP_CFG_REG_33_ADDR(base) ((base) + (0x6FUL))
#define REG_BUCK_OTG_TOP_CFG_REG_34_ADDR(base) ((base) + (0x70UL))
#define REG_BUCK_OTG_TOP_CFG_REG_35_ADDR(base) ((base) + (0x71UL))
#define REG_BUCK_OTG_TOP_CFG_REG_36_ADDR(base) ((base) + (0x72UL))
#define REG_BUCK_OTG_TOP_CFG_REG_37_ADDR(base) ((base) + (0x73UL))
#define REG_BUCK_OTG_TOP_CFG_REG_38_ADDR(base) ((base) + (0x74UL))
#define REG_BUCK_OTG_TOP_CFG_REG_39_ADDR(base) ((base) + (0x75UL))
#define REG_BUCK_OTG_TOP_CFG_REG_40_ADDR(base) ((base) + (0x76UL))
#define REG_BUCK_OTG_TOP_CFG_REG_41_ADDR(base) ((base) + (0x77UL))
#define REG_BUCK_OTG_TOP_CFG_REG_42_ADDR(base) ((base) + (0x78UL))
#define REG_BUCK_OTG_TOP_RO_REG_43_ADDR(base) ((base) + (0x79UL))
#define REG_BUCK_OTG_TOP_RO_REG_44_ADDR(base) ((base) + (0x7AUL))
#define REG_BUCK_OTG_TOP_RO_REG_45_ADDR(base) ((base) + (0x7BUL))
#define REG_BUCK_OTG_TOP_RO_REG_46_ADDR(base) ((base) + (0x7CUL))
#define REG_BUCK_OTG_TOP_RO_REG_47_ADDR(base) ((base) + (0x7DUL))
#define REG_BUCK_OTG_TOP_RO_REG_48_ADDR(base) ((base) + (0x7EUL))
#define REG_USB_OVP_CFG_REG_0_ADDR(base) ((base) + (0x90UL))
#define REG_USB_OVP_CFG_REG_1_ADDR(base) ((base) + (0x91UL))
#define REG_USB_OVP_CFG_REG_2_ADDR(base) ((base) + (0x92UL))
#define REG_USB_OVP_CFG_REG_3_ADDR(base) ((base) + (0x93UL))
#define REG_USB_OVP_CFG_REG_4_ADDR(base) ((base) + (0x94UL))
#define REG_PSW_OVP_CFG_REG_0_ADDR(base) ((base) + (0x97UL))
#define REG_PSW_OVP_CFG_REG_1_ADDR(base) ((base) + (0x98UL))
#define REG_PSW_OVP_CFG_REG_2_ADDR(base) ((base) + (0x99UL))
#define REG_SC_TOP_CFG_REG_0_ADDR(base) ((base) + (0x9CUL))
#define REG_SC_TOP_CFG_REG_1_ADDR(base) ((base) + (0x9DUL))
#define REG_SC_TOP_CFG_REG_2_ADDR(base) ((base) + (0x9EUL))
#define REG_SC_TOP_CFG_REG_3_ADDR(base) ((base) + (0x9FUL))
#define REG_SC_TOP_CFG_REG_4_ADDR(base) ((base) + (0xA0UL))
#define REG_SC_TOP_CFG_REG_5_ADDR(base) ((base) + (0xA1UL))
#define REG_SC_TOP_CFG_REG_6_ADDR(base) ((base) + (0xA2UL))
#define REG_SC_TOP_CFG_REG_7_ADDR(base) ((base) + (0xA3UL))
#define REG_SC_TOP_CFG_REG_8_ADDR(base) ((base) + (0xA4UL))
#define REG_SC_TOP_CFG_REG_9_ADDR(base) ((base) + (0xA5UL))
#define REG_SC_TOP_CFG_REG_10_ADDR(base) ((base) + (0xA6UL))
#define REG_SC_TOP_CFG_REG_11_ADDR(base) ((base) + (0xA7UL))
#define REG_SC_TOP_CFG_REG_12_ADDR(base) ((base) + (0xA8UL))
#define REG_SC_TOP_CFG_REG_13_ADDR(base) ((base) + (0xA9UL))
#define REG_SC_TOP_CFG_REG_14_ADDR(base) ((base) + (0xAAUL))
#define REG_SC_TOP_CFG_REG_15_ADDR(base) ((base) + (0xABUL))
#define REG_SC_TOP_CFG_REG_16_ADDR(base) ((base) + (0xACUL))
#define REG_SC_TOP_CFG_REG_17_ADDR(base) ((base) + (0xADUL))
#define REG_SC_TOP_CFG_REG_18_ADDR(base) ((base) + (0xAEUL))
#define REG_PSEL_CFG_REG_0_ADDR(base) ((base) + (0xB0UL))
#define REG_PSEL_CFG_REG_1_ADDR(base) ((base) + (0xB1UL))
#define REG_PSEL_CFG_REG_2_ADDR(base) ((base) + (0xB2UL))
#define REG_PSEL_CFG_REG_3_ADDR(base) ((base) + (0xB3UL))
#define REG_PSEL_RO_REG_4_ADDR(base) ((base) + (0xB4UL))
#define REG_HKADC_CFG_REG_1_ADDR(base) ((base) + (0xB5UL))
#define REG_HKADC_CFG_REG_2_ADDR(base) ((base) + (0xB6UL))
#define REG_HKADC_CFG_REG_3_ADDR(base) ((base) + (0xB7UL))
#define REG_SYS_DET_CFG_REG_0_ADDR(base) ((base) + (0xB9UL))
#define REG_SYS_DET_CFG_REG_1_ADDR(base) ((base) + (0xBAUL))
#define REG_SYS_DET_CFG_REG_2_ADDR(base) ((base) + (0xBBUL))
#define REG_SYS_DET_CFG_REG_3_ADDR(base) ((base) + (0xBCUL))
#define REG_SYS_DET_CFG_REG_4_ADDR(base) ((base) + (0xBDUL))
#define REG_SYS_DET_CFG_REG_5_ADDR(base) ((base) + (0xBEUL))
#define REG_SYS_DET_CFG_REG_6_ADDR(base) ((base) + (0xBFUL))
#define REG_SYS_DET_CFG_REG_7_ADDR(base) ((base) + (0xC0UL))
#define REG_SYS_DET_RO_REG_8_ADDR(base) ((base) + (0xC1UL))
#define REG_SYS_LOGIC_CFG_REG_0_ADDR(base) ((base) + (0xC2UL))
#define REG_SYS_LOGIC_CFG_REG_2_ADDR(base) ((base) + (0xC3UL))
#define REG_SYS_LOGIC_CFG_REG_3_ADDR(base) ((base) + (0xC4UL))
#define REG_SYS_LOGIC_CFG_REG_4_ADDR(base) ((base) + (0xC5UL))
#define REG_SYS_LOGIC_CFG_REG_5_ADDR(base) ((base) + (0xC6UL))
#define REG_SYS_LOGIC_CFG_REG_6_ADDR(base) ((base) + (0xC7UL))
#define REG_SYS_LOGIC_CFG_REG_7_ADDR(base) ((base) + (0xC8UL))
#define REG_SYS_LOGIC_CFG_REG_8_ADDR(base) ((base) + (0xC9UL))
#define REG_SYS_LOGIC_CFG_REG_9_ADDR(base) ((base) + (0xCAUL))
#define REG_SYS_LOGIC_CFG_REG_10_ADDR(base) ((base) + (0xCBUL))
#define REG_SYS_LOGIC_CFG_REG_11_ADDR(base) ((base) + (0xCCUL))
#define REG_SYS_LOGIC_RO_REG_12_ADDR(base) ((base) + (0xCDUL))
#define REG_SYS_LOGIC_RO_REG_13_ADDR(base) ((base) + (0xCEUL))
#define REG_SYS_LOGIC_RO_REG_14_ADDR(base) ((base) + (0xCFUL))
#define REG_TCPC_CFG_REG_0_ADDR(base) ((base) + (0xD4UL))
#define REG_TCPC_CFG_REG_1_ADDR(base) ((base) + (0xD5UL))
#define REG_TCPC_CFG_REG_2_ADDR(base) ((base) + (0xD6UL))
#define REG_TCPC_CFG_REG_3_ADDR(base) ((base) + (0xD7UL))
#define REG_TYPE_CFG_REG_4_ADDR(base) ((base) + (0xD8UL))
#define REG_TCPC_RO_REG_1_ADDR(base) ((base) + (0xD9UL))
#define REG_SC_PRO_CFG_REG_0_ADDR(base) ((base) + (0xDAUL))
#define REG_SC_PRO_CFG_REG_1_ADDR(base) ((base) + (0xDBUL))
#define REG_SC_PRO_CFG_REG_2_ADDR(base) ((base) + (0xDCUL))
#define REG_SC_PRO_CFG_REG_3_ADDR(base) ((base) + (0xDDUL))
#define REG_SC_PRO_CFG_REG_4_ADDR(base) ((base) + (0xDEUL))
#define REG_SC_PRO_CFG_REG_5_ADDR(base) ((base) + (0xDFUL))
#define REG_SC_PRO_CFG_REG_6_ADDR(base) ((base) + (0xE0UL))
#define REG_SC_PRO_CFG_REG_7_ADDR(base) ((base) + (0xE1UL))
#define REG_SC_PRO_CFG_REG_8_ADDR(base) ((base) + (0xE2UL))
#define REG_SC_PRO_CFG_REG_9_ADDR(base) ((base) + (0xE3UL))
#define REG_SC_PRO_CFG_REG_10_ADDR(base) ((base) + (0xE4UL))
#define REG_SC_PRO_CFG_REG_11_ADDR(base) ((base) + (0xE5UL))
#define REG_SC_PRO_CFG_REG_12_ADDR(base) ((base) + (0xE6UL))
#define REG_SC_PRO_CFG_REG_13_ADDR(base) ((base) + (0xE7UL))
#define REG_SC_PRO_CFG_REG_14_ADDR(base) ((base) + (0xE8UL))
#define REG_SC_PRO_CFG_REG_15_ADDR(base) ((base) + (0xE9UL))
#define REG_SC_PRO_CFG_REG_16_ADDR(base) ((base) + (0xEAUL))
#define REG_SC_PRO_CFG_REG_17_ADDR(base) ((base) + (0xEBUL))
#define REG_REF_TOP_CFG_REG_0_ADDR(base) ((base) + (0xF0UL))
#define REG_REF_TOP_CFG_REG_1_ADDR(base) ((base) + (0xF1UL))
#define REG_REF_TOP_CFG_REG_2_ADDR(base) ((base) + (0xF2UL))
#define REG_REF_TOP_CFG_REG_3_ADDR(base) ((base) + (0xF3UL))
#define REG_REF_TOP_CFG_REG_4_ADDR(base) ((base) + (0xF4UL))
#define REG_REF_TOP_CFG_REG_5_ADDR(base) ((base) + (0xF5UL))
#define REG_OSC_TOP_CFG_REG_0_ADDR(base) ((base) + (0xF6UL))
#define REG_OSC_TOP_CFG_REG_1_ADDR(base) ((base) + (0xF7UL))
#define REG_OSC_TOP_CFG_REG_2_ADDR(base) ((base) + (0xF8UL))
#define REG_AD_STATUS_RSV0_ADDR(base) ((base) + (0xFAUL))
#define REG_AD_STATUS_RSV1_ADDR(base) ((base) + (0xFBUL))
#define REG_AD_STATUS_RSV2_ADDR(base) ((base) + (0xFCUL))
#define REG_AD_STATUS_RSV3_ADDR(base) ((base) + (0xFDUL))
#else
#define REG_CHARGER_BATFET_H_CTRL_ADDR(base) ((base) + (0x00))
#define REG_CHARGER_BATFET_L_CTRL_ADDR(base) ((base) + (0x01))
#define REG_SHIP_MODE_ENB_ADDR(base) ((base) + (0x02))
#define REG_AUTO_SHIP_MODE_ADDR(base) ((base) + (0x03))
#define REG_VBAT_LV_REG_ADDR(base) ((base) + (0x04))
#define REG_BAT_RES_MODE_ADDR(base) ((base) + (0x05))
#define REG_VDM_CFG_REG_0_ADDR(base) ((base) + (0x07))
#define REG_VDM_CFG_REG_1_ADDR(base) ((base) + (0x08))
#define REG_VDM_CFG_REG_2_ADDR(base) ((base) + (0x09))
#define REG_VDM_CFG_REG_3_ADDR(base) ((base) + (0x0A))
#define REG_VDM_CFG_REG_4_ADDR(base) ((base) + (0x0B))
#define REG_VDM_CFG_REG_5_ADDR(base) ((base) + (0x0C))
#define REG_VDM_CFG_RSV_0_ADDR(base) ((base) + (0x0D))
#define REG_VDM_CFG_RSV_1_ADDR(base) ((base) + (0x0E))
#define REG_VDM5_CFG_EN_ADDR(base) ((base) + (0x0F))
#define REG_BATFET_OCP_FLAG_ADDR(base) ((base) + (0x10))
#define REG_DA_BUCK_REVERSBST_MODE_ADDR(base) ((base) + (0x11))
#define REG_SC_BUCK_REVERSBST_CLEAR_ADDR(base) ((base) + (0x12))
#define REG_JTAG_CFG_REG_0_ADDR(base) ((base) + (0x13))
#define REG_COUL_CHANNEL_SEL_ADDR(base) ((base) + (0x14))
#define REG_IBAT_RES_SEL_ADDR(base) ((base) + (0x15))
#define REG_COUL_PD_TIME_ADDR(base) ((base) + (0x16))
#define REG_FCP_TOP_CFG_REG_ADDR(base) ((base) + (0x20))
#define REG_BOOST_CFG_REG_0_ADDR(base) ((base) + (0x30))
#define REG_BOOST_CFG_REG_1_ADDR(base) ((base) + (0x31))
#define REG_BOOST_CFG_REG_2_ADDR(base) ((base) + (0x32))
#define REG_BOOST_CFG_REG_3_ADDR(base) ((base) + (0x33))
#define REG_BOOST_CFG_REG_4_ADDR(base) ((base) + (0x34))
#define REG_BOOST_CFG_REG_5_ADDR(base) ((base) + (0x35))
#define REG_BOOST_CFG_REG_6_ADDR(base) ((base) + (0x36))
#define REG_BOOST_CFG_REG_7_ADDR(base) ((base) + (0x37))
#define REG_BOOST_CFG_REG_8_ADDR(base) ((base) + (0x38))
#define REG_BOOST_CFG_REG_9_ADDR(base) ((base) + (0x39))
#define REG_BOOST_CFG_REG_10_ADDR(base) ((base) + (0x3A))
#define REG_BOOST_RO_REG_11_ADDR(base) ((base) + (0x3B))
#define REG_CHARGER_RO_REG_0_ADDR(base) ((base) + (0x3F))
#define REG_CHARGER_RO_REG_1_ADDR(base) ((base) + (0x40))
#define REG_CHARGER_CFG_REG_0_ADDR(base) ((base) + (0x41))
#define REG_CHARGER_CFG_REG_1_ADDR(base) ((base) + (0x42))
#define REG_BUCK_ILIMIT_ADDR(base) ((base) + (0x43))
#define REG_CHARGER_CFG_REG_2_ADDR(base) ((base) + (0x44))
#define REG_CHARGER_CFG_REG_3_ADDR(base) ((base) + (0x45))
#define REG_CHARGER_CFG_REG_4_ADDR(base) ((base) + (0x46))
#define REG_CHARGER_CFG_REG_5_ADDR(base) ((base) + (0x47))
#define REG_CHARGER_CFG_REG_6_ADDR(base) ((base) + (0x48))
#define REG_CHARGER_CFG_REG_7_ADDR(base) ((base) + (0x49))
#define REG_CHARGER_CFG_REG_8_ADDR(base) ((base) + (0x4A))
#define REG_CHARGER_CFG_REG_9_ADDR(base) ((base) + (0x4B))
#define REG_CHARGER_CFG_REG_10_ADDR(base) ((base) + (0x4C))
#define REG_CHARGER_CFG_REG_11_ADDR(base) ((base) + (0x4D))
#define REG_CHARGER_CFG_REG_12_ADDR(base) ((base) + (0x4E))
#define REG_CHARGER_CFG_REG_13_ADDR(base) ((base) + (0x4F))
#define REG_CHARGER_CFG_REG_14_ADDR(base) ((base) + (0x50))
#define REG_BUCK_OTG_TOP_CFG_REG_0_ADDR(base) ((base) + (0x56))
#define REG_BUCK_OTG_TOP_CFG_REG_1_ADDR(base) ((base) + (0x57))
#define REG_BUCK_OTG_TOP_CFG_REG_2_ADDR(base) ((base) + (0x58))
#define REG_BUCK_OTG_TOP_CFG_REG_3_ADDR(base) ((base) + (0x59))
#define REG_BUCK_OTG_TOP_CFG_REG_4_ADDR(base) ((base) + (0x5A))
#define REG_BUCK_OTG_TOP_CFG_REG_5_ADDR(base) ((base) + (0x5B))
#define REG_BUCK_OTG_TOP_CFG_REG_6_ADDR(base) ((base) + (0x5C))
#define REG_BUCK_OTG_TOP_CFG_REG_7_ADDR(base) ((base) + (0x5D))
#define REG_BUCK_OTG_TOP_CFG_REG_8_ADDR(base) ((base) + (0x5E))
#define REG_BUCK_OTG_TOP_CFG_REG_9_ADDR(base) ((base) + (0x5F))
#define REG_BUCK_OTG_TOP_CFG_REG_10_ADDR(base) ((base) + (0x60))
#define REG_BUCK_OTG_TOP_CFG_REG_11_ADDR(base) ((base) + (0x61))
#define REG_BUCK_OTG_TOP_CFG_REG_12_ADDR(base) ((base) + (0x62))
#define REG_BUCK_OTG_TOP_CFG_REG_13_ADDR(base) ((base) + (0x63))
#define REG_BUCK_OTG_TOP_CFG_REG_14_ADDR(base) ((base) + (0x64))
#define REG_BUCK_OTG_TOP_CFG_REG_15_ADDR(base) ((base) + (0x65))
#define REG_BUCK_OTG_TOP_CFG_REG_16_ADDR(base) ((base) + (0x66))
#define REG_BUCK_OTG_TOP_CFG_REG_17_ADDR(base) ((base) + (0x67))
#define REG_BUCK_OTG_TOP_CFG_REG_18_ADDR(base) ((base) + (0x68))
#define REG_BUCK_OTG_TOP_CFG_REG_19_ADDR(base) ((base) + (0x69))
#define REG_BUCK_OTG_TOP_CFG_REG_20_ADDR(base) ((base) + (0x6A))
#define REG_BUCK_OTG_TOP_CFG_REG_21_ADDR(base) ((base) + (0x6B))
#define REG_BUCK_OTG_TOP_CFG_REG_22_ADDR(base) ((base) + (0x6C))
#define REG_BUCK_OTG_TOP_CFG_REG_31_ADDR(base) ((base) + (0x6D))
#define REG_BUCK_OTG_TOP_CFG_REG_32_ADDR(base) ((base) + (0x6E))
#define REG_BUCK_OTG_TOP_CFG_REG_33_ADDR(base) ((base) + (0x6F))
#define REG_BUCK_OTG_TOP_CFG_REG_34_ADDR(base) ((base) + (0x70))
#define REG_BUCK_OTG_TOP_CFG_REG_35_ADDR(base) ((base) + (0x71))
#define REG_BUCK_OTG_TOP_CFG_REG_36_ADDR(base) ((base) + (0x72))
#define REG_BUCK_OTG_TOP_CFG_REG_37_ADDR(base) ((base) + (0x73))
#define REG_BUCK_OTG_TOP_CFG_REG_38_ADDR(base) ((base) + (0x74))
#define REG_BUCK_OTG_TOP_CFG_REG_39_ADDR(base) ((base) + (0x75))
#define REG_BUCK_OTG_TOP_CFG_REG_40_ADDR(base) ((base) + (0x76))
#define REG_BUCK_OTG_TOP_CFG_REG_41_ADDR(base) ((base) + (0x77))
#define REG_BUCK_OTG_TOP_CFG_REG_42_ADDR(base) ((base) + (0x78))
#define REG_BUCK_OTG_TOP_RO_REG_43_ADDR(base) ((base) + (0x79))
#define REG_BUCK_OTG_TOP_RO_REG_44_ADDR(base) ((base) + (0x7A))
#define REG_BUCK_OTG_TOP_RO_REG_45_ADDR(base) ((base) + (0x7B))
#define REG_BUCK_OTG_TOP_RO_REG_46_ADDR(base) ((base) + (0x7C))
#define REG_BUCK_OTG_TOP_RO_REG_47_ADDR(base) ((base) + (0x7D))
#define REG_BUCK_OTG_TOP_RO_REG_48_ADDR(base) ((base) + (0x7E))
#define REG_USB_OVP_CFG_REG_0_ADDR(base) ((base) + (0x90))
#define REG_USB_OVP_CFG_REG_1_ADDR(base) ((base) + (0x91))
#define REG_USB_OVP_CFG_REG_2_ADDR(base) ((base) + (0x92))
#define REG_USB_OVP_CFG_REG_3_ADDR(base) ((base) + (0x93))
#define REG_USB_OVP_CFG_REG_4_ADDR(base) ((base) + (0x94))
#define REG_PSW_OVP_CFG_REG_0_ADDR(base) ((base) + (0x97))
#define REG_PSW_OVP_CFG_REG_1_ADDR(base) ((base) + (0x98))
#define REG_PSW_OVP_CFG_REG_2_ADDR(base) ((base) + (0x99))
#define REG_SC_TOP_CFG_REG_0_ADDR(base) ((base) + (0x9C))
#define REG_SC_TOP_CFG_REG_1_ADDR(base) ((base) + (0x9D))
#define REG_SC_TOP_CFG_REG_2_ADDR(base) ((base) + (0x9E))
#define REG_SC_TOP_CFG_REG_3_ADDR(base) ((base) + (0x9F))
#define REG_SC_TOP_CFG_REG_4_ADDR(base) ((base) + (0xA0))
#define REG_SC_TOP_CFG_REG_5_ADDR(base) ((base) + (0xA1))
#define REG_SC_TOP_CFG_REG_6_ADDR(base) ((base) + (0xA2))
#define REG_SC_TOP_CFG_REG_7_ADDR(base) ((base) + (0xA3))
#define REG_SC_TOP_CFG_REG_8_ADDR(base) ((base) + (0xA4))
#define REG_SC_TOP_CFG_REG_9_ADDR(base) ((base) + (0xA5))
#define REG_SC_TOP_CFG_REG_10_ADDR(base) ((base) + (0xA6))
#define REG_SC_TOP_CFG_REG_11_ADDR(base) ((base) + (0xA7))
#define REG_SC_TOP_CFG_REG_12_ADDR(base) ((base) + (0xA8))
#define REG_SC_TOP_CFG_REG_13_ADDR(base) ((base) + (0xA9))
#define REG_SC_TOP_CFG_REG_14_ADDR(base) ((base) + (0xAA))
#define REG_SC_TOP_CFG_REG_15_ADDR(base) ((base) + (0xAB))
#define REG_SC_TOP_CFG_REG_16_ADDR(base) ((base) + (0xAC))
#define REG_SC_TOP_CFG_REG_17_ADDR(base) ((base) + (0xAD))
#define REG_SC_TOP_CFG_REG_18_ADDR(base) ((base) + (0xAE))
#define REG_PSEL_CFG_REG_0_ADDR(base) ((base) + (0xB0))
#define REG_PSEL_CFG_REG_1_ADDR(base) ((base) + (0xB1))
#define REG_PSEL_CFG_REG_2_ADDR(base) ((base) + (0xB2))
#define REG_PSEL_CFG_REG_3_ADDR(base) ((base) + (0xB3))
#define REG_PSEL_RO_REG_4_ADDR(base) ((base) + (0xB4))
#define REG_HKADC_CFG_REG_1_ADDR(base) ((base) + (0xB5))
#define REG_HKADC_CFG_REG_2_ADDR(base) ((base) + (0xB6))
#define REG_HKADC_CFG_REG_3_ADDR(base) ((base) + (0xB7))
#define REG_SYS_DET_CFG_REG_0_ADDR(base) ((base) + (0xB9))
#define REG_SYS_DET_CFG_REG_1_ADDR(base) ((base) + (0xBA))
#define REG_SYS_DET_CFG_REG_2_ADDR(base) ((base) + (0xBB))
#define REG_SYS_DET_CFG_REG_3_ADDR(base) ((base) + (0xBC))
#define REG_SYS_DET_CFG_REG_4_ADDR(base) ((base) + (0xBD))
#define REG_SYS_DET_CFG_REG_5_ADDR(base) ((base) + (0xBE))
#define REG_SYS_DET_CFG_REG_6_ADDR(base) ((base) + (0xBF))
#define REG_SYS_DET_CFG_REG_7_ADDR(base) ((base) + (0xC0))
#define REG_SYS_DET_RO_REG_8_ADDR(base) ((base) + (0xC1))
#define REG_SYS_LOGIC_CFG_REG_0_ADDR(base) ((base) + (0xC2))
#define REG_SYS_LOGIC_CFG_REG_2_ADDR(base) ((base) + (0xC3))
#define REG_SYS_LOGIC_CFG_REG_3_ADDR(base) ((base) + (0xC4))
#define REG_SYS_LOGIC_CFG_REG_4_ADDR(base) ((base) + (0xC5))
#define REG_SYS_LOGIC_CFG_REG_5_ADDR(base) ((base) + (0xC6))
#define REG_SYS_LOGIC_CFG_REG_6_ADDR(base) ((base) + (0xC7))
#define REG_SYS_LOGIC_CFG_REG_7_ADDR(base) ((base) + (0xC8))
#define REG_SYS_LOGIC_CFG_REG_8_ADDR(base) ((base) + (0xC9))
#define REG_SYS_LOGIC_CFG_REG_9_ADDR(base) ((base) + (0xCA))
#define REG_SYS_LOGIC_CFG_REG_10_ADDR(base) ((base) + (0xCB))
#define REG_SYS_LOGIC_CFG_REG_11_ADDR(base) ((base) + (0xCC))
#define REG_SYS_LOGIC_RO_REG_12_ADDR(base) ((base) + (0xCD))
#define REG_SYS_LOGIC_RO_REG_13_ADDR(base) ((base) + (0xCE))
#define REG_SYS_LOGIC_RO_REG_14_ADDR(base) ((base) + (0xCF))
#define REG_TCPC_CFG_REG_0_ADDR(base) ((base) + (0xD4))
#define REG_TCPC_CFG_REG_1_ADDR(base) ((base) + (0xD5))
#define REG_TCPC_CFG_REG_2_ADDR(base) ((base) + (0xD6))
#define REG_TCPC_CFG_REG_3_ADDR(base) ((base) + (0xD7))
#define REG_TYPE_CFG_REG_4_ADDR(base) ((base) + (0xD8))
#define REG_TCPC_RO_REG_1_ADDR(base) ((base) + (0xD9))
#define REG_SC_PRO_CFG_REG_0_ADDR(base) ((base) + (0xDA))
#define REG_SC_PRO_CFG_REG_1_ADDR(base) ((base) + (0xDB))
#define REG_SC_PRO_CFG_REG_2_ADDR(base) ((base) + (0xDC))
#define REG_SC_PRO_CFG_REG_3_ADDR(base) ((base) + (0xDD))
#define REG_SC_PRO_CFG_REG_4_ADDR(base) ((base) + (0xDE))
#define REG_SC_PRO_CFG_REG_5_ADDR(base) ((base) + (0xDF))
#define REG_SC_PRO_CFG_REG_6_ADDR(base) ((base) + (0xE0))
#define REG_SC_PRO_CFG_REG_7_ADDR(base) ((base) + (0xE1))
#define REG_SC_PRO_CFG_REG_8_ADDR(base) ((base) + (0xE2))
#define REG_SC_PRO_CFG_REG_9_ADDR(base) ((base) + (0xE3))
#define REG_SC_PRO_CFG_REG_10_ADDR(base) ((base) + (0xE4))
#define REG_SC_PRO_CFG_REG_11_ADDR(base) ((base) + (0xE5))
#define REG_SC_PRO_CFG_REG_12_ADDR(base) ((base) + (0xE6))
#define REG_SC_PRO_CFG_REG_13_ADDR(base) ((base) + (0xE7))
#define REG_SC_PRO_CFG_REG_14_ADDR(base) ((base) + (0xE8))
#define REG_SC_PRO_CFG_REG_15_ADDR(base) ((base) + (0xE9))
#define REG_SC_PRO_CFG_REG_16_ADDR(base) ((base) + (0xEA))
#define REG_SC_PRO_CFG_REG_17_ADDR(base) ((base) + (0xEB))
#define REG_REF_TOP_CFG_REG_0_ADDR(base) ((base) + (0xF0))
#define REG_REF_TOP_CFG_REG_1_ADDR(base) ((base) + (0xF1))
#define REG_REF_TOP_CFG_REG_2_ADDR(base) ((base) + (0xF2))
#define REG_REF_TOP_CFG_REG_3_ADDR(base) ((base) + (0xF3))
#define REG_REF_TOP_CFG_REG_4_ADDR(base) ((base) + (0xF4))
#define REG_REF_TOP_CFG_REG_5_ADDR(base) ((base) + (0xF5))
#define REG_OSC_TOP_CFG_REG_0_ADDR(base) ((base) + (0xF6))
#define REG_OSC_TOP_CFG_REG_1_ADDR(base) ((base) + (0xF7))
#define REG_OSC_TOP_CFG_REG_2_ADDR(base) ((base) + (0xF8))
#define REG_AD_STATUS_RSV0_ADDR(base) ((base) + (0xFA))
#define REG_AD_STATUS_RSV1_ADDR(base) ((base) + (0xFB))
#define REG_AD_STATUS_RSV2_ADDR(base) ((base) + (0xFC))
#define REG_AD_STATUS_RSV3_ADDR(base) ((base) + (0xFD))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_FER_CTRL_ADDR(base) ((base) + (0x0000UL))
#define REG_FER_EVENT_LEVEL_ADDR(base) ((base) + (0x0001UL))
#define REG_FER_BUCK_PG_MSK_ADDR(base) ((base) + (0x0002UL))
#define REG_FER_BUCK_VOK_MSK_ADDR(base) ((base) + (0x0003UL))
#define REG_FER_BUCK_OC_MSK_ADDR(base) ((base) + (0x004UL))
#define REG_FER_BUCK_OT_MSK_ADDR(base) ((base) + (0x0005UL))
#define REG_FER_PMU_PSOK_MSK_ADDR(base) ((base) + (0x0006UL))
#define REG_FER_PMU_IRQ_MSK0_ADDR(base) ((base) + (0x0007UL))
#define REG_FER_PMU_IRQ_MSK1_ADDR(base) ((base) + (0x008UL))
#define REG_FER_BUF_BUCK_PGVOK_ADDR(base) ((base) + (0x0009UL))
#define REG_FER_BUF_BUCK_OCOT_ADDR(base) ((base) + (0x000aUL))
#define REG_FER_BUF_PMU_PSOK_ADDR(base) ((base) + (0x000bUL))
#define REG_FER_BUF_PMU_IRQ0_ADDR(base) ((base) + (0x000cUL))
#define REG_FER_BUF_PMU_IRQ1_ADDR(base) ((base) + (0x000dUL))
#define REG_FER_TRANS_ABIT_DATA_ADDR(base) ((base) + (0x000eUL))
#define REG_FER_TRANS_ABIT_ADDR_ADDR(base) ((base) + (0x000fUL))
#define REG_FER_TRANS_SRBIT_DATA_ADDR(base) ((base) + (0x0010UL))
#define REG_FER_TRANS_SRBIT_ADDR_ADDR(base) ((base) + (0x0011UL))
#define REG_SPMI_DEBUG0_ADDR(base) ((base) + (0x0040UL))
#define REG_SPMI_DEBUG1_ADDR(base) ((base) + (0x0041UL))
#define REG_SPMI_DEBUG2_ADDR(base) ((base) + (0x0042UL))
#define REG_SPMI_DEBUG3_ADDR(base) ((base) + (0x0043UL))
#define REG_SPMI_DEBUG4_ADDR(base) ((base) + (0x0044UL))
#define REG_SPMI_DEBUG5_ADDR(base) ((base) + (0x0045UL))
#define REG_SPMI_DEBUG6_ADDR(base) ((base) + (0x0046UL))
#define REG_SPMI_DEBUG7_ADDR(base) ((base) + (0x0047UL))
#else
#define REG_FER_CTRL_ADDR(base) ((base) + (0x0000))
#define REG_FER_EVENT_LEVEL_ADDR(base) ((base) + (0x0001))
#define REG_FER_BUCK_PG_MSK_ADDR(base) ((base) + (0x0002))
#define REG_FER_BUCK_VOK_MSK_ADDR(base) ((base) + (0x0003))
#define REG_FER_BUCK_OC_MSK_ADDR(base) ((base) + (0x004))
#define REG_FER_BUCK_OT_MSK_ADDR(base) ((base) + (0x0005))
#define REG_FER_PMU_PSOK_MSK_ADDR(base) ((base) + (0x0006))
#define REG_FER_PMU_IRQ_MSK0_ADDR(base) ((base) + (0x0007))
#define REG_FER_PMU_IRQ_MSK1_ADDR(base) ((base) + (0x008))
#define REG_FER_BUF_BUCK_PGVOK_ADDR(base) ((base) + (0x0009))
#define REG_FER_BUF_BUCK_OCOT_ADDR(base) ((base) + (0x000a))
#define REG_FER_BUF_PMU_PSOK_ADDR(base) ((base) + (0x000b))
#define REG_FER_BUF_PMU_IRQ0_ADDR(base) ((base) + (0x000c))
#define REG_FER_BUF_PMU_IRQ1_ADDR(base) ((base) + (0x000d))
#define REG_FER_TRANS_ABIT_DATA_ADDR(base) ((base) + (0x000e))
#define REG_FER_TRANS_ABIT_ADDR_ADDR(base) ((base) + (0x000f))
#define REG_FER_TRANS_SRBIT_DATA_ADDR(base) ((base) + (0x0010))
#define REG_FER_TRANS_SRBIT_ADDR_ADDR(base) ((base) + (0x0011))
#define REG_SPMI_DEBUG0_ADDR(base) ((base) + (0x0040))
#define REG_SPMI_DEBUG1_ADDR(base) ((base) + (0x0041))
#define REG_SPMI_DEBUG2_ADDR(base) ((base) + (0x0042))
#define REG_SPMI_DEBUG3_ADDR(base) ((base) + (0x0043))
#define REG_SPMI_DEBUG4_ADDR(base) ((base) + (0x0044))
#define REG_SPMI_DEBUG5_ADDR(base) ((base) + (0x0045))
#define REG_SPMI_DEBUG6_ADDR(base) ((base) + (0x0046))
#define REG_SPMI_DEBUG7_ADDR(base) ((base) + (0x0047))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_FLASH_DIG_CFG_0_ADDR(base) ((base) + (0x00UL))
#define REG_FLASH_LED_MD_ADDR(base) ((base) + (0x01UL))
#define REG_FLASH_LED_EN_ADDR(base) ((base) + (0x02UL))
#define REG_FLASH_LED1_TIMEOUT_ADDR(base) ((base) + (0x03UL))
#define REG_FLASH_LED2_TIMEOUT_ADDR(base) ((base) + (0x04UL))
#define REG_FLASH_LED3_TIMEOUT_ADDR(base) ((base) + (0x05UL))
#define REG_FLASH_LED1_CODE_ADDR(base) ((base) + (0x06UL))
#define REG_FLASH_LED2_CODE_ADDR(base) ((base) + (0x07UL))
#define REG_FLASH_LED3_CODE_ADDR(base) ((base) + (0x08UL))
#define REG_FLASH_RAMP_STEP_ADDR(base) ((base) + (0x09UL))
#define REG_FLASH_DIG_CFG_7_ADDR(base) ((base) + (0x0AUL))
#define REG_FLASH_CFG_REG_0_ADDR(base) ((base) + (0x40UL))
#define REG_FLASH_CFG_REG_1_ADDR(base) ((base) + (0x41UL))
#define REG_FLASH_CFG_REG_2_ADDR(base) ((base) + (0x42UL))
#define REG_FLASH_CFG_REG_3_ADDR(base) ((base) + (0x43UL))
#define REG_FLASH_CFG_REG_4_ADDR(base) ((base) + (0x44UL))
#define REG_FLASH_CFG_REG_5_ADDR(base) ((base) + (0x45UL))
#define REG_FLASH_RO_REG_ADDR(base) ((base) + (0x46UL))
#define REG_FLASH_LED1_CODE_RO_ADDR(base) ((base) + (0x47UL))
#define REG_FLASH_LED2_CODE_RO_ADDR(base) ((base) + (0x48UL))
#define REG_FLASH_LED3_CODE_RO_ADDR(base) ((base) + (0x49UL))
#else
#define REG_FLASH_DIG_CFG_0_ADDR(base) ((base) + (0x00))
#define REG_FLASH_LED_MD_ADDR(base) ((base) + (0x01))
#define REG_FLASH_LED_EN_ADDR(base) ((base) + (0x02))
#define REG_FLASH_LED1_TIMEOUT_ADDR(base) ((base) + (0x03))
#define REG_FLASH_LED2_TIMEOUT_ADDR(base) ((base) + (0x04))
#define REG_FLASH_LED3_TIMEOUT_ADDR(base) ((base) + (0x05))
#define REG_FLASH_LED1_CODE_ADDR(base) ((base) + (0x06))
#define REG_FLASH_LED2_CODE_ADDR(base) ((base) + (0x07))
#define REG_FLASH_LED3_CODE_ADDR(base) ((base) + (0x08))
#define REG_FLASH_RAMP_STEP_ADDR(base) ((base) + (0x09))
#define REG_FLASH_DIG_CFG_7_ADDR(base) ((base) + (0x0A))
#define REG_FLASH_CFG_REG_0_ADDR(base) ((base) + (0x40))
#define REG_FLASH_CFG_REG_1_ADDR(base) ((base) + (0x41))
#define REG_FLASH_CFG_REG_2_ADDR(base) ((base) + (0x42))
#define REG_FLASH_CFG_REG_3_ADDR(base) ((base) + (0x43))
#define REG_FLASH_CFG_REG_4_ADDR(base) ((base) + (0x44))
#define REG_FLASH_CFG_REG_5_ADDR(base) ((base) + (0x45))
#define REG_FLASH_RO_REG_ADDR(base) ((base) + (0x46))
#define REG_FLASH_LED1_CODE_RO_ADDR(base) ((base) + (0x47))
#define REG_FLASH_LED2_CODE_RO_ADDR(base) ((base) + (0x48))
#define REG_FLASH_LED3_CODE_RO_ADDR(base) ((base) + (0x49))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_UFCS_EN_REG_ADDR(base) ((base) + (0x00UL))
#define REG_UFCS_CTRL_REG_ADDR(base) ((base) + (0x01UL))
#define REG_UFCS_HK_TIMES_REG_ADDR(base) ((base) + (0x02UL))
#define REG_UFCS_RX_M0_BAUD_REG_0_ADDR(base) ((base) + (0x03UL))
#define REG_UFCS_ANCK_REQ_TMR_ADDR(base) ((base) + (0x04UL))
#define REG_UFCS_HW_RST_CFG_ADDR(base) ((base) + (0x11UL))
#define REG_UFCS_WD_TMR_CLR_REG_ADDR(base) ((base) + (0x12UL))
#define REG_UFCS_REV_TMR_CLR_REG_ADDR(base) ((base) + (0x13UL))
#define REG_UFCS_TX_EN_REG_ADDR(base) ((base) + (0x14UL))
#define REG_UFCS_TX_CABLE_RST_REG_ADDR(base) ((base) + (0x15UL))
#define REG_UFCS_TX_RST_REG_ADDR(base) ((base) + (0x16UL))
#define REG_UFCS_TX_ANCK_TMPL_REG_0_ADDR(base) ((base) + (0x17UL))
#define REG_UFCS_TX_ANCK_TMPL_REG_1_ADDR(base) ((base) + (0x18UL))
#define REG_UFCS_WD_CFG_ADDR(base) ((base) + (0x19UL))
#define REG_UFCS_RX_ANALYSIS_REG_ADDR(base) ((base) + (0x1AUL))
#define REG_UFCS_CTRL_EN_REG_1_ADDR(base) ((base) + (0x1BUL))
#define REG_UFCS_CTRL_EN_REG_2_ADDR(base) ((base) + (0x1CUL))
#define REG_UFCS_SEND_TMR_CLR_REG_ADDR(base) ((base) + (0x1DUL))
#define REG_UFCS_TX_CTRL_REG_ADDR(base) ((base) + (0x1EUL))
#define REG_UFCS_TX_BAUD_REG_ADDR(base) ((base) + (0x1FUL))
#define REG_UFCS_SOFT_RST_EN_REG_ADDR(base) ((base) + (0x20UL))
#define REG_UFCS_RX_READ_REQ_ADDR(base) ((base) + (0x21UL))
#define REG_UFCS_RX_BAUD_RO_0_ADDR(base) ((base) + (0x23UL))
#define REG_UFCS_RX_BAUD_RO_1_ADDR(base) ((base) + (0x24UL))
#define REG_UFCS_RX_BAUD_STEP_RO_ADDR(base) ((base) + (0x25UL))
#define REG_UFCS_RX_STATUS_RO_ADDR(base) ((base) + (0x26UL))
#define REG_UFCS_IRQ_FLG_0_ADDR(base) ((base) + (0x27UL))
#define REG_UFCS_IRQ_FLG_1_ADDR(base) ((base) + (0x28UL))
#define REG_UFCS_IRQ_MASK_0_ADDR(base) ((base) + (0x29UL))
#define REG_UFCS_IRQ_MASK_1_ADDR(base) ((base) + (0x2AUL))
#define REG_UFCS_MISC_EN_SEL_REG_ADDR(base) ((base) + (0x2BUL))
#define REG_UFCS_MISC_EN_REG_ADDR(base) ((base) + (0x2CUL))
#define REG_UFCS_RX_DEBUG_REG_ADDR(base) ((base) + (0x2DUL))
#define REG_UFCS_RX_PTYPE_RO_ADDR(base) ((base) + (0x2EUL))
#define REG_UFCS_RX_FAULT_REG_0_ADDR(base) ((base) + (0x2FUL))
#define REG_UFCS_RX_FAULT_REG_1_ADDR(base) ((base) + (0x30UL))
#define REG_UFCS_STM_DEBUG_REG_ADDR(base) ((base) + (0x31UL))
#define REG_UFCS_TESTBUS_RO_SEL_REG_ADDR(base) ((base) + (0x32UL))
#define REG_UFCS_TESTBUS_RO_DATA_REG_ADDR(base) ((base) + (0x33UL))
#define REG_UFCS_AD_RESERVE_REG_ADDR(base) ((base) + (0x34UL))
#define REG_UFCS_DA_RESERVE_REG_ADDR(base) ((base) + (0x35UL))
#define REG_UFCS_CLK_EN_ADDR(base) ((base) + (0x36UL))
#define REG_UFCS_TEST_SIG_ADDR(base) ((base) + (0x37UL))
#define REG_UFCS_TX_MSG_LEN_0_ADDR(base) ((base) + (0x39UL))
#define REG_UFCS_TX_MSG_LEN_1_ADDR(base) ((base) + (0x3AUL))
#define REG_UFCS_TX_RESERVED0_ADDR(base) ((base) + (0x3BUL))
#define REG_UFCS_TX_RESERVED1_ADDR(base) ((base) + (0x3CUL))
#else
#define REG_UFCS_EN_REG_ADDR(base) ((base) + (0x00))
#define REG_UFCS_CTRL_REG_ADDR(base) ((base) + (0x01))
#define REG_UFCS_HK_TIMES_REG_ADDR(base) ((base) + (0x02))
#define REG_UFCS_RX_M0_BAUD_REG_0_ADDR(base) ((base) + (0x03))
#define REG_UFCS_ANCK_REQ_TMR_ADDR(base) ((base) + (0x04))
#define REG_UFCS_HW_RST_CFG_ADDR(base) ((base) + (0x11))
#define REG_UFCS_WD_TMR_CLR_REG_ADDR(base) ((base) + (0x12))
#define REG_UFCS_REV_TMR_CLR_REG_ADDR(base) ((base) + (0x13))
#define REG_UFCS_TX_EN_REG_ADDR(base) ((base) + (0x14))
#define REG_UFCS_TX_CABLE_RST_REG_ADDR(base) ((base) + (0x15))
#define REG_UFCS_TX_RST_REG_ADDR(base) ((base) + (0x16))
#define REG_UFCS_TX_ANCK_TMPL_REG_0_ADDR(base) ((base) + (0x17))
#define REG_UFCS_TX_ANCK_TMPL_REG_1_ADDR(base) ((base) + (0x18))
#define REG_UFCS_WD_CFG_ADDR(base) ((base) + (0x19))
#define REG_UFCS_RX_ANALYSIS_REG_ADDR(base) ((base) + (0x1A))
#define REG_UFCS_CTRL_EN_REG_1_ADDR(base) ((base) + (0x1B))
#define REG_UFCS_CTRL_EN_REG_2_ADDR(base) ((base) + (0x1C))
#define REG_UFCS_SEND_TMR_CLR_REG_ADDR(base) ((base) + (0x1D))
#define REG_UFCS_TX_CTRL_REG_ADDR(base) ((base) + (0x1E))
#define REG_UFCS_TX_BAUD_REG_ADDR(base) ((base) + (0x1F))
#define REG_UFCS_SOFT_RST_EN_REG_ADDR(base) ((base) + (0x20))
#define REG_UFCS_RX_READ_REQ_ADDR(base) ((base) + (0x21))
#define REG_UFCS_RX_BAUD_RO_0_ADDR(base) ((base) + (0x23))
#define REG_UFCS_RX_BAUD_RO_1_ADDR(base) ((base) + (0x24))
#define REG_UFCS_RX_BAUD_STEP_RO_ADDR(base) ((base) + (0x25))
#define REG_UFCS_RX_STATUS_RO_ADDR(base) ((base) + (0x26))
#define REG_UFCS_IRQ_FLG_0_ADDR(base) ((base) + (0x27))
#define REG_UFCS_IRQ_FLG_1_ADDR(base) ((base) + (0x28))
#define REG_UFCS_IRQ_MASK_0_ADDR(base) ((base) + (0x29))
#define REG_UFCS_IRQ_MASK_1_ADDR(base) ((base) + (0x2A))
#define REG_UFCS_MISC_EN_SEL_REG_ADDR(base) ((base) + (0x2B))
#define REG_UFCS_MISC_EN_REG_ADDR(base) ((base) + (0x2C))
#define REG_UFCS_RX_DEBUG_REG_ADDR(base) ((base) + (0x2D))
#define REG_UFCS_RX_PTYPE_RO_ADDR(base) ((base) + (0x2E))
#define REG_UFCS_RX_FAULT_REG_0_ADDR(base) ((base) + (0x2F))
#define REG_UFCS_RX_FAULT_REG_1_ADDR(base) ((base) + (0x30))
#define REG_UFCS_STM_DEBUG_REG_ADDR(base) ((base) + (0x31))
#define REG_UFCS_TESTBUS_RO_SEL_REG_ADDR(base) ((base) + (0x32))
#define REG_UFCS_TESTBUS_RO_DATA_REG_ADDR(base) ((base) + (0x33))
#define REG_UFCS_AD_RESERVE_REG_ADDR(base) ((base) + (0x34))
#define REG_UFCS_DA_RESERVE_REG_ADDR(base) ((base) + (0x35))
#define REG_UFCS_CLK_EN_ADDR(base) ((base) + (0x36))
#define REG_UFCS_TEST_SIG_ADDR(base) ((base) + (0x37))
#define REG_UFCS_TX_MSG_LEN_0_ADDR(base) ((base) + (0x39))
#define REG_UFCS_TX_MSG_LEN_1_ADDR(base) ((base) + (0x3A))
#define REG_UFCS_TX_RESERVED0_ADDR(base) ((base) + (0x3B))
#define REG_UFCS_TX_RESERVED1_ADDR(base) ((base) + (0x3C))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_TX_RAM_DATA_0_ADDR(base,tx_ram_n_0) ((base) + (0x3D+(tx_ram_n_0)UL))
#else
#define REG_TX_RAM_DATA_0_ADDR(base,tx_ram_n_0) ((base) + (0x3D+(tx_ram_n_0)))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_TX_RAM_DATA_1_ADDR(base,tx_ram_n_1) ((base) + (0x00+(tx_ram_n_1)UL))
#else
#define REG_TX_RAM_DATA_1_ADDR(base,tx_ram_n_1) ((base) + (0x00+(tx_ram_n_1)))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_TX_RAM_DATA_2_ADDR(base,tx_ram_n_2) ((base) + (0x00+(tx_ram_n_2)UL))
#else
#define REG_TX_RAM_DATA_2_ADDR(base,tx_ram_n_2) ((base) + (0x00+(tx_ram_n_2)))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_UFCS_RX_MSG_LEN_0_ADDR(base) ((base) + (0x39UL))
#define REG_UFCS_RX_MSG_LEN_1_ADDR(base) ((base) + (0x3AUL))
#define REG_UFCS_RX_RESERVED0_ADDR(base) ((base) + (0x3BUL))
#define REG_UFCS_RX_RESERVED1_ADDR(base) ((base) + (0x3CUL))
#define REG_RX_RAM_DATA_0_ADDR(base,rx_ram_n_0) ((base) + (0x3D+(rx_ram_n_0)UL))
#else
#define REG_UFCS_RX_MSG_LEN_0_ADDR(base) ((base) + (0x39))
#define REG_UFCS_RX_MSG_LEN_1_ADDR(base) ((base) + (0x3A))
#define REG_UFCS_RX_RESERVED0_ADDR(base) ((base) + (0x3B))
#define REG_UFCS_RX_RESERVED1_ADDR(base) ((base) + (0x3C))
#define REG_RX_RAM_DATA_0_ADDR(base,rx_ram_n_0) ((base) + (0x3D+(rx_ram_n_0)))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_RX_RAM_DATA_1_ADDR(base,rx_ram_n_1) ((base) + (0x00+(rx_ram_n_1)UL))
#else
#define REG_RX_RAM_DATA_1_ADDR(base,rx_ram_n_1) ((base) + (0x00+(rx_ram_n_1)))
#endif
#ifndef __SOC_H_FOR_ASM__
#define REG_RX_RAM_DATA_2_ADDR(base,rx_ram_n_2) ((base) + (0x00+(rx_ram_n_2)UL))
#else
#define REG_RX_RAM_DATA_2_ADDR(base,rx_ram_n_2) ((base) + (0x00+(rx_ram_n_2)))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_vend_id_l : 8;
    } reg;
} REG_VENDIDL_UNION;
#endif
#define REG_VENDIDL_pd_vend_id_l_START (0)
#define REG_VENDIDL_pd_vend_id_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_vend_id_h : 8;
    } reg;
} REG_VENDIDH_UNION;
#endif
#define REG_VENDIDH_pd_vend_id_h_START (0)
#define REG_VENDIDH_pd_vend_id_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_prod_id_l : 8;
    } reg;
} REG_PRODIDL_UNION;
#endif
#define REG_PRODIDL_pd_prod_id_l_START (0)
#define REG_PRODIDL_pd_prod_id_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_prod_id_h : 8;
    } reg;
} REG_PRODIDH_UNION;
#endif
#define REG_PRODIDH_pd_prod_id_h_START (0)
#define REG_PRODIDH_pd_prod_id_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dev_id_l : 8;
    } reg;
} REG_DEVIDL_UNION;
#endif
#define REG_DEVIDL_pd_dev_id_l_START (0)
#define REG_DEVIDL_pd_dev_id_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dev_id_h : 8;
    } reg;
} REG_DEVIDH_UNION;
#endif
#define REG_DEVIDH_pd_dev_id_h_START (0)
#define REG_DEVIDH_pd_dev_id_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_typc_revision_l : 8;
    } reg;
} REG_TYPECREVL_UNION;
#endif
#define REG_TYPECREVL_pd_typc_revision_l_START (0)
#define REG_TYPECREVL_pd_typc_revision_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_typc_revision_h : 8;
    } reg;
} REG_TYPECREVH_UNION;
#endif
#define REG_TYPECREVH_pd_typc_revision_h_START (0)
#define REG_TYPECREVH_pd_typc_revision_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_version : 8;
    } reg;
} REG_USBPDVER_UNION;
#endif
#define REG_USBPDVER_pd_version_START (0)
#define REG_USBPDVER_pd_version_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_revision : 8;
    } reg;
} REG_USBPDREV_UNION;
#endif
#define REG_USBPDREV_pd_revision_START (0)
#define REG_USBPDREV_pd_revision_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_itf_revision_l : 8;
    } reg;
} REG_PDIFREVL_UNION;
#endif
#define REG_PDIFREVL_pd_itf_revision_l_START (0)
#define REG_PDIFREVL_pd_itf_revision_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_itf_revision_h : 8;
    } reg;
} REG_PDIFREVH_UNION;
#endif
#define REG_PDIFREVH_pd_itf_revision_h_START (0)
#define REG_PDIFREVH_pd_itf_revision_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_int_ccstatus : 1;
        unsigned char pd_int_port_pwr : 1;
        unsigned char pd_int_rxstat : 1;
        unsigned char pd_int_rxhardrst : 1;
        unsigned char pd_int_txfail : 1;
        unsigned char pd_int_txdisc : 1;
        unsigned char pd_int_txsucc : 1;
        unsigned char pd_int_vbus_alrm_h : 1;
    } reg;
} REG_PD_ALERT_L_UNION;
#endif
#define REG_PD_ALERT_L_pd_int_ccstatus_START (0)
#define REG_PD_ALERT_L_pd_int_ccstatus_END (0)
#define REG_PD_ALERT_L_pd_int_port_pwr_START (1)
#define REG_PD_ALERT_L_pd_int_port_pwr_END (1)
#define REG_PD_ALERT_L_pd_int_rxstat_START (2)
#define REG_PD_ALERT_L_pd_int_rxstat_END (2)
#define REG_PD_ALERT_L_pd_int_rxhardrst_START (3)
#define REG_PD_ALERT_L_pd_int_rxhardrst_END (3)
#define REG_PD_ALERT_L_pd_int_txfail_START (4)
#define REG_PD_ALERT_L_pd_int_txfail_END (4)
#define REG_PD_ALERT_L_pd_int_txdisc_START (5)
#define REG_PD_ALERT_L_pd_int_txdisc_END (5)
#define REG_PD_ALERT_L_pd_int_txsucc_START (6)
#define REG_PD_ALERT_L_pd_int_txsucc_END (6)
#define REG_PD_ALERT_L_pd_int_vbus_alrm_h_START (7)
#define REG_PD_ALERT_L_pd_int_vbus_alrm_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_int_vbus_alrm_l : 1;
        unsigned char pd_int_fault : 1;
        unsigned char pd_int_rx_full : 1;
        unsigned char pd_int_vbus_snk_disc : 1;
        unsigned char reserved : 3;
        unsigned char pd_int_fr_swap : 1;
    } reg;
} REG_PD_ALERT_H_UNION;
#endif
#define REG_PD_ALERT_H_pd_int_vbus_alrm_l_START (0)
#define REG_PD_ALERT_H_pd_int_vbus_alrm_l_END (0)
#define REG_PD_ALERT_H_pd_int_fault_START (1)
#define REG_PD_ALERT_H_pd_int_fault_END (1)
#define REG_PD_ALERT_H_pd_int_rx_full_START (2)
#define REG_PD_ALERT_H_pd_int_rx_full_END (2)
#define REG_PD_ALERT_H_pd_int_vbus_snk_disc_START (3)
#define REG_PD_ALERT_H_pd_int_vbus_snk_disc_END (3)
#define REG_PD_ALERT_H_pd_int_fr_swap_START (7)
#define REG_PD_ALERT_H_pd_int_fr_swap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_msk_ccstatus : 1;
        unsigned char pd_msk_port_pwr : 1;
        unsigned char pd_msk_rxstat : 1;
        unsigned char pd_msk_rxhardrst : 1;
        unsigned char pd_msk_txfail : 1;
        unsigned char pd_msk_txdisc : 1;
        unsigned char pd_msk_txsucc : 1;
        unsigned char pd_msk_vbus_alrm_h : 1;
    } reg;
} REG_PD_ALERT_MSK_L_UNION;
#endif
#define REG_PD_ALERT_MSK_L_pd_msk_ccstatus_START (0)
#define REG_PD_ALERT_MSK_L_pd_msk_ccstatus_END (0)
#define REG_PD_ALERT_MSK_L_pd_msk_port_pwr_START (1)
#define REG_PD_ALERT_MSK_L_pd_msk_port_pwr_END (1)
#define REG_PD_ALERT_MSK_L_pd_msk_rxstat_START (2)
#define REG_PD_ALERT_MSK_L_pd_msk_rxstat_END (2)
#define REG_PD_ALERT_MSK_L_pd_msk_rxhardrst_START (3)
#define REG_PD_ALERT_MSK_L_pd_msk_rxhardrst_END (3)
#define REG_PD_ALERT_MSK_L_pd_msk_txfail_START (4)
#define REG_PD_ALERT_MSK_L_pd_msk_txfail_END (4)
#define REG_PD_ALERT_MSK_L_pd_msk_txdisc_START (5)
#define REG_PD_ALERT_MSK_L_pd_msk_txdisc_END (5)
#define REG_PD_ALERT_MSK_L_pd_msk_txsucc_START (6)
#define REG_PD_ALERT_MSK_L_pd_msk_txsucc_END (6)
#define REG_PD_ALERT_MSK_L_pd_msk_vbus_alrm_h_START (7)
#define REG_PD_ALERT_MSK_L_pd_msk_vbus_alrm_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_msk_vbus_alrm_l : 1;
        unsigned char pd_msk_fault : 1;
        unsigned char pd_msk_rx_full : 1;
        unsigned char pd_msk_vbus_snk_disc : 1;
        unsigned char reserved : 3;
        unsigned char pd_msk_fr_swap : 1;
    } reg;
} REG_PD_ALERT_MSK_H_UNION;
#endif
#define REG_PD_ALERT_MSK_H_pd_msk_vbus_alrm_l_START (0)
#define REG_PD_ALERT_MSK_H_pd_msk_vbus_alrm_l_END (0)
#define REG_PD_ALERT_MSK_H_pd_msk_fault_START (1)
#define REG_PD_ALERT_MSK_H_pd_msk_fault_END (1)
#define REG_PD_ALERT_MSK_H_pd_msk_rx_full_START (2)
#define REG_PD_ALERT_MSK_H_pd_msk_rx_full_END (2)
#define REG_PD_ALERT_MSK_H_pd_msk_vbus_snk_disc_START (3)
#define REG_PD_ALERT_MSK_H_pd_msk_vbus_snk_disc_END (3)
#define REG_PD_ALERT_MSK_H_pd_msk_fr_swap_START (7)
#define REG_PD_ALERT_MSK_H_pd_msk_fr_swap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_msk_snkvbus : 1;
        unsigned char pd_msk_vconn_vld : 1;
        unsigned char pd_msk_vbus_vld : 1;
        unsigned char pd_msk_vbus_vld_en : 1;
        unsigned char pd_msk_src_vbus : 1;
        unsigned char reserved : 1;
        unsigned char pd_msk_init_stat : 1;
        unsigned char pd_msk_debug_acc : 1;
    } reg;
} REG_PD_PWRSTAT_MSK_UNION;
#endif
#define REG_PD_PWRSTAT_MSK_pd_msk_snkvbus_START (0)
#define REG_PD_PWRSTAT_MSK_pd_msk_snkvbus_END (0)
#define REG_PD_PWRSTAT_MSK_pd_msk_vconn_vld_START (1)
#define REG_PD_PWRSTAT_MSK_pd_msk_vconn_vld_END (1)
#define REG_PD_PWRSTAT_MSK_pd_msk_vbus_vld_START (2)
#define REG_PD_PWRSTAT_MSK_pd_msk_vbus_vld_END (2)
#define REG_PD_PWRSTAT_MSK_pd_msk_vbus_vld_en_START (3)
#define REG_PD_PWRSTAT_MSK_pd_msk_vbus_vld_en_END (3)
#define REG_PD_PWRSTAT_MSK_pd_msk_src_vbus_START (4)
#define REG_PD_PWRSTAT_MSK_pd_msk_src_vbus_END (4)
#define REG_PD_PWRSTAT_MSK_pd_msk_init_stat_START (6)
#define REG_PD_PWRSTAT_MSK_pd_msk_init_stat_END (6)
#define REG_PD_PWRSTAT_MSK_pd_msk_debug_acc_START (7)
#define REG_PD_PWRSTAT_MSK_pd_msk_debug_acc_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_msk_i2c_err : 1;
        unsigned char pd_msk_cc_fault : 1;
        unsigned char pd_msk_vbus_ovp : 1;
        unsigned char reserved_0 : 1;
        unsigned char pd_msk_force_disch_fail : 1;
        unsigned char pd_msk_auto_disch_fail : 1;
        unsigned char reserved_1 : 2;
    } reg;
} REG_PD_FAULTSTAT_MSK_UNION;
#endif
#define REG_PD_FAULTSTAT_MSK_pd_msk_i2c_err_START (0)
#define REG_PD_FAULTSTAT_MSK_pd_msk_i2c_err_END (0)
#define REG_PD_FAULTSTAT_MSK_pd_msk_cc_fault_START (1)
#define REG_PD_FAULTSTAT_MSK_pd_msk_cc_fault_END (1)
#define REG_PD_FAULTSTAT_MSK_pd_msk_vbus_ovp_START (2)
#define REG_PD_FAULTSTAT_MSK_pd_msk_vbus_ovp_END (2)
#define REG_PD_FAULTSTAT_MSK_pd_msk_force_disch_fail_START (4)
#define REG_PD_FAULTSTAT_MSK_pd_msk_force_disch_fail_END (4)
#define REG_PD_FAULTSTAT_MSK_pd_msk_auto_disch_fail_START (5)
#define REG_PD_FAULTSTAT_MSK_pd_msk_auto_disch_fail_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_msk_vbus_vsafe0 : 1;
        unsigned char reserved : 7;
    } reg;
} REG_EXTENDED_STATUS_MASK_UNION;
#endif
#define REG_EXTENDED_STATUS_MASK_pd_msk_vbus_vsafe0_START (0)
#define REG_EXTENDED_STATUS_MASK_pd_msk_vbus_vsafe0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_msk_snk_rec_frs : 1;
        unsigned char pd_msk_src_rec_frs : 1;
        unsigned char reserved : 6;
    } reg;
} REG_ALERT_EXTENDED_MASK_UNION;
#endif
#define REG_ALERT_EXTENDED_MASK_pd_msk_snk_rec_frs_START (0)
#define REG_ALERT_EXTENDED_MASK_pd_msk_snk_rec_frs_END (0)
#define REG_ALERT_EXTENDED_MASK_pd_msk_src_rec_frs_START (1)
#define REG_ALERT_EXTENDED_MASK_pd_msk_src_rec_frs_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_orient : 1;
        unsigned char pd_bist_mode : 1;
        unsigned char reserved_0 : 2;
        unsigned char pd_debug_acc_ctrl : 1;
        unsigned char reserved_1 : 1;
        unsigned char pd_en_look4con_alert : 1;
        unsigned char reserved_2 : 1;
    } reg;
} REG_PD_TCPC_CTRL_UNION;
#endif
#define REG_PD_TCPC_CTRL_pd_orient_START (0)
#define REG_PD_TCPC_CTRL_pd_orient_END (0)
#define REG_PD_TCPC_CTRL_pd_bist_mode_START (1)
#define REG_PD_TCPC_CTRL_pd_bist_mode_END (1)
#define REG_PD_TCPC_CTRL_pd_debug_acc_ctrl_START (4)
#define REG_PD_TCPC_CTRL_pd_debug_acc_ctrl_END (4)
#define REG_PD_TCPC_CTRL_pd_en_look4con_alert_START (6)
#define REG_PD_TCPC_CTRL_pd_en_look4con_alert_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_cc1_cfg : 2;
        unsigned char pd_cc2_cfg : 2;
        unsigned char pd_rp_cfg : 2;
        unsigned char pd_drp : 1;
        unsigned char reserved : 1;
    } reg;
} REG_PD_ROLE_CTRL_UNION;
#endif
#define REG_PD_ROLE_CTRL_pd_cc1_cfg_START (0)
#define REG_PD_ROLE_CTRL_pd_cc1_cfg_END (1)
#define REG_PD_ROLE_CTRL_pd_cc2_cfg_START (2)
#define REG_PD_ROLE_CTRL_pd_cc2_cfg_END (3)
#define REG_PD_ROLE_CTRL_pd_rp_cfg_START (4)
#define REG_PD_ROLE_CTRL_pd_rp_cfg_END (5)
#define REG_PD_ROLE_CTRL_pd_drp_START (6)
#define REG_PD_ROLE_CTRL_pd_drp_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_vconn_ocp_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char pd_disch_timer_dis : 1;
        unsigned char reserved_1 : 4;
    } reg;
} REG_PD_FAULT_CTRL_UNION;
#endif
#define REG_PD_FAULT_CTRL_pd_vconn_ocp_en_START (0)
#define REG_PD_FAULT_CTRL_pd_vconn_ocp_en_END (0)
#define REG_PD_FAULT_CTRL_pd_disch_timer_dis_START (3)
#define REG_PD_FAULT_CTRL_pd_disch_timer_dis_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_vconn_en : 1;
        unsigned char reserved_0 : 1;
        unsigned char pd_force_disch_en : 1;
        unsigned char pd_bleed_disch_en : 1;
        unsigned char pd_auto_disch : 1;
        unsigned char pd_valarm_dis : 1;
        unsigned char pd_vbus_mon_dis : 1;
        unsigned char reserved_1 : 1;
    } reg;
} REG_PD_PWR_CTRL_UNION;
#endif
#define REG_PD_PWR_CTRL_pd_vconn_en_START (0)
#define REG_PD_PWR_CTRL_pd_vconn_en_END (0)
#define REG_PD_PWR_CTRL_pd_force_disch_en_START (2)
#define REG_PD_PWR_CTRL_pd_force_disch_en_END (2)
#define REG_PD_PWR_CTRL_pd_bleed_disch_en_START (3)
#define REG_PD_PWR_CTRL_pd_bleed_disch_en_END (3)
#define REG_PD_PWR_CTRL_pd_auto_disch_START (4)
#define REG_PD_PWR_CTRL_pd_auto_disch_END (4)
#define REG_PD_PWR_CTRL_pd_valarm_dis_START (5)
#define REG_PD_PWR_CTRL_pd_valarm_dis_END (5)
#define REG_PD_PWR_CTRL_pd_vbus_mon_dis_START (6)
#define REG_PD_PWR_CTRL_pd_vbus_mon_dis_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_cc1_stat : 2;
        unsigned char pd_cc2_stat : 2;
        unsigned char pd_con_result : 1;
        unsigned char pd_look4con : 1;
        unsigned char reserved : 2;
    } reg;
} REG_PD_CC_STATUS_UNION;
#endif
#define REG_PD_CC_STATUS_pd_cc1_stat_START (0)
#define REG_PD_CC_STATUS_pd_cc1_stat_END (1)
#define REG_PD_CC_STATUS_pd_cc2_stat_START (2)
#define REG_PD_CC_STATUS_pd_cc2_stat_END (3)
#define REG_PD_CC_STATUS_pd_con_result_START (4)
#define REG_PD_CC_STATUS_pd_con_result_END (4)
#define REG_PD_CC_STATUS_pd_look4con_START (5)
#define REG_PD_CC_STATUS_pd_look4con_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_sinking_vbus : 1;
        unsigned char pd_vconn_present : 1;
        unsigned char pd_vbus_present : 1;
        unsigned char pd_vbus_pres_detect_en : 1;
        unsigned char pd_source_vbus : 1;
        unsigned char reserved : 1;
        unsigned char pd_tcpc_init_stat : 1;
        unsigned char pd_debug_acc_connect : 1;
    } reg;
} REG_PD_PWR_STATUS_UNION;
#endif
#define REG_PD_PWR_STATUS_pd_sinking_vbus_START (0)
#define REG_PD_PWR_STATUS_pd_sinking_vbus_END (0)
#define REG_PD_PWR_STATUS_pd_vconn_present_START (1)
#define REG_PD_PWR_STATUS_pd_vconn_present_END (1)
#define REG_PD_PWR_STATUS_pd_vbus_present_START (2)
#define REG_PD_PWR_STATUS_pd_vbus_present_END (2)
#define REG_PD_PWR_STATUS_pd_vbus_pres_detect_en_START (3)
#define REG_PD_PWR_STATUS_pd_vbus_pres_detect_en_END (3)
#define REG_PD_PWR_STATUS_pd_source_vbus_START (4)
#define REG_PD_PWR_STATUS_pd_source_vbus_END (4)
#define REG_PD_PWR_STATUS_pd_tcpc_init_stat_START (6)
#define REG_PD_PWR_STATUS_pd_tcpc_init_stat_END (6)
#define REG_PD_PWR_STATUS_pd_debug_acc_connect_START (7)
#define REG_PD_PWR_STATUS_pd_debug_acc_connect_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_i2c_err : 1;
        unsigned char pd_cc_fault : 1;
        unsigned char pd_vusb_ovp : 1;
        unsigned char reserved_0 : 1;
        unsigned char pd_force_disch_fail : 1;
        unsigned char pd_auto_disch_fail : 1;
        unsigned char reserved_1 : 1;
        unsigned char pd_reg_reset_default : 1;
    } reg;
} REG_PD_FAULT_STATUS_UNION;
#endif
#define REG_PD_FAULT_STATUS_pd_i2c_err_START (0)
#define REG_PD_FAULT_STATUS_pd_i2c_err_END (0)
#define REG_PD_FAULT_STATUS_pd_cc_fault_START (1)
#define REG_PD_FAULT_STATUS_pd_cc_fault_END (1)
#define REG_PD_FAULT_STATUS_pd_vusb_ovp_START (2)
#define REG_PD_FAULT_STATUS_pd_vusb_ovp_END (2)
#define REG_PD_FAULT_STATUS_pd_force_disch_fail_START (4)
#define REG_PD_FAULT_STATUS_pd_force_disch_fail_END (4)
#define REG_PD_FAULT_STATUS_pd_auto_disch_fail_START (5)
#define REG_PD_FAULT_STATUS_pd_auto_disch_fail_END (5)
#define REG_PD_FAULT_STATUS_pd_reg_reset_default_START (7)
#define REG_PD_FAULT_STATUS_pd_reg_reset_default_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_vbus_vsafe0 : 1;
        unsigned char reserved : 7;
    } reg;
} REG_EXTENDED_STATUS_UNION;
#endif
#define REG_EXTENDED_STATUS_pd_vbus_vsafe0_START (0)
#define REG_EXTENDED_STATUS_pd_vbus_vsafe0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_snk_rec_frs : 1;
        unsigned char pd_src_rec_frs : 1;
        unsigned char pd_timer_expired : 1;
        unsigned char reserved : 5;
    } reg;
} REG_ALERT_EXTENDED_UNION;
#endif
#define REG_ALERT_EXTENDED_pd_snk_rec_frs_START (0)
#define REG_ALERT_EXTENDED_pd_snk_rec_frs_END (0)
#define REG_ALERT_EXTENDED_pd_src_rec_frs_START (1)
#define REG_ALERT_EXTENDED_pd_src_rec_frs_END (1)
#define REG_ALERT_EXTENDED_pd_timer_expired_START (2)
#define REG_ALERT_EXTENDED_pd_timer_expired_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_command : 8;
    } reg;
} REG_PD_COMMAND_UNION;
#endif
#define REG_PD_COMMAND_pd_command_START (0)
#define REG_PD_COMMAND_pd_command_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dev_cap1_l : 8;
    } reg;
} REG_PD_DEVCAP1L_UNION;
#endif
#define REG_PD_DEVCAP1L_pd_dev_cap1_l_START (0)
#define REG_PD_DEVCAP1L_pd_dev_cap1_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dev_cap1_h : 8;
    } reg;
} REG_PD_DEVCAP1H_UNION;
#endif
#define REG_PD_DEVCAP1H_pd_dev_cap1_h_START (0)
#define REG_PD_DEVCAP1H_pd_dev_cap1_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dev_cap2_l : 8;
    } reg;
} REG_PD_DEVCAP2L_UNION;
#endif
#define REG_PD_DEVCAP2L_pd_dev_cap2_l_START (0)
#define REG_PD_DEVCAP2L_pd_dev_cap2_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dev_cap2_h : 8;
    } reg;
} REG_PD_DEVCAP2H_UNION;
#endif
#define REG_PD_DEVCAP2H_pd_dev_cap2_h_START (0)
#define REG_PD_DEVCAP2H_pd_dev_cap2_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_stdin_cap : 8;
    } reg;
} REG_PD_STDIN_CAP_UNION;
#endif
#define REG_PD_STDIN_CAP_pd_stdin_cap_START (0)
#define REG_PD_STDIN_CAP_pd_stdin_cap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_stdout_cap : 8;
    } reg;
} REG_PD_STDOUT_CAP_UNION;
#endif
#define REG_PD_STDOUT_CAP_pd_stdout_cap_START (0)
#define REG_PD_STDOUT_CAP_pd_stdout_cap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_msg_header : 8;
    } reg;
} REG_PD_MSG_HEADR_UNION;
#endif
#define REG_PD_MSG_HEADR_pd_msg_header_START (0)
#define REG_PD_MSG_HEADR_pd_msg_header_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_en_sop : 1;
        unsigned char pd_en_sop1 : 1;
        unsigned char pd_en_sop2 : 1;
        unsigned char pd_en_sop1_debug : 1;
        unsigned char pd_en_sop2_debug : 1;
        unsigned char pd_hard_rst : 1;
        unsigned char pd_cable_rst : 1;
        unsigned char reserved : 1;
    } reg;
} REG_PD_RXDETECT_UNION;
#endif
#define REG_PD_RXDETECT_pd_en_sop_START (0)
#define REG_PD_RXDETECT_pd_en_sop_END (0)
#define REG_PD_RXDETECT_pd_en_sop1_START (1)
#define REG_PD_RXDETECT_pd_en_sop1_END (1)
#define REG_PD_RXDETECT_pd_en_sop2_START (2)
#define REG_PD_RXDETECT_pd_en_sop2_END (2)
#define REG_PD_RXDETECT_pd_en_sop1_debug_START (3)
#define REG_PD_RXDETECT_pd_en_sop1_debug_END (3)
#define REG_PD_RXDETECT_pd_en_sop2_debug_START (4)
#define REG_PD_RXDETECT_pd_en_sop2_debug_END (4)
#define REG_PD_RXDETECT_pd_hard_rst_START (5)
#define REG_PD_RXDETECT_pd_hard_rst_END (5)
#define REG_PD_RXDETECT_pd_cable_rst_START (6)
#define REG_PD_RXDETECT_pd_cable_rst_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_rx_bytecnt : 8;
    } reg;
} REG_PD_RXBYTECNT_UNION;
#endif
#define REG_PD_RXBYTECNT_pd_rx_bytecnt_START (0)
#define REG_PD_RXBYTECNT_pd_rx_bytecnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_rx_type : 3;
        unsigned char reserved : 5;
    } reg;
} REG_PD_RXTYPE_UNION;
#endif
#define REG_PD_RXTYPE_pd_rx_type_START (0)
#define REG_PD_RXTYPE_pd_rx_type_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_rx_head_l : 8;
    } reg;
} REG_PD_RXHEADL_UNION;
#endif
#define REG_PD_RXHEADL_pd_rx_head_l_START (0)
#define REG_PD_RXHEADL_pd_rx_head_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_rx_head_h : 8;
    } reg;
} REG_PD_RXHEADH_UNION;
#endif
#define REG_PD_RXHEADH_pd_rx_head_h_START (0)
#define REG_PD_RXHEADH_pd_rx_head_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_rx_data : 8;
    } reg;
} REG_PD_RXDATA_0_UNION;
#endif
#define REG_PD_RXDATA_0_pd_rx_data_START (0)
#define REG_PD_RXDATA_0_pd_rx_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_transmit : 3;
        unsigned char reserved_0 : 1;
        unsigned char pd_retry_cnt : 2;
        unsigned char reserved_1 : 2;
    } reg;
} REG_PD_TRANSMIT_UNION;
#endif
#define REG_PD_TRANSMIT_pd_transmit_START (0)
#define REG_PD_TRANSMIT_pd_transmit_END (2)
#define REG_PD_TRANSMIT_pd_retry_cnt_START (4)
#define REG_PD_TRANSMIT_pd_retry_cnt_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_tx_bytecnt : 8;
    } reg;
} REG_PD_TXBYTECNT_UNION;
#endif
#define REG_PD_TXBYTECNT_pd_tx_bytecnt_START (0)
#define REG_PD_TXBYTECNT_pd_tx_bytecnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_tx_head_l : 8;
    } reg;
} REG_PD_TXHEADL_UNION;
#endif
#define REG_PD_TXHEADL_pd_tx_head_l_START (0)
#define REG_PD_TXHEADL_pd_tx_head_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_tx_head_h : 8;
    } reg;
} REG_PD_TXHEADH_UNION;
#endif
#define REG_PD_TXHEADH_pd_tx_head_h_START (0)
#define REG_PD_TXHEADH_pd_tx_head_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_tx_data : 8;
    } reg;
} REG_PD_TXDATA_UNION;
#endif
#define REG_PD_TXDATA_pd_tx_data_START (0)
#define REG_PD_TXDATA_pd_tx_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_vbus_vol_l : 8;
    } reg;
} REG_PD_VBUS_VOL_L_UNION;
#endif
#define REG_PD_VBUS_VOL_L_pd_vbus_vol_l_START (0)
#define REG_PD_VBUS_VOL_L_pd_vbus_vol_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_vbus_vol_h : 8;
    } reg;
} REG_PD_VBUS_VOL_H_UNION;
#endif
#define REG_PD_VBUS_VOL_H_pd_vbus_vol_h_START (0)
#define REG_PD_VBUS_VOL_H_pd_vbus_vol_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_vbus_snk_disc_l : 8;
    } reg;
} REG_PD_VBUS_SNK_DISCL_UNION;
#endif
#define REG_PD_VBUS_SNK_DISCL_pd_vbus_snk_disc_l_START (0)
#define REG_PD_VBUS_SNK_DISCL_pd_vbus_snk_disc_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_vbus_snk_disc_h : 8;
    } reg;
} REG_PD_VBUS_SNK_DISCH_UNION;
#endif
#define REG_PD_VBUS_SNK_DISCH_pd_vbus_snk_disc_h_START (0)
#define REG_PD_VBUS_SNK_DISCH_pd_vbus_snk_disc_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_vbus_stop_disc_l : 8;
    } reg;
} REG_PD_VBUS_STOP_DISCL_UNION;
#endif
#define REG_PD_VBUS_STOP_DISCL_pd_vbus_stop_disc_l_START (0)
#define REG_PD_VBUS_STOP_DISCL_pd_vbus_stop_disc_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_vbus_stop_disc_h : 8;
    } reg;
} REG_PD_VBUS_STOP_DISCH_UNION;
#endif
#define REG_PD_VBUS_STOP_DISCH_pd_vbus_stop_disc_h_START (0)
#define REG_PD_VBUS_STOP_DISCH_pd_vbus_stop_disc_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_valarm_high_l : 8;
    } reg;
} REG_PD_VALARMH_CFGL_UNION;
#endif
#define REG_PD_VALARMH_CFGL_pd_valarm_high_l_START (0)
#define REG_PD_VALARMH_CFGL_pd_valarm_high_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_valarm_high_h : 8;
    } reg;
} REG_PD_VALARMH_CFGH_UNION;
#endif
#define REG_PD_VALARMH_CFGH_pd_valarm_high_h_START (0)
#define REG_PD_VALARMH_CFGH_pd_valarm_high_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_valarm_low_l : 8;
    } reg;
} REG_PD_VALARML_CFGL_UNION;
#endif
#define REG_PD_VALARML_CFGL_pd_valarm_low_l_START (0)
#define REG_PD_VALARML_CFGL_pd_valarm_low_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_valarm_low_h : 8;
    } reg;
} REG_PD_VALARML_CFGH_UNION;
#endif
#define REG_PD_VALARML_CFGH_pd_valarm_low_h_START (0)
#define REG_PD_VALARML_CFGH_pd_valarm_low_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_frs_en : 1;
        unsigned char da_vconn_dis_en : 1;
        unsigned char pd_drp_thres : 2;
        unsigned char pd_try_snk_en : 1;
        unsigned char da_force_unplug_en : 1;
        unsigned char pd_bmc_cdr_sel : 1;
        unsigned char pd_cc_orient_sel : 1;
    } reg;
} REG_PD_VDM_CFG_0_UNION;
#endif
#define REG_PD_VDM_CFG_0_da_frs_en_START (0)
#define REG_PD_VDM_CFG_0_da_frs_en_END (0)
#define REG_PD_VDM_CFG_0_da_vconn_dis_en_START (1)
#define REG_PD_VDM_CFG_0_da_vconn_dis_en_END (1)
#define REG_PD_VDM_CFG_0_pd_drp_thres_START (2)
#define REG_PD_VDM_CFG_0_pd_drp_thres_END (3)
#define REG_PD_VDM_CFG_0_pd_try_snk_en_START (4)
#define REG_PD_VDM_CFG_0_pd_try_snk_en_END (4)
#define REG_PD_VDM_CFG_0_da_force_unplug_en_START (5)
#define REG_PD_VDM_CFG_0_da_force_unplug_en_END (5)
#define REG_PD_VDM_CFG_0_pd_bmc_cdr_sel_START (6)
#define REG_PD_VDM_CFG_0_pd_bmc_cdr_sel_END (6)
#define REG_PD_VDM_CFG_0_pd_cc_orient_sel_START (7)
#define REG_PD_VDM_CFG_0_pd_cc_orient_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char enable_pd : 1;
        unsigned char reserved : 7;
    } reg;
} REG_PD_VDM_ENABLE_UNION;
#endif
#define REG_PD_VDM_ENABLE_enable_pd_START (0)
#define REG_PD_VDM_ENABLE_enable_pd_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char tc_fsm_reset : 1;
        unsigned char pd_fsm_reset : 1;
        unsigned char pd_tx_phy_soft_reset : 1;
        unsigned char pd_rx_phy_soft_reset : 1;
        unsigned char pd_snk_disc_by_cc : 1;
        unsigned char da_new_vconn_dis_en : 1;
        unsigned char reserved : 2;
    } reg;
} REG_PD_VDM_CFG_1_UNION;
#endif
#define REG_PD_VDM_CFG_1_tc_fsm_reset_START (0)
#define REG_PD_VDM_CFG_1_tc_fsm_reset_END (0)
#define REG_PD_VDM_CFG_1_pd_fsm_reset_START (1)
#define REG_PD_VDM_CFG_1_pd_fsm_reset_END (1)
#define REG_PD_VDM_CFG_1_pd_tx_phy_soft_reset_START (2)
#define REG_PD_VDM_CFG_1_pd_tx_phy_soft_reset_END (2)
#define REG_PD_VDM_CFG_1_pd_rx_phy_soft_reset_START (3)
#define REG_PD_VDM_CFG_1_pd_rx_phy_soft_reset_END (3)
#define REG_PD_VDM_CFG_1_pd_snk_disc_by_cc_START (4)
#define REG_PD_VDM_CFG_1_pd_snk_disc_by_cc_END (4)
#define REG_PD_VDM_CFG_1_da_new_vconn_dis_en_START (5)
#define REG_PD_VDM_CFG_1_da_new_vconn_dis_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dbg_rdata_sel : 4;
        unsigned char pd_dbg_module_sel : 3;
        unsigned char pd_dbg_rdata_en : 1;
    } reg;
} REG_PD_DBG_RDATA_CFG_UNION;
#endif
#define REG_PD_DBG_RDATA_CFG_pd_dbg_rdata_sel_START (0)
#define REG_PD_DBG_RDATA_CFG_pd_dbg_rdata_sel_END (3)
#define REG_PD_DBG_RDATA_CFG_pd_dbg_module_sel_START (4)
#define REG_PD_DBG_RDATA_CFG_pd_dbg_module_sel_END (6)
#define REG_PD_DBG_RDATA_CFG_pd_dbg_rdata_en_START (7)
#define REG_PD_DBG_RDATA_CFG_pd_dbg_rdata_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dbg_rdata : 8;
    } reg;
} REG_PD_DBG_RDATA_UNION;
#endif
#define REG_PD_DBG_RDATA_pd_dbg_rdata_START (0)
#define REG_PD_DBG_RDATA_pd_dbg_rdata_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char attach : 1;
        unsigned char reserved : 5;
        unsigned char dvc : 2;
    } reg;
} REG_STATUIS_UNION;
#endif
#define REG_STATUIS_attach_START (0)
#define REG_STATUIS_attach_END (0)
#define REG_STATUIS_dvc_START (6)
#define REG_STATUIS_dvc_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sndcmd : 1;
        unsigned char reserved_0: 1;
        unsigned char mstr_rst : 1;
        unsigned char enable : 1;
        unsigned char reserved_1: 4;
    } reg;
} REG_CNTL_UNION;
#endif
#define REG_CNTL_sndcmd_START (0)
#define REG_CNTL_sndcmd_END (0)
#define REG_CNTL_mstr_rst_START (2)
#define REG_CNTL_mstr_rst_END (2)
#define REG_CNTL_enable_START (3)
#define REG_CNTL_enable_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cmd : 8;
    } reg;
} REG_CMD_UNION;
#endif
#define REG_CMD_cmd_START (0)
#define REG_CMD_cmd_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_length : 4;
        unsigned char reserved : 4;
    } reg;
} REG_FCP_LENGTH_UNION;
#endif
#define REG_FCP_LENGTH_fcp_length_START (0)
#define REG_FCP_LENGTH_fcp_length_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char addr : 8;
    } reg;
} REG_ADDR_UNION;
#endif
#define REG_ADDR_addr_START (0)
#define REG_ADDR_addr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data0 : 8;
    } reg;
} REG_DATA0_UNION;
#endif
#define REG_DATA0_data0_START (0)
#define REG_DATA0_data0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data1 : 8;
    } reg;
} REG_DATA1_UNION;
#endif
#define REG_DATA1_data1_START (0)
#define REG_DATA1_data1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data2 : 8;
    } reg;
} REG_DATA2_UNION;
#endif
#define REG_DATA2_data2_START (0)
#define REG_DATA2_data2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data3 : 8;
    } reg;
} REG_DATA3_UNION;
#endif
#define REG_DATA3_data3_START (0)
#define REG_DATA3_data3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data4 : 8;
    } reg;
} REG_DATA4_UNION;
#endif
#define REG_DATA4_data4_START (0)
#define REG_DATA4_data4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data5 : 8;
    } reg;
} REG_DATA5_UNION;
#endif
#define REG_DATA5_data5_START (0)
#define REG_DATA5_data5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data6 : 8;
    } reg;
} REG_DATA6_UNION;
#endif
#define REG_DATA6_data6_START (0)
#define REG_DATA6_data6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data7 : 8;
    } reg;
} REG_DATA7_UNION;
#endif
#define REG_DATA7_data7_START (0)
#define REG_DATA7_data7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_rdata0 : 8;
    } reg;
} REG_FCP_RDATA0_UNION;
#endif
#define REG_FCP_RDATA0_fcp_rdata0_START (0)
#define REG_FCP_RDATA0_fcp_rdata0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_rdata1 : 8;
    } reg;
} REG_FCP_RDATA1_UNION;
#endif
#define REG_FCP_RDATA1_fcp_rdata1_START (0)
#define REG_FCP_RDATA1_fcp_rdata1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_rdata2 : 8;
    } reg;
} REG_FCP_RDATA2_UNION;
#endif
#define REG_FCP_RDATA2_fcp_rdata2_START (0)
#define REG_FCP_RDATA2_fcp_rdata2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_rdata3 : 8;
    } reg;
} REG_FCP_RDATA3_UNION;
#endif
#define REG_FCP_RDATA3_fcp_rdata3_START (0)
#define REG_FCP_RDATA3_fcp_rdata3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_rdata4 : 8;
    } reg;
} REG_FCP_RDATA4_UNION;
#endif
#define REG_FCP_RDATA4_fcp_rdata4_START (0)
#define REG_FCP_RDATA4_fcp_rdata4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_rdata5 : 8;
    } reg;
} REG_FCP_RDATA5_UNION;
#endif
#define REG_FCP_RDATA5_fcp_rdata5_START (0)
#define REG_FCP_RDATA5_fcp_rdata5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_rdata6 : 8;
    } reg;
} REG_FCP_RDATA6_UNION;
#endif
#define REG_FCP_RDATA6_fcp_rdata6_START (0)
#define REG_FCP_RDATA6_fcp_rdata6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_rdata7 : 8;
    } reg;
} REG_FCP_RDATA7_UNION;
#endif
#define REG_FCP_RDATA7_fcp_rdata7_START (0)
#define REG_FCP_RDATA7_fcp_rdata7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 1;
        unsigned char nack_alarm : 1;
        unsigned char ack_alarm : 1;
        unsigned char crcpar : 1;
        unsigned char nack : 1;
        unsigned char reserved_1 : 1;
        unsigned char ack : 1;
        unsigned char cmdcpl : 1;
    } reg;
} REG_ISR1_UNION;
#endif
#define REG_ISR1_nack_alarm_START (1)
#define REG_ISR1_nack_alarm_END (1)
#define REG_ISR1_ack_alarm_START (2)
#define REG_ISR1_ack_alarm_END (2)
#define REG_ISR1_crcpar_START (3)
#define REG_ISR1_crcpar_END (3)
#define REG_ISR1_nack_START (4)
#define REG_ISR1_nack_END (4)
#define REG_ISR1_ack_START (6)
#define REG_ISR1_ack_END (6)
#define REG_ISR1_cmdcpl_START (7)
#define REG_ISR1_cmdcpl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0: 1;
        unsigned char protstat : 1;
        unsigned char reserved_1: 1;
        unsigned char parrx : 1;
        unsigned char crcrx : 1;
        unsigned char reserved_2: 3;
    } reg;
} REG_ISR2_UNION;
#endif
#define REG_ISR2_protstat_START (1)
#define REG_ISR2_protstat_END (1)
#define REG_ISR2_parrx_START (3)
#define REG_ISR2_parrx_END (3)
#define REG_ISR2_crcrx_START (4)
#define REG_ISR2_crcrx_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 1;
        unsigned char nack_alarm_mk : 1;
        unsigned char ack_alarm_mk : 1;
        unsigned char crcpar_mk : 1;
        unsigned char nack_mk : 1;
        unsigned char reserved_1 : 1;
        unsigned char ack_mk : 1;
        unsigned char cmdcpl_mk : 1;
    } reg;
} REG_IMR1_UNION;
#endif
#define REG_IMR1_nack_alarm_mk_START (1)
#define REG_IMR1_nack_alarm_mk_END (1)
#define REG_IMR1_ack_alarm_mk_START (2)
#define REG_IMR1_ack_alarm_mk_END (2)
#define REG_IMR1_crcpar_mk_START (3)
#define REG_IMR1_crcpar_mk_END (3)
#define REG_IMR1_nack_mk_START (4)
#define REG_IMR1_nack_mk_END (4)
#define REG_IMR1_ack_mk_START (6)
#define REG_IMR1_ack_mk_END (6)
#define REG_IMR1_cmdcpl_mk_START (7)
#define REG_IMR1_cmdcpl_mk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 1;
        unsigned char protstat_mk : 1;
        unsigned char reserved_1 : 1;
        unsigned char parrx_mk : 1;
        unsigned char crcrx_mk : 1;
        unsigned char reserved_2 : 3;
    } reg;
} REG_IMR2_UNION;
#endif
#define REG_IMR2_protstat_mk_START (1)
#define REG_IMR2_protstat_mk_END (1)
#define REG_IMR2_parrx_mk_START (3)
#define REG_IMR2_parrx_mk_END (3)
#define REG_IMR2_crcrx_mk_START (4)
#define REG_IMR2_crcrx_mk_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_set_d60m_int : 1;
        unsigned char fcp_en_det_int : 1;
        unsigned char reserved : 6;
    } reg;
} REG_FCP_IRQ5_UNION;
#endif
#define REG_FCP_IRQ5_fcp_set_d60m_int_START (0)
#define REG_FCP_IRQ5_fcp_set_d60m_int_END (0)
#define REG_FCP_IRQ5_fcp_en_det_int_START (1)
#define REG_FCP_IRQ5_fcp_en_det_int_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_set_d60m_r_mk : 1;
        unsigned char fcp_en_det_int_mk : 1;
        unsigned char reserved : 6;
    } reg;
} REG_FCP_IRQ5_MASK_UNION;
#endif
#define REG_FCP_IRQ5_MASK_fcp_set_d60m_r_mk_START (0)
#define REG_FCP_IRQ5_MASK_fcp_set_d60m_r_mk_END (0)
#define REG_FCP_IRQ5_MASK_fcp_en_det_int_mk_START (1)
#define REG_FCP_IRQ5_MASK_fcp_en_det_int_mk_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_clk_test : 1;
        unsigned char fcp_mode : 1;
        unsigned char fcp_cmp_en : 1;
        unsigned char fcp_det_en : 1;
        unsigned char reserved : 4;
    } reg;
} REG_FCP_CTRL_UNION;
#endif
#define REG_FCP_CTRL_fcp_clk_test_START (0)
#define REG_FCP_CTRL_fcp_clk_test_END (0)
#define REG_FCP_CTRL_fcp_mode_START (1)
#define REG_FCP_CTRL_fcp_mode_END (1)
#define REG_FCP_CTRL_fcp_cmp_en_START (2)
#define REG_FCP_CTRL_fcp_cmp_en_END (2)
#define REG_FCP_CTRL_fcp_det_en_START (3)
#define REG_FCP_CTRL_fcp_det_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_mod2_set : 2;
        unsigned char reserved : 6;
    } reg;
} REG_FCP_MODE2_SET_UNION;
#endif
#define REG_FCP_MODE2_SET_fcp_mod2_set_START (0)
#define REG_FCP_MODE2_SET_fcp_mod2_set_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_set_d60m_r : 1;
        unsigned char reserved : 7;
    } reg;
} REG_FCP_ADAP_CTRL_UNION;
#endif
#define REG_FCP_ADAP_CTRL_fcp_set_d60m_r_START (0)
#define REG_FCP_ADAP_CTRL_fcp_set_d60m_r_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_rdata_ready : 1;
        unsigned char reserved : 7;
    } reg;
} REG_RDATA_READY_UNION;
#endif
#define REG_RDATA_READY_fcp_rdata_ready_START (0)
#define REG_RDATA_READY_fcp_rdata_ready_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_soft_rst_cfg : 8;
    } reg;
} REG_FCP_SOFT_RST_CTRL_UNION;
#endif
#define REG_FCP_SOFT_RST_CTRL_fcp_soft_rst_cfg_START (0)
#define REG_FCP_SOFT_RST_CTRL_fcp_soft_rst_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rdata_parity_err0 : 1;
        unsigned char rdata_parity_err1 : 1;
        unsigned char rdata_parity_err2 : 1;
        unsigned char rdata_parity_err3 : 1;
        unsigned char rdata_parity_err4 : 1;
        unsigned char rdata_parity_err5 : 1;
        unsigned char rdata_parity_err6 : 1;
        unsigned char rdata_parity_err7 : 1;
    } reg;
} REG_FCP_RDATA_PARITY_ERR_UNION;
#endif
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err0_START (0)
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err0_END (0)
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err1_START (1)
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err1_END (1)
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err2_START (2)
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err2_END (2)
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err3_START (3)
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err3_END (3)
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err4_START (4)
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err4_END (4)
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err5_START (5)
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err5_END (5)
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err6_START (6)
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err6_END (6)
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err7_START (7)
#define REG_FCP_RDATA_PARITY_ERR_rdata_parity_err7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_init_retry_cfg : 5;
        unsigned char reserved : 3;
    } reg;
} REG_FCP_INIT_RETRY_CFG_UNION;
#endif
#define REG_FCP_INIT_RETRY_CFG_fcp_init_retry_cfg_START (0)
#define REG_FCP_INIT_RETRY_CFG_fcp_init_retry_cfg_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char last_hand_fail_irq : 1;
        unsigned char tail_hand_fail_irq : 1;
        unsigned char trans_hand_fail_irq : 1;
        unsigned char init_hand_fail_irq : 1;
        unsigned char rx_data_det_irq : 1;
        unsigned char rx_head_det_irq : 1;
        unsigned char cmd_err_irq : 1;
        unsigned char length_err_irq : 1;
    } reg;
} REG_FCP_IRQ3_UNION;
#endif
#define REG_FCP_IRQ3_last_hand_fail_irq_START (0)
#define REG_FCP_IRQ3_last_hand_fail_irq_END (0)
#define REG_FCP_IRQ3_tail_hand_fail_irq_START (1)
#define REG_FCP_IRQ3_tail_hand_fail_irq_END (1)
#define REG_FCP_IRQ3_trans_hand_fail_irq_START (2)
#define REG_FCP_IRQ3_trans_hand_fail_irq_END (2)
#define REG_FCP_IRQ3_init_hand_fail_irq_START (3)
#define REG_FCP_IRQ3_init_hand_fail_irq_END (3)
#define REG_FCP_IRQ3_rx_data_det_irq_START (4)
#define REG_FCP_IRQ3_rx_data_det_irq_END (4)
#define REG_FCP_IRQ3_rx_head_det_irq_START (5)
#define REG_FCP_IRQ3_rx_head_det_irq_END (5)
#define REG_FCP_IRQ3_cmd_err_irq_START (6)
#define REG_FCP_IRQ3_cmd_err_irq_END (6)
#define REG_FCP_IRQ3_length_err_irq_START (7)
#define REG_FCP_IRQ3_length_err_irq_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char last_hand_no_respond_irq : 1;
        unsigned char tail_hand_no_respond_irq : 1;
        unsigned char trans_hand_no_respond_irq : 1;
        unsigned char init_hand_no_respond_irq : 1;
        unsigned char enable_hand_fail_irq : 1;
        unsigned char enable_hand_no_respond_irq : 1;
        unsigned char reserved : 2;
    } reg;
} REG_FCP_IRQ4_UNION;
#endif
#define REG_FCP_IRQ4_last_hand_no_respond_irq_START (0)
#define REG_FCP_IRQ4_last_hand_no_respond_irq_END (0)
#define REG_FCP_IRQ4_tail_hand_no_respond_irq_START (1)
#define REG_FCP_IRQ4_tail_hand_no_respond_irq_END (1)
#define REG_FCP_IRQ4_trans_hand_no_respond_irq_START (2)
#define REG_FCP_IRQ4_trans_hand_no_respond_irq_END (2)
#define REG_FCP_IRQ4_init_hand_no_respond_irq_START (3)
#define REG_FCP_IRQ4_init_hand_no_respond_irq_END (3)
#define REG_FCP_IRQ4_enable_hand_fail_irq_START (4)
#define REG_FCP_IRQ4_enable_hand_fail_irq_END (4)
#define REG_FCP_IRQ4_enable_hand_no_respond_irq_START (5)
#define REG_FCP_IRQ4_enable_hand_no_respond_irq_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char last_hand_fail_irq_mk : 1;
        unsigned char tail_hand_fail_irq_mk : 1;
        unsigned char trans_hand_fail_irq_mk : 1;
        unsigned char init_hand_fail_irq_mk : 1;
        unsigned char rx_data_det_irq_mk : 1;
        unsigned char rx_head_det_irq_mk : 1;
        unsigned char cmd_err_irq_mk : 1;
        unsigned char length_err_irq_mk : 1;
    } reg;
} REG_FCP_IRQ3_MASK_UNION;
#endif
#define REG_FCP_IRQ3_MASK_last_hand_fail_irq_mk_START (0)
#define REG_FCP_IRQ3_MASK_last_hand_fail_irq_mk_END (0)
#define REG_FCP_IRQ3_MASK_tail_hand_fail_irq_mk_START (1)
#define REG_FCP_IRQ3_MASK_tail_hand_fail_irq_mk_END (1)
#define REG_FCP_IRQ3_MASK_trans_hand_fail_irq_mk_START (2)
#define REG_FCP_IRQ3_MASK_trans_hand_fail_irq_mk_END (2)
#define REG_FCP_IRQ3_MASK_init_hand_fail_irq_mk_START (3)
#define REG_FCP_IRQ3_MASK_init_hand_fail_irq_mk_END (3)
#define REG_FCP_IRQ3_MASK_rx_data_det_irq_mk_START (4)
#define REG_FCP_IRQ3_MASK_rx_data_det_irq_mk_END (4)
#define REG_FCP_IRQ3_MASK_rx_head_det_irq_mk_START (5)
#define REG_FCP_IRQ3_MASK_rx_head_det_irq_mk_END (5)
#define REG_FCP_IRQ3_MASK_cmd_err_irq_mk_START (6)
#define REG_FCP_IRQ3_MASK_cmd_err_irq_mk_END (6)
#define REG_FCP_IRQ3_MASK_length_err_irq_mk_START (7)
#define REG_FCP_IRQ3_MASK_length_err_irq_mk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char last_hand_no_respond_irq_mk : 1;
        unsigned char tail_hand_no_respond_irq_mk : 1;
        unsigned char trans_hand_no_respond_irq_mk : 1;
        unsigned char init_hand_no_respond_irq_mk : 1;
        unsigned char enable_hand_fail_irq_mk : 1;
        unsigned char enable_hand_no_respond_irq_mk : 1;
        unsigned char reserved : 2;
    } reg;
} REG_FCP_IRQ4_MASK_UNION;
#endif
#define REG_FCP_IRQ4_MASK_last_hand_no_respond_irq_mk_START (0)
#define REG_FCP_IRQ4_MASK_last_hand_no_respond_irq_mk_END (0)
#define REG_FCP_IRQ4_MASK_tail_hand_no_respond_irq_mk_START (1)
#define REG_FCP_IRQ4_MASK_tail_hand_no_respond_irq_mk_END (1)
#define REG_FCP_IRQ4_MASK_trans_hand_no_respond_irq_mk_START (2)
#define REG_FCP_IRQ4_MASK_trans_hand_no_respond_irq_mk_END (2)
#define REG_FCP_IRQ4_MASK_init_hand_no_respond_irq_mk_START (3)
#define REG_FCP_IRQ4_MASK_init_hand_no_respond_irq_mk_END (3)
#define REG_FCP_IRQ4_MASK_enable_hand_fail_irq_mk_START (4)
#define REG_FCP_IRQ4_MASK_enable_hand_fail_irq_mk_END (4)
#define REG_FCP_IRQ4_MASK_enable_hand_no_respond_irq_mk_START (5)
#define REG_FCP_IRQ4_MASK_enable_hand_no_respond_irq_mk_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char mstate : 4;
        unsigned char reserved : 4;
    } reg;
} REG_MSTATE_UNION;
#endif
#define REG_MSTATE_mstate_START (0)
#define REG_MSTATE_mstate_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char crc_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_CRC_ENABLE_UNION;
#endif
#define REG_CRC_ENABLE_crc_en_START (0)
#define REG_CRC_ENABLE_crc_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char crc_start_val : 8;
    } reg;
} REG_CRC_START_VALUE_UNION;
#endif
#define REG_CRC_START_VALUE_crc_start_val_START (0)
#define REG_CRC_START_VALUE_crc_start_val_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sample_cnt_adjust : 5;
        unsigned char reserved : 3;
    } reg;
} REG_SAMPLE_CNT_ADJ_UNION;
#endif
#define REG_SAMPLE_CNT_ADJ_sample_cnt_adjust_START (0)
#define REG_SAMPLE_CNT_ADJ_sample_cnt_adjust_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rx_ping_width_min_h : 1;
        unsigned char reserved : 7;
    } reg;
} REG_RX_PING_WIDTH_MIN_H_UNION;
#endif
#define REG_RX_PING_WIDTH_MIN_H_rx_ping_width_min_h_START (0)
#define REG_RX_PING_WIDTH_MIN_H_rx_ping_width_min_h_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rx_ping_width_min_l : 8;
    } reg;
} REG_RX_PING_WIDTH_MIN_L_UNION;
#endif
#define REG_RX_PING_WIDTH_MIN_L_rx_ping_width_min_l_START (0)
#define REG_RX_PING_WIDTH_MIN_L_rx_ping_width_min_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rx_ping_width_max_h : 1;
        unsigned char reserved : 7;
    } reg;
} REG_RX_PING_WIDTH_MAX_H_UNION;
#endif
#define REG_RX_PING_WIDTH_MAX_H_rx_ping_width_max_h_START (0)
#define REG_RX_PING_WIDTH_MAX_H_rx_ping_width_max_h_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rx_ping_width_max_l : 8;
    } reg;
} REG_RX_PING_WIDTH_MAX_L_UNION;
#endif
#define REG_RX_PING_WIDTH_MAX_L_rx_ping_width_max_l_START (0)
#define REG_RX_PING_WIDTH_MAX_L_rx_ping_width_max_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data_wait_time : 7;
        unsigned char reserved : 1;
    } reg;
} REG_DATA_WAIT_TIME_UNION;
#endif
#define REG_DATA_WAIT_TIME_data_wait_time_START (0)
#define REG_DATA_WAIT_TIME_data_wait_time_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cmd_retry_config : 4;
        unsigned char reserved : 4;
    } reg;
} REG_RETRY_CNT_UNION;
#endif
#define REG_RETRY_CNT_cmd_retry_config_START (0)
#define REG_RETRY_CNT_cmd_retry_config_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fcp_ro_reserve : 8;
    } reg;
} REG_FCP_RO_RESERVE_UNION;
#endif
#define REG_FCP_RO_RESERVE_fcp_ro_reserve_START (0)
#define REG_FCP_RO_RESERVE_fcp_ro_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slv_crc_err : 1;
        unsigned char resp_ack_parity_err : 1;
        unsigned char fcp_head_early_err : 1;
        unsigned char slv_crc_parity_err : 1;
        unsigned char rdata_range_err : 1;
        unsigned char reserved : 3;
    } reg;
} REG_FCP_DEBUG_REG0_UNION;
#endif
#define REG_FCP_DEBUG_REG0_slv_crc_err_START (0)
#define REG_FCP_DEBUG_REG0_slv_crc_err_END (0)
#define REG_FCP_DEBUG_REG0_resp_ack_parity_err_START (1)
#define REG_FCP_DEBUG_REG0_resp_ack_parity_err_END (1)
#define REG_FCP_DEBUG_REG0_fcp_head_early_err_START (2)
#define REG_FCP_DEBUG_REG0_fcp_head_early_err_END (2)
#define REG_FCP_DEBUG_REG0_slv_crc_parity_err_START (3)
#define REG_FCP_DEBUG_REG0_slv_crc_parity_err_END (3)
#define REG_FCP_DEBUG_REG0_rdata_range_err_START (4)
#define REG_FCP_DEBUG_REG0_rdata_range_err_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char resp_ack : 8;
    } reg;
} REG_FCP_DEBUG_REG1_UNION;
#endif
#define REG_FCP_DEBUG_REG1_resp_ack_START (0)
#define REG_FCP_DEBUG_REG1_resp_ack_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slv_crc : 8;
    } reg;
} REG_FCP_DEBUG_REG2_UNION;
#endif
#define REG_FCP_DEBUG_REG2_slv_crc_START (0)
#define REG_FCP_DEBUG_REG2_slv_crc_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rx_ping_cnt_l : 8;
    } reg;
} REG_FCP_DEBUG_REG3_UNION;
#endif
#define REG_FCP_DEBUG_REG3_rx_ping_cnt_l_START (0)
#define REG_FCP_DEBUG_REG3_rx_ping_cnt_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 2;
        unsigned char rx_ping_low_cnt : 5;
        unsigned char rx_ping_cnt_h : 1;
    } reg;
} REG_FCP_DEBUG_REG4_UNION;
#endif
#define REG_FCP_DEBUG_REG4_rx_ping_low_cnt_START (2)
#define REG_FCP_DEBUG_REG4_rx_ping_low_cnt_END (6)
#define REG_FCP_DEBUG_REG4_rx_ping_cnt_h_START (7)
#define REG_FCP_DEBUG_REG4_rx_ping_cnt_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rx_packet_wait_adjust : 7;
        unsigned char reserved : 1;
    } reg;
} REG_RX_PACKET_WAIT_ADJUST_UNION;
#endif
#define REG_RX_PACKET_WAIT_ADJUST_rx_packet_wait_adjust_START (0)
#define REG_RX_PACKET_WAIT_ADJUST_rx_packet_wait_adjust_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sample_cnt_tinyjust : 5;
        unsigned char reserved : 3;
    } reg;
} REG_SAMPLE_CNT_TINYJUST_UNION;
#endif
#define REG_SAMPLE_CNT_TINYJUST_sample_cnt_tinyjust_START (0)
#define REG_SAMPLE_CNT_TINYJUST_sample_cnt_tinyjust_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rx_ping_cnt_tinyjust : 5;
        unsigned char reserved : 3;
    } reg;
} REG_RX_PING_CNT_TINYJUST_UNION;
#endif
#define REG_RX_PING_CNT_TINYJUST_rx_ping_cnt_tinyjust_START (0)
#define REG_RX_PING_CNT_TINYJUST_rx_ping_cnt_tinyjust_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char shift_cnt_cfg_max : 4;
        unsigned char reserved : 4;
    } reg;
} REG_SHIFT_CNT_CFG_MAX_UNION;
#endif
#define REG_SHIFT_CNT_CFG_MAX_shift_cnt_cfg_max_START (0)
#define REG_SHIFT_CNT_CFG_MAX_shift_cnt_cfg_max_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_cdr_cfg_0 : 8;
    } reg;
} REG_PD_CDR_CFG_0_UNION;
#endif
#define REG_PD_CDR_CFG_0_pd_cdr_cfg_0_START (0)
#define REG_PD_CDR_CFG_0_pd_cdr_cfg_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_cdr_cfg_1 : 8;
    } reg;
} REG_PD_CDR_CFG_1_UNION;
#endif
#define REG_PD_CDR_CFG_1_pd_cdr_cfg_1_START (0)
#define REG_PD_CDR_CFG_1_pd_cdr_cfg_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dbg_cfg_0 : 8;
    } reg;
} REG_PD_DBG_CFG_0_UNION;
#endif
#define REG_PD_DBG_CFG_0_pd_dbg_cfg_0_START (0)
#define REG_PD_DBG_CFG_0_pd_dbg_cfg_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dbg_cfg_1 : 8;
    } reg;
} REG_PD_DBG_CFG_1_UNION;
#endif
#define REG_PD_DBG_CFG_1_pd_dbg_cfg_1_START (0)
#define REG_PD_DBG_CFG_1_pd_dbg_cfg_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dbg_cfg_2 : 8;
    } reg;
} REG_PD_DBG_CFG_2_UNION;
#endif
#define REG_PD_DBG_CFG_2_pd_dbg_cfg_2_START (0)
#define REG_PD_DBG_CFG_2_pd_dbg_cfg_2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dbg_cfg_3 : 8;
    } reg;
} REG_PD_DBG_CFG_3_UNION;
#endif
#define REG_PD_DBG_CFG_3_pd_dbg_cfg_3_START (0)
#define REG_PD_DBG_CFG_3_pd_dbg_cfg_3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dbg_status_0 : 8;
    } reg;
} REG_PD_DBG_RO_0_UNION;
#endif
#define REG_PD_DBG_RO_0_pd_dbg_status_0_START (0)
#define REG_PD_DBG_RO_0_pd_dbg_status_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dbg_status_1 : 8;
    } reg;
} REG_PD_DBG_RO_1_UNION;
#endif
#define REG_PD_DBG_RO_1_pd_dbg_status_1_START (0)
#define REG_PD_DBG_RO_1_pd_dbg_status_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dbg_status_2 : 8;
    } reg;
} REG_PD_DBG_RO_2_UNION;
#endif
#define REG_PD_DBG_RO_2_pd_dbg_status_2_START (0)
#define REG_PD_DBG_RO_2_pd_dbg_status_2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_dbg_status_3 : 8;
    } reg;
} REG_PD_DBG_RO_3_UNION;
#endif
#define REG_PD_DBG_RO_3_pd_dbg_status_3_START (0)
#define REG_PD_DBG_RO_3_pd_dbg_status_3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_ext_otg_sel : 1;
        unsigned char reserved : 7;
    } reg;
} REG_PD_EXT_OTG_SEL_UNION;
#endif
#define REG_PD_EXT_OTG_SEL_pd_ext_otg_sel_START (0)
#define REG_PD_EXT_OTG_SEL_pd_ext_otg_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_ext_otg_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_PD_EXT_OTG_EN_UNION;
#endif
#define REG_PD_EXT_OTG_EN_pd_ext_otg_en_START (0)
#define REG_PD_EXT_OTG_EN_pd_ext_otg_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_ext_ovp_sel : 1;
        unsigned char reserved : 7;
    } reg;
} REG_PD_EXT_OVP_SEL_UNION;
#endif
#define REG_PD_EXT_OVP_SEL_pd_ext_ovp_sel_START (0)
#define REG_PD_EXT_OVP_SEL_pd_ext_ovp_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_ext_ovp_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_PD_EXT_OVP_EN_UNION;
#endif
#define REG_PD_EXT_OVP_EN_pd_ext_ovp_en_START (0)
#define REG_PD_EXT_OVP_EN_pd_ext_ovp_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_hkadc_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_HKADC_EN_UNION;
#endif
#define REG_HKADC_EN_sc_hkadc_en_START (0)
#define REG_HKADC_EN_sc_hkadc_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_hkadc_start : 1;
        unsigned char reserved : 7;
    } reg;
} REG_HKADC_START_UNION;
#endif
#define REG_HKADC_START_sc_hkadc_start_START (0)
#define REG_HKADC_START_sc_hkadc_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_hkadc_avg_times : 2;
        unsigned char reserved_0 : 2;
        unsigned char sc_hkadc_seq_loop : 1;
        unsigned char sc_hkadc_cul_time : 1;
        unsigned char sc_hkadc_chopper_time : 1;
        unsigned char reserved_1 : 1;
    } reg;
} REG_HKADC_CTRL1_UNION;
#endif
#define REG_HKADC_CTRL1_sc_hkadc_avg_times_START (0)
#define REG_HKADC_CTRL1_sc_hkadc_avg_times_END (1)
#define REG_HKADC_CTRL1_sc_hkadc_seq_loop_START (4)
#define REG_HKADC_CTRL1_sc_hkadc_seq_loop_END (4)
#define REG_HKADC_CTRL1_sc_hkadc_cul_time_START (5)
#define REG_HKADC_CTRL1_sc_hkadc_cul_time_END (5)
#define REG_HKADC_CTRL1_sc_hkadc_chopper_time_START (6)
#define REG_HKADC_CTRL1_sc_hkadc_chopper_time_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_hkadc_seq_chanel_h : 8;
    } reg;
} REG_HKADC_SEQ_CH_H_UNION;
#endif
#define REG_HKADC_SEQ_CH_H_sc_hkadc_seq_chanel_h_START (0)
#define REG_HKADC_SEQ_CH_H_sc_hkadc_seq_chanel_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_hkadc_seq_chanel_l : 8;
    } reg;
} REG_HKADC_SEQ_CH_L_UNION;
#endif
#define REG_HKADC_SEQ_CH_L_sc_hkadc_seq_chanel_l_START (0)
#define REG_HKADC_SEQ_CH_L_sc_hkadc_seq_chanel_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_hkadc_rd_req : 1;
        unsigned char reserved : 7;
    } reg;
} REG_HKADC_RD_SEQ_UNION;
#endif
#define REG_HKADC_RD_SEQ_sc_hkadc_rd_req_START (0)
#define REG_HKADC_RD_SEQ_sc_hkadc_rd_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char hkadc_data_valid : 1;
        unsigned char reserved : 7;
    } reg;
} REG_HKADC_DATA_VALID_UNION;
#endif
#define REG_HKADC_DATA_VALID_hkadc_data_valid_START (0)
#define REG_HKADC_DATA_VALID_hkadc_data_valid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch0_adc_out_l : 8;
    } reg;
} REG_CH0_ADC_L_UNION;
#endif
#define REG_CH0_ADC_L_ch0_adc_out_l_START (0)
#define REG_CH0_ADC_L_ch0_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch0_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH0_ADC_H_UNION;
#endif
#define REG_CH0_ADC_H_ch0_adc_out_h_START (0)
#define REG_CH0_ADC_H_ch0_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch1_adc_out_l : 8;
    } reg;
} REG_CH1_ADC_L_UNION;
#endif
#define REG_CH1_ADC_L_ch1_adc_out_l_START (0)
#define REG_CH1_ADC_L_ch1_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch1_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH1_ADC_H_UNION;
#endif
#define REG_CH1_ADC_H_ch1_adc_out_h_START (0)
#define REG_CH1_ADC_H_ch1_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch2_adc_out_l : 8;
    } reg;
} REG_CH2_ADC_L_UNION;
#endif
#define REG_CH2_ADC_L_ch2_adc_out_l_START (0)
#define REG_CH2_ADC_L_ch2_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch2_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH2_ADC_H_UNION;
#endif
#define REG_CH2_ADC_H_ch2_adc_out_h_START (0)
#define REG_CH2_ADC_H_ch2_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch3_adc_out_l : 8;
    } reg;
} REG_CH3_ADC_L_UNION;
#endif
#define REG_CH3_ADC_L_ch3_adc_out_l_START (0)
#define REG_CH3_ADC_L_ch3_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch3_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH3_ADC_H_UNION;
#endif
#define REG_CH3_ADC_H_ch3_adc_out_h_START (0)
#define REG_CH3_ADC_H_ch3_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch4_adc_out_l : 8;
    } reg;
} REG_CH4_ADC_L_UNION;
#endif
#define REG_CH4_ADC_L_ch4_adc_out_l_START (0)
#define REG_CH4_ADC_L_ch4_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch4_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH4_ADC_H_UNION;
#endif
#define REG_CH4_ADC_H_ch4_adc_out_h_START (0)
#define REG_CH4_ADC_H_ch4_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch5_adc_out_l : 8;
    } reg;
} REG_CH5_ADC_L_UNION;
#endif
#define REG_CH5_ADC_L_ch5_adc_out_l_START (0)
#define REG_CH5_ADC_L_ch5_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch5_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH5_ADC_H_UNION;
#endif
#define REG_CH5_ADC_H_ch5_adc_out_h_START (0)
#define REG_CH5_ADC_H_ch5_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch6_adc_out_l : 8;
    } reg;
} REG_CH6_ADC_L_UNION;
#endif
#define REG_CH6_ADC_L_ch6_adc_out_l_START (0)
#define REG_CH6_ADC_L_ch6_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch6_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH6_ADC_H_UNION;
#endif
#define REG_CH6_ADC_H_ch6_adc_out_h_START (0)
#define REG_CH6_ADC_H_ch6_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch7_adc_out_l : 8;
    } reg;
} REG_CH7_ADC_L_UNION;
#endif
#define REG_CH7_ADC_L_ch7_adc_out_l_START (0)
#define REG_CH7_ADC_L_ch7_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch7_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH7_ADC_H_UNION;
#endif
#define REG_CH7_ADC_H_ch7_adc_out_h_START (0)
#define REG_CH7_ADC_H_ch7_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch8_adc_out_l : 8;
    } reg;
} REG_CH8_ADC_L_UNION;
#endif
#define REG_CH8_ADC_L_ch8_adc_out_l_START (0)
#define REG_CH8_ADC_L_ch8_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch8_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH8_ADC_H_UNION;
#endif
#define REG_CH8_ADC_H_ch8_adc_out_h_START (0)
#define REG_CH8_ADC_H_ch8_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch9_adc_out_l : 8;
    } reg;
} REG_CH9_ADC_L_UNION;
#endif
#define REG_CH9_ADC_L_ch9_adc_out_l_START (0)
#define REG_CH9_ADC_L_ch9_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch9_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH9_ADC_H_UNION;
#endif
#define REG_CH9_ADC_H_ch9_adc_out_h_START (0)
#define REG_CH9_ADC_H_ch9_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch10_adc_out_l : 8;
    } reg;
} REG_CH10_ADC_L_UNION;
#endif
#define REG_CH10_ADC_L_ch10_adc_out_l_START (0)
#define REG_CH10_ADC_L_ch10_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch10_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH10_ADC_H_UNION;
#endif
#define REG_CH10_ADC_H_ch10_adc_out_h_START (0)
#define REG_CH10_ADC_H_ch10_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch11_adc_out_l : 8;
    } reg;
} REG_CH11_ADC_L_UNION;
#endif
#define REG_CH11_ADC_L_ch11_adc_out_l_START (0)
#define REG_CH11_ADC_L_ch11_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch11_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH11_ADC_H_UNION;
#endif
#define REG_CH11_ADC_H_ch11_adc_out_h_START (0)
#define REG_CH11_ADC_H_ch11_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch12_adc_out_l : 8;
    } reg;
} REG_CH12_ADC_L_UNION;
#endif
#define REG_CH12_ADC_L_ch12_adc_out_l_START (0)
#define REG_CH12_ADC_L_ch12_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch12_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH12_ADC_H_UNION;
#endif
#define REG_CH12_ADC_H_ch12_adc_out_h_START (0)
#define REG_CH12_ADC_H_ch12_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch13_adc_out_l : 8;
    } reg;
} REG_CH13_ADC_L_UNION;
#endif
#define REG_CH13_ADC_L_ch13_adc_out_l_START (0)
#define REG_CH13_ADC_L_ch13_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch13_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH13_ADC_H_UNION;
#endif
#define REG_CH13_ADC_H_ch13_adc_out_h_START (0)
#define REG_CH13_ADC_H_ch13_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch14_adc_out_l : 8;
    } reg;
} REG_CH14_ADC_L_UNION;
#endif
#define REG_CH14_ADC_L_ch14_adc_out_l_START (0)
#define REG_CH14_ADC_L_ch14_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch14_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH14_ADC_H_UNION;
#endif
#define REG_CH14_ADC_H_ch14_adc_out_h_START (0)
#define REG_CH14_ADC_H_ch14_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch15_adc_out_l : 8;
    } reg;
} REG_CH15_ADC_L_UNION;
#endif
#define REG_CH15_ADC_L_ch15_adc_out_l_START (0)
#define REG_CH15_ADC_L_ch15_adc_out_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ch15_adc_out_h : 4;
        unsigned char reserved : 4;
    } reg;
} REG_CH15_ADC_H_UNION;
#endif
#define REG_CH15_ADC_H_ch15_adc_out_h_START (0)
#define REG_CH15_ADC_H_ch15_adc_out_h_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_hk_clk_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_HKADC_CLK_EN_UNION;
#endif
#define REG_HKADC_CLK_EN_sc_hk_clk_en_START (0)
#define REG_HKADC_CLK_EN_sc_hk_clk_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_hkadc_tb_sel : 5;
        unsigned char reserved : 2;
        unsigned char sc_hkadc_tb_en : 1;
    } reg;
} REG_HKADC_TB_EN_SEL_UNION;
#endif
#define REG_HKADC_TB_EN_SEL_sc_hkadc_tb_sel_START (0)
#define REG_HKADC_TB_EN_SEL_sc_hkadc_tb_sel_END (4)
#define REG_HKADC_TB_EN_SEL_sc_hkadc_tb_en_START (7)
#define REG_HKADC_TB_EN_SEL_sc_hkadc_tb_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char hkadc_tb_bus_0 : 8;
    } reg;
} REG_HKADC_TB_DATA0_UNION;
#endif
#define REG_HKADC_TB_DATA0_hkadc_tb_bus_0_START (0)
#define REG_HKADC_TB_DATA0_hkadc_tb_bus_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char hkadc_tb_bus_1 : 8;
    } reg;
} REG_HKADC_TB_DATA1_UNION;
#endif
#define REG_HKADC_TB_DATA1_hkadc_tb_bus_1_START (0)
#define REG_HKADC_TB_DATA1_hkadc_tb_bus_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_otp_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_OTP_EN_UNION;
#endif
#define REG_OTP_EN_sc_otp_en_START (0)
#define REG_OTP_EN_sc_otp_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_th_tbat_otp : 8;
    } reg;
} REG_TH_TBAT_OTP_UNION;
#endif
#define REG_TH_TBAT_OTP_sc_th_tbat_otp_START (0)
#define REG_TH_TBAT_OTP_sc_th_tbat_otp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_th_tbat_otp_hys : 8;
    } reg;
} REG_TH_TBAT_OTP_HYS_UNION;
#endif
#define REG_TH_TBAT_OTP_HYS_sc_th_tbat_otp_hys_START (0)
#define REG_TH_TBAT_OTP_HYS_sc_th_tbat_otp_hys_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char chip_id0 : 8;
    } reg;
} REG_VERSION0_RO_REG_0_UNION;
#endif
#define REG_VERSION0_RO_REG_0_chip_id0_START (0)
#define REG_VERSION0_RO_REG_0_chip_id0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char chip_id1 : 8;
    } reg;
} REG_VERSION1_RO_REG_0_UNION;
#endif
#define REG_VERSION1_RO_REG_0_chip_id1_START (0)
#define REG_VERSION1_RO_REG_0_chip_id1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char chip_id2 : 8;
    } reg;
} REG_VERSION2_RO_REG_0_UNION;
#endif
#define REG_VERSION2_RO_REG_0_chip_id2_START (0)
#define REG_VERSION2_RO_REG_0_chip_id2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char chip_id3 : 8;
    } reg;
} REG_VERSION3_RO_REG_0_UNION;
#endif
#define REG_VERSION3_RO_REG_0_chip_id3_START (0)
#define REG_VERSION3_RO_REG_0_chip_id3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char chip_id4 : 8;
    } reg;
} REG_VERSION4_RO_REG_0_UNION;
#endif
#define REG_VERSION4_RO_REG_0_chip_id4_START (0)
#define REG_VERSION4_RO_REG_0_chip_id4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char chip_id5 : 8;
    } reg;
} REG_VERSION5_RO_REG_0_UNION;
#endif
#define REG_VERSION5_RO_REG_0_chip_id5_START (0)
#define REG_VERSION5_RO_REG_0_chip_id5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_cg_testbus_sel : 4;
        unsigned char reserved : 3;
        unsigned char sc_cg_testbus_en : 1;
    } reg;
} REG_SC_TESTBUS_CFG_UNION;
#endif
#define REG_SC_TESTBUS_CFG_sc_cg_testbus_sel_START (0)
#define REG_SC_TESTBUS_CFG_sc_cg_testbus_sel_END (3)
#define REG_SC_TESTBUS_CFG_sc_cg_testbus_en_START (7)
#define REG_SC_TESTBUS_CFG_sc_cg_testbus_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cg_testbus_rdata : 8;
    } reg;
} REG_SC_TESTBUS_RDATA_UNION;
#endif
#define REG_SC_TESTBUS_RDATA_cg_testbus_rdata_START (0)
#define REG_SC_TESTBUS_RDATA_cg_testbus_rdata_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_cg_glb_soft_rst_n : 8;
    } reg;
} REG_GLB_SOFT_RST_CTRL_UNION;
#endif
#define REG_GLB_SOFT_RST_CTRL_sc_cg_glb_soft_rst_n_START (0)
#define REG_GLB_SOFT_RST_CTRL_sc_cg_glb_soft_rst_n_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_cg_efuse_soft_rst_n : 8;
    } reg;
} REG_EFUSE_SOFT_RST_CTRL_UNION;
#endif
#define REG_EFUSE_SOFT_RST_CTRL_sc_cg_efuse_soft_rst_n_START (0)
#define REG_EFUSE_SOFT_RST_CTRL_sc_cg_efuse_soft_rst_n_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_hkadc_soft_rst_n : 8;
    } reg;
} REG_HKADC_SOFT_RST_CTRL_UNION;
#endif
#define REG_HKADC_SOFT_RST_CTRL_sc_hkadc_soft_rst_n_START (0)
#define REG_HKADC_SOFT_RST_CTRL_sc_hkadc_soft_rst_n_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_cg_coul_soft_rst_n : 8;
    } reg;
} REG_COUL_SOFT_RST_CTRL_UNION;
#endif
#define REG_COUL_SOFT_RST_CTRL_sc_cg_coul_soft_rst_n_START (0)
#define REG_COUL_SOFT_RST_CTRL_sc_cg_coul_soft_rst_n_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_cg_coul_pd_rst_n : 8;
    } reg;
} REG_COUL_PD_RST_CTRL_UNION;
#endif
#define REG_COUL_PD_RST_CTRL_sc_cg_coul_pd_rst_n_START (0)
#define REG_COUL_PD_RST_CTRL_sc_cg_coul_pd_rst_n_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_cg_flash_rst_n : 8;
    } reg;
} REG_FLASH_SOFT_RST_CTRL_UNION;
#endif
#define REG_FLASH_SOFT_RST_CTRL_sc_cg_flash_rst_n_START (0)
#define REG_FLASH_SOFT_RST_CTRL_sc_cg_flash_rst_n_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_cg_com_clk_en : 1;
        unsigned char sc_cg_red_clk_en : 1;
        unsigned char sc_cg_pd_clk_en : 1;
        unsigned char sc_cg_2m_clk_en : 1;
        unsigned char sc_cg_pd_clk_en_sel : 1;
        unsigned char sc_cg_2m_clk_en_sel : 1;
        unsigned char sc_cg_ufcs_clk_en : 1;
        unsigned char sc_cg_ufcs_clk_en_sel : 1;
    } reg;
} REG_SC_CRG_CLK_EN_CTRL_UNION;
#endif
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_com_clk_en_START (0)
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_com_clk_en_END (0)
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_red_clk_en_START (1)
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_red_clk_en_END (1)
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_pd_clk_en_START (2)
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_pd_clk_en_END (2)
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_2m_clk_en_START (3)
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_2m_clk_en_END (3)
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_pd_clk_en_sel_START (4)
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_pd_clk_en_sel_END (4)
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_2m_clk_en_sel_START (5)
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_2m_clk_en_sel_END (5)
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_ufcs_clk_en_START (6)
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_ufcs_clk_en_END (6)
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_ufcs_clk_en_sel_START (7)
#define REG_SC_CRG_CLK_EN_CTRL_sc_cg_ufcs_clk_en_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_cg_flash_clk_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_SC_CRG_CLK_EN_CTRL_1_UNION;
#endif
#define REG_SC_CRG_CLK_EN_CTRL_1_sc_cg_flash_clk_en_START (0)
#define REG_SC_CRG_CLK_EN_CTRL_1_sc_cg_flash_clk_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_coul_clk_en_sel : 1;
        unsigned char sc_cg_coul_clk_en : 1;
        unsigned char reserved : 6;
    } reg;
} REG_SC_CRG_CLK_EN_CTRL_2_UNION;
#endif
#define REG_SC_CRG_CLK_EN_CTRL_2_sc_coul_clk_en_sel_START (0)
#define REG_SC_CRG_CLK_EN_CTRL_2_sc_coul_clk_en_sel_END (0)
#define REG_SC_CRG_CLK_EN_CTRL_2_sc_cg_coul_clk_en_START (1)
#define REG_SC_CRG_CLK_EN_CTRL_2_sc_cg_coul_clk_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_cg_testsig_sel : 7;
        unsigned char reserved : 1;
    } reg;
} REG_SC_TESTSIG_CFG_UNION;
#endif
#define REG_SC_TESTSIG_CFG_sc_cg_testsig_sel_START (0)
#define REG_SC_TESTSIG_CFG_sc_cg_testsig_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_wdt_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_SC_WDT_EN_UNION;
#endif
#define REG_SC_WDT_EN_sc_wdt_en_START (0)
#define REG_SC_WDT_EN_sc_wdt_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char wd_rst_n : 1;
        unsigned char reserved : 7;
    } reg;
} REG_WDT_SOFT_RST_UNION;
#endif
#define REG_WDT_SOFT_RST_wd_rst_n_START (0)
#define REG_WDT_SOFT_RST_wd_rst_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_watchdog_timer : 3;
        unsigned char reserved_0 : 1;
        unsigned char sc_wdt_test_sel : 1;
        unsigned char reserved_1 : 3;
    } reg;
} REG_WDT_CTRL_UNION;
#endif
#define REG_WDT_CTRL_sc_watchdog_timer_START (0)
#define REG_WDT_CTRL_sc_watchdog_timer_END (2)
#define REG_WDT_CTRL_sc_wdt_test_sel_START (4)
#define REG_WDT_CTRL_sc_wdt_test_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char wdt_time_out_n : 1;
        unsigned char reserved : 7;
    } reg;
} REG_WDT_TIMEOUT_UNION;
#endif
#define REG_WDT_TIMEOUT_wdt_time_out_n_START (0)
#define REG_WDT_TIMEOUT_wdt_time_out_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_bat_cnct_sel : 1;
        unsigned char reserved : 7;
    } reg;
} REG_BAT_CNCT_SEL_UNION;
#endif
#define REG_BAT_CNCT_SEL_sc_bat_cnct_sel_START (0)
#define REG_BAT_CNCT_SEL_sc_bat_cnct_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_mode : 3;
        unsigned char reserved : 5;
    } reg;
} REG_DA_SC_MODE_UNION;
#endif
#define REG_DA_SC_MODE_da_sc_mode_START (0)
#define REG_DA_SC_MODE_da_sc_mode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_chg_otg_mode : 2;
        unsigned char reserved : 6;
    } reg;
} REG_OTG_MODE_CFG_UNION;
#endif
#define REG_OTG_MODE_CFG_sc_chg_otg_mode_START (0)
#define REG_OTG_MODE_CFG_sc_chg_otg_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_DA_SC_EN_UNION;
#endif
#define REG_DA_SC_EN_da_sc_en_START (0)
#define REG_DA_SC_EN_da_sc_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_scbuck_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_DA_SCBUCK_EN_UNION;
#endif
#define REG_DA_SCBUCK_EN_da_scbuck_en_START (0)
#define REG_DA_SCBUCK_EN_da_scbuck_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_buck_enb : 1;
        unsigned char reserved : 7;
    } reg;
} REG_SC_BUCK_ENB_UNION;
#endif
#define REG_SC_BUCK_ENB_sc_buck_enb_START (0)
#define REG_SC_BUCK_ENB_sc_buck_enb_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_boost_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_DA_BOOST_EN_UNION;
#endif
#define REG_DA_BOOST_EN_da_boost_en_START (0)
#define REG_DA_BOOST_EN_da_boost_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_usbovp_ctrl : 2;
        unsigned char reserved : 6;
    } reg;
} REG_USBOVP_CTRL_UNION;
#endif
#define REG_USBOVP_CTRL_da_usbovp_ctrl_START (0)
#define REG_USBOVP_CTRL_da_usbovp_ctrl_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_pswovp_ctrl : 2;
        unsigned char reserved : 6;
    } reg;
} REG_PSWOVP_CTRL_UNION;
#endif
#define REG_PSWOVP_CTRL_da_pswovp_ctrl_START (0)
#define REG_PSWOVP_CTRL_da_pswovp_ctrl_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_ovp_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_OVP_EN_UNION;
#endif
#define REG_OVP_EN_sc_ovp_en_START (0)
#define REG_OVP_EN_sc_ovp_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_aux_sbu_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_AUX_SBU_EN_UNION;
#endif
#define REG_AUX_SBU_EN_sc_aux_sbu_en_START (0)
#define REG_AUX_SBU_EN_sc_aux_sbu_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_vbus_bkvset : 1;
        unsigned char reserved : 7;
    } reg;
} REG_VBUS_BKVSET_UNION;
#endif
#define REG_VBUS_BKVSET_da_vbus_bkvset_START (0)
#define REG_VBUS_BKVSET_da_vbus_bkvset_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_phase1_en : 8;
    } reg;
} REG_DA_SC_PHASE1_EN_UNION;
#endif
#define REG_DA_SC_PHASE1_EN_da_sc_phase1_en_START (0)
#define REG_DA_SC_PHASE1_EN_da_sc_phase1_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_phase2_en : 8;
    } reg;
} REG_DA_SC_PHASE2_EN_UNION;
#endif
#define REG_DA_SC_PHASE2_EN_da_sc_phase2_en_START (0)
#define REG_DA_SC_PHASE2_EN_da_sc_phase2_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_efuse_pdob_sel : 1;
        unsigned char reserved : 7;
    } reg;
} REG_EFUSE_PDOB_SEL_UNION;
#endif
#define REG_EFUSE_PDOB_SEL_sc_efuse_pdob_sel_START (0)
#define REG_EFUSE_PDOB_SEL_sc_efuse_pdob_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_efuse_prog_int : 1;
        unsigned char sc_efuse_prog_sel : 1;
        unsigned char sc_efuse_inctrl_sel : 1;
        unsigned char reserved : 5;
    } reg;
} REG_EFUSE_MODE_UNION;
#endif
#define REG_EFUSE_MODE_sc_efuse_prog_int_START (0)
#define REG_EFUSE_MODE_sc_efuse_prog_int_END (0)
#define REG_EFUSE_MODE_sc_efuse_prog_sel_START (1)
#define REG_EFUSE_MODE_sc_efuse_prog_sel_END (1)
#define REG_EFUSE_MODE_sc_efuse_inctrl_sel_START (2)
#define REG_EFUSE_MODE_sc_efuse_inctrl_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_efuse_rd_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} REG_EFUSE_RD_CTRL_UNION;
#endif
#define REG_EFUSE_RD_CTRL_sc_efuse_rd_ctrl_START (0)
#define REG_EFUSE_RD_CTRL_sc_efuse_rd_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_efuse_aen_cfg : 1;
        unsigned char reserved : 7;
    } reg;
} REG_EFUSE_AEN_UNION;
#endif
#define REG_EFUSE_AEN_sc_efuse_aen_cfg_START (0)
#define REG_EFUSE_AEN_sc_efuse_aen_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_efuse_pgmen_cfg : 1;
        unsigned char reserved : 7;
    } reg;
} REG_EFUSE_PGMEN_UNION;
#endif
#define REG_EFUSE_PGMEN_sc_efuse_pgmen_cfg_START (0)
#define REG_EFUSE_PGMEN_sc_efuse_pgmen_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_efuse_rden_cfg : 1;
        unsigned char reserved : 7;
    } reg;
} REG_EFUSE_RDEN_UNION;
#endif
#define REG_EFUSE_RDEN_sc_efuse_rden_cfg_START (0)
#define REG_EFUSE_RDEN_sc_efuse_rden_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_efuse_a_cfg : 8;
    } reg;
} REG_EFUSE_ADDR_UNION;
#endif
#define REG_EFUSE_ADDR_sc_efuse_a_cfg_START (0)
#define REG_EFUSE_ADDR_sc_efuse_a_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_efuse_a_cfg_h : 8;
    } reg;
} REG_EFUSE_ADDR_H_UNION;
#endif
#define REG_EFUSE_ADDR_H_sc_efuse_a_cfg_h_START (0)
#define REG_EFUSE_ADDR_H_sc_efuse_a_cfg_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_efuse_pdob_pre_addr : 6;
        unsigned char reserved : 1;
        unsigned char sc_efuse_pdob_pre_we : 1;
    } reg;
} REG_EFUSE_PDOB_PRE_ADDR_WE_UNION;
#endif
#define REG_EFUSE_PDOB_PRE_ADDR_WE_sc_efuse_pdob_pre_addr_START (0)
#define REG_EFUSE_PDOB_PRE_ADDR_WE_sc_efuse_pdob_pre_addr_END (5)
#define REG_EFUSE_PDOB_PRE_ADDR_WE_sc_efuse_pdob_pre_we_START (7)
#define REG_EFUSE_PDOB_PRE_ADDR_WE_sc_efuse_pdob_pre_we_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_efuse_pdob_pre_wdata : 8;
    } reg;
} REG_EFUSE_PDOB_PRE_WDATA_UNION;
#endif
#define REG_EFUSE_PDOB_PRE_WDATA_sc_efuse_pdob_pre_wdata_START (0)
#define REG_EFUSE_PDOB_PRE_WDATA_sc_efuse_pdob_pre_wdata_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char tb_efuse_state : 4;
        unsigned char tb_efuse_por_int_ro : 1;
        unsigned char tb_efuse_rd_done : 1;
        unsigned char reserved : 2;
    } reg;
} REG_EFUSE_STATUS_UNION;
#endif
#define REG_EFUSE_STATUS_tb_efuse_state_START (0)
#define REG_EFUSE_STATUS_tb_efuse_state_END (3)
#define REG_EFUSE_STATUS_tb_efuse_por_int_ro_START (4)
#define REG_EFUSE_STATUS_tb_efuse_por_int_ro_END (4)
#define REG_EFUSE_STATUS_tb_efuse_rd_done_START (5)
#define REG_EFUSE_STATUS_tb_efuse_rd_done_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_efuse_state_reset : 1;
        unsigned char reserved : 7;
    } reg;
} REG_EFUSE_FSM_RESET_UNION;
#endif
#define REG_EFUSE_FSM_RESET_sc_efuse_state_reset_START (0)
#define REG_EFUSE_FSM_RESET_sc_efuse_state_reset_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_efuse1_testbus_sel : 7;
        unsigned char sc_efuse_testbus_en : 1;
    } reg;
} REG_EFUSE_TESTBUS_CFG_UNION;
#endif
#define REG_EFUSE_TESTBUS_CFG_sc_efuse1_testbus_sel_START (0)
#define REG_EFUSE_TESTBUS_CFG_sc_efuse1_testbus_sel_END (6)
#define REG_EFUSE_TESTBUS_CFG_sc_efuse_testbus_en_START (7)
#define REG_EFUSE_TESTBUS_CFG_sc_efuse_testbus_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char efuse_testbus_rdata : 8;
    } reg;
} REG_EFUSE_TESTBUS_RDATA_UNION;
#endif
#define REG_EFUSE_TESTBUS_RDATA_efuse_testbus_rdata_START (0)
#define REG_EFUSE_TESTBUS_RDATA_efuse_testbus_rdata_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_efuse_a_cal_sel : 1;
        unsigned char reserved : 7;
    } reg;
} REG_EFUSE_ADDR_CAL_SEL_UNION;
#endif
#define REG_EFUSE_ADDR_CAL_SEL_sc_efuse_a_cal_sel_START (0)
#define REG_EFUSE_ADDR_CAL_SEL_sc_efuse_a_cal_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_otg_dmd_ofs : 4;
        unsigned char sc_otg_dmd_ramp : 3;
        unsigned char reserved : 1;
    } reg;
} REG_OTG_DMD_CFG_UNION;
#endif
#define REG_OTG_DMD_CFG_sc_otg_dmd_ofs_START (0)
#define REG_OTG_DMD_CFG_sc_otg_dmd_ofs_END (3)
#define REG_OTG_DMD_CFG_sc_otg_dmd_ramp_START (4)
#define REG_OTG_DMD_CFG_sc_otg_dmd_ramp_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_buck_cap3_ea : 2;
        unsigned char sc_buck_cap2_ea : 2;
        unsigned char sc_buck_cap1_ea : 3;
        unsigned char sc_buck_acl_downen : 1;
    } reg;
} REG_BUCK_CFG_REG_0_UNION;
#endif
#define REG_BUCK_CFG_REG_0_sc_buck_cap3_ea_START (0)
#define REG_BUCK_CFG_REG_0_sc_buck_cap3_ea_END (1)
#define REG_BUCK_CFG_REG_0_sc_buck_cap2_ea_START (2)
#define REG_BUCK_CFG_REG_0_sc_buck_cap2_ea_END (3)
#define REG_BUCK_CFG_REG_0_sc_buck_cap1_ea_START (4)
#define REG_BUCK_CFG_REG_0_sc_buck_cap1_ea_END (6)
#define REG_BUCK_CFG_REG_0_sc_buck_acl_downen_START (7)
#define REG_BUCK_CFG_REG_0_sc_buck_acl_downen_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_buck_dt_lshs : 1;
        unsigned char sc_buck_dt_hsls : 1;
        unsigned char sc_buck_dpm_gm_3k : 1;
        unsigned char sc_buck_cap7_acl : 2;
        unsigned char sc_buck_cap6_dpm : 2;
        unsigned char reserved : 1;
    } reg;
} REG_BUCK_CFG_REG_1_UNION;
#endif
#define REG_BUCK_CFG_REG_1_sc_buck_dt_lshs_START (0)
#define REG_BUCK_CFG_REG_1_sc_buck_dt_lshs_END (0)
#define REG_BUCK_CFG_REG_1_sc_buck_dt_hsls_START (1)
#define REG_BUCK_CFG_REG_1_sc_buck_dt_hsls_END (1)
#define REG_BUCK_CFG_REG_1_sc_buck_dpm_gm_3k_START (2)
#define REG_BUCK_CFG_REG_1_sc_buck_dpm_gm_3k_END (2)
#define REG_BUCK_CFG_REG_1_sc_buck_cap7_acl_START (3)
#define REG_BUCK_CFG_REG_1_sc_buck_cap7_acl_END (4)
#define REG_BUCK_CFG_REG_1_sc_buck_cap6_dpm_START (5)
#define REG_BUCK_CFG_REG_1_sc_buck_cap6_dpm_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_buck_hmos_fall : 3;
        unsigned char sc_buck_dt_sel : 2;
        unsigned char sc_buck_dt_lshs_delay : 2;
        unsigned char reserved : 1;
    } reg;
} REG_BUCK_CFG_REG_2_UNION;
#endif
#define REG_BUCK_CFG_REG_2_sc_buck_hmos_fall_START (0)
#define REG_BUCK_CFG_REG_2_sc_buck_hmos_fall_END (2)
#define REG_BUCK_CFG_REG_2_sc_buck_dt_sel_START (3)
#define REG_BUCK_CFG_REG_2_sc_buck_dt_sel_END (4)
#define REG_BUCK_CFG_REG_2_sc_buck_dt_lshs_delay_START (5)
#define REG_BUCK_CFG_REG_2_sc_buck_dt_lshs_delay_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_buck_lmos_fall : 3;
        unsigned char sc_buck_hmos_rise : 3;
        unsigned char reserved : 2;
    } reg;
} REG_BUCK_CFG_REG_3_UNION;
#endif
#define REG_BUCK_CFG_REG_3_sc_buck_lmos_fall_START (0)
#define REG_BUCK_CFG_REG_3_sc_buck_lmos_fall_END (2)
#define REG_BUCK_CFG_REG_3_sc_buck_hmos_rise_START (3)
#define REG_BUCK_CFG_REG_3_sc_buck_hmos_rise_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_buck_res13_dpm_pz : 2;
        unsigned char sc_buck_res1_ea : 3;
        unsigned char sc_buck_lmos_rise : 3;
    } reg;
} REG_BUCK_CFG_REG_4_UNION;
#endif
#define REG_BUCK_CFG_REG_4_sc_buck_res13_dpm_pz_START (0)
#define REG_BUCK_CFG_REG_4_sc_buck_res13_dpm_pz_END (1)
#define REG_BUCK_CFG_REG_4_sc_buck_res1_ea_START (2)
#define REG_BUCK_CFG_REG_4_sc_buck_res1_ea_END (4)
#define REG_BUCK_CFG_REG_4_sc_buck_lmos_rise_START (5)
#define REG_BUCK_CFG_REG_4_sc_buck_lmos_rise_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_buck_res2_ea : 2;
        unsigned char sc_buck_res15_acl_z : 2;
        unsigned char sc_buck_res14_acl_p : 2;
        unsigned char reserved : 2;
    } reg;
} REG_BUCK_CFG_REG_5_UNION;
#endif
#define REG_BUCK_CFG_REG_5_sc_buck_res2_ea_START (0)
#define REG_BUCK_CFG_REG_5_sc_buck_res2_ea_END (1)
#define REG_BUCK_CFG_REG_5_sc_buck_res15_acl_z_START (2)
#define REG_BUCK_CFG_REG_5_sc_buck_res15_acl_z_END (3)
#define REG_BUCK_CFG_REG_5_sc_buck_res14_acl_p_START (4)
#define REG_BUCK_CFG_REG_5_sc_buck_res14_acl_p_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_buck_res5_acl_rout : 2;
        unsigned char sc_buck_res4_dpm_gm : 2;
        unsigned char sc_buck_res3_ea : 3;
        unsigned char reserved : 1;
    } reg;
} REG_BUCK_CFG_REG_6_UNION;
#endif
#define REG_BUCK_CFG_REG_6_sc_buck_res5_acl_rout_START (0)
#define REG_BUCK_CFG_REG_6_sc_buck_res5_acl_rout_END (1)
#define REG_BUCK_CFG_REG_6_sc_buck_res4_dpm_gm_START (2)
#define REG_BUCK_CFG_REG_6_sc_buck_res4_dpm_gm_END (3)
#define REG_BUCK_CFG_REG_6_sc_buck_res3_ea_START (4)
#define REG_BUCK_CFG_REG_6_sc_buck_res3_ea_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_buck_reserve : 8;
    } reg;
} REG_BUCK_CFG_REG_7_UNION;
#endif
#define REG_BUCK_CFG_REG_7_sc_buck_reserve_START (0)
#define REG_BUCK_CFG_REG_7_sc_buck_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_buck_ss_speed : 2;
        unsigned char reserved : 6;
    } reg;
} REG_BUCK_CFG_REG_8_UNION;
#endif
#define REG_BUCK_CFG_REG_8_sc_buck_ss_speed_START (0)
#define REG_BUCK_CFG_REG_8_sc_buck_ss_speed_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_otg_cap3_ea : 2;
        unsigned char sc_otg_cap2_ea : 2;
        unsigned char sc_otg_cap1_ea : 3;
        unsigned char sc_otg_acl_downen : 1;
    } reg;
} REG_OTG_CFG_REG_0_UNION;
#endif
#define REG_OTG_CFG_REG_0_sc_otg_cap3_ea_START (0)
#define REG_OTG_CFG_REG_0_sc_otg_cap3_ea_END (1)
#define REG_OTG_CFG_REG_0_sc_otg_cap2_ea_START (2)
#define REG_OTG_CFG_REG_0_sc_otg_cap2_ea_END (3)
#define REG_OTG_CFG_REG_0_sc_otg_cap1_ea_START (4)
#define REG_OTG_CFG_REG_0_sc_otg_cap1_ea_END (6)
#define REG_OTG_CFG_REG_0_sc_otg_acl_downen_START (7)
#define REG_OTG_CFG_REG_0_sc_otg_acl_downen_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_otg_dt_lshs : 1;
        unsigned char sc_otg_dt_hsls : 1;
        unsigned char sc_otg_dpm_gm_3k : 1;
        unsigned char sc_otg_cap7_acl : 2;
        unsigned char sc_otg_cap6_dpm : 2;
        unsigned char reserved : 1;
    } reg;
} REG_OTG_CFG_REG_1_UNION;
#endif
#define REG_OTG_CFG_REG_1_sc_otg_dt_lshs_START (0)
#define REG_OTG_CFG_REG_1_sc_otg_dt_lshs_END (0)
#define REG_OTG_CFG_REG_1_sc_otg_dt_hsls_START (1)
#define REG_OTG_CFG_REG_1_sc_otg_dt_hsls_END (1)
#define REG_OTG_CFG_REG_1_sc_otg_dpm_gm_3k_START (2)
#define REG_OTG_CFG_REG_1_sc_otg_dpm_gm_3k_END (2)
#define REG_OTG_CFG_REG_1_sc_otg_cap7_acl_START (3)
#define REG_OTG_CFG_REG_1_sc_otg_cap7_acl_END (4)
#define REG_OTG_CFG_REG_1_sc_otg_cap6_dpm_START (5)
#define REG_OTG_CFG_REG_1_sc_otg_cap6_dpm_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_otg_hmos_fall : 3;
        unsigned char sc_otg_dt_sel : 2;
        unsigned char sc_otg_dt_lshs_delay : 2;
        unsigned char reserved : 1;
    } reg;
} REG_OTG_CFG_REG_2_UNION;
#endif
#define REG_OTG_CFG_REG_2_sc_otg_hmos_fall_START (0)
#define REG_OTG_CFG_REG_2_sc_otg_hmos_fall_END (2)
#define REG_OTG_CFG_REG_2_sc_otg_dt_sel_START (3)
#define REG_OTG_CFG_REG_2_sc_otg_dt_sel_END (4)
#define REG_OTG_CFG_REG_2_sc_otg_dt_lshs_delay_START (5)
#define REG_OTG_CFG_REG_2_sc_otg_dt_lshs_delay_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_otg_lmos_fall : 3;
        unsigned char sc_otg_hmos_rise : 3;
        unsigned char reserved : 2;
    } reg;
} REG_OTG_CFG_REG_3_UNION;
#endif
#define REG_OTG_CFG_REG_3_sc_otg_lmos_fall_START (0)
#define REG_OTG_CFG_REG_3_sc_otg_lmos_fall_END (2)
#define REG_OTG_CFG_REG_3_sc_otg_hmos_rise_START (3)
#define REG_OTG_CFG_REG_3_sc_otg_hmos_rise_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_otg_res13_dpm_pz : 2;
        unsigned char sc_otg_res1_ea : 3;
        unsigned char sc_otg_lmos_rise : 3;
    } reg;
} REG_OTG_CFG_REG_4_UNION;
#endif
#define REG_OTG_CFG_REG_4_sc_otg_res13_dpm_pz_START (0)
#define REG_OTG_CFG_REG_4_sc_otg_res13_dpm_pz_END (1)
#define REG_OTG_CFG_REG_4_sc_otg_res1_ea_START (2)
#define REG_OTG_CFG_REG_4_sc_otg_res1_ea_END (4)
#define REG_OTG_CFG_REG_4_sc_otg_lmos_rise_START (5)
#define REG_OTG_CFG_REG_4_sc_otg_lmos_rise_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_otg_res2_ea : 2;
        unsigned char sc_otg_res15_acl_z : 2;
        unsigned char sc_otg_res14_acl_p : 2;
        unsigned char reserved : 2;
    } reg;
} REG_OTG_CFG_REG_5_UNION;
#endif
#define REG_OTG_CFG_REG_5_sc_otg_res2_ea_START (0)
#define REG_OTG_CFG_REG_5_sc_otg_res2_ea_END (1)
#define REG_OTG_CFG_REG_5_sc_otg_res15_acl_z_START (2)
#define REG_OTG_CFG_REG_5_sc_otg_res15_acl_z_END (3)
#define REG_OTG_CFG_REG_5_sc_otg_res14_acl_p_START (4)
#define REG_OTG_CFG_REG_5_sc_otg_res14_acl_p_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_otg_res5_acl_rout : 2;
        unsigned char sc_otg_res4_dpm_gm : 2;
        unsigned char sc_otg_res3_ea : 3;
        unsigned char reserved : 1;
    } reg;
} REG_OTG_CFG_REG_6_UNION;
#endif
#define REG_OTG_CFG_REG_6_sc_otg_res5_acl_rout_START (0)
#define REG_OTG_CFG_REG_6_sc_otg_res5_acl_rout_END (1)
#define REG_OTG_CFG_REG_6_sc_otg_res4_dpm_gm_START (2)
#define REG_OTG_CFG_REG_6_sc_otg_res4_dpm_gm_END (3)
#define REG_OTG_CFG_REG_6_sc_otg_res3_ea_START (4)
#define REG_OTG_CFG_REG_6_sc_otg_res3_ea_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_otg_reserve : 8;
    } reg;
} REG_OTG_CFG_REG_7_UNION;
#endif
#define REG_OTG_CFG_REG_7_sc_otg_reserve_START (0)
#define REG_OTG_CFG_REG_7_sc_otg_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_otg_ss_speed : 2;
        unsigned char reserved : 6;
    } reg;
} REG_OTG_CFG_REG_8_UNION;
#endif
#define REG_OTG_CFG_REG_8_sc_otg_ss_speed_START (0)
#define REG_OTG_CFG_REG_8_sc_otg_ss_speed_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char tb_chg_ctrl_status : 8;
    } reg;
} REG_STATUS_UNION;
#endif
#define REG_STATUS_tb_chg_ctrl_status_START (0)
#define REG_STATUS_tb_chg_ctrl_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_chg_tb_sel : 6;
        unsigned char reserved : 1;
        unsigned char sc_chg_tb_en : 1;
    } reg;
} REG_TB_CFG_UNION;
#endif
#define REG_TB_CFG_sc_chg_tb_sel_START (0)
#define REG_TB_CFG_sc_chg_tb_sel_END (5)
#define REG_TB_CFG_sc_chg_tb_en_START (7)
#define REG_TB_CFG_sc_chg_tb_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char chg_tb_bus : 8;
    } reg;
} REG_TB_BUS_UNION;
#endif
#define REG_TB_BUS_chg_tb_bus_START (0)
#define REG_TB_BUS_chg_tb_bus_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char chg_tb_sig : 1;
        unsigned char reserved : 7;
    } reg;
} REG_TB_SIG_UNION;
#endif
#define REG_TB_SIG_chg_tb_sig_START (0)
#define REG_TB_SIG_chg_tb_sig_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char efs_dig_resv_1 : 8;
    } reg;
} REG_EFS_DIG_TRIM_1_UNION;
#endif
#define REG_EFS_DIG_TRIM_1_efs_dig_resv_1_START (0)
#define REG_EFS_DIG_TRIM_1_efs_dig_resv_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char efs_spmi_slv_id_sel : 1;
        unsigned char efs_spmi_slv_id : 4;
        unsigned char efs_dig_resv_0 : 3;
    } reg;
} REG_EFS_DIG_TRIM_0_UNION;
#endif
#define REG_EFS_DIG_TRIM_0_efs_spmi_slv_id_sel_START (0)
#define REG_EFS_DIG_TRIM_0_efs_spmi_slv_id_sel_END (0)
#define REG_EFS_DIG_TRIM_0_efs_spmi_slv_id_START (1)
#define REG_EFS_DIG_TRIM_0_efs_spmi_slv_id_END (4)
#define REG_EFS_DIG_TRIM_0_efs_dig_resv_0_START (5)
#define REG_EFS_DIG_TRIM_0_efs_dig_resv_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_dcp_ok : 1;
        unsigned char reserved : 7;
    } reg;
} REG_DCP_CFG_UNION;
#endif
#define REG_DCP_CFG_da_dcp_ok_START (0)
#define REG_DCP_CFG_da_dcp_ok_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_bc12_det_en : 1;
        unsigned char da_bc12_auto_en : 1;
        unsigned char da_bc12_vbus_det_en : 1;
        unsigned char da_bc12_dcd_det_en : 1;
        unsigned char da_bc12_pd_det_en : 1;
        unsigned char da_bc12_sd_det_en : 1;
        unsigned char da_bc12_data_src_en : 1;
        unsigned char reserved : 1;
    } reg;
} REG_BC12_CFG_0_UNION;
#endif
#define REG_BC12_CFG_0_da_bc12_det_en_START (0)
#define REG_BC12_CFG_0_da_bc12_det_en_END (0)
#define REG_BC12_CFG_0_da_bc12_auto_en_START (1)
#define REG_BC12_CFG_0_da_bc12_auto_en_END (1)
#define REG_BC12_CFG_0_da_bc12_vbus_det_en_START (2)
#define REG_BC12_CFG_0_da_bc12_vbus_det_en_END (2)
#define REG_BC12_CFG_0_da_bc12_dcd_det_en_START (3)
#define REG_BC12_CFG_0_da_bc12_dcd_det_en_END (3)
#define REG_BC12_CFG_0_da_bc12_pd_det_en_START (4)
#define REG_BC12_CFG_0_da_bc12_pd_det_en_END (4)
#define REG_BC12_CFG_0_da_bc12_sd_det_en_START (5)
#define REG_BC12_CFG_0_da_bc12_sd_det_en_END (5)
#define REG_BC12_CFG_0_da_bc12_data_src_en_START (6)
#define REG_BC12_CFG_0_da_bc12_data_src_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_bc12_dcd_vref_sel : 2;
        unsigned char da_bc12_vbus_vref : 2;
        unsigned char da_bc12_src_vref_sel : 2;
        unsigned char da_bc12_test_vref_sel : 1;
        unsigned char da_bc12_charge_sel : 1;
    } reg;
} REG_BC12_CFG_1_UNION;
#endif
#define REG_BC12_CFG_1_da_bc12_dcd_vref_sel_START (0)
#define REG_BC12_CFG_1_da_bc12_dcd_vref_sel_END (1)
#define REG_BC12_CFG_1_da_bc12_vbus_vref_START (2)
#define REG_BC12_CFG_1_da_bc12_vbus_vref_END (3)
#define REG_BC12_CFG_1_da_bc12_src_vref_sel_START (4)
#define REG_BC12_CFG_1_da_bc12_src_vref_sel_END (5)
#define REG_BC12_CFG_1_da_bc12_test_vref_sel_START (6)
#define REG_BC12_CFG_1_da_bc12_test_vref_sel_END (6)
#define REG_BC12_CFG_1_da_bc12_charge_sel_START (7)
#define REG_BC12_CFG_1_da_bc12_charge_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_dcd_timeout_set : 3;
        unsigned char da_pd_timeout_set : 2;
        unsigned char da_sd_timeout_set : 2;
        unsigned char reserved : 1;
    } reg;
} REG_BC12_CFG_2_UNION;
#endif
#define REG_BC12_CFG_2_da_dcd_timeout_set_START (0)
#define REG_BC12_CFG_2_da_dcd_timeout_set_END (2)
#define REG_BC12_CFG_2_da_pd_timeout_set_START (3)
#define REG_BC12_CFG_2_da_pd_timeout_set_END (4)
#define REG_BC12_CFG_2_da_sd_timeout_set_START (5)
#define REG_BC12_CFG_2_da_sd_timeout_set_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_bc12_charge_det : 1;
        unsigned char ad_bc12_otgsessvid : 1;
        unsigned char ad_bc12_fsvplus : 1;
        unsigned char ad_bc12_fsvminus : 1;
        unsigned char ad_bc12_dcd_timeout : 1;
        unsigned char ad_bc12_pd_timeout : 1;
        unsigned char ad_bc12_sd_timeout : 1;
        unsigned char reserved : 1;
    } reg;
} REG_BC12_STATUS_UNION;
#endif
#define REG_BC12_STATUS_ad_bc12_charge_det_START (0)
#define REG_BC12_STATUS_ad_bc12_charge_det_END (0)
#define REG_BC12_STATUS_ad_bc12_otgsessvid_START (1)
#define REG_BC12_STATUS_ad_bc12_otgsessvid_END (1)
#define REG_BC12_STATUS_ad_bc12_fsvplus_START (2)
#define REG_BC12_STATUS_ad_bc12_fsvplus_END (2)
#define REG_BC12_STATUS_ad_bc12_fsvminus_START (3)
#define REG_BC12_STATUS_ad_bc12_fsvminus_END (3)
#define REG_BC12_STATUS_ad_bc12_dcd_timeout_START (4)
#define REG_BC12_STATUS_ad_bc12_dcd_timeout_END (4)
#define REG_BC12_STATUS_ad_bc12_pd_timeout_START (5)
#define REG_BC12_STATUS_ad_bc12_pd_timeout_END (5)
#define REG_BC12_STATUS_ad_bc12_sd_timeout_START (6)
#define REG_BC12_STATUS_ad_bc12_sd_timeout_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_bc12_reserved : 8;
    } reg;
} REG_BC12_RESERVE0_UNION;
#endif
#define REG_BC12_RESERVE0_da_bc12_reserved_START (0)
#define REG_BC12_RESERVE0_da_bc12_reserved_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_bc12_reserved2 : 8;
    } reg;
} REG_BC12_RESERVE_DA_UNION;
#endif
#define REG_BC12_RESERVE_DA_da_bc12_reserved2_START (0)
#define REG_BC12_RESERVE_DA_da_bc12_reserved2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_bc12_reserved : 4;
        unsigned char reserved : 4;
    } reg;
} REG_BC12_RESERVE1_UNION;
#endif
#define REG_BC12_RESERVE1_ad_bc12_reserved_START (0)
#define REG_BC12_RESERVE1_ad_bc12_reserved_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_ctrl : 3;
        unsigned char reserved : 5;
    } reg;
} REG_CLJ_CTRL_REG0_UNION;
#endif
#define REG_CLJ_CTRL_REG0_eco_ctrl_START (0)
#define REG_CLJ_CTRL_REG0_eco_ctrl_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 1;
        unsigned char coul_eco_dly_sel : 2;
        unsigned char wait_comp_en : 1;
        unsigned char wait_comp_sel : 2;
        unsigned char reserved_1 : 2;
    } reg;
} REG_CLJ_CTRL_REG1_UNION;
#endif
#define REG_CLJ_CTRL_REG1_coul_eco_dly_sel_START (1)
#define REG_CLJ_CTRL_REG1_coul_eco_dly_sel_END (2)
#define REG_CLJ_CTRL_REG1_wait_comp_en_START (3)
#define REG_CLJ_CTRL_REG1_wait_comp_en_END (3)
#define REG_CLJ_CTRL_REG1_wait_comp_sel_START (4)
#define REG_CLJ_CTRL_REG1_wait_comp_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data_eco_en : 1;
        unsigned char eco_data_clr : 1;
        unsigned char coul_charge_en : 1;
        unsigned char coul_charge_flag : 1;
        unsigned char reserved : 4;
    } reg;
} REG_CLJ_CTRL_REG2_UNION;
#endif
#define REG_CLJ_CTRL_REG2_data_eco_en_START (0)
#define REG_CLJ_CTRL_REG2_data_eco_en_END (0)
#define REG_CLJ_CTRL_REG2_eco_data_clr_START (1)
#define REG_CLJ_CTRL_REG2_eco_data_clr_END (1)
#define REG_CLJ_CTRL_REG2_coul_charge_en_START (2)
#define REG_CLJ_CTRL_REG2_coul_charge_en_END (2)
#define REG_CLJ_CTRL_REG2_coul_charge_flag_START (3)
#define REG_CLJ_CTRL_REG2_coul_charge_flag_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_en : 1;
        unsigned char slide_refresh_en : 1;
        unsigned char slide_cnt_cfg : 2;
        unsigned char slide_ready : 1;
        unsigned char reserved : 3;
    } reg;
} REG_CLJ_CTRL_REG3_UNION;
#endif
#define REG_CLJ_CTRL_REG3_slide_en_START (0)
#define REG_CLJ_CTRL_REG3_slide_en_END (0)
#define REG_CLJ_CTRL_REG3_slide_refresh_en_START (1)
#define REG_CLJ_CTRL_REG3_slide_refresh_en_END (1)
#define REG_CLJ_CTRL_REG3_slide_cnt_cfg_START (2)
#define REG_CLJ_CTRL_REG3_slide_cnt_cfg_END (3)
#define REG_CLJ_CTRL_REG3_slide_ready_START (4)
#define REG_CLJ_CTRL_REG3_slide_ready_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_cnt_data_out0 : 8;
    } reg;
} REG_SLIDE_CNT_DATA_OUT0_UNION;
#endif
#define REG_SLIDE_CNT_DATA_OUT0_slide_cnt_data_out0_START (0)
#define REG_SLIDE_CNT_DATA_OUT0_slide_cnt_data_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_cnt_data_out1 : 8;
    } reg;
} REG_SLIDE_CNT_DATA_OUT1_UNION;
#endif
#define REG_SLIDE_CNT_DATA_OUT1_slide_cnt_data_out1_START (0)
#define REG_SLIDE_CNT_DATA_OUT1_slide_cnt_data_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_cnt_data_out2 : 4;
        unsigned char reserved : 4;
    } reg;
} REG_SLIDE_CNT_DATA_OUT2_UNION;
#endif
#define REG_SLIDE_CNT_DATA_OUT2_slide_cnt_data_out2_START (0)
#define REG_SLIDE_CNT_DATA_OUT2_slide_cnt_data_out2_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_ih_data0_out0 : 8;
    } reg;
} REG_SLIDE_IH_DATA0_OUT0_UNION;
#endif
#define REG_SLIDE_IH_DATA0_OUT0_slide_ih_data0_out0_START (0)
#define REG_SLIDE_IH_DATA0_OUT0_slide_ih_data0_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_ih_data0_out1 : 8;
    } reg;
} REG_SLIDE_IH_DATA0_OUT1_UNION;
#endif
#define REG_SLIDE_IH_DATA0_OUT1_slide_ih_data0_out1_START (0)
#define REG_SLIDE_IH_DATA0_OUT1_slide_ih_data0_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_ih_data0_out2 : 8;
    } reg;
} REG_SLIDE_IH_DATA0_OUT2_UNION;
#endif
#define REG_SLIDE_IH_DATA0_OUT2_slide_ih_data0_out2_START (0)
#define REG_SLIDE_IH_DATA0_OUT2_slide_ih_data0_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_ih_data1_out0 : 8;
    } reg;
} REG_SLIDE_IH_DATA1_OUT0_UNION;
#endif
#define REG_SLIDE_IH_DATA1_OUT0_slide_ih_data1_out0_START (0)
#define REG_SLIDE_IH_DATA1_OUT0_slide_ih_data1_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_ih_data1_out1 : 8;
    } reg;
} REG_SLIDE_IH_DATA1_OUT1_UNION;
#endif
#define REG_SLIDE_IH_DATA1_OUT1_slide_ih_data1_out1_START (0)
#define REG_SLIDE_IH_DATA1_OUT1_slide_ih_data1_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_ih_data1_out2 : 8;
    } reg;
} REG_SLIDE_IH_DATA1_OUT2_UNION;
#endif
#define REG_SLIDE_IH_DATA1_OUT2_slide_ih_data1_out2_START (0)
#define REG_SLIDE_IH_DATA1_OUT2_slide_ih_data1_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_ih_data2_out0 : 8;
    } reg;
} REG_SLIDE_IH_DATA2_OUT0_UNION;
#endif
#define REG_SLIDE_IH_DATA2_OUT0_slide_ih_data2_out0_START (0)
#define REG_SLIDE_IH_DATA2_OUT0_slide_ih_data2_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_ih_data2_out1 : 8;
    } reg;
} REG_SLIDE_IH_DATA2_OUT1_UNION;
#endif
#define REG_SLIDE_IH_DATA2_OUT1_slide_ih_data2_out1_START (0)
#define REG_SLIDE_IH_DATA2_OUT1_slide_ih_data2_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_ih_data2_out2 : 8;
    } reg;
} REG_SLIDE_IH_DATA2_OUT2_UNION;
#endif
#define REG_SLIDE_IH_DATA2_OUT2_slide_ih_data2_out2_START (0)
#define REG_SLIDE_IH_DATA2_OUT2_slide_ih_data2_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_ih_data3_out0 : 8;
    } reg;
} REG_SLIDE_IH_DATA3_OUT0_UNION;
#endif
#define REG_SLIDE_IH_DATA3_OUT0_slide_ih_data3_out0_START (0)
#define REG_SLIDE_IH_DATA3_OUT0_slide_ih_data3_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_ih_data3_out1 : 8;
    } reg;
} REG_SLIDE_IH_DATA3_OUT1_UNION;
#endif
#define REG_SLIDE_IH_DATA3_OUT1_slide_ih_data3_out1_START (0)
#define REG_SLIDE_IH_DATA3_OUT1_slide_ih_data3_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_ih_data3_out2 : 8;
    } reg;
} REG_SLIDE_IH_DATA3_OUT2_UNION;
#endif
#define REG_SLIDE_IH_DATA3_OUT2_slide_ih_data3_out2_START (0)
#define REG_SLIDE_IH_DATA3_OUT2_slide_ih_data3_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vh_data0_out0 : 8;
    } reg;
} REG_SLIDE_VH_DATA0_OUT0_UNION;
#endif
#define REG_SLIDE_VH_DATA0_OUT0_slide_vh_data0_out0_START (0)
#define REG_SLIDE_VH_DATA0_OUT0_slide_vh_data0_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vh_data0_out1 : 8;
    } reg;
} REG_SLIDE_VH_DATA0_OUT1_UNION;
#endif
#define REG_SLIDE_VH_DATA0_OUT1_slide_vh_data0_out1_START (0)
#define REG_SLIDE_VH_DATA0_OUT1_slide_vh_data0_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vh_data0_out2 : 8;
    } reg;
} REG_SLIDE_VH_DATA0_OUT2_UNION;
#endif
#define REG_SLIDE_VH_DATA0_OUT2_slide_vh_data0_out2_START (0)
#define REG_SLIDE_VH_DATA0_OUT2_slide_vh_data0_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vh_data1_out0 : 8;
    } reg;
} REG_SLIDE_VH_DATA1_OUT0_UNION;
#endif
#define REG_SLIDE_VH_DATA1_OUT0_slide_vh_data1_out0_START (0)
#define REG_SLIDE_VH_DATA1_OUT0_slide_vh_data1_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vh_data1_out1 : 8;
    } reg;
} REG_SLIDE_VH_DATA1_OUT1_UNION;
#endif
#define REG_SLIDE_VH_DATA1_OUT1_slide_vh_data1_out1_START (0)
#define REG_SLIDE_VH_DATA1_OUT1_slide_vh_data1_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vh_data1_out2 : 8;
    } reg;
} REG_SLIDE_VH_DATA1_OUT2_UNION;
#endif
#define REG_SLIDE_VH_DATA1_OUT2_slide_vh_data1_out2_START (0)
#define REG_SLIDE_VH_DATA1_OUT2_slide_vh_data1_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vh_data2_out0 : 8;
    } reg;
} REG_SLIDE_VH_DATA2_OUT0_UNION;
#endif
#define REG_SLIDE_VH_DATA2_OUT0_slide_vh_data2_out0_START (0)
#define REG_SLIDE_VH_DATA2_OUT0_slide_vh_data2_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vh_data2_out1 : 8;
    } reg;
} REG_SLIDE_VH_DATA2_OUT1_UNION;
#endif
#define REG_SLIDE_VH_DATA2_OUT1_slide_vh_data2_out1_START (0)
#define REG_SLIDE_VH_DATA2_OUT1_slide_vh_data2_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vh_data2_out2 : 8;
    } reg;
} REG_SLIDE_VH_DATA2_OUT2_UNION;
#endif
#define REG_SLIDE_VH_DATA2_OUT2_slide_vh_data2_out2_START (0)
#define REG_SLIDE_VH_DATA2_OUT2_slide_vh_data2_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vh_data3_out0 : 8;
    } reg;
} REG_SLIDE_VH_DATA3_OUT0_UNION;
#endif
#define REG_SLIDE_VH_DATA3_OUT0_slide_vh_data3_out0_START (0)
#define REG_SLIDE_VH_DATA3_OUT0_slide_vh_data3_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vh_data3_out1 : 8;
    } reg;
} REG_SLIDE_VH_DATA3_OUT1_UNION;
#endif
#define REG_SLIDE_VH_DATA3_OUT1_slide_vh_data3_out1_START (0)
#define REG_SLIDE_VH_DATA3_OUT1_slide_vh_data3_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vh_data3_out2 : 8;
    } reg;
} REG_SLIDE_VH_DATA3_OUT2_UNION;
#endif
#define REG_SLIDE_VH_DATA3_OUT2_slide_vh_data3_out2_START (0)
#define REG_SLIDE_VH_DATA3_OUT2_slide_vh_data3_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_il_data0_out0 : 8;
    } reg;
} REG_SLIDE_IL_DATA0_OUT0_UNION;
#endif
#define REG_SLIDE_IL_DATA0_OUT0_slide_il_data0_out0_START (0)
#define REG_SLIDE_IL_DATA0_OUT0_slide_il_data0_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_il_data0_out1 : 8;
    } reg;
} REG_SLIDE_IL_DATA0_OUT1_UNION;
#endif
#define REG_SLIDE_IL_DATA0_OUT1_slide_il_data0_out1_START (0)
#define REG_SLIDE_IL_DATA0_OUT1_slide_il_data0_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_il_data0_out2 : 8;
    } reg;
} REG_SLIDE_IL_DATA0_OUT2_UNION;
#endif
#define REG_SLIDE_IL_DATA0_OUT2_slide_il_data0_out2_START (0)
#define REG_SLIDE_IL_DATA0_OUT2_slide_il_data0_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_il_data1_out0 : 8;
    } reg;
} REG_SLIDE_IL_DATA1_OUT0_UNION;
#endif
#define REG_SLIDE_IL_DATA1_OUT0_slide_il_data1_out0_START (0)
#define REG_SLIDE_IL_DATA1_OUT0_slide_il_data1_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_il_data1_out1 : 8;
    } reg;
} REG_SLIDE_IL_DATA1_OUT1_UNION;
#endif
#define REG_SLIDE_IL_DATA1_OUT1_slide_il_data1_out1_START (0)
#define REG_SLIDE_IL_DATA1_OUT1_slide_il_data1_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_il_data1_out2 : 8;
    } reg;
} REG_SLIDE_IL_DATA1_OUT2_UNION;
#endif
#define REG_SLIDE_IL_DATA1_OUT2_slide_il_data1_out2_START (0)
#define REG_SLIDE_IL_DATA1_OUT2_slide_il_data1_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_il_data2_out0 : 8;
    } reg;
} REG_SLIDE_IL_DATA2_OUT0_UNION;
#endif
#define REG_SLIDE_IL_DATA2_OUT0_slide_il_data2_out0_START (0)
#define REG_SLIDE_IL_DATA2_OUT0_slide_il_data2_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_il_data2_out1 : 8;
    } reg;
} REG_SLIDE_IL_DATA2_OUT1_UNION;
#endif
#define REG_SLIDE_IL_DATA2_OUT1_slide_il_data2_out1_START (0)
#define REG_SLIDE_IL_DATA2_OUT1_slide_il_data2_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_il_data2_out2 : 8;
    } reg;
} REG_SLIDE_IL_DATA2_OUT2_UNION;
#endif
#define REG_SLIDE_IL_DATA2_OUT2_slide_il_data2_out2_START (0)
#define REG_SLIDE_IL_DATA2_OUT2_slide_il_data2_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_il_data3_out0 : 8;
    } reg;
} REG_SLIDE_IL_DATA3_OUT0_UNION;
#endif
#define REG_SLIDE_IL_DATA3_OUT0_slide_il_data3_out0_START (0)
#define REG_SLIDE_IL_DATA3_OUT0_slide_il_data3_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_il_data3_out1 : 8;
    } reg;
} REG_SLIDE_IL_DATA3_OUT1_UNION;
#endif
#define REG_SLIDE_IL_DATA3_OUT1_slide_il_data3_out1_START (0)
#define REG_SLIDE_IL_DATA3_OUT1_slide_il_data3_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_il_data3_out2 : 8;
    } reg;
} REG_SLIDE_IL_DATA3_OUT2_UNION;
#endif
#define REG_SLIDE_IL_DATA3_OUT2_slide_il_data3_out2_START (0)
#define REG_SLIDE_IL_DATA3_OUT2_slide_il_data3_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vl_data0_out0 : 8;
    } reg;
} REG_SLIDE_VL_DATA0_OUT0_UNION;
#endif
#define REG_SLIDE_VL_DATA0_OUT0_slide_vl_data0_out0_START (0)
#define REG_SLIDE_VL_DATA0_OUT0_slide_vl_data0_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vl_data0_out1 : 8;
    } reg;
} REG_SLIDE_VL_DATA0_OUT1_UNION;
#endif
#define REG_SLIDE_VL_DATA0_OUT1_slide_vl_data0_out1_START (0)
#define REG_SLIDE_VL_DATA0_OUT1_slide_vl_data0_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vl_data0_out2 : 8;
    } reg;
} REG_SLIDE_VL_DATA0_OUT2_UNION;
#endif
#define REG_SLIDE_VL_DATA0_OUT2_slide_vl_data0_out2_START (0)
#define REG_SLIDE_VL_DATA0_OUT2_slide_vl_data0_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vl_data1_out0 : 8;
    } reg;
} REG_SLIDE_VL_DATA1_OUT0_UNION;
#endif
#define REG_SLIDE_VL_DATA1_OUT0_slide_vl_data1_out0_START (0)
#define REG_SLIDE_VL_DATA1_OUT0_slide_vl_data1_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vl_data1_out1 : 8;
    } reg;
} REG_SLIDE_VL_DATA1_OUT1_UNION;
#endif
#define REG_SLIDE_VL_DATA1_OUT1_slide_vl_data1_out1_START (0)
#define REG_SLIDE_VL_DATA1_OUT1_slide_vl_data1_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vl_data1_out2 : 8;
    } reg;
} REG_SLIDE_VL_DATA1_OUT2_UNION;
#endif
#define REG_SLIDE_VL_DATA1_OUT2_slide_vl_data1_out2_START (0)
#define REG_SLIDE_VL_DATA1_OUT2_slide_vl_data1_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vl_data2_out0 : 8;
    } reg;
} REG_SLIDE_VL_DATA2_OUT0_UNION;
#endif
#define REG_SLIDE_VL_DATA2_OUT0_slide_vl_data2_out0_START (0)
#define REG_SLIDE_VL_DATA2_OUT0_slide_vl_data2_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vl_data2_out1 : 8;
    } reg;
} REG_SLIDE_VL_DATA2_OUT1_UNION;
#endif
#define REG_SLIDE_VL_DATA2_OUT1_slide_vl_data2_out1_START (0)
#define REG_SLIDE_VL_DATA2_OUT1_slide_vl_data2_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vl_data2_out2 : 8;
    } reg;
} REG_SLIDE_VL_DATA2_OUT2_UNION;
#endif
#define REG_SLIDE_VL_DATA2_OUT2_slide_vl_data2_out2_START (0)
#define REG_SLIDE_VL_DATA2_OUT2_slide_vl_data2_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vl_data3_out0 : 8;
    } reg;
} REG_SLIDE_VL_DATA3_OUT0_UNION;
#endif
#define REG_SLIDE_VL_DATA3_OUT0_slide_vl_data3_out0_START (0)
#define REG_SLIDE_VL_DATA3_OUT0_slide_vl_data3_out0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vl_data3_out1 : 8;
    } reg;
} REG_SLIDE_VL_DATA3_OUT1_UNION;
#endif
#define REG_SLIDE_VL_DATA3_OUT1_slide_vl_data3_out1_START (0)
#define REG_SLIDE_VL_DATA3_OUT1_slide_vl_data3_out1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slide_vl_data3_out2 : 8;
    } reg;
} REG_SLIDE_VL_DATA3_OUT2_UNION;
#endif
#define REG_SLIDE_VL_DATA3_OUT2_slide_vl_data3_out2_START (0)
#define REG_SLIDE_VL_DATA3_OUT2_slide_vl_data3_out2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_l_coul_flag : 1;
        unsigned char irq_h_coul_flag : 1;
        unsigned char reserved : 6;
    } reg;
} REG_COUL_IRQ_FLAG_UNION;
#endif
#define REG_COUL_IRQ_FLAG_irq_l_coul_flag_START (0)
#define REG_COUL_IRQ_FLAG_irq_l_coul_flag_END (0)
#define REG_COUL_IRQ_FLAG_irq_h_coul_flag_START (1)
#define REG_COUL_IRQ_FLAG_irq_h_coul_flag_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_h_coul_cl_gate_flag : 1;
        unsigned char irq_h_coul_cl_out_flag : 1;
        unsigned char irq_h_coul_cl_in_flag : 1;
        unsigned char irq_h_coul_v_gate_flag : 1;
        unsigned char irq_h_coul_i_in_flag : 1;
        unsigned char irq_h_coul_i_out_flag : 1;
        unsigned char irq_h_vbat_drop_flag : 1;
        unsigned char reserved : 1;
    } reg;
} REG_COUL_H_IRQ_FLAG_UNION;
#endif
#define REG_COUL_H_IRQ_FLAG_irq_h_coul_cl_gate_flag_START (0)
#define REG_COUL_H_IRQ_FLAG_irq_h_coul_cl_gate_flag_END (0)
#define REG_COUL_H_IRQ_FLAG_irq_h_coul_cl_out_flag_START (1)
#define REG_COUL_H_IRQ_FLAG_irq_h_coul_cl_out_flag_END (1)
#define REG_COUL_H_IRQ_FLAG_irq_h_coul_cl_in_flag_START (2)
#define REG_COUL_H_IRQ_FLAG_irq_h_coul_cl_in_flag_END (2)
#define REG_COUL_H_IRQ_FLAG_irq_h_coul_v_gate_flag_START (3)
#define REG_COUL_H_IRQ_FLAG_irq_h_coul_v_gate_flag_END (3)
#define REG_COUL_H_IRQ_FLAG_irq_h_coul_i_in_flag_START (4)
#define REG_COUL_H_IRQ_FLAG_irq_h_coul_i_in_flag_END (4)
#define REG_COUL_H_IRQ_FLAG_irq_h_coul_i_out_flag_START (5)
#define REG_COUL_H_IRQ_FLAG_irq_h_coul_i_out_flag_END (5)
#define REG_COUL_H_IRQ_FLAG_irq_h_vbat_drop_flag_START (6)
#define REG_COUL_H_IRQ_FLAG_irq_h_vbat_drop_flag_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_l_coul_cl_gate_flag : 1;
        unsigned char irq_l_coul_cl_out_flag : 1;
        unsigned char irq_l_coul_cl_in_flag : 1;
        unsigned char irq_l_coul_v_gate_flag : 1;
        unsigned char irq_l_coul_i_in_flag : 1;
        unsigned char irq_l_coul_i_out_flag : 1;
        unsigned char irq_l_vbat_drop_flag : 1;
        unsigned char reserved : 1;
    } reg;
} REG_COUL_L_IRQ_FLAG_UNION;
#endif
#define REG_COUL_L_IRQ_FLAG_irq_l_coul_cl_gate_flag_START (0)
#define REG_COUL_L_IRQ_FLAG_irq_l_coul_cl_gate_flag_END (0)
#define REG_COUL_L_IRQ_FLAG_irq_l_coul_cl_out_flag_START (1)
#define REG_COUL_L_IRQ_FLAG_irq_l_coul_cl_out_flag_END (1)
#define REG_COUL_L_IRQ_FLAG_irq_l_coul_cl_in_flag_START (2)
#define REG_COUL_L_IRQ_FLAG_irq_l_coul_cl_in_flag_END (2)
#define REG_COUL_L_IRQ_FLAG_irq_l_coul_v_gate_flag_START (3)
#define REG_COUL_L_IRQ_FLAG_irq_l_coul_v_gate_flag_END (3)
#define REG_COUL_L_IRQ_FLAG_irq_l_coul_i_in_flag_START (4)
#define REG_COUL_L_IRQ_FLAG_irq_l_coul_i_in_flag_END (4)
#define REG_COUL_L_IRQ_FLAG_irq_l_coul_i_out_flag_START (5)
#define REG_COUL_L_IRQ_FLAG_irq_l_coul_i_out_flag_END (5)
#define REG_COUL_L_IRQ_FLAG_irq_l_vbat_drop_flag_START (6)
#define REG_COUL_L_IRQ_FLAG_irq_l_vbat_drop_flag_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_irq_l_coul_mask : 1;
        unsigned char sc_irq_h_coul_mask : 1;
        unsigned char reserved : 6;
    } reg;
} REG_COUL_IRQ_MASK_UNION;
#endif
#define REG_COUL_IRQ_MASK_sc_irq_l_coul_mask_START (0)
#define REG_COUL_IRQ_MASK_sc_irq_l_coul_mask_END (0)
#define REG_COUL_IRQ_MASK_sc_irq_h_coul_mask_START (1)
#define REG_COUL_IRQ_MASK_sc_irq_h_coul_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_irq_h_coul_cl_gate_mask : 1;
        unsigned char sc_irq_h_coul_cl_out_mask : 1;
        unsigned char sc_irq_h_coul_cl_in_mask : 1;
        unsigned char sc_irq_h_coul_v_gate_mask : 1;
        unsigned char sc_irq_h_coul_i_in_mask : 1;
        unsigned char sc_irq_h_coul_i_out_mask : 1;
        unsigned char sc_irq_h_vbat_drop_mask : 1;
        unsigned char reserved : 1;
    } reg;
} REG_COUL_H_IRQ_MASK_UNION;
#endif
#define REG_COUL_H_IRQ_MASK_sc_irq_h_coul_cl_gate_mask_START (0)
#define REG_COUL_H_IRQ_MASK_sc_irq_h_coul_cl_gate_mask_END (0)
#define REG_COUL_H_IRQ_MASK_sc_irq_h_coul_cl_out_mask_START (1)
#define REG_COUL_H_IRQ_MASK_sc_irq_h_coul_cl_out_mask_END (1)
#define REG_COUL_H_IRQ_MASK_sc_irq_h_coul_cl_in_mask_START (2)
#define REG_COUL_H_IRQ_MASK_sc_irq_h_coul_cl_in_mask_END (2)
#define REG_COUL_H_IRQ_MASK_sc_irq_h_coul_v_gate_mask_START (3)
#define REG_COUL_H_IRQ_MASK_sc_irq_h_coul_v_gate_mask_END (3)
#define REG_COUL_H_IRQ_MASK_sc_irq_h_coul_i_in_mask_START (4)
#define REG_COUL_H_IRQ_MASK_sc_irq_h_coul_i_in_mask_END (4)
#define REG_COUL_H_IRQ_MASK_sc_irq_h_coul_i_out_mask_START (5)
#define REG_COUL_H_IRQ_MASK_sc_irq_h_coul_i_out_mask_END (5)
#define REG_COUL_H_IRQ_MASK_sc_irq_h_vbat_drop_mask_START (6)
#define REG_COUL_H_IRQ_MASK_sc_irq_h_vbat_drop_mask_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_irq_l_coul_cl_gate_mask : 1;
        unsigned char sc_irq_l_coul_cl_out_mask : 1;
        unsigned char sc_irq_l_coul_cl_in_mask : 1;
        unsigned char sc_irq_l_coul_v_gate_mask : 1;
        unsigned char sc_irq_l_coul_i_in_mask : 1;
        unsigned char sc_irq_l_coul_i_out_mask : 1;
        unsigned char sc_irq_l_vbat_drop_mask : 1;
        unsigned char reserved : 1;
    } reg;
} REG_COUL_L_IRQ_MASK_UNION;
#endif
#define REG_COUL_L_IRQ_MASK_sc_irq_l_coul_cl_gate_mask_START (0)
#define REG_COUL_L_IRQ_MASK_sc_irq_l_coul_cl_gate_mask_END (0)
#define REG_COUL_L_IRQ_MASK_sc_irq_l_coul_cl_out_mask_START (1)
#define REG_COUL_L_IRQ_MASK_sc_irq_l_coul_cl_out_mask_END (1)
#define REG_COUL_L_IRQ_MASK_sc_irq_l_coul_cl_in_mask_START (2)
#define REG_COUL_L_IRQ_MASK_sc_irq_l_coul_cl_in_mask_END (2)
#define REG_COUL_L_IRQ_MASK_sc_irq_l_coul_v_gate_mask_START (3)
#define REG_COUL_L_IRQ_MASK_sc_irq_l_coul_v_gate_mask_END (3)
#define REG_COUL_L_IRQ_MASK_sc_irq_l_coul_i_in_mask_START (4)
#define REG_COUL_L_IRQ_MASK_sc_irq_l_coul_i_in_mask_END (4)
#define REG_COUL_L_IRQ_MASK_sc_irq_l_coul_i_out_mask_START (5)
#define REG_COUL_L_IRQ_MASK_sc_irq_l_coul_i_out_mask_END (5)
#define REG_COUL_L_IRQ_MASK_sc_irq_l_vbat_drop_mask_START (6)
#define REG_COUL_L_IRQ_MASK_sc_irq_l_vbat_drop_mask_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_h_coul_cl_gate_status : 1;
        unsigned char irq_h_coul_cl_out_status : 1;
        unsigned char irq_h_coul_cl_in_status : 1;
        unsigned char irq_h_coul_v_gate_status : 1;
        unsigned char irq_h_coul_i_in_status : 1;
        unsigned char irq_h_coul_i_out_status : 1;
        unsigned char irq_h_vbat_drop_status : 1;
        unsigned char reserved : 1;
    } reg;
} REG_COUL_H_IRQ_STATUS_UNION;
#endif
#define REG_COUL_H_IRQ_STATUS_irq_h_coul_cl_gate_status_START (0)
#define REG_COUL_H_IRQ_STATUS_irq_h_coul_cl_gate_status_END (0)
#define REG_COUL_H_IRQ_STATUS_irq_h_coul_cl_out_status_START (1)
#define REG_COUL_H_IRQ_STATUS_irq_h_coul_cl_out_status_END (1)
#define REG_COUL_H_IRQ_STATUS_irq_h_coul_cl_in_status_START (2)
#define REG_COUL_H_IRQ_STATUS_irq_h_coul_cl_in_status_END (2)
#define REG_COUL_H_IRQ_STATUS_irq_h_coul_v_gate_status_START (3)
#define REG_COUL_H_IRQ_STATUS_irq_h_coul_v_gate_status_END (3)
#define REG_COUL_H_IRQ_STATUS_irq_h_coul_i_in_status_START (4)
#define REG_COUL_H_IRQ_STATUS_irq_h_coul_i_in_status_END (4)
#define REG_COUL_H_IRQ_STATUS_irq_h_coul_i_out_status_START (5)
#define REG_COUL_H_IRQ_STATUS_irq_h_coul_i_out_status_END (5)
#define REG_COUL_H_IRQ_STATUS_irq_h_vbat_drop_status_START (6)
#define REG_COUL_H_IRQ_STATUS_irq_h_vbat_drop_status_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_l_coul_cl_gate_status : 1;
        unsigned char irq_l_coul_cl_out_status : 1;
        unsigned char irq_l_coul_cl_in_status : 1;
        unsigned char irq_l_coul_v_gate_status : 1;
        unsigned char irq_l_coul_i_in_status : 1;
        unsigned char irq_l_coul_i_out_status : 1;
        unsigned char irq_l_vbat_drop_status : 1;
        unsigned char reserved : 1;
    } reg;
} REG_COUL_L_IRQ_STATUS_UNION;
#endif
#define REG_COUL_L_IRQ_STATUS_irq_l_coul_cl_gate_status_START (0)
#define REG_COUL_L_IRQ_STATUS_irq_l_coul_cl_gate_status_END (0)
#define REG_COUL_L_IRQ_STATUS_irq_l_coul_cl_out_status_START (1)
#define REG_COUL_L_IRQ_STATUS_irq_l_coul_cl_out_status_END (1)
#define REG_COUL_L_IRQ_STATUS_irq_l_coul_cl_in_status_START (2)
#define REG_COUL_L_IRQ_STATUS_irq_l_coul_cl_in_status_END (2)
#define REG_COUL_L_IRQ_STATUS_irq_l_coul_v_gate_status_START (3)
#define REG_COUL_L_IRQ_STATUS_irq_l_coul_v_gate_status_END (3)
#define REG_COUL_L_IRQ_STATUS_irq_l_coul_i_in_status_START (4)
#define REG_COUL_L_IRQ_STATUS_irq_l_coul_i_in_status_END (4)
#define REG_COUL_L_IRQ_STATUS_irq_l_coul_i_out_status_START (5)
#define REG_COUL_L_IRQ_STATUS_irq_l_coul_i_out_status_END (5)
#define REG_COUL_L_IRQ_STATUS_irq_l_vbat_drop_status_START (6)
#define REG_COUL_L_IRQ_STATUS_irq_l_vbat_drop_status_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_coul_rd_req : 1;
        unsigned char reserved : 7;
    } reg;
} REG_COUL_RD_REQ_UNION;
#endif
#define REG_COUL_RD_REQ_sc_coul_rd_req_START (0)
#define REG_COUL_RD_REQ_sc_coul_rd_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reflash_value_ctrl : 1;
        unsigned char eco_filter_time : 2;
        unsigned char reserved_0 : 1;
        unsigned char calibration_ctrl : 1;
        unsigned char reserved_1 : 3;
    } reg;
} REG_CLJ_CTRL_REG4_UNION;
#endif
#define REG_CLJ_CTRL_REG4_reflash_value_ctrl_START (0)
#define REG_CLJ_CTRL_REG4_reflash_value_ctrl_END (0)
#define REG_CLJ_CTRL_REG4_eco_filter_time_START (1)
#define REG_CLJ_CTRL_REG4_eco_filter_time_END (2)
#define REG_CLJ_CTRL_REG4_calibration_ctrl_START (4)
#define REG_CLJ_CTRL_REG4_calibration_ctrl_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_ocv_i_onoff : 1;
        unsigned char reg_data_clr : 1;
        unsigned char cali_auto_time : 2;
        unsigned char cali_auto_onoff_ctrl : 1;
        unsigned char reserved : 3;
    } reg;
} REG_CLJ_CTRL_REG5_UNION;
#endif
#define REG_CLJ_CTRL_REG5_pd_ocv_i_onoff_START (0)
#define REG_CLJ_CTRL_REG5_pd_ocv_i_onoff_END (0)
#define REG_CLJ_CTRL_REG5_reg_data_clr_START (1)
#define REG_CLJ_CTRL_REG5_reg_data_clr_END (1)
#define REG_CLJ_CTRL_REG5_cali_auto_time_START (2)
#define REG_CLJ_CTRL_REG5_cali_auto_time_END (3)
#define REG_CLJ_CTRL_REG5_cali_auto_onoff_ctrl_START (4)
#define REG_CLJ_CTRL_REG5_cali_auto_onoff_ctrl_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 1;
        unsigned char coul_average_sel : 1;
        unsigned char reserved_1 : 1;
        unsigned char debug_refresh_en : 1;
        unsigned char coul_i_data_rate_sel : 1;
        unsigned char coul_v_data_rate_sel : 1;
        unsigned char reserved_2 : 2;
    } reg;
} REG_CIC_CTRL_UNION;
#endif
#define REG_CIC_CTRL_coul_average_sel_START (1)
#define REG_CIC_CTRL_coul_average_sel_END (1)
#define REG_CIC_CTRL_debug_refresh_en_START (3)
#define REG_CIC_CTRL_debug_refresh_en_END (3)
#define REG_CIC_CTRL_coul_i_data_rate_sel_START (4)
#define REG_CIC_CTRL_coul_i_data_rate_sel_END (4)
#define REG_CIC_CTRL_coul_v_data_rate_sel_START (5)
#define REG_CIC_CTRL_coul_v_data_rate_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char coul_mstate : 4;
        unsigned char reserved : 4;
    } reg;
} REG_STATE_TEST_UNION;
#endif
#define REG_STATE_TEST_coul_mstate_START (0)
#define REG_STATE_TEST_coul_mstate_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char il_cic_clk_sel : 1;
        unsigned char ih_cic_clk_sel : 1;
        unsigned char v_cic_clk_sel : 1;
        unsigned char reserved : 1;
        unsigned char cali_en_i : 1;
        unsigned char cali_en_i_force : 1;
        unsigned char cali_en_v_force : 1;
        unsigned char cali_en_v : 1;
    } reg;
} REG_CLJ_DEBUG0_UNION;
#endif
#define REG_CLJ_DEBUG0_il_cic_clk_sel_START (0)
#define REG_CLJ_DEBUG0_il_cic_clk_sel_END (0)
#define REG_CLJ_DEBUG0_ih_cic_clk_sel_START (1)
#define REG_CLJ_DEBUG0_ih_cic_clk_sel_END (1)
#define REG_CLJ_DEBUG0_v_cic_clk_sel_START (2)
#define REG_CLJ_DEBUG0_v_cic_clk_sel_END (2)
#define REG_CLJ_DEBUG0_cali_en_i_START (4)
#define REG_CLJ_DEBUG0_cali_en_i_END (4)
#define REG_CLJ_DEBUG0_cali_en_i_force_START (5)
#define REG_CLJ_DEBUG0_cali_en_i_force_END (5)
#define REG_CLJ_DEBUG0_cali_en_v_force_START (6)
#define REG_CLJ_DEBUG0_cali_en_v_force_END (6)
#define REG_CLJ_DEBUG0_cali_en_v_START (7)
#define REG_CLJ_DEBUG0_cali_en_v_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_coul_always_off : 1;
        unsigned char voltage_coul_always_off : 1;
        unsigned char coul_ctrl_onoff : 1;
        unsigned char coul_ocv_onoff : 1;
        unsigned char reserved : 4;
    } reg;
} REG_CLJ_DEBUG1_UNION;
#endif
#define REG_CLJ_DEBUG1_current_coul_always_off_START (0)
#define REG_CLJ_DEBUG1_current_coul_always_off_END (0)
#define REG_CLJ_DEBUG1_voltage_coul_always_off_START (1)
#define REG_CLJ_DEBUG1_voltage_coul_always_off_END (1)
#define REG_CLJ_DEBUG1_coul_ctrl_onoff_START (2)
#define REG_CLJ_DEBUG1_coul_ctrl_onoff_END (2)
#define REG_CLJ_DEBUG1_coul_ocv_onoff_START (3)
#define REG_CLJ_DEBUG1_coul_ocv_onoff_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char debug_write_pro : 8;
    } reg;
} REG_DEBUG_WRITE_PRO_UNION;
#endif
#define REG_DEBUG_WRITE_PRO_debug_write_pro_START (0)
#define REG_DEBUG_WRITE_PRO_debug_write_pro_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_coul_clk_cali_en : 1;
        unsigned char sc_coul_clk_cali_disable : 1;
        unsigned char reserved : 6;
    } reg;
} REG_COUL_CLK_CALI_EN_UNION;
#endif
#define REG_COUL_CLK_CALI_EN_sc_coul_clk_cali_en_START (0)
#define REG_COUL_CLK_CALI_EN_sc_coul_clk_cali_en_END (0)
#define REG_COUL_CLK_CALI_EN_sc_coul_clk_cali_disable_START (1)
#define REG_COUL_CLK_CALI_EN_sc_coul_clk_cali_disable_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char coul_debug_data_sel : 3;
        unsigned char reserved : 5;
    } reg;
} REG_DEBUG_CIC_DATA_SEL_UNION;
#endif
#define REG_DEBUG_CIC_DATA_SEL_coul_debug_data_sel_START (0)
#define REG_DEBUG_CIC_DATA_SEL_coul_debug_data_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_coul_tb_sel : 6;
        unsigned char sc_coul_tb_en : 1;
        unsigned char coul_tb_sig : 1;
    } reg;
} REG_COUL_TB_CFG_UNION;
#endif
#define REG_COUL_TB_CFG_sc_coul_tb_sel_START (0)
#define REG_COUL_TB_CFG_sc_coul_tb_sel_END (5)
#define REG_COUL_TB_CFG_sc_coul_tb_en_START (6)
#define REG_COUL_TB_CFG_sc_coul_tb_en_END (6)
#define REG_COUL_TB_CFG_coul_tb_sig_START (7)
#define REG_COUL_TB_CFG_coul_tb_sig_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char coul_i_tb_bus0 : 8;
    } reg;
} REG_COUL_I_TB_BUS0_UNION;
#endif
#define REG_COUL_I_TB_BUS0_coul_i_tb_bus0_START (0)
#define REG_COUL_I_TB_BUS0_coul_i_tb_bus0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char coul_i_tb_bus1 : 8;
    } reg;
} REG_COUL_I_TB_BUS1_UNION;
#endif
#define REG_COUL_I_TB_BUS1_coul_i_tb_bus1_START (0)
#define REG_COUL_I_TB_BUS1_coul_i_tb_bus1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char coul_i_tb_bus2 : 8;
    } reg;
} REG_COUL_I_TB_BUS2_UNION;
#endif
#define REG_COUL_I_TB_BUS2_coul_i_tb_bus2_START (0)
#define REG_COUL_I_TB_BUS2_coul_i_tb_bus2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char coul_v_tb_bus0 : 8;
    } reg;
} REG_COUL_V_TB_BUS0_UNION;
#endif
#define REG_COUL_V_TB_BUS0_coul_v_tb_bus0_START (0)
#define REG_COUL_V_TB_BUS0_coul_v_tb_bus0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char coul_v_tb_bus1 : 8;
    } reg;
} REG_COUL_V_TB_BUS1_UNION;
#endif
#define REG_COUL_V_TB_BUS1_coul_v_tb_bus1_START (0)
#define REG_COUL_V_TB_BUS1_coul_v_tb_bus1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char coul_v_tb_bus2 : 8;
    } reg;
} REG_COUL_V_TB_BUS2_UNION;
#endif
#define REG_COUL_V_TB_BUS2_coul_v_tb_bus2_START (0)
#define REG_COUL_V_TB_BUS2_coul_v_tb_bus2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_int_s0 : 8;
    } reg;
} REG_V_INT0_UNION;
#endif
#define REG_V_INT0_v_int_s0_START (0)
#define REG_V_INT0_v_int_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_int_s1 : 8;
    } reg;
} REG_V_INT1_UNION;
#endif
#define REG_V_INT1_v_int_s1_START (0)
#define REG_V_INT1_v_int_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_int_s2 : 8;
    } reg;
} REG_V_INT2_UNION;
#endif
#define REG_V_INT2_v_int_s2_START (0)
#define REG_V_INT2_v_int_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char i_out_gate_s0 : 8;
    } reg;
} REG_I_OUT_GATE0_UNION;
#endif
#define REG_I_OUT_GATE0_i_out_gate_s0_START (0)
#define REG_I_OUT_GATE0_i_out_gate_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char i_out_gate_s1 : 8;
    } reg;
} REG_I_OUT_GATE1_UNION;
#endif
#define REG_I_OUT_GATE1_i_out_gate_s1_START (0)
#define REG_I_OUT_GATE1_i_out_gate_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char i_out_gate_s2 : 8;
    } reg;
} REG_I_OUT_GATE2_UNION;
#endif
#define REG_I_OUT_GATE2_i_out_gate_s2_START (0)
#define REG_I_OUT_GATE2_i_out_gate_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char i_in_gate_s0 : 8;
    } reg;
} REG_I_IN_GATE0_UNION;
#endif
#define REG_I_IN_GATE0_i_in_gate_s0_START (0)
#define REG_I_IN_GATE0_i_in_gate_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char i_in_gate_s1 : 8;
    } reg;
} REG_I_IN_GATE1_UNION;
#endif
#define REG_I_IN_GATE1_i_in_gate_s1_START (0)
#define REG_I_IN_GATE1_i_in_gate_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char i_in_gate_s2 : 8;
    } reg;
} REG_I_IN_GATE2_UNION;
#endif
#define REG_I_IN_GATE2_i_in_gate_s2_START (0)
#define REG_I_IN_GATE2_i_in_gate_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_int_s0 : 8;
    } reg;
} REG_CL_INT0_UNION;
#endif
#define REG_CL_INT0_cl_int_s0_START (0)
#define REG_CL_INT0_cl_int_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_int_s1 : 8;
    } reg;
} REG_CL_INT1_UNION;
#endif
#define REG_CL_INT1_cl_int_s1_START (0)
#define REG_CL_INT1_cl_int_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_int_s2 : 8;
    } reg;
} REG_CL_INT2_UNION;
#endif
#define REG_CL_INT2_cl_int_s2_START (0)
#define REG_CL_INT2_cl_int_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_int_s3 : 8;
    } reg;
} REG_CL_INT3_UNION;
#endif
#define REG_CL_INT3_cl_int_s3_START (0)
#define REG_CL_INT3_cl_int_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_int_s4 : 8;
    } reg;
} REG_CL_INT4_UNION;
#endif
#define REG_CL_INT4_cl_int_s4_START (0)
#define REG_CL_INT4_cl_int_s4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtc_ocv_out_pre4 : 2;
        unsigned char rtc_ocv_out_pre3 : 2;
        unsigned char rtc_ocv_out_pre2 : 2;
        unsigned char rtc_ocv_out_pre1 : 2;
    } reg;
} REG_RTC_OCV_OUT_UNION;
#endif
#define REG_RTC_OCV_OUT_rtc_ocv_out_pre4_START (0)
#define REG_RTC_OCV_OUT_rtc_ocv_out_pre4_END (1)
#define REG_RTC_OCV_OUT_rtc_ocv_out_pre3_START (2)
#define REG_RTC_OCV_OUT_rtc_ocv_out_pre3_END (3)
#define REG_RTC_OCV_OUT_rtc_ocv_out_pre2_START (4)
#define REG_RTC_OCV_OUT_rtc_ocv_out_pre2_END (5)
#define REG_RTC_OCV_OUT_rtc_ocv_out_pre1_START (6)
#define REG_RTC_OCV_OUT_rtc_ocv_out_pre1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rd_sync_pro : 8;
    } reg;
} REG_RD_SYNC_PRO_UNION;
#endif
#define REG_RD_SYNC_PRO_rd_sync_pro_START (0)
#define REG_RD_SYNC_PRO_rd_sync_pro_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rd_sync_sel : 1;
        unsigned char reserved : 7;
    } reg;
} REG_RD_SYNC_SEL_UNION;
#endif
#define REG_RD_SYNC_SEL_rd_sync_sel_START (0)
#define REG_RD_SYNC_SEL_rd_sync_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char il_cic_en_sel : 1;
        unsigned char ih_cic_en_sel : 1;
        unsigned char v_cic_en_sel : 1;
        unsigned char reserved_0 : 1;
        unsigned char sc_coul_cic_il_en : 1;
        unsigned char sc_coul_cic_ih_en : 1;
        unsigned char sc_coul_cic_v_en : 1;
        unsigned char reserved_1 : 1;
    } reg;
} REG_CIC_EN_DEBUG_UNION;
#endif
#define REG_CIC_EN_DEBUG_il_cic_en_sel_START (0)
#define REG_CIC_EN_DEBUG_il_cic_en_sel_END (0)
#define REG_CIC_EN_DEBUG_ih_cic_en_sel_START (1)
#define REG_CIC_EN_DEBUG_ih_cic_en_sel_END (1)
#define REG_CIC_EN_DEBUG_v_cic_en_sel_START (2)
#define REG_CIC_EN_DEBUG_v_cic_en_sel_END (2)
#define REG_CIC_EN_DEBUG_sc_coul_cic_il_en_START (4)
#define REG_CIC_EN_DEBUG_sc_coul_cic_il_en_END (4)
#define REG_CIC_EN_DEBUG_sc_coul_cic_ih_en_START (5)
#define REG_CIC_EN_DEBUG_sc_coul_cic_ih_en_END (5)
#define REG_CIC_EN_DEBUG_sc_coul_cic_v_en_START (6)
#define REG_CIC_EN_DEBUG_sc_coul_cic_v_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_nice_tb_sel : 1;
        unsigned char sc_regn_ok_sel : 1;
        unsigned char reserved : 6;
    } reg;
} REG_SC_NICE_TB_SEL_UNION;
#endif
#define REG_SC_NICE_TB_SEL_sc_nice_tb_sel_START (0)
#define REG_SC_NICE_TB_SEL_sc_nice_tb_sel_END (0)
#define REG_SC_NICE_TB_SEL_sc_regn_ok_sel_START (1)
#define REG_SC_NICE_TB_SEL_sc_regn_ok_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_nice_tb_trig : 1;
        unsigned char sc_regn_ok_trig : 1;
        unsigned char reserved : 6;
    } reg;
} REG_SC_NICE_TB_TRIG_UNION;
#endif
#define REG_SC_NICE_TB_TRIG_sc_nice_tb_trig_START (0)
#define REG_SC_NICE_TB_TRIG_sc_nice_tb_trig_END (0)
#define REG_SC_NICE_TB_TRIG_sc_regn_ok_trig_START (1)
#define REG_SC_NICE_TB_TRIG_sc_regn_ok_trig_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_eco_nice_vld : 1;
        unsigned char reserved : 7;
    } reg;
} REG_ECO_PWROFF_VLD_UNION;
#endif
#define REG_ECO_PWROFF_VLD_sc_eco_nice_vld_START (0)
#define REG_ECO_PWROFF_VLD_sc_eco_nice_vld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char clj_dbg_cfg : 8;
    } reg;
} REG_CLJ_DBG_CFG_UNION;
#endif
#define REG_CLJ_DBG_CFG_clj_dbg_cfg_START (0)
#define REG_CLJ_DBG_CFG_clj_dbg_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char coul_crg_cali_value : 6;
        unsigned char reserved : 2;
    } reg;
} REG_CLJ_DBG_STATUS_UNION;
#endif
#define REG_CLJ_DBG_STATUS_coul_crg_cali_value_START (0)
#define REG_CLJ_DBG_STATUS_coul_crg_cali_value_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_out_ro0 : 8;
    } reg;
} REG_H_CL_OUT_RO0_UNION;
#endif
#define REG_H_CL_OUT_RO0_h_cl_out_ro0_START (0)
#define REG_H_CL_OUT_RO0_h_cl_out_ro0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_out_ro1 : 8;
    } reg;
} REG_H_CL_OUT_RO1_UNION;
#endif
#define REG_H_CL_OUT_RO1_h_cl_out_ro1_START (0)
#define REG_H_CL_OUT_RO1_h_cl_out_ro1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_out_ro2 : 8;
    } reg;
} REG_H_CL_OUT_RO2_UNION;
#endif
#define REG_H_CL_OUT_RO2_h_cl_out_ro2_START (0)
#define REG_H_CL_OUT_RO2_h_cl_out_ro2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_out_ro3 : 8;
    } reg;
} REG_H_CL_OUT_RO3_UNION;
#endif
#define REG_H_CL_OUT_RO3_h_cl_out_ro3_START (0)
#define REG_H_CL_OUT_RO3_h_cl_out_ro3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_out_ro4 : 8;
    } reg;
} REG_H_CL_OUT_RO4_UNION;
#endif
#define REG_H_CL_OUT_RO4_h_cl_out_ro4_START (0)
#define REG_H_CL_OUT_RO4_h_cl_out_ro4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_in_ro0 : 8;
    } reg;
} REG_H_CL_IN_RO0_UNION;
#endif
#define REG_H_CL_IN_RO0_h_cl_in_ro0_START (0)
#define REG_H_CL_IN_RO0_h_cl_in_ro0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_in_ro1 : 8;
    } reg;
} REG_H_CL_IN_RO1_UNION;
#endif
#define REG_H_CL_IN_RO1_h_cl_in_ro1_START (0)
#define REG_H_CL_IN_RO1_h_cl_in_ro1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_in_ro2 : 8;
    } reg;
} REG_H_CL_IN_RO2_UNION;
#endif
#define REG_H_CL_IN_RO2_h_cl_in_ro2_START (0)
#define REG_H_CL_IN_RO2_h_cl_in_ro2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_in_ro3 : 8;
    } reg;
} REG_H_CL_IN_RO3_UNION;
#endif
#define REG_H_CL_IN_RO3_h_cl_in_ro3_START (0)
#define REG_H_CL_IN_RO3_h_cl_in_ro3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_in_ro4 : 8;
    } reg;
} REG_H_CL_IN_RO4_UNION;
#endif
#define REG_H_CL_IN_RO4_h_cl_in_ro4_START (0)
#define REG_H_CL_IN_RO4_h_cl_in_ro4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_chg_timer_ro0 : 8;
    } reg;
} REG_H_CHG_TIMER_RO0_UNION;
#endif
#define REG_H_CHG_TIMER_RO0_h_chg_timer_ro0_START (0)
#define REG_H_CHG_TIMER_RO0_h_chg_timer_ro0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_chg_timer_ro1 : 8;
    } reg;
} REG_H_CHG_TIMER_RO1_UNION;
#endif
#define REG_H_CHG_TIMER_RO1_h_chg_timer_ro1_START (0)
#define REG_H_CHG_TIMER_RO1_h_chg_timer_ro1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_chg_timer_ro2 : 8;
    } reg;
} REG_H_CHG_TIMER_RO2_UNION;
#endif
#define REG_H_CHG_TIMER_RO2_h_chg_timer_ro2_START (0)
#define REG_H_CHG_TIMER_RO2_h_chg_timer_ro2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_chg_timer_ro3 : 8;
    } reg;
} REG_H_CHG_TIMER_RO3_UNION;
#endif
#define REG_H_CHG_TIMER_RO3_h_chg_timer_ro3_START (0)
#define REG_H_CHG_TIMER_RO3_h_chg_timer_ro3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_load_timer_ro0 : 8;
    } reg;
} REG_H_LOAD_TIMER_RO0_UNION;
#endif
#define REG_H_LOAD_TIMER_RO0_h_load_timer_ro0_START (0)
#define REG_H_LOAD_TIMER_RO0_h_load_timer_ro0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_load_timer_ro1 : 8;
    } reg;
} REG_H_LOAD_TIMER_RO1_UNION;
#endif
#define REG_H_LOAD_TIMER_RO1_h_load_timer_ro1_START (0)
#define REG_H_LOAD_TIMER_RO1_h_load_timer_ro1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_load_timer_ro2 : 8;
    } reg;
} REG_H_LOAD_TIMER_RO2_UNION;
#endif
#define REG_H_LOAD_TIMER_RO2_h_load_timer_ro2_START (0)
#define REG_H_LOAD_TIMER_RO2_h_load_timer_ro2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_load_timer_ro3 : 8;
    } reg;
} REG_H_LOAD_TIMER_RO3_UNION;
#endif
#define REG_H_LOAD_TIMER_RO3_h_load_timer_ro3_START (0)
#define REG_H_LOAD_TIMER_RO3_h_load_timer_ro3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_out_ro0 : 8;
    } reg;
} REG_L_CL_OUT_RO0_UNION;
#endif
#define REG_L_CL_OUT_RO0_l_cl_out_ro0_START (0)
#define REG_L_CL_OUT_RO0_l_cl_out_ro0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_out_ro1 : 8;
    } reg;
} REG_L_CL_OUT_RO1_UNION;
#endif
#define REG_L_CL_OUT_RO1_l_cl_out_ro1_START (0)
#define REG_L_CL_OUT_RO1_l_cl_out_ro1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_out_ro2 : 8;
    } reg;
} REG_L_CL_OUT_RO2_UNION;
#endif
#define REG_L_CL_OUT_RO2_l_cl_out_ro2_START (0)
#define REG_L_CL_OUT_RO2_l_cl_out_ro2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_out_ro3 : 8;
    } reg;
} REG_L_CL_OUT_RO3_UNION;
#endif
#define REG_L_CL_OUT_RO3_l_cl_out_ro3_START (0)
#define REG_L_CL_OUT_RO3_l_cl_out_ro3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_out_ro4 : 8;
    } reg;
} REG_L_CL_OUT_RO4_UNION;
#endif
#define REG_L_CL_OUT_RO4_l_cl_out_ro4_START (0)
#define REG_L_CL_OUT_RO4_l_cl_out_ro4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_in_ro0 : 8;
    } reg;
} REG_L_CL_IN_RO0_UNION;
#endif
#define REG_L_CL_IN_RO0_l_cl_in_ro0_START (0)
#define REG_L_CL_IN_RO0_l_cl_in_ro0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_in_ro1 : 8;
    } reg;
} REG_L_CL_IN_RO1_UNION;
#endif
#define REG_L_CL_IN_RO1_l_cl_in_ro1_START (0)
#define REG_L_CL_IN_RO1_l_cl_in_ro1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_in_ro2 : 8;
    } reg;
} REG_L_CL_IN_RO2_UNION;
#endif
#define REG_L_CL_IN_RO2_l_cl_in_ro2_START (0)
#define REG_L_CL_IN_RO2_l_cl_in_ro2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_in_ro3 : 8;
    } reg;
} REG_L_CL_IN_RO3_UNION;
#endif
#define REG_L_CL_IN_RO3_l_cl_in_ro3_START (0)
#define REG_L_CL_IN_RO3_l_cl_in_ro3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_in_ro4 : 8;
    } reg;
} REG_L_CL_IN_RO4_UNION;
#endif
#define REG_L_CL_IN_RO4_l_cl_in_ro4_START (0)
#define REG_L_CL_IN_RO4_l_cl_in_ro4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_chg_timer_ro0 : 8;
    } reg;
} REG_L_CHG_TIMER_RO0_UNION;
#endif
#define REG_L_CHG_TIMER_RO0_l_chg_timer_ro0_START (0)
#define REG_L_CHG_TIMER_RO0_l_chg_timer_ro0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_chg_timer_ro1 : 8;
    } reg;
} REG_L_CHG_TIMER_RO1_UNION;
#endif
#define REG_L_CHG_TIMER_RO1_l_chg_timer_ro1_START (0)
#define REG_L_CHG_TIMER_RO1_l_chg_timer_ro1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_chg_timer_ro2 : 8;
    } reg;
} REG_L_CHG_TIMER_RO2_UNION;
#endif
#define REG_L_CHG_TIMER_RO2_l_chg_timer_ro2_START (0)
#define REG_L_CHG_TIMER_RO2_l_chg_timer_ro2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_chg_timer_ro3 : 8;
    } reg;
} REG_L_CHG_TIMER_RO3_UNION;
#endif
#define REG_L_CHG_TIMER_RO3_l_chg_timer_ro3_START (0)
#define REG_L_CHG_TIMER_RO3_l_chg_timer_ro3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_load_timer_ro0 : 8;
    } reg;
} REG_L_LOAD_TIMER_RO0_UNION;
#endif
#define REG_L_LOAD_TIMER_RO0_l_load_timer_ro0_START (0)
#define REG_L_LOAD_TIMER_RO0_l_load_timer_ro0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_load_timer_ro1 : 8;
    } reg;
} REG_L_LOAD_TIMER_RO1_UNION;
#endif
#define REG_L_LOAD_TIMER_RO1_l_load_timer_ro1_START (0)
#define REG_L_LOAD_TIMER_RO1_l_load_timer_ro1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_load_timer_ro2 : 8;
    } reg;
} REG_L_LOAD_TIMER_RO2_UNION;
#endif
#define REG_L_LOAD_TIMER_RO2_l_load_timer_ro2_START (0)
#define REG_L_LOAD_TIMER_RO2_l_load_timer_ro2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_load_timer_ro3 : 8;
    } reg;
} REG_L_LOAD_TIMER_RO3_UNION;
#endif
#define REG_L_LOAD_TIMER_RO3_l_load_timer_ro3_START (0)
#define REG_L_LOAD_TIMER_RO3_l_load_timer_ro3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_cnt_out1_s0 : 8;
    } reg;
} REG_ECO_CNT1_OUT0_UNION;
#endif
#define REG_ECO_CNT1_OUT0_eco_cnt_out1_s0_START (0)
#define REG_ECO_CNT1_OUT0_eco_cnt_out1_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_cnt_out1_s1 : 8;
    } reg;
} REG_ECO_CNT1_OUT1_UNION;
#endif
#define REG_ECO_CNT1_OUT1_eco_cnt_out1_s1_START (0)
#define REG_ECO_CNT1_OUT1_eco_cnt_out1_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_cnt_out2_s0 : 8;
    } reg;
} REG_ECO_CNT2_OUT0_UNION;
#endif
#define REG_ECO_CNT2_OUT0_eco_cnt_out2_s0_START (0)
#define REG_ECO_CNT2_OUT0_eco_cnt_out2_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_cnt_out2_s1 : 8;
    } reg;
} REG_ECO_CNT2_OUT1_UNION;
#endif
#define REG_ECO_CNT2_OUT1_eco_cnt_out2_s1_START (0)
#define REG_ECO_CNT2_OUT1_eco_cnt_out2_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_cnt_out3_s0 : 8;
    } reg;
} REG_ECO_CNT3_OUT0_UNION;
#endif
#define REG_ECO_CNT3_OUT0_eco_cnt_out3_s0_START (0)
#define REG_ECO_CNT3_OUT0_eco_cnt_out3_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_cnt_out3_s1 : 8;
    } reg;
} REG_ECO_CNT3_OUT1_UNION;
#endif
#define REG_ECO_CNT3_OUT1_eco_cnt_out3_s1_START (0)
#define REG_ECO_CNT3_OUT1_eco_cnt_out3_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_cnt_out4_s0 : 8;
    } reg;
} REG_ECO_CNT4_OUT0_UNION;
#endif
#define REG_ECO_CNT4_OUT0_eco_cnt_out4_s0_START (0)
#define REG_ECO_CNT4_OUT0_eco_cnt_out4_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_cnt_out4_s1 : 8;
    } reg;
} REG_ECO_CNT4_OUT1_UNION;
#endif
#define REG_ECO_CNT4_OUT1_eco_cnt_out4_s1_START (0)
#define REG_ECO_CNT4_OUT1_eco_cnt_out4_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_coul_adc_ibias_sel : 6;
        unsigned char reserved : 2;
    } reg;
} REG_COUL_TOP_CFG_REG_0_UNION;
#endif
#define REG_COUL_TOP_CFG_REG_0_da_coul_adc_ibias_sel_START (0)
#define REG_COUL_TOP_CFG_REG_0_da_coul_adc_ibias_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_coul_dt_ctrl : 2;
        unsigned char da_coul_chop_clk_sel : 4;
        unsigned char da_coul_i_pga_gain_adj : 2;
    } reg;
} REG_COUL_TOP_CFG_REG_1_UNION;
#endif
#define REG_COUL_TOP_CFG_REG_1_da_coul_dt_ctrl_START (0)
#define REG_COUL_TOP_CFG_REG_1_da_coul_dt_ctrl_END (1)
#define REG_COUL_TOP_CFG_REG_1_da_coul_chop_clk_sel_START (2)
#define REG_COUL_TOP_CFG_REG_1_da_coul_chop_clk_sel_END (5)
#define REG_COUL_TOP_CFG_REG_1_da_coul_i_pga_gain_adj_START (6)
#define REG_COUL_TOP_CFG_REG_1_da_coul_i_pga_gain_adj_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_coul_i_pga_cap_n : 4;
        unsigned char da_coul_i_amp_ibias_sel : 4;
    } reg;
} REG_COUL_TOP_CFG_REG_2_UNION;
#endif
#define REG_COUL_TOP_CFG_REG_2_da_coul_i_pga_cap_n_START (0)
#define REG_COUL_TOP_CFG_REG_2_da_coul_i_pga_cap_n_END (3)
#define REG_COUL_TOP_CFG_REG_2_da_coul_i_amp_ibias_sel_START (4)
#define REG_COUL_TOP_CFG_REG_2_da_coul_i_amp_ibias_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_coul_ih_debug_ctrlh : 1;
        unsigned char da_coul_ih_debug_ctrl : 2;
        unsigned char reserved : 1;
        unsigned char da_coul_i_pga_cap_p : 4;
    } reg;
} REG_COUL_TOP_CFG_REG_3_UNION;
#endif
#define REG_COUL_TOP_CFG_REG_3_da_coul_ih_debug_ctrlh_START (0)
#define REG_COUL_TOP_CFG_REG_3_da_coul_ih_debug_ctrlh_END (0)
#define REG_COUL_TOP_CFG_REG_3_da_coul_ih_debug_ctrl_START (1)
#define REG_COUL_TOP_CFG_REG_3_da_coul_ih_debug_ctrl_END (2)
#define REG_COUL_TOP_CFG_REG_3_da_coul_i_pga_cap_p_START (4)
#define REG_COUL_TOP_CFG_REG_3_da_coul_i_pga_cap_p_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_coul_il_pga_chop_en : 1;
        unsigned char da_coul_il_int1_chop_en : 1;
        unsigned char da_coul_il_debug_ctrlh : 1;
        unsigned char da_coul_il_debug_ctrl : 2;
        unsigned char da_coul_ih_sys_chop_en : 1;
        unsigned char da_coul_ih_pga_chop_en : 1;
        unsigned char da_coul_ih_int1_chop_en : 1;
    } reg;
} REG_COUL_TOP_CFG_REG_4_UNION;
#endif
#define REG_COUL_TOP_CFG_REG_4_da_coul_il_pga_chop_en_START (0)
#define REG_COUL_TOP_CFG_REG_4_da_coul_il_pga_chop_en_END (0)
#define REG_COUL_TOP_CFG_REG_4_da_coul_il_int1_chop_en_START (1)
#define REG_COUL_TOP_CFG_REG_4_da_coul_il_int1_chop_en_END (1)
#define REG_COUL_TOP_CFG_REG_4_da_coul_il_debug_ctrlh_START (2)
#define REG_COUL_TOP_CFG_REG_4_da_coul_il_debug_ctrlh_END (2)
#define REG_COUL_TOP_CFG_REG_4_da_coul_il_debug_ctrl_START (3)
#define REG_COUL_TOP_CFG_REG_4_da_coul_il_debug_ctrl_END (4)
#define REG_COUL_TOP_CFG_REG_4_da_coul_ih_sys_chop_en_START (5)
#define REG_COUL_TOP_CFG_REG_4_da_coul_ih_sys_chop_en_END (5)
#define REG_COUL_TOP_CFG_REG_4_da_coul_ih_pga_chop_en_START (6)
#define REG_COUL_TOP_CFG_REG_4_da_coul_ih_pga_chop_en_END (6)
#define REG_COUL_TOP_CFG_REG_4_da_coul_ih_int1_chop_en_START (7)
#define REG_COUL_TOP_CFG_REG_4_da_coul_ih_int1_chop_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_coul_il_sys_chop_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_COUL_TOP_CFG_REG_5_UNION;
#endif
#define REG_COUL_TOP_CFG_REG_5_da_coul_il_sys_chop_en_START (0)
#define REG_COUL_TOP_CFG_REG_5_da_coul_il_sys_chop_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_coul_reserve0 : 8;
    } reg;
} REG_COUL_TOP_CFG_REG_6_UNION;
#endif
#define REG_COUL_TOP_CFG_REG_6_da_coul_reserve0_START (0)
#define REG_COUL_TOP_CFG_REG_6_da_coul_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_coul_reserve1 : 8;
    } reg;
} REG_COUL_TOP_CFG_REG_7_UNION;
#endif
#define REG_COUL_TOP_CFG_REG_7_da_coul_reserve1_START (0)
#define REG_COUL_TOP_CFG_REG_7_da_coul_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_coul_reserve2 : 8;
    } reg;
} REG_COUL_TOP_CFG_REG_8_UNION;
#endif
#define REG_COUL_TOP_CFG_REG_8_da_coul_reserve2_START (0)
#define REG_COUL_TOP_CFG_REG_8_da_coul_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_coul_reserve3 : 8;
    } reg;
} REG_COUL_TOP_CFG_REG_9_UNION;
#endif
#define REG_COUL_TOP_CFG_REG_9_da_coul_reserve3_START (0)
#define REG_COUL_TOP_CFG_REG_9_da_coul_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_coul_v_debug_ctrl : 2;
        unsigned char da_coul_v_amp_ibias_sel : 2;
        unsigned char da_coul_v_alias_en : 1;
        unsigned char da_coul_test_mode : 2;
        unsigned char da_coul_sys_chop_freq_sel : 1;
    } reg;
} REG_COUL_TOP_CFG_REG_10_UNION;
#endif
#define REG_COUL_TOP_CFG_REG_10_da_coul_v_debug_ctrl_START (0)
#define REG_COUL_TOP_CFG_REG_10_da_coul_v_debug_ctrl_END (1)
#define REG_COUL_TOP_CFG_REG_10_da_coul_v_amp_ibias_sel_START (2)
#define REG_COUL_TOP_CFG_REG_10_da_coul_v_amp_ibias_sel_END (3)
#define REG_COUL_TOP_CFG_REG_10_da_coul_v_alias_en_START (4)
#define REG_COUL_TOP_CFG_REG_10_da_coul_v_alias_en_END (4)
#define REG_COUL_TOP_CFG_REG_10_da_coul_test_mode_START (5)
#define REG_COUL_TOP_CFG_REG_10_da_coul_test_mode_END (6)
#define REG_COUL_TOP_CFG_REG_10_da_coul_sys_chop_freq_sel_START (7)
#define REG_COUL_TOP_CFG_REG_10_da_coul_sys_chop_freq_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_coul_v_sys_chop_en : 1;
        unsigned char da_coul_v_pga_gain_sel : 1;
        unsigned char da_coul_v_pga_chop_en : 1;
        unsigned char da_coul_v_int1_chop_en : 1;
        unsigned char da_coul_v_debug_pgah : 1;
        unsigned char reserved : 3;
    } reg;
} REG_COUL_TOP_CFG_REG_11_UNION;
#endif
#define REG_COUL_TOP_CFG_REG_11_da_coul_v_sys_chop_en_START (0)
#define REG_COUL_TOP_CFG_REG_11_da_coul_v_sys_chop_en_END (0)
#define REG_COUL_TOP_CFG_REG_11_da_coul_v_pga_gain_sel_START (1)
#define REG_COUL_TOP_CFG_REG_11_da_coul_v_pga_gain_sel_END (1)
#define REG_COUL_TOP_CFG_REG_11_da_coul_v_pga_chop_en_START (2)
#define REG_COUL_TOP_CFG_REG_11_da_coul_v_pga_chop_en_END (2)
#define REG_COUL_TOP_CFG_REG_11_da_coul_v_int1_chop_en_START (3)
#define REG_COUL_TOP_CFG_REG_11_da_coul_v_int1_chop_en_END (3)
#define REG_COUL_TOP_CFG_REG_11_da_coul_v_debug_pgah_START (4)
#define REG_COUL_TOP_CFG_REG_11_da_coul_v_debug_pgah_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vbat_drop_det_en : 1;
        unsigned char l_vbat_drop_det_th : 3;
        unsigned char h_vbat_drop_det_en : 1;
        unsigned char h_vbat_drop_det_th : 3;
    } reg;
} REG_V_DROP_CTRL0_UNION;
#endif
#define REG_V_DROP_CTRL0_l_vbat_drop_det_en_START (0)
#define REG_V_DROP_CTRL0_l_vbat_drop_det_en_END (0)
#define REG_V_DROP_CTRL0_l_vbat_drop_det_th_START (1)
#define REG_V_DROP_CTRL0_l_vbat_drop_det_th_END (3)
#define REG_V_DROP_CTRL0_h_vbat_drop_det_en_START (4)
#define REG_V_DROP_CTRL0_h_vbat_drop_det_en_END (4)
#define REG_V_DROP_CTRL0_h_vbat_drop_det_th_START (5)
#define REG_V_DROP_CTRL0_h_vbat_drop_det_th_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vdrop_out_pre0_s0 : 8;
    } reg;
} REG_H_V_DROP_PRE0_OUT0_UNION;
#endif
#define REG_H_V_DROP_PRE0_OUT0_h_vdrop_out_pre0_s0_START (0)
#define REG_H_V_DROP_PRE0_OUT0_h_vdrop_out_pre0_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vdrop_out_pre0_s1 : 8;
    } reg;
} REG_H_V_DROP_PRE0_OUT1_UNION;
#endif
#define REG_H_V_DROP_PRE0_OUT1_h_vdrop_out_pre0_s1_START (0)
#define REG_H_V_DROP_PRE0_OUT1_h_vdrop_out_pre0_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vdrop_out_pre0_s2 : 8;
    } reg;
} REG_H_V_DROP_PRE0_OUT2_UNION;
#endif
#define REG_H_V_DROP_PRE0_OUT2_h_vdrop_out_pre0_s2_START (0)
#define REG_H_V_DROP_PRE0_OUT2_h_vdrop_out_pre0_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vdrop_out_pre1_s0 : 8;
    } reg;
} REG_H_V_DROP_PRE1_OUT0_UNION;
#endif
#define REG_H_V_DROP_PRE1_OUT0_h_vdrop_out_pre1_s0_START (0)
#define REG_H_V_DROP_PRE1_OUT0_h_vdrop_out_pre1_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vdrop_out_pre1_s1 : 8;
    } reg;
} REG_H_V_DROP_PRE1_OUT1_UNION;
#endif
#define REG_H_V_DROP_PRE1_OUT1_h_vdrop_out_pre1_s1_START (0)
#define REG_H_V_DROP_PRE1_OUT1_h_vdrop_out_pre1_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vdrop_out_pre1_s2 : 8;
    } reg;
} REG_H_V_DROP_PRE1_OUT2_UNION;
#endif
#define REG_H_V_DROP_PRE1_OUT2_h_vdrop_out_pre1_s2_START (0)
#define REG_H_V_DROP_PRE1_OUT2_h_vdrop_out_pre1_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vdrop_out_pre2_s0 : 8;
    } reg;
} REG_H_V_DROP_PRE2_OUT0_UNION;
#endif
#define REG_H_V_DROP_PRE2_OUT0_h_vdrop_out_pre2_s0_START (0)
#define REG_H_V_DROP_PRE2_OUT0_h_vdrop_out_pre2_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vdrop_out_pre2_s1 : 8;
    } reg;
} REG_H_V_DROP_PRE2_OUT1_UNION;
#endif
#define REG_H_V_DROP_PRE2_OUT1_h_vdrop_out_pre2_s1_START (0)
#define REG_H_V_DROP_PRE2_OUT1_h_vdrop_out_pre2_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vdrop_out_pre2_s2 : 8;
    } reg;
} REG_H_V_DROP_PRE2_OUT2_UNION;
#endif
#define REG_H_V_DROP_PRE2_OUT2_h_vdrop_out_pre2_s2_START (0)
#define REG_H_V_DROP_PRE2_OUT2_h_vdrop_out_pre2_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vdrop_out_pre0_s0 : 8;
    } reg;
} REG_L_V_DROP_PRE0_OUT0_UNION;
#endif
#define REG_L_V_DROP_PRE0_OUT0_l_vdrop_out_pre0_s0_START (0)
#define REG_L_V_DROP_PRE0_OUT0_l_vdrop_out_pre0_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vdrop_out_pre0_s1 : 8;
    } reg;
} REG_L_V_DROP_PRE0_OUT1_UNION;
#endif
#define REG_L_V_DROP_PRE0_OUT1_l_vdrop_out_pre0_s1_START (0)
#define REG_L_V_DROP_PRE0_OUT1_l_vdrop_out_pre0_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vdrop_out_pre0_s2 : 8;
    } reg;
} REG_L_V_DROP_PRE0_OUT2_UNION;
#endif
#define REG_L_V_DROP_PRE0_OUT2_l_vdrop_out_pre0_s2_START (0)
#define REG_L_V_DROP_PRE0_OUT2_l_vdrop_out_pre0_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vdrop_out_pre1_s0 : 8;
    } reg;
} REG_L_V_DROP_PRE1_OUT0_UNION;
#endif
#define REG_L_V_DROP_PRE1_OUT0_l_vdrop_out_pre1_s0_START (0)
#define REG_L_V_DROP_PRE1_OUT0_l_vdrop_out_pre1_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vdrop_out_pre1_s1 : 8;
    } reg;
} REG_L_V_DROP_PRE1_OUT1_UNION;
#endif
#define REG_L_V_DROP_PRE1_OUT1_l_vdrop_out_pre1_s1_START (0)
#define REG_L_V_DROP_PRE1_OUT1_l_vdrop_out_pre1_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vdrop_out_pre1_s2 : 8;
    } reg;
} REG_L_V_DROP_PRE1_OUT2_UNION;
#endif
#define REG_L_V_DROP_PRE1_OUT2_l_vdrop_out_pre1_s2_START (0)
#define REG_L_V_DROP_PRE1_OUT2_l_vdrop_out_pre1_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vdrop_out_pre2_s0 : 8;
    } reg;
} REG_L_V_DROP_PRE2_OUT0_UNION;
#endif
#define REG_L_V_DROP_PRE2_OUT0_l_vdrop_out_pre2_s0_START (0)
#define REG_L_V_DROP_PRE2_OUT0_l_vdrop_out_pre2_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vdrop_out_pre2_s1 : 8;
    } reg;
} REG_L_V_DROP_PRE2_OUT1_UNION;
#endif
#define REG_L_V_DROP_PRE2_OUT1_l_vdrop_out_pre2_s1_START (0)
#define REG_L_V_DROP_PRE2_OUT1_l_vdrop_out_pre2_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vdrop_out_pre2_s2 : 8;
    } reg;
} REG_L_V_DROP_PRE2_OUT2_UNION;
#endif
#define REG_L_V_DROP_PRE2_OUT2_l_vdrop_out_pre2_s2_START (0)
#define REG_L_V_DROP_PRE2_OUT2_l_vdrop_out_pre2_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_out_s0 : 8;
    } reg;
} REG_H_CL_OUT0_UNION;
#endif
#define REG_H_CL_OUT0_h_cl_out_s0_START (0)
#define REG_H_CL_OUT0_h_cl_out_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_out_s1 : 8;
    } reg;
} REG_H_CL_OUT1_UNION;
#endif
#define REG_H_CL_OUT1_h_cl_out_s1_START (0)
#define REG_H_CL_OUT1_h_cl_out_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_out_s2 : 8;
    } reg;
} REG_H_CL_OUT2_UNION;
#endif
#define REG_H_CL_OUT2_h_cl_out_s2_START (0)
#define REG_H_CL_OUT2_h_cl_out_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_out_s3 : 8;
    } reg;
} REG_H_CL_OUT3_UNION;
#endif
#define REG_H_CL_OUT3_h_cl_out_s3_START (0)
#define REG_H_CL_OUT3_h_cl_out_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_out_s4 : 8;
    } reg;
} REG_H_CL_OUT4_UNION;
#endif
#define REG_H_CL_OUT4_h_cl_out_s4_START (0)
#define REG_H_CL_OUT4_h_cl_out_s4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_in_s0 : 8;
    } reg;
} REG_H_CL_IN0_UNION;
#endif
#define REG_H_CL_IN0_h_cl_in_s0_START (0)
#define REG_H_CL_IN0_h_cl_in_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_in_s1 : 8;
    } reg;
} REG_H_CL_IN1_UNION;
#endif
#define REG_H_CL_IN1_h_cl_in_s1_START (0)
#define REG_H_CL_IN1_h_cl_in_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_in_s2 : 8;
    } reg;
} REG_H_CL_IN2_UNION;
#endif
#define REG_H_CL_IN2_h_cl_in_s2_START (0)
#define REG_H_CL_IN2_h_cl_in_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_in_s3 : 8;
    } reg;
} REG_H_CL_IN3_UNION;
#endif
#define REG_H_CL_IN3_h_cl_in_s3_START (0)
#define REG_H_CL_IN3_h_cl_in_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_cl_in_s4 : 8;
    } reg;
} REG_H_CL_IN4_UNION;
#endif
#define REG_H_CL_IN4_h_cl_in_s4_START (0)
#define REG_H_CL_IN4_h_cl_in_s4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_chg_timer_s0 : 8;
    } reg;
} REG_H_CHG_TIMER0_UNION;
#endif
#define REG_H_CHG_TIMER0_h_chg_timer_s0_START (0)
#define REG_H_CHG_TIMER0_h_chg_timer_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_chg_timer_s1 : 8;
    } reg;
} REG_H_CHG_TIMER1_UNION;
#endif
#define REG_H_CHG_TIMER1_h_chg_timer_s1_START (0)
#define REG_H_CHG_TIMER1_h_chg_timer_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_chg_timer_s2 : 8;
    } reg;
} REG_H_CHG_TIMER2_UNION;
#endif
#define REG_H_CHG_TIMER2_h_chg_timer_s2_START (0)
#define REG_H_CHG_TIMER2_h_chg_timer_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_chg_timer_s3 : 8;
    } reg;
} REG_H_CHG_TIMER3_UNION;
#endif
#define REG_H_CHG_TIMER3_h_chg_timer_s3_START (0)
#define REG_H_CHG_TIMER3_h_chg_timer_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_load_timer_s0 : 8;
    } reg;
} REG_H_LOAD_TIMER0_UNION;
#endif
#define REG_H_LOAD_TIMER0_h_load_timer_s0_START (0)
#define REG_H_LOAD_TIMER0_h_load_timer_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_load_timer_s1 : 8;
    } reg;
} REG_H_LOAD_TIMER1_UNION;
#endif
#define REG_H_LOAD_TIMER1_h_load_timer_s1_START (0)
#define REG_H_LOAD_TIMER1_h_load_timer_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_load_timer_s2 : 8;
    } reg;
} REG_H_LOAD_TIMER2_UNION;
#endif
#define REG_H_LOAD_TIMER2_h_load_timer_s2_START (0)
#define REG_H_LOAD_TIMER2_h_load_timer_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_load_timer_s3 : 8;
    } reg;
} REG_H_LOAD_TIMER3_UNION;
#endif
#define REG_H_LOAD_TIMER3_h_load_timer_s3_START (0)
#define REG_H_LOAD_TIMER3_h_load_timer_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h0_offset_current_mod_s0 : 8;
    } reg;
} REG_H0_OFFSET_CURRENT_MOD_0_UNION;
#endif
#define REG_H0_OFFSET_CURRENT_MOD_0_h0_offset_current_mod_s0_START (0)
#define REG_H0_OFFSET_CURRENT_MOD_0_h0_offset_current_mod_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h0_offset_current_mod_s1 : 8;
    } reg;
} REG_H0_OFFSET_CURRENT_MOD_1_UNION;
#endif
#define REG_H0_OFFSET_CURRENT_MOD_1_h0_offset_current_mod_s1_START (0)
#define REG_H0_OFFSET_CURRENT_MOD_1_h0_offset_current_mod_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h0_offset_current_mod_s2 : 8;
    } reg;
} REG_H0_OFFSET_CURRENT_MOD_2_UNION;
#endif
#define REG_H0_OFFSET_CURRENT_MOD_2_h0_offset_current_mod_s2_START (0)
#define REG_H0_OFFSET_CURRENT_MOD_2_h0_offset_current_mod_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h1_offset_current_mod_s0 : 8;
    } reg;
} REG_H1_OFFSET_CURRENT_MOD_0_UNION;
#endif
#define REG_H1_OFFSET_CURRENT_MOD_0_h1_offset_current_mod_s0_START (0)
#define REG_H1_OFFSET_CURRENT_MOD_0_h1_offset_current_mod_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h1_offset_current_mod_s1 : 8;
    } reg;
} REG_H1_OFFSET_CURRENT_MOD_1_UNION;
#endif
#define REG_H1_OFFSET_CURRENT_MOD_1_h1_offset_current_mod_s1_START (0)
#define REG_H1_OFFSET_CURRENT_MOD_1_h1_offset_current_mod_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h1_offset_current_mod_s2 : 8;
    } reg;
} REG_H1_OFFSET_CURRENT_MOD_2_UNION;
#endif
#define REG_H1_OFFSET_CURRENT_MOD_2_h1_offset_current_mod_s2_START (0)
#define REG_H1_OFFSET_CURRENT_MOD_2_h1_offset_current_mod_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_offset_voltage_mod_s0 : 8;
    } reg;
} REG_H_OFFSET_VOLTAGE_MOD_0_UNION;
#endif
#define REG_H_OFFSET_VOLTAGE_MOD_0_h_offset_voltage_mod_s0_START (0)
#define REG_H_OFFSET_VOLTAGE_MOD_0_h_offset_voltage_mod_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_offset_voltage_mod_s1 : 8;
    } reg;
} REG_H_OFFSET_VOLTAGE_MOD_1_UNION;
#endif
#define REG_H_OFFSET_VOLTAGE_MOD_1_h_offset_voltage_mod_s1_START (0)
#define REG_H_OFFSET_VOLTAGE_MOD_1_h_offset_voltage_mod_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_offset_voltage_mod_s2 : 8;
    } reg;
} REG_H_OFFSET_VOLTAGE_MOD_2_UNION;
#endif
#define REG_H_OFFSET_VOLTAGE_MOD_2_h_offset_voltage_mod_s2_START (0)
#define REG_H_OFFSET_VOLTAGE_MOD_2_h_offset_voltage_mod_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_s0 : 8;
    } reg;
} REG_H_CURRENT_0_UNION;
#endif
#define REG_H_CURRENT_0_h_current_s0_START (0)
#define REG_H_CURRENT_0_h_current_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_s1 : 8;
    } reg;
} REG_H_CURRENT_1_UNION;
#endif
#define REG_H_CURRENT_1_h_current_s1_START (0)
#define REG_H_CURRENT_1_h_current_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_s2 : 8;
    } reg;
} REG_H_CURRENT_2_UNION;
#endif
#define REG_H_CURRENT_2_h_current_s2_START (0)
#define REG_H_CURRENT_2_h_current_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_out_s0 : 8;
    } reg;
} REG_H_V_OUT_0_UNION;
#endif
#define REG_H_V_OUT_0_h_v_out_s0_START (0)
#define REG_H_V_OUT_0_h_v_out_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_out_s1 : 8;
    } reg;
} REG_H_V_OUT_1_UNION;
#endif
#define REG_H_V_OUT_1_h_v_out_s1_START (0)
#define REG_H_V_OUT_1_h_v_out_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_out_s2 : 8;
    } reg;
} REG_H_V_OUT_2_UNION;
#endif
#define REG_H_V_OUT_2_h_v_out_s2_START (0)
#define REG_H_V_OUT_2_h_v_out_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h0_offset_current_s0 : 8;
    } reg;
} REG_H0_OFFSET_CURRENT0_UNION;
#endif
#define REG_H0_OFFSET_CURRENT0_h0_offset_current_s0_START (0)
#define REG_H0_OFFSET_CURRENT0_h0_offset_current_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h0_offset_current_s1 : 8;
    } reg;
} REG_H0_OFFSET_CURRENT1_UNION;
#endif
#define REG_H0_OFFSET_CURRENT1_h0_offset_current_s1_START (0)
#define REG_H0_OFFSET_CURRENT1_h0_offset_current_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h0_offset_current_s2 : 8;
    } reg;
} REG_H0_OFFSET_CURRENT2_UNION;
#endif
#define REG_H0_OFFSET_CURRENT2_h0_offset_current_s2_START (0)
#define REG_H0_OFFSET_CURRENT2_h0_offset_current_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h1_offset_current_s0 : 8;
    } reg;
} REG_H1_OFFSET_CURRENT0_UNION;
#endif
#define REG_H1_OFFSET_CURRENT0_h1_offset_current_s0_START (0)
#define REG_H1_OFFSET_CURRENT0_h1_offset_current_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h1_offset_current_s1 : 8;
    } reg;
} REG_H1_OFFSET_CURRENT1_UNION;
#endif
#define REG_H1_OFFSET_CURRENT1_h1_offset_current_s1_START (0)
#define REG_H1_OFFSET_CURRENT1_h1_offset_current_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h1_offset_current_s2 : 8;
    } reg;
} REG_H1_OFFSET_CURRENT2_UNION;
#endif
#define REG_H1_OFFSET_CURRENT2_h1_offset_current_s2_START (0)
#define REG_H1_OFFSET_CURRENT2_h1_offset_current_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_offset_voltage_s0 : 8;
    } reg;
} REG_H_OFFSET_VOLTAGE0_UNION;
#endif
#define REG_H_OFFSET_VOLTAGE0_h_offset_voltage_s0_START (0)
#define REG_H_OFFSET_VOLTAGE0_h_offset_voltage_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_offset_voltage_s1 : 8;
    } reg;
} REG_H_OFFSET_VOLTAGE1_UNION;
#endif
#define REG_H_OFFSET_VOLTAGE1_h_offset_voltage_s1_START (0)
#define REG_H_OFFSET_VOLTAGE1_h_offset_voltage_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_offset_voltage_s2 : 8;
    } reg;
} REG_H_OFFSET_VOLTAGE2_UNION;
#endif
#define REG_H_OFFSET_VOLTAGE2_h_offset_voltage_s2_START (0)
#define REG_H_OFFSET_VOLTAGE2_h_offset_voltage_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_ocv_data_s0 : 8;
    } reg;
} REG_H_OCV_VOLTAGE0_UNION;
#endif
#define REG_H_OCV_VOLTAGE0_h_v_ocv_data_s0_START (0)
#define REG_H_OCV_VOLTAGE0_h_v_ocv_data_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_ocv_data_s1 : 8;
    } reg;
} REG_H_OCV_VOLTAGE1_UNION;
#endif
#define REG_H_OCV_VOLTAGE1_h_v_ocv_data_s1_START (0)
#define REG_H_OCV_VOLTAGE1_h_v_ocv_data_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_ocv_data_s2 : 8;
    } reg;
} REG_H_OCV_VOLTAGE2_UNION;
#endif
#define REG_H_OCV_VOLTAGE2_h_v_ocv_data_s2_START (0)
#define REG_H_OCV_VOLTAGE2_h_v_ocv_data_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_i_ocv_data_s0 : 8;
    } reg;
} REG_H_OCV_CURRENT0_UNION;
#endif
#define REG_H_OCV_CURRENT0_h_i_ocv_data_s0_START (0)
#define REG_H_OCV_CURRENT0_h_i_ocv_data_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_i_ocv_data_s1 : 8;
    } reg;
} REG_H_OCV_CURRENT1_UNION;
#endif
#define REG_H_OCV_CURRENT1_h_i_ocv_data_s1_START (0)
#define REG_H_OCV_CURRENT1_h_i_ocv_data_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_i_ocv_data_s2 : 8;
    } reg;
} REG_H_OCV_CURRENT2_UNION;
#endif
#define REG_H_OCV_CURRENT2_h_i_ocv_data_s2_START (0)
#define REG_H_OCV_CURRENT2_h_i_ocv_data_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_eco_out_clin_s0 : 8;
    } reg;
} REG_H_ECO_OUT_CLIN_0_UNION;
#endif
#define REG_H_ECO_OUT_CLIN_0_h_eco_out_clin_s0_START (0)
#define REG_H_ECO_OUT_CLIN_0_h_eco_out_clin_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_eco_out_clin_s1 : 8;
    } reg;
} REG_H_ECO_OUT_CLIN_1_UNION;
#endif
#define REG_H_ECO_OUT_CLIN_1_h_eco_out_clin_s1_START (0)
#define REG_H_ECO_OUT_CLIN_1_h_eco_out_clin_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_eco_out_clin_s2 : 8;
    } reg;
} REG_H_ECO_OUT_CLIN_2_UNION;
#endif
#define REG_H_ECO_OUT_CLIN_2_h_eco_out_clin_s2_START (0)
#define REG_H_ECO_OUT_CLIN_2_h_eco_out_clin_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_eco_out_clin_s3 : 8;
    } reg;
} REG_H_ECO_OUT_CLIN_3_UNION;
#endif
#define REG_H_ECO_OUT_CLIN_3_h_eco_out_clin_s3_START (0)
#define REG_H_ECO_OUT_CLIN_3_h_eco_out_clin_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_eco_out_clin_s4 : 8;
    } reg;
} REG_H_ECO_OUT_CLIN_4_UNION;
#endif
#define REG_H_ECO_OUT_CLIN_4_h_eco_out_clin_s4_START (0)
#define REG_H_ECO_OUT_CLIN_4_h_eco_out_clin_s4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_eco_out_clout_s0 : 8;
    } reg;
} REG_H_ECO_OUT_CLOUT_0_UNION;
#endif
#define REG_H_ECO_OUT_CLOUT_0_h_eco_out_clout_s0_START (0)
#define REG_H_ECO_OUT_CLOUT_0_h_eco_out_clout_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_eco_out_clout_s1 : 8;
    } reg;
} REG_H_ECO_OUT_CLOUT_1_UNION;
#endif
#define REG_H_ECO_OUT_CLOUT_1_h_eco_out_clout_s1_START (0)
#define REG_H_ECO_OUT_CLOUT_1_h_eco_out_clout_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_eco_out_clout_s2 : 8;
    } reg;
} REG_H_ECO_OUT_CLOUT_2_UNION;
#endif
#define REG_H_ECO_OUT_CLOUT_2_h_eco_out_clout_s2_START (0)
#define REG_H_ECO_OUT_CLOUT_2_h_eco_out_clout_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_eco_out_clout_s3 : 8;
    } reg;
} REG_H_ECO_OUT_CLOUT_3_UNION;
#endif
#define REG_H_ECO_OUT_CLOUT_3_h_eco_out_clout_s3_START (0)
#define REG_H_ECO_OUT_CLOUT_3_h_eco_out_clout_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_eco_out_clout_s4 : 8;
    } reg;
} REG_H_ECO_OUT_CLOUT_4_UNION;
#endif
#define REG_H_ECO_OUT_CLOUT_4_h_eco_out_clout_s4_START (0)
#define REG_H_ECO_OUT_CLOUT_4_h_eco_out_clout_s4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre0_s0 : 8;
    } reg;
} REG_H_V_PRE0_OUT0_UNION;
#endif
#define REG_H_V_PRE0_OUT0_h_vout_pre0_s0_START (0)
#define REG_H_V_PRE0_OUT0_h_vout_pre0_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre0_s1 : 8;
    } reg;
} REG_H_V_PRE0_OUT1_UNION;
#endif
#define REG_H_V_PRE0_OUT1_h_vout_pre0_s1_START (0)
#define REG_H_V_PRE0_OUT1_h_vout_pre0_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre0_s2 : 8;
    } reg;
} REG_H_V_PRE0_OUT2_UNION;
#endif
#define REG_H_V_PRE0_OUT2_h_vout_pre0_s2_START (0)
#define REG_H_V_PRE0_OUT2_h_vout_pre0_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre1_s0 : 8;
    } reg;
} REG_H_V_PRE1_OUT0_UNION;
#endif
#define REG_H_V_PRE1_OUT0_h_vout_pre1_s0_START (0)
#define REG_H_V_PRE1_OUT0_h_vout_pre1_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre1_s1 : 8;
    } reg;
} REG_H_V_PRE1_OUT1_UNION;
#endif
#define REG_H_V_PRE1_OUT1_h_vout_pre1_s1_START (0)
#define REG_H_V_PRE1_OUT1_h_vout_pre1_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre1_s2 : 8;
    } reg;
} REG_H_V_PRE1_OUT2_UNION;
#endif
#define REG_H_V_PRE1_OUT2_h_vout_pre1_s2_START (0)
#define REG_H_V_PRE1_OUT2_h_vout_pre1_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre2_s0 : 8;
    } reg;
} REG_H_V_PRE2_OUT0_UNION;
#endif
#define REG_H_V_PRE2_OUT0_h_vout_pre2_s0_START (0)
#define REG_H_V_PRE2_OUT0_h_vout_pre2_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre2_s1 : 8;
    } reg;
} REG_H_V_PRE2_OUT1_UNION;
#endif
#define REG_H_V_PRE2_OUT1_h_vout_pre2_s1_START (0)
#define REG_H_V_PRE2_OUT1_h_vout_pre2_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre2_s2 : 8;
    } reg;
} REG_H_V_PRE2_OUT2_UNION;
#endif
#define REG_H_V_PRE2_OUT2_h_vout_pre2_s2_START (0)
#define REG_H_V_PRE2_OUT2_h_vout_pre2_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre3_s0 : 8;
    } reg;
} REG_H_V_PRE3_OUT0_UNION;
#endif
#define REG_H_V_PRE3_OUT0_h_vout_pre3_s0_START (0)
#define REG_H_V_PRE3_OUT0_h_vout_pre3_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre3_s1 : 8;
    } reg;
} REG_H_V_PRE3_OUT1_UNION;
#endif
#define REG_H_V_PRE3_OUT1_h_vout_pre3_s1_START (0)
#define REG_H_V_PRE3_OUT1_h_vout_pre3_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre3_s2 : 8;
    } reg;
} REG_H_V_PRE3_OUT2_UNION;
#endif
#define REG_H_V_PRE3_OUT2_h_vout_pre3_s2_START (0)
#define REG_H_V_PRE3_OUT2_h_vout_pre3_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre4_s0 : 8;
    } reg;
} REG_H_V_PRE4_OUT0_UNION;
#endif
#define REG_H_V_PRE4_OUT0_h_vout_pre4_s0_START (0)
#define REG_H_V_PRE4_OUT0_h_vout_pre4_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre4_s1 : 8;
    } reg;
} REG_H_V_PRE4_OUT1_UNION;
#endif
#define REG_H_V_PRE4_OUT1_h_vout_pre4_s1_START (0)
#define REG_H_V_PRE4_OUT1_h_vout_pre4_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre4_s2 : 8;
    } reg;
} REG_H_V_PRE4_OUT2_UNION;
#endif
#define REG_H_V_PRE4_OUT2_h_vout_pre4_s2_START (0)
#define REG_H_V_PRE4_OUT2_h_vout_pre4_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre5_s0 : 8;
    } reg;
} REG_H_V_PRE5_OUT0_UNION;
#endif
#define REG_H_V_PRE5_OUT0_h_vout_pre5_s0_START (0)
#define REG_H_V_PRE5_OUT0_h_vout_pre5_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre5_s1 : 8;
    } reg;
} REG_H_V_PRE5_OUT1_UNION;
#endif
#define REG_H_V_PRE5_OUT1_h_vout_pre5_s1_START (0)
#define REG_H_V_PRE5_OUT1_h_vout_pre5_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre5_s2 : 8;
    } reg;
} REG_H_V_PRE5_OUT2_UNION;
#endif
#define REG_H_V_PRE5_OUT2_h_vout_pre5_s2_START (0)
#define REG_H_V_PRE5_OUT2_h_vout_pre5_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre6_s0 : 8;
    } reg;
} REG_H_V_PRE6_OUT0_UNION;
#endif
#define REG_H_V_PRE6_OUT0_h_vout_pre6_s0_START (0)
#define REG_H_V_PRE6_OUT0_h_vout_pre6_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre6_s1 : 8;
    } reg;
} REG_H_V_PRE6_OUT1_UNION;
#endif
#define REG_H_V_PRE6_OUT1_h_vout_pre6_s1_START (0)
#define REG_H_V_PRE6_OUT1_h_vout_pre6_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre6_s2 : 8;
    } reg;
} REG_H_V_PRE6_OUT2_UNION;
#endif
#define REG_H_V_PRE6_OUT2_h_vout_pre6_s2_START (0)
#define REG_H_V_PRE6_OUT2_h_vout_pre6_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre7_s0 : 8;
    } reg;
} REG_H_V_PRE7_OUT0_UNION;
#endif
#define REG_H_V_PRE7_OUT0_h_vout_pre7_s0_START (0)
#define REG_H_V_PRE7_OUT0_h_vout_pre7_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre7_s1 : 8;
    } reg;
} REG_H_V_PRE7_OUT1_UNION;
#endif
#define REG_H_V_PRE7_OUT1_h_vout_pre7_s1_START (0)
#define REG_H_V_PRE7_OUT1_h_vout_pre7_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_vout_pre7_s2 : 8;
    } reg;
} REG_H_V_PRE7_OUT2_UNION;
#endif
#define REG_H_V_PRE7_OUT2_h_vout_pre7_s2_START (0)
#define REG_H_V_PRE7_OUT2_h_vout_pre7_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre0_s0 : 8;
    } reg;
} REG_H_CURRENT_PRE0_OUT0_UNION;
#endif
#define REG_H_CURRENT_PRE0_OUT0_h_current_pre0_s0_START (0)
#define REG_H_CURRENT_PRE0_OUT0_h_current_pre0_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre0_s1 : 8;
    } reg;
} REG_H_CURRENT_PRE0_OUT1_UNION;
#endif
#define REG_H_CURRENT_PRE0_OUT1_h_current_pre0_s1_START (0)
#define REG_H_CURRENT_PRE0_OUT1_h_current_pre0_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre0_s2 : 8;
    } reg;
} REG_H_CURRENT_PRE0_OUT2_UNION;
#endif
#define REG_H_CURRENT_PRE0_OUT2_h_current_pre0_s2_START (0)
#define REG_H_CURRENT_PRE0_OUT2_h_current_pre0_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre1_s0 : 8;
    } reg;
} REG_H_CURRENT_PRE1_OUT0_UNION;
#endif
#define REG_H_CURRENT_PRE1_OUT0_h_current_pre1_s0_START (0)
#define REG_H_CURRENT_PRE1_OUT0_h_current_pre1_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre1_s1 : 8;
    } reg;
} REG_H_CURRENT_PRE1_OUT1_UNION;
#endif
#define REG_H_CURRENT_PRE1_OUT1_h_current_pre1_s1_START (0)
#define REG_H_CURRENT_PRE1_OUT1_h_current_pre1_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre1_s2 : 8;
    } reg;
} REG_H_CURRENT_PRE1_OUT2_UNION;
#endif
#define REG_H_CURRENT_PRE1_OUT2_h_current_pre1_s2_START (0)
#define REG_H_CURRENT_PRE1_OUT2_h_current_pre1_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre2_s0 : 8;
    } reg;
} REG_H_CURRENT_PRE2_OUT0_UNION;
#endif
#define REG_H_CURRENT_PRE2_OUT0_h_current_pre2_s0_START (0)
#define REG_H_CURRENT_PRE2_OUT0_h_current_pre2_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre2_s1 : 8;
    } reg;
} REG_H_CURRENT_PRE2_OUT1_UNION;
#endif
#define REG_H_CURRENT_PRE2_OUT1_h_current_pre2_s1_START (0)
#define REG_H_CURRENT_PRE2_OUT1_h_current_pre2_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre2_s2 : 8;
    } reg;
} REG_H_CURRENT_PRE2_OUT2_UNION;
#endif
#define REG_H_CURRENT_PRE2_OUT2_h_current_pre2_s2_START (0)
#define REG_H_CURRENT_PRE2_OUT2_h_current_pre2_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre3_s0 : 8;
    } reg;
} REG_H_CURRENT_PRE3_OUT0_UNION;
#endif
#define REG_H_CURRENT_PRE3_OUT0_h_current_pre3_s0_START (0)
#define REG_H_CURRENT_PRE3_OUT0_h_current_pre3_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre3_s1 : 8;
    } reg;
} REG_H_CURRENT_PRE3_OUT1_UNION;
#endif
#define REG_H_CURRENT_PRE3_OUT1_h_current_pre3_s1_START (0)
#define REG_H_CURRENT_PRE3_OUT1_h_current_pre3_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre3_s2 : 8;
    } reg;
} REG_H_CURRENT_PRE3_OUT2_UNION;
#endif
#define REG_H_CURRENT_PRE3_OUT2_h_current_pre3_s2_START (0)
#define REG_H_CURRENT_PRE3_OUT2_h_current_pre3_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre4_s0 : 8;
    } reg;
} REG_H_CURRENT_PRE4_OUT0_UNION;
#endif
#define REG_H_CURRENT_PRE4_OUT0_h_current_pre4_s0_START (0)
#define REG_H_CURRENT_PRE4_OUT0_h_current_pre4_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre4_s1 : 8;
    } reg;
} REG_H_CURRENT_PRE4_OUT1_UNION;
#endif
#define REG_H_CURRENT_PRE4_OUT1_h_current_pre4_s1_START (0)
#define REG_H_CURRENT_PRE4_OUT1_h_current_pre4_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre4_s2 : 8;
    } reg;
} REG_H_CURRENT_PRE4_OUT2_UNION;
#endif
#define REG_H_CURRENT_PRE4_OUT2_h_current_pre4_s2_START (0)
#define REG_H_CURRENT_PRE4_OUT2_h_current_pre4_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre5_s0 : 8;
    } reg;
} REG_H_CURRENT_PRE5_OUT0_UNION;
#endif
#define REG_H_CURRENT_PRE5_OUT0_h_current_pre5_s0_START (0)
#define REG_H_CURRENT_PRE5_OUT0_h_current_pre5_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre5_s1 : 8;
    } reg;
} REG_H_CURRENT_PRE5_OUT1_UNION;
#endif
#define REG_H_CURRENT_PRE5_OUT1_h_current_pre5_s1_START (0)
#define REG_H_CURRENT_PRE5_OUT1_h_current_pre5_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre5_s2 : 8;
    } reg;
} REG_H_CURRENT_PRE5_OUT2_UNION;
#endif
#define REG_H_CURRENT_PRE5_OUT2_h_current_pre5_s2_START (0)
#define REG_H_CURRENT_PRE5_OUT2_h_current_pre5_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre6_s0 : 8;
    } reg;
} REG_H_CURRENT_PRE6_OUT0_UNION;
#endif
#define REG_H_CURRENT_PRE6_OUT0_h_current_pre6_s0_START (0)
#define REG_H_CURRENT_PRE6_OUT0_h_current_pre6_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre6_s1 : 8;
    } reg;
} REG_H_CURRENT_PRE6_OUT1_UNION;
#endif
#define REG_H_CURRENT_PRE6_OUT1_h_current_pre6_s1_START (0)
#define REG_H_CURRENT_PRE6_OUT1_h_current_pre6_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre6_s2 : 8;
    } reg;
} REG_H_CURRENT_PRE6_OUT2_UNION;
#endif
#define REG_H_CURRENT_PRE6_OUT2_h_current_pre6_s2_START (0)
#define REG_H_CURRENT_PRE6_OUT2_h_current_pre6_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre7_s0 : 8;
    } reg;
} REG_H_CURRENT_PRE7_OUT0_UNION;
#endif
#define REG_H_CURRENT_PRE7_OUT0_h_current_pre7_s0_START (0)
#define REG_H_CURRENT_PRE7_OUT0_h_current_pre7_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre7_s1 : 8;
    } reg;
} REG_H_CURRENT_PRE7_OUT1_UNION;
#endif
#define REG_H_CURRENT_PRE7_OUT1_h_current_pre7_s1_START (0)
#define REG_H_CURRENT_PRE7_OUT1_h_current_pre7_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_current_pre7_s2 : 8;
    } reg;
} REG_H_CURRENT_PRE7_OUT2_UNION;
#endif
#define REG_H_CURRENT_PRE7_OUT2_h_current_pre7_s2_START (0)
#define REG_H_CURRENT_PRE7_OUT2_h_current_pre7_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_ocv_out_pre1_s0 : 8;
    } reg;
} REG_H_V_OCV_PRE1_OUT0_UNION;
#endif
#define REG_H_V_OCV_PRE1_OUT0_h_v_ocv_out_pre1_s0_START (0)
#define REG_H_V_OCV_PRE1_OUT0_h_v_ocv_out_pre1_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_ocv_out_pre1_s1 : 8;
    } reg;
} REG_H_V_OCV_PRE1_OUT1_UNION;
#endif
#define REG_H_V_OCV_PRE1_OUT1_h_v_ocv_out_pre1_s1_START (0)
#define REG_H_V_OCV_PRE1_OUT1_h_v_ocv_out_pre1_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_ocv_out_pre1_s2 : 8;
    } reg;
} REG_H_V_OCV_PRE1_OUT2_UNION;
#endif
#define REG_H_V_OCV_PRE1_OUT2_h_v_ocv_out_pre1_s2_START (0)
#define REG_H_V_OCV_PRE1_OUT2_h_v_ocv_out_pre1_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_ocv_out_pre2_s0 : 8;
    } reg;
} REG_H_V_OCV_PRE2_OUT0_UNION;
#endif
#define REG_H_V_OCV_PRE2_OUT0_h_v_ocv_out_pre2_s0_START (0)
#define REG_H_V_OCV_PRE2_OUT0_h_v_ocv_out_pre2_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_ocv_out_pre2_s1 : 8;
    } reg;
} REG_H_V_OCV_PRE2_OUT1_UNION;
#endif
#define REG_H_V_OCV_PRE2_OUT1_h_v_ocv_out_pre2_s1_START (0)
#define REG_H_V_OCV_PRE2_OUT1_h_v_ocv_out_pre2_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_ocv_out_pre2_s2 : 8;
    } reg;
} REG_H_V_OCV_PRE2_OUT2_UNION;
#endif
#define REG_H_V_OCV_PRE2_OUT2_h_v_ocv_out_pre2_s2_START (0)
#define REG_H_V_OCV_PRE2_OUT2_h_v_ocv_out_pre2_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_ocv_out_pre3_s0 : 8;
    } reg;
} REG_H_V_OCV_PRE3_OUT0_UNION;
#endif
#define REG_H_V_OCV_PRE3_OUT0_h_v_ocv_out_pre3_s0_START (0)
#define REG_H_V_OCV_PRE3_OUT0_h_v_ocv_out_pre3_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_ocv_out_pre3_s1 : 8;
    } reg;
} REG_H_V_OCV_PRE3_OUT1_UNION;
#endif
#define REG_H_V_OCV_PRE3_OUT1_h_v_ocv_out_pre3_s1_START (0)
#define REG_H_V_OCV_PRE3_OUT1_h_v_ocv_out_pre3_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_ocv_out_pre3_s2 : 8;
    } reg;
} REG_H_V_OCV_PRE3_OUT2_UNION;
#endif
#define REG_H_V_OCV_PRE3_OUT2_h_v_ocv_out_pre3_s2_START (0)
#define REG_H_V_OCV_PRE3_OUT2_h_v_ocv_out_pre3_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_ocv_out_pre4_s0 : 8;
    } reg;
} REG_H_V_OCV_PRE4_OUT0_UNION;
#endif
#define REG_H_V_OCV_PRE4_OUT0_h_v_ocv_out_pre4_s0_START (0)
#define REG_H_V_OCV_PRE4_OUT0_h_v_ocv_out_pre4_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_ocv_out_pre4_s1 : 8;
    } reg;
} REG_H_V_OCV_PRE4_OUT1_UNION;
#endif
#define REG_H_V_OCV_PRE4_OUT1_h_v_ocv_out_pre4_s1_START (0)
#define REG_H_V_OCV_PRE4_OUT1_h_v_ocv_out_pre4_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_v_ocv_out_pre4_s2 : 8;
    } reg;
} REG_H_V_OCV_PRE4_OUT2_UNION;
#endif
#define REG_H_V_OCV_PRE4_OUT2_h_v_ocv_out_pre4_s2_START (0)
#define REG_H_V_OCV_PRE4_OUT2_h_v_ocv_out_pre4_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_i_ocv_out_pre1_s0 : 8;
    } reg;
} REG_H_I_OCV_PRE1_OUT0_UNION;
#endif
#define REG_H_I_OCV_PRE1_OUT0_h_i_ocv_out_pre1_s0_START (0)
#define REG_H_I_OCV_PRE1_OUT0_h_i_ocv_out_pre1_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_i_ocv_out_pre1_s1 : 8;
    } reg;
} REG_H_I_OCV_PRE1_OUT1_UNION;
#endif
#define REG_H_I_OCV_PRE1_OUT1_h_i_ocv_out_pre1_s1_START (0)
#define REG_H_I_OCV_PRE1_OUT1_h_i_ocv_out_pre1_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_i_ocv_out_pre1_s2 : 8;
    } reg;
} REG_H_I_OCV_PRE1_OUT2_UNION;
#endif
#define REG_H_I_OCV_PRE1_OUT2_h_i_ocv_out_pre1_s2_START (0)
#define REG_H_I_OCV_PRE1_OUT2_h_i_ocv_out_pre1_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_i_ocv_out_pre2_s0 : 8;
    } reg;
} REG_H_I_OCV_PRE2_OUT0_UNION;
#endif
#define REG_H_I_OCV_PRE2_OUT0_h_i_ocv_out_pre2_s0_START (0)
#define REG_H_I_OCV_PRE2_OUT0_h_i_ocv_out_pre2_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_i_ocv_out_pre2_s1 : 8;
    } reg;
} REG_H_I_OCV_PRE2_OUT1_UNION;
#endif
#define REG_H_I_OCV_PRE2_OUT1_h_i_ocv_out_pre2_s1_START (0)
#define REG_H_I_OCV_PRE2_OUT1_h_i_ocv_out_pre2_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_i_ocv_out_pre2_s2 : 8;
    } reg;
} REG_H_I_OCV_PRE2_OUT2_UNION;
#endif
#define REG_H_I_OCV_PRE2_OUT2_h_i_ocv_out_pre2_s2_START (0)
#define REG_H_I_OCV_PRE2_OUT2_h_i_ocv_out_pre2_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_i_ocv_out_pre3_s0 : 8;
    } reg;
} REG_H_I_OCV_PRE3_OUT0_UNION;
#endif
#define REG_H_I_OCV_PRE3_OUT0_h_i_ocv_out_pre3_s0_START (0)
#define REG_H_I_OCV_PRE3_OUT0_h_i_ocv_out_pre3_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_i_ocv_out_pre3_s1 : 8;
    } reg;
} REG_H_I_OCV_PRE3_OUT1_UNION;
#endif
#define REG_H_I_OCV_PRE3_OUT1_h_i_ocv_out_pre3_s1_START (0)
#define REG_H_I_OCV_PRE3_OUT1_h_i_ocv_out_pre3_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_i_ocv_out_pre3_s2 : 8;
    } reg;
} REG_H_I_OCV_PRE3_OUT2_UNION;
#endif
#define REG_H_I_OCV_PRE3_OUT2_h_i_ocv_out_pre3_s2_START (0)
#define REG_H_I_OCV_PRE3_OUT2_h_i_ocv_out_pre3_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_i_ocv_out_pre4_s0 : 8;
    } reg;
} REG_H_I_OCV_PRE4_OUT0_UNION;
#endif
#define REG_H_I_OCV_PRE4_OUT0_h_i_ocv_out_pre4_s0_START (0)
#define REG_H_I_OCV_PRE4_OUT0_h_i_ocv_out_pre4_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_i_ocv_out_pre4_s1 : 8;
    } reg;
} REG_H_I_OCV_PRE4_OUT1_UNION;
#endif
#define REG_H_I_OCV_PRE4_OUT1_h_i_ocv_out_pre4_s1_START (0)
#define REG_H_I_OCV_PRE4_OUT1_h_i_ocv_out_pre4_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char h_i_ocv_out_pre4_s2 : 8;
    } reg;
} REG_H_I_OCV_PRE4_OUT2_UNION;
#endif
#define REG_H_I_OCV_PRE4_OUT2_h_i_ocv_out_pre4_s2_START (0)
#define REG_H_I_OCV_PRE4_OUT2_h_i_ocv_out_pre4_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_out_s0 : 8;
    } reg;
} REG_L_CL_OUT0_UNION;
#endif
#define REG_L_CL_OUT0_l_cl_out_s0_START (0)
#define REG_L_CL_OUT0_l_cl_out_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_out_s1 : 8;
    } reg;
} REG_L_CL_OUT1_UNION;
#endif
#define REG_L_CL_OUT1_l_cl_out_s1_START (0)
#define REG_L_CL_OUT1_l_cl_out_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_out_s2 : 8;
    } reg;
} REG_L_CL_OUT2_UNION;
#endif
#define REG_L_CL_OUT2_l_cl_out_s2_START (0)
#define REG_L_CL_OUT2_l_cl_out_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_out_s3 : 8;
    } reg;
} REG_L_CL_OUT3_UNION;
#endif
#define REG_L_CL_OUT3_l_cl_out_s3_START (0)
#define REG_L_CL_OUT3_l_cl_out_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_out_s4 : 8;
    } reg;
} REG_L_CL_OUT4_UNION;
#endif
#define REG_L_CL_OUT4_l_cl_out_s4_START (0)
#define REG_L_CL_OUT4_l_cl_out_s4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_in_s0 : 8;
    } reg;
} REG_L_CL_IN0_UNION;
#endif
#define REG_L_CL_IN0_l_cl_in_s0_START (0)
#define REG_L_CL_IN0_l_cl_in_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_in_s1 : 8;
    } reg;
} REG_L_CL_IN1_UNION;
#endif
#define REG_L_CL_IN1_l_cl_in_s1_START (0)
#define REG_L_CL_IN1_l_cl_in_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_in_s2 : 8;
    } reg;
} REG_L_CL_IN2_UNION;
#endif
#define REG_L_CL_IN2_l_cl_in_s2_START (0)
#define REG_L_CL_IN2_l_cl_in_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_in_s3 : 8;
    } reg;
} REG_L_CL_IN3_UNION;
#endif
#define REG_L_CL_IN3_l_cl_in_s3_START (0)
#define REG_L_CL_IN3_l_cl_in_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_cl_in_s4 : 8;
    } reg;
} REG_L_CL_IN4_UNION;
#endif
#define REG_L_CL_IN4_l_cl_in_s4_START (0)
#define REG_L_CL_IN4_l_cl_in_s4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_chg_timer_s0 : 8;
    } reg;
} REG_L_CHG_TIMER0_UNION;
#endif
#define REG_L_CHG_TIMER0_l_chg_timer_s0_START (0)
#define REG_L_CHG_TIMER0_l_chg_timer_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_chg_timer_s1 : 8;
    } reg;
} REG_L_CHG_TIMER1_UNION;
#endif
#define REG_L_CHG_TIMER1_l_chg_timer_s1_START (0)
#define REG_L_CHG_TIMER1_l_chg_timer_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_chg_timer_s2 : 8;
    } reg;
} REG_L_CHG_TIMER2_UNION;
#endif
#define REG_L_CHG_TIMER2_l_chg_timer_s2_START (0)
#define REG_L_CHG_TIMER2_l_chg_timer_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_chg_timer_s3 : 8;
    } reg;
} REG_L_CHG_TIMER3_UNION;
#endif
#define REG_L_CHG_TIMER3_l_chg_timer_s3_START (0)
#define REG_L_CHG_TIMER3_l_chg_timer_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_load_timer_s0 : 8;
    } reg;
} REG_L_LOAD_TIMER0_UNION;
#endif
#define REG_L_LOAD_TIMER0_l_load_timer_s0_START (0)
#define REG_L_LOAD_TIMER0_l_load_timer_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_load_timer_s1 : 8;
    } reg;
} REG_L_LOAD_TIMER1_UNION;
#endif
#define REG_L_LOAD_TIMER1_l_load_timer_s1_START (0)
#define REG_L_LOAD_TIMER1_l_load_timer_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_load_timer_s2 : 8;
    } reg;
} REG_L_LOAD_TIMER2_UNION;
#endif
#define REG_L_LOAD_TIMER2_l_load_timer_s2_START (0)
#define REG_L_LOAD_TIMER2_l_load_timer_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_load_timer_s3 : 8;
    } reg;
} REG_L_LOAD_TIMER3_UNION;
#endif
#define REG_L_LOAD_TIMER3_l_load_timer_s3_START (0)
#define REG_L_LOAD_TIMER3_l_load_timer_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_offset_current_mod_s0 : 8;
    } reg;
} REG_L_OFFSET_CURRENT_MOD_0_UNION;
#endif
#define REG_L_OFFSET_CURRENT_MOD_0_l_offset_current_mod_s0_START (0)
#define REG_L_OFFSET_CURRENT_MOD_0_l_offset_current_mod_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_offset_current_mod_s1 : 8;
    } reg;
} REG_L_OFFSET_CURRENT_MOD_1_UNION;
#endif
#define REG_L_OFFSET_CURRENT_MOD_1_l_offset_current_mod_s1_START (0)
#define REG_L_OFFSET_CURRENT_MOD_1_l_offset_current_mod_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_offset_current_mod_s2 : 8;
    } reg;
} REG_L_OFFSET_CURRENT_MOD_2_UNION;
#endif
#define REG_L_OFFSET_CURRENT_MOD_2_l_offset_current_mod_s2_START (0)
#define REG_L_OFFSET_CURRENT_MOD_2_l_offset_current_mod_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_offset_voltage_mod_s0 : 8;
    } reg;
} REG_L_OFFSET_VOLTAGE_MOD_0_UNION;
#endif
#define REG_L_OFFSET_VOLTAGE_MOD_0_l_offset_voltage_mod_s0_START (0)
#define REG_L_OFFSET_VOLTAGE_MOD_0_l_offset_voltage_mod_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_offset_voltage_mod_s1 : 8;
    } reg;
} REG_L_OFFSET_VOLTAGE_MOD_1_UNION;
#endif
#define REG_L_OFFSET_VOLTAGE_MOD_1_l_offset_voltage_mod_s1_START (0)
#define REG_L_OFFSET_VOLTAGE_MOD_1_l_offset_voltage_mod_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_offset_voltage_mod_s2 : 8;
    } reg;
} REG_L_OFFSET_VOLTAGE_MOD_2_UNION;
#endif
#define REG_L_OFFSET_VOLTAGE_MOD_2_l_offset_voltage_mod_s2_START (0)
#define REG_L_OFFSET_VOLTAGE_MOD_2_l_offset_voltage_mod_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_s0 : 8;
    } reg;
} REG_L_CURRENT_0_UNION;
#endif
#define REG_L_CURRENT_0_l_current_s0_START (0)
#define REG_L_CURRENT_0_l_current_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_s1 : 8;
    } reg;
} REG_L_CURRENT_1_UNION;
#endif
#define REG_L_CURRENT_1_l_current_s1_START (0)
#define REG_L_CURRENT_1_l_current_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_s2 : 8;
    } reg;
} REG_L_CURRENT_2_UNION;
#endif
#define REG_L_CURRENT_2_l_current_s2_START (0)
#define REG_L_CURRENT_2_l_current_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_out_s0 : 8;
    } reg;
} REG_L_V_OUT_0_UNION;
#endif
#define REG_L_V_OUT_0_l_v_out_s0_START (0)
#define REG_L_V_OUT_0_l_v_out_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_out_s1 : 8;
    } reg;
} REG_L_V_OUT_1_UNION;
#endif
#define REG_L_V_OUT_1_l_v_out_s1_START (0)
#define REG_L_V_OUT_1_l_v_out_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_out_s2 : 8;
    } reg;
} REG_L_V_OUT_2_UNION;
#endif
#define REG_L_V_OUT_2_l_v_out_s2_START (0)
#define REG_L_V_OUT_2_l_v_out_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_offset_current_s0 : 8;
    } reg;
} REG_L_OFFSET_CURRENT0_UNION;
#endif
#define REG_L_OFFSET_CURRENT0_l_offset_current_s0_START (0)
#define REG_L_OFFSET_CURRENT0_l_offset_current_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_offset_current_s1 : 8;
    } reg;
} REG_L_OFFSET_CURRENT1_UNION;
#endif
#define REG_L_OFFSET_CURRENT1_l_offset_current_s1_START (0)
#define REG_L_OFFSET_CURRENT1_l_offset_current_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_offset_current_s2 : 8;
    } reg;
} REG_L_OFFSET_CURRENT2_UNION;
#endif
#define REG_L_OFFSET_CURRENT2_l_offset_current_s2_START (0)
#define REG_L_OFFSET_CURRENT2_l_offset_current_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_offset_voltage_s0 : 8;
    } reg;
} REG_L_OFFSET_VOLTAGE0_UNION;
#endif
#define REG_L_OFFSET_VOLTAGE0_l_offset_voltage_s0_START (0)
#define REG_L_OFFSET_VOLTAGE0_l_offset_voltage_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_offset_voltage_s1 : 8;
    } reg;
} REG_L_OFFSET_VOLTAGE1_UNION;
#endif
#define REG_L_OFFSET_VOLTAGE1_l_offset_voltage_s1_START (0)
#define REG_L_OFFSET_VOLTAGE1_l_offset_voltage_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_offset_voltage_s2 : 8;
    } reg;
} REG_L_OFFSET_VOLTAGE2_UNION;
#endif
#define REG_L_OFFSET_VOLTAGE2_l_offset_voltage_s2_START (0)
#define REG_L_OFFSET_VOLTAGE2_l_offset_voltage_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_ocv_data_s0 : 8;
    } reg;
} REG_L_OCV_VOLTAGE0_UNION;
#endif
#define REG_L_OCV_VOLTAGE0_l_v_ocv_data_s0_START (0)
#define REG_L_OCV_VOLTAGE0_l_v_ocv_data_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_ocv_data_s1 : 8;
    } reg;
} REG_L_OCV_VOLTAGE1_UNION;
#endif
#define REG_L_OCV_VOLTAGE1_l_v_ocv_data_s1_START (0)
#define REG_L_OCV_VOLTAGE1_l_v_ocv_data_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_ocv_data_s2 : 8;
    } reg;
} REG_L_OCV_VOLTAGE2_UNION;
#endif
#define REG_L_OCV_VOLTAGE2_l_v_ocv_data_s2_START (0)
#define REG_L_OCV_VOLTAGE2_l_v_ocv_data_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_i_ocv_data_s0 : 8;
    } reg;
} REG_L_OCV_CURRENT0_UNION;
#endif
#define REG_L_OCV_CURRENT0_l_i_ocv_data_s0_START (0)
#define REG_L_OCV_CURRENT0_l_i_ocv_data_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_i_ocv_data_s1 : 8;
    } reg;
} REG_L_OCV_CURRENT1_UNION;
#endif
#define REG_L_OCV_CURRENT1_l_i_ocv_data_s1_START (0)
#define REG_L_OCV_CURRENT1_l_i_ocv_data_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_i_ocv_data_s2 : 8;
    } reg;
} REG_L_OCV_CURRENT2_UNION;
#endif
#define REG_L_OCV_CURRENT2_l_i_ocv_data_s2_START (0)
#define REG_L_OCV_CURRENT2_l_i_ocv_data_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_eco_out_clin_s0 : 8;
    } reg;
} REG_L_ECO_OUT_CLIN_0_UNION;
#endif
#define REG_L_ECO_OUT_CLIN_0_l_eco_out_clin_s0_START (0)
#define REG_L_ECO_OUT_CLIN_0_l_eco_out_clin_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_eco_out_clin_s1 : 8;
    } reg;
} REG_L_ECO_OUT_CLIN_1_UNION;
#endif
#define REG_L_ECO_OUT_CLIN_1_l_eco_out_clin_s1_START (0)
#define REG_L_ECO_OUT_CLIN_1_l_eco_out_clin_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_eco_out_clin_s2 : 8;
    } reg;
} REG_L_ECO_OUT_CLIN_2_UNION;
#endif
#define REG_L_ECO_OUT_CLIN_2_l_eco_out_clin_s2_START (0)
#define REG_L_ECO_OUT_CLIN_2_l_eco_out_clin_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_eco_out_clin_s3 : 8;
    } reg;
} REG_L_ECO_OUT_CLIN_3_UNION;
#endif
#define REG_L_ECO_OUT_CLIN_3_l_eco_out_clin_s3_START (0)
#define REG_L_ECO_OUT_CLIN_3_l_eco_out_clin_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_eco_out_clin_s4 : 8;
    } reg;
} REG_L_ECO_OUT_CLIN_4_UNION;
#endif
#define REG_L_ECO_OUT_CLIN_4_l_eco_out_clin_s4_START (0)
#define REG_L_ECO_OUT_CLIN_4_l_eco_out_clin_s4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_eco_out_clout_s0 : 8;
    } reg;
} REG_L_ECO_OUT_CLOUT_0_UNION;
#endif
#define REG_L_ECO_OUT_CLOUT_0_l_eco_out_clout_s0_START (0)
#define REG_L_ECO_OUT_CLOUT_0_l_eco_out_clout_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_eco_out_clout_s1 : 8;
    } reg;
} REG_L_ECO_OUT_CLOUT_1_UNION;
#endif
#define REG_L_ECO_OUT_CLOUT_1_l_eco_out_clout_s1_START (0)
#define REG_L_ECO_OUT_CLOUT_1_l_eco_out_clout_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_eco_out_clout_s2 : 8;
    } reg;
} REG_L_ECO_OUT_CLOUT_2_UNION;
#endif
#define REG_L_ECO_OUT_CLOUT_2_l_eco_out_clout_s2_START (0)
#define REG_L_ECO_OUT_CLOUT_2_l_eco_out_clout_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_eco_out_clout_s3 : 8;
    } reg;
} REG_L_ECO_OUT_CLOUT_3_UNION;
#endif
#define REG_L_ECO_OUT_CLOUT_3_l_eco_out_clout_s3_START (0)
#define REG_L_ECO_OUT_CLOUT_3_l_eco_out_clout_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_eco_out_clout_s4 : 8;
    } reg;
} REG_L_ECO_OUT_CLOUT_4_UNION;
#endif
#define REG_L_ECO_OUT_CLOUT_4_l_eco_out_clout_s4_START (0)
#define REG_L_ECO_OUT_CLOUT_4_l_eco_out_clout_s4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre0_s0 : 8;
    } reg;
} REG_L_V_PRE0_OUT0_UNION;
#endif
#define REG_L_V_PRE0_OUT0_l_vout_pre0_s0_START (0)
#define REG_L_V_PRE0_OUT0_l_vout_pre0_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre0_s1 : 8;
    } reg;
} REG_L_V_PRE0_OUT1_UNION;
#endif
#define REG_L_V_PRE0_OUT1_l_vout_pre0_s1_START (0)
#define REG_L_V_PRE0_OUT1_l_vout_pre0_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre0_s2 : 8;
    } reg;
} REG_L_V_PRE0_OUT2_UNION;
#endif
#define REG_L_V_PRE0_OUT2_l_vout_pre0_s2_START (0)
#define REG_L_V_PRE0_OUT2_l_vout_pre0_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre1_s0 : 8;
    } reg;
} REG_L_V_PRE1_OUT0_UNION;
#endif
#define REG_L_V_PRE1_OUT0_l_vout_pre1_s0_START (0)
#define REG_L_V_PRE1_OUT0_l_vout_pre1_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre1_s1 : 8;
    } reg;
} REG_L_V_PRE1_OUT1_UNION;
#endif
#define REG_L_V_PRE1_OUT1_l_vout_pre1_s1_START (0)
#define REG_L_V_PRE1_OUT1_l_vout_pre1_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre1_s2 : 8;
    } reg;
} REG_L_V_PRE1_OUT2_UNION;
#endif
#define REG_L_V_PRE1_OUT2_l_vout_pre1_s2_START (0)
#define REG_L_V_PRE1_OUT2_l_vout_pre1_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre2_s0 : 8;
    } reg;
} REG_L_V_PRE2_OUT0_UNION;
#endif
#define REG_L_V_PRE2_OUT0_l_vout_pre2_s0_START (0)
#define REG_L_V_PRE2_OUT0_l_vout_pre2_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre2_s1 : 8;
    } reg;
} REG_L_V_PRE2_OUT1_UNION;
#endif
#define REG_L_V_PRE2_OUT1_l_vout_pre2_s1_START (0)
#define REG_L_V_PRE2_OUT1_l_vout_pre2_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre2_s2 : 8;
    } reg;
} REG_L_V_PRE2_OUT2_UNION;
#endif
#define REG_L_V_PRE2_OUT2_l_vout_pre2_s2_START (0)
#define REG_L_V_PRE2_OUT2_l_vout_pre2_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre3_s0 : 8;
    } reg;
} REG_L_V_PRE3_OUT0_UNION;
#endif
#define REG_L_V_PRE3_OUT0_l_vout_pre3_s0_START (0)
#define REG_L_V_PRE3_OUT0_l_vout_pre3_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre3_s1 : 8;
    } reg;
} REG_L_V_PRE3_OUT1_UNION;
#endif
#define REG_L_V_PRE3_OUT1_l_vout_pre3_s1_START (0)
#define REG_L_V_PRE3_OUT1_l_vout_pre3_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre3_s2 : 8;
    } reg;
} REG_L_V_PRE3_OUT2_UNION;
#endif
#define REG_L_V_PRE3_OUT2_l_vout_pre3_s2_START (0)
#define REG_L_V_PRE3_OUT2_l_vout_pre3_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre4_s0 : 8;
    } reg;
} REG_L_V_PRE4_OUT0_UNION;
#endif
#define REG_L_V_PRE4_OUT0_l_vout_pre4_s0_START (0)
#define REG_L_V_PRE4_OUT0_l_vout_pre4_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre4_s1 : 8;
    } reg;
} REG_L_V_PRE4_OUT1_UNION;
#endif
#define REG_L_V_PRE4_OUT1_l_vout_pre4_s1_START (0)
#define REG_L_V_PRE4_OUT1_l_vout_pre4_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre4_s2 : 8;
    } reg;
} REG_L_V_PRE4_OUT2_UNION;
#endif
#define REG_L_V_PRE4_OUT2_l_vout_pre4_s2_START (0)
#define REG_L_V_PRE4_OUT2_l_vout_pre4_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre5_s0 : 8;
    } reg;
} REG_L_V_PRE5_OUT0_UNION;
#endif
#define REG_L_V_PRE5_OUT0_l_vout_pre5_s0_START (0)
#define REG_L_V_PRE5_OUT0_l_vout_pre5_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre5_s1 : 8;
    } reg;
} REG_L_V_PRE5_OUT1_UNION;
#endif
#define REG_L_V_PRE5_OUT1_l_vout_pre5_s1_START (0)
#define REG_L_V_PRE5_OUT1_l_vout_pre5_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre5_s2 : 8;
    } reg;
} REG_L_V_PRE5_OUT2_UNION;
#endif
#define REG_L_V_PRE5_OUT2_l_vout_pre5_s2_START (0)
#define REG_L_V_PRE5_OUT2_l_vout_pre5_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre6_s0 : 8;
    } reg;
} REG_L_V_PRE6_OUT0_UNION;
#endif
#define REG_L_V_PRE6_OUT0_l_vout_pre6_s0_START (0)
#define REG_L_V_PRE6_OUT0_l_vout_pre6_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre6_s1 : 8;
    } reg;
} REG_L_V_PRE6_OUT1_UNION;
#endif
#define REG_L_V_PRE6_OUT1_l_vout_pre6_s1_START (0)
#define REG_L_V_PRE6_OUT1_l_vout_pre6_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre6_s2 : 8;
    } reg;
} REG_L_V_PRE6_OUT2_UNION;
#endif
#define REG_L_V_PRE6_OUT2_l_vout_pre6_s2_START (0)
#define REG_L_V_PRE6_OUT2_l_vout_pre6_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre7_s0 : 8;
    } reg;
} REG_L_V_PRE7_OUT0_UNION;
#endif
#define REG_L_V_PRE7_OUT0_l_vout_pre7_s0_START (0)
#define REG_L_V_PRE7_OUT0_l_vout_pre7_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre7_s1 : 8;
    } reg;
} REG_L_V_PRE7_OUT1_UNION;
#endif
#define REG_L_V_PRE7_OUT1_l_vout_pre7_s1_START (0)
#define REG_L_V_PRE7_OUT1_l_vout_pre7_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_vout_pre7_s2 : 8;
    } reg;
} REG_L_V_PRE7_OUT2_UNION;
#endif
#define REG_L_V_PRE7_OUT2_l_vout_pre7_s2_START (0)
#define REG_L_V_PRE7_OUT2_l_vout_pre7_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre0_s0 : 8;
    } reg;
} REG_L_CURRENT_PRE0_OUT0_UNION;
#endif
#define REG_L_CURRENT_PRE0_OUT0_l_current_pre0_s0_START (0)
#define REG_L_CURRENT_PRE0_OUT0_l_current_pre0_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre0_s1 : 8;
    } reg;
} REG_L_CURRENT_PRE0_OUT1_UNION;
#endif
#define REG_L_CURRENT_PRE0_OUT1_l_current_pre0_s1_START (0)
#define REG_L_CURRENT_PRE0_OUT1_l_current_pre0_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre0_s2 : 8;
    } reg;
} REG_L_CURRENT_PRE0_OUT2_UNION;
#endif
#define REG_L_CURRENT_PRE0_OUT2_l_current_pre0_s2_START (0)
#define REG_L_CURRENT_PRE0_OUT2_l_current_pre0_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre1_s0 : 8;
    } reg;
} REG_L_CURRENT_PRE1_OUT0_UNION;
#endif
#define REG_L_CURRENT_PRE1_OUT0_l_current_pre1_s0_START (0)
#define REG_L_CURRENT_PRE1_OUT0_l_current_pre1_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre1_s1 : 8;
    } reg;
} REG_L_CURRENT_PRE1_OUT1_UNION;
#endif
#define REG_L_CURRENT_PRE1_OUT1_l_current_pre1_s1_START (0)
#define REG_L_CURRENT_PRE1_OUT1_l_current_pre1_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre1_s2 : 8;
    } reg;
} REG_L_CURRENT_PRE1_OUT2_UNION;
#endif
#define REG_L_CURRENT_PRE1_OUT2_l_current_pre1_s2_START (0)
#define REG_L_CURRENT_PRE1_OUT2_l_current_pre1_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre2_s0 : 8;
    } reg;
} REG_L_CURRENT_PRE2_OUT0_UNION;
#endif
#define REG_L_CURRENT_PRE2_OUT0_l_current_pre2_s0_START (0)
#define REG_L_CURRENT_PRE2_OUT0_l_current_pre2_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre2_s1 : 8;
    } reg;
} REG_L_CURRENT_PRE2_OUT1_UNION;
#endif
#define REG_L_CURRENT_PRE2_OUT1_l_current_pre2_s1_START (0)
#define REG_L_CURRENT_PRE2_OUT1_l_current_pre2_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre2_s2 : 8;
    } reg;
} REG_L_CURRENT_PRE2_OUT2_UNION;
#endif
#define REG_L_CURRENT_PRE2_OUT2_l_current_pre2_s2_START (0)
#define REG_L_CURRENT_PRE2_OUT2_l_current_pre2_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre3_s0 : 8;
    } reg;
} REG_L_CURRENT_PRE3_OUT0_UNION;
#endif
#define REG_L_CURRENT_PRE3_OUT0_l_current_pre3_s0_START (0)
#define REG_L_CURRENT_PRE3_OUT0_l_current_pre3_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre3_s1 : 8;
    } reg;
} REG_L_CURRENT_PRE3_OUT1_UNION;
#endif
#define REG_L_CURRENT_PRE3_OUT1_l_current_pre3_s1_START (0)
#define REG_L_CURRENT_PRE3_OUT1_l_current_pre3_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre3_s2 : 8;
    } reg;
} REG_L_CURRENT_PRE3_OUT2_UNION;
#endif
#define REG_L_CURRENT_PRE3_OUT2_l_current_pre3_s2_START (0)
#define REG_L_CURRENT_PRE3_OUT2_l_current_pre3_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre4_s0 : 8;
    } reg;
} REG_L_CURRENT_PRE4_OUT0_UNION;
#endif
#define REG_L_CURRENT_PRE4_OUT0_l_current_pre4_s0_START (0)
#define REG_L_CURRENT_PRE4_OUT0_l_current_pre4_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre4_s1 : 8;
    } reg;
} REG_L_CURRENT_PRE4_OUT1_UNION;
#endif
#define REG_L_CURRENT_PRE4_OUT1_l_current_pre4_s1_START (0)
#define REG_L_CURRENT_PRE4_OUT1_l_current_pre4_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre4_s2 : 8;
    } reg;
} REG_L_CURRENT_PRE4_OUT2_UNION;
#endif
#define REG_L_CURRENT_PRE4_OUT2_l_current_pre4_s2_START (0)
#define REG_L_CURRENT_PRE4_OUT2_l_current_pre4_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre5_s0 : 8;
    } reg;
} REG_L_CURRENT_PRE5_OUT0_UNION;
#endif
#define REG_L_CURRENT_PRE5_OUT0_l_current_pre5_s0_START (0)
#define REG_L_CURRENT_PRE5_OUT0_l_current_pre5_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre5_s1 : 8;
    } reg;
} REG_L_CURRENT_PRE5_OUT1_UNION;
#endif
#define REG_L_CURRENT_PRE5_OUT1_l_current_pre5_s1_START (0)
#define REG_L_CURRENT_PRE5_OUT1_l_current_pre5_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre5_s2 : 8;
    } reg;
} REG_L_CURRENT_PRE5_OUT2_UNION;
#endif
#define REG_L_CURRENT_PRE5_OUT2_l_current_pre5_s2_START (0)
#define REG_L_CURRENT_PRE5_OUT2_l_current_pre5_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre6_s0 : 8;
    } reg;
} REG_L_CURRENT_PRE6_OUT0_UNION;
#endif
#define REG_L_CURRENT_PRE6_OUT0_l_current_pre6_s0_START (0)
#define REG_L_CURRENT_PRE6_OUT0_l_current_pre6_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre6_s1 : 8;
    } reg;
} REG_L_CURRENT_PRE6_OUT1_UNION;
#endif
#define REG_L_CURRENT_PRE6_OUT1_l_current_pre6_s1_START (0)
#define REG_L_CURRENT_PRE6_OUT1_l_current_pre6_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre6_s2 : 8;
    } reg;
} REG_L_CURRENT_PRE6_OUT2_UNION;
#endif
#define REG_L_CURRENT_PRE6_OUT2_l_current_pre6_s2_START (0)
#define REG_L_CURRENT_PRE6_OUT2_l_current_pre6_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre7_s0 : 8;
    } reg;
} REG_L_CURRENT_PRE7_OUT0_UNION;
#endif
#define REG_L_CURRENT_PRE7_OUT0_l_current_pre7_s0_START (0)
#define REG_L_CURRENT_PRE7_OUT0_l_current_pre7_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre7_s1 : 8;
    } reg;
} REG_L_CURRENT_PRE7_OUT1_UNION;
#endif
#define REG_L_CURRENT_PRE7_OUT1_l_current_pre7_s1_START (0)
#define REG_L_CURRENT_PRE7_OUT1_l_current_pre7_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_current_pre7_s2 : 8;
    } reg;
} REG_L_CURRENT_PRE7_OUT2_UNION;
#endif
#define REG_L_CURRENT_PRE7_OUT2_l_current_pre7_s2_START (0)
#define REG_L_CURRENT_PRE7_OUT2_l_current_pre7_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_ocv_out_pre1_s0 : 8;
    } reg;
} REG_L_V_OCV_PRE1_OUT0_UNION;
#endif
#define REG_L_V_OCV_PRE1_OUT0_l_v_ocv_out_pre1_s0_START (0)
#define REG_L_V_OCV_PRE1_OUT0_l_v_ocv_out_pre1_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_ocv_out_pre1_s1 : 8;
    } reg;
} REG_L_V_OCV_PRE1_OUT1_UNION;
#endif
#define REG_L_V_OCV_PRE1_OUT1_l_v_ocv_out_pre1_s1_START (0)
#define REG_L_V_OCV_PRE1_OUT1_l_v_ocv_out_pre1_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_ocv_out_pre1_s2 : 8;
    } reg;
} REG_L_V_OCV_PRE1_OUT2_UNION;
#endif
#define REG_L_V_OCV_PRE1_OUT2_l_v_ocv_out_pre1_s2_START (0)
#define REG_L_V_OCV_PRE1_OUT2_l_v_ocv_out_pre1_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_ocv_out_pre2_s0 : 8;
    } reg;
} REG_L_V_OCV_PRE2_OUT0_UNION;
#endif
#define REG_L_V_OCV_PRE2_OUT0_l_v_ocv_out_pre2_s0_START (0)
#define REG_L_V_OCV_PRE2_OUT0_l_v_ocv_out_pre2_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_ocv_out_pre2_s1 : 8;
    } reg;
} REG_L_V_OCV_PRE2_OUT1_UNION;
#endif
#define REG_L_V_OCV_PRE2_OUT1_l_v_ocv_out_pre2_s1_START (0)
#define REG_L_V_OCV_PRE2_OUT1_l_v_ocv_out_pre2_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_ocv_out_pre2_s2 : 8;
    } reg;
} REG_L_V_OCV_PRE2_OUT2_UNION;
#endif
#define REG_L_V_OCV_PRE2_OUT2_l_v_ocv_out_pre2_s2_START (0)
#define REG_L_V_OCV_PRE2_OUT2_l_v_ocv_out_pre2_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_ocv_out_pre3_s0 : 8;
    } reg;
} REG_L_V_OCV_PRE3_OUT0_UNION;
#endif
#define REG_L_V_OCV_PRE3_OUT0_l_v_ocv_out_pre3_s0_START (0)
#define REG_L_V_OCV_PRE3_OUT0_l_v_ocv_out_pre3_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_ocv_out_pre3_s1 : 8;
    } reg;
} REG_L_V_OCV_PRE3_OUT1_UNION;
#endif
#define REG_L_V_OCV_PRE3_OUT1_l_v_ocv_out_pre3_s1_START (0)
#define REG_L_V_OCV_PRE3_OUT1_l_v_ocv_out_pre3_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_ocv_out_pre3_s2 : 8;
    } reg;
} REG_L_V_OCV_PRE3_OUT2_UNION;
#endif
#define REG_L_V_OCV_PRE3_OUT2_l_v_ocv_out_pre3_s2_START (0)
#define REG_L_V_OCV_PRE3_OUT2_l_v_ocv_out_pre3_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_ocv_out_pre4_s0 : 8;
    } reg;
} REG_L_V_OCV_PRE4_OUT0_UNION;
#endif
#define REG_L_V_OCV_PRE4_OUT0_l_v_ocv_out_pre4_s0_START (0)
#define REG_L_V_OCV_PRE4_OUT0_l_v_ocv_out_pre4_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_ocv_out_pre4_s1 : 8;
    } reg;
} REG_L_V_OCV_PRE4_OUT1_UNION;
#endif
#define REG_L_V_OCV_PRE4_OUT1_l_v_ocv_out_pre4_s1_START (0)
#define REG_L_V_OCV_PRE4_OUT1_l_v_ocv_out_pre4_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_v_ocv_out_pre4_s2 : 8;
    } reg;
} REG_L_V_OCV_PRE4_OUT2_UNION;
#endif
#define REG_L_V_OCV_PRE4_OUT2_l_v_ocv_out_pre4_s2_START (0)
#define REG_L_V_OCV_PRE4_OUT2_l_v_ocv_out_pre4_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_i_ocv_out_pre1_s0 : 8;
    } reg;
} REG_L_I_OCV_PRE1_OUT0_UNION;
#endif
#define REG_L_I_OCV_PRE1_OUT0_l_i_ocv_out_pre1_s0_START (0)
#define REG_L_I_OCV_PRE1_OUT0_l_i_ocv_out_pre1_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_i_ocv_out_pre1_s1 : 8;
    } reg;
} REG_L_I_OCV_PRE1_OUT1_UNION;
#endif
#define REG_L_I_OCV_PRE1_OUT1_l_i_ocv_out_pre1_s1_START (0)
#define REG_L_I_OCV_PRE1_OUT1_l_i_ocv_out_pre1_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_i_ocv_out_pre1_s2 : 8;
    } reg;
} REG_L_I_OCV_PRE1_OUT2_UNION;
#endif
#define REG_L_I_OCV_PRE1_OUT2_l_i_ocv_out_pre1_s2_START (0)
#define REG_L_I_OCV_PRE1_OUT2_l_i_ocv_out_pre1_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_i_ocv_out_pre2_s0 : 8;
    } reg;
} REG_L_I_OCV_PRE2_OUT0_UNION;
#endif
#define REG_L_I_OCV_PRE2_OUT0_l_i_ocv_out_pre2_s0_START (0)
#define REG_L_I_OCV_PRE2_OUT0_l_i_ocv_out_pre2_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_i_ocv_out_pre2_s1 : 8;
    } reg;
} REG_L_I_OCV_PRE2_OUT1_UNION;
#endif
#define REG_L_I_OCV_PRE2_OUT1_l_i_ocv_out_pre2_s1_START (0)
#define REG_L_I_OCV_PRE2_OUT1_l_i_ocv_out_pre2_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_i_ocv_out_pre2_s2 : 8;
    } reg;
} REG_L_I_OCV_PRE2_OUT2_UNION;
#endif
#define REG_L_I_OCV_PRE2_OUT2_l_i_ocv_out_pre2_s2_START (0)
#define REG_L_I_OCV_PRE2_OUT2_l_i_ocv_out_pre2_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_i_ocv_out_pre3_s0 : 8;
    } reg;
} REG_L_I_OCV_PRE3_OUT0_UNION;
#endif
#define REG_L_I_OCV_PRE3_OUT0_l_i_ocv_out_pre3_s0_START (0)
#define REG_L_I_OCV_PRE3_OUT0_l_i_ocv_out_pre3_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_i_ocv_out_pre3_s1 : 8;
    } reg;
} REG_L_I_OCV_PRE3_OUT1_UNION;
#endif
#define REG_L_I_OCV_PRE3_OUT1_l_i_ocv_out_pre3_s1_START (0)
#define REG_L_I_OCV_PRE3_OUT1_l_i_ocv_out_pre3_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_i_ocv_out_pre3_s2 : 8;
    } reg;
} REG_L_I_OCV_PRE3_OUT2_UNION;
#endif
#define REG_L_I_OCV_PRE3_OUT2_l_i_ocv_out_pre3_s2_START (0)
#define REG_L_I_OCV_PRE3_OUT2_l_i_ocv_out_pre3_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_i_ocv_out_pre4_s0 : 8;
    } reg;
} REG_L_I_OCV_PRE4_OUT0_UNION;
#endif
#define REG_L_I_OCV_PRE4_OUT0_l_i_ocv_out_pre4_s0_START (0)
#define REG_L_I_OCV_PRE4_OUT0_l_i_ocv_out_pre4_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_i_ocv_out_pre4_s1 : 8;
    } reg;
} REG_L_I_OCV_PRE4_OUT1_UNION;
#endif
#define REG_L_I_OCV_PRE4_OUT1_l_i_ocv_out_pre4_s1_START (0)
#define REG_L_I_OCV_PRE4_OUT1_l_i_ocv_out_pre4_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char l_i_ocv_out_pre4_s2 : 8;
    } reg;
} REG_L_I_OCV_PRE4_OUT2_UNION;
#endif
#define REG_L_I_OCV_PRE4_OUT2_l_i_ocv_out_pre4_s2_START (0)
#define REG_L_I_OCV_PRE4_OUT2_l_i_ocv_out_pre4_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_group_fcp : 1;
        unsigned char irq_group_flash : 1;
        unsigned char irq_group_ufcs : 1;
        unsigned char irq_group_bc12 : 1;
        unsigned char irq_group_pd : 1;
        unsigned char irq_group_sc : 1;
        unsigned char irq_group_chg : 1;
        unsigned char irq_group_coul : 1;
    } reg;
} REG_IRQ_FLAG_UNION;
#endif
#define REG_IRQ_FLAG_irq_group_fcp_START (0)
#define REG_IRQ_FLAG_irq_group_fcp_END (0)
#define REG_IRQ_FLAG_irq_group_flash_START (1)
#define REG_IRQ_FLAG_irq_group_flash_END (1)
#define REG_IRQ_FLAG_irq_group_ufcs_START (2)
#define REG_IRQ_FLAG_irq_group_ufcs_END (2)
#define REG_IRQ_FLAG_irq_group_bc12_START (3)
#define REG_IRQ_FLAG_irq_group_bc12_END (3)
#define REG_IRQ_FLAG_irq_group_pd_START (4)
#define REG_IRQ_FLAG_irq_group_pd_END (4)
#define REG_IRQ_FLAG_irq_group_sc_START (5)
#define REG_IRQ_FLAG_irq_group_sc_END (5)
#define REG_IRQ_FLAG_irq_group_chg_START (6)
#define REG_IRQ_FLAG_irq_group_chg_END (6)
#define REG_IRQ_FLAG_irq_group_coul_START (7)
#define REG_IRQ_FLAG_irq_group_coul_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} REG_IRQ_FLAG_RSV_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_psw_vpsw_plugin : 1;
        unsigned char irq_psw_vpsw_plugout : 1;
        unsigned char irq_psw_vpsw_uvlo : 1;
        unsigned char irq_ovp_vusb_ovp : 1;
        unsigned char irq_ovp_pwron : 1;
        unsigned char irq_ovp_vusb_plugin : 1;
        unsigned char irq_ovp_vusb_plugout : 1;
        unsigned char irq_ovp_vusb_uvlo : 1;
    } reg;
} REG_IRQ_FLAG_0_UNION;
#endif
#define REG_IRQ_FLAG_0_irq_psw_vpsw_plugin_START (0)
#define REG_IRQ_FLAG_0_irq_psw_vpsw_plugin_END (0)
#define REG_IRQ_FLAG_0_irq_psw_vpsw_plugout_START (1)
#define REG_IRQ_FLAG_0_irq_psw_vpsw_plugout_END (1)
#define REG_IRQ_FLAG_0_irq_psw_vpsw_uvlo_START (2)
#define REG_IRQ_FLAG_0_irq_psw_vpsw_uvlo_END (2)
#define REG_IRQ_FLAG_0_irq_ovp_vusb_ovp_START (3)
#define REG_IRQ_FLAG_0_irq_ovp_vusb_ovp_END (3)
#define REG_IRQ_FLAG_0_irq_ovp_pwron_START (4)
#define REG_IRQ_FLAG_0_irq_ovp_pwron_END (4)
#define REG_IRQ_FLAG_0_irq_ovp_vusb_plugin_START (5)
#define REG_IRQ_FLAG_0_irq_ovp_vusb_plugin_END (5)
#define REG_IRQ_FLAG_0_irq_ovp_vusb_plugout_START (6)
#define REG_IRQ_FLAG_0_irq_ovp_vusb_plugout_END (6)
#define REG_IRQ_FLAG_0_irq_ovp_vusb_uvlo_START (7)
#define REG_IRQ_FLAG_0_irq_ovp_vusb_uvlo_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_otg_ocp : 1;
        unsigned char irq_buck_ocp : 1;
        unsigned char irq_otg_scp : 1;
        unsigned char irq_otg_uvp : 1;
        unsigned char irq_otg_ovp : 1;
        unsigned char irq_regn_ocp : 1;
        unsigned char irq_psw_vpsw_ovp : 1;
        unsigned char irq_psw_pwron : 1;
    } reg;
} REG_IRQ_FLAG_1_UNION;
#endif
#define REG_IRQ_FLAG_1_irq_otg_ocp_START (0)
#define REG_IRQ_FLAG_1_irq_otg_ocp_END (0)
#define REG_IRQ_FLAG_1_irq_buck_ocp_START (1)
#define REG_IRQ_FLAG_1_irq_buck_ocp_END (1)
#define REG_IRQ_FLAG_1_irq_otg_scp_START (2)
#define REG_IRQ_FLAG_1_irq_otg_scp_END (2)
#define REG_IRQ_FLAG_1_irq_otg_uvp_START (3)
#define REG_IRQ_FLAG_1_irq_otg_uvp_END (3)
#define REG_IRQ_FLAG_1_irq_otg_ovp_START (4)
#define REG_IRQ_FLAG_1_irq_otg_ovp_END (4)
#define REG_IRQ_FLAG_1_irq_regn_ocp_START (5)
#define REG_IRQ_FLAG_1_irq_regn_ocp_END (5)
#define REG_IRQ_FLAG_1_irq_psw_vpsw_ovp_START (6)
#define REG_IRQ_FLAG_1_irq_psw_vpsw_ovp_END (6)
#define REG_IRQ_FLAG_1_irq_psw_pwron_START (7)
#define REG_IRQ_FLAG_1_irq_psw_pwron_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_fast_charge_fault : 1;
        unsigned char irq_pre_charge_fault : 1;
        unsigned char irq_trickle_charge_fault : 1;
        unsigned char irq_vbat_ovp : 1;
        unsigned char irq_batfet_ocp : 1;
        unsigned char irq_vsys_l_scp : 1;
        unsigned char irq_vsys_h_ovp : 1;
        unsigned char irq_vsys_h_scp : 1;
    } reg;
} REG_IRQ_FLAG_2_UNION;
#endif
#define REG_IRQ_FLAG_2_irq_fast_charge_fault_START (0)
#define REG_IRQ_FLAG_2_irq_fast_charge_fault_END (0)
#define REG_IRQ_FLAG_2_irq_pre_charge_fault_START (1)
#define REG_IRQ_FLAG_2_irq_pre_charge_fault_END (1)
#define REG_IRQ_FLAG_2_irq_trickle_charge_fault_START (2)
#define REG_IRQ_FLAG_2_irq_trickle_charge_fault_END (2)
#define REG_IRQ_FLAG_2_irq_vbat_ovp_START (3)
#define REG_IRQ_FLAG_2_irq_vbat_ovp_END (3)
#define REG_IRQ_FLAG_2_irq_batfet_ocp_START (4)
#define REG_IRQ_FLAG_2_irq_batfet_ocp_END (4)
#define REG_IRQ_FLAG_2_irq_vsys_l_scp_START (5)
#define REG_IRQ_FLAG_2_irq_vsys_l_scp_END (5)
#define REG_IRQ_FLAG_2_irq_vsys_h_ovp_START (6)
#define REG_IRQ_FLAG_2_irq_vsys_h_ovp_END (6)
#define REG_IRQ_FLAG_2_irq_vsys_h_scp_START (7)
#define REG_IRQ_FLAG_2_irq_vsys_h_scp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_reversbst : 1;
        unsigned char irq_vbat_lv : 1;
        unsigned char irq_chg_rechg : 1;
        unsigned char irq_chg_eoc : 1;
        unsigned char irq_tdie_otp : 1;
        unsigned char irq_otmp_jreg : 1;
        unsigned char irq_tbat_otp : 1;
        unsigned char irq_wdt_tot : 1;
    } reg;
} REG_IRQ_FLAG_3_UNION;
#endif
#define REG_IRQ_FLAG_3_irq_reversbst_START (0)
#define REG_IRQ_FLAG_3_irq_reversbst_END (0)
#define REG_IRQ_FLAG_3_irq_vbat_lv_START (1)
#define REG_IRQ_FLAG_3_irq_vbat_lv_END (1)
#define REG_IRQ_FLAG_3_irq_chg_rechg_START (2)
#define REG_IRQ_FLAG_3_irq_chg_rechg_END (2)
#define REG_IRQ_FLAG_3_irq_chg_eoc_START (3)
#define REG_IRQ_FLAG_3_irq_chg_eoc_END (3)
#define REG_IRQ_FLAG_3_irq_tdie_otp_START (4)
#define REG_IRQ_FLAG_3_irq_tdie_otp_END (4)
#define REG_IRQ_FLAG_3_irq_otmp_jreg_START (5)
#define REG_IRQ_FLAG_3_irq_otmp_jreg_END (5)
#define REG_IRQ_FLAG_3_irq_tbat_otp_START (6)
#define REG_IRQ_FLAG_3_irq_tbat_otp_END (6)
#define REG_IRQ_FLAG_3_irq_wdt_tot_START (7)
#define REG_IRQ_FLAG_3_irq_wdt_tot_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_ldo33_scp : 1;
        unsigned char irq_ldo1p8_ana_scp : 1;
        unsigned char irq_vpsw_sleep_mod : 1;
        unsigned char irq_vusb_sleep_mod : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 1;
        unsigned char reserved_2 : 1;
        unsigned char reserved_3 : 1;
    } reg;
} REG_IRQ_FLAG_4_UNION;
#endif
#define REG_IRQ_FLAG_4_irq_ldo33_scp_START (0)
#define REG_IRQ_FLAG_4_irq_ldo33_scp_END (0)
#define REG_IRQ_FLAG_4_irq_ldo1p8_ana_scp_START (1)
#define REG_IRQ_FLAG_4_irq_ldo1p8_ana_scp_END (1)
#define REG_IRQ_FLAG_4_irq_vpsw_sleep_mod_START (2)
#define REG_IRQ_FLAG_4_irq_vpsw_sleep_mod_END (2)
#define REG_IRQ_FLAG_4_irq_vusb_sleep_mod_START (3)
#define REG_IRQ_FLAG_4_irq_vusb_sleep_mod_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_reserved_0 : 1;
        unsigned char irq_reserved_1 : 1;
        unsigned char irq_reserved_2 : 1;
        unsigned char irq_reserved_3 : 1;
        unsigned char irq_reserved_4 : 1;
        unsigned char irq_reserved_5 : 1;
        unsigned char irq_reserved_6 : 1;
        unsigned char irq_reserved_7 : 1;
    } reg;
} REG_IRQ_FLAG_5_UNION;
#endif
#define REG_IRQ_FLAG_5_irq_reserved_0_START (0)
#define REG_IRQ_FLAG_5_irq_reserved_0_END (0)
#define REG_IRQ_FLAG_5_irq_reserved_1_START (1)
#define REG_IRQ_FLAG_5_irq_reserved_1_END (1)
#define REG_IRQ_FLAG_5_irq_reserved_2_START (2)
#define REG_IRQ_FLAG_5_irq_reserved_2_END (2)
#define REG_IRQ_FLAG_5_irq_reserved_3_START (3)
#define REG_IRQ_FLAG_5_irq_reserved_3_END (3)
#define REG_IRQ_FLAG_5_irq_reserved_4_START (4)
#define REG_IRQ_FLAG_5_irq_reserved_4_END (4)
#define REG_IRQ_FLAG_5_irq_reserved_5_START (5)
#define REG_IRQ_FLAG_5_irq_reserved_5_END (5)
#define REG_IRQ_FLAG_5_irq_reserved_6_START (6)
#define REG_IRQ_FLAG_5_irq_reserved_6_END (6)
#define REG_IRQ_FLAG_5_irq_reserved_7_START (7)
#define REG_IRQ_FLAG_5_irq_reserved_7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_sc_vbus_vdrop_ovp : 1;
        unsigned char irq_fwd_psw_vdrop_min : 1;
        unsigned char irq_fwd_ovp_vdrop_min : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 1;
        unsigned char reserved_2 : 1;
        unsigned char reserved_3 : 1;
        unsigned char reserved_4 : 1;
    } reg;
} REG_IRQ_FLAG_6_UNION;
#endif
#define REG_IRQ_FLAG_6_irq_sc_vbus_vdrop_ovp_START (0)
#define REG_IRQ_FLAG_6_irq_sc_vbus_vdrop_ovp_END (0)
#define REG_IRQ_FLAG_6_irq_fwd_psw_vdrop_min_START (1)
#define REG_IRQ_FLAG_6_irq_fwd_psw_vdrop_min_END (1)
#define REG_IRQ_FLAG_6_irq_fwd_ovp_vdrop_min_START (2)
#define REG_IRQ_FLAG_6_irq_fwd_ovp_vdrop_min_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_sc_cfly1_scp : 1;
        unsigned char irq_sc_ibat_ocp : 1;
        unsigned char irq_fwd_vbat1_ovp : 1;
        unsigned char irq_rvs_vout_uvlo : 1;
        unsigned char irq_sc_vout_ovp : 1;
        unsigned char irq_sc_ibus_rcp : 1;
        unsigned char irq_sc_ibus_ucp : 1;
        unsigned char irq_sc_ibus_ocp : 1;
    } reg;
} REG_IRQ_FLAG_7_UNION;
#endif
#define REG_IRQ_FLAG_7_irq_sc_cfly1_scp_START (0)
#define REG_IRQ_FLAG_7_irq_sc_cfly1_scp_END (0)
#define REG_IRQ_FLAG_7_irq_sc_ibat_ocp_START (1)
#define REG_IRQ_FLAG_7_irq_sc_ibat_ocp_END (1)
#define REG_IRQ_FLAG_7_irq_fwd_vbat1_ovp_START (2)
#define REG_IRQ_FLAG_7_irq_fwd_vbat1_ovp_END (2)
#define REG_IRQ_FLAG_7_irq_rvs_vout_uvlo_START (3)
#define REG_IRQ_FLAG_7_irq_rvs_vout_uvlo_END (3)
#define REG_IRQ_FLAG_7_irq_sc_vout_ovp_START (4)
#define REG_IRQ_FLAG_7_irq_sc_vout_ovp_END (4)
#define REG_IRQ_FLAG_7_irq_sc_ibus_rcp_START (5)
#define REG_IRQ_FLAG_7_irq_sc_ibus_rcp_END (5)
#define REG_IRQ_FLAG_7_irq_sc_ibus_ucp_START (6)
#define REG_IRQ_FLAG_7_irq_sc_ibus_ucp_END (6)
#define REG_IRQ_FLAG_7_irq_sc_ibus_ocp_START (7)
#define REG_IRQ_FLAG_7_irq_sc_ibus_ocp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_sc2_dsw_q10_ocp_peak : 1;
        unsigned char irq_sc2_dsw_q5_ocp_peak : 1;
        unsigned char irq_sc2_dsw_q4_ocp_peak : 1;
        unsigned char irq_sc1_dsw_q10_ocp_peak : 1;
        unsigned char irq_sc1_dsw_q5_ocp_peak : 1;
        unsigned char irq_sc1_dsw_q4_ocp_peak : 1;
        unsigned char irq_sc_cfly3_scp : 1;
        unsigned char irq_sc_cfly2_scp : 1;
    } reg;
} REG_IRQ_FLAG_8_UNION;
#endif
#define REG_IRQ_FLAG_8_irq_sc2_dsw_q10_ocp_peak_START (0)
#define REG_IRQ_FLAG_8_irq_sc2_dsw_q10_ocp_peak_END (0)
#define REG_IRQ_FLAG_8_irq_sc2_dsw_q5_ocp_peak_START (1)
#define REG_IRQ_FLAG_8_irq_sc2_dsw_q5_ocp_peak_END (1)
#define REG_IRQ_FLAG_8_irq_sc2_dsw_q4_ocp_peak_START (2)
#define REG_IRQ_FLAG_8_irq_sc2_dsw_q4_ocp_peak_END (2)
#define REG_IRQ_FLAG_8_irq_sc1_dsw_q10_ocp_peak_START (3)
#define REG_IRQ_FLAG_8_irq_sc1_dsw_q10_ocp_peak_END (3)
#define REG_IRQ_FLAG_8_irq_sc1_dsw_q5_ocp_peak_START (4)
#define REG_IRQ_FLAG_8_irq_sc1_dsw_q5_ocp_peak_END (4)
#define REG_IRQ_FLAG_8_irq_sc1_dsw_q4_ocp_peak_START (5)
#define REG_IRQ_FLAG_8_irq_sc1_dsw_q4_ocp_peak_END (5)
#define REG_IRQ_FLAG_8_irq_sc_cfly3_scp_START (6)
#define REG_IRQ_FLAG_8_irq_sc_cfly3_scp_END (6)
#define REG_IRQ_FLAG_8_irq_sc_cfly2_scp_START (7)
#define REG_IRQ_FLAG_8_irq_sc_cfly2_scp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_sbu2_ovp : 1;
        unsigned char irq_sbu1_ovp : 1;
        unsigned char irq_cc_uv : 1;
        unsigned char irq_cc_ocp : 1;
        unsigned char irq_cc_ov : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 1;
        unsigned char reserved_2 : 1;
    } reg;
} REG_IRQ_FLAG_9_UNION;
#endif
#define REG_IRQ_FLAG_9_irq_sbu2_ovp_START (0)
#define REG_IRQ_FLAG_9_irq_sbu2_ovp_END (0)
#define REG_IRQ_FLAG_9_irq_sbu1_ovp_START (1)
#define REG_IRQ_FLAG_9_irq_sbu1_ovp_END (1)
#define REG_IRQ_FLAG_9_irq_cc_uv_START (2)
#define REG_IRQ_FLAG_9_irq_cc_uv_END (2)
#define REG_IRQ_FLAG_9_irq_cc_ocp_START (3)
#define REG_IRQ_FLAG_9_irq_cc_ocp_END (3)
#define REG_IRQ_FLAG_9_irq_cc_ov_START (4)
#define REG_IRQ_FLAG_9_irq_cc_ov_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_bc12_vbus_plugout : 1;
        unsigned char irq_bc12_auto_det : 1;
        unsigned char irq_bc12_dcp_ready : 1;
        unsigned char irq_bc12_sd_det : 1;
        unsigned char irq_bc12_pd_det : 1;
        unsigned char irq_bc12_dcd_det : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 1;
    } reg;
} REG_IRQ_FLAG_10_UNION;
#endif
#define REG_IRQ_FLAG_10_irq_bc12_vbus_plugout_START (0)
#define REG_IRQ_FLAG_10_irq_bc12_vbus_plugout_END (0)
#define REG_IRQ_FLAG_10_irq_bc12_auto_det_START (1)
#define REG_IRQ_FLAG_10_irq_bc12_auto_det_END (1)
#define REG_IRQ_FLAG_10_irq_bc12_dcp_ready_START (2)
#define REG_IRQ_FLAG_10_irq_bc12_dcp_ready_END (2)
#define REG_IRQ_FLAG_10_irq_bc12_sd_det_START (3)
#define REG_IRQ_FLAG_10_irq_bc12_sd_det_END (3)
#define REG_IRQ_FLAG_10_irq_bc12_pd_det_START (4)
#define REG_IRQ_FLAG_10_irq_bc12_pd_det_END (4)
#define REG_IRQ_FLAG_10_irq_bc12_dcd_det_START (5)
#define REG_IRQ_FLAG_10_irq_bc12_dcd_det_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_ufcs_plugout : 1;
        unsigned char irq_ufcs_dm_ovp : 1;
        unsigned char irq_ufcs_dp_ovp : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 1;
        unsigned char reserved_2 : 1;
        unsigned char reserved_3 : 1;
        unsigned char reserved_4 : 1;
    } reg;
} REG_IRQ_FLAG_11_UNION;
#endif
#define REG_IRQ_FLAG_11_irq_ufcs_plugout_START (0)
#define REG_IRQ_FLAG_11_irq_ufcs_plugout_END (0)
#define REG_IRQ_FLAG_11_irq_ufcs_dm_ovp_START (1)
#define REG_IRQ_FLAG_11_irq_ufcs_dm_ovp_END (1)
#define REG_IRQ_FLAG_11_irq_ufcs_dp_ovp_START (2)
#define REG_IRQ_FLAG_11_irq_ufcs_dp_ovp_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_flash_ivfm : 1;
        unsigned char irq_led3_open : 1;
        unsigned char irq_led3_scp : 1;
        unsigned char irq_led2_open : 1;
        unsigned char irq_led2_scp : 1;
        unsigned char irq_led1_open : 1;
        unsigned char irq_led1_scp : 1;
        unsigned char reserved : 1;
    } reg;
} REG_IRQ_FLAG_12_UNION;
#endif
#define REG_IRQ_FLAG_12_irq_flash_ivfm_START (0)
#define REG_IRQ_FLAG_12_irq_flash_ivfm_END (0)
#define REG_IRQ_FLAG_12_irq_led3_open_START (1)
#define REG_IRQ_FLAG_12_irq_led3_open_END (1)
#define REG_IRQ_FLAG_12_irq_led3_scp_START (2)
#define REG_IRQ_FLAG_12_irq_led3_scp_END (2)
#define REG_IRQ_FLAG_12_irq_led2_open_START (3)
#define REG_IRQ_FLAG_12_irq_led2_open_END (3)
#define REG_IRQ_FLAG_12_irq_led2_scp_START (4)
#define REG_IRQ_FLAG_12_irq_led2_scp_END (4)
#define REG_IRQ_FLAG_12_irq_led1_open_START (5)
#define REG_IRQ_FLAG_12_irq_led1_open_END (5)
#define REG_IRQ_FLAG_12_irq_led1_scp_START (6)
#define REG_IRQ_FLAG_12_irq_led1_scp_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_led3_timeout : 1;
        unsigned char irq_led2_timeout : 1;
        unsigned char irq_led1_timeout : 1;
        unsigned char reserved : 5;
    } reg;
} REG_IRQ_FLAG_13_UNION;
#endif
#define REG_IRQ_FLAG_13_irq_led3_timeout_START (0)
#define REG_IRQ_FLAG_13_irq_led3_timeout_END (0)
#define REG_IRQ_FLAG_13_irq_led2_timeout_START (1)
#define REG_IRQ_FLAG_13_irq_led2_timeout_END (1)
#define REG_IRQ_FLAG_13_irq_led1_timeout_START (2)
#define REG_IRQ_FLAG_13_irq_led1_timeout_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_group_fcp_mask : 1;
        unsigned char irq_group_flash_mask : 1;
        unsigned char irq_group_ufcs_mask : 1;
        unsigned char irq_group_bc12_mask : 1;
        unsigned char irq_group_pd_mask : 1;
        unsigned char irq_group_sc_mask : 1;
        unsigned char irq_group_chg_mask : 1;
        unsigned char irq_group_coul_mask : 1;
    } reg;
} REG_IRQ_MASK_UNION;
#endif
#define REG_IRQ_MASK_irq_group_fcp_mask_START (0)
#define REG_IRQ_MASK_irq_group_fcp_mask_END (0)
#define REG_IRQ_MASK_irq_group_flash_mask_START (1)
#define REG_IRQ_MASK_irq_group_flash_mask_END (1)
#define REG_IRQ_MASK_irq_group_ufcs_mask_START (2)
#define REG_IRQ_MASK_irq_group_ufcs_mask_END (2)
#define REG_IRQ_MASK_irq_group_bc12_mask_START (3)
#define REG_IRQ_MASK_irq_group_bc12_mask_END (3)
#define REG_IRQ_MASK_irq_group_pd_mask_START (4)
#define REG_IRQ_MASK_irq_group_pd_mask_END (4)
#define REG_IRQ_MASK_irq_group_sc_mask_START (5)
#define REG_IRQ_MASK_irq_group_sc_mask_END (5)
#define REG_IRQ_MASK_irq_group_chg_mask_START (6)
#define REG_IRQ_MASK_irq_group_chg_mask_END (6)
#define REG_IRQ_MASK_irq_group_coul_mask_START (7)
#define REG_IRQ_MASK_irq_group_coul_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} REG_IRQ_MASK_RSV_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_psw_vpsw_plugin_mask : 1;
        unsigned char irq_psw_vpsw_plugout_mask : 1;
        unsigned char irq_psw_vpsw_uvlo_mask : 1;
        unsigned char irq_ovp_vusb_ovp_mask : 1;
        unsigned char irq_ovp_pwron_mask : 1;
        unsigned char irq_ovp_vusb_plugin_mask : 1;
        unsigned char irq_ovp_vusb_plugout_mask : 1;
        unsigned char irq_ovp_vusb_uvlo_mask : 1;
    } reg;
} REG_IRQ_MASK_0_UNION;
#endif
#define REG_IRQ_MASK_0_irq_psw_vpsw_plugin_mask_START (0)
#define REG_IRQ_MASK_0_irq_psw_vpsw_plugin_mask_END (0)
#define REG_IRQ_MASK_0_irq_psw_vpsw_plugout_mask_START (1)
#define REG_IRQ_MASK_0_irq_psw_vpsw_plugout_mask_END (1)
#define REG_IRQ_MASK_0_irq_psw_vpsw_uvlo_mask_START (2)
#define REG_IRQ_MASK_0_irq_psw_vpsw_uvlo_mask_END (2)
#define REG_IRQ_MASK_0_irq_ovp_vusb_ovp_mask_START (3)
#define REG_IRQ_MASK_0_irq_ovp_vusb_ovp_mask_END (3)
#define REG_IRQ_MASK_0_irq_ovp_pwron_mask_START (4)
#define REG_IRQ_MASK_0_irq_ovp_pwron_mask_END (4)
#define REG_IRQ_MASK_0_irq_ovp_vusb_plugin_mask_START (5)
#define REG_IRQ_MASK_0_irq_ovp_vusb_plugin_mask_END (5)
#define REG_IRQ_MASK_0_irq_ovp_vusb_plugout_mask_START (6)
#define REG_IRQ_MASK_0_irq_ovp_vusb_plugout_mask_END (6)
#define REG_IRQ_MASK_0_irq_ovp_vusb_uvlo_mask_START (7)
#define REG_IRQ_MASK_0_irq_ovp_vusb_uvlo_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_otg_ocp_mask : 1;
        unsigned char irq_buck_ocp_mask : 1;
        unsigned char irq_otg_scp_mask : 1;
        unsigned char irq_otg_uvp_mask : 1;
        unsigned char irq_otg_ovp_mask : 1;
        unsigned char irq_regn_ocp_mask : 1;
        unsigned char irq_psw_vpsw_ovp_mask : 1;
        unsigned char irq_psw_pwron_mask : 1;
    } reg;
} REG_IRQ_MASK_1_UNION;
#endif
#define REG_IRQ_MASK_1_irq_otg_ocp_mask_START (0)
#define REG_IRQ_MASK_1_irq_otg_ocp_mask_END (0)
#define REG_IRQ_MASK_1_irq_buck_ocp_mask_START (1)
#define REG_IRQ_MASK_1_irq_buck_ocp_mask_END (1)
#define REG_IRQ_MASK_1_irq_otg_scp_mask_START (2)
#define REG_IRQ_MASK_1_irq_otg_scp_mask_END (2)
#define REG_IRQ_MASK_1_irq_otg_uvp_mask_START (3)
#define REG_IRQ_MASK_1_irq_otg_uvp_mask_END (3)
#define REG_IRQ_MASK_1_irq_otg_ovp_mask_START (4)
#define REG_IRQ_MASK_1_irq_otg_ovp_mask_END (4)
#define REG_IRQ_MASK_1_irq_regn_ocp_mask_START (5)
#define REG_IRQ_MASK_1_irq_regn_ocp_mask_END (5)
#define REG_IRQ_MASK_1_irq_psw_vpsw_ovp_mask_START (6)
#define REG_IRQ_MASK_1_irq_psw_vpsw_ovp_mask_END (6)
#define REG_IRQ_MASK_1_irq_psw_pwron_mask_START (7)
#define REG_IRQ_MASK_1_irq_psw_pwron_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_fast_charge_fault_mask : 1;
        unsigned char irq_pre_charge_fault_mask : 1;
        unsigned char irq_trickle_charge_fault_mask : 1;
        unsigned char irq_vbat_ovp_mask : 1;
        unsigned char irq_batfet_ocp_mask : 1;
        unsigned char irq_vsys_l_scp_mask : 1;
        unsigned char irq_vsys_h_ovp_mask : 1;
        unsigned char irq_vsys_h_scp_mask : 1;
    } reg;
} REG_IRQ_MASK_2_UNION;
#endif
#define REG_IRQ_MASK_2_irq_fast_charge_fault_mask_START (0)
#define REG_IRQ_MASK_2_irq_fast_charge_fault_mask_END (0)
#define REG_IRQ_MASK_2_irq_pre_charge_fault_mask_START (1)
#define REG_IRQ_MASK_2_irq_pre_charge_fault_mask_END (1)
#define REG_IRQ_MASK_2_irq_trickle_charge_fault_mask_START (2)
#define REG_IRQ_MASK_2_irq_trickle_charge_fault_mask_END (2)
#define REG_IRQ_MASK_2_irq_vbat_ovp_mask_START (3)
#define REG_IRQ_MASK_2_irq_vbat_ovp_mask_END (3)
#define REG_IRQ_MASK_2_irq_batfet_ocp_mask_START (4)
#define REG_IRQ_MASK_2_irq_batfet_ocp_mask_END (4)
#define REG_IRQ_MASK_2_irq_vsys_l_scp_mask_START (5)
#define REG_IRQ_MASK_2_irq_vsys_l_scp_mask_END (5)
#define REG_IRQ_MASK_2_irq_vsys_h_ovp_mask_START (6)
#define REG_IRQ_MASK_2_irq_vsys_h_ovp_mask_END (6)
#define REG_IRQ_MASK_2_irq_vsys_h_scp_mask_START (7)
#define REG_IRQ_MASK_2_irq_vsys_h_scp_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_reversbst_mask : 1;
        unsigned char irq_vbat_lv_mask : 1;
        unsigned char irq_chg_rechg_mask : 1;
        unsigned char irq_chg_eoc_mask : 1;
        unsigned char irq_tdie_otp_mask : 1;
        unsigned char irq_otmp_jreg_mask : 1;
        unsigned char irq_tbat_otp_mask : 1;
        unsigned char irq_wdt_tot_mask : 1;
    } reg;
} REG_IRQ_MASK_3_UNION;
#endif
#define REG_IRQ_MASK_3_irq_reversbst_mask_START (0)
#define REG_IRQ_MASK_3_irq_reversbst_mask_END (0)
#define REG_IRQ_MASK_3_irq_vbat_lv_mask_START (1)
#define REG_IRQ_MASK_3_irq_vbat_lv_mask_END (1)
#define REG_IRQ_MASK_3_irq_chg_rechg_mask_START (2)
#define REG_IRQ_MASK_3_irq_chg_rechg_mask_END (2)
#define REG_IRQ_MASK_3_irq_chg_eoc_mask_START (3)
#define REG_IRQ_MASK_3_irq_chg_eoc_mask_END (3)
#define REG_IRQ_MASK_3_irq_tdie_otp_mask_START (4)
#define REG_IRQ_MASK_3_irq_tdie_otp_mask_END (4)
#define REG_IRQ_MASK_3_irq_otmp_jreg_mask_START (5)
#define REG_IRQ_MASK_3_irq_otmp_jreg_mask_END (5)
#define REG_IRQ_MASK_3_irq_tbat_otp_mask_START (6)
#define REG_IRQ_MASK_3_irq_tbat_otp_mask_END (6)
#define REG_IRQ_MASK_3_irq_wdt_tot_mask_START (7)
#define REG_IRQ_MASK_3_irq_wdt_tot_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_ldo33_scp_mask : 1;
        unsigned char irq_ldo1p8_ana_scp_mask : 1;
        unsigned char irq_vpsw_sleep_mod_mask : 1;
        unsigned char irq_vusb_sleep_mod_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 1;
        unsigned char reserved_2 : 1;
        unsigned char reserved_3 : 1;
    } reg;
} REG_IRQ_MASK_4_UNION;
#endif
#define REG_IRQ_MASK_4_irq_ldo33_scp_mask_START (0)
#define REG_IRQ_MASK_4_irq_ldo33_scp_mask_END (0)
#define REG_IRQ_MASK_4_irq_ldo1p8_ana_scp_mask_START (1)
#define REG_IRQ_MASK_4_irq_ldo1p8_ana_scp_mask_END (1)
#define REG_IRQ_MASK_4_irq_vpsw_sleep_mod_mask_START (2)
#define REG_IRQ_MASK_4_irq_vpsw_sleep_mod_mask_END (2)
#define REG_IRQ_MASK_4_irq_vusb_sleep_mod_mask_START (3)
#define REG_IRQ_MASK_4_irq_vusb_sleep_mod_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_reserved_0_mask : 1;
        unsigned char irq_reserved_1_mask : 1;
        unsigned char irq_reserved_2_mask : 1;
        unsigned char irq_reserved_3_mask : 1;
        unsigned char irq_reserved_4_mask : 1;
        unsigned char irq_reserved_5_mask : 1;
        unsigned char irq_reserved_6_mask : 1;
        unsigned char irq_reserved_7_mask : 1;
    } reg;
} REG_IRQ_MASK_5_UNION;
#endif
#define REG_IRQ_MASK_5_irq_reserved_0_mask_START (0)
#define REG_IRQ_MASK_5_irq_reserved_0_mask_END (0)
#define REG_IRQ_MASK_5_irq_reserved_1_mask_START (1)
#define REG_IRQ_MASK_5_irq_reserved_1_mask_END (1)
#define REG_IRQ_MASK_5_irq_reserved_2_mask_START (2)
#define REG_IRQ_MASK_5_irq_reserved_2_mask_END (2)
#define REG_IRQ_MASK_5_irq_reserved_3_mask_START (3)
#define REG_IRQ_MASK_5_irq_reserved_3_mask_END (3)
#define REG_IRQ_MASK_5_irq_reserved_4_mask_START (4)
#define REG_IRQ_MASK_5_irq_reserved_4_mask_END (4)
#define REG_IRQ_MASK_5_irq_reserved_5_mask_START (5)
#define REG_IRQ_MASK_5_irq_reserved_5_mask_END (5)
#define REG_IRQ_MASK_5_irq_reserved_6_mask_START (6)
#define REG_IRQ_MASK_5_irq_reserved_6_mask_END (6)
#define REG_IRQ_MASK_5_irq_reserved_7_mask_START (7)
#define REG_IRQ_MASK_5_irq_reserved_7_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_sc_vbus_vdrop_ovp_mask : 1;
        unsigned char irq_fwd_psw_vdrop_min_mask : 1;
        unsigned char irq_fwd_ovp_vdrop_min_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 1;
        unsigned char reserved_2 : 1;
        unsigned char reserved_3 : 1;
        unsigned char reserved_4 : 1;
    } reg;
} REG_IRQ_MASK_6_UNION;
#endif
#define REG_IRQ_MASK_6_irq_sc_vbus_vdrop_ovp_mask_START (0)
#define REG_IRQ_MASK_6_irq_sc_vbus_vdrop_ovp_mask_END (0)
#define REG_IRQ_MASK_6_irq_fwd_psw_vdrop_min_mask_START (1)
#define REG_IRQ_MASK_6_irq_fwd_psw_vdrop_min_mask_END (1)
#define REG_IRQ_MASK_6_irq_fwd_ovp_vdrop_min_mask_START (2)
#define REG_IRQ_MASK_6_irq_fwd_ovp_vdrop_min_mask_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_sc_cfly1_scp_mask : 1;
        unsigned char irq_sc_ibat_ocp_mask : 1;
        unsigned char irq_fwd_vbat1_ovp_mask : 1;
        unsigned char irq_rvs_vout_uvlo_mask : 1;
        unsigned char irq_sc_vout_ovp_mask : 1;
        unsigned char irq_sc_ibus_rcp_mask : 1;
        unsigned char irq_sc_ibus_ucp_mask : 1;
        unsigned char irq_sc_ibus_ocp_mask : 1;
    } reg;
} REG_IRQ_MASK_7_UNION;
#endif
#define REG_IRQ_MASK_7_irq_sc_cfly1_scp_mask_START (0)
#define REG_IRQ_MASK_7_irq_sc_cfly1_scp_mask_END (0)
#define REG_IRQ_MASK_7_irq_sc_ibat_ocp_mask_START (1)
#define REG_IRQ_MASK_7_irq_sc_ibat_ocp_mask_END (1)
#define REG_IRQ_MASK_7_irq_fwd_vbat1_ovp_mask_START (2)
#define REG_IRQ_MASK_7_irq_fwd_vbat1_ovp_mask_END (2)
#define REG_IRQ_MASK_7_irq_rvs_vout_uvlo_mask_START (3)
#define REG_IRQ_MASK_7_irq_rvs_vout_uvlo_mask_END (3)
#define REG_IRQ_MASK_7_irq_sc_vout_ovp_mask_START (4)
#define REG_IRQ_MASK_7_irq_sc_vout_ovp_mask_END (4)
#define REG_IRQ_MASK_7_irq_sc_ibus_rcp_mask_START (5)
#define REG_IRQ_MASK_7_irq_sc_ibus_rcp_mask_END (5)
#define REG_IRQ_MASK_7_irq_sc_ibus_ucp_mask_START (6)
#define REG_IRQ_MASK_7_irq_sc_ibus_ucp_mask_END (6)
#define REG_IRQ_MASK_7_irq_sc_ibus_ocp_mask_START (7)
#define REG_IRQ_MASK_7_irq_sc_ibus_ocp_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_sc2_dsw_q10_ocp_peak_mask : 1;
        unsigned char irq_sc2_dsw_q5_ocp_peak_mask : 1;
        unsigned char irq_sc2_dsw_q4_ocp_peak_mask : 1;
        unsigned char irq_sc1_dsw_q10_ocp_peak_mask : 1;
        unsigned char irq_sc1_dsw_q5_ocp_peak_mask : 1;
        unsigned char irq_sc1_dsw_q4_ocp_peak_mask : 1;
        unsigned char irq_sc_cfly3_scp_mask : 1;
        unsigned char irq_sc_cfly2_scp_mask : 1;
    } reg;
} REG_IRQ_MASK_8_UNION;
#endif
#define REG_IRQ_MASK_8_irq_sc2_dsw_q10_ocp_peak_mask_START (0)
#define REG_IRQ_MASK_8_irq_sc2_dsw_q10_ocp_peak_mask_END (0)
#define REG_IRQ_MASK_8_irq_sc2_dsw_q5_ocp_peak_mask_START (1)
#define REG_IRQ_MASK_8_irq_sc2_dsw_q5_ocp_peak_mask_END (1)
#define REG_IRQ_MASK_8_irq_sc2_dsw_q4_ocp_peak_mask_START (2)
#define REG_IRQ_MASK_8_irq_sc2_dsw_q4_ocp_peak_mask_END (2)
#define REG_IRQ_MASK_8_irq_sc1_dsw_q10_ocp_peak_mask_START (3)
#define REG_IRQ_MASK_8_irq_sc1_dsw_q10_ocp_peak_mask_END (3)
#define REG_IRQ_MASK_8_irq_sc1_dsw_q5_ocp_peak_mask_START (4)
#define REG_IRQ_MASK_8_irq_sc1_dsw_q5_ocp_peak_mask_END (4)
#define REG_IRQ_MASK_8_irq_sc1_dsw_q4_ocp_peak_mask_START (5)
#define REG_IRQ_MASK_8_irq_sc1_dsw_q4_ocp_peak_mask_END (5)
#define REG_IRQ_MASK_8_irq_sc_cfly3_scp_mask_START (6)
#define REG_IRQ_MASK_8_irq_sc_cfly3_scp_mask_END (6)
#define REG_IRQ_MASK_8_irq_sc_cfly2_scp_mask_START (7)
#define REG_IRQ_MASK_8_irq_sc_cfly2_scp_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_sbu2_ovp_mask : 1;
        unsigned char irq_sbu1_ovp_mask : 1;
        unsigned char irq_cc_uv_mask : 1;
        unsigned char irq_cc_ocp_mask : 1;
        unsigned char irq_cc_ov_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 1;
        unsigned char reserved_2 : 1;
    } reg;
} REG_IRQ_MASK_9_UNION;
#endif
#define REG_IRQ_MASK_9_irq_sbu2_ovp_mask_START (0)
#define REG_IRQ_MASK_9_irq_sbu2_ovp_mask_END (0)
#define REG_IRQ_MASK_9_irq_sbu1_ovp_mask_START (1)
#define REG_IRQ_MASK_9_irq_sbu1_ovp_mask_END (1)
#define REG_IRQ_MASK_9_irq_cc_uv_mask_START (2)
#define REG_IRQ_MASK_9_irq_cc_uv_mask_END (2)
#define REG_IRQ_MASK_9_irq_cc_ocp_mask_START (3)
#define REG_IRQ_MASK_9_irq_cc_ocp_mask_END (3)
#define REG_IRQ_MASK_9_irq_cc_ov_mask_START (4)
#define REG_IRQ_MASK_9_irq_cc_ov_mask_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_bc12_vbus_plugout_mask : 1;
        unsigned char irq_bc12_auto_det_mask : 1;
        unsigned char irq_bc12_dcp_ready_mask : 1;
        unsigned char irq_bc12_sd_det_mask : 1;
        unsigned char irq_bc12_pd_det_mask : 1;
        unsigned char irq_bc12_dcd_det_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 1;
    } reg;
} REG_IRQ_MASK_10_UNION;
#endif
#define REG_IRQ_MASK_10_irq_bc12_vbus_plugout_mask_START (0)
#define REG_IRQ_MASK_10_irq_bc12_vbus_plugout_mask_END (0)
#define REG_IRQ_MASK_10_irq_bc12_auto_det_mask_START (1)
#define REG_IRQ_MASK_10_irq_bc12_auto_det_mask_END (1)
#define REG_IRQ_MASK_10_irq_bc12_dcp_ready_mask_START (2)
#define REG_IRQ_MASK_10_irq_bc12_dcp_ready_mask_END (2)
#define REG_IRQ_MASK_10_irq_bc12_sd_det_mask_START (3)
#define REG_IRQ_MASK_10_irq_bc12_sd_det_mask_END (3)
#define REG_IRQ_MASK_10_irq_bc12_pd_det_mask_START (4)
#define REG_IRQ_MASK_10_irq_bc12_pd_det_mask_END (4)
#define REG_IRQ_MASK_10_irq_bc12_dcd_det_mask_START (5)
#define REG_IRQ_MASK_10_irq_bc12_dcd_det_mask_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_ufcs_plugout_mask : 1;
        unsigned char irq_ufcs_dm_ovp_mask : 1;
        unsigned char irq_ufcs_dp_ovp_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 1;
        unsigned char reserved_2 : 1;
        unsigned char reserved_3 : 1;
        unsigned char reserved_4 : 1;
    } reg;
} REG_IRQ_MASK_11_UNION;
#endif
#define REG_IRQ_MASK_11_irq_ufcs_plugout_mask_START (0)
#define REG_IRQ_MASK_11_irq_ufcs_plugout_mask_END (0)
#define REG_IRQ_MASK_11_irq_ufcs_dm_ovp_mask_START (1)
#define REG_IRQ_MASK_11_irq_ufcs_dm_ovp_mask_END (1)
#define REG_IRQ_MASK_11_irq_ufcs_dp_ovp_mask_START (2)
#define REG_IRQ_MASK_11_irq_ufcs_dp_ovp_mask_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_flash_ivfm_mask : 1;
        unsigned char irq_led3_open_mask : 1;
        unsigned char irq_led3_scp_mask : 1;
        unsigned char irq_led2_open_mask : 1;
        unsigned char irq_led2_scp_mask : 1;
        unsigned char irq_led1_open_mask : 1;
        unsigned char irq_led1_scp_mask : 1;
        unsigned char reserved : 1;
    } reg;
} REG_IRQ_MASK_12_UNION;
#endif
#define REG_IRQ_MASK_12_irq_flash_ivfm_mask_START (0)
#define REG_IRQ_MASK_12_irq_flash_ivfm_mask_END (0)
#define REG_IRQ_MASK_12_irq_led3_open_mask_START (1)
#define REG_IRQ_MASK_12_irq_led3_open_mask_END (1)
#define REG_IRQ_MASK_12_irq_led3_scp_mask_START (2)
#define REG_IRQ_MASK_12_irq_led3_scp_mask_END (2)
#define REG_IRQ_MASK_12_irq_led2_open_mask_START (3)
#define REG_IRQ_MASK_12_irq_led2_open_mask_END (3)
#define REG_IRQ_MASK_12_irq_led2_scp_mask_START (4)
#define REG_IRQ_MASK_12_irq_led2_scp_mask_END (4)
#define REG_IRQ_MASK_12_irq_led1_open_mask_START (5)
#define REG_IRQ_MASK_12_irq_led1_open_mask_END (5)
#define REG_IRQ_MASK_12_irq_led1_scp_mask_START (6)
#define REG_IRQ_MASK_12_irq_led1_scp_mask_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_led3_timeout_mask : 1;
        unsigned char irq_led2_timeout_mask : 1;
        unsigned char irq_led1_timeout_mask : 1;
        unsigned char reserved : 5;
    } reg;
} REG_IRQ_MASK_13_UNION;
#endif
#define REG_IRQ_MASK_13_irq_led3_timeout_mask_START (0)
#define REG_IRQ_MASK_13_irq_led3_timeout_mask_END (0)
#define REG_IRQ_MASK_13_irq_led2_timeout_mask_START (1)
#define REG_IRQ_MASK_13_irq_led2_timeout_mask_END (1)
#define REG_IRQ_MASK_13_irq_led1_timeout_mask_START (2)
#define REG_IRQ_MASK_13_irq_led1_timeout_mask_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} REG_IRQ_STATUS_RSV_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_irq_psw_vpsw_plugin : 1;
        unsigned char st_irq_psw_vpsw_plugout : 1;
        unsigned char st_irq_psw_vpsw_uvlo : 1;
        unsigned char st_irq_ovp_vusb_ovp : 1;
        unsigned char st_irq_ovp_pwron : 1;
        unsigned char st_irq_ovp_vusb_plugin : 1;
        unsigned char st_irq_ovp_vusb_plugout : 1;
        unsigned char st_irq_ovp_vusb_uvlo : 1;
    } reg;
} REG_IRQ_STATUS_0_UNION;
#endif
#define REG_IRQ_STATUS_0_st_irq_psw_vpsw_plugin_START (0)
#define REG_IRQ_STATUS_0_st_irq_psw_vpsw_plugin_END (0)
#define REG_IRQ_STATUS_0_st_irq_psw_vpsw_plugout_START (1)
#define REG_IRQ_STATUS_0_st_irq_psw_vpsw_plugout_END (1)
#define REG_IRQ_STATUS_0_st_irq_psw_vpsw_uvlo_START (2)
#define REG_IRQ_STATUS_0_st_irq_psw_vpsw_uvlo_END (2)
#define REG_IRQ_STATUS_0_st_irq_ovp_vusb_ovp_START (3)
#define REG_IRQ_STATUS_0_st_irq_ovp_vusb_ovp_END (3)
#define REG_IRQ_STATUS_0_st_irq_ovp_pwron_START (4)
#define REG_IRQ_STATUS_0_st_irq_ovp_pwron_END (4)
#define REG_IRQ_STATUS_0_st_irq_ovp_vusb_plugin_START (5)
#define REG_IRQ_STATUS_0_st_irq_ovp_vusb_plugin_END (5)
#define REG_IRQ_STATUS_0_st_irq_ovp_vusb_plugout_START (6)
#define REG_IRQ_STATUS_0_st_irq_ovp_vusb_plugout_END (6)
#define REG_IRQ_STATUS_0_st_irq_ovp_vusb_uvlo_START (7)
#define REG_IRQ_STATUS_0_st_irq_ovp_vusb_uvlo_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_irq_otg_ocp : 1;
        unsigned char st_irq_buck_ocp : 1;
        unsigned char st_irq_otg_scp : 1;
        unsigned char st_irq_otg_uvp : 1;
        unsigned char st_irq_otg_ovp : 1;
        unsigned char st_irq_regn_ocp : 1;
        unsigned char st_irq_psw_vpsw_ovp : 1;
        unsigned char st_irq_psw_pwron : 1;
    } reg;
} REG_IRQ_STATUS_1_UNION;
#endif
#define REG_IRQ_STATUS_1_st_irq_otg_ocp_START (0)
#define REG_IRQ_STATUS_1_st_irq_otg_ocp_END (0)
#define REG_IRQ_STATUS_1_st_irq_buck_ocp_START (1)
#define REG_IRQ_STATUS_1_st_irq_buck_ocp_END (1)
#define REG_IRQ_STATUS_1_st_irq_otg_scp_START (2)
#define REG_IRQ_STATUS_1_st_irq_otg_scp_END (2)
#define REG_IRQ_STATUS_1_st_irq_otg_uvp_START (3)
#define REG_IRQ_STATUS_1_st_irq_otg_uvp_END (3)
#define REG_IRQ_STATUS_1_st_irq_otg_ovp_START (4)
#define REG_IRQ_STATUS_1_st_irq_otg_ovp_END (4)
#define REG_IRQ_STATUS_1_st_irq_regn_ocp_START (5)
#define REG_IRQ_STATUS_1_st_irq_regn_ocp_END (5)
#define REG_IRQ_STATUS_1_st_irq_psw_vpsw_ovp_START (6)
#define REG_IRQ_STATUS_1_st_irq_psw_vpsw_ovp_END (6)
#define REG_IRQ_STATUS_1_st_irq_psw_pwron_START (7)
#define REG_IRQ_STATUS_1_st_irq_psw_pwron_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_irq_fast_charge_fault : 1;
        unsigned char st_irq_pre_charge_fault : 1;
        unsigned char st_irq_trickle_charge_fault : 1;
        unsigned char st_irq_vbat_ovp : 1;
        unsigned char st_irq_batfet_ocp : 1;
        unsigned char st_irq_vsys_l_scp : 1;
        unsigned char st_irq_vsys_h_ovp : 1;
        unsigned char st_irq_vsys_h_scp : 1;
    } reg;
} REG_IRQ_STATUS_2_UNION;
#endif
#define REG_IRQ_STATUS_2_st_irq_fast_charge_fault_START (0)
#define REG_IRQ_STATUS_2_st_irq_fast_charge_fault_END (0)
#define REG_IRQ_STATUS_2_st_irq_pre_charge_fault_START (1)
#define REG_IRQ_STATUS_2_st_irq_pre_charge_fault_END (1)
#define REG_IRQ_STATUS_2_st_irq_trickle_charge_fault_START (2)
#define REG_IRQ_STATUS_2_st_irq_trickle_charge_fault_END (2)
#define REG_IRQ_STATUS_2_st_irq_vbat_ovp_START (3)
#define REG_IRQ_STATUS_2_st_irq_vbat_ovp_END (3)
#define REG_IRQ_STATUS_2_st_irq_batfet_ocp_START (4)
#define REG_IRQ_STATUS_2_st_irq_batfet_ocp_END (4)
#define REG_IRQ_STATUS_2_st_irq_vsys_l_scp_START (5)
#define REG_IRQ_STATUS_2_st_irq_vsys_l_scp_END (5)
#define REG_IRQ_STATUS_2_st_irq_vsys_h_ovp_START (6)
#define REG_IRQ_STATUS_2_st_irq_vsys_h_ovp_END (6)
#define REG_IRQ_STATUS_2_st_irq_vsys_h_scp_START (7)
#define REG_IRQ_STATUS_2_st_irq_vsys_h_scp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_irq_reversbst : 1;
        unsigned char st_irq_vbat_lv : 1;
        unsigned char st_irq_chg_rechg : 1;
        unsigned char st_irq_chg_eoc : 1;
        unsigned char st_irq_tdie_otp : 1;
        unsigned char st_irq_otmp_jreg : 1;
        unsigned char st_irq_tbat_otp : 1;
        unsigned char st_irq_wdt_tot : 1;
    } reg;
} REG_IRQ_STATUS_3_UNION;
#endif
#define REG_IRQ_STATUS_3_st_irq_reversbst_START (0)
#define REG_IRQ_STATUS_3_st_irq_reversbst_END (0)
#define REG_IRQ_STATUS_3_st_irq_vbat_lv_START (1)
#define REG_IRQ_STATUS_3_st_irq_vbat_lv_END (1)
#define REG_IRQ_STATUS_3_st_irq_chg_rechg_START (2)
#define REG_IRQ_STATUS_3_st_irq_chg_rechg_END (2)
#define REG_IRQ_STATUS_3_st_irq_chg_eoc_START (3)
#define REG_IRQ_STATUS_3_st_irq_chg_eoc_END (3)
#define REG_IRQ_STATUS_3_st_irq_tdie_otp_START (4)
#define REG_IRQ_STATUS_3_st_irq_tdie_otp_END (4)
#define REG_IRQ_STATUS_3_st_irq_otmp_jreg_START (5)
#define REG_IRQ_STATUS_3_st_irq_otmp_jreg_END (5)
#define REG_IRQ_STATUS_3_st_irq_tbat_otp_START (6)
#define REG_IRQ_STATUS_3_st_irq_tbat_otp_END (6)
#define REG_IRQ_STATUS_3_st_irq_wdt_tot_START (7)
#define REG_IRQ_STATUS_3_st_irq_wdt_tot_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_irq_ldo33_scp : 1;
        unsigned char st_irq_ldo1p8_ana_scp : 1;
        unsigned char st_irq_vpsw_sleep_mod : 1;
        unsigned char st_irq_vusb_sleep_mod : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 1;
        unsigned char reserved_2 : 1;
        unsigned char reserved_3 : 1;
    } reg;
} REG_IRQ_STATUS_4_UNION;
#endif
#define REG_IRQ_STATUS_4_st_irq_ldo33_scp_START (0)
#define REG_IRQ_STATUS_4_st_irq_ldo33_scp_END (0)
#define REG_IRQ_STATUS_4_st_irq_ldo1p8_ana_scp_START (1)
#define REG_IRQ_STATUS_4_st_irq_ldo1p8_ana_scp_END (1)
#define REG_IRQ_STATUS_4_st_irq_vpsw_sleep_mod_START (2)
#define REG_IRQ_STATUS_4_st_irq_vpsw_sleep_mod_END (2)
#define REG_IRQ_STATUS_4_st_irq_vusb_sleep_mod_START (3)
#define REG_IRQ_STATUS_4_st_irq_vusb_sleep_mod_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_irq_reserved_0 : 1;
        unsigned char st_irq_reserved_1 : 1;
        unsigned char st_irq_reserved_2 : 1;
        unsigned char st_irq_reserved_3 : 1;
        unsigned char st_irq_reserved_4 : 1;
        unsigned char st_irq_reserved_5 : 1;
        unsigned char st_irq_reserved_6 : 1;
        unsigned char st_irq_reserved_7 : 1;
    } reg;
} REG_IRQ_STATUS_5_UNION;
#endif
#define REG_IRQ_STATUS_5_st_irq_reserved_0_START (0)
#define REG_IRQ_STATUS_5_st_irq_reserved_0_END (0)
#define REG_IRQ_STATUS_5_st_irq_reserved_1_START (1)
#define REG_IRQ_STATUS_5_st_irq_reserved_1_END (1)
#define REG_IRQ_STATUS_5_st_irq_reserved_2_START (2)
#define REG_IRQ_STATUS_5_st_irq_reserved_2_END (2)
#define REG_IRQ_STATUS_5_st_irq_reserved_3_START (3)
#define REG_IRQ_STATUS_5_st_irq_reserved_3_END (3)
#define REG_IRQ_STATUS_5_st_irq_reserved_4_START (4)
#define REG_IRQ_STATUS_5_st_irq_reserved_4_END (4)
#define REG_IRQ_STATUS_5_st_irq_reserved_5_START (5)
#define REG_IRQ_STATUS_5_st_irq_reserved_5_END (5)
#define REG_IRQ_STATUS_5_st_irq_reserved_6_START (6)
#define REG_IRQ_STATUS_5_st_irq_reserved_6_END (6)
#define REG_IRQ_STATUS_5_st_irq_reserved_7_START (7)
#define REG_IRQ_STATUS_5_st_irq_reserved_7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_irq_sc_vbus_vdrop_ovp : 1;
        unsigned char st_irq_fwd_psw_vdrop_min : 1;
        unsigned char st_irq_fwd_ovp_vdrop_min : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 1;
        unsigned char reserved_2 : 1;
        unsigned char reserved_3 : 1;
        unsigned char reserved_4 : 1;
    } reg;
} REG_IRQ_STATUS_6_UNION;
#endif
#define REG_IRQ_STATUS_6_st_irq_sc_vbus_vdrop_ovp_START (0)
#define REG_IRQ_STATUS_6_st_irq_sc_vbus_vdrop_ovp_END (0)
#define REG_IRQ_STATUS_6_st_irq_fwd_psw_vdrop_min_START (1)
#define REG_IRQ_STATUS_6_st_irq_fwd_psw_vdrop_min_END (1)
#define REG_IRQ_STATUS_6_st_irq_fwd_ovp_vdrop_min_START (2)
#define REG_IRQ_STATUS_6_st_irq_fwd_ovp_vdrop_min_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_irq_sc_cfly1_scp : 1;
        unsigned char st_irq_sc_ibat_ocp : 1;
        unsigned char st_irq_fwd_vbat1_ovp : 1;
        unsigned char st_irq_rvs_vout_uvlo : 1;
        unsigned char st_irq_sc_vout_ovp : 1;
        unsigned char st_irq_sc_ibus_rcp : 1;
        unsigned char st_irq_sc_ibus_ucp : 1;
        unsigned char st_irq_sc_ibus_ocp : 1;
    } reg;
} REG_IRQ_STATUS_7_UNION;
#endif
#define REG_IRQ_STATUS_7_st_irq_sc_cfly1_scp_START (0)
#define REG_IRQ_STATUS_7_st_irq_sc_cfly1_scp_END (0)
#define REG_IRQ_STATUS_7_st_irq_sc_ibat_ocp_START (1)
#define REG_IRQ_STATUS_7_st_irq_sc_ibat_ocp_END (1)
#define REG_IRQ_STATUS_7_st_irq_fwd_vbat1_ovp_START (2)
#define REG_IRQ_STATUS_7_st_irq_fwd_vbat1_ovp_END (2)
#define REG_IRQ_STATUS_7_st_irq_rvs_vout_uvlo_START (3)
#define REG_IRQ_STATUS_7_st_irq_rvs_vout_uvlo_END (3)
#define REG_IRQ_STATUS_7_st_irq_sc_vout_ovp_START (4)
#define REG_IRQ_STATUS_7_st_irq_sc_vout_ovp_END (4)
#define REG_IRQ_STATUS_7_st_irq_sc_ibus_rcp_START (5)
#define REG_IRQ_STATUS_7_st_irq_sc_ibus_rcp_END (5)
#define REG_IRQ_STATUS_7_st_irq_sc_ibus_ucp_START (6)
#define REG_IRQ_STATUS_7_st_irq_sc_ibus_ucp_END (6)
#define REG_IRQ_STATUS_7_st_irq_sc_ibus_ocp_START (7)
#define REG_IRQ_STATUS_7_st_irq_sc_ibus_ocp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_irq_sc2_dsw_q10_ocp_peak : 1;
        unsigned char st_irq_sc2_dsw_q5_ocp_peak : 1;
        unsigned char st_irq_sc2_dsw_q4_ocp_peak : 1;
        unsigned char st_irq_sc1_dsw_q10_ocp_peak : 1;
        unsigned char st_irq_sc1_dsw_q5_ocp_peak : 1;
        unsigned char st_irq_sc1_dsw_q4_ocp_peak : 1;
        unsigned char st_irq_sc_cfly3_scp : 1;
        unsigned char st_irq_sc_cfly2_scp : 1;
    } reg;
} REG_IRQ_STATUS_8_UNION;
#endif
#define REG_IRQ_STATUS_8_st_irq_sc2_dsw_q10_ocp_peak_START (0)
#define REG_IRQ_STATUS_8_st_irq_sc2_dsw_q10_ocp_peak_END (0)
#define REG_IRQ_STATUS_8_st_irq_sc2_dsw_q5_ocp_peak_START (1)
#define REG_IRQ_STATUS_8_st_irq_sc2_dsw_q5_ocp_peak_END (1)
#define REG_IRQ_STATUS_8_st_irq_sc2_dsw_q4_ocp_peak_START (2)
#define REG_IRQ_STATUS_8_st_irq_sc2_dsw_q4_ocp_peak_END (2)
#define REG_IRQ_STATUS_8_st_irq_sc1_dsw_q10_ocp_peak_START (3)
#define REG_IRQ_STATUS_8_st_irq_sc1_dsw_q10_ocp_peak_END (3)
#define REG_IRQ_STATUS_8_st_irq_sc1_dsw_q5_ocp_peak_START (4)
#define REG_IRQ_STATUS_8_st_irq_sc1_dsw_q5_ocp_peak_END (4)
#define REG_IRQ_STATUS_8_st_irq_sc1_dsw_q4_ocp_peak_START (5)
#define REG_IRQ_STATUS_8_st_irq_sc1_dsw_q4_ocp_peak_END (5)
#define REG_IRQ_STATUS_8_st_irq_sc_cfly3_scp_START (6)
#define REG_IRQ_STATUS_8_st_irq_sc_cfly3_scp_END (6)
#define REG_IRQ_STATUS_8_st_irq_sc_cfly2_scp_START (7)
#define REG_IRQ_STATUS_8_st_irq_sc_cfly2_scp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_irq_sbu2_ovp : 1;
        unsigned char st_irq_sbu1_ovp : 1;
        unsigned char st_irq_cc_uv : 1;
        unsigned char st_irq_cc_ocp : 1;
        unsigned char st_irq_cc_ov : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 1;
        unsigned char reserved_2 : 1;
    } reg;
} REG_IRQ_STATUS_9_UNION;
#endif
#define REG_IRQ_STATUS_9_st_irq_sbu2_ovp_START (0)
#define REG_IRQ_STATUS_9_st_irq_sbu2_ovp_END (0)
#define REG_IRQ_STATUS_9_st_irq_sbu1_ovp_START (1)
#define REG_IRQ_STATUS_9_st_irq_sbu1_ovp_END (1)
#define REG_IRQ_STATUS_9_st_irq_cc_uv_START (2)
#define REG_IRQ_STATUS_9_st_irq_cc_uv_END (2)
#define REG_IRQ_STATUS_9_st_irq_cc_ocp_START (3)
#define REG_IRQ_STATUS_9_st_irq_cc_ocp_END (3)
#define REG_IRQ_STATUS_9_st_irq_cc_ov_START (4)
#define REG_IRQ_STATUS_9_st_irq_cc_ov_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_irq_bc12_vbus_plugout : 1;
        unsigned char st_irq_bc12_auto_det : 1;
        unsigned char st_irq_bc12_dcp_ready : 1;
        unsigned char st_irq_bc12_sd_det : 1;
        unsigned char st_irq_bc12_pd_det : 1;
        unsigned char st_irq_bc12_dcd_det : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 1;
    } reg;
} REG_IRQ_STATUS_10_UNION;
#endif
#define REG_IRQ_STATUS_10_st_irq_bc12_vbus_plugout_START (0)
#define REG_IRQ_STATUS_10_st_irq_bc12_vbus_plugout_END (0)
#define REG_IRQ_STATUS_10_st_irq_bc12_auto_det_START (1)
#define REG_IRQ_STATUS_10_st_irq_bc12_auto_det_END (1)
#define REG_IRQ_STATUS_10_st_irq_bc12_dcp_ready_START (2)
#define REG_IRQ_STATUS_10_st_irq_bc12_dcp_ready_END (2)
#define REG_IRQ_STATUS_10_st_irq_bc12_sd_det_START (3)
#define REG_IRQ_STATUS_10_st_irq_bc12_sd_det_END (3)
#define REG_IRQ_STATUS_10_st_irq_bc12_pd_det_START (4)
#define REG_IRQ_STATUS_10_st_irq_bc12_pd_det_END (4)
#define REG_IRQ_STATUS_10_st_irq_bc12_dcd_det_START (5)
#define REG_IRQ_STATUS_10_st_irq_bc12_dcd_det_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_irq_ufcs_plugout : 1;
        unsigned char st_irq_ufcs_dm_ovp : 1;
        unsigned char st_irq_ufcs_dp_ovp : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 1;
        unsigned char reserved_2 : 1;
        unsigned char reserved_3 : 1;
        unsigned char reserved_4 : 1;
    } reg;
} REG_IRQ_STATUS_11_UNION;
#endif
#define REG_IRQ_STATUS_11_st_irq_ufcs_plugout_START (0)
#define REG_IRQ_STATUS_11_st_irq_ufcs_plugout_END (0)
#define REG_IRQ_STATUS_11_st_irq_ufcs_dm_ovp_START (1)
#define REG_IRQ_STATUS_11_st_irq_ufcs_dm_ovp_END (1)
#define REG_IRQ_STATUS_11_st_irq_ufcs_dp_ovp_START (2)
#define REG_IRQ_STATUS_11_st_irq_ufcs_dp_ovp_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_irq_flash_ivfm : 1;
        unsigned char st_irq_led3_open : 1;
        unsigned char st_irq_led3_scp : 1;
        unsigned char st_irq_led2_open : 1;
        unsigned char st_irq_led2_scp : 1;
        unsigned char st_irq_led1_open : 1;
        unsigned char st_irq_led1_scp : 1;
        unsigned char reserved : 1;
    } reg;
} REG_IRQ_STATUS_12_UNION;
#endif
#define REG_IRQ_STATUS_12_st_irq_flash_ivfm_START (0)
#define REG_IRQ_STATUS_12_st_irq_flash_ivfm_END (0)
#define REG_IRQ_STATUS_12_st_irq_led3_open_START (1)
#define REG_IRQ_STATUS_12_st_irq_led3_open_END (1)
#define REG_IRQ_STATUS_12_st_irq_led3_scp_START (2)
#define REG_IRQ_STATUS_12_st_irq_led3_scp_END (2)
#define REG_IRQ_STATUS_12_st_irq_led2_open_START (3)
#define REG_IRQ_STATUS_12_st_irq_led2_open_END (3)
#define REG_IRQ_STATUS_12_st_irq_led2_scp_START (4)
#define REG_IRQ_STATUS_12_st_irq_led2_scp_END (4)
#define REG_IRQ_STATUS_12_st_irq_led1_open_START (5)
#define REG_IRQ_STATUS_12_st_irq_led1_open_END (5)
#define REG_IRQ_STATUS_12_st_irq_led1_scp_START (6)
#define REG_IRQ_STATUS_12_st_irq_led1_scp_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_irq_led3_timeout : 1;
        unsigned char st_irq_led2_timeout : 1;
        unsigned char st_irq_led1_timeout : 1;
        unsigned char reserved : 5;
    } reg;
} REG_IRQ_STATUS_13_UNION;
#endif
#define REG_IRQ_STATUS_13_st_irq_led3_timeout_START (0)
#define REG_IRQ_STATUS_13_st_irq_led3_timeout_END (0)
#define REG_IRQ_STATUS_13_st_irq_led2_timeout_START (1)
#define REG_IRQ_STATUS_13_st_irq_led2_timeout_END (1)
#define REG_IRQ_STATUS_13_st_irq_led1_timeout_START (2)
#define REG_IRQ_STATUS_13_st_irq_led1_timeout_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_fake_irq : 8;
    } reg;
} REG_FAKE_IRQ_UNION;
#endif
#define REG_FAKE_IRQ_sc_fake_irq_START (0)
#define REG_FAKE_IRQ_sc_fake_irq_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_irq_sel : 8;
    } reg;
} REG_IRQ_SEL_UNION;
#endif
#define REG_IRQ_SEL_sc_irq_sel_START (0)
#define REG_IRQ_SEL_sc_irq_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char batfet_h_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} REG_CHARGER_BATFET_H_CTRL_UNION;
#endif
#define REG_CHARGER_BATFET_H_CTRL_batfet_h_ctrl_START (0)
#define REG_CHARGER_BATFET_H_CTRL_batfet_h_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char batfet_l_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} REG_CHARGER_BATFET_L_CTRL_UNION;
#endif
#define REG_CHARGER_BATFET_L_CTRL_batfet_l_ctrl_START (0)
#define REG_CHARGER_BATFET_L_CTRL_batfet_l_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ship_mode_enb : 1;
        unsigned char reserved : 7;
    } reg;
} REG_SHIP_MODE_ENB_UNION;
#endif
#define REG_SHIP_MODE_ENB_ship_mode_enb_START (0)
#define REG_SHIP_MODE_ENB_ship_mode_enb_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char auto_ship_mode : 1;
        unsigned char reserved : 7;
    } reg;
} REG_AUTO_SHIP_MODE_UNION;
#endif
#define REG_AUTO_SHIP_MODE_auto_ship_mode_START (0)
#define REG_AUTO_SHIP_MODE_auto_ship_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char vbat_lv : 1;
        unsigned char reserved : 7;
    } reg;
} REG_VBAT_LV_REG_UNION;
#endif
#define REG_VBAT_LV_REG_vbat_lv_START (0)
#define REG_VBAT_LV_REG_vbat_lv_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_bat_res_mode : 1;
        unsigned char reserved : 7;
    } reg;
} REG_BAT_RES_MODE_UNION;
#endif
#define REG_BAT_RES_MODE_sc_bat_res_mode_START (0)
#define REG_BAT_RES_MODE_sc_bat_res_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_pmos_en : 1;
        unsigned char reserved_0 : 3;
        unsigned char sc_chg_lp : 1;
        unsigned char reserved_1 : 3;
    } reg;
} REG_VDM_CFG_REG_0_UNION;
#endif
#define REG_VDM_CFG_REG_0_sc_pmos_en_START (0)
#define REG_VDM_CFG_REG_0_sc_pmos_en_END (0)
#define REG_VDM_CFG_REG_0_sc_chg_lp_START (4)
#define REG_VDM_CFG_REG_0_sc_chg_lp_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 4;
        unsigned char sc_boot_en : 1;
        unsigned char reserved_1 : 3;
    } reg;
} REG_VDM_CFG_REG_1_UNION;
#endif
#define REG_VDM_CFG_REG_1_sc_boot_en_START (4)
#define REG_VDM_CFG_REG_1_sc_boot_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_regn_en : 1;
        unsigned char reserved_0 : 3;
        unsigned char sc_vusb_off_mask : 1;
        unsigned char reserved_1 : 3;
    } reg;
} REG_VDM_CFG_REG_2_UNION;
#endif
#define REG_VDM_CFG_REG_2_sc_regn_en_START (0)
#define REG_VDM_CFG_REG_2_sc_regn_en_END (0)
#define REG_VDM_CFG_REG_2_sc_vusb_off_mask_START (4)
#define REG_VDM_CFG_REG_2_sc_vusb_off_mask_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_jig_sw : 1;
        unsigned char reserved : 7;
    } reg;
} REG_VDM_CFG_REG_3_UNION;
#endif
#define REG_VDM_CFG_REG_3_sc_jig_sw_START (0)
#define REG_VDM_CFG_REG_3_sc_jig_sw_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_uart_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_VDM_CFG_REG_4_UNION;
#endif
#define REG_VDM_CFG_REG_4_sc_uart_en_START (0)
#define REG_VDM_CFG_REG_4_sc_uart_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_jtag_sbu_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_VDM_CFG_REG_5_UNION;
#endif
#define REG_VDM_CFG_REG_5_sc_jtag_sbu_en_START (0)
#define REG_VDM_CFG_REG_5_sc_jtag_sbu_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_vdm_rsv_0 : 1;
        unsigned char pd_vdm_rsv_1 : 1;
        unsigned char pd_vdm_rsv_2 : 1;
        unsigned char pd_vdm_rsv_3 : 1;
        unsigned char pd_vdm_rsv_4 : 1;
        unsigned char pd_vdm_rsv_5 : 1;
        unsigned char pd_vdm_rsv_6 : 1;
        unsigned char pd_vdm_rsv_7 : 1;
    } reg;
} REG_VDM_CFG_RSV_0_UNION;
#endif
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_0_START (0)
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_0_END (0)
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_1_START (1)
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_1_END (1)
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_2_START (2)
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_2_END (2)
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_3_START (3)
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_3_END (3)
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_4_START (4)
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_4_END (4)
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_5_START (5)
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_5_END (5)
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_6_START (6)
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_6_END (6)
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_7_START (7)
#define REG_VDM_CFG_RSV_0_pd_vdm_rsv_7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pd_vdm_rsv_8 : 1;
        unsigned char pd_vdm_rsv_9 : 1;
        unsigned char pd_vdm_rsv_10 : 1;
        unsigned char pd_vdm_rsv_11 : 1;
        unsigned char pd_vdm_rsv_12 : 1;
        unsigned char pd_vdm_rsv_13 : 1;
        unsigned char pd_vdm_rsv_14 : 1;
        unsigned char pd_vdm_rsv_15 : 1;
    } reg;
} REG_VDM_CFG_RSV_1_UNION;
#endif
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_8_START (0)
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_8_END (0)
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_9_START (1)
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_9_END (1)
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_10_START (2)
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_10_END (2)
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_11_START (3)
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_11_END (3)
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_12_START (4)
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_12_END (4)
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_13_START (5)
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_13_END (5)
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_14_START (6)
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_14_END (6)
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_15_START (7)
#define REG_VDM_CFG_RSV_1_pd_vdm_rsv_15_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_pd_vdm5_en : 8;
    } reg;
} REG_VDM5_CFG_EN_UNION;
#endif
#define REG_VDM5_CFG_EN_sc_pd_vdm5_en_START (0)
#define REG_VDM5_CFG_EN_sc_pd_vdm5_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char flag_batfet_ocp : 1;
        unsigned char reserved : 7;
    } reg;
} REG_BATFET_OCP_FLAG_UNION;
#endif
#define REG_BATFET_OCP_FLAG_flag_batfet_ocp_START (0)
#define REG_BATFET_OCP_FLAG_flag_batfet_ocp_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_reversbst_mode : 1;
        unsigned char reserved : 7;
    } reg;
} REG_DA_BUCK_REVERSBST_MODE_UNION;
#endif
#define REG_DA_BUCK_REVERSBST_MODE_da_buck_reversbst_mode_START (0)
#define REG_DA_BUCK_REVERSBST_MODE_da_buck_reversbst_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_buck_reversbst_clear : 1;
        unsigned char reserved : 7;
    } reg;
} REG_SC_BUCK_REVERSBST_CLEAR_UNION;
#endif
#define REG_SC_BUCK_REVERSBST_CLEAR_sc_buck_reversbst_clear_START (0)
#define REG_SC_BUCK_REVERSBST_CLEAR_sc_buck_reversbst_clear_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_irq_sbu_ovp_mask : 1;
        unsigned char reserved : 7;
    } reg;
} REG_JTAG_CFG_REG_0_UNION;
#endif
#define REG_JTAG_CFG_REG_0_da_irq_sbu_ovp_mask_START (0)
#define REG_JTAG_CFG_REG_0_da_irq_sbu_ovp_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_coul_channel_sel : 1;
        unsigned char reserved : 7;
    } reg;
} REG_COUL_CHANNEL_SEL_UNION;
#endif
#define REG_COUL_CHANNEL_SEL_da_coul_channel_sel_START (0)
#define REG_COUL_CHANNEL_SEL_da_coul_channel_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_bat_res_sel : 2;
        unsigned char reserved : 6;
    } reg;
} REG_IBAT_RES_SEL_UNION;
#endif
#define REG_IBAT_RES_SEL_da_bat_res_sel_START (0)
#define REG_IBAT_RES_SEL_da_bat_res_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_coul_pd_time_sel : 2;
        unsigned char reserved : 6;
    } reg;
} REG_COUL_PD_TIME_UNION;
#endif
#define REG_COUL_PD_TIME_sc_coul_pd_time_sel_START (0)
#define REG_COUL_PD_TIME_sc_coul_pd_time_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_dp_res_det_iqsel : 2;
        unsigned char da_dp_res_det_en : 1;
        unsigned char da_app_det_en : 1;
        unsigned char da_app_det_chsel : 1;
        unsigned char reserved : 3;
    } reg;
} REG_FCP_TOP_CFG_REG_UNION;
#endif
#define REG_FCP_TOP_CFG_REG_da_dp_res_det_iqsel_START (0)
#define REG_FCP_TOP_CFG_REG_da_dp_res_det_iqsel_END (1)
#define REG_FCP_TOP_CFG_REG_da_dp_res_det_en_START (2)
#define REG_FCP_TOP_CFG_REG_da_dp_res_det_en_END (2)
#define REG_FCP_TOP_CFG_REG_da_app_det_en_START (3)
#define REG_FCP_TOP_CFG_REG_da_app_det_en_END (3)
#define REG_FCP_TOP_CFG_REG_da_app_det_chsel_START (4)
#define REG_FCP_TOP_CFG_REG_da_app_det_chsel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_boost_resv0 : 8;
    } reg;
} REG_BOOST_CFG_REG_0_UNION;
#endif
#define REG_BOOST_CFG_REG_0_da_boost_resv0_START (0)
#define REG_BOOST_CFG_REG_0_da_boost_resv0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_boost_resv1 : 8;
    } reg;
} REG_BOOST_CFG_REG_1_UNION;
#endif
#define REG_BOOST_CFG_REG_1_da_boost_resv1_START (0)
#define REG_BOOST_CFG_REG_1_da_boost_resv1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_boost_resv2 : 8;
    } reg;
} REG_BOOST_CFG_REG_2_UNION;
#endif
#define REG_BOOST_CFG_REG_2_da_boost_resv2_START (0)
#define REG_BOOST_CFG_REG_2_da_boost_resv2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_boost_resv3 : 8;
    } reg;
} REG_BOOST_CFG_REG_3_UNION;
#endif
#define REG_BOOST_CFG_REG_3_da_boost_resv3_START (0)
#define REG_BOOST_CFG_REG_3_da_boost_resv3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_boost_resv4 : 8;
    } reg;
} REG_BOOST_CFG_REG_4_UNION;
#endif
#define REG_BOOST_CFG_REG_4_da_boost_resv4_START (0)
#define REG_BOOST_CFG_REG_4_da_boost_resv4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_boost_resv5 : 8;
    } reg;
} REG_BOOST_CFG_REG_5_UNION;
#endif
#define REG_BOOST_CFG_REG_5_da_boost_resv5_START (0)
#define REG_BOOST_CFG_REG_5_da_boost_resv5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_boost_resv6 : 8;
    } reg;
} REG_BOOST_CFG_REG_6_UNION;
#endif
#define REG_BOOST_CFG_REG_6_da_boost_resv6_START (0)
#define REG_BOOST_CFG_REG_6_da_boost_resv6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_boost_resv7 : 8;
    } reg;
} REG_BOOST_CFG_REG_7_UNION;
#endif
#define REG_BOOST_CFG_REG_7_da_boost_resv7_START (0)
#define REG_BOOST_CFG_REG_7_da_boost_resv7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_boost_resv8 : 8;
    } reg;
} REG_BOOST_CFG_REG_8_UNION;
#endif
#define REG_BOOST_CFG_REG_8_da_boost_resv8_START (0)
#define REG_BOOST_CFG_REG_8_da_boost_resv8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_boost_resv9 : 8;
    } reg;
} REG_BOOST_CFG_REG_9_UNION;
#endif
#define REG_BOOST_CFG_REG_9_da_boost_resv9_START (0)
#define REG_BOOST_CFG_REG_9_da_boost_resv9_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_boost_ready : 1;
        unsigned char reserved : 7;
    } reg;
} REG_BOOST_CFG_REG_10_UNION;
#endif
#define REG_BOOST_CFG_REG_10_da_boost_ready_START (0)
#define REG_BOOST_CFG_REG_10_da_boost_ready_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_boost_mode : 1;
        unsigned char reserved : 7;
    } reg;
} REG_BOOST_RO_REG_11_UNION;
#endif
#define REG_BOOST_RO_REG_11_ad_boost_mode_START (0)
#define REG_BOOST_RO_REG_11_ad_boost_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_chg_pre_state : 1;
        unsigned char ad_chg_fwd_en : 1;
        unsigned char ad_chg_dpm_state : 1;
        unsigned char ad_chg_chgstate : 2;
        unsigned char ad_chg_acl_state : 1;
        unsigned char ad_batfet_l_disch : 1;
        unsigned char ad_batfet_h_state : 1;
    } reg;
} REG_CHARGER_RO_REG_0_UNION;
#endif
#define REG_CHARGER_RO_REG_0_ad_chg_pre_state_START (0)
#define REG_CHARGER_RO_REG_0_ad_chg_pre_state_END (0)
#define REG_CHARGER_RO_REG_0_ad_chg_fwd_en_START (1)
#define REG_CHARGER_RO_REG_0_ad_chg_fwd_en_END (1)
#define REG_CHARGER_RO_REG_0_ad_chg_dpm_state_START (2)
#define REG_CHARGER_RO_REG_0_ad_chg_dpm_state_END (2)
#define REG_CHARGER_RO_REG_0_ad_chg_chgstate_START (3)
#define REG_CHARGER_RO_REG_0_ad_chg_chgstate_END (4)
#define REG_CHARGER_RO_REG_0_ad_chg_acl_state_START (5)
#define REG_CHARGER_RO_REG_0_ad_chg_acl_state_END (5)
#define REG_CHARGER_RO_REG_0_ad_batfet_l_disch_START (6)
#define REG_CHARGER_RO_REG_0_ad_batfet_l_disch_END (6)
#define REG_CHARGER_RO_REG_0_ad_batfet_h_state_START (7)
#define REG_CHARGER_RO_REG_0_ad_batfet_h_state_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_chg_tri_state : 1;
        unsigned char ad_chg_therm_state : 1;
        unsigned char ad_chg_sft_pd : 1;
        unsigned char ad_chg_rev_ok : 1;
        unsigned char ad_chg_rev_en : 1;
        unsigned char ad_chg_pu_btft : 1;
        unsigned char reserved : 2;
    } reg;
} REG_CHARGER_RO_REG_1_UNION;
#endif
#define REG_CHARGER_RO_REG_1_ad_chg_tri_state_START (0)
#define REG_CHARGER_RO_REG_1_ad_chg_tri_state_END (0)
#define REG_CHARGER_RO_REG_1_ad_chg_therm_state_START (1)
#define REG_CHARGER_RO_REG_1_ad_chg_therm_state_END (1)
#define REG_CHARGER_RO_REG_1_ad_chg_sft_pd_START (2)
#define REG_CHARGER_RO_REG_1_ad_chg_sft_pd_END (2)
#define REG_CHARGER_RO_REG_1_ad_chg_rev_ok_START (3)
#define REG_CHARGER_RO_REG_1_ad_chg_rev_ok_END (3)
#define REG_CHARGER_RO_REG_1_ad_chg_rev_en_START (4)
#define REG_CHARGER_RO_REG_1_ad_chg_rev_en_END (4)
#define REG_CHARGER_RO_REG_1_ad_chg_pu_btft_START (5)
#define REG_CHARGER_RO_REG_1_ad_chg_pu_btft_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_chg_cap2_sel : 2;
        unsigned char da_chg_cap1_sel : 2;
        unsigned char da_chg_bat_open : 1;
        unsigned char da_chg_ate_mode : 1;
        unsigned char da_chg_acl_rpt_en : 1;
        unsigned char da_chg_2x_ibias_en : 1;
    } reg;
} REG_CHARGER_CFG_REG_0_UNION;
#endif
#define REG_CHARGER_CFG_REG_0_da_chg_cap2_sel_START (0)
#define REG_CHARGER_CFG_REG_0_da_chg_cap2_sel_END (1)
#define REG_CHARGER_CFG_REG_0_da_chg_cap1_sel_START (2)
#define REG_CHARGER_CFG_REG_0_da_chg_cap1_sel_END (3)
#define REG_CHARGER_CFG_REG_0_da_chg_bat_open_START (4)
#define REG_CHARGER_CFG_REG_0_da_chg_bat_open_END (4)
#define REG_CHARGER_CFG_REG_0_da_chg_ate_mode_START (5)
#define REG_CHARGER_CFG_REG_0_da_chg_ate_mode_END (5)
#define REG_CHARGER_CFG_REG_0_da_chg_acl_rpt_en_START (6)
#define REG_CHARGER_CFG_REG_0_da_chg_acl_rpt_en_END (6)
#define REG_CHARGER_CFG_REG_0_da_chg_2x_ibias_en_START (7)
#define REG_CHARGER_CFG_REG_0_da_chg_2x_ibias_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_chg_cp_src_sel : 1;
        unsigned char da_chg_clk_div2_shd : 1;
        unsigned char da_chg_cap4_sel : 2;
        unsigned char da_chg_cap3_sel : 2;
        unsigned char reserved : 2;
    } reg;
} REG_CHARGER_CFG_REG_1_UNION;
#endif
#define REG_CHARGER_CFG_REG_1_da_chg_cp_src_sel_START (0)
#define REG_CHARGER_CFG_REG_1_da_chg_cp_src_sel_END (0)
#define REG_CHARGER_CFG_REG_1_da_chg_clk_div2_shd_START (1)
#define REG_CHARGER_CFG_REG_1_da_chg_clk_div2_shd_END (1)
#define REG_CHARGER_CFG_REG_1_da_chg_cap4_sel_START (2)
#define REG_CHARGER_CFG_REG_1_da_chg_cap4_sel_END (3)
#define REG_CHARGER_CFG_REG_1_da_chg_cap3_sel_START (4)
#define REG_CHARGER_CFG_REG_1_da_chg_cap3_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_ilimit : 5;
        unsigned char reserved : 3;
    } reg;
} REG_BUCK_ILIMIT_UNION;
#endif
#define REG_BUCK_ILIMIT_da_buck_ilimit_START (0)
#define REG_BUCK_ILIMIT_da_buck_ilimit_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_chg_eoc_del2m_en : 1;
        unsigned char da_chg_en_term : 1;
        unsigned char da_chg_cv_adj : 3;
        unsigned char reserved : 3;
    } reg;
} REG_CHARGER_CFG_REG_2_UNION;
#endif
#define REG_CHARGER_CFG_REG_2_da_chg_eoc_del2m_en_START (0)
#define REG_CHARGER_CFG_REG_2_da_chg_eoc_del2m_en_END (0)
#define REG_CHARGER_CFG_REG_2_da_chg_en_term_START (1)
#define REG_CHARGER_CFG_REG_2_da_chg_en_term_END (1)
#define REG_CHARGER_CFG_REG_2_da_chg_cv_adj_START (2)
#define REG_CHARGER_CFG_REG_2_da_chg_cv_adj_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_chg_fast_ichg : 5;
        unsigned char reserved : 3;
    } reg;
} REG_CHARGER_CFG_REG_3_UNION;
#endif
#define REG_CHARGER_CFG_REG_3_da_chg_fast_ichg_START (0)
#define REG_CHARGER_CFG_REG_3_da_chg_fast_ichg_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_chg_force_eoc : 1;
        unsigned char da_chg_fastchg_timer : 2;
        unsigned char da_chg_fast_vchg : 5;
    } reg;
} REG_CHARGER_CFG_REG_4_UNION;
#endif
#define REG_CHARGER_CFG_REG_4_da_chg_force_eoc_START (0)
#define REG_CHARGER_CFG_REG_4_da_chg_force_eoc_END (0)
#define REG_CHARGER_CFG_REG_4_da_chg_fastchg_timer_START (1)
#define REG_CHARGER_CFG_REG_4_da_chg_fastchg_timer_END (2)
#define REG_CHARGER_CFG_REG_4_da_chg_fast_vchg_START (3)
#define REG_CHARGER_CFG_REG_4_da_chg_fast_vchg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_chg_ir_set : 4;
        unsigned char da_chg_ir_sense_gate_shild : 1;
        unsigned char da_chg_gap_sense_gate_shild : 1;
        unsigned char da_chg_force_gap : 1;
        unsigned char reserved : 1;
    } reg;
} REG_CHARGER_CFG_REG_5_UNION;
#endif
#define REG_CHARGER_CFG_REG_5_da_chg_ir_set_START (0)
#define REG_CHARGER_CFG_REG_5_da_chg_ir_set_END (3)
#define REG_CHARGER_CFG_REG_5_da_chg_ir_sense_gate_shild_START (4)
#define REG_CHARGER_CFG_REG_5_da_chg_ir_sense_gate_shild_END (4)
#define REG_CHARGER_CFG_REG_5_da_chg_gap_sense_gate_shild_START (5)
#define REG_CHARGER_CFG_REG_5_da_chg_gap_sense_gate_shild_END (5)
#define REG_CHARGER_CFG_REG_5_da_chg_force_gap_START (6)
#define REG_CHARGER_CFG_REG_5_da_chg_force_gap_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_chg_ocp_test : 1;
        unsigned char da_chg_ocp_shd : 1;
        unsigned char da_chg_ocp_delay_shd : 1;
        unsigned char da_chg_ocp_adj : 2;
        unsigned char da_chg_md_sel : 1;
        unsigned char da_chg_iref_clamp : 2;
    } reg;
} REG_CHARGER_CFG_REG_6_UNION;
#endif
#define REG_CHARGER_CFG_REG_6_da_chg_ocp_test_START (0)
#define REG_CHARGER_CFG_REG_6_da_chg_ocp_test_END (0)
#define REG_CHARGER_CFG_REG_6_da_chg_ocp_shd_START (1)
#define REG_CHARGER_CFG_REG_6_da_chg_ocp_shd_END (1)
#define REG_CHARGER_CFG_REG_6_da_chg_ocp_delay_shd_START (2)
#define REG_CHARGER_CFG_REG_6_da_chg_ocp_delay_shd_END (2)
#define REG_CHARGER_CFG_REG_6_da_chg_ocp_adj_START (3)
#define REG_CHARGER_CFG_REG_6_da_chg_ocp_adj_END (4)
#define REG_CHARGER_CFG_REG_6_da_chg_md_sel_START (5)
#define REG_CHARGER_CFG_REG_6_da_chg_md_sel_END (5)
#define REG_CHARGER_CFG_REG_6_da_chg_iref_clamp_START (6)
#define REG_CHARGER_CFG_REG_6_da_chg_iref_clamp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_chg_q4_3x_shd : 1;
        unsigned char da_chg_prechg_timer : 2;
        unsigned char da_chg_pre_vchg : 2;
        unsigned char da_chg_pre_ichg : 2;
        unsigned char reserved : 1;
    } reg;
} REG_CHARGER_CFG_REG_7_UNION;
#endif
#define REG_CHARGER_CFG_REG_7_da_chg_q4_3x_shd_START (0)
#define REG_CHARGER_CFG_REG_7_da_chg_q4_3x_shd_END (0)
#define REG_CHARGER_CFG_REG_7_da_chg_prechg_timer_START (1)
#define REG_CHARGER_CFG_REG_7_da_chg_prechg_timer_END (2)
#define REG_CHARGER_CFG_REG_7_da_chg_pre_vchg_START (3)
#define REG_CHARGER_CFG_REG_7_da_chg_pre_vchg_END (4)
#define REG_CHARGER_CFG_REG_7_da_chg_pre_ichg_START (5)
#define REG_CHARGER_CFG_REG_7_da_chg_pre_ichg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_chg_rechg_time : 2;
        unsigned char reserved : 6;
    } reg;
} REG_CHARGER_CFG_REG_8_UNION;
#endif
#define REG_CHARGER_CFG_REG_8_da_chg_rechg_time_START (0)
#define REG_CHARGER_CFG_REG_8_da_chg_rechg_time_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_chg_resv1 : 8;
    } reg;
} REG_CHARGER_CFG_REG_9_UNION;
#endif
#define REG_CHARGER_CFG_REG_9_da_chg_resv1_START (0)
#define REG_CHARGER_CFG_REG_9_da_chg_resv1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_chg_resv2 : 8;
    } reg;
} REG_CHARGER_CFG_REG_10_UNION;
#endif
#define REG_CHARGER_CFG_REG_10_da_chg_resv2_START (0)
#define REG_CHARGER_CFG_REG_10_da_chg_resv2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_chg_resvo : 8;
    } reg;
} REG_CHARGER_CFG_REG_11_UNION;
#endif
#define REG_CHARGER_CFG_REG_11_da_chg_resvo_START (0)
#define REG_CHARGER_CFG_REG_11_da_chg_resvo_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_chg_term_ichg : 2;
        unsigned char da_chg_scp_en : 1;
        unsigned char da_chg_rpt_en : 1;
        unsigned char da_chg_rev_ok_cmp : 2;
        unsigned char da_chg_rev_mode : 2;
    } reg;
} REG_CHARGER_CFG_REG_12_UNION;
#endif
#define REG_CHARGER_CFG_REG_12_da_chg_term_ichg_START (0)
#define REG_CHARGER_CFG_REG_12_da_chg_term_ichg_END (1)
#define REG_CHARGER_CFG_REG_12_da_chg_scp_en_START (2)
#define REG_CHARGER_CFG_REG_12_da_chg_scp_en_END (2)
#define REG_CHARGER_CFG_REG_12_da_chg_rpt_en_START (3)
#define REG_CHARGER_CFG_REG_12_da_chg_rpt_en_END (3)
#define REG_CHARGER_CFG_REG_12_da_chg_rev_ok_cmp_START (4)
#define REG_CHARGER_CFG_REG_12_da_chg_rev_ok_cmp_END (5)
#define REG_CHARGER_CFG_REG_12_da_chg_rev_mode_START (6)
#define REG_CHARGER_CFG_REG_12_da_chg_rev_mode_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_chg_vrechg_hys : 2;
        unsigned char da_chg_vclamp_set : 3;
        unsigned char da_chg_vbat_plus6mv : 1;
        unsigned char da_chg_timer_en : 1;
        unsigned char da_chg_test_md : 1;
    } reg;
} REG_CHARGER_CFG_REG_13_UNION;
#endif
#define REG_CHARGER_CFG_REG_13_da_chg_vrechg_hys_START (0)
#define REG_CHARGER_CFG_REG_13_da_chg_vrechg_hys_END (1)
#define REG_CHARGER_CFG_REG_13_da_chg_vclamp_set_START (2)
#define REG_CHARGER_CFG_REG_13_da_chg_vclamp_set_END (4)
#define REG_CHARGER_CFG_REG_13_da_chg_vbat_plus6mv_START (5)
#define REG_CHARGER_CFG_REG_13_da_chg_vbat_plus6mv_END (5)
#define REG_CHARGER_CFG_REG_13_da_chg_timer_en_START (6)
#define REG_CHARGER_CFG_REG_13_da_chg_timer_en_END (6)
#define REG_CHARGER_CFG_REG_13_da_chg_test_md_START (7)
#define REG_CHARGER_CFG_REG_13_da_chg_test_md_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_chg_vres2_sel : 2;
        unsigned char da_chg_vres1_sel : 2;
        unsigned char reserved : 4;
    } reg;
} REG_CHARGER_CFG_REG_14_UNION;
#endif
#define REG_CHARGER_CFG_REG_14_da_chg_vres2_sel_START (0)
#define REG_CHARGER_CFG_REG_14_da_chg_vres2_sel_END (1)
#define REG_CHARGER_CFG_REG_14_da_chg_vres1_sel_START (2)
#define REG_CHARGER_CFG_REG_14_da_chg_vres1_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_9v_maxduty_en : 1;
        unsigned char da_buck_9v_maxduty_adj : 2;
        unsigned char reserved : 5;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_0_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_0_da_buck_9v_maxduty_en_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_0_da_buck_9v_maxduty_en_END (0)
#define REG_BUCK_OTG_TOP_CFG_REG_0_da_buck_9v_maxduty_adj_START (1)
#define REG_BUCK_OTG_TOP_CFG_REG_0_da_buck_9v_maxduty_adj_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_antibst : 8;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_1_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_1_da_buck_antibst_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_1_da_buck_antibst_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_cmp_cur : 2;
        unsigned char da_buck_clamp_sel : 1;
        unsigned char da_buck_chg_ov_en : 1;
        unsigned char da_buck_cc_4m : 1;
        unsigned char da_buck_cap5_cc : 2;
        unsigned char da_buck_autochg_en : 1;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_2_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_2_da_buck_cmp_cur_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_2_da_buck_cmp_cur_END (1)
#define REG_BUCK_OTG_TOP_CFG_REG_2_da_buck_clamp_sel_START (2)
#define REG_BUCK_OTG_TOP_CFG_REG_2_da_buck_clamp_sel_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_2_da_buck_chg_ov_en_START (3)
#define REG_BUCK_OTG_TOP_CFG_REG_2_da_buck_chg_ov_en_END (3)
#define REG_BUCK_OTG_TOP_CFG_REG_2_da_buck_cc_4m_START (4)
#define REG_BUCK_OTG_TOP_CFG_REG_2_da_buck_cc_4m_END (4)
#define REG_BUCK_OTG_TOP_CFG_REG_2_da_buck_cap5_cc_START (5)
#define REG_BUCK_OTG_TOP_CFG_REG_2_da_buck_cap5_cc_END (6)
#define REG_BUCK_OTG_TOP_CFG_REG_2_da_buck_autochg_en_START (7)
#define REG_BUCK_OTG_TOP_CFG_REG_2_da_buck_autochg_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_crtsense_en_l : 1;
        unsigned char da_buck_crtsense_en_h : 1;
        unsigned char da_buck_crtsense_chpp_ctrl : 1;
        unsigned char da_buck_crtsense_chpp_clk_sel : 2;
        unsigned char da_buck_crtsense_avgcurr_filter_sel : 3;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_3_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_3_da_buck_crtsense_en_l_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_3_da_buck_crtsense_en_l_END (0)
#define REG_BUCK_OTG_TOP_CFG_REG_3_da_buck_crtsense_en_h_START (1)
#define REG_BUCK_OTG_TOP_CFG_REG_3_da_buck_crtsense_en_h_END (1)
#define REG_BUCK_OTG_TOP_CFG_REG_3_da_buck_crtsense_chpp_ctrl_START (2)
#define REG_BUCK_OTG_TOP_CFG_REG_3_da_buck_crtsense_chpp_ctrl_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_3_da_buck_crtsense_chpp_clk_sel_START (3)
#define REG_BUCK_OTG_TOP_CFG_REG_3_da_buck_crtsense_chpp_clk_sel_END (4)
#define REG_BUCK_OTG_TOP_CFG_REG_3_da_buck_crtsense_avgcurr_filter_sel_START (5)
#define REG_BUCK_OTG_TOP_CFG_REG_3_da_buck_crtsense_avgcurr_filter_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_crtsense_res_sel : 3;
        unsigned char da_buck_crtsense_ratio_sel : 2;
        unsigned char da_buck_crtsense_gm_sel : 3;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_4_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_4_da_buck_crtsense_res_sel_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_4_da_buck_crtsense_res_sel_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_4_da_buck_crtsense_ratio_sel_START (3)
#define REG_BUCK_OTG_TOP_CFG_REG_4_da_buck_crtsense_ratio_sel_END (4)
#define REG_BUCK_OTG_TOP_CFG_REG_4_da_buck_crtsense_gm_sel_START (5)
#define REG_BUCK_OTG_TOP_CFG_REG_4_da_buck_crtsense_gm_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_dmd_delay : 1;
        unsigned char da_buck_dmd_clamp : 1;
        unsigned char da_buck_cvdmd : 5;
        unsigned char da_buck_crtsense_swcs_filter_ctrl : 1;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_5_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_5_da_buck_dmd_delay_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_5_da_buck_dmd_delay_END (0)
#define REG_BUCK_OTG_TOP_CFG_REG_5_da_buck_dmd_clamp_START (1)
#define REG_BUCK_OTG_TOP_CFG_REG_5_da_buck_dmd_clamp_END (1)
#define REG_BUCK_OTG_TOP_CFG_REG_5_da_buck_cvdmd_START (2)
#define REG_BUCK_OTG_TOP_CFG_REG_5_da_buck_cvdmd_END (6)
#define REG_BUCK_OTG_TOP_CFG_REG_5_da_buck_crtsense_swcs_filter_ctrl_START (7)
#define REG_BUCK_OTG_TOP_CFG_REG_5_da_buck_crtsense_swcs_filter_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_dpm_auto : 1;
        unsigned char da_buck_dmd_sel : 4;
        unsigned char da_buck_dmd_ibias : 2;
        unsigned char da_buck_dmd_en : 1;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_6_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_6_da_buck_dpm_auto_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_6_da_buck_dpm_auto_END (0)
#define REG_BUCK_OTG_TOP_CFG_REG_6_da_buck_dmd_sel_START (1)
#define REG_BUCK_OTG_TOP_CFG_REG_6_da_buck_dmd_sel_END (4)
#define REG_BUCK_OTG_TOP_CFG_REG_6_da_buck_dmd_ibias_START (5)
#define REG_BUCK_OTG_TOP_CFG_REG_6_da_buck_dmd_ibias_END (6)
#define REG_BUCK_OTG_TOP_CFG_REG_6_da_buck_dmd_en_START (7)
#define REG_BUCK_OTG_TOP_CFG_REG_6_da_buck_dmd_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_eco : 1;
        unsigned char da_buck_dpm_sel : 4;
        unsigned char reserved : 3;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_7_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_7_da_buck_eco_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_7_da_buck_eco_END (0)
#define REG_BUCK_OTG_TOP_CFG_REG_7_da_buck_dpm_sel_START (1)
#define REG_BUCK_OTG_TOP_CFG_REG_7_da_buck_dpm_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_fullduty_offtime : 2;
        unsigned char da_buck_fullduty_en : 1;
        unsigned char da_buck_fullduty_delaytime : 4;
        unsigned char reserved : 1;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_8_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_8_da_buck_fullduty_offtime_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_8_da_buck_fullduty_offtime_END (1)
#define REG_BUCK_OTG_TOP_CFG_REG_8_da_buck_fullduty_en_START (2)
#define REG_BUCK_OTG_TOP_CFG_REG_8_da_buck_fullduty_en_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_8_da_buck_fullduty_delaytime_START (3)
#define REG_BUCK_OTG_TOP_CFG_REG_8_da_buck_fullduty_delaytime_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_lmos_on_sel : 1;
        unsigned char da_buck_lmos_on_en : 1;
        unsigned char da_buck_gap_mode_sel : 1;
        unsigned char da_buck_gap_auto : 1;
        unsigned char da_buck_gap : 3;
        unsigned char reserved : 1;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_9_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_9_da_buck_lmos_on_sel_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_9_da_buck_lmos_on_sel_END (0)
#define REG_BUCK_OTG_TOP_CFG_REG_9_da_buck_lmos_on_en_START (1)
#define REG_BUCK_OTG_TOP_CFG_REG_9_da_buck_lmos_on_en_END (1)
#define REG_BUCK_OTG_TOP_CFG_REG_9_da_buck_gap_mode_sel_START (2)
#define REG_BUCK_OTG_TOP_CFG_REG_9_da_buck_gap_mode_sel_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_9_da_buck_gap_auto_START (3)
#define REG_BUCK_OTG_TOP_CFG_REG_9_da_buck_gap_auto_END (3)
#define REG_BUCK_OTG_TOP_CFG_REG_9_da_buck_gap_START (4)
#define REG_BUCK_OTG_TOP_CFG_REG_9_da_buck_gap_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_lmosocp_lpf : 2;
        unsigned char reserved : 6;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_10_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_10_da_buck_lmosocp_lpf_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_10_da_buck_lmosocp_lpf_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_loopenable : 8;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_11_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_11_da_buck_loopenable_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_11_da_buck_loopenable_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_min_ontime_sel : 1;
        unsigned char da_buck_min_ontime : 2;
        unsigned char da_buck_min_offtime_sel : 1;
        unsigned char da_buck_min_offtime : 2;
        unsigned char da_buck_ls_down : 2;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_12_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_12_da_buck_min_ontime_sel_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_12_da_buck_min_ontime_sel_END (0)
#define REG_BUCK_OTG_TOP_CFG_REG_12_da_buck_min_ontime_START (1)
#define REG_BUCK_OTG_TOP_CFG_REG_12_da_buck_min_ontime_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_12_da_buck_min_offtime_sel_START (3)
#define REG_BUCK_OTG_TOP_CFG_REG_12_da_buck_min_offtime_sel_END (3)
#define REG_BUCK_OTG_TOP_CFG_REG_12_da_buck_min_offtime_START (4)
#define REG_BUCK_OTG_TOP_CFG_REG_12_da_buck_min_offtime_END (5)
#define REG_BUCK_OTG_TOP_CFG_REG_12_da_buck_ls_down_START (6)
#define REG_BUCK_OTG_TOP_CFG_REG_12_da_buck_ls_down_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_ocp_peak : 2;
        unsigned char da_buck_ocp_enb : 1;
        unsigned char da_buck_ocp_delay_sel_h : 2;
        unsigned char da_buck_ocp_adj : 2;
        unsigned char reserved : 1;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_13_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_13_da_buck_ocp_peak_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_13_da_buck_ocp_peak_END (1)
#define REG_BUCK_OTG_TOP_CFG_REG_13_da_buck_ocp_enb_START (2)
#define REG_BUCK_OTG_TOP_CFG_REG_13_da_buck_ocp_enb_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_13_da_buck_ocp_delay_sel_h_START (3)
#define REG_BUCK_OTG_TOP_CFG_REG_13_da_buck_ocp_delay_sel_h_END (4)
#define REG_BUCK_OTG_TOP_CFG_REG_13_da_buck_ocp_adj_START (5)
#define REG_BUCK_OTG_TOP_CFG_REG_13_da_buck_ocp_adj_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_osc_frq : 4;
        unsigned char da_buck_ocp_vally : 2;
        unsigned char da_buck_ocp_sel_h : 2;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_14_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_14_da_buck_osc_frq_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_14_da_buck_osc_frq_END (3)
#define REG_BUCK_OTG_TOP_CFG_REG_14_da_buck_ocp_vally_START (4)
#define REG_BUCK_OTG_TOP_CFG_REG_14_da_buck_ocp_vally_END (5)
#define REG_BUCK_OTG_TOP_CFG_REG_14_da_buck_ocp_sel_h_START (6)
#define REG_BUCK_OTG_TOP_CFG_REG_14_da_buck_ocp_sel_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_pre_op : 8;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_15_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_15_da_buck_pre_op_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_15_da_buck_pre_op_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_res10_cc_rout : 2;
        unsigned char da_buck_rdy_en : 1;
        unsigned char da_buck_rc_thm : 2;
        unsigned char da_buck_random : 3;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_16_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_16_da_buck_res10_cc_rout_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_16_da_buck_res10_cc_rout_END (1)
#define REG_BUCK_OTG_TOP_CFG_REG_16_da_buck_rdy_en_START (2)
#define REG_BUCK_OTG_TOP_CFG_REG_16_da_buck_rdy_en_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_16_da_buck_rc_thm_START (3)
#define REG_BUCK_OTG_TOP_CFG_REG_16_da_buck_rc_thm_END (4)
#define REG_BUCK_OTG_TOP_CFG_REG_16_da_buck_random_START (5)
#define REG_BUCK_OTG_TOP_CFG_REG_16_da_buck_random_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_res8_cv_gm : 2;
        unsigned char da_buck_res7_sys_gm : 2;
        unsigned char da_buck_res6_thm_gm : 2;
        unsigned char da_buck_res12_cc_pz : 2;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_17_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_17_da_buck_res8_cv_gm_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_17_da_buck_res8_cv_gm_END (1)
#define REG_BUCK_OTG_TOP_CFG_REG_17_da_buck_res7_sys_gm_START (2)
#define REG_BUCK_OTG_TOP_CFG_REG_17_da_buck_res7_sys_gm_END (3)
#define REG_BUCK_OTG_TOP_CFG_REG_17_da_buck_res6_thm_gm_START (4)
#define REG_BUCK_OTG_TOP_CFG_REG_17_da_buck_res6_thm_gm_END (5)
#define REG_BUCK_OTG_TOP_CFG_REG_17_da_buck_res12_cc_pz_START (6)
#define REG_BUCK_OTG_TOP_CFG_REG_17_da_buck_res12_cc_pz_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_res9_cc_gm : 2;
        unsigned char reserved : 6;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_18_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_18_da_buck_res9_cc_gm_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_18_da_buck_res9_cc_gm_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_reserve1 : 8;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_19_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_19_da_buck_reserve1_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_19_da_buck_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_reserve2 : 8;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_20_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_20_da_buck_reserve2_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_20_da_buck_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_saw_sel : 2;
        unsigned char da_buck_saw_peak_adj : 1;
        unsigned char reserved : 1;
        unsigned char da_buck_reverbst_mode2 : 4;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_21_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_21_da_buck_saw_sel_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_21_da_buck_saw_sel_END (1)
#define REG_BUCK_OTG_TOP_CFG_REG_21_da_buck_saw_peak_adj_START (2)
#define REG_BUCK_OTG_TOP_CFG_REG_21_da_buck_saw_peak_adj_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_21_da_buck_reverbst_mode2_START (4)
#define REG_BUCK_OTG_TOP_CFG_REG_21_da_buck_reverbst_mode2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_test_saw_en : 1;
        unsigned char da_buck_sysovp_sel : 1;
        unsigned char da_buck_sysovp_en : 1;
        unsigned char da_buck_sysmin_sel : 2;
        unsigned char da_buck_ssmode_en : 1;
        unsigned char da_buck_sft_maxduty_en : 1;
        unsigned char da_buck_saw_vally_adj : 1;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_22_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_22_da_buck_test_saw_en_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_22_da_buck_test_saw_en_END (0)
#define REG_BUCK_OTG_TOP_CFG_REG_22_da_buck_sysovp_sel_START (1)
#define REG_BUCK_OTG_TOP_CFG_REG_22_da_buck_sysovp_sel_END (1)
#define REG_BUCK_OTG_TOP_CFG_REG_22_da_buck_sysovp_en_START (2)
#define REG_BUCK_OTG_TOP_CFG_REG_22_da_buck_sysovp_en_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_22_da_buck_sysmin_sel_START (3)
#define REG_BUCK_OTG_TOP_CFG_REG_22_da_buck_sysmin_sel_END (4)
#define REG_BUCK_OTG_TOP_CFG_REG_22_da_buck_ssmode_en_START (5)
#define REG_BUCK_OTG_TOP_CFG_REG_22_da_buck_ssmode_en_END (5)
#define REG_BUCK_OTG_TOP_CFG_REG_22_da_buck_sft_maxduty_en_START (6)
#define REG_BUCK_OTG_TOP_CFG_REG_22_da_buck_sft_maxduty_en_END (6)
#define REG_BUCK_OTG_TOP_CFG_REG_22_da_buck_saw_vally_adj_START (7)
#define REG_BUCK_OTG_TOP_CFG_REG_22_da_buck_saw_vally_adj_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_otg_clp_l_set : 1;
        unsigned char da_otg_clp_l_en : 1;
        unsigned char da_otg_clp_h_en : 1;
        unsigned char da_otg_ckmin_raise : 1;
        unsigned char da_otg_ckmin : 2;
        unsigned char reserved : 2;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_31_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_31_da_otg_clp_l_set_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_31_da_otg_clp_l_set_END (0)
#define REG_BUCK_OTG_TOP_CFG_REG_31_da_otg_clp_l_en_START (1)
#define REG_BUCK_OTG_TOP_CFG_REG_31_da_otg_clp_l_en_END (1)
#define REG_BUCK_OTG_TOP_CFG_REG_31_da_otg_clp_h_en_START (2)
#define REG_BUCK_OTG_TOP_CFG_REG_31_da_otg_clp_h_en_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_31_da_otg_ckmin_raise_START (3)
#define REG_BUCK_OTG_TOP_CFG_REG_31_da_otg_ckmin_raise_END (3)
#define REG_BUCK_OTG_TOP_CFG_REG_31_da_otg_ckmin_START (4)
#define REG_BUCK_OTG_TOP_CFG_REG_31_da_otg_ckmin_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_otg_ocp_en : 1;
        unsigned char da_otg_lmos_ocp : 2;
        unsigned char da_otg_lim_set : 2;
        unsigned char da_otg_hmos : 1;
        unsigned char reserved : 1;
        unsigned char da_otg_dmd : 1;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_32_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_32_da_otg_ocp_en_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_32_da_otg_ocp_en_END (0)
#define REG_BUCK_OTG_TOP_CFG_REG_32_da_otg_lmos_ocp_START (1)
#define REG_BUCK_OTG_TOP_CFG_REG_32_da_otg_lmos_ocp_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_32_da_otg_lim_set_START (3)
#define REG_BUCK_OTG_TOP_CFG_REG_32_da_otg_lim_set_END (4)
#define REG_BUCK_OTG_TOP_CFG_REG_32_da_otg_hmos_START (5)
#define REG_BUCK_OTG_TOP_CFG_REG_32_da_otg_hmos_END (5)
#define REG_BUCK_OTG_TOP_CFG_REG_32_da_otg_dmd_START (7)
#define REG_BUCK_OTG_TOP_CFG_REG_32_da_otg_dmd_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_otg_ovp_en : 1;
        unsigned char da_otg_osc_ckmax : 2;
        unsigned char da_otg_osc : 4;
        unsigned char da_otg_ocp_sys : 1;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_33_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_33_da_otg_ovp_en_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_33_da_otg_ovp_en_END (0)
#define REG_BUCK_OTG_TOP_CFG_REG_33_da_otg_osc_ckmax_START (1)
#define REG_BUCK_OTG_TOP_CFG_REG_33_da_otg_osc_ckmax_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_33_da_otg_osc_START (3)
#define REG_BUCK_OTG_TOP_CFG_REG_33_da_otg_osc_END (6)
#define REG_BUCK_OTG_TOP_CFG_REG_33_da_otg_ocp_sys_START (7)
#define REG_BUCK_OTG_TOP_CFG_REG_33_da_otg_ocp_sys_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 1;
        unsigned char da_otg_pfm_v_en : 1;
        unsigned char da_otg_pfm_sel : 1;
        unsigned char da_otg_ovp_sel : 1;
        unsigned char reserved_1 : 4;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_34_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_34_da_otg_pfm_v_en_START (1)
#define REG_BUCK_OTG_TOP_CFG_REG_34_da_otg_pfm_v_en_END (1)
#define REG_BUCK_OTG_TOP_CFG_REG_34_da_otg_pfm_sel_START (2)
#define REG_BUCK_OTG_TOP_CFG_REG_34_da_otg_pfm_sel_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_34_da_otg_ovp_sel_START (3)
#define REG_BUCK_OTG_TOP_CFG_REG_34_da_otg_ovp_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_otg_reserve1 : 8;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_35_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_35_da_otg_reserve1_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_35_da_otg_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_otg_reserve2 : 8;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_36_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_36_da_otg_reserve2_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_36_da_otg_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_otg_slop_set : 2;
        unsigned char da_otg_slop_en : 1;
        unsigned char da_otg_skip_set : 1;
        unsigned char da_otg_scp_time : 1;
        unsigned char da_otg_scp_en : 1;
        unsigned char da_otg_rf : 2;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_37_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_37_da_otg_slop_set_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_37_da_otg_slop_set_END (1)
#define REG_BUCK_OTG_TOP_CFG_REG_37_da_otg_slop_en_START (2)
#define REG_BUCK_OTG_TOP_CFG_REG_37_da_otg_slop_en_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_37_da_otg_skip_set_START (3)
#define REG_BUCK_OTG_TOP_CFG_REG_37_da_otg_skip_set_END (3)
#define REG_BUCK_OTG_TOP_CFG_REG_37_da_otg_scp_time_START (4)
#define REG_BUCK_OTG_TOP_CFG_REG_37_da_otg_scp_time_END (4)
#define REG_BUCK_OTG_TOP_CFG_REG_37_da_otg_scp_en_START (5)
#define REG_BUCK_OTG_TOP_CFG_REG_37_da_otg_scp_en_END (5)
#define REG_BUCK_OTG_TOP_CFG_REG_37_da_otg_rf_START (6)
#define REG_BUCK_OTG_TOP_CFG_REG_37_da_otg_rf_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_otg_vbus : 1;
        unsigned char da_otg_uvp_sel : 2;
        unsigned char da_otg_uvp_en : 1;
        unsigned char da_otg_switch_regnoff : 1;
        unsigned char da_otg_switch : 1;
        unsigned char reserved : 2;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_38_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_38_da_otg_vbus_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_38_da_otg_vbus_END (0)
#define REG_BUCK_OTG_TOP_CFG_REG_38_da_otg_uvp_sel_START (1)
#define REG_BUCK_OTG_TOP_CFG_REG_38_da_otg_uvp_sel_END (2)
#define REG_BUCK_OTG_TOP_CFG_REG_38_da_otg_uvp_en_START (3)
#define REG_BUCK_OTG_TOP_CFG_REG_38_da_otg_uvp_en_END (3)
#define REG_BUCK_OTG_TOP_CFG_REG_38_da_otg_switch_regnoff_START (4)
#define REG_BUCK_OTG_TOP_CFG_REG_38_da_otg_switch_regnoff_END (4)
#define REG_BUCK_OTG_TOP_CFG_REG_38_da_otg_switch_START (5)
#define REG_BUCK_OTG_TOP_CFG_REG_38_da_otg_switch_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_otg_voutcap : 3;
        unsigned char reserved : 5;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_39_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_39_da_otg_voutcap_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_39_da_otg_voutcap_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sns_reserve1 : 8;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_40_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_40_da_sns_reserve1_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_40_da_sns_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sns_reserve2 : 8;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_41_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_41_da_sns_reserve2_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_41_da_sns_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_vsys_h_scp_dis : 1;
        unsigned char reserved : 7;
    } reg;
} REG_BUCK_OTG_TOP_CFG_REG_42_UNION;
#endif
#define REG_BUCK_OTG_TOP_CFG_REG_42_da_vsys_h_scp_dis_START (0)
#define REG_BUCK_OTG_TOP_CFG_REG_42_da_vsys_h_scp_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_buck_ok : 1;
        unsigned char reserved : 7;
    } reg;
} REG_BUCK_OTG_TOP_RO_REG_43_UNION;
#endif
#define REG_BUCK_OTG_TOP_RO_REG_43_ad_buck_ok_START (0)
#define REG_BUCK_OTG_TOP_RO_REG_43_ad_buck_ok_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_buck_state0 : 8;
    } reg;
} REG_BUCK_OTG_TOP_RO_REG_44_UNION;
#endif
#define REG_BUCK_OTG_TOP_RO_REG_44_ad_buck_state0_START (0)
#define REG_BUCK_OTG_TOP_RO_REG_44_ad_buck_state0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_buck_state1 : 8;
    } reg;
} REG_BUCK_OTG_TOP_RO_REG_45_UNION;
#endif
#define REG_BUCK_OTG_TOP_RO_REG_45_ad_buck_state1_START (0)
#define REG_BUCK_OTG_TOP_RO_REG_45_ad_buck_state1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_buck_state2 : 8;
    } reg;
} REG_BUCK_OTG_TOP_RO_REG_46_UNION;
#endif
#define REG_BUCK_OTG_TOP_RO_REG_46_ad_buck_state2_START (0)
#define REG_BUCK_OTG_TOP_RO_REG_46_ad_buck_state2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_otg_on : 1;
        unsigned char ad_otg_en_in : 1;
        unsigned char ad_otg_dmd_plus_ro : 1;
        unsigned char reserved : 5;
    } reg;
} REG_BUCK_OTG_TOP_RO_REG_47_UNION;
#endif
#define REG_BUCK_OTG_TOP_RO_REG_47_ad_otg_on_START (0)
#define REG_BUCK_OTG_TOP_RO_REG_47_ad_otg_on_END (0)
#define REG_BUCK_OTG_TOP_RO_REG_47_ad_otg_en_in_START (1)
#define REG_BUCK_OTG_TOP_RO_REG_47_ad_otg_en_in_END (1)
#define REG_BUCK_OTG_TOP_RO_REG_47_ad_otg_dmd_plus_ro_START (2)
#define REG_BUCK_OTG_TOP_RO_REG_47_ad_otg_dmd_plus_ro_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_otg_state0 : 8;
    } reg;
} REG_BUCK_OTG_TOP_RO_REG_48_UNION;
#endif
#define REG_BUCK_OTG_TOP_RO_REG_48_ad_otg_state0_START (0)
#define REG_BUCK_OTG_TOP_RO_REG_48_ad_otg_state0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_usb_ovp_pro_en : 1;
        unsigned char da_usb_ovp_ichg_sel : 2;
        unsigned char da_usb_ovp_dt_sel : 1;
        unsigned char da_usb_ovp_alm_en : 1;
        unsigned char reserved : 3;
    } reg;
} REG_USB_OVP_CFG_REG_0_UNION;
#endif
#define REG_USB_OVP_CFG_REG_0_da_usb_ovp_pro_en_START (0)
#define REG_USB_OVP_CFG_REG_0_da_usb_ovp_pro_en_END (0)
#define REG_USB_OVP_CFG_REG_0_da_usb_ovp_ichg_sel_START (1)
#define REG_USB_OVP_CFG_REG_0_da_usb_ovp_ichg_sel_END (2)
#define REG_USB_OVP_CFG_REG_0_da_usb_ovp_dt_sel_START (3)
#define REG_USB_OVP_CFG_REG_0_da_usb_ovp_dt_sel_END (3)
#define REG_USB_OVP_CFG_REG_0_da_usb_ovp_alm_en_START (4)
#define REG_USB_OVP_CFG_REG_0_da_usb_ovp_alm_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_usb_ovp_resved : 8;
    } reg;
} REG_USB_OVP_CFG_REG_1_UNION;
#endif
#define REG_USB_OVP_CFG_REG_1_da_usb_ovp_resved_START (0)
#define REG_USB_OVP_CFG_REG_1_da_usb_ovp_resved_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_usb_uvlo_en : 1;
        unsigned char da_usb_plugout_en : 1;
        unsigned char da_usb_plugin_en : 1;
        unsigned char da_usb_ovpsub_pd_enb : 1;
        unsigned char da_usb_ovp_shdn_dt_sel : 1;
        unsigned char da_usb_ovp_set : 3;
    } reg;
} REG_USB_OVP_CFG_REG_2_UNION;
#endif
#define REG_USB_OVP_CFG_REG_2_da_usb_uvlo_en_START (0)
#define REG_USB_OVP_CFG_REG_2_da_usb_uvlo_en_END (0)
#define REG_USB_OVP_CFG_REG_2_da_usb_plugout_en_START (1)
#define REG_USB_OVP_CFG_REG_2_da_usb_plugout_en_END (1)
#define REG_USB_OVP_CFG_REG_2_da_usb_plugin_en_START (2)
#define REG_USB_OVP_CFG_REG_2_da_usb_plugin_en_END (2)
#define REG_USB_OVP_CFG_REG_2_da_usb_ovpsub_pd_enb_START (3)
#define REG_USB_OVP_CFG_REG_2_da_usb_ovpsub_pd_enb_END (3)
#define REG_USB_OVP_CFG_REG_2_da_usb_ovp_shdn_dt_sel_START (4)
#define REG_USB_OVP_CFG_REG_2_da_usb_ovp_shdn_dt_sel_END (4)
#define REG_USB_OVP_CFG_REG_2_da_usb_ovp_set_START (5)
#define REG_USB_OVP_CFG_REG_2_da_usb_ovp_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_ovp_reserve0 : 8;
    } reg;
} REG_USB_OVP_CFG_REG_3_UNION;
#endif
#define REG_USB_OVP_CFG_REG_3_da_ovp_reserve0_START (0)
#define REG_USB_OVP_CFG_REG_3_da_ovp_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_ovp_reserve1 : 8;
    } reg;
} REG_USB_OVP_CFG_REG_4_UNION;
#endif
#define REG_USB_OVP_CFG_REG_4_da_ovp_reserve1_START (0)
#define REG_USB_OVP_CFG_REG_4_da_ovp_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_psw_ovp_pro_en : 1;
        unsigned char da_psw_ovp_ichg_sel : 2;
        unsigned char da_psw_ovp_en : 1;
        unsigned char da_psw_ovp_dt_sel : 1;
        unsigned char da_psw_ovp_alm_en : 1;
        unsigned char reserved : 2;
    } reg;
} REG_PSW_OVP_CFG_REG_0_UNION;
#endif
#define REG_PSW_OVP_CFG_REG_0_da_psw_ovp_pro_en_START (0)
#define REG_PSW_OVP_CFG_REG_0_da_psw_ovp_pro_en_END (0)
#define REG_PSW_OVP_CFG_REG_0_da_psw_ovp_ichg_sel_START (1)
#define REG_PSW_OVP_CFG_REG_0_da_psw_ovp_ichg_sel_END (2)
#define REG_PSW_OVP_CFG_REG_0_da_psw_ovp_en_START (3)
#define REG_PSW_OVP_CFG_REG_0_da_psw_ovp_en_END (3)
#define REG_PSW_OVP_CFG_REG_0_da_psw_ovp_dt_sel_START (4)
#define REG_PSW_OVP_CFG_REG_0_da_psw_ovp_dt_sel_END (4)
#define REG_PSW_OVP_CFG_REG_0_da_psw_ovp_alm_en_START (5)
#define REG_PSW_OVP_CFG_REG_0_da_psw_ovp_alm_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_psw_ovp_resved : 8;
    } reg;
} REG_PSW_OVP_CFG_REG_1_UNION;
#endif
#define REG_PSW_OVP_CFG_REG_1_da_psw_ovp_resved_START (0)
#define REG_PSW_OVP_CFG_REG_1_da_psw_ovp_resved_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_psw_uvlo_en : 1;
        unsigned char da_psw_plugout_en : 1;
        unsigned char da_psw_plugin_en : 1;
        unsigned char da_psw_ovpsub_pd_enb : 1;
        unsigned char da_psw_ovp_shdn_dt_sel : 1;
        unsigned char da_psw_ovp_set : 3;
    } reg;
} REG_PSW_OVP_CFG_REG_2_UNION;
#endif
#define REG_PSW_OVP_CFG_REG_2_da_psw_uvlo_en_START (0)
#define REG_PSW_OVP_CFG_REG_2_da_psw_uvlo_en_END (0)
#define REG_PSW_OVP_CFG_REG_2_da_psw_plugout_en_START (1)
#define REG_PSW_OVP_CFG_REG_2_da_psw_plugout_en_END (1)
#define REG_PSW_OVP_CFG_REG_2_da_psw_plugin_en_START (2)
#define REG_PSW_OVP_CFG_REG_2_da_psw_plugin_en_END (2)
#define REG_PSW_OVP_CFG_REG_2_da_psw_ovpsub_pd_enb_START (3)
#define REG_PSW_OVP_CFG_REG_2_da_psw_ovpsub_pd_enb_END (3)
#define REG_PSW_OVP_CFG_REG_2_da_psw_ovp_shdn_dt_sel_START (4)
#define REG_PSW_OVP_CFG_REG_2_da_psw_ovp_shdn_dt_sel_END (4)
#define REG_PSW_OVP_CFG_REG_2_da_psw_ovp_set_START (5)
#define REG_PSW_OVP_CFG_REG_2_da_psw_ovp_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_drv_weak_hs_sel : 2;
        unsigned char da_sc_drv_pwm_weak_sel : 2;
        unsigned char da_sc_cp_freq_sel : 1;
        unsigned char da_sc_cfly_pd_mask : 1;
        unsigned char da_sc_block_weak_st_sel : 2;
    } reg;
} REG_SC_TOP_CFG_REG_0_UNION;
#endif
#define REG_SC_TOP_CFG_REG_0_da_sc_drv_weak_hs_sel_START (0)
#define REG_SC_TOP_CFG_REG_0_da_sc_drv_weak_hs_sel_END (1)
#define REG_SC_TOP_CFG_REG_0_da_sc_drv_pwm_weak_sel_START (2)
#define REG_SC_TOP_CFG_REG_0_da_sc_drv_pwm_weak_sel_END (3)
#define REG_SC_TOP_CFG_REG_0_da_sc_cp_freq_sel_START (4)
#define REG_SC_TOP_CFG_REG_0_da_sc_cp_freq_sel_END (4)
#define REG_SC_TOP_CFG_REG_0_da_sc_cfly_pd_mask_START (5)
#define REG_SC_TOP_CFG_REG_0_da_sc_cfly_pd_mask_END (5)
#define REG_SC_TOP_CFG_REG_0_da_sc_block_weak_st_sel_START (6)
#define REG_SC_TOP_CFG_REG_0_da_sc_block_weak_st_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_drvq10r : 3;
        unsigned char da_sc_drvq10f : 3;
        unsigned char da_sc_drv_weak_ls_sel : 2;
    } reg;
} REG_SC_TOP_CFG_REG_1_UNION;
#endif
#define REG_SC_TOP_CFG_REG_1_da_sc_drvq10r_START (0)
#define REG_SC_TOP_CFG_REG_1_da_sc_drvq10r_END (2)
#define REG_SC_TOP_CFG_REG_1_da_sc_drvq10f_START (3)
#define REG_SC_TOP_CFG_REG_1_da_sc_drvq10f_END (5)
#define REG_SC_TOP_CFG_REG_1_da_sc_drv_weak_ls_sel_START (6)
#define REG_SC_TOP_CFG_REG_1_da_sc_drv_weak_ls_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_drvq1r : 3;
        unsigned char da_sc_drvq1f : 3;
        unsigned char reserved : 2;
    } reg;
} REG_SC_TOP_CFG_REG_2_UNION;
#endif
#define REG_SC_TOP_CFG_REG_2_da_sc_drvq1r_START (0)
#define REG_SC_TOP_CFG_REG_2_da_sc_drvq1r_END (2)
#define REG_SC_TOP_CFG_REG_2_da_sc_drvq1f_START (3)
#define REG_SC_TOP_CFG_REG_2_da_sc_drvq1f_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_drvq2r : 3;
        unsigned char da_sc_drvq2f : 3;
        unsigned char reserved : 2;
    } reg;
} REG_SC_TOP_CFG_REG_3_UNION;
#endif
#define REG_SC_TOP_CFG_REG_3_da_sc_drvq2r_START (0)
#define REG_SC_TOP_CFG_REG_3_da_sc_drvq2r_END (2)
#define REG_SC_TOP_CFG_REG_3_da_sc_drvq2f_START (3)
#define REG_SC_TOP_CFG_REG_3_da_sc_drvq2f_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_drvq3r : 3;
        unsigned char da_sc_drvq3f : 3;
        unsigned char reserved : 2;
    } reg;
} REG_SC_TOP_CFG_REG_4_UNION;
#endif
#define REG_SC_TOP_CFG_REG_4_da_sc_drvq3r_START (0)
#define REG_SC_TOP_CFG_REG_4_da_sc_drvq3r_END (2)
#define REG_SC_TOP_CFG_REG_4_da_sc_drvq3f_START (3)
#define REG_SC_TOP_CFG_REG_4_da_sc_drvq3f_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_drvq4r : 3;
        unsigned char da_sc_drvq4f : 3;
        unsigned char reserved : 2;
    } reg;
} REG_SC_TOP_CFG_REG_5_UNION;
#endif
#define REG_SC_TOP_CFG_REG_5_da_sc_drvq4r_START (0)
#define REG_SC_TOP_CFG_REG_5_da_sc_drvq4r_END (2)
#define REG_SC_TOP_CFG_REG_5_da_sc_drvq4f_START (3)
#define REG_SC_TOP_CFG_REG_5_da_sc_drvq4f_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_drvq5r : 3;
        unsigned char da_sc_drvq5f : 3;
        unsigned char reserved : 2;
    } reg;
} REG_SC_TOP_CFG_REG_6_UNION;
#endif
#define REG_SC_TOP_CFG_REG_6_da_sc_drvq5r_START (0)
#define REG_SC_TOP_CFG_REG_6_da_sc_drvq5r_END (2)
#define REG_SC_TOP_CFG_REG_6_da_sc_drvq5f_START (3)
#define REG_SC_TOP_CFG_REG_6_da_sc_drvq5f_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_drvq6r : 3;
        unsigned char da_sc_drvq6f : 3;
        unsigned char reserved : 2;
    } reg;
} REG_SC_TOP_CFG_REG_7_UNION;
#endif
#define REG_SC_TOP_CFG_REG_7_da_sc_drvq6r_START (0)
#define REG_SC_TOP_CFG_REG_7_da_sc_drvq6r_END (2)
#define REG_SC_TOP_CFG_REG_7_da_sc_drvq6f_START (3)
#define REG_SC_TOP_CFG_REG_7_da_sc_drvq6f_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_drvq7r : 3;
        unsigned char da_sc_drvq7f : 3;
        unsigned char reserved : 2;
    } reg;
} REG_SC_TOP_CFG_REG_8_UNION;
#endif
#define REG_SC_TOP_CFG_REG_8_da_sc_drvq7r_START (0)
#define REG_SC_TOP_CFG_REG_8_da_sc_drvq7r_END (2)
#define REG_SC_TOP_CFG_REG_8_da_sc_drvq7f_START (3)
#define REG_SC_TOP_CFG_REG_8_da_sc_drvq7f_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_drvq8r : 3;
        unsigned char da_sc_drvq8f : 3;
        unsigned char reserved : 2;
    } reg;
} REG_SC_TOP_CFG_REG_9_UNION;
#endif
#define REG_SC_TOP_CFG_REG_9_da_sc_drvq8r_START (0)
#define REG_SC_TOP_CFG_REG_9_da_sc_drvq8r_END (2)
#define REG_SC_TOP_CFG_REG_9_da_sc_drvq8f_START (3)
#define REG_SC_TOP_CFG_REG_9_da_sc_drvq8f_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_fd_en_delay_sel : 1;
        unsigned char da_sc_drvq9r : 3;
        unsigned char da_sc_drvq9f : 3;
        unsigned char reserved : 1;
    } reg;
} REG_SC_TOP_CFG_REG_10_UNION;
#endif
#define REG_SC_TOP_CFG_REG_10_da_sc_fd_en_delay_sel_START (0)
#define REG_SC_TOP_CFG_REG_10_da_sc_fd_en_delay_sel_END (0)
#define REG_SC_TOP_CFG_REG_10_da_sc_drvq9r_START (1)
#define REG_SC_TOP_CFG_REG_10_da_sc_drvq9r_END (3)
#define REG_SC_TOP_CFG_REG_10_da_sc_drvq9f_START (4)
#define REG_SC_TOP_CFG_REG_10_da_sc_drvq9f_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_ls_fd_sel : 2;
        unsigned char da_sc_hs_fd_sel : 2;
        unsigned char da_sc_freq_sel : 3;
        unsigned char reserved : 1;
    } reg;
} REG_SC_TOP_CFG_REG_11_UNION;
#endif
#define REG_SC_TOP_CFG_REG_11_da_sc_ls_fd_sel_START (0)
#define REG_SC_TOP_CFG_REG_11_da_sc_ls_fd_sel_END (1)
#define REG_SC_TOP_CFG_REG_11_da_sc_hs_fd_sel_START (2)
#define REG_SC_TOP_CFG_REG_11_da_sc_hs_fd_sel_END (3)
#define REG_SC_TOP_CFG_REG_11_da_sc_freq_sel_START (4)
#define REG_SC_TOP_CFG_REG_11_da_sc_freq_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_pwr_ts : 2;
        unsigned char reserved : 2;
        unsigned char da_sc_lvc_bstchg_sel : 2;
        unsigned char da_sc_lvc_bst_res : 2;
    } reg;
} REG_SC_TOP_CFG_REG_12_UNION;
#endif
#define REG_SC_TOP_CFG_REG_12_da_sc_pwr_ts_START (0)
#define REG_SC_TOP_CFG_REG_12_da_sc_pwr_ts_END (1)
#define REG_SC_TOP_CFG_REG_12_da_sc_lvc_bstchg_sel_START (4)
#define REG_SC_TOP_CFG_REG_12_da_sc_lvc_bstchg_sel_END (5)
#define REG_SC_TOP_CFG_REG_12_da_sc_lvc_bst_res_START (6)
#define REG_SC_TOP_CFG_REG_12_da_sc_lvc_bst_res_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_reserve0 : 8;
    } reg;
} REG_SC_TOP_CFG_REG_13_UNION;
#endif
#define REG_SC_TOP_CFG_REG_13_da_sc_reserve0_START (0)
#define REG_SC_TOP_CFG_REG_13_da_sc_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_reserve1 : 8;
    } reg;
} REG_SC_TOP_CFG_REG_14_UNION;
#endif
#define REG_SC_TOP_CFG_REG_14_da_sc_reserve1_START (0)
#define REG_SC_TOP_CFG_REG_14_da_sc_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_reserve2 : 8;
    } reg;
} REG_SC_TOP_CFG_REG_15_UNION;
#endif
#define REG_SC_TOP_CFG_REG_15_da_sc_reserve2_START (0)
#define REG_SC_TOP_CFG_REG_15_da_sc_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_ts_muxsela : 3;
        unsigned char da_sc_ts_mod : 1;
        unsigned char da_sc_sscmp2_tsmod : 1;
        unsigned char da_sc_sscmp1_tsmod : 1;
        unsigned char reserved : 2;
    } reg;
} REG_SC_TOP_CFG_REG_16_UNION;
#endif
#define REG_SC_TOP_CFG_REG_16_da_sc_ts_muxsela_START (0)
#define REG_SC_TOP_CFG_REG_16_da_sc_ts_muxsela_END (2)
#define REG_SC_TOP_CFG_REG_16_da_sc_ts_mod_START (3)
#define REG_SC_TOP_CFG_REG_16_da_sc_ts_mod_END (3)
#define REG_SC_TOP_CFG_REG_16_da_sc_sscmp2_tsmod_START (4)
#define REG_SC_TOP_CFG_REG_16_da_sc_sscmp2_tsmod_END (4)
#define REG_SC_TOP_CFG_REG_16_da_sc_sscmp1_tsmod_START (5)
#define REG_SC_TOP_CFG_REG_16_da_sc_sscmp1_tsmod_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_load_sel : 2;
        unsigned char sc_load_en : 1;
        unsigned char da_sc_ts_pathb : 1;
        unsigned char da_sc_ts_patha : 1;
        unsigned char da_sc_ts_muxselb : 3;
    } reg;
} REG_SC_TOP_CFG_REG_17_UNION;
#endif
#define REG_SC_TOP_CFG_REG_17_sc_load_sel_START (0)
#define REG_SC_TOP_CFG_REG_17_sc_load_sel_END (1)
#define REG_SC_TOP_CFG_REG_17_sc_load_en_START (2)
#define REG_SC_TOP_CFG_REG_17_sc_load_en_END (2)
#define REG_SC_TOP_CFG_REG_17_da_sc_ts_pathb_START (3)
#define REG_SC_TOP_CFG_REG_17_da_sc_ts_pathb_END (3)
#define REG_SC_TOP_CFG_REG_17_da_sc_ts_patha_START (4)
#define REG_SC_TOP_CFG_REG_17_da_sc_ts_patha_END (4)
#define REG_SC_TOP_CFG_REG_17_da_sc_ts_muxselb_START (5)
#define REG_SC_TOP_CFG_REG_17_da_sc_ts_muxselb_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_shaking_en : 1;
        unsigned char sc_parallel_en : 1;
        unsigned char reserved : 6;
    } reg;
} REG_SC_TOP_CFG_REG_18_UNION;
#endif
#define REG_SC_TOP_CFG_REG_18_sc_shaking_en_START (0)
#define REG_SC_TOP_CFG_REG_18_sc_shaking_en_END (0)
#define REG_SC_TOP_CFG_REG_18_sc_parallel_en_START (1)
#define REG_SC_TOP_CFG_REG_18_sc_parallel_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_psel_ref_set : 2;
        unsigned char da_psel_ocp_shield : 1;
        unsigned char da_psel_ldo3p3_tsmod : 1;
        unsigned char da_psel_force_off : 1;
        unsigned char da_psel_cp_en : 1;
        unsigned char da_ldo1p8_d_vset : 2;
    } reg;
} REG_PSEL_CFG_REG_0_UNION;
#endif
#define REG_PSEL_CFG_REG_0_da_psel_ref_set_START (0)
#define REG_PSEL_CFG_REG_0_da_psel_ref_set_END (1)
#define REG_PSEL_CFG_REG_0_da_psel_ocp_shield_START (2)
#define REG_PSEL_CFG_REG_0_da_psel_ocp_shield_END (2)
#define REG_PSEL_CFG_REG_0_da_psel_ldo3p3_tsmod_START (3)
#define REG_PSEL_CFG_REG_0_da_psel_ldo3p3_tsmod_END (3)
#define REG_PSEL_CFG_REG_0_da_psel_force_off_START (4)
#define REG_PSEL_CFG_REG_0_da_psel_force_off_END (4)
#define REG_PSEL_CFG_REG_0_da_psel_cp_en_START (5)
#define REG_PSEL_CFG_REG_0_da_psel_cp_en_END (5)
#define REG_PSEL_CFG_REG_0_da_ldo1p8_d_vset_START (6)
#define REG_PSEL_CFG_REG_0_da_ldo1p8_d_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_psel_regn_vset : 2;
        unsigned char reserved : 6;
    } reg;
} REG_PSEL_CFG_REG_1_UNION;
#endif
#define REG_PSEL_CFG_REG_1_da_psel_regn_vset_START (0)
#define REG_PSEL_CFG_REG_1_da_psel_regn_vset_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_psel_reserved : 8;
    } reg;
} REG_PSEL_CFG_REG_2_UNION;
#endif
#define REG_PSEL_CFG_REG_2_da_psel_reserved_START (0)
#define REG_PSEL_CFG_REG_2_da_psel_reserved_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_regn_ocp_irq_shield : 2;
        unsigned char reserved : 6;
    } reg;
} REG_PSEL_CFG_REG_3_UNION;
#endif
#define REG_PSEL_CFG_REG_3_da_regn_ocp_irq_shield_START (0)
#define REG_PSEL_CFG_REG_3_da_regn_ocp_irq_shield_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_ldo1p8_a_ocp : 1;
        unsigned char reserved : 7;
    } reg;
} REG_PSEL_RO_REG_4_UNION;
#endif
#define REG_PSEL_RO_REG_4_ad_ldo1p8_a_ocp_START (0)
#define REG_PSEL_RO_REG_4_ad_ldo1p8_a_ocp_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_hkadc_ibias_sel : 8;
    } reg;
} REG_HKADC_CFG_REG_1_UNION;
#endif
#define REG_HKADC_CFG_REG_1_da_hkadc_ibias_sel_START (0)
#define REG_HKADC_CFG_REG_1_da_hkadc_ibias_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_hkadc_reserved : 8;
    } reg;
} REG_HKADC_CFG_REG_2_UNION;
#endif
#define REG_HKADC_CFG_REG_2_da_hkadc_reserved_START (0)
#define REG_HKADC_CFG_REG_2_da_hkadc_reserved_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_hkadc_reset : 1;
        unsigned char hkadc_buffer_sel : 1;
        unsigned char reserved : 6;
    } reg;
} REG_HKADC_CFG_REG_3_UNION;
#endif
#define REG_HKADC_CFG_REG_3_da_hkadc_reset_START (0)
#define REG_HKADC_CFG_REG_3_da_hkadc_reset_END (0)
#define REG_HKADC_CFG_REG_3_hkadc_buffer_sel_START (1)
#define REG_HKADC_CFG_REG_3_hkadc_buffer_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_buck_vbus_plugout_en : 1;
        unsigned char da_buck_vbus_plugin_en : 1;
        unsigned char da_buck_vbus_ovp_en : 1;
        unsigned char da_buck_vbat_ovp_en : 1;
        unsigned char da_bat_gd_shield : 1;
        unsigned char da_bat_gd_sel : 1;
        unsigned char da_adc_det_sel : 1;
        unsigned char da_adc_det_psechop_en : 1;
    } reg;
} REG_SYS_DET_CFG_REG_0_UNION;
#endif
#define REG_SYS_DET_CFG_REG_0_da_buck_vbus_plugout_en_START (0)
#define REG_SYS_DET_CFG_REG_0_da_buck_vbus_plugout_en_END (0)
#define REG_SYS_DET_CFG_REG_0_da_buck_vbus_plugin_en_START (1)
#define REG_SYS_DET_CFG_REG_0_da_buck_vbus_plugin_en_END (1)
#define REG_SYS_DET_CFG_REG_0_da_buck_vbus_ovp_en_START (2)
#define REG_SYS_DET_CFG_REG_0_da_buck_vbus_ovp_en_END (2)
#define REG_SYS_DET_CFG_REG_0_da_buck_vbat_ovp_en_START (3)
#define REG_SYS_DET_CFG_REG_0_da_buck_vbat_ovp_en_END (3)
#define REG_SYS_DET_CFG_REG_0_da_bat_gd_shield_START (4)
#define REG_SYS_DET_CFG_REG_0_da_bat_gd_shield_END (4)
#define REG_SYS_DET_CFG_REG_0_da_bat_gd_sel_START (5)
#define REG_SYS_DET_CFG_REG_0_da_bat_gd_sel_END (5)
#define REG_SYS_DET_CFG_REG_0_da_adc_det_sel_START (6)
#define REG_SYS_DET_CFG_REG_0_da_adc_det_sel_END (6)
#define REG_SYS_DET_CFG_REG_0_da_adc_det_psechop_en_START (7)
#define REG_SYS_DET_CFG_REG_0_da_adc_det_psechop_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_psw_dropmin_set : 2;
        unsigned char da_sc_psw_dropmin_en : 1;
        unsigned char da_sc_psw_dropmin_dbt : 1;
        unsigned char da_psw_slp_vset : 1;
        unsigned char da_psw_sleep_block : 1;
        unsigned char da_buck_vbus_uvp_en : 1;
        unsigned char da_buck_vbus_uvlo_en : 1;
    } reg;
} REG_SYS_DET_CFG_REG_1_UNION;
#endif
#define REG_SYS_DET_CFG_REG_1_da_sc_psw_dropmin_set_START (0)
#define REG_SYS_DET_CFG_REG_1_da_sc_psw_dropmin_set_END (1)
#define REG_SYS_DET_CFG_REG_1_da_sc_psw_dropmin_en_START (2)
#define REG_SYS_DET_CFG_REG_1_da_sc_psw_dropmin_en_END (2)
#define REG_SYS_DET_CFG_REG_1_da_sc_psw_dropmin_dbt_START (3)
#define REG_SYS_DET_CFG_REG_1_da_sc_psw_dropmin_dbt_END (3)
#define REG_SYS_DET_CFG_REG_1_da_psw_slp_vset_START (4)
#define REG_SYS_DET_CFG_REG_1_da_psw_slp_vset_END (4)
#define REG_SYS_DET_CFG_REG_1_da_psw_sleep_block_START (5)
#define REG_SYS_DET_CFG_REG_1_da_psw_sleep_block_END (5)
#define REG_SYS_DET_CFG_REG_1_da_buck_vbus_uvp_en_START (6)
#define REG_SYS_DET_CFG_REG_1_da_buck_vbus_uvp_en_END (6)
#define REG_SYS_DET_CFG_REG_1_da_buck_vbus_uvlo_en_START (7)
#define REG_SYS_DET_CFG_REG_1_da_buck_vbus_uvlo_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_vbat_ovp_en : 1;
        unsigned char da_sc_vbat_ovp_dbt : 1;
        unsigned char da_sc_usb_dropmin_set : 2;
        unsigned char da_sc_usb_dropmin_en : 1;
        unsigned char da_sc_usb_dropmin_dbt : 1;
        unsigned char reserved : 2;
    } reg;
} REG_SYS_DET_CFG_REG_2_UNION;
#endif
#define REG_SYS_DET_CFG_REG_2_da_sc_vbat_ovp_en_START (0)
#define REG_SYS_DET_CFG_REG_2_da_sc_vbat_ovp_en_END (0)
#define REG_SYS_DET_CFG_REG_2_da_sc_vbat_ovp_dbt_START (1)
#define REG_SYS_DET_CFG_REG_2_da_sc_vbat_ovp_dbt_END (1)
#define REG_SYS_DET_CFG_REG_2_da_sc_usb_dropmin_set_START (2)
#define REG_SYS_DET_CFG_REG_2_da_sc_usb_dropmin_set_END (3)
#define REG_SYS_DET_CFG_REG_2_da_sc_usb_dropmin_en_START (4)
#define REG_SYS_DET_CFG_REG_2_da_sc_usb_dropmin_en_END (4)
#define REG_SYS_DET_CFG_REG_2_da_sc_usb_dropmin_dbt_START (5)
#define REG_SYS_DET_CFG_REG_2_da_sc_usb_dropmin_dbt_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_vbat_ovp_set : 3;
        unsigned char reserved : 5;
    } reg;
} REG_SYS_DET_CFG_REG_3_UNION;
#endif
#define REG_SYS_DET_CFG_REG_3_da_sc_vbat_ovp_set_START (0)
#define REG_SYS_DET_CFG_REG_3_da_sc_vbat_ovp_set_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sys_det_reserve : 8;
    } reg;
} REG_SYS_DET_CFG_REG_4_UNION;
#endif
#define REG_SYS_DET_CFG_REG_4_da_sys_det_reserve_START (0)
#define REG_SYS_DET_CFG_REG_4_da_sys_det_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sys_det_reserve1 : 8;
    } reg;
} REG_SYS_DET_CFG_REG_5_UNION;
#endif
#define REG_SYS_DET_CFG_REG_5_da_sys_det_reserve1_START (0)
#define REG_SYS_DET_CFG_REG_5_da_sys_det_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_vbus_uv_bk : 1;
        unsigned char da_vbus_ov_bk : 1;
        unsigned char reserved_0 : 1;
        unsigned char da_vbat_lv_t : 1;
        unsigned char da_usb_slp_vset : 1;
        unsigned char da_usb_sleep_block : 1;
        unsigned char reserved_1 : 2;
    } reg;
} REG_SYS_DET_CFG_REG_6_UNION;
#endif
#define REG_SYS_DET_CFG_REG_6_da_vbus_uv_bk_START (0)
#define REG_SYS_DET_CFG_REG_6_da_vbus_uv_bk_END (0)
#define REG_SYS_DET_CFG_REG_6_da_vbus_ov_bk_START (1)
#define REG_SYS_DET_CFG_REG_6_da_vbus_ov_bk_END (1)
#define REG_SYS_DET_CFG_REG_6_da_vbat_lv_t_START (3)
#define REG_SYS_DET_CFG_REG_6_da_vbat_lv_t_END (3)
#define REG_SYS_DET_CFG_REG_6_da_usb_slp_vset_START (4)
#define REG_SYS_DET_CFG_REG_6_da_usb_slp_vset_END (4)
#define REG_SYS_DET_CFG_REG_6_da_usb_sleep_block_START (5)
#define REG_SYS_DET_CFG_REG_6_da_usb_sleep_block_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_ufcs_plugout_en : 1;
        unsigned char da_ufcs_dpdm_ovp_en : 1;
        unsigned char reserved : 6;
    } reg;
} REG_SYS_DET_CFG_REG_7_UNION;
#endif
#define REG_SYS_DET_CFG_REG_7_da_ufcs_plugout_en_START (0)
#define REG_SYS_DET_CFG_REG_7_da_ufcs_plugout_en_END (0)
#define REG_SYS_DET_CFG_REG_7_da_ufcs_dpdm_ovp_en_START (1)
#define REG_SYS_DET_CFG_REG_7_da_ufcs_dpdm_ovp_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_sys_det_reserve : 8;
    } reg;
} REG_SYS_DET_RO_REG_8_UNION;
#endif
#define REG_SYS_DET_RO_REG_8_ad_sys_det_reserve_START (0)
#define REG_SYS_DET_RO_REG_8_ad_sys_det_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sys_test_resvo0 : 8;
    } reg;
} REG_SYS_LOGIC_CFG_REG_0_UNION;
#endif
#define REG_SYS_LOGIC_CFG_REG_0_da_sys_test_resvo0_START (0)
#define REG_SYS_LOGIC_CFG_REG_0_da_sys_test_resvo0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sys_test_resvo1 : 8;
    } reg;
} REG_SYS_LOGIC_CFG_REG_2_UNION;
#endif
#define REG_SYS_LOGIC_CFG_REG_2_da_sys_test_resvo1_START (0)
#define REG_SYS_LOGIC_CFG_REG_2_da_sys_test_resvo1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 1;
        unsigned char da_eis_sc_sw_trigger : 1;
        unsigned char da_eis_sc_sw_tot : 4;
        unsigned char da_eis_sc_sw_mode : 1;
        unsigned char reserved_1 : 1;
    } reg;
} REG_SYS_LOGIC_CFG_REG_3_UNION;
#endif
#define REG_SYS_LOGIC_CFG_REG_3_da_eis_sc_sw_trigger_START (1)
#define REG_SYS_LOGIC_CFG_REG_3_da_eis_sc_sw_trigger_END (1)
#define REG_SYS_LOGIC_CFG_REG_3_da_eis_sc_sw_tot_START (2)
#define REG_SYS_LOGIC_CFG_REG_3_da_eis_sc_sw_tot_END (5)
#define REG_SYS_LOGIC_CFG_REG_3_da_eis_sc_sw_mode_START (6)
#define REG_SYS_LOGIC_CFG_REG_3_da_eis_sc_sw_mode_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_ldo33_en : 1;
        unsigned char da_ldo18a_en : 1;
        unsigned char da_ibat_sw_en : 1;
        unsigned char da_ibat_sw : 3;
        unsigned char da_frs_hiz : 1;
        unsigned char da_fr_swap_en_mask : 1;
    } reg;
} REG_SYS_LOGIC_CFG_REG_4_UNION;
#endif
#define REG_SYS_LOGIC_CFG_REG_4_da_ldo33_en_START (0)
#define REG_SYS_LOGIC_CFG_REG_4_da_ldo33_en_END (0)
#define REG_SYS_LOGIC_CFG_REG_4_da_ldo18a_en_START (1)
#define REG_SYS_LOGIC_CFG_REG_4_da_ldo18a_en_END (1)
#define REG_SYS_LOGIC_CFG_REG_4_da_ibat_sw_en_START (2)
#define REG_SYS_LOGIC_CFG_REG_4_da_ibat_sw_en_END (2)
#define REG_SYS_LOGIC_CFG_REG_4_da_ibat_sw_START (3)
#define REG_SYS_LOGIC_CFG_REG_4_da_ibat_sw_END (5)
#define REG_SYS_LOGIC_CFG_REG_4_da_frs_hiz_START (6)
#define REG_SYS_LOGIC_CFG_REG_4_da_frs_hiz_END (6)
#define REG_SYS_LOGIC_CFG_REG_4_da_fr_swap_en_mask_START (7)
#define REG_SYS_LOGIC_CFG_REG_4_da_fr_swap_en_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 1;
        unsigned char da_otg_delay_sel : 2;
        unsigned char da_otg_chg_regnok : 1;
        unsigned char da_osc_test_sel : 3;
        unsigned char reserved_1 : 1;
    } reg;
} REG_SYS_LOGIC_CFG_REG_5_UNION;
#endif
#define REG_SYS_LOGIC_CFG_REG_5_da_otg_delay_sel_START (1)
#define REG_SYS_LOGIC_CFG_REG_5_da_otg_delay_sel_END (2)
#define REG_SYS_LOGIC_CFG_REG_5_da_otg_chg_regnok_START (3)
#define REG_SYS_LOGIC_CFG_REG_5_da_otg_chg_regnok_END (3)
#define REG_SYS_LOGIC_CFG_REG_5_da_osc_test_sel_START (4)
#define REG_SYS_LOGIC_CFG_REG_5_da_osc_test_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sys_resvo0 : 8;
    } reg;
} REG_SYS_LOGIC_CFG_REG_6_UNION;
#endif
#define REG_SYS_LOGIC_CFG_REG_6_da_sys_resvo0_START (0)
#define REG_SYS_LOGIC_CFG_REG_6_da_sys_resvo0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sys_resvo1 : 8;
    } reg;
} REG_SYS_LOGIC_CFG_REG_7_UNION;
#endif
#define REG_SYS_LOGIC_CFG_REG_7_da_sys_resvo1_START (0)
#define REG_SYS_LOGIC_CFG_REG_7_da_sys_resvo1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sys_resvo2 : 8;
    } reg;
} REG_SYS_LOGIC_CFG_REG_8_UNION;
#endif
#define REG_SYS_LOGIC_CFG_REG_8_da_sys_resvo2_START (0)
#define REG_SYS_LOGIC_CFG_REG_8_da_sys_resvo2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sys_resvo3 : 8;
    } reg;
} REG_SYS_LOGIC_CFG_REG_9_UNION;
#endif
#define REG_SYS_LOGIC_CFG_REG_9_da_sys_resvo3_START (0)
#define REG_SYS_LOGIC_CFG_REG_9_da_sys_resvo3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sys_resvo4 : 8;
    } reg;
} REG_SYS_LOGIC_CFG_REG_10_UNION;
#endif
#define REG_SYS_LOGIC_CFG_REG_10_da_sys_resvo4_START (0)
#define REG_SYS_LOGIC_CFG_REG_10_da_sys_resvo4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_vbus_uvp_dt_sel : 1;
        unsigned char da_vbus_ok_nflt_mask : 1;
        unsigned char da_timer_test : 1;
        unsigned char reserved : 5;
    } reg;
} REG_SYS_LOGIC_CFG_REG_11_UNION;
#endif
#define REG_SYS_LOGIC_CFG_REG_11_da_vbus_uvp_dt_sel_START (0)
#define REG_SYS_LOGIC_CFG_REG_11_da_vbus_uvp_dt_sel_END (0)
#define REG_SYS_LOGIC_CFG_REG_11_da_vbus_ok_nflt_mask_START (1)
#define REG_SYS_LOGIC_CFG_REG_11_da_vbus_ok_nflt_mask_END (1)
#define REG_SYS_LOGIC_CFG_REG_11_da_timer_test_START (2)
#define REG_SYS_LOGIC_CFG_REG_11_da_timer_test_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_eis_in : 1;
        unsigned char ad_crack : 1;
        unsigned char ad_avdd_ok : 1;
        unsigned char reserved : 5;
    } reg;
} REG_SYS_LOGIC_RO_REG_12_UNION;
#endif
#define REG_SYS_LOGIC_RO_REG_12_ad_eis_in_START (0)
#define REG_SYS_LOGIC_RO_REG_12_ad_eis_in_END (0)
#define REG_SYS_LOGIC_RO_REG_12_ad_crack_START (1)
#define REG_SYS_LOGIC_RO_REG_12_ad_crack_END (1)
#define REG_SYS_LOGIC_RO_REG_12_ad_avdd_ok_START (2)
#define REG_SYS_LOGIC_RO_REG_12_ad_avdd_ok_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_sys_resvi0 : 8;
    } reg;
} REG_SYS_LOGIC_RO_REG_13_UNION;
#endif
#define REG_SYS_LOGIC_RO_REG_13_ad_sys_resvi0_START (0)
#define REG_SYS_LOGIC_RO_REG_13_ad_sys_resvi0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_sys_resvi1 : 8;
    } reg;
} REG_SYS_LOGIC_RO_REG_14_UNION;
#endif
#define REG_SYS_LOGIC_RO_REG_14_ad_sys_resvi1_START (0)
#define REG_SYS_LOGIC_RO_REG_14_ad_sys_resvi1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_typ_cfg0 : 8;
    } reg;
} REG_TCPC_CFG_REG_0_UNION;
#endif
#define REG_TCPC_CFG_REG_0_da_typ_cfg0_START (0)
#define REG_TCPC_CFG_REG_0_da_typ_cfg0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_typ_cfg1 : 8;
    } reg;
} REG_TCPC_CFG_REG_1_UNION;
#endif
#define REG_TCPC_CFG_REG_1_da_typ_cfg1_START (0)
#define REG_TCPC_CFG_REG_1_da_typ_cfg1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_typ_cfg2 : 8;
    } reg;
} REG_TCPC_CFG_REG_2_UNION;
#endif
#define REG_TCPC_CFG_REG_2_da_typ_cfg2_START (0)
#define REG_TCPC_CFG_REG_2_da_typ_cfg2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_cc_reserved : 4;
        unsigned char reserved : 4;
    } reg;
} REG_TCPC_CFG_REG_3_UNION;
#endif
#define REG_TCPC_CFG_REG_3_da_cc_reserved_START (0)
#define REG_TCPC_CFG_REG_3_da_cc_reserved_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sbu2_det_en : 1;
        unsigned char da_sbu1_det_en : 1;
        unsigned char da_sbu_cur_sel : 2;
        unsigned char da_sbu_adc_chsel : 1;
        unsigned char reserved : 3;
    } reg;
} REG_TYPE_CFG_REG_4_UNION;
#endif
#define REG_TYPE_CFG_REG_4_da_sbu2_det_en_START (0)
#define REG_TYPE_CFG_REG_4_da_sbu2_det_en_END (0)
#define REG_TYPE_CFG_REG_4_da_sbu1_det_en_START (1)
#define REG_TYPE_CFG_REG_4_da_sbu1_det_en_END (1)
#define REG_TYPE_CFG_REG_4_da_sbu_cur_sel_START (2)
#define REG_TYPE_CFG_REG_4_da_sbu_cur_sel_END (3)
#define REG_TYPE_CFG_REG_4_da_sbu_adc_chsel_START (4)
#define REG_TYPE_CFG_REG_4_da_sbu_adc_chsel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_cc_resvi : 4;
        unsigned char reserved : 4;
    } reg;
} REG_TCPC_RO_REG_1_UNION;
#endif
#define REG_TCPC_RO_REG_1_ad_cc_resvi_START (0)
#define REG_TCPC_RO_REG_1_ad_cc_resvi_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_s1q1_ocp_rvs_peak_set : 2;
        unsigned char da_s1q1_ocp_fwd_set : 2;
        unsigned char da_s1q1_ocp_fwd_peak_set : 2;
        unsigned char da_s1q1_ocp_en : 1;
        unsigned char reserved : 1;
    } reg;
} REG_SC_PRO_CFG_REG_0_UNION;
#endif
#define REG_SC_PRO_CFG_REG_0_da_s1q1_ocp_rvs_peak_set_START (0)
#define REG_SC_PRO_CFG_REG_0_da_s1q1_ocp_rvs_peak_set_END (1)
#define REG_SC_PRO_CFG_REG_0_da_s1q1_ocp_fwd_set_START (2)
#define REG_SC_PRO_CFG_REG_0_da_s1q1_ocp_fwd_set_END (3)
#define REG_SC_PRO_CFG_REG_0_da_s1q1_ocp_fwd_peak_set_START (4)
#define REG_SC_PRO_CFG_REG_0_da_s1q1_ocp_fwd_peak_set_END (5)
#define REG_SC_PRO_CFG_REG_0_da_s1q1_ocp_en_START (6)
#define REG_SC_PRO_CFG_REG_0_da_s1q1_ocp_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_s2q1_ocp_en : 1;
        unsigned char da_s1q1_ucp_en : 1;
        unsigned char da_s1q1_rcp_en : 1;
        unsigned char da_s1q1_peak_ocp_en : 1;
        unsigned char da_s1q1_ocp_rvs_set : 3;
        unsigned char reserved : 1;
    } reg;
} REG_SC_PRO_CFG_REG_1_UNION;
#endif
#define REG_SC_PRO_CFG_REG_1_da_s2q1_ocp_en_START (0)
#define REG_SC_PRO_CFG_REG_1_da_s2q1_ocp_en_END (0)
#define REG_SC_PRO_CFG_REG_1_da_s1q1_ucp_en_START (1)
#define REG_SC_PRO_CFG_REG_1_da_s1q1_ucp_en_END (1)
#define REG_SC_PRO_CFG_REG_1_da_s1q1_rcp_en_START (2)
#define REG_SC_PRO_CFG_REG_1_da_s1q1_rcp_en_END (2)
#define REG_SC_PRO_CFG_REG_1_da_s1q1_peak_ocp_en_START (3)
#define REG_SC_PRO_CFG_REG_1_da_s1q1_peak_ocp_en_END (3)
#define REG_SC_PRO_CFG_REG_1_da_s1q1_ocp_rvs_set_START (4)
#define REG_SC_PRO_CFG_REG_1_da_s1q1_ocp_rvs_set_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_s2q1_ocp_rvs_peak_set : 2;
        unsigned char da_s2q1_ocp_fwd_set : 2;
        unsigned char da_s2q1_ocp_fwd_peak_set : 2;
        unsigned char reserved : 2;
    } reg;
} REG_SC_PRO_CFG_REG_2_UNION;
#endif
#define REG_SC_PRO_CFG_REG_2_da_s2q1_ocp_rvs_peak_set_START (0)
#define REG_SC_PRO_CFG_REG_2_da_s2q1_ocp_rvs_peak_set_END (1)
#define REG_SC_PRO_CFG_REG_2_da_s2q1_ocp_fwd_set_START (2)
#define REG_SC_PRO_CFG_REG_2_da_s2q1_ocp_fwd_set_END (3)
#define REG_SC_PRO_CFG_REG_2_da_s2q1_ocp_fwd_peak_set_START (4)
#define REG_SC_PRO_CFG_REG_2_da_s2q1_ocp_fwd_peak_set_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_ibat_ocp_dbt : 1;
        unsigned char da_sc_ibat_ocp_chopper_en : 1;
        unsigned char da_s2q1_ucp_en : 1;
        unsigned char da_s2q1_rcp_en : 1;
        unsigned char da_s2q1_peak_ocp_en : 1;
        unsigned char da_s2q1_ocp_rvs_set : 3;
    } reg;
} REG_SC_PRO_CFG_REG_3_UNION;
#endif
#define REG_SC_PRO_CFG_REG_3_da_sc_ibat_ocp_dbt_START (0)
#define REG_SC_PRO_CFG_REG_3_da_sc_ibat_ocp_dbt_END (0)
#define REG_SC_PRO_CFG_REG_3_da_sc_ibat_ocp_chopper_en_START (1)
#define REG_SC_PRO_CFG_REG_3_da_sc_ibat_ocp_chopper_en_END (1)
#define REG_SC_PRO_CFG_REG_3_da_s2q1_ucp_en_START (2)
#define REG_SC_PRO_CFG_REG_3_da_s2q1_ucp_en_END (2)
#define REG_SC_PRO_CFG_REG_3_da_s2q1_rcp_en_START (3)
#define REG_SC_PRO_CFG_REG_3_da_s2q1_rcp_en_END (3)
#define REG_SC_PRO_CFG_REG_3_da_s2q1_peak_ocp_en_START (4)
#define REG_SC_PRO_CFG_REG_3_da_s2q1_peak_ocp_en_END (4)
#define REG_SC_PRO_CFG_REG_3_da_s2q1_ocp_rvs_set_START (5)
#define REG_SC_PRO_CFG_REG_3_da_s2q1_ocp_rvs_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_ibat_ocp_offset_adj : 4;
        unsigned char da_sc_ibat_ocp_en : 1;
        unsigned char reserved : 3;
    } reg;
} REG_SC_PRO_CFG_REG_4_UNION;
#endif
#define REG_SC_PRO_CFG_REG_4_da_sc_ibat_ocp_offset_adj_START (0)
#define REG_SC_PRO_CFG_REG_4_da_sc_ibat_ocp_offset_adj_END (3)
#define REG_SC_PRO_CFG_REG_4_da_sc_ibat_ocp_en_START (4)
#define REG_SC_PRO_CFG_REG_4_da_sc_ibat_ocp_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_q1_rcp_dbt : 1;
        unsigned char da_sc_q1_ocp_dbt : 1;
        unsigned char da_sc_pro_en : 1;
        unsigned char da_sc_ibat_res_place_sel : 1;
        unsigned char da_sc_ibat_ocp_set : 4;
    } reg;
} REG_SC_PRO_CFG_REG_5_UNION;
#endif
#define REG_SC_PRO_CFG_REG_5_da_sc_q1_rcp_dbt_START (0)
#define REG_SC_PRO_CFG_REG_5_da_sc_q1_rcp_dbt_END (0)
#define REG_SC_PRO_CFG_REG_5_da_sc_q1_ocp_dbt_START (1)
#define REG_SC_PRO_CFG_REG_5_da_sc_q1_ocp_dbt_END (1)
#define REG_SC_PRO_CFG_REG_5_da_sc_pro_en_START (2)
#define REG_SC_PRO_CFG_REG_5_da_sc_pro_en_END (2)
#define REG_SC_PRO_CFG_REG_5_da_sc_ibat_res_place_sel_START (3)
#define REG_SC_PRO_CFG_REG_5_da_sc_ibat_res_place_sel_END (3)
#define REG_SC_PRO_CFG_REG_5_da_sc_ibat_ocp_set_START (4)
#define REG_SC_PRO_CFG_REG_5_da_sc_ibat_ocp_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_vbus_dropovp_en : 1;
        unsigned char da_sc_q1_ucp_set : 2;
        unsigned char da_sc_q1_ucp_dbt : 1;
        unsigned char da_sc_q1_rcp_shield_time : 2;
        unsigned char da_sc_q1_rcp_set : 2;
    } reg;
} REG_SC_PRO_CFG_REG_6_UNION;
#endif
#define REG_SC_PRO_CFG_REG_6_da_sc_vbus_dropovp_en_START (0)
#define REG_SC_PRO_CFG_REG_6_da_sc_vbus_dropovp_en_END (0)
#define REG_SC_PRO_CFG_REG_6_da_sc_q1_ucp_set_START (1)
#define REG_SC_PRO_CFG_REG_6_da_sc_q1_ucp_set_END (2)
#define REG_SC_PRO_CFG_REG_6_da_sc_q1_ucp_dbt_START (3)
#define REG_SC_PRO_CFG_REG_6_da_sc_q1_ucp_dbt_END (3)
#define REG_SC_PRO_CFG_REG_6_da_sc_q1_rcp_shield_time_START (4)
#define REG_SC_PRO_CFG_REG_6_da_sc_q1_rcp_shield_time_END (5)
#define REG_SC_PRO_CFG_REG_6_da_sc_q1_rcp_set_START (6)
#define REG_SC_PRO_CFG_REG_6_da_sc_q1_rcp_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc_vout_uvlo_en : 1;
        unsigned char da_sc_vout_ovp_set : 2;
        unsigned char da_sc_vout_ovp_en : 1;
        unsigned char da_sc_vout_ovp_dbt : 1;
        unsigned char da_sc_vbus_dropovp_set : 2;
        unsigned char reserved : 1;
    } reg;
} REG_SC_PRO_CFG_REG_7_UNION;
#endif
#define REG_SC_PRO_CFG_REG_7_da_sc_vout_uvlo_en_START (0)
#define REG_SC_PRO_CFG_REG_7_da_sc_vout_uvlo_en_END (0)
#define REG_SC_PRO_CFG_REG_7_da_sc_vout_ovp_set_START (1)
#define REG_SC_PRO_CFG_REG_7_da_sc_vout_ovp_set_END (2)
#define REG_SC_PRO_CFG_REG_7_da_sc_vout_ovp_en_START (3)
#define REG_SC_PRO_CFG_REG_7_da_sc_vout_ovp_en_END (3)
#define REG_SC_PRO_CFG_REG_7_da_sc_vout_ovp_dbt_START (4)
#define REG_SC_PRO_CFG_REG_7_da_sc_vout_ovp_dbt_END (4)
#define REG_SC_PRO_CFG_REG_7_da_sc_vbus_dropovp_set_START (5)
#define REG_SC_PRO_CFG_REG_7_da_sc_vbus_dropovp_set_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc1_dsw_offset_adj : 6;
        unsigned char da_sc_vout_uvlo_set : 2;
    } reg;
} REG_SC_PRO_CFG_REG_8_UNION;
#endif
#define REG_SC_PRO_CFG_REG_8_da_sc1_dsw_offset_adj_START (0)
#define REG_SC_PRO_CFG_REG_8_da_sc1_dsw_offset_adj_END (5)
#define REG_SC_PRO_CFG_REG_8_da_sc_vout_uvlo_set_START (6)
#define REG_SC_PRO_CFG_REG_8_da_sc_vout_uvlo_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc1q5_dsw_ocp_en : 1;
        unsigned char da_sc1q4_dsw_ocp_set : 5;
        unsigned char da_sc1q4_dsw_ocp_en : 1;
        unsigned char da_sc1q10_dsw_ocp_en : 1;
    } reg;
} REG_SC_PRO_CFG_REG_9_UNION;
#endif
#define REG_SC_PRO_CFG_REG_9_da_sc1q5_dsw_ocp_en_START (0)
#define REG_SC_PRO_CFG_REG_9_da_sc1q5_dsw_ocp_en_END (0)
#define REG_SC_PRO_CFG_REG_9_da_sc1q4_dsw_ocp_set_START (1)
#define REG_SC_PRO_CFG_REG_9_da_sc1q4_dsw_ocp_set_END (5)
#define REG_SC_PRO_CFG_REG_9_da_sc1q4_dsw_ocp_en_START (6)
#define REG_SC_PRO_CFG_REG_9_da_sc1q4_dsw_ocp_en_END (6)
#define REG_SC_PRO_CFG_REG_9_da_sc1q10_dsw_ocp_en_START (7)
#define REG_SC_PRO_CFG_REG_9_da_sc1q10_dsw_ocp_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc1q5q10_dsw_ocp_set : 5;
        unsigned char reserved : 3;
    } reg;
} REG_SC_PRO_CFG_REG_10_UNION;
#endif
#define REG_SC_PRO_CFG_REG_10_da_sc1q5q10_dsw_ocp_set_START (0)
#define REG_SC_PRO_CFG_REG_10_da_sc1q5q10_dsw_ocp_set_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc2q4_dsw_ocp_en : 1;
        unsigned char da_sc2q10_dsw_ocp_en : 1;
        unsigned char da_sc2_dsw_offset_adj : 6;
    } reg;
} REG_SC_PRO_CFG_REG_11_UNION;
#endif
#define REG_SC_PRO_CFG_REG_11_da_sc2q4_dsw_ocp_en_START (0)
#define REG_SC_PRO_CFG_REG_11_da_sc2q4_dsw_ocp_en_END (0)
#define REG_SC_PRO_CFG_REG_11_da_sc2q10_dsw_ocp_en_START (1)
#define REG_SC_PRO_CFG_REG_11_da_sc2q10_dsw_ocp_en_END (1)
#define REG_SC_PRO_CFG_REG_11_da_sc2_dsw_offset_adj_START (2)
#define REG_SC_PRO_CFG_REG_11_da_sc2_dsw_offset_adj_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc2q5_dsw_ocp_en : 1;
        unsigned char da_sc2q4_dsw_ocp_set : 5;
        unsigned char reserved : 2;
    } reg;
} REG_SC_PRO_CFG_REG_12_UNION;
#endif
#define REG_SC_PRO_CFG_REG_12_da_sc2q5_dsw_ocp_en_START (0)
#define REG_SC_PRO_CFG_REG_12_da_sc2q5_dsw_ocp_en_END (0)
#define REG_SC_PRO_CFG_REG_12_da_sc2q4_dsw_ocp_set_START (1)
#define REG_SC_PRO_CFG_REG_12_da_sc2q4_dsw_ocp_set_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_sc2q5q10_dsw_ocp_set : 5;
        unsigned char reserved : 3;
    } reg;
} REG_SC_PRO_CFG_REG_13_UNION;
#endif
#define REG_SC_PRO_CFG_REG_13_da_sc2q5q10_dsw_ocp_set_START (0)
#define REG_SC_PRO_CFG_REG_13_da_sc2q5q10_dsw_ocp_set_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_scpro_reserve : 8;
    } reg;
} REG_SC_PRO_CFG_REG_14_UNION;
#endif
#define REG_SC_PRO_CFG_REG_14_da_scpro_reserve_START (0)
#define REG_SC_PRO_CFG_REG_14_da_scpro_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_scpro_reserve1 : 8;
    } reg;
} REG_SC_PRO_CFG_REG_15_UNION;
#endif
#define REG_SC_PRO_CFG_REG_15_da_scpro_reserve1_START (0)
#define REG_SC_PRO_CFG_REG_15_da_scpro_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_scpro_testmd : 8;
    } reg;
} REG_SC_PRO_CFG_REG_16_UNION;
#endif
#define REG_SC_PRO_CFG_REG_16_da_scpro_testmd_START (0)
#define REG_SC_PRO_CFG_REG_16_da_scpro_testmd_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_s2_cfly3_scp_en : 1;
        unsigned char da_s2_cfly2_scp_en : 1;
        unsigned char da_s2_cfly1_scp_en : 1;
        unsigned char da_s1_cfly3_scp_en : 1;
        unsigned char da_s1_cfly2_scp_en : 1;
        unsigned char da_s1_cfly1_scp_en : 1;
        unsigned char reserved : 2;
    } reg;
} REG_SC_PRO_CFG_REG_17_UNION;
#endif
#define REG_SC_PRO_CFG_REG_17_da_s2_cfly3_scp_en_START (0)
#define REG_SC_PRO_CFG_REG_17_da_s2_cfly3_scp_en_END (0)
#define REG_SC_PRO_CFG_REG_17_da_s2_cfly2_scp_en_START (1)
#define REG_SC_PRO_CFG_REG_17_da_s2_cfly2_scp_en_END (1)
#define REG_SC_PRO_CFG_REG_17_da_s2_cfly1_scp_en_START (2)
#define REG_SC_PRO_CFG_REG_17_da_s2_cfly1_scp_en_END (2)
#define REG_SC_PRO_CFG_REG_17_da_s1_cfly3_scp_en_START (3)
#define REG_SC_PRO_CFG_REG_17_da_s1_cfly3_scp_en_END (3)
#define REG_SC_PRO_CFG_REG_17_da_s1_cfly2_scp_en_START (4)
#define REG_SC_PRO_CFG_REG_17_da_s1_cfly2_scp_en_END (4)
#define REG_SC_PRO_CFG_REG_17_da_s1_cfly1_scp_en_START (5)
#define REG_SC_PRO_CFG_REG_17_da_s1_cfly1_scp_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_ref_gate_filiter_shield : 1;
        unsigned char da_ref_fake_load : 1;
        unsigned char da_ref_chop_sel : 1;
        unsigned char da_ref_buffer_current : 1;
        unsigned char da_ref_bg_test_mode : 1;
        unsigned char da_ref_bg_output_load : 1;
        unsigned char da_ref_bg_out_en : 1;
        unsigned char da_bg_curr_sel : 1;
    } reg;
} REG_REF_TOP_CFG_REG_0_UNION;
#endif
#define REG_REF_TOP_CFG_REG_0_da_ref_gate_filiter_shield_START (0)
#define REG_REF_TOP_CFG_REG_0_da_ref_gate_filiter_shield_END (0)
#define REG_REF_TOP_CFG_REG_0_da_ref_fake_load_START (1)
#define REG_REF_TOP_CFG_REG_0_da_ref_fake_load_END (1)
#define REG_REF_TOP_CFG_REG_0_da_ref_chop_sel_START (2)
#define REG_REF_TOP_CFG_REG_0_da_ref_chop_sel_END (2)
#define REG_REF_TOP_CFG_REG_0_da_ref_buffer_current_START (3)
#define REG_REF_TOP_CFG_REG_0_da_ref_buffer_current_END (3)
#define REG_REF_TOP_CFG_REG_0_da_ref_bg_test_mode_START (4)
#define REG_REF_TOP_CFG_REG_0_da_ref_bg_test_mode_END (4)
#define REG_REF_TOP_CFG_REG_0_da_ref_bg_output_load_START (5)
#define REG_REF_TOP_CFG_REG_0_da_ref_bg_output_load_END (5)
#define REG_REF_TOP_CFG_REG_0_da_ref_bg_out_en_START (6)
#define REG_REF_TOP_CFG_REG_0_da_ref_bg_out_en_END (6)
#define REG_REF_TOP_CFG_REG_0_da_bg_curr_sel_START (7)
#define REG_REF_TOP_CFG_REG_0_da_bg_curr_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_ref_ibias_out_en : 2;
        unsigned char reserved : 6;
    } reg;
} REG_REF_TOP_CFG_REG_1_UNION;
#endif
#define REG_REF_TOP_CFG_REG_1_da_ref_ibias_out_en_START (0)
#define REG_REF_TOP_CFG_REG_1_da_ref_ibias_out_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_ref_resv0 : 8;
    } reg;
} REG_REF_TOP_CFG_REG_2_UNION;
#endif
#define REG_REF_TOP_CFG_REG_2_da_ref_resv0_START (0)
#define REG_REF_TOP_CFG_REG_2_da_ref_resv0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_ref_resv1 : 8;
    } reg;
} REG_REF_TOP_CFG_REG_3_UNION;
#endif
#define REG_REF_TOP_CFG_REG_3_da_ref_resv1_START (0)
#define REG_REF_TOP_CFG_REG_3_da_ref_resv1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_ref_thsd_tmp_set : 2;
        unsigned char da_ref_thsd_en : 1;
        unsigned char da_ref_thsd_adj : 2;
        unsigned char da_ref_thsd_140c_down : 1;
        unsigned char da_ref_tdie_otp_shield : 1;
        unsigned char da_ref_tdie_otp_sel : 1;
    } reg;
} REG_REF_TOP_CFG_REG_4_UNION;
#endif
#define REG_REF_TOP_CFG_REG_4_da_ref_thsd_tmp_set_START (0)
#define REG_REF_TOP_CFG_REG_4_da_ref_thsd_tmp_set_END (1)
#define REG_REF_TOP_CFG_REG_4_da_ref_thsd_en_START (2)
#define REG_REF_TOP_CFG_REG_4_da_ref_thsd_en_END (2)
#define REG_REF_TOP_CFG_REG_4_da_ref_thsd_adj_START (3)
#define REG_REF_TOP_CFG_REG_4_da_ref_thsd_adj_END (4)
#define REG_REF_TOP_CFG_REG_4_da_ref_thsd_140c_down_START (5)
#define REG_REF_TOP_CFG_REG_4_da_ref_thsd_140c_down_END (5)
#define REG_REF_TOP_CFG_REG_4_da_ref_tdie_otp_shield_START (6)
#define REG_REF_TOP_CFG_REG_4_da_ref_tdie_otp_shield_END (6)
#define REG_REF_TOP_CFG_REG_4_da_ref_tdie_otp_sel_START (7)
#define REG_REF_TOP_CFG_REG_4_da_ref_tdie_otp_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_ref_thsd_trim_set : 1;
        unsigned char reserved : 7;
    } reg;
} REG_REF_TOP_CFG_REG_5_UNION;
#endif
#define REG_REF_TOP_CFG_REG_5_da_ref_thsd_trim_set_START (0)
#define REG_REF_TOP_CFG_REG_5_da_ref_thsd_trim_set_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_osc_reserve1 : 8;
    } reg;
} REG_OSC_TOP_CFG_REG_0_UNION;
#endif
#define REG_OSC_TOP_CFG_REG_0_da_osc_reserve1_START (0)
#define REG_OSC_TOP_CFG_REG_0_da_osc_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_osc_reserve2 : 8;
    } reg;
} REG_OSC_TOP_CFG_REG_1_UNION;
#endif
#define REG_OSC_TOP_CFG_REG_1_da_osc_reserve2_START (0)
#define REG_OSC_TOP_CFG_REG_1_da_osc_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_osc16m_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_OSC_TOP_CFG_REG_2_UNION;
#endif
#define REG_OSC_TOP_CFG_REG_2_da_osc16m_en_START (0)
#define REG_OSC_TOP_CFG_REG_2_da_osc16m_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_state_reserve0 : 8;
    } reg;
} REG_AD_STATUS_RSV0_UNION;
#endif
#define REG_AD_STATUS_RSV0_ad_state_reserve0_START (0)
#define REG_AD_STATUS_RSV0_ad_state_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_state_reserve1 : 8;
    } reg;
} REG_AD_STATUS_RSV1_UNION;
#endif
#define REG_AD_STATUS_RSV1_ad_state_reserve1_START (0)
#define REG_AD_STATUS_RSV1_ad_state_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_state_reserve2 : 8;
    } reg;
} REG_AD_STATUS_RSV2_UNION;
#endif
#define REG_AD_STATUS_RSV2_ad_state_reserve2_START (0)
#define REG_AD_STATUS_RSV2_ad_state_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_state_reserve3 : 8;
    } reg;
} REG_AD_STATUS_RSV3_UNION;
#endif
#define REG_AD_STATUS_RSV3_ad_state_reserve3_START (0)
#define REG_AD_STATUS_RSV3_ad_state_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_bypass : 1;
        unsigned char fer_test : 1;
        unsigned char fer_snapshot : 1;
        unsigned char reserved : 5;
    } reg;
} REG_FER_CTRL_UNION;
#endif
#define REG_FER_CTRL_fer_bypass_START (0)
#define REG_FER_CTRL_fer_bypass_END (0)
#define REG_FER_CTRL_fer_test_START (1)
#define REG_FER_CTRL_fer_test_END (1)
#define REG_FER_CTRL_fer_snapshot_START (2)
#define REG_FER_CTRL_fer_snapshot_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_pmu_psok_level : 1;
        unsigned char fer_pmu_irq_level : 1;
        unsigned char fer_buck_ocot_level : 1;
        unsigned char fer_buck_pgvok_level : 1;
        unsigned char reserved : 4;
    } reg;
} REG_FER_EVENT_LEVEL_UNION;
#endif
#define REG_FER_EVENT_LEVEL_fer_pmu_psok_level_START (0)
#define REG_FER_EVENT_LEVEL_fer_pmu_psok_level_END (0)
#define REG_FER_EVENT_LEVEL_fer_pmu_irq_level_START (1)
#define REG_FER_EVENT_LEVEL_fer_pmu_irq_level_END (1)
#define REG_FER_EVENT_LEVEL_fer_buck_ocot_level_START (2)
#define REG_FER_EVENT_LEVEL_fer_buck_ocot_level_END (2)
#define REG_FER_EVENT_LEVEL_fer_buck_pgvok_level_START (3)
#define REG_FER_EVENT_LEVEL_fer_buck_pgvok_level_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_buck_pg_msk : 8;
    } reg;
} REG_FER_BUCK_PG_MSK_UNION;
#endif
#define REG_FER_BUCK_PG_MSK_fer_buck_pg_msk_START (0)
#define REG_FER_BUCK_PG_MSK_fer_buck_pg_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_buck_vok_msk : 8;
    } reg;
} REG_FER_BUCK_VOK_MSK_UNION;
#endif
#define REG_FER_BUCK_VOK_MSK_fer_buck_vok_msk_START (0)
#define REG_FER_BUCK_VOK_MSK_fer_buck_vok_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_buck_oc_msk : 8;
    } reg;
} REG_FER_BUCK_OC_MSK_UNION;
#endif
#define REG_FER_BUCK_OC_MSK_fer_buck_oc_msk_START (0)
#define REG_FER_BUCK_OC_MSK_fer_buck_oc_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_buck_ot_msk : 8;
    } reg;
} REG_FER_BUCK_OT_MSK_UNION;
#endif
#define REG_FER_BUCK_OT_MSK_fer_buck_ot_msk_START (0)
#define REG_FER_BUCK_OT_MSK_fer_buck_ot_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_pmu_psok_msk : 1;
        unsigned char reserved : 7;
    } reg;
} REG_FER_PMU_PSOK_MSK_UNION;
#endif
#define REG_FER_PMU_PSOK_MSK_fer_pmu_psok_msk_START (0)
#define REG_FER_PMU_PSOK_MSK_fer_pmu_psok_msk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_pmu_irq_msk0 : 8;
    } reg;
} REG_FER_PMU_IRQ_MSK0_UNION;
#endif
#define REG_FER_PMU_IRQ_MSK0_fer_pmu_irq_msk0_START (0)
#define REG_FER_PMU_IRQ_MSK0_fer_pmu_irq_msk0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_pmu_irq_msk1 : 4;
        unsigned char reserved : 4;
    } reg;
} REG_FER_PMU_IRQ_MSK1_UNION;
#endif
#define REG_FER_PMU_IRQ_MSK1_fer_pmu_irq_msk1_START (0)
#define REG_FER_PMU_IRQ_MSK1_fer_pmu_irq_msk1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_buf_buck_pgvok : 8;
    } reg;
} REG_FER_BUF_BUCK_PGVOK_UNION;
#endif
#define REG_FER_BUF_BUCK_PGVOK_fer_buf_buck_pgvok_START (0)
#define REG_FER_BUF_BUCK_PGVOK_fer_buf_buck_pgvok_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_buf_buck_ocot : 8;
    } reg;
} REG_FER_BUF_BUCK_OCOT_UNION;
#endif
#define REG_FER_BUF_BUCK_OCOT_fer_buf_buck_ocot_START (0)
#define REG_FER_BUF_BUCK_OCOT_fer_buf_buck_ocot_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_buf_pmu_psok : 1;
        unsigned char reserved : 7;
    } reg;
} REG_FER_BUF_PMU_PSOK_UNION;
#endif
#define REG_FER_BUF_PMU_PSOK_fer_buf_pmu_psok_START (0)
#define REG_FER_BUF_PMU_PSOK_fer_buf_pmu_psok_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_buf_pmu_irq0 : 8;
    } reg;
} REG_FER_BUF_PMU_IRQ0_UNION;
#endif
#define REG_FER_BUF_PMU_IRQ0_fer_buf_pmu_irq0_START (0)
#define REG_FER_BUF_PMU_IRQ0_fer_buf_pmu_irq0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_buf_pmu_irq1 : 4;
        unsigned char reserved : 4;
    } reg;
} REG_FER_BUF_PMU_IRQ1_UNION;
#endif
#define REG_FER_BUF_PMU_IRQ1_fer_buf_pmu_irq1_START (0)
#define REG_FER_BUF_PMU_IRQ1_fer_buf_pmu_irq1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_trans_abit_data : 8;
    } reg;
} REG_FER_TRANS_ABIT_DATA_UNION;
#endif
#define REG_FER_TRANS_ABIT_DATA_fer_trans_abit_data_START (0)
#define REG_FER_TRANS_ABIT_DATA_fer_trans_abit_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_trans_abit_addr : 8;
    } reg;
} REG_FER_TRANS_ABIT_ADDR_UNION;
#endif
#define REG_FER_TRANS_ABIT_ADDR_fer_trans_abit_addr_START (0)
#define REG_FER_TRANS_ABIT_ADDR_fer_trans_abit_addr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_trans_srbit_data : 8;
    } reg;
} REG_FER_TRANS_SRBIT_DATA_UNION;
#endif
#define REG_FER_TRANS_SRBIT_DATA_fer_trans_srbit_data_START (0)
#define REG_FER_TRANS_SRBIT_DATA_fer_trans_srbit_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fer_trans_srbit_addr : 8;
    } reg;
} REG_FER_TRANS_SRBIT_ADDR_UNION;
#endif
#define REG_FER_TRANS_SRBIT_ADDR_fer_trans_srbit_addr_START (0)
#define REG_FER_TRANS_SRBIT_ADDR_fer_trans_srbit_addr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug0 : 8;
    } reg;
} REG_SPMI_DEBUG0_UNION;
#endif
#define REG_SPMI_DEBUG0_spmi_debug0_START (0)
#define REG_SPMI_DEBUG0_spmi_debug0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug1 : 8;
    } reg;
} REG_SPMI_DEBUG1_UNION;
#endif
#define REG_SPMI_DEBUG1_spmi_debug1_START (0)
#define REG_SPMI_DEBUG1_spmi_debug1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug2 : 8;
    } reg;
} REG_SPMI_DEBUG2_UNION;
#endif
#define REG_SPMI_DEBUG2_spmi_debug2_START (0)
#define REG_SPMI_DEBUG2_spmi_debug2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug3 : 8;
    } reg;
} REG_SPMI_DEBUG3_UNION;
#endif
#define REG_SPMI_DEBUG3_spmi_debug3_START (0)
#define REG_SPMI_DEBUG3_spmi_debug3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug4 : 8;
    } reg;
} REG_SPMI_DEBUG4_UNION;
#endif
#define REG_SPMI_DEBUG4_spmi_debug4_START (0)
#define REG_SPMI_DEBUG4_spmi_debug4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug5 : 8;
    } reg;
} REG_SPMI_DEBUG5_UNION;
#endif
#define REG_SPMI_DEBUG5_spmi_debug5_START (0)
#define REG_SPMI_DEBUG5_spmi_debug5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug6 : 8;
    } reg;
} REG_SPMI_DEBUG6_UNION;
#endif
#define REG_SPMI_DEBUG6_spmi_debug6_START (0)
#define REG_SPMI_DEBUG6_spmi_debug6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug7 : 8;
    } reg;
} REG_SPMI_DEBUG7_UNION;
#endif
#define REG_SPMI_DEBUG7_spmi_debug7_START (0)
#define REG_SPMI_DEBUG7_spmi_debug7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_flash_strobe_en : 1;
        unsigned char sc_flash_bb_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char da_flash_bb_en_ro : 1;
        unsigned char reserved_1 : 3;
    } reg;
} REG_FLASH_DIG_CFG_0_UNION;
#endif
#define REG_FLASH_DIG_CFG_0_sc_flash_strobe_en_START (0)
#define REG_FLASH_DIG_CFG_0_sc_flash_strobe_en_END (0)
#define REG_FLASH_DIG_CFG_0_sc_flash_bb_en_START (1)
#define REG_FLASH_DIG_CFG_0_sc_flash_bb_en_END (1)
#define REG_FLASH_DIG_CFG_0_da_flash_bb_en_ro_START (4)
#define REG_FLASH_DIG_CFG_0_da_flash_bb_en_ro_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_flash_led_md : 3;
        unsigned char reserved : 5;
    } reg;
} REG_FLASH_LED_MD_UNION;
#endif
#define REG_FLASH_LED_MD_sc_flash_led_md_START (0)
#define REG_FLASH_LED_MD_sc_flash_led_md_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_flash_led_en : 3;
        unsigned char reserved_0 : 1;
        unsigned char da_flash_led_en_ro : 3;
        unsigned char reserved_1 : 1;
    } reg;
} REG_FLASH_LED_EN_UNION;
#endif
#define REG_FLASH_LED_EN_sc_flash_led_en_START (0)
#define REG_FLASH_LED_EN_sc_flash_led_en_END (2)
#define REG_FLASH_LED_EN_da_flash_led_en_ro_START (4)
#define REG_FLASH_LED_EN_da_flash_led_en_ro_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_flash_led1_timeout : 4;
        unsigned char sc_flash_led1_timeout_en : 1;
        unsigned char reserved : 3;
    } reg;
} REG_FLASH_LED1_TIMEOUT_UNION;
#endif
#define REG_FLASH_LED1_TIMEOUT_sc_flash_led1_timeout_START (0)
#define REG_FLASH_LED1_TIMEOUT_sc_flash_led1_timeout_END (3)
#define REG_FLASH_LED1_TIMEOUT_sc_flash_led1_timeout_en_START (4)
#define REG_FLASH_LED1_TIMEOUT_sc_flash_led1_timeout_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_flash_led2_timeout : 4;
        unsigned char sc_flash_led2_timeout_en : 1;
        unsigned char reserved : 3;
    } reg;
} REG_FLASH_LED2_TIMEOUT_UNION;
#endif
#define REG_FLASH_LED2_TIMEOUT_sc_flash_led2_timeout_START (0)
#define REG_FLASH_LED2_TIMEOUT_sc_flash_led2_timeout_END (3)
#define REG_FLASH_LED2_TIMEOUT_sc_flash_led2_timeout_en_START (4)
#define REG_FLASH_LED2_TIMEOUT_sc_flash_led2_timeout_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_flash_led3_timeout : 4;
        unsigned char sc_flash_led3_timeout_en : 1;
        unsigned char reserved : 3;
    } reg;
} REG_FLASH_LED3_TIMEOUT_UNION;
#endif
#define REG_FLASH_LED3_TIMEOUT_sc_flash_led3_timeout_START (0)
#define REG_FLASH_LED3_TIMEOUT_sc_flash_led3_timeout_END (3)
#define REG_FLASH_LED3_TIMEOUT_sc_flash_led3_timeout_en_START (4)
#define REG_FLASH_LED3_TIMEOUT_sc_flash_led3_timeout_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_flash_led1_code : 7;
        unsigned char reserved : 1;
    } reg;
} REG_FLASH_LED1_CODE_UNION;
#endif
#define REG_FLASH_LED1_CODE_sc_flash_led1_code_START (0)
#define REG_FLASH_LED1_CODE_sc_flash_led1_code_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_flash_led2_code : 7;
        unsigned char reserved : 1;
    } reg;
} REG_FLASH_LED2_CODE_UNION;
#endif
#define REG_FLASH_LED2_CODE_sc_flash_led2_code_START (0)
#define REG_FLASH_LED2_CODE_sc_flash_led2_code_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_flash_led3_code : 7;
        unsigned char reserved : 1;
    } reg;
} REG_FLASH_LED3_CODE_UNION;
#endif
#define REG_FLASH_LED3_CODE_sc_flash_led3_code_START (0)
#define REG_FLASH_LED3_CODE_sc_flash_led3_code_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_flash_led_tr : 3;
        unsigned char reserved_0 : 1;
        unsigned char sc_flash_led_tf : 3;
        unsigned char reserved_1 : 1;
    } reg;
} REG_FLASH_RAMP_STEP_UNION;
#endif
#define REG_FLASH_RAMP_STEP_sc_flash_led_tr_START (0)
#define REG_FLASH_RAMP_STEP_sc_flash_led_tr_END (2)
#define REG_FLASH_RAMP_STEP_sc_flash_led_tf_START (4)
#define REG_FLASH_RAMP_STEP_sc_flash_led_tf_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_flash_test_bus_sel : 3;
        unsigned char reserved_0 : 1;
        unsigned char sc_flash_tmode : 1;
        unsigned char reserved_1 : 3;
    } reg;
} REG_FLASH_DIG_CFG_7_UNION;
#endif
#define REG_FLASH_DIG_CFG_7_sc_flash_test_bus_sel_START (0)
#define REG_FLASH_DIG_CFG_7_sc_flash_test_bus_sel_END (2)
#define REG_FLASH_DIG_CFG_7_sc_flash_tmode_START (4)
#define REG_FLASH_DIG_CFG_7_sc_flash_tmode_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_flash_ivfm_set : 3;
        unsigned char da_flash_ivfm_filter : 1;
        unsigned char da_flash_ivfm_en : 3;
        unsigned char reserved : 1;
    } reg;
} REG_FLASH_CFG_REG_0_UNION;
#endif
#define REG_FLASH_CFG_REG_0_da_flash_ivfm_set_START (0)
#define REG_FLASH_CFG_REG_0_da_flash_ivfm_set_END (2)
#define REG_FLASH_CFG_REG_0_da_flash_ivfm_filter_START (3)
#define REG_FLASH_CFG_REG_0_da_flash_ivfm_filter_END (3)
#define REG_FLASH_CFG_REG_0_da_flash_ivfm_en_START (4)
#define REG_FLASH_CFG_REG_0_da_flash_ivfm_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_flash_ivfm_vhys : 1;
        unsigned char reserved : 7;
    } reg;
} REG_FLASH_CFG_REG_1_UNION;
#endif
#define REG_FLASH_CFG_REG_1_da_flash_ivfm_vhys_START (0)
#define REG_FLASH_CFG_REG_1_da_flash_ivfm_vhys_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_flash_resv0 : 8;
    } reg;
} REG_FLASH_CFG_REG_2_UNION;
#endif
#define REG_FLASH_CFG_REG_2_da_flash_resv0_START (0)
#define REG_FLASH_CFG_REG_2_da_flash_resv0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_flash_resv1 : 8;
    } reg;
} REG_FLASH_CFG_REG_3_UNION;
#endif
#define REG_FLASH_CFG_REG_3_da_flash_resv1_START (0)
#define REG_FLASH_CFG_REG_3_da_flash_resv1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_flash_resv2 : 8;
    } reg;
} REG_FLASH_CFG_REG_4_UNION;
#endif
#define REG_FLASH_CFG_REG_4_da_flash_resv2_START (0)
#define REG_FLASH_CFG_REG_4_da_flash_resv2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_flash_resv3 : 8;
    } reg;
} REG_FLASH_CFG_REG_5_UNION;
#endif
#define REG_FLASH_CFG_REG_5_da_flash_resv3_START (0)
#define REG_FLASH_CFG_REG_5_da_flash_resv3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_flash_strobe_in_ro : 1;
        unsigned char ad_flash_bb_eoss_ro : 1;
        unsigned char reserved : 6;
    } reg;
} REG_FLASH_RO_REG_UNION;
#endif
#define REG_FLASH_RO_REG_ad_flash_strobe_in_ro_START (0)
#define REG_FLASH_RO_REG_ad_flash_strobe_in_ro_END (0)
#define REG_FLASH_RO_REG_ad_flash_bb_eoss_ro_START (1)
#define REG_FLASH_RO_REG_ad_flash_bb_eoss_ro_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_flash_led1_code : 7;
        unsigned char reserved : 1;
    } reg;
} REG_FLASH_LED1_CODE_RO_UNION;
#endif
#define REG_FLASH_LED1_CODE_RO_da_flash_led1_code_START (0)
#define REG_FLASH_LED1_CODE_RO_da_flash_led1_code_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_flash_led2_code : 7;
        unsigned char reserved : 1;
    } reg;
} REG_FLASH_LED2_CODE_RO_UNION;
#endif
#define REG_FLASH_LED2_CODE_RO_da_flash_led2_code_START (0)
#define REG_FLASH_LED2_CODE_RO_da_flash_led2_code_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_flash_led3_code : 7;
        unsigned char reserved : 1;
    } reg;
} REG_FLASH_LED3_CODE_RO_UNION;
#endif
#define REG_FLASH_LED3_CODE_RO_da_flash_led3_code_START (0)
#define REG_FLASH_LED3_CODE_RO_da_flash_led3_code_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_ufcs_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_UFCS_EN_REG_UNION;
#endif
#define REG_UFCS_EN_REG_sc_ufcs_en_START (0)
#define REG_UFCS_EN_REG_sc_ufcs_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_ufcs_mode : 1;
        unsigned char sc_hreset_th : 2;
        unsigned char sc_frame_space_th : 3;
        unsigned char reserved : 2;
    } reg;
} REG_UFCS_CTRL_REG_UNION;
#endif
#define REG_UFCS_CTRL_REG_sc_ufcs_mode_START (0)
#define REG_UFCS_CTRL_REG_sc_ufcs_mode_END (0)
#define REG_UFCS_CTRL_REG_sc_hreset_th_START (1)
#define REG_UFCS_CTRL_REG_sc_hreset_th_END (2)
#define REG_UFCS_CTRL_REG_sc_frame_space_th_START (3)
#define REG_UFCS_CTRL_REG_sc_frame_space_th_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_hk_det_cnt_cfg : 3;
        unsigned char reserved : 5;
    } reg;
} REG_UFCS_HK_TIMES_REG_UNION;
#endif
#define REG_UFCS_HK_TIMES_REG_sc_hk_det_cnt_cfg_START (0)
#define REG_UFCS_HK_TIMES_REG_sc_hk_det_cnt_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_m0_baud_delta : 3;
        unsigned char reserved : 5;
    } reg;
} REG_UFCS_RX_M0_BAUD_REG_0_UNION;
#endif
#define REG_UFCS_RX_M0_BAUD_REG_0_sc_m0_baud_delta_START (0)
#define REG_UFCS_RX_M0_BAUD_REG_0_sc_m0_baud_delta_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_ufcs_anck_req_tmr : 8;
    } reg;
} REG_UFCS_ANCK_REQ_TMR_UNION;
#endif
#define REG_UFCS_ANCK_REQ_TMR_sc_ufcs_anck_req_tmr_START (0)
#define REG_UFCS_ANCK_REQ_TMR_sc_ufcs_anck_req_tmr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_ufcs_hw_rst : 1;
        unsigned char reserved : 7;
    } reg;
} REG_UFCS_HW_RST_CFG_UNION;
#endif
#define REG_UFCS_HW_RST_CFG_sc_ufcs_hw_rst_START (0)
#define REG_UFCS_HW_RST_CFG_sc_ufcs_hw_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_wd_clr : 1;
        unsigned char reserved : 7;
    } reg;
} REG_UFCS_WD_TMR_CLR_REG_UNION;
#endif
#define REG_UFCS_WD_TMR_CLR_REG_sc_wd_clr_START (0)
#define REG_UFCS_WD_TMR_CLR_REG_sc_wd_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_rev_tmr_clr : 1;
        unsigned char reserved : 7;
    } reg;
} REG_UFCS_REV_TMR_CLR_REG_UNION;
#endif
#define REG_UFCS_REV_TMR_CLR_REG_sc_rev_tmr_clr_START (0)
#define REG_UFCS_REV_TMR_CLR_REG_sc_rev_tmr_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_send_start : 1;
        unsigned char reserved : 7;
    } reg;
} REG_UFCS_TX_EN_REG_UNION;
#endif
#define REG_UFCS_TX_EN_REG_sc_send_start_START (0)
#define REG_UFCS_TX_EN_REG_sc_send_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_send_cable_rst : 1;
        unsigned char reserved : 7;
    } reg;
} REG_UFCS_TX_CABLE_RST_REG_UNION;
#endif
#define REG_UFCS_TX_CABLE_RST_REG_sc_send_cable_rst_START (0)
#define REG_UFCS_TX_CABLE_RST_REG_sc_send_cable_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_send_rst : 1;
        unsigned char reserved : 7;
    } reg;
} REG_UFCS_TX_RST_REG_UNION;
#endif
#define REG_UFCS_TX_RST_REG_sc_send_rst_START (0)
#define REG_UFCS_TX_RST_REG_sc_send_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_msg_anck_tmpl_dat0 : 8;
    } reg;
} REG_UFCS_TX_ANCK_TMPL_REG_0_UNION;
#endif
#define REG_UFCS_TX_ANCK_TMPL_REG_0_sc_msg_anck_tmpl_dat0_START (0)
#define REG_UFCS_TX_ANCK_TMPL_REG_0_sc_msg_anck_tmpl_dat0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_msg_anck_tmpl_dat1 : 8;
    } reg;
} REG_UFCS_TX_ANCK_TMPL_REG_1_UNION;
#endif
#define REG_UFCS_TX_ANCK_TMPL_REG_1_sc_msg_anck_tmpl_dat1_START (0)
#define REG_UFCS_TX_ANCK_TMPL_REG_1_sc_msg_anck_tmpl_dat1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_wd_cfg : 8;
    } reg;
} REG_UFCS_WD_CFG_UNION;
#endif
#define REG_UFCS_WD_CFG_sc_wd_cfg_START (0)
#define REG_UFCS_WD_CFG_sc_wd_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_auto_analysis_en : 8;
    } reg;
} REG_UFCS_RX_ANALYSIS_REG_UNION;
#endif
#define REG_UFCS_RX_ANALYSIS_REG_sc_auto_analysis_en_START (0)
#define REG_UFCS_RX_ANALYSIS_REG_sc_auto_analysis_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_hreset_en : 1;
        unsigned char sc_sender_resp_tmr_en : 1;
        unsigned char sc_rev_tmr_en : 1;
        unsigned char sc_wd_en : 1;
        unsigned char sc_ufcs_rx_anck_wr_en : 1;
        unsigned char sc_hw_crc_en : 1;
        unsigned char sc_auto_retrans_en : 1;
        unsigned char sc_auto_anck_en : 1;
    } reg;
} REG_UFCS_CTRL_EN_REG_1_UNION;
#endif
#define REG_UFCS_CTRL_EN_REG_1_sc_hreset_en_START (0)
#define REG_UFCS_CTRL_EN_REG_1_sc_hreset_en_END (0)
#define REG_UFCS_CTRL_EN_REG_1_sc_sender_resp_tmr_en_START (1)
#define REG_UFCS_CTRL_EN_REG_1_sc_sender_resp_tmr_en_END (1)
#define REG_UFCS_CTRL_EN_REG_1_sc_rev_tmr_en_START (2)
#define REG_UFCS_CTRL_EN_REG_1_sc_rev_tmr_en_END (2)
#define REG_UFCS_CTRL_EN_REG_1_sc_wd_en_START (3)
#define REG_UFCS_CTRL_EN_REG_1_sc_wd_en_END (3)
#define REG_UFCS_CTRL_EN_REG_1_sc_ufcs_rx_anck_wr_en_START (4)
#define REG_UFCS_CTRL_EN_REG_1_sc_ufcs_rx_anck_wr_en_END (4)
#define REG_UFCS_CTRL_EN_REG_1_sc_hw_crc_en_START (5)
#define REG_UFCS_CTRL_EN_REG_1_sc_hw_crc_en_END (5)
#define REG_UFCS_CTRL_EN_REG_1_sc_auto_retrans_en_START (6)
#define REG_UFCS_CTRL_EN_REG_1_sc_auto_retrans_en_END (6)
#define REG_UFCS_CTRL_EN_REG_1_sc_auto_anck_en_START (7)
#define REG_UFCS_CTRL_EN_REG_1_sc_auto_anck_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_auto_baud_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_UFCS_CTRL_EN_REG_2_UNION;
#endif
#define REG_UFCS_CTRL_EN_REG_2_sc_auto_baud_en_START (0)
#define REG_UFCS_CTRL_EN_REG_2_sc_auto_baud_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_send_resp_tmr_clr : 1;
        unsigned char reserved : 7;
    } reg;
} REG_UFCS_SEND_TMR_CLR_REG_UNION;
#endif
#define REG_UFCS_SEND_TMR_CLR_REG_sc_send_resp_tmr_clr_START (0)
#define REG_UFCS_SEND_TMR_CLR_REG_sc_send_resp_tmr_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_frame_idle_cnt_cfg : 3;
        unsigned char reserved : 5;
    } reg;
} REG_UFCS_TX_CTRL_REG_UNION;
#endif
#define REG_UFCS_TX_CTRL_REG_sc_frame_idle_cnt_cfg_START (0)
#define REG_UFCS_TX_CTRL_REG_sc_frame_idle_cnt_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_baud_cfg : 2;
        unsigned char reserved : 6;
    } reg;
} REG_UFCS_TX_BAUD_REG_UNION;
#endif
#define REG_UFCS_TX_BAUD_REG_sc_baud_cfg_START (0)
#define REG_UFCS_TX_BAUD_REG_sc_baud_cfg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_ufcs_soft_rst_n : 1;
        unsigned char reserved : 7;
    } reg;
} REG_UFCS_SOFT_RST_EN_REG_UNION;
#endif
#define REG_UFCS_SOFT_RST_EN_REG_sc_ufcs_soft_rst_n_START (0)
#define REG_UFCS_SOFT_RST_EN_REG_sc_ufcs_soft_rst_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_read_rx_req : 1;
        unsigned char reserved : 7;
    } reg;
} REG_UFCS_RX_READ_REQ_UNION;
#endif
#define REG_UFCS_RX_READ_REQ_sc_read_rx_req_START (0)
#define REG_UFCS_RX_READ_REQ_sc_read_rx_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char baud_final_l : 8;
    } reg;
} REG_UFCS_RX_BAUD_RO_0_UNION;
#endif
#define REG_UFCS_RX_BAUD_RO_0_baud_final_l_START (0)
#define REG_UFCS_RX_BAUD_RO_0_baud_final_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char baud_final_h : 2;
        unsigned char reserved : 6;
    } reg;
} REG_UFCS_RX_BAUD_RO_1_UNION;
#endif
#define REG_UFCS_RX_BAUD_RO_1_baud_final_h_START (0)
#define REG_UFCS_RX_BAUD_RO_1_baud_final_h_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char baud_final_step : 2;
        unsigned char reserved : 6;
    } reg;
} REG_UFCS_RX_BAUD_STEP_RO_UNION;
#endif
#define REG_UFCS_RX_BAUD_STEP_RO_baud_final_step_START (0)
#define REG_UFCS_RX_BAUD_STEP_RO_baud_final_step_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ro_ufcs_rx_busy : 1;
        unsigned char ro_ufcs_rx_cache_busy : 1;
        unsigned char ro_ufcs_rx_read_ack : 1;
        unsigned char reserved : 5;
    } reg;
} REG_UFCS_RX_STATUS_RO_UNION;
#endif
#define REG_UFCS_RX_STATUS_RO_ro_ufcs_rx_busy_START (0)
#define REG_UFCS_RX_STATUS_RO_ro_ufcs_rx_busy_END (0)
#define REG_UFCS_RX_STATUS_RO_ro_ufcs_rx_cache_busy_START (1)
#define REG_UFCS_RX_STATUS_RO_ro_ufcs_rx_cache_busy_END (1)
#define REG_UFCS_RX_STATUS_RO_ro_ufcs_rx_read_ack_START (2)
#define REG_UFCS_RX_STATUS_RO_ro_ufcs_rx_read_ack_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_ufcs_wd_tmr : 1;
        unsigned char irq_ufcs_hw_rst : 1;
        unsigned char irq_ufcs_rx_ack_err : 1;
        unsigned char irq_ufcs_rx_ack_ok : 1;
        unsigned char irq_ufcs_rx_end : 1;
        unsigned char reserved : 3;
    } reg;
} REG_UFCS_IRQ_FLG_0_UNION;
#endif
#define REG_UFCS_IRQ_FLG_0_irq_ufcs_wd_tmr_START (0)
#define REG_UFCS_IRQ_FLG_0_irq_ufcs_wd_tmr_END (0)
#define REG_UFCS_IRQ_FLG_0_irq_ufcs_hw_rst_START (1)
#define REG_UFCS_IRQ_FLG_0_irq_ufcs_hw_rst_END (1)
#define REG_UFCS_IRQ_FLG_0_irq_ufcs_rx_ack_err_START (2)
#define REG_UFCS_IRQ_FLG_0_irq_ufcs_rx_ack_err_END (2)
#define REG_UFCS_IRQ_FLG_0_irq_ufcs_rx_ack_ok_START (3)
#define REG_UFCS_IRQ_FLG_0_irq_ufcs_rx_ack_ok_END (3)
#define REG_UFCS_IRQ_FLG_0_irq_ufcs_rx_end_START (4)
#define REG_UFCS_IRQ_FLG_0_irq_ufcs_rx_end_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_ufcs_bps_det : 1;
        unsigned char irq_ufcs_rcvr_tmr : 1;
        unsigned char irq_ufcs_sdr_tmr : 1;
        unsigned char irq_ufcs_ack_tmr : 1;
        unsigned char irq_ufcs_tx_end : 1;
        unsigned char irq_ufcs_rer_over : 1;
        unsigned char irq_ufcs_hk_fail : 1;
        unsigned char irq_ufcs_hk_det : 1;
    } reg;
} REG_UFCS_IRQ_FLG_1_UNION;
#endif
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_bps_det_START (0)
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_bps_det_END (0)
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_rcvr_tmr_START (1)
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_rcvr_tmr_END (1)
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_sdr_tmr_START (2)
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_sdr_tmr_END (2)
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_ack_tmr_START (3)
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_ack_tmr_END (3)
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_tx_end_START (4)
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_tx_end_END (4)
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_rer_over_START (5)
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_rer_over_END (5)
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_hk_fail_START (6)
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_hk_fail_END (6)
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_hk_det_START (7)
#define REG_UFCS_IRQ_FLG_1_irq_ufcs_hk_det_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_irq_ufcs_wd_tmr_mask : 1;
        unsigned char sc_irq_ufcs_hw_rst_mask : 1;
        unsigned char sc_irq_ufcs_rx_ack_err_mask : 1;
        unsigned char sc_irq_ufcs_rx_ack_ok_mask : 1;
        unsigned char sc_irq_ufcs_rx_end_mask : 1;
        unsigned char reserved : 3;
    } reg;
} REG_UFCS_IRQ_MASK_0_UNION;
#endif
#define REG_UFCS_IRQ_MASK_0_sc_irq_ufcs_wd_tmr_mask_START (0)
#define REG_UFCS_IRQ_MASK_0_sc_irq_ufcs_wd_tmr_mask_END (0)
#define REG_UFCS_IRQ_MASK_0_sc_irq_ufcs_hw_rst_mask_START (1)
#define REG_UFCS_IRQ_MASK_0_sc_irq_ufcs_hw_rst_mask_END (1)
#define REG_UFCS_IRQ_MASK_0_sc_irq_ufcs_rx_ack_err_mask_START (2)
#define REG_UFCS_IRQ_MASK_0_sc_irq_ufcs_rx_ack_err_mask_END (2)
#define REG_UFCS_IRQ_MASK_0_sc_irq_ufcs_rx_ack_ok_mask_START (3)
#define REG_UFCS_IRQ_MASK_0_sc_irq_ufcs_rx_ack_ok_mask_END (3)
#define REG_UFCS_IRQ_MASK_0_sc_irq_ufcs_rx_end_mask_START (4)
#define REG_UFCS_IRQ_MASK_0_sc_irq_ufcs_rx_end_mask_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_irq_ufcs_bps_det_mask : 1;
        unsigned char sc_irq_ufcs_rcvr_tmr_mask : 1;
        unsigned char sc_irq_ufcs_sdr_tmr_mask : 1;
        unsigned char sc_irq_ufcs_ack_tmr_mask : 1;
        unsigned char sc_irq_ufcs_tx_end_mask : 1;
        unsigned char sc_irq_ufcs_rer_over_mask : 1;
        unsigned char sc_irq_ufcs_hk_fail_mask : 1;
        unsigned char sc_irq_ufcs_hk_det_mask : 1;
    } reg;
} REG_UFCS_IRQ_MASK_1_UNION;
#endif
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_bps_det_mask_START (0)
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_bps_det_mask_END (0)
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_rcvr_tmr_mask_START (1)
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_rcvr_tmr_mask_END (1)
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_sdr_tmr_mask_START (2)
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_sdr_tmr_mask_END (2)
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_ack_tmr_mask_START (3)
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_ack_tmr_mask_END (3)
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_tx_end_mask_START (4)
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_tx_end_mask_END (4)
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_rer_over_mask_START (5)
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_rer_over_mask_END (5)
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_hk_fail_mask_START (6)
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_hk_fail_mask_END (6)
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_hk_det_mask_START (7)
#define REG_UFCS_IRQ_MASK_1_sc_irq_ufcs_hk_det_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_inf_en_sel : 8;
    } reg;
} REG_UFCS_MISC_EN_SEL_REG_UNION;
#endif
#define REG_UFCS_MISC_EN_SEL_REG_sc_inf_en_sel_START (0)
#define REG_UFCS_MISC_EN_SEL_REG_sc_inf_en_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 1;
        unsigned char sc_ufcs_dm_out_en : 1;
        unsigned char sc_ufcs_dm_din_en : 1;
        unsigned char sc_ufcs_dp_out_en : 1;
        unsigned char sc_ufcs_dp_din_en : 1;
        unsigned char reserved_1 : 3;
    } reg;
} REG_UFCS_MISC_EN_REG_UNION;
#endif
#define REG_UFCS_MISC_EN_REG_sc_ufcs_dm_out_en_START (1)
#define REG_UFCS_MISC_EN_REG_sc_ufcs_dm_out_en_END (1)
#define REG_UFCS_MISC_EN_REG_sc_ufcs_dm_din_en_START (2)
#define REG_UFCS_MISC_EN_REG_sc_ufcs_dm_din_en_END (2)
#define REG_UFCS_MISC_EN_REG_sc_ufcs_dp_out_en_START (3)
#define REG_UFCS_MISC_EN_REG_sc_ufcs_dp_out_en_END (3)
#define REG_UFCS_MISC_EN_REG_sc_ufcs_dp_din_en_START (4)
#define REG_UFCS_MISC_EN_REG_sc_ufcs_dp_din_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_stm_fsm_reset : 1;
        unsigned char sc_hreset_n_mask : 1;
        unsigned char reserved : 6;
    } reg;
} REG_UFCS_RX_DEBUG_REG_UNION;
#endif
#define REG_UFCS_RX_DEBUG_REG_sc_stm_fsm_reset_START (0)
#define REG_UFCS_RX_DEBUG_REG_sc_stm_fsm_reset_END (0)
#define REG_UFCS_RX_DEBUG_REG_sc_hreset_n_mask_START (1)
#define REG_UFCS_RX_DEBUG_REG_sc_hreset_n_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ro_ufcs_rx_package_type : 7;
        unsigned char reserved : 1;
    } reg;
} REG_UFCS_RX_PTYPE_RO_UNION;
#endif
#define REG_UFCS_RX_PTYPE_RO_ro_ufcs_rx_package_type_START (0)
#define REG_UFCS_RX_PTYPE_RO_ro_ufcs_rx_package_type_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ufcs_rx_fault_0 : 8;
    } reg;
} REG_UFCS_RX_FAULT_REG_0_UNION;
#endif
#define REG_UFCS_RX_FAULT_REG_0_ufcs_rx_fault_0_START (0)
#define REG_UFCS_RX_FAULT_REG_0_ufcs_rx_fault_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ufcs_rx_fault_1 : 8;
    } reg;
} REG_UFCS_RX_FAULT_REG_1_UNION;
#endif
#define REG_UFCS_RX_FAULT_REG_1_ufcs_rx_fault_1_START (0)
#define REG_UFCS_RX_FAULT_REG_1_ufcs_rx_fault_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char hk_st_curr : 3;
        unsigned char tx_st_curr : 2;
        unsigned char reserved : 3;
    } reg;
} REG_UFCS_STM_DEBUG_REG_UNION;
#endif
#define REG_UFCS_STM_DEBUG_REG_hk_st_curr_START (0)
#define REG_UFCS_STM_DEBUG_REG_hk_st_curr_END (2)
#define REG_UFCS_STM_DEBUG_REG_tx_st_curr_START (3)
#define REG_UFCS_STM_DEBUG_REG_tx_st_curr_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ufcs_testsig_sel : 4;
        unsigned char ufcs_test_bus_sel : 3;
        unsigned char reserved : 1;
    } reg;
} REG_UFCS_TESTBUS_RO_SEL_REG_UNION;
#endif
#define REG_UFCS_TESTBUS_RO_SEL_REG_ufcs_testsig_sel_START (0)
#define REG_UFCS_TESTBUS_RO_SEL_REG_ufcs_testsig_sel_END (3)
#define REG_UFCS_TESTBUS_RO_SEL_REG_ufcs_test_bus_sel_START (4)
#define REG_UFCS_TESTBUS_RO_SEL_REG_ufcs_test_bus_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ufcs_testbus : 8;
    } reg;
} REG_UFCS_TESTBUS_RO_DATA_REG_UNION;
#endif
#define REG_UFCS_TESTBUS_RO_DATA_REG_ufcs_testbus_START (0)
#define REG_UFCS_TESTBUS_RO_DATA_REG_ufcs_testbus_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ad_ufcs_reserve : 8;
    } reg;
} REG_UFCS_AD_RESERVE_REG_UNION;
#endif
#define REG_UFCS_AD_RESERVE_REG_ad_ufcs_reserve_START (0)
#define REG_UFCS_AD_RESERVE_REG_ad_ufcs_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char da_ufcs_reserve : 8;
    } reg;
} REG_UFCS_DA_RESERVE_REG_UNION;
#endif
#define REG_UFCS_DA_RESERVE_REG_da_ufcs_reserve_START (0)
#define REG_UFCS_DA_RESERVE_REG_da_ufcs_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ufcs_clk_dbg_en : 1;
        unsigned char reserved : 7;
    } reg;
} REG_UFCS_CLK_EN_UNION;
#endif
#define REG_UFCS_CLK_EN_ufcs_clk_dbg_en_START (0)
#define REG_UFCS_CLK_EN_ufcs_clk_dbg_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sc_ufcs_test_tx_data_sel : 1;
        unsigned char sc_ufcs_test_tx_data : 1;
        unsigned char reserved : 6;
    } reg;
} REG_UFCS_TEST_SIG_UNION;
#endif
#define REG_UFCS_TEST_SIG_sc_ufcs_test_tx_data_sel_START (0)
#define REG_UFCS_TEST_SIG_sc_ufcs_test_tx_data_sel_END (0)
#define REG_UFCS_TEST_SIG_sc_ufcs_test_tx_data_START (1)
#define REG_UFCS_TEST_SIG_sc_ufcs_test_tx_data_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ufcs_tx_msg_len_0 : 8;
    } reg;
} REG_UFCS_TX_MSG_LEN_0_UNION;
#endif
#define REG_UFCS_TX_MSG_LEN_0_ufcs_tx_msg_len_0_START (0)
#define REG_UFCS_TX_MSG_LEN_0_ufcs_tx_msg_len_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ufcs_tx_msg_len_1 : 8;
    } reg;
} REG_UFCS_TX_MSG_LEN_1_UNION;
#endif
#define REG_UFCS_TX_MSG_LEN_1_ufcs_tx_msg_len_1_START (0)
#define REG_UFCS_TX_MSG_LEN_1_ufcs_tx_msg_len_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} REG_UFCS_TX_RESERVED0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} REG_UFCS_TX_RESERVED1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char tx_ram_data_0 : 8;
    } reg;
} REG_TX_RAM_DATA_0_UNION;
#endif
#define REG_TX_RAM_DATA_0_tx_ram_data_0_START (0)
#define REG_TX_RAM_DATA_0_tx_ram_data_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} REG_TX_RAM_DATA_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} REG_TX_RAM_DATA_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ufcs_rx_msg_len_h : 1;
        unsigned char reserved : 7;
    } reg;
} REG_UFCS_RX_MSG_LEN_0_UNION;
#endif
#define REG_UFCS_RX_MSG_LEN_0_ufcs_rx_msg_len_h_START (0)
#define REG_UFCS_RX_MSG_LEN_0_ufcs_rx_msg_len_h_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ufcs_rx_msg_len_l : 8;
    } reg;
} REG_UFCS_RX_MSG_LEN_1_UNION;
#endif
#define REG_UFCS_RX_MSG_LEN_1_ufcs_rx_msg_len_l_START (0)
#define REG_UFCS_RX_MSG_LEN_1_ufcs_rx_msg_len_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} REG_UFCS_RX_RESERVED0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} REG_UFCS_RX_RESERVED1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rx_ram_data_0 : 8;
    } reg;
} REG_RX_RAM_DATA_0_UNION;
#endif
#define REG_RX_RAM_DATA_0_rx_ram_data_0_START (0)
#define REG_RX_RAM_DATA_0_rx_ram_data_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} REG_RX_RAM_DATA_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} REG_RX_RAM_DATA_2_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
