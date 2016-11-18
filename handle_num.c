/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:20:22 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/17 22:45:23 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	handle_num(int n, int base, t_flags *flags)
{
	if (flags->minus)
	{
		ft_putstr(flags->plus && n >= 0 ? "+" : "");
		ft_putstr(!flags->plus && flags->space && n >= 0 ? " " : "");
		if (flags->hashtag)
			if (flags->conversion == 'o')
				ft_putstr(n > 0 ? "0" : "");
			else if (flags->conversion == 'x' || flags->conversion == 'X')
				ft_putstr(flags->conversion == 'x' ? "0x" : "0X");
		ft_putnbr_base(n, base);
		while (flags->width-- >= ft_intlen(n) + flags->hashtag)
			ft_putchar(' ');
	}
	else
	{
		while (!flags->zero && flags->width-- >= ft_intlen(n) + flags->hashtag
				+ (n < 0 || flags->plus))
			ft_putchar(' ');
		ft_putstr(flags->plus && n >= 0 ? "+" : "");
		ft_putstr(!flags->plus && flags->space && n >= 0 ? " " : "");
		if (flags->hashtag)
			if (flags->conversion == 'o')
				ft_putstr(n > 0 ? "0" : "");
			else if (flags->conversion == 'x' || flags->conversion == 'X')
				ft_putstr(flags->conversion == 'x' ? "0x" : "0X");
		while (flags->zero && flags->width-- >= ft_intlen(n) + flags->hashtag)
			ft_putchar('0');
		if (!(n == 0 && flags->precision == 0))
			ft_putnbr_base(n, base);
	}
}
