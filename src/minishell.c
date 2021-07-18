/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/18 13:40:01 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static void	try_cmds(t_redirection	**redict)
{
	char	**argv;
	int		i;

	i = 0;
	while (redict[i])
	{
		printf("Type : %d\n", redict[i]->type);
		if (redict[i]->value)
		{
			argv = parsing(redict[i]->value);
			if (count_array(argv) > 0)
				update_env("_", argv[count_array(argv) - 1]);
			try_exec(argv);
			free_array(argv);
			free(redict[i]->value);
			if (redict[i] && redict[i]->value == NULL)
				break ;
		}
		i++;
	}
	free_array((char **)redict);
}
/*
	pour fix leaks faire un new free array
*/


void	minishell(void)
{
	char			*in;
	char			*prompt;
	t_redirection	**redict;

	while (1)
	{
		ft_prompt(&prompt);
		in = readline(prompt);
		if (!in)
			ft_exit();
		if (in[0])
			add_history(in);
		redict = cmds(in);
		argv = parsing(redict[i]->value);
		free(in);
		try_cmds(redict);
		free(prompt);
	}
}
