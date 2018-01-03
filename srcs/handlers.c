/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/03 11:14:00 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void	get_modifiers(t_print *s)
{
	if (*s->format == 'h')
		(*(s->format + 1) == 'h' && (s->format += 1)) ?
		(s->mod = HH) : (s->mod = H);
	else if (*s->format == 'l')
		(*(s->format + 1) == 'l' && (s->format += 1)) ?
		(s->mod = LL) : (s->mod = L);
	else if (*s->format == 'j')
		s->mod = J;
	else if (*s->format == 'z')
		s->mod = Z;
	else
		s->mod = X;
	s->format++;
}

// TODO: Rediriger les nombres vers les fonctions qui vont bien,
// ainsi que les strings.

void		process_flag(t_print *s)
{
	s->flag = ft_chrstr("sSpdDioOuUxXcC%", s->format);
	get_modifiers(s);
	if (ft_strchr("dDioOuUxXp", s->flag))
		handle_nb(s);
	else if (ft_strchr("sScC", s->flag))
		handle_str(s);
	else if (s->flag == '%')
		ft_putchar('%');
}
