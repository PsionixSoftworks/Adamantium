#ifndef _ADAMANTIUM_ERRNO_H
#define _ADAMANTIUM_ERRNO_H					1

/* Define the header guard here just in case */
#define _ERRNO_H							1

// The 'errno' value is used to tell the system what error has occured. It is defined in kernel.c:
extern int errno;

/* 
 * Common errno values go here. They may be changed at some point and organized into categories
 * but for now, we just need them in the system. It's important we have these because they are 
 * not just limited to protected mode. They can/will also be used in user mode. The reason they
 * are in an enum instead of the way it is normally done, is because it's faster and easier to
 * write them. Plus the POSIX standard doesn't specify whether the values are a macro or an
 * identifier. So we'll go with an unnamed enum for now.
 */

#define _NUM_ERROR							ERRNUM		// At this time _NUM_ERROR=81;

enum
{
	E2BIG=0x01,
	EACCESS,
	EADDRINUSE,
	EADDRNOTAVAIL,
	EAFNOSUPPORT,
	EAGAIN,
	EALREADY,
	EBADF,
	EBADMSG,
	EBUSY,
	ECANCELED,
	ECHILD,
	ECONNABORTED,
	ECONNREFUSED,
	ECONNRESET,
	EDEADLK,
	EDESTADDRREQ,
	EDOM,
	EDQUOT,
	EEXIST,
	EFAULT,
	EFBIG,
	EHOSTUNREACH,
	EIDRM,
	EILSEQ,
	EINPROGRESS,
	EINTR,
	EINVAL,
	EIO,
	EISCONN,
	EISDIR,
	ELOOP,
	EMFILE,
	EMLINK,
	EMSGSIZE,
	EMULTIHOP,
	ENAMETOOLONG,
	ENETDOWN,
	ENETRESET,
	ENETUNREACH,
	ENFILE,
	ENOBUFS,
	ENODATA,
	ENODEV,
	ENOENT,
	ENOEXEC,
	ENOLCK,
	ENOLINK,
	ENOMEM,
	ENOMSG,
	ENOPROTOOPT,
	ENOSPC,
	ENOSR,
	ENOSYS,
	ENOTCONN,
	ENOTDIR,
	ENOTEMPTY,
	ENOTRECOVERABLE,
	ENOTSOCK,
	ENOTSUP,
	ENOTTY,
	ENXIO,
	EOPNOTSUPP,
	EOVERFLOW,
	EOWNERDEAD,
	EPERM,
	EPIPE,
	EPROTO,
	EPROTONOSUPPORT,
	EPROTOTYPE,
	ERANGE,
	EROFS,
	ESPIPE,
	ESRCH,
	ESTALE,
	ETIME,
	ETIMEDOUT,
	ETXTBSY,
	EWOULDBLOCK,
	EXDEV,

	ERRNUM,
};

#endif
