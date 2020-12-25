section .text
global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcpy
extern ___error
extern _puts

; rdi is src
; rsi is de dst
; rdx is i

_ft_strdup:
    cmp		rdi, 0			; compare is src is NULL
	je		error			; if src is NULL return
	
	push	rdi				; save register that strlen uses
	call	_ft_strlen		; use ft_strlen on source
	inc		rax				; ft_strlen + 1 for '\0;
	mov		rdi, rax		; put len in rdi
	
	call	_malloc			; rdi is used for malloc, empty after and put in rax
	cmp		rax, 0			; check if malloc failed
	je		error			; ret is malloc fail
	mov		rdi, rax		; put content in rdi
	pop		rsi				; src for use strcpy
	call	_ft_strcpy
	ret

error:
	pop		rdi				; restore caller-save register
	ret