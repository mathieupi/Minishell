# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 11:30:44 by mmehran           #+#    #+#              #
#    Updated: 2021/07/13 14:59:31 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= minishell

HEADER_FILE 		= minishell.h \
						utils.h \
						inc.h

FOLDER				= src/
FOLDER_INC			= src/inc/
FOLDER_UTILS		= src/utils/
FOLDER_HEADER		= header/

SRCS				= minishell.c \
						main.c \
						parsing.c

SRCS_UTILS			= utils.c \
						utils2.c \
						ft_error.c \
						try_exec.c \
						ft_getenv.c

SRCS_INC			= pwd.c \
						echo.c \
						cd.c \
						env.c \
						exit.c \
						export.c \
						unset.c \

SRC					= $(addprefix ${FOLDER},${SRCS})
SRC_INC				= $(addprefix ${FOLDER_INC},${SRCS_INC})
SRC_UTILS			= $(addprefix ${FOLDER_UTILS},${SRCS_UTILS})
HEADERS				= $(addprefix ${FOLDER_HEADER},${HEADER_FILE})

OBJS				= ${SRC:.c=.o}
OBJS_INC			= ${SRC_INC:.c=.o}
OBJS_UTILS			= ${SRC_UTILS:.c=.o}

OBJ					= ${OBJS} ${OBJS_INC} ${OBJS_UTILS}

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -f
LIBS				= -L ./libft -lft -lreadline

$(NAME):	${OBJ}
			make -C ./libft
			$(CC) $(CFLAGS) ${OBJ} $(LIBS) -o $(NAME)
			@echo "\e[1;34m---------------------------"
			@echo "\e[1;35mYour best shell is ready ✅"
			@echo "\e[1;36m---------------------------\e[0m"
all:		${NAME}

%.o: %.c	$(HEADERS)
			$(CC) -c $(CFLAGS) -o $@ $<

re: 		fclean all

clean:
			make -C ./libft clean
			${RM} ${OBJ}
			@echo "\e[1;34m------------------------"
			@echo "\e[1;35mObject file is delete 🚮"
			@echo "\e[1;36m------------------------\e[0m"

fclean:
			make -C ./libft fclean
			${RM} ${OBJ} $(NAME)
			@echo "\e[1;34m-----------------------"
			@echo "\e[1;35mYour folder is clean 🧹"
			@echo "\e[1;36m-----------------------\e[0m"

.PHONY: 	all clean fclean re
