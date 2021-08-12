/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:00:06 by mmehran           #+#    #+#             */
/*   Updated: 2021/08/13 00:38:20 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

static void	child_exec_redir(t_cmd *cmd, bool last)
{
	int		fork_id;

	(void) last;
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

static void	close_reset_fd(t_cmd *cmd, int stdin_, int stdout_)
{
	if (cmd->fin)
		close(cmd->fin);
	if (cmd->fout)
		close(cmd->fout);
	dup2(stdin_, 0);
	dup2(stdout_, 1);
	close(stdin_);
	close(stdout_);
}

static bool	open_fin(t_cmd **cmds, int icmd, int *fin)
{
	if (icmd == -1)
		*fin = dup(0);
	else
		*fin = ft_open_file(cmds[icmd]->args[0]);
	return (*fin != -1);
}

static bool	create_fout(t_cmd **cmds, int ocmd, int *fout)
{
	if (ocmd == -1)
		*fout = dup(0);
	else
	{
		if (cmds[ocmd]->type == '>')
			*fout = ft_create_file(cmds[ocmd]->args[0], false);
		else
			*fout = ft_append_file(cmds[ocmd]->args[0], false);
	}
	return (*fout != -1);
}

void	multi_pipe(t_cmd **cmds, int *i, int icmd, int ocmd)
{
	t_fds	fds;

	if (!open_fin(cmds, icmd, &fds.fin) || !create_fout(cmds, ocmd, &fds.fout))
		return ;
	fds.first = true;
	while (cmds[*i] && (fds.first || cmds[*i]->type == '|'))
	{
		fds.stdin_ = dup(0);
		fds.stdout_ = dup(1);
		cmds[*i]->fin = fds.fin;
		if (cmds[*i + 1] && cmds[*i + 1]->type == '|')
		{
			pipe(fds.curr_pipe);
			cmds[*i]->fout = fds.curr_pipe[1];
			fds.fin = fds.curr_pipe[0];
		}
		else
			cmds[*i]->fout = fds.fout;
		child_exec_redir(cmds[*i], !cmds[*i + 1] || cmds[*i + 1]->type != '|');
		close_reset_fd(cmds[*i], fds.stdin_, fds.stdout_);
		fds.first = false;
		(*i)++;
	}
	if (icmd != -1 || ocmd != -1)
		*i = ft_max(icmd, ocmd);
}
