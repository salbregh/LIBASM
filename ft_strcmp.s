section .text
global _ft_strcmp

_ft_strcmp:
	mov		rdx, -1					; set the 3rd callee argument to -1 (i = -1)

compare:
	inc		rdx;
	mov		al, byte [rdi + rdx]	; put value of s1 character in al
	mov		cl, byte [rsi + rdx]	; put value of s2 character in rcl
	or		al, al					; check if s1 == NULL
	jz		return					; if equal to null return 
	cmp		al, cl					; compare the 2 values
	je		compare					; go back to compare if equal
	jne		return					; jump to return if not equal to zero

return:
	sub		al, cl					; calculate the diffence and put in al
	movsx	rax, al					; put diff in rax
	ret								; return diff
