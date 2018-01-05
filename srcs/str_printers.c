/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:25 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/03 16:09:53 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <inttypes.h>

static void	handle_pre(t_print *s, int len)
{
	s->mfw = (s->mfw > len) ? (s->mfw - len) : 0;
	if (s->pad_is == BEFORE)
		while (s->mfw-- > 0 && (s->cnt += 1))
			ft_putchar(' ');
}

static void	handle_char(t_print *s)
{
	handle_pre(s, 1);
	if (s->flag == 'c' && (s->cnt += 1))
		ft_putchar((char)va_arg(s->ap, int));
	else if (s->flag == 'C' && (s->cnt += 1))
		ft_putwchar((va_arg(s->ap, wchar_t)));
	else if (s->flag == '%' && (s->cnt += 1))
		ft_putchar('%');
	handle_post_digit(s, POST, 0);
}

static void	handle_wstr(t_print *s)
{
	char *arg;

	arg = NULL;
	if (!(arg = (char*)(va_arg(s->ap, wchar_t*))))
		arg = "(null)";
	if (s->is_prec)
		arg = ((int)ft_wstrlen((wchar_t*)arg) > s->prec) ?
		(char*)ft_wstrnsub((wchar_t*)arg, s->prec) : arg;
	handle_pre(s, ft_wstrlen((wchar_t*)arg));
	s->cnt += ft_wstrlen((wchar_t*)arg);
	ft_putwstr((wchar_t*)arg);
	handle_post_digit(s, POST, 0);
}

void		handle_str(t_print *s)
{
	char *arg;

	arg = NULL;
	if (s->flag == 's')
	{
		if (!(arg = (char*)(va_arg(s->ap, char*))))
			arg = "(null)";
		if (s->is_prec)
			arg = ((int)ft_strlen(arg) > s->prec) ?
			ft_strnsub(arg, s->prec) : arg;
		handle_pre(s, ft_strlen(arg));
		s->cnt += ft_strlen(arg);
		ft_putstr(arg);
		handle_post_digit(s, POST, 0);
	}
	else if (s->flag == 'S')
		handle_wstr(s);
	else
		handle_char(s);
}
