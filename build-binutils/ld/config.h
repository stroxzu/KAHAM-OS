/* config.h.  Generated from config.in by configure.  */
/* config.in.  Generated from configure.ac by autoheader.  */

/* Check that config.h is #included before system headers
   (this works only for glibc, but that should be enough).  */
#if defined(__GLIBC__) && !defined(__FreeBSD_kernel__) && !defined(__CONFIG_H__)
#  error config.h must be #included before system headers
#endif
#define __CONFIG_H__ 1

/* Default compression algorithm for --enable-compressed-debug-sections. */
#define DEFAULT_COMPRESSED_DEBUG_ALGORITHM COMPRESS_DEBUG_GABI_ZLIB

/* Define to 1 if you want to emit gnu hash in the ELF linker by default. */
#define DEFAULT_EMIT_GNU_HASH 0

/* Define to 1 if you want to emit sysv hash in the ELF linker by default. */
#define DEFAULT_EMIT_SYSV_HASH 1

/* Define if you want compressed debug sections by default. */
/* #undef DEFAULT_FLAG_COMPRESS_DEBUG */

/* Define to 1 if you want to turn executable stack warnings into errors by
   default. */
#define DEFAULT_LD_ERROR_EXECSTACK 0

/* Define to 1 if you want to turn executable segment warnings into errors by
   default. */
#define DEFAULT_LD_ERROR_RWX_SEGMENTS 0

/* Define to 0 if you want to disable the generation of an executable stack
   when a .note-GNU-stack section is missing. */
#define DEFAULT_LD_EXECSTACK 1

/* The default method for DT_TEXTREL check in ELF linker. */
#define DEFAULT_LD_TEXTREL_CHECK textrel_check_none

/* Define to 1 if DT_TEXTREL check is warning in ELF linker by default. */
#define DEFAULT_LD_TEXTREL_CHECK_WARNING 0

/* Define to 1 if you want to enable --warn-execstack in ELF linker by
   default. */
#define DEFAULT_LD_WARN_EXECSTACK 2

/* Define to 0 if you want to disable --warn-rwx-segments in ELF linker by
   default. */
#define DEFAULT_LD_WARN_RWX_SEGMENTS 1

/* Define to 1 if you want to enable -z mark-plt in ELF x86-64 linker by
   default. */
#define DEFAULT_LD_Z_MARK_PLT 0

/* Define to 1 if you want to enable -z relro in ELF linker by default. */
#define DEFAULT_LD_Z_RELRO 0

/* Define to 1 if you want to enable -z separate-code in ELF linker by
   default. */
#define DEFAULT_LD_Z_SEPARATE_CODE 0

/* Define to 1 if you want to set DT_RUNPATH instead of DT_RPATH by default.
   */
#define DEFAULT_NEW_DTAGS 0

/* Define if you want run-time sanity checks. */
/* #undef ENABLE_CHECKING */

/* Handle .ctf type-info sections */
#define ENABLE_LIBCTF 1

/* Define to 1 if translation of program messages to the user's native
   language is requested. */
/* #undef ENABLE_NLS */

/* Additional extension a shared object might have. */
/* #undef EXTRA_SHLIB_EXTENSION */

/* Define to choose default GOT handling scheme */
#define GOT_HANDLING_DEFAULT GOT_HANDLING_TARGET_DEFAULT

/* Define to 1 if you have the Mac OS X function
   CFLocaleCopyPreferredLanguages in the CoreFoundation framework. */
/* #undef HAVE_CFLOCALECOPYPREFERREDLANGUAGES */

/* Define to 1 if you have the Mac OS X function CFPreferencesCopyAppValue in
   the CoreFoundation framework. */
/* #undef HAVE_CFPREFERENCESCOPYAPPVALUE */

/* Define to 1 if you have the `close' function. */
#define HAVE_CLOSE 1

/* Define if the GNU dcgettext() function is already present or preinstalled.
   */
/* #undef HAVE_DCGETTEXT */

/* Define to 1 if you have the declaration of `asprintf', and to 0 if you
   don't. */
#define HAVE_DECL_ASPRINTF 1

/* Define to 1 if you have the declaration of `environ', and to 0 if you
   don't. */
#define HAVE_DECL_ENVIRON 1

/* Is the prototype for getopt in <unistd.h> in the expected format? */
#define HAVE_DECL_GETOPT 1

/* Define to 1 if you have the declaration of `stpcpy', and to 0 if you don't.
   */
#define HAVE_DECL_STPCPY 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <elf-hints.h> header file. */
/* #undef HAVE_ELF_HINTS_H */

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the `getpagesize' function. */
#define HAVE_GETPAGESIZE 1

/* Define if the GNU gettext() function is already present or preinstalled. */
/* #undef HAVE_GETTEXT */

/* Define to 1 if you have the `glob' function. */
#define HAVE_GLOB 1

/* Define if you have the iconv() function and it works. */
/* #undef HAVE_ICONV */

/* Define .init_array/.fini_array sections are available and working. */
#define HAVE_INITFINI_ARRAY 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* The jansson library is to be used */
/* #undef HAVE_JANSSON */

/* Define if your <locale.h> file defines LC_MESSAGES. */
#define HAVE_LC_MESSAGES 1

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define to 1 if you have the `lseek' function. */
#define HAVE_LSEEK 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `mkstemp' function. */
#define HAVE_MKSTEMP 1

/* Define to 1 if you have a working `mmap' system call. */
#define HAVE_MMAP 1

/* Define to 1 if you have the `open' function. */
#define HAVE_OPEN 1

/* Define to 1 if you have the `realpath' function. */
#define HAVE_REALPATH 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/file.h> header file. */
#define HAVE_SYS_FILE_H 1

/* Define to 1 if you have the <sys/mman.h> header file. */
#define HAVE_SYS_MMAN_H 1

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the `waitpid' function. */
#define HAVE_WAITPID 1

/* Define to 1 if you have the <windows.h> header file. */
/* #undef HAVE_WINDOWS_H */

/* Define to 1 if zstd is enabled. */
/* #undef HAVE_ZSTD */

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Name of package */
#define PACKAGE "ld"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "ld"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "ld 2.42"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "ld"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "2.42"

/* The size of `void *', as computed by sizeof. */
#define SIZEOF_VOID_P 8

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if you want to support the --error-handling-script command line
   option. */
#define SUPPORT_ERROR_HANDLING_SCRIPT 1

/* Use b modifier when opening binary files? */
/* #undef USE_BINARY_FOPEN */

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif


/* Version number of package */
#define VERSION "2.42"

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
#define YYTEXT_POINTER 1

/* Enable large inode numbers on Mac OS X 10.5.  */
#ifndef _DARWIN_USE_64_BIT_INODE
# define _DARWIN_USE_64_BIT_INODE 1
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* Define to 1 if on MINIX. */
/* #undef _MINIX */

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
/* #undef _POSIX_1_SOURCE */

/* Define to 1 if you need to in order for `stat' and other things to work. */
/* #undef _POSIX_SOURCE */
