/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/22 22:37:21 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	try_cmds(t_cmd	**redir)
{
	char	**argv;
	int		i;

	i = 0;
	while (redir[i])
	{
		if (redir[i]->str)
		{
			argv = parsing(redir[i]->str);
			if (count_array(argv) > 0)
				update_env("_", argv[count_array(argv) - 1]);
			try_exec(argv);
			free_array(argv);
			free(redir[i]->str);
			if (redir[i] && redir[i]->str == NULL)
			{
				while (redir[i] && redir[i]->str == NULL)
					free(redir[i++]->str);
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
	t_cmd			**redir;

	(void)redir;
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
		// try_cmds(redir);
		int j = -1;
		while (redir[++j])
		{
			printf("%d, %s\n", redir[j]->type, redir[j]->str);
			free(redir[j]->str);
			free(redir[j]);
		}
		free(redir);
		free(prompt);
	}
}
