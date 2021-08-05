/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 05:42:10 by bledda            #+#    #+#             */
/*   Updated: 2021/08/05 13:30:55 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

void	ft_exit(char **av)
{
	g_global.return_code = 1;
	printf("exit\n");
	if (count_array(av) > 1)
	{
		if (!ft_strisdigit(av[1]))
		{
			ft_error2("exit", av[1], "numeric argument required", 255);
			return ;
		}
		else if (count_array(av) != 2)
		{
			ft_error2("exit", av[1], "too many arguments", 1);
			return ;
		}
		else
			g_global.return_code = ft_atoi(av[1]);
	}
	exit(g_global.return_code);
}
