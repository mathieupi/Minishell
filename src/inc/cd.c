/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 05:42:10 by bledda            #+#    #+#             */
/*   Updated: 2021/07/09 08:58:53 by bledda           ###   ########.fr       */
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
		}
		free(*pwd);
		*pwd = ft_strdup("/");
		if (size_pwd <= 0 && chemin[i])
		{
			// seg here si pas de parametre apres ../
			while (chemin[i])
			{
				add_value(pwd, chemin[i]);
				i++;
			}
		}
		else if (i == 0)
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
				i++;
			}
		}
		else
		{
			// boucle infi ou seg
			size_pwd_tmp = 0;
			if (ft_strncmp(chemin[i], ".", 1) == 0)
				i++;
			while (size_pwd_tmp < size_pwd)
			{
				add_value(pwd, pwd_explode[size_pwd_tmp]);
				if (size_pwd_tmp + 1 < size_pwd || chemin[i])
					add_value(pwd, "/");
				size_pwd++;
			}
			while (chemin[i])
			{
				add_value(pwd, chemin[i]);
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

	args = ft_split(in, ' ');
	size_arg = count_array(args);
	if (size_arg == 1)
		printf("Dossier user\n");
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
