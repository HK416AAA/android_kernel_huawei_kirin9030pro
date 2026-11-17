/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: Implement red black tree
 * Create: 2019-12-26
 * Note: To use this red black tree, instead of including the data structure in ns_rb_node, users need to include
 *       ns_rb_node as a struct in the data structure (typical in Linux implementation).
 *       During tree operations, users can use rb_entry(ptr, type, member) to get pointer to data structure from pointer
 *       to ns_rb_node (member is the name of struct ns_rb_node member in that data structure).
 */
#include "stack_rb_tree.h"


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Set parent node's left or right pointer to child node based on the relationship between node and parent node */
static void link_parent_child(const struct ns_rb_node *node, struct ns_rb_root *root,
                              struct ns_rb_node *parent_node, const struct ns_rb_node *child_node)
{
    if (parent_node != NULL) {
        if (parent_node->rb_left == node) {
            parent_node->rb_left = (struct ns_rb_node *)child_node;
        } else {
            parent_node->rb_right = (struct ns_rb_node *)child_node;
        }
    } else {
        root->rb_node_p = (struct ns_rb_node *)child_node;
    }
}

static inline bool is_node_black(const struct ns_rb_node *node)
{
    return ((node == NULL) || (node->color == RB_BLACK));
}

static inline bool both_children_black(const struct ns_rb_node *node)
{
    return (is_node_black(node->rb_left) && is_node_black(node->rb_right));
}

static inline void set_node_black(struct ns_rb_node *node)
{
    if (node != NULL) {
        node->color = RB_BLACK;
    }
}

static void rb_rotate_left(struct ns_rb_node *node, struct ns_rb_root *root)
{
    struct ns_rb_node *right_node = node->rb_right;

    node->rb_right = right_node->rb_left;
    if (right_node->rb_left != NULL) {
        right_node->rb_left->rb_parent = node;
    }

    right_node->rb_parent = node->rb_parent;
    link_parent_child(node, root, node->rb_parent, right_node);

    right_node->rb_left = node;
    node->rb_parent = right_node;
}

static void rb_rotate_right(struct ns_rb_node *node, struct ns_rb_root *root)
{
    struct ns_rb_node *left_node = node->rb_left;

    node->rb_left = left_node->rb_right;
    if (left_node->rb_right != NULL) {
        left_node->rb_right->rb_parent = node;
    }

    left_node->rb_parent = node->rb_parent;
    link_parent_child(node, root, node->rb_parent, left_node);

    left_node->rb_right = node;
    node->rb_parent = left_node;
}

/*
 * Note: Users of this function should make sure that node != NULL and parent_node != NULL
 */
void rb_fix_insert_violation(struct ns_rb_node *node_p, struct ns_rb_root *root)
{
    struct ns_rb_node *node = node_p;

    while ((node != root->rb_node_p) && (node->rb_parent->color == RB_RED)) {
        if (node->rb_parent == node->rb_parent->rb_parent->rb_left) {
            /* Case 1: node's parent is the left child of node's grandparent */
            struct ns_rb_node *uncle_node = node->rb_parent->rb_parent->rb_right;

            if ((uncle_node != NULL) && (uncle_node->color == RB_RED)) {
                /* Case 1.1: node's uncle node is red, only recoloring is required */
                node->rb_parent->color = RB_BLACK;
                uncle_node->color = RB_BLACK;
                node->rb_parent->rb_parent->color = RB_RED;
                node = node->rb_parent->rb_parent;
            } else {
                /*
                 * Case 1.2: node's uncle node is black, and node is the right child of its parent, first rotate left
                 *           and then rotate right. Swap the color of parent and grandparent in the end
                 * Case 1.3: node's uncle node is black, and node is the left child of its parent, rotate right and
                 *           swap the color of parent and grandparent in the end
                 */
                if (node->rb_parent->rb_right == node) {
                    node = node->rb_parent;
                    rb_rotate_left(node, root);
                }

                node->rb_parent->color = RB_BLACK;
                node->rb_parent->rb_parent->color = RB_RED;
                rb_rotate_right(node->rb_parent->rb_parent, root);
            }
        } else {
            /* Case 2: node's parent is the right child of node's grandparent (mirror of Case 1) */
            struct ns_rb_node *uncle_node = node->rb_parent->rb_parent->rb_left;

            if ((uncle_node != NULL) && (uncle_node->color == RB_RED)) {
                node->rb_parent->color = RB_BLACK;
                uncle_node->color = RB_BLACK;
                node->rb_parent->rb_parent->color = RB_RED;
                node = node->rb_parent->rb_parent;
            } else {
                if (node->rb_parent->rb_left == node) {
                    node = node->rb_parent;
                    rb_rotate_right(node, root);
                }

                node->rb_parent->color = RB_BLACK;
                node->rb_parent->rb_parent->color = RB_RED;
                rb_rotate_left(node->rb_parent->rb_parent, root);
            }
        }
    }

    root->rb_node_p->color = RB_BLACK;
}

