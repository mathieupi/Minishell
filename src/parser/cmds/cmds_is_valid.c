/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 02:01:27 by bledda            #+#    #+#             */
/*   Updated: 2021/07/23 02:10:14 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

static char	*string_char(int nb)
{
	char	*tmp;

	if (nb == 248)
		tmp = ft_strdup(">>");
	else if (nb == 240)
		tmp = ft_strdup("<<");
	else if (nb == 496)
		tmp = ft_strdup("||");
	else if (nb == 152)
		tmp = ft_strdup("&&");
	else if (nb == 124)
		tmp = ft_strdup("|");
	else if (nb == 60)
		tmp = ft_strdup("<");
	else if (nb == 62)
		tmp = ft_strdup(">");
	else if (nb == 59)
		tmp = ft_strdup(";");
	else if (nb == 38)
		tmp = ft_strdup("&");
	return (tmp);
}

static bool	first_is_command(t_cmd **cmds)
{
	char	*str_error;

	if (cmds[1] && cmds[0]->type == 0 && cmds[0]->str == 0
		&& cmds[1]->type != 0)
	{
		str_error = string_char(cmds[1]->type);
		ft_error("syntax error near unexpected token", str_error);
		free(str_error);
		return (false);
	}
	return (true);
}

static bool	is_double_semicolon(t_cmd **cmds, int i)
{
	if (cmds[i + 1] && cmds[i]->type == ';' && cmds[i + 1]->type == ';'
		&& !cmds[i]->str
		&& (ft_streql(cmds[i + 1]->str, " ") || !cmds[i + 1]->str))
	{
		ft_error("syntax error near unexpected token", ";;");
		return (false);
	}
	else if (cmds[i]->type == ';')
		cmds[i]->type = 0;
	return (true);
}

static bool	is_double_separator(t_cmd **cmds, int i)
{
	char	*str_error;

	if (cmds[i + 1] && cmds[i]->type != 0 && cmds[i + 1]->type != 0
		&& ft_streql(cmds[i]->str, " ")
		&& (ft_streql(cmds[i + 1]->str, " ") || !cmds[i + 1]->str))
	{
		str_error = string_char(cmds[i + 1]->type);
		ft_error("syntax error near unexpected token", str_error);
		free(str_error);
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
	return (true);
}
