#include <string.h>

size_t strlen(const char* str)
{
	size_t sz = 0;
	while(str[sz] != '\0')
		sz++;
	return sz;
}
