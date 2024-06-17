#ifndef _ADAMANTIUM_COMPILER_H
#define _ADAMANTIUM_COMPILER_H				1

#define PACKED								__attribute__((packed))
#define NORETURN							__attribute__((__noreturn__))

#define _packed                              PACKED
#define _noreturn                            NORETURN

#endif
