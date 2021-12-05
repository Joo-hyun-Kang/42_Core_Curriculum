# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 16:56:05 by jokang            #+#    #+#              #
#    Updated: 2021/12/05 20:22:04 by jokang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

BONUS = ft_lstnew.c

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

OBJ		= ${FILES:.c=.o}
BONUS_OBJ = ${BONUS:.c=.o}

RM		= rm -rf

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME)	: ${OBJ}
			ar rc ${NAME} ${OBJ}

all : ${NAME}
bonus: ${OBJ} ${BONUS_OBJ}
			ar rc ${NAME} ${OBJ} ${BONUS_OBJ}

clean :
			${RM} *.o 

fclean : clean
			${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
