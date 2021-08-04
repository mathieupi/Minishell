/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:36:47 by mmehran           #+#    #+#             */
/*   Updated: 2021/08/04 16:26:18 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

static bool	ft_create_file(char *str)
{
	int	fd;

	fd = open(str, O_CREAT);
	if (fd == -1)
		return (false);
	close (fd);
	return (true);
}

static void	redirection(t_cmd **cmds, int *i)
{
	int	save_i;

	save_i = *i;
	if (cmds[*i + 1]
		&& (cmds[*i + 1]->type == CHEVRON_LL || cmds[*i + 1]->type == '<'))
	{
		while (cmds[*i + 1]
			&& (cmds[*i + 1]->type == CHEVRON_LL || cmds[*i + 1]->type == '<'))
			(*i)++;
		if (cmds[*i]->type == '<')
			l_chevron(cmds[save_i], cmds[*i]);
		else if (cmds[*i]->type == CHEVRON_LL)
			ll_chevron(cmds[save_i], cmds[*i]);
	}
	else if (cmds[*i + 1] && cmds[*i + 1]->type == '|')
		ft_pipe(cmds[save_i], cmds[++(*i)]);
	else if (cmds[*i + 1]
		&& (cmds[*i + 1]->type == CHEVRON_RR || cmds[*i + 1]->type == '>'))
	{
		while (cmds[*i + 1]
			&& (cmds[*i + 1]->type == CHEVRON_RR || cmds[*i + 1]->type == '>'))
		{
			(*i)++;
			if (cmds[*i + 1]
				&& (cmds[*i + 1]->type == CHEVRON_RR
					|| cmds[*i + 1]->type == '>'))
				ft_create_file(cmds[*i]->str);
		}
		if (cmds[*i]->type == '>')
			r_chevron(cmds[save_i], cmds[*i]);
		else if (cmds[*i]->type == CHEVRON_RR)
			rr_chevron(cmds[save_i], cmds[*i]);
	}
}

void	try_cmds(t_cmd	**cmds)
{
	char	**argv;
	int		i;

	i = -1;
	while (cmds[++i])
	{
		if (cmds[i + 1] && cmds[i + 1]->type)
			redirection(cmds, &i);
		else if (cmds[i]->str)
		{
			argv = cmds[i]->args;
			if (count_array(argv) > 0)
				update_env("_", argv[count_array(argv) - 1]);
			try_exec(argv);
		}
	}
}
