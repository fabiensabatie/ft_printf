/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/06 15:08:26 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		handle_special(t_print *s)
{
	if (ft_strchr("oO", s->flag) && s->arg != 0 && ft_strlen(s->hash)
	&& (s->cnt += ft_strlen(s->hash)) && (s->nb_digits += ft_strlen(s->hash))
	&& (s->h += 1) && (s->prec -= ft_strlen(s->hash)))
		ft_putstr(s->hash);
	else if (ft_strchr("xX", s->flag) && (s->arg != 0 || s->ptr)
	&& ft_strlen(s->hash) && (s->cnt += ft_strlen(s->hash))
	&& (s->nb_digits += ft_strlen(s->hash)) && (s->h += 1))
		ft_putstr(s->hash);
	s->hash = (s->h) ? "" : s->hash;
}

void		handle_zero(t_print *s)
{
	if (s->arg == 0 && ft_strchr("xXuUidDoO", s->flag) && !s->ip
	&& (s->cnt += 1))
		return (ft_putchar('0'));
	if (s->arg == 0 && ft_strchr("uU", s->flag) && s->ip && s->oprec >= 1
	&& (s->cnt += 1))
		ft_putchar('0');
	else if (s->arg == 0 && ft_strchr("xX", s->flag) && s->ip && s->oprec >= 1
	&& ft_strlen(s->hash) && (s->cnt += 1))
		return (ft_putchar('0'));
	else if (s->arg == 0 && ft_strchr("oO", s->flag) && s->ip
	&& ft_strlen(s->hash) && (s->cnt += 1))
		return (ft_putchar('0'));
	else if (s->arg == 0 && ft_strchr("dDxXoO", s->flag) && s->ip)
		return ;
	if (!s->h && ft_strlen(s->hash) && (s->cnt += ft_strlen(s->hash)))
		ft_putstr(s->hash);
}

static void	set_color(t_print *s)
{
	if (*s->format == 'R' && (s->format += 1))
		s->color = RED;
	else if (*s->format == 'G' && (s->format += 1))
		s->color = GREEN;
	else if (*s->format == 'B' && (s->format += 1))
		s->color = BLUE;
	else if (*s->format == 'Y' && (s->format += 1))
		s->color = YELLOW;
	else if (*s->format == 'V' && (s->format += 1))
		s->color = PURPLE;
	else if (*s->format == 'M' && (s->format += 1))
		s->color = MAGENTA;
	else
		s->color = CR;
}

void		handle_bonus(t_print *s)
{
	s->color = 0;
	s->blink = 0;
	while (*s->format != s->flag && !(ft_strchr("hljz", *s->format)))
	{
		if (*s->format == '=' && (s->format += 1))
			s->blink++;
		else if (*s->format == '|' && (s->format += 1))
			set_color(s);
		else
			s->format++;
	}
}
