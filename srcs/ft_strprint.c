/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:34:09 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/28 14:41:06 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"
#include <unistd.h>

static void	print_unicode(t_print *s, wchar_t c)
{
	s->unisize = 0;
	if (c < 0x7F)
		ft_putchar(c);
	else if (c <= 0x7FF && (s->unisize = 2))
	{
		s->uni[0] = (c >> 6) | 0xc0;
		s->uni[1] = (c & 0x3f) | 0x80;
	}
	else if (c <= 0xFFFF && (s->unisize = 3))
	{
		s->uni[0] = (c >> 12) | 0xe0;
		s->uni[1] = ((c >> 6) & 0x3f) | 0x80;
		s->uni[2] = (c & 0x3f) | 0x80;
	}
	else if (c <= 0x1FFFFFF && (s->unisize = 4))
	{
		s->uni[0] = (c >> 18) | 0xf0;;
		s->uni[1] = ((c >> 12) & 0x3f) | 0x80;
		s->uni[2] = ((c >> 6) & 0x3f) | 0x80;
		s->uni[3] = (c & 0x3f) | 0x80;
	}
	write(1, s->uni, s->unisize);
	s->cnt++;
}

void		adapt_modifiers(t_print *s, char *str, int mode)
{
	if (mode == STR)
	{
		s->precision = (s->precision == -1) ?
		ft_strlen(str) : s->precision;
		s->precision = (s->precision > (int)ft_strlen(str)) ?
		0 : s->precision;
		s->mfw = (s->mfw > (int)ft_strlen(str)) ?
		s->mfw - s->precision : 0;
	}
	else if (mode == UNI_STR)
	{
		s->precision = (s->precision == -1) ?
		ft_wstrlen((wchar_t*)str) : s->precision;
		s->precision = (s->precision > (int)ft_wstrlen((wchar_t*)str)) ?
		0 : s->precision;
		s->mfw = (s->mfw > (int)ft_wstrlen((wchar_t*)str)) ?
		s->mfw - s->precision : 0;
	}
	else if (mode == UNI_CHAR || mode == CHAR)
	{
		s->precision = (s->precision == -1) ? 1 : s->precision;
		s->precision = (s->precision > 1) ? 0 : s->precision;
		s->mfw = (s->mfw > 1) ? s->mfw - s->precision : 0;
	}
}

void		print_str(t_print *s, char *str, int mode)
{
	wchar_t *wstr;
	if (!(s->nmfw) && s->mfw)
		while (s->mfw-- && (s->cnt += 1))
		{
			ft_putchar(s->pad);
			if (!s->mfw)
				break ;
		}
	if (str)
	{
		wstr = (wchar_t*)str;
		adapt_modifiers(s, str, mode);
		if (mode == STR && (s->cnt +=
			ft_strlen(ft_strnsub(str, s->precision))))
				ft_putstr(ft_strnsub(str, s->precision));
		else if (mode == CHAR && (s->cnt += 1))
			ft_putchar((char)str);
		else if (mode == UNI_CHAR)
			print_unicode(s, (wchar_t)str);
		else if (mode == UNI_STR && (s->cnt += s->mfw))
			while (*wstr && s->precision--)
				print_unicode(s, *wstr++);
	}
	else if (mode % 2 == 0 && (s->cnt += 6))
		ft_putstr("(null)");
	else if (mode % 2 == 1 && (s->cnt += 1))
		ft_putstr("^@");
	if (s->nmfw && s->mfw)
		while (s->mfw-- && (s->cnt += 1))
			ft_putchar(s->pad);
}