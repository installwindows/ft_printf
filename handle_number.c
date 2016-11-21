/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:02:42 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/20 17:08:12 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

char	*create_unumber(va_list *args, t_flags *f)
{
	unsigned long long	ull;
	int					len;

	ull = va_arg(*args, unsigned long long);
}

char	*create_snumber(va_list *args, t_flags *f)
{
	long long	ll;
	int			len;

	ll = va_arg(*args, long long);
	len = ft_numlen(ll);
	
}

ssize_t	handle_number(char *n, t_flags *f)
{
	int		neg;

	neg = *n == '-' ? '-' : 0;
	
}
