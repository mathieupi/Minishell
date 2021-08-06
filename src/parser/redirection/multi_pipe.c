/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:34:40 by mmehran           #+#    #+#             */
/*   Updated: 2021/08/06 19:29:00 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

static bool	is_last_pipe(t_cmd **cmds, int i)
{
	if (!cmds[i + 1] || cmds[i + 1]->type != '|')
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

typedef struct s_tam
{
	int	lol;
}	t_tam;

static void	close_fd(t_cmd *cmd)
{
	if (cmd->fin)
		close(cmd->fin);
	if (cmd->fout)
		close(cmd->fout);
}

void	multi_pipe(t_cmd **cmds, int *i, int icmd, int ocmd)
{
	int		curr_pipe[2];
	bool	first;
	int		stdin_;
	int		stdout_;
	int		fin;
	int		fout;

	stdin_ = dup(0);
	stdout_ = dup(1);
	if (icmd == -1)
		fin = dup(stdin_);
	else
		fin = open(cmds[icmd]->args[0], O_RDONLY);
	if (ocmd == -1)
		fout = dup(stdout_);
	else
	{
		if (cmds[ocmd]->type == '>')
			fout = open(cmds[ocmd]->args[0], O_CREAT | O_TRUNC | O_WRONLY, 0777);
		else
			fout = open(cmds[ocmd]->args[0], O_CREAT | O_APPEND | O_WRONLY, 0777);
	}
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
		else
			cmds[*i]->fout = fout;
		child_exec_redir(cmds[*i]);
		close_fd(cmds[*i]);
		reset_fd(stdin_, stdout_);
		first = false;
		(*i)++;
	}
	if (icmd != -1 || ocmd != -1)
		*i = ft_max(icmd, ocmd);
}
