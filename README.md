**An implementation of the `asprintf()` family of functions for MSVC and MinGW**

```
#include "asprintf_msvc.h"
#include <stdio.h>

int main(void)
{
	char *test;
	wchar_t *wtest;

	if((test = asprintf("%s %s? 0x%I64X\n", "lorem", "ipsum", 0xDEADBEEFCAFEBABEui64)))
	{
		fputs(test, stderr);
		free(test);
	}

	if((wtest = aswprintf(L"%s %s? 0x%I64X\n", L"lorem", L"ipsum", 0xDEADBEEFCAFEBABEui64)))
	{
		fputws(wtest, stderr);
		free(wtest);
	}
}
```
