.section .text.ex1
.global ex1
.type ex1, "function"
ex1:
	li	gp, 0x80000000
	la	t0, ex_handler
	csrw	mtvec, t0
	nop
	nop
	nop
	ecall
	li	t0, 0x8000000
	lw	t0, 0(t0)
halt: 
	wfi
	j	halt
	
.section .text.ex_handler
.global ex_handler
.type ex_handler, "function"
ex_handler:
	li	a1, 0xc0ffee
	csrr	a0, mcause
	wfi
	j	ex_handler
