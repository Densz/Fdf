# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/10 15:42:56 by dzheng            #+#    #+#              #
#    Updated: 2017/02/10 16:56:51 by dzheng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./mlx

SRC = fdf.c

OBJDIR = objs

CFLAGS = -Wall -Wextra -Werror

CC = gcc

OBJ = $(addprefix ${OBJDIR}/, $(SRC:.c=.o))

all:${NAME}

${NAME}: ${OBJ}
	@make -C libft/
	@echo Compiling ${NAME}
	@${CC} ${CFLAGS} -Ilibft -Llibft/ -lft -I. -o $@ ${OBJ}
	@echo "\033[32m./mlx is ready!\033[0m"

${OBJDIR}/%.o : ./srcs/%.c
	@echo Compiling $@
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -Ilibft -I. -c -o $@ $<

clean:
	@echo clean libft...
	@make -C libft/ clean
	@echo clean objs...
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@echo fclean libft...
	@make -C libft/ fclean
	@echo clean ${NAME}...
	@/bin/rm -f ${NAME} test

test:
	@${CC} -I./libft/ -Llibft/ -lft -I. -g -o ${NAME} \
	$(addprefix srcs/, ${SRC})

re: fclean all

build: ${OBJ}

.PHONY: all clean fclean re test