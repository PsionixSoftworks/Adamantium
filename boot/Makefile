SRC				= $(wildcard *.S *.asm)
BUILD			= $(SRC:.S=.o) $(SRC:.asm=.o)
NASM			= nasm -felf32
AS				= as --32
ASFLAGS			= -I../include
OBJS			= 

all: $(BUILD)
	@echo [INFO]: Finished building all sources.

%.o: %.asm
	$(NASM) $< -o ../$@

%.o: %.S
	$(AS) $(ASFLAGS) $< -o ../$@
