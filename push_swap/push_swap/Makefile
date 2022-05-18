SRCS	= 	push_swap.c

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
