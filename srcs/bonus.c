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
