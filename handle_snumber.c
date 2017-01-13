/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_snumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:20:17 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/12 19:28:11 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static int	print_signed_number(long long n, t_flags *f)
{
	int		neg;
	int		nbprint;

	nbprint = 0;
	neg = n < 0;
	if (f->f & F_PRECISION && f->precision > ft_snumlen(n))
		nbprint += ft_putnchar('0', f->precision - ft_snumlen(n));
	if (f->f & F_PRECISION && f->precision == 0 && n == 0)
		;
	else
		nbprint += ft_putdigit(n);
	return (nbprint);
}

static int	handle_non_minus(t_flags *f, int neg, long long n)
{
	int		nbprint;

	nbprint = 0;
	if (f->f & F_SPACE && !(f->f & F_PLUS) && !neg)
		nbprint += ft_putchar(' ');
	if (f->f & F_PLUS && !neg)
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
	return (nbprint);
}

int			handle_signed_number(long long n, t_flags *f)
{
	int		neg;
	int		nbprint;

	nbprint = 0;
	neg = n < 0;
	if (f->f & F_MINUS)
	{
		if (f->f & F_SPACE && !(f->f & F_PLUS) && !neg)
			nbprint += ft_putchar(' ');
		if (f->f & F_PLUS && !neg)
			nbprint += ft_putchar('+');
		if (neg)
			nbprint += ft_putchar('-');
		nbprint += print_signed_number(n, f);
		if (f->f & F_WIDTH && f->width > nbprint)
			nbprint += ft_putnchar(' ', f->width - nbprint);
	}
	else
		nbprint += handle_non_minus(f, neg, n);
	return (nbprint);
}
