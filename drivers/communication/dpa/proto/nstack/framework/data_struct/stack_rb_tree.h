/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: Implement red black tree
 * Create: 2019-12-26
 */

#ifndef NSTACK_RB_TREE_H
#define NSTACK_RB_TREE_H

#include "stack_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define RB_RED 0U
#define RB_BLACK 1U

struct ns_rb_node {
    uint8_t color;

    /* Union is for alignment under different operating systems */
    union {
        struct ns_rb_node *rb_parent;
        uint64_t rb_parent_a;
    };

    union {
        struct ns_rb_node *rb_right;
        uint64_t rb_right_a;
    };

    union {
        struct ns_rb_node *rb_left;
        uint64_t rb_left_a;
    };
};

struct ns_rb_root {
    /* Union is for alignment under different OS */
    union {
        struct ns_rb_node *rb_node_p;
        uint64_t rb_node_a;
    };
};

typedef s32 (*rb_compare_func)(const struct ns_rb_node *nd, const struct ns_rb_node *cmp_nd);

s32 rb_insert_node(struct ns_rb_node *nd, struct ns_rb_root *root, rb_compare_func func);
struct ns_rb_node *rb_search_node(const struct ns_rb_node *exp_nd, const struct ns_rb_root *root, rb_compare_func func);

void rb_fix_insert_violation(struct ns_rb_node *node_p, struct ns_rb_root *root);
void rb_delete_node(const struct ns_rb_node *node, struct ns_rb_root *root);
struct ns_rb_node *rb_inorder_successor(struct ns_rb_node *node_p);

/* Get the struct that contain ns_rb_node */
#define rb_entry(ptr, type, member) container_of(ptr, type, member)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NSTACK_RB_TREE_H */
