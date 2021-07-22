/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:51:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/18 15:17:34 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

// cat chien;echo coucou;

// static bool	is_valid(char *str)
// {
// 	while (*str)
// 	{
// 		str++;
// 	}
// 	return (true);
// }

static void	add_calloc(t_cmd ***cmdsp)
{
	int		count;
	t_cmd	**tmp;
	t_cmd	**cmds;

	cmds = *cmdsp;
	count = -1;
	while (cmds[++count])
		;
	tmp = ft_calloc(count + 2, sizeof(t_cmd *));
	count = -1;
	while (cmds[++count])
		tmp[count] = cmds[count];
	tmp[count] = ft_calloc(1, sizeof(t_cmd));
	free(cmds);
	*cmdsp = tmp;
}

static bool	is_inset(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (true);
		set++;
	}
	return (false);
}

static bool	tam(char c, char next_c, char *set)
{
	while (*set)
	{
		if (c == *set && next_c == *set)
			return (true);
		set++;
	}
	return (false);
}

t_cmd	**split_cmds(char *str)
{
	t_cmd		**cmds;
	t_parsing	parsing;
	int			i;
	int			type;

	i = 0;
	cmds = ft_calloc(2, sizeof(t_cmd *));
	cmds[i] = ft_calloc(1, sizeof(t_cmd));
	parsing = (t_parsing){0};
	while (*str)
	{
		update_struct2(*str, &parsing);
		if (!parsing.inhibited && !parsing.in_squote && !parsing.in_squote
			&& is_inset(*str, "<>|;&"))
		{
			add_calloc(&cmds);
			i++;
			type = *str;
			if (tam(*str, *(str + 1), "<>|&"))
			{
				type *= 2;
				str++;
			}
			cmds[i]->type = type;
			if (*str)
				str++;
		}
		if (*str)
		{
			add_char(&cmds[i]->str, *str);
			str++;
		}
	}
	return (cmds);
}
