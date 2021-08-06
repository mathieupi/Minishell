/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 20:55:05 by bledda            #+#    #+#             */
/*   Updated: 2021/08/06 21:31:42 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

void	red_left(t_cmd **cmds, int *i)
{
	int	save_i;

	save_i = *i;
	while (cmds[*i + 1]
		&& (cmds[*i + 1]->type == CHEVRON_LL || cmds[*i + 1]->type == '<'))
		(*i)++;
	if (cmds[*i]->type == '<')
		l_chevron(cmds[save_i], cmds[*i]);
	else if (cmds[*i]->type == CHEVRON_LL)
		ll_chevron(cmds[save_i], cmds[*i]);
}

bool	red_right(t_cmd **cmds, int *i)
{
	int	save_i;

	save_i = *i;
	while (cmds[*i + 1]
		&& (cmds[*i + 1]->type == CHEVRON_RR
			|| cmds[*i + 1]->type == '>'))
	{
		(*i)++;
		if (cmds[*i + 1]
			&& (cmds[*i + 1]->type == CHEVRON_RR
				|| cmds[*i + 1]->type == '>')
			&& (cmds[*i]->type == '>' || cmds[*i]->type == CHEVRON_RR)
			&& ft_append_file(cmds[*i]->args[0], true) == -1)
			return (false);
	}
	if (cmds[*i]->type == '>')
		r_chevron(cmds[save_i], cmds[*i]);
	else if (cmds[*i]->type == CHEVRON_RR)
		rr_chevron(cmds[save_i], cmds[*i]);
	return (true);
}

bool	try_right(t_cmd **cmds, int *i)
{
	while (cmds[*i + 1]
		&& (cmds[*i + 1]->type == CHEVRON_RR || cmds[*i + 1]->type == '>'))
	{
		if (cmds[*i]->type == '>' || cmds[*i]->type == CHEVRON_RR)
		{
			if (ft_append_file(cmds[*i]->args[0], true) == -1)
				return (false);
		}
		(*i)++;
	}
	return (true);
}

bool	exec_multi(t_cmd **cmds, int *save_i, int *fin, int *fout)
{
	while (cmds[*save_i + 1] && cmds[*save_i + 1]->type == '|')
		(*save_i)++;
	if (!try_right(cmds, save_i))
		return (false);
	if ((cmds[*save_i]->type == CHEVRON_RR || cmds[*save_i]->type == '>'))
		*fout = *save_i;
	while (cmds[*save_i + 1]
		&& (cmds[*save_i + 1]->type == CHEVRON_LL
			|| cmds[*save_i + 1]->type == '<'))
		(*save_i)++;
	if ((cmds[*save_i]->type == CHEVRON_LL || cmds[*save_i]->type == '<'))
		*fin = *save_i;
	if (*fout == -1)
	{
		if (!try_right(cmds, save_i))
			return (false);
		if ((cmds[*save_i]->type == CHEVRON_RR || cmds[*save_i]->type == '>'))
			*fout = *save_i;
	}
	return (true);
}
