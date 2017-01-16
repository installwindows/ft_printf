/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:41:40 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/15 19:58:00 by varnaud          ###   ########.fr       */
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
	
	printf("%d\n", ft_printf("ft_printf: |%f| r:", 93.78));
	printf("%d\n", printf   ("printf...: |%f| r:", 93.78));
	printf("------------------------------------------------------------\n");	

	printf("%d\n", ft_printf("ft_printf: |%f| r:", -93.78));
	printf("%d\n", printf   ("printf...: |%f| r:", -93.78));
	printf("------------------------------------------------------------\n");	

	printf("%d\n", ft_printf("ft_printf: |%.15f| r:", 93.78));
	printf("%d\n", printf   ("printf...: |%.15f| r:", 93.78));
	printf("------------------------------------------------------------\n");	

	printf("%d\n", ft_printf("ft_printf: |%15f| r:", 93.78));
	printf("%d\n", printf   ("printf...: |%15f| r:", 93.78));
	printf("------------------------------------------------------------\n");	

	printf("%d\n", ft_printf("ft_printf: |%-15f| r:", 93.78));
	printf("%d\n", printf   ("printf...: |%-15f| r:", 93.78));
	printf("------------------------------------------------------------\n");	


	printf("%d\n", ft_printf("ft_printf: |%#f| r:", 0));
	printf("%d\n", printf   ("printf...: |%#f| r:", 0));
	printf("------------------------------------------------------------\n");	

	printf("%d\n", ft_printf("ft_printf: |{%f}{%F}| r:", 1.42, 1.42));
	printf("%d\n", printf   ("printf...: |{%f}{%F}| r:", 1.42, 1.42));
	printf("------------------------------------------------------------\n");	
}
