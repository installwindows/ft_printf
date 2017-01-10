/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:06:45 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/09 21:58:17 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		d_conversion(t_flags *flags, va_list *args)
{
	long long	d;

	if (flags->f & F_PRECISION && flags->precision >= 0)
		flags->f ^= F_ZERO;
	if (flags->f & F_HH)
		d = va_arg(*args, char);
	else if (flags->f & F_H)
		d = va_arg(*args, short int);
	else if (flags->f & F_L)
		d = va_arg(*args, long int);
	else if (flags->f & F_LL)
		d = va_arg(*args, long long int);
	else if (flags->f & F_J)
		d = va_arg(*args, intmax_t);
	else if (flags->f & F_Z)
		d = va_arg(*args, size_t);
	else
		d = va_arg(*args, int);
	return (handle_signed_number(d, flags));
}
