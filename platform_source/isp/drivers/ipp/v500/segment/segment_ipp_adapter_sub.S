	.text
	.section	.note.gnu.property,"a",@note
	.p2align	3
	.word	4
	.word	16
	.word	5
	.asciz	"GNU"
	.word	3221225472
	.word	4
	.word	3
	.word	0
.Lsec_end0:
	.text
	.file	"segment_ipp_adapter_sub.c"
	.file	0 "/mnt/disk/jenkins/ci/workspace/chipset_pipeline_release/opensource/component_code/vendor/huawei/extra/build/build_script/kirin_kernel_release/out" "/mnt/disk/jenkins/ci/workspace/chipset_pipeline_release/opensource/component_code/vendor/huawei/extra/build/build_script/kirin_kernel_release/kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c" md5 0x96ab449ceb854a24d9ef5d42082e29b2
	.file	1 "/mnt/disk/jenkins/ci/workspace/chipset_pipeline_release/opensource/component_code/vendor/huawei/extra/build/build_script/kirin_kernel_release" "kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c" md5 0x96ab449ceb854a24d9ef5d42082e29b2
	.file	2 "/mnt/disk/jenkins/ci/workspace/chipset_pipeline_release/opensource/component_code/vendor/huawei/extra/build/build_script/kirin_kernel_release" "kernel/platform_source/isp/drivers/ipp/v500/include/ipp.h" md5 0xd2a64c7418aacea276442c42f670a92b
	.file	3 "/mnt/disk/jenkins/ci/workspace/chipset_pipeline_release/opensource/component_code/vendor/huawei/extra/build/build_script/kirin_kernel_release" "kernel/include/uapi/asm-generic/int-ll64.h" md5 0xf4d0ec5bcdd84e825a78a7add39d54dd
	.file	4 "/mnt/disk/jenkins/ci/workspace/chipset_pipeline_release/opensource/component_code/vendor/huawei/extra/build/build_script/kirin_kernel_release" "kernel/include/asm-generic/int-ll64.h" md5 0x12ca7bdb629352cc4c9a492f86b435a7
	.file	5 "/mnt/disk/jenkins/ci/workspace/chipset_pipeline_release/opensource/component_code/vendor/huawei/extra/build/build_script/kirin_kernel_release" "kernel/include/uapi/linux/types.h" md5 0x7c936cc2c480f3ca49eee93332649344
	.weak	do_ippsmmu_enable               // -- Begin function do_ippsmmu_enable
	.p2align	2
	.type	do_ippsmmu_enable,@function
do_ippsmmu_enable:                      // @do_ippsmmu_enable
.Lfunc_begin0:
	.file	6 "/mnt/disk/jenkins/ci/workspace/chipset_pipeline_release/opensource/component_code/vendor/huawei/extra/build/build_script/kirin_kernel_release" "kernel/include/platform_include/isp/linux/hipp_common.h" md5 0x4dcb1210fa5ef24f444ed6f0ca87ed93
	.loc	6 67 0                          // kernel/include/platform_include/isp/linux/hipp_common.h:67:0
	.cfi_sections .debug_frame
	.cfi_startproc
// %bb.0:
	.loc	6 67 90 prologue_end            // kernel/include/platform_include/isp/linux/hipp_common.h:67:90
	hint	#34
.Ltmp0:
	//DEBUG_VALUE: do_ippsmmu_enable:mode <- $w0
	mov	w0, wzr
.Ltmp1:
	//DEBUG_VALUE: do_ippsmmu_enable:mode <- [DW_OP_LLVM_entry_value 1] $w0
	ret
.Ltmp2:
.Lfunc_end0:
	.size	do_ippsmmu_enable, .Lfunc_end0-do_ippsmmu_enable
	.cfi_endproc
                                        // -- End function
	.weak	do_ippsmmu_disable              // -- Begin function do_ippsmmu_disable
	.p2align	2
	.type	do_ippsmmu_disable,@function
do_ippsmmu_disable:                     // @do_ippsmmu_disable
.Lfunc_begin1:
	.loc	6 68 0                          // kernel/include/platform_include/isp/linux/hipp_common.h:68:0
	.cfi_startproc
// %bb.0:
	.loc	6 68 91 prologue_end            // kernel/include/platform_include/isp/linux/hipp_common.h:68:91
	hint	#34
.Ltmp3:
	//DEBUG_VALUE: do_ippsmmu_disable:mode <- $w0
	mov	w0, wzr
.Ltmp4:
	//DEBUG_VALUE: do_ippsmmu_disable:mode <- [DW_OP_LLVM_entry_value 1] $w0
	ret
.Ltmp5:
.Lfunc_end1:
	.size	do_ippsmmu_disable, .Lfunc_end1-do_ippsmmu_disable
	.cfi_endproc
                                        // -- End function
	.globl	hipp_orcm_clk_enable            // -- Begin function hipp_orcm_clk_enable
	.p2align	2
	.type	hipp_orcm_clk_enable,@function
hipp_orcm_clk_enable:                   // @hipp_orcm_clk_enable
.Lfunc_begin2:
	.loc	1 41 0                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:41:0
	.cfi_startproc
