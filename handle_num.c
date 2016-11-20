/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:20:22 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/19 15:24:10 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		handle_num(long long n, int base, t_flags *flags)
{
	ssize_t	nbprint;

	nbprint = 0;
	if (flags->minus)
	{
		nbprint += ft_putstr(flags->plus && n >= 0 ? "+" : "");
		nbprint += ft_putstr(!flags->plus && flags->space && n >= 0 ? " " : "");
		if (flags->hashtag)
			if (flags->conversion == 'o')
				nbprint += ft_putstr(n > 0 ? "0" : "");
			else if (flags->conversion == 'x' || flags->conversion == 'X')
				nbprint += ft_putstr(flags->conversion == 'x' ? "0x" : "0X");
		nbprint += flags->conversion == 'x' ? ft_putnbr_base(n, base) :
														ft_putNBR_base(n, base);
		while (flags->width-- >= ft_intlen(n) + flags->hashtag)
			nbprint += ft_putchar(' ');
	}
	else
	{
		while (!flags->zero && flags->width-- >= ft_intlen(n) + flags->hashtag
				+ (n < 0 || flags->plus))
			nbprint += ft_putchar(' ');
		nbprint += ft_putstr(flags->plus && n >= 0 ? "+" : "");
		nbprint += ft_putstr(!flags->plus && flags->space && n >= 0 ? " " : "");
		if (flags->hashtag)
			if (flags->conversion == 'o')
				nbprint += ft_putstr(n > 0 ? "0" : "");
			else if (flags->conversion == 'x' || flags->conversion == 'X')
				nbprint += ft_putstr(flags->conversion == 'x' ? "0x" : "0X");
		while (flags->zero && flags->width-- >= ft_intlen(n) + flags->hashtag)
			nbprint += ft_putchar('0');
		if (!(n == 0 && flags->precision == 0))
			nbprint += flags->conversion == 'x' ? ft_putnbr_base(n, base) :
														ft_putNBR_base(n, base);
	}
	return (nbprint);
}
