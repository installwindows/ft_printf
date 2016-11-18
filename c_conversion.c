/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:10:20 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/18 14:03:41 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

void	c_conversion(t_flags *flags, va_list *args)
{
	char	*c;

	c = malloc(2);
	c[0] = va_arg(*args, int);
	c[1] = '\0';
	handle_field(flags, c, ' ');
	free(c);
}
