# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcahill <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 10:30:02 by fcahill           #+#    #+#              #
#    Updated: 2019/01/18 19:05:08 by fcahill          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =    ft_1validate.c		\
		 ft_create_map.c	\
		 main.c				\
		 ft_savetotable.c	\
		 ft_solver.c 		\
		 tools.c			\

OBJ = $(SRC:.c=.o)

INCLUDE = ./

CC = gcc

FLAG = -Wall -Werror -Wextra

all: $(NAME)

check:
	@make -C ./libft

$(NAME): $(OBJ) check
	@$(CC) $(FLAG) $(OBJ) ./libft/libft.a -I $(INCLUDE) -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
