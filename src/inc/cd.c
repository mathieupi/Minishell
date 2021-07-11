/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 04:36:22 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/11 18:11:22 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

int	try_chdir(char *tmp, char *saved_pwd, char **av)
{
	struct stat	buffer;
	int			status;

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
	return (0);
}

int	count_arg(char **av)
{
	if (count_array(av) > 1)
	{
		ft_error("cd", "too many arguments");
		return (1);
	}
	else if (count_array(av) == 0)
	{
		chdir(getenv("HOME"));
		return (1);
	}
	return (0);
}

void	ft_cd(char **av)
{
	char		**splitted;
	char		*tmp;
	int			i;
	char		*saved_pwd;

	av++;
	i = 0;
	if (count_arg(av))
		return ;
	saved_pwd = get_pwd();
	splitted = ft_split(*av, '/');
	while (splitted[i])
	{
		tmp = splitted[i];
		if (ft_streql(tmp, "~") && i == 0)
			tmp = getenv("HOME");
		if (try_chdir(tmp, saved_pwd, av))
			break ;
		i++;
	}
	free(saved_pwd);
	free_array(splitted);
}
