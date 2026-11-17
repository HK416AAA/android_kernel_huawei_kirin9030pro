/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
 * Description: Phy driver.
 * Author: gemingjia@h-partners.com
 * Create: 2025-04-24
 */

#ifndef _HW_PHY_DRIVER
#define _HW_PHY_DRIVER

#define PHY_INTERRUPT_REG			0xa002
#define PHY_NODE_SWITCH				0xc00
#define PHY_POWER_DOWN_WAITTIME		4000
#define PHY_INTERRUPT_WAIT_TIME		200
#define PHY_INTERRUPT_WAIT_CYCLE	5
#define PHY_INTERRUPT_REG_BIT        BIT(6)
#define PHY_INTERRUPT_SOFT_RESET     BIT(15)
#define PHY_REG_FLAG_CLEAR_MASK 		0x1000
#define PHY_SDS_WORK_REG 			0x0140
#define PHY_INT_SUCC_OFFSET			 10
#define PHY_INT_FAIL_OFFSET			 11
#define PHY_GET_MASK_VALUE			0x01

#define PHY_ID_MASK           0x00000fff
#define MPHY_ID_MASK          0x0000ffff

#define PHY_ID                   		0x0000011a
#define MAX_PHY_ADDR 					32
#define PHY_ETHERNET_REG				1

#define PHY_REG_SPEC_STATUS             0x11
#define REG_DEBUG_ADDR_OFFSET           0x1e
#define REG_DEBUG_DATA                  0x1f

#define PHY_EXTREG_SLEEP_CONTROL1    0x27
#define PHY_EN_SLEEP_SW_BIT          15
#define PHY_REG_HIGH_ADDR            8
#define PHY_STRAP_POLL_ADDR          0x7
#define PHY_CONFIG_CONTROL1          0xc

#define PHY_REG_MODE                 0xa000
#define PHY_STRAP_POLL               0xa001
#define PHY_SPEED_MODE               0xc000
#define PHY_DUPLEX                   0x2000
#define PHY_SPEED_MODE_BIT           14
#define PHY_DUPLEX_BIT               13
#define PHY_LINK_STATUS_BIT          10

#define PHY_UTP_INTR_REG              0x12
#define PHY_WOL_FEATURE_INTR_MASK          BIT(6)
#define PHY_LINK_SUCCEED_INTR_MASK          BIT(10)
#define PHY_LINK_FAILED_INTR_MASK          BIT(11)
#define PHY_DUPLEX_CHANGED_INTR_MASK          BIT(13)
#define PHY_SPEED_CHANGED_INTR_MASK          BIT(14)
#define PHY_INTRS_MASK (PHY_LINK_SUCCEED_INTR_MASK | PHY_LINK_FAILED_INTR_MASK | \
	PHY_WOL_FEATURE_INTR_MASK)

#define PHY_UTP_INTR_STATUS_REG              0x13
#define PHY_WOL_FEATURE_INTR          BIT(6)
#define PHY_LINK_SUCCEED_INTR          BIT(10)
#define PHY_LINK_FAILED_INTR          BIT(11)
#define PHY_DUPLEX_CHANGED_INTR          BIT(13)
#define PHY_SPEED_CHANGED_INTR          BIT(14)
#define PHY_INTRS_STATUS (PHY_WOL_FEATURE_INTR | PHY_LINK_SUCCEED_INTR | \
	PHY_LINK_FAILED_INTR | PHY_DUPLEX_CHANGED_INTR | PHY_SPEED_CHANGED_INTR)

#define PHY_WOL_FEATURE_MACADDR2_4_MAGIC_PACKET    0xa007
#define PHY_WOL_FEATURE_MACADDR1_4_MAGIC_PACKET    0xa008
#define PHY_WOL_FEATURE_MACADDR0_4_MAGIC_PACKET    0xa009

#define PHY_WOL_FEATURE_WOL_LTH_SEL_0       0
#define PHY_WOL_FEATURE_WOL_LTH_SEL_1       1
#define PHY_WOL_FEATURE_WOL_INT_TYPE_SEL    2
#define PHY_WOL_FEATURE_WOL_EN              3
#define PHY_WOL_FEATURE_WOL_SRC_SEL         4
#define PHY_WOL_FEATURE_WOL_SRC_MANUAL      5
#define PHY_WOL_FEATURE_PMEB_INTB_SEL       6

