/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/10 18:51:20 by bledda           ###   ########.fr       */
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
		PRONT $ echo "coucou
		> je suis un retour a la ligne"
		coucou
		je suis un retour a la ligne
		PRONT $ 
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

void	minishell(char **envp)
{
	char	*in;
	char	*pwd;

	pwd = ft_pwd();
	while (1)
	{
		in = readline("\e[1;34mMinishell\e[0m $ ");
		if (!in)
			break ;
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
