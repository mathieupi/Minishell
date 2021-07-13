/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 21:42:23 by bledda            #+#    #+#             */
/*   Updated: 2021/07/13 09:25:48 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

void	clear_var(int i_env, int i, char **av)
{
	int		arg;
	char	**env;

	if (g_environ[i_env]
		&& ft_strncmp(g_environ[i_env], av[i], ft_strlen(av[i])) == 0)
	{
		env = ft_calloc(sizeof(char *), count_array(g_environ));
		arg = 0;
		while (arg < i_env)
		{
			env[arg] = ft_strdup(g_environ[arg]);
			arg++;
		}
		i_env++;
		while (g_environ[i_env])
		{
			env[arg] = ft_strdup(g_environ[i_env]);
			i_env++;
			arg++;
		}
		free_array(g_environ);
		g_environ = env;
	}
}

void	ft_unset(char **av)
{
	int		i;
	int		i_env;
	int		ac;

	i = 0;
	ac = count_array(av);
	if (ac > 1)
	{
		while (av[++i])
		{
			i_env = 0;
			if (ft_strisalnum(av[i]) == 0)
			{
				ft_error2("unset", av[i], "not a valid identifier");
				return ;
			}
			while (g_environ[i_env]
				&& ft_strncmp(g_environ[i_env], av[i], ft_strlen(av[i])) != 0)
				i_env++;
			clear_var(i_env, i, av);
		}
	}
}
