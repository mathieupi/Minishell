/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:19:23 by bledda            #+#    #+#             */
/*   Updated: 2021/07/22 03:16:31 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static bool	is_comment(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '#')
		return (true);
	return (false);
}

static bool	run_sh(int ac, char **av)
{
	t_redirection	**redict;
	char			*line;
	int				fd;

	if (ac > 2)
		return (true);
	else if (ac == 2 && is_suffix(av[1], ".sh"))
	{
		fd = open(av[1], O_RDWR);
		if (fd == -1)
			return (true);
		while (get_next_line(fd, &line) > 0)
		{
			if (!is_comment(line))
			{
				redict = cmds(line);
				try_cmds(redict);
			}
			free(line);
		}
		close(fd);
		printf("\n\n");
		return (true);
	}
	return (false);
}

int	main(int ac, char **av, char **envp)
{
	int	i;

	i = 0;
	g_environ = ft_calloc(sizeof(char *), count_array(envp) + 1);
	while (envp[i])
	{
		g_environ[i] = ft_strdup(envp[i]);
		i++;
	}
	signal(SIGINT, handle);
	signal(SIGQUIT, handle);
	if (run_sh(ac, av))
		return (0);
	minishell();
	return (0);
}
