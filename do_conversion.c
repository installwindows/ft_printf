/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:57:40 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/03 22:57:05 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void	do_conversion(t_flags *flags, va_list *args)
{
	void	(*conversions[14])(t_flags *flags, va_list *args);

	conversions[0] = s_conversion;
	(*conversions[flags->conversion])(flags, args);
}
