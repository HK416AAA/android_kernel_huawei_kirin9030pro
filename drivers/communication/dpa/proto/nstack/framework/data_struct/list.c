/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 */

#include "list.h"


void dmm_list_link(struct dmm_list_head *newp, struct dmm_list_head *head)
{
    if (dmm_is_list_empty(newp)) {
        return;
    }

    newp->next->prev = head;
    newp->prev->next = head->next;

    head->next->prev = newp->prev;
    head->next = newp->next;

    newp->next = NULL;
    newp->prev = NULL;
}

void dmm_hlist_del_init(struct dmm_hlist_node *n)
{
    struct dmm_hlist_node *next = n->next;
    struct dmm_hlist_node **pprev = n->pprev;

    if ((pprev == NULL) && (next == NULL)) {
        return;
    }

    if (pprev != NULL) {
        *pprev = next;
    }

    if (next != NULL) {
        next->pprev = pprev;
    }

    n->next = NULL;
    n->pprev = NULL;
}

