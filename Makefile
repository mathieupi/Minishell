# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 11:30:44 by mmehran           #+#    #+#              #
#    Updated: 2021/07/09 00:12:49 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= minishell

HEADER_FILE 		= header/minishell.h

FOLDER				= src/
FOLDER_INC			= src/inc/

SRCS				= minishell.c \
						main.c

SRCS_INC			= cd.c \
						echo.c \
						env.c \
						exit.c \
						export.c \
						pwd.c \
						unset.c

SRC					= $(addprefix ${FOLDER},${SRCS})
SRC_INC				= $(addprefix ${FOLDER_INC},${SRCS_INC})

OBJS				= ${SRC:.c=.o}
OBJS_INC			= ${SRC_INC:.c=.o}

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -f
LIBS				= -L ./libft -lft -lreadline

$(NAME):	libft ${OBJS} ${OBJS_INC}
			$(CC) $(CFLAGS) ${OBJS} ${OBJS_INC} $(LIBS) -o $(NAME)

all:		${NAME}

%.o: %.c	$(HEADER_FILE)
			$(CC) -c $(CFLAGS) -o $@ $<

libft:
			make -C ./libft

re: 		fclean all

clean:
			make -C ./libft clean
			${RM} ${OBJS} ${OBJS_INC}

fclean:		
			make -C ./libft fclean
			${RM} ${OBJS} ${OBJS_INC}
			${RM} $(NAME)

.PHONY: 	libft all clean fclean re
