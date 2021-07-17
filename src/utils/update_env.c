/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 21:34:52 by bledda            #+#    #+#             */
/*   Updated: 2021/07/17 17:49:49 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"

static int	isset_env(char *env)
{
	int i;

	i = 0;
	while (g_environ[i] != 0)
	{
		if (ft_strncmp(g_environ[i], env, ft_strlen(env)) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	update_env(char *env, char *new_value)
{
	int		i;
	char	*tmp;

	i = 0;
	if (isset_env(env))
	{
		tmp = ft_strdup(env);
		add_value(&tmp, "=");
		add_value(&tmp, new_value);
		while (g_environ[i] && ft_strncmp(g_environ[i], env, ft_strlen(env)) != 0)
			i++;
		free(g_environ[i]);
		g_environ[i] = ft_strdup(tmp);
		free(tmp);
	}
}
