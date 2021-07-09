/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 05:42:10 by bledda            #+#    #+#             */
/*   Updated: 2021/07/09 05:32:15 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	ft_putargs(int ac, char **av, int option)
{
	int	i;

	if (option == 0)
		i = 1;
	else
		i = 2;
	while (i < ac)
	{
		ft_putstr_fd(av[i], 1);
		if (i + 1 != ac)
			ft_putchar_fd(' ', 1);
		i++;
	}
}

void	ft_echo(int ac, char **av)
{
	int	option;

	option = 0;
	if (ac >= 2 && ft_strncmp(av[1], "-n", 2) == 0)
	{
		option = 1;
		if (ft_strlen(av[1]) >= 3 && ft_strncmp(av[1], "-n ", 3) == 0)
			option = 0;
	}
	ft_putargs(ac, av, option);
	if (option == 0)
		ft_putchar_fd('\n', 1);
}
