/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 07:27:49 by mmehran           #+#    #+#             */
/*   Updated: 2021/08/04 16:30:13 by mmehran          ###   ########.fr       */
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

void	ft_pipe(t_cmd *cmd1, t_cmd *cmd2)
{
	int		fd1[2];
	int		fork_id;
	int		fork_id2;

	pipe(fd1);
	fork_id = fork();
	if (fork_id == 0)
	{
		close(fd1[0]);
		cmd1->fout = fd1[1];
		ft_exec_redir(cmd1);
	}
	fork_id2 = fork();
	if (fork_id2 == 0)
	{
		close(fd1[1]);
		cmd2->fin = fd1[0];
		ft_exec_redir(cmd2);
	}
	close(fd1[0]);
	close(fd1[1]);
	waitpid(fork_id, NULL, 0);
	waitpid(fork_id2, NULL, 0);
}
