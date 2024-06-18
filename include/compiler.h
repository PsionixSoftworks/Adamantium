#ifndef _ADAMANTIUM_COMPILER_H
#define _ADAMANTIUM_COMPILER_H				1

#define PACKED								__attribute__((packed))
#define NORETURN							__attribute__((__noreturn__))
#define ALIGN(x)							__attribute__((__aligned(x)))

#define _packed								PACKED
#define _noreturn							NORETURN
#define _align(x)							ALIGN(x)

#endif
