/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_backslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:19:10 by bledda            #+#    #+#             */
/*   Updated: 2021/07/21 18:38:16 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

void	remove_backslash(char **arg)
{
	int			i;
	int			j;
	char		*tmp;
	t_parsing	parsing;

	parsing = (t_parsing){0};
	tmp = ft_calloc(sizeof(char), ft_strlen(*arg) + 1);
	i = -1;
	j = 0;
	while ((*arg)[++i] != 0)
	{
		update_struct2((*arg)[i], &parsing);
		if (!parsing.inhibited && !parsing.in_dquote && !parsing.in_squote
			&& (*arg)[i] == '\\' && (*arg)[i + 1] != '\\'
			 && (*arg)[i + 1] != '\'' && (*arg)[i + 1] != '\"')
			continue ;
		if (!parsing.inhibited && parsing.in_dquote && (*arg)[i] == '\\'
			&& (*arg)[i + 1] == '$')
			continue ;
		tmp[j++] = (*arg)[i];
	}
	free(*arg);
	*arg = ft_strdup(tmp);
	free(tmp);
}
