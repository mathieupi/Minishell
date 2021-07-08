/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/08 23:42:05 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

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

void    exec(char **argv)
{
    int    pid;

    pid = fork();
    if (pid == 0)
        execvp(argv[0], argv);
    else if (pid > 0)
        waitpid(pid, NULL, 0);
}

void	minishell(void)
{
	char	*in;
	char	**splitted;

	while (1)
	{
		in = readline(">");
		if (!in)
			break ;
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
