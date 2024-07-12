.include "asm.inc"

function start
.option push
.option norvc
.option norelax
	la gp,_global_start
.option pop

stack_setup:
	la a0, _stack_start
	mv sp, a0
	mv a0,zero
jump_to_main:
	jal	main
	j	.
