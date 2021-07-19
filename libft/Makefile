# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 20:33:58 by mmehran           #+#    #+#              #
#    Updated: 2021/07/20 00:37:25 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
RM 			= rm -rf
AR 			= ar rcs

OBJS 		= ft_memset.o \
				ft_bzero.o \
				ft_memcpy.o \
				ft_memccpy.o \
				ft_memmove.o \
				ft_memchr.o \
				ft_memcmp.o \
				ft_strlen.o \
				ft_strlcpy.o \
				ft_strlcat.o \
				ft_strchr.o \
				ft_strrchr.o \
				ft_strnstr.o \
				ft_strncmp.o \
				ft_atoi.o \
				ft_isalpha.o \
				ft_isdigit.o \
				ft_isalnum.o \
				ft_isascii.o \
				ft_isprint.o \
				ft_toupper.o \
				ft_tolower.o \
				ft_calloc.o \
				ft_strdup.o \
				ft_strjoin.o \
				ft_itoa.o \
				ft_substr.o \
				ft_isspace.o \
				ft_islower.o \
				ft_isupper.o \
				ft_putchar_fd.o \
				ft_putstr_fd.o \
				ft_putendl_fd.o \
				ft_putnbr_fd.o \
				ft_strtrim.o \
				ft_strmapi.o \
				ft_split.o \
				get_next_line.o \
				ft_nbrlen.o \
				ft_printf.o \
				ft_lstnew.o \
				ft_lstadd_front.o \
				ft_lstsize.o \
				ft_lstlast.o \
				ft_lstadd_back.o \
				ft_lstdelone.o \
				ft_lstclear.o \
				ft_lstiter.o \
				ft_lstmap.o

$(NAME): 	$(OBJS)
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Compiling libft 🔨\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)
			@$(AR) $@ $^
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Libft is ok ✅\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)

.c.o:
			@$(CC) $(CFLAGS) -c -o $@ $<

all: 		$(NAME)

clean:
			@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: 	clean
			@$(RM) $(NAME)

re: 		clean all

.PHONY: 	all clean fclean re

#	COLOR SETTING	############
black 				= "\e[1;30m"
red 				= "\e[1;31m"
green 				= "\e[1;32m"
yellow 				= "\e[1;33m"
blue 				= "\e[1;34m"
magenta 			= "\e[1;35m"
cyan 				= "\e[1;36m"
white 				= "\e[1;37m"

bg_black 			= "\e[40m"
bg_red 				= "\e[41m"
bg_green 			= "\e[42m"
bg_yellow 			= "\e[43m"
bg_blue 			= "\e[44m"
bg_magenta 			= "\e[45m"
bg_cyan 			= "\e[46m"
bg_white 			= "\e[47m"

reset 				= "\e[0m"
################################
