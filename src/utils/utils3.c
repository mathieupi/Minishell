/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 12:36:42 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/18 12:37:27 by mmehran          ###   ########.fr       */
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
