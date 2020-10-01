/******************************************************************************/
/* asprintf() for MSVC/MinGW, by LoRd_MuldeR <MuldeR2@GMX.de>                 */
/* This code snippet has been released under the CC0 1.0 Universal license!   */
/******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS /*stfu*/
#include <stdio.h>
#include "asprintf_msvc.h"

char *vasprintf(const char *const fmt, va_list ap)
{
	int result;
	char *buffer;

	const int str_len = _vscprintf(fmt, ap);
	if (str_len < 1)
	{
		return NULL;
	}

	if (!(buffer = (char*) malloc(sizeof(char) * (((size_t)str_len) + 1U))))
	{
		return NULL;
	}

	if ((result = _vsnprintf(buffer, ((size_t)str_len) + 1U, fmt, ap)) < 1)
	{
		free(buffer);
		buffer = NULL;
	}

	return buffer;
}

char *asprintf(const char *const fmt, ...)
{
	char *buffer;

	va_list ap;
	va_start(ap, fmt);

	buffer = vasprintf(fmt, ap);

	va_end(ap);
	return buffer;
}

wchar_t *vaswprintf(const wchar_t *const fmt, va_list ap)
{
	int result;
	wchar_t *buffer;

	const int str_len = _vscwprintf(fmt, ap);
	if (str_len < 1)
	{
		return NULL;
	}

	if (!(buffer = (wchar_t*) malloc(sizeof(wchar_t) * (((size_t)str_len) + 1U))))
	{
		return NULL;
	}

	if ((result = _vsnwprintf(buffer, ((size_t)str_len) + 1U, fmt, ap)) < 1)
	{
		free(buffer);
		buffer = NULL;
	}

	return buffer;
}

wchar_t *aswprintf(const wchar_t *const fmt, ...)
{
	wchar_t *buffer;

	va_list ap;
	va_start(ap, fmt);

	buffer = vaswprintf(fmt, ap);

	va_end(ap);
	return buffer;
}
