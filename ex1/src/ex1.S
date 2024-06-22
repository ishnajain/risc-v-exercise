.section .text.ex1
.global ex1
.type ex1, "function"
ex1:
	la	gp, dstarr
	la	a0, srcarr
	la	a1, dstarr
	lw	t0, 0(a0)
	sw	t0, 0(a1)
halt: 
	wfi
	j	halt

.section .rodata.srcarr
.type srcarr, "object"
srcarr: 
	.word	0xC0FFEE

.section .data.dstarr
.type dstarr, "object"
dstarr:
	.word	0

