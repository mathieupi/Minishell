/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:28:17 by bledda            #+#    #+#             */
/*   Updated: 2021/08/06 20:54:41 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

static bool	try_multi(t_cmd **cmds, int *i)
{
	int	save_i;
	int	fin;
	int	fout;
	int	j;

	save_i = *i;
	fin = -1;
	fout = -1;
	j = 0;
	while (j++ <= 1)
		if (!exec_multi(cmds, &save_i, &fin, &fout))
			return (false);
	multi_pipe(cmds, i, fin, fout);
	return (true);
}

static bool	try_simple(t_cmd **cmds, int *i)
{
	if (cmds[*i + 1] && cmds[*i + 1]->type == '|')
	{
		multi_pipe(cmds, i, -1, -1);
		return (false);
	}
	else if (cmds[*i + 1]
		&& (cmds[*i + 1]->type == CHEVRON_RR || cmds[*i + 1]->type == '>'))
	{
		if (!red_right(cmds, i))
			return (false);
	}
	else if (cmds[*i + 1]
		&& (cmds[*i + 1]->type == CHEVRON_LL || cmds[*i + 1]->type == '<'))
		red_left(cmds, i);
	return (true);
}

static bool	redirection(t_cmd **cmds, int *i)
{
	if (is_simple(cmds, i))
	{
		if (!try_simple(cmds, i))
			return (false);
	}
	else if (!is_simple(cmds, i))
	{
		if (!try_multi(cmds, i))
			return (false);
	}
	return (true);
}

void	try_cmds(t_cmd	**cmds)
{
	char	**argv;
	int		i;

	i = 0;
	while (cmds[i])
	{
		if (cmds[i + 1] && cmds[i + 1]->type)
		{
			if (!redirection(cmds, &i))
				continue ;
			if (!cmds[i])
				break ;
		}
		else if (cmds[i]->str)
		{
			argv = cmds[i]->args;
			if (count_array(argv) > 0)
				update_env("_", argv[count_array(argv) - 1]);
			try_exec(argv);
		}
		i++;
	}
}
