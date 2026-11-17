/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */
#ifndef SPL_ERR_H
#define SPL_ERR_H

#include "stack_types.h"
#ifdef __cplusplus
extern "C" {
#endif

#define SPL_EPERM 1            /* Operation not permitted */
#define SPL_ENOENT 2           /* No such file or directory */
#define SPL_ESRCH 3            /* No such process */
#define SPL_EINTR 4            /* Interrupted system call */
#define SPL_EIO 5              /* I/O error */
#define SPL_ENXIO 6            /* No such device or address */
#define SPL_E2BIG 7            /* Arg list too long */
#define SPL_ENOEXEC 8          /* Exec format error */
#define SPL_EBADF 9            /* Bad file number */
#define SPL_ECHILD 10          /* No child processes */
#define SPL_EAGAIN 11          /* Try again */
#define SPL_ENOMEM 12          /* Out of memory */
#define SPL_EACCES 13          /* Permission denied */
#define SPL_EFAULT 14          /* Bad address */
#define SPL_ENOTBLK 15         /* Block device required */
#define SPL_EBUSY 16           /* Device or resource busy */
#define SPL_EEXIST 17          /* File exists */
#define SPL_EXDEV 18           /* Cross-device link */
#define SPL_ENODEV 19          /* No such device */
#define SPL_ENOTDIR 20         /* Not a directory */
#define SPL_EISDIR 21          /* Is a directory */
#define SPL_EINVAL 22          /* Invalid argument */
#define SPL_ENFILE 23          /* File table overflow */
#define SPL_EMFILE 24          /* Too many open files */
#define SPL_ENOTTY 25          /* Not a typewriter */
#define SPL_ETXTBSY 26         /* Text file busy */
#define SPL_EFBIG 27           /* File too large */
#define SPL_ENOSPC 28          /* No space left on device */
#define SPL_ESPIPE 29          /* Illegal seek */
#define SPL_EROFS 30           /* Read-only file system */
#define SPL_EMLINK 31          /* Too many links */
#define SPL_EPIPE 32           /* Broken pipe */
#define SPL_EDOM 33            /* Math argument out of domain of func */
#define SPL_ERANGE 34          /* Math result not representable */
#define SPL_EDEADLK 35         /* Resource deadlock would occur */
#define SPL_ENAMETOOLONG 36    /* File name too long */
#define SPL_ENOLCK 37          /* No stored locks available */
#define SPL_ENOSYS 38          /* Function not implemented */
#define SPL_ENOTEMPTY 39       /* Directory not empty */
#define SPL_ELOOP 40           /* Too many symbolic links encountered */
#define SPL_EWOULDBLOCK SPL_EAGAIN /* Operation would block */
#define SPL_ENOMSG 42          /* No message of desired type */
#define SPL_EIDRM 43
#define SPL_ECHRNG 44          /* Channel number out of range */
#define SPL_EL2NSYNC 45        /* Level 2 not synchronized */
#define SPL_EL3HLT 46          /* Level 3 halted */
#define SPL_EL3RST 47          /* Level 3 reset */
#define SPL_ELNRNG 48          /* Link number out of range */
#define SPL_EUNATCH 49         /* Protocol driver not attached */
#define SPL_ENOCSI 50          /* No CSI structure available */
#define SPL_EL2HLT 51          /* Level 2 halted */
#define SPL_EBADE 52           /* Invalid exchange */
#define SPL_EBADR 53           /* Invalid request descriptor */
#define SPL_EXFULL 54          /* Exchange full */
#define SPL_ENOANO 55          /* No anode */
#define SPL_EBADRQC 56         /* Invalid request code */
#define SPL_EBADSLT 57         /* Invalid slot */
#define SPL_EDEADLOCK SPL_EDEADLK
 
#define SPL_EBFONT 59          /* Bad font file format */
#define SPL_ENOSTR 60          /* Device not a stream */
#define SPL_ENODATA 61         /* No data available */
#define SPL_ETIME 62           /* Timer expired */
#define SPL_ENOSR 63           /* Out of streams resources */
#define SPL_ENONET 64          /* Machine is not on the network */
#define SPL_ENOPKG 65          /* Package not installed */
#define SPL_EREMOTE 66         /* Object is remote */
#define SPL_ENOLINK 67         /* Link has been severed */
#define SPL_EADV 68            /* Advertise error */
#define SPL_ESRMNT 69          /* Srmount error */
#define SPL_ECOMM 70           /* Communication error on send */
#define SPL_EPROTO 71          /* Protocol error */
#define SPL_EMULTIHOP 72       /* Multihop attempted */
#define SPL_EDOTDOT 73         /* RFS specific error */
#define SPL_EBADMSG 74         /* Not a data message */
#define SPL_EOVERFLOW 75       /* Value too large for defined data type */
#define SPL_ENOTUNIQ 76        /* Name not unique on network */
#define SPL_EBADFD 77          /* File descriptor in bad state */
#define SPL_EREMCHG 78         /* Remote address changed */
#define SPL_ELIBACC 79         /* Can not access a needed shared library */
#define SPL_ELIBBAD 80         /* Accessing a corrupted shared library */
#define SPL_ELIBSCN 81         /* .lib section in a.out corrupted */
#define SPL_ELIBMAX 82         /* Attempting to link in too many shared libraries */
#define SPL_ELIBEXEC 83        /* Cannot exec a shared library directly */
#define SPL_EILSEQ 84          /* Illegal byte sequence */
#define SPL_ERESTART 85        /* Interrupted system call should be restarted */
#define SPL_ESTRPIPE 86        /* Streams pipe error */
#define SPL_EUSERS 87          /* Too many users */
#define SPL_ENOTSOCK 88        /* Socket operation on non-socket */
#define SPL_EDESTADDRREQ 89    /* Destination address required */
#define SPL_EMSGSIZE 90        /* Message too long */
#define SPL_EPROTOTYPE 91      /* Protocol wrong type for socket */
#define SPL_ENOPROTOOPT 92     /* Protocol not available */
#define SPL_EPROTONOSUPPORT 93 /* Protocol not supported */
#define SPL_ESOCKTNOSUPPORT 94 /* Socket type not supported */
#define SPL_EOPNOTSUPP 95      /* Operation not supported on transport endpoint */
#define SPL_EPFNOSUPPORT 96    /* Protocol family not supported */
#define SPL_EAFNOSUPPORT 97    /* Address family not supported by protocol */
#define SPL_EADDRINUSE 98      /* Address already in use */
#define SPL_EADDRNOTAVAIL 99   /* Cannot assign requested address */
#define SPL_ENETDOWN 100       /* Network is down */
#define SPL_ENETUNREACH 101    /* Network is unreachable */
#define SPL_ENETRESET 102      /* Network dropped connection because of reset */
#define SPL_ECONNABORTED 103   /* Software caused connection abort */
#define SPL_ECONNRESET 104     /* Connection reset by peer */
#define SPL_ENOBUFS 105        /* No buffer space available */
#define SPL_EISCONN 106        /* Transport endpoint is already connected */
#define SPL_ENOTCONN 107       /* Transport endpoint is not connected */
#define SPL_ESHUTDOWN 108      /* Cannot send after transport endpoint shutdown */
#define SPL_ETOOMANYREFS 109   /* Too many references: cannot splice */
#define SPL_ETIMEDOUT 110      /* Connection timed out */
#define SPL_ECONNREFUSED 111   /* Connection refused */
#define SPL_EHOSTDOWN 112      /* Host is down */
#define SPL_EHOSTUNREACH 113   /* No route to host */
#define SPL_EALREADY 114       /* Operation already in progress */
#define SPL_EINPROGRESS 115    /* Operation now in progress */
#define SPL_ESTALE 116         /* Stale NFS file handle */
#define SPL_EUCLEAN 117        /* Structure needs cleaning */
#define SPL_ENOTNAM 118        /* Not a XENIX named type file */
#define SPL_ENAVAIL 119        /* No XENIX semaphores available */
#define SPL_EISNAM 120         /* Is a named type file */
#define SPL_EREMOTEIO 121      /* Remote I/O error */
#define SPL_EDQUOT 122         /* Quota exceeded */
#define SPL_ENOMEDIUM 123   /* No medium found */
#define SPL_EMEDIUMTYPE 124 /* Wrong medium type */

#define SPL_ENSROK 0
#define SPL_ENSRNODATA 160
#define SPL_ENSRFORMERR 161
#define SPL_ENSRSERVFAIL 162
#define SPL_ENSRNOTFOUND 163
#define SPL_ENSRNOTIMP 164
#define SPL_ENSRREFUSED 165
#define SPL_ENSRBADQUERY 166
#define SPL_ENSRBADNAME 167
#define SPL_ENSRBADFAMILY 168
#define SPL_ENSRBADRESP 169
#define SPL_ENSRCONNREFUSED 170
#define SPL_ENSRTIMEOUT 171
#define SPL_ENSROF 172
#define SPL_ENSRFILE 173
#define SPL_ENSRNOMEM 174
#define SPL_ENSRDESTRUCTION 175
#define SPL_ENSRQUERYDOMAINTOOLONG 176
#define SPL_ENSRCNAMELOOP 177
#define SPL_OPTION_DEG 200
#define SPL_ERESTARTSYS    512

#define SPL_ERR_PCB_FREED 3   /* No error, but pcb is freed, cann't be use later. */
#define SPL_ERR_STORED_OK 2   /* No error, but sbuf has stored somewhere, will be used later. */
#define SPL_ERR_NO_EAT_OK 1   /* No error, but caller need to free sbuf. */

#define SPL_ERR_CLOSE_WAIT (-23) /* closed in established state */

static inline bool spl_err_is_fatal(err_t e)
{
    bool ret = false;
    if ((e == SPL_ERR_NO_EAT_OK) || (e == SPL_ERR_STORED_OK) || (e == SPL_ERR_PCB_FREED)) {
        return false;
    }
    switch (-e) {
        case 0:
            break;
        case SPL_ENOMEM:
            break;
        case SPL_ENOBUFS:
            break;
        case SPL_ETIMEDOUT:
            break;
        case SPL_EHOSTUNREACH:
            break;
        case SPL_EINPROGRESS:
            break;
        case SPL_EINVAL:
            break;
        case SPL_EWOULDBLOCK:
            break;
        case SPL_EADDRINUSE:
            break;
        case SPL_EISCONN:
            break;
        default:
            ret = true;
            break;
    }

    return ret;
}


#ifdef __cplusplus
}
#endif

#endif
