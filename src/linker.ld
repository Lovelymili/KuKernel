MEMORY
{
    RAM (rwx) : ORIGIN = 0x0, LENGTH = 0x100000000  /* 4GB 内存区域 */
    STACK (rw) : ORIGIN = 0xF0000000, LENGTH = 0x20000000  /* 栈区域，512MB */
    MM_AREA (rw) : ORIGIN = 0x24000000, LENGTH = 0x04000000 /* mm管理区，64MB */
    HEAP_AREA (rw) : ORIGIN = 0x22000000, LENGTH = 0x20000000 /* 堆区，512MB */
}

SECTIONS
{
    .text.boot : AT(0x0) {
        *(.text.boot)
    }

    .text : AT(0x10000000) {
        *(.text)
    }

    .rodata : AT(0x18000000) { 
        *(.rodata)
    }

    .data : AT(0x20000000) {
        *(.data)
    }

    . = ALIGN(0x8);

    bss_begin = .;  
    .bss : AT(0x24000000) {
        *(.bss*)
    }
    bss_end = .; 

    heap_begin = 0x22000000;
    .heap : AT(0x22000000) {
        *(.heap)
    }
    heap_end = .;

    stack_begin = 0xF0000000;
    .stack : AT(0xF0000000) {
        *(.stack)
    }
    stack_end = .;

    mm_begin = .;
    .mm : AT(0x28000000) {  
        *(.mm*)
    }
    mm_end = .;
}

