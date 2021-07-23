/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:52:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/23 16:00:52 by bledda           ###   ########.fr       */
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
	t_export	var;

	var = (t_export){0};
	while (av[++var.arg])
	{
		var.i = 0;
		var.i_env = 0;
		while (av[var.arg][var.i] && av[var.arg][var.i] != '=')
			add_char(&var.tmp, av[var.arg][var.i++]);
		if (av[var.arg][var.i] != '=' || !ft_strcheckunset(var.tmp))
		{
			if (!ft_strcheckunset(var.tmp))
				ft_error2("export", av[var.arg], "not a valid identifier");
			free(var.tmp);
			return ;
		}
		free(var.tmp);
		while (g_global.env[var.i_env]
			&& ft_strncmp(g_global.env[var.i_env], av[var.arg], var.i) != 0)
			var.i_env++;
		send_update(var.i_env, av, var.arg, var.i);
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
