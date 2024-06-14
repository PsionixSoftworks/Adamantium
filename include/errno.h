#ifndef _ADAMANTIUM_ERRNO_H
#define _ADAMANTIUM_ERRNO_H					1

// The 'errno' value is used to tell the system what error has occured. It is defined in kernel.c:
extern int errno;

// We just need the one error code for now:
#define EOVERFLOW							75

#endif
