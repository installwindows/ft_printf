/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:05:40 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/12 19:17:03 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static int	print_p(t_flags *f, unsigned long long p)
{
	int		n;

	n = 0;
	if (f->f & F_MINUS)
	{
		n += ft_putstr("0x");
		if (f->f & F_PRECISION && f->precision > ft_unumlen_base(p, 16))
			n += ft_putnchar('0', f->precision - ft_unumlen_base(p, 16));
		if (!(f->f & F_PRECISION && f->precision == 0 && p == 0))
			n += ft_putudigit_base(p, 16, ft_itoc);
		if (f->f & F_WIDTH && f->width > n)
			n += ft_putnchar(' ', f->width - n);
	}
	else
	{
		n += 2 + LARGEST(f->precision, ft_unumlen_base(p, 16));
		if (f->f & F_WIDTH && f->width > n)
			n += ft_putnchar(' ', f->width - n);
		ft_putstr("0x");
		if (f->f & F_PRECISION && f->precision > ft_unumlen_base(p, 16))
			ft_putnchar('0', f->precision - ft_unumlen_base(p, 16));
		if (!(f->f & F_PRECISION && f->precision == 0 && p == 0 && n--))
			ft_putudigit_base(p, 16, ft_itoc);
	}
	return (n);
}

int			p_conversion(t_flags *flags, va_list *args)
{
	unsigned long long	addr;

	addr = (unsigned long long)va_arg(*args, void *);
	if (flags->f & F_ZERO)
	{
		flags->f |= F_PRECISION;
		flags->precision = flags->width > 2 ? flags->width - 2 : 1;
		flags->f |= F_MINUS;
	}
	return (print_p(flags, addr));
}
