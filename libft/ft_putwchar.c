/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:34:09 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/03 01:30:37 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putwchar(wchar_t c)
{
	char uni[5];

	if (!c)
		return ;
	if (c < 0x7F && (uni[4] = 1))
		uni[0] = c;
	else if (c <= 0x7FF && (uni[4] = 2))
	{
		uni[0] = (c >> 6) | 0xc0;
		uni[1] = (c & 0x3f) | 0x80;
	}
	else if (c <= 0xFFFF && (uni[4] = 3))
	{
		uni[0] = (c >> 12) | 0xe0;
		uni[1] = ((c >> 6) & 0x3f) | 0x80;
		uni[2] = (c & 0x3f) | 0x80;
	}
	else if (c <= 0x1FFFFFF && (uni[4] = 4))
	{
		uni[0] = (c >> 18) | 0xf0;
		uni[1] = ((c >> 12) & 0x3f) | 0x80;
		uni[2] = ((c >> 6) & 0x3f) | 0x80;
		uni[3] = (c & 0x3f) | 0x80;
	}
	write(1, uni, uni[4]);
}
