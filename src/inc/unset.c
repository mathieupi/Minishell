/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 21:42:23 by bledda            #+#    #+#             */
/*   Updated: 2021/07/23 14:31:11 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

void	clear_var(int i_env, int i, char **av)
{
	int		arg;
	char	**env;

	if (g_global.env[i_env]
		&& ft_strncmp(g_global.env[i_env], av[i], ft_strlen(av[i])) == 0)
	{
		env = ft_calloc(sizeof(char *), count_array(g_global.env));
		arg = 0;
		while (arg < i_env)
		{
			env[arg] = ft_strdup(g_global.env[arg]);
			arg++;
		}
		i_env++;
		while (g_global.env[i_env])
		{
			env[arg] = ft_strdup(g_global.env[i_env]);
			i_env++;
			arg++;
		}
		free_array(g_global.env);
		g_global.env = env;
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
			if (ft_strcheckunset(av[i]) == 0)
			{
				ft_error2("unset", av[i], "not a valid identifier");
				return ;
			}
			while (g_global.env[i_env]
				&& ft_strncmp(g_global.env[i_env], av[i],
					ft_strlen(av[i])) != 0)
				i_env++;
			clear_var(i_env, i, av);
		}
	}
}
