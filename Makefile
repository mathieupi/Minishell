# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 11:30:44 by mmehran           #+#    #+#              #
#    Updated: 2021/07/08 23:49:55 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= minishell

HEADER_FILE 		= header/minishell.h

FOLDER				= src/

SRCS				= minishell.c \
						main.c

SRC					= $(addprefix ${FOLDER},${SRCS})

OBJS				= ${SRC:.c=.o}

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror -lreadline
RM					= rm -f

$(NAME):	libft ${OBJS}
			$(CC) $(CFLAGS) ${OBJS} libft/libft.a -o $(NAME)

all:		${NAME}

%.o: %.c	$(HEADER_FILE)
			$(CC) -c $(CFLAGS) -o $@ $<

libft:
			make -C ./libft

re: 		fclean all

clean:
			make -C ./libft clean
			${RM} $(OBJS_COMU) $(OBJS_BONUS) $(OBJS)

fclean:		
			make -C ./libft fclean
			${RM} $(OBJS_COMU) $(OBJS_BONUS) $(OBJS)
			${RM} $(NAME)

.PHONY: 	libft all clean fclean re
