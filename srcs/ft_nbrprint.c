/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:34:09 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/23 21:08:37 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int	print_itoa_base(t_print *s, long long number, int base, int mode)
{
	char *digits;
	int res[128];
	long long n;
	int cur;
	int i;

	i = 0;
	digits = (mode == CM) ?
		ft_strdup("0123456789ABCDEFGH") : ft_strdup("0123456789abcdefgh");
	n = (number < 0) ? -number : number;
	while (n != 0)
	{
		res[i++] = ft_abs(n % base);
		n /= base;
	}
	cur = i;
	n = (s->mfw) ? (LL)s->mfw : (LL)s->precision;
	if (s->hash && s->pad == '0' && (number != 0) && (n -= 2) && (s->cnt += 2))
		(mode == CM) ? ft_putstr("0X") : ft_putstr("0x");
	if (number < 0 && (s->cnt += 1) && (cur += 1))
		ft_putchar('-');
	else if (s->plus && (s->cnt += 1) && (cur += 1))
		ft_putchar(s->psign);
	if (!(s->nmfw) && s->mfw)
		while (n-- > (LL)cur && (s->cnt += 1))
			ft_putchar(s->pad);
	if (number == 0 && (s->cnt += 1))
	{
		ft_putnbr(0);
		return (0);
	}
	if (s->hash && (number != 0) && (s->pad != '0') && (s->cnt += 2) && (n -= 2))
		(mode == CM) ? ft_putstr("0X") : ft_putstr("0x");
	while (i-- && (s->cnt += 1))
		ft_putchar(digits[res[i]]);
	if (s->nmfw && s->mfw)
		while (n-- > (LL)cur && (s->cnt += 1))
		{
			ft_putchar(s->pad);
		}
	free(digits);
	return (0);
}