/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 04:36:22 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/17 18:23:10 by bledda           ###   ########.fr       */
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

static void	go(char *env_name, char **av)
{
	char	*saved_pwd;
	char	*env_value;

	saved_pwd = get_pwd();
	env_value = ft_getenv(env_name);
	try_chdir(env_value, saved_pwd, av);
	free(saved_pwd);
	free(env_value);
}

bool	is_arg_count_valid(char **av)
{
	if (count_array(av) > 1)
	{
		ft_error("cd", "too many arguments");
		return (false);
	}
	else if (count_array(av) == 1)
	{
		if (ft_count_char(av[0], '/') == ft_strlen(av[0]))
		{
			go("HOME", av);
			return (false);
		}
		if (ft_streql(av[0], "-"))
		{
			go("OLDPWD", av);
			return (false);
		}
	}
	return (true);
}

void	add_prefix(char **str, char *prefix)
{
	char	*temp;

	temp = ft_strdup(prefix);
	add_value(&temp, *str);
	free(*str);
	*str = temp;
}

void	ft_cd(char **av)
{
	char	**splitted;
	int		i;
	char	*saved_pwd;

	av++;
	i = -1;
	if (!is_arg_count_valid(av))
		return ;
	splitted = ft_split(*av, '/');
	if (!splitted || count_array(splitted) == 0)
		go("HOME", av);
	saved_pwd = get_pwd();
	while (splitted[++i])
	{
		if (i == 0 && av[0][0] == '/')
			add_prefix(&splitted[i], "/");
		if (try_chdir(splitted[i], saved_pwd, av))
			break ;
	}
	free(saved_pwd);
	free_array(splitted);
}
