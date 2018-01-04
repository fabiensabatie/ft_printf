/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:17 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/03 21:22:34 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <inttypes.h>
#include <stdlib.h>

static	int	get_base(t_print *s)
{
	if (s->flag == 'o' || s->flag == 'O')
		return (8);
	else if (s->flag == 'x' || s->flag == 'X')
		return (16);
	else
		return (10);
}

static void pad(t_print *s)
{
	s->prec = (s->prec > s->nb_digits) ? (s->prec - s->nb_digits) : 0;
	if (s->sign == '+' || s->sign == ' ')
		s->nb_digits++;
	s->mfw = (s->mfw > (s->prec + s->nb_digits)) ?
	(s->mfw - s->prec - s->nb_digits) : 0;
	if (s->pad_char == ' ')
		while (s->mfw-- > (int)ft_strlen(s->hash) && (s->cnt += 1))
			ft_putchar(s->pad_char);
	if (s->sign == ' ' && s->nb_ispos && (s->cnt += 1))
		ft_putchar(s->sign);
	else if (s->sign == '+' && (s->cnt += 1) && ft_strchr("dDioO", s->flag))
		(s->nb_ispos) ? ft_putchar('+') : ft_putchar('-');
	if (s->pad_char == '0')
		while (s->mfw-- > (int)ft_strlen(s->hash) && (s->cnt += 1))
				ft_putchar(s->pad_char);
	while (s->prec-- > (int)ft_strlen(s->hash) && (s->cnt += 1))
		ft_putchar('0');
}

static void handle_pre(t_print *s)
{
	if (s->pad_is == BEFORE && s->pad_char == ' ')
		pad(s);
	else if (s->pad_is == AFTER && s->is_prec)
	{
		s->prec = (s->prec > s->nb_digits) ? (s->prec - s->nb_digits) : 0;
		while (s->prec-- > (int)ft_strlen(s->hash) && (s->cnt += 1)
		&& (s->nb_digits += 1))
			ft_putchar('0');
	}
	else if (s->pad_is == AFTER && !s->nb_ispos
	&& (s->nb_digits += 1) && (s->cnt += 1))
		ft_putchar('-');
	if (s->arg == 0 && ft_strchr("iuU", s->flag) && (s->cnt += 1))
		return (ft_putchar('0'));
	else if (s->arg == 0 && ft_strchr("dDxXoO", s->flag) && !s->is_prec && (s->cnt += 1))
		return (ft_putchar('0'));
	else if (s->arg == 0 && ft_strchr("oO", s->flag) && s->is_prec && ft_strlen(s->hash) && (s->cnt += 1))
		return (ft_putchar('0'));
	else if (s->arg == 0 && ft_strchr("dDxXoO", s->flag) && s->is_prec)
		return ;
	if (ft_strlen(s->hash) && (s->cnt += ft_strlen(s->hash)))
		ft_putstr(s->hash);
	if (s->pad_is == BEFORE && s->pad_char == '0')
		pad(s);
}

static void	nb_print(t_print *s, intmax_t nbr, int mode)
{
	char		*digits;
	intmax_t	res[264];
	int			base;
	int			i;

	s->arg = nbr;
	s->nb_ispos = (nbr >= 0) ? 1 : 0;
	nbr = (mode == UINT) ? nbr : (uintmax_t)nbr;
	if ((!s->nb_ispos) && (s->sign = '+'))
		nbr = -nbr;
	i = 0;
	base = get_base(s);
	digits = (s->flag == 'x') ?
	ft_strdup("0123456789abcdef") : ft_strdup("0123456789ABCDEF");
	while (nbr)
	{
		res[i++] = ft_abs(nbr % base);
		nbr /= base;
	}
	s->nb_digits = i ? i : 1;
	if (s->arg == 0 && ft_strchr("xXoOdD", s->flag) && s->is_prec)
		s->nb_digits = 0;
	handle_pre(s);
	while (i-- && (s->cnt += 1))
		ft_putchar(digits[res[i]]);
	handle_post(s, s->nb_digits);
	free(digits);
}

void		handle_nb(t_print *s)
{
	intmax_t arg;

	arg = va_arg(s->ap, intmax_t);
	if (s->mod == H)
		(ft_strchr("dDi", s->flag)) ? nb_print(s, (short int)arg, INT) :
		nb_print(s, (unsigned short)arg, UINT);
	if (s->mod == HH)
		(ft_strchr("dDi", s->flag)) ? nb_print(s, (signed char)arg, INT) :
		nb_print(s, (unsigned char)arg, UINT);
	if (s->mod == L)
		(ft_strchr("dDi", s->flag)) ? nb_print(s, (long)arg, INT) :
		nb_print(s, (unsigned long)arg, UINT);
	if (s->mod == LL)
		(ft_strchr("dDi", s->flag)) ? nb_print(s, (long long)arg, INT) :
		nb_print(s, (unsigned long long)arg, UINT);
	if (s->mod == J)
		(ft_strchr("dDi", s->flag)) ? nb_print(s, arg, INT) :
		nb_print(s, (uintmax_t)arg, UINT);
	if (s->mod == Z)
		(ft_strchr("dDi", s->flag)) ? nb_print(s, arg, INT) :
		nb_print(s, (size_t)arg, UINT);
	if (s->mod == X)
		(ft_strchr("dDi", s->flag)) ? nb_print(s, (int)arg, INT) :
		nb_print(s, (unsigned int)arg, UINT);
}
