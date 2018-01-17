/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:39:36 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/17 14:39:38 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/ft_printf.h"
#include <stdio.h>
#include <locale.h>

int		main(void)
{
	int				free = 42;

	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", ft_printf("@moulitest: %#X %#X", 5, 5));
	printf(" : %d chars.\n", printf("@moulitest: %#X %#X", 5, 5));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", ft_printf("@moulitest: %#.X %#.0X", 5, 5));
	printf(" : %d chars.\n", printf("@moulitest: %#.X %#.0X", 5, 5));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", ft_printf("@moulitest: %#.X %#.0X", 10, 10));
	printf(" : %d chars.\n", printf("@moulitest: %#.X %#.0X", 10, 10));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", ft_printf("@moulitest: %#12.X %#12.0X", 10, 10));
	printf(" : %d chars.\n", printf("@moulitest: %#12.X %#12.0X", 10, 10));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", ft_printf("@moulitest: %#-5X %#-5X", 5, 5));
	printf(" : %d chars.\n", printf("@moulitest: %#-5X %#-5X", 5, 5));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", ft_printf("@moulitest: %#-10.X %#-10.0X", 5, 5));
	printf(" : %d chars.\n", printf("@moulitest: %#-10.X %#-10.0X", 5, 5));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", ft_printf("@moulitest: %#-1.X %#-1.0X", 10, 10));
	printf(" : %d chars.\n", printf("@moulitest: %#-1.X %#-1.0X", 10, 10));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", ft_printf("@moulitest: %#-12.X %#-12.0X", 10, 10));
	printf(" : %d chars.\n", printf("@moulitest: %#-12.X %#-12.0X", 10, 10));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%12d, %-3.0d", 50, 50));
	printf(" : %d chars.\n", ft_printf("%23.p, %-10.0p", 0, 0));
	ft_putendl("-------------------------------------------------------------");
	setlocale(LC_ALL, "");
	printf(" : %d chars.\n", ft_printf("%s %C %d %p %x %% %S", "bonjour ", 0x2622, 42, &free, 42, L"ο Δικαιοπολ"));
	printf(" : %d chars.\n", printf("%s %C %d %p %x %% %S", "bonjour ", 0x2622, 42, &free, 42, L"ο Δικαιοπολ"));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", ft_printf("%10S", L"Δικαιοπολις"));
	printf(" : %d chars.\n", printf("%10S", L"Δικαιοπολις"));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", ft_printf("%#.3o", 12));
	printf(" : %d chars.\n", printf("%#.3o", 12));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", ft_printf("%#o", 42));
	printf(" : %d chars.\n", printf("%#o", 42));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", ft_printf("%#0.o", 0));
	printf(" : %d chars.\n", printf("%#0.o", 0));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%% %%%%% %%%"));
	printf(" : %d chars.\n", ft_printf("%%%% %%%%%"));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%d %10% %s", 0, "salut"));
	printf(" : %d chars.\n", ft_printf("%d %10% %s", 0, "salut"));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%d %10% %*.*d", 0, 12, 15, 145));
	printf(" : %d chars.\n", ft_printf("%d %10% %*.*d", 0, 12, 15, 145));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%*.*s is a string", 0, 0, "this"));
	printf(" : %d chars.\n", ft_printf("%*.*s is a string", 0, 0, "this"));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("{%3d}", 0));
	printf(" : %d chars.\n", ft_printf("{%3d}", 0));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%s, %------3.3s", NULL, NULL));
	printf(" : %d chars.\n", ft_printf("%s, %------3.3s", NULL, NULL));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%.0s, %.0s", NULL, "salut"));
	printf(" : %d chars.\n", ft_printf("%.0s, %.0s", NULL, "salut"));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%.s, %.s", NULL, "salut"));
	printf(" : %d chars.\n", ft_printf("%.s, %.s", NULL, "salut"));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%d, %-3.3d", 12, 23));
	printf(" : %d chars.\n", ft_printf("%d, %-3.3d", 12, 23));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%12d, %-3.0d", 0, 0));
	printf(" : %d chars.\n", ft_printf("%12d, %-3.0d", 0, 0));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%#8x", 42));
	printf(" : %d chars.\n", ft_printf("%#8x", 42));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%#08x", 42));
	printf(" : %d chars.\n", ft_printf("%#08x", 42));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", ft_printf("@moulitest: %#x %#x", 0, 0));
	printf(" : %d chars.\n", printf("@moulitest: %#x %#x", 0, 0));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", ft_printf("{%16p}", &free));
	printf(" : %d chars.\n", printf("{%16p}", &free));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("@moulitest: %#2.x %#2.0x", 10, 10));
	printf(" : %d chars.\n", ft_printf("@moulitest: %#2.x %#2.0x", 10, 10));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("@moulitest: %#.o %#.0o", 10, 10));
	printf(" : %d chars.\n", ft_printf("@moulitest: %#.o %#.0o", 10, 10));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("@moulitest: %#2.o %#2.0o", 10, 10));
	printf(" : %d chars.\n", ft_printf("@moulitest: %#2.o %#2.0o", 10, 10));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("@moulitest: %.o %.0o", 0, 0));
	printf(" : %d chars.\n", ft_printf("@moulitest: %.o %.0o", 0, 0));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("@moulitest: %5.o %5.0o", 0, 0));
	printf(" : %d chars.\n", ft_printf("@moulitest: %5.o %5.0o", 0, 0));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("@moulitest: %.d %.0d", 0, 0));
	printf(" : %d chars.\n", ft_printf("@moulitest: %.d %.0d", 0, 0));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("@moulitest: %5.d %5.0d", 0, 0));
	printf(" : %d chars.\n", ft_printf("@moulitest: %5.d %5.0d", 0, 0));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("@moulitest: %.o %.0o", 10, 10));
	printf(" : %d chars.\n", ft_printf("@moulitest: %.o %.0o", 10, 10));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("@moulitest: %5.o %5.0o", 10, 10));
	printf(" : %d chars.\n", ft_printf("@moulitest: %5.o %5.0o", 10, 10));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("@moulitest: %.d %.0d", 10, 10));
	printf(" : %d chars.\n", ft_printf("@moulitest: %.d %.0d", 10, 10));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("@moulitest: %5.d %5.0d", 10, 10));
	printf(" : %d chars.\n", ft_printf("@moulitest: %5.d %5.0d", 10, 10));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("@moulitest: %.o %.0o", 10, 10));
	printf(" : %d chars.\n", ft_printf("@moulitest: %.o %.0o", 10, 10));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("@moulitest: %5.o %5.0o", 10, 10));
	printf(" : %d chars.\n", ft_printf("@moulitest: %5.o %5.0o", 10, 10));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("@moulitest: % 10.5d", 4242));
	printf(" : %d chars.\n", ft_printf("@moulitest: % 10.5d", 4242));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%10s is a string", "this"));
	printf(" : %d chars.\n", ft_printf("%10s is a string", "this"));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%5.2s is a string", "this"));
	printf(" : %d chars.\n", ft_printf("%5.2s is a string", "this"));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%10s is a string", ""));
	printf(" : %d chars.\n", ft_printf("%10s is a string", ""));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%5.2s is a string", ""));
	printf(" : %d chars.\n", ft_printf("%5.2s is a string", ""));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%-10s is a string", "this"));
	printf(" : %d chars.\n", ft_printf("%-10s is a string", "this"));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%-5.2s is a string", "this"));
	printf(" : %d chars.\n", ft_printf("%-5.2s is a string", "this"));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%-10s is a string", ""));
	printf(" : %d chars.\n", ft_printf("%-10s is a string", ""));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("{% 03d}", 0));
	printf(" : %d chars.\n", ft_printf("{% 03d}", 0));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%.C", 0));
	printf(" : %d chars.\n", ft_printf("%.C", 0));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%-24.0d, %-22.d", 0, 0));
	printf(" : %d chars.\n", ft_printf("%-24.0d, %-22.d", 0, 0));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%-26.d, %.0d", 0, 0));
	printf(" : %d chars.\n", ft_printf("%-26.d, %.0d", 0, 0));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%4.0d, %.d", 0, 0));
	printf(" : %d chars.\n", ft_printf("%4.0d, %.d", 0, 0));
	ft_putendl("-------------------------------------------------------------");
	printf(" : %d chars.\n", printf("%6.d, %.0d", 0, 0));
	printf(" : %d chars.\n", ft_printf("%6.d, %.0d", 0, 0));
	ft_putendl("-------------------------------------------------------------");
}