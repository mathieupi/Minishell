/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:52:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/16 14:00:02 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

void	print_var(void)
{
	int		i;
	char	*name;
	char	*content;
	int		i_tmp;

	i = 0;
	while (g_environ[i])
	{
		i_tmp = 0;
		while (g_environ[i][i_tmp] != '=')
			i_tmp++;
		name = ft_calloc(sizeof(char), i_tmp + 2);
		content = ft_calloc(sizeof(char), ft_strlen(g_environ[i]) - i_tmp + 1);
		ft_strlcpy(name, g_environ[i], i_tmp + 2);
		ft_strlcpy(content, g_environ[i] + i_tmp + 1,
			ft_strlen(g_environ[i]) - i_tmp);
		printf("declare -x %s\"%s\"\n", name, content);
		free(name);
		free(content);
		i++;
	}
}

void	send_update(int i_env, char **av, int arg, int i)
{
	char	**env;

	if (g_environ[i_env] && ft_strncmp(g_environ[i_env], av[arg], i) == 0)
	{
		free(g_environ[i_env]);
		g_environ[i_env] = ft_strdup(av[arg]);
	}
	else
	{
		i_env = count_array(g_environ) + 1;
		env = ft_calloc(sizeof(char *), i_env + 1);
		i_env = 0;
		while (g_environ[i_env])
		{
			env[i_env] = ft_strdup(g_environ[i_env]);
			free(g_environ[i_env]);
			i_env++;
		}
		env[i_env] = ft_strdup(av[arg]);
		free(g_environ);
		g_environ = env;
	}
}

void	update_var(char **av)
{
	int		i;
	int		i_env;
	int		arg;

	arg = 0;
	while (av[++arg])
	{
		i = 0;
		i_env = 0;
		while (av[arg][i] && av[arg][i] != '=')
			i++;
		if (av[arg][i] != '=' || av[arg][0] == '=')
		{
			ft_error2("export", av[arg], "not a valid identifier");
			return ;
		}
		while (g_environ[i_env]
			&& ft_strncmp(g_environ[i_env], av[arg], i) != 0)
			i_env++;
		send_update(i_env, av, arg, i);
	}
}

void	ft_export(char **av)
{
	if (count_array(av) == 1)
		print_var();
	else if (count_array(av) >= 2)
		update_var(av);
}
