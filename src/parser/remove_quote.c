/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:26:55 by bledda            #+#    #+#             */
/*   Updated: 2021/07/20 22:49:55 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

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
		update_struct((*arg)[i], &parsing);
		if (!is_inhibited(*arg, i))
		{
			if ((*arg)[i] == '"' && !parsing.in_squote)
				continue ;
			if ((*arg)[i] == '\'' && !parsing.in_dquote)
				continue ;
		}
		tmp[j++] = (*arg)[i];
	}
	free(*arg);
	*arg = tmp;
}
