/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_chevron.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 07:36:34 by mmehran           #+#    #+#             */
/*   Updated: 2021/08/04 17:24:10 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

static void	ft_exec_redir(t_cmd *cmd)
{
	if (cmd->fin)
	{
		dup2(cmd->fin, 0);
		close(cmd->fin);
	}
	if (cmd->fout)
	{
		dup2(cmd->fout, 1);
		close(cmd->fout);
	}
	try_exec(cmd->args);
	close(1);
	close(0);
	exit(0);
}

static void	read_in_util(t_cmd *end_keyword)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_streql(line, end_keyword->args[0]))
		{
			free(line);
			break ;
		}
		write(end_keyword->fout, line, ft_strlen(line));
		write(end_keyword->fout, "\n", 1);
		free(line);
	}
	exit(0);
}

void	ll_chevron(t_cmd *cmd1, t_cmd *end_keyword)
{
	int	fd1[2];
	int	fork_id;
	int	fork_id2;

	pipe(fd1);
	fork_id2 = fork();
	if (fork_id2 == 0)
		read_in_util(end_keyword);
	waitpid(fork_id2, NULL, 0);
	fork_id = fork();
	if (fork_id == 0)
	{
		close(fd1[1]);
		cmd1->fin = fd1[0];
		ft_exec_redir(cmd1);
	}
	close(fd1[0]);
	close(fd1[1]);
	waitpid(fork_id, NULL, 0);
}
