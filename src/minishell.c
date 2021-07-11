/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/11 21:07:04 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	minishell(void)
{
	char	*in;
	char	**argv;
	char	*prompt;

	while (1)
	{
		ft_prompt(&prompt);
		in = readline("> ");
		if (!in)
			ft_exit();
		if (in[0])
			add_history(in);
		//ft_clean_input(&in); memleak
		argv = ft_split(in, ' ');
		try_exec(argv);
		free(prompt);
		free_array(argv);
		free(in);
	}
}
