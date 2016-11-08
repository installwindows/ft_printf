/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:58:26 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/07 22:43:43 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		handle_field(t_flags *flags, char *s, char c)
{
	int		len;
	int		size;

	if (flags->zero)
		c = '0';
	len = ft_strlen(s);
	if (flags->precision != -1)
		size = flags->precision < len ? flags->precision : len;
	else
		size = len;
	if (flags->width != -1)
	{
		if (flags->width > size)
		{
			if (flags->minus)
			{
				ft_putnstr(s, size);
				while (flags->width - size > 0)
				{
					ft_putchar(c);
					flags->width--;
				}
			}
			else
			{
				while (flags->width - size > 0)
				{
					ft_putchar(c);
					flags->width--;
				}
				ft_putnstr(s, size);
			}
		}
	}
	else
		ft_putnstr(s, size);
	return (0);
}
