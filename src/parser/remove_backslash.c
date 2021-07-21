/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_backslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:19:10 by bledda            #+#    #+#             */
/*   Updated: 2021/07/21 15:18:45 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

// ?nabeEfrtv

void	remove_backslash(char **arg) //env, double bashslash,
{
	int			i;
	int			j;
	char		*tmp;
	t_parsing	parsing;

	if (ft_count_char(*arg, '\\') > 0)
	{
		parsing = (t_parsing){0};
		tmp = ft_calloc(sizeof(char), ft_strlen(*arg) + 1);
		i = -1;
		j = 0;
		while ((*arg)[++i] != 0)
		{
			update_struct((*arg)[i], &parsing);
			if (!is_inhibited(*arg, i))
			{
				if (!parsing.in_dquote && !parsing.in_squote && (*arg)[i] == '\\'
					&& (*arg)[i + 1] != '\\' &&  (*arg)[i + 1] != '\'' && (*arg)[i + 1] != '\"')
					continue ;
				if (parsing.in_dquote && (*arg)[i] == '\\' && (*arg)[i + 1] == '$')
					continue ;
			}
			tmp[j++] = (*arg)[i];
		}
		free(*arg);
		*arg = ft_strdup(tmp);
		free(tmp);
	}
}

void	remove_backslash2(char **arg)
{
	int		i;
	int		j;
	char	*tmp;

	if (ft_count_char(*arg, '\\') > 0)
	{
		tmp = ft_calloc(sizeof(char), ft_strlen(*arg) + 1);
		i = -1;
		j = 0;
		while ((*arg)[++i] != 0)
		{
			if ((*arg)[i] == '\\' && !is_inhibited(*arg, i))
				continue ;
			tmp[j++] = (*arg)[i];
		}
		free(*arg);
		*arg = ft_strdup(tmp);
		free(tmp);
	}
}
