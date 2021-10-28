# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acolin <acolin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 10:33:42 by acolin            #+#    #+#              #
#    Updated: 2021/10/28 12:19:35 by acolin           ###   ########.fr        #
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
		ft_atoi.c ft_putnbr_fd.c

OBJC = ${SRCS:.c=.o}
OBJC_C = ${SRCS_CLIENT:.c=.o}
OBJC_S = ${SRCS_SERVER:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c ${SRCS} -o ${<:.c=.o}

all: client server
	
client:
	${CC} ${CFLAGS} ${OBJC_C} ${OBJC} -o ${NAME_CLIENT}
server:
	${CC} ${CFLAGS} ${OBJC_S} ${OBJC} -o ${NAME_SERVER}
	
clean:
	 ${RM} ${OBJC} ${OBJC_C} ${OBJC_S}

fclean: clean
	${RM} ${NAME_CLIENT} ${NAME_SERVER}

bonus:

re: fclean all

.PHONY: all clean fclean re