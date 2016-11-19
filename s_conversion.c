/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:34:09 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/18 20:05:27 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

int		s_conversion(t_flags *flags, va_list *args)
{
	char	*arg;

	arg = va_arg(*args, char *);
	handle_field(flags, arg, ' ');
	return (0);
}
