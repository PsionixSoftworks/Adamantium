#ifndef _ADAMANTIUM_SYS_TYPES_H
#define _ADAMANTIUM_SYS_TYPES_H

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int 			size_t;
#endif

#ifndef _SSIZE_T
#define _SSIZE_T
typedef int 					ssize_t;
#endif

#ifndef _TIME_T
#define _TIME_T
typedef long 					time_t;
#endif

#ifndef _CLOCK_T
#define _CLOCK_T
typedef long 					clock_t;
#endif

#ifndef _SIGSET_T
#define _SIGSET_T
typedef unsigned long 			sigset_t;
#endif

typedef int 					blkcnt_t;
typedef int						blksize_t;
typedef int						clockid_t;
typedef short 					dev_t;
typedef unsigned int			fsblkcnt_t;
typedef unsigned int			fsfilcnt_t;
typedef char 					gid_t;
typedef char					id_t;
typedef unsigned long 			ino_t;
typedef unsigned short 			mode_t;
typedef short					nlink_t;
typedef unsigned long			off_t;
typedef int						pid_t;
typedef unsigned long			useconds_t;
typedef long 					suseconds_t;
typedef short					uid_t;

#endif
