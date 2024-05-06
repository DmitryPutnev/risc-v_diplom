.section .data
.equiv mtimecmp, 0x02004000
.equiv mtime, 0x0200bff8

.section .text
.global _start

_start:
	li t0, mtime
	sw zero, 0(t0)
	sw zero, 4(t0)
	
	li t0, mtimecmp
	li t1, 0x18000
	sw t1, 0(t0)
	sw zero, 4(t0)
	
	la t0, timer_interrupt_handler
	csrw mtvec, t0
	
	csrr t0, mstatus
	addi t0, t0, 8
	csrw mstatus, t0
	
	li t0, (1 << 7) | (1 << 5);
	csrw mie, t0
	
	li t1, 5
	li t2, 0
	
	j wait
wait:
	bgt t1, t2, wait
	
	nop

.align 4
timer_interrupt_handler:

	li t0, mtime
	sw zero, 0(t0)
	sw zero, 4(t0)
	
	addi t2, t2, 1
	mret
