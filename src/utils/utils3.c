/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 12:36:42 by mmehran           #+#    #+#             */
/*   Updated: 2021/08/02 09:36:32 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"

char	**ft_get_paths(void)
{
	char	*path;
	char	**paths;

	path = ft_getenv("PATH");
	paths = ft_split(path, ':');
	free(path);
	return (paths);
}

bool	is_suffix(char *str, char *suffix)
{
	int	size_suffix;
	int	size_str;

	size_suffix = ft_strlen(suffix) - 1;
	size_str = ft_strlen(str) - 1;
	if (size_str >= size_suffix)
	{
		while (size_suffix >= 0)
		{
			if (str[size_str] == suffix[size_suffix])
			{
				size_str--;
				size_suffix--;
			}
			else
				return (false);
		}
		return (true);
	}
	return (false);
}
