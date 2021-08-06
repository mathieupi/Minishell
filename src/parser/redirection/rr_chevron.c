/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_chevron.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 07:37:42 by mmehran           #+#    #+#             */
/*   Updated: 2021/08/06 21:34:59 by mmehran          ###   ########.fr       */
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

static void	write_file(t_cmd *cmd_file, int fdin)
{
	int		fd;
	char	*line;

	dup2(fdin, 0);
	close(fdin);
	fd = ft_append_file(cmd_file->args[0], false);
	while (get_next_line(0, &line) > 0)
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	close(fd);
	close(0);
	exit(0);
}

void	rr_chevron(t_cmd *cmd1, t_cmd *cmd_file)
{
	int	fd1[2];
	int	fork_id;
	int	fork_id2;

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
		write_file(cmd_file, fd1[0]);
	}
	close(fd1[0]);
	close(fd1[1]);
	waitpid(fork_id, NULL, 0);
	waitpid(fork_id2, NULL, 0);
}
