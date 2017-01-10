/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:02:42 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/09 18:00:00 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

char	*create_number(va_list *args, t_flags *f, int base)
{
	void	*type;
	char	*number;

	type = va_arg(*args, f->conversion == 'u' ? unsigned long long : long long);
	
}

char	*create_unumber(va_list *args, t_flags *f, int base)
{
	unsigned long long	ull;
	unsigned long long	tmp;
	int					len;
	char				*n;
	char				*t;

	ull = va_arg(*args, unsigned long long);
	tmp = ull;
	len = 1;
	while ((tmp /= base))
		len++;
	t = n;
	n[0] = '+';
	if (f->precision > len)
		ft_memset(&n[f->plus], '0', f->precision - len);
	while (len--)
	{
		n[f->plus + f->precision]
}

char	*create_snumber(va_list *args, t_flags *f, int base)
{
	long long	ll;
	int			len;

	ll = va_arg(*args, long long);
	len = ft_numlen(ll);
	
}

int		print_signed_number(long long n, t_flags *f)
{
	int		neg;
	int		nbprint;

	nbprint = 0;
	neg = n < 0;
	if (f->f & F_SPACE && !(f->f & F_PLUS) && !neg)
		nbprint += ft_putchar(' ');
	if (f->f & F_PLUS)
		nbprint += ft_putchar('+');
	if (f->f & F_PRECISION && f->precision > ft_)

}

int		handle_signed_number(long long n, t_flags *f)
{
	int		neg;

	neg = n < 0;
	if (f->f & F_MINUS)
	{
	}
	else
	{
		
	}
}
