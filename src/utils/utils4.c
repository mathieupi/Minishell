/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 12:36:42 by mmehran           #+#    #+#             */
/*   Updated: 2021/08/06 18:29:47 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"

bool	ft_append_file(char *str)
{
	int	fd;

	fd = open(str, O_CREAT | O_APPEND | O_WRONLY, 0777);
	if (fd == -1)
	{
		ft_error(str, "Is a directory", 1);
		return (false);
	}
	close(fd);
	return (true);
}

bool	ft_create_file(char *str)
{
	int	fd;

	fd = open(str, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (fd == -1)
	{
		ft_error(str, "Is a directory", 1);
		return (false);
	}
	close(fd);
	return (true);
}

int	ft_open_file(char *str)
{
	int			fd;
	struct stat	buffer;
	int			status;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		status = stat(str, &buffer);
		if (status == -1)
			ft_error2("cd", str, "No such file or directory", 1);
		else if (status == 0)
			ft_error("cd", "Not a directory", 1);
	}
	return (fd);
}