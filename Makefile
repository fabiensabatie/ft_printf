# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:18:12 by fsabatie          #+#    #+#              #
#    Updated: 2018/01/06 14:43:22 by fsabatie         ###   ########.fr        #
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
OBJ_PATH = obj
INC_PATH = imcludes

PRINTF_SRC =	ft_printf.c \
				handlers.c \
				nb_printers.c \
				bonus.c

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
			ft_wstrnsub.c \
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
			ft_chrcstr.c \
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
			ft_chrstr.c \
			ft_strlen.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_strrev.c \
			ft_bzero.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_abs.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
PRINTF_OBJ = $(addprefix $(OBJ_PATH)/,$(PRINTF_SRC:.c=.o))
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
_SRC = $(addprefix ../,$(SRC))
PRSRC = $(addprefix srcs/,$(PRINTF_SRC))
_PRSRC = $(addprefix ../,$(PRSRC))

CPPFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "${GREEN}Compiling libftprintf." | tr -d '\n'
	@mkdir obj && cd obj && gcc $(CPPFLAGS) -c $(_SRC) $(_PRSRC)
	@ar rc $(NAME) $(OBJ) $(PRINTF_OBJ)
	@ranlib $(NAME)
	@echo " ${GREEN}[OK]"

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: re
	@echo "${GREEN}Compiling binary." | tr -d '\n'
	@gcc $(CPPFLAGS) -o printf main.c libftprintf.a
	@echo " ${GREEN}[OK]"
	@make fclean

tclean : fclean
	@rm -rf printf
