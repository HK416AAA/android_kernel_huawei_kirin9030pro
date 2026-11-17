/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2024. All rights reserved.
 * License terms: GNU General Public License (GPL)
 * Description: Huawei mtp timer
 * Author: songqiubin
 * Create: 2021-10-27
 *
 * MinTP layer2 Reliable Transmission Protocol.
 * Part of the code refers to the Linux tcpip stack
 */

#include "mintp_congestion.h"
#include "mintp_input.h"
#include "mintp_output.h"
#include "mintp_rack.h"
#include "mintp_timer.h"
#define NACK_RETRY_RTT_COE_FOUR 4
#define NACK_RETRY_RTT_COE_FIVE 5
#define PRECISION_ALG 100
#define RCV_TIME_OUT 25000
static void mtp_write_err(struct sock *sk)
{
	sk->sk_err = sk->sk_err_soft ? : ETIMEDOUT;
	mtp_sk_info(mtp_sk(sk), "sk_err %d\n", sk->sk_err);
	sk->sk_error_report(sk);

	mtp_write_queue_purge(sk);
	sk->sk_send_head = NULL;
	mtp_done(sk);
}

static void mtp_retransmit_timer(struct sock *sk)
{
	struct mtp_sock *msk = mtp_sk(sk);
	struct net_device *dev;
	struct sk_buff *skb;

	msk->stats.rto_times++;
	if (msk->rtx.retransmits >= MTP_RETRY ||
		(sk->sk_state == TCP_SYN_SENT &&
		 msk->rtx.retransmits >= MTP_SYN_RETRY)) {
		mtp_write_err(sk);
		return;
	}

	msk->tlp_high_seq = 0;
	mtp_enter_loss(sk);
	dev = mtp_odev_get(msk);
	if (unlikely(!dev))
		return;

	skb = mtp_write_queue_head(sk);
	skb->dev = dev;
	if (mtp_retransmit_skb(sk, skb) > 0) {
		dev_put(dev);
		/* Retransmission failed because of local congestion,
		 * do not backoff.
		 */
		if (!msk->rtx.retransmits)
			msk->rtx.retransmits = 1;

		msk->rtx.timeout = jiffies + MTP_RTO_MIN;
		msk->rtx.pend = MTP_RTX_TIMER_RETRANS;
		sk_reset_timer(sk, &msk->rtx.timer, msk->rtx.timeout);
		return;
	}
	dev_put(dev);

	if (sk->sk_state == TCP_ESTABLISHED && mtp_stream_is_thin(msk) &&
	    msk->rtx.retransmits <= MTP_THIN_LINEAR_RETRIES) {
		msk->rtx.backoff = 0;
		msk->rtx.rto = min(mtp_get_rto(msk), MTP_RTO_MAX);
	} else {
		msk->rtx.backoff++;
		msk->rtx.rto = min(msk->rtx.rto << 1, MTP_RTO_MAX);
	}

	msk->rtx.retransmits++;
	msk->rtx.timeout = jiffies + msk->rtx.rto;
	msk->rtx.pend = MTP_RTX_TIMER_RETRANS;
	sk_reset_timer(sk, &msk->rtx.timer, msk->rtx.timeout);
}

static void mtp_write_wakeup(struct sock *sk)
{
	if (sk->sk_state == TCP_CLOSE)
		return;

	mtp_write_xmit(sk, 0, sk_gfp_mask(sk, GFP_ATOMIC));
}

