/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wcstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:10:14 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/10 22:31:22 by varnaud          ###   ########.fr       */
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

int		handle_wcstr(t_flags *flags, wchar_t *wcstr)
{
	size_t	size;
	char	*mbstr;
	int		nbprint;

	nbprint = 0;
	if (flags->f & F_MINUS)
	{
		nbprint += print_wcstr(flags, wcstr);
		if (flags->f & F_WIDTH)
			while (flags->width > nbprint)
				nbprint += write(1, " ", 1);
	}
	else
	{
		size = ft_wcstrlen(wcstr);
		if (flags->f & F_WIDTH)
			while (flags->width-- > size)
				nbprint += write(1, " ", 1);
		nbprint += print_wcstr(flags, wcstr);
	}
	return (nbprint);
}
