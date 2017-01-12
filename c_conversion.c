/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:10:20 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/11 17:55:07 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

int		handle_c(t_flags *f, char c)
{
	int		nbprint;

	nbprint = 0;
	if (f->f & F_MINUS)
	{
	}
	else
	{

	}
	return (nbprint);
}

int		handle_wc(t_flags *f, wchar_t wc)
{
	int		nbprint;

	nbprint = 0;
	return (nbprint);
}

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