static void mtp_probe_timer(struct sock *sk)
{
	struct mtp_sock *msk = mtp_sk(sk);
    struct sk_buff *skb;
    struct net_device *dev;
	__u32 expires;

	msk->batch_send = 0;
	mtp_write_wakeup(sk);
	if (msk->packets_out || !mtp_send_head(sk)) {
		msk->rtx.probes = 0;
		return;
	}

	if (sock_flag(sk, SOCK_DEAD) || sk->sk_state == TCP_CLOSE ||
	    msk->rtx.probes >= MTP_PROBE_RETRY) {
		mtp_write_err(sk);
		return;
	}

    skb = mtp_send_head(sk);
    dev = mtp_odev_get(msk);
    if (skb && dev && msk->snd_wnd) {
		mtp_sk_info(msk, "use data skb to probe\n");
		MTP_SKB_CB(skb)->tx.need_cache = MTP_NOCACHE;
        skb->dev = dev;
		if (likely(!mtp_transmit_skb(sk, skb, 1, GFP_ATOMIC, msk->rcv_nxt))) {
            mtp_event_new_data_sent(sk, skb);
            dev_put(dev);
            return;
		}
        mtp_sk_err(msk, "mtp_transmit_skb fail\n");
    }

    if (dev) {
        dev_put(dev);
        dev = NULL;
    }

	/* Only send another probe if we didn't close things up. */
	mtp_send_ack(sk, 1);
	msk->rtx.probes++;

	expires = min(msk->rtx.rto << msk->rtx.probes, MTP_RTO_MAX);
	msk->rtx.timeout = jiffies + expires;
	msk->rtx.pend = MTP_RTX_TIMER_PROBE;
	mtp_sk_info(msk, "send probe %u rto %u expires %u\n",
		msk->rtx.probes, msk->rtx.rto, expires);
	sk_reset_timer(sk, &msk->rtx.timer, msk->rtx.timeout);
}

/* Called with BH disabled */
void mtp_write_timer_handler(struct sock *sk)
{
	struct mtp_sock *msk = mtp_sk(sk);
	if (((1 << sk->sk_state) & (TCPF_CLOSE | TCPF_LISTEN)) || !msk->rtx.pend)
		return;

	if (time_after(msk->rtx.timeout, jiffies)) {
		sk_reset_timer(sk, &msk->rtx.timer, msk->rtx.timeout);
		goto out;
	}

	mtp_mstamp_refresh(msk);
	switch (msk->rtx.pend) {
	case MTP_RTX_TIMER_RETRANS:
		mtp_retransmit_timer(sk);
		break;
	case MTP_RTX_TIMER_LOSS_PROBE:
		mtp_send_loss_probe(sk);
		break;
	case MTP_RTX_TIMER_REO_TIMEOUT:
		mtp_rack_reo_timeout(sk);
		break;
	case MTP_RTX_TIMER_PROBE:
		mtp_probe_timer(sk);
		break;
	default:
		break;
	}

out:
	sk_mem_reclaim(sk);
}

static void mtp_write_timer(mtp_timer_ptr data)
{
	struct sock *sk = (struct sock *)container_of((struct timer_list *)data, struct mtp_sock, rtx.timer);

	bh_lock_sock(sk);
	if (!sock_owned_by_user(sk)) {
		mtp_write_timer_handler(sk);
	} else {
		/* deleguate our work to mtp_release_cb() */
		if (!test_and_set_bit(MTP_WRITE_TIMER_DEFERRED, &sk->sk_tsq_flags))
			sock_hold(sk);
	}
	bh_unlock_sock(sk);
	sock_put(sk);
}

/* Called with BH disabled */
void mtp_taildoublesend_timer_handler(struct sock *sk)
{
	struct mtp_sock *msk = mtp_sk(sk);
	if (sk->sk_state != TCP_ESTABLISHED)
		return;
	if (!msk->low_latency.tds.pend)
		goto out;
	if (!msk->packets_out) {
		msk->low_latency.tds.pend = 0;
		goto out;
	}
	if (time_after(msk->low_latency.tds.timeout, jiffies)) {
		sk_reset_timer(sk, &msk->low_latency.tds.timer, msk->low_latency.tds.timeout);
		goto out;
	}
	mtp_mstamp_refresh(msk);
	
	mtp_tail_double_send(sk);
out:
	sk_mem_reclaim(sk);
}

