/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 03:51:29 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/11 17:56:33 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

void	ft_putargs(char **av)
{
	while (*av)
	{
		ft_putstr_fd(*av, 1);
		if (*(av + 1) != NULL)
			ft_putchar_fd(' ', 1);
		av++;
	}
}

void	ft_echo(char **argv)
{
	bool	option;

	argv++;
	option = false;
	if (ft_streql(*argv, "-n"))
	{
		option = true;
		argv++;
	}
	ft_putargs(argv);
	if (!option)
		ft_putchar_fd('\n', 1);
}
