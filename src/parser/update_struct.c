/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 06:23:22 by bledda            #+#    #+#             */
/*   Updated: 2021/07/14 06:25:39 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

void	update_struct(char c, t_parsing *parsing)
{
	if (parsing->inhibited)
		parsing->inhibited = false;
	else
	{
		if (c == '\\' && parsing->in_squote)
			parsing->inhibited = true;
		if (c == '"' && !parsing->in_squote)
			parsing->in_dquote = !parsing->in_dquote;
		if (c == '\'' && !parsing->in_dquote)
			parsing->in_squote = !parsing->in_squote;
	}
}
