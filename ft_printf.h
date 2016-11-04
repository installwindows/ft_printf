/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:19:46 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/03 22:49:01 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>

typedef struct	s_flags
{
	char		conversion;
	int			hashtag;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	int			precision;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_flags;

int				ft_printf(const char *format, ...);
int				handle_field(t_flags *flags, char *s);
void			s_conversion(t_flags *flags, va_list *args);
void			do_conversion(t_flags *flags, va_list *args);

#endif
