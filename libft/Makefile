# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 20:33:58 by mmehran           #+#    #+#              #
#    Updated: 2021/07/15 20:18:42 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

OBJS = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlen.o ft_strlcpy.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strnstr.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_calloc.o ft_strdup.o \
	ft_strjoin.o ft_itoa.o ft_substr.o ft_isspace.o ft_islower.o ft_isupper.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_strtrim.o ft_strmapi.o ft_split.o \
	get_next_line.o ft_nbrlen.o ft_printf.o

$(NAME): $(OBJS)
			@printf "\e[1;34m------------------\n"
			@printf "\e[1;35mCompiling libft 🔨\n"
			@printf "\e[1;36m------------------\e[0m\n"
			@$(AR) $@ $^
			@printf "\e[1;34m--------------\n"
			@printf "\e[1;35mLibft is ok ✅\n"
			@printf "\e[1;36m---------------\e[0m\n"

.c.o:
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
