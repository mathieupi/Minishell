/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:36:54 by bledda            #+#    #+#             */
/*   Updated: 2021/07/13 01:07:10 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include <stdlib.h>
#include <stdio.h>

extern char	**environ;

int	count_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int main(int ac, char **av)
{
	int i;
	int j;
	char **new_environ;

	i = 0;
	j = 0;
	if (ac == 2)
	{
		while (av[1][i] && av[1][i] != '=')
			i++;
		while (environ[j] && ft_strncmp(environ[j], av[1], i) != 0)
			j++;
		if (environ[j] && ft_strncmp(environ[j], av[1], i) == 0)
			environ[j] = ft_strdup(av[1]);
		else
		{
			j = count_array(environ) + 1; 
			new_environ = ft_calloc(sizeof(char *), j + 1);
			j = 0;
			while (environ[j])
			{
				new_environ[j] = environ[j];
				j++;
			}
			new_environ[j] = ft_strdup(av[1]);
			environ = new_environ;
		}
	}
	return (0);
}
