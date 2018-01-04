/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:34:09 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/03 13:20:02 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
# include <stdarg.h>
# include <stdlib.h>

int			ft_printf(const char *format, ...)
{
	t_print	s;

	ft_bzero(&s, sizeof(s));
	s.format = ft_strdup((char *)format);
	va_start(s.ap, format);
	while (*s.format)
	{
		if (*s.format == '%' && (s.format += 1))
			process_flag(&s);
		else if ((s.cnt += 1))
			ft_putchar(*s.format++);
	}
	va_end(s.ap);
	return (s.cnt);
}