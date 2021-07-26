/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_chevron.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 07:36:34 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/26 11:40:29 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

void	ll_chevron(t_cmd *cmd1, t_cmd *end_keyword)
{
	int	fd1[2];
	int	fork_id;
	int	fork_id2;
	char	**argv;

	pipe(fd1);
	if ((fork_id2 = fork()) == 0)
	{
		printf("%s\n", end_keyword->str);

		argv = parsing(end_keyword->str);
		char *line;
		while (get_next_line(0, &line) > 0)
		{
			if (ft_streql(line, argv[0]))
			{
				free(line);
				break ;
			}
			write(fd1[1], line, ft_strlen(line));
			write(fd1[1], "\n", 1);
			free(line);
		}
		close(fd1[0]);
		close(fd1[1]);
		exit(0);
	}
	waitpid(fork_id2, NULL, 0);
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
	close(fd1[0]);
	close(fd1[1]);
	waitpid(fork_id, NULL, 0);
}
