/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:34:09 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/23 18:44:42 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{/*
	setlocale(LC_ALL, "");
	char value = 25;
	char *tr = &value;

	printf("Nombre %%i: %i\n", 25);
	ft_printf("Nombre %%i: %i\n", 25);
	printf("Nombre %%d: %d\n", 25);
	ft_printf("Nombre %%d: %d\n", 25);
	printf("Nombre %%D: %D\n", 25);
	ft_printf("Nombre %%D: %D\n", 25);
	printf("Nombre %%o: %o\n", 25);
	ft_printf("Nombre %%o: %o\n", 25);
	printf("Nombre %%x: %x\n", 25);
	ft_printf("Nombre %%x: %x\n", 25);
	printf("Nombre %%X: %X\n", 25);
	ft_printf("Nombre %%X: %X\n", 25);
	printf("Nombre %%i: %i\n", -25);
	ft_printf("Nombre %%i: %i\n", -25);
	printf("Nombre %%d: %d\n", -25);
	ft_printf("Nombre %%d: %d\n", -25);
	printf("Nombre %%D: %D\n", -25);
	ft_printf("Nombre %%D: %D\n", -25);
	printf("Nombre %%o: %o\n", -25);
	ft_printf("Nombre %%o: %o\n", -25);
	printf("Nombre %%x: %x\n", -25);
	ft_printf("Nombre %%x: %x\n", -25);
	printf("Nombre %%X: %X\n", -25);
	ft_printf("Nombre %%X: %X\n", -25);
	printf("Nombre %%i: %i\n", 2147483647 + 1);
	ft_printf("Nombre %%i: %i\n", 2147483647 + 1);
	printf("Nombre %%d: %d\n", 2147483647 + 1);
	ft_printf("Nombre %%d: %d\n", 2147483647 + 1);
	printf("Nombre %%D: %D\n", 2147483647 + 1);
	ft_printf("Nombre %%D: %D\n", 2147483647 + 1);
	printf("Nombre %%o: %o\n", 2147483647 + 1);
	ft_printf("Nombre %%o: %o\n", 2147483647 + 1);
	printf("Nombre %%x: %x\n", 2147483647 + 1);
	ft_printf("Nombre %%x: %x\n", 2147483647 + 1);
	printf("Nombre %%X: %X\n", 2147483647 + 1);
	ft_printf("Nombre %%X: %X\n", 2147483647 + 1);
	printf("Nombre %%i: %i\n", (int)-2147483648);
	ft_printf("Nombre %%i: %i\n", (int)-2147483648);
	printf("Nombre %%d: %d\n", (int)-2147483648);
	ft_printf("Nombre %%d: %d\n", (int)-2147483648);
	printf("Nombre %%D: %D\n", (int)-2147483648);
	ft_printf("Nombre %%D: %D\n", (int)-2147483648);
	printf("Nombre %%o: %o\n", (int)-2147483648);
	ft_printf("Nombre %%o: %o\n", (int)-2147483648);
	printf("Nombre %%x: %x\n", (int)-2147483648);
	ft_printf("Nombre %%x: %x\n", (int)-2147483648);
	printf("Nombre %%X: %X\n", (int)-2147483648);
	ft_printf("Nombre %%X: %X\n", (int)-2147483648);
	printf("Adresse %%p: %p\n", tr);
	ft_printf("Adresse %%p: %p\n", tr);
	printf("Unicode %%C : %C\n", L'米');
	ft_printf("Unicode %%C : %C\n", L'米');
	printf("Unicode %%S : %S\n", L"米米米米米米米米米");
	ft_printf("Unicode %%S : %S\n", L"米米米米米米米米米");
	printf("Vide %%s : %s\n", NULL);
	ft_printf("Vide %%s : %s\n", NULL);
	printf("Vide %%s : %s\n", (char*)0);
	ft_printf("Vide %%s : %s\n", (char*)0);
	printf("Nombre %%i: %.5i\n", 25);
	ft_printf("Nombre %%i: %.5i\n", 25);
	printf("Nombre %%d: %.7d\n", 25);
	ft_printf("Nombre %%d: %.7d\n", 25);
	printf("Nombre %%D: %.D\n", 25);
	ft_printf("Nombre %%D: %.D\n", 25);
	printf("Nombre %%o: %.3o\n", 25);
	ft_printf("Nombre %%o: %.3o\n", 25);
	printf("Nombre %%x: %.6x\n", 25);
	ft_printf("Nombre %%x: %.6x\n", 25);
	printf("Nombre %%X: %.78X\n", 25);
	ft_printf("Nombre %%X: %.78X\n", 25);
	printf("Nombre %%X: %5X\n", 25);
	ft_printf("Nombre %%X: %5X\n", 25);*/
	printf("@moulitest: %5.x %5.0x\n", 0, 0);
	ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);
}