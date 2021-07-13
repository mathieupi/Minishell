/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:11:20 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/13 09:42:05 by bledda           ###   ########.fr       */
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
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	main(int ac, char **av, char **envp)
{
	int	i;

	(void)ac;
	(void)av;
	i = 0;
	g_environ = ft_calloc(sizeof(char *), count_array(envp) + 1);
	while (envp[i])
	{
		g_environ[i] = ft_strdup(envp[i]);
		i++;
	}
	signal(SIGINT, handle);
	signal(SIGQUIT, handle);
	minishell();
}