static void rb_check_rb_right_black(struct ns_rb_node **sibling_node, struct ns_rb_root *root,
                                    const struct ns_rb_node *parent_node)
{
    if (is_node_black((*sibling_node)->rb_right)) {
        set_node_black((*sibling_node)->rb_left);
        (*sibling_node)->color = RB_RED;
        rb_rotate_right(*sibling_node, root);
        *sibling_node = parent_node->rb_right;
    }
}

static void rb_check_rb_left_black(struct ns_rb_node **sibling_node, struct ns_rb_root *root,
                                   const struct ns_rb_node *parent_node)
{
    if (is_node_black((*sibling_node)->rb_left)) {
        set_node_black((*sibling_node)->rb_right);
        (*sibling_node)->color = RB_RED;
        rb_rotate_left(*sibling_node, root);
        *sibling_node = parent_node->rb_left;
    }
}


static void rb_fix_delete_violation(struct ns_rb_node *child_node_p, struct ns_rb_node *parent_node_p,
    struct ns_rb_root *root)
{
    struct ns_rb_node *child_node = child_node_p;
    struct ns_rb_node *parent_node = parent_node_p;

    while ((root->rb_node_p != child_node) && is_node_black(child_node) && (parent_node != NULL)) {
        struct ns_rb_node *sibling_node = NULL;
        if (parent_node->rb_left == child_node) {
            /* Case 1: child_node is the left child of parent_node */
            sibling_node = parent_node->rb_right;

            /*
             * Case 1.1: sibling node is red, rotate left to move sibling up, recolor the sbiling node and parent node,
             *           then the situation becomes Case 1.2
             */
            if (sibling_node->color == RB_RED) {
                sibling_node->color = RB_BLACK;
                parent_node->color = RB_RED;
                rb_rotate_left(parent_node, root);
                sibling_node = parent_node->rb_right;
            }

            if (both_children_black(sibling_node)) {
                /*
                 * Case 1.2: sibling node is black and both of its children are black, recolor the sibling node and
                 *           move up to parent node for next round of operation
                 */
                sibling_node->color = RB_RED;
                child_node = parent_node;
                parent_node = parent_node->rb_parent;
            } else {
                /*
                 * Case 1.3: sibling node is black and only its left child is red, recolor and rotate right, move to
                 *           Case 1.4
                 */
                rb_check_rb_right_black(&sibling_node, root, parent_node);

                /*
                 * Case 1.4: sibling node is black and its right child is red (or both children are red), recolor and
                 *           rotate left
                 */
                sibling_node->color = parent_node->color;
                parent_node->color = RB_BLACK;
                sibling_node->rb_right->color = RB_BLACK;
                rb_rotate_left(parent_node, root);
                child_node = root->rb_node_p;
            }
        } else {
            /* Case 2: child_node is the right child of parent_node (mirror of Case 1) */
            sibling_node = parent_node->rb_left;

            if (sibling_node->color == RB_RED) {
                sibling_node->color = RB_BLACK;
                parent_node->color = RB_RED;
                rb_rotate_right(parent_node, root);
                sibling_node = parent_node->rb_left;
            }

            if (both_children_black(sibling_node)) {
                sibling_node->color = RB_RED;
                child_node = parent_node;
                parent_node = parent_node->rb_parent;
            } else {
                rb_check_rb_left_black(&sibling_node, root, parent_node);
                sibling_node->color = parent_node->color;
                parent_node->color = RB_BLACK;
                sibling_node->rb_left->color = RB_BLACK;
                rb_rotate_right(parent_node, root);
                child_node = root->rb_node_p;
            }
        }
    }

    set_node_black(child_node);
}

