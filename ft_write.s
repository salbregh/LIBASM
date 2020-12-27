section .text
global _ft_write
extern ___error

; rdi 1st argument holds the file descriptor
; rsi 2nd argument holds the string to be written
; rdx 3rd argument holds the count
; use r8 r9 or r10 for other variables

_ft_write:
	mov		rax, 0x2000004		; systemcall number for write
	syscall						; envoke system to do the write
	cmp		rax, -1				; see if write failed
	je		error				; jump to error if -1 
	ret

error:
	mov		r8,  rax			; save the value of errno in r8
	call	___error			; returns the address of the error
	mov		[rax], r8			; set the value of errno
	mov		rax, -1
	ret