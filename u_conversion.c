/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:08:50 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/18 20:04:31 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		u_conversion(t_flags *flags, va_list *args)
{
	unsigned int	d;

	d = va_arg(*args, unsigned int);
	handle_num(d, 10, flags);
	return (0);
}
