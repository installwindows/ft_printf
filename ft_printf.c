/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 13:45:00 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/12 19:08:28 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

static int	read_args(char *format, va_list *args, int nbprint)
{
	char	*fmt;

	if ((fmt = ft_strchr(format, '%')) == NULL)
	{
		nbprint += ft_putstr(format);
		return (nbprint);
	}
	else
	{
		ft_putnstr(format, fmt - format);
		nbprint += fmt - format;
		fmt++;
		nbprint += print_arg(&fmt, args);
		format = fmt;
	}
	return (read_args(format, args, nbprint));
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	int			r;

	va_start(args, format);
	r = read_args((char*)format, &args, 0);
	va_end(args);
	return (r);
}
