/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_linux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:40:48 by bledda            #+#    #+#             */
/*   Updated: 2021/08/13 02:34:33 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static void	handle_child(int sig)
{
	if (sig == SIGQUIT)
	{
		g_global.return_code = 131;
		printf("Quit: 3\n");
	}
	else if (sig == SIGINT)
	{
		g_global.return_code = 130;
		printf("\n");
	}
}

void	handle(int sig)
{
	if (g_global.child_pid)
		handle_child(sig);
	else if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
		printf("\b\b  \b\b");
}