static void mtp_taildoublesend_timer(mtp_timer_ptr data)
{
	struct sock *sk = (struct sock *)container_of(
		(struct timer_list *)data, struct mtp_sock, low_latency.tds.timer);

	bh_lock_sock(sk);
	if (!sock_owned_by_user(sk)) {
		mtp_taildoublesend_timer_handler(sk);
	} else {
		/* deleguate our work to mtp_release_cb() */
		if (!test_and_set_bit(MTP_TAILDOUBLESEND_TIMER_DEFERRED, &sk->sk_tsq_flags))
			sock_hold(sk);
	}
	bh_unlock_sock(sk);
	sock_put(sk);
}

void nack_retrans_handler(struct sock *sk)
{
	int cnt;
	struct mtp_sock *msk = mtp_sk(sk);
	struct sk_buff *skb;
	if (sk->sk_state != TCP_ESTABLISHED)
		return;
	if (!msk->packets_out || !msk->low_latency.time_sync_valid) {
		msk->low_latency.nack_retrans.valid = 0;
		goto out;
	}
	if (time_after(msk->low_latency.nack_retrans.timeout, jiffies)) {
		sk_reset_timer(sk, &msk->low_latency.nack_retrans.timer, msk->low_latency.nack_retrans.timeout);
		goto out;
	}
	if (msk->lost_skb_hint) {
		skb = msk->lost_skb_hint;
		cnt = msk->lost_cnt_hint;
	} else {
		skb = mtp_write_queue_head(sk);
		cnt = 0;
	}
	mtp_for_write_queue_from(skb, sk) {
		if (skb == mtp_send_head(sk))
			break;
		/* this is not the most efficient way to do this... */
		msk->lost_skb_hint = skb;
		msk->lost_cnt_hint = cnt;
	
		struct mtp_skb_cb *scb = MTP_SKB_CB(skb);
		/* Skip ones already (s)acked */
		if (!after(scb->end_seq, msk->snd_una) ||
			(scb->sacked & MTPCB_SACKED_ACKED))
			continue;
		if ((scb->sacked & (MTPCB_RETRANS | MTPCB_NACK_RETRANS)) &&
			(msk->cur_mstamp - scb->tx.delivered_mstamp) <
				msk->low_latency.retry_rtt * NACK_RETRY_RTT_COE_FOUR / NACK_RETRY_RTT_COE_FIVE)
			continue;

		if ((msk->cur_mstamp - scb->tx.delivered_mstamp) < msk->low_latency.raw_owd)
			continue;
		if (MTP_SKB_LL_RETRANS_CNT(skb) >= MTP_LOW_LATENCY_MAX_RETRY) {
			mtp_sk_debug(msk, "retrans %u~%u, retrans time more than %u\n", scb->seq, scb->end_seq, MTP_LOW_LATENCY_MAX_RETRY);
			continue;
		}
		cnt++;
		scb->sacked |= MTPCB_NACK_RETRANS;
		scb->flags |= MTPHDR_RTX;
		scb->tx.need_cache = MTP_NOCACHE;
		scb->opt_flags |= MTPOPT_FLAG_HIGHPRIORITY;
		mtp_transmit_skb(sk, skb, 1, GFP_ATOMIC, msk->rcv_nxt);
		msk->low_latency.retransmit_skbs++;
		MTP_SKB_LL_RETRANS_CNT(skb)++;
		mtp_sk_debug(msk, "nack retrans %u~%u lost cnt %d elapse time %u\n",
		scb->seq, scb->end_seq, cnt, msk->cur_mstamp - scb->tx.delivered_mstamp);
	}
	sk_reset_timer(
		sk, &msk->low_latency.nack_retrans.timer, jiffies + usecs_to_jiffies(msk->low_latency.nack_retrans.timeout));
out:
	sk_mem_reclaim(sk);
}

