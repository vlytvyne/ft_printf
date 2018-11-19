# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 14:32:03 by vlytvyne          #+#    #+#              #
#    Updated: 2018/11/17 21:15:16 by vlytvyne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c get_num_str.c hash_manager.c parser.c \
plus_space_manager.c precision_manager.c width_manager.c \
zero_manager.c lib/btoa.c lib/ft_atoi.c lib/ft_isdigit.c \
lib/ft_putchar.c lib/ft_putstr.c lib/capitalize.c lib/ft_isalpha.c \
lib/ft_strchr.c lib/ft_strcpy.c lib/ft_strdup.c lib/ft_strjoin.c \
lib/ft_strlen.c lib/ft_strnew.c lib/ft_strsub.c lib/ft_tolower.c \
lib/ft_tolower.c lib/ftoa.c lib/is_whitespace.c lib/itoa_base.c \
lib/uitoa_base.c lib/ft_itoa.c lib/ft_bzero.c lib/ft_strcat.c \
lib/ft_toupper.c lib/get_abs.c lib/power.c

OBJ = $(SRC:.c=.o)

%.o: %.c libft.h header.h
	gcc $(FLAGS) -o $@ -c $< -I .

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
