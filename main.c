/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 18:27:05 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/09 17:59:54 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <wchar.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int		main(void)
{
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


	printf("%#05x\n", 42);


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
