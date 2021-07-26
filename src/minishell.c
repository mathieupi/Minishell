/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:24:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/26 14:30:18 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"


bool	redi_right(t_cmd **cmds, int *i)//For Right
{
	int		j;
	char	**argv;

	j = *i;
	if (cmds[*i])
	{
		while (cmds[*i + 1] && (cmds[*i + 1]->type == '>' || cmds[*i + 1]->type == '>' * 4))
		{
			argv = parsing(cmds[*i + 1]->str);
			int fd = open(argv[0], O_CREAT, 0777);
			if (fd == -1)
				return (1);
			close(fd);
			(*i)++;
		}
		if (cmds[*i]->type == '>')
			r_chevron(cmds[j], cmds[*i]);
		else
			rr_chevron(cmds[j], cmds[*i]);
		if (cmds[*i + 1] && cmds[*i + 1]->type)
			cmds[*i + 1]->type = 0;
		return (0);
	}
	return (0);
}

bool redi_left(t_cmd **cmds, int *i)// For Left
{
	char *first_simple;
	char *first_second;
	char *file;
	char **argv;

	first_simple = 0;
	first_second = 0;
	file = 0;
	if (cmds[*i])
	{
		int z = 0;
		while (cmds[*i + 1] && (cmds[*i + 1]->type == '<' || cmds[*i + 1]->type == '<' * 4))
		{
			argv = parsing(cmds[*i + 1]->str);
			if (cmds[*i + 1]->type == '<')
			{
				if (first_simple == 0)
					first_simple = ft_strdup(argv[0]);
				else if (first_second == 0)
					first_second = ft_strdup(argv[0]);
				else
				{
					if (z == 0)
					{
						free(first_simple);
						first_simple = ft_strdup(argv[0]);
					}
					else
					{
						free(first_second);
						first_second = ft_strdup(argv[0]);
					}
					z++;
				}
				if (z == 2)
					z = 0;
			}
			else if (cmds[*i + 1]->type == '<' * 4)
			{
				if (file == 0)
					file = ft_strdup(argv[0]);
				else if (file != 0)
				{
					free(file);
					file = ft_strdup(argv[0]);
				}
			}
			(*i)++;
		}/*
		if (cmds[*i + 1] && (cmds[*i + 1]->type == 0))
		{
			if (cmds[*i]->type == '<')
				//Super nouvelle fonction l_chevron(cmds, first_simple, first_second);
			else if (cmds[*i]->type == '<' * 4)
				//Supper Nouovelle fonction ll_chevron(cmds, file);
			return (0);
		}
		else
		{
			Faut trouver comment l'envoyer plus loins
		}*/
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
			if (redi_left(cmds, &i))
				ft_error("error", "error", 1);
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
