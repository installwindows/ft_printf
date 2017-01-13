/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wcstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:10:14 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/12 18:24:50 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

int		ft_wcstrlen(wchar_t *wcstr)
{
	int		len;
	char	mbstr[4];

	len = 0;
	while (*wcstr)
	{
		len += ft_wctomb(mbstr, *wcstr);
		wcstr++;
	}
	return (len);
}

int		print_wcstr(t_flags *flags, wchar_t *wcstr)
{
	int		size;
	int		nbprint;
	char	mbstr[4];

	nbprint = 0;
	while (*wcstr)
	{
		size = ft_wctomb(mbstr, *wcstr);
		if (flags->f & F_PRECISION && nbprint + size > flags->precision)
			break ;
		nbprint += write(1, mbstr, size);
		wcstr++;
	}
	return (nbprint);
}

int		correction(wchar_t *wcstr, int size)
{
	char	mb[4];
	int		i;
	int		current;
	int		total;

	i = 0;
	total = 0;
	while (wcstr[i])
	{
		current = ft_wctomb(mb, wcstr[i]);
		total += current;
		if (total > size)
		{
			size = total - current;
			break ;
		}
		i++;
	}
	return (size);
}

int		handle_wcstr(t_flags *flags, wchar_t *wcstr)
{
	size_t	size;
	char	mb[4];
	int		nbprint;
	int		i;

	nbprint = 0;
	if (flags->f & F_MINUS)
	{
		nbprint += print_wcstr(flags, wcstr);
		if (flags->f & F_WIDTH)
			while (flags->width > nbprint)
				nbprint += write(1, flags->f & F_ZERO ? "0" : " ", 1);
	}
	else
	{
		size = ft_wcstrlen(wcstr);
		if (flags->f & F_PRECISION)
		{
			size = SMALLEST(ft_wcstrlen(wcstr), flags->precision);
			size = correction(wcstr, size);
		}
		if (flags->f & F_WIDTH)
			while (flags->width-- > size)
				nbprint += write(1, flags->f & F_ZERO ? "0" : " ", 1);
		nbprint += print_wcstr(flags, wcstr);
	}
	return (nbprint);
}
