/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:08:05 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/19 15:50:36 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		o_conversion(t_flags *flags, va_list *args)
{
	int		d;

	d = va_arg(*args, int);
	return ((int)handle_num(d, 8, flags));
}
