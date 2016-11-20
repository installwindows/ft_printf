/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:58:26 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/19 15:08:25 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		handle_field(t_flags *flags, char *s, char c)
{
	int		len;
	int		size;
	ssize_t	nbprint;

	nbprint = 0;
	len = ft_strlen(s);
	if (flags->precision != -1 && flags->conversion == 's')
		size = flags->precision < len ? flags->precision : len;
	else
		size = len;
	if (flags->width != -1 && flags->width > size)
	{
		if (flags->minus)
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
