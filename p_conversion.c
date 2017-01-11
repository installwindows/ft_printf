/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:05:40 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/11 15:56:54 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		p_conversion(t_flags *flags, va_list *args)
{
	unsigned long long	addr;
	int					nbprint;

	nbprint = 0;
	addr = (unsigned long long)va_arg(*args, void *);
	if (flags->f & F_MINUS)
	{
		nbprint += ft_putstr("0x");
		if (flags->f & F_PRECISION && flags->precision > ft_unumlen_base(addr, 16))
			nbprint += ft_putnchar('0', flags->precision - ft_unumlen_base(addr, 16));
		if (!(flags->f & F_PRECISION && flags->precision == 0 && addr == 0))
			nbprint += ft_putudigit_base(addr, 16, ft_itoc);
		if (flags->f & F_WIDTH && flags->width > nbprint)
			ft_putnchar(' ', flags->width - nbprint);
	}
	else
	{
		nbprint += 2 + LARGEST(flags->precision, ft_unumlen_base(addr, 16));
		if (flags->f & F_WIDTH && flags->width > nbprint)
			nbprint += ft_putnchar(' ', flags->width - nbprint);
		ft_putstr("0x");
		if (flags->f & F_PRECISION && flags->precision > ft_unumlen_base(addr, 16))
			ft_putnchar('0', flags->precision - ft_unumlen_base(addr, 16));
		if (!(flags->f & F_PRECISION && flags->precision == 0 && addr == 0 && nbprint--))
			ft_putudigit_base(addr, 16, ft_itoc);
	}
	return (nbprint);
}
