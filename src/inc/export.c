/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:52:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/13 01:09:51 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

void	ft_export(char **av)
{
	int i;
	int j;
	char **env;

	i = 0;
	j = 0;

	env = environ;
	if (count_array(av) == 1)
		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
	else if (count_array(av) == 2)
	{
		while (av[1][i] && av[1][i] != '=')
			i++;
		while (environ[j] && ft_strncmp(environ[j], av[1], i) != 0)
			j++;
		if (environ[j] && ft_strncmp(environ[j], av[1], i) == 0)
			environ[j] = ft_strdup(av[1]);
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
			env[j] = ft_strdup(av[1]);
			environ = env;
		}
	}
}
