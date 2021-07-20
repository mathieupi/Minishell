/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_backslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:19:10 by bledda            #+#    #+#             */
/*   Updated: 2021/07/20 22:06:39 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

void	remove_backslash(char **arg)
{
	int		i;
	int		j;
	char	*tmp;

	if (ft_count_char(*arg, '\\') > 0)
	{
		tmp = ft_calloc(sizeof(char), ft_strlen(*arg) + 1);
		i = 0;
		j = 0;
		while ((*arg)[i] != 0)
		{
			if (is_inhibited(*arg, i) || (*arg)[i] != '\\')
			{
				tmp[j] = (*arg)[i];
				j++;
			}
			i++;
		}
		free(*arg);
		*arg = ft_strdup(tmp);
		free(tmp);
	}
}
