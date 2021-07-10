/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 05:42:10 by bledda            #+#    #+#             */
/*   Updated: 2021/07/10 04:49:20 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

// Faut verifier que ce soit des dossiers
// -bash: cd: ARGS: No such file or directory
// -bash: cd: ARGS: Not a directory

void	add_value(char **str, char *new_value)
{
	char	*tmp;

	tmp = ft_strjoin(*str, new_value);
	free(*str);
	*str = tmp;
}

void	update_pwd(char **chemin, char **pwd, char *arg)
{
	int		size_pwd;
	char	**pwd_explode;
	int		i;
	int		size_pwd_tmp;

	pwd_explode = ft_split(*pwd, '/');
	size_pwd = count_array(pwd_explode);
	if (ft_strncmp(chemin[0], "...", 3) == 0)
		printf("-minishell: cd: %s:  No such file or directory\n", arg);
	else
	{
		i = 0;
		while (ft_strncmp(chemin[i], "..", 2) == 0)
		{
			i++;
			size_pwd--;
			if (!chemin[i])
				break ;
		}
		free(*pwd);
		*pwd = ft_strdup("/");
		if (i == 0)
		{
			size_pwd = 0;
			while (pwd_explode[size_pwd])
			{
				add_value(pwd, pwd_explode[size_pwd]);
				add_value(pwd, "/");
				size_pwd++;
			}
			if (ft_strncmp(chemin[i], ".", 1) == 0)
				i++;
			while (chemin[i])
			{
				add_value(pwd, chemin[i]);
				if (chemin[i + 1])
					add_value(pwd, "/");
				i++;
			}
		}
		else if (size_pwd <= 0)
		{
			while (chemin[i])
			{
				add_value(pwd, chemin[i]);
				if (chemin[i + 1])
					add_value(pwd, "/");
				i++;
			}
		}
		else
		{
			size_pwd_tmp = 0;
			while (size_pwd_tmp < size_pwd)
			{
				add_value(pwd, pwd_explode[size_pwd_tmp]);
				if (size_pwd_tmp + 1 < size_pwd || chemin[i])
					add_value(pwd, "/");
				size_pwd_tmp++;
			}
			while (chemin[i])
			{
				add_value(pwd, chemin[i]);
				if (chemin[i + 1])
					add_value(pwd, "/");
				i++;
			}
		}
	}
	free_array(pwd_explode);
}

void	ft_cd(char **pwd, char *in)
{
	int		size_arg;
	char	**args;
	char	**chemin;
	char *tmp;

	args = ft_split(in, ' ');
	size_arg = count_array(args);
	if (size_arg == 1 || (args[1][0] == '~' && args[1][1] == 0))
	{
		/*
			!!! Ne pas modifier directement tmp car modifie variable global
			pointer directement sur la variable global
		*/
		tmp = getenv("HOME");
		free(*pwd);
		*pwd = ft_strdup(tmp);
	}
	else if (args[1][0] == '/')
	{
		free(*pwd);
		*pwd = ft_strdup(args[1]);
	}
	else
	{
		chemin = ft_split(args[1], '/');
		update_pwd(chemin, pwd, args[1]);
		free_array(chemin);
	}
	free_array(args);
}
