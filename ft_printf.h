/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:29:41 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/28 14:31:54 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# define CM 0
# define LM 1
# define STR 2
# define CHAR 1
# define UNI_STR 4
# define UNI_CHAR 3
# define ULL unsigned long long
# define LL long long

typedef struct	s_print
{
	va_list		ap;
	char		*format;
	char		uni[4];
	int 		unisize;
	int			precision;
	int			mfw;
	int			nmfw;
	int			hash;
	int			plus;
	char		psign;
	char		pad;
	size_t		cnt;
}				t_print;

int		ft_printf(const char * format, ...);
int 	print_itoa_base(t_print *s, long long number, int base, int mode);
void 	print_str(t_print *s, char *str, int mode);
void	process_flag(t_print *s);
void	to_buffer(t_print *s, char *str);

#endif
