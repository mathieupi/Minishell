/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 09:27:38 by bledda            #+#    #+#             */
/*   Updated: 2021/08/02 09:35:18 by mmehran          ###   ########.fr       */
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
	while (g_global.env[++i])
	{
		i_tmp = 0;
		while (g_global.env[i][i_tmp] != '=')
			i_tmp++;
		name = ft_calloc(sizeof(char), i_tmp + 1);
		content = ft_calloc(1, ft_strlen(g_global.env[i]) - i_tmp + 1);
		ft_strlcpy(name, g_global.env[i], i_tmp + 1);
		ft_strlcpy(content, g_global.env[i] + i_tmp + 1,
			ft_strlen(g_global.env[i]) - i_tmp);
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
