/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:57:40 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/18 19:59:26 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		do_conversion(t_flags *flags, va_list *args)
{
	const char *lookup = "sSpdDioOuUxXcC";
	int		(*conversions[14])(t_flags *flags, va_list *args);

	conversions[0] = s_conversion;
	conversions[1] = S_conversion;
	conversions[2] = p_conversion;
	conversions[3] = d_conversion;
	conversions[4] = D_conversion;
	conversions[5] = i_conversion;
	conversions[6] = o_conversion;
	conversions[7] = O_conversion;
	conversions[8] = u_conversion;
	conversions[9] = U_conversion;
	conversions[10] = x_conversion;
	conversions[11] = X_conversion;
	conversions[12] = c_conversion;
	conversions[13] = C_conversion;
	return ((*conversions[ft_strchr(lookup, flags->conversion) - lookup])
			(flags, args));
}
