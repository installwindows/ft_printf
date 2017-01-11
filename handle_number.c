/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:02:42 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/10 18:31:13 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		print_signed_number(long long n, t_flags *f)
{
	int		neg;
	int		nbprint;

	nbprint = 0;
	neg = n < 0;
	if (f->f & F_PRECISION && f->precision > ft_snumlen(n))
		nbprint += ft_putnchar('0', f->precision - ft_snumlen(n));
	nbprint += ft_putdigit(n);
	return (nbprint);
}

int		print_unsigned_number(unsigned long long n, int base, t_flags *f)
{
	int		nbprint;

	nbprint = 0;
	if (f->f & F_PRECISION && f->precision > ft_unumlen_base(n, base))
		nbprint += ft_putnchar('0', f->precision - ft_unumlen_base(n, base));
	nbprint += ft_putudigit_base(n, base, f->conversion == 'X' ? ft_itocc :
			ft_itoc);
	return (nbprint);
}

int		handle_signed_number(long long n, t_flags *f)
{
	int		neg;
	int		nbprint;

	nbprint = 0;
	neg = n < 0;
	if (f->f & F_MINUS)
	{
		if (f->f & F_SPACE && !(f->f & F_PLUS) && !neg)
			nbprint += ft_putchar(' ');
		if (f->f & F_PLUS)
			nbprint += ft_putchar('+');
		if (neg)
			nbprint += ft_putchar('-');
		nbprint += print_signed_number(n, f);
		if (f->f & F_WIDTH && f->width > nbprint)
			nbprint += ft_putnchar(' ', f->width - nbprint);
	}
	else
	{
		if (f->f & F_SPACE && !(f->f & F_PLUS) && !neg)
			nbprint += ft_putchar(' ');
		if (f->f & F_PLUS)
			nbprint += ft_putchar('+');
		neg = neg + nbprint + (ft_snumlen(n) > f->precision ? ft_snumlen(n) :
				f->precision);
		if (n < 0 && f->f & F_ZERO)
			nbprint += ft_putchar('-');
		if (f->f & F_WIDTH && f->width > neg)
			nbprint += ft_putnchar(f->f & F_ZERO ? '0' : ' ', f->width - neg);
		if (n < 0 && !(f->f & F_ZERO))
			nbprint += ft_putchar('-');
		nbprint += print_signed_number(n, f);
	}
	return (nbprint);
}

int		print_hash(unsigned long long n, t_flags *f)
{
	if (f->conversion == 'o' && n != 0)
		return (ft_putchar('0'));
	if (f->conversion == 'x' && n != 0)
		return (ft_putstr("0x"));
	if (f->conversion == 'X' && n != 0)
		return (ft_putstr("0X"));
	return (0);
}

int		handle_unsigned_number(unsigned long long n, int b, t_flags *f)
{
	int		nbprint;

	nbprint = 0;
	if (f->f & F_MINUS)
	{
		nbprint += print_hash(n, f);
		nbprint += print_unsigned_number(n, b, f);
		if (f->f & F_WIDTH && f->width > nbprint)
			nbprint += ft_putnchar(' ', f->width - nbprint);
	}
	else
	{
		nbprint += print_hash(n ,f);
		if (f->f & F_WIDTH && f->width > nbprint + (ft_unumlen_base(n, b) >
					f->precision ? ft_unumlen_base(n, b) : f->precision))
			nbprint += ft_putnchar(f->f & F_ZERO ? '0' : ' ', f->width -
					(nbprint + (ft_unumlen_base(n, b) > f->precision ?
					ft_unumlen_base(n, b) : f->precision)));
		nbprint += print_unsigned_number(n, b, f);
	}
	return (nbprint);
}
