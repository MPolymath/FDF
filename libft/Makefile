#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/28 17:47:38 by mdiouf            #+#    #+#              #
#    Updated: 2014/12/28 17:47:40 by mdiouf           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC          = gcc

NAME        = libft.a

CFLAGS = -Wall -Wextra -Werror -I./includes

SRC         = ft_atoi.c \
			   ft_bzero.c \
			   ft_isalnum.c \
			   ft_isalpha.c \
			   ft_isascii.c \
			   ft_isdigit.c \
			   ft_isprint.c \
			   ft_memccpy.c \
			   ft_memchr.c \
			   ft_memcmp.c \
			   ft_memcpy.c \
			   ft_memmove.c \
			   ft_memset.c \
			   ft_putchar.c \
			   ft_putnbr.c \
			   ft_putstr.c \
			   ft_strcat.c \
			   ft_strchr.c \
			   ft_strcmp.c \
			   ft_strcpy.c \
			   ft_strdup.c \
			   ft_strlcat.c \
			   ft_strlen.c \
			   ft_strncat.c \
			   ft_strncmp.c \
			   ft_strncpy.c \
			   ft_strnstr.c \
			   ft_strrchr.c \
			   ft_strstr.c \
			   ft_tolower.c \
			   ft_toupper.c \
			   ft_strtrim.c \
			   ft_strjoin.c \
			   ft_strsub.c \
			   ft_strnequ.c \
			   ft_strequ.c \
			   ft_strmapi.c \
			   ft_strmap.c \
			   ft_striteri.c \
			   ft_striter.c \
			   ft_strclr.c \
			   ft_strdel.c \
			   ft_strnew.c \
			   ft_memdel.c \
			   ft_memalloc.c \
			   ft_itoa.c \
			   ft_strsplit.c \
			   ft_putendl.c \
			   ft_putendl_fd.c \
			   ft_putchar_fd.c \
			   ft_putstr_fd.c \
			   ft_putnbr_fd.c \
			   ft_tablen.c \
			   ft_tabdup.c \
			   ft_print_tab.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
