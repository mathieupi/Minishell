/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 21:34:52 by bledda            #+#    #+#             */
/*   Updated: 2021/07/16 22:00:46 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"

void	update_env(char *env, char *new_value)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup(env);
	add_value(&tmp, "=");
	add_value(&tmp, new_value);
	while (g_environ[i] && ft_strncmp(g_environ[i], env, ft_strlen(env)) != 0)
		i++;
	free(g_environ[i]);
	g_environ[i] = ft_strdup(tmp);
	free(tmp);
}
