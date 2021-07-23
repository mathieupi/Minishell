/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:52:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/23 14:53:47 by mmehran          ###   ########.fr       */
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
	env = g_global.env;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	g_global.return_code = 0;
}
