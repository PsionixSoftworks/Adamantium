#include <string.h>

void* memset(void* pbuf, int value, size_t sz)
{
	unsigned char* buf = (unsigned char*)pbuf;
	for (size_t i = 0; i < sz; i++)
	{
		buf[i] = (unsigned char)value;
	}
	return pbuf;
}
