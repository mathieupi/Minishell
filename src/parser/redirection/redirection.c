/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:28:17 by bledda            #+#    #+#             */
/*   Updated: 2021/08/04 17:28:29 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

static bool	ft_create_file(char *str)
{
	int	fd;

	fd = open(str, O_CREAT | O_APPEND | O_WRONLY, 0777);;
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

static bool	redirection(t_cmd **cmds, int *i)
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
	else if (cmds[*i + 1] && (cmds[*i + 1]->type == CHEVRON_RR || cmds[*i + 1]->type == '>'))
	{
		while (cmds[*i + 1] && (cmds[*i + 1]->type == CHEVRON_RR || cmds[*i + 1]->type == '>'))
		{
			(*i)++;
			if (cmds[*i + 1] && (cmds[*i + 1]->type == CHEVRON_RR || cmds[*i + 1]->type == '>')
				&& !ft_create_file(cmds[*i]->args[0]))
			{
				ft_error(cmds[*i]->str, "Is a directory", 1);
				return (false);
			}
		}
		if (cmds[*i]->type == '>')
			r_chevron(cmds[save_i], cmds[*i]);
		else if (cmds[*i]->type == CHEVRON_RR)
			rr_chevron(cmds[save_i], cmds[*i]);
	}
	return (true);
}

void	try_cmds(t_cmd	**cmds)
{
	char	**argv;
	int		i;

	i = -1;
	while (cmds[++i])
	{
		if (cmds[i + 1] && cmds[i + 1]->type)
		{
			if (!redirection(cmds, &i))
				break ;
		}
		else if (cmds[i]->str)
		{
			argv = cmds[i]->args;
			if (count_array(argv) > 0)
				update_env("_", argv[count_array(argv) - 1]);
			try_exec(argv);
		}
	}
}
