section .text
global _ft_strlen

_ft_strlen:
	mov		rax, -1					; i = -1

loop:
    inc		rax						; i++
	cmp		byte [rdi + rax], 0		; compare byte to NULL
	jne		loop					; loops if not at NULL yet
	ret