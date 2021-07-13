/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:52:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/13 05:50:44 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

void	ft_export(char **av)
{
	int i;
	int j;
	int z;
	char **env;

	i = 0;
	j = 0;
	z = 1;
	if (count_array(av) == 1)
	{
		while (g_environ[i])
		{
			// Apres le '=' les arg doit ve avoir le "
			printf("declare -x %s\n", g_environ[i]);
			i++;
		}
	}
	else if (count_array(av) >= 2)
	{
		while (av[z])
		{
			i = 0;
			j = 0;
			while (av[z][i] && av[z][i] != '=')
				i++;
			if (av[z][i] != '=')
			{
				// pas encore compris quand ce message doit ce print exactement
				ft_error2("export", av[z], "not a valid identifier");
				return ;
			}
			while (g_environ[j] && ft_strncmp(g_environ[j], av[z], i) != 0)
				j++;
			if (g_environ[j] && ft_strncmp(g_environ[j], av[z], i) == 0)
			{
				free(g_environ[j]);
				g_environ[j] = ft_strdup(av[z]);
			}
			else
			{
				j = count_array(g_environ) + 1;
				env = ft_calloc(sizeof(char *), j + 1);
				j = 0;
				while (g_environ[j])
				{
					env[j] = ft_strdup(g_environ[j]);
					free(g_environ[j]);
					j++;
				}
				env[j] = ft_strdup(av[z]);
				free(g_environ);
				g_environ = env;
			}
			z++;
		}
	}
}
