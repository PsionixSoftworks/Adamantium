#ifndef _ADAMANTIUM_STDIO_H
#define _ADAMANTIUM_STDIO_H					1

#if defined(__cplusplus)
#define EXTERN_C_BEGIN 						extern "C" {
#define EXTERN_C_END						}
#else
#define EXTERN_C_BEGIN
#define EXTERN_C_END
#endif

#ifndef EOF
#define EOF									(-1)
#endif	// !EOF

EXTERN_C_BEGIN

int putchar(int);
int puts(const char*);
int printf(const char* restrict, ...);

EXTERN_C_END

#endif
