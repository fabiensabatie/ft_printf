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
# include "../libft/libft.h"

typedef enum	e_mod
{ 	H = 0,
	HH = 1,
	L = 2,
	LL = 3,
	J = 4,
	Z = 5
}				t_mod;

typedef struct		s_print
{
	va_list			ap;
	char			*format;
	char			flag;
	t_mod			mod;
	size_t			cnt;
}					t_print;

int					ft_printf(const char * format, ...);
void	process_flag(t_print *s);

#endif
