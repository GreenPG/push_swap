# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 14:10:41 by gpasquet          #+#    #+#              #
#    Updated: 2022/12/16 10:06:20 by gpasquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap

LIBFT = libft/libft.a

SRC =	src/main.c \
		src/lst_functions.c \
		src/free_functions.c \
		src/parsing.c \
		src/parsing2.c \
		src/utils.c \
		src/move_functions.c \
		src/small_sort.c \
		src/index_functions.c \
		src/big_sort.c \
		src/rotation_functions.c \
		src/get_limits.c \
		src/get_elem.c \
		src/move_display.c

OBJS = ${SRC:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	$(NAME)

$(NAME):	${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

${LIBFT}:
	make -C libft

clean:
	${RM} ${OBJS}
	make clean -C libft

fclean: clean
	${RM} ${NAME}
	make fclean -C libft

re: fclean all

.PHONY:	all clean fclean re
