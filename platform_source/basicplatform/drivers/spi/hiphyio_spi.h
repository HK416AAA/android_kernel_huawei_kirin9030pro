/*
 * hiphyio_spi.h. A driver for the SPI bus master.
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __HIPHYIO_SPI_H_
#define __HIPHYIO_SPI_H_

/* error number */
#define E_HWSPI_LOCK        1
#define E_SPI_NO_CLK        2
#define E_SPI_NO_CLK_EN     3
#define E_SPI_CLK_SET_RATE  4
#define E_SPI_PARAMS        5

/* register bit */
#define BIT_CSEN            0U
#define BIT_CPOL            2U
#define BIT_CPHA            3U
#define BIT_DRPR            4U
#define BIT_DRPO            12U
#define BIT_FRAME           20U
#define BIT_hiphyioPD            25U
#define BIT_TXDMAE          26U
#define BIT_RXDMAE          27U

#define GET_HARDWARE_TIMEOUT  10000
#define ENUM_SPI_HWSPIN_LOCK  27

/*
 * This macro is used to define some register default values.
 * reg is masked with mask, the OR:ed with an (again masked)
 * val shifted sb steps to the left.
 */
#define HIPHYIO_WRITE_BITS(reg, val, mask, sb) \
	((reg) = ((reg) & ~(mask)) | (((val) << (sb)) & (mask)))

/*
 * This macro is also used to define some default values.
 * It will just shift val by sb steps to the left and mask
 * the result with mask.
 */
#define GEN_MASK_BITS(val, mask, sb) \
	(((val) << (sb)) & (mask))

#define DO_NOT_QUEUE_DMA         0
#define QUEUE_DMA                1
#define RX_TRANSFER              1
#define TX_TRANSFER              2
#define FIFO_DEPTH               256

/*
 * Macros to access HIPHYIO Registers with their offsets
 */
#define HIPHYIO_CSCR(r) ((r) + 0x000) /* cs register */
#define HIPHYIO_COMMONCR(r) ((r) + 0x004) /* spi common register */
#define HIPHYIO_ENR(r) ((r) + 0x008) /* spi enable register */
#define HIPHYIO_FIFOCR(r) ((r) + 0x00C) /* fifo level control register */
#define HIPHYIO_IMC(r) ((r) + 0x010) /* interrupt mask register */
#define HIPHYIO_DIN(r) ((r) + 0x014) /* data in register */
#define HIPHYIO_DOUT(r) ((r) + 0x018) /* data out register */
#define HIPHYIO_SR(r) ((r) + 0x01C)  /* status register */
#define HIPHYIO_RIS(r) ((r) + 0x020) /* raw interrupt register */
#define HIPHYIO_MIS(r) ((r) + 0x024) /* after mask interrupt status register */
#define HIPHYIO_ICR(r) ((r) + 0x028) /* interrupt clear register */
#define HIPHYIO_RIS(r) ((r) + 0x020) /* raw interrupt register */
#define HIPHYIO_MIS(r) ((r) + 0x024) /* after mask interrupt status register */
#define HIPHYIO_ICR(r) ((r) + 0x028) /* interrupt clear register */
#define HIPHYIO_DMA_CTRL(r)  ((r) + 0x100) /* interrupt clear register */
#define HIPHYIO_SDMA_ADDR_H_R(r) ((r) + 0x104) /* rx buffer addr high */
#define HIPHYIO_SDMA_ADDR_L_R(r) ((r) + 0x108) /* rx buffer addr low */
#define HIPHYIO_SDMA_ADDR_H_W(r) ((r) + 0x10c) /* tx buffer addr high */
#define HIPHYIO_SDMA_ADDR_L_W(r) ((r) + 0x110) /* tx buffer addr low */
#define HIPHYIO_DMA_CMD_START(r) ((r) + 0x124) /* exclusive dma enable */
#define INTR_SPI_DMA_MASK(r) ((r) + 0x128) /* exclusive dma irq mask */
#define INTR_SPI_DMA_CLR(r) ((r) + 0x12c) /* exclusive dma irq clr */
#define INTR_SPI_DMA_RAW(r) ((r) + 0x130) /* exclusive dma irq row */
#define INTR_SPI_DMA(r) ((r) + 0x134)     /* exclusive dma irq */
#define SPI_DMA_TRANS_STAT(r) ((r) + 0x1D4) /* exclusive dma trans stat */

