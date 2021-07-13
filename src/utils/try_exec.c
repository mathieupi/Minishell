/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:18:53 by bledda            #+#    #+#             */
/*   Updated: 2021/07/13 09:41:18 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"

int	exec(char **argv)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		exit(126);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
	return (1);
}

void	try_exec2(char **argv)
{
	int		i;
	char	**splitted;
	char	*saved;
	int		code;

	splitted = ft_split(getenv("PATH"), ':');
	saved = argv[0];
	i = 0;
	code = 1;
	while (splitted[i])
	{
		add_value(&splitted[i], "/");
		add_value(&splitted[i], argv[0]);
		argv[0] = splitted[i];
		code = exec(argv);
		if (code != 126)
			break ;
		free(argv[0]);
		argv[0] = saved;
		i++;
	}
	free(splitted);
	if (code == 126)
		ft_error(argv[0], "command not found");
}

void	try_exec(char **argv)
{
	if (!argv || !argv[0])
		return ;
	else if (ft_streql(argv[0], "env"))
		ft_env(argv);
	else if (ft_streql(argv[0], "export"))
		ft_export(argv);
	else if (ft_streql(argv[0], "unset"))
		ft_unset(argv);
	else if (ft_streql(argv[0], "exit"))
		ft_exit();
	else if (ft_streql(argv[0], "pwd"))
		ft_pwd();
	else if (ft_streql(argv[0], "echo"))
		ft_echo(argv);
	else if (ft_streql(argv[0], "cd"))
		ft_cd(argv);
	else
		try_exec2(argv);
}
