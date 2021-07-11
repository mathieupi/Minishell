/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:18:53 by bledda            #+#    #+#             */
/*   Updated: 2021/07/11 18:19:24 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"

void	exec(char **argv)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			ft_error(argv[0], "command not found");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
		waitpid(pid, NULL, 0);
}

void	try_exec(char **argv)
{
	if (!argv || !argv[0])
		return ;
	if (ft_streql(argv[0], "env"))
	{
		ft_env(argv);
		return ;
	}
	else if (ft_streql(argv[0], "export"))
	{
		ft_export(argv);
		return ;
	}
	else if (ft_streql(argv[0], "exit"))
	{
		ft_exit();
		return ;
	}
	else if (ft_streql(argv[0], "pwd"))
	{
		ft_pwd();
		return ;
	}
	else if (ft_streql(argv[0], "echo"))
	{
		ft_echo(argv);
		return ;
	}
	else if (ft_streql(argv[0], "cd"))
	{
		ft_cd(argv);
		return ;
	}
	exec(argv);
}