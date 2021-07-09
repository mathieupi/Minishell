/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:28:54 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/09 07:36:10 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include "../libft/libft.h"

void	minishell(void);
char	*ft_pwd(void);
void	ft_echo(int ac, char **av);
void	ft_exit(void);
void	ft_cd(char **pwd, char *in);

int		count_array(char **arr);
void	free_array(char **arr);

#endif