#define HIPHYIO_VER(r) ((r) + 0xFE0) /* version register */

/*
 * SPI CS Control register -- HIPHYIO_CSCR
 */
#define HIPHYIO_CSCR_MASK_CSEN (0x1U << 0)

/*
 * SPI Common Control register--HIPHYIO_COMMONCR
 */
#define HIPHYIO_COMMONCR_LOOPBACK (0x1U << 1)
#define HIPHYIO_COMMONCR_MASK_CPOL (0x1U << 2)
#define HIPHYIO_COMMONCR_MASK_CPHA (0x1U << 3)
#define HIPHYIO_COMMONCR_MASK_DRPR (0xFFU << 4)
#define HIPHYIO_COMMONCR_MASK_DRPO (0xFFU << 12)  /* clk divider Prescale */
#define HIPHYIO_COMMONCR_MASK_FRAMESIZE (0x0FU << 20) /* Effective data bit width */
#define HIPHYIO_COMMONCR_MASK_HSPD (0x1U << 25)   /* Transmit mode high/nomal */
#define HIPHYIO_COMMONCR_MASK_TXDMAE (0x1U << 26) /* Transmit DMA Enable bit */
#define HIPHYIO_COMMONCR_MASK_RXDMAE (0x1U << 27) /* Receive DMA Enable bit */
#define HIPHYIO_COMMONCR_MASK_TIMEOUTCNT (0x3U << 28) /* Receive FIFO timeout count */

/*
 * SPI Enable Register -- HIPHYIO_ENR
 */
#define HIPHYIO_ENR_MASK_EN (0x1U << 0) /* spi enable */

/*
 * HIPHYIO Status Register - HIPHYIO_SR
 */
#define HIPHYIO_SR_MASK_TFE   (0x1U << 0) /* Transmit FIFO empty */
#define HIPHYIO_SR_MASK_TNF   (0x1U << 1) /* Transmit FIFO not fUl */
#define HIPHYIO_SR_MASK_RNE   (0x1U << 2) /* Receive FIFO not empty */
#define HIPHYIO_SR_MASK_RFF   (0x1U << 3) /* Receive FIFO fUl */
#define HIPHYIO_SR_MASK_BSY   (0x1U << 4) /* Busy Flag */

/*
 * HIPHYIO TX/RX FIFO Register - HIPHYIO_FIFOCR
 */
#define HIPHYIO_FIFOCR_MASK_TXDMA (0x07U << 0)
#define HIPHYIO_FIFOCR_MASK_TXINT (0x3U << 3)
#define HIPHYIO_FIFOCR_MASK_RXDMA (0x7U << 6)
#define HIPHYIO_FIFOCR_MASK_RXINT (0x3U << 9)
#define HIPHYIO_FIFOCR_MASK_TXINT_V600 (0x7U << 3)
#define HIPHYIO_FIFOCR_MASK_RXINT_V600 (0x7U << 9)

/*
 * HIPHYIO Interrupt Mask Set/Clear Register - HIPHYIO_IMC
 */
#define HIPHYIO_IMC_MASK_RORIM (0x1U << 0) /* Receive Overrun Interrupt mask */
#define HIPHYIO_IMC_MASK_RTIM  (0x1U << 1) /* Receive timeout Interrupt mask */
#define HIPHYIO_IMC_MASK_RXIM  (0x1U << 2) /* Receive FIFO Interrupt mask */
#define HIPHYIO_IMC_MASK_TXIM  (0x1U << 3) /* Transmit FIFO Interrupt mask */

/*
 * HIPHYIO Raw Interrupt Status Register - HIPHYIO_RIS
 */
/* Receive Overrun Raw Interrupt status */
#define HIPHYIO_RIS_MASK_RORRIS		(0x1U << 0)
/* Receive Timeout Raw Interrupt status */
#define HIPHYIO_RIS_MASK_RTRIS		(0x1U << 1)
/* Receive FIFO Raw Interrupt status */
#define HIPHYIO_RIS_MASK_RXRIS		(0x1U << 2)
/* Transmit FIFO Raw Interrupt status */
#define HIPHYIO_RIS_MASK_TXRIS		(0x1U << 3)

/*
 * HIPHYIO Masked Interrupt Status Register - HIPHYIO_MIS
 */
