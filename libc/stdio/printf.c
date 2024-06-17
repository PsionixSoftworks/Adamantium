#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <vga.h>

#define MAX_CHARACTERS						TERMINAL_WIDTH * TERMINAL_HEIGHT

int printf(const char* restrict fmt, ...)
{
	va_list params;
	va_start(params, fmt);
	for (size_t i = 0; i < strlen(fmt); i++)
	{
		if (fmt[i] == '%')
		{
			switch (fmt[i+1])
			{
				case 's':
				{
					char* str = va_arg(params, char*);
					if (!puts(str))
					{
						return -1;
					}
					i++;
					continue;
				}
				case 'b': 
				{
					unsigned int str = va_arg(params, unsigned int);
					char buffer[MAX_CHARACTERS];
					puts(itoa(str, buffer, 2));
					i++;
					continue;
				}
				case 'c':
				{
					char c = va_arg(params, int);
					if (!putchar(c))
					{
						return -1;
					}
					i++;
					continue;
				}
				case 'd':
				{
					int str = va_arg(params, int);
					char buffer[MAX_CHARACTERS];
					if (!puts(itoa(str, buffer, 10)))
					{
						return -1;
					}
					i++;
					continue;
				}
				case 'u':		/* Broken. Unsigned integers are supposed to wrap around when their limits are reached... */
				{
					unsigned int str = va_arg(params, unsigned int);
					char buffer[MAX_CHARACTERS];
					if (!puts(itoa(str, buffer, 10)))
					{
						return -1;
					}
					i++;
					continue;
				}
				case 'o':
				{
					int str = va_arg(params, int);
					char buffer[MAX_CHARACTERS];
					if (!puts(itoa(str, buffer, 8)))
					{
						return -1;
					}
					i++;
					continue;
				}
				case 'x':
				{
					unsigned int str = va_arg(params, unsigned int);
					char buffer[MAX_CHARACTERS];
					char* result = itoa(str, buffer, 16);
					if (!puts(result))
					{
						return -1;
					}
					i++;
					continue;
				}
			};
		}
		else
		{
			putchar(fmt[i]);
		}
	}
	va_end(params);
	return 0;
}
