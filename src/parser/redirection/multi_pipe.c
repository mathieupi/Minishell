/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:34:40 by mmehran           #+#    #+#             */
/*   Updated: 2021/08/05 17:40:23 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

static bool	is_last_pipe(t_cmd **cmds, int i)
{
	if (!cmds[i + 1])
		return (true);
	if (cmds[i + 1]->type != '|')
		return (true);
	return (false);
}

static void	child_exec_redir(t_cmd *cmd)
{
	int		fork_id;

	fork_id = fork();
	if (fork_id == 0)
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
	waitpid(fork_id, NULL, 0);
}

static void	reset_fd(int stdin_, int stdout_)
{
	dup2(stdin_, 0);
	dup2(stdout_, 1);
}

static void	close_fd(t_cmd *cmd)
{
	if (cmd->fin)
		close(cmd->fin);
	if (cmd->fout)
		close(cmd->fout);
}

void	multi_pipe(t_cmd **cmds, int *i)
{
	int		curr_pipe[2];
	bool	first;
	int		stdin_;
	int		stdout_;
	int		fin;

	stdin_ = dup(0);
	stdout_ = dup(1);
	fin = dup(stdin_);
	first = true;
	while (cmds[*i] && (first || cmds[*i]->type == '|'))
	{
		cmds[*i]->fin = fin;
		if (!is_last_pipe(cmds, *i))
		{
			pipe(curr_pipe);
			cmds[*i]->fout = curr_pipe[1];
			fin = curr_pipe[0];
		}
		child_exec_redir(cmds[*i]);
		close_fd(cmds[*i]);
		reset_fd(stdin_, stdout_);
		first = false;
		(*i)++;
	}
}
