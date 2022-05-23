# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 16:56:05 by jokang            #+#    #+#              #
#    Updated: 2022/05/21 22:38:01 by jokang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	arraylist.c\
			command.c\
			command_queue.c\
			command_three.c\
			command_two.c\
			ft_stack_fuction.c\
			ft_stack_fuction_two.c\
			libft_chagned.c\
			libft_utils.c\
			libft_utils_two.c\
			push_swap.c\
			push_swap_utils.c\
			quick_sort.c\
			sort.c\
			sort_swap.c\
			sort_swap_sec.c\
			sort_swap_third.c\
			sort_utils.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap
LIBFT = libft
LIBFT_LIB = libft.a

CC	= gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -I./ -o $(<:.c=.o)

$(NAME) : $(OBJS)
	make all -C $(LIBFT) /
	gcc -o $(NAME) $(OBJS) -Llibft -lft

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
