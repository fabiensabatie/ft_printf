/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/03 20:46:10 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		handle_post(t_print *s, int i)
{
	if (s->pad_is == AFTER && s->pad_char == ' ')
		while (s->mfw-- > i + (int)ft_strlen(s->hash) && (s->cnt += 1))
			ft_putchar(s->pad_char);
}

static void handle_digits(t_print *s)
{
	if (s->is_prec && (s->pad_char = ' '))
		s->prec = ft_atoi(s->format);
	else
		s->mfw = ft_atoi(s->format);
	while (ft_isdigit(*s->format))
		s->format++;
}

static void handle_opflag(t_print *s)
{
	if (*s->format == '#' && (s->format += 1))
	{
		if (s->flag == 'o')
			s->hash = ft_strdup("0");
		else if (ft_strchr("xX", s->flag))
			s->hash = (s->flag == 'x') ? ft_strdup("0x") : ft_strdup("0X");
	}
	else if (ft_isdigit(*s->format) && *s->format != '0')
		handle_digits(s);
	else if (*s->format == '-' && (s->format += 1))
		s->pad_is = AFTER;
	else if ((s->pad_is != AFTER) && *s->format == '0' && (s->format += 1)
	&& (ft_strchr("dDioOuUxX", s->flag) && s->prec == 0))
		s->pad_char = '0';
	else if (*s->format == ' ' && !(s->sign)
	&& (ft_strchr("dDi", s->flag) && (s->format += 1)))
		s->sign = ' ';
	else if (*s->format == '+' && (ft_strchr("dDi", s->flag))
	&& (s->format += 1))
		s->sign = '+';
	else if (*s->format == '.' && (s->format += 1) && (s->is_prec += 1))
		handle_digits(s);
	else
		s->format++;
}

static void	get_modifiers(t_print *s)
{
	s->mod = X;
	if (*s->format == 'h' && (s->format += 1))
		(*s->format == 'h' && (s->format += 1)) ?
		(s->mod = HH) : (s->mod = H);
	else if (*s->format == 'l' && (s->format += 1))
		(*s->format == 'l' && (s->format += 1)) ?
		(s->mod = LL) : (s->mod = L);
	else if (*s->format == 'j' && (s->format += 1))
		s->mod = J;
	else if (*s->format == 'z' && (s->format += 1))
		s->mod = Z;
}

void		process_flag(t_print *s)
{
	s->flag = ft_chrstr("sSpPdDioOuUxXcCb%", s->format);
	while (*s->format != s->flag && !(ft_strchr("hljz", *s->format)))
		handle_opflag(s);
	get_modifiers(s);
	if (ft_strchr("diouxXb", s->flag))
		handle_nb(s);
	else if (ft_strchr("DOUpP", s->flag))
	{
		if (s->flag == 'D')
			s->cnt += ft_printf("%ld", va_arg(s->ap, long));
		else if (s->flag == 'O')
			s->cnt += ft_printf("%lo", va_arg(s->ap, unsigned long));
		else if (s->flag == 'U')
			s->cnt += ft_printf("%lu", va_arg(s->ap, unsigned long));
		else if (s->flag == 'p')
			s->cnt += ft_printf("%#lx", va_arg(s->ap, unsigned long));
		else if (s->flag == 'P')
			s->cnt += ft_printf("%#lX", va_arg(s->ap, unsigned long));
	}
	else if (ft_strchr("sScC%", s->flag))
		handle_str(s);
	s->format++;
}
