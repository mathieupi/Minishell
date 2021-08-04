/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:36:47 by mmehran           #+#    #+#             */
/*   Updated: 2021/08/04 15:06:51 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

void	redirection(t_cmd **cmds)
{
	int	i;

	i = -1;
	while (cmds[++i])
	{
		printf("[DEBUG] %s %d\n", cmds[i]->str, cmds[i]->type);
	}
}
