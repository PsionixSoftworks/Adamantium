#ifndef _ADAMANTIUM_STDLIB_H
#define _ADAMANTIUM_STDLIB_H				1

#include "compiler.h"

#if defined(__cplusplus)
#define EXTERN_C_BEGIN 						extern "C" {
#define EXTERN_C_END						}
#else
#define EXTERN_C_BEGIN
#define EXTERN_C_END
#endif

EXTERN_C_BEGIN
extern NORETURN void abort(void);
extern char* itoa(int, char*, int);
EXTERN_C_END

#endif
