#ifndef _ADAMANTIUM_STRING_H
#define _ADAMANTIUM_STRING_H				1

#include <stddef.h>

#if defined(__cplusplus)
#define EXTERN_C_BEGIN 						extern "C" {
#define EXTERN_C_END						}
#else
#define EXTERN_C_BEGIN
#define EXTERN_C_END
#endif

EXTERN_C_BEGIN

void* memcpy(void* __restrict, const void* __restrict, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);
int memcmp(const void*, const void*, size_t);
size_t strlen(const char*);

EXTERN_C_END

#endif	// !_STRING_H
