/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 */


#ifndef LIST_H
#define LIST_H

#include "stack_types.h"

#ifdef __cplusplus
/* *INDENT-OFF* */
extern "C" {
/* *INDENT-ON* */
#endif

struct dmm_list_head {
    struct dmm_list_head *next;
    struct dmm_list_head *prev;
};

struct dmm_hlist_node {
    /**
     * @pprev: point the previous node's next pointer
     */
    struct dmm_hlist_node *next;
    struct dmm_hlist_node **pprev;
};

struct dmm_hlist_head {
    struct dmm_hlist_node *first;
};

#define dmm_list_entry(ptr, type, member) container_of(ptr, type, member)

#define dmm_list_for_each_entry_type(tpos, typeof_tpos, pos, head, member)                                     \
    for ((pos) = ((head)->next);                                                                               \
         ((pos) != NULL) && ((pos) != (head)) && ((tpos) = dmm_list_entry((pos), typeof_tpos, member), true);    \
         (pos) = ((pos)->next))

#define dmm_list_for_each_entry(tpos, pos, head, member)                                                            \
    for ((pos) = ((head)->next);                                                                                    \
         ((pos) != NULL) && ((pos) != (head)) && ((tpos) = dmm_list_entry((pos), __typeof__(*(tpos)), member), true); \
         (pos) = ((pos)->next))

#define dmm_list_for_each_entry_head(tpos, pos, head, member)                                                  \
    for ((pos) = (struct dmm_list_head *)((head)->next); ((pos) != NULL) && ((pos) != (struct dmm_list_head *)(head)) \
        && ((tpos) = dmm_list_entry((pos), __typeof__(*(tpos)), member), true);                                    \
         (pos) = (pos)->next)

#define dmm_list_for_each_safe_entry(tpos, pos, n, head, member)                                               \
    for ((pos) = (head)->next, (n) = (pos)->next;                                                                  \
         ((pos) != NULL) && ((pos) != (head)) && ((tpos) = dmm_list_entry((pos), __typeof__(*(tpos)), member), true); \
         (pos) = (n), (n) = (pos)->next)

#define DMM_INIT_LIST_HEAD(list)    \
do {                                \
        (list)->next = (list);      \
        (list)->prev = (list);      \
} while (false)

#define DMM_INIT_LIST_NODE(list)    \
do {                                \
        (list)->next = NULL;        \
        (list)->prev = NULL;        \
} while (false)

static inline bool dmm_is_list_empty(const struct dmm_list_head *head)
{
    return (head->next == head);
}

/*
 * @head: the list to test.
 */
static inline void dmm_list_add(struct dmm_list_head *newp, struct dmm_list_head *head)
{
    head->next->prev = newp;
    newp->next = head->next;
    newp->prev = head;
    head->next = newp;
}

/* insert newp list without newp's head into head->next */
void dmm_list_link(struct dmm_list_head *newp, struct dmm_list_head *head);

/* insert newp list without newp's head into head tail */
static inline void dmm_list_link_tail(struct dmm_list_head *newp, struct dmm_list_head *head)
{
    dmm_list_link(newp, head->prev);
}

static inline void dmm_list_add_tail(struct dmm_list_head *newp, const struct dmm_list_head *head)
{
    dmm_list_add(newp, head->prev);
}

static inline void dmm_list_del(struct dmm_list_head *entry)
{
    if ((entry->prev == NULL) || (entry->next == NULL)) {
        return;
    }
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
    entry->next = NULL;
    entry->prev = NULL;
}

static inline struct dmm_list_head *dmm_list_get_first(const struct dmm_list_head *head)
{
    return head->next;
}

void dmm_hlist_del_init(struct dmm_hlist_node *n);

static inline bool dmm_is_hlist_empty(const struct dmm_hlist_head *head)
{
    return (head->first == NULL);
}

/* add after the head */
static inline void dmm_hlist_add_head(struct dmm_hlist_node *node, struct dmm_hlist_head *head)
{
    struct dmm_hlist_node *first = head->first;

    node->next = first;
    if (first != NULL) {
        first->pprev = &node->next;
    }

    head->first = node;
    node->pprev = &head->first;
}

#define DMM_INIT_HLIST_HEAD(ptr) ((ptr)->first = NULL)
#define DMM_INIT_HLIST_NODE(ptr)    \
do {                                \
        (ptr)->next = NULL;         \
        (ptr)->pprev = NULL;        \
} while (false)

#define dmm_hlist_entry(ptr, type, member) container_of(ptr, type, member)

/**
 * dmm_hlist_for_each_entry - iterate over list of given type
 * @member: the name of the dmm_hlist_node within the struct.
 * @head:   the head for your list.
 * @pos:    the &struct dmm_hlist_node to use as a loop cursor.
 * @tpos:   the type * to use as a loop cursor.
 */
#define dmm_hlist_for_each_entry(tpos, pos, head, member)                                           \
    for ((pos) = (head)->first;                                                                       \
         ((pos) != NULL) && ((tpos) = dmm_hlist_entry((pos), __typeof__(*(tpos)), member), true); \
         (pos) = (pos)->next)

/**
 * dmm_hlist_for_each_entry_type - iterate over list of given type
 * @member: the name of the dmm_hlist_node within the struct.
 * @head:   the head for your list.
 * @pos:    the &struct dmm_hlist_node to use as a loop cursor.
 * @tpos:   the type * to use as a loop cursor.
 */
#define dmm_hlist_for_each_entry_type(tpos, typeof_tpos, pos, head, member)              \
    for ((pos) = (head)->first;                                                            \
         ((pos) != NULL) && ((tpos) = dmm_hlist_entry((pos), typeof_tpos, member), true);  \
         (pos) = (pos)->next)
/**
 * next must be != NULL
 * add n node before next node
 *
 * @n: new node
 * @next: node in the hlist
 */
static inline void dmm_hlist_add_before(struct dmm_hlist_node *n, struct dmm_hlist_node *next)
{
    n->pprev = next->pprev;
    n->next = next;
    next->pprev = &n->next;
    *(n->pprev) = n;
}

/**
 * next must be != NULL
 * add n node after next node
 *  actual behavior is add after n
 * @n: node in the hlist
 * @next: new node
 */
static inline void dmm_hlist_add_after(struct dmm_hlist_node *n, struct dmm_hlist_node *next)
{
    next->next = n->next;
    n->next = next;
    next->pprev = &n->next;
    if (next->next != NULL) {
        next->next->pprev = &next->next;
    }
}

static inline bool dmm_hlist_unhashed(const struct dmm_hlist_node *h)
{
    return (h->pprev == NULL);
}

#ifdef __cplusplus
/* *INDENT-OFF* */
};
/* *INDENT-ON* */
#endif

#endif /* LIST_H */