/* Receive Overrun Masked Interrupt status */
#define HIPHYIO_MIS_MASK_RORMIS		(0x1U << 0)
/* Receive Timeout Masked Interrupt status */
#define HIPHYIO_MIS_MASK_RTMIS		(0x1U << 1)
/* Receive FIFO Masked Interrupt status */
#define HIPHYIO_MIS_MASK_RXMIS		(0x1U << 2)
/* Transmit FIFO Masked Interrupt status */
#define HIPHYIO_MIS_MASK_TXMIS		(0x1U << 3)

/*
 * HIPHYIO Interrupt Clear Register - HIPHYIO_ICR
 */
/* Receive Overrun Raw Clear Interrupt bit */
#define HIPHYIO_ICR_MASK_RORIC		(0x1U << 0)
/* Receive Timeout Clear Interrupt bit */
#define HIPHYIO_ICR_MASK_RTIC		(0x1U << 1)

/* SPI_DMA_CTRL */
#define DMA_ENBALE_APB          (0x1U << 21)
#define DMA_SDMA_MODE           0
#define DMA_ADMA_MODE           (0x1U << 20)

/* SPI_DMA_CMD_START */
#define DMA_CMD_START           (0x1U << 0)

/*
 * exclusive dma interrupt bit(0x58~0x64)
 */
/* exclusive dma transfer complete */
#define INT_DMA_COMPLETE    (0x1U << 12)
/* read addr miss align */
#define INT_DMA_RD_DESCR_ADDR_ERR   (0x1U << 9)
/* write addr miss align */
#define INT_DMA_WR_DESCR_ADDR_ERR   (0x1U << 6)
/* dma read response error */
#define INT_DMA_RD_RRESP_ERR   (0x1U << 5)
/* dma write response error */
#define INT_DMA_WR_BRESP_ERR   (0x1U << 3)
/* dma rx fifo overflow */
#define INT_DMA_RX_OVERFLOW   (0x1U << 2)
/* dma rx fifo underflow */
#define INT_DMA_RX_UNDERFLOW  (0x1U << 1)
/* dma tx fifo overflow */
#define INT_DMA_TX_OVERFLOW  (0x1U << 0)

#define EXCLUSIVE_DMA_ALL_INT 0x1FFF

#define MSG_STATE_START			((void *) 0)
#define MSG_STATE_RUNNING		((void *) 1)
#define MSG_STATE_DONE			((void *) 2)
#define MSG_STATE_ERROR			((void *) -1)

/*
 * DMA Burst Config
 */
#define MAX_BURST_1		1
#define MAX_BURST_4		4
#define MAX_BURST_8		8
#define MAX_BURST_16	16
#define MAX_BURST_32	32

/*
 * HIPHYIO State - Whether Enabled or Disabled
 */
#define HIPHYIO_DISABLED			0
#define HIPHYIO_ENABLED			1

/*
 * HIPHYIO DMA State - Whether DMA Enabled or Disabled
 */
#define HIPHYIO_DMA_DISABLED		0
#define HIPHYIO_DMA_ENABLED			1

/*
 * HIPHYIO Clock Defaults
 */
#define HIPHYIO_DEFAULT_CLKRATE 0x2
#define HIPHYIO_DEFAULT_PRESCALE 0x40

#define CLK_CPSDVR_MIN 0x02
#define CLK_CPSDVR_MAX 0xFE
#define CLK_SCR_MIN 0x00
#define CLK_SCR_MAX 0xFF

/*
 * HIPHYIO Interrupt related Macros
 */
#define DEFAULT_HIPHYIO_REG_IMSC  0xFU
#define DEFAULT_HIPHYIO_REG_IMSC_V600  0x3FF
#define DISABLE_ALL_INTERRUPTS DEFAULT_HIPHYIO_REG_IMSC
#define DISABLE_ALL_INTERRUPTS_V600 DEFAULT_HIPHYIO_REG_IMSC_V600
#define ENABLE_ALL_INTERRUPTS 0x0U

#define CLEAR_ALL_INTERRUPTS  0x3
#define CLEAR_ALL_INTERRUPTS_V600  0x3FF
#define SPI_32BITS_MASK  (0xffffffff)
#define SPI_POLLING_TIMEOUT 1000

