/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:10:20 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/10 23:54:36 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <wchar.h>
#include "libft.h"
#include "ft_printf.h"

int		c_conversion(t_flags *flags, va_list *args)
{
	char	c[2];
	wchar_t	wc[2];
	int		nbprint;

	nbprint = 0;
	if (flags->f & F_L)
	{
		wc[0] = va_arg(*args, wchar_t);
		wc[1] = '\0';
		nbprint += handle_wcstr(flags, wc);
		if (wc[0] == 0)
			nbprint++;
	}
	else
	{
		c[0] = va_arg(*args, int);
		c[1] = '\0';
		nbprint += handle_string(flags, c, ' ');
		if (c[0] == 0)
			nbprint++;
	}
	return (nbprint);
}
