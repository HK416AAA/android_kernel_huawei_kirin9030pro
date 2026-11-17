/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <securec.h>
#include "bsp_print.h"
#include "udx_buffer_queue.h"

#undef THIS_MODU
#define THIS_MODU mod_udx_buffer

udx_buffer_queue* udx_buffer_queue_get(void *data)
{
    if (data == NULL) {
        dpa_pr_err("data is null\n");
        return NULL;
    }
    return (udx_buffer_queue *)data;
}

int udx_get_buffer_queue_item(udx_buffer_queue *queue, udx_buffer_queue_item *item)
{
    int ret;
    if (queue == NULL || item == NULL) {
        dpa_pr_err("queue or item is null\n");
        return -EINVAL;
    }

    if (udx_buffer_queue_empty(&queue->head)) {
        dpa_pr_err("queue is empty\n");
        return -ENOMEM;
    }

    ret = memcpy_s(item, sizeof(udx_buffer_queue_item), &queue->data[queue->head.head], sizeof(udx_buffer_queue_item));
    if (ret != 0) {
        dpa_pr_err("memcpy_s failed, ret = %d\n", ret);
        return ret;
    }
    queue->head.head = (queue->head.head + 1) % (queue->head.capacity);
    return ret;
}

int udx_put_buffer_queue_item(udx_buffer_queue *queue, udx_buffer_queue_item *item)
{
    int ret;
    if (queue == NULL || item == NULL) {
        dpa_pr_err("queue or item is null\n");
        return -EINVAL;
    }

    if (udx_buffer_queue_full(&queue->head)) {
        dpa_pr_err("queue is full\n");
        return -ENOMEM;
    }

    ret = memcpy_s(&queue->data[queue->head.tail], sizeof(udx_buffer_queue_item), item, sizeof(udx_buffer_queue_item));
    if (ret != 0) {
        dpa_pr_err("memcpy_s failed, ret = %d\n", ret);
        return ret;
    }
    queue->head.tail = (queue->head.tail + 1) % (queue->head.capacity);
    return ret;
}

int udx_get_buffer_queue_count(udx_buffer_queue *queue)
{
    return udx_buffer_queue_data_sz(&queue->head);
}

int udx_get_buffer_queue_left(udx_buffer_queue *queue)
{
    return udx_buffer_queue_idle_sz(&queue->head);
}
