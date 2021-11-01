# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 14:13:11 by pamoutaf          #+#    #+#              #
#    Updated: 2021/11/01 18:23:23 by pamoutaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
SRC_CLIENT = ft_client.c
SRC_SERVER = ft_server.c
SRCS = minitalk_utils.c
GCC = gcc -Wall -Wextra -Werror -fsanitize=address
OBJS_CLT = $(SRC_CLIENT:.c=.o)
OBJS_SRV = $(SRC_SERVER:.c=.o)
OBJS_SRCS = $(SRCS:.c=.o)
RM = rm -rf

%.o: %.c
		gcc -c -o $@ $<

all: $(SERVER) $(CLIENT)

$(NAME):	all

$(SERVER):	$(OBJS_SRCS)
			$(GCC) -c $(SRC_SERVER) $(SRCS)
			$(GCC) -o $(SERVER) $(OBJS_SRV) $(OBJS_SRCS)

$(CLIENT):	$(OBJS_SRCS)
			$(GCC) -c $(SRC_CLIENT) $(SRCS)
			$(GCC) -o $(CLIENT) $(OBJS_CLT) $(OBJS_SRCS)

clean:  
		$(RM) $(OBJS_SRV) $(OBJS_CLT) $(OBJS_SRCS)

fclean: clean
		$(RM) $(SERVER) $(CLIENT)

re: fclean all