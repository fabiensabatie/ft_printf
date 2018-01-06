/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:25 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/06 15:05:37 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <inttypes.h>
#include <stdarg.h>
#include <stdlib.h>

int			ft_printf(const char *format, ...)
{
	t_print	s;
	char	*f_start;

	ft_bzero(&s, sizeof(s));
	s.format = ft_strdup((char *)format);
	f_start = s.format;
	va_start(s.ap, format);
	while (*s.format)
	{
		s.mfw = 0;
		s.is_prec = 0;
		s.prec = 0;
		s.sign = 0;
		s.nb_ispos = 0;
		s.hash = "";
		s.pad_char = ' ';
		s.arg = 1;
		if (*s.format == '%' && !(*(s.format + 1)))
			s.format++;
		else if (*s.format == '%' && (s.format += 1))
			process_flag(&s);
		else if (*s.format && (s.cnt += 1))
			ft_putchar(*s.format++);
	}
	va_end(s.ap);
	free(f_start);
	return (s.cnt);
}

static void	handle_pre(t_print *s, int len)
{
	if (s->blink)
		ft_putstr(BLINK);
	if (s->color)
		ft_putstr(s->color);
	s->mfw = (s->mfw > len) ? (s->mfw - len) : 0;
	if (s->pad_is == BEFORE)
		while (s->mfw-- > 0 && (s->cnt += 1))
			ft_putchar(' ');
}

static void	handle_char(t_print *s)
{
	handle_pre(s, 1);
	if (s->flag == 'c' && (s->cnt += 1))
		ft_putchar((char)va_arg(s->ap, int));
	else if (s->flag == 'C' && (s->cnt += 1))
		ft_putwchar((va_arg(s->ap, wchar_t)));
	else if (s->flag == '%' && (s->cnt += 1))
		ft_putchar('%');
	handle_post_digit(s, POST, 0);
}

static void	handle_wstr(t_print *s)
{
	char *arg;

	arg = NULL;
	if (!(arg = (char*)(va_arg(s->ap, wchar_t*))))
		arg = "(null)";
	if (s->is_prec)
		arg = ((int)ft_wstrlen((wchar_t*)arg) > s->prec) ?
		(char*)ft_wstrnsub((wchar_t*)arg, s->prec) : arg;
	handle_pre(s, ft_wstrlen((wchar_t*)arg));
	s->cnt += ft_wstrlen((wchar_t*)arg);
	ft_putwstr((wchar_t*)arg);
	handle_post_digit(s, POST, 0);
}

void		handle_str(t_print *s)
{
	char *arg;

	arg = NULL;
	if (s->flag == 's')
	{
		if (!(arg = (char*)(va_arg(s->ap, char*))))
			arg = "(null)";
		if (s->is_prec)
			arg = ((int)ft_strlen(arg) > s->prec) ?
			ft_strnsub(arg, s->prec) : arg;
		handle_pre(s, ft_strlen(arg));
		s->cnt += ft_strlen(arg);
		ft_putstr(arg);
		handle_post_digit(s, POST, 0);
	}
	else if (s->flag == 'S')
		handle_wstr(s);
	else
		handle_char(s);
}
