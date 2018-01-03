/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:29:41 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/03 01:09:29 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"

typedef enum	e_mod
{
	H,
	HH,
	L,
	LL,
	J,
	Z,
	X
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
