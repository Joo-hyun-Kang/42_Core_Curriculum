NAME = btc
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
RM = rm -f

SRCS = main.cpp \
		BitcoinExchange.cpp
		

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CXX) -o $@ $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: fclean all clean re
