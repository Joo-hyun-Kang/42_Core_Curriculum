SRCS =	main.cpp\
		ClapTrap.cpp\
		ScavTrap.cpp\

OBJS = $(SRCS:.cpp=.o)

NAME = ScavTrap

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re .cpp.o
