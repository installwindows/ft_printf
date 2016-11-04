/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:19:46 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/04 04:54:49 by varnaud          ###   ########.fr       */
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

int				ft_printf(const char *format, ...)
				__attribute__ ((format (printf, 1, 2)));
int				handle_field(t_flags *flags, char *s);
void			do_conversion(t_flags *flags, va_list *args);
void			s_conversion(t_flags *flags, va_list *args);
void			S_conversion(t_flags *flags, va_list *args);
void			p_conversion(t_flags *flags, va_list *args);
void			d_conversion(t_flags *flags, va_list *args);
void			D_conversion(t_flags *flags, va_list *args);
void			i_conversion(t_flags *flags, va_list *args);
void			o_conversion(t_flags *flags, va_list *args);
void			O_conversion(t_flags *flags, va_list *args);
void			u_conversion(t_flags *flags, va_list *args);
void			U_conversion(t_flags *flags, va_list *args);
void			x_conversion(t_flags *flags, va_list *args);
void			X_conversion(t_flags *flags, va_list *args);
void			c_conversion(t_flags *flags, va_list *args);
void			C_conversion(t_flags *flags, va_list *args);

#endif
