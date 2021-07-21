/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 03:51:29 by mmehran           #+#    #+#             */
/*   Updated: 2021/07/21 19:47:06 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

static void	ft_putargs(char **av)
{
	while (*av)
	{
		ft_putstr_fd(*av, 1);
		if (*(av + 1) != NULL)
			ft_putchar_fd(' ', 1);
		av++;
	}
}

static bool	ft_option(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != 'n' && str[i] != 'e' && str[i] != 'E')
			return (false);
		i++;
	}
	return (true);
}

void	ft_echo(char **argv)
{
	bool	option;

	argv++;
	option = false;
	while (ft_option(*argv))
	{
		option = true;
		argv++;
	}
	ft_putargs(argv);
	if (!option)
		ft_putchar_fd('\n', 1);
}
