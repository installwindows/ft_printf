/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 18:27:05 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/12 16:51:53 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int		main(void)
{
	//setlocale(LC_ALL, "");
	goto p;

	/* p */
p:
	{
		printf("%d\n", printf   ("printf...: |%-15p| r:", 0));
		printf("%d\n", ft_printf("ft_printf: |%-15p| r:", 0));
		goto exit;
	}

	/* z length modifier tests */
z:	
	{
		printf("%d\n", printf   ("printf...: |%zu, %zu| r:", 0, ULLONG_MAX));
		printf("%d\n", ft_printf("ft_printf: |%zu, %zu| r:", 0, ULLONG_MAX));

		printf("%d\n", printf   ("printf...: |%zo, %zo| r:", 0, ULLONG_MAX));
		printf("%d\n", ft_printf("ft_printf: |%zo, %zo| r:", 0, ULLONG_MAX));

		goto exit;
	}
	
	/* c conversion */
c:	
	{
		printf("%d\n", printf   ("printf...: |% c| r:", 'a'));
		printf("%d\n", ft_printf("ft_printf: |% c| r:", 'a'));
		goto exit;
	}

	/* d conversion */
d:
	{
		printf("%d\n", printf   ("printf...: |%hhO| r:", USHRT_MAX));
		printf("%d\n", ft_printf("ft_printf: |%hhO| r:", USHRT_MAX));
		goto exit;
	}

	/* errors */
err:
	{
		printf("%d\n", printf   ("|%+d|", -42));
		printf("%d\n", ft_printf("|%+d|", -42));
		goto exit;
	}

	/* mix */
mix:
	{
		printf("%d\n", printf   ("printf...: |%s %C %d %p %x %% %S| r:", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
		printf("%d\n", ft_printf("ft_printf: |%s %C %d %p %x %% %S| r:", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
		goto exit;
	}
	/* tests */
test:
	{
		char	*test = "derp";
		printf("... %03c\n", 0);
		goto exit;
	}
exit:
	return (0);
}
