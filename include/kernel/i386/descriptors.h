#ifndef _ADAMANTIUM_DESCRIPTORS_H
#define _ADAMANTIUM_DESCRIPTORS_H

#define MAX_GDT_ENTRIES						5
#define MAX_IDT_ENTRIES						256

#if !defined(__ASSEMBLER__)
#include <kernel/tty.h>
#include <vga.h>
#include <stdint.h>
#include <stdio.h>
#include "interrupt.h"

extern void descriptors_init(void);

#endif

#define GDT_KERNEL_CODE_SEGMENT				0x08
#define GDT_KERNEL_DATA_SEGMENT				0x10
#endif
