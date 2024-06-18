SRC				= $(wildcard *.asm *.c)
BUILD			= $(SRC:.c=.o)
CC				= gcc -m32
CFLAGS			= -ffreestanding -fno-exceptions -fno-stack-protector -O2 -g -Wall -Wextra -Iinclude
OBJS			= $(wildcard *.o)
EMU				= qemu-system-i386 -machine ubuntu -drive format=raw,file=$(ISO_FILE)

MKDIR 			= mkdir -pv
CP 				= cp
CFG 			= grub.cfg
BIN				= KERNEL
ISO_PATH 		= iso
BOOT_PATH 		= $(ISO_PATH)/boot
GRUB_PATH 		= $(BOOT_PATH)/grub
ISO_FILE		= adamantium.iso

.PHONY: all
all: build_list linker iso run
	@echo Make has finished all tasks.

build_list:
	make -C boot
	make -C init
	make -C kernel/i386
	make -C libc

link: link.ld $(OBJS)
	ld -m elf_i386 -T link.ld -o $(BIN) $(OBJS)

iso: $(BIN)
	$(MKDIR) $(GRUB_PATH)
	$(CP) $(BIN) $(BOOT_PATH)
	$(CP) $(CFG) $(GRUB_PATH)
	grub-file --is-x86-multiboot $(BOOT_PATH)/$(BIN)
	grub-mkrescue -o $(ISO_FILE) $(ISO_PATH)

run:
	$(EMU)

clean: $(OBJS)
	rm -rf *.o *.iso *KERNEL
