/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:51:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/17 23:42:12 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/redirection.h"

static int	isredirection(char *str)
{
	char	*tmp;

	tmp = ft_strdup(str);
	trim_arg(&tmp, " \t\n\v\f\r");
	if (ft_streql(tmp, ">>"))
	{
		free(tmp);
		return (DOUBLE_RIGHT);
	}
	if (ft_streql(tmp, ">"))
	{
		free(tmp);
		return (SIMPLE_RIGHT);
	}
	if (ft_streql(tmp, "<<"))
	{
		free(tmp);
		return (DOUBLE_LEFT);
	}
	if (ft_streql(tmp, "<"))
	{
		free(tmp);
		return (SIMPLE_LEFT);
	}
	if (ft_streql(tmp, "|"))
	{
		free(tmp);
		return (PIPE);
	}
	free(tmp);
	return (0);
}

t_redirection	**cmds(char *str)
{
	char			**tmp;
	int				ac;
	int				i;
	int				j;
	t_redirection	**redict;

	ac = count_args(str);
	tmp = ft_calloc(sizeof(char *), ac + 1);
	split_args(tmp, str);
	i = 0;
	j = 0;
	while (tmp[i])
	{
		if (isredirection(tmp[i]) != 0)
			j++;
		i++;
	}
	redict = ft_calloc(sizeof(t_redirection), j + 1);
	i = 0;
	j = 0;
	redict[j] = ft_calloc(sizeof(t_redirection), 1);
	while (tmp[i])
	{
		if (isredirection(tmp[i]) == 0)
			add_value(&redict[j]->value, tmp[i]);
		else
		{
			j++;
			redict[j] = ft_calloc(sizeof(t_redirection), 1);
			redict[j]->type = isredirection(tmp[i]);
		}
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (redict);
}
