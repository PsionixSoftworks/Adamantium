SRC				= $(wildcard *.c)
BUILD			= $(SRC:.c=.o)
CC				= gcc -m32
CFLAGS			= -ffreestanding -fno-exceptions -fno-stack-protector -O2 -g -Wall -Wextra -I../include

all: $(BUILD)
	@echo [INFO]: Finished building all sources.

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o ../$@
