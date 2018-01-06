/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:13:28 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/06 16:18:25 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "includes/ft_printf.h"
#include <limits.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	printf("%lo, %lo\n", 0, 0xffffffff);
	ft_printf("%lo, %lo\n", 0, 0xffffffff);
}
