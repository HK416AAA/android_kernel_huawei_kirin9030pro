/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description: oal_queue.h header file
 * Author: dpa drivers
 */

#ifndef OAL_LIST_H
#define OAL_LIST_H

/* 其他头文件包含 */
#include "oal_types.h"
#include "oal_mm.h"
#include "oal_util.h"
/* 宏定义 */

/* 遍历双向链表使用时请在其后加大括号 */
#define oal_dlist_search_for_each(_dlist_pos, _dilst_head) \
    for ((_dlist_pos) = (_dilst_head)->pst_next; (_dlist_pos) != (_dilst_head); (_dlist_pos) = (_dlist_pos)->pst_next)

/* 遍列双向链表，并可安全删除某个节点 */
#define oal_dlist_search_for_each_safe(_dlist_pos, n, _dilst_head)                                    \
    for ((_dlist_pos) = (_dilst_head)->pst_next, (n) = (_dlist_pos)->pst_next; (_dlist_pos) != (_dilst_head); \
         (_dlist_pos) = (n), (n) = (_dlist_pos)->pst_next)

/* 遍列netbuf链表，并可安全删除某个节点 */
#define oal_netbuf_search_for_each_safe(_dlist_pos, n, _dilst_head) \
        for ((_dlist_pos) = ((_dilst_head)->hdr).next, (n) = oal_netbuf_next(_dlist_pos); \
            (_dlist_pos) != (oal_netbuf_stru *)(&(_dilst_head)->hdr); \
            (_dlist_pos) = (n), (n) = oal_netbuf_next(_dlist_pos))
/*
 * 获得双向链表中指定的节点 第一个参数为模板链表结构体指针； 第二个参数为链表中数据结构体类型名；
 * 第三个参数为数据结构体中模板链表结构体的名字
 */
#define oal_dlist_get_entry(_dlist_ptr, _data_type, _data_member_dlist_name) \
    container_of(_dlist_ptr, _data_type, _data_member_dlist_name)

/* STRUCT定义 */
typedef struct tag_oal_list_entry_stru {
    struct tag_oal_list_entry_stru *pst_next;
} oal_list_entry_stru;

typedef struct {
    struct tag_oal_list_entry_stru *pst_next;
    struct tag_oal_list_entry_stru *pst_prev;
} oal_list_head_stru;

typedef struct tag_oal_dlist_head_stru {
    struct tag_oal_dlist_head_stru *pst_next;
    struct tag_oal_dlist_head_stru *pst_prev;
} oal_dlist_head_stru;

/*
 * 函 数 名  : oal_dlist_init_head
 * 功能描述  : 链表初始化函数
 * 输入参数  : pst_list: 链表头指针
 */
OAL_STATIC OAL_INLINE void oal_dlist_init_head(oal_dlist_head_stru *pst_list)
{
    if (oal_unlikely(pst_list == NULL)) {
        oal_warn_on(1);
        return;
    }
    pst_list->pst_next = pst_list;
    pst_list->pst_prev = pst_list;
}

/*
 * 函 数 名  : oal_dlist_add
 * 功能描述  : 链表节点加入操作
 * 输入参数  : pst_new: 新加入节点指针
 *             pst_prev: 加入位置的前一个节点指针
 *             pst_next: 加入位置的下一个节点指针
 */
OAL_STATIC OAL_INLINE void oal_dlist_add(oal_dlist_head_stru *pst_new,
                                         oal_dlist_head_stru *pst_prev,
                                         oal_dlist_head_stru *pst_next)
{
    if (oal_unlikely((pst_new == NULL) || (pst_prev == NULL) || (pst_prev == NULL))) {
        oal_warn_on(1);
        return;
    }
    pst_next->pst_prev = pst_new;
    pst_new->pst_next = pst_next;
    pst_new->pst_prev = pst_prev;
    pst_prev->pst_next = pst_new;
}

/*
 * 函 数 名  : oal_dlist_delete
 * 功能描述  : 从链表的指定位置删除一个节点提炼
 * 输入参数  : pst_prev: 删除位置的前一个节点指针
 *             pst_next: 删除位置的下一个节点指针
 */
OAL_STATIC OAL_INLINE void oal_dlist_delete(oal_dlist_head_stru *pst_prev, oal_dlist_head_stru *pst_next)
{
    if (oal_unlikely((pst_prev == NULL) || (pst_next == NULL))) {
        oal_warn_on(1);
        return;
    }
    pst_next->pst_prev = pst_prev;
    pst_prev->pst_next = pst_next;
}

