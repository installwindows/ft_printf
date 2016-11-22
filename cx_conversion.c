/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:09:56 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/19 15:52:00 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		X_conversion(t_flags *flags, va_list *args)
{
	return ((int)x_conversion(flags, args));
}
