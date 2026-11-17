/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
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
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <asm/current.h>
#include <linux/atomic.h>
#include <linux/socket.h>
#include <linux/bitops.h>
#include <net/tcp.h>
#include <linux/net_monitor_hook.h>
#include <securec.h>

void test_sys_socket(int family, int type, int protocol) {
    NM_TRACE(__sys_socket, 3, family, type, protocol);
}

void test_sys_setsockopt(int level, int optname, unsigned short family, char *optval, int optlen) {
    NM_TRACE(__sys_setsockopt, 5, level, optname, family, optval, optlen);
}

void test_sys_getsockopt(int level, int optname, unsigned short family, char *optval, int optlen) {
    NM_TRACE(__sys_setsockopt, 5, level, optname, family, optval, optlen);
}

void test_sys_shutdown(int fd, int how) {
    NM_TRACE(__sys_shutdown, 2, fd, how);
}

void test_sys_sendmsg(unsigned short family, unsigned int flags) {
    NM_TRACE(___sys_sendmsg, 2, family, flags);
}

void test_sys_recvmsg(unsigned short family, unsigned int flags) {
    NM_TRACE(___sys_recvmsg, 2, family, flags);
}

void test_sock_ioctl(unsigned short family, unsigned int cmd, unsigned long arg) {
    NM_TRACE(compat_sock_ioctl, 3, cmd, arg, family);
}

int net_monitor_test_0(void)
{
    test_sys_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    test_sys_socket(AF_INET + 1, SOCK_STREAM, IPPROTO_TCP);
    return 0;
}

int net_monitor_test_1(void)
{
    int i,j;
    for (i = 0; i < 128; i++) {
        for (j = 0; j < 128; j++) {
            test_sys_setsockopt(i, j, AF_INET, NULL, 0);
        }
    }
    
    return 0;
}

int net_monitor_test_2(void)
{
    int i,j;
    for (i = 0; i < 128; i++) {
        for (j = 0; j < 128; j++) {
            test_sys_getsockopt(i, j, AF_INET, NULL, 0);
        }
    }
    
    return 0;
}

int net_monitor_test_3(void)
{
    int i,j;
    for (i = 0; i < 128; i++) {
        for (j = 0; j < 128; j++) {
            test_sys_sendmsg(i, j);
        }
    }
    
    return 0;
}

int net_monitor_test_4(void)
{
    int i,j;
    for (i = 0; i < 128; i++) {
        for (j = 0; j < 128; j++) {
            test_sys_recvmsg(i, j);
        }
    }
    
    return 0;
}

int net_monitor_test_5(void)
{
    int i,j;
    for (i = 0; i < 128; i++) {
        for (j = 0; j < 128; j++) {
            test_sock_ioctl(i, j, 1);
        }
    }
    
    return 0;
}