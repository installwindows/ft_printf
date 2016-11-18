/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 18:27:05 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/17 22:43:21 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int		main(void)
{
	int		n = 0;
	int		d = -42;

	printf("|%#010x|\n", 42);
	ft_printf("|%#010x|\n", 42);
	printf("|%+04.d|\n", n);
	ft_printf("|%+04.d|\n", n);
	printf("|%+04.d|\n", d);
	ft_printf("|%+04.d|\n", d);
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
