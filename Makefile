CP 			:= cp
RM 			:= rm -rf
MKDIR 		:= mkdir -pv

BIN 		= KERNEL
CFG 		= grub.cfg
ISO_PATH 	:= iso
BOOT_PATH 	:= $(ISO_PATH)/boot
GRUB_PATH 	:= $(BOOT_PATH)/grub
ISO_FILE	:= adamantium.iso

CFLAGS		= -ffreestanding -fno-exceptions -fno-stack-protector -O2 -g -Wall -Wextra -Iinclude

.PHONY: all
all: bootloader kernel linker iso run
	@echo Make has completed.

bootloader: boot/grub-boot.S
	as --32 boot/grub-boot.S -o boot.o

kernel: init/kernel.c
	gcc -m32 -c init/kernel.c -o kernel.o $(CFLAGS)
	gcc -m32 -c libc/stdlib/abort.c -o abort.o $(CFLAGS)
	gcc -m32 -c libc/string/memmove.c -o memmove.o $(CFLAGS)
	gcc -m32 -c libc/string/strlen.c -o strlen.o $(CFLAGS)
	gcc -m32 -c libc/string/memcmp.c -o memcmp.o $(CFLAGS)
	gcc -m32 -c libc/string/memset.c -o memset.o $(CFLAGS)
	gcc -m32 -c libc/string/memcpy.c -o memcpy.o $(CFLAGS)
	gcc -m32 -c libc/stdio/printf.c -o printf.o $(CFLAGS)
	gcc -m32 -c libc/stdio/putchar.c -o putchar.o $(CFLAGS)
	gcc -m32 -c libc/stdio/puts.c -o puts.o $(CFLAGS)

linker: link.ld boot.o kernel.o
	ld -m elf_i386 -T link.ld -o kernel boot.o kernel.o abort.o memmove.o strlen.o memcmp.o memset.o memcpy.o printf.o putchar.o puts.o

iso: kernel
	$(MKDIR) $(GRUB_PATH)
	$(CP) $(BIN) $(BOOT_PATH)
	$(CP) $(CFG) $(GRUB_PATH)
	grub-file --is-x86-multiboot $(BOOT_PATH)/$(BIN)
	grub-mkrescue -o $(ISO_FILE) $(ISO_PATH)

.PHONY: clean
clean:
	$(RM) *.o $(BIN) *iso
run:
	qemu-system-i386 -machine ubuntu -drive format=raw,file=$(ISO_FILE)
	$(RM) *.o $(BIN) *iso
