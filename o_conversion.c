/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:08:05 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/18 13:46:17 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

void	o_conversion(t_flags *flags, va_list *args)
{
	int		d;

	d = va_arg(*args, int);
	handle_num(d, 8, flags);
}
