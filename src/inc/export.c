/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:52:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/23 15:44:34 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

static void	print_var(void)
{
	int		i;
	char	*name;
	char	*content;
	int		i_tmp;

	i = 0;
	while (g_global.env[i])
	{
		i_tmp = 0;
		while (g_global.env[i][i_tmp] != '=')
			i_tmp++;
		name = ft_calloc(sizeof(char), i_tmp + 2);
		content = ft_calloc(sizeof(char),
				ft_strlen(g_global.env[i]) - i_tmp + 1);
		ft_strlcpy(name, g_global.env[i], i_tmp + 2);
		ft_strlcpy(content, g_global.env[i] + i_tmp + 1,
			ft_strlen(g_global.env[i]) - i_tmp);
		printf("declare -x %s\"%s\"\n", name, content);
		free(name);
		free(content);
		i++;
	}
}

static void	send_update(int i_env, char **av, int arg, int i)
{
	char	**env;

	if (g_global.env[i_env] && ft_strncmp(g_global.env[i_env], av[arg], i) == 0)
	{
		free(g_global.env[i_env]);
		g_global.env[i_env] = ft_strdup(av[arg]);
	}
	else
	{
		i_env = count_array(g_global.env) + 1;
		env = ft_calloc(sizeof(char *), i_env + 1);
		i_env = 0;
		while (g_global.env[i_env])
		{
			env[i_env] = ft_strdup(g_global.env[i_env]);
			free(g_global.env[i_env]);
			i_env++;
		}
		env[i_env] = ft_strdup(av[arg]);
		free(g_global.env);
		g_global.env = env;
	}
}

static void	update_var(char **av)
{
	int		i;
	int		i_env;
	int		arg;
	char	*tmp;

	arg = 0;
	tmp = 0;
	while (av[++arg])
	{
		i = 0;
		i_env = 0;
		while (av[arg][i] && av[arg][i] != '=')
			add_char(&tmp, av[arg][i++]);
		if (av[arg][i] != '=' || !ft_strcheckunset(tmp) == 0)
		{
			if (ft_strcheckunset(tmp) == 0)
				ft_error2("export", av[arg], "not a valid identifier");
			free(tmp);
			return ;
		}
		free(tmp);
		while (g_global.env[i_env]
			&& ft_strncmp(g_global.env[i_env], av[arg], i) != 0)
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
	g_global.return_code = 0;
}
