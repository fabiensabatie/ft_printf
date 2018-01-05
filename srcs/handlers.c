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

void		handle_post_digit(t_print *s, int mode, int i)
{
	if (mode == DIGITS)
	{
		if (s->is_prec && (s->pad_char = ' '))
			s->prec = ft_atoi(s->format);
		else
			s->mfw = ft_atoi(s->format);
		while (ft_isdigit(*s->format))
			s->format++;
	}
	else
	{
		if (s->pad_is == AFTER && s->pad_char == ' ')
			while (s->mfw-- > i + (int)ft_strlen(s->hash) && (s->cnt += 1))
				ft_putchar(s->pad_char);
	}
}

void		handle_signs(t_print *s)
{
	if (s->pad_is == BEFORE && s->pad_char == ' ')
		pad(s);
	else if (s->pad_is == AFTER && s->is_prec)
	{
		if (s->sign == '+' && ft_strchr("dDioO", s->flag) && (s->cnt += 1))
			(s->nb_ispos) ? ft_putchar('+') : ft_putchar('-');
		s->prec = (s->prec > s->nb_digits) ? (s->prec - s->nb_digits) : 0;
		while (s->prec-- > (int)ft_strlen(s->hash) && (s->cnt += 1)
		&& (s->nb_digits += 1))
			ft_putchar('0');
		if (s->sign == '+' && ft_strchr("dDioO", s->flag))
			s->nb_digits++;
	}
	else if (s->pad_is == AFTER && !s->nb_ispos && (s->nb_digits += 1)
	&& (s->cnt += 1))
		ft_putchar('-');
	else if (s->pad_is == AFTER && s->sign == ' ' && (s->nb_digits += 1)
	&& (s->cnt += 1))
		ft_putchar(' ');
}

static void	handle_opflag(t_print *s)
{
	if (*s->format == '#' && (s->format += 1))
	{
		if (s->flag == 'o')
			s->hash = ft_strdup("0");
		else if (ft_strchr("xX", s->flag))
			s->hash = (s->flag == 'x') ? "0x" : "0X";
	}
	else if (ft_isdigit(*s->format) && *s->format != '0')
		handle_post_digit(s, DIGITS, 0);
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
		handle_post_digit(s, DIGITS, 0);
	else
		s->format++;
}

static void	get_modifiers(t_print *s)
{
	s->digits = (s->flag == 'x') ?
	"0123456789abcdef" : "0123456789ABCDEF";
	s->mod = X;
	if (*s->format == 'h' && (s->format += 1))
		s->mod = (*s->format == 'h' && (s->format += 1)) ? HH : H;
	else if (*s->format == 'l' && (s->format += 1))
		s->mod = (*s->format == 'l' && (s->format += 1)) ? LL : L;
	else if (*s->format == 'j' && (s->format += 1))
		s->mod = J;
	else if (*s->format == 'z' && (s->format += 1))
		s->mod = Z;
}

void		process_flag(t_print *s)
{
	if (!(s->flag = ft_chrstr("sSpPdDioOuUxXcCb%", s->format)))
		return ;
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
