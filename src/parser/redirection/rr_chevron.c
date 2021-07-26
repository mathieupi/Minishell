/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_chevron.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 07:37:42 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/26 13:49:44 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

void	rr_chevron(t_cmd *cmd1, t_cmd *cmd_file)
{
	int	fd1[2];
	int	fork_id;
	int	fork_id2;
	char	**argv;

	pipe(fd1);
	if ((fork_id = fork()) == 0)
	{
		//printf("%s\n", cmd1->str);
		//cmd1
		dup2(fd1[1], 1);
		close(fd1[0]);
		close(fd1[1]);
		argv = parsing(cmd1->str);
		try_exec(argv);
		close(1);
		exit(0);
	}
	if ((fork_id2 = fork()) == 0)
	{
		//printf("%s\n", cmd_file->str);
		dup2(fd1[0], 0);
		close(fd1[0]);
		close(fd1[1]);
		argv = parsing(cmd_file->str);
		int fd = open(argv[0], O_CREAT | O_APPEND | O_WRONLY, 0777);
		char *line;
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
	close(fd1[0]);
	close(fd1[1]);
	waitpid(fork_id, NULL, 0);
	waitpid(fork_id2, NULL, 0);
}
