#include "mm.h"
.section ".text.boot"

.globl _start
_start:
	mrs	x0, mpidr_el1		
	and	x0, x0,#0xFF		// Check processor id
	cbz	x0, master		// Hang for all non-primary CPU
	b	proc_hang
proc_hang: 
	b 	proc_hang

master:
	adr	x0, bss_begin
	adr	x1, bss_end
	sub	x1, x1, x0
	bl 	memzero
	bl init_page_table
	    // 禁用 MMU
    mrs     x0, SCTLR_EL1            
    bic     x0, x0, #0x1             
    msr     SCTLR_EL1, x0            

    ldr     x0, =page_table   
    msr     TTBR0_EL1, x0            
	//加载内核
	//bl  load_kernel

    // 启用 MMU
    mrs     x0, SCTLR_EL1            
    orr     x0, x0, #0x1             
    msr     SCTLR_EL1, x0            

	mov	sp, #LOW_MEMORY
	bl	kernel_main      //进入main
	b 	proc_hang		//丸辣
