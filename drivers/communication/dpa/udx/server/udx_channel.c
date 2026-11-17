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

#include <linux/module.h>
#include <linux/file.h>
#include <linux/mount.h>
#include <linux/pseudo_fs.h>
#include <linux/spinlock.h>
#include <bsp_print.h>
#include "udx_service.h"

struct udx_channel_node {
    struct list_head list;
    struct inode *inode;
    struct file *file;
    void *instance;
    int fd;
};

static struct udx_channel_ctx *get_udx_channel_ctx(void);
struct udx_channel_node *g_last_node = NULL;

static struct udx_channel_node *udx_channel_node_alloc(void)
{
    struct udx_channel_node *node;

    node = kzalloc(sizeof(struct udx_channel_node), GFP_KERNEL);
    if (node == NULL) {
        return NULL;
    }

    INIT_LIST_HEAD(&node->list);

    g_last_node = node;
    return node;
}

struct udx_channel_ctx {
    struct pseudo_fs_context *pseudo_fs;
    struct vfsmount *channel_mnt;
    struct list_head channel_head;
    spinlock_t lock;
};

static struct udx_channel_ctx *g_udx_channel_ctx = NULL;

static int udx_init_fs_context(struct fs_context *fc)
{
    struct udx_channel_ctx *ctx = get_udx_channel_ctx();
    if (ctx == NULL) {
        return -ENOMEM;
    }

    ctx->pseudo_fs = init_pseudo(fc, 0x5238);
    if (IS_ERR(ctx->pseudo_fs)) {
        return PTR_ERR(ctx->pseudo_fs);
    }

    INIT_LIST_HEAD(&ctx->channel_head);
    spin_lock_init(&ctx->lock);
    return 0;
}

static struct file_system_type udx_channel_fs = {
    .name = "udx",
    .init_fs_context = udx_init_fs_context,
    .kill_sb = kill_anon_super,
};

static int udx_channel_init(struct udx_channel_ctx *ctx)
{
    ctx->channel_mnt = kern_mount(&udx_channel_fs);
    if (IS_ERR(ctx->channel_mnt)) {
        return PTR_ERR(ctx->channel_mnt);
    }

    return 0;
}

static struct udx_channel_ctx* get_udx_channel_ctx(void)
{
    if (g_udx_channel_ctx == NULL) {
        g_udx_channel_ctx = kmalloc(sizeof(struct udx_channel_ctx), GFP_KERNEL);
        if (g_udx_channel_ctx == NULL) {
            return NULL;
        }
        if (udx_channel_init(g_udx_channel_ctx) != 0) {
            kfree(g_udx_channel_ctx);
            g_udx_channel_ctx = NULL;
            return NULL;
        }
    }
    return g_udx_channel_ctx;
}

long channel_ioctl(struct file *file, unsigned cmd, unsigned long arg)
{
    dpa_pr_err("[%s] cmd: %d, arg: %ld\n", __func__, cmd, arg);
    return 0;
}

int channel_release(struct inode *i, struct file *filp)
{
    struct udx_channel_node *node;
    struct udx_channel_ctx* ctx;

    node = (struct udx_channel_node *)i->i_private;

    ctx = get_udx_channel_ctx();
    if (ctx == NULL) {
        return -ENOMEM;
    }
    spin_lock(&ctx->lock);
    list_del(&node->list);
    spin_unlock(&ctx->lock);
    kfree(node);
    return 0;
}

const struct file_operations channel_file_ops = {
    .owner =	THIS_MODULE,
    .unlocked_ioctl = channel_ioctl,
    .release =  channel_release,
};

static int sockfs_setattr(struct dentry *dentry, struct iattr *iattr)
{
    int err = simple_setattr(dentry, iattr);

    return err;
}

static const struct inode_operations udx_inode_ops = {
	.setattr = sockfs_setattr,
};

static struct inode *get_new_inode(struct super_block *sb)
{
    struct inode *inode;
    inode = new_inode(sb);
    if (inode == NULL) {
        return NULL;
    }
    inode->i_ino = get_next_ino();
    inode->i_mode = S_IFSOCK | S_IRWXUGO;
    inode->i_uid = current_fsuid();
    inode->i_gid = current_fsgid();
    inode->i_op = &udx_inode_ops;
    return inode;
}

int do_channel_alloc_file(struct udx_service_impl *service_impl, struct udx_channel_ctx* ctx)
{
    struct inode *inode;
    struct file *file;
    struct udx_channel_node *node;

    inode = get_new_inode(ctx->channel_mnt->mnt_sb);
    if (inode == NULL) {
        dpa_pr_err("[%s] inode is NULL\n", __func__);
        return -ENOMEM;
    }

    file = alloc_file_pseudo(inode, ctx->channel_mnt, "udx_channel", O_RDWR, service_impl->fops);
    if (IS_ERR(file)) {
        dpa_pr_err("[%s] file is NULL\n", __func__);
        return -ENOMEM;
    }

    int fd = get_unused_fd_flags(0);
    if (fd < 0) {
        dpa_pr_err("[%s] fd is invalid\n", __func__);
        fput(file);
        return -ENOMEM;
    }

    get_file(file);
    fd_install(fd, file);

    node = udx_channel_node_alloc();
    if (node == NULL) {
        dpa_pr_err("[%s] node is NULL\n", __func__);
        fput(file);
        return -ENOMEM;
    }

    node->instance = service_impl->get_instance(service_impl->private_data);
    inode->i_private = node;
    file->private_data = node;
    node->inode = inode;
    node->file = file;
    node->fd = fd;
    spin_lock(&ctx->lock);
    list_add(&node->list, &ctx->channel_head);
    spin_unlock(&ctx->lock);

    fput(file);
    return fd;
}

int channel_alloc_file(const char *service_name)
{
    struct udx_channel_ctx* ctx;
    struct udx_service_impl *service_impl;

    service_impl = udx_get_service_instance(service_name);
    if (service_impl == NULL) {
        dpa_pr_err("[%s] service_impl is NULL\n", __func__);
        return -ENOMEM;
    }

    ctx = get_udx_channel_ctx();
    if (ctx == NULL) {
        dpa_pr_err("[%s] ctx is NULL\n", __func__);
        return -ENOMEM;
    }

    return do_channel_alloc_file(service_impl, ctx);
}


void *udx_service_get_instance(struct file *f)
{
    struct udx_channel_node *node;
    node = (struct udx_channel_node *)f->private_data;
    if (node == NULL) {
        return NULL;
    }
    return node->instance;
}