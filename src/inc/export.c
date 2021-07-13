/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:52:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/13 03:23:32 by bledda           ###   ########.fr       */
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
		env = environ;
		while (env[i])
		{
			// Apres le = les arg doitvent avoir le "
			printf("declare -x %s\n", env[i]);
			i++;
		}
	}
	else if (count_array(av) >= 2)
	{
		i = 0;
		j = 0;
		while (av[z])
		{
			while (av[z][i] && av[z][i] != '=')
				i++;
			if (av[z][i] != '=')
			{
				// pas encore compris quand ce message doit ce print exactement
				ft_error2("export", av[z], "not a valid identifier");
				// pas encore compris quand ce message doit ce print exactement
				return ;
			}
			while (environ[j] && ft_strncmp(environ[j], av[z], i) != 0)
				j++;
			if (environ[j] && ft_strncmp(environ[j], av[z], i) == 0)
				environ[j] = ft_strdup(av[z]);
			else
			{
				j = count_array(environ) + 1; 
				env = ft_calloc(sizeof(char *), j + 1);
				j = 0;
				while (environ[j])
				{
					env[j] = environ[j];
					j++;
				}
				env[j] = ft_strdup(av[z]);
				environ = env;
			}
			z++;
		}
	}
}
