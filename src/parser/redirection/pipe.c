/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 07:27:49 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/26 07:46:17 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

void	ft_pipe(t_cmd *cmd1, t_cmd *cmd2)
{
	int	fd1[2];
	int	fork_id;
	int	fork_id2;
	char	**argv;

	pipe(fd1);
	if ((fork_id = fork()) == 0)
	{
		printf("%s\n", cmd1->str);
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
		printf("%s\n", cmd2->str);
		dup2(fd1[0], 0);
		close(fd1[0]);
		close(fd1[1]);
		argv = parsing(cmd2->str);
		try_exec(argv);
		close(0);
		exit(0);
	}
	close(fd1[0]);
	close(fd1[1]);
	waitpid(fork_id, NULL, 0);
	waitpid(fork_id2, NULL, 0);
}
