/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/10 21:17:25 by bledda           ###   ########.fr       */
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

int	count_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	exec(char **argv)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		execve(argv[0], argv, NULL);
	else if (pid > 0)
		waitpid(pid, NULL, 0);
}

/*
	MAN FT_USING

	function is int
	0 = exec
	1 = ft_echo
	{
		Faut gere les "" '' """ '''
		prompt $ echo "coucou
		> je suis un retour a la ligne"
		coucou
		je suis un retour a la ligne
		prompt $
	}
*/
void	ft_using(int function, char *in)
{
	char	**splitted;

	splitted = ft_split(in, ' ');
	if (function == 0)
		exec(splitted);
	else if (function == 1)
		ft_echo(count_array(splitted), splitted);
	free_array(splitted);
}

void	ft_prompt(char **prompt, char *pwd)
{
	char	*name;
	char	*logname;

	name = getenv("NAME");
	logname = getenv("LOGNAME");
	*prompt = ft_strdup(GREEN);
	add_value(prompt, logname);
	add_value(prompt, "@");
	add_value(prompt, name);
	add_value(prompt, RESET);
	add_value(prompt, ":");
	add_value(prompt, BLUE);
	add_value(prompt, pwd);
	add_value(prompt, RESET);
	add_value(prompt, "$ ");
}

void	minishell(char **envp)
{
	char	*in;
	char	*pwd;
	char	*prompt;

	pwd = ft_pwd();
	while (1)
	{
		ft_prompt(&prompt, pwd);
		in = readline(prompt);
		if (!in)
		{
			ft_exit();
			break ;
		}
		add_history(in);
		if (ft_strncmp(in, "./", 2) == 0)
			ft_using(0, in);
		else if (ft_strncmp(in, "exit", 4) == 0)
		{
			free(pwd);
			ft_exit();
		}
		else if (ft_strncmp(in, "pwd", 3) == 0)
			printf("%s\n", pwd);
		else if (ft_strncmp(in, "echo", 4) == 0)
			ft_using(1, in);
		else if (ft_strncmp(in, "cd", 2) == 0)
			ft_cd(&pwd, in);
		else if (ft_strncmp(in, "export", 6) == 0)
			ft_export(envp, in);
		else if (ft_strncmp(in, "env", 3) == 0)
			ft_env(envp, in);
		else if (ft_strncmp(in, "ls", 2) == 0)
			system("ls");
		free(in);
	}
}
