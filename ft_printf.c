/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 13:45:00 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/03 23:18:11 by varnaud          ###   ########.fr       */
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
		flags->hashtag = 1;
	else if (**format == '0')
		flags->zero = 1;
	else if (**format == '-')
		flags->minus = 1;
	else if (**format == ' ')
		flags->space = 1;
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
		(*format) += ft_intlen(flags->width);
}

void	precision(char **format, t_flags *flags)
{
	if (**format == '.')
	{
		flags->precision = ft_atoi(++(*format));
		if (flags->precision > 0 || **format == '0')
			(*format) += ft_intlen(flags->precision);
	}
}

void	length_modifier(char **format, t_flags *flags)
{
	if (**format == 'h' && *(*format + 1) == 'h')
		flags->hh = 1;
	else if (**format == 'h')
		flags->h = 1;
	else if (**format == 'l' && *(*format + 1) == 'l')
		flags->ll = 1;
	else if (**format == 'l')
		flags->l = 1;
	else if (**format == 'j')
		flags->j = 1;
	else if (**format == 'z')
		flags->z = 1;
	else
		return ;
	if (flags->hh || flags->ll)
		(*format) += 2;
	else
		(*format)++;
}

void	printflags(const char *format, t_flags *f)
{
	printf("format: |%s|\n", format);
	printf("conversion: %d\n", f->conversion);
	printf("hashtag: %d\n", f->hashtag);
	printf("zero: %d\n", f->zero);
	printf("minus: %d\n", f->minus);
	printf("plus: %d\n", f->plus);
	printf("space: %d\n", f->space);
	printf("width: %d\n", f->width);
	printf("precision: %d\n", f->precision);
	printf("hh: %d\n", f->hh);
	printf("h: %d\n", f->h);
	printf("l: %d\n", f->l);
	printf("ll: %d\n", f->ll);
	printf("j: %d\n", f->j);
	printf("z: %d\n", f->z);
	printf("\n");
}

void	print_arg(char **format, va_list *args)
{
	const char *lookup = "sSpdDioOuUxXcC";

	t_flags	flags;

	ft_memset(&flags, 0, sizeof(t_flags));
	flags.width = -1;
	flags.precision = -1;
	(*format)++;
	//printf("format: |%s|\n", *format);
	flag_characters(format, &flags);
	field_width(format, &flags);
	precision(format, &flags);
	length_modifier(format, &flags);
	flags.conversion = ft_strchr(lookup, **format) - lookup;
	(*format)++;

	//printflags(*format, &flags);

	do_conversion(&flags, args);	
}

int		read_args(char *format, va_list *args)
{
	char	*fmt;

	if ((fmt = ft_strchr(format, '%')) == NULL)
	{
		ft_putstr(format);
		return (0);
	}
	else
	{
		ft_putnstr(format, fmt - format);
		print_arg(&fmt, args);
		format = fmt;
	}
	return (read_args(format, args));
}

int		ft_printf(const char *format, ...)
{
	va_list		args;

	va_start(args, format);
	read_args(format, &args);
	va_end(args);
	return (0);
}
