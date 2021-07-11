/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/11 18:19:40 by bledda           ###   ########.fr       */
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
		ft_clean_input(&in);
		argv = ft_split(in, ' ');
		try_exec(argv);
		free(prompt);
		free_array(argv);
		free(in);
	}
}
