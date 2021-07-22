/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:09:28 by bledda            #+#    #+#             */
/*   Updated: 2021/07/22 23:09:33 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

void	add_calloc(t_cmd ***cmdsp)
{
	int		count;
	t_cmd	**tmp;
	t_cmd	**cmds;

	cmds = *cmdsp;
	count = -1;
	while (cmds[++count])
		;
	tmp = ft_calloc(count + 2, sizeof(t_cmd *));
	count = -1;
	while (cmds[++count])
		tmp[count] = cmds[count];
	tmp[count] = ft_calloc(1, sizeof(t_cmd));
	free(cmds);
	*cmdsp = tmp;
}
