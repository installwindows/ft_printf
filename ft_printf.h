/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:19:46 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/21 17:29:42 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# pragma GCC diagnostic ignored "-Wdangling-else"
# include <stdarg.h>

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
int				handle_field(t_flags *flags, char *s, char c);
int				handle_num(long long n, int base, t_flags *flags);
int				do_conversion(t_flags *flags, va_list *args);
int				s_conversion(t_flags *flags, va_list *args);
int				ls_conversion(t_flags *flags, va_list *args);
int				p_conversion(t_flags *flags, va_list *args);
int				d_conversion(t_flags *flags, va_list *args);
int				ld_conversion(t_flags *flags, va_list *args);
int				i_conversion(t_flags *flags, va_list *args);
int				o_conversion(t_flags *flags, va_list *args);
int				lo_conversion(t_flags *flags, va_list *args);
int				u_conversion(t_flags *flags, va_list *args);
int				lu_conversion(t_flags *flags, va_list *args);
int				x_conversion(t_flags *flags, va_list *args);
int				cx_conversion(t_flags *flags, va_list *args);
int				c_conversion(t_flags *flags, va_list *args);
int				lc_conversion(t_flags *flags, va_list *args);

#endif
