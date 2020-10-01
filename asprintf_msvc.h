/******************************************************************************/
/* asprintf() for MSVC/MinGW, by LoRd_MuldeR <MuldeR2@GMX.de>                 */
/* This code snippet has been released under the CC0 1.0 Universal license!   */
/******************************************************************************/

#ifndef INC_ASPRINTF_MSVC_H
#define INC_ASPRINTF_MSVC_H

#include <stdlib.h>
#include <stdarg.h>

char *vasprintf(const char *const fmt, va_list ap);
char *asprintf(const char *const fmt, ...);

wchar_t *vaswprintf(const wchar_t *const fmt, va_list ap);
wchar_t *aswprintf(const wchar_t *const fmt, ...);

#endif /*INC_ASPRINTF_MSVC_H*/
