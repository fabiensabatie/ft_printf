/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:34:09 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/21 17:59:11 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <wchar.h>

size_t	ft_wstrlen(wchar_t *wstr)
{
	size_t i;

	i = 0;
	while (*wstr++)
		i++;
	return (i);
}
