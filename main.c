/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:34:09 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/03 20:49:42 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <inttypes.h>

int main(void)
{
	setlocale(LC_ALL, "");

	printf("%\n");
	ft_printf("%\n");
	return (0);
}