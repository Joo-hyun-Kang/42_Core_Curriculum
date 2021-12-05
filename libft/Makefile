# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 16:56:05 by jokang            #+#    #+#              #
#    Updated: 2021/12/05 19:52:39 by jokang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS	=	ft_lstnew.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libft.a

CC	= gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

ifdef WITH_BONUS
		OBJS_SWITCH = $(OBJS_BONUS) $(OBJS)
else
		OBJS_SWITCH = $(OBJS)
endif

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -MD

$(NAME) : $(OBJS_SWITCH)
	ar rcu $@ $^
	ranlib $@

all : $(NAME)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus : 
	$(MAKE) WITH_BONUS=1 $(NAME)

.PHONY: all clean fclean re bonus
