/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:34:09 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/03 01:23:19 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "");

	printf("%s\n", "this is a string");
	ft_printf("%s\n", "this is a string");
	printf("%c\n", 'a');
	ft_printf("%c\n", 'a');
	printf("%S\n", L"ሴሴሴሴሴሴ");
	ft_printf("%S\n", L"ሴሴሴሴሴሴ");
	printf("%C\n", L'ሴ');
	ft_printf("%C\n", L'ሴ');
	printf("%hd\n", (short)32767);
	ft_printf("%hd\n", 32767);

}