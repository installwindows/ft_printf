/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:41:40 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/13 20:18:22 by varnaud          ###   ########.fr       */
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
	
	printf("%d\n", ft_printf("ft_printf: |%+d| r:", 42));
	printf("%d\n", printf   ("printf...: |%+d| r:", 42));
	
}
