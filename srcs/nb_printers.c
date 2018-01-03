/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:17 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/03 11:13:19 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <inttypes.h>

static void	uint_print(intmax_t nbr)
{
	ft_putnbr(nbr);
}

static void	lint_print(uintmax_t nbr)
{
	ft_putnbr(nbr);
}

void		handle_nb(t_print *s)
{
	intmax_t arg;

	arg = va_arg(s->ap, intmax_t);
	if (s->mod == H)
		(s->flag == 'd' || s->flag == 'D' || s->flag == 'i') ?
		lint_print((short)arg) : uint_print((unsigned short)arg);
	if (s->mod == HH)
		(s->flag == 'd' || s->flag == 'D' || s->flag == 'i') ?
		lint_print((signed char)arg) : uint_print((unsigned char)arg);
	if (s->mod == L)
		(s->flag == 'd' || s->flag == 'D' || s->flag == 'i') ?
		lint_print((long)arg) : uint_print((unsigned long)arg);
	if (s->mod == LL)
		(s->flag == 'd' || s->flag == 'D' || s->flag == 'i') ?
		lint_print((long long)arg) : uint_print((unsigned long long)arg);
	if (s->mod == J)
		(s->flag == 'd' || s->flag == 'D' || s->flag == 'i') ?
		lint_print(arg) : uint_print((uintmax_t)arg);
	if (s->mod == Z)
		(s->flag == 'd' || s->flag == 'D' || s->flag == 'i') ?
		lint_print((size_t)arg) : uint_print((size_t)arg);
	if (s->mod == X)
		(s->flag == 'd' || s->flag == 'D' || s->flag == 'i') ?
		lint_print((int)arg) : uint_print(arg);
	s->format++;
}
