#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

/* Print internal: Prints the specified formatted string. */
static bool print_int(const unsigned char* data, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		if (putchar(data[i]) == EOF)
		{
			return false;
		}
	}
	return true;
}

int printf(const char* restrict fmt, ...)
{
	va_list params;
	va_start(params, fmt);

	int written = 0;
	while (*fmt != '\0')
	{
		size_t maxrem = INT_MAX - written;
		if (fmt[0] != '%' || fmt[1] == '%') {
			if (fmt[0] == '%')
			{
				fmt++;
			}
			size_t amt = 1;
			while (fmt[amt] && fmt[amt] != '%')
			{
				amt++;
			}
			if (maxrem < amt) 
			{
				errno = -EOVERFLOW;
				return -1;
			}
			if (!print_int(fmt, amt))
			{
				return -1;
			}
			fmt += amt;
			written += amt;
			continue;
		}
		const char* fmt_start = fmt++;
		if (*fmt == 'c')
		{
			fmt++;
			char c = (char)va_arg(params, int);
			if (!maxrem)
			{
				errno = -EOVERFLOW;
				return -1;
			}
			if (!print_int(&c, sizeof(c)))
			{
				return -1;
			}
			written++;
		}
		else if (*fmt == 's') 
		{
			fmt++;
			const char* str = va_arg(params, const char*);
			size_t len = strlen(str);
			if (maxrem < len)
			{
				errno = -EOVERFLOW;
				return -1;
			}
			if (!print_int(str, len))
			{
				return -1;
			}
			written += len;
		}
		else
		{
			fmt = fmt_start;
			size_t len = strlen(fmt);
			if (maxrem < len)
			{
				errno = -EOVERFLOW;
				return -1;
			}
			if (!print_int(fmt, len))
			{
				return -1;
			}
			written += len;
			fmt += len;
		}
	}
	va_end(params);
	return written;
}
