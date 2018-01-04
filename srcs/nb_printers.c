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

static void	nb_print(t_print *s, intmax_t nbr, int mode)
{
	char	*digits;
	int		res[264];
	int		base;
	int		i;

	nbr = (mode == UINT) ? nbr : (uintmax_t)nbr;
	i = 0;
	base = get_base(s);
	digits = (s->flag == 'x') ?
	ft_strdup("0123456789abcdef") : ft_strdup("0123456789ABCDEF");
	if (nbr == 0 && (s->cnt += 1))
	{
		ft_putchar('0');
		return;
	}
	while (nbr)
	{
		res[i++] = ft_abs(nbr % base);
		nbr /= base;
	}
	while (i-- && (s->cnt += 1))
		ft_putchar(digits[res[i]]);
	free(digits);
}

void		handle_nb(t_print *s)
{
	intmax_t arg;

	arg = va_arg(s->ap, intmax_t);
	if (s->mod == H)
		(s->flag == 'd' || s->flag == 'D' || s->flag == 'i') ?
		nb_print(s, (short int)arg, INT) : nb_print(s, (unsigned short)arg, UINT);
	if (s->mod == HH)
		(s->flag == 'd' || s->flag == 'D' || s->flag == 'i') ?
		nb_print(s, (signed char)arg, INT) : nb_print(s, (unsigned char)arg, UINT);
	if (s->mod == L)
		(s->flag == 'd' || s->flag == 'D' || s->flag == 'i') ?
		nb_print(s, (long)arg, INT) : nb_print(s, (unsigned long)arg, UINT);
	if (s->mod == LL)
		(s->flag == 'd' || s->flag == 'D' || s->flag == 'i') ?
		nb_print(s, (long long)arg, INT) : nb_print(s, (unsigned long long)arg, UINT);
	if (s->mod == J)
		(s->flag == 'd' || s->flag == 'D' || s->flag == 'i') ?
		nb_print(s, arg, INT) : nb_print(s, (uintmax_t)arg, UINT);
	if (s->mod == Z)
		(s->flag == 'd' || s->flag == 'D' || s->flag == 'i') ?
		nb_print(s, arg, INT) : nb_print(s, (size_t)arg, UINT);
	if (s->mod == X)
		(s->flag == 'd' || s->flag == 'D' || s->flag == 'i') ?
		nb_print(s, (int)arg, INT) : nb_print(s, (unsigned int)arg, UINT);
}
