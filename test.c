#include <stdio.h>
#include <unistd.h>

int		main(void)
{
	char	*p;
	char	c = 'c';

	p = &c;
	printf("%lli\n", (long long)p);
	//write(1, "\033[22;34mAyy \033[0mLamo\n", 21);
	//printf("\033[22;34m%d %d\033[0m\n", 50, 100);
}