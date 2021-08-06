/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 20:51:54 by bledda            #+#    #+#             */
/*   Updated: 2021/08/06 20:52:20 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

static bool	simple_pipe(t_cmd **cmds, int *j)
{
	int	i;

	i = *j;
	while (cmds[i + 1] && cmds[i + 1]->type == '|')
		i++;
	if (cmds[i + 1] && cmds[i + 1]->type != '|')
		return (false);
	return (true);
}

static bool	simple_left(t_cmd **cmds, int *j)
{
	int	i;

	i = *j;
	while (cmds[i + 1]
		&& (cmds[i + 1]->type == CHEVRON_LL || cmds[i + 1]->type == '<'))
		i++;
	if (cmds[i + 1]
		&& (cmds[i + 1]->type != CHEVRON_LL || cmds[i + 1]->type != '<'))
		return (false);
	return (true);
}

static bool	simple_right(t_cmd **cmds, int *j)
{
	int	i;

	i = *j;
	while (cmds[i + 1]
		&& (cmds[i + 1]->type == CHEVRON_RR || cmds[i + 1]->type == '>'))
		i++;
	if (cmds[i + 1]
		&& (cmds[i + 1]->type != CHEVRON_RR || cmds[i + 1]->type != '>'))
		return (false);
	return (true);
}

bool	is_simple(t_cmd **cmds, int *j)
{
	int	i;

	i = *j;
	if (cmds[i + 1] && cmds[i + 1]->type == '|')
	{
		if (!simple_pipe(cmds, &i))
			return (false);
	}
	else if (cmds[i + 1]
		&& (cmds[i + 1]->type == CHEVRON_RR || cmds[i + 1]->type == '>'))
	{
		if (!simple_right(cmds, &i))
			return (false);
	}
	else if (cmds[i + 1]
		&& (cmds[i + 1]->type == CHEVRON_LL || cmds[i + 1]->type == '<'))
	{
		if (!simple_left(cmds, &i))
			return (false);
	}
	return (true);
}
