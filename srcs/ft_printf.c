/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:34:09 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/04 23:52:35 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
# include <stdarg.h>
# include <stdlib.h>

static int init_tprint(t_print *s)
{
	s->flag = 0;
	s->mod = 0;
	s->hash = 0;
	s->mfw = 0;
	s->is_prec = 0;
	s->prec = 0;
	s->pad_is = 0;
	s->sign = 0;
	s->nb_ispos = 0;
	s->hash = "";
	s->pad_char = ' ';
	s->arg = 1;
	return (1);
}

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
		if (*s.format == '%' && (s.format += 1) && init_tprint(&s))
			process_flag(&s);
		else if ((s.cnt += 1))
			ft_putchar(*s.format++);
	}
	va_end(s.ap);
	if (s.hash && ft_strlen(s.hash))
		free (s.hash);
	free(f_start);
	if (s.hash && ft_strlen(s.hash))
		free(s.hash);
	return (s.cnt);
}