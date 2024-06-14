#include <string.h>

void* memcpy(void* restrict pdst, const void* restrict psrc, size_t sz)
{
	unsigned char* dst 			= (unsigned char*)pdst;
	const unsigned char* src 	= (const unsigned char*)psrc;
	for (size_t i = 0; i < sz; i++)
	{
		dst[i] = src[i];
	}
	return pdst;
}
