/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:52:30 by bledda            #+#    #+#             */
/*   Updated: 2021/07/10 05:08:45 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	ft_export(char **env, char *in)
{
	char	**args;
	int		size_arg;

	args = ft_split(in, ' ');
	size_arg = count_array(args);
	if (size_arg == 1)
	{
		while(*env)
		{
			printf("%s\n", *env);
			env++;
		}
	}
}
