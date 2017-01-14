/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:41:40 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/13 21:05:01 by varnaud          ###   ########.fr       */
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
	
	printf("%d\n", ft_printf("ft_printf: |%b| r:", 93));
	printf("%d\n", printf   ("printf...: |%x| r:", 93));
	
}