#define HARDWARE_LOCK_DEFAULT 1
#define DEFAULT_HIPHYIO_REG_CSCR (GEN_MASK_BITS(HIPHYIO_CS_CTRL_DISENABLE, HIPHYIO_CSCR_MASK_CSEN, 0))
#define DEFAULT_HIPHYIO_REG_COMMONCR      \
	(GEN_MASK_BITS(LOOPBACK_DISABLED, HIPHYIO_COMMONCR_LOOPBACK, 1) | \
	GEN_MASK_BITS(HIPHYIO_CLK_POL_IDLE_LOW, HIPHYIO_COMMONCR_MASK_CPOL, 2) | \
	GEN_MASK_BITS(HIPHYIO_CLK_SECOND_EDGE, HIPHYIO_COMMONCR_MASK_CPHA, 3) | \
	GEN_MASK_BITS(HIPHYIO_DEFAULT_PRESCALE, HIPHYIO_COMMONCR_MASK_DRPR, 4) | \
	GEN_MASK_BITS(HIPHYIO_DEFAULT_CLKRATE, HIPHYIO_COMMONCR_MASK_DRPO, 12) | \
	GEN_MASK_BITS(HIPHYIO_DATA_BITS_12, HIPHYIO_COMMONCR_MASK_FRAMESIZE, 20) | \
	GEN_MASK_BITS(HIPHYIO_NOMAL, HIPHYIO_COMMONCR_MASK_HSPD, 25) | \
	GEN_MASK_BITS(HIPHYIO_DMA_DISABLED, HIPHYIO_COMMONCR_MASK_TXDMAE, 26) | \
	GEN_MASK_BITS(HIPHYIO_DMA_DISABLED, HIPHYIO_COMMONCR_MASK_RXDMAE, 27))
#define DEFAULT_HIPHYIO_REG_ENR                       \
	(GEN_MASK_BITS(HIPHYIO_DISABLED, HIPHYIO_ENR_MASK_EN, 0))


#define DEFAULT_HIPHYIO_REG_FIFOCR                    \
	(GEN_MASK_BITS(HIPHYIO_TX_64_OR_MORE_EMPTY_LOC, HIPHYIO_FIFOCR_MASK_TXDMA, 0) |   \
	GEN_MASK_BITS(HIPHYIO_TX_64_OR_MORE_EMPTY_LOC, HIPHYIO_FIFOCR_MASK_TXINT, 3) | \
	GEN_MASK_BITS(HIPHYIO_RX_16_OR_MORE_ELEM, HIPHYIO_FIFOCR_MASK_RXDMA, 6) |     \
	GEN_MASK_BITS(HIPHYIO_RX_16_OR_MORE_ELEM, HIPHYIO_FIFOCR_MASK_RXINT, 9))

#define DEFAULT_HIPHYIO_REG_FIFOCR_V600                    \
	(GEN_MASK_BITS(HIPHYIO_TX_64_OR_MORE_EMPTY_LOC, HIPHYIO_FIFOCR_MASK_TXDMA, 0) |   \
	GEN_MASK_BITS(HIPHYIO_TX_64_OR_MORE_EMPTY_LOC, HIPHYIO_FIFOCR_MASK_TXINT_V600, 3) | \
	GEN_MASK_BITS(HIPHYIO_RX_16_OR_MORE_ELEM, HIPHYIO_FIFOCR_MASK_RXDMA, 6) |     \
	GEN_MASK_BITS(HIPHYIO_RX_16_OR_MORE_ELEM, HIPHYIO_FIFOCR_MASK_RXINT_V600, 9))

#define  DUMMY_MAX 130
#define  SPI_CS_REG_CNT 4
#define  CS_INFO_CNT 2

#ifndef UNUSED
#define UNUSED(x) ((void)(x))
#endif

#define  HIPHYIO_SPI_SETUP 1
#define  HIPHYIO_SPI_PIN_SELECT 2
#define  HIPHYIO_SPI_PIN_IDLE 0
#define  HIPHYIO_SPI_PIN_NORMAL 1

#define WAIT_FOR_COMPLETION  (HZ * 2)

enum hiphyio_spi_reading {
	READING_NULL,
	READING_U8,
	READING_U16,
	READING_U32
};

enum hiphyio_spi_writing {
	WRITING_NULL,
	WRITING_U8,
	WRITING_U16,
	WRITING_U32
};

