/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcrtomb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 20:06:43 by varnaud           #+#    #+#             */
/*   Updated: 2017/01/08 23:26:37 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_wcrtomb(char *s, wchar_t widechar)
{
	int		i;
	int		byte_count;
	long	wc;

	byte_count = 1;
	wc = widechar;
	if (wc <= 0x7F)
	{
		s[0] = (char)wc;
		s[1] = 0;
	}
	else
	{
		if (wc <= 0x7FF)

	}
}
