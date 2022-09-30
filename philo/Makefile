# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jokang <jokang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 17:32:17 by jokang            #+#    #+#              #
#    Updated: 2022/09/30 21:29:34 by jokang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	main.c\
			philo.c\
			philo_action.c\
			philo_death.c\
			philo_fork.c\
			utils.c\
			monitor.c\
			fork.c\

OBJS = $(SRCS:.c=.o)

NAME = philo

CC	= cc
CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
