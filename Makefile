# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 10:33:42 by pamoutaf          #+#    #+#              #
#    Updated: 2021/10/28 18:55:18 by pamoutaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
SRC0 = ft_client.c
SRC1 = ft_server.c
SRCS = ft_putchar_fd.c ft_putstr_fd.c \
		ft_atoi.c ft_putnbr_fd.c
GCC = gcc -Wall -Wextra -Werror -fsanitize=address
OBJS_CLT = $(SRC0:.c=.o)
OBJS_SRV = $(SRC1:.c=.o)
OBJS_SRCS = $(SRCS:.c=.o)
RM = rm -rf

all: $(SERVER) $(CLIENT)

$(NAME):	all

$(SERVER):
		$(GCC) -c $(SRC1) $(SRCS)
		$(GCC) -o $(SERVER) $(OBJS_SRV) $(OBJS_SRCS)

$(CLIENT):
		$(GCC) -c $(SRC0) $(SRCS)
		$(GCC) -o $(CLIENT) $(OBJS_CLT) $(OBJS_SRCS)

clean:  
		$(RM) $(OBJS_SRV) $(OBJS_CLT) $(OBJS_SRCS)

fclean: clean
		$(RM) $(SERVER) $(CLIENT)

re: fclean all