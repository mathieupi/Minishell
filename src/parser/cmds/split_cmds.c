/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:51:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/23 01:53:43 by bledda           ###   ########.fr       */
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

static bool	cmds_is_valid(t_cmd	**cmds)
{
	int		i;
	char	*str_error;

	i = -1;
	if (cmds[1] && cmds[0]->type == 0 && cmds[0]->str == 0
		&& cmds[1]->type != 0)
	{
		str_error = string_char(cmds[1]->type);
		ft_error("syntax error near unexpected token", str_error);
		free(str_error);
		return (false);
	}
	while (cmds[++i])
	{
		if (cmds[i]->type == 0)
			continue ;
		if (cmds[i + 1] && cmds[i]->type == ';' && cmds[i + 1]->type == ';'
			&& ft_streql(cmds[i]->str, " ")
			&& (ft_streql(cmds[i + 1]->str, " ") || cmds[i + 1]->str == 0))
		{
			ft_error("syntax error near unexpected token", ";;");
			return (false);
		}
		else if (cmds[i]->type == ';')
			cmds[i]->type = 0;
		if (cmds[i + 1] && cmds[i]->type != 0 && cmds[i + 1]->type != 0
			&& ft_streql(cmds[i]->str, " ")
			&& (ft_streql(cmds[i + 1]->str, " ") || cmds[i + 1]->str == 0))
		{
			str_error = string_char(cmds[i + 1]->type);
			ft_error("syntax error near unexpected token", str_error);
			free(str_error);
			return (false);
		}
	}
	return (true);
}

static bool	try_create_cmd(char **strp, t_parsing *parsing,
	t_cmd ***cmdsp, int *i)
{
	int		type;
	char	*str;

	str = *strp;
	if (!parsing->inhibited && !parsing->in_squote && !parsing->in_squote
		&& isset(*str, "<>|;&"))
	{
		add_calloc(cmdsp);
		(*i)++;
		type = *str;
		if (double_char(*str, *(str + 1), "<>|&"))
		{
			type *= 4;
			(*strp)++;
		}
		(*cmdsp)[*i]->type = type;
		return (true);
	}
	return (false);
}

t_cmd	**split_cmds(char *str)
{
	t_cmd		**cmds;
	t_parsing	parsing;
	int			i;

	i = 0;
	cmds = ft_calloc(2, sizeof(t_cmd *));
	cmds[i] = ft_calloc(1, sizeof(t_cmd));
	parsing = (t_parsing){0};
	while (*str)
	{
		update_struct2(*str, &parsing);
		if (!try_create_cmd(&str, &parsing, &cmds, &i))
			add_char(&cmds[i]->str, *str);
		str++;
	}
	if (cmds_is_valid(cmds))
		return (cmds);
	while (i >= 0)
	{
		if (cmds[i]->str)
			free(cmds[i]->str);
		free(cmds[i--]);
	}
	free(cmds);
	return (0);
}
