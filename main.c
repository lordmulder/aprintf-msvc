/******************************************************************************/
/* asprintf() for MSVC/MinGW, by LoRd_MuldeR <MuldeR2@GMX.de>                 */
/* This code snippet has been released under the CC0 1.0 Universal license!   */
/******************************************************************************/

#include "asprintf_msvc.h"
#include <stdio.h>

int main(void)
{
	char *test;
	wchar_t *wtest;

	if((test = asprintf("%s %s? 0x%I64X\n", "lorem", "ipsum", 0xDEADBEEFCAFEBABEull)))
	{
		fputs(test, stderr);
		free(test);
	}

	if((wtest = aswprintf(L"%s %s? 0x%I64X\n", L"lorem", L"ipsum", 0xDEADBEEFCAFEBABEull)))
	{
		fputws(wtest, stderr);
		free(wtest);
	}
}
