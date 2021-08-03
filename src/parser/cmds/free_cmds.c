/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:08:26 by mmehran           #+#    #+#             */
/*   Updated: 2021/08/03 10:08:41 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

void	free_cmds(t_cmd **cmds)
{
	int	i;

	if (!cmds)
		return ;
	i = -1;
	while (cmds[++i])
	{
		if (cmds[i]->str)
			free(cmds[i]->str);
		if (cmds[i]->args)
			free_array(cmds[i]->args);
		free(cmds[i]);
	}
	free(cmds);
}
