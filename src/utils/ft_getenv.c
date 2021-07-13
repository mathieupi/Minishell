/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 09:27:38 by bledda            #+#    #+#             */
/*   Updated: 2021/07/13 09:39:02 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"

char	*ft_getenv(char *str)
{
	char	*name;
	char	*content;
	int		i;
	int		i_tmp;

	i = -1;
	while (g_environ[++i])
	{
		i_tmp = 0;
		while (g_environ[i][i_tmp] != '=')
			i_tmp++;
		name = ft_calloc(sizeof(char), i_tmp + 1);
		content = ft_calloc(sizeof(char), ft_strlen(g_environ[i]) - i_tmp + 1);
		ft_strlcpy(name, g_environ[i], i_tmp + 1);
		ft_strlcpy(content, g_environ[i] + i_tmp + 1,
			ft_strlen(g_environ[i]) - i_tmp);
		if (ft_streql(str, name))
		{
			free(name);
			return (content);
		}
		free(name);
		free(content);
	}
	return (0);
}
