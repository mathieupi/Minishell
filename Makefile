# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 11:30:44 by mmehran           #+#    #+#              #
#    Updated: 2021/07/16 11:57:36 by mmehran          ###   ########.fr        #
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
						ft_getenv.c \
						print_array.c

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
						split_args.c \
						is_inhibited.c \
						trim_arg.c \
						sub_env.c

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
MAKE_EXT			= @make -s --no-print-directory -C
LIBS				= -L ./libft -lft -lreadline
LIBS_MAC			= -L/Users/$(USER)/.brew/Cellar/readline/8.1/lib/

UNAME_S				= $(shell uname -s)

COMPIL_LINE_LINUX	= $(CC) $(CFLAGS) ${OBJ} $(LIBS) -o $(NAME)
COMPIL_LINE_MAC		= $(CC) $(CFLAGS) ${OBJ} $(LIBS) $(LIBS_MAC) -o $(NAME)

ifeq ($(UNAME_S),Linux)
	COMPILE 		= $(COMPIL_LINE_LINUX)
	CROSS			= $(OBJS_LINUX)
	LOGDATE 		= $(shell date --iso=seconds)
endif
ifeq ($(UNAME_S),Darwin)
	COMPILE			= $(COMPIL_LINE_MAC)
	READLINE		= @brew install readline
	CROSS			= $(OBJS_MAC)
	LOGDATE 		= $(shell date)
endif

OBJ					= ${OBJS} ${OBJS_INC} ${OBJS_UTILS} ${OBJS_PARSER} ${CROSS}

$(NAME):	${OBJ}
			@printf "\e[1;34m################################################\n"
			@printf "#          :::      ::::::::                   #\n"
			@printf "#        :+:      :+:    :+:      mmehran      #\n"
			@printf "#      +:+ +:+         +:+          and        #\n"
			@printf "#    +#+  +:+       +#+            bledda      #\n"
			@printf "#  +#+#+#+#+#+   +#+                 as        #\n"
			@printf "#       #+#    #+#                Minishell    #\n"
			@printf "#      ###   ########                          #\n"
			@printf "################################################\e[0m\n"
			@printf "\e[1;34m--------------\n"
			@printf "\e[1;35mStart build ⏳\n"
			@printf "\e[1;36m--------------\e[0m\n"
			$(MAKE_EXT) ./libft
			$(READLINE)
			@printf "\e[1;34m---------------------\n"
			@printf "\e[1;35mCompiling minishell🔨\n"
			@printf "\e[1;36m----------------------\e[0m\n"
			@$(COMPILE)
			@printf "\e[1;34m---------------------------\n"
			@printf "\e[1;35mYour best shell is ready ✅\n"
			@printf "\e[1;36m---------------------------\e[0m\n"

all:		${NAME}

%.o: %.c	$(HEADERS)
			@$(CC) -c $(CFLAGS) -o $@ $<

re: 		fclean all

clean:
			$(MAKE_EXT) ./libft clean
			@${RM} ${OBJ}
			@printf "\e[1;34m---------------------------------\n"
			@printf "\e[1;35mObject files have been deleted 🚮\n"
			@printf "\e[1;36m---------------------------------\e[0m\n"

fclean:		clean
			$(MAKE_EXT) ./libft fclean
			@${RM} $(NAME)
			@printf "\e[1;34m--------------------------\n"
			@printf "\e[1;35mYour folder is now clean 🧹\n"
			@printf "\e[1;36m--------------------------\e[0m\n"

pull:		fclean
			@printf "\e[1;34m--------------------------\n"
			@printf "\e[1;35mGit pull in progress 🐱‍👓\n"
			@printf "\e[1;36m--------------------------\e[0m\n"
			@git pull

push:		fclean
			@printf "\e[1;34m----------------\n"
			@printf "\e[1;35mAdd all files 🐱‍👓\n"
			@printf "\e[1;36m----------------\e[0m\n"
			@git add .
			@printf "\e[1;34m--------------------\n"
			@printf "\e[1;35mCommit adding date 🐱‍👓\n"
			@printf "\e[1;36m--------------------\e[0m\n"
			@git commit -m "$(LOGDATE)"
			@printf "\e[1;34m------------\n"
			@printf "\e[1;35mGit push 🐱‍👓\n"
			@printf "\e[1;36m------------\e[0m\n"
			@git push

help:
			@printf "\e[1;35m------------------------------------------------\n"
			@printf "\e[1;35m| make or all or minishell : compile minishell  |\n"
			@printf "\e[1;35m| help                     : print help         |\n"
			@printf "\e[1;35m| clean                    : delete object file |\n"
			@printf "\e[1;35m| fclean                   : delete object file |\n"
			@printf "\e[1;35m|                            and binarie        |\n"
			@printf "\e[1;35m| pull                     : fclean + update rep|\n"
			@printf "\e[1;35m| push                     : fclean + upload rep|\n"
			@printf "\e[1;35m| re                       : fclean + all       |\n"
			@printf "\e[1;35m------------------------------------------------\n"

.PHONY: 	all clean fclean re help pull push
