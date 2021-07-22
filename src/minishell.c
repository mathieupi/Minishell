/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/23 01:53:24 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	try_cmds(t_cmd	**redir)
{
	char	**argv;
	int		i;

	i = -1;
	while (redir[++i])
	{
		if (redir[i]->str)
		{
			argv = parsing(redir[i]->str);
			if (count_array(argv) > 0)
				update_env("_", argv[count_array(argv) - 1]);
			try_exec(argv);
			free_array(argv);
			free(redir[i]->str);
		}
		free(redir[i]);
	}
	free(redir);
}

void	minishell(void)
{
	char			*in;
	char			*prompt;
	t_cmd			**redir;

	ft_load_history();
	while (1)
	{
		ft_prompt(&prompt);
		in = readline(prompt);
		if (!in)
			ft_exit();
		if (in[0])
			ft_add_history(in);
		redir = split_cmds(in);
		if (redir)
			try_cmds(redir);
		free(in);
		free(prompt);
	}
}
