/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saved_lol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:18:53 by bledda            #+#    #+#             */
/*   Updated: 2021/07/13 02:55:35 by mmehran          ###   ########.fr       */
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

void	try_exec2(char **argv)
{
	int		i;
	char	**splitted;
	char	*saved;

	splitted = ft_split(getenv("PATH"), ':');
	saved = argv[0];
	i = 0;
	while (splitted[i])
	{
		add_value(&splitted[i], "/");
		add_value(&splitted[i], argv[0]);
		argv[0] = splitted[i];
		exec(argv);
		free(argv[0]);
		argv[0] = saved;
		i++;
	}
	free(splitted);
}

void	try_exec(char **argv)
{
	if (!argv || !argv[0])
		return ;
	else if (ft_streql(argv[0], "env"))
		ft_env(argv);
	else if (ft_streql(argv[0], "export"))
		ft_export(argv);
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