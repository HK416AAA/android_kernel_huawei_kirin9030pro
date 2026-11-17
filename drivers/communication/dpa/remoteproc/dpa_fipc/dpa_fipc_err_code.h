/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#ifndef _DPA_FIPC_ERR_CODE_H
#define _DPA_FIPC_ERR_CODE_H

#define DPA_FIPC_OK (0)
#define DPA_FIPC_ERR_ESRCH (-3)             /* No such process */
#define DPA_FIPC_ERR_EIO (-5)               /* Input/output error */
#define DPA_FIPC_ERR_ENXIO (-6)             /* No such device or address */
#define DPA_FIPC_ERR_ENOMEM (-12)           /* Cannot allocate memory */
#define DPA_FIPC_ERR_EEXIST (-17)           /* File exists */
#define DPA_FIPC_ERR_EINVAL (-22)           /* Invalid argument */
#define DPA_FIPC_ERR_ECHRNG (-44)           /* Channel number out of range */
#define DPA_FIPC_ERR_ETIME (-62)            /* Timer expired */
#define DPA_FIPC_ERR_EPROTO (-71)           /* Protocol error */
#define DPA_FIPC_ERR_EBADMSG (-74)          /* Bad message */
#define DPA_FIPC_ERR_EBADFD (-77)           /* File descriptor in bad state */
#define DPA_FIPC_ERR_ENETUNREACH (-101)     /* Network is unreachable */
#define DPA_FIPC_ERR_EHOSTUNREACH (-113)    /* No route to host */
#define DPA_FIPC_ERR_ENOTRECOVERABLE (-131) /* State not recoverable */
#define DPA_FIPC_ERR_PM_OPIPE_NOT_IDLE (-512)
#define DPA_FIPC_ERR_PM_IPIPE_NOT_IDLE (-513)
#define DPA_FIPC_ERR_PM_IPIPE_NEG_REFUSE (-514)
#define DPA_FIPC_ERR_PM_IPIPE_NEG_TIMEOUT (-515)
#define DPA_FIPC_ERR_PM_IPIPE_NEG_FAIL (-516)
#define DPA_FIPC_ERR_PM_OPIPE_NOT_EMPTY (-517)
#define DPA_FIPC_ERR_PM_IPIPE_NOT_EMPTY (-518)
#define DPA_FIPC_ERR_HALT_QUERY_WAIT_TIMEOUT (-519)
#define DPA_FIPC_ERR_MDM_IN_STR (-520)

// DPA MSG扩展错误码
#define DPA_FIPC_ERR_EMPTY (-1000)
#define DPA_FIPC_ERR_BAD_LEN (-1001)
#define DPA_FIPC_ERR_OUT_OF_RANGE (-1002)
#define DPA_FIPC_ERR_WRITE_FAILED (-1003)
#define DPA_FIPC_ERR_READ_FAILED (-1004)
#define DPA_FIPC_ERR_MEM_OP_FAILED (-1005)
#define DPA_FIPC_ERR_IRQ_FAILED (-1006)
#define DPA_FIPC_ERR_BAD_CHANNEL (-1007)
#define DPA_FIPC_ERR_CHECK_FAILED (-1008)
#define DPA_FIPC_ERR_BAD_STATE (-1009)
#define DPA_FIPC_ERR_PIPE_INT_EN (-1010)
#define DPA_FIPC_ERR_IN_INT_IPIPE (-1011)
#define DPA_FIPC_ERR_IN_INT_OPIPE (-1012)
#define DPA_FIPC_ERR_CLK_FAILED (-1013)
#define DPA_FIPC_ERR_PIPE_INT_HDL (-1014)
#define DPA_FIPC_ERR_IN_INT_CBK (-1015)
#endif