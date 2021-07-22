/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:51:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/23 00:10:53 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

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
			type *= 2;
			strp++;
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
	return (cmds);
}
