# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 11:30:44 by mmehran           #+#    #+#              #
#    Updated: 2021/07/22 20:13:01 by mmehran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= minishell

#	FILES	####################################################################
HEADER_FILE 		= minishell.h \
						utils.h \
						inc.h \
						parser.h \
						color.h \
						history.h

FOLDER				= src/
FOLDER_INC			= src/inc/
FOLDER_UTILS		= src/utils/
FOLDER_PARSER_ARGS	= src/parser/args/
FOLDER_PARSER_CMDS	= src/parser/cmds/
FOLDER_HEADER		= header/
FOLDER_CROSS		= src/cross_platform/

SRCS				= minishell.c \
						main.c \
						history.c

SRCS_UTILS			= utils.c \
						utils2.c \
						ft_error.c \
						try_exec.c \
						ft_getenv.c \
						print_array.c \
						update_env.c \
						utils3.c

SRCS_INC			= pwd.c \
						echo.c \
						cd.c \
						env.c \
						exit.c \
						export.c \
						unset.c

SRCS_LINUX			= handle_linux.c

SRCS_MAC			= handle_mac.c

SRCS_PARSER_ARGS	= parser.c \
						update_struct.c \
						is_valid.c \
						add_char.c \
						count_args.c \
						ft_isutil.c \
						add_arg.c \
						split_args.c \
						is_inhibited.c \
						trim_arg.c \
						sub_env.c \
						remove_backslash.c \
						remove_quote.c \
						sub_tilde.c \
						ft_replace_str.c

SRCS_PARSER_CMDS		= redirection.c

SRC					= $(addprefix ${FOLDER},${SRCS})
SRC_INC				= $(addprefix ${FOLDER_INC},${SRCS_INC})
SRC_UTILS			= $(addprefix ${FOLDER_UTILS},${SRCS_UTILS})
SRC_PARSER_ARGS		= $(addprefix ${FOLDER_PARSER_ARGS},${SRCS_PARSER_ARGS})
SRC_PARSER_CMDS		= $(addprefix ${FOLDER_PARSER_CMDS},${SRCS_PARSER_CMDS})
HEADERS				= $(addprefix ${FOLDER_HEADER},${HEADER_FILE})
SRC_LINUX			= $(addprefix ${FOLDER_CROSS},${SRCS_LINUX})
SRC_MAC				= $(addprefix ${FOLDER_CROSS},${SRCS_MAC})

OBJS				= ${SRC:.c=.o}
OBJS_INC			= ${SRC_INC:.c=.o}
OBJS_UTILS			= ${SRC_UTILS:.c=.o}
OBJS_PARSER_ARGS	= ${SRC_PARSER_ARGS:.c=.o}
OBJS_PARSER_CMDS	= ${SRC_PARSER_CMDS:.c=.o}
OBJS_LINUX			= ${SRC_LINUX:.c=.o}
OBJS_MAC			= ${SRC_MAC:.c=.o}
####################################################################################

#	COMPILATION		################################################################
CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -rf
MAKE_EXT			= @make -s --no-print-directory -C
LIBS				= -L ./libft -lft -lreadline
LIBS_MAC			= -L/Users/$(USER)/.brew/Cellar/readline/8.1/lib/

HISTORY_FILE		= $(HOME)/.minishell_history
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

OBJ					= ${OBJS} ${OBJS_INC} ${OBJS_UTILS} ${OBJS_PARSER_ARGS} ${OBJS_PARSER_CMDS} ${CROSS}
#####################################################################################

#	RULES	#########################################################################
$(NAME):	${OBJ}
			@printf $(blue)
			@printf "################################################\n"
			@printf "#          :::      ::::::::                   #\n"
			@printf "#        :+:      :+:    :+:      mmehran      #\n"
			@printf "#      +:+ +:+         +:+          and        #\n"
			@printf "#    +#+  +:+       +#+            bledda      #\n"
			@printf "#  +#+#+#+#+#+   +#+                 as        #\n"
			@printf "#       #+#    #+#                Minishell    #\n"
			@printf "#      ###   ########nice.fr                   #\n"
			@printf "################################################\n"
			@printf "➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Start build ⏳\n"
			@printf "➖➖➖➖➖➖➖\n"
			@printf $(reset)
			$(MAKE_EXT) ./libft
			$(READLINE)
			@printf "➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Compiling minishell🔨\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)
			@$(COMPILE)
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Your best shell is ready ✅\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)

all:		${NAME}

%.o: %.c	$(HEADERS)
			@$(CC) -c $(CFLAGS) -o $@ $<

