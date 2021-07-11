/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/11 06:16:42 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

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
	} else if (ft_streql(argv[0], "exit"))
	{
		ft_exit();
		return ;
	}
	else if (ft_streql(argv[0], "pwd"))
	{
		ft_pwd();
		return ;
	}else if (ft_streql(argv[0], "echo"))
	{
		ft_echo(argv);
		return ;
	}else if (ft_streql(argv[0], "cd"))
	{
		ft_cd(argv);
		return ;
	}
	exec(argv);
}

void	ft_prompt(char **prompt)
{
	char	*name;
	char	*logname;

	name = getenv("NAME");
	logname = getenv("LOGNAME");
	*prompt = ft_strdup("(dev)");
	add_value(prompt, GREEN);
	add_value(prompt, logname);
	add_value(prompt, "@");
	add_value(prompt, name);
	add_value(prompt, RESET);
	add_value(prompt, ":");
	add_value(prompt, BLUE);
	//add_value(prompt, pwd);
	add_value(prompt, RESET);
	add_value(prompt, "$ ");
}

char	*ft_remove_char(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = malloc(ft_strlen(str));
	while (ft_isspace(str[i]) && str[i] != 0)
		i++;
	while (str[i] != 0)
	{
		if (str[i] == '\'' || str[i] == '\\' || str[i] == '"')
		{
			if (str[i] == '\'' || str[i] == '\"')
			{
				if (i - 1 >= 0 && str[i - 1] == '\\')
				{
					tmp[j] = str[i];
					j++;
				}
			}
			else
			{
				if (i - 1 >= 0 && (str[i - 1] == '"' || str[i - 1] == '\''))
				{
					tmp[j] = str[i];
					j++;
				}
			}
		}
		else
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	tmp[j] = 0;
	free(str);
	return (tmp);
}

int	ft_clean_input(char **in)
{
	int	size_input;

	size_input = ft_strlen(*in);
	if ((*in)[size_input - 1] == '\\')
	{
		printf("This case should not be managed\n");
		return (0);
	}
	else
		*in = ft_strdup(ft_remove_char(*in));
	return (1);
}

void	minishell(void)
{
	char	*in;
	char	**argv;
	char	*prompt;

	while (1)
	{
		ft_prompt(&prompt);
		in = readline(prompt);
		if (!in)
			ft_exit();
		if (in[0])
			add_history(in);
		//ft_clean_input(&in);
		argv = ft_split(in, ' ');
		try_exec(argv);
		free(prompt);
		free_array(argv);
		free(in);
	}
}
