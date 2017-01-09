/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:58:26 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/08 16:16:35 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		handle_string(t_flags *flags, char *s, char c)
{
	int		len;
	int		size;
	ssize_t	nbprint;

	nbprint = 0;
	len = ft_strlen(s);
	if (flags->f & F_PRECISION && flags->conversion == 's')
		size = flags->precision < len ? flags->precision : len;
	else
		size = len;
	if (flags->f & F_WIDTH && flags->width > size)
	{
		if (flags->f & F_MINUS)
		{
			nbprint += ft_putnstr(s, size);
			while (flags->width - size > 0)
			{
				nbprint += ft_putchar(c);
				flags->width--;
			}
		}
		else
		{
			while (flags->width - size > 0)
			{
				nbprint += ft_putchar(c);
				flags->width--;
			}
			nbprint += ft_putnstr(s, size);
		}
	}
	else
		nbprint += ft_putnstr(s, size);
	return (nbprint);
}
