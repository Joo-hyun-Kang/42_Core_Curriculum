# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 16:56:05 by jokang            #+#    #+#              #
#    Updated: 2022/05/30 16:14:08 by jokang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	arraylist.c\
			get_next_line_bonus.c\
			get_next_line_utils_bonus.c\
			image.c\
			map.c\
			move.c\
			play.c\
			so_long.c

OBJS = $(SRCS:.c=.o)

NAME = so_long
LIBFT = libft
LIBFT_LIB = libft.a

CC	= gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -I./ -o $(<:.c=.o)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	gcc -o $(NAME) $(OBJS) -Llibft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY: all clean fclean re bonus
