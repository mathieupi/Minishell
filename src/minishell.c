/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/22 16:40:36 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	try_cmds(t_redirection	**redir)
{
	char	**argv;
	int		i;

	i = 0;
	while (redir[i])
	{
		if (redir[i]->value)
		{
			argv = parsing(redir[i]->value);
			if (count_array(argv) > 0)
				update_env("_", argv[count_array(argv) - 1]);
			try_exec(argv);
			free_array(argv);
			free(redir[i]->value);
			if (redir[i] && redir[i]->value == NULL)
			{
				while (redir[i] && redir[i]->value == NULL)
					free(redir[i++]->value);
				break ;
			}
		}
		i++;
	}
	free_array((char **)redir);
}

void	minishell(void)
{
	char			*in;
	char			*prompt;
	t_redirection	**redir;

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
		free(in);
		try_cmds(redir);
		free(prompt);
	}
}
