/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:51:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/18 15:17:34 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/redirection.h"

static int	isredirection(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(str);
	trim_arg(&tmp, " \t\n\v\f\r");
	if (ft_streql(tmp, ">>"))
		i = DOUBLE_RIGHT;
	else if (ft_streql(tmp, ">"))
		i = SIMPLE_RIGHT;
	else if (ft_streql(tmp, "<<"))
		i = DOUBLE_LEFT;
	else if (ft_streql(tmp, "<"))
		i = SIMPLE_LEFT;
	else if (ft_streql(tmp, "|"))
		i = PIPE;
	free(tmp);
	return (i);
}

static int	count_cmds(char **str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
		if (isredirection(str[i]) != 0)
			j++;
	return (j);
}

t_redirection	**split_cmds(char *str)
{
	char			**tmp;
	int				ac;
	int				i;
	int				j;
	t_redirection	**redir;

	ac = count_args(str);
	tmp = ft_calloc(sizeof(char *), ac + 1);
	split_args(tmp, str);
	redir = ft_calloc(sizeof(t_redirection), count_cmds(tmp) + 1);
	i = -1;
	j = 0;
	redir[j] = ft_calloc(sizeof(t_redirection), 1);
	while (tmp[++i])
	{
		if (isredirection(tmp[i]) == 0)
			add_value(&redir[j]->value, tmp[i]);
		else
		{
			redir[++j] = ft_calloc(sizeof(t_redirection), 1);
			redir[j]->type = isredirection(tmp[i]);
		}
	}
	free_array(tmp);
	return (redir);
}
