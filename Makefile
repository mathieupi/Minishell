# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 11:30:44 by mmehran           #+#    #+#              #
#    Updated: 2021/07/09 21:16:08 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= minishell

HEADER_FILE 		= header/minishell.h

FOLDER				= src/
FOLDER_INC			= src/inc/

SRCS				= minishell.c \
						main.c

SRCS_INC			= pwd.c \
						echo.c \
						cd.c \
						env.c \
						exit.c \
						export.c \
						unset.c

SRC					= $(addprefix ${FOLDER},${SRCS})
SRC_INC				= $(addprefix ${FOLDER_INC},${SRCS_INC})

OBJS				= ${SRC:.c=.o}
OBJS_INC			= ${SRC_INC:.c=.o}

ECHO				= $(FOLDER_INC)echo

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -f
LIBS				= -L ./libft -lft -lreadline

$(NAME):	${OBJS} ${OBJS_INC}
			make -C ./libft
			$(CC) $(CFLAGS) ${OBJS} ${OBJS_INC} $(LIBS) -o $(NAME)

all:		${NAME}

%.o: %.c	$(HEADER_FILE)
			$(CC) -c $(CFLAGS) -o $@ $<

re: 		fclean all

clean:
			make -C ./libft clean
			${RM} ${OBJS} ${OBJS_INC}

fclean:		
			make -C ./libft fclean
			${RM} ${OBJS} ${OBJS_INC}
			${RM} $(NAME)

.PHONY: 	all clean fclean re