static void nack_retrans_timer(mtp_timer_ptr data)
{
	struct sock *sk = (struct sock *)container_of(
		(struct timer_list *)data, struct mtp_sock, low_latency.nack_retrans.timer);
	bh_lock_sock(sk);
	if (!sock_owned_by_user(sk)) {
		nack_retrans_handler(sk);
	} else {
		/* deleguate our work to mtp_release_cb() */
		if (!test_and_set_bit(MTP_NACK_RETRANS_DEFERRED, &sk->sk_tsq_flags))
			sock_hold(sk);
	}
	bh_unlock_sock(sk);
	sock_put(sk);
}

void low_latency_co_handler(struct sock *sk)
{
	struct mtp_sock *msk = mtp_sk(sk);
	bool flag = false;
	if (sk->sk_state != TCP_ESTABLISHED)
		return;
	u64 rcv_time_elapse = MTP_JIFFIERS32 - msk->lrcvtime;
	if (!msk->packets_out && rcv_time_elapse > RCV_TIME_OUT) {
		msk->low_latency.alg_nego.timer_valid = 0;
		mtp_sk_debug(msk, "STOP TIMER low_latency");
		goto out;
	}

	if (time_after(msk->low_latency.alg_nego.timeout, jiffies)) {
		mtp_sk_debug(msk, "RESTART TIMER low_latency");
		sk_reset_timer(sk, &msk->low_latency.alg_nego.timer, msk->low_latency.alg_nego.timeout);
		goto out;
	}
	struct mtp_low_latency_data *data_blocks = &msk->low_latency.alg_nego.data_to_send;
    *data_blocks = msk->low_latency.alg_nego.last_data;
	u32 rate = msk->low_latency.retransmit_skbs * PRECISION_ALG / msk->low_latency.transmit_skbs;
	if (rate != msk->low_latency.alg_nego.last_data.rate ||
		msk->low_latency.alg_nego.rtt != msk->low_latency.alg_nego.last_data.rtt) {
		data_blocks->rtt = msk->low_latency.alg_nego.rtt;
		data_blocks->rate = rate;
		flag = true;
		mtp_sk_debug(msk, "send rate %u rtt %u retransmit_skbs %u transmit_skbs %u",
			rate, data_blocks->rtt, msk->low_latency.retransmit_skbs, msk->low_latency.transmit_skbs);
	}
	u32 retry_rtt;
	if (msk->low_latency.delayTuneAlg != NULL) {
		run_alg(msk->low_latency.delayTuneAlg);
		retry_rtt = get_retry_rtt(msk->low_latency.delayTuneAlg);
		if (retry_rtt != msk->low_latency.alg_nego.last_data.retry_rtt && retry_rtt <= MAX_RETRY_RTT) {
			data_blocks->retry_rtt = retry_rtt;
			flag = true;
			mtp_sk_debug(msk, "send retry_rtt %u", retry_rtt);
		}
	}
	if (flag) {
        msk->low_latency.alg_nego.last_data = msk->low_latency.alg_nego.data_to_send;
		send_low_latency(sk);
    }
	msk->low_latency.alg_nego.timeout = jiffies + usecs_to_jiffies(MTP_TIMEOUT_LOW_LATENCY);
    sk_reset_timer(sk, &msk->low_latency.alg_nego.timer, msk->low_latency.alg_nego.timeout);
out:
	sk_mem_reclaim(sk);
}

static void low_latency_co_timer(mtp_timer_ptr data)
{
	struct sock *sk = (struct sock *)container_of(
		(struct timer_list *)data, struct mtp_sock, low_latency.alg_nego.timer);
	bh_lock_sock(sk);
	if (!sock_owned_by_user(sk)) {
		low_latency_co_handler(sk);
	} else {
		/* deleguate our work to mtp_release_cb() */
		if (!test_and_set_bit(MTP_LOW_LATENCY_CO_DEFERRED, &sk->sk_tsq_flags))
			sock_hold(sk);
	}
	bh_unlock_sock(sk);
	sock_put(sk);
}

