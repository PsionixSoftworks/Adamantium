CC				= gcc -m32
CFLAGS			= -ffreestanding -fno-exceptions -fno-stack-protector -O2 -g -Wall -Wextra -I../include
PARENT_DIR		= ../../

.PHONY: all
all: stdlib

stdlib: stdio/printf.c
	$(CC) $(CFLAGS) -c stdio/printf.c -o ../printf.o
	$(CC) $(CFLAGS) -c stdio/putchar.c -o ../putchar.o
	$(CC) $(CFLAGS) -c stdio/puts.c -o ../puts.o

	$(CC) $(CFLAGS) -c stdlib/abort.c -o ../abort.o
	$(CC) $(CFLAGS) -c stdlib/itoa.c -o ../itoa.o

	$(CC) $(CFLAGS) -c string/memcmp.c -o ../memcmp.o
	$(CC) $(CFLAGS) -c string/memcpy.c -o ../memcpy.o
	$(CC) $(CFLAGS) -c string/memmove.c -o ../memmove.o
	$(CC) $(CFLAGS) -c string/memset.c -o ../memset.o
	$(CC) $(CFLAGS) -c string/strlen.c -o ../strlen.o
