#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
# define LARGEST(a, b) (a > b ? a : b)



char		*shiftdot(const char *n1, int by)
{
	char	*nodot;
	int		i;
	int		j;
	int		dot;

	dot = 0;
	nodot = malloc(ft_strlen(n1) + by + 1);
	i = 0;
	while (*n1)
	{
		if (*n1 != '.')
			nodot[i++] = *n1;
		else
			dot = i > 0 ? i - 1 : 1;
		n1++;
	}
	j = i - 1;
	while (j + dot++ < by)
		nodot[i++] = '0';
	nodot[i] = '\0';
	return (nodot);
}

char		*ft_bignum_mtp(const char *n1, const char *n2)
{
	int		d[ft_strlen(n1) + ft_strlen(n2)];
	int		i;
	int		j;
	char	*str;

	ft_memset(d, 0, (ft_strlen(n1) + ft_strlen(n2)) * sizeof(int));
	i = 0;
	while (i < (int)ft_strlen(n1))
	{
		j = 0;
		while (j < (int)ft_strlen(n2))
		{
			d[i + j] += ((n1[i] - '0') * (n2[j] - '0'));
			j++;
		}
		i++;
	}
	str = malloc(ft_strlen(n1) + ft_strlen(n2) + 1);
	ft_memset(str, 0, ft_strlen(n1) + ft_strlen(n2) + 1);
	i = 0;
	while (i < (int)(ft_strlen(n1) + ft_strlen(n2)))
	{
		if (i + 1 < (int)(ft_strlen(n1) + ft_strlen(n2)))
			d[i + 1] += d[i] / 10;
		str[i] = (d[i] % 10) + '0';
		i++;
	}
	//while (i > 0 && str[--i] == '0')
	//	str[i] = '\0';
	return (ft_strrev(str));
}

char		*mtp(const char *n1, const char *n2)
{
	char	*d1;
	char	*d2;
	char	*r;
	int		i;
	int		j;

	d1 = shiftdot(n1, LARGEST(ft_strichr(n1, '.'), ft_strichr(n2, '.')));
	d2 = shiftdot(n2, LARGEST(ft_strichr(n1, '.'), ft_strichr(n2, '.')));
	ft_strrev(d1);
	ft_strrev(d2);
	r = ft_bignum_mtp(d1, d2);
	free(d1);
	free(d2);
	d1 = malloc(ft_strlen(r) + 1);
	i = 0;
	j = 0;
	while (r[j])
	{
		if (i == LARGEST(ft_strichr(n1, '.'), ft_strichr(n2, '.')))
			d1[i] = '.';
		else
			d1[i] = r[j++];
		i++;
	}
	free(r);
	return (d1);
}
int		main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%s\n", mtp(argv[1], argv[2]));
	}
	if (argc == 2)
		printf("%s\n", shiftdot((argv[1]), 1));
}
