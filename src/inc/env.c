/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:52:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/11 03:52:53 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

/*
	Visiblement resultat ok pour env
	change un petit peut sur export seul
*/

void	ft_env(char **argv)
{
	(void)argv;
	char	**env;

	env = environ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
