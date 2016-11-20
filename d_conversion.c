/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:06:45 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/19 15:24:33 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		d_conversion(t_flags *flags, va_list *args)
{
	int		d;

	if (flags->precision >= 0)
		flags->zero = 0;
	d = va_arg(*args, int);
	return ((int)handle_num(d, 10, flags));
}
