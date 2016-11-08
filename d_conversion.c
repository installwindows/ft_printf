/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:06:45 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/08 00:00:33 by varnaud          ###   ########.fr       */
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
	int		len;

	d = va_arg(*args, int);
	len = ft_intlen(d);
	if (d < 0)
		len++;
	if (flags->zero)
	{
		if (len < flags->width)
		{

		}
	}
	n = ft_itoa(d);

	handle_field(flags, n, ' ');
	free(n);
}