#define PHY_WOL_FEATURE_REG_CFG               0xa00a
#define PHY_WOL_FEATURE_TYPE_CFG              BIT(0)    /* WOL TYPE Config */
#define PHY_WOL_FEATURE_ENABLE_CFG            BIT(3)    /* WOL Enable Config */
#define PHY_WOL_FEATURE_INTR_SEL_CFG          BIT(6)    /* WOL Event Interrupt Enable Config */
#define PHY_WOL_FEATURE_WIDTH1_CFG            BIT(1)    /* WOL Pulse Width Config */
#define PHY_WOL_FEATURE_WIDTH2_CFG            BIT(2)    /* WOL Pulse Width Config */
#define PHY_EXLOOPBACK_CLOSE_SLEEP			BIT(15)
#define PHY_EXLOOPBACK_SOFT_RESET			    BIT(4)

#define PHY_REG_SPACE_UTP             0
#define PHY_REG_SPACE_FIBER           2

#define PHY_EXTERNAL_LOOPBACK_SLEEP_CLOSE 0x27
#define PHY_EXTERNAL_LOOPBACK_UTP_REG 0xa
#define PHY_EXTERNAL_LOOPBACK_MII_REG 0x0
#define PHY_EXTERNAL_LOOPBACK_TEN 0x8100
#define PHY_EXTERNAL_LOOPBACK_HUNDRED 0xa100
#define PHY_EXTERNAL_LOOPBACK_THOUSAND 0x8140

#define PHY_EXTERNAL_LOOPBACK_MONDE_TEN 10
#define PHY_EXTERNAL_LOOPBACK_MONDE_HUNDRED 100
#define PHY_EXTERNAL_LOOPBACK_MONDE_THOUSAND 1000

#define PHY_EXTERNAL_LOOPBACK_MAX_TRY_TIME  200
#define PHY_EXTERNAL_LOOPBACK_WAIT_TIME     10

#define PHY_INTERCONNECT_REG_ONE	0x51
#define PHY_INTERCONNECT_REG_TWO	0x57
#define PHY_INTERCONNECT_REG_ONE_INDEX	0x47f
#define PHY_INTERCONNECT_REG_TWO_INDEX	0x2d4f

#define PHY_ID_DEFAULT   0xFFFF

typedef enum {
	SP_TEN,
	SP_HUNDRED,
	SP_THOUSAND
} EXTERNAL_LOOPBACK_SPEED;

#define GET_EXTERNAL_LOOPBACK_SPEED_DIR  _IOR('M', 0x01, EXTERNAL_LOOPBACK_SPEED)

#define GET_EXTERNAL_LOOPBACK_SPEED_DIR_COMP   _IOW('M', 0x01, EXTERNAL_LOOPBACK_SPEED)

/* PHY polling mode */
#define PHY_MODE_FIBER           1 // fiber mode only
#define PHY_MODE_UTP             2 // utp mode only
#define PHY_MODE_POLL            3 // fiber and utp, poll mode

/* PHY polling val */
#define PHY_VAL_FIBER            5 // fiber mode only
#define PHY_VAL_POLL             7 // utp mode only

/* PHY adjust status*/
#define PHY_ADJUST_STATUS_TEN             0
#define PHY_ADJUST_STATUS_HUNDRED         1
#define PHY_ADJUST_STATUS_THOUSAND        2

#define phy_check_null_and_return(condition, ret, msg) \
	do { \
		if(condition) { \
			pr_err("[HW_PHY] [%s:%d] %s\n", __func__, __LINE__, msg); \
			return ret; \
		} \
	} while(0)

#define phy_check_negative_and_return(condition, ret, msg) \
	do { \
		const typeof(condition) __cond = (condition); \
		if(__cond < 0) { \
			pr_err("[HW_PHY] [%s:%d] %s %d\n", __func__, __LINE__, msg, (int)__cond); \
			return ret; \
		} \
	} while(0)

#endif