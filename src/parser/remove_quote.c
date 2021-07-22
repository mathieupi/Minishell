/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:26:55 by bledda            #+#    #+#             */
/*   Updated: 2021/07/22 18:09:03 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

static bool	to_skip(char c, char next_c, t_parsing *parsing)
{
	if (!parsing->inhibited && c == '"' && !parsing->in_squote)
		return (true);
	if (!parsing->inhibited && c == '\'' && !parsing->in_dquote)
		return (true);
	if (!parsing->inhibited && c == '\\' && !parsing->in_squote
		&& (next_c == '\\' || next_c == '"'))
		return (true);
	if (!parsing->inhibited && c == '\\' && !parsing->in_dquote
		&& !parsing->in_squote && next_c == '\'')
		return (true);
	return (false);
}

void	remove_quote(char **arg)
{
	t_parsing	parsing;
	int			i;
	int			j;
	char		*tmp;

	parsing = (t_parsing){0};
	tmp = ft_calloc(sizeof(char), ft_strlen(*arg) + 1);
	i = -1;
	j = 0;
	while ((*arg)[++i] != 0)
	{
		update_struct2((*arg)[i], &parsing);
		if (to_skip((*arg)[i], (*arg)[i + 1], &parsing))
			continue ;
		tmp[j++] = (*arg)[i];
	}
	free(*arg);
	*arg = tmp;
}
