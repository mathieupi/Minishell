/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_backslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:19:10 by bledda            #+#    #+#             */
/*   Updated: 2021/07/16 14:31:17 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

void	remove_backslash(char **arg)
{
	int		i;
	int 	j;
	char	*tmp;

	if (ft_strlen(*arg) == 1 && (*arg)[0] == '\\')
		(*arg)[0] = ' ';
	else if (ft_count_char(*arg, '\\'))
	{
		tmp = ft_calloc(sizeof(char), ft_strlen(*arg) + 1);
		i = 0;
		j = 0;
		while (*arg[i] != 0)
		{
			if (*arg[i] != '\\')
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
