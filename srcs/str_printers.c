/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:25 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/03 11:13:27 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <inttypes.h>

void	handle_str(t_print *s)
{
	intmax_t *arg;

	arg = NULL;
	if (s->flag == 's')
	{
		arg = (intmax_t*)(va_arg(s->ap, char*));
		s->cnt += ft_strlen((char*)arg);
		ft_putstr((char*)arg);
	}
	else if (s->flag == 'c' && (s->cnt += 1))
		ft_putchar((char)va_arg(s->ap, int));
	else if (s->flag == 'S')
	{
		arg = (intmax_t*)(va_arg(s->ap, wchar_t*));
		s->cnt += ft_wstrlen((wchar_t*)arg);
		ft_putwstr((wchar_t*)arg);
	}
	else if (s->flag == 'C' && (s->cnt += 1))
		ft_putwchar((va_arg(s->ap, wchar_t)));
}