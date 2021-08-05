/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 02:01:27 by bledda            #+#    #+#             */
/*   Updated: 2021/08/05 12:59:27 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

static char	*string_char(int nb)
{
	if (nb == CHEVRON_RR)
		return (">>");
	else if (nb == CHEVRON_LL)
		return ("<<");
	else if (nb == PIPE_PIPE)
		return ("||");
	else if (nb == AND_AND)
		return ("&&");
	else if (nb == '|')
		return ("|");
	else if (nb == '<')
		return ("<");
	else if (nb == '>')
		return (">");
	else if (nb == ';')
		return (";");
	else if (nb == '&')
		return ("&");
	return (NULL);
}

static bool	first_is_command(t_cmd **cmds)
{
	char	*str_error;

	if (cmds[1] && cmds[0]->type == 0 && cmds[0]->str == 0
		&& cmds[1]->type != 0)
	{
		str_error = string_char(cmds[1]->type);
		ft_error("syntax error near unexpected token", str_error, 2);
		return (false);
	}
	return (true);
}

static bool	is_double_semicolon(t_cmd **cmds, int i)
{
	char	*str_error;

	if (cmds[i + 1] && cmds[i]->type == ';' && cmds[i + 1]->type == ';'
		&& !cmds[i]->str)
	{
		ft_error("syntax error near unexpected token", ";;", 2);
		return (false);
	}
	else if (cmds[i]->type == ';')
		cmds[i]->type = 0;
	if (cmds[i + 1] && cmds[i]->type == 0 && cmds[i + 1]->type != 0
		&& (ft_streql(cmds[i]->str, " ") || !cmds[i]->str))
	{
		str_error = string_char(cmds[i + 1]->type);
		ft_error("syntax error near unexpected token", str_error, 2);
		return (false);
	}
	return (true);
}

static bool	is_double_separator(t_cmd **cmds, int i)
{
	char	*str_error;

	if (cmds[i + 1] && cmds[i]->type != 0 && cmds[i + 1]->type != 0
		&& (ft_streql(cmds[i]->str, " ") || !cmds[i]->str))
	{
		str_error = string_char(cmds[i + 1]->type);
		ft_error("syntax error near unexpected token", str_error, 2);
		return (false);
	}
	return (true);
}

bool	cmds_is_valid(t_cmd	**cmds)
{
	int		i;

	i = -1;
	if (!first_is_command(cmds))
		return (false);
	while (cmds[++i])
	{
		if (cmds[i]->type == 0)
			continue ;
		if (!is_double_semicolon(cmds, i)
			|| !is_double_separator(cmds, i))
			return (false);
	}
	if (!cmds[i - 1]->str && cmds[i - 1]->type)
	{
		printf("Comeback in 7.5 million years 🕰\n");
		return (false);
	}
	return (true);
}
