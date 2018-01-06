/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:29:41 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/06 14:46:45 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <inttypes.h>
# define BEFORE 0
# define AFTER 1
# define DIGITS 0
# define POST 1
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define PURPLE		"\x1b[36m"
# define CR			"\x1b[39m"
# define BLINK		"\x1b[5m"

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
	char			*digits;
	char			flag;
	t_mod			mod;
	char			*hash;
	char			*color;
	int				blink;
	int				mfw;
	int				is_prec;
	int				prec;
	int				pad_is;
	char			pad_char;
	char			sign;
	int				base;
	int				nb_ispos;
	int				nb_digits;
	intmax_t		arg;
	size_t			cnt;
}					t_print;

int					ft_printf(const char *format, ...);
void				handle_post_digit(t_print *s, int mode, int i);
void				handle_signs(t_print *s);
void				pad(t_print *s);
void				process_flag(t_print *s);
void				handle_nb(t_print *s);
void				handle_str(t_print *s);
void				handle_bonus(t_print *s);

#endif
