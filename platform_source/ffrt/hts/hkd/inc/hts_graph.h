/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: hts_graph.h
 */
#ifndef _HTS_GRAPH_H_
#define _HTS_GRAPH_H_
 
#include <linux/types.h>
#include "ffrt_configs.h"
 
#define NODE_NUM_MAX 3
#define NODE_NAME_LEN_MAX 20
 
enum graph_type_kernel {
    STATIC_GRAPH_KERNEL = 0,
    DYNAMIC_GRAPH_KERNEL
};
 
typedef struct {
    unsigned int input_node_num;
    char input_node_name[NODE_NUM_MAX][NODE_NAME_LEN_MAX];
    soc_ip input_dev_type[NODE_NUM_MAX];
    unsigned int src_event[NODE_NUM_MAX];
    unsigned int output_node_num;
    char output_node_name[NODE_NUM_MAX][NODE_NAME_LEN_MAX];
    soc_ip output_dev_type[NODE_NUM_MAX];
    unsigned int dst_event[NODE_NUM_MAX];
    unsigned int src_repeat;
    unsigned int dst_repeat;
} hts_graph_rule;
 
typedef struct {
    const char* name;
    enum graph_type_kernel graph_type;
    unsigned int rule_num;
    hts_graph_rule* graph_node;
    bool is_register;
    bool is_enable;
    pid_t pid;
    uint16_t event_count;
    uint16_t graph_id;
} hts_graph_kernel;
 
#endif