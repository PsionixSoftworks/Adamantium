#include <string.h>

void* memmove(void* pdst, const void* psrc, size_t sz)
{
	unsigned char* dst 			= (unsigned char*)pdst;
	const unsigned char* src 	= (const unsigned char*)psrc;

	if (dst < src)
	{
		for (size_t i = 0; i < sz; i++)
		{
			dst[i] = src[i];
		}
	}
	else
	{
		for (size_t i = sz; i != 0; i--)
		{
			dst[i - 1] = src[i - 1];
		}
	}
	return pdst;
}
