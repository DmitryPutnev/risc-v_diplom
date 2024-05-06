.section .data

.section .text
.global _start

_start:
	csrr t0, mstatus
	csrr t1, mepc
	la t3, user
	csrw mepc, t3
	mret

	
user:
	li t0, 5
	li t1, 4
	add t0, t0, t1
	csrr t0, mstatus
	
	li a0, 1
	li a7, 93
	ecall
