# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 14:13:11 by pamoutaf          #+#    #+#              #
#    Updated: 2021/10/30 14:13:57 by pamoutaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
SRC0 = ft_client.c
SRC1 = ft_server.c
SRCS = minitalk_utils.c
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