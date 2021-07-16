/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/16 11:55:44 by mmehran          ###   ########.fr       */
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
		in = readline(prompt);
		if (!in)
			ft_exit();
		if (in[0])
			add_history(in);
		argv = parsing(in);
		try_exec(argv);
		free(prompt);
		free_array(argv);
		free(in);
	}
}
