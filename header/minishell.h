/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:28:54 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/13 05:47:28 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BLACK "\001\e[1;30m\002"
# define GREEN "\001\e[1;32m\002"
# define YELLOW "\001\e[1;33m\002"
# define BLUE "\001\e[1;34m\002"
# define MAGENTA "\001\e[1;35m\002"
# define CYAN "\001\e[1;36m\002"
# define WHITE "\001\e[1;37m\002"
# define RESET "\001\e[0m\002"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include "../libft/libft.h"
# include "utils.h"
# include "inc.h"

char	**g_environ;

void	minishell(void);

#endif
