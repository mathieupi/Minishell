/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:45:34 by bledda            #+#    #+#             */
/*   Updated: 2021/08/02 09:34:35 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/history.h"

char	*get_history_file(void)
{
	char	*home;

	home = ft_getenv("HOME");
	add_value(&home, "/.minishell_history");
	return (home);
}

void	ft_load_history(void)
{
	int				fd;
	char			*line;
	char			*history_file;

	history_file = get_history_file();
	fd = open(history_file, O_CREAT | O_RDWR | O_APPEND, 0777);
	while (get_next_line(fd, &line) > 0)
	{
		add_history(line);
		free(line);
	}
	free(history_file);
	close(fd);
}

void	ft_add_history(char *in)
{
	int				fd;
	char			*history_file;

	history_file = get_history_file();
	fd = open(history_file, O_CREAT | O_RDWR | O_APPEND, 0777);
	ft_putstr_fd(in, fd);
	ft_putstr_fd("\n", fd);
	add_history(in);
	free(history_file);
	close(fd);
}
