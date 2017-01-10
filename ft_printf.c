/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 13:45:00 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/09 21:42:29 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

#include <stdio.h>

void	flag_characters(char **format, t_flags *flags)
{
	if (**format == '#')
		flags->f |= F_HASH;
	else if (**format == '0')
		flags->f |= F_ZERO;
	else if (**format == '-')
		flags->f |= F_MINUS;
	else if (**format == '+')
		flags->f |= F_PLUS;
	else if (**format == ' ')
		flags->f |= F_SPACE;
	else
		return ;
	(*format)++;
}

void	field_width(char **format, t_flags *flags)
{
	if (!ft_isdigit(**format))
		return ;
	flags->width = ft_atoi(*format);
	if (flags->width > 0 || **format == '0')
	{
		flags->f |= F_WIDTH;
		(*format) += ft_numlen(flags->width);
	}
}

void	precision(char **format, t_flags *flags)
{
	if (**format == '.')
	{
		flags->f |= F_PRECISION;
		flags->precision = ft_atoi(++(*format));
		if (flags->precision > 0 || **format == '0')
			(*format) += ft_numlen(flags->precision);
	}
}

void	length_modifier(char **format, t_flags *flags)
{
	if (**format == 'h' && *(*format + 1) == 'h')
		flags->f |= F_HH;
	else if (**format == 'h')
		flags->f |= F_H;
	else if (**format == 'l' && *(*format + 1) == 'l')
		flags->f |= F_LL;
	else if (**format == 'l')
		flags->f |= F_L;
	else if (**format == 'j')
		flags->f |= F_J;
	else if (**format == 'z')
		flags->f |= F_Z;
	else
		return ;
	if ((flags->f & F_HH) || (flags->f & F_LL))
		(*format) += 2;
	else
		(*format)++;
}

void	printflags(const char *format, t_flags *f)
{
	printf("format: |%s|\n", format);
	printf("conversion: %d\n", f->conversion);
	printf("hash: %d\n", f->f & F_HASH);
	printf("zero: %d\n", f->f & F_ZERO);
	printf("minus: %d\n", f->f & F_MINUS);
	printf("plus: %d\n", f->f & F_PLUS);
	printf("space: %d\n", f->f & F_SPACE);
	printf("width: %d %d\n", f->f & F_WIDTH, f->width);
	printf("precision: %d %d\n", f->f & F_PRECISION, f->precision);
	printf("hh: %d\n", f->f & F_HH);
	printf("h: %d\n", f->f & F_H);
	printf("l: %d\n", f->f & F_L);
	printf("ll: %d\n", f->f & F_LL);
	printf("j: %d\n", f->f & F_J);
	printf("z: %d\n", f->f & F_Z);
	printf("\n");
}

int		print_arg(char **format, va_list *args)
{
	t_flags	flags;

	if (**format == '%')
		return ((int)ft_putchar('%'));
	ft_memset(&flags, 0, sizeof(t_flags));
	//printf("format: |%s|\n", *format);
	flag_characters(format, &flags);
	flag_characters(format, &flags);
	field_width(format, &flags);
	precision(format, &flags);
	length_modifier(format, &flags);
	flags.conversion = **format;
	(*format)++;

	//printflags(*format, &flags);
	return (do_conversion(&flags, args));
}

int		read_args(char *format, va_list *args, int nbprint)
{
	char	*fmt;

	if ((fmt = ft_strchr(format, '%')) == NULL)
	{
		nbprint += ft_putstr(format);
		return (nbprint);
	}
	else
	{
		ft_putnstr(format, fmt - format);
		nbprint += fmt - format;
		fmt++;
		nbprint += print_arg(&fmt, args);
		format = fmt;
	}
	return (read_args(format, args, nbprint));
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			r;

//	ft_putstr("IM CALLED\n");
	va_start(args, format);
	r = read_args((char*)format, &args, 0);
	va_end(args);
	return (r);
}
