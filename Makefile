# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 11:30:44 by mmehran           #+#    #+#              #
#    Updated: 2021/07/09 02:40:28 by bledda           ###   ########.fr        #
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
						unset.c

ECHO_FILE			= echo.c
PWD_FILE			= pwd.c

SRC					= $(addprefix ${FOLDER},${SRCS})
SRC_INC				= $(addprefix ${FOLDER_INC},${SRCS_INC})
ECHO_INC			= $(addprefix ${FOLDER_INC},${ECHO_FILE})
PWD_INC				= $(addprefix ${FOLDER_INC},${PWD_FILE})

OBJS				= ${SRC:.c=.o}
OBJS_INC			= ${SRC_INC:.c=.o}
OBJS_ECHO			= ${ECHO_INC:.c=.o}
OBJS_PWD			= ${PWD_INC:.c=.o}

ECHO				= $(FOLDER_INC)echo
PWD					= $(FOLDER_INC)pwd

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -f
LIBS				= -L ./libft -lft -lreadline

$(NAME):	$(ECHO) $(PWD) ${OBJS} ${OBJS_INC}
			make -C ./libft
			$(CC) $(CFLAGS) ${OBJS} ${OBJS_INC} $(LIBS) -o $(NAME)

all:		${NAME}

%.o: %.c	$(HEADER_FILE)
			$(CC) -c $(CFLAGS) -o $@ $<

$(ECHO):	$(OBJS_ECHO)
			make -C ./libft
			$(CC) $(CFLAGS) ${OBJS_ECHO} $(LIBS) -o $(ECHO)

$(PWD):		$(OBJS_PWD)
			make -C ./libft
			$(CC) $(CFLAGS) ${OBJS_PWD} $(LIBS) -o $(PWD)

re: 		fclean all

clean:
			make -C ./libft clean
			${RM} ${OBJS} ${OBJS_INC} ${OBJS_ECHO} ${OBJS_PWD}

fclean:		
			make -C ./libft fclean
			${RM} ${OBJS} ${OBJS_INC} ${OBJS_ECHO} ${OBJS_PWD}
			${RM} $(NAME) $(ECHO) ${PWD}

.PHONY: 	all clean fclean re

