/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:28:54 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/10 21:05:18 by mmehran          ###   ########.fr       */
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
# define WHITE "\001\e[0m\002"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include "../libft/libft.h"

void	minishell(char **env);
char	*ft_pwd(void);
void	ft_echo(int ac, char **av);
void	ft_exit(void);
void	ft_cd(char **pwd, char *in);
void	ft_export(char **env, char *in);
void	ft_env(char **env, char *in);

void	add_value(char **str, char *new_value);

int		count_array(char **arr);
void	free_array(char **arr);

#endif
