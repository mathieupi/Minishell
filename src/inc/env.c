/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:52:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/11 06:21:41 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

/*
	Visiblement resultat ok pour env
	change un petit peut sur export seul
*/

void	ft_env(char **argv)
{
	char	**env;

	(void)argv;
	env = environ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
