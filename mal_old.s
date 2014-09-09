	.syntax unified
	.cpu cortex-m3
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 2
	.eabi_attribute 18, 4
	.thumb
	.file	"lab2.c"
	.global	__aeabi_ldivmod
	.text
	.align	2
	.global	func
	.thumb
	.thumb_func
	.type	func, %function
func:
	mov r0, #1
	mov r1, 0x20000100
	str r0, [r1, #0]
	mov pc, 0x193

	.size	func, .-func
	.comm	gLast,4,4
	.ident	"GCC: (Sourcery G++ Lite 2010q1-188) 4.4.1"
