# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acolin <acolin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 10:33:42 by acolin            #+#    #+#              #
#    Updated: 2021/10/25 16:02:28 by acolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
LIB = libftprintf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rf -f

SRCS_CLIENT = ft_client.c
SRCS_SERVER = ft_server.c
SRCS = ft_putchar_fd.c ft_putstr_fd.c \
		ft_strlen.c ft_atoi.c ft_putnbr_fd.c
		
OBJC = ${SRCS=.c:.o}

all: 
	${CC} ${CFlAG} ${SRCS_SERVER} ${SRCS} -o ${NAME_SERVER}
	${CC} ${CFlAG} ${SRCS_CLIENT} ${SRCS} -o ${NAME_CLIENT}

clean:
	 ${RM} ${OBJC}

fclean: clean
	${RM} ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all

.PHONY: all clean fclean re