/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:10:20 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/12 16:46:20 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <wchar.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

int		handle_c(t_flags *f, unsigned char c)
{
	int		nbprint;

	nbprint = 0;
	//if (f->f & F_SPACE && c != 0)
	//	nbprint += ft_putchar(' ');
	if (f->f & F_MINUS)
	{
		nbprint += write(1, &c, 1);
		if (f->f & F_WIDTH && f->width > nbprint)
			nbprint += ft_putnchar(f->f & F_ZERO ? '0' : ' ', f->width - nbprint);
	}
	else
	{
		if (f->f & F_WIDTH && f->width > nbprint + 1)
			nbprint += ft_putnchar(f->f & F_ZERO ? '0' : ' ', f->width - (nbprint + 1));
		nbprint += write(1, &c, 1);
	}
	return (nbprint);
}

int		handle_wc(t_flags *f, wchar_t wc)
{
	int		nbprint;
	int		size;
	char	mb[4];


	size = ft_wctomb(mb, wc);
	nbprint = 0;
	//if (f->f & F_SPACE && wc != 0)
	//	nbprint += ft_putchar(' ');
	if (f->f & F_MINUS)
	{
		nbprint += write(1, mb, size);
		if (f->f & F_WIDTH && f->width > nbprint + 1)
			nbprint += ft_putnchar(' ', f->width - nbprint + 1);
	}
	else
	{
		if (f->f & F_WIDTH && f->width > nbprint + 1)
			nbprint += ft_putnchar(' ', f->width - nbprint + 1);
		nbprint += write(1, mb, size);
	}
	return (nbprint);
}

int		c_conversion(t_flags *flags, va_list *args)
{
	int		nbprint;

	nbprint = 0;
	if (flags->f & F_L)
	{
		nbprint += handle_wc(flags, va_arg(*args, wchar_t));
	}
	else
	{
		nbprint += handle_c(flags, (unsigned char)va_arg(*args, int));
	}
	return (nbprint);
	/*
	char	c[2];
	wchar_t	wc[2];
	int		nbprint;

	nbprint = 0;
	if (flags->f & F_L)
	{
		wc[0] = va_arg(*args, wchar_t);
		wc[1] = '\0';
		nbprint += handle_wcstr(flags, wc);
		if (wc[0] == 0)
			nbprint++;
	}
	else
	{
		c[0] = va_arg(*args, int);
		c[1] = '\0';
		nbprint += handle_string(flags, c, ' ');
		if (c[0] == 0)
			nbprint++;
	}
	return (nbprint);
	*/
}
