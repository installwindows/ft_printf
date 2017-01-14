/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:02:42 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/13 20:04:08 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static int	print_unsigned_number(unsigned long long n, int base, t_flags *f)
{
	int		nbprint;

	nbprint = 0;
	if (f->f & F_PRECISION && f->precision > ft_unumlen_base(n, base))
		nbprint += ft_putnchar('0', f->precision - ft_unumlen_base(n, base));
	if ((f->f & F_PRECISION && f->precision == 0 && n == 0) ||
		(n == 0 && f->f & F_HASH))
		;
	else
		nbprint += ft_putudigit_base(n, base, f->conversion == 'X' ? ft_itocc :
			ft_itoc);
	if (f->conversion == 'p' && n == 0 && !(f->f & F_PRECISION && f->precision))
		nbprint += ft_putudigit_base(n, base, ft_itoc);
	return (nbprint);
}

static int	print_hash(unsigned long long n, t_flags *f)
{
	if ((f->conversion == 'o' || f->conversion == 'O') && f->precision <
			ft_unumlen_base(n, 8))
		return (ft_putchar('0'));
	if (f->conversion == 'x' && !(f->f & F_PRECISION && f->precision == 0))
		return (ft_putstr(n == 0 ? "0" : "0x"));
	if (f->conversion == 'X' && !(f->f & F_PRECISION && f->precision == 0))
		return (ft_putstr(n == 0 ? "0" : "0X"));
	if (f->conversion == 'p')
		return (ft_putstr("0x"));
	return (0);
}

static int	bits_to_print(t_flags *f, unsigned long long n)
{
	int		nbprint;

	nbprint = 0;
	if (ft_toupper(f->conversion) == 'X' && f->f & F_HASH &&
		!(f->f & F_PRECISION && f->precision == 0))
		nbprint += (n == 0 ? 1 : 2);
	else if (ft_toupper(f->conversion) == 'O' && f->f & F_HASH &&
			f->precision < ft_unumlen_base(n, 8))
		nbprint += 1;
	return (nbprint);
}

int			handle_unsigned_number(unsigned long long n, int b, t_flags *f)
{
	int		nbprint;

	nbprint = bits_to_print(f, n);
	if (f->f & F_MINUS)
	{
		if (f->f & F_HASH)
			print_hash(n, f);
		nbprint += print_unsigned_number(n, b, f);
		if (f->f & F_WIDTH && f->width > nbprint)
			nbprint += ft_putnchar(' ', f->width - nbprint);
	}
	else
	{
		if (ft_toupper(f->conversion) == 'X' && f->f & F_HASH && f->f & F_ZERO)
			print_hash(n, f);
		if (f->f & F_WIDTH && f->width > nbprint + (ft_unumlen_base(n, b) >
			f->precision ? ft_unumlen_base(n, b) : f->precision))
			nbprint += ft_putnchar(f->f & F_ZERO ? '0' : ' ', f->width -
					(nbprint + (ft_unumlen_base(n, b) > f->precision ?
					ft_unumlen_base(n, b) - (n == 0) : f->precision)));
		if (f->f & F_HASH && !(f->f & F_ZERO))
			print_hash(n, f);
		nbprint += print_unsigned_number(n, b, f);
	}
	return (nbprint);
}
