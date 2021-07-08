# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 11:30:44 by mmehran           #+#    #+#              #
#    Updated: 2021/07/09 01:35:41 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= minishell

HEADER_FILE 		= header/minishell.h

FOLDER				= src/
FOLDER_INC			= src/inc/

SRCS				= minishell.c \
						main.c

SRCS_INC			= cd.c \
						env.c \
						exit.c \
						export.c \
						pwd.c \
						unset.c

ECHO_FILE			= echo.c

SRC					= $(addprefix ${FOLDER},${SRCS})
SRC_INC				= $(addprefix ${FOLDER_INC},${SRCS_INC})
ECHO_INC			= $(addprefix ${FOLDER_INC},${ECHO_FILE})

OBJS				= ${SRC:.c=.o}
OBJS_INC			= ${SRC_INC:.c=.o}
OBJS_ECHO			= ${ECHO_INC:.c=.o}

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -f
LIBS				= -L ./libft -lft -lreadline

$(NAME):	libft echo ${OBJS} ${OBJS_INC}
			$(CC) $(CFLAGS) ${OBJS} ${OBJS_INC} $(LIBS) -o $(NAME)

all:		${NAME}

%.o: %.c	$(HEADER_FILE)
			$(CC) -c $(CFLAGS) -o $@ $<

libft:
			make -C ./libft

echo:		libft 
			$(CC) $(CFLAGS) ${ECHO_INC} $(LIBS) -o ${FOLDER_INC}echo

re: 		fclean all

clean:
			make -C ./libft clean
			${RM} ${OBJS} ${OBJS_INC} ${OBJS_ECHO}

fclean:		
			make -C ./libft fclean
			${RM} ${OBJS} ${OBJS_INC} ${OBJS_ECHO}
			${RM} $(NAME) ${FOLDER_INC}echo

.PHONY: 	libft echo all clean fclean re

