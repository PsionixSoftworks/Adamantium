#include <stdio.h>
#include <string.h>
#include <vga.h>

int puts(const char* str)
{
	static size_t len = 0;
	while (len < strlen(str))
	{
		putchar(str[len++]);
	}
	return len;
}
