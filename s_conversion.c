/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:34:09 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/07 22:37:54 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

void	s_conversion(t_flags *flags, va_list *args)
{
	char	*arg;

	arg = va_arg(*args, char *);
	handle_field(flags, arg, ' ');
}
