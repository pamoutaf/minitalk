# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrew <andrew@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 10:33:42 by acolin            #+#    #+#              #
#    Updated: 2021/10/26 19:09:02 by andrew           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
LIB = libftprintf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

SRCS_CLIENT = ft_client.c
SRCS_SERVER = ft_server.c
SRCS = ft_putchar_fd.c ft_putstr_fd.c \
		ft_strlen.c ft_atoi.c ft_putnbr_fd.c
		
OBJC = ${SRCS=.c:.o}

all: 
	${CC} ${CFlAGS} ${SRCS_SERVER} ${SRCS} -o ${NAME_SERVER}
	${CC} ${CFlAGS} ${SRCS_CLIENT} ${SRCS} -o ${NAME_CLIENT}

clean:
	 ${RM} ${OBJC}

fclean: clean
	${RM} ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all

.PHONY: all clean fclean re