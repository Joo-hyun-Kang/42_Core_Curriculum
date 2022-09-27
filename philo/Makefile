SRCS	= 	philo.c\
			philo_utils.c\
			monitor.c\

OBJS = $(SRCS:.c=.o)

NAME = philo

CC	= gcc
CFLAGS = -Wall -Wextra -Werror -pthread -g

RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) 

all : $(NAME)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus