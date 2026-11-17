/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
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
 */

#ifndef PS_BMI_RNIC_IOCTL_H
#define PS_BMI_RNIC_IOCTL_H

#ifdef __cplusplus
extern "C" {
#endif

#define RNIC_IOCTL_START		0x89F0 /* same as SIOCDEVPRIVATE */
#define RNIC_IOCTL_END			0x89FF
#define RNIC_IOCTL_PRIVATE		RNIC_IOCTL_END

#define RNIC_IOCTL_PRIV_ADD_VLAN	0x0001
#define RNIC_IOCTL_PRIV_DEL_VLAN	0x0002
#define RNIC_IOCTL_PRIV_GET_VLAN	0x0003
#define RNIC_IOCTL_PRIV_SET_DROP_TIME	0x0004
#define RNIC_IOCTL_PRIV_GET_DROP_TIME	0x0005
#define RNIC_IOCTL_PRIV_SET_GRO_WT	0x0006
#define RNIC_IOCTL_PRIV_DIS_GRO		0x0007
#define RNIC_IOCTL_PRIV_BOOST_CPU	0x0008
/* RNIC_IOCTL_PRIV_SET_FWMODE should be executed before PDU session was setup or nic was up */
#define RNIC_IOCTL_PRIV_SET_FWMODE	0x0009
#define RNIC_IOCTL_PRIV_GET_FWMODE	0x000A
#define RNIC_IOCTL_PRIV_SET_DROP_POLICY 0x000B
#define RNIC_IOCTL_PRIV_GET_DROP_POLICY 0x000C

#define RNIC_IOCTL_MAX_VLAN_NUM		16

enum RNIC_FORWARD_MODE {
	RNIC_FW_MODE_DIRECT = 0,
	RNIC_FW_MODE_RELAY = 1,
	RNIC_FW_MODE_BUTT,
};

/* Granularity and Time Mapping Table of drop_time code
 * Granularity   Code   Time   Granularity   Code   Time   Granularity   Code   Time   Granularity   Code   Time
 * 10            0      0      10            32     320    40            64     640    40            96     1920
 * 10            1      10     10            33     330    40            65     680    40            97     1960
 * 10            2      20     10            34     340    40            66     720    40            98     2000
 * 10            3      30     10            35     350    40            67     760    40            99     2040
 * 10            4      40     10            36     360    40            68     800    40            100    2080
 * 10            5      50     10            37     370    40            69     840    40            101    2120
 * 10            6      60     10            38     380    40            70     880    40            102    2160
 * 10            7      70     10            39     390    40            71     920    40            103    2200
 * 10            8      80     10            40     400    40            72     960    40            104    2240
 * 10            9      90     10            41     410    40            73     1000   40            105    2280
 * 10            10     100    10            42     420    40            74     1040   40            106    2320
 * 10            11     110    10            43     430    40            75     1080   40            107    2360
 * 10            12     120    10            44     440    40            76     1120   40            108    2400
 * 10            13     130    10            45     450    40            77     1160   40            109    2440
 * 10            14     140    10            46     460    40            78     1200   40            110    2480
 * 10            15     150    10            47     470    40            79     1240   40            111    2520
 * 10            16     160    10            48     480    40            80     1280   40            112    2560
 * 10            17     170    10            49     490    40            81     1320   40            113    2600
 * 10            18     180    10            50     500    40            82     1360   40            114    2640
 * 10            19     190    10            51     510    40            83     1400   40            115    2680
 * 10            20     200    10            52     520    40            84     1440   40            116    2720
 * 10            21     210    10            53     530    40            85     1480   40            117    2760
 * 10            22     220    10            54     540    40            86     1520   40            118    2800
 * 10            23     230    10            55     550    40            87     1560   40            119    2840
 * 10            24     240    10            56     560    40            88     1600   40            120    2880
 * 10            25     250    10            57     570    40            89     1640   40            121    2920
 * 10            26     260    10            58     580    40            90     1680   40            122    2960
 * 10            27     270    10            59     590    40            91     1720   40            123    3000
 * 10            28     280    10            60     600    40            92     1760   40            124    3040
 * 10            29     290    10            61     610    40            93     1800   40            125    3080
 * 10            30     300    10            62     620    40            94     1840   40            126    3120
 * 10            31     310    10            63     630    40            95     1880   40            127    3160
 */

struct rnic_ioctl_priv_args_s {
	int cmd;
	union {
		unsigned int data;

		struct {
			unsigned int   vlan_num; /* number of vlan id */
			unsigned short vlan_ids[RNIC_IOCTL_MAX_VLAN_NUM];
		} vlan_cfg;

		struct {
			unsigned char code;
		} drop_time;

		/* Define drop times for SKBs with priority 0, 1, 2, and one reserved entry */
		struct {
			unsigned char drop_time[4];
		} drop_policy_code;

		unsigned int gro_weight;
		unsigned int gro_disable;
		unsigned int boost_en;
		unsigned int fw_mode;
	};
};

#ifdef __cplusplus
}
#endif

#endif /* PS_BMI_RNIC_IOCTL_H */
