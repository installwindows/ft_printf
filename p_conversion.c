/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:05:40 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/04 01:38:01 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

void	p_conversion(t_flags *flags, va_list *args)
{
	void	*p;

	p = va_arg(*args, void *);
	ft_putstr("0x");
	ft_putnbr_base((long long)p, 16);
}
