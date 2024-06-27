SRC				= $(wildcard *.c)
BUILD			= $(SRC:.c=.o)
CC				= gcc -m32
ASSEMB			= as --32
CFLAGS			= -ffreestanding -fno-exceptions -fno-stack-protector -O2 -g -Wall -Wextra -I../../include

all: $(BUILD) assembly
	@echo [INFO]: Finished building all sources.

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o ../../$@

assembly:
	$(ASSEMB) isr_idx.S -o ../../isr_idx.o
