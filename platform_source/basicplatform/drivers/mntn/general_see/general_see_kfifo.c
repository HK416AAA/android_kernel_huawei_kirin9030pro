/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: provide the FIFO operation functions for mspc mntn
 * Create: 2025-06-17
 */

#include <linux/kfifo.h>
#include <linux/spinlock_types.h>
#include <platform_include/basicplatform/linux/ipc_msg.h>

#define MSPC_MNTN_MSG_QUEUE_NUM          10

#ifdef CONFIG_CRYPTO_CORE
#define FIFO_OK                          0x5A5A
#define FIFO_ERROR                       0xA5A5
#else
#define FIFO_OK                          0
#define FIFO_ERROR                       (-10002)
#endif

static struct kfifo g_mntn_msg_queue;
static spinlock_t g_msg_queue_spinlock;

/*
 * @brief      : Initalize the msg queue of mspc mntn
 * @return     : ::int, 0 on init suceess, other value on failure
 */
int mspc_mntn_msg_queue_init(void)
{
	int ret = 0;

	ret = kfifo_alloc(&g_mntn_msg_queue, MSPC_MNTN_MSG_QUEUE_NUM * sizeof(struct ipc_msg),
	                  GFP_KERNEL);
	if (ret != 0)
		pr_err("%s: kfifo aolloc failed! return 0x%x\n", __func__, ret);

	spin_lock_init(&g_msg_queue_spinlock);
	return ret;
}

/*
 * @brief      : Free the msg queue of mspc mntn
 */
void mspc_mntn_msg_queue_free(void)
{
	kfifo_free(&g_mntn_msg_queue);
}

/*
 * @brief      : Push the ipc_msg data into the msg queue of mspc mntn
 * @param[in]  : msg: ipc_msg data to be pushed
 * @return     : ::int, FIFO_OK on init suceess, FIFO_ERROR value on failure
 */
int mspc_mntn_msg_queue_kfifo_in(struct ipc_msg *msg)
{
	int ret = 0;

	if (msg == NULL) {
		pr_info("%s: msg is NULL!\n", __func__);
		return FIFO_ERROR;
	}

	if (kfifo_is_full(&g_mntn_msg_queue)) {
		pr_info("%s: kfifo is full!\n", __func__);
		return FIFO_ERROR;
	}

	ret = kfifo_in_spinlocked(&g_mntn_msg_queue, msg, sizeof(struct ipc_msg),
							  &g_msg_queue_spinlock);
	if (ret != sizeof(struct ipc_msg)) {
		pr_err("%s: kfifo in failed!\n", __func__);
		return FIFO_ERROR;
	}

	return FIFO_OK;
}

/*
 * @brief      : Pop the ipc_msg data out of the msg queue of mspc mntn
 * @param[in]  : msg: ipc_msg data to be popped
 * @return     : ::int, FIFO_OK on init suceess, FIFO_ERROR value on failure
 */
int mspc_mntn_msg_queue_kfifo_out(struct ipc_msg *msg)
{
	int ret = 0;

	if (msg == NULL) {
		pr_info("%s: msg is NULL!\n", __func__);
		return FIFO_ERROR;
	}

	if (kfifo_is_empty(&g_mntn_msg_queue))
		return FIFO_ERROR;

	ret = kfifo_out_spinlocked(&g_mntn_msg_queue, msg, sizeof(struct ipc_msg),
							   &g_msg_queue_spinlock);
	if (ret != sizeof(struct ipc_msg)) {
		pr_err("%s: kfifo out failed!\n", __func__);
		return FIFO_ERROR;
	}

	return FIFO_OK;
}
