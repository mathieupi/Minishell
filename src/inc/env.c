/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:52:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/13 05:33:47 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

/*
	Visiblement resultat ok pour env
	change un petit peut sur export seul
*/

void	ft_env(char **argv)
{
	char	**env;

	(void)argv;
	env = g_environ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
