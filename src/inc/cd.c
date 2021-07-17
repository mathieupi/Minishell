/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 04:36:22 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/16 22:00:58 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

int	try_chdir(char *tmp, char *saved_pwd, char **av)
{
	struct stat	buffer;
	int			status;
	char		*pwd;

	if (chdir(tmp) == -1)
	{
		chdir(saved_pwd);
		status = stat(*av, &buffer);
		if (status == -1)
			ft_error2("cd", av[0], "No such file or directory");
		else if (status == 0)
			ft_error("cd", "Not a directory");
		return (1);
	}
	pwd = get_pwd();
	update_env("PWD", pwd);
	update_env("OLDPWD", saved_pwd);
	free(pwd);
	return (0);
}

bool	is_arg_count_valid(char **av)
{
	char	*saved_pwd;

	if (count_array(av) > 1)
	{
		ft_error("cd", "too many arguments");
		return (false);
	}
	else if (count_array(av) == 1 && ft_streql(av[0], "/"))
	{
		saved_pwd = get_pwd();
		try_chdir("/", saved_pwd, av);
		free(saved_pwd);
		return (false);
	}
	return (true);
}

void	ft_cd(char **av)
{
	char	**splitted;
	int		i;
	char	*saved_pwd;
	char	*temp;
	char	*home;

	av++;
	i = 0;
	if (!is_arg_count_valid(av))
		return ;
	saved_pwd = get_pwd();
	splitted = ft_split(*av, '/');
	if (count_array(splitted) == 0)
	{
		home = ft_getenv("HOME");
		try_chdir(home, saved_pwd, av);
		free(home);
	}
	while (splitted[i])
	{
		if (i == 0 && av[0][0] == '/')
		{
			temp = ft_strdup("/");
			add_value(&temp, splitted[i]);
			free(splitted[i]);
			splitted[i] = temp;
		}
		printf("%s\n", splitted[i]);
		if (try_chdir(splitted[i], saved_pwd, av))
			break ;
		i++;
	}
	free(saved_pwd);
	free_array(splitted);
}
