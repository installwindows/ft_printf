/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   S_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:01:51 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/04 01:03:12 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

void	S_conversion(t_flags *flags, va_list *args)
{
	flags->l = 1;
	s_conversion(flags, args);
}
