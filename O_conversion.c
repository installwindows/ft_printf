/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   O_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:08:30 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/19 15:50:57 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		O_conversion(t_flags *flags, va_list *args)
{
	unsigned long	d;

	flags->l = 1;
	d = va_arg(*args, unsigned long);
	return ((int)handle_num(d, 8, flags));
}
