/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:07:16 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/21 17:32:52 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		ld_conversion(t_flags *flags, va_list *args)
{
	long	d;

	d = va_arg(*args, long);
	flags->l = 1;
	return ((int)handle_num(d, 10, flags));
}
