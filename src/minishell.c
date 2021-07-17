/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/17 23:39:14 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

/*
	Je vois pas ou j'ai oublier de free
	Premier passage pas de leaks et apres a chaque passage ya des leaks
	Visiblement cela vient de redirection.c
*/

void	minishell(void)
{
	char			*in;
	char			**argv;
	char			*prompt;
	t_redirection	**redict;
	int				j;

	while (1)
	{
		ft_prompt(&prompt);
		in = readline(prompt);
		if (!in)
			ft_exit();
		if (in[0])
			add_history(in);
		redict = cmds(in);
		free(in);
		j = 0;
		while (redict[j])
		{
			printf("Type : %d\n", redict[j]->type);
			if (redict[j]->value)
			{
				argv = parsing(redict[j]->value);
				if (count_array(argv) > 0)
					update_env("_", argv[count_array(argv) - 1]);
				try_exec(argv);
				free_array(argv);
				free(redict[j]->value);
			}
			j++;
			if (redict[j] && redict[j]->value == NULL)
				break ;
		}
		free(redict);
		free(prompt);
	}
}
