/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floating_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 00:24:33 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/17 03:11:01 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "mantissa.h"
#include "ft_bignum.h"
#include "libft.h"
#include "exponent.h"

static char	*eval_exponent(unsigned long long num, int exponent, char *str)
{
	char	*tmp;
	char	*exp;

	tmp = (mtp(ft_strrev(str), g_exponent[exponent]));
	free(str);
	if (num & 0x8000000000000000ull)
	{
		str = ft_strjoin("-", tmp);
		free(tmp);
		tmp = str;
	}
	return (tmp);
}

static char	*get_float(double d)
{
	int					i;
	char				*str;
	char				*tmp;
	unsigned long long	mask;
	unsigned long long	num;

	if (d == 0)
		return (ft_itoa(0));
	ft_memcpy(&num, &d, sizeof(double));
	str = ft_itoa(1);
	mask = 0x8000000000000ull;
	i = 0;
	while (mask > 0)
	{
		tmp = str;
		if (num & mask)
		{
			str = ft_bignum_add(str, g_mantissa[i]);
			free(tmp);
		}
		mask >>= 1;
		i++;
	}
	return (eval_exponent(num, (num >> 52) - 1023, str));
}

static char	*createdotnum(int dot)
{
	char	*num;
	int		i;

	i = 1;
	num = malloc(dot + 2);
	num[0] = '.';
	num[dot] = '1';
	num[dot + 1] = '\0';
	while (i < dot)
		num[i++] = '0';
	return (ft_strrev(num));
}

static char	*round_bignum(int p, char *n)
{
	int			dot;
	char		*tmp;
	char		*num;

	dot = ft_strichr(n, '.');
	if (dot == -1)
		return (n);
	if (dot + p + 1 < (int)ft_strlen(n))
	{
		if (n[dot + p + 1] - '0' >= 5)
		{
			tmp = ft_bignum_add((num = createdotnum(p)), ft_strrev(n));
			free(n);
			free(num);
			return (ft_strrev(tmp));
		}
	}
	return (n);
}

static int	print_float(t_flags *f, char *n)
{
	int		nbprint;
	int		dot;

	dot = ft_strichr(n, '.');
	nbprint = ft_putnstr(n, dot == -1 ? ft_strlen(n) : dot);
	if (f->f & F_HASH)
		nbprint += ft_putchar('.');
	if (f->precision > 0 && dot != -1)
		nbprint += ft_putnstr(n + dot, f->precision + 1);
	if (dot == -1 && f->f & F_HASH)
		nbprint += ft_putnchar('0', f->precision);
	return (nbprint);
}

int			f_conversion(t_flags *flags, va_list *args)
{
	double	d;
	char	*r;
	int		nbprint;

	nbprint = 0;
	d = va_arg(*args, double);
	if (!(flags->f & F_PRECISION))
		flags->precision = 6;
	r = round_bignum(flags->precision, get_float(d));
	if (flags->f & F_MINUS)
	{
		if (flags->f & F_PLUS && d >= 0)
			nbprint += ft_putchar('+');
		if (flags->f & F_SPACE && !(flags->f & F_PLUS) && d >= 0)
			nbprint += ft_putchar(' ');
		nbprint += print_float(flags, r);
		if (flags->f & F_WIDTH)
			while (nbprint < flags->width)
				nbprint += ft_putchar(flags->f & F_ZERO ? '0' : ' ');
	}
	else
	{
		if (flags->f & F_WIDTH)
		   	while (nbprint + flags->precision + LARGEST(ft_strichr(r, '.') + 1, 0) + ((flags->f &
				F_PLUS || flags->f & F_SPACE) && d >= 0 ? 1 : 0) < flags->width)
				nbprint += ft_putchar(flags->f & F_ZERO ? '0' : ' ');
		if (flags->f & F_PLUS && d >= 0)
			nbprint += ft_putchar('+');
		if (flags->f & F_SPACE && !(flags->f & F_PLUS) && d >= 0)
			nbprint += ft_putchar(' ');
		nbprint += print_float(flags, r);
	}
	free(r);
	return (nbprint);
}
