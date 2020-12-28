section .text
global _ft_write
extern ___error

_ft_write:
	mov		rax, 0x2000004		; systemcall number for write
	syscall						; envoke system to do the write
	jc		error				; jump if carry flag
	ret

error:
	mov		r8,  rax			; save the value of errno in r8
	call	___error			; returns the address of the error
	mov		[rax], r8			; set the value of errno
	mov		rax, -1
	ret