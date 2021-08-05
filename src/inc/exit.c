/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 05:42:10 by bledda            #+#    #+#             */
/*   Updated: 2021/08/05 12:13:19 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/inc.h"

void	ft_exit(char **av)
{
	printf("exit\n");
	if (count_array(av) == 1)
		g_global.return_code = 1;
	else if (count_array(av) > 2)
	{
		if (ft_strisdigit(av[1]))
			ft_error2("exit", av[1], "too many arguments", 1);
		else
		{
			ft_error2("exit", av[1], "numeric argument required", 255);
			return ;
		}
	}
	else if (count_array(av) == 2)
	{
		if (ft_strisdigit(av[1]))
			g_global.return_code = ft_atoi(av[1]);
		else
		{
			ft_error2("exit", av[1], "numeric argument required", 255);
			return ;
		}
	}
	exit(g_global.return_code);
}
