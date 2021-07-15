# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 11:30:44 by mmehran           #+#    #+#              #
#    Updated: 2021/07/15 19:48:43 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= minishell

HEADER_FILE 		= minishell.h \
						utils.h \
						inc.h \
						parser.h

FOLDER				= src/
FOLDER_INC			= src/inc/
FOLDER_UTILS		= src/utils/
FOLDER_PARSER		= src/parser/
FOLDER_HEADER		= header/
FOLDER_CROSS		= src/cross_platform/

SRCS				= minishell.c \
						main.c \

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
						unset.c

SRCS_LINUX			= handle_linux.c

SRCS_MAC			= handle_mac.c

SRCS_PARSER			= parser.c \
						update_struct.c \
						is_valid.c \
						add_char.c \
						count_args.c \
						ft_isutil.c \
						add_arg.c \
						split_args.c

SRC					= $(addprefix ${FOLDER},${SRCS})
SRC_INC				= $(addprefix ${FOLDER_INC},${SRCS_INC})
SRC_UTILS			= $(addprefix ${FOLDER_UTILS},${SRCS_UTILS})
SRC_PARSER			= $(addprefix ${FOLDER_PARSER},${SRCS_PARSER})
HEADERS				= $(addprefix ${FOLDER_HEADER},${HEADER_FILE})
SRC_LINUX			= $(addprefix ${FOLDER_CROSS},${SRCS_LINUX})
SRC_MAC				= $(addprefix ${FOLDER_CROSS},${SRCS_MAC})

OBJS				= ${SRC:.c=.o}
OBJS_INC			= ${SRC_INC:.c=.o}
OBJS_UTILS			= ${SRC_UTILS:.c=.o}
OBJS_PARSER			= ${SRC_PARSER:.c=.o}
OBJS_LINUX			= ${SRC_LINUX:.c=.o}
OBJS_MAC			= ${SRC_MAC:.c=.o}

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -f
LIBS				= -L ./libft -lft -lreadline
LIBS_MAC			= -L/Users/$(USER)/.brew/Cellar/readline/8.1/lib/

READLINE =

COMPIL_LINE_LINUX	= $(CC) $(CFLAGS) ${OBJ} $(LIBS) -o $(NAME)
COMPIL_LINE_MAC		= $(CC) $(CFLAGS) ${OBJ} $(LIBS) $(LIBS_MAC) -o $(NAME)
COMPILE =

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	COMPILE 		= $(COMPIL_LINE_LINUX)
	CROSS			= $(OBJS_LINUX)
endif
ifeq ($(UNAME_S),Darwin)
	COMPILE			= $(COMPIL_LINE_MAC)
	READLINE		= brew reinstall readline
	CROSS			= $(OBJS_MAC)
endif

OBJ					= ${OBJS} ${OBJS_INC} ${OBJS_UTILS} ${OBJS_PARSER} ${CROSS}

$(NAME):	${OBJ}
			make -C ./libft
			$(READLINE)
			$(COMPILE)
			@printf "\e[1;34m---------------------------\n"
			@printf "\e[1;35mYour best shell is ready ✅\n"
			@printf "\e[1;36m---------------------------\e[0m\n"

all:		${NAME}

%.o: %.c	$(HEADERS)
			$(CC) -c $(CFLAGS) -o $@ $<

re: 		fclean all

clean:
			make -C ./libft clean
			${RM} ${OBJ}
			@printf "\e[1;34m---------------------------------\n"
			@printf "\e[1;35mObject files have been deleted 🚮\n"
			@printf "\e[1;36m---------------------------------\e[0m\n"

fclean:
			make -C ./libft fclean
			${RM} ${OBJ} $(NAME)
			@printf "\e[1;34m--------------------------\n"
			@printf "\e[1;35mYour folder is now clean 🧹\n"
			@printf "\e[1;36m---------------------------\e[0m\n"

.PHONY: 	all clean fclean re