enum hiphyio_spi_loopback {
	LOOPBACK_DISABLED,
	LOOPBACK_ENABLED
};

enum hiphyio_spi_speed_mode { HIPHYIO_NOMAL, HIPHYIO_HIGH };

enum hiphyio_spi_cs_ctrl {
	HIPHYIO_CS_CTRL_DISENABLE,
	HIPHYIO_CS_CTRL_ENABLE
};

enum hiphyio_spi_clk_pol {
	HIPHYIO_CLK_POL_IDLE_LOW,
	HIPHYIO_CLK_POL_IDLE_HIGH
};

enum hiphyio_spi_clk_phase {
	HIPHYIO_CLK_FIRST_EDGE,
	HIPHYIO_CLK_SECOND_EDGE
};

enum hiphyio_spi_chip_select { HIPHYIO_CHIP_SELECT, HIPHYIO_CHIP_DESELECT };

enum hiphyio_spi_mode {
	INTERRUPT_TRANSFER,
	POLLING_TRANSFER,
	DMA_TRANSFER,
	EXCLUSIVE_DMA_TRANSFER
};

enum hiphyio_spi_interface {
	HIPHYIO_INTERFACE_MOTOROLA_SPI,
	HIPHYIO_INTERFACE_TI_SYNC_SERIAL,
	HIPHYIO_INTERFACE_NATIONAL_MICROWIRE,
	HIPHYIO_INTERFACE_UNIDIRECTIONAL
};

enum hiphyio_spi_hierarchy {
	HIPHYIO_MASTER,
	HIPHYIO_SLAVE
};

enum hiphyio_spi_clkdelay {
	HIPHYIO_FEEDBACK_CLK_DELAY_NONE,
	HIPHYIO_FEEDBACK_CLK_DELAY_1T,
	HIPHYIO_FEEDBACK_CLK_DELAY_2T,
	HIPHYIO_FEEDBACK_CLK_DELAY_3T,
	HIPHYIO_FEEDBACK_CLK_DELAY_4T,
	HIPHYIO_FEEDBACK_CLK_DELAY_5T,
	HIPHYIO_FEEDBACK_CLK_DELAY_6T,
	HIPHYIO_FEEDBACK_CLK_DELAY_7T
};

enum hiphyio_spi_microwire_wait_state {
	HIPHYIO_MWIRE_WAIT_ZERO,
	HIPHYIO_MWIRE_WAIT_ONE
};

enum hiphyio_spi_duplex {
	HIPHYIO_MICROWIRE_CHANNEL_FULL_DUPLEX,
	HIPHYIO_MICROWIRE_CHANNEL_HALF_DUPLEX
};

enum hiphyio_spi_microwire_ctrl_len {
	HIPHYIO_DATA_BITS_4 = 0x03,
	HIPHYIO_DATA_BITS_5,
	HIPHYIO_DATA_BITS_6,
	HIPHYIO_DATA_BITS_7,
	HIPHYIO_DATA_BITS_8,
	HIPHYIO_DATA_BITS_9,
	HIPHYIO_DATA_BITS_10,
	HIPHYIO_DATA_BITS_11,
	HIPHYIO_DATA_BITS_12,
	HIPHYIO_DATA_BITS_13,
	HIPHYIO_DATA_BITS_14,
	HIPHYIO_DATA_BITS_15,
	HIPHYIO_DATA_BITS_16,
	HIPHYIO_DATA_BITS_17,
	HIPHYIO_DATA_BITS_18,
	HIPHYIO_DATA_BITS_19,
	HIPHYIO_DATA_BITS_20,
	HIPHYIO_DATA_BITS_21,
	HIPHYIO_DATA_BITS_22,
	HIPHYIO_DATA_BITS_23,
	HIPHYIO_DATA_BITS_24,
	HIPHYIO_DATA_BITS_25,
	HIPHYIO_DATA_BITS_26,
	HIPHYIO_DATA_BITS_27,
	HIPHYIO_DATA_BITS_28,
	HIPHYIO_DATA_BITS_29,
	HIPHYIO_DATA_BITS_30,
	HIPHYIO_DATA_BITS_31,
	HIPHYIO_DATA_BITS_32
};

