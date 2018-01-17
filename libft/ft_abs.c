/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:10:34 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/09 19:10:35 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

unsigned long long	ft_abs(long long n)
{
	if (n < 0)
		return ((unsigned long long)-n);
	return ((unsigned long long)n);
}
