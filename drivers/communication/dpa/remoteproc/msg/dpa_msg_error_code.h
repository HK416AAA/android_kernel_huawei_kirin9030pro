/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 */
#ifndef _DPA_MSG_ERR_CODE_H
#define _DPA_MSG_ERR_CODE_H

#define MSG_ERR_GEN(err) (0x80000000 | (err))

/* follow mdrv_msg.h definition */
#define MSG_ERR_ESRCH (-3)             /* No such process */
#define MSG_ERR_EIO (-4)               /* Input/output error */
#define MSG_ERR_ENXIO (-5)             /* No such device or address */
#define MSG_ERR_EAGAIN (-6)            /* Resource temporarily unavailable */
#define MSG_ERR_ENOMEM (-7)            /* Cannot allocate memory */
#define MSG_ERR_EEXIST (-8)            /* File exists */
#define MSG_ERR_EINVAL (-9)           /* Invalid argument */
#define MSG_ERR_ECHRNG (-10)           /* Channel number out of range */
#define MSG_ERR_ETIME (-11)            /* Timer expired */
#define MSG_ERR_EPROTO (-12)            /* Protocol error */
#define MSG_ERR_EBADMSG (-13)          /* Bad message */
#define MSG_ERR_ENETUNREACH (-14)      /* Network is unreachable */
#define MSG_ERR_EHOSTUNREACH (-15)     /* No route to host */
#define MSG_ERR_ENOTRECOVERABLE (-16)  /* State not recoverable */

// msg正常返回
#define MSG_OK (0)

#define MSG_ERR_COMMON_INPUT (-17)
#define MSG_ERR_COMMON_BAD_LENGTH (-18)
#define MSG_ERR_COMMON_OUT_OF_LIMIT (-19)
#define MSG_ERR_COMMON_MEM_OP_ERROR (-20)
#define MSG_ERR_COMMON_BAD_STATE (-21)

#define MSG_ERR_RECV_BAD_MSG_TYPE (-22)
#define MSG_ERR_RECV_BAD_MSG_LENGTH (-23)
#define MSG_ERR_RECV_BAD_EVENT (-24)

#define MSG_ERR_SEND_BAD_DEST (-25)
#define MSG_ERR_SEND_BAD_SRC (-26)
#define MSG_ERR_SEND_NO_CBK (-27)

#endif
