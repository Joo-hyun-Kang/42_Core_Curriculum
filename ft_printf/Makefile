# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:32:34 by jokang            #+#    #+#              #
#    Updated: 2022/03/24 14:11:19 by jokang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	ft_printf.c\
			ft_printf_utils.c\

OBJS = $(SRCS:.c=.o)

OBJS_FILES = $(OBJS)

NAME = libftprintf.a

CC	= gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS_FILES)
	ar rc $@ $^

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
