/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:06:45 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/16 23:39:15 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

void	d_conversion(t_flags *flags, va_list *args)
{
	int		d;
	char	*n;
	char	*tmp;
	int		len;

	d = va_arg(*args, int);
	len = ft_intlen(d);
	tmp = flags->precision == 0 && d == 0 ? ft_strnew(0) : ft_itoa(d);
	if (flags->zero)
		if (d < 0 && len--)
			ft_putchar('-');
	tmp = ft_itoa(d);
	handle_field(flags, tmp + (d < 0 && flags->zero), flags->zero &&
			!(d == 0 && flags->precision == 0) ? '0' : ' ');
	free(tmp);
}
