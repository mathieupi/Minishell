/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:54:58 by bledda            #+#    #+#             */
/*   Updated: 2021/08/05 11:54:24 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_H
# define INC_H

# include "minishell.h"

void	ft_pwd(void);
void	ft_echo(char **argv);
void	ft_exit(char **argv);
void	ft_export(char **argv);
void	ft_env(char **argv);
void	ft_cd(char **argv);
void	ft_unset(char **av);

typedef struct s_export
{
	int		i;
	int		i_env;
	int		arg;
	char	*tmp;
}				t_export;

#endif
