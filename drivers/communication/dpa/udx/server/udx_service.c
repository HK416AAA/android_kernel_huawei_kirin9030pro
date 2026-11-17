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

#include <linux/kernel.h>
#include <linux/slab.h>
#include <securec.h>
#include <bsp_print.h>
#include "udx_service.h"

struct udx_param {
    char *name;
    char *value;
    int len;
    struct list_head list;
};

struct udx_service {
    char *name;
    struct list_head list;
    struct list_head para_list;
    spinlock_t para_lock;
    int attached;
    struct udx_service_impl *instance;
};

struct udx_service_manager {
    struct list_head service_list;
    struct mutex lock;
};

static struct udx_service_manager *g_mgr = NULL;

static int udx_service_manager_init(struct udx_service_manager *mgr)
{
    INIT_LIST_HEAD(&mgr->service_list);
    mutex_init(&mgr->lock);
    return 0;
}

static struct udx_service_manager *get_serivce_manager()
{
    if (!g_mgr) {
        g_mgr = kmalloc(sizeof(struct udx_service_manager), GFP_KERNEL);
        udx_service_manager_init(g_mgr);
    }
    return g_mgr;
}

static int udx_service_add(struct udx_service_manager *mgr, struct udx_service *service)
{
    mutex_lock(&mgr->lock);
    list_add_tail(&service->list, &mgr->service_list);
    mutex_unlock(&mgr->lock);
    return 0;
}

static void udx_service_attach_done(struct udx_service *service)
{
    struct udx_param *param;
    list_for_each_entry(param, &service->para_list, list) {
        dpa_pr_err("[%s]%s:%d\n", __func__, param->name, *((int *)param->value));
        service->instance->config(param->name, *((int *)param->value), service->instance->private_data);
    }
}

static int do_udx_service_add_param_int(struct udx_service *service, const char *name, int val)
{
    int ret;
    struct udx_param *param;

    param = kzalloc(sizeof(struct udx_param), GFP_KERNEL);
    if (!param) {
        return -1;
    }

    param->name = kmalloc(strlen(name) + 1, GFP_KERNEL);
    if (!param->name) {
        ret = -2;
        goto error;
    }

    if (memcpy_s(param->name, strlen(name) + 1, name, strlen(name) + 1)) {
        ret = -3;
        goto error;
    }

    param->value = kmalloc(sizeof(int), GFP_KERNEL);
    if (!param->value) {
        ret = -4;
        goto error;
    }

    if (memcpy_s(param->value, sizeof(int), &val, sizeof(int))) {
        ret = -5;
        goto error;
    }

    param->len = sizeof(int);

    INIT_LIST_HEAD(&param->list);
    list_add_tail(&param->list, &service->para_list);

    if (service->attached && service->instance) {
        udx_service_attach_done(service);
    }

    return 0;

error:
    if (param->value) {
        kfree(param->value);
    }
    if (param->name) {
        kfree(param->name);
    }
    kfree(param);
    return ret;
}

static void udx_service_del_param(struct udx_service *service)
{
    struct udx_param *param, *n;
    list_for_each_entry_safe(param, n, &service->para_list, list) {
        list_del(&param->list);
        kfree(param->value);
        kfree(param->name);
        kfree(param);
    }
}

static int __udx_service_add_by_name(struct udx_service_manager *mgr, const char *name)
{
    struct udx_service *service;
    service = kzalloc(sizeof(struct udx_service), GFP_KERNEL);
    if (!service) {
        return -1;
    }
    service->name = kmalloc(strlen(name) + 1, GFP_KERNEL);
    if (!service->name) {
        goto error;
    }
    if (memcpy_s(service->name, strlen(name) + 1, name, strlen(name) + 1)) {
        goto error;
    }
    INIT_LIST_HEAD(&service->para_list);
    INIT_LIST_HEAD(&service->list);

    udx_service_add(mgr, service);

    return 0;
error:
    kfree(service->name);
    kfree(service);
    return -1;
}

int udx_service_add_by_name(const char *name)
{
    struct udx_service_manager *mgr = get_serivce_manager();
    if (!mgr) {
        return -1;
    }

    return __udx_service_add_by_name(mgr, name);
}

static struct udx_service *__udx_serivce_get(struct list_head *head, const char *name) {
    struct udx_service *service;
    list_for_each_entry(service, head, list) {
        if (!strcmp(service->name, name)) {
            return service;
        }
    }
    return NULL;
}

struct udx_service *udx_serivce_get(const char *name)
{
    struct udx_service_manager *mgr = get_serivce_manager();
    if (!mgr) {
        return NULL;
    }
    return __udx_serivce_get(&mgr->service_list, name);
}

int udx_service_add_param_int(const char *service_name, const char *item_name, int val)
{
    struct udx_service_manager *mgr;
    struct udx_service *service;

    mgr = get_serivce_manager();
    if (!mgr) {
        return -1;
    }

    service = __udx_serivce_get(&mgr->service_list, service_name);
    if (!service) {
        return -1;
    }

    return do_udx_service_add_param_int(service, item_name, val);
}

static void __udx_service_clean(struct udx_service_manager *mgr) {
    struct udx_service *service, *n;
    struct list_head *head = &mgr->service_list;
    list_for_each_entry_safe(service, n, head, list) {
        udx_service_del_param(service);
        kfree(service->name);
        kfree(service);
    }
    INIT_LIST_HEAD(head);
    return;
}

void udx_service_clean(void) {
    struct udx_service_manager *mgr = get_serivce_manager();
    if (!mgr) {
        return;
        }
    __udx_service_clean(mgr);
}

void udx_service_dump_param(struct udx_service *service)
{
    struct udx_param *param;
    list_for_each_entry(param, &service->para_list, list) {
        dpa_pr_err("[%s]%s:%d\n", __func__, param->name, *((int *)param->value));
    }
}

int udx_service_register(const char *name, struct udx_service_impl *instance)
{
    struct udx_service_manager *mgr;
    struct udx_service *service;

    mgr = get_serivce_manager();
    if (!mgr) {
        dpa_pr_err("[%s]get_serivce_manager failed\n", __func__);
        return -1;
    }

    service = __udx_serivce_get(&mgr->service_list, name);
    if (!service) {
        if (__udx_service_add_by_name(mgr, name)) {
            dpa_pr_err("[%s]get service failed\n", __func__);
            return -1;
        }
        service = __udx_serivce_get(&mgr->service_list, name);
        if (!service) {
            dpa_pr_err("[%s]get service failed\n", __func__);
            return -1;
        }
    }

    service->instance = instance;
    service->attached = 1;
    if (service->instance) {
        udx_service_attach_done(service);
    }
    return 0;
}

struct udx_service_impl *udx_get_service_instance(const char *name)
{
    struct udx_service_manager *mgr;
    struct udx_service *service;

    mgr = get_serivce_manager();
    if (!mgr) {
        return NULL;
    }

    service = __udx_serivce_get(&mgr->service_list, name);
    if (!service) {
        return NULL;
    }

    return service->instance;
}

int udx_service_dump(void)
{
    struct udx_service_manager *mgr;
    struct udx_service *service;

    mgr = get_serivce_manager();
    if (!mgr) {
        return -1;
    }

    mutex_lock(&mgr->lock);

    list_for_each_entry(service, &mgr->service_list, list) {
        dpa_pr_err("[%s]%s\n", __func__, service->name);
        udx_service_dump_param(service);
    }

    mutex_unlock(&mgr->lock);
    return 0;
}