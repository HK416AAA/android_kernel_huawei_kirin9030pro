/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: Contexthub 9030 driver.
 * Create: 2024-10-10
 */
#ifndef __IODIE__DRV__
#define __IODIE__DRV__

#include <platform_include/smart/drivers/io_die/iodie_hiphyio_def.h>

enum iodie_commu_cmd{
	IODIE_CMD_START,
	IODIE_CMD_STATUS_NOTIFY = 0x01,
	IODIE_CMD_STATUS_NOTIFY_RESP = 0x02,
	IODIE_CMD_AXI_RECORD = 0x03,
	IODIE_CMD_AXI_RECORD_RESP = 0x04,
	IODIE_CMD_REG_OP = 0x5,
	IODIE_CMD_REG_OP_RESP = 0x6,
	IODIE_CMD_CLK_OUT_CFG = 0x7,
	IODIE_CMD_CLK_OUT_CFG_RESP = 0x8,
	IODIE_CMD_IODIE_ERR = 0x9,
	IODIE_CMD_IODIE_ERR_RESP = 0xA,
	IODIE_CMD_TEST,
	IODIE_CMD_TEST_RESP,
	IODIE_CMD_MAX, /* MAX must less than IODIE_CMD_GPIO0_WEAKUP */
};

#define IODIE_CMD_GPIO_WAKEUP_START   100 /* gpio0 */
#define IODIE_CMD_GPIO_WAKEUP_END     227 /* gpio127 */

struct iodie_commu_data {
	const void *wr_buf;
	int wr_len;
	char *rd_buf;
	int rd_len;
	int errno;
};

struct hio_ap_user_time {
    uint64_t bt_uart_time;
    uint64_t gnss_uart_time;
    uint64_t audio_uart_time;
};

#if defined(CONFIG_DFX_DEBUG_FS) && defined(CONFIG_CONTEXTHUB_IO_DIE_HIPHYIO)
struct iodie_reg_op{
	uint32_t op;        /* 0 write 1 read */
	uint32_t slave_id;
	uint32_t reg_addr;
	uint32_t val;       /* write vlaue, if read, ignore it */
};
#endif

int iodie_drv_normal_request(enum iodie_user user, enum iodie_runtime_status status);
int iodie_drv_normal_release(enum iodie_user user, enum iodie_runtime_status status);
int iodie_drv_fnpll_request(enum iodie_user user);
int iodie_drv_fnpll_release(enum iodie_user user);
int iodie_drv_notify_register(enum iodie_user user, iodie_user_func func);

int iodie_drv_commu(enum iodie_commu_cmd cmd, struct iodie_commu_data *data);

enum iodie_sys_status iodie_drv_get_sys_status(void);
enum iodie_err_status iodie_drv_get_err_status(void);

int get_iodie_dts_status(void);

int iodie_drv_clk_out_sys(enum iodie_clk_out_op op, unsigned int freq);

struct hio_ap_user_time send_hiphyio_user_data_to_dubai(void);
void hiphyio_user_data_reset(void);
void update_user_start_time_data(enum iodie_user user);
void update_user_end_time_data(enum iodie_user user);

#if defined(CONFIG_DFX_DEBUG_FS) && defined(CONFIG_CONTEXTHUB_IO_DIE_HIPHYIO)
int iodie_reg_op(struct iodie_reg_op *data);
#endif

#endif

