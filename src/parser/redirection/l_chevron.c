/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_chevron.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 07:33:07 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/26 07:38:40 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

void	l_chevron(t_cmd *cmd1, t_cmd *cmd_file)
{
	int	fd1[2];
	int	fork_id;
	char	**argv;

	pipe(fd1);
	if ((fork_id = fork()) == 0)
	{
		printf("%s LOL\n", cmd1->str);
		close(fd1[1]);
		dup2(fd1[0], 0);
		close(fd1[0]);
		argv = parsing(cmd1->str);
		try_exec(argv);
		exit(0);
	}
	else
	{
		printf("%s\n", cmd_file->str);

		argv = parsing(cmd_file->str);
		int fd = open(argv[0], O_RDONLY);
		char *line;
		while (get_next_line(fd, &line) > 0)
		{
			write(fd1[1], line, ft_strlen(line));
			write(fd1[1], "\n", 1);
			free(line);
		}
		close(fd);
	}
	close(fd1[0]);
	close(fd1[1]);
	waitpid(fork_id, NULL, 0);
}
