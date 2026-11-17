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

#ifndef __BSP_PRINT_H__
#define __BSP_PRINT_H__

#include <linux/printk.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ****************************
 * 枚举定义
 * BSP_PRINT_OFF: 表示打印关闭
 * BSP_P_FATAL的打印级别最高
 * *************************** */
enum bsp_log_level {
    BSP_PRINT_OFF = 0,
    BSP_P_FATAL = 1,
    BSP_P_ERR,
    BSP_P_WRN,
    BSP_P_INFO,
    BSP_P_DEBUG,
    BSP_LEVEL_BUTT
};
// 打印接口性能极差，只允许在启动时和dump调用存日志回调前使用
void bsp_dpa_print(enum bsp_log_level level, char *fmt, ...) __attribute__((format(printf, 2, 3)));
// 打印接口性能极差，只允许在启动时和dump调用存日志回调前使用
#define dpa_pr_fatal(fmt, ...) do { \
    bsp_dpa_print(BSP_P_FATAL, fmt, ##__VA_ARGS__); \
    (void)printk(KERN_CRIT "[mod_dpa_host]" fmt, ##__VA_ARGS__);\
} while (0)
#define dpa_pr_err(fmt, ...) do { \
    bsp_dpa_print(BSP_P_ERR, fmt, ##__VA_ARGS__); \
    (void)printk(KERN_ERR "[mod_dpa_host]" fmt, ##__VA_ARGS__);\
} while (0)
#define dpa_pr_wrn(fmt, ...) do { \
    bsp_dpa_print(BSP_P_WRN, fmt, ##__VA_ARGS__); \
    (void)printk(KERN_WARNING "[mod_dpa_host]" fmt, ##__VA_ARGS__);\
} while (0)
#define dpa_pr_info(fmt, ...) do { \
    bsp_dpa_print(BSP_P_INFO, fmt, ##__VA_ARGS__); \
    (void)printk(KERN_INFO "[mod_dpa_host]" fmt, ##__VA_ARGS__);\
} while (0)
#define dpa_pr_debug(fmt, ...) do { \
    bsp_dpa_print(BSP_P_DEBUG, fmt, ##__VA_ARGS__); \
    (void)printk(KERN_DEBUG "[mod_dpa_host]" fmt, ##__VA_ARGS__);\
} while (0)

#define bsp_info(fmt, ...) do { \
    pr_info("[mod_dpa_host] " fmt, ##__VA_ARGS__); \
} while (0)

#ifdef __cplusplus
}
#endif

#endif
