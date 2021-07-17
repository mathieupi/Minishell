/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:28:54 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/17 20:49:58 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include "color.h"
# include "../libft/libft.h"
# include "utils.h"
# include "inc.h"
# include "parser.h"
# include "redirection.h"

# ifdef __linux__
#  include <readline/readline.h>
#  include <readline/history.h>
# elif __APPLE__
char	*readline(const char *prompt);
int		add_history(const char *string_for_history);
int		rl_on_new_line(void);
void	rl_redisplay(void);
void	rl_replace_line(const char *buffer, int something);
# endif

char	**g_environ;

void	minishell(void);
void	handle(int sig);

#endif
