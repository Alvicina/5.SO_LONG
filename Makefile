# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 13:32:53 by jotorral          #+#    #+#              #
#    Updated: 2023/11/24 10:04:12 by alvicina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c so_long_utils.c so_long_checkmaps.c so_long_graphics.c \
	  so_long_moves.c so_long_moves_utils.c so_long_floodfill.c \

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -Imlx #-g3 -fsanitize=address

all: lib $(NAME)

$(NAME): $(OBJ) so_long.h
	$(CC) $(FLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGl -framework AppKit -o $(NAME) 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

execute:
	./$(NAME) maps/map6.ber

clean:
	rm -rf $(OBJ)
	$(MAKE) -C mlx clean

fclean:	clean
		rm -rf $(NAME)

re: fclean all

lib:
	$(MAKE) -C mlx re

.PHONY: all execute clean fclean re lib
