/*
 * Copyright (c) 2025-2025, Hisilicon Tech. Co., Ltd. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include "mdfx_notifier.h"
#include "mdfx_priv.h"
#include "mdfx_utils.h"

struct mdfx_notifier *mdfx_get_notifier(uint64_t visitor_type)
{
	struct mdfx_notifier *notifier = NULL;
	struct mdfx_actor_t *actor = NULL;

	if (visitor_type >= VISITOR_TYPE_MAX) {
        mdfx_pr_err("invalid visitor_type=%llu", visitor_type);
        return NULL;
	}

	if (g_mdfx_data == NULL) {
		mdfx_pr_err("g_mdfx_data is NULL");
        return NULL;
    }

	actor = &g_mdfx_data->actors[ACTOR_NOTIFIER];
	if (actor == NULL || actor->actor_data == NULL) {
		mdfx_pr_err("notifier actor is not ready");
        return NULL;
    }

	notifier = &((struct mdfx_notifier *)actor->actor_data)[visitor_type];
    if (notifier == NULL) {
        mdfx_pr_err("notifier is not ready");
		return NULL;
    }
	return notifier;
}

int mdfx_register_client(struct notifier_block *nb, uint64_t visitor_type)
{
	struct mdfx_notifier *notifier = mdfx_get_notifier(visitor_type);

	if (notifier == NULL) {
		mdfx_pr_err("notifier is NULL");
        return -1;
    }

	return raw_notifier_chain_register(&notifier->visitor_notifier_list, nb);
}
EXPORT_SYMBOL(mdfx_register_client);

int mdfx_unregister_client(struct notifier_block *nb, uint64_t visitor_type)
{
	struct mdfx_notifier *notifier = mdfx_get_notifier(visitor_type);

	if (notifier == NULL) {
		mdfx_pr_err("notifier is NULL");
        return -1;
    }

    return raw_notifier_chain_unregister(&notifier->visitor_notifier_list, nb);
}
EXPORT_SYMBOL(mdfx_unregister_client);

int mdfx_register_blocking_client(struct notifier_block *nb, uint64_t visitor_type)
{
	struct mdfx_notifier *notifier = mdfx_get_notifier(visitor_type);

	if (notifier == NULL) {
		mdfx_pr_err("notifier is NULL");
        return -1;
    }

	return blocking_notifier_chain_register(&notifier->visitor_blocking_notifier_list, nb);
}
EXPORT_SYMBOL(mdfx_register_blocking_client);

int mdfx_unregister_blocking_client(struct notifier_block *nb, uint64_t visitor_type)
{
	struct mdfx_notifier *notifier = mdfx_get_notifier(visitor_type);

	if (notifier == NULL) {
		mdfx_pr_err("notifier is NULL");
        return -1;
    }

    return blocking_notifier_chain_unregister(&notifier->visitor_blocking_notifier_list, nb);
}
EXPORT_SYMBOL(mdfx_unregister_blocking_client);

int mdfx_notify_call_chain(struct mdfx_notifier *notifier, unsigned long val, void *v)
{
	int ret1;
	int ret2;
	if (notifier == NULL) {
		mdfx_pr_err("notifier is NULL");
        return -1;
    }

    ret1 = raw_notifier_call_chain(&notifier->visitor_notifier_list, val, v);
	ret2 = blocking_notifier_call_chain(&notifier->visitor_blocking_notifier_list, val, v);
	return ret1 || ret2;
}

static int mdfx_notifier_act(struct mdfx_pri_data *mdfx_data, struct mdfx_event *event, void *value)
{
	struct mdfx_visitor_node *visitor = NULL;
	struct mdfx_event_value event_value = {0};
	int ret;

	if (mdfx_data == NULL || event == NULL) {
		mdfx_pr_err("invalid input");
        return -1;
    }

	if (!IS_ENABLE_BITS_FIELD(event->desc.current_visitor_actions, NOTIFY_DETAIL_ALL_INFO)) {
		mdfx_pr_info("NOTIFY_DETAIL_ALL_INFO is not enable");
		return 0;
	}

	visitor = mdfx_get_visitor(&mdfx_data->visitors, event->visitor_id);
	if (visitor == NULL) {
        mdfx_pr_err("visitor is not exist, visitor_id=%lld", event->visitor_id);
        return -1;
	}

	event_value.visitor_id = event->visitor_id;
	event_value.actions = event->desc.current_visitor_actions;
	ret = scnprintf(event_value.event_name, MDFX_EVENT_NAME_MAX, "%s", event->desc.event_name);
	if (unlikely(ret <= 0))
		event_value.event_name[0] = '\0';

    return mdfx_notify_call_chain(visitor->notifier, event->desc.event_type, &event_value);
}

static struct mdfx_actor_ops_t mdfx_notifier_ops = {
	.act = mdfx_notifier_act,
	.do_ioctl = NULL,
};

void mdfx_notifier_init_actor(struct mdfx_actor_t *actor)
{
	struct mdfx_notifier *notifiers = NULL;

	actor->actor_type = ACTOR_NOTIFIER;
	actor->ops = &mdfx_notifier_ops;

	notifiers = kzalloc(sizeof(struct mdfx_notifier) * VISITOR_TYPE_MAX, GFP_KERNEL);
	if (notifiers == NULL) {
		mdfx_pr_err("kzalloc failed");
        return;
    }

	actor->actor_data = notifiers;
}
