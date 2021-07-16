/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:26:55 by bledda            #+#    #+#             */
/*   Updated: 2021/07/16 17:38:15 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

// typedef struct s_parsing
// {
// 	bool	inhibited;
// 	bool	in_squote;
// 	bool	in_dquote;
// 	bool	sp;
// }	t_parsing;

void	remove_quote(char **arg)
{
	t_parsing parsing;
	int		i;
	int		j;
	char	*tmp;

	parsing = (t_parsing){0};
	if (ft_strlen(*arg) >= 2)
	{
		tmp = ft_calloc(sizeof(char), ft_strlen(*arg) + 1);
		i = 0;
		j = 0;
		while ((*arg)[i] != 0)
		{
			update_struct((*arg)[i], &parsing);
			if ((*arg)[i] == '\\')
			{
				tmp[j] = (*arg)[i];
				j++;
				i++;
			}
			if ((*arg)[i] != '\'' && (*arg)[i] != '"')
			{
				tmp[j] = (*arg)[i];
				j++;
			}
			if ((*arg)[i] == '\'' || (*arg)[i] == '"')
			{
				if (parsing.inhibited
					|| ((*arg)[i] == '\'' && parsing.in_dquote)
						|| ((*arg)[i] == '"' && parsing.in_squote))
				{
					tmp[j] = (*arg)[i];
					j++;
				}
			}
			parsing.inhibited = false;
			i++;
		}
		free(*arg);
		*arg = ft_strdup(tmp);
		free(tmp);
	}
}
