/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:06:45 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/12 06:59:00 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

void	d_conversion(t_flags *flags, va_list *args)
{
	int		d;
	char	*n;
	char	*tmp;
	int		len;

	d = va_arg(*args, int);
	len = ft_intlen(d);
	if (len < flags->width)
	{
		n = (char*)malloc(flags->width + len + 1);
		if (d < 0)
			*n = '-';
		
		ft_memset(n + (d < 0), flags->zero ? '0' : ' ', flags->width - len);
		tmp = ft_itoa(d);
		ft_strcpy(n + (d < 0) + flags->width - len, tmp + (d < 0));
		free(tmp);
	}
	else
		n = ft_itoa(d);
	ft_putstr(n);
	free(n);
}
