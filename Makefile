# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:18:12 by fsabatie          #+#    #+#              #
#    Updated: 2017/12/23 15:43:59 by fsabatie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

# Defining colors

RED = \033[1;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[1;36m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
WHITE = \033[0;97m

# Defining variables

NAME = libftprintf.a
SRC_PATH = libft

PRINTF_SRC =	ft_printf.c \
				ft_handlers.c \
				ft_strprint.c \
				ft_nbrprint.c

SRC_NAME =	ft_strjoin_char.c \
			ft_strjoinfree.c \
			ft_putendl_fd.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_lstdelone.c \
			ft_memalloc.c \
			ft_striteri.c \
			ft_strsplit.c \
			ft_putwchar.c \
			ft_wstrlen.c \
			ft_strnequ.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_isdigit.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_putchar.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_strncpy.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_striter.c \
			ft_strmapi.c \
			ft_putendl.c \
			ft_lstiter.c \
			ft_strnsub.c \
			ft_strcsub.c \
			ft_putwstr.c \
			ft_lstmap.c \
			ft_strsub.c \
			ft_lstnew.c \
			ft_strnew.c \
			ft_strequ.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_memdel.c \
			ft_strmap.c \
			ft_strdel.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_memcmp.c \
			ft_memchr.c \
			ft_strstr.c \
			ft_strcmp.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strstr.c \
			ft_strcat.c \
			ft_strlen.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_strrev.c \
			ft_bzero.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_abs.c

OBJ_NAME = $(SRC_NAME:.c=.o)
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
PRSRC = $(addprefix srcs/,$(PRINTF_SRC))
CPPFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(CPPFLAGS) -c $(SRC) $(PRSRC)
	@ar rc $(NAME) $(OBJ_NAME) $(PRINTF_OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ_NAME) $(PRINTF_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: fclean all clean
	@gcc $(CPPFLAGS) -o printf libftprintf.a main.c
	@make fclean
