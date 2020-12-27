section .text
global _ft_read
extern ___error

_ft_read:
	mov		rax, 1
	ret