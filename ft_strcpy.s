section .text
global _ft_strcpy

_ft_strcpy:
	mov		rdx, -1						; i = -1

copy:
	inc		rdx							; increment i
	mov		al, byte [rsi + rdx]		; get the character in the src
	or		al, al						; if character is zero return 
	jz		return						; return if zero
	mov		byte [rdi + rdx], al		; copy the src character into the dest
	jne		copy						; loop to copy again


return:
	mov		rax, rdi					; put dest in the return
	ret