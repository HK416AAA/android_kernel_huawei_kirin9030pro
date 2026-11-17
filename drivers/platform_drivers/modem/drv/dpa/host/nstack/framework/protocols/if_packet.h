/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */
#ifndef DPA_IF_PACKET_H
#define DPA_IF_PACKET_H

#define SPL_PACKET_HOST         0 /* To us */
#define SPL_PACKET_BROADCAST    1 /* To all */
#define SPL_PACKET_MULTICAST    2 /* To group */
#define SPL_PACKET_OTHERHOST    3 /* To someone else */
#define SPL_PACKET_OUTGOING     4 /* Outgoing of any type */
#define SPL_PACKET_LOOPBACK     5 /* MC/BRD frame looped back */
#define SPL_PACKET_USER         6 /* To user space */
#define SPL_PACKET_KERNEL       7 /* To kernel space */

#endif