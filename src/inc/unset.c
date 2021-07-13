/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 21:42:23 by bledda            #+#    #+#             */
/*   Updated: 2021/07/13 08:20:30 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

void	ft_unset(char **av)
{
	int		i;
	int		j;
	int		z;
	int		ac;
	char	**env;

	i = 1;
	j = 0;
	ac = count_array(av);
	if (ac > 1)
	{
		while (av[i])
		{
			j = 0;
			if (ft_strisalnum(av[i]) == 0)
			{
				ft_error2("unset", av[i], "not a valid identifier");
				return ;
			}
			while (g_environ[j]
				&& ft_strncmp(g_environ[j], av[i], ft_strlen(av[i])) != 0)
				j++;
			if (g_environ[j]
				&& ft_strncmp(g_environ[j], av[i], ft_strlen(av[i])) == 0)
			{
				env = ft_calloc(sizeof(char *), count_array(g_environ));
				z = 0;
				while (z < j)
				{
					env[z] = ft_strdup(g_environ[z]);
					free(g_environ[z]);
					z++;
				}
				free(g_environ[j]);
				j++;
				while (g_environ[j])
				{
					env[z] = ft_strdup(g_environ[j]);
					free(g_environ[j]);
					j++;
					z++;
				}
				free(g_environ);
				g_environ = env;
			}
			i++;
		}
	}
}
