/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:26:55 by bledda            #+#    #+#             */
/*   Updated: 2021/07/21 17:46:44 by mmehran          ###   ########.fr       */
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
		if (!parsing.inhibited)
		{
			if ((*arg)[i] == '"' && !parsing.in_squote)
				continue ;
			if ((*arg)[i] == '\'' && !parsing.in_dquote)
				continue ;
			if ((*arg)[i] == '\\' && !parsing.in_squote && !parsing.in_dquote)
				continue ;
		}
		tmp[j++] = (*arg)[i];
	}
	free(*arg);
	*arg = tmp;
}

// void	remove_quote(char **arg)
// {
// 	t_parsing	parsing;
// 	int			i;
// 	int			j;
// 	char		*tmp;

// 	parsing = (t_parsing){0};
// 	tmp = ft_calloc(sizeof(char), ft_strlen(*arg) + 1);
// 	i = 0;
// 	j = 0;
// 	while ((*arg)[i] != 0)
// 	{
// 		update_struct((*arg)[i], &parsing);
// 		if ((*arg)[i] == '\\')
// 			tmp[j++] = (*arg)[i++];
// 		if ((*arg)[i] != '\'' && (*arg)[i] != '"')
// 			tmp[j++] = (*arg)[i];
// 		if (((*arg)[i] == '\'' || (*arg)[i] == '"') && (parsing.inhibited
// 			|| ((*arg)[i] == '\'' && parsing.in_dquote)
// 				|| ((*arg)[i] == '"' && parsing.in_squote)))
// 			tmp[j++] = (*arg)[i];
// 		parsing.inhibited = false;
// 		i++;
// 	}
// 	free(*arg);
// 	*arg = tmp;
// }
