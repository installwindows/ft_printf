/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:34:09 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/19 15:11:18 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

int		s_conversion(t_flags *flags, va_list *args)
{
	char	*arg;

	arg = va_arg(*args, char *);
	return ((int)handle_field(flags, arg, ' '));
}
