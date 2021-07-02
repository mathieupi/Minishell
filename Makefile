# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 11:30:44 by mmehran           #+#    #+#              #
#    Updated: 2021/07/02 11:38:02 by mmehran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBS = -L ./Libft -lft -lreadline

OBJS =
OBJS_BONUS =

ifdef WITH_BONUS
OBJS = $(OBJS_BONUS)
endif

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

clean:
	make -C ./libft clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: clean all

bonus:
	$(MAKE) WITH_BONUS=1 all

.PHONY: all clean fclean re bonus
