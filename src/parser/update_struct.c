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
	if (!parsing->inibiteur)
	{
		if (c == '\\')
			parsing->inibiteur = true;
		if (c == '"')
			parsing->in_dquote = !parsing->in_dquote;
		if (c == '\'' && !parsing->in_dquote)
			parsing->in_squote = !parsing->in_squote;
	}
	if (parsing->inibiteur)
		parsing->i++;
	if (parsing->i == 2)
	{
		parsing->inibiteur = false;
		parsing->i = 0;
	}
}
