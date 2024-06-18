#ifndef _ADAMANTIUM_LIMITS_H
#define _ADAMANTIUM_LIMITS_H				1

/* Char limits */
#define CHAR_BIT							 8
#define CHAR_MIN							-128
#define CHAR_MAX							 127
#define SCHAR_MIN							 CHAR_MIN
#define	SCHAR_MAX							 CHAR_MAX
#define UCHAR_MAX							 255

/* Short limits */
#define SHRT_MIN							-32767
#define SHRT_MAX							 32767
#define USHRT_MAX							 65535

/* Integer limits */
#define INT_MIN								-2147483647
#define INT_MAX								 2147483647
#define UINT_MAX							 4294967295U

/* Long limits */
#define LONG_BIT							 32
#define LONG_MIN							-2147483647
#define	LONG_MAX							 2147483647
#define ULONG_MAX							 4294967295UL

/* Word limits */
#define WORD_BIT							 32

/* Long long limits (int64) */
#define LLONG_MIN							-9223372036854775807LL
#define LLONG_MAX							 9223372036854775807LL
#define ULLONG_MAX							 18446744073709551615ULL

/* Maximum number of bytes in a character, for any spupported locale */
#define MB_LEN_MAX							1

/* POSIX Standard Macro Definitions (The Open Group Base Specifications Issue 7, 2018 edition) */
#if defined(_POSIX_SOURCE)
#define _POSIX_ARG_MAX						4096
#define _POSIX_CHILD_MAX					25
#define _POSIX_HOST_NAME_MAX				255
#define _POSIX_LINK_MAX						8
#define _POSIX_LOGIN_NAME_MAX				9
#define _POSIX_NAME_MAX						14
#define _POSIX_OPEN_MAX						20
#define _POSIX_PATH_MAX						256
#define _POSIX_SSIZE_MAX					32767
#define _POSIX_TTY_NAME_MAX					9
#define _POSIX_TZNAME_MAX					6
#endif

#define FILESIZEBITS						32
#define PAGE_SIZE							4096
#define PAGESIZE							PAGE_SIZE

/* Signed size max */
#if defined(_POSIX_SSIZE_MAX)
#define SSIZE_MAX							_POSIX_SSIZE_MAX
#else
#define SSIZE_MAX							32767
#endif

#if defined(_POSIX_CHILD_MAX)
#define CHILD_MAX							_POSIX_CHILD_MAX
#else
#define CHILD_MAX							25
#endif	// _POSIX_CHILD_MAX

#if defined(_POSIX_LOGIN_NAME_MAX)
#define LOGIN_NAME_MAX						_POSIX_LOGIN_NAME_MAX
#else
#define LOGIN_NAME_MAX						32
#endif	// _POSIX_LOGIN_NAME_MAX

#if defined(_POSIX_HOST_NAME_MAX)
#define HOST_NAME_MAX						_POSIX_HOST_NAME_MAX
#else
#define HOST_NAME_MAX						32
#endif	// _POSIX_HOST_NAME_MAX

#if defined(_POSIX_ARG_MAX)
#define ARG_MAX								_POSIX_ARG_MAX
#else
#define ARG_MAX								16384
#endif	// _POSIX_ARG_MAX

#if defined(_POSIX_OPEN_MAX)
#define OPEN_MAX							_POSIX_OPEN_MAX
#else
#define OPEN_MAX							24
#endif	// _POSIX_OPEN_MAX

#if defined(_POSIX_TZNAME_MAX)
#define TZNAME_MAX							_POSIX_TZNAME_MAX
#else
#define TZNAME_MAX							6
#endif	// _POSIX_TZNAME_MAX

#endif	// _ADAMANTIUM_LIMITS_H

// This file attempts to meet compliance with "The Open Group Base Specifications Issue 7, 2018 edition."
