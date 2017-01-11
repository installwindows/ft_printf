/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 18:27:05 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/11 15:54:37 by varnaud          ###   ########.fr       */
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
	setlocale(LC_ALL, "");
	goto test;
	/* z length modifier tests */
z:	
	{
		printf("%d\n", printf   ("printf...: |%zu, %zu| r:", 0, ULLONG_MAX));
		printf("%d\n", ft_printf("ft_printf: |%zu, %zu| r:", 0, ULLONG_MAX));

		printf("%d\n", printf   ("printf...: |%zo, %zo| r:", 0, ULLONG_MAX));
		printf("%d\n", ft_printf("ft_printf: |%zo, %zo| r:", 0, ULLONG_MAX));

		return (0);
	}
	
	/* c conversion */
c:	
	{
		printf("%d\n", printf   ("printf...: |%3c| r:", 0));
		printf("%d\n", ft_printf("ft_printf: |%3c| r:", 0));
		return (0);
	}

	/* d conversion */
d:
	{
		printf("%d\n", printf   ("printf...: |%hhO| r:", USHRT_MAX));
		printf("%d\n", ft_printf("ft_printf: |%hhO| r:", USHRT_MAX));
		return (0);
	}

	/* errors */
err:
	{
		printf("%d\n", printf   ("|%+d|", -42));
		printf("%d\n", ft_printf("|%+d|", -42));
		return (0);
	}

	/* mix */
mix:
	{
		printf("%d\n", printf   ("printf...: |%s %C %d %p %x %% %S| r:", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
		printf("%d\n", ft_printf("ft_printf: |%s %C %d %p %x %% %S| r:", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
		return (0);
	}
	/* tests */
test:
	{
		char	*test = "derp";
		printf("... %.0p %.p\n", 0, 0);
		ft_printf("ft: %.0p %.p\n", 0, 0);
		return (0);
	}

	/*
	setlocale(LC_ALL, "");
	int		r = 0;
	int		n = 97;
	int		d = -42;
	wchar_t	*wcstr = L"こんにちはお元気ですか";
	wchar_t	*wcstr2 = L"שלום עולם";

	r = printf   ("printf...: |%ls| r: ", wcstr);
	printf("%d\n", r);
	r = ft_printf("ft_printf: |%ls| r: ", wcstr);
	printf("%d\n", r);
	r = printf   ("printf...: |%-40ls| r: ", wcstr2);
	printf("%d\n", r);
	r = ft_printf("ft_printf: |%-40ls| r: ", wcstr2);
	printf("%d\n", r);


	
	printf("%d\n", printf   ("printf...: |%10s| r:", 0));
	printf("%d\n", ft_printf("ft_printf: |%10s| r:", 0));

	printf("%d\n", printf   ("printf...: |%-5.4d| r:", -42));
	printf("%d\n", ft_printf("ft_printf: |%-5.4d| r:", -42));

	*/
	//printf("%S", L"米");

	//printf("|%-5.4ld|\n", 42);
	//ft_printf("|%-5.4ld|\n", 42);

	//printf("|%s|\n", s);
	//ft_printf("|%s|\n", s);
	//printf("|%4c|\n", n);
	//ft_printf("|%4c|\n", n);
	//printf("|%#010X|\n", 42);
	//ft_printf("|%#010X|\n", 42);
	//printf("|%+04.d|\n", n);
	//ft_printf("|%+04.d|\n", n);
	//printf("|%+04.d|\n", d);
	//ft_printf("|%+04.d|\n", d);
	//ft_printf("|%15d|...|%p|\n", "Hello World", &n);
	//printf("|%15d|...|%p|\n", "Hello World", &n);
	//ft_printf("%s...%s...%s...", "Hello", "world", "!");
	//ft_printf("%#10ld...%s...%010.5hhc...%%");
	//printf("|%-20.20s|\n", "Ayylmao");
	//printf("|%-40.5s|\n", "Hello world");
	//printf("|%.40s|\n", "Hello world");
	//printf("|%.s|\n", "Hello world");
	//printf("|%S|", L"ο Δικαιοπολις εν αγρω εστιν");
/*
	{
		int		*i;
		int		j = 42;
		i = &j;
		printf("%p\n", i);
		ft_putnbr_base((long long)i, 16);
	}
*/

}