// %bb.0:
	hint	#25
	.cfi_negate_ra_state
	stp	x29, x30, [sp, #-16]!           // 16-byte Folded Spill
	.cfi_def_cfa_offset 16
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_remember_state
.Ltmp6:
	.loc	1 44 13 prologue_end            // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:44:13
	mov	w0, wzr
	bl	hipp_get_regaddr
.Ltmp7:
	//DEBUG_VALUE: hipp_orcm_clk_enable:crg_base <- $x0
	.loc	1 45 6                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:45:6
	cbz	x0, .LBB2_3
.Ltmp8:
// %bb.1:
	//DEBUG_VALUE: hipp_orcm_clk_enable:crg_base <- $x0
	.loc	1 50 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:50:2
	add	x8, x0, #864
	mov	w9, #1
	//APP
	dmb	oshst
	//NO_APP
.Ltmp9:
	.loc	1 51 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:51:2
	add	x10, x0, #576
.Ltmp10:
	.file	7 "/mnt/disk/jenkins/ci/workspace/chipset_pipeline_release/opensource/component_code/vendor/huawei/extra/build/build_script/kirin_kernel_release" "kernel/arch/arm64/include/asm/io.h" md5 0xea4f3f43f10220e241bfc2dd30aa14c5
	.loc	7 43 2                          // kernel/arch/arm64/include/asm/io.h:43:2
	//APP
	str	w9, [x8]
	//NO_APP
.Ltmp11:
	.loc	1 53 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:53:2
	add	x8, x0, #816
.Ltmp12:
	.loc	1 52 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:52:2
	add	x11, x0, #768
.Ltmp13:
	//DEBUG_VALUE: __raw_writel:val <- 1
	//DEBUG_VALUE: __raw_writel:addr <- $x8
	.loc	1 51 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:51:2
	//APP
	dmb	oshst
	//NO_APP
.Ltmp14:
	//DEBUG_VALUE: __raw_writel:val <- 1
	//DEBUG_VALUE: __raw_writel:addr <- $x10
	.loc	7 43 2                          // kernel/arch/arm64/include/asm/io.h:43:2
	//APP
	str	w9, [x10]
	//NO_APP
.Ltmp15:
	.loc	1 54 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:54:2
	add	x10, x0, #1792
.Ltmp16:
	.loc	1 52 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:52:2
	//APP
	dmb	oshst
	//NO_APP
.Ltmp17:
	//DEBUG_VALUE: __raw_writel:val <- 1
	//DEBUG_VALUE: __raw_writel:addr <- $x11
	.loc	7 43 2                          // kernel/arch/arm64/include/asm/io.h:43:2
	//APP
	str	w9, [x11]
	//NO_APP
.Ltmp18:
	.loc	1 53 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:53:2
	//APP
	dmb	oshst
	//NO_APP
.Ltmp19:
	//DEBUG_VALUE: __raw_writel:val <- 1
	//DEBUG_VALUE: __raw_writel:addr <- $x8
	.loc	7 43 2                          // kernel/arch/arm64/include/asm/io.h:43:2
	//APP
	str	w9, [x8]
	//NO_APP
.Ltmp20:
	.loc	1 54 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:54:2
	//APP
	dmb	oshst
	//NO_APP
.Ltmp21:
	//DEBUG_VALUE: __raw_writel:val <- 1
	//DEBUG_VALUE: __raw_writel:addr <- $x10
	.loc	7 43 2                          // kernel/arch/arm64/include/asm/io.h:43:2
	//APP
	str	w9, [x10]
	//NO_APP
.Ltmp22:
	.loc	1 55 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:55:2
	//APP
	dmb	oshst
	//NO_APP
	add	x8, x0, #1216
.Ltmp23:
	.loc	1 0 2 is_stmt 0                 // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:0:2
	mov	w0, wzr
.Ltmp24:
	//DEBUG_VALUE: __raw_writel:val <- 1
	//DEBUG_VALUE: __raw_writel:addr <- $x8
	.loc	7 43 2 is_stmt 1                // kernel/arch/arm64/include/asm/io.h:43:2
	//APP
	str	w9, [x8]
	//NO_APP
.Ltmp25:
.LBB2_2:
	.loc	1 58 1                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:58:1
	ldp	x29, x30, [sp], #16             // 16-byte Folded Reload
	hint	#29
	.cfi_negate_ra_state
	ret
.LBB2_3:
	.cfi_restore_state
.Ltmp26:
	//DEBUG_VALUE: hipp_orcm_clk_enable:crg_base <- $x0
	.loc	1 46 3                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:46:3
	adrp	x0, .L.str
.Ltmp27:
	add	x0, x0, :lo12:.L.str
	adrp	x1, .L__func__.hipp_orcm_clk_enable
	add	x1, x1, :lo12:.L__func__.hipp_orcm_clk_enable
	mov	w2, #46
	bl	printk
.Ltmp28:
	.loc	1 0 3 is_stmt 0                 // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:0:3
	mov	w0, #-22
	b	.LBB2_2
.Ltmp29:
.Lfunc_end2:
	.size	hipp_orcm_clk_enable, .Lfunc_end2-hipp_orcm_clk_enable
	.cfi_endproc
	.file	8 "/mnt/disk/jenkins/ci/workspace/chipset_pipeline_release/opensource/component_code/vendor/huawei/extra/build/build_script/kirin_kernel_release" "kernel/platform_source/isp/drivers/ipp/v500/include/drivers/ipp_core.h" md5 0x3bcf9037162839da5d99446884eeac9a
	.file	9 "/mnt/disk/jenkins/ci/workspace/chipset_pipeline_release/opensource/component_code/vendor/huawei/extra/build/build_script/kirin_kernel_release" "kernel/include/linux/printk.h" md5 0xdba0d0502b5ec7a7c7e4cdc106e5cf81
                                        // -- End function
	.globl	hipp_orcm_clk_disable           // -- Begin function hipp_orcm_clk_disable
	.p2align	2
	.type	hipp_orcm_clk_disable,@function
hipp_orcm_clk_disable:                  // @hipp_orcm_clk_disable
.Lfunc_begin3:
	.loc	1 61 0 is_stmt 1                // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:61:0
	.cfi_startproc
// %bb.0:
	hint	#25
	.cfi_negate_ra_state
	stp	x29, x30, [sp, #-16]!           // 16-byte Folded Spill
	.cfi_def_cfa_offset 16
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_remember_state
.Ltmp30:
	.loc	1 64 13 prologue_end            // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:64:13
	mov	w0, wzr
	bl	hipp_get_regaddr
.Ltmp31:
	//DEBUG_VALUE: hipp_orcm_clk_disable:crg_base <- $x0
	.loc	1 65 6                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:65:6
	cbz	x0, .LBB3_3
.Ltmp32:
// %bb.1:
	//DEBUG_VALUE: hipp_orcm_clk_disable:crg_base <- $x0
	.loc	1 0 6 is_stmt 0                 // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:0:6
	mov	x8, x0
.Ltmp33:
	//DEBUG_VALUE: hipp_orcm_clk_disable:crg_base <- $x8
	mov	w0, wzr
.Ltmp34:
	.loc	1 70 2 is_stmt 1                // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:70:2
	add	x9, x8, #864
.Ltmp35:
	.loc	1 71 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:71:2
	add	x10, x8, #576
.Ltmp36:
	.loc	1 70 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:70:2
	//APP
	dmb	oshst
	//NO_APP
.Ltmp37:
	.loc	1 72 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:72:2
	add	x11, x8, #768
.Ltmp38:
	//DEBUG_VALUE: __raw_writel:addr <- $x9
	//DEBUG_VALUE: __raw_writel:val <- 0
	.loc	7 43 2                          // kernel/arch/arm64/include/asm/io.h:43:2
	//APP
	str	w0, [x9]
	//NO_APP
.Ltmp39:
	.loc	1 73 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:73:2
	add	x9, x8, #816
.Ltmp40:
	.loc	1 71 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:71:2
	//APP
	dmb	oshst
	//NO_APP
.Ltmp41:
	//DEBUG_VALUE: __raw_writel:val <- 0
	//DEBUG_VALUE: __raw_writel:addr <- $x10
	.loc	7 43 2                          // kernel/arch/arm64/include/asm/io.h:43:2
	//APP
	str	w0, [x10]
	//NO_APP
.Ltmp42:
	.loc	1 74 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:74:2
	add	x10, x8, #1792
.Ltmp43:
	.loc	1 72 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:72:2
	//APP
	dmb	oshst
	//NO_APP
.Ltmp44:
	//DEBUG_VALUE: __raw_writel:val <- 0
	//DEBUG_VALUE: __raw_writel:addr <- $x11
	.loc	7 43 2                          // kernel/arch/arm64/include/asm/io.h:43:2
	//APP
	str	w0, [x11]
	//NO_APP
.Ltmp45:
	.loc	1 73 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:73:2
	//APP
	dmb	oshst
	//NO_APP
.Ltmp46:
	//DEBUG_VALUE: __raw_writel:val <- 0
	//DEBUG_VALUE: __raw_writel:addr <- $x9
	.loc	7 43 2                          // kernel/arch/arm64/include/asm/io.h:43:2
	//APP
	str	w0, [x9]
	//NO_APP
.Ltmp47:
	.loc	1 74 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:74:2
	//APP
	dmb	oshst
	//NO_APP
.Ltmp48:
	//DEBUG_VALUE: __raw_writel:val <- 0
	//DEBUG_VALUE: __raw_writel:addr <- $x10
	.loc	7 43 2                          // kernel/arch/arm64/include/asm/io.h:43:2
	//APP
	str	w0, [x10]
	//NO_APP
.Ltmp49:
	.loc	1 75 2                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:75:2
	//APP
	dmb	oshst
	//NO_APP
	add	x8, x8, #1216
.Ltmp50:
	//DEBUG_VALUE: __raw_writel:val <- 0
	//DEBUG_VALUE: __raw_writel:addr <- $x8
	.loc	7 43 2                          // kernel/arch/arm64/include/asm/io.h:43:2
	//APP
	str	w0, [x8]
	//NO_APP
.Ltmp51:
.LBB3_2:
	.loc	1 78 1                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:78:1
	ldp	x29, x30, [sp], #16             // 16-byte Folded Reload
	hint	#29
	.cfi_negate_ra_state
	ret
.LBB3_3:
	.cfi_restore_state
.Ltmp52:
	//DEBUG_VALUE: hipp_orcm_clk_disable:crg_base <- $x0
	.loc	1 66 3                          // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:66:3
	adrp	x0, .L.str
.Ltmp53:
	add	x0, x0, :lo12:.L.str
	adrp	x1, .L__func__.hipp_orcm_clk_disable
	add	x1, x1, :lo12:.L__func__.hipp_orcm_clk_disable
	mov	w2, #66
	bl	printk
.Ltmp54:
	.loc	1 0 3 is_stmt 0                 // kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c:0:3
	mov	w0, #-22
	b	.LBB3_2
.Ltmp55:
.Lfunc_end3:
	.size	hipp_orcm_clk_disable, .Lfunc_end3-hipp_orcm_clk_disable
	.cfi_endproc
                                        // -- End function
	.type	.L.str,@object                  // @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"[ispcpe][%s,%d]Failed : hipp_get_regaddr\n"
	.size	.L.str, 42

	.type	.L__func__.hipp_orcm_clk_enable,@object // @__func__.hipp_orcm_clk_enable
.L__func__.hipp_orcm_clk_enable:
	.asciz	"hipp_orcm_clk_enable"
	.size	.L__func__.hipp_orcm_clk_enable, 21

	.type	.L__func__.hipp_orcm_clk_disable,@object // @__func__.hipp_orcm_clk_disable
.L__func__.hipp_orcm_clk_disable:
	.asciz	"hipp_orcm_clk_disable"
	.size	.L__func__.hipp_orcm_clk_disable, 22

	.section	.debug_loclists,"",@progbits
	.word	.Ldebug_list_header_end0-.Ldebug_list_header_start0 // Length
.Ldebug_list_header_start0:
	.hword	5                               // Version
	.byte	8                               // Address size
	.byte	0                               // Segment selector size
	.word	4                               // Offset entry count
.Lloclists_table_base0:
	.word	.Ldebug_loc0-.Lloclists_table_base0
	.word	.Ldebug_loc1-.Lloclists_table_base0
	.word	.Ldebug_loc2-.Lloclists_table_base0
	.word	.Ldebug_loc3-.Lloclists_table_base0
.Ldebug_loc0:
	.byte	4                               // DW_LLE_offset_pair
	.uleb128 .Ltmp0-.Lfunc_begin0           //   starting offset
	.uleb128 .Ltmp1-.Lfunc_begin0           //   ending offset
	.byte	1                               // Loc expr size
	.byte	80                              // DW_OP_reg0
	.byte	4                               // DW_LLE_offset_pair
	.uleb128 .Ltmp1-.Lfunc_begin0           //   starting offset
	.uleb128 .Lfunc_end0-.Lfunc_begin0      //   ending offset
	.byte	4                               // Loc expr size
	.byte	163                             // DW_OP_entry_value
	.byte	1                               // 1
	.byte	80                              // DW_OP_reg0
	.byte	159                             // DW_OP_stack_value
	.byte	0                               // DW_LLE_end_of_list
.Ldebug_loc1:
	.byte	4                               // DW_LLE_offset_pair
	.uleb128 .Ltmp3-.Lfunc_begin0           //   starting offset
	.uleb128 .Ltmp4-.Lfunc_begin0           //   ending offset
	.byte	1                               // Loc expr size
	.byte	80                              // DW_OP_reg0
	.byte	4                               // DW_LLE_offset_pair
	.uleb128 .Ltmp4-.Lfunc_begin0           //   starting offset
	.uleb128 .Lfunc_end1-.Lfunc_begin0      //   ending offset
	.byte	4                               // Loc expr size
	.byte	163                             // DW_OP_entry_value
	.byte	1                               // 1
	.byte	80                              // DW_OP_reg0
	.byte	159                             // DW_OP_stack_value
	.byte	0                               // DW_LLE_end_of_list
.Ldebug_loc2:
	.byte	4                               // DW_LLE_offset_pair
	.uleb128 .Ltmp7-.Lfunc_begin0           //   starting offset
	.uleb128 .Ltmp24-.Lfunc_begin0          //   ending offset
	.byte	1                               // Loc expr size
	.byte	80                              // DW_OP_reg0
	.byte	4                               // DW_LLE_offset_pair
	.uleb128 .Ltmp26-.Lfunc_begin0          //   starting offset
	.uleb128 .Ltmp27-.Lfunc_begin0          //   ending offset
	.byte	1                               // Loc expr size
	.byte	80                              // DW_OP_reg0
	.byte	0                               // DW_LLE_end_of_list
.Ldebug_loc3:
	.byte	4                               // DW_LLE_offset_pair
	.uleb128 .Ltmp31-.Lfunc_begin0          //   starting offset
	.uleb128 .Ltmp33-.Lfunc_begin0          //   ending offset
	.byte	1                               // Loc expr size
	.byte	80                              // DW_OP_reg0
	.byte	4                               // DW_LLE_offset_pair
	.uleb128 .Ltmp33-.Lfunc_begin0          //   starting offset
	.uleb128 .Ltmp50-.Lfunc_begin0          //   ending offset
	.byte	1                               // Loc expr size
	.byte	88                              // DW_OP_reg8
	.byte	4                               // DW_LLE_offset_pair
	.uleb128 .Ltmp52-.Lfunc_begin0          //   starting offset
	.uleb128 .Ltmp53-.Lfunc_begin0          //   ending offset
	.byte	1                               // Loc expr size
	.byte	80                              // DW_OP_reg0
	.byte	0                               // DW_LLE_end_of_list
.Ldebug_list_header_end0:
	.section	.debug_abbrev,"",@progbits
	.byte	1                               // Abbreviation Code
	.byte	17                              // DW_TAG_compile_unit
	.byte	1                               // DW_CHILDREN_yes
	.byte	37                              // DW_AT_producer
	.byte	37                              // DW_FORM_strx1
	.byte	19                              // DW_AT_language
	.byte	5                               // DW_FORM_data2
	.byte	3                               // DW_AT_name
	.byte	37                              // DW_FORM_strx1
	.byte	114                             // DW_AT_str_offsets_base
	.byte	23                              // DW_FORM_sec_offset
	.byte	16                              // DW_AT_stmt_list
	.byte	23                              // DW_FORM_sec_offset
	.byte	27                              // DW_AT_comp_dir
	.byte	37                              // DW_FORM_strx1
	.byte	17                              // DW_AT_low_pc
	.byte	27                              // DW_FORM_addrx
	.byte	18                              // DW_AT_high_pc
	.byte	6                               // DW_FORM_data4
	.byte	115                             // DW_AT_addr_base
	.byte	23                              // DW_FORM_sec_offset
	.ascii	"\214\001"                      // DW_AT_loclists_base
	.byte	23                              // DW_FORM_sec_offset
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	2                               // Abbreviation Code
	.byte	52                              // DW_TAG_variable
	.byte	0                               // DW_CHILDREN_no
	.byte	73                              // DW_AT_type
	.byte	19                              // DW_FORM_ref4
	.byte	58                              // DW_AT_decl_file
	.byte	11                              // DW_FORM_data1
	.byte	59                              // DW_AT_decl_line
	.byte	11                              // DW_FORM_data1
	.byte	2                               // DW_AT_location
	.byte	24                              // DW_FORM_exprloc
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	3                               // Abbreviation Code
	.byte	1                               // DW_TAG_array_type
	.byte	1                               // DW_CHILDREN_yes
	.byte	73                              // DW_AT_type
	.byte	19                              // DW_FORM_ref4
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	4                               // Abbreviation Code
	.byte	33                              // DW_TAG_subrange_type
	.byte	0                               // DW_CHILDREN_no
	.byte	73                              // DW_AT_type
	.byte	19                              // DW_FORM_ref4
	.byte	55                              // DW_AT_count
	.byte	11                              // DW_FORM_data1
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	5                               // Abbreviation Code
	.byte	36                              // DW_TAG_base_type
	.byte	0                               // DW_CHILDREN_no
	.byte	3                               // DW_AT_name
	.byte	37                              // DW_FORM_strx1
	.byte	62                              // DW_AT_encoding
	.byte	11                              // DW_FORM_data1
	.byte	11                              // DW_AT_byte_size
	.byte	11                              // DW_FORM_data1
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	6                               // Abbreviation Code
	.byte	36                              // DW_TAG_base_type
	.byte	0                               // DW_CHILDREN_no
	.byte	3                               // DW_AT_name
	.byte	37                              // DW_FORM_strx1
	.byte	11                              // DW_AT_byte_size
	.byte	11                              // DW_FORM_data1
	.byte	62                              // DW_AT_encoding
	.byte	11                              // DW_FORM_data1
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	7                               // Abbreviation Code
	.byte	38                              // DW_TAG_const_type
	.byte	0                               // DW_CHILDREN_no
	.byte	73                              // DW_AT_type
	.byte	19                              // DW_FORM_ref4
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	8                               // Abbreviation Code
	.byte	4                               // DW_TAG_enumeration_type
	.byte	1                               // DW_CHILDREN_yes
	.byte	73                              // DW_AT_type
	.byte	19                              // DW_FORM_ref4
	.byte	3                               // DW_AT_name
	.byte	37                              // DW_FORM_strx1
	.byte	11                              // DW_AT_byte_size
	.byte	11                              // DW_FORM_data1
	.byte	58                              // DW_AT_decl_file
	.byte	11                              // DW_FORM_data1
	.byte	59                              // DW_AT_decl_line
	.byte	11                              // DW_FORM_data1
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	9                               // Abbreviation Code
	.byte	40                              // DW_TAG_enumerator
	.byte	0                               // DW_CHILDREN_no
	.byte	3                               // DW_AT_name
	.byte	37                              // DW_FORM_strx1
	.byte	28                              // DW_AT_const_value
	.byte	15                              // DW_FORM_udata
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	10                              // Abbreviation Code
	.byte	15                              // DW_TAG_pointer_type
	.byte	0                               // DW_CHILDREN_no
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	11                              // Abbreviation Code
	.byte	22                              // DW_TAG_typedef
	.byte	0                               // DW_CHILDREN_no
	.byte	73                              // DW_AT_type
	.byte	19                              // DW_FORM_ref4
	.byte	3                               // DW_AT_name
	.byte	37                              // DW_FORM_strx1
	.byte	58                              // DW_AT_decl_file
	.byte	11                              // DW_FORM_data1
	.byte	59                              // DW_AT_decl_line
	.byte	11                              // DW_FORM_data1
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	12                              // Abbreviation Code
	.byte	46                              // DW_TAG_subprogram
	.byte	1                               // DW_CHILDREN_yes
	.byte	17                              // DW_AT_low_pc
	.byte	27                              // DW_FORM_addrx
	.byte	18                              // DW_AT_high_pc
	.byte	6                               // DW_FORM_data4
	.byte	64                              // DW_AT_frame_base
	.byte	24                              // DW_FORM_exprloc
	.byte	122                             // DW_AT_call_all_calls
	.byte	25                              // DW_FORM_flag_present
	.byte	3                               // DW_AT_name
	.byte	37                              // DW_FORM_strx1
	.byte	58                              // DW_AT_decl_file
	.byte	11                              // DW_FORM_data1
	.byte	59                              // DW_AT_decl_line
	.byte	11                              // DW_FORM_data1
	.byte	39                              // DW_AT_prototyped
	.byte	25                              // DW_FORM_flag_present
	.byte	73                              // DW_AT_type
	.byte	19                              // DW_FORM_ref4
	.byte	63                              // DW_AT_external
	.byte	25                              // DW_FORM_flag_present
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	13                              // Abbreviation Code
	.byte	5                               // DW_TAG_formal_parameter
	.byte	0                               // DW_CHILDREN_no
	.byte	2                               // DW_AT_location
	.byte	34                              // DW_FORM_loclistx
	.byte	3                               // DW_AT_name
	.byte	37                              // DW_FORM_strx1
	.byte	58                              // DW_AT_decl_file
	.byte	11                              // DW_FORM_data1
	.byte	59                              // DW_AT_decl_line
	.byte	11                              // DW_FORM_data1
	.byte	73                              // DW_AT_type
	.byte	19                              // DW_FORM_ref4
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	14                              // Abbreviation Code
	.byte	46                              // DW_TAG_subprogram
	.byte	1                               // DW_CHILDREN_yes
	.byte	3                               // DW_AT_name
	.byte	37                              // DW_FORM_strx1
	.byte	58                              // DW_AT_decl_file
	.byte	11                              // DW_FORM_data1
	.byte	59                              // DW_AT_decl_line
	.byte	11                              // DW_FORM_data1
	.byte	39                              // DW_AT_prototyped
	.byte	25                              // DW_FORM_flag_present
	.byte	32                              // DW_AT_inline
	.byte	33                              // DW_FORM_implicit_const
	.byte	1
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	15                              // Abbreviation Code
	.byte	5                               // DW_TAG_formal_parameter
	.byte	0                               // DW_CHILDREN_no
	.byte	3                               // DW_AT_name
	.byte	37                              // DW_FORM_strx1
	.byte	58                              // DW_AT_decl_file
	.byte	11                              // DW_FORM_data1
	.byte	59                              // DW_AT_decl_line
	.byte	11                              // DW_FORM_data1
	.byte	73                              // DW_AT_type
	.byte	19                              // DW_FORM_ref4
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	16                              // Abbreviation Code
	.byte	15                              // DW_TAG_pointer_type
	.byte	0                               // DW_CHILDREN_no
	.byte	73                              // DW_AT_type
	.byte	19                              // DW_FORM_ref4
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	17                              // Abbreviation Code
	.byte	53                              // DW_TAG_volatile_type
	.byte	0                               // DW_CHILDREN_no
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	18                              // Abbreviation Code
	.byte	52                              // DW_TAG_variable
	.byte	0                               // DW_CHILDREN_no
	.byte	2                               // DW_AT_location
	.byte	34                              // DW_FORM_loclistx
	.byte	3                               // DW_AT_name
	.byte	37                              // DW_FORM_strx1
	.byte	58                              // DW_AT_decl_file
	.byte	11                              // DW_FORM_data1
	.byte	59                              // DW_AT_decl_line
	.byte	11                              // DW_FORM_data1
	.byte	73                              // DW_AT_type
	.byte	19                              // DW_FORM_ref4
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	19                              // Abbreviation Code
	.byte	29                              // DW_TAG_inlined_subroutine
	.byte	0                               // DW_CHILDREN_no
	.byte	49                              // DW_AT_abstract_origin
	.byte	19                              // DW_FORM_ref4
	.byte	17                              // DW_AT_low_pc
	.byte	27                              // DW_FORM_addrx
	.byte	18                              // DW_AT_high_pc
	.byte	6                               // DW_FORM_data4
	.byte	88                              // DW_AT_call_file
	.byte	11                              // DW_FORM_data1
	.byte	89                              // DW_AT_call_line
	.byte	11                              // DW_FORM_data1
	.byte	87                              // DW_AT_call_column
	.byte	11                              // DW_FORM_data1
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	20                              // Abbreviation Code
	.byte	29                              // DW_TAG_inlined_subroutine
	.byte	1                               // DW_CHILDREN_yes
	.byte	49                              // DW_AT_abstract_origin
	.byte	19                              // DW_FORM_ref4
	.byte	17                              // DW_AT_low_pc
	.byte	27                              // DW_FORM_addrx
	.byte	18                              // DW_AT_high_pc
	.byte	6                               // DW_FORM_data4
	.byte	88                              // DW_AT_call_file
	.byte	11                              // DW_FORM_data1
	.byte	89                              // DW_AT_call_line
	.byte	11                              // DW_FORM_data1
	.byte	87                              // DW_AT_call_column
	.byte	11                              // DW_FORM_data1
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	21                              // Abbreviation Code
	.byte	5                               // DW_TAG_formal_parameter
	.byte	0                               // DW_CHILDREN_no
	.byte	28                              // DW_AT_const_value
	.byte	15                              // DW_FORM_udata
	.byte	49                              // DW_AT_abstract_origin
	.byte	19                              // DW_FORM_ref4
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	22                              // Abbreviation Code
	.byte	5                               // DW_TAG_formal_parameter
	.byte	0                               // DW_CHILDREN_no
	.byte	2                               // DW_AT_location
	.byte	24                              // DW_FORM_exprloc
	.byte	49                              // DW_AT_abstract_origin
	.byte	19                              // DW_FORM_ref4
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	23                              // Abbreviation Code
	.byte	72                              // DW_TAG_call_site
	.byte	1                               // DW_CHILDREN_yes
	.byte	127                             // DW_AT_call_origin
	.byte	19                              // DW_FORM_ref4
	.byte	125                             // DW_AT_call_return_pc
	.byte	27                              // DW_FORM_addrx
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	24                              // Abbreviation Code
	.byte	73                              // DW_TAG_call_site_parameter
	.byte	0                               // DW_CHILDREN_no
	.byte	2                               // DW_AT_location
	.byte	24                              // DW_FORM_exprloc
	.byte	126                             // DW_AT_call_value
	.byte	24                              // DW_FORM_exprloc
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	25                              // Abbreviation Code
	.byte	46                              // DW_TAG_subprogram
	.byte	1                               // DW_CHILDREN_yes
	.byte	3                               // DW_AT_name
	.byte	37                              // DW_FORM_strx1
	.byte	58                              // DW_AT_decl_file
	.byte	11                              // DW_FORM_data1
	.byte	59                              // DW_AT_decl_line
	.byte	11                              // DW_FORM_data1
	.byte	39                              // DW_AT_prototyped
	.byte	25                              // DW_FORM_flag_present
	.byte	73                              // DW_AT_type
	.byte	19                              // DW_FORM_ref4
	.byte	60                              // DW_AT_declaration
	.byte	25                              // DW_FORM_flag_present
	.byte	63                              // DW_AT_external
	.byte	25                              // DW_FORM_flag_present
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	26                              // Abbreviation Code
	.byte	5                               // DW_TAG_formal_parameter
	.byte	0                               // DW_CHILDREN_no
	.byte	73                              // DW_AT_type
	.byte	19                              // DW_FORM_ref4
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	27                              // Abbreviation Code
	.byte	24                              // DW_TAG_unspecified_parameters
	.byte	0                               // DW_CHILDREN_no
	.byte	0                               // EOM(1)
	.byte	0                               // EOM(2)
	.byte	0                               // EOM(3)
	.section	.debug_info,"",@progbits
.Lcu_begin0:
	.word	.Ldebug_info_end0-.Ldebug_info_start0 // Length of Unit
.Ldebug_info_start0:
	.hword	5                               // DWARF version number
	.byte	1                               // DWARF Unit Type
	.byte	8                               // Address Size (in bytes)
	.word	.debug_abbrev                   // Offset Into Abbrev. Section
	.byte	1                               // Abbrev [1] 0xc:0x2da DW_TAG_compile_unit
	.byte	0                               // DW_AT_producer
	.hword	1                               // DW_AT_language
	.byte	1                               // DW_AT_name
	.word	.Lstr_offsets_base0             // DW_AT_str_offsets_base
	.word	.Lline_table_start0             // DW_AT_stmt_list
	.byte	2                               // DW_AT_comp_dir
	.byte	3                               // DW_AT_low_pc
	.word	.Lfunc_end3-.Lfunc_begin0       // DW_AT_high_pc
	.word	.Laddr_table_base0              // DW_AT_addr_base
	.word	.Lloclists_table_base0          // DW_AT_loclists_base
	.byte	2                               // Abbrev [2] 0x27:0xa DW_TAG_variable
	.word	49                              // DW_AT_type
	.byte	1                               // DW_AT_decl_file
	.byte	46                              // DW_AT_decl_line
	.byte	2                               // DW_AT_location
	.byte	161
	.byte	0
	.byte	3                               // Abbrev [3] 0x31:0xc DW_TAG_array_type
	.word	61                              // DW_AT_type
	.byte	4                               // Abbrev [4] 0x36:0x6 DW_TAG_subrange_type
	.word	65                              // DW_AT_type
	.byte	42                              // DW_AT_count
	.byte	0                               // End Of Children Mark
	.byte	5                               // Abbrev [5] 0x3d:0x4 DW_TAG_base_type
	.byte	3                               // DW_AT_name
	.byte	8                               // DW_AT_encoding
	.byte	1                               // DW_AT_byte_size
	.byte	6                               // Abbrev [6] 0x41:0x4 DW_TAG_base_type
	.byte	4                               // DW_AT_name
	.byte	8                               // DW_AT_byte_size
	.byte	7                               // DW_AT_encoding
	.byte	2                               // Abbrev [2] 0x45:0xa DW_TAG_variable
	.word	79                              // DW_AT_type
	.byte	1                               // DW_AT_decl_file
	.byte	46                              // DW_AT_decl_line
	.byte	2                               // DW_AT_location
	.byte	161
	.byte	1
	.byte	3                               // Abbrev [3] 0x4f:0xc DW_TAG_array_type
	.word	91                              // DW_AT_type
	.byte	4                               // Abbrev [4] 0x54:0x6 DW_TAG_subrange_type
	.word	65                              // DW_AT_type
	.byte	21                              // DW_AT_count
	.byte	0                               // End Of Children Mark
	.byte	7                               // Abbrev [7] 0x5b:0x5 DW_TAG_const_type
	.word	61                              // DW_AT_type
	.byte	2                               // Abbrev [2] 0x60:0xa DW_TAG_variable
	.word	106                             // DW_AT_type
	.byte	1                               // DW_AT_decl_file
	.byte	66                              // DW_AT_decl_line
	.byte	2                               // DW_AT_location
	.byte	161
	.byte	2
	.byte	3                               // Abbrev [3] 0x6a:0xc DW_TAG_array_type
	.word	91                              // DW_AT_type
	.byte	4                               // Abbrev [4] 0x6f:0x6 DW_TAG_subrange_type
	.word	65                              // DW_AT_type
	.byte	22                              // DW_AT_count
	.byte	0                               // End Of Children Mark
	.byte	8                               // Abbrev [8] 0x76:0x2e DW_TAG_enumeration_type
	.word	164                             // DW_AT_type
	.byte	18                              // DW_AT_name
	.byte	4                               // DW_AT_byte_size
	.byte	2                               // DW_AT_decl_file
	.byte	25                              // DW_AT_decl_line
	.byte	9                               // Abbrev [9] 0x7f:0x3 DW_TAG_enumerator
	.byte	6                               // DW_AT_name
	.byte	0                               // DW_AT_const_value
	.byte	9                               // Abbrev [9] 0x82:0x3 DW_TAG_enumerator
	.byte	7                               // DW_AT_name
	.byte	1                               // DW_AT_const_value
	.byte	9                               // Abbrev [9] 0x85:0x3 DW_TAG_enumerator
	.byte	8                               // DW_AT_name
	.byte	2                               // DW_AT_const_value
	.byte	9                               // Abbrev [9] 0x88:0x3 DW_TAG_enumerator
	.byte	9                               // DW_AT_name
	.byte	3                               // DW_AT_const_value
	.byte	9                               // Abbrev [9] 0x8b:0x3 DW_TAG_enumerator
	.byte	10                              // DW_AT_name
	.byte	4                               // DW_AT_const_value
	.byte	9                               // Abbrev [9] 0x8e:0x3 DW_TAG_enumerator
	.byte	11                              // DW_AT_name
	.byte	5                               // DW_AT_const_value
	.byte	9                               // Abbrev [9] 0x91:0x3 DW_TAG_enumerator
	.byte	12                              // DW_AT_name
	.byte	6                               // DW_AT_const_value
	.byte	9                               // Abbrev [9] 0x94:0x3 DW_TAG_enumerator
	.byte	13                              // DW_AT_name
	.byte	7                               // DW_AT_const_value
	.byte	9                               // Abbrev [9] 0x97:0x3 DW_TAG_enumerator
	.byte	14                              // DW_AT_name
	.byte	8                               // DW_AT_const_value
	.byte	9                               // Abbrev [9] 0x9a:0x3 DW_TAG_enumerator
	.byte	15                              // DW_AT_name
	.byte	9                               // DW_AT_const_value
	.byte	9                               // Abbrev [9] 0x9d:0x3 DW_TAG_enumerator
	.byte	16                              // DW_AT_name
	.byte	10                              // DW_AT_const_value
	.byte	9                               // Abbrev [9] 0xa0:0x3 DW_TAG_enumerator
	.byte	17                              // DW_AT_name
	.byte	11                              // DW_AT_const_value
	.byte	0                               // End Of Children Mark
	.byte	5                               // Abbrev [5] 0xa4:0x4 DW_TAG_base_type
	.byte	5                               // DW_AT_name
	.byte	7                               // DW_AT_encoding
	.byte	4                               // DW_AT_byte_size
	.byte	8                               // Abbrev [8] 0xa8:0x13 DW_TAG_enumeration_type
	.word	164                             // DW_AT_type
	.byte	22                              // DW_AT_name
	.byte	4                               // DW_AT_byte_size
	.byte	1                               // DW_AT_decl_file
	.byte	34                              // DW_AT_decl_line
	.byte	9                               // Abbrev [9] 0xb1:0x3 DW_TAG_enumerator
	.byte	19                              // DW_AT_name
	.byte	0                               // DW_AT_const_value
	.byte	9                               // Abbrev [9] 0xb4:0x3 DW_TAG_enumerator
	.byte	20                              // DW_AT_name
	.byte	1                               // DW_AT_const_value
	.byte	9                               // Abbrev [9] 0xb7:0x3 DW_TAG_enumerator
	.byte	21                              // DW_AT_name
	.byte	2                               // DW_AT_const_value
	.byte	0                               // End Of Children Mark
	.byte	10                              // Abbrev [10] 0xbb:0x1 DW_TAG_pointer_type
	.byte	11                              // Abbrev [11] 0xbc:0x8 DW_TAG_typedef
	.word	196                             // DW_AT_type
	.byte	24                              // DW_AT_name
	.byte	4                               // DW_AT_decl_file
	.byte	21                              // DW_AT_decl_line
	.byte	11                              // Abbrev [11] 0xc4:0x8 DW_TAG_typedef
	.word	164                             // DW_AT_type
	.byte	23                              // DW_AT_name
	.byte	3                               // DW_AT_decl_file
	.byte	27                              // DW_AT_decl_line
	.byte	11                              // Abbrev [11] 0xcc:0x8 DW_TAG_typedef
	.word	196                             // DW_AT_type
	.byte	25                              // DW_AT_name
	.byte	5                               // DW_AT_decl_file
	.byte	31                              // DW_AT_decl_line
	.byte	12                              // Abbrev [12] 0xd4:0x19 DW_TAG_subprogram
	.byte	3                               // DW_AT_low_pc
	.word	.Lfunc_end0-.Lfunc_begin0       // DW_AT_high_pc
	.byte	1                               // DW_AT_frame_base
	.byte	111
                                        // DW_AT_call_all_calls
	.byte	32                              // DW_AT_name
	.byte	6                               // DW_AT_decl_file
	.byte	67                              // DW_AT_decl_line
                                        // DW_AT_prototyped
	.word	518                             // DW_AT_type
                                        // DW_AT_external
	.byte	13                              // Abbrev [13] 0xe3:0x9 DW_TAG_formal_parameter
	.byte	0                               // DW_AT_location
	.byte	36                              // DW_AT_name
	.byte	6                               // DW_AT_decl_file
	.byte	67                              // DW_AT_decl_line
	.word	164                             // DW_AT_type
	.byte	0                               // End Of Children Mark
	.byte	12                              // Abbrev [12] 0xed:0x19 DW_TAG_subprogram
	.byte	4                               // DW_AT_low_pc
	.word	.Lfunc_end1-.Lfunc_begin1       // DW_AT_high_pc
	.byte	1                               // DW_AT_frame_base
	.byte	111
                                        // DW_AT_call_all_calls
	.byte	33                              // DW_AT_name
	.byte	6                               // DW_AT_decl_file
	.byte	68                              // DW_AT_decl_line
                                        // DW_AT_prototyped
	.word	518                             // DW_AT_type
                                        // DW_AT_external
	.byte	13                              // Abbrev [13] 0xfc:0x9 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_location
	.byte	36                              // DW_AT_name
	.byte	6                               // DW_AT_decl_file
	.byte	68                              // DW_AT_decl_line
	.word	164                             // DW_AT_type
	.byte	0                               // End Of Children Mark
	.byte	14                              // Abbrev [14] 0x106:0x15 DW_TAG_subprogram
	.byte	26                              // DW_AT_name
	.byte	7                               // DW_AT_decl_file
	.byte	40                              // DW_AT_decl_line
                                        // DW_AT_prototyped
                                        // DW_AT_inline
	.byte	15                              // Abbrev [15] 0x10a:0x8 DW_TAG_formal_parameter
	.byte	27                              // DW_AT_name
	.byte	7                               // DW_AT_decl_file
	.byte	40                              // DW_AT_decl_line
	.word	188                             // DW_AT_type
	.byte	15                              // Abbrev [15] 0x112:0x8 DW_TAG_formal_parameter
	.byte	28                              // DW_AT_name
	.byte	7                               // DW_AT_decl_file
	.byte	40                              // DW_AT_decl_line
	.word	283                             // DW_AT_type
	.byte	0                               // End Of Children Mark
	.byte	16                              // Abbrev [16] 0x11b:0x5 DW_TAG_pointer_type
	.word	288                             // DW_AT_type
	.byte	17                              // Abbrev [17] 0x120:0x1 DW_TAG_volatile_type
	.byte	12                              // Abbrev [12] 0x121:0xc8 DW_TAG_subprogram
	.byte	5                               // DW_AT_low_pc
	.word	.Lfunc_end2-.Lfunc_begin2       // DW_AT_high_pc
	.byte	1                               // DW_AT_frame_base
	.byte	109
                                        // DW_AT_call_all_calls
	.byte	34                              // DW_AT_name
	.byte	1                               // DW_AT_decl_file
	.byte	40                              // DW_AT_decl_line
                                        // DW_AT_prototyped
	.word	518                             // DW_AT_type
                                        // DW_AT_external
	.byte	18                              // Abbrev [18] 0x130:0x9 DW_TAG_variable
	.byte	2                               // DW_AT_location
	.byte	37                              // DW_AT_name
	.byte	1                               // DW_AT_decl_file
	.byte	42                              // DW_AT_decl_line
	.word	187                             // DW_AT_type
	.byte	19                              // Abbrev [19] 0x139:0xd DW_TAG_inlined_subroutine
	.word	262                             // DW_AT_abstract_origin
	.byte	6                               // DW_AT_low_pc
	.word	.Ltmp11-.Ltmp10                 // DW_AT_high_pc
	.byte	1                               // DW_AT_call_file
	.byte	50                              // DW_AT_call_line
	.byte	2                               // DW_AT_call_column
	.byte	20                              // Abbrev [20] 0x146:0x1b DW_TAG_inlined_subroutine
	.word	262                             // DW_AT_abstract_origin
	.byte	7                               // DW_AT_low_pc
	.word	.Ltmp15-.Ltmp14                 // DW_AT_high_pc
	.byte	1                               // DW_AT_call_file
	.byte	51                              // DW_AT_call_line
	.byte	2                               // DW_AT_call_column
	.byte	21                              // Abbrev [21] 0x153:0x6 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_const_value
	.word	266                             // DW_AT_abstract_origin
	.byte	22                              // Abbrev [22] 0x159:0x7 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_location
	.byte	90
	.word	274                             // DW_AT_abstract_origin
	.byte	0                               // End Of Children Mark
	.byte	20                              // Abbrev [20] 0x161:0x1b DW_TAG_inlined_subroutine
	.word	262                             // DW_AT_abstract_origin
	.byte	8                               // DW_AT_low_pc
	.word	.Ltmp20-.Ltmp19                 // DW_AT_high_pc
	.byte	1                               // DW_AT_call_file
	.byte	53                              // DW_AT_call_line
	.byte	2                               // DW_AT_call_column
	.byte	21                              // Abbrev [21] 0x16e:0x6 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_const_value
	.word	266                             // DW_AT_abstract_origin
	.byte	22                              // Abbrev [22] 0x174:0x7 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_location
	.byte	88
	.word	274                             // DW_AT_abstract_origin
	.byte	0                               // End Of Children Mark
	.byte	20                              // Abbrev [20] 0x17c:0x1b DW_TAG_inlined_subroutine
	.word	262                             // DW_AT_abstract_origin
	.byte	9                               // DW_AT_low_pc
	.word	.Ltmp18-.Ltmp17                 // DW_AT_high_pc
	.byte	1                               // DW_AT_call_file
	.byte	52                              // DW_AT_call_line
	.byte	2                               // DW_AT_call_column
	.byte	21                              // Abbrev [21] 0x189:0x6 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_const_value
	.word	266                             // DW_AT_abstract_origin
	.byte	22                              // Abbrev [22] 0x18f:0x7 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_location
	.byte	91
	.word	274                             // DW_AT_abstract_origin
	.byte	0                               // End Of Children Mark
	.byte	20                              // Abbrev [20] 0x197:0x1b DW_TAG_inlined_subroutine
	.word	262                             // DW_AT_abstract_origin
	.byte	10                              // DW_AT_low_pc
	.word	.Ltmp22-.Ltmp21                 // DW_AT_high_pc
	.byte	1                               // DW_AT_call_file
	.byte	54                              // DW_AT_call_line
	.byte	2                               // DW_AT_call_column
	.byte	21                              // Abbrev [21] 0x1a4:0x6 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_const_value
	.word	266                             // DW_AT_abstract_origin
	.byte	22                              // Abbrev [22] 0x1aa:0x7 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_location
	.byte	90
	.word	274                             // DW_AT_abstract_origin
	.byte	0                               // End Of Children Mark
	.byte	20                              // Abbrev [20] 0x1b2:0x1b DW_TAG_inlined_subroutine
	.word	262                             // DW_AT_abstract_origin
	.byte	11                              // DW_AT_low_pc
	.word	.Ltmp25-.Ltmp24                 // DW_AT_high_pc
	.byte	1                               // DW_AT_call_file
	.byte	55                              // DW_AT_call_line
	.byte	2                               // DW_AT_call_column
	.byte	21                              // Abbrev [21] 0x1bf:0x6 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_const_value
	.word	266                             // DW_AT_abstract_origin
	.byte	22                              // Abbrev [22] 0x1c5:0x7 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_location
	.byte	88
	.word	274                             // DW_AT_abstract_origin
	.byte	0                               // End Of Children Mark
	.byte	23                              // Abbrev [23] 0x1cd:0xe DW_TAG_call_site
	.word	489                             // DW_AT_call_origin
	.byte	12                              // DW_AT_call_return_pc
	.byte	24                              // Abbrev [24] 0x1d3:0x7 DW_TAG_call_site_parameter
	.byte	1                               // DW_AT_location
	.byte	80
	.byte	3                               // DW_AT_call_value
	.byte	163
	.byte	1
	.byte	111
	.byte	0                               // End Of Children Mark
	.byte	23                              // Abbrev [23] 0x1db:0xd DW_TAG_call_site
	.word	503                             // DW_AT_call_origin
	.byte	13                              // DW_AT_call_return_pc
	.byte	24                              // Abbrev [24] 0x1e1:0x6 DW_TAG_call_site_parameter
	.byte	1                               // DW_AT_location
	.byte	82
	.byte	2                               // DW_AT_call_value
	.byte	16
	.byte	46
	.byte	0                               // End Of Children Mark
	.byte	0                               // End Of Children Mark
	.byte	25                              // Abbrev [25] 0x1e9:0xe DW_TAG_subprogram
	.byte	29                              // DW_AT_name
	.byte	8                               // DW_AT_decl_file
	.byte	62                              // DW_AT_decl_line
                                        // DW_AT_prototyped
	.word	187                             // DW_AT_type
                                        // DW_AT_declaration
                                        // DW_AT_external
	.byte	26                              // Abbrev [26] 0x1f1:0x5 DW_TAG_formal_parameter
	.word	164                             // DW_AT_type
	.byte	0                               // End Of Children Mark
	.byte	25                              // Abbrev [25] 0x1f7:0xf DW_TAG_subprogram
	.byte	30                              // DW_AT_name
	.byte	9                               // DW_AT_decl_file
	.byte	176                             // DW_AT_decl_line
                                        // DW_AT_prototyped
	.word	518                             // DW_AT_type
                                        // DW_AT_declaration
                                        // DW_AT_external
	.byte	26                              // Abbrev [26] 0x1ff:0x5 DW_TAG_formal_parameter
	.word	522                             // DW_AT_type
	.byte	27                              // Abbrev [27] 0x204:0x1 DW_TAG_unspecified_parameters
	.byte	0                               // End Of Children Mark
	.byte	5                               // Abbrev [5] 0x206:0x4 DW_TAG_base_type
	.byte	31                              // DW_AT_name
	.byte	5                               // DW_AT_encoding
	.byte	4                               // DW_AT_byte_size
	.byte	16                              // Abbrev [16] 0x20a:0x5 DW_TAG_pointer_type
	.word	91                              // DW_AT_type
	.byte	12                              // Abbrev [12] 0x20f:0xd6 DW_TAG_subprogram
	.byte	14                              // DW_AT_low_pc
	.word	.Lfunc_end3-.Lfunc_begin3       // DW_AT_high_pc
	.byte	1                               // DW_AT_frame_base
	.byte	109
                                        // DW_AT_call_all_calls
	.byte	35                              // DW_AT_name
	.byte	1                               // DW_AT_decl_file
	.byte	60                              // DW_AT_decl_line
                                        // DW_AT_prototyped
	.word	518                             // DW_AT_type
                                        // DW_AT_external
	.byte	18                              // Abbrev [18] 0x21e:0x9 DW_TAG_variable
	.byte	3                               // DW_AT_location
	.byte	37                              // DW_AT_name
	.byte	1                               // DW_AT_decl_file
	.byte	62                              // DW_AT_decl_line
	.word	187                             // DW_AT_type
	.byte	20                              // Abbrev [20] 0x227:0x1b DW_TAG_inlined_subroutine
	.word	262                             // DW_AT_abstract_origin
	.byte	15                              // DW_AT_low_pc
	.word	.Ltmp39-.Ltmp38                 // DW_AT_high_pc
	.byte	1                               // DW_AT_call_file
	.byte	70                              // DW_AT_call_line
	.byte	2                               // DW_AT_call_column
	.byte	21                              // Abbrev [21] 0x234:0x6 DW_TAG_formal_parameter
	.byte	0                               // DW_AT_const_value
	.word	266                             // DW_AT_abstract_origin
	.byte	22                              // Abbrev [22] 0x23a:0x7 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_location
	.byte	89
	.word	274                             // DW_AT_abstract_origin
	.byte	0                               // End Of Children Mark
	.byte	20                              // Abbrev [20] 0x242:0x1b DW_TAG_inlined_subroutine
	.word	262                             // DW_AT_abstract_origin
	.byte	16                              // DW_AT_low_pc
	.word	.Ltmp42-.Ltmp41                 // DW_AT_high_pc
	.byte	1                               // DW_AT_call_file
	.byte	71                              // DW_AT_call_line
	.byte	2                               // DW_AT_call_column
	.byte	21                              // Abbrev [21] 0x24f:0x6 DW_TAG_formal_parameter
	.byte	0                               // DW_AT_const_value
	.word	266                             // DW_AT_abstract_origin
	.byte	22                              // Abbrev [22] 0x255:0x7 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_location
	.byte	90
	.word	274                             // DW_AT_abstract_origin
	.byte	0                               // End Of Children Mark
	.byte	20                              // Abbrev [20] 0x25d:0x1b DW_TAG_inlined_subroutine
	.word	262                             // DW_AT_abstract_origin
	.byte	17                              // DW_AT_low_pc
	.word	.Ltmp45-.Ltmp44                 // DW_AT_high_pc
	.byte	1                               // DW_AT_call_file
	.byte	72                              // DW_AT_call_line
	.byte	2                               // DW_AT_call_column
	.byte	21                              // Abbrev [21] 0x26a:0x6 DW_TAG_formal_parameter
	.byte	0                               // DW_AT_const_value
	.word	266                             // DW_AT_abstract_origin
	.byte	22                              // Abbrev [22] 0x270:0x7 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_location
	.byte	91
	.word	274                             // DW_AT_abstract_origin
	.byte	0                               // End Of Children Mark
	.byte	20                              // Abbrev [20] 0x278:0x1b DW_TAG_inlined_subroutine
	.word	262                             // DW_AT_abstract_origin
	.byte	18                              // DW_AT_low_pc
	.word	.Ltmp47-.Ltmp46                 // DW_AT_high_pc
	.byte	1                               // DW_AT_call_file
	.byte	73                              // DW_AT_call_line
	.byte	2                               // DW_AT_call_column
	.byte	21                              // Abbrev [21] 0x285:0x6 DW_TAG_formal_parameter
	.byte	0                               // DW_AT_const_value
	.word	266                             // DW_AT_abstract_origin
	.byte	22                              // Abbrev [22] 0x28b:0x7 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_location
	.byte	89
	.word	274                             // DW_AT_abstract_origin
	.byte	0                               // End Of Children Mark
	.byte	20                              // Abbrev [20] 0x293:0x1b DW_TAG_inlined_subroutine
	.word	262                             // DW_AT_abstract_origin
	.byte	19                              // DW_AT_low_pc
	.word	.Ltmp49-.Ltmp48                 // DW_AT_high_pc
	.byte	1                               // DW_AT_call_file
	.byte	74                              // DW_AT_call_line
	.byte	2                               // DW_AT_call_column
	.byte	21                              // Abbrev [21] 0x2a0:0x6 DW_TAG_formal_parameter
	.byte	0                               // DW_AT_const_value
	.word	266                             // DW_AT_abstract_origin
	.byte	22                              // Abbrev [22] 0x2a6:0x7 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_location
	.byte	90
	.word	274                             // DW_AT_abstract_origin
	.byte	0                               // End Of Children Mark
	.byte	20                              // Abbrev [20] 0x2ae:0x1b DW_TAG_inlined_subroutine
	.word	262                             // DW_AT_abstract_origin
	.byte	20                              // DW_AT_low_pc
	.word	.Ltmp51-.Ltmp50                 // DW_AT_high_pc
	.byte	1                               // DW_AT_call_file
	.byte	75                              // DW_AT_call_line
	.byte	2                               // DW_AT_call_column
	.byte	21                              // Abbrev [21] 0x2bb:0x6 DW_TAG_formal_parameter
	.byte	0                               // DW_AT_const_value
	.word	266                             // DW_AT_abstract_origin
	.byte	22                              // Abbrev [22] 0x2c1:0x7 DW_TAG_formal_parameter
	.byte	1                               // DW_AT_location
	.byte	88
	.word	274                             // DW_AT_abstract_origin
	.byte	0                               // End Of Children Mark
	.byte	23                              // Abbrev [23] 0x2c9:0xe DW_TAG_call_site
	.word	489                             // DW_AT_call_origin
	.byte	21                              // DW_AT_call_return_pc
	.byte	24                              // Abbrev [24] 0x2cf:0x7 DW_TAG_call_site_parameter
	.byte	1                               // DW_AT_location
	.byte	80
	.byte	3                               // DW_AT_call_value
	.byte	163
	.byte	1
	.byte	111
	.byte	0                               // End Of Children Mark
	.byte	23                              // Abbrev [23] 0x2d7:0xd DW_TAG_call_site
	.word	503                             // DW_AT_call_origin
	.byte	22                              // DW_AT_call_return_pc
	.byte	24                              // Abbrev [24] 0x2dd:0x6 DW_TAG_call_site_parameter
	.byte	1                               // DW_AT_location
	.byte	82
	.byte	2                               // DW_AT_call_value
	.byte	16
	.byte	66
	.byte	0                               // End Of Children Mark
	.byte	0                               // End Of Children Mark
	.byte	0                               // End Of Children Mark
.Ldebug_info_end0:
	.section	.debug_str_offsets,"",@progbits
	.word	156                             // Length of String Offsets Set
	.hword	5
	.hword	0
.Lstr_offsets_base0:
	.section	.debug_str,"MS",@progbits,1
.Linfo_string0:
	.asciz	"BiSheng Mobile STD 203.1.0.B040 clang version 15.0.4 (bc89b9c72883)" // string offset=0
.Linfo_string1:
	.asciz	"/mnt/disk/jenkins/ci/workspace/chipset_pipeline_release/opensource/component_code/vendor/huawei/extra/build/build_script/kirin_kernel_release/kernel/platform_source/isp/drivers/ipp/v500/segment/segment_ipp_adapter_sub.c" // string offset=68
.Linfo_string2:
	.asciz	"/mnt/disk/jenkins/ci/workspace/chipset_pipeline_release/opensource/component_code/vendor/huawei/extra/build/build_script/kirin_kernel_release/out" // string offset=288
.Linfo_string3:
	.asciz	"char"                          // string offset=434
.Linfo_string4:
	.asciz	"__ARRAY_SIZE_TYPE__"           // string offset=439
.Linfo_string5:
	.asciz	"unsigned int"                  // string offset=459
.Linfo_string6:
	.asciz	"CPE_TOP"                       // string offset=472
.Linfo_string7:
	.asciz	"CMDLIST_REG"                   // string offset=480
.Linfo_string8:
	.asciz	"CVDR_REG"                      // string offset=492
.Linfo_string9:
	.asciz	"MC_REG"                        // string offset=501
.Linfo_string10:
	.asciz	"KLT_REG"                       // string offset=508
.Linfo_string11:
	.asciz	"ARF_REG"                       // string offset=516
.Linfo_string12:
	.asciz	"REORDER_REG"                   // string offset=524
.Linfo_string13:
	.asciz	"ORB_ENH"                       // string offset=536
.Linfo_string14:
	.asciz	"COMPARE_REG"                   // string offset=544
.Linfo_string15:
	.asciz	"TBU_REG"                       // string offset=556
.Linfo_string16:
	.asciz	"SEC_ADPT_REG"                  // string offset=564
.Linfo_string17:
	.asciz	"MAX_HISP_CPE_REG"              // string offset=577
.Linfo_string18:
	.asciz	"HISP_CPE_REG_TYPE"             // string offset=594
.Linfo_string19:
	.asciz	"IPP_CLK_DISABLE"               // string offset=612
.Linfo_string20:
	.asciz	"IPP_CLK_EN"                    // string offset=628
.Linfo_string21:
	.asciz	"IPP_CLK_STATUS_MAX"            // string offset=639
.Linfo_string22:
	.asciz	"HIPP_CLK_STATUS"               // string offset=658
.Linfo_string23:
	.asciz	"__u32"                         // string offset=674
.Linfo_string24:
	.asciz	"u32"                           // string offset=680
.Linfo_string25:
	.asciz	"__le32"                        // string offset=684
.Linfo_string26:
	.asciz	"__raw_writel"                  // string offset=691
.Linfo_string27:
	.asciz	"val"                           // string offset=704
.Linfo_string28:
	.asciz	"addr"                          // string offset=708
.Linfo_string29:
	.asciz	"hipp_get_regaddr"              // string offset=713
.Linfo_string30:
	.asciz	"printk"                        // string offset=730
.Linfo_string31:
	.asciz	"int"                           // string offset=737
.Linfo_string32:
	.asciz	"do_ippsmmu_enable"             // string offset=741
.Linfo_string33:
	.asciz	"do_ippsmmu_disable"            // string offset=759
.Linfo_string34:
	.asciz	"hipp_orcm_clk_enable"          // string offset=778
.Linfo_string35:
	.asciz	"hipp_orcm_clk_disable"         // string offset=799
.Linfo_string36:
	.asciz	"mode"                          // string offset=821
.Linfo_string37:
	.asciz	"crg_base"                      // string offset=826
	.section	.debug_str_offsets,"",@progbits
	.word	.Linfo_string0
	.word	.Linfo_string1
	.word	.Linfo_string2
	.word	.Linfo_string3
	.word	.Linfo_string4
	.word	.Linfo_string5
	.word	.Linfo_string6
	.word	.Linfo_string7
	.word	.Linfo_string8
	.word	.Linfo_string9
	.word	.Linfo_string10
	.word	.Linfo_string11
	.word	.Linfo_string12
	.word	.Linfo_string13
	.word	.Linfo_string14
	.word	.Linfo_string15
	.word	.Linfo_string16
	.word	.Linfo_string17
	.word	.Linfo_string18
	.word	.Linfo_string19
	.word	.Linfo_string20
	.word	.Linfo_string21
	.word	.Linfo_string22
	.word	.Linfo_string23
	.word	.Linfo_string24
	.word	.Linfo_string25
	.word	.Linfo_string26
	.word	.Linfo_string27
	.word	.Linfo_string28
	.word	.Linfo_string29
	.word	.Linfo_string30
	.word	.Linfo_string31
	.word	.Linfo_string32
	.word	.Linfo_string33
	.word	.Linfo_string34
	.word	.Linfo_string35
	.word	.Linfo_string36
	.word	.Linfo_string37
	.section	.debug_addr,"",@progbits
	.word	.Ldebug_addr_end0-.Ldebug_addr_start0 // Length of contribution
.Ldebug_addr_start0:
	.hword	5                               // DWARF version number
	.byte	8                               // Address size
	.byte	0                               // Segment selector size
.Laddr_table_base0:
	.xword	.L.str
	.xword	.L__func__.hipp_orcm_clk_enable
	.xword	.L__func__.hipp_orcm_clk_disable
	.xword	.Lfunc_begin0
	.xword	.Lfunc_begin1
	.xword	.Lfunc_begin2
	.xword	.Ltmp10
	.xword	.Ltmp14
	.xword	.Ltmp19
	.xword	.Ltmp17
	.xword	.Ltmp21
	.xword	.Ltmp24
	.xword	.Ltmp7
	.xword	.Ltmp28
	.xword	.Lfunc_begin3
	.xword	.Ltmp38
	.xword	.Ltmp41
	.xword	.Ltmp44
	.xword	.Ltmp46
	.xword	.Ltmp48
	.xword	.Ltmp50
	.xword	.Ltmp31
	.xword	.Ltmp54
.Ldebug_addr_end0:
	.ident	"BiSheng Mobile STD 203.1.0.B040 clang version 15.0.4 (bc89b9c72883)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.section	.debug_line,"",@progbits
.Lline_table_start0:
