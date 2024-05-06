.section .data

.section .text
.global _start

_start:
	la t0, exception_handler
	csrw mtvec, t0
	
	#lw t1, 0(t0)
	
	#ebreak
	
	#unimp
	
	ecall
	
	li a0, 0
	li a7, 93
	ecall
	
.align 4
exception_handler:
	
	csrr t1, mcause
	
	li a0, 1
	li a7, 93
	ecall