static void mtp_keepalive_timer(mtp_timer_ptr data)
{
	struct sock *sk = (struct sock *)container_of((struct timer_list *)data, struct mtp_sock, inet.sk.sk_timer);
	struct mtp_sock *msk = mtp_sk(sk);
	u32 elapsed;
	/* Only process if socket is not in use. */
	bh_lock_sock(sk);
	if (sock_owned_by_user(sk)) {
		/* Try again later. */
		sk_reset_timer(sk, &sk->sk_timer, jiffies + 1);
		goto out;
	}

	if (sk->sk_state == TCP_LISTEN) {
		goto out;
	}

	if (sk->sk_state == TCP_FIN_WAIT1 || sk->sk_state == TCP_FIN_WAIT2 || sk->sk_state == TCP_LAST_ACK) {
		mtp_sk_info(msk, "keepalive expire on state %u\n", sk->sk_state);
		mtp_done(sk);
		goto out;
	}

	if (!sock_flag(sk, SOCK_KEEPOPEN) ||
	    ((1 << sk->sk_state) & (TCPF_CLOSE | TCPF_SYN_SENT)))
		goto out;

	/* It is alive without keepalive */
	if (msk->packets_out || mtp_send_head(sk)) {
		elapsed = msk->keepalive_time;
		goto resched;
	}

	elapsed = MTP_JIFFIERS32 - msk->rcv_tstamp;
	if (elapsed >= msk->keepalive_time) {
		if (msk->keepalive_probes >= MTP_PROBE_RETRY) {
			mtp_sk_info(msk, "keepalive_probes %u exceed, reset connection\n", msk->keepalive_probes);
			mtp_send_reset(sk, msk->snd_nxt, msk->rcv_nxt, GFP_ATOMIC);
			mtp_write_err(sk);
			goto out;
		}
		mtp_sk_info(msk, "send keepalive_probes %u\n", msk->keepalive_probes);
		mtp_send_ack(sk, 1);
		elapsed = min(MTP_KEEPALIVE_INTVL << msk->keepalive_probes, MTP_RTO_MAX);
		msk->keepalive_probes++;
	} else {
		elapsed = msk->keepalive_time - elapsed;
	}

resched:
	sk_reset_timer(sk, &sk->sk_timer, jiffies + elapsed);
out:
	bh_unlock_sock(sk);
	sock_put(sk);
}

/* Called with BH disabled */
void mtp_delack_timer_handler(struct sock *sk)
{
	struct mtp_sock *msk = mtp_sk(sk);
	mtp_sk_debug(msk, "delay ack send\n");
	sk_mem_reclaim_partial(sk);

	if (time_after(msk->delack.timeout, jiffies)) {
		sk_reset_timer(sk, &msk->delack.timer, msk->delack.timeout);
		return;
	}

	msk->delack.enable = 0;
	if (msk->delack.ack_pend)
		mtp_send_ack(sk, 0);
}

static void mtp_delack_timer(mtp_timer_ptr data)
{
	struct sock *sk = (struct sock *)container_of((struct timer_list *)data, struct mtp_sock, delack.timer);

	bh_lock_sock(sk);
	if (!sock_owned_by_user(sk)) {
		mtp_delack_timer_handler(sk);
	} else {
		struct mtp_sock *msk = mtp_sk(sk);
		msk->delack.quick = 1;
		/* deleguate our work to mtp_release_cb() */
		if (!test_and_set_bit(MTP_DELACK_TIMER_DEFERRED, &sk->sk_tsq_flags))
			sock_hold(sk);
	}
	bh_unlock_sock(sk);
	sock_put(sk);
}

void tack_retrans_handler(struct sock *sk)
{
	struct mtp_sock *msk = mtp_sk(sk);
	if (sk->sk_state != TCP_ESTABLISHED)
		return;
	msk->low_latency.tack_retrans.sendtack = 1;
	mtp_send_ack(sk, 0);
	msk->low_latency.tack_retrans.sendtack = 0;
}