/*
 * 函 数 名  : oal_dlist_is_empty
 * 功能描述  : 判断一个链表是否为空
 * 输入参数  : pst_head: 链表头指针
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 oal_dlist_is_empty(oal_dlist_head_stru *pst_head)
{
    if (oal_unlikely(pst_head == NULL)) {
        oal_warn_on(1);
        return OAL_TRUE;
    }
    if (oal_any_null_ptr2(pst_head->pst_next, pst_head->pst_prev)) {
        return OAL_TRUE;
    }

    return pst_head->pst_next == pst_head;
}

/*
 * 函 数 名  : oal_dlist_add_head
 * 功能描述  : 往链表头部插入节点
 * 输入参数  : pst_new: 要插入的新节点
 *             pst_head: 链表头指针
 */
OAL_STATIC OAL_INLINE void oal_dlist_add_head(oal_dlist_head_stru *pst_new, oal_dlist_head_stru *pst_head)
{
    oal_dlist_add(pst_new, pst_head, pst_head->pst_next);
}

/*
 * 函 数 名  : oal_dlist_add_tail
 * 功能描述  : 向链表尾部插入节点
 * 输入参数  : pst_new: 要插入的新节点
 *             pst_head: 链表头指针
 */
OAL_STATIC OAL_INLINE void oal_dlist_add_tail(oal_dlist_head_stru *pst_new, oal_dlist_head_stru *pst_head)
{
    oal_dlist_add(pst_new, pst_head->pst_prev, pst_head);
}

/*
 * 函 数 名  : oal_dlist_delete_entry
 * 功能描述  : 删除链表中的指定节点,不负责释放，不判断链表是否为空，请注意
 * 输入参数  : pst_entry: 需要删除的节点
 */
OAL_STATIC OAL_INLINE void oal_dlist_delete_entry(oal_dlist_head_stru *pst_entry)
{
    if (oal_unlikely(pst_entry == NULL)) {
        oal_warn_on(1);
        return;
    }

    if (oal_unlikely(oal_any_null_ptr2(pst_entry->pst_next, pst_entry->pst_prev))) {
        return;
    }

    oal_dlist_delete(pst_entry->pst_prev, pst_entry->pst_next);
    pst_entry->pst_next = NULL;
    pst_entry->pst_prev = NULL;
}

/*
 * 函 数 名  : oal_dlist_delete_head
 * 功能描述  : 从双向链表头部删除一个节点,不判断链表是否为空，不负责释放内存 请注意
 */
OAL_STATIC OAL_INLINE oal_dlist_head_stru *oal_dlist_delete_head(oal_dlist_head_stru *pst_head)
{
    oal_dlist_head_stru *pst_node = NULL;

    if (oal_unlikely(pst_head == NULL)) {
        oal_warn_on(1);
        return NULL;
    }

    pst_node = pst_head->pst_next;

    oal_warn_on(pst_node == pst_head);
    oal_warn_on(pst_node == NULL);

    oal_dlist_delete_entry(pst_node);

    return pst_node;
}
/*
 * 函 数 名  : oal_dlist_join_tail
 * 功能描述  : 将链表2 加入链表1的尾部
 */
OAL_STATIC OAL_INLINE void oal_dlist_join_tail(oal_dlist_head_stru *pst_head1, oal_dlist_head_stru *pst_head2)
{
    oal_dlist_head_stru *pst_dlist1_tail = NULL;
    oal_dlist_head_stru *pst_dlist2_tail = NULL;
    oal_dlist_head_stru *pst_dlist2_first = NULL;

    if (oal_unlikely((pst_head1 == NULL) || (pst_head2 == NULL))) {
        oal_warn_on(1);
        return;
    }

    pst_dlist1_tail = pst_head1->pst_prev;
    pst_dlist2_tail = pst_head2->pst_prev;
    pst_dlist2_first = pst_head2->pst_next;
    pst_dlist1_tail->pst_next = pst_dlist2_first;
    pst_dlist2_first->pst_prev = pst_dlist1_tail;
    pst_head1->pst_prev = pst_dlist2_tail;
    pst_dlist2_tail->pst_next = pst_head1;
}

#endif /* end of oal_list.h */
