# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcahill <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 10:30:02 by fcahill           #+#    #+#              #
#    Updated: 2019/01/16 19:57:41 by fcahill          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

SRCS = ft_1validate.c \
	   ft_create_map.c \
	   ft_savetotable.c \
	   ft_solver.c \
	   ft_freearray.c \
	   tools.c \
	   main.c \

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

HEADER = -I libft/

LIB = libft/ 

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	@make -C libft/ && make clean -C libft/
	$(CC) -o $(NAME) $(OBJ) -L $(LIB) -lft

clean: 
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
