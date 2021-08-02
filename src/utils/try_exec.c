/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:18:53 by bledda            #+#    #+#             */
/*   Updated: 2021/08/02 09:35:25 by mmehran          ###   ########.fr       */
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
		execve(argv[0], argv, g_global.env);
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
	g_global.return_code = code;
	if (code == 126)
		ft_error(cmd, "command not found", 127);
}

char	**get_exec_paths(char *program_name)
{
	char	**paths;
	char	**tmp;
	int		i;

	if (ft_strncmp(program_name, "./", 2) == 0)
	{
		paths = ft_calloc(2, sizeof(char *));
		paths[0] = get_pwd();
	}
	else
	{
		tmp = ft_get_paths();
		if (ft_count_char(program_name, '/'))
		{
			paths = ft_calloc(count_array(tmp) + 2, sizeof(char *));
			paths[0] = ft_strdup("");
			i = -1;
			while (tmp[++i])
				paths[i + 1] = ft_strdup(tmp[i]);
			free_array(tmp);
		}
		else
			paths = tmp;
	}
	return (paths);
}

void	try_exec2(char **argv)
{
	int		i;
	char	**paths;
	char	*program_name;
	int		code;
	char	*save;

	program_name = ft_strdup(argv[0]);
	paths = get_exec_paths(program_name);
	i = -1;
	while (paths[++i])
	{
		save = ft_strdup(paths[i]);
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
	free_array(paths);
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
