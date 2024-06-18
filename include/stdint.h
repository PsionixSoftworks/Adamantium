#ifndef _ADAMANTIUM_STDINT_H
#define _ADAMANTIUM_STDINT_H				1

/* Include limits.h here */
#include <limits.h>

/* More macro definitions for the types defined below */
#ifndef INT8_MIN
#define INT8_MIN							-127
#endif	// INT8_MIN

#ifndef INT8_MAX
#define INT8_MAX							127
#endif	// INT8_MAX

#ifndef UINT8_MAX
#define UINT8_MAX							255
#endif	// UINT8_MAX

#ifndef INT16_MIN
#define INT16_MIN							-32767
#endif	// INT16_MIN

#ifndef INT16_MAX
#define INT16_MAX							32767
#endif	// INT16_MAX

#ifndef UINT16_MAX
#define UINT16_MAX							65535
#endif	// UINT16_MAX

#ifndef INT32_MIN
#define INT32_MIN							-2147483647
#endif	// INT32_MIN

#ifndef INT32_MAX
#define INT32_MAX							2147483647
#endif	// INT32_MAX

#ifndef UINT32_MAX
#define UINT32_MAX							4294967295
#endif	// UINT32_MAX

#ifndef INT64_MIN
#define INT64_MIN							-9223372036854775807
#endif	// INT64_MIN

#ifndef INT64_MAX
#define INT64_MAX							9223372036854775807
#endif	// INT64_MAX

#ifndef UINT64_MAX
#define UINT64_MAX							18446744073709551615
#endif	// UINT64_MAX

#ifndef INT8_LEAST_MIN
#define INT8_LEAST_MIN						-127
#endif	// INT8_LEAST_MIN

#ifndef INT8_LEAST_MAX
#define INT8_LEAST_MAX						127
#endif	// INT8_LEAST_MAX

#ifndef UINT8_LEAST_MAX
#define UINT8_LEAST_MAX						255
#endif	// UINT8_LEAST_MAX

#ifndef INT16_LEAST_MIN
#define INT16_LEAST_MIN						-32767
#endif	// INT16_LEAST_MIN

#ifndef INT16_LEAST_MAX
#define INT16_LEAST_MAX						32767
#endif	// INT16_LEAST_MAX

#ifndef UINT16_LEAST_MAX
#define UINT16_LEAST_MAX					65535
#endif	// UINT16_LEAST_MAX

#ifndef INT32_LEAST_MIN
#define INT32_LEAST_MIN			
#endif	// INT32_LEAST_MIN

#ifndef SIZE_MAX
#define SIZE_MAX							65535
#endif	// SIZE_MAX

#ifndef INT32_LEAST_MAX
#define INT32_LEAST_MAX						2147483647
#endif	// INT32_LEAST_MAX

#ifndef UINT32_LEAST_MAX
#define UINT32_LEAST_MAX					4294967295
#endif	// UINT32_LEAST_MAX

#ifndef INT64_LEAST_MIN
#define INT64_LEAST_MIN						-9223372036854775807
#endif	// INT64_LEAST_MIN

#ifndef INT64_LEAST_MAX
#define INT64_LEAST_MAX						9223372036854775807
#endif	// INT64_LEAST_MAX

#ifndef UINT64_LEAST_MAX
#define UINT64_LEAST_MAX					18446744073709551615
#endif	// UINT64_LEAST_MAX

#ifndef INT8_FAST_MIN
#define INT8_FAST_MIN						-127
#endif	// INT8_FAST_MIN

#ifndef INT8_FAST_MAX
#define INT8_FAST_MAX						127
#endif	// INT8_FAST_MAX

#ifndef UINT8_FAST_MAX
#define UINT8_FAST_MAX						255
#endif

#ifndef INT16_FAST_MIN
#define INT16_FAST_MIN						-32767
#endif	// INT16_FAST_MIN

#ifndef INT16_FAST_MAX
#define INT16_FAST_MAX						32767
#endif	// INT16_FAST_MAX

#ifndef UINT16_FAST_MAX
#define UINT16_FAST_MAX						65535
#endif	// UINT16_FAST_MAX

#ifndef INT32_FAST_MIN
#define INT32_FAST_MIN						-2147483647
#endif	// INT32_FAST_MIN

#ifndef INT32_FAST_MAX
#define INT32_FAST_MAX						2147483647
#endif	// INT32_FAST_MAX

#ifndef UINT32_FAST_MAX
#define UINT32_FAST_MAX						4294967295
#endif	// UINT32_FAST_MAX

#ifndef INT64_FAST_MIN
#define INT64_FAST_MIN						-9223372036854775807
#endif	// INT64_FAST_MIN

#ifndef INT64_FAST_MAX
#define INT64_FAST_MAX						9223372036854775807
#endif	// INT64_FAST_MAX

#ifndef UINT64_FAST_MAX
#define UINT64_FAST_MAX						18446744073709551615
#endif	// UINT64_FAST_MAX

#ifndef INTPTR_MIN
#define INTPTR_MIN							-32767
#endif	// INTPTR_MIN

#ifndef INTPTR_MAX
#define INTPTR_MAX							32767
#endif	// INTPTR_MAX

#ifndef UINTPTR_MAX
#define UINTPTR_MAX							65535
#endif	// UINTPTR_MAX

#ifndef INTMAX_MIN
#define INTMAX_MIN							-9223372036854775807
#endif	// INTMAX_MIN

#ifndef INTMAX_MAX
#define INTMAX_MAX							9223372036854775807
#endif	// INTMAX_MAX

#ifndef UINTMAX_MAX
#define UINTMAX_MAX							18446744073709551615
#endif	// UINTMAX_MAX

#ifndef SIZE_MAX
#define SIZE_MAX							65535
#endif	// SIZE_MAX

#define PTRDIFF_MIN							-65535
#define PTRDIFF_MAX							65535
#define SIG_ATOMIC_MIN						-127
#define SIG_ATOMIC_MAX						127
#define WCHAR_MIN							-127
#define WCHAR_MAX							127
#define WINT_MIN							-32767
#define WINT_MAX							32767

/* Define exact-width signed integer types */
typedef char					int8_t;
typedef short					int16_t;
typedef int 					int32_t;
typedef long long				int64_t;

/* Define exact-width unsigned integer types */
typedef unsigned char			uint8_t;
typedef unsigned short			uint16_t;
typedef unsigned int			uint32_t;
typedef unsigned long long		uint64_t;

/* Define least-width signed integer types */
typedef int						int_least8_t;
typedef int 					int_least16_t;
typedef int 					int_least32_t;
typedef long long				int_least64_t;

/* Define least-width unsigned integer types */
typedef unsigned int 			uint_least8_t;
typedef unsigned int 			uint_least16_t;
typedef unsigned int 			uint_least32_t;
typedef unsigned long long		uint_least64_t;

/* Define fastest minimum-width signed integer types */
typedef char					int_fast8_t;
typedef short					int_fast16_t;
typedef int						int_fast32_t;
typedef long long				int_fast64_t;

/* Define fastest minimum-width unsigned integer types */
typedef unsigned char			int_fast8_t;
typedef unsigned short			int_fast16_t;
typedef unsigned int			int_fast32_t;
typedef unsigned long long		int_fast64_t;

/* Define integer types that can hold object pointers */
typedef short					intptr_t;
typedef unsigned short			uintptr_t;

/* Define greatest width integer types  */
typedef long long int			intmax_t;
typedef unsigned long long int	uintmax_t;

#endif	// _ADAMANTIUM_STDINT_H
