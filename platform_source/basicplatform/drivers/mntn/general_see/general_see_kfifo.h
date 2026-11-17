/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: provide the FIFO operation functions for mspc mntn
 * Create: 2025-06-17
 */

#ifndef GENERAL_SEE_KFIFO_H
#define GENERAL_SEE_KFIFO_H

/*
 * @brief      : Initalize the msg queue of mspc mntn
 * @return     : ::int, 0 on init suceess, other value on failure
 */
int mspc_mntn_msg_queue_init(void);

/*
 * @brief      : Free the msg queue of mspc mntn
 */
void mspc_mntn_msg_queue_free(void);

/*
 * @brief      : Pop the ipc_msg data out of the msg queue of mspc mntn
 * @param[in]  : msg: ipc_msg data to be pulled
 * @return     : ::int, FIFO_OK on init suceess, FIFO_ERROR value on failure
 */
int mspc_mntn_msg_queue_kfifo_in(struct ipc_msg *msg);

/*
 * @brief      : Pop the ipc_msg data out of the msg queue of mspc mntn
 * @param[in]  : msg: ipc_msg data to be popped
 * @return     : ::int, FIFO_OK on init suceess, FIFO_ERROR value on failure
 */
int mspc_mntn_msg_queue_kfifo_out(struct ipc_msg *msg);

#endif /* GENERAL_SEE_THREAD_H */
