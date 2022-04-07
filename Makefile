# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 19:51:29 by chandsom          #+#    #+#              #
#    Updated: 2020/11/20 17:52:51 by chandsom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC			= ft_tolower.c \
			  ft_toupper.c \
			  ft_isprint.c \
			  ft_isdigit.c \
			  ft_isascii.c \
			  ft_isalpha.c \
			  ft_isalnum.c \
			  ft_memset.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memccpy.c \
			  ft_memmove.c \
			  ft_memcmp.c \
			  ft_memchr.c \
			  ft_strlen.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strncmp.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_atoi.c \
			  ft_strlcpy.c \
			  ft_putnbr_fd.c \
			  ft_strnstr.c \
			  ft_strlcat.c \
			  ft_calloc.c \
			  ft_strdup.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_strmapi.c \
			  ft_itoa.c \
			  ft_split.c

OBJS		= $(SRC:.c=.o)

RM			= rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

all: 		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re: 		fclean all
