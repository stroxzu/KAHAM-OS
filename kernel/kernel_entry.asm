[bits 32]
global _start
_start:
    call kernel_main
hang:
    jmp hang