static void mtp_tack_timer(mtp_timer_ptr data)
{
	struct sock *sk = (struct sock *)container_of(
		(struct timer_list *)data, struct mtp_sock, low_latency.tack_retrans.timer);
	bh_lock_sock(sk);

	if (!sock_owned_by_user(sk)) {
		tack_retrans_handler(sk);
	} else {
		/* deleguate our work to mtp_release_cb() */
		if (!test_and_set_bit(MTP_TACK_RETRANS_DEFERRED, &sk->sk_tsq_flags))
			sock_hold(sk);
	}
	bh_unlock_sock(sk);
	sock_put(sk);
}

void mtp_init_xmit_timers(struct sock *sk)
{
	struct mtp_sock *msk = mtp_sk(sk);

	mtp_setup_timer(&msk->delack.timer, mtp_delack_timer);
	msk->delack.ack_pend = 0;
	msk->delack.enable = 0;
	msk->delack.quick = 0;
	msk->delack.ofo_ack = 0;
	msk->delack.compress_ack = 0;
	msk->delack.ofo_rcv_nxt = msk->rcv_nxt;

	mtp_setup_timer(&msk->rtx.timer, mtp_write_timer);
	msk->rtx.rto = MTP_TIMEOUT_INIT;
	msk->rtx.pend = 0;
	msk->rtx.retransmits = 0;
	msk->rtx.backoff = 0;

	mtp_setup_timer(&msk->low_latency.tds.timer, mtp_taildoublesend_timer);
	msk->low_latency.tds.pend = 0;

	msk->keepalive_time = MTP_DEFAULT_KEEPALIVE_TIME;
	mtp_setup_timer(&sk->sk_timer, mtp_keepalive_timer);

	mtp_setup_timer(&msk->low_latency.tack_retrans.timer, mtp_tack_timer);
	msk->low_latency.tack_retrans.double_recv_cnt = 0;
	msk->low_latency.tack_retrans.sum_interval = 0;
	msk->low_latency.tack_retrans.last_recv_time = 0;
	msk->low_latency.tack_retrans.double_recv = 0;
	msk->low_latency.tack_retrans.sendtack = 0;

	mtp_setup_timer(&msk->low_latency.nack_retrans.timer, nack_retrans_timer);
	msk->low_latency.is_need_nack_retrans_time = false;
	msk->low_latency.nack_retrans.valid = 0;

	mtp_setup_timer(&msk->low_latency.alg_nego.timer, low_latency_co_timer);
	msk->low_latency.alg_nego.timeout = MTP_TIMEOUT_LOW_LATENCY;
	msk->low_latency.alg_nego.rtt = 0;
	msk->low_latency.alg_nego.last_data.rate = MAX_RATE;
	msk->low_latency.alg_nego.last_data.rtt = 0;
	msk->low_latency.alg_nego.last_data.retry_rtt = 0;
}

void mtp_clear_xmit_timers(struct sock *sk)
{
	struct mtp_sock *msk = mtp_sk(sk);
	sk_stop_timer(sk, &msk->delack.timer);
	sk_stop_timer(sk, &msk->rtx.timer);
	sk_stop_timer(sk, &sk->sk_timer);
	sk_stop_timer(sk, &msk->low_latency.tds.timer);
	sk_stop_timer(sk, &msk->low_latency.tack_retrans.timer);
	sk_stop_timer(sk, &msk->low_latency.nack_retrans.timer);
	sk_stop_timer(sk, &msk->low_latency.alg_nego.timer);
}

void mtp_set_keepalive(struct sock *sk, int val)
{
	if ((1 << sk->sk_state) & (TCPF_CLOSE | TCPF_LISTEN))
		return;

	if (val && !sock_flag(sk, SOCK_KEEPOPEN))
		sk_reset_timer(sk, &sk->sk_timer, jiffies + mtp_sk(sk)->keepalive_time);
	else if (!val)
		sk_stop_timer(sk, &sk->sk_timer);
}
