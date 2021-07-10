/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:11:20 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/10 02:21:30 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	handle(int sig)
{
	printf("\b\b  \b\b");
	if (sig == SIGINT)
	{
		rl_on_new_line();
		printf("\n");
		//rl_replace_line("", 0);
		rl_redisplay();
	}
}


int	main(void)
{
	signal(SIGINT, handle);
	signal(SIGQUIT, handle);
	minishell();
}
