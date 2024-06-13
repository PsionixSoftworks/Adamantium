CP 			:= cp
RM 			:= rm -rf
MKDIR 		:= mkdir -pv

BIN 		= kernel
CFG 		= grub.cfg
ISO_PATH 	:= iso
BOOT_PATH 	:= $(ISO_PATH)/boot
GRUB_PATH 	:= $(BOOT_PATH)/grub
ISO_FILE	:= adamantium.iso

.PHONY: all
all: bootloader kernel linker iso run
	@echo Make has completed.

bootloader: boot/grub-boot.S
	as --32 boot/grub-boot.S -o boot.o

kernel: init/kernel.c
	gcc -m32 -c init/kernel.c -o kernel.o -Iinclude

linker: link.ld boot.o kernel.o
	ld -m elf_i386 -T link.ld -o kernel boot.o kernel.o

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