re: 		fclean all

clean:
			$(MAKE_EXT) ./libft clean
			@${RM} ${OBJ}
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Object files have been deleted 🚮\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)

fclean:		clean
			$(MAKE_EXT) ./libft fclean
			@${RM} $(NAME) $(HISTORY_FILE)
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Your folder is now clean 🧹\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)

pull:		fclean
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Git pull in progress 🐱‍👓\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)
			@git pull

push:		pull
			@${RM} $(NAME).dSYM
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Add all files 🐱‍👓\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)
			@git add .
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Commit adding date 🐱‍👓\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)
			@git commit -m "$(LOGDATE)"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Git push 🐱‍👓\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)
			@git push

apple:
			@printf $(bg_cyan)
			@printf $(white)
			@printf "                #      "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_cyan)
			@printf $(white)
			@printf "              ###      "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_cyan)
			@printf $(white)
			@printf "             ####      "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_cyan)
			@printf $(white)
			@printf "            ####       "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_cyan)
			@printf $(white)
			@printf "            ##         "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_green)
			@printf $(white)
			@printf "     ######   ######   "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_green)
			@printf $(white)
			@printf "   ##################  "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_green)
			@printf $(white)
			@printf "  #################### "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_green)
			@printf $(white)
			@printf " ####################  "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_yellow)
			@printf $(white)
			@printf "###################    "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_yellow)
			@printf $(white)
			@printf "###################    "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_yellow)
			@printf $(white)
			@printf "###################    "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_yellow)
			@printf $(white)
			@printf "###################    "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_red)
			@printf $(white)
			@printf "####################   "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_red)
			@printf $(white)
			@printf "#####################  "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_red)
			@printf $(white)
			@printf " ##################### "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_red)
			@printf $(white)
			@printf " ######################"
			@printf $(reset)
			@printf "\n"
			@printf $(bg_magenta)
			@printf $(white)
			@printf "  #################### "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_magenta)
			@printf $(white)
			@printf "   ################### "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_magenta)
			@printf $(white)
			@printf "    #################  "
			@printf $(reset)
			@printf "\n"
			@printf $(bg_magenta)
			@printf $(white)
			@printf "     ######    #####   \n"
			@printf $(bg_black)
			@printf $(reset)

tea:
			@printf $(red)
			@printf "            .------.____\n"
			@printf "         .-'       \\ ___)\n"
			@printf "      .-'         \\\\\\n"
			@printf "   .-'        ___  \\\\)\n"
			@printf ".-'          /  (\\  |)\n"
			@printf "         __  \  ( | |\n"
			@printf "        /  \  \__'| |\n"
			@printf "       /    \____).-'\n"
			@printf "     .'       /   |\n"
			@printf "    /     .  /    |\n"
			@printf "  .'     / \\/     |\n"
			@printf " /      /   \\     |\n"
			@printf "       /    /    _|_\n"
			@printf "       \\   /    /\\ /\\ \n"
			@printf "        \\ /    /__v__\\ \n"
			@printf "         '    |       |\n"
			@printf "              |     .#|\n"
			@printf "              |#.  .##|\n"
			@printf "              |#######|\n"
			@printf "              |#######|\n"
			@printf $(reset)

help:
			@printf $(magenta)
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf "| make, make all, make minishell : compile minishell  |\n"
			@printf "| help                           : print help         |\n"
			@printf "| clean                          : delete object file |\n"
			@printf "| fclean                         : delete object file |\n"
			@printf "|                                  and binarie        |\n"
			@printf "| pull                           : fclean + update rep|\n"
			@printf "| push                           : fclean + upload rep|\n"
			@printf "| apple, tea                     : suprises           |\n"
			@printf "| re                             : fclean + all       |\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)

.PHONY: 	all clean fclean re help pull push apple tea cofee
#################################################################################

#	COLOR SETTING	#############################################################
black 				= "\e[1;30m"
red 				= "\e[1;31m"
green 				= "\e[1;32m"
yellow 				= "\e[1;33m"
blue 				= "\e[1;34m"
magenta 			= "\e[1;35m"
cyan 				= "\e[1;36m"
white 				= "\e[1;37m"

bg_black 			= "\e[40m"
bg_red 				= "\e[41m"
bg_green 			= "\e[42m"
bg_yellow 			= "\e[43m"
bg_blue 			= "\e[44m"
bg_magenta 			= "\e[45m"
bg_cyan 			= "\e[46m"
bg_white 			= "\e[47m"

reset 				= "\e[0m"
#################################################################################
