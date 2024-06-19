gdt_start:					; Null Segment
    dq 0x0000000000000000
gdt_kcode:					; Kernel Code Segment
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 0x9A
    db 0xCF
    db 0x00
gdt_kdata:					; Kernel Data Segment
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 0x92
    db 0xCF
    db 0x00
gdt_end:

[global gdt_install]
gdt_pointer:                ; Pointer is where the GDT is loaded from
    dw gdt_end - gdt_start
    dd gdt_start

; Install the GDT:
gdt_install:
    mov eax, gdt_pointer
    lgdt [eax]

	mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:.flush
.flush:
    ret
