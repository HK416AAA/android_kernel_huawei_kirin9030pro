/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: mntn_status_savelog header
 * Create: 2024-02-02
 */

#ifndef __MNTN_STATUS_SAVELOG_H__
#define __MNTN_STATUS_SAVELOG_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CONFIG_CONTEXTHUB_MNTN_STATUS_SAVELOG
/**
 * @brief get dump_file dir.
 *
 * @return NA
 */
void *get_dump_restore_dir(void);

/**
 * @brief savelog process init.
 *
 * @return NA
 */
void mntn_status_savelog(void);
#endif

#ifdef __cplusplus
}
#endif
#endif
