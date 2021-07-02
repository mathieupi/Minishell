/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/02 16:38:35 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./Libft/libft.h"

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

void	exec(char **argv)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		execvp(argv[0], argv);
	else if (pid > 0)
		while (wait(NULL) != pid)
			;
}

void	minishell(void)
{
	char	*in;
	char	**splitted;

	while (1)
	{
		in = readline(">");
		add_history(in);
		if (ft_strncmp(in, "./", 2) == 0)
		{
			splitted = ft_split(in, ' ');
			exec(splitted);
			free_array(splitted);
		}
		free(in);
	}
}
