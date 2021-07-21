/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 06:23:22 by bledda            #+#    #+#             */
/*   Updated: 2021/07/21 17:41:04 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parser.h"

void	update_struct(char c, t_parsing *parsing)
{
	if (parsing->inhibited)
		parsing->inhibited = false;
	else
	{
		if (c == '\\' && !parsing->in_squote)
			parsing->inhibited = true;
		if (c == '"' && !parsing->in_squote)
			parsing->in_dquote = !parsing->in_dquote;
		if (c == '\'' && !parsing->in_dquote)
			parsing->in_squote = !parsing->in_squote;
	}
}

void	update_struct2(char c, t_parsing *parsing)
{
	parsing->in_squote = parsing->is_simple;
	parsing->in_dquote = parsing->is_double;
	if (parsing->inhibited)
		parsing->inhibited = false;
	else if (parsing->is_inhiber)
	{
		parsing->inhibited = true;
		parsing->is_inhiber = false;
	}
	if (c == '\\' && !parsing->in_squote)
		parsing->is_inhiber = true;
	if (c == '\'' && !parsing->in_dquote)
		parsing->is_simple = !parsing->is_simple;
	if (c == '"' && !parsing->in_squote && !parsing->inhibited)
		parsing->is_double = !parsing->is_double;
}
