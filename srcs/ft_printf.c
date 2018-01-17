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
#include <unistd.h>

int			ft_sprintf(char **str, const char *format, ...)
{
	t_print	s;
	char	*f_start;

	ft_bzero(&s, sizeof(s));
	s.format = ft_strdup((char *)format);
	s.buffer = ft_strdup("");
	f_start = s.format;
	va_start(s.ap, format);
	ft_vprintf(&s);
	*str = s.buffer;
	va_end(s.ap);
	free(f_start);
	return (s.cnt);
}

int			ft_printf(const char *format, ...)
{
	t_print	s;
	char	*f_start;

	ft_bzero(&s, sizeof(s));
	s.format = ft_strdup((char *)format);
	s.buffer = ft_strdup("");
	f_start = s.format;
	va_start(s.ap, format);
	ft_vprintf(&s);
	write(1, s.buffer, s.cnt);
	va_end(s.ap);
	free(f_start);
	free(s.buffer);
	return (s.cnt);
}

void		ft_vprintf(t_print *s)
{
	while (*s->format)
	{
		if ((int)s->cnt == -1)
			return ;
		s->mfw = 0;
		s->sign = 0;
		s->nb_ispos = 0;
		s->hash = "";
		s->pad_char = ' ';
		s->arg = 1;
		s->ip = 0;
		s->prec = 0;
		s->wchar = 0;
		s->pad_is = BEFORE;
		s->ptr = 0;
		if (*s->format == '%' && !(*(s->format + 1)))
			s->format++;
		else if (*s->format == '%' && (s->format += 1))
			process_flag(s);
		else if (*s->format)
			fill_buffer(s, CHAR, 0, (char)*s->format++);
	}
}
