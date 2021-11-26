SRC_DIR = ./

SRCS = $(notdir $(wildcard $(SRC_DIR)*.c))

OBJS = $(SRCS:.c=.o)

DEPS = $(OBJS:.o=.d)

NAME = libft.a

CC	= gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -MD

$(NAME) : $(OBJS)
	ar rc $@ $^
	ranlib $@

clean :
	$(RM) $(OBJS) $(DEPS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
