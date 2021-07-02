# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 11:30:44 by mmehran           #+#    #+#              #
#    Updated: 2021/07/02 14:27:39 by mmehran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBS = -L ./Libft -lft -lreadline

OBJS = main.o minishell.o
OBJS_BONUS =

ifdef WITH_BONUS
OBJS = $(OBJS_BONUS)
endif

$(NAME): $(OBJS)
	make -C ./Libft
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

clean:
	make -C ./Libft clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C ./Libft fclean
	$(RM) $(NAME)

re: clean all

bonus:
	$(MAKE) WITH_BONUS=1 all

.PHONY: all clean fclean re bonus
