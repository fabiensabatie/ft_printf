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
# define CHAR 0
# define STR 1
# define WCHAR 2
# define WSTR 3
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define PURPLE		"\x1b[36m"
# define CR			"\x1b[39m"
# define BLINKON	"\x1b[5m"
# define BLINKOFF	"\x1b[25m"

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
	char			*buffer;
	char			*digits;
	char			flag;
	t_mod			mod;
	int				ptr;
	int				wchar;
	char			*hash;
	int				h;
	char			*color;
	int				blink;
	int				mfw;
	int				ip;
	int				prec;
	int				oprec;
	int				pad_is;
	char			pad_char;
	char			sign;
	int				base;
	int				nb_ispos;
	int				nb_digits;
	intmax_t		arg;
	size_t			cnt;
	int				zeros;
}					t_print;

int					ft_printf(const char *format, ...);
int					ft_sprintf(char **str, const char *format, ...);
void				ft_vprintf(t_print *s);
void				handle_post_digit(t_print *s, int mode, int i);
void				fill_buffer(t_print *s, int mode, char *str, char c);
void				wchar_tobuffer(t_print *s, wchar_t c);
void				handle_signs(t_print *s);
void				pad(t_print *s);
void				process_flag(t_print *s);
void				handle_nb(t_print *s);
void				handle_str(t_print *s);
void				handle_zero(t_print *s);
void				handle_special(t_print *s);
void				handle_bonus(t_print *s);

#endif