static void rb_delete_node_with_two_children(const struct ns_rb_node *node, struct ns_rb_root *root)
{
    /* Use this pointer to find the inorder successor of node */
    struct ns_rb_node *inorder_successor = node->rb_right;
    while (inorder_successor->rb_left != NULL) {
        inorder_successor = inorder_successor->rb_left;
    }

    link_parent_child(node, root, node->rb_parent, inorder_successor);

    struct ns_rb_node *child_node = inorder_successor->rb_right;
    struct ns_rb_node *parent_node = inorder_successor->rb_parent;
    uint8_t color = inorder_successor->color;

    if (parent_node == node) {
        parent_node = inorder_successor;
    } else {
        if (child_node != NULL) {
            child_node->rb_parent = parent_node;
        }

        parent_node->rb_left = child_node;

        inorder_successor->rb_right = node->rb_right;
        node->rb_right->rb_parent = inorder_successor;
    }

    inorder_successor->color = node->color;
    inorder_successor->rb_parent = node->rb_parent;
    inorder_successor->rb_left = node->rb_left;
    node->rb_left->rb_parent = inorder_successor;

    if (color == RB_BLACK) {
        rb_fix_delete_violation(child_node, parent_node, root);
    }
}

/*
 * First perform standard BST node deletion, then fix color violation if deleted node is black
 *
 * Note: Users of this function should make sure that node != NULL and paret_node != NULL
 */
void rb_delete_node(const struct ns_rb_node *node, struct ns_rb_root *root)
{
    struct ns_rb_node *child_node = NULL;
    if (node->rb_left == NULL) {
        child_node = node->rb_right;
    } else if (node->rb_right == NULL) {
        child_node = node->rb_left;
    } else {
        rb_delete_node_with_two_children(node, root);
        return;
    }

    struct ns_rb_node *parent_node = node->rb_parent;

    if (child_node != NULL) {
        child_node->rb_parent = parent_node;
    }

    link_parent_child(node, root, parent_node, child_node);

    if (node->color == RB_BLACK) {
        rb_fix_delete_violation(child_node, parent_node, root);
    }
}

/* Note: Users of this function should make sure that node != NULL */
struct ns_rb_node *rb_inorder_successor(struct ns_rb_node *node_p)
{
    struct ns_rb_node *node = node_p;

    if (node->rb_right != NULL) {
        node = node->rb_right;
        while (node->rb_left != NULL) {
            node = node->rb_left;
        }
        return node;
    }

    struct ns_rb_node *parent_node = node->rb_parent;
    while ((parent_node != NULL) && (node == parent_node->rb_right)) {
        node = parent_node;
        parent_node = parent_node->rb_parent;
    }

    return parent_node;
}

/* Note: Users of this function should make sure that node != NULL and paret_node != NULL */
static void rb_link_two_nodes(struct ns_rb_node *node, struct ns_rb_node *parent_node, u8 is_left)
{
    if (is_left == 1U) {
        parent_node->rb_left = node;
    } else {
        parent_node->rb_right = node;
    }
    node->rb_parent = parent_node;
}

/* Insert the ns_rb_node in data to red black tree. Return 0 for success; return -1 for failure (e.g. duplicate) */
s32 rb_insert_node(struct ns_rb_node *nd, struct ns_rb_root *root, rb_compare_func func)
{
    struct ns_rb_node *parent = NULL;
    u8 is_left = 0;
    struct ns_rb_node *cur = (root)->rb_node_p;
    s32 compare_result = 1;
    s32 ret = 0;
    while (cur != NULL) {
        parent = cur;
        compare_result = func(cur, nd);
        if (compare_result > 0) {
            cur = cur->rb_left;
            is_left = 1;
        } else if (compare_result < 0) {
            cur = cur->rb_right;
            is_left = 0;
        } else {
            break;
        }
    }
    if (compare_result != 0) {
        if (parent == NULL) {
            root->rb_node_p = nd;
        } else {
            rb_link_two_nodes(nd, parent, is_left);
        }
        rb_fix_insert_violation(nd, root);
    } else {
        ret = -1;
    }

    return ret;
}

/* Search ns_rb_node in the red black tree. If found, "return" that node; else, "return" NULL */
struct ns_rb_node *rb_search_node(const struct ns_rb_node *exp_nd, const struct ns_rb_root *root, rb_compare_func func)
{
    struct ns_rb_node *cur = root->rb_node_p;

    while (cur != NULL) {
        s32 ret = func(cur, exp_nd);
        if (ret > 0) {
            cur = cur->rb_left;
        } else if (ret < 0) {
            cur = cur->rb_right;
        } else {
            break;
        }
    }

    return cur;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

