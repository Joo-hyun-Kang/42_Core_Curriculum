# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 16:56:05 by jokang            #+#    #+#              #
#    Updated: 2022/05/25 21:23:23 by jokang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRCS	= server.c

CLIENT_SRCS = client.c\
			  client_utils.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

NAME = mini_talk
SERVER = server
CLIENT = client

LIBFT = libft
LIBFT_LIB = libft.a

CC	= gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -I./ -o $(<:.c=.o)

$(SERVER) : $(SERVER_OBJS)
	make all -C $(LIBFT)
	gcc -o $(SERVER) $(SERVER_OBJS) -L./libft -lft

$(CLIENT) : $(LIBFT) $(CLIENT_OBJS)
	make all -C $(LIBFT)
	gcc -o $(CLIENT) $(CLIENT_OBJS) -L./libft -lft

$(NAME) : $(SERVER) $(CLIENT)

all : $(NAME)

clean :
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
	$(RM) $(LIBFT_LIB)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY: all clean fclean re bonus
