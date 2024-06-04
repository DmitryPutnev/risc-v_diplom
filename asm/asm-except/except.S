.section .data

.section .text
.global main

main:
	la t0, exception_handler
	csrw mtvec, t0
	
	unimp
	
.align 4
exception_handler:
	
	j exit
