[org 0x7c00]

mov ah, 0x0E
mov si, message

print_loop:
    lodsb
    cmp al, 0
    je hang
    int 0x10
    jmp print_loop

hang:
    jmp $

message db 'hello stroxzu', 0

times 510-($-$$) db 0
dw 0xAA55
