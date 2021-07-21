/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:26:55 by bledda            #+#    #+#             */
/*   Updated: 2021/07/21 18:36:41 by mmehran          ###   ########.fr       */
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
		update_struct2((*arg)[i], &parsing);
		if (!parsing.inhibited && (*arg)[i] == '"' && !parsing.in_squote)
			continue ;
		if (!parsing.inhibited && (*arg)[i] == '\'' && !parsing.in_dquote)
			continue ;
		if (!parsing.inhibited && (*arg)[i] == '\\' && !parsing.in_squote
			&& ((*arg)[i + 1] == '\\' || (*arg)[i + 1] == '"'))
			continue ;
		tmp[j++] = (*arg)[i];
	}
	free(*arg);
	*arg = tmp;
}
