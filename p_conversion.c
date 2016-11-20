/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:05:40 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/19 15:49:26 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		p_conversion(t_flags *flags, va_list *args)
{
	void	*p;
	ssize_t	nbprint;

	p = va_arg(*args, void *);
	nbprint = ft_putstr("0x");
	nbprint += ft_putnbr_base((long long)p, 16);
	return ((int)nbprint);
}
