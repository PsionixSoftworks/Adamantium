SRC				= $(wildcard *.S *.asm)
BUILD			= $(SRC:.S=.o)
GCC				= gcc -c -m32
ASFLAGS			= -I../include
OBJS			= 

all: $(BUILD)
	@echo [INFO]: Finished building all sources.

%.o: %.S
	$(GCC) $(ASFLAGS) $< -o ../$@ 
