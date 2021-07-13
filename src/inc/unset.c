/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 21:42:23 by bledda            #+#    #+#             */
/*   Updated: 2021/07/13 03:33:41 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

void	ft_unset(char **av)
{
	int i;
	int j;
	int z;
	int ac;
	char **env;

	ac = count_array(av);
	i = 1;
	j = 0;
	if (ac > 1)
	{
		while (av[i])
		{
			if (ft_strisalnum(av[i]) == 0)
			{
				ft_error2("unset", av[i], "not a valid identifier");
				return ;
			}
			while (environ[j] && ft_strncmp(environ[j], av[i], ft_strlen(av[i])) != 0)
				j++;
			if (environ[j] && ft_strncmp(environ[j], av[i], ft_strlen(av[i])) == 0)
			{
				env = ft_calloc(sizeof(char *), count_array(environ));
				z = 0;
				while (z < j)
				{
					env[z] = ft_strdup(environ[z]);
					z++;
				}
				j++;
				while (environ[j])
				{
					env[z] = ft_strdup(environ[j]);
					j++;
					z++;
				}
				environ = env;
			}
			i++;
		}
	}
}
