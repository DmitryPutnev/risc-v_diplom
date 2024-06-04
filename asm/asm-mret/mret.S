.section .data
.section .text
.global main

main:
	la t1, user
	csrw mepc, t1
	mret
	
user:
	j exit
