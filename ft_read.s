section .text
global _ft_read
extern ___error

_ft_read:
	mov		rax, 0x2000003		; symstemcall for read
	syscall						; envoke system to do the read
	jc		error				; jump if carry flag
	ret							; if not return bytes read

error:
	mov		r8, rax;			; save errno value in r8
	call	___error			; error returns address of errno
	mov		[rax], r8			; set value of errno
	mov		rax, -1				; set returnvalue to -1
	ret