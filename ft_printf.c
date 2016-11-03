/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 13:45:00 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/02 18:37:58 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

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
	flags->width = ft_atoi(*format);
	if (flags->width > 0)
		(*format)++;
}

void	precision(char **format, t_flags *flags)
{
	if (**format == '.')
		flags->precision = ft_atoi(++(*format));
}

void	length_modifier(char **format, t_flags *flags)
{
	
}

void	print_arg(char *format, va_list *args)
{
	t_flags	flags;

	
}

int		read_args(const char *format, va_list *args)
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
		print_arg(format + 1, args);
	}
	return (read_args(fmt + 1, args));
}

int		ft_printf(const char *format, ...)
{
	va_list		args;

	va_start(args, format);
	read_args(format, &args);
	va_end(args);
	return (0);
}
