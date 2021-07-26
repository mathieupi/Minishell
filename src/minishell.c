/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/26 08:11:45 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	try_cmds(t_cmd	**cmds)
{
	char	**argv;
	int		i;

	i = -1;
	while (cmds[++i])
	{
		if (cmds[i]->str)
		{
			argv = parsing(cmds[i]->str);
			if (count_array(argv) > 0)
				update_env("_", argv[count_array(argv) - 1]);
			try_exec(argv);
			free_array(argv);
			free(cmds[i]->str);
		}
		free(cmds[i]);
	}
	free(cmds);
}

void	minishell(void)
{
	char			*in;
	char			*prompt;
	t_cmd			**cmds;

	ft_load_history();
	while (1)
	{
		ft_prompt(&prompt);
		in = readline(prompt);
		if (!in)
			ft_exit();
		if (in[0])
			ft_add_history(in);
		cmds = split_cmds(in);
		if (cmds)
			try_cmds(cmds);
		free(in);
		free(prompt);
	}
}
