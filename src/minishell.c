/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/26 11:35:58 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

bool	redi(t_cmd	**cmds, int *i)
{
	int		j;
	char	**argv;

	j = *i;
	while (cmds[*i])
	{
		while (cmds[*i + 1] && (cmds[*i + 1]->type == '>' || cmds[*i + 1]->type == '>' * 4))
		{
			argv = parsing(cmds[*i + 1]->str);
			int fd = open(argv[0], O_CREAT, 0777);
			if (fd == -1)
			{
				printf("ERRRRROR %s\n", argv[0]);
				return (1);
			}
			close(fd);
			(*i)++;
		}
		if (cmds[*i]->type == '>')
			r_chevron(cmds[j], cmds[*i]);
		else
			rr_chevron(cmds[j], cmds[*i]);
		if (cmds[*i + 1] && cmds[*i + 1]->type)
		{
			cmds[*i + 1]->type = 0;
		}
		return (0);
	}
	return (0);
}

void	try_cmds(t_cmd	**cmds)
{
	char	**argv;
	int		i;

	i = -1;
	while (cmds[++i])
	{
		if (cmds[i + 1] && cmds[i + 1]->type)
		{
			if (redi(cmds, &i))
			{
				ft_error("error", "error", 1);
			}
		}
		else if (cmds[i]->str)
		{
			argv = parsing(cmds[i]->str);
			if (count_array(argv) > 0)
				update_env("_", argv[count_array(argv) - 1]);
			try_exec(argv);
			free_array(argv);
			free(cmds[i]->str);
		}
		free(cmds[i]);
	}
	free(cmds);
}

void	minishell(void)
{
	char			*in;
	char			*prompt;
	t_cmd			**cmds;

	ft_load_history();
	while (1)
	{
		ft_prompt(&prompt);
		in = readline(prompt);
		if (!in)
			ft_exit();
		if (in[0])
			ft_add_history(in);
		cmds = split_cmds(in);
		if (cmds)
			try_cmds(cmds);
		free(in);
		free(prompt);
	}
}
