# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/10 15:42:56 by dzheng            #+#    #+#              #
#    Updated: 2017/02/14 18:52:08 by dzheng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIB_PATH = ./libft/
LIB = $(LIB_PATH)/libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
PATH_SRC = ./srcs/
SRCS = $(PATH_SRC)fdf.c \
		$(PATH_SRC)ft_check_tab.c

#COLORS
C_GOOD			=	"\033[32m"

#MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$

all: $(NAME)

$(NAME): 
		make -C ./libft/
		@$(CC) $(FLAGS) $(SRCS) $(LIB) -o $(NAME)
		@echo "Compiling" [ $(NAME) ] $(SUCCESS)

test:		
		@$(CC) $(FLAGS) $(SRCS) $(LIB) -o $(NAME)
		./fdf 10-2.fdf

clean:
		make -C ./libft/ clean

fclean: clean
		/bin/rm -f $(NAME)
		make -C ./libft/ fclean

re: fclean all

.PHONY: all clean fclean re