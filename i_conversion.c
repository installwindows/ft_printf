/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:07:44 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/18 13:47:00 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		i_conversion(t_flags *flags, va_list *args)
{
	int		d;

	d = va_arg(*args, int);
	handle_num(d, 10, flags);
	return (0);
}