enum hiphyio_spi_rx_level_trig {
	HIPHYIO_RX_1_OR_MORE_ELEM,
	HIPHYIO_RX_4_OR_MORE_ELEM,
	HIPHYIO_RX_8_OR_MORE_ELEM,
	HIPHYIO_RX_16_OR_MORE_ELEM,
	HIPHYIO_RX_32_OR_MORE_ELEM,
	HIPHYIO_RX_64_OR_MORE_ELEM,
	HIPHYIO_RX_128_OR_MORE_ELEM,
	HIPHYIO_RX_224_OR_MORE_ELEM
};

enum hiphyio_spi_tx_level_trig {
	HIPHYIO_TX_1_OR_MORE_EMPTY_LOC,
	HIPHYIO_TX_4_OR_MORE_EMPTY_LOC,
	HIPHYIO_TX_8_OR_MORE_EMPTY_LOC,
	HIPHYIO_TX_16_OR_MORE_EMPTY_LOC,
	HIPHYIO_TX_32_OR_MORE_EMPTY_LOC,
	HIPHYIO_TX_64_OR_MORE_EMPTY_LOC,
	HIPHYIO_TX_128_OR_MORE_EMPTY_LOC
};

struct hiphyio_spi_clock_params {
	u8 cpsdvsr; /* value from 2 to 254 (even only!) */
	u8 scr; /* value from 0 to 255 */
};

struct hiphyio_spi_controller {
	struct platform_device		*pdev;
	resource_size_t			phybase;
	void __iomem			*virtbase;
	struct clk			*clk;
	struct spi_master		*master;
	struct hiphyio_spi_platform_data	*pdata;
	struct tasklet_struct		pump_transfers;
	struct spi_message		*cur_msg;
	struct spi_transfer		*cur_transfer;
	struct chip_data		*cur_chip;
	bool				next_msg_cs_active;
	bool				internal_cs_ctrl;
	void				*tx;
	void				*tx_end;
	void				*rx;
	void				*rx_end;
	int			         irq;
	enum hiphyio_spi_reading		read;
	enum hiphyio_spi_writing		write;
	u32				exp_fifo_level;
	enum hiphyio_spi_rx_level_trig		rx_lev_trig;
	enum hiphyio_spi_tx_level_trig		tx_lev_trig;
	struct dma_chan			*dma_rx_channel;
	struct dma_chan			*dma_tx_channel;
	int hardware_mutex;
	struct hwspinlock *spi_hwspin_lock;
	spinlock_t sync_spinlock;
	int sync_locked;
	struct sg_table			sgt_rx;
	struct sg_table			sgt_tx;
	u32 transfer_len;
	spinlock_t lock;
	int cur_cs;
	int *chipselects;
	char				*dummypage;
	bool				dma_running;
	void __iomem   *cs_reg_base;
	u32 iodie_dummy;
	u32 cs0_offset;
	u32 cs0_bit;
	u32 cs2_offset;
	u32 cs2_bit;
	struct completion dma_complete;
	u32 hiphyio_spi_cr;
	unsigned int spi_sleep_use_doze;
	unsigned int doze_id;
};

struct dma_chan;

struct hiphyio_spi_platform_data {
	u16 bus_id;
	u8 num_chipselect;
	u8 enable_dma : 1;
	bool (*dma_filter)(struct dma_chan *chan, void *filter_param);
	void *dma_rx_param;
	void *dma_tx_param;
	int *chipselects;
	bool rt;
};

struct hiphyio_spi_config_chip {
	enum hiphyio_spi_interface iface;
	enum hiphyio_spi_hierarchy hierarchy;
	bool slave_tx_disable;
	struct hiphyio_spi_clock_params clk_freq;
	enum hiphyio_spi_mode com_mode;
	enum hiphyio_spi_rx_level_trig rx_lev_trig;
	enum hiphyio_spi_tx_level_trig tx_lev_trig;
	enum hiphyio_spi_microwire_ctrl_len ctrl_len;
	enum hiphyio_spi_microwire_wait_state wait_state;
	enum hiphyio_spi_duplex duplex;
	enum hiphyio_spi_clkdelay clkdelay;
	void (*cs_control) (u32 control);
};

struct chip_data {
	u8 n_bytes;
	u32 csr;
	bool enable_dma;
	u32 cr;
	enum hiphyio_spi_reading read;
	enum hiphyio_spi_writing write;
	u32 enr;
	void (*cs_control) (u32 command);
	int xfer_type;
};

#endif
