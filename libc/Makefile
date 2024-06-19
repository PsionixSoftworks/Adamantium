ASSEMB			= as --32
CC				= gcc -m32
CFLAGS			= -ffreestanding -fno-exceptions -fno-stack-protector -O2 -g -Wall -Wextra -I../include
PARENT_DIR		= ../../

.PHONY: all
all: stdlib

stdlib: stdio/printf.c
# 	Standard IO:
	$(CC) $(CFLAGS) -c stdio/printf.c -o ../printf.o
	$(CC) $(CFLAGS) -c stdio/putchar.c -o ../putchar.o
	$(CC) $(CFLAGS) -c stdio/puts.c -o ../puts.o

#	Standard Library:
	$(CC) $(CFLAGS) -c stdlib/abort.c -o ../abort.o
	$(CC) $(CFLAGS) -c stdlib/itoa.c -o ../itoa.o

#	String:
	$(ASSEMB) string/memcmp.S -o ../memcmp.o
	$(ASSEMB) string/memcpy.S -o ../memcpy.o
	$(ASSEMB) string/memmove.S -o ../memmove.o
	$(ASSEMB) string/memset.S -o ../memset.o
	$(ASSEMB) string/strlen.S -o ../strlen.o
