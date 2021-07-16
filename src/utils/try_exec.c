/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:18:53 by bledda            #+#    #+#             */
/*   Updated: 2021/07/16 18:30:38 by bledda           ###   ########.fr       */
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
		execve(argv[0], argv, g_environ);
		exit(126);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
	return (1);
}

void	error_code(int code, char *cmd)
{
	if (code == 126)
		ft_error(cmd, "command not found");
}

void	try_exec2(char **argv)
{
	int		i;
	char	**splitted;
	char	*program_name;
	int		code;
	char	*save;

	splitted = ft_split(getenv("PATH"), ':');
	program_name = ft_strdup(argv[0]);
	i = -1;
	while (splitted[++i])
	{
		save = ft_strdup(splitted[i]);
		add_value(&save, "/");
		add_value(&save, argv[0]);
		free(argv[0]);
		argv[0] = save;
		code = exec(argv);
		if (code != 126)
			break ;
		free(argv[0]);
		argv[0] = ft_strdup(program_name);
	}
	free_array(splitted);
	error_code(code, program_name);
	free(program_name);
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
