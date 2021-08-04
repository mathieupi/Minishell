/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_chevron.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 07:33:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/08/04 16:53:04 by mmehran          ###   ########.fr       */
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

static void	read_file(t_cmd *cmd_file, int fdout)
{
	int		fd;
	char	*line;

	fd = open(cmd_file->args[0], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		write(cmd_file->fout, line, ft_strlen(line));
		write(cmd_file->fout, "\n", 1);
		free(line);
	}
	close(fd);
}

void	l_chevron(t_cmd *cmd1, t_cmd *cmd_file)
{
	int		fd1[2];
	int		fork_id;
	int		fd_file;
	char	*line;

	pipe(fd1);
	fork_id = fork();
	if (fork_id == 0)
	{
		close(fd1[1]);
		cmd1->fin = fd1[0];
		ft_exec_redir(cmd1);
	}
	else
		read_file(cmd_file, fd1[1]);
	close(fd1[0]);
	close(fd1[1]);
	waitpid(fork_id, NULL, 0);
}
