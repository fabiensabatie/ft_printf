/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:34:09 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/23 18:50:11 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int ft_printf(const char *format, ...)
{
	t_print	s;

	ft_bzero(&s, sizeof(s));
	s.format = ft_strdup((char *)format);
	va_start(s.ap, format);
	while (*s.format)
	{
		if (*s.format == '%')
			process_flag(&s);
		else if ((s.cnt += 1))
			ft_putchar(*(s.format)++);
	}
	va_end(s.ap);
	return (s.cnt);
}