/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:34:09 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/23 20:58:27 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

/*
** 						~ CONVERSION SPECIFIER ~
** A character that specifies the type of conversion to be applied
** if the character following % is a % then is it acts as an ESC char
** The conversion specifiers and their meanings are:
** 1) d, i, D : signed int
** 2) o, u, x, X : unsigned octal, uns. decimal, uns. hexa lower and uppercase
** 3) b, B for unsigned binary
** 3) c, C : char and large char
** 4) s : pointer to a string

'#'         The value should be converted to an ``alternate form''.
For c, d, i, n, p, s, and u conversions, this option has no
effect.  For o conversions, the precision of the number is
increased to force the first character of the output string
to a zero.  For x and X conversions, a non-zero result has
the string `0x' (or `0X' for X conversions) prepended to
it.  For a, A, e, E, f, F, g, and G conversions, the result
will always contain a decimal point, even if no digits fol-
low it (normally, a decimal point appears in the results of
those conversions only if a digit follows).  For g and G
conversions, trailing zeros are not removed from the result
as they would otherwise be.

'0' (zero)   Zero padding.  For all conversions except n, the converted
value is padded on the left with zeros rather than blanks.
If a precision is given with a numeric conversion (d, i, o,
u, i, x, and X), the 0 flag is ignored.

'-'          A negative field width flag; the converted value is to be
left adjusted on the field boundary.  Except for n conver-
sions, the converted value is padded on the right with
blanks, rather than on the left with blanks or zeros.  A -
overrides a 0 if both are given.

' ' (space)  A blank should be left before a positive number produced by
a signed conversion (a, A, d, e, E, f, F, g, G, or i).

'+'          A sign must always be placed before a number produced by a
signed conversion.  A + overrides a space if both are used.

An optional decimal digit string specifying a minimum field width.  If
the converted value has fewer characters than the field width, it will
be padded with spaces on the left (or right, if the left-adjustment flag
has been given) to fill out the field width.

An optional precision, in the form of a period . followed by an optional
digit string.  If the digit string is omitted, the precision is taken as
zero.  This gives the minimum number of digits to appear for d, i, o, u,
x, and X conversions, the number of digits to appear after the decimal-
point for a, A, e, E, f, and F conversions, the maximum number of sig-
nificant digits for g and G conversions, or the maximum number of char-
acters to be printed from a string for s conversions.
*/
void 	handle_spec(t_print *s)
{
	s->pad = ' ';
	s->precision = -1;
	s->mfw = 0;
	while (*s->format == ' ' && (s->format += 1) && (s->plus = 1))
		s->psign = ' ';
	if (*s->format == '-' && (s->format += 1))
		s->nmfw = 1;
	if (*s->format == '#' && (s->format += 1))
		s->hash = 1;
	if (ft_isdigit(*s->format))
	{
		while (*s->format == '0' && (s->format += 1) && !s->nmfw)
			s->pad = '0';
		s->mfw = ft_atoi(s->format);
		if (s->mfw)
			while (ft_isdigit(*s->format))
				s->format++;
	}
	while (*s->format == '+' && (s->format += 1) && (s->plus = 1))
		s->psign = '+';
	if (*s->format == '.' && (s->format += 1))
	{
		if (ft_isdigit(*s->format))
		{
			s->precision = ft_atoi(s->format);
			if (s->precision >= 0)
				s->format += ft_strlen(ft_itoa(s->precision));
		}
	}
	while (*s->format == ' ')
		s->format++;
}

intmax_t	get_arg(t_print *s)
{
	intmax_t	nbr;

	nbr = va_arg(s->ap, intmax_t);

	if (*s->format == 'h' && (s->format += 1))
		nbr = (*s->format++ == 'h' && (s->format += 1)) ?
		(unsigned char)nbr : (unsigned short int)nbr;
	else if (*s->format == 'l' && (s->format += 1))
		nbr = (*s->format++ == 'l' && (s->format += 1)) ?
		(unsigned long int)nbr : (unsigned long long int)nbr;
	else if (*s->format == 'j' && (s->format += 1))
		nbr = (intmax_t)nbr;
	else if (*s->format == 'z' && (s->format += 1))
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

void	process_flag(t_print *s)
{
	s->format += 1;
	handle_spec(s);
	if (*s->format == 'c')
		print_str(s, va_arg(s->ap, char*), CHAR);
	else if (*s->format == 'o')
		print_itoa_base(s, (LL)ft_abs(va_arg(s->ap, LL)), 8, CM);
	else if (*s->format == 'x')
		print_itoa_base(s, (LL)ft_abs(va_arg(s->ap, LL)), 16, LM);
	else if (*s->format == 'X')
		print_itoa_base(s, (LL)ft_abs(va_arg(s->ap, LL)), 16, CM);
	else if (*s->format == 'd')
		print_itoa_base(s, (LL)va_arg(s->ap, int), 10, CM);
	else if (*s->format == 'i')
		print_itoa_base(s, (LL)va_arg(s->ap, int), 10, CM);
	else if (*s->format == 'D')
		print_itoa_base(s, (LL)ft_abs(va_arg(s->ap, LL)), 10, CM);
	else if (*s->format == 'p')
		ft_printf("0x7fff%x", (LL)ft_abs(va_arg(s->ap, LL)));
	else if (*s->format == 's')
		print_str(s, va_arg(s->ap, char*), STR);
	else if (*s->format == 'C')
		print_str(s, (char*)va_arg(s->ap, wchar_t*), UNI_CHAR);
	else if (*s->format == 'S')
		print_str(s, (char*)va_arg(s->ap, wchar_t*), UNI_STR);
	else if (*s->format == '%')
		print_str(s, (char*)'%', CHAR);
	s->format += 1;
}