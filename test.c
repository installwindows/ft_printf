#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	wchar_t		*wc_str = L"ß水🍌";
	mbstate_t	mbstate;
	char		mb_str[4];
	size_t		size = 0;
	int			n = 0;

	setlocale(LC_ALL, "");
	//memset(&mbstate, 0, sizeof(mbstate));
	//size = wcrtomb(&mb_str, *wc_str, &mbstate);

	//printf("%ls\n", wc_str);
	//printf("%c", mb_str);
	//printf("%d", sizeof(wchar_t));
	while (*wc_str)
	{
		size = wcrtomb(mb_str, *wc_str, NULL);
		write(1, mb_str, size);
		wc_str++;
	}
	//printf("%10s\n", "abc");
	//n = printf("%.9ls\n", wc_str);
	//printf("%d sizeof %d\n", n, sizeof(wc_str));
}
