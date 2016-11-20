/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:09:29 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/19 15:51:38 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		x_conversion(t_flags *flags, va_list *args)
{
	unsigned int	d;

	d = va_arg(*args, unsigned int);
	return ((int)handle_num(d, 16, flags));
}
