/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:49:17 by bledda            #+#    #+#             */
/*   Updated: 2021/07/21 20:12:18 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# define DOUBLE_RIGHT 1
# define SIMPLE_RIGHT 2
# define DOUBLE_LEFT 3
# define SIMPLE_LEFT 4
# define PIPE 5

# include "minishell.h"

typedef struct s_redirection
{
	int		type;
	char	*value;
}	t_redirection;

t_redirection	**cmds(char *str);
void			try_cmds(t_redirection	**redict);

#endif
