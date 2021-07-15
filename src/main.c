/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:19:23 by bledda            #+#    #+#             */
/*   Updated: 2021/07/15 18:34:22 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	handle(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		printf("  \b\b\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		printf("  \b\b");
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
	return (0);
}
